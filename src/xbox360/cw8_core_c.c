/* CW8 part c: table lookups, lua registry store, scope guard. Built with /Oc. */
#include "fam4_refstr.h"
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
typedef unsigned int cw8_uptr;
#else
typedef unsigned long cw8_uptr;
#endif
#ifdef _MSC_VER
#define CW8C_INL static __forceinline
#else
#define CW8C_INL static inline
#endif


typedef struct Cw8Node { u32 key; u32 value; } Cw8Node;
typedef struct Cw8Owner { u32 pad0; u8 *base; } Cw8Owner;
extern Cw8Node *ts4_string_table_find_881FBA58(void *table, void *key, u32 *c, u32 *b, u32 *a);
extern void ts4_call_seq_u32_off0_8819AD80(void *key);
extern void ts4_string_map_chars_8819BA08(void *key);

/* 0x881EB5E8: normalise key, look it up in the table at owner+0x14D0, return its value (0 if absent) */
u32 ts4_table_find_value_881EB5E8(Cw8Owner *self, void *key)
{
    u32 a, b, c;
    Cw8Node *n;
    u8 *tbl;
    ts4_string_map_chars_8819BA08(key);
    tbl = self->base + 0x14d0;
    n = ts4_string_table_find_881FBA58(tbl, key, &c, &b, &a);
    if (n != 0) {
        u32 value = n->value;
        ts4_call_seq_u32_off0_8819AD80(key);
        return value;
    }
    ts4_call_seq_u32_off0_8819AD80(key);
    return 0;
}

/* 0x881EB928: look up key in the table at owner+0x1428, return its value (0 if absent) */
u32 ts4_table_find_value_881EB928(Cw8Owner *self, void *key)
{
    u32 a, b, c;
    Cw8Node *n;
    u8 *tbl = self->base + 0x1428;
    n = ts4_string_table_find_881FBA58(tbl, key, &c, &b, &a);
    if (n != 0) {
        u32 value = n->value;
        ts4_call_seq_u32_off0_8819AD80(key);
        return value;
    }
    ts4_call_seq_u32_off0_8819AD80(key);
    return 0;
}

/* 0x881EB9A0: same lookup in the table at owner+0x13F0 */
u32 ts4_table_find_value_881EB9A0(Cw8Owner *self, void *key)
{
    u32 a, b, c;
    Cw8Node *n;
    u8 *tbl = self->base + 0x13f0;
    n = ts4_string_table_find_881FBA58(tbl, key, &c, &b, &a);
    if (n != 0) {
        u32 value = n->value;
        ts4_call_seq_u32_off0_8819AD80(key);
        return value;
    }
    ts4_call_seq_u32_off0_8819AD80(key);
    return 0;
}

typedef struct Cw8StkTop { u8 pad[0xc]; char *top; char *base; } Cw8StkTop;
typedef struct Cw8LuaHolder { Cw8StkTop *L; } Cw8LuaHolder;
typedef struct Cw8LuaOwner { u8 pad[0x18]; Cw8LuaHolder *holder; } Cw8LuaOwner;
typedef struct Cw8LuaGlobal { u8 pad[0x88]; Cw8LuaHolder *holder; } Cw8LuaGlobal;
typedef struct Cw8Tmp { void *a; int b; } Cw8Tmp;
extern Cw8LuaGlobal *lbl_88D41FC4;
extern Cw8Tmp *ts4_loop_call_seq_u32_off0_881B1B68(Cw8Tmp *out, Cw8LuaHolder *h, const char *s);
extern void fn_88832EF8(Cw8Tmp *t, Cw8LuaHolder *h);
extern void ts4_lua_rawset_88823430(void *L, int idx);
extern void lua3_lua_settop_888246A8(void *L, int idx);

/* 0x881E9A90: push key and value strings, build the user value, store it in the registry table and restore the stack */
void ts4_lua_set_registry_str_881E9A90(Cw8LuaOwner *self, const char **key)
{
    Cw8LuaHolder *h = self->holder;
    Cw8StkTop *L;
    int saved;
    Cw8Tmp tmp;
    if ((long)h == 0)
        h = lbl_88D41FC4->holder;
    L = h->L;
    saved = (L->top - L->base) >> 4;
    ts4_loop_call_seq_u32_off0_881B1B68(&tmp, h, *key);
    ts4_loop_call_seq_u32_off0_881B1B68(&tmp, h, *key);
    fn_88832EF8(&tmp, h);
    ts4_lua_rawset_88823430(h->L, -0x2711);
    lua3_lua_settop_888246A8(h->L, -2);
    lua3_lua_settop_888246A8(L, saved);
}

typedef struct Cw8Target { void *s[18]; void (*notify)(void *, void *); } Cw8TargetVt;
typedef struct Cw8TargetObj { const Cw8TargetVt *vt; } Cw8TargetObj;
typedef struct Cw8Entry { u32 key; Cw8TargetObj *target; } Cw8Entry;
typedef struct Cw8Reg { u32 pad0; u8 *base; } Cw8Reg;
extern void *lbl_88D41FC0;
extern void *fn_88198CE0(void *p);

/* 0x881E90A0: look the key up in the table at base+0x13F0 and notify its target with arg, under the global guard */
void *ts4_registry_notify_881E90A0(Cw8Reg *self, void *key, void *arg)
{
    void *guard = fn_88198CE0(lbl_88D41FC0);
    u32 a, b, c;
    u8 *tbl = self->base + 0x13f0;
    Cw8Entry *e = (Cw8Entry *)ts4_string_table_find_881FBA58(tbl, key, &c, &b, &a);
    if (e != 0) {
        e->target->vt->notify(e->target, arg);
    }
    return fn_88198CE0(guard);
}

typedef struct Cw8GuardRec { u8 pad[1]; u8 flag; } Cw8GuardRec;
CW8C_INL void cw8_guard_set(Cw8GuardRec *r, u8 v)
{
    r->flag = v;
}
typedef struct Cw8Guarded { u8 pad[0x6c]; u32 slots; } Cw8Guarded;
typedef struct Cw8Guard { Cw8Guarded *obj; u8 saved; } Cw8Guard;
extern u32 ts4_input_thread_slot_data_88883CD0(void *key);
extern void *lbl_88D459B4;

/* 0x881E3930: constructor of a scope guard: remember the object and clear its flag byte */
#ifdef _MSC_VER
__declspec(noinline)
#endif
Cw8Guard *ts4_guard_ctor_881E3930(Cw8Guard *self, Cw8Guarded *obj)
{
    self->obj = obj;
    self->saved = 0;
    if (obj != 0) {
        u8 *rec;
        u32 off;
        self->saved = 0;
        off = ts4_input_thread_slot_data_88883CD0(lbl_88D459B4) + 0x18;
        rec = (u8 *)(cw8_uptr)(obj->slots + off);
        cw8_guard_set((Cw8GuardRec *)rec, 0);
    }
    return self;
}

/* 0x881E3988: destructor of the scope guard: restore the flag byte */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_guard_dtor_881E3988(Cw8Guard *self)
{
    Cw8Guarded *obj = self->obj;
    if (obj != 0) {
        u8 *rec;
        u32 off;
        u8 saved = self->saved;
        off = ts4_input_thread_slot_data_88883CD0(lbl_88D459B4) + 0x18;
        rec = (u8 *)(cw8_uptr)(obj->slots + off);
        cw8_guard_set((Cw8GuardRec *)rec, saved);
    }
}

typedef struct Cw8W6 { u32 w[6]; } Cw8W6;
typedef struct Cw8Elem {
    char *name;
    Cw8W6 words;
    u8 sub[0x10];
} Cw8Elem;
typedef struct Cw8ElemVec { u32 pad0; Cw8Elem *data; u32 count; } Cw8ElemVec;
typedef struct Cw8AssignVt { void *s[9]; void (*attach)(void *, void *); u32 pad[4]; void *(*clone)(void *); } Cw8AssignVt;
typedef struct Cw8Owned { const Cw8AssignVt *vt; } Cw8Owned;
typedef struct Cw8AssignObj {
    u8 pad0[0xc];
    char *str;
    u8 pad10[0x12];
    u8 f22;
    u8 pad23;
    Cw8Owned *owned;
    Cw8ElemVec vec;
    u32 f34;
    u32 f38;
    u8 f3c, f3d;
    u8 pad3e[2];
    u32 f40;
    Cw8W6 words44;
    u32 f5c;
    u32 pad60;
    u32 f64;
    u32 pad68;
    u32 f6c;
    u8 f70;
    u8 pad71[3];
    u32 f74, f78, f7c, f80;
} Cw8AssignObj;
extern void ts4_if_call_seq_u32_off0_8819B0C8(void *dst, const void *src);
extern void ts4_v2c_resize_8820B1A0(void *vec, u32 n);
extern void ts4_prvec_assign_8820ACE8(void *dst, const void *src);
extern void ts4_assign_counted_8820AB10(void *dst, void *src);

CW8C_INL void cw8_vec_assign(Cw8ElemVec *dv, Cw8ElemVec *sv)
{
    Cw8Elem *dst;
    Cw8Elem *src;
    u32 n;
    ts4_v2c_resize_8820B1A0(dv, sv->count);
    n = sv->count;
    src = sv->data;
    dst = dv->data;
    while (n != 0) {
        Cw8Elem *d = dst;
        n--;
        dst++;
        ts4_if_call_seq_u32_off0_8819B0C8(d, src);
        d->words = src->words;
        ts4_prvec_assign_8820ACE8(d->sub, src->sub);
        src++;
    }
}

/* 0x881D8D78: assignment operator of the record: copies strings, element array, scalar fields, re-attaches the owned object */
void ts4_assign_record_881D8D78(Cw8AssignObj *self, Cw8AssignObj *o)
{
    Cw8Owned *ow;
    ts4_if_call_seq_u32_off0_8819B0C8(&self->str, &o->str);
    self->f22 = o->f22;
    cw8_vec_assign(&self->vec, &o->vec);
    self->f38 = o->f38;
    self->f3c = o->f3c;
    self->f3d = o->f3d;
    self->f40 = o->f40;
    self->f6c = o->f6c;
    self->words44 = o->words44;
    self->f64 = o->f64;
    self->f5c = o->f5c;
    self->f70 = o->f70;
    self->f74 = o->f74;
    self->f78 = o->f78;
    self->f7c = o->f7c;
    self->f80 = o->f80;
    ow = o->owned;
    if ((long)ow != 0) {
        ts4_assign_counted_8820AB10(&self->owned, ow->vt->clone(ow));
        self->owned->vt->attach(self->owned, self);
    }
}

/* 0x881E2DA0: drop the reference held by each of n string handles */
void ts4_str_release_each_881E2DA0(char **p, u32 n)
{
    while (n != 0) {
        char **cur = p;
        n--;
        p++;
        ts4_str_release(*cur);
    }
}

typedef struct Cw8Singleton { u32 f0, f4, f8, fc, f10; void *f14; } Cw8Singleton;
typedef struct Cw8AllocArgs { u32 size; u32 flags; } Cw8AllocArgs;
extern Cw8Singleton *lbl_88D41F98;
extern void *lbl_88D41FC0;
extern char lbl_880C1320[];
extern void *fn_88198CE0(void *p);
extern void *ts4_dispatch2_88199068(u32 zero, u32 size, Cw8AllocArgs *args);
extern void fn_881DAA70(void *obj, u32 n);
extern void fn_881DAC88(void *obj);
extern void *fn_881DAFA8(void *obj, const char *s, u32 n);

typedef struct Cw8HNode { u32 pad0; u32 pad4; u32 chain; u32 hash; } Cw8HNode;
typedef struct Cw8HTable {
    u8 pad0[0x14];
    Cw8HNode **buckets;
    u32 count;
    u32 pad1c;
    u32 pad20[3];
    u32 f2c;
    u32 pad30;
    u32 f34;
} Cw8HTable;
extern void fn_881C5AA8(Cw8HTable *t, u32 n, u32 flag);
extern Cw8HNode *fn_8818F1D8(Cw8HTable *t);
extern void *fn_8818EB10(void *node, const void *key);
extern u32 fn_881F0388(Cw8HTable *t);
extern void ts4_hashtable_rehash_881EFE08(Cw8HTable *t, u32 n);

/* 0x881EE128: find the entry for key in the hash table, creating and linking a new node when absent; returns the value part */
void *ts4_htable_find_or_add_881EE128(Cw8HTable *t, const void *key)
{
    struct { u32 hash; u32 bucket; u32 extra; } o;
    Cw8HNode *n = (Cw8HNode *)ts4_string_table_find_881FBA58(t, (void *)key, &o.bucket, &o.hash, &o.extra);
    if (n == 0) {
        u32 off;
        if (t->buckets == 0)
            fn_881C5AA8(t, t->pad1c, 1);
        n = fn_8818F1D8(t);
        if (n != 0) {
            fn_8818EB10(n, key);
            n->hash = o.hash;
        }
        off = o.bucket * 4;
        t->count = t->count + 1;
        n->chain = *(u32 *)(off + (char *)t->buckets);
        *(Cw8HNode **)((char *)t->buckets + off) = n;
        if (t->count > t->f2c && t->f34 == 0)
            ts4_hashtable_rehash_881EFE08(t, fn_881F0388(t));
    }
    return (char *)n + 4;
}

typedef struct Cw8InlineVec { u8 pad0[0x28]; void *data; u32 count; u32 cap; } Cw8InlineVec;
extern void *fn_88562DC0(void *dst, const void *src, u32 n);

/* 0x881E2ED0: ensure room for n words by moving the external data into the inline buffer at the start of the object */
void ts4_inline_vec_reserve_881E2ED0(Cw8InlineVec *v, u32 n)
{
    u32 cap = v->cap;
    if (n > cap) {
        void *src = v->data;
        if (src != 0) {
            u32 count = v->count;
            u32 step = count >> 3;
            u32 newcap;
            if (step < 4)
                step = 4;
            else if (step > 0x400)
                step = 0x400;
            newcap = v->cap + step;
            if (n < newcap)
                n = newcap;
            fn_88562DC0(v, src, count << 2);
        }
        v->cap = n;
        v->data = v;
    }
}
