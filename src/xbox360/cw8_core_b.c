/* CW8 part b: container helpers, constructors, destructors. Built with /Oc. */
#include "fam4_refstr.h"
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
typedef unsigned int cw8_uptr;
#else
typedef unsigned long cw8_uptr;
#endif

typedef struct Cw8Vt { void *s[4]; void *(*get)(void *); } Cw8Vt;
typedef struct Cw8Svc { const Cw8Vt *vt; } Cw8Svc;
typedef struct Cw8Quad { u32 a, b, c, d; } Cw8Quad;

typedef struct Cw8Obj88 {
    const void *vt;
    u32 pad4[2];
    void *service_data;
    u32 f10;
    u32 pad14[4];
    u32 f24, f28, f2c, f30, f34;
    u32 pad38[2];
    Cw8Quad quad;
} Cw8Obj88;

extern void fn_881F7958(void *self);
extern Cw8Svc *fn_881519D0(void);
extern char lbl_880E8130[];
extern char lbl_880E8168[];
extern Cw8Quad lbl_88C6BBA0;

/* 0x881D4788: constructor: base init, bind service data, clear fields, copy a 16-byte default */
Cw8Obj88 *ts4_obj88_ctor_881D4788(Cw8Obj88 *self)
{
    Cw8Svc *svc;
    volatile Cw8Obj88 *v = self;
    fn_881F7958(self);
    v->vt = lbl_880E8130;
    svc = fn_881519D0();
    v->service_data = (char *)svc->vt->get(svc) + 0x10;
    v->vt = lbl_880E8168;
    v->f10 = 0;
    self->f24 = 0;
    self->f28 = 0;
    self->f2c = 0;
    self->f30 = 0;
    self->quad = lbl_88C6BBA0;
    self->f34 = 0;
    return self;
}

typedef struct Cw8U32Vec { u32 pad0; u32 *data; u32 count; } Cw8U32Vec;
extern void ts4_pv_reserve_881F25F0(Cw8U32Vec *v, u32 needed);

/* 0x881E21F0: append one u32 to the vector (reserving first); returns the old count */
u32 ts4_u32vec_push_back_881E21F0(Cw8U32Vec *v, const u32 *value)
{
    u32 *slot;
    ts4_pv_reserve_881F25F0(v, v->count + 1);
    slot = v->data + v->count;
    if (slot != 0) {
        *slot = *value;
    }
    return v->count++;
}

typedef struct Cw8StrList { u8 pad0[0x28]; char ***data; u32 count; } Cw8StrList;
extern void ts4_inline_vec_reserve_881E2ED0(Cw8StrList *v, u32 needed);
extern u32 lbl_88D3E414;
u32 fn_8819A9D8(void);
char **fn_8819C090(char **, char **, u32);

/* 0x881E2D20: append a copy of a string to the list (reserving first); returns the old count */
u32 ts4_strlist_push_back_881E2D20(Cw8StrList *list, char **str)
{
    char **slot;
    ts4_inline_vec_reserve_881E2ED0(list, list->count + 1);
    slot = (char **)(list->data + list->count);
    if (slot != 0) {
        int owner = ((int *)*str)[-4];
        if (owner == 0) {
            owner = lbl_88D3E414;
            if ((u32)owner == 0) owner = fn_8819A9D8();
        }
        fn_8819C090(slot, str, owner);
    }
    return list->count++;
}

typedef struct Cw8Seq Cw8Seq;
typedef struct Cw8SeqVt { void *s[3]; u32 (*step)(void *, u32, u32); void *s2[0x74 / 4 - 4]; void (*seek)(Cw8Seq *, u32); } Cw8SeqVt;
typedef struct Cw8SeqSrcVt { void *s[3]; u32 (*step)(void *, u32, u32); } Cw8SeqSrcVt;
typedef struct Cw8SeqSrc { const Cw8SeqSrcVt *vt; } Cw8SeqSrc;
struct Cw8Seq {
    const Cw8SeqVt *vt;
    u8 pad4[0x20];
    Cw8SeqSrc *src;
    u8 pad28[0x3c];
    u32 pos;
};

/* 0x881D7A10: step the source; on success rewind to position 0 when the position is the -1 sentinel */
u32 ts4_seq_step_881D7A10(Cw8Seq *self, u32 arg)
{
    u32 ok = self->src->vt->step(self->src, arg, (u32)-1);
    if ((u8)ok != 0) {
        u32 pos = self->pos;
        if (pos >= (u32)-1) {
            self->vt->seek(self, pos + 1);
        }
    }
    return ok;
}

typedef struct Cw8RawVec { u32 begin; void *data; u32 count; u32 cap; } Cw8RawVec;
typedef struct Cw8TripleVec { u8 pad0[0xc]; Cw8RawVec a; Cw8RawVec b; Cw8RawVec c; } Cw8TripleVec;
extern void fn_881F26C0(void *data, u32 count);
extern void fn_881992A8(u32 zero, void *ptr);

/* 0x881D93B0: destroy the three owned vectors (the first runs element destructors) and report success */
u32 ts4_triple_vec_clear_881D93B0(Cw8TripleVec *self)
{
    Cw8RawVec *v = &self->a;
    Cw8RawVec *w;
    u32 zero = 0;
    if (v->data != 0) {
        fn_881F26C0(v->data, v->count);
        if (v->data != 0) {
            fn_881992A8(0, v->data);
        }
        v->data = (void *)(cw8_uptr)zero;
    }
    v->count = zero;
    w = &self->b;
    v->cap = zero;
    v->begin = zero;
    if (w->data != 0) {
        fn_881992A8(0, w->data);
        w->data = (void *)(cw8_uptr)zero;
    }
    w->count = zero;
    v = &self->c;
    w->begin = zero;
    w->cap = zero;
    if (v->data != 0) {
        fn_881992A8(0, v->data);
        v->data = (void *)(cw8_uptr)zero;
    }
    v->count = zero;
    v->cap = zero;
    v->begin = zero;
    return 1;
}

typedef struct Cw8FreeNode { struct Cw8FreeNode *next; } Cw8FreeNode;
typedef struct Cw8PoolVt { void *s[2]; void (*unlock)(void *); } Cw8PoolVt;
typedef struct Cw8Pool { const Cw8PoolVt *vt; u8 pad4[4]; u8 lock[0x1c]; Cw8FreeNode *free_head; } Cw8Pool;
extern Cw8Pool *fn_8818A290(void);
extern void RtlEnterCriticalSection(void *cs);

/* 0x881E1D70: give every node of a list back to the pool's free list under its lock, then empty the list */
void ts4_free_list_release_881E1D70(Cw8FreeNode **head)
{
    Cw8FreeNode *node = *head;
    if (node != 0) {
        do {
            Cw8FreeNode *cur = node;
            Cw8Pool *pool;
            node = node->next;
            pool = fn_8818A290();
            RtlEnterCriticalSection(pool->lock);
            cur->next = pool->free_head;
            ((volatile Cw8Pool *)pool)->free_head = cur;
            ((volatile Cw8Pool *)pool)->vt->unlock(pool);
        } while (node != 0);
    }
    *head = 0;
}

typedef struct Cw8RefHolder { char *str; u8 pad4[0x18]; Cw8RawVec vec; } Cw8RefHolder;
extern void ts4_str_release_each_8820ADD8(void *data, u32 count);

/* 0x881D7008: destructor: destroy the elements of the vector, free its storage, drop the string reference */
void ts4_ref_holder_dtor_881D7008(Cw8RefHolder *self)
{
    Cw8RawVec *v = &self->vec;
    if (v->data != 0) {
        ts4_str_release_each_8820ADD8(v->data, v->count);
        if (v->data != 0) {
            fn_881992A8(0, v->data);
        }
    }
    ts4_str_release(self->str);
}

typedef struct Cw8Grow { u32 pad0; void *data; u32 count; u32 cap; } Cw8Grow;
extern void *ts4_if_call_seq_u32_off0_8818C588(Cw8Grow *v, u32 bytes);
extern void *fn_88562DC0(void *dst, const void *src, u32 n);

/* 0x881DA2C0: reserve room for n 0x2c-byte elements, growing geometrically (count/8 clamped to 4..0x400) */
void ts4_grow_reserve_2c_881DA2C0(Cw8Grow *v, u32 n)
{
    if (n > v->cap) {
        if (v->data == 0) {
            v->data = ts4_if_call_seq_u32_off0_8818C588(v, n * 0x2c);
            if (v->data == 0)
                return;
            v->cap = n;
        } else {
            u32 step = v->count >> 3;
            u32 newcap;
            void *p;
            if (step < 4)
                step = 4;
            else if (step > 0x400)
                step = 0x400;
            step = v->cap + step;
            newcap = (n < step) ? step : n;
            p = ts4_if_call_seq_u32_off0_8818C588(v, newcap * 0x2c);
            if (p == 0)
                return;
            fn_88562DC0(p, v->data, v->count * 0x2c);
            if (v->data != 0)
                fn_881992A8(0, v->data);
            v->data = p;
            v->cap = newcap;
        }
    }
}

/* 0x881DA390: same for 8-byte elements */
void ts4_grow_reserve_8_881DA390(Cw8Grow *v, u32 n)
{
    if (n > v->cap) {
        if (v->data == 0) {
            v->data = ts4_if_call_seq_u32_off0_8818C588(v, n * 8);
            if (v->data == 0)
                return;
            v->cap = n;
        } else {
            u32 step = v->count >> 3;
            u32 newcap;
            void *p;
            if (step < 4)
                step = 4;
            else if (step > 0x400)
                step = 0x400;
            step = v->cap + step;
            newcap = (n < step) ? step : n;
            p = ts4_if_call_seq_u32_off0_8818C588(v, newcap * 8);
            if (p == 0)
                return;
            fn_88562DC0(p, v->data, v->count * 8);
            if (v->data != 0)
                fn_881992A8(0, v->data);
            v->data = p;
            v->cap = newcap;
        }
    }
}

typedef struct Cw8BitIter { u32 *word; u32 bit; } Cw8BitIter;
extern u8 ts4_pair_differs_881876A0(Cw8BitIter *a, Cw8BitIter *b);

/* 0x881EE580: fill the bit range [it, last) (vector<bool> style iterators) with *value */
void ts4_bit_fill_881EE580(Cw8BitIter *it, Cw8BitIter *last, const u8 *value)
{
    while (ts4_pair_differs_881876A0(it, last) != 0) {
        u32 *word = it->word;
        u8 v = *value;
        u32 mask = (u32)1 << it->bit;
        if (v != 0)
            *word |= mask;
        else
            *word &= ~mask;
        if (it->bit++ == 0x1f) {
            it->bit = 0;
            it->word++;
        }
    }
}
