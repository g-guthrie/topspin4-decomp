typedef struct TS4Obj TS4Obj;
typedef struct TS4ObjVtbl {
    void *slot0;
    void *slot1;
    void (*method8)(TS4Obj *self, void *arg);
} TS4ObjVtbl;
struct TS4Obj { TS4ObjVtbl *vtbl; };
typedef struct TS4SessionCtxField { unsigned char reserved[0xc]; void *field_c; } TS4SessionCtxField;
extern TS4SessionCtxField *g_ts4_session_context;

/* Fetch the object for session_context->field_c via a per-function getter,
   call its vtable slot 2 (offset 8) with arg, and return the object. */
#define TS4_SESSION_VCALL8(NAME, GETTER) \
    extern TS4Obj *GETTER(void *); \
    TS4Obj *NAME(void *arg) \
    { \
        TS4Obj *obj = GETTER(g_ts4_session_context->field_c); \
        obj->vtbl->method8(obj, arg); \
        return obj; \
    }

/* Swing_DLL.xex 0x88919208 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_88919208, fn_88172F60)
/* Swing_DLL.xex 0x88919A18 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_88919A18, fn_88172CA0)
/* Swing_DLL.xex 0x88919B48 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_88919B48, fn_88172BF0)
/* Swing_DLL.xex 0x88919C88 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_88919C88, fn_88172B40)
/* Swing_DLL.xex 0x88919CE8 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_88919CE8, fn_88172A90)
/* Swing_DLL.xex 0x8891A018 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_8891A018, fn_88172980)
/* Swing_DLL.xex 0x8891A158 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_8891A158, fn_881728C8)
/* Swing_DLL.xex 0x8891A298 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_8891A298, fn_88172810)
/* Swing_DLL.xex 0x8891A780 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_8891A780, fn_88172760)
/* Swing_DLL.xex 0x8891AA68 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_8891AA68, fn_881726B0)
/* Swing_DLL.xex 0x8891AB98 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_8891AB98, fn_88172600)
/* Swing_DLL.xex 0x8891ACC8 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_8891ACC8, fn_88172550)
/* Swing_DLL.xex 0x8891B038 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_8891B038, fn_88172340)
/* Swing_DLL.xex 0x8891FE98 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_8891FE98, fn_881724A0)
/* Swing_DLL.xex 0x8891FEF8 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_8891FEF8, fn_881723F0)
/* Swing_DLL.xex 0x88937ED8 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_88937ED8, fn_8816EA48)
/* Swing_DLL.xex 0x88938010 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_88938010, fn_8816E998)
/* Swing_DLL.xex 0x88938160 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_88938160, fn_8816E8E8)
/* Swing_DLL.xex 0x889381C0 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_889381C0, fn_8816E830)
/* Swing_DLL.xex 0x88938300 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_88938300, fn_8816E778)
/* Swing_DLL.xex 0x889384C0 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_889384C0, fn_8816E598)
/* Swing_DLL.xex 0x88938600 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_88938600, fn_8816E6C0)
/* Swing_DLL.xex 0x88938CC8 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_88938CC8, fn_8816E430)
/* Swing_DLL.xex 0x88938D28 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_88938D28, fn_8816E378)
/* Swing_DLL.xex 0x8893A0B0 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_8893A0B0, fn_8816E2C8)
/* Swing_DLL.xex 0x8893A1F8 */
TS4_SESSION_VCALL8(ts4_session_field_getter_vcall8_8893A1F8, fn_8816E208)
