/* 0x88379428: calls vtable slot 15 with x on each child (+0x80, count +0x7c); returns the last result */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ch { struct VT *vt; } Ch;
typedef struct VT { void *s[15]; int (*fn)(Ch *, float); } VT;
typedef struct { char p[0x7c]; int n; Ch *kids[1]; } S;
int ts4_kids_call_slot15_f_88379428(S *s, float a) { int r = 0; int i; for (i = 0; i < s->n; i++) r = s->kids[i]->vt->fn(s->kids[i], a); return r; }
