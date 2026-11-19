/* Swing_DLL.xex 0x881B91A0: vector<20-byte binding>::resize(n) with the default {0, hash 0x629B9E5B, 0, 0, 0}: erase the tail or _Insert_n (fn_881B9978) at end.
 * /Oc. 88280428 resize template; the element's assignment is member-wise (unrolled field copy, no inner word loop). */
typedef struct Binding { unsigned int a; unsigned int hash; unsigned int c, d, e; } Binding;
typedef struct VecB { Binding *first; Binding *last; Binding *end; } VecB;
void fn_881B9978(VecB *v, Binding *where, unsigned int count, const Binding *val);

static __inline Binding *copyb(Binding *f, Binding *l, Binding *d)
{
    int n;
    for (n = l - f; 0 < n; --n, ++f, ++d) {
        d->a = f->a;
        d->hash = f->hash;
        d->c = f->c;
        d->d = f->d;
        d->e = f->e;
    }
    return d;
}

void fn_881B91A0(VecB *v, unsigned int n)
{
    Binding val;
    val.a = 0;
    val.hash = 0x629B9E5B;
    val.c = 0;
    val.d = 0;
    val.e = 0;
    if (n < (unsigned int)(v->last - v->first))
        v->last = copyb(v->last, v->last, v->first + n);
    else
        fn_881B9978(v, v->last, n - (v->last - v->first), &val);
}
