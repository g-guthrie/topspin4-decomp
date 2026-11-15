/*
 * Message-box script entry (frontend-map section 1.3: "Message box" row).
 */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline __attribute__((unused))
#endif
typedef struct Val { int type; u32 reserved; union { int integer; double number; } value; u8 payload[0x28]; } Val;
typedef struct Args { u8 reserved[0x380]; Val *items; u32 count; } Args;
typedef struct Ctx { u8 reserved[0x10]; Args *args; } Ctx;
extern Val *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
INL Val *arg_at(Args *a, u32 i)
{
    if (a->count > i) {
        return &a->items[i];
    }
    return g_ts4_default_script_value;
}
INL double arg_number(Val *v)
{
    if (v->type == 4) {
        return v->value.number;
    } else if (v->type == 1) {
        return v->value.integer;
    }
    return g_ts4_script_constants[11];
}
typedef struct XNode XNode;
typedef struct XNodeVt { u8 pad[0x28]; u8 *(*value_ptr)(XNode *n, void *h, u32 id, u32 create); } XNodeVt;
struct XNode { XNodeVt *vt; };
typedef struct XHandle { XNode *node; u32 id; u32 extra; } XHandle;
typedef struct Engine { u8 pad[0x27c]; u32 f27c; } Engine;
extern Engine *lbl_88D45B1C;
extern const char lbl_880ED64C[]; /* UI:/UI/VariableList/VarCKey[@Id="MessageBox_Id"]/@Value */
extern const char lbl_880ED610[]; /* UI:/UI/VariableList/VarBool[@Id="MessageBox_Closed"]/@Value */
extern void *ts4_find_service(u32 id);
extern u32 *fn_886260B8(void *svc, u32 key, int pad, u32 type, u32 mode, u32 (*cb)(u32), u32 c, u32 d);
extern u32 ts4_if_addr_lbl_880EEC38_8878E6D0(u32 a0);
extern void ts4_if_set_u32_off0_8862BE08(XHandle *out, const char *path);
extern u32 *ts4_gp0_xdata_get_u32_or_default_88165E20(u32 *out, XHandle *h, u32 *def);
extern void ts4_get_u32_off0_8822AFE8(XHandle *h, u32 *value);

/* 0x88791270 (0x340): Lua TriggerMessageBox(pad, kind, key, buttons, text_id).
 * Queues a message-box job on the device service 0x11A98C5A through fn_886260B8(service, key, pad,
 * type, mode, ts4_if_addr_lbl_880EEC38_8878E6D0, 0, 0).  kind picks the mode (0x9C1C9375 -> 1,
 * 0x8FF3A55A -> 2, 0xD63C69C5 -> 3, else 0); buttons picks the type (0x01403330 -> 0, 0x3705EF5D -> 2,
 * 0x33EB4F4C -> 1, else 0).  When a job is returned: read MessageBox_Id with engine+0x27C as the
 * default, store text_id in job+0, then write MessageBox_Id = 0x4905ED7B.  Always clears
 * MessageBox_Closed (WaitMessageBox 0x887915B0 polls it until the RUI SMessageBox layer sets it).
 * Returns 0. */
u32 ts4_script_trigger_message_box_88791270(Ctx *c)
{
    int pad = (int)arg_number(arg_at(c->args, 0));
    u32 kind = (u32)arg_number(arg_at(c->args, 1));
    u32 key = (u32)arg_number(arg_at(c->args, 2));
    u32 buttons = (u32)arg_number(arg_at(c->args, 3));
    u32 text_id = (u32)arg_number(arg_at(c->args, 4));
    void *svc = ts4_find_service(0x11A98C5A);
    u32 mode;
    u32 type;
    u32 *job;
    XHandle id_h;
    XHandle closed_h;
    u32 v;
    mode = 0;
    if (kind == 0x9C1C9375) mode = 1;
    else if (kind == 0x8FF3A55A) mode = 2;
    else if (kind == 0xD63C69C5) mode = 3;
    type = 0;
    if (buttons == 0x01403330) type = 0;
    else if (buttons == 0x3705EF5D) type = 2;
    else if (buttons == 0x33EB4F4C) type = 1;
    job = fn_886260B8(svc, key, pad, type, mode, ts4_if_addr_lbl_880EEC38_8878E6D0, 0, 0);
    if (job) {
        u32 out;
        ts4_if_set_u32_off0_8862BE08(&id_h, lbl_880ED64C);
        v = lbl_88D45B1C->f27c;
        ts4_gp0_xdata_get_u32_or_default_88165E20(&out, &id_h, &v);
        job[0] = text_id;
        v = 0x4905ED7B;
        ts4_get_u32_off0_8822AFE8(&id_h, &v);
    }
    ts4_if_set_u32_off0_8862BE08(&closed_h, lbl_880ED610);
    *closed_h.node->vt->value_ptr(closed_h.node, &closed_h, closed_h.id, 1) = 0;
    return 0;
}
