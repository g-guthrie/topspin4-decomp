/* 0x883DD558: finds the caller in the map at x+0xA8 (keys +0x20, count +0x1C), counts its -1-terminated id list (+0x2C)
   and tail-calls fn_883DC3C0 with delta; returns 0 when there is no table or no entry. Matched plain /O1 (agT). */
typedef struct Map { char pad[0x1c]; int n; void **keys; char pad2[8]; int **lists; } Map;
typedef struct X { char pad[0xa8]; Map *map; } X;
typedef struct T { char pad[0x4c]; int *counts; } T;
int fn_883DC3C0(T *t, const int *ids, int n, int delta);
int ts4_adjust_counts_for_owner_883DD558(T *t, X *x, int delta)
{
    Map *m;
    int *ids;
    void **p;
    int i, k;
    if (!t->counts)
        return 0;
    m = x->map;
    i = 0;
    if (m->n > 0)
        for (p = m->keys; i < m->n; i++, p++)
            if (*p == t)
                break;
    if (i >= m->n)
        return 0;
    ids = m->lists[i];
    for (k = 0; ids[k] != -1; k++)
        ;
    return fn_883DC3C0(t, ids, k, delta);
}
