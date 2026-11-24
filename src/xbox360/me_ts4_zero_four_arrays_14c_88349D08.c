/* 0x88349D08: zeroes four 16-float arrays at +0x14c..+0x248 of the outer object; returns 0 */
/* Matched on /Oc plain only (work/army/ME/v.py chk). */
typedef struct { char p[0x1c]; } Base;
typedef struct { char p[0x14c]; float a[16], b[16], c[16], d[16]; } O;
int ts4_zero_four_arrays_14c_88349D08(Base *bs) { O *o = bs ? (O *)((char *)bs - 0x1c) : 0; int i; for (i = 0; i < 16; i++) { o->b[i] = 0.0f; o->a[i] = 0.0f; o->d[i] = 0.0f; o->c[i] = 0.0f; } return 0; }
