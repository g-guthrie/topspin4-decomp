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

extern void *lbl_88D459E0;
extern void *ts4_find_service(ts4_script_u32);
extern void fn_889A6BE0(void *, ts4_script_u32);
extern void fn_8879FF30(void *, int, int);
extern void fn_8862BE08(void *, void *);
extern void fn_88169350(void *, void *);
extern char lbl_880D41AC[];
extern void ts4_assign_formatted_text(void *, void *);
extern void *ts4_member_field_addr_8883B388(void *, int);
extern void ts4_destroy_owned_object(void *);
extern void fn_88150600(void *, void *);
extern void *g_ts4_tsu_notification_object;
extern void fn_887E2BE0(void *, ts4_script_u32);

struct G4C { ts4_script_u8 pad[0x4c]; ts4_script_u32 f4c; ts4_script_u32 b50; ts4_script_u32 e54; };
struct S1D { ts4_script_u8 pad[0x1d]; ts4_script_u8 f; };

/* Swing_DLL.xex 0x88786500 */
ts4_script_u32 ts4_script_load_via_lookup_88786500(struct TS4ScriptContext *context) { struct TS4ScriptValue *value; double number; struct G4C *g; ts4_script_u32 *r; TS4_SCRIPT_NUM(context, number) g = lbl_88D459E0; r = ts4_member_field_addr_8883B578(g, (int)number); g->f4c = *r; return 0; }
/* Swing_DLL.xex 0x887874E0 */
ts4_script_u32 ts4_script_call_service_887874E0(struct TS4ScriptContext *context) { struct TS4ScriptValue *value; double number; void *svc; TS4_SCRIPT_NUM(context, number) svc = ts4_find_service(0x061B4A78u); if (svc) fn_889A6BE0(svc, (ts4_script_u32)number); return 0; }


struct Vec2 { char *b; char *e; };


