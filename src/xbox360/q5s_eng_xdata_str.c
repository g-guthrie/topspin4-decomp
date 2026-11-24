/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex): XData string fields and the record readers that use them (q5s eng).
 * Route: LTCG (/Oc), context src/xbox360/pp1_pool_primer.c. Spec: work/specs/Q5S/q5s_eng_xdata_str.json.
 *
 * Strings are written by fn_88603D78 as a 16-bit length (-1 for a null string) followed by the characters.
 * ts4_xread_short_string_886042C8 is its reader. The record readers (slot 3 of the 5-slot XData record
 * vtables, see q5s_eng_xdata_read.c) read their fields in the order the slot-2 writers write them.
 */
#ifndef _MSC_VER
#define __forceinline inline
#endif
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif
extern char *ts4_msg_buffer_alloc_88278620(int size);
/* Swing_DLL.xex 0x88604388 (fk2_004.c): copy a len-byte blob into a new message buffer (*out = 0 when len is 0);
 * returns len and subtracts it from *rem, or -1. */
extern void ts4_msg_pool_service_get_8864DFF0(void);
extern void ts4_registry_dispatch_888860A0(void *p);
extern void *fn_8899F760(u32 size);
extern char lbl_880F9848[];
extern int ts4_if_call_seq_u32_off0_88604388(const u8 *src, void **out, u32 len, u32 *rem);

/* Bounded u16 read returning the bytes consumed (2) or -1. The `2 > *n` spelling matters: written as
 * `*n < 2` the compiler threads it through the caller's identical `*rem < 2` test and drops the -1 arm
 * that the target keeps. */
static int ts4_xread_u16_sized(u16 *out, const u8 *p, u32 *n)
{
    if (2 > *n)
        return -1;
    *out = *(const u16 *)p;
    *n -= 2;
    return 2;
}

/* Swing_DLL.xex 0x886042C8: read a length-prefixed string into a new message buffer (*out, NUL-terminated);
 * length -1 stores a null pointer. Returns the bytes consumed and subtracts them from *rem, or -1 when the
 * input is short or the allocation fails. `__restrict` on rem lets the compiler load *out before the final
 * `*rem -= len` store, as in the target. */
int ts4_xread_short_string_886042C8(const u8 *src, char **out, u32 *__restrict rem)
{
    u16 v;
    int used;
    short len;
    char *buf;
    if (*rem < 2)
        return -1;
    v = 0;
    used = ts4_xread_u16_sized(&v, src, rem);
    len = (short)v;
    if (len == -1) {
        *out = 0;
        return used;
    }
    if ((u32)len > *rem)
        return -1;
    buf = ts4_msg_buffer_alloc_88278620(len + 1);
    *out = buf;
    if (buf == 0)
        return -1;
    memcpy(buf, src + used, len);
    *rem -= len;
    (*out)[len] = 0;
    return len + used;
}

/* Field readers shared with q5s_eng_xdata_read.c: fail (0) when fewer bytes remain than the field needs. */
static int ts4_xread_u16(u16 *out, const u8 *p, u32 *n)
{
    if (*n < 2)
        return 0;
    *out = *(const u16 *)p;
    *n -= 2;
    return 1;
}

static int ts4_xread_u32(u32 *out, const u8 *p, u32 *n)
{
    if (*n < 4)
        return 0;
    *out = *(const u32 *)p;
    *n -= 4;
    return 1;
}

static int ts4_xread_u64(u64 *out, const u8 *p, u32 *n)
{
    if (*n < 8)
        return 0;
    *out = *(const u64 *)p;
    *n -= 8;
    return 1;
}

/* vtable 0x880F98C0, writer ts4_write_record_885FBB90. */
typedef struct Ts4XRecStr_885FF8C0 {
    u8 pad0[0xc];
    char *name;                                    /* +0x0C */
    u16 f10;                                       /* +0x10 */
    u8 pad12[2];
    u32 f14;                                       /* +0x14 */
    u32 f18;                                       /* +0x18 */
} Ts4XRecStr_885FF8C0;

/* Swing_DLL.xex 0x885FF8C0: slot 3 of vtable 0x880F98C0: string, u16, u32, u32. */
u32 ts4_read_record_885FF8C0(Ts4XRecStr_885FF8C0 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    int used = ts4_xread_short_string_886042C8(p, &self->name, &n);
    if (used < 0)
        return 0;
    p += used;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f14, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f18, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* vtable 0x880F9870, writer ts4_write_record_885FBCE0. */
typedef struct Ts4XRecStr_885FFB08 {
    u8 pad0[0xc];
    char *name;                                    /* +0x0C */
    u16 f10;                                       /* +0x10 */
    u16 f12;                                       /* +0x12 */
    u32 f14;                                       /* +0x14 */
    u32 f18;                                       /* +0x18 */
    u32 f1c;                                       /* +0x1C */
    u32 f20;                                       /* +0x20 */
    u8 pad24[4];
    u64 f28;                                       /* +0x28 */
    u64 f30;                                       /* +0x30 */
} Ts4XRecStr_885FFB08;

/* Swing_DLL.xex 0x885FFB08: slot 3 of vtable 0x880F9870: string, 2 x u16, 4 x u32, 2 x u64. */
u32 ts4_read_record_885FFB08(Ts4XRecStr_885FFB08 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    int used = ts4_xread_short_string_886042C8(p, &self->name, &n);
    if (used < 0)
        return 0;
    p += used;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f12, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f14, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f18, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f1c, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f20, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u64(&self->f28, p, &n))
        return 0;
    p += 8;
    if (!ts4_xread_u64(&self->f30, p, &n))
        return 0;
    p += 8;
    *rem -= p - src;
    return 1;
}

/* vtable 0x880F9848, writer ts4_write_record_885FBDA8. */
typedef struct Ts4XRecStr_885FFD30 {
    u8 pad0[0xc];
    u32 fc;                                        /* +0x0C */
    char *s10;                                     /* +0x10 */
    char *s14;                                     /* +0x14 */
} Ts4XRecStr_885FFD30;

/* Swing_DLL.xex 0x885FFD30: slot 3 of vtable 0x880F9848: u32, string, string. */
u32 ts4_read_record_885FFD30(Ts4XRecStr_885FFD30 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    int used;
    if (!ts4_xread_u32(&self->fc, p, &n))
        return 0;
    p += 4;
    used = ts4_xread_short_string_886042C8(p, &self->s10, &n);
    if (used < 0)
        return 0;
    p += used;
    used = ts4_xread_short_string_886042C8(p, &self->s14, &n);
    if (used < 0)
        return 0;
    p += used;
    *rem -= p - src;
    return 1;
}

/* vtable 0x880F9834, writer ts4_write_record_885FBE00. */
typedef struct Ts4XRecStr_885FFDD0 {
    u8 pad0[0xc];
    u16 fc;                                        /* +0x0C */
    u16 fe;                                        /* +0x0E */
    char *s10;                                     /* +0x10 */
    char *s14;                                     /* +0x14 */
    char *s18;                                     /* +0x18 */
    u32 f1c;                                       /* +0x1C */
    u32 f20;                                       /* +0x20 */
    u16 h24[14];                                   /* +0x24..+0x3E */
    u32 f40;                                       /* +0x40 */
    u32 f44;                                       /* +0x44 */
    u32 f48;                                       /* +0x48 */
    u8 pad4c[4];
    u64 f50;                                       /* +0x50 */
} Ts4XRecStr_885FFDD0;

/* Swing_DLL.xex 0x885FFDD0: slot 3 of vtable 0x880F9834: 2 x u16, 3 strings, 2 x u32, 14 x u16, 3 x u32, u64. */
u32 ts4_read_record_885FFDD0(Ts4XRecStr_885FFDD0 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    int used;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->fe, p, &n))
        return 0;
    p += 2;
    used = ts4_xread_short_string_886042C8(p, &self->s10, &n);
    if (used < 0)
        return 0;
    p += used;
    used = ts4_xread_short_string_886042C8(p, &self->s14, &n);
    if (used < 0)
        return 0;
    p += used;
    used = ts4_xread_short_string_886042C8(p, &self->s18, &n);
    if (used < 0)
        return 0;
    p += used;
    if (!ts4_xread_u32(&self->f1c, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f20, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u16(&self->h24[0], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h24[1], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h24[2], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h24[3], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h24[4], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h24[5], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h24[6], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h24[7], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h24[8], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h24[9], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h24[10], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h24[11], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h24[12], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h24[13], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f40, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f44, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f48, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u64(&self->f50, p, &n))
        return 0;
    p += 8;
    *rem -= p - src;
    return 1;
}

/* Record with two strings followed by two u16 fields. */
typedef struct Ts4XRecStr_88600308 {
    u8 pad0[0xc];
    char *s0c;                                     /* +0x0C */
    char *s10;                                     /* +0x10 */
    u16 f14;                                       /* +0x14 */
    u16 f16;                                       /* +0x16 */
} Ts4XRecStr_88600308;

/* Swing_DLL.xex 0x88600308: XData record reader: string, string, u16, u16. */
u32 ts4_read_record_88600308(Ts4XRecStr_88600308 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    int used;
    used = ts4_xread_short_string_886042C8(p, &self->s0c, &n);
    if (used < 0)
        return 0;
    p += used;
    used = ts4_xread_short_string_886042C8(p, &self->s10, &n);
    if (used < 0)
        return 0;
    p += used;
    if (!ts4_xread_u16(&self->f14, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f16, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Record with a u16, a u64, then a string and a blob whose length is the u32 at +0x20. */
typedef struct Ts4XRecStr_885F82C0 {
    u8 pad0[0xc];
    u16 fc;                                        /* +0x0C */
    u8 pade[2];
    u64 f10;                                       /* +0x10 */
    void *blob;                                    /* +0x18 */
    char *s1c;                                     /* +0x1C */
    u32 blob_len;                                  /* +0x20 */
} Ts4XRecStr_885F82C0;

/* Swing_DLL.xex 0x885F82C0: XData record reader: u16, u64, u32 blob length, string, blob. */
u32 ts4_read_record_885F82C0(Ts4XRecStr_885F82C0 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    int used;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u64(&self->f10, p, &n))
        return 0;
    p += 8;
    if (!ts4_xread_u32(&self->blob_len, p, &n))
        return 0;
    p += 4;
    used = ts4_xread_short_string_886042C8(p, &self->s1c, &n);
    if (used < 0)
        return 0;
    p += used;
    used = ts4_if_call_seq_u32_off0_88604388(p, &self->blob, self->blob_len, &n);
    if (used < 0)
        return 0;
    p += used;
    *rem -= p - src;
    return 1;
}

/* Record of four strings. */
typedef struct Ts4XRecStr_88600A38 {
    u8 pad0[0xc];
    char *s[4];                                    /* +0x0C..+0x18 */
} Ts4XRecStr_88600A38;

/* Swing_DLL.xex 0x88600A38: XData record reader: four strings. */
u32 ts4_read_record_88600A38(Ts4XRecStr_88600A38 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    int used;
    used = ts4_xread_short_string_886042C8(p, &self->s[0], &n);
    if (used < 0)
        return 0;
    p += used;
    used = ts4_xread_short_string_886042C8(p, &self->s[1], &n);
    if (used < 0)
        return 0;
    p += used;
    used = ts4_xread_short_string_886042C8(p, &self->s[2], &n);
    if (used < 0)
        return 0;
    p += used;
    used = ts4_xread_short_string_886042C8(p, &self->s[3], &n);
    if (used < 0)
        return 0;
    p += used;
    *rem -= p - src;
    return 1;
}

/* Child record (vtable 0x880F9848, reader ts4_read_record_885FFD30). */
struct Ts4XChild_885F85C0;
typedef struct Ts4XChildVt_885F85C0 {
    void (*dtor)(struct Ts4XChild_885F85C0 *self, u32 flags);
    u32 (*size)(struct Ts4XChild_885F85C0 *self);
    u32 (*write)(struct Ts4XChild_885F85C0 *self, u32 off);
    u8 (*read)(struct Ts4XChild_885F85C0 *self, const u8 *src, u32 *rem);
} Ts4XChildVt_885F85C0;
typedef struct Ts4XChild_885F85C0 {
    const Ts4XChildVt_885F85C0 *vt;                /* +0x00 */
    u32 f4;                                        /* +0x04 */
    u16 f8;                                        /* +0x08 */
    u8 fa;                                         /* +0x0A */
    u8 fb;                                         /* +0x0B */
    u32 fc;                                        /* +0x0C */
    u32 f10;                                       /* +0x10 */
    u32 f14;                                       /* +0x14 */
} Ts4XChild_885F85C0;

typedef struct Ts4XRecStr_885F85C0 {
    u8 pad0[0x10];
    u64 f10;                                       /* +0x10 */
    u16 f18;                                       /* +0x18 */
    u8 pad1a[2];
    u32 blob_len;                                  /* +0x1C */
    u16 f20;                                       /* +0x20 */
    u16 has_child;                                 /* +0x22 */
    void *blob;                                    /* +0x24 */
    Ts4XChild_885F85C0 *child;                     /* +0x28 */
    char *s2c;                                     /* +0x2C */
    char *s30;                                     /* +0x30 */
} Ts4XRecStr_885F85C0;

/* Inline new of the child record. Plain static is not inlined here (81 off); __forceinline is needed, and the
 * helper form also fixes the register assignment of the open-coded version (22 off). */
static __forceinline Ts4XChild_885F85C0 *ts4_xchild_new(void)
{
    Ts4XChild_885F85C0 *c;
    ts4_msg_pool_service_get_8864DFF0();
    c = (Ts4XChild_885F85C0 *)fn_8899F760(0x18);
    if (c != 0) {
        c->vt = (const Ts4XChildVt_885F85C0 *)lbl_880F9848;
        c->f4 = 0;
        c->f8 = 0;
        c->fa = 0;
        c->fb = 0x18;
        c->fc = 0;
        c->f10 = 0;
        c->f14 = 0;
        return c;
    }
    return 0;
}

/* Inline delete: dtor (slot 0, flags 0), then pool service and registry free. */
static __forceinline void ts4_xchild_release(Ts4XChild_885F85C0 **pc)
{
    Ts4XChild_885F85C0 *c = *pc;
    if (c != 0) {
        c->vt->dtor(c, 0);
        ts4_msg_pool_service_get_8864DFF0();
        ts4_registry_dispatch_888860A0(c);
        *pc = 0;
    }
}

/* Swing_DLL.xex 0x885F85C0: XData record reader: u64, u16, u32 blob length, u16, u16, string, string, then
 * (when +0x22 is nonzero) a freshly allocated child record read through its own vtable, then the blob. */
u32 ts4_read_record_885F85C0(Ts4XRecStr_885F85C0 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    int used;
    if (!ts4_xread_u64(&self->f10, p, &n))
        return 0;
    p += 8;
    if (!ts4_xread_u16(&self->f18, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->blob_len, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u16(&self->has_child, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f20, p, &n))
        return 0;
    p += 2;
    used = ts4_xread_short_string_886042C8(p, &self->s2c, &n);
    if (used < 0)
        return 0;
    p += used;
    used = ts4_xread_short_string_886042C8(p, &self->s30, &n);
    if (used < 0)
        return 0;
    p += used;
    if (self->has_child != 0) {
        Ts4XChild_885F85C0 *c;
        u32 m;
        u32 cm;
        ts4_xchild_release(&self->child);
        c = ts4_xchild_new();
        self->child = c;
        if (c == 0)
            return 0;
        m = *rem - self->blob_len - (p - src);
        cm = m - 8;
        if (!c->vt->read(c, p + 8, &cm))
            return 0;
        p += m;
    }
    used = ts4_if_call_seq_u32_off0_88604388(p, &self->blob, self->blob_len, &n);
    if (used < 0)
        return 0;
    p += used;
    *rem -= p - src;
    return 1;
}

/* Record with two blobs (lengths at +0x10 and +0x18), two strings, a u16 and a u32. */
typedef struct Ts4XRecStr_88600678 {
    u8 pad0[0xc];
    void *blob0;                                   /* +0x0C */
    u32 blob0_len;                                 /* +0x10 */
    void *blob1;                                   /* +0x14 */
    u32 blob1_len;                                 /* +0x18 */
    char *s1c;                                     /* +0x1C */
    char *s20;                                     /* +0x20 */
    u16 f24;                                       /* +0x24 */
    u8 pad26[2];
    u32 f28;                                       /* +0x28 */
} Ts4XRecStr_88600678;

/* Swing_DLL.xex 0x88600678: XData record reader: (u32 length, blob) x 2, string, string, u16, u32. */
u32 ts4_read_record_88600678(Ts4XRecStr_88600678 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    int used;
    if (!ts4_xread_u32(&self->blob0_len, p, &n))
        return 0;
    p += 4;
    used = ts4_if_call_seq_u32_off0_88604388(p, &self->blob0, self->blob0_len, &n);
    if (used < 0)
        return 0;
    p += used;
    if (!ts4_xread_u32(&self->blob1_len, p, &n))
        return 0;
    p += 4;
    used = ts4_if_call_seq_u32_off0_88604388(p, &self->blob1, self->blob1_len, &n);
    if (used < 0)
        return 0;
    p += used;
    used = ts4_xread_short_string_886042C8(p, &self->s1c, &n);
    if (used < 0)
        return 0;
    p += used;
    used = ts4_xread_short_string_886042C8(p, &self->s20, &n);
    if (used < 0)
        return 0;
    p += used;
    {
        /* The tail reads use a fresh copy of n. Reusing n (whose address went to the calls above) leaves a dead
         * `stw n` after the u16 read that the target does not have. */
        u32 k = n;
        if (!ts4_xread_u16(&self->f24, p, &k))
            return 0;
        p += 2;
        if (!ts4_xread_u32(&self->f28, p, &k))
            return 0;
        p += 4;
    }
    *rem -= p - src;
    return 1;
}

typedef struct Ts4XRecStr_885FF7C0 {
    u8 pad0[12];
    void * blob;                                   /* +0x0C */
    u32 count;                                     /* +0x10 */
} Ts4XRecStr_885FF7C0;

/* Swing_DLL.xex 0x885FF7C0: XData record reader: u32 count, then a blob of count 8-byte entries. */
u32 ts4_read_record_885FF7C0(Ts4XRecStr_885FF7C0 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    int used;
    if (!ts4_xread_u32(&self->count, p, &n))
        return 0;
    p += 4;
    used = ts4_if_call_seq_u32_off0_88604388(p, &self->blob, self->count * 8, &n);
    if (used < 0)
        return 0;
    p += used;
    *rem -= p - src;
    return 1;
}

typedef struct Ts4XRecStr_885FF970 {
    u8 pad0[12];
    char * s0c;                                    /* +0x0C */
    u16 f10;                                       /* +0x10 */
} Ts4XRecStr_885FF970;

/* Swing_DLL.xex 0x885FF970: XData record reader: string, u16. */
u32 ts4_read_record_885FF970(Ts4XRecStr_885FF970 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    int used;
    used = ts4_xread_short_string_886042C8(p, &self->s0c, &n);
    if (used < 0)
        return 0;
    p += used;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

typedef struct Ts4XRecStr_886003B8 {
    u8 pad0[12];
    char * s0c;                                    /* +0x0C */
    u16 f10;                                       /* +0x10 */
} Ts4XRecStr_886003B8;

/* Swing_DLL.xex 0x886003B8: XData record reader: string, u16. */
u32 ts4_read_record_886003B8(Ts4XRecStr_886003B8 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    int used;
    used = ts4_xread_short_string_886042C8(p, &self->s0c, &n);
    if (used < 0)
        return 0;
    p += used;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

typedef struct Ts4XRecStr_88600438 {
    u8 pad0[12];
    char * s0c;                                    /* +0x0C */
    u16 f10;                                       /* +0x10 */
} Ts4XRecStr_88600438;

/* Swing_DLL.xex 0x88600438: XData record reader: string, u16. */
u32 ts4_read_record_88600438(Ts4XRecStr_88600438 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    int used;
    used = ts4_xread_short_string_886042C8(p, &self->s0c, &n);
    if (used < 0)
        return 0;
    p += used;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

typedef struct Ts4XRecStr_885FF9F0 {
    u8 pad0[12];
    char * s0c;                                    /* +0x0C */
    u32 f10;                                       /* +0x10 */
    u16 f14;                                       /* +0x14 */
} Ts4XRecStr_885FF9F0;

/* Swing_DLL.xex 0x885FF9F0: XData record reader: string, u32, u16. */
u32 ts4_read_record_885FF9F0(Ts4XRecStr_885FF9F0 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    int used;
    used = ts4_xread_short_string_886042C8(p, &self->s0c, &n);
    if (used < 0)
        return 0;
    p += used;
    if (!ts4_xread_u32(&self->f10, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u16(&self->f14, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

typedef struct Ts4XRecStr_88600080 {
    u8 pad0[12];
    u16 fc;                                        /* +0x0C */
    u16 fe;                                        /* +0x0E */
    u16 f10;                                       /* +0x10 */
    u8 pad12[2];
    void * blob;                                   /* +0x14 */
    u32 blob_len;                                  /* +0x18 */
    u8 pad1c[4];
    u64 f20;                                       /* +0x20 */
} Ts4XRecStr_88600080;

/* Swing_DLL.xex 0x88600080: XData record reader: 3 x u16, u32 blob length, blob, u64. */
u32 ts4_read_record_88600080(Ts4XRecStr_88600080 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    int used;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->fe, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->blob_len, p, &n))
        return 0;
    p += 4;
    used = ts4_if_call_seq_u32_off0_88604388(p, &self->blob, self->blob_len, &n);
    if (used < 0)
        return 0;
    p += used;
    if (!ts4_xread_u64(&self->f20, p, &n))
        return 0;
    p += 8;
    *rem -= p - src;
    return 1;
}

typedef struct Ts4XRecStr_88600160 {
    u8 pad0[12];
    u16 fc;                                        /* +0x0C */
    u8 pade[2];
    void * blob;                                   /* +0x10 */
    u32 blob_len;                                  /* +0x14 */
    u64 f18;                                       /* +0x18 */
} Ts4XRecStr_88600160;

/* Swing_DLL.xex 0x88600160: XData record reader: u16, u32 blob length, blob, u64. */
u32 ts4_read_record_88600160(Ts4XRecStr_88600160 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    int used;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->blob_len, p, &n))
        return 0;
    p += 4;
    used = ts4_if_call_seq_u32_off0_88604388(p, &self->blob, self->blob_len, &n);
    if (used < 0)
        return 0;
    p += used;
    if (!ts4_xread_u64(&self->f18, p, &n))
        return 0;
    p += 8;
    *rem -= p - src;
    return 1;
}

typedef struct Ts4XRecStr_886007A0 {
    u8 pad0[0xc];
    u16 h0c[9];                                    /* +0x0C..+0x1C */
    u8 pad1e[2];
    void *blob0;                                   /* +0x20 */
    u32 blob0_len;                                 /* +0x24 */
    void *blob1;                                   /* +0x28 */
    u32 blob1_len;                                 /* +0x2C */
    u16 f30;                                       /* +0x30 */
    u8 pad32[2];
    char *s34;                                     /* +0x34 */
    char *s38;                                     /* +0x38 */
    u32 f3c;                                       /* +0x3C */
    u16 f40;                                       /* +0x40 */
} Ts4XRecStr_886007A0;

/* Swing_DLL.xex 0x886007A0: XData record reader: 9 x u16, (u32 length, blob) x 2, u16, string, string, u32, u16. */
u32 ts4_read_record_886007A0(Ts4XRecStr_886007A0 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    int used;
    if (!ts4_xread_u16(&self->h0c[0], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h0c[1], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h0c[2], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h0c[3], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h0c[4], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h0c[5], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h0c[6], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h0c[7], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->h0c[8], p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->blob0_len, p, &n))
        return 0;
    p += 4;
    used = ts4_if_call_seq_u32_off0_88604388(p, &self->blob0, self->blob0_len, &n);
    if (used < 0)
        return 0;
    p += used;
    if (!ts4_xread_u32(&self->blob1_len, p, &n))
        return 0;
    p += 4;
    used = ts4_if_call_seq_u32_off0_88604388(p, &self->blob1, self->blob1_len, &n);
    if (used < 0)
        return 0;
    p += used;
    if (!ts4_xread_u16(&self->f30, p, &n))
        return 0;
    p += 2;
    used = ts4_xread_short_string_886042C8(p, &self->s34, &n);
    if (used < 0)
        return 0;
    p += used;
    used = ts4_xread_short_string_886042C8(p, &self->s38, &n);
    if (used < 0)
        return 0;
    p += used;
    {
        /* Fresh copy of n for the tail reads, as in ts4_read_record_88600678. */
        u32 k = n;
        if (!ts4_xread_u32(&self->f3c, p, &k))
            return 0;
        p += 4;
        if (!ts4_xread_u16(&self->f40, p, &k))
            return 0;
        p += 2;
    }
    *rem -= p - src;
    return 1;
}
