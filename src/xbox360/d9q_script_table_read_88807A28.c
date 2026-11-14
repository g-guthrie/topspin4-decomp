/* Swing_DLL.xex 0x88807A28-0x88807BC4, executable version 0.0.0.3. */
typedef struct lua_State lua_State;

/* Script call frame: the Lua state is the first member. */
typedef struct Ts9Frame {
    lua_State *L;
} Ts9Frame;

typedef struct Ts9Context {
    char pad[0x6C];
    Ts9Frame *frame;
} Ts9Context;

/* Callback argument block: the call context is the first member. */
typedef struct Ts9Args {
    Ts9Context *ctx;
} Ts9Args;

/* Polymorphic reader target: the method table is the first member. */
typedef struct Ts9Sink {
    void **vt;
} Ts9Sink;

/* Reader state built on the stack for a table argument. */
typedef struct Ts9Reader {
    Ts9Frame *f;
    int idx;
    Ts9Sink *p;
    int limit;
    int q;
} Ts9Reader;

typedef struct Ts9Obj {
    int w[8];
} Ts9Obj;

typedef int (*Ts9ReadFn)(Ts9Sink *self, Ts9Sink **p, int limit, int mode);

extern int lib3_lua_type_88822738(lua_State *L, int idx);
extern Ts9Obj *ts4_if_call_seq_u32_off8_88837608(Ts9Obj *out, Ts9Reader *r);
extern unsigned char fn_888063B0(Ts9Obj *o, Ts9Sink **p);
extern void fn_881B1BF8(Ts9Reader *r, Ts9Args *a, int v);
extern void ts4_loop_call_seq_u32_off0_881B1B68(Ts9Reader *r, Ts9Args *a, int v);

/* Script callback: read argument 1 as a table through reader slot 10 and push the result. */
int ts4_script_table_read_88807A28(void *self, Ts9Args *a)
{
    Ts9Frame *fr = a->ctx->frame;
    Ts9Reader r;
    Ts9Obj o;
    Ts9Obj *t;
    (void)self;
    if (lib3_lua_type_88822738(fr->L, 1) != 5) return 0;
    r.f = fr; r.p = 0; r.q = 0; r.limit = 0xFFFFF; r.idx = 1;
    t = ts4_if_call_seq_u32_off8_88837608(&o, &r);
    if (!fn_888063B0(t, &r.p)) return 0;
    fn_881B1BF8(&r, a, ((Ts9ReadFn)r.p->vt[10])(r.p, &r.p, r.limit, 2));
    return 1;
}

/* Script callback: same as above through reader slot 20. */
int ts4_script_table_read_88807AF8(void *self, Ts9Args *a)
{
    Ts9Frame *fr = a->ctx->frame;
    Ts9Reader r;
    Ts9Obj o;
    Ts9Obj *t;
    (void)self;
    if (lib3_lua_type_88822738(fr->L, 1) != 5) return 0;
    r.f = fr; r.p = 0; r.q = 0; r.limit = 0xFFFFF; r.idx = 1;
    t = ts4_if_call_seq_u32_off8_88837608(&o, &r);
    if (!fn_888063B0(t, &r.p)) return 0;
    ts4_loop_call_seq_u32_off0_881B1B68(&r, a, ((Ts9ReadFn)r.p->vt[20])(r.p, &r.p, r.limit, 1));
    return 1;
}
