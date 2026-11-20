/* CX47 part a: Pam Display renderer small helpers (0x88740000-0x88760000), plain route. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;
#ifdef _MSC_VER
#define CX47_INL static __forceinline
#else
#define CX47_INL static inline
#endif
#define W(p, o) (*(u32 *)((char *)(p) + (o)))
#define B(p, o) (*(u8 *)((char *)(p) + (o)))

void ts4_dtor_887538D0(char *self);
void ts4_dtor_887539B8(char *self);
char *ts4_ctor_88753A58(char *self);
extern char *lbl_88D45AD4;
typedef struct { u32 a, b; } Cx47PT;
typedef struct Cx47Pkt { u8 p0[0x68]; u32 prim; u32 p1; u32 cnt; u8 p2[8]; u8 idx; } Cx47Pkt;
extern Cx47PT lbl_880D1A00[];
extern void fn_882938A0(u32 dev, u32 prim, u32 a, u32 b, u32 n);
extern void fn_88293488(u32 dev, u32 prim, u32 n);
/* 0x8874EA60: draw a packet: plain or indexed, primitive count from the table */
void ts4_draw_packet_8874EA60(Cx47Pkt *p)
{
    u32 dev = *(u32 *)(lbl_88D45AD4 + 0x15720);
    if (p->idx == 1)
        fn_882938A0(dev, p->prim, 0, 0, lbl_880D1A00[p->prim].a * p->cnt + lbl_880D1A00[p->prim].b);
    else
        fn_88293488(dev, p->prim, lbl_880D1A00[p->prim].a * p->cnt + lbl_880D1A00[p->prim].b);
}

extern void fn_88221008(void *);
extern void fn_88750AD8(void *);
extern void ts4_tsu_cleanup_end(void *);
/* 0x88753388: release and delete the three objects at +0x34 */
void ts4_release_three_88753388(char *self)
{
    char *p;
    int i;
    if (B(self, 0x10) == 0 && B(self, 0xd) == 0) fn_88221008(self);
    p = self + 0x34;
    for (i = 3; i != 0; i--) {
        void *o = *(void **)p;
        if (o != 0) {
            fn_88750AD8(o);
            ts4_tsu_cleanup_end(o);
            *(u32 *)p = 0;
        }
        p += 4;
    }
}

extern void fn_887569C8(void *, void *);
/* 0x8875A070: walk a tree: children at +0x10/+0x14 recursively, entries at +0x1c/+0x20 */
void ts4_walk_8875A070(void *self, char *node, int a)
{
    if (node != 0) {
        void **p = *(void ***)(node + 0x10);
        void **e = *(void ***)(node + 0x14);
        for (; p != e; p++) ts4_walk_8875A070(self, *p, a);
        p = *(void ***)(node + 0x1c);
        e = *(void ***)(node + 0x20);
        for (; p != e; p++) fn_887569C8(self, *p);
    }
}

extern void *lbl_88D45B38;
extern void ts4_if_call_seq_fn_881F04B8_886131F0(void *g, void *node, u32 a);
extern void fn_885651F8(void *node);
extern void ts4_destroy_owned_object(void *p);
extern char lbl_880D19F0[];
extern char lbl_880F2284[];
extern char lbl_880D1F0C[];

/* 0x887539B8: free the block at +0x157d4, reset the table pointer, destroy two owned objects, finish through 0x887538D0 */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_dtor_887539B8(char *self)
{
    char *m = self + 0x157d4;
    void *n = *(void **)m;
    if (n != 0) {
        if (lbl_88D45B38 != 0) ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, n, W(m, 8));
        else fn_885651F8(n);
    }
    *(char **)(self + 0x157b4) = lbl_880D19F0;
    ts4_destroy_owned_object(*(void **)(self + 0x15720));
    ts4_destroy_owned_object(*(void **)(self + 0x15714));
    ts4_dtor_887538D0(self);
}

/* 0x88756848: set the table pointer, free the block at +0x1580c, then destroy the base at +0x10 */
void ts4_dtor_88756848(char *self)
{
    char *m = self + 0x1580c;
    void *n;
    *(char **)self = lbl_880F2284;
    n = *(void **)m;
    if (n != 0) {
        if (lbl_88D45B38 != 0) ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, n, W(m, 8));
        else fn_885651F8(n);
    }
    ts4_dtor_887539B8(self + 0x10);
}

extern void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(u32 *p);
extern void *fn_88753628(void *);
extern void fn_8816D1A8(void *);
extern void fn_8825D390(void *, u32);
extern void RtlInitializeCriticalSection(void *);

/* 0x88753A58 */
#ifdef _MSC_VER
__declspec(noinline)
#endif
char *ts4_ctor_88753A58(char *self)
{
    u32 tmp;
    u32 *m;
    fn_88753628(self);
    fn_8816D1A8(self + 0x15714);
    fn_8816D1A8(self + 0x15720);
    *(char **)(self + 0x157b4) = lbl_880D1F0C;
    m = (u32 *)(self + 0x157d4);
    tmp = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&tmp);
    m[0] = 0;
    m[1] = 0;
    m[2] = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(m + 2);
    m[3] = 0;
    B(self, 0x8c) = 0;
    fn_8825D390(self + 0x15714, 0x104);
    fn_8825D390(self + 0x15720, 0x104);
    return self;
}

/* 0x887568C0 */
char *ts4_ctor_887568C0(char *self)
{
    u32 tmp;
    u32 *m;
    ts4_ctor_88753A58(self + 0x10);
    *(char **)self = lbl_880F2284;
    tmp = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&tmp);
    m = (u32 *)(self + 0x1580c);
    m[0] = 0;
    m[1] = 0;
    m[2] = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(m + 2);
    m[3] = 0;
    RtlInitializeCriticalSection(self + 0x157c8);
    B(self, 0x15809) = 0;
    B(self, 0x1580a) = 0;
    B(self, 0x1580b) = 0;
    return self;
}

extern void *fn_88562DC0(void *dst, const void *src, u32 n);
extern u32 fn_8823E898(u32 a, u32 b, u32 c);
extern void ts4_release_ids_8874B9B8(void *self);
typedef struct Cx47PV { void **first; void **last; } Cx47PV;
CX47_INL void **cx47_mv(void **first, void **last, void **dst)
{
    if (first == last) return dst;
    {
        u32 n = (u32)((char *)last - (char *)first);
        return (void **)((char *)fn_88562DC0(dst, first, n) + n);
    }
}
typedef struct Cx47Pair { u32 a, b; } Cx47Pair;
CX47_INL void cx47_upd(Cx47Pair *m) { m->b = fn_8823E898(m->b, m->b, m->a); }

/* 0x887514B8: refresh the pair at +0x80, delete every object of the vector at +0x94, clear it, release ids */
void ts4_release_ptrs_887514B8(char *self)
{
    Cx47PV *v;
    void **p;
    cx47_upd((Cx47Pair *)(self + 0x80));
    v = (Cx47PV *)(self + 0x94);
    for (p = v->first; p != *(void ***)(self + 0x98); p++) {
        if (*p != 0) ts4_tsu_cleanup_end(*p);
    }
    v->last = cx47_mv(v->last, v->last, v->first);
    ts4_release_ids_8874B9B8(self);
}

extern char *lbl_88D45A4C;
extern void fn_88756638(void *, u32);
typedef struct Cx47Obj { void **vt; } Cx47Obj;
typedef void (*Cx47VFn)(void *);
/* 0x88758DA8: under the renderer lock, call 0x88756638 and slot 2 of every flagged object of the vector */
void ts4_end_frame_objs_88758DA8(char *self)
{
    Cx47Obj *lk = (Cx47Obj *)(lbl_88D45A4C + 0x154);
    void **p;
    void **e;
    ((Cx47VFn)lk->vt[1])(lk);
    fn_88756638(self + 0x30, 6);
    p = *(void ***)self;
    e = *(void ***)(self + 4);
    if (e != p) {
        do {
            char *o = (char *)*p;
            if (B(o, 8) != 0) ((Cx47VFn)(*(void ***)o)[2])(o);
            p++;
        } while (p != e);
    }
    ((Cx47VFn)lk->vt[2])(lk);
}

extern u32 fn_88233B30(u32 a, u32 b, u32 c);
CX47_INL void cx47_upd2(Cx47Pair *m) { m->b = fn_88233B30(m->b, m->b, m->a); }
extern void ts4_if_call_seq_u32_off8_88280958(void *);
extern void ts4_if_call_seq_u32_off8_8825E668(void *);
extern void ts4_if_call_seq_fn_88280958_882803B8(void *);
extern void ts4_if_call_seq_fn_8825E668_8825E6C8(void *);
extern void fn_88220468(void *);
extern void fn_88220228(void *);
/* 0x8875C050 */
void ts4_dtor_8875C050(char *self)
{
    char *a, *b;
    cx47_upd2((Cx47Pair *)(self + 0xb0));
    a = self + 0x18e0;
    ts4_if_call_seq_u32_off8_88280958(a);
    b = self + 0x18d0;
    ts4_if_call_seq_u32_off8_8825E668(b);
    ts4_if_call_seq_fn_88280958_882803B8(a);
    ts4_if_call_seq_fn_8825E668_8825E6C8(b);
    fn_88220468(self + 0x74);
    fn_88220228(self + 0x40);
    fn_88220228(self + 0xc);
}

extern void ts4_vec32_move_tail_8821FBC8(void *);
#define FREEBLK(m) \
    do { \
        void *n = *(void **)(m); \
        if (n != 0) { \
            if (g != 0) { \
                ts4_if_call_seq_fn_881F04B8_886131F0(g, n, W(m, 8)); \
                g = lbl_88D45B38; \
            } else { \
                fn_885651F8(n); \
            } \
        } \
    } while (0)
/* 0x88744B98: trim three 32-byte-element vectors, then free their blocks through the pool */
void ts4_dtor_88744B98(char *self)
{
    char *m1, *m2, *m3;
    void *g;
    m1 = self + 0x1bc;
    ts4_vec32_move_tail_8821FBC8(m1);
    m2 = self + 0x1cc;
    ts4_vec32_move_tail_8821FBC8(m2);
    m3 = self + 0x1dc;
    ts4_vec32_move_tail_8821FBC8(m3);
    {
        void *n = *(void **)(self + 0x1dc);
        g = lbl_88D45B38;
        if (n != 0) {
            if (g != 0) {
                ts4_if_call_seq_fn_881F04B8_886131F0(g, n, W(m3, 8));
                g = lbl_88D45B38;
            } else {
                fn_885651F8(n);
            }
        }
    }
    FREEBLK(m2);
    FREEBLK(m1);
}
extern char lbl_880F20EC[];

extern u32 *fn_88613570(u32 owner, u32 size, u32 align, void *cap_ptr);
extern void fn_882342F0(u32 *first, u32 *last, u32 *dst);
extern void ts4_loop_call_seq_u32_off4_88229AF0(void *v);
typedef struct Cx47PV4 { u32 *first; u32 *last; u32 pool; u32 *cap; } Cx47PV4;
/* 0x8875D840: pointer vector with a fixed 0x4e20-entry reserve */
Cx47PV4 *ts4_ctor_8875D840(Cx47PV4 *self)
{
    u32 tmp = 0;
    volatile Cx47PV4 *vs = self;
    u32 *c, *f;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&tmp);
    vs->first = 0;
    vs->last = 0;
    vs->pool = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&self->pool);
    vs->cap = 0;
    c = vs->cap;
    f = vs->first;
    if ((u32)(c - f) < 0x4e20) {
        u32 *last = self->last;
        u32 *first = f;
        int n = last - first;
        u32 *p;
        if (first != 0) {
            p = fn_88613570(self->pool, 0x13880, 4, &self->pool);
            fn_882342F0(first, last, p);
            ts4_loop_call_seq_u32_off4_88229AF0(self);
        } else {
            p = fn_88613570(self->pool, 0x13880, 4, &self->pool);
        }
        self->first = p;
        self->last = p + n;
        self->cap = p + 0x4e20;
    }
    return self;
}

extern void fn_8825C848(void *);
extern void fn_8825C9F8(void *, u32);
extern void fn_8822C1C8(void *, u32);
extern void fn_8825CB20(void *, u32);
extern char lbl_880F3428[];
extern char lbl_880F342C[];
CX47_INL void cx47_ia(char *t)
{
    char *m;
    W(t, 0) = (u32)(unsigned long)lbl_880F3428;
    W(t, 8) = 0;
    m = t + 0xc;
    fn_8825C848(m);
    W(t, 0x44) = 0;
    *(u64 *)(t + 0x40) = 0;
    W(t, 0x3c) = 0;
    fn_8825C9F8(m + 0x20, 0x30);
    fn_8822C1C8(m + 0x10, 0x30);
    fn_8825CB20(m, 0x30);
}
CX47_INL void cx47_ib(char *t)
{
    char *m;
    W(t, 0) = (u32)(unsigned long)lbl_880F342C;
    W(t, 4) = 0;
    m = t + 8;
    fn_8825C848(m);
    W(t, 0x38) = 0;
    fn_8825C9F8(m + 0x20, 0x30);
    fn_8822C1C8(m + 0x10, 0x30);
    fn_8825CB20(m, 0x30);
}
/* 0x88747F68: two sub-objects at +8 and +0x50, then a few fields */
char *ts4_ctor_88747F68(char *self)
{
    W(self, 0) = 0;
    cx47_ia(self + 8);
    cx47_ib(self + 0x50);
    W(self, 0x8c) = 0;
    W(self, 0x94) = 0;
    *(volatile u32 *)(self + 0x90) = 0xfffff;
    *(volatile u8 *)(self + 0x98) = 0;
    return self;
}

extern void *fn_8857B6D8(u32, u32, u32, u32);
extern void fn_8822AA10(void *);
extern void *ts4_if_call_seq_fn_88883CD0_8860D250(void *);
extern void *ts4_loop_call_seq_fn_88563230_88884B20(void *fn, void *a, void *b, u32 c);
extern void fn_8857B598(void *, u32);
extern void ts4_resume_thread(void *);
extern void ts4_if_call_seq_NtSetEvent_8857C1F8(void *);
extern char lbl_880F0248[];
extern void fn_8872A9B8(void);
extern void *lbl_88D45A74;
extern void *lbl_88D42940;
extern void *lbl_88D41FDC;
/* 0x88746100: loader singleton: two events, then a started worker thread */
char *ts4_ctor_88746100(char *self)
{
    u32 tmp = 0;
    void *t;
    void *o;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&tmp);
    W(self, 0) = 0;
    W(self, 4) = 0;
    W(self, 8) = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0((u32 *)(self + 8));
    W(self, 0xc) = 0;
    lbl_88D45A74 = self;
    lbl_88D42940 = fn_8857B6D8(0, 0, 0, 0);
    lbl_88D41FDC = fn_8857B6D8(0, 0, 0, 0);
    fn_8822AA10(self);
    o = ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38);
    tmp = 0;
    W(self, 0x10) = *(volatile u32 *)&tmp;
    t = ts4_loop_call_seq_fn_88563230_88884B20((void *)fn_8872A9B8, o, lbl_880F0248, 0x20000);
    W(self, 0x14) = (u32)(unsigned long)t;
    fn_8857B598(t, 1);
    ts4_resume_thread(t);
    ts4_if_call_seq_NtSetEvent_8857C1F8(lbl_88D42940);
    return self;
}

extern void ts4_if_call_seq_fn_8825D1A8_8825D208(void *);
extern void ts4_if_call_seq_u32_off0_8825D318(void *);
extern void fn_8873EFC0(void *);
extern void ts4_if_call_seq_fn_8821FD70_88721100(void *);
extern void ts4_if_call_seq_ts4_object_finalize_8872B458(void *);
CX47_INL void cx47_blk(char *m)
{
    void *n = *(void **)m;
    if (n != 0) {
        void *g = lbl_88D45B38;
        if (g != 0) ts4_if_call_seq_fn_881F04B8_886131F0(g, n, W(m, 8));
        else fn_885651F8(n);
    }
}
/* 0x887538D0: free two pool blocks, destroy two owned objects, tear down the members */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_dtor_887538D0(char *self)
{
    char *t;
    cx47_blk(self + 0x15640);
    ts4_destroy_owned_object(*(void **)(self + 0x15608));
    cx47_blk(self + 0x155f8);
    ts4_if_call_seq_fn_8825D1A8_8825D208(self + 0x155e0);
    ts4_if_call_seq_u32_off0_8825D318(self + 0x1d44);
    ts4_destroy_owned_object(*(void **)(self + 0x1d38));
    t = self + 0xdc;
    fn_8873EFC0(t + 0x64);
    ts4_if_call_seq_fn_8821FD70_88721100(t + 4);
    ts4_if_call_seq_ts4_object_finalize_8872B458(self + 0x64);
}

extern void ts4_small_string256_ctor_88163B90(void *p);
extern void *ts4_small_string256_from_cstr_881A5020(void *self, const char *text);
extern void ts4_byte_string_assign_8816D090(void *dst, void *src);
extern char lbl_880F20EC[];
extern char lbl_880C1320[];
typedef struct Cx47Str { char b[0x110]; } Cx47Str;
CX47_INL void cx47_sv(char *m)
{
    u32 tmp = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&tmp);
    W(m, 0) = 0;
    W(m, 4) = 0;
    W(m, 8) = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0((u32 *)(m + 8));
    W(m, 0xc) = 0;
}
/* 0x88746018: string at +4, three pooled vectors, flags, then the default name */
char *ts4_ctor_88746018(char *self)
{
    Cx47Str s;
    *(char **)self = lbl_880F20EC;
    ts4_small_string256_ctor_88163B90(self + 4);
    W(self, 0x118) = 0;
    cx47_sv(self + 0x11c);
    cx47_sv(self + 0x12c);
    cx47_sv(self + 0x13c);
    B(self, 0x114) = 0;
    W(self, 0x110) = 0;
    B(self, 0x115) = 1;
    B(self, 0x116) = 0;
    ts4_small_string256_from_cstr_881A5020(&s, lbl_880C1320);
    ts4_byte_string_assign_8816D090(self + 4, &s);
    W(self, 0x118) = 0;
    return self;
}
