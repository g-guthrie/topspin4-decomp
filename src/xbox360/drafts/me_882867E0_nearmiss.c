/* NEAR MISS (agAD, b164): 67 off, /Oc plain. Rest of the operator= template matches; the shrink-branch copy loop is
 * strength-reduced with a +0x10 IV offset (addi/subi r4) where the target indexes f directly. */
/* Swing_DLL.xex 0x882867E0: vector<20-byte item>::operator= (item = 12-byte member assigned by fn_88150600 plus two words;
 * out-of-line uninitialised copy fn_88286558, per-item destroy ts4_if_get_u32_offc_8827C828). agAD, /Oc plain. */
typedef struct Sub { int w[3]; } Sub;
typedef struct Item { Sub a; int c; int d; } Item;
typedef struct Vec { Item *first; Item *last; Item *end; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_8817F480(Item **cap, unsigned n);
Item *fn_88286558(const Item *f, const Item *l, Item *d);
void ts4_if_get_u32_offc_8827C828(Item *p);
void ts4_destroy_owned_object(void *p);
void fn_88150600(Sub *d, const Sub *s);
static __inline void destroy(Item *f, Item *l)
{
    for (; f != l; ++f)
        ts4_if_get_u32_offc_8827C828(f);
}
static __inline void assign(Item *d, const Item *s)
{
    fn_88150600(&d->a, &s->a);
    d->c = s->c;
    d->d = s->d;
}
static __inline Item *copy(const Item *f, const Item *l, Item *d)
{
    int n;
    for (n = l - f; 0 < n; --n, ++f, ++d)
        assign(d, f);
    return d;
}

Vec *ts4_vec20_assign_882867E0(Vec *self, const Vec *rhs)
{
    if (rhs != self) {
        const Item *f = rhs->first;
        const Item *l = rhs->last;
        unsigned n = l - rhs->first;
        if (n > (unsigned)(self->end - self->first)) {
            Item *nb = n ? ts4_if_call_seq_u32_lbl_88D45B38_8817F480(&self->end, n) : 0;
            fn_88286558(f, l, nb);
            destroy(self->first, self->last);
            ts4_destroy_owned_object(self->first);
            self->first = nb;
            self->end = nb + n;
        } else if ((unsigned)(self->last - self->first) >= n) {
            Item *e = copy(f, rhs->last, self->first);
            destroy(e, self->last);
        } else {
            copy(f, rhs->first + (self->last - self->first), self->first);
            fn_88286558(rhs->first + (self->last - self->first), rhs->last, self->last);
        }
        self->last = self->first + n;
    }
    return self;
}

