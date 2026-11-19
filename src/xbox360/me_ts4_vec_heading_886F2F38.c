extern const float g_ts4_script_constants[]; extern const float lbl_8814B440;
float fn_881A4458(float x); double fn_88564BF8(double y, double x);
typedef struct V3 { float x, y, z; } V3;
void ts4_vec_heading_886F2F38(V3 *v, float *out){ float a = fn_881A4458(-v->y); if (a < g_ts4_script_constants[0x3a] && a > g_ts4_script_constants[0x39]) *out = (float)fn_88564BF8(v->z, v->x); else *out = lbl_8814B440; }