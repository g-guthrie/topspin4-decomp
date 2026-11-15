/* CX36: container and stream helpers, Swing_DLL.xex 0x8892xxxx-0x8893xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX36_INL static __forceinline
#else
#define CX36_INL static inline
#endif
extern void *fn_88562DC0(void *dst, const void *src, u32 n);

/* ---- destroy all owned elements then clear the pointer vector ---- */
typedef struct Cx36Obj { void **vt; } Cx36Obj;
typedef struct Cx36PV { Cx36Obj **first; Cx36Obj **last; } Cx36PV;
typedef void (*Cx36DelFn)(Cx36Obj *o, int flags);
CX36_INL Cx36Obj **cx36_mv(Cx36Obj **first, Cx36Obj **last, Cx36Obj **dst)
{
    if (first == last)
        return dst;
    {
        u32 n = (u32)((char *)last - (char *)first);
        return (Cx36Obj **)((char *)fn_88562DC0(dst, first, n) + n);
    }
}
/* 0x88922B28 */
void ts4_pv_destroy_all_88922B28(Cx36PV *v)
{
    Cx36Obj **p = v->first;
    Cx36Obj **end = v->last;
    for (; p != end; p++) {
        if (*p)
            ((Cx36DelFn)(*p)->vt[0])(*p, 1);
    }
    v->last = cx36_mv(v->last, v->last, v->first);
}
/* 0x889316F8 */
void ts4_pv_destroy_all_889316F8(Cx36PV *v)
{
    Cx36Obj **p = v->first;
    Cx36Obj **end = v->last;
    for (; p != end; p++) {
        if (*p)
            ((Cx36DelFn)(*p)->vt[0])(*p, 1);
    }
    v->last = cx36_mv(v->last, v->last, v->first);
}

/* 0x88936AF0: write one bit at the stream's bit cursor */
typedef struct Cx36Bits { void **vt; u32 pos; } Cx36Bits;
typedef u8 *(*Cx36DataFn)(Cx36Bits *b);
#if 0 /* near miss, not byte-identical */
Cx36Bits *ts4_bits_write_bit_88936AF0(Cx36Bits *b, u8 bit)
{
    u32 pos = b->pos;
    u8 *p = ((Cx36DataFn)b->vt[3])(b) + (pos >> 3);
    u32 mask;
    int n;
    u32 bb = bit;
    mask = 1 << (b->pos & 7);
    if (bb)
        *p = (u8)(mask | *p);
    else
        *p = (u8)(*p & ~mask);
    n = b->pos + 1;
    if (n >= 0)
        b->pos = n;
    return b;
}
#endif

/* 0x88936E38: swap the keys of the two elements found by key a and key b */
typedef struct Cx36KEl { u32 w0; int key; } Cx36KEl;
typedef struct Cx36KVec { u8 pad[4]; Cx36KEl **first; Cx36KEl **last; } Cx36KVec;
typedef struct Cx36KOwner { u8 pad[0x1c]; Cx36KVec *v; } Cx36KOwner;
#if 0 /* near miss, not byte-identical */
void ts4_swap_keys_88936E38(Cx36KOwner *o, int a, int b)
{
    Cx36KVec *v = o->v;
    Cx36KEl *ea = cx36_kfind(v, a);
    Cx36KEl *eb = cx36_kfind(v, b);
    if (ea)
        ea->key = b;
    if (eb)
        eb->key = a;
}
#endif
