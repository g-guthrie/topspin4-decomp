/* 0x88595218: calls ts4_if_call_seq_fn_88594848_88594F78(&t->set, item) under the lock embedded at +0x74 (slots 2 and 5); returns 0 on success, else E_OUTOFMEMORY. */
/* Matched on /O1 (agAF). The HRESULT is computed into a local before the unlock call; sibling 0x885A63C8. */
typedef struct Lock Lock;
typedef struct LockVt { void *f[2]; void (*enter)(Lock *l); void *f3[2]; void (*leave)(Lock *l); } LockVt;
struct Lock { LockVt *vt; };
typedef struct T { char p[0x74]; Lock lock; char p78[0x218 - 0x78]; char set[4]; } T;
extern int ts4_if_call_seq_fn_88594848_88594F78(void *set, void *item);
long fn_88595218(T *t, void *item)
{
    long hr;
    t->lock.vt->enter(&t->lock);
    hr = ts4_if_call_seq_fn_88594848_88594F78(t->set, item) ? 0 : 0x8007000E;
    t->lock.vt->leave(&t->lock);
    return hr;
}
