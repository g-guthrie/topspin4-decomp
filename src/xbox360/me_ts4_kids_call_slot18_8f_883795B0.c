/* 0x883795B0: calls vtable slot 18 with eight floats on each child (+0x80, count +0x7c); returns the last result */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ch { struct VT *vt; } Ch;
typedef struct VT { void *s[18]; int (*fn)(Ch *, float, float, float, float, float, float, float, float); } VT;
typedef struct S { char p[0x7c]; int n; Ch *kids[1]; } S;
int ts4_kids_call_slot18_8f_883795B0(S *s, float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7) { int r = 0; int i; for (i = 0; i < s->n; i++) r = s->kids[i]->vt->fn(s->kids[i], a0, a1, a2, a3, a4, a5, a6, a7); return r; }
