/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex) shared gameplay types: classes.h
 * Classes rebuilt from every function that touches them (vtables, ctors/dtors, readers/writers), with the
 * C++ members whose codegen the byte matches depend on. Conventions and evidence tags: docs/agents/types.md.
 * Per-class notes (functions, evidence, status): docs/agents/classes.md.
 *
 * Not included by ts4.h (opt-in): include it after ts4/ts4.h, as "include/ts4/classes.h". The C++ parts declare
 * memcpy and define inline members, which existing ts4.h users must not pick up by accident.
 *
 * Evidence tags: `V <addr>` = offset read/written by the byte-matched function at <addr>; `U asm <addr>` = offset
 * seen in the disassembly of a not-yet-matched function (proven offset, function unmatched).
 */
#ifndef TS4_CLASSES_H
#define TS4_CLASSES_H

#include "base.h"

#ifdef _MSC_VER
#define TS4_CLS_ALIGN16 __declspec(align(16))
#define TS4_CLS_FORCEINLINE __forceinline
#else
#define TS4_CLS_ALIGN16 __attribute__((aligned(16)))
#define TS4_CLS_FORCEINLINE inline
#endif

#ifdef __cplusplus
#ifdef _MSC_VER
extern "C" void *memcpy(void *, const void *, unsigned int);
#pragma function(memcpy) /* Ts4Matrix44::operator= and Ts4RelArr::Assign call memcpy (88187B18, 88187BC0) */
#define TS4_CLS_MEMCPY memcpy
#else
#define TS4_CLS_MEMCPY __builtin_memcpy /* host syntax checks: no libc headers needed */
#endif
#endif

/* ===================================================================================================
 * Ts4Vector3 (0xC) and Ts4Matrix44 (0x40, align 16): the value classes of Ts4XformBlock.
 * Vector3::operator= reads z, y, x into temporaries and then stores x, y, z: that gives the target's
 * lfs 8/4/0 + stfs 0/4/8 groups (88187B18, three times). Matrix44::operator= is a memcpy call of 0x40 bytes
 * (classes.h itself says `#pragma function(memcpy)` under cl, so the copy is not expanded inline).
 * =================================================================================================== */
#ifdef __cplusplus
struct Ts4Vector3 {
    float x, y, z;                               /* +0x0/+0x4/+0x8 V 88187B18 88187BC0 */
    Ts4Vector3 &operator=(const Ts4Vector3 &s)
    {
        float z_ = s.z, y_ = s.y, x_ = s.x;
        x = x_; y = y_; z = z_;
        return *this;
    }
};
struct TS4_CLS_ALIGN16 Ts4Matrix44 {
    float m[16];                                 /* +0x00 V 88187B18 (copied as one 0x40-byte memcpy) */
    Ts4Matrix44 &operator=(const Ts4Matrix44 &s) { TS4_CLS_MEMCPY(this, &s, sizeof(*this)); return *this; }
};
#else
typedef struct Ts4Vector3 { float x, y, z; } Ts4Vector3;
typedef struct TS4_CLS_ALIGN16 Ts4Matrix44 { float m[16]; } Ts4Matrix44;
#endif
TS4_ASSERT_SIZE(Ts4Vector3, 0xC);
TS4_ASSERT_SIZE(Ts4Matrix44, 0x40);

/* ===================================================================================================
 * Ts4XformBlock (0x80 with padding, align 16): three vectors, a matrix and a trailing float triple.
 * Set() = 88187B18 (out of line; called by Ts4XformRecord::Set 88187BC0 and by 887D7FB0, which copies the first
 * record's block into every other record of a 0xD0-stride array). The tail (dx, dy, dz) is copied in field order
 * with interleaved lfs/stfs, so it is not a Ts4Vector3 (that would give the reversed load group).
 * =================================================================================================== */
#ifdef __cplusplus
struct Ts4XformBlock {
    Ts4Vector3 a;                                /* +0x00 V 88187B18 */
    Ts4Vector3 b;                                /* +0x0C V 88187B18 */
    Ts4Vector3 c;                                /* +0x18 V 88187B18 */
    Ts4Matrix44 m;                               /* +0x30 V 88187B18 */
    float dx, dy, dz;                            /* +0x70 V 88187B18 */
    void Set(const Ts4XformBlock &s);            /* 88187B18 */
};
#else
typedef struct Ts4XformBlock {
    Ts4Vector3 a, b, c;
    Ts4Matrix44 m;
    float dx, dy, dz;
} Ts4XformBlock;
#endif
TS4_ASSERT_OFFSET(Ts4XformBlock, m, 0x30);
TS4_ASSERT_OFFSET(Ts4XformBlock, dx, 0x70);
TS4_ASSERT_SIZE(Ts4XformBlock, 0x80);

/* ===================================================================================================
 * Ts4RelArr<T> (C++ view of Ts4RelArray12, 0xC): self-relative array {offset (-1 = none), count, capacity}.
 * Assign() is the inlined copy-assign used five times by 88187BC0: copy only when the source has elements,
 * both offsets are set and the capacity fits; then count = max(count, n) with an unsigned compare while the
 * `n > 0` test is signed. So count/capacity are unsigned here (Ts4RelArray12 says int; same layout).
 * =================================================================================================== */
#ifdef __cplusplus
template <class T> struct Ts4RelArr {
    int offset;                                  /* +0x00 V 88187BC0 */
    unsigned int count;                          /* +0x04 V 88187BC0 */
    unsigned int capacity;                       /* +0x08 V 88187BC0 */
    T *Data() { return (T *)((char *)this + offset); }
    const T *Data() const { return (const T *)((const char *)this + offset); }
    TS4_CLS_FORCEINLINE void Assign(const Ts4RelArr &s)
    {
        int n = s.count;
        if (n > 0 && offset != -1 && s.offset != -1 && capacity >= (unsigned int)n) {
            TS4_CLS_MEMCPY(Data(), s.Data(), n * sizeof(T));
            count = count < (unsigned int)n ? n : count;
        }
    }
};
#endif

/* ===================================================================================================
 * Ts4XformRecord (0xD0, align 16): four rel arrays, two flag bytes, a Ts4XformBlock and a fifth rel array.
 * Set() = 88187BC0 (member-wise copy-assign; C caller cx34_f.c calls it as fn_88187BC0).
 * Arrays of records (stride 0xD0) hang off Owner+0xB0 in 887D7FB0 (U asm 887D7FB0).
 * Element sizes come from the memcpy lengths in 88187BC0: 0x30, 8, 8, 8, 0x10.
 * =================================================================================================== */
typedef struct Ts4XformRecElem30 { unsigned char b[0x30]; } Ts4XformRecElem30;
typedef struct Ts4XformRecElem8 { unsigned char b[0x8]; } Ts4XformRecElem8;
typedef struct Ts4XformRecElem10 { unsigned char b[0x10]; } Ts4XformRecElem10;
#ifdef __cplusplus
struct Ts4XformRecord {
    Ts4RelArr<Ts4XformRecElem30> a;              /* +0x00 V 88187BC0 */
    Ts4RelArr<Ts4XformRecElem8> b;               /* +0x0C V 88187BC0 */
    Ts4RelArr<Ts4XformRecElem8> c;               /* +0x18 V 88187BC0 */
    Ts4RelArr<Ts4XformRecElem8> d;               /* +0x24 V 88187BC0 */
    unsigned char f_30;                          /* +0x30 V 88187BC0 */
    unsigned char f_31;                          /* +0x31 V 88187BC0 */
    Ts4XformBlock block;                         /* +0x40 V 88187BC0 887D7FB0(U asm) */
    Ts4RelArr<Ts4XformRecElem10> e;              /* +0xC0 V 88187BC0 */
    void Set(const Ts4XformRecord &s);           /* 88187BC0 */
};
TS4_ASSERT_OFFSET(Ts4XformRecord, f_30, 0x30);
TS4_ASSERT_OFFSET(Ts4XformRecord, block, 0x40);
TS4_ASSERT_OFFSET(Ts4XformRecord, e, 0xC0);
TS4_ASSERT_SIZE(Ts4XformRecord, 0xD0);
#endif

/* ===================================================================================================
 * Ts4Tracker (0x98): vtable ts4_vtbl_Q5sTrackerItem880F3798 (1 slot: scalar deleting dtor 88262BB0), a polymorphic shell member
 * at +0x08 (vtable ts4_vtbl_Ts4TrackerShell880D6B70: the linker-folded vtable of trivial classes whose only virtual is the dtor,
 * shared by the 16-byte elements of 88267630 and the service members of 8817D2A0/88212040; not one class),
 * two accumulators and a block of floats/counters.
 *   ctor   886CC058: vptrs, a(), b() (member ctors), then { f_30 = 0; Reset(); } with Reset inlined
 *   Reset  886CBC30: clears everything except the vptrs, f_30 and b; scale (+0x3C) = 1.0f
 *   dtor   886C3510 (inline body: the two vptr stores), deleting dtor 88262BB0, vector delete 88262730 (stride 0x98)
 *   other loaders of ts4_vtbl_Q5sTrackerItem880F3798 (embedding ctors, not examined): 88266740, 886D66A8, 886E1328
 * The zero is the literal 0.0f (pooled at 0x8814B440, `g_ts4_event_value`); 1.0f is g_ts4_script_constants[0].
 * Reset only matches with the literal: a named extern float is reloaded after every float store in C++.
 * =================================================================================================== */
#ifdef __cplusplus
struct Ts4TrackerShell {                         /* vtable ts4_vtbl_Ts4TrackerShell880D6B70 */
    virtual ~Ts4TrackerShell() {}
};
struct Ts4TrackerAcc {                           /* 0x14 */
    float v[4];                                  /* +0x00 V 886CBC30 886CC058(ctor, 6 off) */
    int n;                                       /* +0x10 V 886CBC30 */
    Ts4TrackerAcc() { v[0] = 0.0f; n = 0; v[1] = 0.0f; v[2] = 0.0f; v[3] = 0.0f; }
    void Clear() { n = 0; v[0] = 0.0f; v[1] = 0.0f; v[2] = 0.0f; v[3] = 0.0f; }
};
TS4_STATIC_ASSERT(sizeof(Ts4TrackerAcc) == 0x14, Ts4TrackerAcc_size);
struct Ts4Tracker {                              /* vtable ts4_vtbl_Q5sTrackerItem880F3798 at +0x00 */
    int f_04;                                    /* +0x04 V 886CBC30 */
    Ts4TrackerShell shell;                       /* +0x08 U asm 886CC058 886C3510 88262BB0 (vptr ts4_vtbl_Ts4TrackerShell880D6B70) */
    float f_0c, f_10, f_14, f_18;                /* +0x0C V 886CBC30 */
    float f_1c, f_20, f_24, f_28, f_2c;          /* +0x1C V 886CBC30 (paired with f_6c/f_74/f_78/f_7c/f_80 in Reset order) */
    int f_30;                                    /* +0x30 U asm 886CC058 (ctor only) */
    int f_34;                                    /* +0x34 V 886CBC30 */
    float f_38;                                  /* +0x38 V 886CBC30 */
    float scale;                                 /* +0x3C V 886CBC30 (reset to 1.0f) */
    float f_40;                                  /* +0x40 V 886CBC30 */
    Ts4TrackerAcc a;                             /* +0x44 V 886CBC30 */
    Ts4TrackerAcc b;                             /* +0x58 U asm 886CC058 (ctor only) */
    int f_6c;                                    /* +0x6C V 886CBC30 */
    float f_70;                                  /* +0x70 V 886CBC30 */
    int f_74, f_78, f_7c;                        /* +0x74 V 886CBC30 */
    unsigned char f_80;                          /* +0x80 V 886CBC30 */
    char pad_0081[0x17];                         /* +0x81 .. 0x98 (size from 88262730) */
    Ts4Tracker();                                /* 886CC058 (open: 6 off) */
    virtual ~Ts4Tracker() {}                     /* 886C3510 inline body, 88262BB0 deleting */
    void Reset();                                /* 886CBC30 */
};
TS4_ASSERT_OFFSET(Ts4Tracker, f_04, 0x04);
TS4_ASSERT_OFFSET(Ts4Tracker, shell, 0x08);
TS4_ASSERT_OFFSET(Ts4Tracker, f_0c, 0x0C);
TS4_ASSERT_OFFSET(Ts4Tracker, f_30, 0x30);
TS4_ASSERT_OFFSET(Ts4Tracker, scale, 0x3C);
TS4_ASSERT_OFFSET(Ts4Tracker, a, 0x44);
TS4_ASSERT_OFFSET(Ts4Tracker, b, 0x58);
TS4_ASSERT_OFFSET(Ts4Tracker, f_6c, 0x6C);
TS4_ASSERT_OFFSET(Ts4Tracker, f_80, 0x80);
TS4_ASSERT_SIZE(Ts4Tracker, 0x98);
#else
typedef struct Ts4TrackerAcc { float v[4]; int n; } Ts4TrackerAcc;
typedef struct Ts4Tracker {
    const void *vtbl;                            /* +0x00 ts4_vtbl_Q5sTrackerItem880F3798 */
    int f_04;
    const void *shell_vtbl;                      /* +0x08 ts4_vtbl_Ts4TrackerShell880D6B70 */
    float f_0c, f_10, f_14, f_18, f_1c, f_20, f_24, f_28, f_2c;
    int f_30, f_34;
    float f_38, scale, f_40;
    Ts4TrackerAcc a, b;
    int f_6c;
    float f_70;
    int f_74, f_78, f_7c;
    unsigned char f_80;
    char pad_0081[0x17];
} Ts4Tracker;
TS4_ASSERT_OFFSET(Ts4Tracker, scale, 0x3C);
TS4_ASSERT_OFFSET(Ts4Tracker, b, 0x58);
TS4_ASSERT_SIZE(Ts4Tracker, 0x98);
#endif

#endif /* TS4_CLASSES_H */
