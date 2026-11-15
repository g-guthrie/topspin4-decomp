/* PR1: Pam Display renderer frame control (wave PR1, plain route).
 *   0x8875F308 CDisplay::RenderFrame  (0x180)
 *   0x887690A8 CDisplay::ResetDevice  (0xEC)
 * Names and layouts follow docs/renderer-map.md (sections 1.2, 2.2, 4.2).
 * g_Display = *(char **)0x88D45AD4; its render-texture table is *(g+0x10): (CRC32(name), index) pairs
 * between +4 and +8, 0x44-byte entries at +0x24 with the texture pointer at entry+8.
 */
typedef unsigned int u32;
typedef unsigned char u8;
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wuninitialized"
#endif
#ifdef _MSC_VER
#define INL static __forceinline
typedef unsigned int pr1_size_t;
#else
#define INL static inline
typedef __SIZE_TYPE__ pr1_size_t;
#endif
typedef struct Pr1Less { u8 b; } Pr1Less;
typedef struct Pr1Pair { u32 hash; int idx; } Pr1Pair;
typedef struct Pr1RTex { u8 p0[8]; void *tex; u8 p1[0x38]; } Pr1RTex;
typedef struct Pr1TexTab { u32 p0; Pr1Pair *first; Pr1Pair *last; u8 p1[0x18]; Pr1RTex *ent; } Pr1TexTab;
extern char *lbl_88D45AD4;
extern int lbl_88C6D0F4;
extern int lbl_88C6D0F8;
extern void ts4_sort_ptrs_8822A1E8(void *, void *, Pr1Less);
extern void fn_88755E58(Pr1TexTab *, void *, u32);
extern void fn_8875E4C8(void *, void *);
/* inlined render-texture lookup: index of the entry whose name hash is h, or -1 */
INL Pr1Pair *pr1_findp(Pr1TexTab *t, u32 h)
{
    Pr1Pair *e = t->last;
    Pr1Pair *p = t->first;
    for (; p != e; p++)
        if (p->hash == h) break;
    return p;
}
INL int pr1_find(Pr1TexTab *t, u32 h)
{
    Pr1Pair *p = pr1_findp(t, h);
    if (p != t->last) return p->idx;
    return -1;
}
INL Pr1TexTab *pr1_tab(void) { return *(Pr1TexTab **)(lbl_88D45AD4 + 0x10); }
/* 0x8875F308 CDisplay::RenderFrame: sort the render-packet pointer array at g+0x1D64..+0x1D68, bind the two
 * default render textures (name hashes 0xADA3A6BB on sampler 5, 0x18F10F61 on sampler 4; indices cached in two
 * statics that start at -1) while a display hierarchy is active (g+0x1563C not 0 and not 0xDD3795AD), then run
 * RenderPacketLoop(g+0x1D64, g+0x155F0). */
void ts4_render_frame_8875F308(void)
{
    char *g = lbl_88D45AD4;
    char *a = g + 0x1d64;
    char *b = g + 0x155f0;
    Pr1Less c;
    u32 h;
    ts4_sort_ptrs_8822A1E8(*(void **)(g + 0x1d64), *(void **)(g + 0x1d68), c);
    g = lbl_88D45AD4;
    h = *(u32 *)(g + 0x1563c);
    if (h != 0 && h != 0xDD3795ADu) {
        if (lbl_88C6D0F4 == -1) lbl_88C6D0F4 = pr1_find(*(Pr1TexTab **)(g + 0x10), 0xADA3A6BBu);
        if (lbl_88C6D0F4 != -1) fn_88755E58(*(Pr1TexTab **)(g + 0x10), pr1_tab()->ent[lbl_88C6D0F4].tex, 5);
        if (lbl_88C6D0F8 == -1) lbl_88C6D0F8 = pr1_find(*(Pr1TexTab **)(g + 0x10), 0x18F10F61u);
        if (lbl_88C6D0F8 != -1) fn_88755E58(*(Pr1TexTab **)(g + 0x10), pr1_tab()->ent[lbl_88C6D0F8].tex, 4);
    }
    fn_8875E4C8(a, b);
}

typedef struct Pr1Lock { void **vt; } Pr1Lock;
typedef void (*Pr1VFn)(void *);
extern volatile int lbl_88D45A94;
extern volatile int lbl_88D45A7C;
extern char *lbl_88D45A4C;
extern void fn_88292A78(void *dev);
extern void fn_88296EB8(void *dev);
extern void fn_88767230(void *res);
extern int fn_88292B88(void *dev, void *ring);
extern void ts4_loop_call_seq_KeGetCurrentProcessType_882A26D8(void *dev);
extern int fn_882A2430(void *dev, void *pp);
extern void *memcpy(void *, const void *, pr1_size_t);
/* 0x887690A8 CDisplay::ResetDevice (self = g_Display): wait for the two busy flags 0x88D45A94/0x88D45A7C,
 * lock the RHI (*0x88D45A4C + 0x154, slot 1/2 = lock/unlock), BlockUntilIdle, unbind all, release the display
 * GPU resources (self+0x10), copy the present parameters self+0x15748 (0x7C bytes) to RHI+0x8C, re-initialise
 * the ring buffer from pp+0x48; on success BlockUntilIdle and set the video mode (0x882A26D8 around 0x882A2430). */
void ts4_reset_device_887690A8(char *self)
{
    Pr1Lock *lk;
    void **pdev;
    char *pp;
    void *dev;
    while (lbl_88D45A94 != 0 || lbl_88D45A7C != 0) ;
    lk = (Pr1Lock *)(lbl_88D45A4C + 0x154);
    ((Pr1VFn)lk->vt[1])(lk);
    pdev = (void **)(self + 0x15720);
    fn_88292A78(*pdev);
    fn_88296EB8(*pdev);
    fn_88767230(self + 0x10);
    pp = self + 0x15748;
    memcpy(lbl_88D45A4C + 0x8c, pp, 0x7c);
    dev = *pdev;
    if (fn_88292B88(dev, pp + 0x48) == 0) {
        fn_88292A78(dev);
        ts4_loop_call_seq_KeGetCurrentProcessType_882A26D8(dev);
        if (fn_882A2430(dev, pp) == 0) ts4_loop_call_seq_KeGetCurrentProcessType_882A26D8(dev);
    }
    ((Pr1VFn)lk->vt[2])(lk);
}
