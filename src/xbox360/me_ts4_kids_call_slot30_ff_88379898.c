/* 0x88379898: calls vtable slot 30 with (x, y) on each child (+0x80, count +0x7c); returns the last result */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ch { struct VT *vt; } Ch;
typedef struct VT { void *s[30]; int (*fn)(Ch *, float, float); } VT;
typedef struct S { char p[0x7c]; int n; Ch *kids[1]; } S;
int ts4_kids_call_slot30_ff_88379898(S *s, float x, float y) { int r = 0; int i; for (i = 0; i < s->n; i++) r = s->kids[i]->vt->fn(s->kids[i], x, y); return r; }
