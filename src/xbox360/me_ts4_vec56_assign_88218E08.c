/* Swing_DLL.xex 0x88218E08: vector<56-byte item>::operator= (grow: allocate, copy-construct, destroy and free the old block;
 * shrink: assign then destroy the tail; else assign the overlap and copy-construct the rest). agAD: /Oc plain. */
typedef struct Item { int w[14]; } Item;
typedef struct Vec { Item *first; Item *last; Item *end; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_882147E8(Item **cap, unsigned n);
void ts4_destroy_owned_object(void *p);
void fn_881C60C8(Item *d, const Item *s);
void fn_881C6168(Item *d, const Item *s);
void ts4_call_seq_fn_881B19A0_881C6008(Item *p);
static __inline Item *ucopy(const Item *f, const Item *l, Item *d)
{
    for (; f != l; ++d, ++f)
        if (d) fn_881C60C8(d, f);
    return d;
}
static __inline void destroy(Item *f, Item *l)
{
    for (; f != l; ++f)
        ts4_call_seq_fn_881B19A0_881C6008(f);
}
static __inline Item *copy(const Item *f, const Item *l, Item *d)
{
    int n;
    for (n = l - f; 0 < n; --n, ++f, ++d)
        fn_881C6168(d, f);
    return d;
}

Vec *ts4_vec56_assign_88218E08(Vec *self, const Vec *rhs)
{
    if (rhs != self) {
        const Item *f = rhs->first;
        const Item *l = rhs->last;
        unsigned n = l - rhs->first;
        if (n > (unsigned)(self->end - self->first)) {
            Item *nb = n ? ts4_if_call_seq_u32_lbl_88D45B38_882147E8(&self->end, n) : 0;
            { const Item *s;
            for (s = f; s != l; ++s) {
                Item *d = (Item *)(((char *)nb - (char *)f) + (char *)s);
                if (d) fn_881C60C8(d, s);
            } }
            destroy(self->first, self->last);
            ts4_destroy_owned_object(self->first);
            self->first = nb;
            self->end = nb + n;
        } else if ((unsigned)(self->last - self->first) >= n) {
            Item *e = copy(f, rhs->last, self->first);
            destroy(e, self->last);
        } else {
            copy(f, rhs->first + (self->last - self->first), self->first);
            ucopy(rhs->first + (self->last - self->first), rhs->last, self->last);
        }
        self->last = self->first + n;
    }
    return self;
}
