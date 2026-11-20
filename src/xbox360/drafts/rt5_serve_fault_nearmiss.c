/*
 * DRAFT (not part of the matching build). RT5: serve fault path, point-winner decision (Swing_DLL.xex 0x8865C308, 0xB4).
 * docs/gameplay/rules-and-scoring.md section 4.7. Behaviour is exact (checked by reading the disassembly); NOT byte matched:
 * plain /Oc and LTCG routes both leave 41 of 45 instructions off, because the original builds `reason - 0x79EE9B03` as
 * subis/addi (an add form) and keeps ctx loaded first with the constants hoisted ahead of the loads. 70+ flag-order / result-
 * variable / u8-bool variants tried (permutations of the three flags, four return shapes, flags before and after the load).
 */
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

struct Rt5Rally { u8 pad[0x7C]; s32 last_hitter; };               /* B30: +0x7C last hitter index */
struct Rt5Match { u8 pad[0x64]; s32 withdraw_loser; };            /* +0x64: player that withdrew */
struct Rt5Ctx { u8 pad0[0x30]; struct Rt5Rally *rally; u8 pad1[0x44 - 0x34]; struct Rt5Match *match; };
struct Rt5Scoring { void *vtbl; struct Rt5Ctx *ctx; };

/* Scoring_GetPointWinner: winner index for a point-end reason (-1 = nobody, e.g. Let). Swing_DLL.xex 0x8865C308 */
s32 ts4_scoring_get_point_winner_8865C308(struct Rt5Scoring *self, const u32 *reason)
{
    struct Rt5Ctx *ctx = self->ctx;
    u32 r = *reason;
    u8 is_miss = r == 0xC222A5E0u;
    u8 is_let = r == 0xC9238771u;
    u8 is_other = r + 0x861164FDu == 0;
    s32 last = ctx->rally->last_hitter;
    if (r == 0x3C1D5115u)
        last = 1 - last;
    if (r == 0x22703895u)
        return 1 - ctx->match->withdraw_loser;
    if (is_let)
        return -1;
    if (is_miss || is_other)
        return 1 - last;
    return last;
}
