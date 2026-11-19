/* 0x88379010: calls vtable slot 9 with a on each child (+0x80, count +0x7c); returns the last result */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ch { struct VT *vt; } Ch;
typedef struct VT { void *s[9]; int (*fn)(Ch *, int); } VT;
typedef struct { char p[0x7c]; int n; Ch *kids[1]; } S;
int ts4_kids_call_slot9_88379010(S *s, int a) { int r = 0; int i; for (i = 0; i < s->n; i++) r = s->kids[i]->vt->fn(s->kids[i], a); return r; }
