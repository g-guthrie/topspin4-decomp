/* Swing_DLL.xex 0x8816E038: vector<12-byte item>::operator= (grow: allocate, copy-construct, destroy and free the old block;
 * shrink: assign then destroy the tail; else assign the overlap and copy-construct the rest). agAD template, /Oc plain. */
typedef struct Item { int w[3]; } Item;
typedef struct Vec { Item *first; Item *last; Item *end; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88263C98(Item **cap, unsigned n);
void ts4_destroy_owned_object(void *p);
void ts4_assign_formatted_text(Item *d, int v);
void fn_88150600(Item *d, const Item *s);
void ts4_loop_call_seq_u32_off0_88150378(Item *f, Item *l);
static __inline Item *ucopy(const Item *f, const Item *l, Item *d)
{
    for (; f != l; ++d, ++f)
        if (d) ts4_assign_formatted_text(d, f->w[0]);
    return d;
}
static __inline void destroy(Item *f, Item *l) { ts4_loop_call_seq_u32_off0_88150378(f, l); }
static __inline Item *copy(const Item *f, const Item *l, Item *d)
{
    int n;
    for (n = l - f; 0 < n; --n, ++f, ++d)
        fn_88150600(d, f);
    return d;
}

Vec *ts4_vec12_assign_8816E038(Vec *self, const Vec *rhs)
{
    if (rhs != self) {
        const Item *f = rhs->first;
        const Item *l = rhs->last;
        unsigned n = l - rhs->first;
        if (n > (unsigned)(self->end - self->first)) {
            Item *nb = n ? ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&self->end, n) : 0;
            { const Item *s;
            for (s = f; s != l; ++s) {
                Item *d = (Item *)(((char *)nb - (char *)f) + (char *)s);
                if (d) ts4_assign_formatted_text(d, s->w[0]);
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
