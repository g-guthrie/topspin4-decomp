/* near-miss: 18 off, size 0x54 vs 0x5c (target loads owner->target twice with a dead mr copy, srwi sign test) */
/* ME: arm a timer flag when a tuned value is at or above 0.1 (pick.py throughput). Swing_DLL.xex 0x8865E430 */
extern float g_ts4_script_constants[];
#define TS4_ONE (g_ts4_script_constants[0])            /* 1.0f */
#define TS4_EASE (g_ts4_script_constants[0x2AC / 4])   /* 0.1f */

struct Ts4TimerTarget {
    unsigned char pad_000[0x4DD];
    unsigned char enabled;           /* +0x4DD */
    unsigned char pad_4de[0xA10 - 0x4DE];
    float timer;                     /* +0xA10 */
    unsigned char pad_a14[0xA2C - 0xA14];
    unsigned char armed;             /* +0xA2C */
    unsigned char pad_a2d[0xF54 - 0xA2D];
    float level;                     /* +0xF54 */
};
struct Ts4TimerOwner { unsigned char pad_00[0x74]; struct Ts4TimerTarget *target; /* +0x74 */ };
struct Ts4TimerSelf { unsigned char pad_00[0x1C]; struct Ts4TimerOwner *owner; /* +0x1C */ };

static int ts4_sign_bit(float f) { return *(unsigned short *)&f >> 15; }

void ts4_arm_level_timer_8865E430(struct Ts4TimerSelf *self)
{
    struct Ts4TimerTarget *t = self->owner->target;
    float d = t->level - TS4_EASE;
    unsigned char armed;
    if (self->owner->target->enabled && !ts4_sign_bit(d))
        armed = 1;
    else
        armed = 0;
    t->armed = armed;
    t->timer = TS4_ONE;
}
