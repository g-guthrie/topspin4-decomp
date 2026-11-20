/*
 * DRAFTS (not byte-matched): storage-device and save entry points, frontend-map section 1.3.
 *
 * 0x88785B10 (0x234) Lua TCR_SelectDevice / TCR_ShowDeviceSelector(pad, a, b, size_hash, allow_any).
 *   Unless fn_888CDF68(pad) says the pad already has a device, finds the pad's device-selector object
 *   in the list at [0x88D45B30] (+0x1C begin, +0x20 end, 8-byte entries {pad, selector}), points
 *   0x88D45A58 at selector+0x4C (the status word TCR_WaitForDeviceSelector polls), picks the minimum
 *   free space from the size hash (0x14B75F81 -> 0x2AB980 bytes, 0xD8254C81 -> 0xAAE600 bytes, else 0)
 *   and calls fn_88888210(selector, bytes, !allow_any, a, b), which starts the device-selector state
 *   machine (fn_8888A1B8).  Returns 0.  The script default number is held in one register (f31) for both
 *   numeric arguments, hence the explicit `def` local.
 *   4 instructions off: the original sets the "not found" value (li r3,0) after the branch on
 *   fn_888CDF68; this compiler hoists it above and shares it with the return value.  Tried: early
 *   return, `== 0`, inline helper with returns or a result variable, C++, 0..8 dead locals.
 * 0x8879F810 (0x21C) Lua TCR_TriggerLoadSaveCompositeAction(pad, key, name, unused_flag, flag).
 *   Copies the name string (ts4_assign_formatted_text into a one-word owned string), evaluates the
 *   flag strings, then on the action queue at [0x88D45A0C] with kind lbl_88C6C940:
 *   if an action (pad, key) of that kind is queued (ts4_range_has_887E97E8 == 1) it removes it and
 *   returns 0; otherwise, unless either form is queued (ts4_range_has_either_887E9860), it allocates a
 *   0x3AC action (ts4_create_3ac_object(pad)), constructs it with fn_8877DB28(o, key, name, flag, "")
 *   (a constructor: it returns o) and queues it with fn_887EA280(queue, action, key).  Frees the string
 *   and returns 1.  The Lua side then waits on Common_LoadSaveStatus_Closed/_Finished.
 *   23 instructions off (pad and key are copied into a block, which fixes the first conversion): the
 *   original treats fn_8877DB28 as a C++ constructor call (keeps o in r30, uses
 *   the returned this) and schedules the argument conversions differently.  Calling it as an MSVC
 *   explicit constructor call (o->X::X(...)) gives the same size with 17 off, but references a
 *   mangled name, so the C form is kept here.
 * fn_equiv (work/equiv/pr2_device_save.json): 0x88785B10 EQUIVALENT 337 valid trials, 92% coverage;
 *   0x8879F810 EQUIVALENT 246 valid trials, 100% coverage.
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
extern const char g_ts4_true_string[];
INL Val *arg_at(Args *a, u32 i)
{
    if (a->count > i) {
        return &a->items[i];
    }
    return g_ts4_default_script_value;
}
INL double arg_number_d(Val *v, double d)
{
    if (v->type == 4) {
        return v->value.number;
    } else if (v->type == 1) {
        return v->value.integer;
    }
    return d;
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
typedef struct PadUser { u32 pad; struct DevSel *sel; } PadUser;
typedef struct PadUsers { u8 pad[0x1c]; PadUser *begin; PadUser *end; } PadUsers;
typedef struct DevSel { u8 pad[0x4c]; u8 state[4]; } DevSel;
extern PadUsers *lbl_88D45B30;
extern void *lbl_88D45A58;
extern u8 ts4_script_string_equals(void *value, const char *text);
extern u8 fn_888CDF68(int pad);
extern void fn_88888210(DevSel *s, u32 bytes, u32 any_device, u8 a, u8 b);

INL DevSel *find_pad_user(PadUsers *l, int pad)
{
    DevSel *s = 0;
    PadUser *end = l->end;
    PadUser *it = l->begin;
    for (; end != it; it++) {
        if ((u32)pad == it->pad) {
            s = it->sel;
            break;
        }
    }
    return s;
}

typedef struct OwnedStr { char *p; } OwnedStr;
typedef struct ActQueue ActQueue;
extern ActQueue *lbl_88D45A0C;
extern u8 lbl_88C6C940[];
extern const char lbl_880C1320[];
extern void ts4_assign_formatted_text(void *dst, const char *text);
extern void ts4_destroy_owned_object(void *p);
extern u8 ts4_range_has_887E97E8(ActQueue *q, void *kind, int pad, u32 key);
extern void ts4_range_remove_887E98F0(ActQueue *q, void *kind, int pad, u32 key);
extern u8 ts4_range_has_either_887E9860(ActQueue *q, void *kind, int pad, u32 key);
extern void *ts4_create_3ac_object(int pad);
extern void *fn_8877DB28(void *o, u32 key, char *name, u8 flag, const char *empty);
extern void fn_887EA280(ActQueue *q, void *action, u32 key);

/* 0x88785B10: Lua TCR_SelectDevice(pad, a, b, size_hash, allow_any) */
u32 ts4_script_tcr_select_device_88785B10(Ctx *c)
{
    Val *v0 = arg_at(c->args, 0);
    double def = g_ts4_script_constants[11];
    int pad = (int)arg_number_d(v0, def);
    u8 a = ts4_script_string_equals(arg_at(c->args, 1)->payload, g_ts4_true_string);
    u8 b = ts4_script_string_equals(arg_at(c->args, 2)->payload, g_ts4_true_string);
    u32 size = (u32)arg_number_d(arg_at(c->args, 3), def);
    u8 any = ts4_script_string_equals(arg_at(c->args, 4)->payload, g_ts4_true_string);
    if (!fn_888CDF68(pad)) {
        DevSel *s = find_pad_user(lbl_88D45B30, pad);
        u32 bytes;
        lbl_88D45A58 = s->state;
        bytes = 0;
        if (size == 0x14B75F81) bytes = 0x2AB980;
        else if (size == 0xD8254C81) bytes = 0xAAE600;
        fn_88888210(s, bytes, any == 0, a, b);
    }
    return 0;
}

/* 0x8879F810: Lua TCR_TriggerLoadSaveCompositeAction(pad, key, name, flag3, flag4) */
u32 ts4_script_tcr_trigger_load_save_8879F810(Ctx *c)
{
    int p = (int)arg_number(arg_at(c->args, 0));
    u32 k = (u32)arg_number(arg_at(c->args, 1));
    {
        int pad = p;
        u32 key = k;
        OwnedStr name;
        u8 flag;
        ActQueue *q;
        u32 ok;
        u8 has;
        char *n;
        ts4_assign_formatted_text(&name, *(char **)arg_at(c->args, 2)->payload);
        ts4_script_string_equals(arg_at(c->args, 3)->payload, g_ts4_true_string);
        flag = ts4_script_string_equals(arg_at(c->args, 4)->payload, g_ts4_true_string);
        q = lbl_88D45A0C;
        ok = 1;
        has = ts4_range_has_887E97E8(q, lbl_88C6C940, pad, key);
        n = name.p;
        if (has == 1) {
            ts4_range_remove_887E98F0(q, lbl_88C6C940, pad, key);
            ok = 0;
        } else if (!ts4_range_has_either_887E9860(q, lbl_88C6C940, pad, key)) {
            void *o = ts4_create_3ac_object(pad);
            fn_887EA280(q, fn_8877DB28(o, key, n, flag, lbl_880C1320), key);
        }
        ts4_destroy_owned_object(n);
        return ok;
    }
}
