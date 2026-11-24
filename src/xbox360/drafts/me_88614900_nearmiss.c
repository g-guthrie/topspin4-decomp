/* NEAR MISS 0x88614900 (fn_88614900), /Oc: 1 off, lwzx base/index order (agU round 2, matching-b157). */
typedef struct { char p[8]; unsigned char v; } It;
typedef struct { char p[0x24]; It **b, **e; } S;
void ts4_set_items_byte8_88614900(S *s, unsigned char v) { unsigned i, n = s->e - s->b; for (i = 0; i < n; i++) s->b[i]->v = v; }
