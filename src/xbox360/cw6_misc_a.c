/* Swing_DLL.xex 0x881A4ED0-0x881A6A00: small core helpers (strings, lists, vector tails). */
typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *ts4_find_char_88173D98(u8 *begin, u8 *end, int ch);
extern void fn_881A4F30(void *node);
extern void ts4_destroy_owned_object(void *p);

typedef struct ByteRange_881A4ED0 { u8 *first; u8 *last; } ByteRange_881A4ED0;

/* Returns the byte offset of the first '|' (0x7c) in the range, or -1 when absent. */
int ts4_range_find_pipe_881A4ED0(ByteRange_881A4ED0 *r)
{
    u8 *last = r->last;
    u8 *first = r->first;
    if ((int)(last - first) != 0) {
        u8 *p = ts4_find_char_88173D98(first, last, 0x7c);
        if (p != last) {
            return (int)(p - first);
        }
    }
    return -1;
}

typedef struct ListNode_881A5088 { struct ListNode_881A5088 *next; struct ListNode_881A5088 *prev; } ListNode_881A5088;
typedef struct List_881A5088 { ListNode_881A5088 *head; } List_881A5088;

/* Releases every node of a circular list and resets the sentinel to empty. */
void ts4_list_clear_881A5088(List_881A5088 *l)
{
    ListNode_881A5088 *head = l->head;
    ListNode_881A5088 *n = head->next;
    while (n != head) {
        ListNode_881A5088 *cur = n;
        n = n->next;
        fn_881A4F30(cur);
        head = l->head;
    }
    head->next = head;
    l->head->prev = l->head;
}

extern int fn_8857BA40(void *handle, int arg, int zero, int flags);
typedef struct Seek_881A5678 { u8 pad[0x14]; void *handle; } Seek_881A5678;

/* Forwards a seek origin (0 -> 1, 1 -> 2, other -> 0) to the underlying handle call. */
int ts4_forward_origin_881A5678(Seek_881A5678 *s, int arg, int mode)
{
    int flags;
    if (mode == 0) {
        flags = 1;
    } else {
        flags = (mode == 1) ? 2 : 0;
    }
    fn_8857BA40(s->handle, arg, 0, flags);
    return 0;
}

extern void *ts4_copy_vec3_range_8816B0F8(void *a, void *b, void *c);
typedef struct Vec3_881A62E8 { void *first; void *last; } Vec3_881A62E8;
typedef struct Obj_881A62E8 { void *p0; u8 pad[8]; void *p0c; u8 pad2[0x28]; Vec3_881A62E8 v; } Obj_881A62E8;

static void vec3_erase_tail_881A62E8(Vec3_881A62E8 *v)
{
    v->last = ts4_copy_vec3_range_8816B0F8(v->last, v->last, v->first);
}

/* Tears down an object: erases the tail of its vec3 array, then destroys its owned pointers. */
void ts4_obj_teardown_881A62E8(Obj_881A62E8 *o)
{
    vec3_erase_tail_881A62E8(&o->v);
    if (o->v.first) {
        ts4_destroy_owned_object(o->v.first);
    }
    ts4_destroy_owned_object(o->p0c);
    ts4_destroy_owned_object(o->p0);
}

typedef struct LuaState_881B3640 LuaState_881B3640;
typedef struct LuaCtx_881B3640 { LuaState_881B3640 **pl; int idx; } LuaCtx_881B3640;
#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#else
#include <string.h>
#endif
extern void ts4_lua_pushnil_88824188(void *L);
extern void ts4_lua_pushlstring_88823FC0(void *L, const char *s, u32 len);
extern void ts4_lua_pushlightuserdata_88823C98(void *L, void *p);
extern void ts4_lua_settable_88823580(void *L, int idx);

/* Sets t[key] = name (nil when name is null) on the Lua table at the context's stack index. */
void ts4_lua_set_string_field_881B3640(LuaCtx_881B3640 *c, const char *name, void *key)
{
    void *L = *(void **)c->pl;
    if (name == 0) {
        ts4_lua_pushnil_88824188(L);
    } else {
        ts4_lua_pushlstring_88823FC0(L, name, (u32)strlen(name));
    }
    ts4_lua_pushlightuserdata_88823C98(*(void **)c->pl, key);
    ts4_lua_settable_88823580(*(void **)c->pl, c->idx);
}

typedef struct LState_881B1860 { u8 pad[0x6c]; void *ctx; } LState_881B1860;
typedef struct CallArg_881B1860 { void *ctx; int index; } CallArg_881B1860;
typedef struct Thunk_881B1860 { void (*fn)(void *ctx, CallArg_881B1860 *args); } Thunk_881B1860;
extern void *lib3_lua_touserdata_88822230(LState_881B1860 *L, int idx);
typedef struct Thunk_881B3080 { void *self; void (*fn)(void *self, void *ctx, CallArg_881B1860 *args); } Thunk_881B3080;

/* Builds a 21-slot argument array (slot i holds the call context and index i) and invokes the userdata's callback. */
void ts4_lua_call_thunk_881B1860(LState_881B1860 *L)
{
    CallArg_881B1860 args[21];
    Thunk_881B1860 *t;
    void *ctx;
    int i;
    t = (Thunk_881B1860 *)lib3_lua_touserdata_88822230(L, -0x2712);
    ctx = L->ctx;
    for (i = 0; i < 21; i++) {
        args[i].ctx = 0;
    }
    for (i = 1; i < 21; i++) {
        args[i].ctx = ctx;
        args[i].index = i;
    }
    t->fn(ctx, args);
}


/* Same as the previous builder, but the userdata callback also receives the userdata's first word. */
void ts4_lua_call_thunk_881B3080(LState_881B1860 *L)
{
    CallArg_881B1860 args[21];
    Thunk_881B3080 *t;
    void *ctx;
    void *self;
    int i;
    t = (Thunk_881B3080 *)lib3_lua_touserdata_88822230(L, -0x2712);
    ctx = L->ctx;
    self = t->self;
    for (i = 0; i < 21; i++) {
        args[i].ctx = 0;
    }
    for (i = 1; i < 21; i++) {
        args[i].ctx = ctx;
        args[i].index = i;
    }
    t->fn(self, ctx, args);
}

typedef struct LuaStk_881B36D0 { u8 pad[0xc]; int top; int base; } LuaStk_881B36D0;
typedef struct LuaPl_881B36D0 { LuaStk_881B36D0 *L; } LuaPl_881B36D0;
typedef struct LuaCtx_881B36D0 { LuaPl_881B36D0 *pl; int idx; } LuaCtx_881B36D0;
typedef struct LuaRes_881B36D0 { LuaPl_881B36D0 *pl; int count; } LuaRes_881B36D0;
extern void ts4_lua_rawget_88823AE8(void *L, int idx);

/* Looks up ctx table[name] (nil when name is null) via rawget and returns the owner plus the resulting stack count. */
LuaRes_881B36D0 *ts4_lua_get_string_field_881B36D0(LuaRes_881B36D0 *out, LuaCtx_881B36D0 *c, const char *name)
{
    LuaPl_881B36D0 *pl;
    LuaStk_881B36D0 *stk;
    void *L = c->pl->L;
    if (name == 0) {
        ts4_lua_pushnil_88824188(L);
    } else {
        ts4_lua_pushlstring_88823FC0(L, name, (u32)strlen(name));
    }
    ts4_lua_rawget_88823AE8(c->pl->L, c->idx);
    pl = c->pl;
    stk = pl->L;
    out->pl = pl;
    out->count = (stk->top - stk->base) >> 4;
    return out;
}

typedef unsigned short u16;
typedef struct LuaCtx_881B1BF8 { LuaStk_881B36D0 *L; int idx; } LuaCtx_881B1BF8;
typedef struct LuaRes_881B1BF8 { LuaCtx_881B1BF8 *ctx; int count; } LuaRes_881B1BF8;
extern void fn_88834B28(void *L, const u16 *s, int len);

/* Pushes a UTF-16 string (nil when null) on the context's Lua stack and returns the owner plus the stack count. */
LuaRes_881B1BF8 *ts4_lua_push_wstring_881B1BF8(LuaRes_881B1BF8 *out, LuaCtx_881B1BF8 *c, const u16 *w)
{
    LuaStk_881B36D0 *stk;
    void *L = c->L;
    if (w == 0) {
        ts4_lua_pushnil_88824188(L);
    } else {
        const u16 *e = w;
        while (*e) {
            e++;
        }
        fn_88834B28(L, w, (int)(e - w));
    }
    stk = c->L;
    out->ctx = c;
    out->count = (stk->top - stk->base) >> 4;
    return out;
}

