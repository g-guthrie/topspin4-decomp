/* 0x88375208: runs the base handler, then calls vtable slot 39 with a on each child (+0xb0, count +0xac); returns the base error or 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ch { struct VT *vt; } Ch;
typedef struct VT { void *s[39]; int (*fn)(Ch *, int); } VT;
typedef struct S { char p[0xac]; int n; Ch *kids[1]; } S;
int fn_88335880(S *s, int);
int ts4_base_then_kids_slot39_88375208(S *s, int a) { int r = fn_88335880(s, a); int i; if (r) return r; for (i = 0; i < s->n; i++) s->kids[i]->vt->fn(s->kids[i], a); return 0; }
