/* 0x88636EA8: zeroes a 12-float block from g_ts4_event_value and puts g_ts4_script_constants[0] at +0x20 and +0x28 */
/* Matched on /Oc LTCG route only (+ pp1_pool_primer.c). */
extern float g_ts4_event_value;
extern const float g_ts4_script_constants[];
typedef struct { float m[12]; } M;
void ts4_init_basis_3x4_88636EA8(M *o) { float z = g_ts4_event_value; float one; o->m[0] = z; o->m[1] = z; o->m[2] = z; one = g_ts4_script_constants[0]; o->m[9] = z; o->m[10] = one; o->m[11] = z; o->m[6] = z; o->m[7] = z; o->m[8] = one; o->m[3] = z; o->m[4] = z; o->m[5] = z; }
