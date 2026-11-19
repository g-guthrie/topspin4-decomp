/* 0x88349D60: k 0: stores x at +0x13c clamped to the max at +0x140; k 1: stores x at +0x148; returns 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char p[0x1c]; } Base;
typedef struct { char p[0x13c]; float v; float max; int q; float w; } O;
int ts4_set_param_13c_148_88349D60(Base *b, unsigned k, float x) { O *o = b ? (O *)((char *)b - 0x1c) : 0; switch (k) { case 0: { float m = o->max; o->v = x; if (x >= m) o->v = m; } break; case 1: o->w = x; break; } return 0; }
