/* Swing_DLL.xex game core 0x8818C6C0-0x8819C000 (CW29): locked calls, guards, early-out predicates. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
#ifdef _MSC_VER
typedef unsigned int cx_uptr;
#else
typedef unsigned long cx_uptr;
#endif

cx_uptr RtlEnterCriticalSection(cx_uptr);
cx_uptr RtlLeaveCriticalSection(cx_uptr);
cx_uptr RtlInitializeCriticalSection(cx_uptr);
void *ts4_dispatch2_88199068(void *a, u32 size, void *req);
u32 fn_88198CE0(void *);
void fn_881992A8(void *, void *);
struct cx_holder { void *vt; u32 f4; u8 cs[0x1c]; };
extern char lbl_880DCF30[];
extern void *lbl_88D3E3A4;

/* 0x8818DDB8: run fn_8818DE58 under the optional critical section at 0x18; returns whether it succeeded */
struct cx_locked { u8 pad[0x14]; int f14; u8 cs_holder[0x20]; };
u8 fn_8818DE58(void *, u32, u32);
u32 ts4_locked_try_8818DDB8(struct cx_locked *self, u32 a, u32 b)
{
    int f14 = self->f14;
    u8 *sub = self->cs_holder;
    int locked = 0;
    if (f14 == -1) {
        RtlEnterCriticalSection((cx_uptr)(sub + 8));
        locked = 1;
    }
    if (fn_8818DE58(self, a, b) == 0) {
        if (locked != 0 && f14 == -1)
            RtlLeaveCriticalSection((cx_uptr)(sub + 8));
        return 0;
    }
    if (locked != 0 && f14 == -1)
        RtlLeaveCriticalSection((cx_uptr)(sub + 8));
    return 1;
}

/* 0x881987E8: largest free tail among the unflagged blocks of the pool, under the optional lock at 0x98 */
struct cx_blk { u8 pad0[4]; struct cx_blk *next; int size; u8 flags; };
struct cx_pool { u8 pad[0x74]; int lockv; u8 pad78[0xc]; struct cx_blk *head; u8 pad88[0xc]; u32 align; };
int ts4_pool_max_free_tail_881987E8(struct cx_pool *self)
{
    int lockv = self->lockv;
    u8 *cs = (u8 *)self + 0x98;
    int best;
    struct cx_blk *p;
    if (lockv == -1)
        RtlEnterCriticalSection((cx_uptr)(cs + 8));
    p = self->head;
    best = 0;
    while (p != 0) {
        if (((u32)p->flags & ~0x3fu) == 0) {
            u32 al = self->align;
            int v = p->size - (int)(((u32)(cx_uptr)p + al + 15) & (0 - al)) + (int)(cx_uptr)p + 0x10;
            if (v > best)
                best = v;
        }
        p = p->next;
    }
    if (lockv == -1)
        RtlLeaveCriticalSection((cx_uptr)(cs + 8));
    return best;
}

/* 0x881988C8 / 0x88198978: open the named sub-resource of the pool under its optional lock, apply two ops, release it */
struct cx_res { u8 pad[0x74]; int lockv; u8 pad78[8]; void *f80; u8 pad84[8]; u32 f8c; u8 pad90[8]; struct cx_holder h; };
extern char lbl_880D2F18[], lbl_880D2F14[];
void *ts4_tailcall_fn_885655E8_88565748(void *, const void *);
void fn_88565F50(void *, u32, u32, void *);
void ts4_tailcall_fn_885659E8_88565AF8(void *, u32, u32, void *);
void fn_88566FE8(void *);
u32 ts4_pool_apply_881988C8(struct cx_res *self, void *name)
{
    int lockv = self->lockv;
    u8 *cs = (u8 *)self + 0x98;
    void *h;
    if (lockv == -1)
        RtlEnterCriticalSection((cx_uptr)(cs + 8));
    h = ts4_tailcall_fn_885655E8_88565748(name, lbl_880D2F18);
    if (h == 0) {
        if (lockv == -1)
            RtlLeaveCriticalSection((cx_uptr)(cs + 8));
        return 0;
    }
    fn_88565F50(self, 0xc0, 1, h);
    fn_88565F50(self->f80, self->f8c, 1, h);
    fn_88566FE8(h);
    if (lockv == -1)
        RtlLeaveCriticalSection((cx_uptr)(cs + 8));
    return 1;
}

u32 ts4_pool_apply_88198978(struct cx_res *self, void *name)
{
    int lockv = self->lockv;
    u8 *cs = (u8 *)self + 0x98;
    void *h;
    if (lockv == -1)
        RtlEnterCriticalSection((cx_uptr)(cs + 8));
    h = ts4_tailcall_fn_885655E8_88565748(name, lbl_880D2F14);
    if (h == 0) {
        if (lockv == -1)
            RtlLeaveCriticalSection((cx_uptr)(cs + 8));
        return 0;
    }
    ts4_tailcall_fn_885659E8_88565AF8(self, 0xc0, 1, h);
    ts4_tailcall_fn_885659E8_88565AF8(self->f80, self->f8c, 1, h);
    fn_88566FE8(h);
    if (lockv == -1)
        RtlLeaveCriticalSection((cx_uptr)(cs + 8));
    return 1;
}

/* 0x881964A0: run the request through the runner (or the pending-request path when none is set), under the saved state */
extern void *lbl_88D3E3A4;
extern int lbl_88D45978;
u32 fn_88198CE0(void *);
void ts4_if_get_u32_lbl_88D3E3A4_88195DF0(void *out, void *self, u32 a, u32 b, u32 c, void *p, u32 z);
void fn_88194028(void *);
void ts4_if_atomic_interlocked_dec_881876D0(void *);
u32 ts4_runner_exec_88196A60(void *, u32, u32, u32);
struct cx_req { u8 pad[0x1c]; u32 f1c; };
u32 ts4_run_request_881964A0(void **self, u32 a, u32 b, u32 c)
{
    u32 saved = fn_88198CE0(lbl_88D3E3A4);
    int t = lbl_88D45978;
    u32 r;
    if (t == 0) {
        struct cx_req *out;
        int g = t;
        ts4_if_get_u32_lbl_88D3E3A4_88195DF0(&out, self, a, b, c, &g, 0);
        fn_88194028(&out);
        r = out->f1c;
        ts4_if_atomic_interlocked_dec_881876D0(out);
        fn_88198CE0((void *)(cx_uptr)saved);
        return r;
    }
    r = ts4_runner_exec_88196A60(*self, a, b, c);
    fn_88198CE0((void *)(cx_uptr)saved);
    return r;
}

/* 0x8818FDF8: split a string at the first '|' into the text before it and the text after it, under the saved state */
extern void *lbl_88D3E378;
int ts4_if_call_seq_u32_off0_8819B8D0(char **s, int ch, int from);
void ts4_string_unshare_8819B308(char **self);
char **ts4_string_left_8819BE88(char **out, char **src, int n);
char **ts4_string_mid_8819BD70(char **out, char **src, int start, int count);
void ts4_if_call_seq_u32_off0_8819B0C8(char **dst, char **src);
void ts4_call_seq_u32_off0_8819AD80(char **s);
void ts4_string_split_bar_8818FDF8(void *unused, char **src, char **head, char **tail)
{
    u32 saved = fn_88198CE0(lbl_88D3E378);
    int n = ts4_if_call_seq_u32_off0_8819B8D0(src, 0x7c, 0);
    char *tmp;
    (void)unused;
    if (n == -1) {
        ts4_string_unshare_8819B308(head);
        ts4_string_unshare_8819B308(tail);
        fn_88198CE0((void *)(cx_uptr)saved);
        return;
    }
    ts4_if_call_seq_u32_off0_8819B0C8(head, ts4_string_left_8819BE88(&tmp, src, n));
    ts4_call_seq_u32_off0_8819AD80(&tmp);
    {
        int m = n + 1;
        ts4_string_mid_8819BD70(&tmp, src, m, ((int *)*src)[-3] - m);
    }
    ts4_if_call_seq_u32_off0_8819B0C8(tail, &tmp);
    ts4_call_seq_u32_off0_8819AD80(&tmp);
    fn_88198CE0((void *)(cx_uptr)saved);
}

/* 0x88193EE0: scalar-deleting destructor: two sub-object cleanups, one container, four handle holders, base dtor */
struct cx_hsub { void *vt; void *h; };
struct cx_dobj { u8 pad[0x10]; struct cx_hsub s10, s18, s20, s28; u8 pad30[4]; u8 c34[0x90]; u8 cc4[0x20]; u8 ce4[0x20]; };
extern char lbl_880DCF20[];
void fn_881974B0(void *);
void fn_88193C70(void *);
void ts4_if_call_seq_lbl_880DD7F4_881A1E10(void *);
void ts4_tsu_cleanup_end(void *);
void ts4_if_get_u32_lbl_88C32048_8857A1E0(void *);
static void cx_hsub_dtor(struct cx_hsub *s)
{
    s->vt = lbl_880DCF20;
    if (s->h != 0) {
        ts4_if_get_u32_lbl_88C32048_8857A1E0(s->h);
        s->h = 0;
    }
}
void *ts4_dtor_88193EE0(struct cx_dobj *self, u32 flags)
{
    fn_881974B0(self->ce4);
    fn_881974B0(self->cc4);
    fn_88193C70(self->c34);
    cx_hsub_dtor(&self->s28);
    cx_hsub_dtor(&self->s20);
    cx_hsub_dtor(&self->s18);
    cx_hsub_dtor(&self->s10);
    ts4_if_call_seq_lbl_880DD7F4_881A1E10(self);
    if ((flags & 1) != 0)
        ts4_tsu_cleanup_end(self);
    return self;
}

/* 0x88198C50: lazily construct the global lock holder (static-init guard bit 0) and register its destructor */
extern struct cx_holder lbl_88D4AB10;
extern u32 lbl_88D4AB34;
void ts4_holder_destroy_88AFF060(void);
int fn_88563470(void (*fn)(void));
struct cx_holder *ts4_global_holder_88198C50(void)
{
    if ((lbl_88D4AB34 & 1) == 0) {
        lbl_88D4AB34 |= 1;
        lbl_88D4AB10.f4 = 0;
        lbl_88D4AB10.vt = lbl_880DCF30;
        RtlInitializeCriticalSection((cx_uptr)&lbl_88D4AB10.cs);
        fn_88563470(ts4_holder_destroy_88AFF060);
    }
    return &lbl_88D4AB10;
}

/* 0x8818D840: tear the container down under its optional lock and the saved state; always succeeds */
struct cx_inner { u32 f0; void *f4; };
struct cx_td {
    u8 *base; u32 f4; u8 pad8[0xc]; int f14; u8 cs_holder[0x24]; u32 f3c; u8 pad40[0xc]; void *f4c;
};
void fn_8818D920(void *);
void ts4_loop_get_u32_off14_8818E928(void *);
void ts4_if_call_seq_u32_off4_8818EAB8(void *);
void fn_8818ECC0(void *);
void ts4_node_list_run_8818A530(void *);
u32 ts4_container_teardown_8818D840(struct cx_td *self)
{
    int f14 = self->f14;
    u8 *sub = self->cs_holder;
    int locked = 0;
    u32 saved;
    struct cx_inner *in;
    if (f14 == -1) {
        RtlEnterCriticalSection((cx_uptr)(sub + 8));
        locked = 1;
    }
    saved = fn_88198CE0((void *)(cx_uptr)self->f4);
    fn_8818D920(self);
    ts4_loop_get_u32_off14_8818E928(self);
    ts4_if_call_seq_u32_off4_8818EAB8(self->base + 4);
    if (self->f4c != 0)
        fn_881992A8(0, self->f4c);
    self->f4c = 0;
    in = (struct cx_inner *)(self->base + 0x14);
    fn_8818ECC0(in);
    ts4_node_list_run_8818A530(in->f4);
    in->f4 = 0;
    in->f0 = 0;
    ts4_string_unshare_8819B308((char **)self->base);
    if (self->f3c != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((void *)(cx_uptr)self->f3c);
        self->f3c = 0;
    }
    fn_88198CE0((void *)(cx_uptr)saved);
    if (locked != 0 && f14 == -1)
        RtlLeaveCriticalSection((cx_uptr)(sub + 8));
    return 1;
}

/* 0x8819A230 / 0x8819A688: take a block from the size-class slot (16-byte classes) or allocate a large one, under the table lock */
struct cx_lvt { void *s0; void (*lock)(void *); void (*unlock)(void *); };
struct cx_lobj { struct cx_lvt *vt; };
struct cx_blk2 { void *owner; u32 f4; int f8; u32 fc; };
void *fn_8818A3E0(void *);
#define CX_BLOCK_ALLOC(NAME, LOCK_OFF, NCLASS) \
    struct cx_blk2 *NAME(u8 *self, int size, int count) \
    { \
        struct cx_lobj *lock = (struct cx_lobj *)(self + (LOCK_OFF)); \
        u32 saved; \
        u32 idx; \
        struct cx_blk2 *b; \
        u32 zero = 0; \
        lock->vt->lock(lock); \
        saved = fn_88198CE0((void *)(cx_uptr)*(u32 *)(self + 0x1c)); \
        idx = (u32)(size / 16); \
        if (idx < (NCLASS)) { \
            b = (struct cx_blk2 *)fn_8818A3E0(self + idx * 0x38 + 0x20); \
            b->f8 = (int)(idx * 16 + 15); \
        } else { \
            u32 req[2]; \
            req[0] = 1000; \
            req[1] = zero; \
            b = (struct cx_blk2 *)ts4_dispatch2_88199068(0, (size + 1) * count + 0x10, req); \
            if (b == 0) { \
                fn_88198CE0((void *)(cx_uptr)saved); \
                lock->vt->unlock(lock); \
                return 0; \
            } \
            b->f8 = size; \
        } \
        b->owner = self; \
        b->f4 = zero; \
        b->fc = 1; \
        fn_88198CE0((void *)(cx_uptr)saved); \
        lock->vt->unlock(lock); \
        return b; \
    }
CX_BLOCK_ALLOC(ts4_block_alloc_8819A230, 0x720, 0x20)
CX_BLOCK_ALLOC(ts4_block_alloc_8819A688, 0x3a0, 0x10)


/* 0x8818EF90: reserve room for n 0x40-byte elements, growing geometrically (count/8 clamped to 4..0x400) */
struct cx_grow { u32 pad0; void *data; u32 count; u32 cap; };
void *ts4_if_call_seq_u32_off0_8818C588(void *v, u32 bytes);
void *fn_88562DC0(void *dst, const void *src, u32 n);
void ts4_grow_reserve_40_8818EF90(struct cx_grow *v, u32 n)
{
    if (n > v->cap) {
        if (v->data == 0) {
            v->data = ts4_if_call_seq_u32_off0_8818C588(v, n << 6);
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
            p = ts4_if_call_seq_u32_off0_8818C588(v, newcap << 6);
            if (p == 0)
                return;
            fn_88562DC0(p, v->data, v->count << 6);
            if (v->data != 0)
                fn_881992A8(0, v->data);
            v->data = p;
            v->cap = newcap;
        }
    }
}
