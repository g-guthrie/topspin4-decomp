/* SM5: hand-matched small functions (Swing_DLL.xex 0x88700000-0x88B00000). */
#include "script_context.h"

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern void *g_ts4_session_context;
extern void *g_ts4_session_state;
extern void *lbl_88D45954, *lbl_88D45878, *lbl_88D4593C, *lbl_88D45A64, *lbl_88D459DC, *lbl_88D45A04;
extern void *lbl_88D45B0C, *lbl_88D459E0, *lbl_88D45A60, *lbl_88D45960, *lbl_88D41FC4, *lbl_88D45B1C;
extern void *g_ts4_online_context;
extern void fn_88931FE0(void *, ts4_script_u32 *);
extern ts4_script_u8 fn_88865388(void *, int, int, ts4_script_u8 *);
extern ts4_script_u32 fn_887EA5C8(void *, int);
extern void ts4_if_get_u32_off1c_886570B8(void *, ts4_script_u32);
extern void fn_888D0838(void *, ts4_script_u32);
extern void fn_889A5200(void *, int, int, int);
extern void fn_88855170(void *, int, int, int, int, int);
extern void fn_882107D0(void *, ts4_script_u32 *, int);
extern void fn_888C7C28(void *, ts4_script_u32 *);
extern ts4_script_u32 fn_8899CA48(void *, ts4_script_u32 *);
extern void *ts4_member_field_addr_8883B578(void *, int);
extern void fn_88853540(void *, int, int);

/* Evaluate the first script argument as a double (default constant 11 when not numeric). */
#define TS4_SCRIPT_NUM(context, number) \
    if ((context)->arguments->count > 0) { \
        value = (context)->arguments->first_value; \
    } else { \
        value = g_ts4_default_script_value; \
    } \
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) { \
        number = value->value.number; \
    } else if (value->type == TS4_SCRIPT_VALUE_INTEGER) { \
        number = value->value.integer; \
    } else { \
        number = g_ts4_script_constants[11]; \
    }

struct F80 { ts4_script_u8 pad[0x80]; float f; };
struct G80 { ts4_script_u8 pad[0x80]; struct F80 *p; };
struct G24 { ts4_script_u8 pad[0x24]; float f; };
struct G60 { ts4_script_u8 pad[0x60]; ts4_script_u32 *p; };
struct VT34 { ts4_script_u32 (**vt)(void *, void *); };

/* Swing_DLL.xex 0x8877B4D0 */
ts4_script_u32 ts4_script_add_float_f80_8877B4D0(struct TS4ScriptContext *context) { struct TS4ScriptValue *value; double number; struct G80 *g; TS4_SCRIPT_NUM(context, number) g = lbl_88D45954; g->p->f = (float)number + g->p->f; return 0; }
/* Swing_DLL.xex 0x8877B7F0 */
ts4_script_u32 ts4_script_set_float_f80_8877B7F0(struct TS4ScriptContext *context) { struct TS4ScriptValue *value; double number; struct G80 *g; TS4_SCRIPT_NUM(context, number) g = lbl_88D45954; g->p->f = (float)number; return 0; }
/* Swing_DLL.xex 0x8877B9B0 */
ts4_script_u32 ts4_script_set_float_f24_8877B9B0(struct TS4ScriptContext *context) { struct TS4ScriptValue *value; double number; struct G24 *g; TS4_SCRIPT_NUM(context, number) g = lbl_88D45878; if (g) g->f = (float)number; return 0; }
/* Swing_DLL.xex 0x8877BEB8 */
ts4_script_u32 ts4_script_session_state_call_8877BEB8(struct TS4ScriptContext *context) { struct TS4ScriptValue *value; double number; ts4_script_u32 v; TS4_SCRIPT_NUM(context, number) v = (ts4_script_u32)number; fn_88931FE0(g_ts4_session_state, &v); return 0; }
/* Swing_DLL.xex 0x88780C90 */
ts4_script_u32 ts4_script_forward_int_88780C90(struct TS4ScriptContext *context) { struct TS4ScriptValue *value; double number;  TS4_SCRIPT_NUM(context, number) return fn_887EA5C8(lbl_88D45A04, (int)number); }
/* Swing_DLL.xex 0x88780D28 */
ts4_script_u32 ts4_script_call_if_obj_88780D28(struct TS4ScriptContext *context) { struct TS4ScriptValue *value; double number; void *g; TS4_SCRIPT_NUM(context, number) g = lbl_88D45B0C; if (g) ts4_if_get_u32_off1c_886570B8(g, (ts4_script_u32)number); return 0; }
/* Swing_DLL.xex 0x88788D90 */
ts4_script_u32 ts4_script_call_lobby_88788D90(struct TS4ScriptContext *context) { struct TS4ScriptValue *value; double number; struct G60 *s; void *p; TS4_SCRIPT_NUM(context, number) s = g_ts4_session_context; p = *(void **)((char *)s + 0x1c); if (p) fn_889A5200(p, (int)number, 1, 0); return 0; }
/* Swing_DLL.xex 0x88788E40 */
ts4_script_u32 ts4_script_call_lobby_88788E40(struct TS4ScriptContext *context) { struct TS4ScriptValue *value; double number; struct G60 *s; void *p; TS4_SCRIPT_NUM(context, number) s = g_ts4_session_context; p = *(void **)((char *)s + 0x1c); if (p) fn_889A5200(p, (int)number, 0, 1); return 0; }
/* Swing_DLL.xex 0x887A0ED0 */
ts4_script_u32 ts4_script_call_with_ref_887A0ED0(struct TS4ScriptContext *context) { struct TS4ScriptValue *value; double number; ts4_script_u32 v; TS4_SCRIPT_NUM(context, number) v = (ts4_script_u32)number; fn_882107D0(*(void **)((char *)lbl_88D41FC4 + 0x70), &v, 0); return 0; }
