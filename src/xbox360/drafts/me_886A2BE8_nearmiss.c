/* 0x886A2BE8 near miss (91 off, /Oc plain C; first draft, 6 variants). AI brain: if the current spot is fresh
 * (<10 ticks), not locked, and (when check_angle) the heading is wide and facing_x > k[67], reruns the selection scorer
 * with its flags cleared; on a new spot index stores it (+ side, aim vector) and returns 1, else restores flags and
 * returns 0. Residue: r28/r29 swap (zero vs body), one reloc short (target 10 vs 9), sign-bit test lacks clrlwi,
 * tail block layout (size 0x218 vs 0x204). */
typedef unsigned int u32; typedef unsigned char u8; typedef unsigned short u16;
double fabs(double);
#pragma intrinsic(fabs)
typedef struct { float v[4]; } __declspec(align(16)) Vec4;
extern const float lbl_880C88DC;
extern const float g_ts4_script_constants[];
struct Gp2SelectionScorer;
void fn_8817B608(float *angle);
void ts4_selection_scorer_run_8869AEF8(struct Gp2SelectionScorer *scorer, int has_commit, void *style);
void fn_8865DBA8(struct Gp2SelectionScorer *scorer, int *best_index, unsigned char *best_side, int exclude_volley, int only_volley);
typedef struct Spot { char _0[0x24]; int tick; char _28[8]; } Spot;
typedef struct Court { char _0[0x5A0]; Spot *spots; } Court;
typedef struct Mt { char _0[0x24]; Court *court; } Mt;
typedef struct Clock { char _0[0x310]; int tick; } Clock;
typedef struct Arena { char _0[0x30]; Clock *clock; char _34[0x28]; Mt *mt; } Arena;
typedef struct Opp { char _0[0xB0]; int style; } Opp;
typedef struct OppH { char _0[0x24]; Opp *opp; } OppH;
typedef struct Body { char _0[0x440]; float facing_x, heading; char _448[0x18E]; u8 b5da; char _5db[0x305];
    Vec4 aim; char _8f0[0x2D8]; int spot; char _bcc[5]; u8 side; } Body;
typedef struct Lock { char _0[0x14]; u8 locked; } Lock;
typedef struct Styles { char _0[0x228]; char style[4]; } Styles;
typedef struct World { char _0[0x10]; u8 check_angle; char _11[0x1B]; Styles *styles; char _30[8]; u8 b38; char _39[0xF];
    Arena *arena; OppH *opp; char _50[0x24]; Body *body; char _78[0xC]; Lock *lock; } World;
typedef struct Flags2 { u8 b0; char _1[0x5F]; u8 b60; } Flags2;
typedef struct Brain { char _0[0x24]; void *style; char _28[4]; Flags2 *flags; char _30[8]; char scorer[0x11C]; World *world; char _158[0x118];
    Vec4 aim; } Brain;
u8 ts4_brain_try_reselect_spot_886A2BE8(Brain *self)
{
    World *w = self->world;
    Body *b = w->body;
    int age = w->arena->mt->court->spots[b->spot].tick - w->arena->clock->tick;
    u8 ok = 1;
    if (w->check_angle) {
        float h = b->heading, d;
        u8 wide;
        int neg;
        if (w->opp->opp->style == (int)0xA2EDA1E7) {
            float t = lbl_880C88DC + h;
            fn_8817B608(&t);
            h = t;
        }
        d = g_ts4_script_constants[67] - b->facing_x;
        wide = (float)fabs(h) > g_ts4_script_constants[170];
        neg = *(u16 *)&d >> 15;
        ok = (u8)neg && wide;
    }
    if (!w->lock->locked && age < 10 && ok) {
        u8 saved_w = w->b38, saved0, saved60;
        struct Gp2SelectionScorer *sc = (struct Gp2SelectionScorer *)self->scorer;
        int idx;
        u8 side;
        w->b38 = 0;
        saved0 = self->flags->b0;
        saved60 = self->flags->b60;
        self->flags->b0 = 0;
        self->flags->b60 = 0;
        idx = -1;
        side = 0;
        ts4_selection_scorer_run_8869AEF8(sc, 0, self->world->styles->style);
        fn_8865DBA8(sc, &idx, &side, 1, 0);
        if (idx != -1) {
            self->style = self->world->styles->style;
            self->world->body->spot = idx;
            self->world->body->side = side;
            self->world->body->b5da = 0;
            self->aim = self->world->body->aim;
            return 1;
        }
        self->world->b38 = saved_w;
        self->flags->b0 = saved0;
        self->flags->b60 = saved60;
    }
    return 0;
}
