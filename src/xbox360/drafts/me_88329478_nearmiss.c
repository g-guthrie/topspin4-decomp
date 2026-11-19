/* NEAR MISS 0x88329478 (fn_88329478), /Oc: 1 off, lwzx base/index order (known open family) (agU 2026-11-19, work/army/ME/v.py chk, matching-b154). */
typedef struct { int a; int n; char p[0xc]; int *v; } S;
int ts4_get_slot_14_88329478(S *s, int i, int *out) { if (out && i >= 0 && i < s->n) { *out = s->v[i]; return 0; } return 0x25; }
