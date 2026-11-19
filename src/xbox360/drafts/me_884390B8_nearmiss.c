/* 0x884390B8 near miss (agW, /Oc): 2 off, the target sets r3 (mr r3,r30) before r4 (subi r4,r31,0x10) after the vcall; sibling of 884390B8/884A5F20. */
/* Calls d->vt[4](d, e) and passes the result with (a, b - 0x10, c->x20) to fn_88438FC0. A result local, a 16-byte element type and /O1 did not change the order. */
typedef struct D D;
typedef struct { void *s[4]; int (*f10)(D *, int); } DVt;
struct D { DVt *vt; };
typedef struct { char pad[0x20]; int x20; } C;
void fn_88438FC0(void *a, char *b, int c, int r);
void ts4_vcall10_then_call_884390B8(void *a, char *b, C *c, int unused, D *d, int e)
{
    fn_88438FC0(a, b - 0x10, c->x20, d->vt->f10(d, e));
}
