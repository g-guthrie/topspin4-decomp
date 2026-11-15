/* CX36: hash-keyed byte readers, session helpers and bit-stream writers, Swing_DLL.xex 0x8892xxxx-0x8893xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX36_INL static __forceinline
#else
#define CX36_INL static inline
#endif

typedef struct Cx36Rel { int off; u32 hash; } Cx36Rel;

/* 0x88922FE8: byte at +7 for the first hash, +0xD for four others, else 0 */
u8 ts4_known_hash_byte_a_88922FE8(Cx36Rel *o)
{
    u8 r = 0;
    u32 h = o->hash;
    if (h == 0xFCF73E23)
        return *((u8 *)o + o->off + 7);
    if (h == 0x5559D5D6 || h == 0xC952E870 || h == 0x67860A08 || h == 0x5EFAFFB9)
        r = *((u8 *)o + o->off + 0xD);
    return r;
}
/* 0x88923068: byte at +6 for the first hash, +0xC for four others, else 0 */
u8 ts4_known_hash_byte_b_88923068(Cx36Rel *o)
{
    u8 r = 0;
    u32 h = o->hash;
    if (h == 0xFCF73E23)
        return *((u8 *)o + o->off + 6);
    if (h == 0x5559D5D6 || h == 0xC952E870 || h == 0x67860A08 || h == 0x5EFAFFB9)
        r = *((u8 *)o + o->off + 0xC);
    return r;
}

/* 0x88936BB0: advance the bit stream when the cursor is past the limit, else mark it overflowed */
typedef struct Cx36BS { void **vt; u32 pos; u32 lim; int err; } Cx36BS;
extern void fn_88936A90(Cx36BS *b);
Cx36BS *ts4_bits_step_88936BB0(Cx36BS *b)
{
    u32 c = b->pos >= b->lim + 1;
    if ((u8)c == 0) {
        if (b->err == 0)
            b->err = 2;
    }
    if ((u8)c != 0)
        fn_88936A90(b);
    return b;
}

/* 0x88939210: write a NUL-terminated string (with terminator) or flag an error when null */
#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#else
#include <string.h>
#endif
extern void fn_88939040(Cx36BS *b, const char *s, u32 n);
Cx36BS *ts4_bits_write_string_88939210(Cx36BS *b, const char *s)
{
    if (s) {
        fn_88939040(b, s, strlen(s) + 1);
    } else if (b->err == 0)
        b->err = 3;
    return b;
}
