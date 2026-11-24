/* 0x8837FD20: clamps x to [-1, 1]; when it differs from +0x94, stores it and runs the update */
/* Matched on /Oc plain only (work/army/ME/v.py chk). */
typedef struct { char p[0x94]; float v; } S;
int fn_8837DBD8(S *s);
int ts4_set_unit_clamped_94_8837FD20(S *s, float x) { if (x < -1.0f) x = -1.0f; else if (x > 1.0f) x = 1.0f; if (s->v == x) return 0; s->v = x; return fn_8837DBD8(s); }
