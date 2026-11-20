/* CX37: small net/lobby/scheduler/front-end helpers, Swing_DLL.xex 0x8894xxxx-0x8895xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX37_INL static __forceinline
#else
#define CX37_INL static inline
#endif

typedef struct Cx37Flag { u8 pad[0x1d]; u8 b1d; } Cx37Flag;
#if 0 /* near miss, not byte-identical */
/* 0x88941E00: flag whether the id is 0xA6F6E957 */
void ts4_set_flag_if_id_88941E00(Cx37Flag *o, u32 id)
{
    o->b1d = id == 0xA6F6E957;
}
#endif

typedef struct Cx37V3 { u32 a, b, c; } Cx37V3;
CX37_INL void cx37_v3_default(Cx37V3 *dst)
{
    Cx37V3 d;
    d.a = 0;
    d.c = 0;
    d.b = 0xFFFFF;
    *dst = d;
}
typedef struct Cx37R3 { u8 pad[8]; u32 w8; u8 pad2[0x2c - 0xc]; u8 b2c; u8 pad3[3]; Cx37V3 v; } Cx37R3;
/* 0x88941940 */
void ts4_range_reset_88941940(Cx37R3 *o)
{
    cx37_v3_default(&o->v);
    o->b2c = 0;
    o->w8 = 3;
}
typedef struct Cx37R1 { u8 pad[8]; u32 w8; u8 pad2[0x1c - 0xc]; u8 b1c; u8 pad3[3]; Cx37V3 v; } Cx37R1;
/* 0x88941970 */
void ts4_range_reset_88941970(Cx37R1 *o)
{
    cx37_v3_default(&o->v);
    o->b1c = 0;
    o->w8 = 1;
}
/* 0x88943730 */
void ts4_range_reset_88943730(Cx37R1 *o)
{
    cx37_v3_default(&o->v);
    o->b1c = 0;
    o->w8 = 1;
}

typedef struct Cx37Ctx { u8 pad[0x1c]; char *w1c; char *w20; } Cx37Ctx;
extern char *lbl_88D458C0;
#if 0 /* near miss, not byte-identical */
/* 0x88941C28 */
void ts4_ctx_init_88941C28(Cx37Ctx *o, u32 *key)
{
    char *g;
    o->w20 = 0;
    g = lbl_88D458C0;
    o->w1c = g;
    if (*key == 0xF5BF4F97)
        o->w20 = g + 0xcc;
    else
        o->w20 = g + 0x194;
}
#endif
