/*
 * DRAFT (not part of the matching build). PR1, wave PR1.
 * 0x8875E4C8 RenderPacketLoop (0x5FC B), names from docs/renderer-map.md sections 1.2 and 4.2.
 *
 * Status: plain route, 373 instructions differ (candidate 0x604 B vs 0x5FC). The control flow, call order and
 * nearly every load/compare line up block for block; most differences are a one-register shift of the
 * 18 saved registers (r14-r31) and the spill slots of the five per-frame pointers, plus a few CSE choices
 * (the target loads +0xA6 once for the two frame-flag stores; it keeps the shader index from the compare in
 * r30 for the 0x8C multiply). Not tuned further.
 *
 * Called as RenderPacketLoop(g+0x1D64 (sorted packet-pointer vector), g+0x155F0 (extra packets)) from
 * CDisplay::RenderFrame (matched, src/xbox360/pr1_display_frame.c).
 *
 * What it does:
 *  - Lock the RHI (*0x88D45A4C + 0x154). Read the per-frame pointers from g_Display: +0x18 shader table,
 *    +0x1C views/constant banks, +0x20 per-frame flag block, +0x24 render state (st), +0x3C pass context.
 *    Cache the index of the "CamUI" render layer (CRC32 0xD2284DB4 in the hash table g+0x2C) in the global
 *    0x88C6D0F0 (starts at -1).
 *  - If there is anything to draw (vector size + extra->count(+0x10)): build a default packet on the stack
 *    (ctor 0x88713DF8, dtor ts4_clear_finalize_88713DA8) as "previous", clear the first packet's pass flag
 *    bit 2 (no resolve-and-rebind before the first packet), then walk the packets. Iteration has three
 *    phases: the vector (phase -1); after the first packet whose pass.tex_index (+0x74) is 0 (the first
 *    packet drawn into the main buffer) the extra list (phase 0, nodes from extra->+0xC, next = 0x8815D480,
 *    packet at node+0x10); when the list returns to its head, the rest of the vector (phase 1).
 *  - Per packet:
 *    1. Frame skipping: period +0xA0 (1 = every frame); bitfield +0xA1 {count:7, const_bank:1}: while
 *       count != 0 decrement it and skip the packet; at 0 reload count = period - 1 and draw.
 *    2. Each state block is sent only when it differs from the previously drawn packet:
 *       layer +0xA5 / slot +0xA2 -> ts4_select_slot_entry_8874E9E8(g->+0x1C, layer, slot);
 *       always ExecutePassCommands(passctx, &pkt->pass) and 0x887326B0(st, view +0x94, pkt) (job set-up);
 *       camera +0xA7 -> 0x887071D0(camera) (camera VS constants);
 *       view +0x94 or light key +0x80 -> 0x886F71E0(view, 12-byte light key at +0x7C by value) (lights);
 *       material block +0x50 (ts4_intvec_equal_8822DF38) -> 0x88730CD8(st, &pkt->material, +0x34);
 *       vertex format +0x90 or view -> BindVertexFormat (matched 0x88722798) with *(st->+0x328)+0x40 +
 *       64*vformat, unless the job has an export record (+0x74);
 *       flag bit 5 of +0xA6 -> g+0x15688 = 1/0; bits 6/7 always copied to frame block +9/+8;
 *       shader +0x8E, variant +0xA4, material, or flag bits 5-7, or st->+0x324 (force) -> SelectAndBindShader
 *       0x8875D910(g->+0x28, shader entry (0x8C B, variant table at +0x3C when +0x1C), &pkt->+0x96);
 *       constant block +0x92 -> 0x887074E0(block) when != -1;
 *       VS constants c177-c180 (SetVertexShaderConstantF fast path 0x88290568(dev, 0xB1, p, 4, 0xC0000)):
 *       from bank g+0x15650 + 128*block when const_bank is set, else (when +0x8C changed) store +0x8C into
 *       *(g->+0x1C) and use *(g->+0x1C)->+0x2C + 64*index.
 *    3. Draw: DrawPacketGeometry 0x88750E30(st). Packets drawn into the main buffer (tex_index < 1) while
 *       *(0x88D45A48)+0x71 is set go through the multi-view path: sort key +0x9C in [6000, 7000): 0x8874B668
 *       (passctx, 0, passctx->+0x40, passctx->+0x3C), draw once, ts4_step_mod2_88750DD0(passctx); CamUI
 *       layer packets without +0xA8: select (layer, slot, 0), draw, step, draw; others: select(layer, slot,
 *       passctx->+0x30), draw, step, select again, draw.
 *    4. The drawn packet becomes "previous".
 *  - Destroy the stack packet, unlock.
 * fn_equiv: see the PR1 report (work/equiv/pr1_8875E4C8.json).
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned long long u64;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
typedef struct Pr1PassCmd { u8 flags; s8 slot; u8 level; u8 p3; int tex_index; int rt_index; } Pr1PassCmd;
typedef struct Pr1LightKey { u32 a, b, c; } Pr1LightKey;   /* +0x7C..+0x87, passed by value */
/* bitfield byte at +0xA1 (MSVC bitfields are MSB first) */
typedef struct Pr1Countdown { u8 count : 7; u8 const_bank : 1; } Pr1Countdown;
typedef struct Pr1Packet {
    u8 p0[0x34];
    u32 material_arg;       /* +0x34 */
    u8 p38[0x18];
    u32 material[8];        /* +0x50 parameter block (int vector), compared with ts4_intvec_equal_8822DF38 */
    Pr1PassCmd pass;        /* +0x70 */
    Pr1LightKey light;      /* +0x7C (+0x80 light key, +0x84) */
    u32 p88;
    s16 const_index;        /* +0x8C */
    s16 shader;             /* +0x8E */
    s16 vformat;            /* +0x90 */
    s16 const_block;        /* +0x92 */
    s16 view;               /* +0x94 */
    u16 shader_data;        /* +0x96 */
    u32 p98;
    int sort_key;           /* +0x9C */
    u8 period;              /* +0xA0 */
    Pr1Countdown cd;        /* +0xA1 */
    s8 slot;                /* +0xA2 */
    u8 pa3;
    s8 variant;             /* +0xA4 */
    s8 layer;               /* +0xA5 */
    u8 flags;               /* +0xA6 bit5 -> g+0x15688, bit6/bit7 -> per-frame flags */
    s8 camera;              /* +0xA7 */
    u8 no_multiview;        /* +0xA8 */
    u8 pa9[7];
} Pr1Packet;
typedef struct Pr1PacketVec { Pr1Packet **first; Pr1Packet **last; } Pr1PacketVec;
typedef struct Pr1ListNode { u8 p0[0x10]; Pr1Packet *pkt; } Pr1ListNode;
typedef struct Pr1PacketList { u8 p0[8]; Pr1ListNode *first; } Pr1PacketList;
typedef struct Pr1Extra { u8 p0[0xc]; Pr1PacketList *list; int count; } Pr1Extra;
typedef struct Pr1Pair { u32 hash; int idx; } Pr1Pair;
typedef struct Pr1HashTab { u32 p0; Pr1Pair *first; Pr1Pair *last; } Pr1HashTab;
typedef struct Pr1Shader { u8 p0[0x1c]; u8 has_variants; u8 p1d[0x1f]; struct Pr1Shader *variants; u8 p40[0x4c]; } Pr1Shader;
typedef struct Pr1State { u8 p0[0x324]; u8 force_shader; u8 p325[3]; char *view; } Pr1State;
typedef struct Pr1Lock { void **vt; } Pr1Lock;
typedef void (*Pr1VFn)(void *);
extern char *lbl_88D45AD4;
extern char *lbl_88D45A4C;
extern char *lbl_88D45A48;
extern int lbl_88C6D0F0;
extern void fn_88713DF8(Pr1Packet *p);
extern void ts4_clear_finalize_88713DA8(Pr1Packet *p);
extern void ts4_select_slot_entry_8874E9E8(void *tab, int layer, int slot);
extern void fn_88759BA0(void *passctx, Pr1PassCmd *cmd);
extern void fn_887326B0(Pr1State *st, int view, Pr1Packet *pkt);
extern void fn_887071D0(int camera);
extern void fn_886F71E0(int view, Pr1LightKey key);
extern u32 ts4_intvec_equal_8822DF38(void *a, void *b);
extern void fn_88730CD8(Pr1State *st, void *material, u32 arg);
extern void ts4_if_call_seq_u8_off2d_88722798(Pr1State *st, void *vformat);
extern void fn_8875D910(void *a, Pr1Shader *sh, void *data);
extern void fn_887074E0(int block);
extern void fn_88290568(void *dev, u32 reg, void *data, u32 count, u32 mask);
extern void fn_8874B668(void *passctx, u32 a, u32 b, u32 c);
extern void fn_88750E30(Pr1State *st);
extern void ts4_step_mod2_88750DD0(void *passctx);
extern void ts4_select_slot_or_forward_887146C0(int layer, int slot, u32 arg);
extern Pr1ListNode *ts4_rb_tree_increment_8815D480(Pr1ListNode *n);
INL Pr1Pair *pr1_findp(Pr1HashTab *t, u32 h)
{
    Pr1Pair *e = t->last;
    Pr1Pair *p = t->first;
    for (; p != e; p++)
        if (p->hash == h) break;
    return p;
}
INL int pr1_find(Pr1HashTab *t, u32 h)
{
    Pr1Pair *p = pr1_findp(t, h);
    if (p != t->last) return p->idx;
    return -1;
}
void ts4_render_packet_loop_8875E4C8(Pr1PacketVec *pv, Pr1Extra *ext)
{
    Pr1Lock *lk = (Pr1Lock *)(lbl_88D45A4C + 0x154);
    char *g;
    char *shaders, *views, *frame;
    Pr1State *st;
    char *passctx;
    u32 n;
    Pr1Packet prev_init;
    Pr1Packet *prev;
    Pr1PacketList *list;
    Pr1ListNode *node;
    Pr1Packet **it, **end;
    int phase;
    ((Pr1VFn)lk->vt[1])(lk);
    g = lbl_88D45AD4;
    n = (u32)(pv->last - pv->first) + ext->count;
    shaders = *(char **)(g + 0x18);
    views = *(char **)(g + 0x1c);
    frame = *(char **)(g + 0x20);
    st = *(Pr1State **)(g + 0x24);
    passctx = *(char **)(g + 0x3c);
    if (lbl_88C6D0F0 == -1) lbl_88C6D0F0 = pr1_find(*(Pr1HashTab **)(g + 0x2c), 0xD2284DB4u); /* "CamUI" */
    if (n != 0) {
        fn_88713DF8(&prev_init);
        prev = &prev_init;
        phase = -1;
        (*pv->first)->pass.flags &= ~4;
        list = ext->list;
        it = pv->first;
        end = pv->last;
        node = list->first;
        while (it != end) {
            Pr1Packet *pkt;
            u8 skip;
            if (phase == 0) pkt = node->pkt;
            else pkt = *it;
            /* draw only every `period` frames */
            if (pkt->period != 1) {
                if (pkt->cd.count != 0) {
                    pkt->cd.count--;
                    skip = 1;
                } else {
                    pkt->cd.count = pkt->period - 1;
                    skip = 0;
                }
            } else {
                skip = 0;
            }
            if (!skip) {
                if (prev->layer != pkt->layer || *(u8 *)&prev->slot != *(u8 *)&pkt->slot)
                    ts4_select_slot_entry_8874E9E8(*(void **)(g + 0x1c), pkt->layer, pkt->slot);
                fn_88759BA0(passctx, &pkt->pass);
                fn_887326B0(st, pkt->view, pkt);
                if (prev->camera != pkt->camera) fn_887071D0(pkt->camera);
                if (prev->view != pkt->view || prev->light.b != pkt->light.b) fn_886F71E0(pkt->view, pkt->light);
                if (!(u8)ts4_intvec_equal_8822DF38(prev->material, pkt->material))
                    fn_88730CD8(st, pkt->material, pkt->material_arg);
                if (prev->vformat != pkt->vformat || *(u16 *)&prev->view != *(u16 *)&pkt->view) {
                    char *v = st->view;
                    if (*(int *)(v + 0x74) == 0)
                        ts4_if_call_seq_u8_off2d_88722798(st, *(char **)(v + 0x40) + pkt->vformat * 0x40);
                }
                {
                    u32 b = (pkt->flags >> 5) & 1;
                    if (((prev->flags >> 5) & 1) != b) {
                        if (b == 1) *(u32 *)(g + 0x15688) = 1;
                        else *(u32 *)(g + 0x15688) = 0;
                    }
                }
                frame[9] = (pkt->flags >> 6) & 1;
                frame[8] = pkt->flags >> 7;
                if (prev->shader != pkt->shader || *(u8 *)&prev->variant != *(u8 *)&pkt->variant ||
                    !(u8)ts4_intvec_equal_8822DF38(prev->material, pkt->material) ||
                    ((prev->flags ^ pkt->flags) & 0x80) || ((prev->flags ^ pkt->flags) & 0x40) ||
                    ((prev->flags ^ pkt->flags) & 0x20) || st->force_shader != 0) {
                    Pr1Shader *sh = (Pr1Shader *)(*(char **)(shaders + 0x20) + pkt->shader * 0x8c);
                    if (pkt->variant != -1 && sh->has_variants != 0) sh = &sh->variants[pkt->variant];
                    fn_8875D910(*(void **)(lbl_88D45AD4 + 0x28), sh, &pkt->shader_data);
                }
                if (prev->const_block != pkt->const_block && pkt->const_block != -1) fn_887074E0(pkt->const_block);
                if (pkt->cd.const_bank) {
                    char *gg = lbl_88D45AD4;
                    fn_88290568(*(void **)(gg + 0x15720), 0xb1, *(char **)(g + 0x15650) + pkt->const_block * 0x80, 4, 0xC0000);
                } else if (prev->const_index != pkt->const_index || prev->cd.const_bank) {
                    char *gg;
                    *(int *)views = pkt->const_index;
                    gg = lbl_88D45AD4;
                    fn_88290568(*(void **)(gg + 0x15720), 0xb1,
                                *(char **)(*(char **)(gg + 0x1c) + 0x2c) + pkt->const_index * 0x40, 4, 0xC0000);
                }
                /* main-buffer packets go through the multi-view path */
                if (pkt->pass.tex_index < 1 && lbl_88D45A48[0x71] != 0) {
                    if (pkt->sort_key >= 6000 && pkt->sort_key < 7000) {
                        fn_8874B668(passctx, 0, *(u32 *)(passctx + 0x40), *(u32 *)(passctx + 0x3c));
                        fn_88750E30(st);
                        ts4_step_mod2_88750DD0(passctx);
                    } else if (pkt->layer == lbl_88C6D0F0 && pkt->no_multiview == 0) {
                        ts4_select_slot_or_forward_887146C0(pkt->layer, pkt->slot, 0);
                        fn_88750E30(st);
                        ts4_step_mod2_88750DD0(passctx);
                        fn_88750E30(st);
                    } else {
                        ts4_select_slot_or_forward_887146C0(pkt->layer, pkt->slot, *(u32 *)(passctx + 0x30));
                        fn_88750E30(st);
                        ts4_step_mod2_88750DD0(passctx);
                        ts4_select_slot_or_forward_887146C0(pkt->layer, pkt->slot, *(u32 *)(passctx + 0x30));
                        fn_88750E30(st);
                    }
                } else {
                    fn_88750E30(st);
                }
                prev = pkt;
            }
            if (phase == 0) node = ts4_rb_tree_increment_8815D480(node);
            else it++;
            if (pkt->pass.tex_index == 0 && phase == -1) phase = 0;
            else if (phase == 0 && node == (Pr1ListNode *)list) phase = 1;
        }
        ts4_clear_finalize_88713DA8(&prev_init);
    }
    ((Pr1VFn)lk->vt[2])(lk);
}
