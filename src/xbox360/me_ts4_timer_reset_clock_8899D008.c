/* Swing_DLL.xex 0x8899D008: stop the countdown: clear start (+0x9c) and the state+0x858 minutes/seconds clock.
 * /Oc. Same ClockDisplay pointer form as 8899F838. */
typedef struct ClockDisplay { unsigned int minutes; unsigned int seconds; } ClockDisplay;
typedef struct SessionState { char pad[0x858]; ClockDisplay clock; } SessionState;
typedef struct SessionContext { char pad[0x3c]; SessionState *state; } SessionContext;
typedef struct Timer { char pad[0x9c]; unsigned int startMs; } Timer;
extern SessionContext *g_ts4_session_context;

void fn_8899D008(Timer *t)
{
    ClockDisplay *clock;
    t->startMs = 0;
    clock = &g_ts4_session_context->state->clock;
    clock->minutes = 0;
    clock->seconds = 0;
}
