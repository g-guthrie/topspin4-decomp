/* 0x88330480: clamps x to >= 0, stores it at +0x58 and calls the update */
/* Matched on /Oc plain only (work/army/ME/v.py chk). */
typedef struct { char p[0x58]; float v; } S;
void fn_8832FA68(S *s);
void ts4_set_nonneg_58_88330480(S *s, float x) { if (x < 0.0f) x = 0.0f; s->v = x; fn_8832FA68(s); }
