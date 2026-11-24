/* 0x88838808: returns entry i (0x3C bytes) of the self-relative table at +0x1C (offset at +0, -1 = none; count at +4), or 0 when i is out of range or the table is empty. */
/* Matched on /Oc (agAB). Element address in an inline at(t, i) with p = 0 first and (char *)t + (i * 0x3c + t->off); the caller uses r = 0 and one i < n test. */
typedef struct E { char b[0x3c]; } E;
typedef struct Tab { int off; int n; } Tab;
typedef struct S { char pad[0x1c]; Tab *t; } S;
static E *at(Tab *t, int i) { E *p = 0; if (t->off != -1) p = (E *)((char *)t + (i * 0x3c + t->off)); return p; }
E *fn_88838808(S *s, int i)
{
    Tab *t = s->t;
    E *r = 0;
    if (i < t->n)
        r = at(t, i);
    return r;
}
