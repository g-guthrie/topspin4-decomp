/* Near-miss (agAP), 0x886F6348, LTCG ctx=[]: one extra 'mr r11,r4' from the k copy and the cmplw order of cap/last; target keeps key in r30 without a copy. */
typedef struct IVec { int *first; int *last; int *reserved; int *end; } IVec;
typedef struct S { char p[0x3c]; IVec v; } S;
int *cw3_find_int_881655A0(int *first, int *last, const int *val);
void ts4_vector_grow_append_scalar4_8816DD48(IVec *v, int *where, const int *val);
void ts4_add_unique_int_886F6348(S *s, int key){ int *e = s->v.last; IVec *v = &s->v; int k = key; if (cw3_find_int_881655A0(v->first, e, &key) == e) { if (v->last != v->end) { if (v->last) *v->last = k; v->last++; } else ts4_vector_grow_append_scalar4_8816DD48(v, v->last, &key); } }