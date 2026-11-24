/* 0x88375068: runs the base handler, then calls vtable slot 11 with (x, y, z) on each child; returns the base error or 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ch { struct VT *vt; } Ch;
typedef struct VT { void *s[11]; int (*fn)(Ch *, float, float, float); } VT;
typedef struct S { char p[0xac]; int n; Ch *kids[1]; } S;
int ts4_if_get_88334A18(S *s, float, float, float);
int ts4_base_then_kids_slot11_fff_88375068(S *s, float x, float y, float z) { int r = ts4_if_get_88334A18(s, x, y, z); int i; if (r) return r; for (i = 0; i < s->n; i++) s->kids[i]->vt->fn(s->kids[i], x, y, z); return 0; }
