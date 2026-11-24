/* CW11 part a: XData wire-record readers/writers (0x885F4E48-0x88610000). Built with /Oc. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long long u64;
#ifdef _MSC_VER
extern void *memset(void *, int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

typedef struct Cx11Span { u8 pad[0xc]; u8 *data; u32 size; u16 pad2; short count; } Cx11Span;

/* 0x885F5F88: copy record idx (10 bytes: u64 + u16) out of a counted span, honouring the bytes left */
u32 ts4_span_read_rec10_885F5F88(Cx11Span *s, short idx, u64 *out)
{
    u8 *p;
    u32 size;
    if (idx >= s->count) return 0;
    size = s->size;
    p = s->data;
    if (idx > 0) p += idx * 10;
    if (size >= 8) {
        *out = *(u64 *)p;
        size -= 8;
    }
    if (size >= 2) {
        *(u16 *)((u8 *)out + 8) = *(u16 *)(p + 8);
    }
    return 1;
}

/* 0x885F57F8 / 0x885F5AB0: walk idx entries of {u16 tag, u16 len, data[len]}, then read tag, len and a 32-byte zero-padded copy of the data */
#define CX11_READ_NAME(NAME) \
void NAME(Cx11Span *s, short idx, u16 *out) \
{ \
    if (idx < s->count) { \
        u32 size = s->size; \
        u16 *p = (u16 *)s->data; \
        u16 len = 0; \
        u16 *q; \
        int i; \
        for (i = 0; i < idx; i++) { \
            p++; \
            if (size >= 2) { \
                len = *p; \
                size -= 2; \
            } \
            p = (u16 *)((u8 *)p + len + 2); \
        } \
        if (size >= 2) { out[0] = *p; size -= 2; } \
        q = p + 1; \
        if (size >= 2) { out[1] = *q; } \
        memset(out + 2, 0, 0x20); \
        memcpy(out + 2, q + 1, out[1]); \
    } \
}
CX11_READ_NAME(ts4_span_read_name_885F57F8)
CX11_READ_NAME(ts4_span_read_name_885F5AB0)

extern char *fn_88603F38(void *o, u32 off);
extern u32 fn_88603D78(char *dst, const char *s);

/* 0x885F6398 / 0x885F6410: u16, u64, u32 header, a length-prefixed string, then a raw blob of f20 bytes */
typedef struct { char padc[12]; u16 fc; char pad0e[2]; u64 f10; const char *f18; const char *f1c; u32 f20; } Cx11RecA;
#define CX11_WRITE_A(NAME) \
int NAME(Cx11RecA *o, u32 off) \
{ \
    char *p = fn_88603F38(o, off) + off; \
    u32 n; \
    *(u16 *)p = o->fc; \
    p += 2; \
    *(u64 *)p = o->f10; \
    p += 8; \
    *(u32 *)p = o->f20; \
    p += 4; \
    p += fn_88603D78(p, o->f1c); \
    n = o->f20; \
    if (n != 0) memcpy(p, o->f18, n); \
    p += n; \
    return (int)(unsigned long)(p - off); \
}
CX11_WRITE_A(ts4_write_record_885F6398)
CX11_WRITE_A(ts4_write_record_885F6410)

/* 0x885F64E0: 56-byte block, two u16, one u32, then a raw blob of f48 bytes */
typedef struct { u64 q[7]; } Cx11Blk56;
#define CX11_COPY56(p, b) \
    (*(u64 *)(p) = (b).q[0], *(u64 *)((p) + 8) = (b).q[1], *(u64 *)((p) + 16) = (b).q[2], *(u64 *)((p) + 24) = (b).q[3], \
     *(u64 *)((p) + 32) = (b).q[4], *(u64 *)((p) + 40) = (b).q[5], *(u64 *)((p) + 48) = (b).q[6])
typedef struct { char padc[16]; Cx11Blk56 blk; u32 f48; const char *f4c; u16 f50; u16 f52; } Cx11RecB;
int ts4_write_record_885F64E0(Cx11RecB *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    u32 n;
    CX11_COPY56(p, o->blk);
    p += 56;
    *(u16 *)p = o->f52;
    p += 2;
    *(u16 *)p = o->f50;
    p += 2;
    *(u32 *)p = o->f48;
    p += 4;
    n = o->f48;
    if (n != 0) memcpy(p, o->f4c, n);
    p += n;
    return (int)(unsigned long)(p - off);
}

/* 0x885F6580: same 56-byte block, then u16 and two u32 */
typedef struct { char padc[16]; Cx11Blk56 blk; u32 f48; u32 f4c; char pad50[28]; u16 f6c; } Cx11RecC;
int ts4_write_record_885F6580(Cx11RecC *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    CX11_COPY56(p, o->blk);
    p += 56;
    *(u16 *)p = o->f6c;
    p += 2;
    *(u32 *)p = o->f48;
    p += 4;
    *(u32 *)p = o->f4c;
    p += 4;
    return (int)(unsigned long)(p - off);
}

/* 0x885F6B40: length-prefixed blob followed by a run of u16 and u32 fields */
typedef struct { char padc[12]; const char *fc; u32 f10; u16 f14; u16 f16; u32 f18; u32 f1c; u16 f20; u16 f22; u16 f24; u16 f26; u16 f28; u16 f2a; u16 f2c; u16 f2e; u16 f30; } Cx11RecD;
int ts4_write_record_885F6B40(Cx11RecD *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    u32 n;
    *(u32 *)p = o->f10;
    p += 4;
    n = o->f10;
    if (n != 0) memcpy(p, o->fc, n);
    p += n;
    *(u16 *)p = o->f14;
    p += 2;
    *(u16 *)p = o->f16;
    p += 2;
    *(u32 *)p = o->f18;
    p += 4;
    *(u32 *)p = o->f1c;
    p += 4;
    *(u16 *)p = o->f20;
    p += 2;
    *(u16 *)p = o->f22;
    p += 2;
    *(u16 *)p = o->f24;
    p += 2;
    *(u16 *)p = o->f26;
    p += 2;
    *(u16 *)p = o->f28;
    p += 2;
    *(u16 *)p = o->f2a;
    p += 2;
    *(u16 *)p = o->f2c;
    p += 2;
    *(u16 *)p = o->f2e;
    p += 2;
    *(u16 *)p = o->f30;
    p += 2;
    return (int)(unsigned long)(p - off);
}

/* 0x885F6C00: length-prefixed blob followed by two u16 and a u32 */
typedef struct { char padc[12]; const char *fc; u32 f10; u32 f14; u16 f18; u16 f1a; } Cx11RecE;
int ts4_write_record_885F6C00(Cx11RecE *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    u32 n;
    *(u32 *)p = o->f10;
    p += 4;
    n = o->f10;
    if (n != 0) memcpy(p, o->fc, n);
    p += n;
    *(u16 *)p = o->f18;
    p += 2;
    *(u16 *)p = o->f1a;
    p += 2;
    *(u32 *)p = o->f14;
    p += 4;
    return (int)(unsigned long)(p - off);
}

/* 0x885FB998: u32 count followed by count 8-byte items */
typedef struct { char padc[12]; const char *fc; u32 f10; } Cx11RecF;
int ts4_write_record_885FB998(Cx11RecF *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    u32 n;
    *(u32 *)p = o->f10;
    p += 4;
    n = o->f10 << 3;
    if (n != 0) memcpy(p, o->fc, n);
    p += n;
    return (int)(unsigned long)(p - off);
}

/* 0x885FBF60: three u16, a u32-counted blob, then a trailing u64 */
typedef struct { char padc[12]; u16 fc; u16 fe; u16 f10; char pad12[2]; const char *f14; u32 f18; char pad1c[4]; u64 f20; } Cx11RecG;
int ts4_write_record_885FBF60(Cx11RecG *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    u32 n;
    *(u16 *)p = o->fc;
    p += 2;
    *(u16 *)p = o->fe;
    p += 2;
    *(u16 *)p = o->f10;
    p += 2;
    *(u32 *)p = o->f18;
    p += 4;
    n = o->f18;
    if (n != 0) memcpy(p, o->f14, n);
    p += n;
    *(u64 *)p = o->f20;
    p += 8;
    return (int)(unsigned long)(p - off);
}

/* 0x885FBFD8: a u16, a u32-counted blob, then a trailing u64 */
typedef struct { char padc[12]; u16 fc; char pad0e[2]; const char *f10; u32 f14; u64 f18; } Cx11RecH;
int ts4_write_record_885FBFD8(Cx11RecH *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    u32 n;
    *(u16 *)p = o->fc;
    p += 2;
    *(u32 *)p = o->f14;
    p += 4;
    n = o->f14;
    if (n != 0) memcpy(p, o->f10, n);
    p += n;
    *(u64 *)p = o->f18;
    p += 8;
    return (int)(unsigned long)(p - off);
}

/* 0x885FC708: two u32-counted blobs, two strings, a u16 and a u32 */
typedef struct { char padc[12]; const char *fc; u32 f10; const char *f14; u32 f18; const char *f1c; const char *f20; u16 f24; char pad26[2]; u32 f28; } Cx11RecI;
int ts4_write_record_885FC708(Cx11RecI *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    u32 n;
    *(u32 *)p = o->f10;
    p += 4;
    n = o->f10;
    if (n != 0) memcpy(p, o->fc, n);
    p += n;
    *(u32 *)p = o->f18;
    p += 4;
    n = o->f18;
    if (n != 0) memcpy(p, o->f14, n);
    p += n;
    p += fn_88603D78(p, o->f1c);
    p += fn_88603D78(p, o->f20);
    *(u16 *)p = o->f24;
    p += 2;
    *(u32 *)p = o->f28;
    p += 4;
    return (int)(unsigned long)(p - off);
}

/* 0x885FC910: eight u16, two u32-counted blobs, a u16, two strings, a u32 and a u16 */
typedef struct { char padc[12]; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; char pad1e[2]; const char *f20; u32 f24; const char *f28; u32 f2c; u16 f30; char pad32[2]; const char *f34; const char *f38; u32 f3c; u16 f40; } Cx11RecJ;
int ts4_write_record_885FC910(Cx11RecJ *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    u32 n;
    *(u16 *)p = o->fc;
    p += 2;
    *(u16 *)p = o->fe;
    p += 2;
    *(u16 *)p = o->f10;
    p += 2;
    *(u16 *)p = o->f12;
    p += 2;
    *(u16 *)p = o->f14;
    p += 2;
    *(u16 *)p = o->f16;
    p += 2;
    *(u16 *)p = o->f18;
    p += 2;
    *(u16 *)p = o->f1a;
    p += 2;
    *(u16 *)p = o->f1c;
    p += 2;
    *(u32 *)p = o->f24;
    p += 4;
    n = o->f24;
    if (n != 0) memcpy(p, o->f20, n);
    p += n;
    *(u32 *)p = o->f2c;
    p += 4;
    n = o->f2c;
    if (n != 0) memcpy(p, o->f28, n);
    p += n;
    *(u16 *)p = o->f30;
    p += 2;
    p += fn_88603D78(p, o->f34);
    p += fn_88603D78(p, o->f38);
    *(u32 *)p = o->f3c;
    p += 4;
    *(u16 *)p = o->f40;
    p += 2;
    return (int)(unsigned long)(p - off);
}

/* 0x885F5BB0: skip idx entries of {u32,u32,u16 x5,u16 len,data[len]}, then read the next one with a 32-byte-free-style bounds check per field,
   and a 0x80-byte zero-padded copy of the trailing data */
typedef struct Cx11Entry1 { u32 f0; u32 f4; u16 f8; u16 fa; u16 fc; u16 fe; u16 f10; u16 f12; u8 text[0x80]; } Cx11Entry1;
u32 ts4_span_read_entry_885F5BB0(Cx11Span *s, short idx, Cx11Entry1 *out)
{
    u32 size;
    u8 *p;
    u16 len;
    u8 *q;
    int i;
    if (idx >= s->count) return 0;
    size = s->size;
    len = 0;
    p = s->data;
    for (i = 0; i < idx; i++) {
        p += 0x12;
        if (size >= 2) { len = *(u16 *)p; size -= 2; }
        p += len + 2;
    }
    if (size >= 4) { out->f0 = *(u32 *)p; size -= 4; }
    p += 4;
    if (size >= 4) { out->f4 = *(u32 *)p; size -= 4; }
    p += 4;
    if (size >= 2) { out->f8 = *(u16 *)p; size -= 2; }
    p += 2;
    if (size >= 2) { out->fa = *(u16 *)p; size -= 2; }
    p += 2;
    if (size >= 2) { out->fc = *(u16 *)p; size -= 2; }
    p += 2;
    if (size >= 2) { out->fe = *(u16 *)p; size -= 2; }
    p += 2;
    if (size >= 2) { out->f10 = *(u16 *)p; size -= 2; }
    q = p + 2;
    if (size >= 2) { out->f12 = *(u16 *)q; }
    memset(out->text, 0, 0x80);
    memcpy(out->text, q + 2, out->f12);
    return 1;
}
