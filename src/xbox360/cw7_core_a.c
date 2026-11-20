/* Swing_DLL.xex game core 0x881B91A0-0x881D1D78: loaders / resources, hand written. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
typedef unsigned int cw7_uptr;
#else
typedef unsigned long cw7_uptr;
#endif
extern long _InterlockedDecrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedDecrement)
#endif

void ts4_destroy_owned_object(void *);
struct cw7_e14 { u32 a, b, c, d, e; };

/* 0x881BA4D8: copy-construct [first,last) of 20-byte elements to dst, returns end of dst */
struct cw7_e14 *ts4_copy_range_e14_881BA4D8(struct cw7_e14 *first, struct cw7_e14 *last, struct cw7_e14 *dst)
{
    while (first != last) {
        if (dst) {
            dst->b = 0;
            dst->a = first->a;
            dst->b = first->b;
            dst->c = first->c;
            dst->d = first->d;
            dst->e = first->e;
        }
        first++;
        dst++;
    }
    return dst;
}

/* 0x881BC0D0: destroy owned object (field +0x18) of each 0x24-byte element in [first,last) */
struct cw7_e24 { u8 pad[0x18]; void *owned; u8 pad2[0x8]; };
void ts4_destroy_range_e24_881BC0D0(struct cw7_e24 *first, struct cw7_e24 *last)
{
    while (first != last) {
        if (first->owned) ts4_destroy_owned_object(first->owned);
        first++;
    }
}

/* 0x881C2390: call a per-element routine on count consecutive 0x38-byte elements */
void ts4_call_seq_fn_881B19A0_881C6008(void *);
void ts4_each_call_881C2390(char *elems, u32 count)
{
    while (count) {
        char *e = elems;
        count--;
        elems += 0x38;
        ts4_call_seq_fn_881B19A0_881C6008(e);
    }
}

/* 0x881BD068: fill [first,last) with copies of *val (0x24-byte records, vector member at +0x18) */
struct cw7_vec { u32 *begin, *end, *cap; };
struct cw7_rec { u8 a, b, c; u32 d, e, f, g, h; struct cw7_vec v; };
struct cw7_vec *fn_881BD170(struct cw7_vec *dst, const struct cw7_vec *src);
void ts4_fill_range_rec_881BD068(struct cw7_rec *first, struct cw7_rec *last, const struct cw7_rec *val)
{
    for (; first != last; first++) {
        first->a = val->a;
        first->b = val->b;
        first->c = val->c;
        first->d = val->d;
        first->e = val->e;
        first->f = val->f;
        first->g = val->g;
        first->h = val->h;
        fn_881BD170(&first->v, &val->v);
    }
}


/* 0x881C70D8: drop one reference (23-bit counter) held by *ref; free the object at zero; clear *ref */
struct cw7_rc { u32 w0, w4; u32 hi : 8; u32 rc : 23; u32 flag : 1; };
void fn_881C6E30(struct cw7_rc *);
void fn_881992A8(void *, void *);
void ts4_release_ref_881C70D8(struct cw7_rc **ref)
{
    struct cw7_rc *o = *ref;
    o->rc--;
    if (o->rc == 0) {
        fn_881C6E30(o);
        fn_881992A8(0, o);
    }
    *ref = 0;
}


/* 0x881C3C00: locate a slot in a self-relative table (offsets in words), store this into it, return the slot */
int fn_881C3AD8(u32 **self);
u32 *ts4_table_slot_store_881C3C00(u32 **self)
{
    int idx = fn_881C3AD8(self);
    if (idx == -1) return 0;
    {
        u32 *t = *self;
        u32 n = t[0];
        u32 a = t[idx + 2];
        u32 b = t[n + 2];
        u32 off = (b + n + 3) * 4 + a;
        *(u32 **)((char *)t + off) = (u32 *)self;
        return (u32 *)((char *)t + off);
    }
}
