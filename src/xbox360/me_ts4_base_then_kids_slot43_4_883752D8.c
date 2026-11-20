/* 0x883752D8: runs the base handler, then calls vtable slot 43 with (a, b, c, d) on each child; returns the base error or 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ch { struct VT *vt; } Ch;
typedef struct VT { void *s[43]; int (*fn)(Ch *, int, int, int, int); } VT;
typedef struct S { char p[0xac]; int n; Ch *kids[1]; } S;
int fn_88336BB8(S *s, int, int, int, int);
int ts4_base_then_kids_slot43_4_883752D8(S *s, int a, int b, int c, int d) { int r = fn_88336BB8(s, a, b, c, d); int i; if (r) return r; for (i = 0; i < s->n; i++) s->kids[i]->vt->fn(s->kids[i], a, b, c, d); return 0; }
