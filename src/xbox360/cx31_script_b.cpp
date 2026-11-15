/* CW31 part b: script callbacks that set a body field and run the guarded session update inline. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline __attribute__((unused))
#endif
struct Val { int type; u32 reserved; union { int integer; double number; } value; u8 pad[0x28]; };
struct Args { u8 reserved[0x380]; Val *items; u32 count; };
struct Ctx { u8 reserved[0x10]; Args *args; };
extern "C" Val *g_ts4_default_script_value;
extern "C" double g_ts4_script_constants[];

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

struct Guard {
    virtual void slot0();
    virtual void enter();
    virtual void leave();
};
struct Shared {
    char pad0[8];
    Guard guard;
};
struct Owner {
    char pad0[0x1c];
    Shared *shared;
};
struct Body { u8 pad[0x14]; int slot; int slot2; int slot3; };
struct Msg { u8 pad[8]; Body *body; };

extern "C" Owner *g_ts4_session_state;
extern "C" void ts4_loop_get_u32_off8_8861DDB0(Shared *shared, Msg *m);
extern "C" Msg *fn_882156B8(void *state, u32 key);
extern "C" Msg *fn_882155E0(void *state, u32 key);
extern "C" Msg *fn_881542F8(void *state, u32 key);

INL void guarded_update(Shared **sp, Msg *m)
{
    Guard *guard = &(*sp)->guard;
    guard->enter();
    ts4_loop_get_u32_off8_8861DDB0(*sp, m);
    guard->leave();
}

/* 0x88785D48 */
extern "C" u32 ts4_script_session_msg_slot14_88785D48(Ctx *c)
{
    int v = (int)arg_number(arg_at(c->args, 0));
    Msg *m = fn_882156B8(g_ts4_session_state, 0x3D54D47Eu);
    Shared **sp = &g_ts4_session_state->shared;
    m->body->slot = v;
    guarded_update(sp, m);
    return 0;
}

/* 0x88788CA0 */
extern "C" u32 ts4_script_session_msg_slot18_88788CA0(Ctx *c)
{
    int v = (int)arg_number(arg_at(c->args, 0));
    Msg *m = fn_882155E0(g_ts4_session_state, 0xC8385BA8u);
    Shared **sp = &g_ts4_session_state->shared;
    m->body->slot2 = v;
    guarded_update(sp, m);
    return 0;
}

/* 0x88789368 */
extern "C" u32 ts4_script_session_msg_send_88789368(Ctx *c)
{
    Msg *m = fn_881542F8(g_ts4_session_state, 0xD98C63D3u);
    (void)c;
    guarded_update(&g_ts4_session_state->shared, m);
    return 0;
}
