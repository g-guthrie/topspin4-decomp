/* 0x883DC3C0: adds delta to counts[ids[i]] (table at +0x4C) for n ids, then clamps negative entries to zero; returns 0.
   Matched plain /O1 (agT); register-keeping callee of 0x883DD7A0. */
typedef struct T { char pad[0x4c]; int *counts; } T;
int fn_883DC3C0(T *t, const int *ids, int n, int delta)
{
    int i;
    if (t->counts && n > 0) {
        for (i = 0; i < n; i++)
            t->counts[ids[i]] += delta;
        for (i = 0; i < n; i++)
            if (t->counts[ids[i]] < 0)
                t->counts[ids[i]] = 0;
    }
    return 0;
}
