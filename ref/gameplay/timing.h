/* Groundstroke timing value (fn_8867DF68) and the shared curve evaluator (fn_881899D8).
 * See docs/gameplay/timing-and-fatigue.md s1. Read from code; curve values from Settings.bin. */
#ifndef TS4_TIMING_H
#define TS4_TIMING_H

typedef struct { float in_start, in_stop, out_start, out_stop; } Ts4Range;

/* fn_881899D8: last range with in_start <= x (else the first), clamped ramp. */
float ts4_range_curve(const Ts4Range *r, int n, float x);

/* fn_8867DF68: frames = frames from now until the ball reaches the player's contact depth
 * (TimingBaseFrame S+0xD04); ability = TimingAbility S+0xD0C. has_prediction = 0 gives -1. */
float ts4_timing_value(const Ts4Range *worst, int nw, const Ts4Range *best, int nb,
                       int has_prediction, float frames, float ability);

/* Shipped baseline curve (SwingTimingSelectionList/Baseline/5ae85f27/848c2a13, file 0x2B420). */
extern const Ts4Range ts4_timing_baseline[6];
extern const Ts4Range ts4_timing_volley[6];

#endif
