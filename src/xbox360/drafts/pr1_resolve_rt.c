/*
 * DRAFT (not part of the matching build). PR1, wave PR1.
 * 0x887561A8 ResolveRT (0x200 B), names from docs/renderer-map.md section 1.3.
 *
 * Status: 2 instructions differ (plain route, no flags; the LTCG route gives the same 2). In the non-tiled
 * branch the target materialises the NULL destPoint (`li r7,0`) after the two stack stores of the 9th/10th
 * Resolve arguments; this candidate puts it between them. Everything else, including the VMX copy of the
 * clear colour and the hoisted Z constants, is byte-exact. Tried: NULL through a typed cast or a local,
 * a forceinline Resolve wrapper for one or both calls, Z through a local, swapping the branches, LTCG.
 *
 * What it does: resolve render target `rt` (a render-target descriptor, section 4.2) into `dest`.
 *  - g_Display = *(char **)0x88D45AD4. First clears byte +0xA of *(g+0x20) (a per-frame flag block).
 *  - dest == NULL: use the target's own render texture, g->tbl(+0x10)->ent(+0x24)[rt->tex_index(+0x8C)].tex
 *    (+8), when tex_index != -1. If there is still no destination, return.
 *  - dev = *(g+0x15720). D3DTexture_GetLevelDesc(dest, 0, &desc) (0x88289D38).
 *  - Resolve parameters (3 words on the stack): {desc.Format, 0, depth format}, depth format 0x1A220197
 *    (D24FS8-like float depth) when rt->inverted_depth (+0xC4) else 0x2D200196 (D24S8).
 *  - clear colour = the 16-byte constant at 0x880FC650 (copied with lvx128/stvx128); ClearZ = 0.0f
 *    (0x8814B440) when inverted depth, else 1.0f (g_ts4_script_constants[0]); ClearStencil = 0.
 *  - Tiled (rt->tiles, +0x80, != 0): for each tile i: SetPredication-like 0x8829B288(dev, 3 << 2i);
 *    Resolve(dev, 0, &rt->tile[i] (16-byte rects at +0), dest, &{tile.x1, tile.y1}, rt->+0xC8, ...).
 *    Then 0x8829B288(dev, 0) and EndTiling-like 0x8829B748(dev).
 *  - Not tiled: SetRenderTarget(dev, 0, rt->+0x84) (0x8828E1B0), SetDepthStencilSurface(dev, rt->+0x88)
 *    (0x8828E500), then one Resolve(dev, 0, NULL, dest, NULL, rt->+0xC8, ...).
 *  - D3DDevice_Resolve is 0x88294450; its 6th argument is rt->+0xC8 (the map reads it as the stencil clear;
 *    by argument position it is the XDK's DestLevel/slice slot, so treat the name as open).
 * fn_equiv: UNCHECKED (VMX128 clear-colour copy).
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Pr1Rect { int x1, y1, x2, y2; } Pr1Rect;
typedef struct Pr1Point { int x, y; } Pr1Point;
#include "../ts4_vector.h"
typedef __vector4 Pr1Vec4;
typedef struct Pr1SurfDesc { u32 format; u32 type; u32 usage; u32 pool; u32 ms; u32 msq; u32 width; u32 height; } Pr1SurfDesc;
typedef struct Pr1ResolveParams { u32 color_format; u32 zero; u32 depth_format; } Pr1ResolveParams;
typedef struct Pr1RT {
    Pr1Rect tile[8];        /* +0x00 predicated-tiling rectangles */
    u32 tiles;              /* +0x80 tile count (0 = no tiling) */
    void *color_surface;    /* +0x84 */
    void *depth_surface;    /* +0x88 */
    int tex_index;          /* +0x8C render-texture table index, -1 = none */
    u8 p90[0xC4 - 0x90];
    u8 inverted_depth;      /* +0xC4 */
    u8 pc5[3];
    u32 resolve_c8;         /* +0xC8 */
} Pr1RT;
typedef struct Pr1RTex { u8 p0[8]; void *tex; u8 p1[0x38]; } Pr1RTex;
typedef struct Pr1TexTab { u8 p0[0x24]; Pr1RTex *ent; } Pr1TexTab;
extern char *lbl_88D45AD4;
extern Pr1Vec4 lbl_880FC650;
extern float lbl_8814B440;
extern float g_ts4_script_constants[];
extern void fn_88289D38(void *tex, u32 level, Pr1SurfDesc *desc);
extern void fn_8829B288(void *dev, u32 mask);
extern void fn_8829B748(void *dev);
extern void fn_8828E1B0(void *dev, u32 index, void *surf);
extern void fn_8828E500(void *dev, void *surf);
extern void fn_88294450(void *dev, u32 flags, const Pr1Rect *rect, void *dest, const Pr1Point *pt, u32 a6,
                        const Pr1Vec4 *color, float z, u32 stencil, const Pr1ResolveParams *params);
void ts4_resolve_rt_887561A8(Pr1RT *rt, void *dest)
{
    char *g = lbl_88D45AD4;
    void *dev;
    Pr1SurfDesc desc;
    Pr1Vec4 color;
    Pr1ResolveParams prm;
    *(u8 *)(*(char **)(g + 0x20) + 0xa) = 0;
    if (rt->tex_index != -1 && dest == 0)
        dest = (*(Pr1TexTab **)(g + 0x10))->ent[rt->tex_index].tex;
    if (dest == 0) return;
    dev = *(void **)(g + 0x15720);
    fn_88289D38(dest, 0, &desc);
    prm.zero = 0;
    prm.color_format = desc.format;
    color = lbl_880FC650;
    prm.depth_format = rt->inverted_depth ? 0x1A220197u : 0x2D200196u;
    if (rt->tiles != 0) {
        u32 i = 0;
        u32 sh = 0;
        Pr1Rect *r = rt->tile;
        float z0 = lbl_8814B440;
        float z1 = g_ts4_script_constants[0];
        do {
            Pr1Point pt;
            fn_8829B288(dev, 3u << sh);
            pt.x = r->x1;
            pt.y = r->y1;
            fn_88294450(dev, 0, r, dest, &pt, rt->resolve_c8, &color, rt->inverted_depth ? z0 : z1, 0, &prm);
            i++;
            sh += 2;
            r++;
        } while (i < rt->tiles);
        fn_8829B288(dev, 0);
        fn_8829B748(dev);
    } else {
        fn_8828E1B0(dev, 0, rt->color_surface);
        fn_8828E500(dev, rt->depth_surface);
        fn_88294450(dev, 0, 0, dest, 0, rt->resolve_c8, &color,
                    rt->inverted_depth ? lbl_8814B440 : g_ts4_script_constants[0], 0, &prm);
    }
}
