/* 0x8883B2B8: follows two self-relative offsets (-1 = null) from the last 0x1C-byte entry of the self-relative array at b(+0x1C)+0x1C (count at +0x10) and returns the final address. */
/* Matched on /Oc (agAB). The self-relative resolve is an inline helper with p = 0 first and an if-assign (li 0 before the test), not a ternary. */
typedef struct Rel { int off; } Rel;
typedef struct E { Rel r; char p[0x1c - 4]; } E;
typedef struct Arr { Rel r; char p4[0xc]; int n; } Arr;
typedef struct B { char p[0x1c]; Arr a; } B;
typedef struct T { char p[0x1c]; B *b; } T;
static void *deref(Rel *r) { void *p = 0; if (r->off != -1) p = (char *)r + r->off; return p; }
void *fn_8883B2B8(T *t)
{
    Arr *a = &t->b->a;
    E *last = &((E *)((char *)a + a->r.off))[a->n - 1];
    return deref((Rel *)deref(&last->r));
}
