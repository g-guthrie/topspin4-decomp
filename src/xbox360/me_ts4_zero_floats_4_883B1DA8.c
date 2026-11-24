/* 0x883B1DA8: zeroes the n floats at s->v (+0x4/+0x8) */
/* Matched on /Oc plain only (work/army/ME/v.py chk). */
typedef struct { int a; float *v; int n; } S;
void ts4_zero_floats_4_883B1DA8(S *s) { int i; for (i = 0; i < s->n; i++) s->v[i] = 0.0f; }
