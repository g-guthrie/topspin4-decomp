/*
 * DRAFT (not part of the matching build). PR1, wave PR1.
 * 0x88759BA0 ExecutePassCommands (0x4D0 B), names from docs/renderer-map.md section 1.3.
 *
 * Status:
 *  - LTCG route: 61 instructions differ. Command:
 *      python3 tools/fn_check_ltcg.py src/xbox360/drafts/pr1_execute_pass_commands.c
 *        --context src/xbox360/drafts/pr1_execute_pass_commands_ctx.c
 *        --context nogl:src/xbox360/drafts/pr1_execute_pass_commands_imp.c
 *        --include fn_88289D38 --include fn_886EB3E8 --include fn_88292698
 *        --include ts4_if_atomic_interlocked_dec_88288530 --include KeGetCurrentProcessType
 *        ts4_execute_pass_commands_88759BA0=0x88759BA0
 *    All 61 are saved-register colouring (the same values in permuted r24-r31) plus one swapped load pair
 *    in the "same target?" test. Same size, same stack frame, same relocations.
 *  - Plain route: 289 differ (frame 0xF0 instead of 0x100, one saved register fewer).
 *  Why LTCG: the target re-reads g_Display into r31 right after the calls that may change it (0x88756720,
 *  ResolveRT, the delete, CreateTexture, 0x88750BF0) but NOT after GetLevelDesc, the format map, the
 *  device accessor, BlockOnFence and Release. That is link-time mod/ref information. The context file
 *  gives LTCG stub bodies for exactly those five callees (touching only their own statics, with register
 *  footprints like the originals: the real 0x886EB3E8 uses only r3 and r8-r12, so the caller keeps the
 *  old format in r7 across it). This is the first use of "behavioural stubs as LTCG context" in this tree.
 *
 * What it does, ctx = pass context (*(g_Display+0x3C)), cmd = packet+0x70 (12-byte pass block):
 *  1. cmd->flags bit2: ResolveAndRebind (0x887567D8, matched) on ctx; bit1: ResolveSecondaryTargets
 *     0x887563A8(ctx->rt); bit3: ClearTarget 0x887533F8(ctx->rt, flags >> 4).
 *  2. dev = g->+0x15720. cur = ctx->last.rt_index (+0xC).
 *  3. New render-target descriptor (cmd->rt_index != cur and != -1):
 *     resolve the old one (0x88756720(cur) when cur != -1; ResolveRT(ctx->rt, 0) when the last pass rendered
 *     to a texture), delete the temporary level RT (ctx+0x14: 0x88750AD8 release twice around the read,
 *     then operator delete ts4_tsu_cleanup_end), BindRenderTarget 0x887534F0(cmd->rt_index), and when the
 *     current camera view (*(g->+0x1C)+8, entries of 0x120 B at *(g->+0x2C)+0x24) is enabled (+0x118),
 *     D3DDevice_SetViewport(dev, {(u32)x, (u32)y, (u32)w, (u32)h (floats at +0x108..+0x114), 0.0, 1.0}).
 *     ctx->rt = NULL.
 *  4. Same descriptor, different destination texture or slot (render to texture): the same resolve/delete
 *     steps, then ent = &render-texture table entry cmd->tex_index (0x44 B, layout below). Return without
 *     updating ctx->last if the entry has no texture. GetLevelDesc(tex, cmd->level); fmt =
 *     MapRTFormatToTextureFormat 0x886EB3E8(desc.Format). If fmt differs: remember the old format (+0x28);
 *     if the entry owns the texture (+0x10 == 0) wait for its fence (inlined XDK device accessor:
 *     VdGlobalXamDevice when KeGetCurrentProcessType()==2 else VdGlobalDevice; BlockOnFence 0x88292698(dev,
 *     fence, 5, 0)) and Release it, else keep it at +0x2C; then CreateTexture 0x8828AEA0(w, h, 1, 1, 0, fmt, 0,
 *     3) into +0x8, and mark the target for a resolve after binding.
 *     slot = cmd->slot unless -1 (then the entry's +0x14); rt = ent->rts[slot] (+0x34). If none, or for a
 *     non-zero level, allocate a 0xCC-byte RT (pool alloc ts4_node_dispatch_with_target_88613268 with the
 *     heap flags g->+0x15680, inlined constructor +0x84=0, +0x88=0, +0x90=1, +0x8C=-1, +0xC8=0), store it in
 *     the entry (level 0) or ctx->rt_level, set +0x8C = tex index, create surfaces 0x88750BF0(rt, w, h, slot,
 *     ent->format (+0x40) unless -1 else fmt, level).
 *     Viewport: camera view enabled -> rt->vp (+0x94, 6 words) = ctx->vp (+0x18); otherwise (for texture 0
 *     also rt->+0xB4 = ctx->+0x38) rt->vp = rt->default_vp (+0xAC).
 *     BeginTargetTiling 0x88756638(rt, flags >> 4); ResolveRT(rt, 0) if the texture was re-created;
 *     ctx->rt = rt.
 *  5. ctx->last = *cmd (unless step 4 returned early).
 * fn_equiv: see the PR1 report (work/equiv/pr1_88759BA0.json).
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef signed char s8;
typedef struct Pr1Viewport { u32 x, y, w, h; float min_z, max_z; } Pr1Viewport;
typedef struct Pr1SurfDesc { u32 format; u32 type; u32 usage; u32 pool; u32 ms; u32 msq; u32 width; u32 height; } Pr1SurfDesc;
/* pass-command block (render packet +0x70) */
typedef struct Pr1PassCmd {
    u8 flags;               /* +0 bit2 resolve+rebind, bit1 resolve secondary, bit3 clear, bits 4-7 clear/tiling flags */
    s8 slot;                /* +1 render-target slot of the texture entry, -1 = entry default */
    u8 level;               /* +2 texture level (0 = the entry's own RT) */
    u8 p3;
    int tex_index;          /* +4 destination render texture */
    int rt_index;           /* +8 render-target descriptor index, -1 = render to texture */
} Pr1PassCmd;
typedef struct Pr1RT { u8 p0[0x8c]; int tex_index; int p90; u8 p94[0xc8 - 0x94]; u32 pc8; } Pr1RT;
#define RT_VP(rt) ((Pr1Viewport *)((char *)(rt) + 0x94))
#define RT_VP_DEF(rt) ((Pr1Viewport *)((char *)(rt) + 0xac))
/* render-texture table entry, 0x44 bytes */
typedef struct Pr1RTex {
    u8 p0[8];
    void *tex;              /* +0x08 */
    u32 pc;
    u8 shared;              /* +0x10 texture not owned */
    u8 p11[3];
    int slot;               /* +0x14 default RT slot */
    u8 p18[0x10];
    u32 old_format;         /* +0x28 */
    void *old_tex;          /* +0x2C */
    u32 p30;
    Pr1RT *rts[3];          /* +0x34 */
    int format;             /* +0x40 forced RT format, -1 = from the texture */
} Pr1RTex;
typedef struct Pr1TexTab { u8 p0[0x24]; Pr1RTex *ent; } Pr1TexTab;
typedef struct Pr1PassCtx {
    u32 p0;
    Pr1PassCmd last;        /* +0x04 */
    Pr1RT *rt;              /* +0x10 current render target */
    Pr1RT *rt_level;        /* +0x14 temporary RT for a non-zero level */
    Pr1Viewport vp;         /* +0x18 */
    u8 p30[8];
    u32 p38;                /* +0x38 */
} Pr1PassCtx;
typedef struct Pr1CamView { u8 p0[0x108]; float x, y, w, h; u8 enabled; u8 p119[7]; } Pr1CamView;
extern char *lbl_88D45AD4;
extern void *lbl_88D45B38;
extern float lbl_8814B440;
extern float g_ts4_script_constants[];
extern char **__imp_VdGlobalDevice;
extern char **__imp_VdGlobalXamDevice;
extern int KeGetCurrentProcessType(void);
extern void ts4_if_call_seq_u32_off10_887567D8(Pr1PassCtx *ctx);
extern void fn_887563A8(Pr1RT *rt);
extern void fn_887533F8(Pr1RT *rt, u32 flags);
extern void fn_88756720(int rt_index);
extern void fn_887561A8(Pr1RT *rt, void *dest);
extern void fn_88750AD8(Pr1RT *rt);
extern void ts4_tsu_cleanup_end(void *p);
extern void fn_887534F0(int rt_index);
extern void fn_8828DF30(void *dev, const Pr1Viewport *vp);
extern void fn_88289D38(void *tex, u32 level, Pr1SurfDesc *desc);
extern int fn_886EB3E8(u32 format);
extern void fn_88292698(void *dev, u32 fence, u32 a, u32 b);
extern u32 ts4_if_atomic_interlocked_dec_88288530(void *res);
extern void *fn_8828AEA0(u32 w, u32 h, u32 levels, u32 usage, u32 a5, int format, u32 a7, u32 a8);
extern void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);
extern void fn_88750BF0(Pr1RT *rt, u32 w, u32 h, int slot, int format, u32 level);
extern void fn_88756638(Pr1RT *rt, u32 flags);
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
INL void pr1_drop_level_rt(Pr1PassCtx *ctx)
{
    if (*(int *)&ctx->rt_level != 0) {
        Pr1RT *o;
        fn_88750AD8(ctx->rt_level);
        o = ctx->rt_level;
        if (o != 0) {
            fn_88750AD8(o);
            ts4_tsu_cleanup_end(o);
        }
        ctx->rt_level = 0;
    }
}
INL Pr1CamView *pr1_cam_view(int i)
{
    return (Pr1CamView *)(*(char **)(*(char **)(lbl_88D45AD4 + 0x2c) + 0x24) + i * 0x120);
}
INL void *pr1_d3d_device(void)
{
    if (KeGetCurrentProcessType() == 2) return *__imp_VdGlobalXamDevice;
    return *__imp_VdGlobalDevice;
}
INL u32 pr1_heap_flags(void)
{
    char *g = lbl_88D45AD4;
    u32 r = 0;
    if (g != 0) r = *(u32 *)(g + 0x15680);
    return r;
}
INL int pr1_same_target(const Pr1PassCmd *a, const Pr1PassCmd *b)
{
    return *(const volatile int *)&b->tex_index == *(const volatile int *)&a->tex_index && *(const volatile u8 *)&a->slot == *(const u8 *)&b->slot;
}
void ts4_execute_pass_commands_88759BA0(Pr1PassCtx *ctx, Pr1PassCmd *cmd)
{
    char *g;
    void *dev;
    int cur;
    if ((cmd->flags & 4) == 4) ts4_if_call_seq_u32_off10_887567D8(ctx);
    if ((cmd->flags & 2) == 2) fn_887563A8(ctx->rt);
    if ((cmd->flags & 8) == 8) fn_887533F8(ctx->rt, cmd->flags >> 4);
    g = lbl_88D45AD4;
    dev = *(void **)(g + 0x15720);
    cur = ctx->last.rt_index;
    if (cmd->rt_index != cur && cmd->rt_index != -1) {
        int vi;
        if (cur != -1) fn_88756720(cur);
        if (ctx->last.tex_index != -1 && *(int *)&ctx->rt != 0) fn_887561A8(ctx->rt, 0);
        pr1_drop_level_rt(ctx);
        fn_887534F0(cmd->rt_index);
        vi = *(int *)(*(char **)(lbl_88D45AD4 + 0x1c) + 8);
        if (vi != -1) {
            Pr1CamView *v = pr1_cam_view(vi);
            if (v->enabled) {
                Pr1Viewport vp;
                vp.x = (u32)v->x;
                vp.y = (u32)v->y;
                vp.w = (u32)v->w;
                vp.h = (u32)v->h;
                vp.min_z = lbl_8814B440;
                vp.max_z = g_ts4_script_constants[0];
                fn_8828DF30(dev, &vp);
            }
        }
        ctx->rt = 0;
    } else if (!pr1_same_target(cmd, &ctx->last)) {
        Pr1RTex *ent;
        void *tex;
        int level;
        Pr1SurfDesc desc;
        int fmt;
        u32 w, h;
        u8 recreated;
        int slot;
        Pr1RT **prt;
        Pr1RT *rt;
        int vi;
        if (cur != -1) fn_88756720(cur);
        if (ctx->last.tex_index != -1 && *(int *)&ctx->rt != 0) fn_887561A8(ctx->rt, 0);
        pr1_drop_level_rt(ctx);
        ent = &(*(Pr1TexTab **)(g + 0x10))->ent[cmd->tex_index];
        tex = ent->tex;
        if (tex == 0) return;
        level = cmd->level;
        fn_88289D38(tex, level, &desc);
        fmt = fn_886EB3E8(desc.format);
        h = desc.height;
        w = desc.width;
        recreated = 0;
        if (fmt != (int)desc.format) {
            recreated = 1;
            ent->old_format = desc.format;
            if (ent->shared == 0) {
                /* inlined D3D: wait until the GPU is done with the texture, then release it */
                void *d = pr1_d3d_device();
                if (*(u32 *)((char *)tex + 8) != 0) fn_88292698(d, *(u32 *)((char *)tex + 8), 5, 0);
                ts4_if_atomic_interlocked_dec_88288530(tex);
            } else {
                ent->old_tex = tex;
            }
            ent->shared = 0;
            ent->tex = fn_8828AEA0(w, h, 1, 1, 0, fmt, 0, 3);
        }
        slot = ent->slot;
        if (cmd->slot != -1 && slot != cmd->slot) slot = cmd->slot;
        prt = &ent->rts[slot];
        rt = *prt;
        if (rt == 0 || level != 0) {
            int f = fmt;
            Pr1RT *o;
            if (ent->format != -1) f = ent->format;
            o = (Pr1RT *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0xcc, 4, pr1_heap_flags(), 2);
            if (o != 0) {
                *(volatile u32 *)((char *)o + 0x84) = 0;
                *(volatile u32 *)((char *)o + 0x88) = 0;
                *(volatile u32 *)((char *)o + 0x90) = 1;
                *(volatile int *)((char *)o + 0x8c) = -1;
                *(volatile u32 *)((char *)o + 0xc8) = 0;
            } else {
                o = 0;
            }
            rt = o;
            if (level == 0) *prt = rt;
            else ctx->rt_level = rt;
            rt->tex_index = cmd->tex_index;
            fn_88750BF0(rt, w, h, slot, f, level);
        }
        vi = *(int *)(*(char **)(lbl_88D45AD4 + 0x1c) + 8);
        if (vi != -1) {
            if (pr1_cam_view(vi)->enabled) {
                *RT_VP(rt) = ctx->vp;
            } else {
                if (cmd->tex_index == 0) *(u32 *)((char *)rt + 0xb4) = ctx->p38;
                *RT_VP(rt) = *RT_VP_DEF(rt);
            }
        }
        fn_88756638(rt, cmd->flags >> 4);
        if (recreated) fn_887561A8(rt, 0);
        ctx->rt = rt;
    }
    ctx->last = *cmd;
}
