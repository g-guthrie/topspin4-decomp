/* Swing_DLL.xex 0x8899F838: countdown check: elapsed = (now - start)/1000; within the limit it optionally writes the minutes/seconds left to the state+0x858 clock and returns 0; past it, clears start and the clock and returns 1 (also 1 when not started).
 * /Oc. The clock stores go through a ClockDisplay pointer, which keeps the state reload in r11. */
typedef struct ClockDisplay { unsigned int minutes; unsigned int seconds; } ClockDisplay;
typedef struct SessionState { char pad[0x858]; ClockDisplay clock; } SessionState;
typedef struct SessionContext { char pad[0x3c]; SessionState *state; } SessionContext;
typedef struct Timer { char pad[0x9c]; unsigned int startMs; } Timer;
extern SessionContext *g_ts4_session_context;
unsigned int ts4_get_u32__imp_KeTimeStampBundle_8857B830(void);

int fn_8899F838(Timer *t, unsigned int limitSeconds, unsigned char show)
{
    ClockDisplay *clock;
    if (t->startMs) {
        unsigned int elapsed = (ts4_get_u32__imp_KeTimeStampBundle_8857B830() - t->startMs) / 1000;
        if (limitSeconds >= elapsed) {
            if (show) {
                unsigned int left = limitSeconds - elapsed;
                clock = &g_ts4_session_context->state->clock;
                clock->minutes = left / 60;
                clock->seconds = left % 60;
            }
            return 0;
        }
        t->startMs = 0;
        clock = &g_ts4_session_context->state->clock;
        clock->minutes = 0;
        clock->seconds = 0;
    }
    return 1;
}
