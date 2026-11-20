/* 0x88996058: appends (a, b) to the 4-entry pair array at +0x2c while count (+0x4c) + 1 < 4 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { int a, b; } E;
typedef struct { char p[0x2c]; E e[4]; int n; } S;
void ts4_push_pair_2c_88996058(S *s, int a, int b) { if (s->n + 1 < 4) { E *e = &s->e[s->n]; e->a = a; e->b = b; s->n++; } }
