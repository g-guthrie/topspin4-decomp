/* agAR near-miss, 2 off: li r8,1 is scheduled before the first stw r11,0x10c (target: after). Same family as 888FA078 draft. Loop and other stores match. */

typedef unsigned int u32; typedef unsigned char u8;
typedef struct Elem { char b[0x3c]; } Elem;
typedef struct Range { u32 a, b, c, d, lim, e; } Range;
static __inline void range_init(Range *r)
{
    r->a = 0; r->b = 0; r->c = 0; r->d = 0; r->e = 0; r->lim = 0xFFFFF;
}
typedef struct O { const void *vt; char pad[0x18]; Elem e[4];
  Range r; u32 f124, f128; char pad2[0x28]; u8 f154; char pad3[7]; u8 f15c; } O;
extern void fn_88617D88(void *p);
extern Elem *fn_888FA078(Elem *e);
extern const char lbl_880DBD08[];
O *fn_888FD948(O *o)
{
    Elem *p; int i;
    fn_88617D88(o);
    o->vt = lbl_880DBD08;
    p = o->e; i = 3; do { fn_888FA078(p); p++; } while (--i >= 0);
    range_init(&o->r);
    o->f124 = 0; o->f128 = 0;
    o->f154 = 0; o->f15c = 1;
    return o;
}
