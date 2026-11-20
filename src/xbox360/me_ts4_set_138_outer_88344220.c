/* 0x88344220: stores x at +0x138 of the outer object; returns 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char p[0x1c]; } Base;
typedef struct { char p[0x138]; float v; } O;
int ts4_set_138_outer_88344220(Base *b, float x) { O *o = b ? (O *)((char *)b - 0x1c) : 0; o->v = x; return 0; }
