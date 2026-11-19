/* CW40 part a: small UI/script helpers in 0x887D0000-0x88800000. */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Cx40Vt { void *s[64]; } Cx40Vt;
typedef struct Cx40Obj { void **vt; } Cx40Obj;

/* vtable views used by the single-expression calls below */
typedef struct Cx40VtKey { void *s[13]; void (*s34)(void *, void *); void *s38[2]; void (*s40)(void *, void *); } Cx40VtKey;
typedef struct Cx40KeyObj { Cx40VtKey *vt; } Cx40KeyObj;

extern void *fn_887F0CA0(void *, void *);
extern char lbl_88C6C014[];

/* 0x887F0E88: look up an entry by hash key and pass it to vtable slot 0x34. */
void ts4_dispatch_by_key_887F0E88(Cx40KeyObj *self)
{
    u32 key = 0xBA46B5E8u;
    self->vt->s34(self, fn_887F0CA0(self, &key));
}

/* 0x887F1A30: look up the entry for a global key and pass it to vtable slot 0x40. */
void ts4_dispatch_by_global_887F1A30(Cx40KeyObj *self)
{
    self->vt->s40(self, fn_887F0CA0(self, lbl_88C6C014));
}

typedef struct Cx40Vt28 { void *s[10]; u8 (*s28)(void *, void *, void *, void *); } Cx40Vt28;
typedef struct Cx40Obj28 { Cx40Vt28 *vt; } Cx40Obj28;

/* 0x887E99D8: forward an argument block to slot 0x28 of the object at +0x24; 0 when it returns 1, else 2. */
u32 ts4_forward_args_887E99D8(char *self, char *a)
{
    Cx40Obj28 *o = *(Cx40Obj28 **)(self + 0x24);
    u32 r = 2;
    if (o->vt->s28(o, *(void **)(a + 8), a + 0x10, *(void **)(a + 0x14)) == 1) r = 0;
    return r;
}

extern void fn_887EA898(void *, void *);
/* 0x887EB598: run fn_887EA898 between slot 1 and slot 2 of the guard at +8 of the object at +0x1c. */
int ts4_guarded_apply_887EB598(char *self, char *a)
{
    Cx40Obj *sub = (Cx40Obj *)(*(char **)(self + 0x1c) + 8);
    ((void (*)(void *))sub->vt[1])(sub);
    fn_887EA898(*(void **)(self + 0x20), *(void **)(a + 0x10));
    ((void (*)(void *))sub->vt[2])(sub);
    return 0;
}

extern void ts4_if_call_seq_u32_off0_887D3C88(void *, void *);
extern void *fn_887D02A8(void *, int, int, int, int, int);
/* 0x887D75A0: stamp the notify hash at +0x100, set both flags, run the base init. */
void *ts4_tsu_notify_object(char *self)
{
    *(u32 *)(self + 0x100) = 0xEBFC4526u;
    ts4_if_call_seq_u32_off0_887D3C88(self, self + 0x100);
    self[0x60] = 1;
    self[0x2cc] = 1;
    return fn_887D02A8(self, 0, 0, 0, 0, 0);
}

extern u32 fn_8857B6D8(u32, u32, u32, u32);
typedef struct Cx40B { u8 a, b; u8 pad[2]; u32 c, d; } Cx40B;
/* 0x887EA830: init a small record; mode 1 allocates the handle at +8. */
Cx40B *ts4_init_mode_record_887EA830(Cx40B *self, u8 m)
{
    self->b = m;
    self->a = 0;
    self->c = 0;
    self->d = 0;
    if (m == 1) self->d = fn_8857B6D8(0, 0, 0, 0);
    return self;
}

typedef struct Cx40PVv { u32 *first, *last, *cap; } Cx40PVv;
extern void ts4_vector_grow_append_scalar4_88174A38(Cx40PVv *, u32 *, u32 *);
/* 0x887F81B0: push one u32 onto the vector at +0x3c. */
void ts4_u32_vec_push_887F81B0(char *self, u32 val)
{
    Cx40PVv *v = (Cx40PVv *)(self + 0x3c);
    u32 *last = v->last;
    if (last != v->cap) {
        if (last) *last = val;
        v->last++;
    } else {
        ts4_vector_grow_append_scalar4_88174A38(v, last, &val);
    }
}

typedef struct Cx40Vt8 { void *s[2]; void (*s8)(void *); } Cx40Vt8;
typedef struct Cx40Obj8 { Cx40Vt8 *vt; char pad[4]; u8 b8; } Cx40Obj8;
extern void ts4_mgr_update_active_slots_887D98D0(void *);
extern void fn_887D7FB0(void *);
/* 0x887D9970: when active, run slot 2 on the three sub-objects (the one at +0xe0 with its flag raised), refresh slots. */
void ts4_mgr_refresh_887D9970(char *self, u8 flag)
{
    if (self[0x9d] != 0) {
        Cx40Obj8 *o = *(Cx40Obj8 **)(self + 0xe0);
        u8 saved = o->b8;
        Cx40Obj8 *q;
        o->b8 = 1;
        q = *(Cx40Obj8 **)(self + 0xe0);
        q->vt->s8(q);
        (*(Cx40Obj8 **)(self + 0xe0))->b8 = saved;
        q = *(Cx40Obj8 **)(self + 0xd0);
        q->vt->s8(q);
        q = *(Cx40Obj8 **)(self + 0xe4);
        q->vt->s8(q);
        if (flag != 0) ts4_mgr_update_active_slots_887D98D0(self);
        fn_887D7FB0(self);
    }
}

extern void fn_888DC7F8(void *, int, u32, u32, int);
/* 0x887DB548: apply slot idx (or all four when idx == -1) of the table at +0xa8+0x1c0 if its flag byte is set. */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_slot_apply_887DB548(char *self, u32 flag, int idx)
{
    if (idx == -1) {
        int i = 0;
        do {
            ts4_slot_apply_887DB548(self, flag, i);
            i++;
        } while (i < 4);
    } else {
        char *t = *(char **)(self + 0xa8) + 0x1c0;
        char *e = t + (idx * 0xb4 + *(int *)t);
        if (e[0x75] != 0) {
            u32 a;
            if ((u8)flag != 0) a = *(u32 *)(self + 0x64);
            else a = 0;
            fn_888DC7F8(*(void **)(self + 0xac), idx, flag, a, -1);
        }
    }
}

/* self-relative table header: first word is the byte offset of the entries, second is the count (-1 offset = empty) */
typedef struct Cx40Tb { int off; u32 cnt; } Cx40Tb;
#ifdef _MSC_VER
#define CX40_INL static __forceinline
#else
#define CX40_INL static inline
#endif
CX40_INL char *cx40_tb_begin(volatile Cx40Tb *t) { char *r = 0; int off = t->off; if (off != -1) r = (char *)t + off; return r; }
CX40_INL char *cx40_tb_end(volatile Cx40Tb *t) { char *r = 0; int off = t->off; if (off != -1) r = (char *)t + (t->cnt * 0xb4 + off); return r; }
/* 0x887D0468: clear the slot flags and four per-entry words of every 0xb4-byte entry in the table. */
void ts4_slots_reset_887D0468(char *self)
{
    char *h = *(char **)(self + 0xa8);
    char *p, *e;
    volatile Cx40Tb *t;
    *(u32 *)(h + 0x204) = 0;
    t = (volatile Cx40Tb *)(*(char **)(self + 0xa8) + 0x1c0);
    self[0x124] = 0;
    self[0x125] = 0;
    *(u32 *)(self + 0x324) = 0;
    p = cx40_tb_begin(t);
    e = cx40_tb_end(t);
    if (p != e) {
        char *q = p + 0x48;
        do {
            *(u32 *)(q + 0x54) = 0;
            *(u32 *)(q - 4) = 0;
            *(u32 *)q = 0;
            *(u32 *)(q - 0xc) = 0;
            q += 0xb4;
        } while (q - 0x48 != e);
    }
}
