/*
 * Ts4Tracker::Reset (886CBC30). Class: include/ts4/classes.h, notes: docs/agents/classes.md.
 * The zero is the literal 0.0f (pooled at 0x8814B440); a named extern float would be reloaded after every
 * float store. scale = 1.0f comes from g_ts4_script_constants[0] (the pool slot at +0xF70 is that table).
 * The ctor 886CC058 (vptrs, a(), b(), f_30 = 0, inlined Reset) is still 6 off: see
 * drafts/q5s_swan_886cc058_nearmiss.c.
 */
#include "include/ts4/ts4.h"
#include "include/ts4/classes.h"

extern "C" const float g_ts4_script_constants[];

void Ts4Tracker::Reset()
{
    f_34 = 0;
    f_04 = 0;
    scale = g_ts4_script_constants[0];
    f_38 = 0.0f;
    f_40 = 0.0f;
    f_0c = 0.0f;
    f_10 = 0.0f;
    f_14 = 0.0f;
    f_18 = 0.0f;
    a.Clear();
    f_6c = 0;
    f_1c = 0.0f;
    f_74 = 0;
    f_20 = 0.0f;
    f_78 = 0;
    f_24 = 0.0f;
    f_7c = 0;
    f_28 = 0.0f;
    f_80 = 0;
    f_2c = 0.0f;
    f_70 = 0.0f;
}
