/* Swing_DLL.xex 0x887870F0-0x887873E0, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define INL static __forceinline
typedef unsigned __int64 u64;
#else
#define INL static inline __attribute__((unused))
typedef unsigned long long u64;
#endif
typedef struct Val { int type; u32 reserved; union { int integer; double number; } value; u8 pad[0x28]; } Val;
typedef struct Args { u8 reserved[0x380]; Val *items; u32 count; } Args;
typedef struct Ctx { u8 reserved[0x10]; Args *args; } Ctx;
typedef struct Body { u8 pad[0x14]; int slot; u64 stamp; } Body;
typedef struct Msg { u8 pad[8]; Body *body; } Msg;
typedef struct Svc Svc;
typedef struct SvcVtbl { u8 pad[0x4c]; u8 *(*get)(Svc *, int); } SvcVtbl;
struct Svc { SvcVtbl *vt; };
extern Val *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern void *g_ts4_session_state;
extern Svc *ts4_find_service(u32 id);
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

/* the record sits at a self-relative offset stored in the first word of the table */
#define BODY(NAME, SVC, SIZE, BASE_OFF, KEY) \
u32 NAME(Ctx *c) \
{ \
    int slot = (int)arg_number(arg_at(c->args, 0)); \
    int idx = (int)arg_number(arg_at(c->args, 1)); \
    if (idx != -1) { \
        Svc *s = ts4_find_service(SVC); \
        if (s) { \
            u8 *base = s->vt->get(s, 0) + BASE_OFF; \
            u32 off = *(u32 *)base; \
            u8 *rec = idx * SIZE + off + base; \
            Msg *m = fn_882156B8(g_ts4_session_state, KEY); \
            void *st = g_ts4_session_state; \
            Body *b = m->body; \
            b->slot = slot; \
            b->stamp = *(u64 *)rec; \
            fn_88151560(st, m); \
        } \
    } \
    return 0; \
}

BODY(ts4_script_set_slot_stamp_887870F0, 0x8A2D4CADu, 0xd0, 0, 0x92434A9Du)
BODY(ts4_script_set_slot_stamp_88787390, 0x8A2D4CADu, 0xd0, 0, 0x77A62561u)
