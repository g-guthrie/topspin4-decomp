/* 0x8834A6E0: zeroes 16 float pairs at +0x140 of the outer object; returns 0 */
/* Matched on /Oc plain only (work/army/ME/v.py chk). */
typedef struct { char p[0x1c]; } Base;
typedef struct { float x, y; } P;
typedef struct { char p[0x140]; P v[16]; } O;
int ts4_zero_pairs_140_8834A6E0(Base *b) { O *o = b ? (O *)((char *)b - 0x1c) : 0; int i; for (i = 0; i < 16; i++) { o->v[i].y = 0.0f; o->v[i].x = 0.0f; } return 0; }
