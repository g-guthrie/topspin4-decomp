/*
 * GP2 (WP2) DRAFT: swing-selection debug HUD.
 *
 *   fn_886B0418 (0x78)   SwingModule debug-render slot (vtable 0x880F4478 +0x38)     MATCHED in gp2_swing_wrappers.c
 *   fn_886AC2C8 (0x4c4)  SwingBrain::DebugHud: the code that prints "InputNotation: %.2f",
 *                        "Selection Score: %.2f", "Ball Difficulty: %.2f", "Reachability: %.2f m.s-1"
 *
 * IMPORTANT: this is NOT where candidate scoring happens. It only (a) forces a recompute on request and
 * (b) formats the four values of one sample into a stack buffer (fn_885635D0 = sprintf). In the shipped
 * build the text is never drawn (no draw call follows the four sprintf calls; only dead vector stores of the
 * sample position remain), so the HUD has no gameplay effect except the forced recompute below.
 *
 * Debug switches (DebugConfig = PlayerCtx->world(+0x48)->debug(+0x28)):
 *   +0x48 master, +0x25 recompute reach, +0x1f recompute side flags(BD80), +0x22 eval default style,
 *   +0x1c/+0x1d/+0x1e draw debug lines (fn_886794D0 / fn_8866C830 / fn_8866C578),
 *   +0x24 print the sample values, +0x23 draw the committed sample, +0x18 float (0..1) = which sample to show,
 *   +0x14 style selector hash: "Steps" 0xf5e32576 -> PlayerTuning+0x208, "InsideOut" 0xbd8ea388 -> +0x1f8, else +0x218.
 */
#include "../gp2_types.h"

extern int fn_885635D0(char *buffer, const char *format, ...); /* sprintf */

struct Gp2HudDebugConfig {
    unsigned char pad0[0x14];
    unsigned int style_selector;       /* +0x14 */
    float sample_fraction;             /* +0x18 0..1: which candidate sample to display */
    unsigned char draw_lines_a;        /* +0x1c */
    unsigned char draw_lines_b;        /* +0x1d */
    unsigned char draw_lines_c;        /* +0x1e */
    unsigned char recompute_flags;     /* +0x1f */
    unsigned char pad20[2];
    unsigned char eval_default_style;  /* +0x22 */
    unsigned char draw_commit;         /* +0x23 */
    unsigned char print_values;        /* +0x24 */
    unsigned char recompute_reach;     /* +0x25 */
    unsigned char pad26[0x48 - 0x26];
    unsigned char master;              /* +0x48 */
};

void gp2_swing_brain_debug_hud(
    struct Gp2HudDebugConfig *dbg,
    int player_index_must_be_zero,               /* PlayerCtx+0x14 == 0: only the first player */
    struct Gp2ReachRecord records[2],            /* brain+0x118 -> 2 x 0x34 */
    struct Gp2CandidateSet sets[2],              /* brain+0x2c  -> 2 x 0x60 */
    float *ball_difficulty                       /* BallPrediction owner +0x7c, 8 bytes per sample */
)
{
    char text[0x40];
    int total = 0, shown, i, w;
    int use_second = 0;                          /* PlayerState+0xbc8 != -1 ? PlayerState+0xbd1 : records[0].valid */
    struct Gp2ReachRecord *rec = use_second ? &records[0] : &records[1];

    if (!dbg->master || player_index_must_be_zero != 0) return;
    /* ... optional force-recompute: sets[0].dirty = sets[1].dirty = 1 (read back by fn_886A39A8) when the
       world+0x1c->0xc0 byte is set; recompute_reach -> fn_8869B128; recompute_flags -> fn_8868BD80;
       eval_default_style -> fn_886A9628; draw_lines_* -> the three debug-line drivers ... */

    /* number of samples over all windows, then pick one by the debug fraction */
    for (w = 0; w < rec->windows.count; w++) {
        struct Gp2ReachWindow *win = (struct Gp2ReachWindow *)((char *)&rec->windows + rec->windows.offset) + w;
        total += win->end - win->start + 1;
    }
    shown = (int)((float)total * dbg->sample_fraction);
    if (shown > total - 1) shown = total - 1;
    for (w = 0, i = 0; w < rec->windows.count; w++) {
        struct Gp2ReachWindow *win = (struct Gp2ReachWindow *)((char *)&rec->windows + rec->windows.offset) + w;
        int s;
        for (s = win->start; s <= win->end; s++, i++) {
            if (i != shown) continue;
            fn_885635D0(text, "InputNotation: %.2f",
                        (double)((float *)((char *)&rec->input_notation + rec->input_notation.offset))[s]);
            fn_885635D0(text, "Selection Score: %.2f",
                        (double)((float *)((char *)&rec->selection_score + rec->selection_score.offset))[s]);
            fn_885635D0(text, "Ball Difficulty: %.2f", (double)ball_difficulty[s * 2]);
            fn_885635D0(text, "Reachability: %.2f m.s-1",
                        (double)((float *)((char *)&sets[use_second ? 0 : 1].reach_speed
                                           + sets[use_second ? 0 : 1].reach_speed.offset))[s]);
            return;
        }
    }
}
