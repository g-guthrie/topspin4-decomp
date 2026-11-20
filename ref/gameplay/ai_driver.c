/* Reference for the opponent input path.  There is no separate AI driver in
 * the game: the same candidate pipeline runs with the human flag cleared
 * (see docs/gameplay/movement-and-ai.md section B). */
#include "movement.h"

/* fn_8865DBA8.  Candidates are scanned in order; strict '>' keeps the first
 * best.  `floor_value` is the pool constant the running best starts from. */
int ai_argmax(const struct ai_candidate *c, int n, int a4, int a5,
              float floor_value)
{
    int best = -1, i;
    float best_score = floor_value;
    for (i = 0; i < n; i++) {
        int non_volley = !c[i].is_volley;
        int accept;
        if (a4 == 0)
            accept = (a5 == 0) ? 1 : c[i].is_volley;
        else
            accept = (a5 == 0) ? non_volley : 1;
        if (accept && c[i].score > best_score) {
            best_score = c[i].score;
            best = i;
        }
    }
    return best;
}

/* fn_88689508: per candidate scoring.  Inputs go to a data-driven graph
 * (fn_8890E988).  Humans additionally feed InputNotation; AI feeds nothing
 * for it.  Required speed above max_speed (50 m/s) yields -1 without
 * running the graph (documented in GP2). */
void ai_score_all(struct ai_candidate *c, int n, int human, float max_speed,
                  ai_score_fn fn, void *user)
{
    int i;
    for (i = 0; i < n; i++) {
        if (!human)
            c[i].input_notation = 0.0f;
        if (c[i].reach_speed > max_speed)
            c[i].score = -1.0f;
        else
            c[i].score = fn(&c[i], human, user);
    }
}

/* fn_8869C010: for non-human players the raw stick used by aiming is zero. */
struct ai_stick ai_effective_stick(int human, struct ai_stick raw)
{
    struct ai_stick z = {0.0f, 0.0f};
    return human ? raw : z;
}

/* fn_886884E8: heading = -atan2(...) of the target, intensity fixed to 1. */
struct ai_polar ai_move_command(float heading_to_target)
{
    struct ai_polar p;
    p.heading = -heading_to_target;
    p.intensity = 1.0f;
    return p;
}

/* fn_886A3DF0 (aim state update), structure only. */
enum ai_aim_mode ai_choose_aim(int stick_aim_enabled, int out_of_range,
                               int in_reach)
{
    if (!stick_aim_enabled)
        return AI_AIM_NEUTRAL;
    if (out_of_range || !in_reach)
        return AI_AIM_AUTO;
    return AI_AIM_NEUTRAL;
}
