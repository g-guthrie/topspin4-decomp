/* Swing_DLL.xex 0x88787EB0-0x88788A00, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define INL static __forceinline
typedef unsigned __int64 u64;
#else
#define INL static inline
typedef unsigned long long u64;
#endif
typedef struct Val { int type; u32 reserved; union { int integer; double number; } value; u8 pad[0x28]; } Val;
typedef struct Args { u8 reserved[0x380]; Val *items; u32 count; } Args;
typedef struct Ctx { u8 reserved[0x10]; Args *args; } Ctx;
typedef struct Session { u8 reserved[0x1c]; void *lobby; } Session;
typedef struct Rec { u8 pad[0x70]; u64 stamp; } Rec;
typedef struct Body { u8 pad[0x14]; int slot; u64 stamp; } Body;
typedef struct Msg { u8 pad[8]; Body *body; } Msg;
extern Val *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern Session *g_ts4_session_context;
extern void *g_ts4_session_state;
extern Rec *fn_8899F970(void *lobby, int idx);
extern Msg *fn_882156B8(void *state, u32 key);
extern void fn_88151560(void *state, Msg *m);

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

u32 ts4_script_set_slot_stamp_88787EB0(Ctx *c)
{
    int slot = (int)arg_number(arg_at(c->args, 0));
    int idx = (int)arg_number(arg_at(c->args, 1));
    void *lobby;
    lobby = g_ts4_session_context->lobby;
    if (lobby && idx != -1) {
        Rec *r = fn_8899F970(lobby, idx);
        if (r) {
            Msg *m = fn_882156B8(g_ts4_session_state, 0x0ECA33C8);
            void *st = g_ts4_session_state;
            Body *b = m->body;
            b->slot = slot;
            b->stamp = r->stamp;
            fn_88151560(st, m);
        }
    }
    return 0;
}

u32 ts4_script_set_slot_stamp_88788268(Ctx *c)
{
    int slot = (int)arg_number(arg_at(c->args, 0));
    int idx = (int)arg_number(arg_at(c->args, 1));
    void *lobby;
    lobby = g_ts4_session_context->lobby;
    if (lobby && idx != -1) {
        Rec *r = fn_8899F970(lobby, idx);
        if (r) {
            Msg *m = fn_882156B8(g_ts4_session_state, 0x92434A9D);
            void *st = g_ts4_session_state;
            Body *b = m->body;
            b->slot = slot;
            b->stamp = r->stamp;
            fn_88151560(st, m);
        }
    }
    return 0;
}

u32 ts4_script_set_slot_stamp_88788620(Ctx *c)
{
    int slot = (int)arg_number(arg_at(c->args, 0));
    int idx = (int)arg_number(arg_at(c->args, 1));
    void *lobby;
    lobby = g_ts4_session_context->lobby;
    if (lobby && idx != -1) {
        Rec *r = fn_8899F970(lobby, idx);
        if (r) {
            Msg *m = fn_882156B8(g_ts4_session_state, 0x77A62561);
            void *st = g_ts4_session_state;
            Body *b = m->body;
            b->slot = slot;
            b->stamp = r->stamp;
            fn_88151560(st, m);
        }
    }
    return 0;
}
