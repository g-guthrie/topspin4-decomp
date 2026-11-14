/* Vigor model: fn_886902E8 (init), fn_88690540 (per frame), fn_8866EE48 (point end).
 * See docs/gameplay/timing-and-fatigue.md s2. Read from code. The FatigueIngame and
 * FatigueConst graph outputs (cost, capacity, recovery rate, ...) are inputs here. */
#ifndef TS4_FATIGUE_H
#define TS4_FATIGUE_H

typedef struct {
    float sum_acceleration;  /* S+0xF20 */
    float sum_powerful;      /* S+0xF24 */
    float anim_cost;         /* S+0xF28 #080853e1 */
    float carried;           /* S+0xF2C #908acc60 */
    float cost;              /* S+0xF44 #3122036a (FatigueIngame output) */
    float total;             /* S+0xF48 #2c8fcdcc */
    float recovery_rate;     /* S+0xF50 #09ff7c93 */
    float vigor;             /* S+0xF54 CurrentVigor */
    float recovery;          /* S+0xF58 CurrentRecovery */
    float recovery_scale;    /* S+0xF5C #a50ecfff */
    float capacity;          /* S+0xF60 #b2f052bb */
    float vigor_max;         /* S+0xF64 VigorMax */
} Ts4Fatigue;

void ts4_fatigue_init(Ts4Fatigue *f);
/* accel = |second difference of look-ahead positions| in raw units; scaled by 0.1 * 0.001. */
void ts4_fatigue_add_acceleration(Ts4Fatigue *f, float accel);
/* After FatigueIngame has written f->cost. */
void ts4_fatigue_update_vigor(Ts4Fatigue *f);
/* bonus: controller +0x34 / +0x30 (or 0); rest: /Fatigue multiplier (1, 2 or 3; 0 means 1). */
void ts4_fatigue_point_end(Ts4Fatigue *f, float bonus, float rest);

#endif
