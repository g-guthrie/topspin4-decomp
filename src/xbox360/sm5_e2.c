/* SM5: hand-matched small functions (Swing_DLL.xex 0x88700000-0x88B00000). */
#include "script_context.h"

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern const char g_ts4_true_string[];
ts4_script_u8 ts4_script_string_equals(void *value, const char *text);
extern void *lbl_88D4587C;

struct TS4F72 { ts4_script_u8 pad[0x72]; ts4_script_u8 a; ts4_script_u8 b; };
/* Swing_DLL.xex 0x8877BAF0 */
ts4_script_u32 ts4_script_set_two_flags_8877BAF0(struct TS4ScriptContext *context) { struct TS4ScriptValue *value; struct TS4F72 *state; ts4_script_u8 flag; if (context->arguments->count > 0) value = context->arguments->first_value; else value = g_ts4_default_script_value; flag = ts4_script_string_equals(value->payload, g_ts4_true_string); state = lbl_88D4587C; if (state) { state->b = flag; state->a = flag; } return 0; }
