/* 0x88375270: runs the base handler, then calls vtable slot 41 with a on each child (+0xb0, count +0xac); returns the base error or 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ch { struct VT *vt; } Ch;
typedef struct VT { void *s[41]; int (*fn)(Ch *, int); } VT;
typedef struct S { char p[0xac]; int n; Ch *kids[1]; } S;
int ts4_if_set_u32_off3c_88335AC8(S *s, int);
int ts4_base_then_kids_slot41_88375270(S *s, int a) { int r = ts4_if_set_u32_off3c_88335AC8(s, a); int i; if (r) return r; for (i = 0; i < s->n; i++) s->kids[i]->vt->fn(s->kids[i], a); return 0; }
