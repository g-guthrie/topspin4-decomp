/* 0x882C7B38: state 1 with pending bytes (+0x18): writes them through fn_8857BD30(h, buf, n, &out, 0), moves them to done (+0x1C) and returns out */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); states 0/2 return 0, failure or other states return E_FAIL (0x80004005). */
typedef struct T { void *h; int f4, f8; unsigned state; int f10; void *buf; unsigned pending; unsigned done; } T;
int fn_8857BD30(void *h, void *buf, unsigned n, int *out, void *ov);
int ts4_flush_pending_882C7B38(T *t)
{
    int out;
    switch (t->state) {
    case 0:
    case 2:
        return 0;
    case 1:
        if (!t->pending)
            return 0;
        if (!fn_8857BD30(t->h, t->buf, t->pending, &out, 0))
            return 0x80004005;
        t->done += t->pending;
        t->pending = 0;
        return out;
    default:
        return 0x80004005;
    }
}
