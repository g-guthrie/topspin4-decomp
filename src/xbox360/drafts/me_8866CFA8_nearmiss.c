/* NEAR MISS (14 lines: prologue scheduling only; target does `mr r31,r3` and `lis r3,heap` before
 * the header stores, which then go through r31). Everything after the call matches.
 * 0x8866CFA8: constructor; both blend limits take the script default, the two
 * counters are cleared, a 0x14-byte helper (own vtable, three cleared words) is allocated from
 * the game heap, the dirty flag is set and the blend weight zeroed. */
typedef unsigned int u32;
typedef struct Helper { void *vt; int a, b, c; int pad; } Helper;
typedef struct Self { void *vt; char p[0xc]; int n0; int n1; Helper *helper; char p1[0x30 - 0x1c]; float lim0;
    char p2[0x60 - 0x34]; float lim1; char p3[0x6c - 0x64]; float weight; unsigned char dirty; unsigned char busy; } Self;
extern char lbl_880F4464[];
extern char lbl_880F4804[];
extern float g_ts4_script_constants[];
extern float lbl_8814B440;
extern void *lbl_88D45B38;
extern void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);
static __inline Helper *helper_init(Helper *h) { h->a = 0; h->b = 0; h->c = 0; h->vt = lbl_880F4804; return h; }
Self *ts4_ctor_blend_helper_8866CFA8(Self *s)
{
    void *mem;
    Helper *h;
    float d = g_ts4_script_constants[69];
    s->vt = lbl_880F4464;
    s->lim0 = d;
    s->lim1 = d;
    s->n0 = 0;
    s->n1 = 0;
    mem = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, sizeof(Helper), 4, 0, 2);
    if (mem)
        h = helper_init((Helper *)mem);
    else
        h = 0;
    s->helper = h;
    s->busy = 0;
    s->dirty = 1;
    s->weight = lbl_8814B440;
    return s;
}
