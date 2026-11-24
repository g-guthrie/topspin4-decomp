/* W11H: core reset, LTCG route. Swing_DLL.xex 0x886E0C48 */
#include "w6b_types.h"
extern const __vector4 lbl_880FC650;
extern const float g_ts4_event_value;
extern void fn_886DF3B0(void *p);
typedef struct E1Sl { unsigned char b0; unsigned char b1; unsigned char pad[2]; int w4; int w8; int wc; } E1Sl;
typedef struct E1Ent { unsigned char p0[0x48]; E1Sl sl; } E1Ent;
static __inline void e1_sl_init(E1Sl *s) { s->b0 = 0; s->b1 = 0; s->w4 = 0; s->w8 = 0; s->wc = -1; }
typedef struct E1Hdr { int rel; } E1Hdr;
typedef struct E1Blk { __vector4 va; __vector4 vb; float f20; unsigned char b24; } E1Blk;
typedef struct E1Core { unsigned char pad[0x103]; unsigned char b103; unsigned char pad1[0x4b0 - 0x104]; E1Blk blk; unsigned char pad2[0x518 - 0x4b0 - sizeof(E1Blk)]; int idx; } E1Core;
typedef struct E1Sub { unsigned char pad[0x38]; E1Hdr *h; } E1Sub;
typedef struct E1Self { unsigned char pad[0x10]; E1Sub *sub; E1Core *core; } E1Self;
static __inline E1Ent *e1_ent(E1Hdr *h, int i) { return (E1Ent *)((char *)h + (i * 0x140 + h->rel)); }
static __inline void e1_blk_init(E1Blk *b)
{
    __vector4 v = lbl_880FC650;
    __vector4 w = __vor(v, v);
    b->va = v;
    b->vb = w;
    b->f20 = g_ts4_event_value;
    b->b24 = 0;
}
#ifdef _MSC_VER
#define E1_PAD int op1_pad0 = 0;
#else
#define E1_PAD
#endif
void ts4_reset_core_886E0C48(E1Self *self)
{
    E1_PAD 
    E1Core *c = self->core;
    E1Ent *e;
    fn_886DF3B0((char *)self + 0x30);
    e1_blk_init(&self->core->blk);
    c->b103 = 1;
    e = e1_ent(self->sub->h, self->core->idx);
    e1_sl_init(&e->sl);
}
