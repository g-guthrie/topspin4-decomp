/*
 * DRAFTS (not byte-matched) for the sign-in waits, frontend-map section 1.3.
 * Matched neighbours are in src/xbox360/pr2_signin.c.
 *
 * 0x88778CD0 (0x14) Lua TCR_WaitForSignIn: returns 1 while byte 0x88C46F42 (sign-in finished) is 0,
 *   so the script keeps waiting.  3 instructions off: register numbering only (the original loads the
 *   byte into r11 and computes the result in r3 with cntlzw/rlwinm; every C form tried keeps a different
 *   register).  fn_equiv (work/equiv/pr2_signin_near.json): all five EQUIVALENT, 100% block coverage
 *   (161, 163, 134, 104 and 266 valid trials in the order listed here).
 * 0x888DA288 (0x68) device-select deferred action: clears byte 0x88C46F6A (device chosen), then queues
 *   ts4_set_u8_lbl_88C46F6A_888BFCE0 on service 0x11A98C5A with key 0x83DE4BDF (mode 2), passing arg.
 *   12 instructions off: argument registers are set up in a different order around the find_service call.
 * 0x888C5618 (0xBC) deferred action behind TCR_AskSignIn: when the request is not cancelled (ctx+0x4 and
 *   ctx+0xC both 0) it calls XamShowSigninUI(user = tcr+0x24, panes = tcr+0x28 ? 2 : 1) and then blocks in
 *   ts4_wait_system_ui_closed_888C0260.  It always sets 0x88C46F42 = 1 (which ends TCR_WaitForSignIn).
 *   If the UI was shown and the pad's record still says not signed in (+0x1A), it asks again through
 *   ts4_tcr_ask_sign_in_888DA4B0 (so the sign-in UI re-opens until the player signs in); otherwise it
 *   clears the record's "asking" byte (+0x1B).  6 instructions off on the LTCG route (context
 *   pr2_signin.c): the `panes` value is built with a different compare sequence.
 * 0x888DA4B0 (0xF8) TCR_AskSignIn core: searches the online state's signed-in list
 *   ([g_ts4_online_state]+0x1C: begin +4, end +8, entries {+4 pad, +8 signed_in}) for the pad, stores
 *   the action key in tcr+0x6C.  Signed in: sets 0x88C46F42 = 1.  Not signed in: marks the pad record
 *   +0x1B = 1, stores user in tcr+0x24, sets 0x88C46F42 = 0 and queues 0x888C5618 on tcr+0x20 with key
 *   (action key, or 0x91459AB9 when 0), pad, mode 2.  8 instructions off on the LTCG route: register
 *   numbering for the 0x88C46F42 address.
 * 0x8878A5D8 (0x158) Lua TCR_AskSignIn(pad, user, key): converts the three arguments (int, int, u32) and
 *   calls ts4_tcr_ask_sign_in_888DA4B0(find_service(0xF4F09230), pad, user, key); returns 0.  84 instructions
 *   off (all from one shift): the original keeps `key` in r29 across the find_service call (save helpers
 *   __savegprlr_29, frame 0x80); this compiler reloads it from the conversion slot after the call instead.
 *   Tried: C and C++, /Oc, /Os, LTCG with context, reordered declarations, double locals, explicit
 *   service local, implicit conversions.
 */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline __attribute__((unused))
#endif
typedef struct PadObj { u8 pad[0xc]; int pad_index; u8 pad10[0xa]; u8 b1a; u8 b1b; u8 pad1c[0x94]; } PadObj;
typedef struct ModList ModList;
typedef struct Engine { u8 pad[0x234]; ModList *modules; } Engine;
typedef struct Val { int type; u32 reserved; union { int integer; double number; } value; u8 pad[0x28]; } Val;
typedef struct Args { u8 reserved[0x380]; Val *items; u32 count; } Args;
typedef struct Ctx { u8 reserved[0x10]; Args *args; } Ctx;
typedef struct TcrActions { u8 pad[0x20]; void *queue; u32 user; u8 show_all; u8 pad29[0x3b]; u32 action_key; } TcrActions;
typedef struct Ctx0c { u8 pad[4]; u32 f4; u8 pad8[4]; int fc; } Ctx0c;
typedef struct SigninAction { u8 pad[0xc]; Ctx0c *ctx; u8 pad10[0x18]; int pad_index; } SigninAction;
typedef struct SignedInEntry { u8 pad[4]; int pad_index; int signed_in; } SignedInEntry;
typedef struct SignedInList { u8 pad[4]; SignedInEntry **begin; SignedInEntry **end; } SignedInList;
typedef struct OnlineState { u8 pad[0x1c]; SignedInList *signed_in; } OnlineState;
extern Engine *lbl_88D45B1C;
extern TcrActions *lbl_88D4593C;
extern OnlineState *g_ts4_online_state;
extern u8 lbl_88C46F42;
extern u8 lbl_88C46F6A;
extern Val *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern void *ts4_find_service(u32 id);
extern void ts4_set_u8_lbl_88C46F6A_888BFCE0(void);
extern void ts4_tailcall_XamShowSigninUI_8857A688(u32 user, u32 panes);
extern void ts4_wait_system_ui_closed_888C0260(void);
extern PadObj *ts4_pad_record_find_88614938(ModList *m, int pad);
extern void fn_886260B8(void *svc, u32 key, int arg, u32 a, u32 b, void (*cb)(void *), u32 c, u32 d);
void ts4_tcr_ask_sign_in_888DA4B0(TcrActions *t, int pad, u32 user, u32 key);

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

/* 0x88778CD0: Lua TCR_WaitForSignIn */
u32 ts4_script_tcr_wait_for_sign_in_88778CD0(void *ctx)
{
    u8 done = lbl_88C46F42;
    (void)ctx;
    return done == 0;
}

/* 0x888DA288: device-select deferred action */
void ts4_device_select_deferred_888DA288(int arg)
{
    void *svc;
    lbl_88C46F6A = 0;
    svc = ts4_find_service(0x11A98C5A);
    fn_886260B8(svc, 0x83DE4BDF, arg, 0, 2, (void (*)(void *))ts4_set_u8_lbl_88C46F6A_888BFCE0, 0, 0);
}

/* 0x888C5618: deferred action behind TCR_AskSignIn: show the sign-in UI and block until it closes */
void ts4_signin_action_run_888C5618(SigninAction *a)
{
    TcrActions *t = lbl_88D4593C;
    u8 shown = 0;
    Ctx0c *c = a->ctx;
    PadObj *p;
    if (c->fc == 0 && c->f4 == 0) {
        shown = 1;
        ts4_tailcall_XamShowSigninUI_8857A688(t->user, ((t->show_all == 0) ^ 1) + 1);
        ts4_wait_system_ui_closed_888C0260();
    }
    lbl_88C46F42 = 1;
    p = ts4_pad_record_find_88614938(lbl_88D45B1C->modules, a->pad_index);
    if (shown && !p->b1a) {
        ts4_tcr_ask_sign_in_888DA4B0(t, a->pad_index, t->user, t->action_key);
        return;
    }
    p->b1b = 0;
}

/* 0x888DA4B0: ask pad `pad` to sign in (TCR_AskSignIn): done at once when the pad is already signed in */
void ts4_tcr_ask_sign_in_888DA4B0(TcrActions *t, int pad, u32 user, u32 key)
{
    SignedInList *l = g_ts4_online_state->signed_in;
    SignedInEntry **end = l->end;
    SignedInEntry **it = l->begin;
    int found;
    for (; it != end; it++) {
        if (pad == (*it)->pad_index) {
            found = (*it)->signed_in;
            goto have;
        }
    }
    found = 0;
have:
    t->action_key = key;
    if (found == 0) {
        PadObj *p = ts4_pad_record_find_88614938(lbl_88D45B1C->modules, pad);
        p->b1b = 1;
        t->user = user;
        lbl_88C46F42 = 0;
        fn_886260B8(t->queue, t->action_key != 0 ? t->action_key : 0x91459AB9, pad, 2, 0, (void (*)(void *))ts4_signin_action_run_888C5618, 0, 0);
    } else {
        lbl_88C46F42 = 1;
    }
}

/* 0x8878A5D8: Lua TCR_AskSignIn(pad, user, key) */
u32 ts4_script_tcr_ask_sign_in_8878A5D8(Ctx *c)
{
    int pad = (int)arg_number(arg_at(c->args, 0));
    int user = (int)arg_number(arg_at(c->args, 1));
    u32 key = (u32)arg_number(arg_at(c->args, 2));
    ts4_tcr_ask_sign_in_888DA4B0((TcrActions *)ts4_find_service(0xF4F09230), pad, (u32)user, key);
    return 0;
}

