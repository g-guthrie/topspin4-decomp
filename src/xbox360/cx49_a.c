/* Swing_DLL.xex 0x88836xxx LuaObject table setters, hand-matched. */
#include "d3d_lua.h"

struct Cx49LuaObject;
typedef struct Cx49LuaGlue {
    Ts4LuaState *L;
    struct Cx49LuaObject *last; /* most recent live script object of this state */
} Cx49LuaGlue;

/* A script object: linked into its state's list, a tagged value (the table) followed by its glue. */
typedef struct Cx49LuaObject {
    struct Cx49LuaObject *next;
    struct Cx49LuaObject *prev;
    Ts4LuaValue v;
    Cx49LuaGlue *glue;
} Cx49LuaObject;

extern void lua2_luaV_settable_8880D278(Ts4LuaState *L, const Ts4LuaValue *t, Ts4LuaValue *key, Ts4LuaValue *val);

/* t[(double)key] = *val */
Cx49LuaObject *cx49_luaobj_set_int_888364F8(Cx49LuaObject *o, int key, Ts4LuaValue *val)
{
    Ts4LuaValue k;
    k.tt = 3;
    k.u.n = (double)key;
    lua2_luaV_settable_8880D278(o->glue->L, &o->v, &k, val);
    return o;
}

/* t[key->payload] = number; the key is a script value whose payload sits at +8 */
Cx49LuaObject *cx49_luaobj_set_num_888365A8(Cx49LuaObject *o, Cx49LuaObject *key, double n)
{
    Ts4LuaValue k;
    k.tt = 3;
    k.u.n = n;
    lua2_luaV_settable_8880D278(o->glue->L, &o->v, &key->v, &k);
    return o;
}

#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#else
#include <string.h>
#endif
extern Ts4LuaObject *lua2_luaS_newlstr_888131A0(void *L, const char *s, u32 len);

/* Store a new counted string value in *o. */
void cx49_value_set_string_88836400(void *L, Ts4LuaValue *o, const char *s)
{
    int n;
    o->tt = 4;
    n = strlen(s);
    o->u.gc = lua2_luaS_newlstr_888131A0(L, s, n);
    o->u.gc->refs++;
}

/* ---- typed field getters on a script table: look the key up into a temporary, test its tag, fall back ---- */
typedef struct Cx49Tmp {
    u32 w0;
    u32 w1;
    int kind;
    u32 w3;
    union {
        const char *data;
        double n;
        int b;
    } v;
    u32 w5, w6;
} Cx49Tmp;
extern void fn_88837880(Cx49Tmp *t, void *obj, const char *key);
extern void ts4_call_seq_u32_off10_88837820(Cx49Tmp *t, void *obj, int idx);
extern void fn_881B19A0(Cx49Tmp *t);




/* integer element idx, or -1 */
int cx49_get_index_int_88837E58(void *obj, int idx)
{
    Cx49Tmp t;
    int r;
    ts4_call_seq_u32_off10_88837820(&t, obj, idx);
    if (t.kind != 3) {
        fn_881B19A0(&t);
        return -1;
    }
    r = (int)(u32)t.v.n;
    fn_881B19A0(&t);
    return r;
}

/* boolean field, or the default */
u32 cx49_get_bool_88837ED0(void *obj, const char *key, u32 def)
{
    Cx49Tmp t;
    u8 r;
    fn_88837880(&t, obj, key);
    if (t.kind != 1) {
        fn_881B19A0(&t);
        return def;
    }
    r = (t.v.b != 0);
    fn_881B19A0(&t);
    return r;
}

extern void fn_88818C88(void *L, Ts4LuaObject *o);

/* t[name] = *val with a string key made on the fly. */
Cx49LuaObject *cx49_luaobj_set_named_888368B0(Cx49LuaObject *o, const char *key, Ts4LuaValue *val)
{
    Ts4LuaState *L = o->glue->L;
    Ts4LuaValue k;
    k.tt = 4;
    k.u.gc = lua2_luaS_newlstr_888131A0(L, key, strlen(key));
    k.u.gc->refs++;
    lua2_luaV_settable_8880D278(L, &o->v, &k, val);
    TS4_RELEASE(L, &k);
    return o;
}



