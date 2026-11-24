/* Swing_DLL.xex 0x881AE140: vector<44-byte POD item>::operator= (grow: allocate, memberwise copy, free the old block;
 * shrink: out-of-line assign fn_881AF6E8; else assign the overlap and copy the rest). agAD, /Oc plain. */
typedef struct Item { int w[11]; } Item;
typedef struct Vec { Item *first; Item *last; Item *end; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_881AE078(Item **cap, unsigned n);
void ts4_destroy_owned_object(void *p);
Item *fn_881AF6E8(const Item *f, const Item *l, Item *d);
static __inline Item *ucopy(const Item *f, const Item *l, Item *d)
{
    for (; f != l; ++d, ++f)
        if (d) *d = *f;
    return d;
}

Vec *ts4_vec44_assign_881AE140(Vec *self, const Vec *rhs)
{
    if (rhs != self) {
        const Item *f = rhs->first;
        const Item *l = rhs->last;
        unsigned n = l - rhs->first;
        if (n > (unsigned)(self->end - self->first)) {
            Item *nb = n ? ts4_if_call_seq_u32_lbl_88D45B38_881AE078(&self->end, n) : 0;
            { const Item *s;
            for (s = f; s != l; ++s) {
                Item *d = (Item *)(((char *)nb - (char *)f) + (char *)s);
                if (d) *d = *s;
            } }
            ts4_destroy_owned_object(self->first);
            self->first = nb;
            self->end = nb + n;
        } else if ((unsigned)(self->last - self->first) >= n) {
            fn_881AF6E8(f, l, self->first);
        } else {
            fn_881AF6E8(f, f + (self->last - self->first), self->first);
            ucopy(rhs->first + (self->last - self->first), rhs->last, self->last);
        }
        self->last = self->first + n;
    }
    return self;
}
