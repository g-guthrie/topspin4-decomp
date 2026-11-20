/* 0x8834A730: stores x at +0x13c of the outer object when k is zero; returns 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char p[0x1c]; } Base;
typedef struct { char p[0x13c]; float v; } O;
int ts4_set_13c_unless_8834A730(Base *b, int k, float x) { O *o = b ? (O *)((char *)b - 0x1c) : 0; if (!k) o->v = x; return 0; }
