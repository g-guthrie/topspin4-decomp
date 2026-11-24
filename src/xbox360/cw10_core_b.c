/* CW10 part b: game core 0x8820F390-0x88220C18, allocated objects. Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;

extern void *lbl_88D45B38;

/* 0x8821A070 / 0x8821A130: allocate and construct a 0x34-byte object (the second allocator argument differs: 2 vs 0) */
extern void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 align, u32 a, u32 b);
extern char lbl_880EFD14[];
typedef struct Cw10Lim { u32 a; u32 cap; u32 b; } Cw10Lim;
typedef struct Cw10Obj34 { void *vt; u32 f4, f8, fc, f10; u8 f14, f15; u32 f18; u8 f1c; u32 f20; u32 f24; Cw10Lim lim; } Cw10Obj34;
static void cw10_lim_ctor(Cw10Lim *l)
{
    l->cap = 0xFFFFF;
    l->a = 0;
    l->b = 0;
}
static void cw10_lim_reset(Cw10Lim *l)
{
    l->a = 0;
    l->b = 0;
    l->cap = 0xFFFFF;
}
static void cw10_obj34_init(Cw10Obj34 *q)
{
    volatile Cw10Obj34 *p = q;
    p->f4 = 0;
    p->f8 = 0;
    p->fc = 0;
    p->f10 = 0;
    p->f14 = 0;
    p->f15 = 0;
    p->f18 = 0;
    p->f1c = 0;
    p->f20 = 0xB6C65665;
    p->vt = lbl_880EFD14;
    p->f24 = 0;
    cw10_lim_ctor(&q->lim);
    cw10_lim_reset(&q->lim);
}
Cw10Obj34 *ts4_create_obj34_8821A070(void)
{
    Cw10Obj34 *p = (Cw10Obj34 *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x34, 4, 0, 2);
    if (p != 0) {
        cw10_obj34_init(p);
        return p;
    }
    return 0;
}
Cw10Obj34 *ts4_create_obj34_8821A130(void)
{
    Cw10Obj34 *p = (Cw10Obj34 *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x34, 4, 0, 0);
    if (p != 0) {
        cw10_obj34_init(p);
        return p;
    }
    return 0;
}
