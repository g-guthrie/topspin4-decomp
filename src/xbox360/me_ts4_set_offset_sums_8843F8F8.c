/* 0x8843F8F8: stores x at +0x14, then base + x at +0x2c (through a pointer local, so base is re-read) and +0x3c */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char p[0x10]; float base; float off; char q[0x14]; float a; char r[0xc]; float b; } S;
void ts4_set_offset_sums_8843F8F8(S *s, float x) { s->off = x; { float *p = &s->a; *p = s->base + x; } s->b = s->base + x; }
