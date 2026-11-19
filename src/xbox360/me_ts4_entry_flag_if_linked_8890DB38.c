/* 0x8890DB38: returns the flag byte (+0x31) of entry i of the 0x34-byte vector at +0x1C when both i and the entry's parent index (+0x20) are in range, else 0. */
/* Matched on /Oc (agAB). vsize/vat inline helpers on &t->v; the element is taken through vat twice (begin reloaded). */
typedef struct E { char p[0x20]; int parent; char p24[0x31 - 0x24]; unsigned char flag; char p32[2]; } E;
typedef struct V { E *begin; E *end; } V;
typedef struct T { char p[0x1c]; V v; } T;
static unsigned int vsize(V *v) { return v->end - v->begin; }
static E *vat(V *v, int i) { return &v->begin[i]; }
unsigned char fn_8890DB38(T *t, int i)
{
    unsigned int n = vsize(&t->v);
    if ((unsigned int)i < n && i >= 0) {
        int p = vat(&t->v, i)->parent;
        if ((unsigned int)p < n && p >= 0)
            return vat(&t->v, i)->flag;
    }
    return 0;
}
