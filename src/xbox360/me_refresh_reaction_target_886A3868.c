/* 0x886A3868: after running the reaction analysers, starts (or keeps) a pending-reaction timer when
 * the reaction strength exceeds the script threshold and enough frames have passed since the opponent's
 * last hit, and while the timer is within its window refreshes the target: a new target from the
 * planner (or one that has dropped below the script floor) is committed. The reaction state is updated last in every case. */
typedef struct Target { float x; float y; } Target;
typedef struct Tune { char p[0x9d0]; Target candidate; char p1[0x9e8 - 0x9d8]; Target committed;
    char p2[0xdf4 - 0x9f0]; float max_wait; float min_gap; } Tune;
typedef struct Clock { char p[0x310]; int frame; } Clock;
typedef struct Match { char p[0x30]; Clock *clock; } Match;
typedef struct LastHit { char p[0x68]; int frame; } LastHit;
typedef struct Opp { char p[0x24]; LastHit *hit; } Opp;
typedef struct Player { char p[0x48]; Match *match; Opp *opp; char p2[0x64 - 0x50]; void *planner; char p3[0x74 - 0x68]; Tune *tune; } Player;
typedef struct React { char p[0x154]; Player *player; char p2[0x1e0 - 0x158]; char analysers[0x2a0 - 0x1e0]; int start_frame; } React;
extern float g_ts4_script_constants[];
void ts4_loop_call_seq_u32_off2c_8890E988(void *analysers);
unsigned char fn_88691298(void *planner, Target *cand, Target *committed);
void fn_886A37D0(React *r);
void ts4_refresh_reaction_target_886A3868(React *r)
{
    const float *k;
    Player *p;
    Tune *t;
    Target *cand, *committed;
    unsigned char ok;
    ts4_loop_call_seq_u32_off2c_8890E988(r->analysers);
    k = g_ts4_script_constants;
    p = r->player;
    t = p->tune;
    cand = &t->candidate;
    committed = &t->committed;
    if (cand->y > k[67] && r->start_frame < 0) {
        int now = p->match->clock->frame;
        if ((float)(now - p->opp->hit->frame) < t->min_gap) r->start_frame = now;
    }
    ok = r->start_frame > -1 && !((float)(p->match->clock->frame - r->start_frame) > p->tune->max_wait);
    if (ok) {
        unsigned char planned = fn_88691298(p->planner, cand, committed);
        unsigned char low = cand->y < k[171];
        if (planned || low) {
            *committed = *cand;
        }
    }
    fn_886A37D0(r);
}
