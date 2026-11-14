/* HS2 hand-decompiled functions, group C (Swing_DLL.xex 0x8842xxxx-0x8846xxxx). */

/* ---- variable-size integer read ---- */

int fn_88426178(void *a, void *b);

/* Reads a signed 8/16/32-bit value from p, width given by fn_88426178; 0 for other widths. */
int ts4_read_sized_int_88426440(void *a, void *p)
{
    int result = 0;
    switch (fn_88426178(a, p)) {
    case 1:
        result = *(signed char *)p;
        break;
    case 2:
        result = *(short *)p;
        break;
    case 4:
        result = *(int *)p;
        break;
    }
    return result;
}

/* ---- pair table removal ---- */

typedef struct Hs2PairEntry {
    unsigned key;
    int value;
} Hs2PairEntry;

typedef struct Hs2PairTable {
    char pad[0xc];
    Hs2PairEntry *volatile items;
    int count;
} Hs2PairTable;

/* ---- vtable iteration ---- */

typedef struct Hs2Iter {
    void **vtbl;
} Hs2Iter;

/* Counts items by repeatedly calling vtbl[3](self, previous) until -1 is returned. */
int ts4_iter_count_8843A0B0(Hs2Iter *it)
{
    int n = 0;
    int r = ((int (*)(Hs2Iter *))it->vtbl[2])(it);
    while (r != -1) {
        n++;
        r = ((int (*)(Hs2Iter *, int))it->vtbl[3])(it, r);
    }
    return n;
}
