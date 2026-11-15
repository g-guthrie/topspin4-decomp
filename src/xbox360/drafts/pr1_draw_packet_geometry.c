/*
 * DRAFT (not part of the matching build). PR1, wave PR1.
 * 0x88750E30 DrawPacketGeometry (0x294 B), names from docs/renderer-map.md sections 1.2 and 3.3.
 *
 * Status: 14 instructions differ (plain route). 9 are a swapped scratch register pair at the top (the view
 * pointer and g_Display: target r11/r10, candidate r10/r11); 5 are the tail-chunk offset of the chunked
 * export path: the target computes (chunk_len * chunks) * stride, the candidate reuses stride*chunk_len
 * (CSE with the loop's chunk size) and multiplies by chunks. Tried: every association/operand order, signed
 * fields, a separate local, load placement of g_Display/view, volatile placement.
 *
 * Argument: the render state object st = *(g_Display + 0x24) (the same object RenderPacketLoop passes to
 * 0x887326B0 and 0x88730CD8), NOT the packet: the map's "packet+0x328" is st+0x328, the current job/view
 * record, which 0x887326B0 sets for each packet.
 *
 * What it does:
 *  - dev = *(g_Display + 0x15720).
 *  - No export record (view->+0x74 == NULL): DrawPacketPrimitives 0x8874EA60(st) (DrawVertices or
 *    DrawIndexedVertices with the primitive-count table at 0x880D1A00) and return.
 *  - Export record present: return unless g_Display+0x15628 > 2 and e->count (+0) != 0.
 *    Unbind streams 1 and 2 (D3DDevice_SetStreamSource 0x8828E000(dev, s, NULL, 0, 0, 1)).
 *    Draw through 0x8829AE68(dev, a, start, n):
 *      chunked (e->+0x1C != 0): `chunks` (+0x20) draws of stride(+0x8)*chunk_len(+0x24) starting at base (+4),
 *      then, if tail_len (+0x28) != 0, one draw of stride*tail_len at base + chunk_len*chunks*stride;
 *      else one draw (dev, count, base, stride*count).
 *    Then the inlined D3D block below (device fields from docs/renderer-map.md 2.3), then the record's
 *    completion callback e->cb(+0x18)(e->cb_arg(+0x10)) when set.
 * fn_equiv: see the PR1 report (work/equiv/pr1_88750E30.json).
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Pr1Export {
    u32 count;              /* +0x00 */
    u32 base;               /* +0x04 */
    u32 stride;             /* +0x08 */
    u32 pc;
    void *cb_arg;           /* +0x10 */
    u32 p14;
    void (*cb)(void *);     /* +0x18 */
    u8 chunked;             /* +0x1C */
    u8 p1d[3];
    u32 chunks;             /* +0x20 */
    u32 chunk_len;          /* +0x24 */
    u32 tail_len;           /* +0x28 */
} Pr1Export;
/* current job/view record, *(state + 0x328), set per packet by 0x887326B0 */
typedef struct Pr1View { u8 p0[0x74]; Pr1Export *exp; } Pr1View;
/* render state object, *(g_Display + 0x24) */
typedef struct Pr1State { u8 p0[0x328]; Pr1View *view; } Pr1State;
typedef struct Pr1DevList { u32 p0[3]; u32 *wp; u32 *limit; } Pr1DevList;
typedef struct Pr1ExportSlot { u32 *fixup; u32 p4; u32 *addr; u32 used; u8 p10[8]; } Pr1ExportSlot;
extern char *lbl_88D45AD4;
extern void fn_8874EA60(Pr1State *st);
extern void fn_8828E000(char *dev, u32 stream, void *vb, u32 offset, u32 stride, u32 freq);
extern void fn_8829AE68(char *dev, u32 a, u32 start, u32 n);
extern void fn_88292598(char *dev);
extern u32 *fn_88291290(Pr1DevList *list);
extern void fn_8829A260(char *dev, u32 a);
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
INL void pr1_fix_slot(Pr1ExportSlot *s)
{
    if (s->fixup != 0) {
        u32 a = (u32)(unsigned long)s->addr;
        *s->fixup = ((((a >> 20) + 0x200) & 0x1000) + (a & 0x1FFFFFFF)) - 0x40000000;
        *s->addr = 0xC0000000;
    }
    s->used = 0;
}
INL u32 *pr1_list_reserve(Pr1DevList *l)
{
    u32 *p = l->wp;
    if (p + 1 > l->limit) p = fn_88291290(l);
    return p;
}
void ts4_draw_packet_geometry_88750E30(Pr1State *st)
{
    char *g = lbl_88D45AD4;
    Pr1View *v = st->view;
    char *dev = *(char **)(g + 0x15720);
    Pr1Export *e;
    u32 *p;
    if (*(Pr1Export * volatile *)&v->exp == 0) {
        fn_8874EA60(st);
        return;
    }
    if (*(int *)(g + 0x15628) <= 2) return;
    e = v->exp;
    if (e->count == 0) return;
    fn_8828E000(dev, 1, 0, 0, 0, 1);
    fn_8828E000(dev, 2, 0, 0, 0, 1);
    if (e->chunked != 0) {
        u32 base = e->base;
        if (e->chunks != 0 && e->chunk_len != 0) {
            u32 n = e->stride * e->chunk_len;
            u32 i = 0;
            u32 off;
            if (i < e->chunks) {
                off = base;
                do {
                    fn_8829AE68(dev, 1, off, n);
                    i++;
                    off += n;
                } while (i < e->chunks);
            }
        }
        if (e->tail_len != 0) {
            u32 off = e->chunk_len * e->chunks * e->stride + base;
            fn_8829AE68(dev, 1, off, e->stride * e->tail_len);
        }
    } else {
        fn_8829AE68(dev, e->count, e->base, e->stride * e->count);
    }
    /* inlined D3D (end of the export/point-list job): clear device flag bit 1 at +0x2ABC, touch the GPU
       fence (*(dev+0x2A90), volatile read), make command-buffer space (0x88292598), patch the three export
       slots (CPU->GPU physical address, minus 0x40000000, then 0xC0000000 marker), append tag 0x8B000000 to
       the deferred-record list at +0x3500 and, unless flags 0x20/0x40 are set, flush it (0x8829A260). */
    *(u8 *)(dev + 0x2abc) &= ~2;
    (void)**(volatile u32 **)(dev + 0x2a90);
    fn_88292598(dev);
    pr1_fix_slot((Pr1ExportSlot *)(dev + 0x34a4));
    pr1_fix_slot((Pr1ExportSlot *)(dev + 0x34bc));
    pr1_fix_slot((Pr1ExportSlot *)(dev + 0x34d4));
    p = pr1_list_reserve((Pr1DevList *)(dev + 0x3500));
    *p = 0x8B000000;
    *(u32 **)(dev + 0x350c) = p + 1;
    if (!(*(u8 *)(dev + 0x2abc) & 0x20) && !(*(u8 *)(dev + 0x2abc) & 0x40)) fn_8829A260(dev, *(u32 *)(dev + 0x2ecc));
    if (e->cb != 0) e->cb(e->cb_arg);
}
