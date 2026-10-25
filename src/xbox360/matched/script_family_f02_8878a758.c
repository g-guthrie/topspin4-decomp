/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Functions in this file compile to exact objdiff matches with the Xbox 360
 * compiler (see docs/matching-build.md). They were written from the disassembly
 * of the retail module with AI assistance; names, types and field roles are
 * reconstructions, and each function states its address range.
 */
#include "script_argument_helpers.h"

typedef struct {
    float x, y, z;
} ts4_float3;

extern void *lbl_88D45954;
void fn_888D9498(void *object, ts4_float3 first, ts4_float3 second);

static ts4_float3 ts4_float3_make(float x, float y, float z)
{
    ts4_float3 value;
    value.x = x;
    value.y = y;
    value.z = z;
    return value;
}

/* Registered as InitFreeFormCamera. 0x8878A758-0x8878A9C8. A2(0..5) N F, call(G, Q, Q), R=0. */
ts4_u32 ts4_script_init_free_form_camera(struct TS4ScriptContext *context)
{
    ts4_float3 first;
    ts4_float3 second;
    float a = (float)ts4_script_number(ts4_script_argument(context, 0));
    float b = (float)ts4_script_number(ts4_script_argument(context, 1));
    float c = (float)ts4_script_number(ts4_script_argument(context, 2));
    float d = (float)ts4_script_number(ts4_script_argument(context, 3));
    float e = (float)ts4_script_number(ts4_script_argument(context, 4));
    float f = (float)ts4_script_number(ts4_script_argument(context, 5));
    first = ts4_float3_make(a, b, c);
    second = ts4_float3_make(d, e, f);
    fn_888D9498(lbl_88D45954, first, second);
    return 0;
}
