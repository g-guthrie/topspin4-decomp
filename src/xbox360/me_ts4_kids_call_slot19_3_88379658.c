/* 0x88379658: calls vtable slot 19 with (a, b, c) on each child; returns the last result */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ch { struct VT *vt; } Ch;
typedef struct VT { void *s[19]; int (*fn)(Ch *, int, int, int); } VT;
typedef struct { char p[0x7c]; int n; Ch *kids[1]; } S;
int ts4_kids_call_slot19_3_88379658(S *s, int a, int b, int c) { int r = 0; int i; for (i = 0; i < s->n; i++) r = s->kids[i]->vt->fn(s->kids[i], a, b, c); return r; }
