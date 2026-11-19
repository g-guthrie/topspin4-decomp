/* 0x885A63C8: calls ts4_if_call_seq_fn_885A5568_885A5FD0(&t->set, item) under the lock embedded at +0x54 (slots 2 and 5); returns 0 on success, else E_OUTOFMEMORY. */
/* Matched on /O1 (agAF). Same source as 0x88595218 with the lock at +0x54 and the set at +0x78. */
typedef struct Lock Lock;
typedef struct LockVt { void *f[2]; void (*enter)(Lock *l); void *f3[2]; void (*leave)(Lock *l); } LockVt;
struct Lock { LockVt *vt; };
typedef struct T { char p[0x54]; Lock lock; char p58[0x78 - 0x58]; char set[4]; } T;
extern int ts4_if_call_seq_fn_885A5568_885A5FD0(void *set, void *item);
long fn_885A63C8(T *t, void *item)
{
    long hr;
    t->lock.vt->enter(&t->lock);
    hr = ts4_if_call_seq_fn_885A5568_885A5FD0(t->set, item) ? 0 : 0x8007000E;
    t->lock.vt->leave(&t->lock);
    return hr;
}
