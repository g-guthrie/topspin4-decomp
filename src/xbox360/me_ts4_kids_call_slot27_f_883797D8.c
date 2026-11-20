/* 0x883797D8: calls vtable slot 27 with x on each child (+0x80, count +0x7c); returns the last result */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ch { struct VT *vt; } Ch;
typedef struct VT { void *s[27]; int (*fn)(Ch *, float); } VT;
typedef struct { char p[0x7c]; int n; Ch *kids[1]; } S;
int ts4_kids_call_slot27_f_883797D8(S *s, float a) { int r = 0; int i; for (i = 0; i < s->n; i++) r = s->kids[i]->vt->fn(s->kids[i], a); return r; }
