/* Swing_DLL.xex 0x8865F618: fixed-step runner. While *running, steps the two sub-objects (vtable slot 2) each
 * iteration, flags every period-th step in *out, throttles to 1/60 s of the performance counter when the period
 * is 1, and stops once the current game record's byte +0x5C is set. Otherwise runs min(*pending, *period) queued
 * steps and subtracts them from *pending. LTCG route (the 1/60 double sits in the module pool), /Oc for the divw. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned long long u64;
typedef struct IStep { void **vt; } IStep;
typedef struct Rec { char p0[0x5c]; u8 b5c; char p5d[0xc4 - 0x5d]; } Rec;
typedef struct Game {
    char p0[0x1c]; int f1c; char p20[0x10]; int *f30; int f34; char p38[4]; Rec *recs;
} Game;
typedef struct World { char p0[0x234]; Game *game; } World;
typedef struct Stepper {
    char p0[0x1c];
    IStep *a;
    IStep *b;
    char p24[4];
    u64 last;
    int *pending;
    u8 *running;
    int *period;
    u8 *out;
} Stepper;
extern World *lbl_88D45B1C;
extern void fn_8857B010(u64 *f);
extern void fn_8857AFF0(u64 *t);
static __inline void step(IStep *o) { ((void (*)(IStep *))o->vt[2])(o); }
void ts4_step_runner_update_8865F618(Stepper *s)
{
    if (*s->running) {
        int i = 0;
        double k = 0.016666666666666666;
        for (;;) {
            u8 skip = (i % *s->period) != 0;
            Game *g;
            u64 freq;
            step(s->a);
            *s->out = skip;
            step(s->b);
            fn_8857B010(&freq);
            if (*s->period == 1) {
                u64 wait = (long long)((double)freq * k);
                u64 now;
                do {
                    fn_8857AFF0(&now);
                } while (now - s->last < wait);
                s->last = now;
            }
            i++;
            g = lbl_88D45B1C->game;
            if (g) {
                int idx;
                Rec *r;
                if (g->f34 > 0 && *g->f30 != -1)
                    idx = *g->f30;
                else
                    idx = g->f1c;
                r = &g->recs[idx];
                if (r && r->b5c) {
                    *s->running = 0;
                    return;
                }
            }
        }
    } else {
        int n = *s->pending;
        if (n > 0) {
            int m = (n >= *s->period) ? *s->period : n;
            if (m > 0) {
                int c;
                *s->out = 1;
                c = m - 1;
                if (c > 0) {
                    do {
                        step(s->a);
                        step(s->b);
                    } while (--c != 0);
                }
                step(s->a);
                *s->out = 0;
                step(s->b);
                *s->pending -= m;
            }
        } else {
            *s->out = 0;
            step(s->a);
            step(s->b);
        }
    }
}
