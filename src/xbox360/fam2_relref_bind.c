/* Family FAM2: bind-from-relative-reference initialisers (Swing_DLL.xex 0x887FDC00..0x887FE610).
   Each refreshes a relative reference with fn_8892EE88 (passing the null handle {0, 0xFFFFF, 0}),
   resolves it (NULL when not valid; self-relative when the relative flag is set, otherwise absolute)
   and copies fields of the referenced record into the object.  It then resizes the
   object's word vector to COUNT zeroes. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Ts4Handle12 { u32 a, b, c; } Ts4Handle12;
typedef struct Ts4RelRef { u32 f0; u32 off; u8 valid; u8 relative; } Ts4RelRef;
typedef struct Ts4WordVec { u32 a, b, c; } Ts4WordVec;
typedef struct Ts4RelBound {
    void **vt;
    u8 pad04[8];
    u32 f0c;
    u8 pad10[4];
    Ts4WordVec vec;
    u8 pad20[0xc];
    u32 f2c, f30, f34;
} Ts4RelBound;
extern void fn_8892EE88(Ts4RelRef *ref, Ts4Handle12 h, u32 z);
extern void ts4_vec_resize_val_88159370(Ts4WordVec *v, u32 n, u32 *value);

#define RELREF_RESOLVE(ref) \
    ((ref)->valid ? ((ref)->relative ? (u32 *)((char *)(ref) - (ref)->off) : (u32 *)(unsigned long)(ref)->off) : 0)
#define RELREC_FIELD(p, OFF) (*(u32 *)((char *)(p) + (p)[0] + (OFF)))

#define TS4_RELREF_BIND_VEC(A, COUNT) \
void ts4_relref_bind_vec_##A(Ts4RelBound *self, Ts4RelRef *ref); \
void ts4_relref_bind_vec_##A(Ts4RelBound *self, Ts4RelRef *ref) \
{ \
    Ts4Handle12 h; \
    u32 *p; \
    u32 zero; \
    h.a = 0; \
    h.b = 0xFFFFF; \
    h.c = 0; \
    fn_8892EE88(ref, h, 0); \
    p = RELREF_RESOLVE(ref); \
    { \
        u32 v = p[1]; \
        zero = 0; \
        self->f0c = v; \
    } \
    self->f2c = RELREC_FIELD(p, 4); \
    ts4_vec_resize_val_88159370(&self->vec, COUNT, &zero); \
}

/* Swing_DLL.xex addresses */
TS4_RELREF_BIND_VEC(887FDC00, 2)
TS4_RELREF_BIND_VEC(887FDC98, 1)
TS4_RELREF_BIND_VEC(887FDD30, 2)
TS4_RELREF_BIND_VEC(887FDDC8, 1)
TS4_RELREF_BIND_VEC(887FE010, 1)
TS4_RELREF_BIND_VEC(887FE180, 1)
TS4_RELREF_BIND_VEC(887FE4E0, 1)
TS4_RELREF_BIND_VEC(887FE578, 1)
TS4_RELREF_BIND_VEC(887FE610, 1)
