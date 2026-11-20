/* SM4: float/vector field fills, constructors storing a vtable, small arithmetic helpers (MSVC 16.00 /O2). */
typedef long long ts4_s64;

extern float g_ts4_script_constants[];
extern float lbl_8814B440;
extern float lbl_88001A20;

/* fill 4 floats with the first script constant */
void ts4_fill4_script_constant_886EB230(float *p) { p[0] = g_ts4_script_constants[0]; p[1] = p[0]; p[2] = p[0]; p[3] = p[0]; }
/* fill floats 1..4 with a global constant */
void ts4_fill4_from_1_886C44A0(float *p) { p[1] = lbl_8814B440; p[2] = p[1]; p[3] = p[1]; p[4] = p[1]; }
/* set floats 3, 5 and 7 to a global constant */
void ts4_set_floats_3_5_7_88508CE0(float *p) { p[3] = lbl_88001A20; p[5] = p[3]; p[7] = p[3]; }

/* constructors: store the vtable pointer, then zero the fields in the original order */
struct sm4_c1 { void *vt; int f4; int f8; char c; };
extern char lbl_880D6B70[];
void ts4_ctor_vt_3fields_886C72C0(volatile struct sm4_c1 *s) { s->vt = lbl_880D6B70; s->f8 = 0; s->f4 = 0; s->c = 0; }
struct sm4_c2 { void *vt; int f4, f8, fc, f10; };
extern char lbl_880F4854[];
void ts4_ctor_vt_4fields_8867C100(volatile struct sm4_c2 *s) { s->vt = lbl_880F4854; s->f8 = 0; s->fc = 0; s->f10 = 0; s->f4 = 0; }

/* squared length of a 4-float vector */
struct sm4_v4 { float x, y, z, w; };
float ts4_vec4_length_sq_88518D78(struct sm4_v4 *v) { return v->y * v->y + v->x * v->x + v->z * v->z + v->w * v->w; }

/* (float)((double)a / (double)b) for two 64-bit integers */
float ts4_ratio_s64_885ED960(ts4_s64 a, ts4_s64 b) { return (float)((double)a / (double)b); }

/* store the low 24 bits of v big-endian at base + idx * 3 */
void ts4_store_u24_be_885BFDF8(int v, unsigned char *base, int unused, int idx) { unsigned char *p = base + idx * 3; int t = v >> 8; (void)unused; p[2] = (unsigned char)v; p[1] = (unsigned char)t; p[0] = (unsigned char)(t >> 8); }

/* b > a for the signed difference (b - a) */
struct sm4_pair { int a, b; };
int ts4_is_diff_positive_88660060(struct sm4_pair *s) { return (s->b - s->a) > 0; }

/* tail call forwarding the stored value */
extern void fn_886E1D90(void *, int);
void ts4_store_f4_forward_886E2080(int *s, int v) { s[1] = v; fn_886E1D90(s, v); }
extern void fn_88693040(int, int, char *, float);
void ts4_forward_with_float_88693270(int a, int b, char *c) { fn_88693040(a, b, c, *(float *)(*(char **)(c + 0x74) + 0xd90)); }
