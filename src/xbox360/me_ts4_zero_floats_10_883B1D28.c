/* 0x883B1D28: zeroes the n floats at s->v (+0x10/+0x14) */
/* Matched on /Oc plain only (work/army/ME/v.py chk). */
typedef struct { char p[0x10]; float *v; int n; } S;
void ts4_zero_floats_10_883B1D28(S *s) { int i; for (i = 0; i < s->n; i++) s->v[i] = 0.0f; }
