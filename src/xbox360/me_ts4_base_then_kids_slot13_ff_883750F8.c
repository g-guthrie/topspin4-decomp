/* 0x883750F8: runs the base handler, then calls vtable slot 13 with (x, y) on each child; returns the base error or 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ch { struct VT *vt; } Ch;
typedef struct VT { void *s[13]; int (*fn)(Ch *, float, float); } VT;
typedef struct S { char p[0xac]; int n; Ch *kids[1]; } S;
int ts4_if_get_88334A88(S *s, float, float);
int ts4_base_then_kids_slot13_ff_883750F8(S *s, float x, float y) { int r = ts4_if_get_88334A88(s, x, y); int i; if (r) return r; for (i = 0; i < s->n; i++) s->kids[i]->vt->fn(s->kids[i], x, y); return 0; }
