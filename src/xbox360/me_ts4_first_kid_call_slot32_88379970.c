/* 0x88379970: calls vtable slot 32 with a on the first child only (loop capped at 1); returns the result */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ch { struct VT *vt; } Ch;
typedef struct VT { void *s[32]; int (*fn)(Ch *, int); } VT;
typedef struct { char p[0x7c]; int n; Ch *kids[1]; } S;
int ts4_first_kid_call_slot32_88379970(S *s, int a) { int r = 0; int i; for (i = 0; i < s->n; i++) { if (i >= 1) break; r = s->kids[i]->vt->fn(s->kids[i], a); } return r; }
