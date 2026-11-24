/* 0x883435B0: zeroes two 16-pair float arrays at +0x150 and +0x1d0 of the outer object; returns 0 */
/* Matched on /Oc plain only (work/army/ME/v.py chk). */
typedef struct { char p[0x1c]; } Base;
typedef struct { float x, y; } P;
typedef struct { char p[0x150]; P a[16], b[16]; } O;
int ts4_zero_two_pair_arrays_150_883435B0(Base *bs) { O *o = bs ? (O *)((char *)bs - 0x1c) : 0; int i; for (i = 0; i < 16; i++) { o->a[i].y = 0.0f; o->a[i].x = 0.0f; o->b[i].y = 0.0f; o->b[i].x = 0.0f; } return 0; }
