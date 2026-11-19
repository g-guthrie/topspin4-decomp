/* 0x88374FD0: runs the base handler, then calls vtable slot 9 with (x, y, z, k) on each child; returns the base error or 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ch { struct VT *vt; } Ch;
typedef struct VT { void *s[9]; int (*fn)(Ch *, float, float, float, int); } VT;
typedef struct S { char p[0xac]; int n; Ch *kids[1]; } S;
int fn_88334948(S *s, float, float, float, int);
int ts4_base_then_kids_slot9_fffi_88374FD0(S *s, float x, float y, float z, int k) { int r = fn_88334948(s, x, y, z, k); int i; if (r) return r; for (i = 0; i < s->n; i++) s->kids[i]->vt->fn(s->kids[i], x, y, z, k); return 0; }
