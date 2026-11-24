/* 0x888D9420: sends the vectors (80, 16, 5) and (360, k * 0.92777777, 5) with the hash 0x5392B268 through
 * fn_888D0FE0. 12-byte values pass by value in GPR pairs.
 * Matched on the LTCG route (/Oc, pool primer): the constants are float literals that LTCG puts in the module pool
 * g_ts4_script_constants (+0x638, +0x344, +0x1E0, +0x374, +0x750). Read as pool externs, the product came out
 * `fmuls f10,f12,f1`; the literal gives the target's `fmuls f10,f1,f12`.
 * Standalone byte-exact unit for the backlog block in eq_q5_gameplay_small_d.c (left unchanged). */
typedef unsigned int u32;
typedef struct Ts4SendV3 { float x, y, z; } Ts4SendV3;
extern void fn_888D0FE0(void *self, u32 hash, Ts4SendV3 a, Ts4SendV3 b);

void ts4_send_vectors_5392B268_888D9420(void *self, float k)
{
    Ts4SendV3 a, b;
    a.x = 80.0f;
    a.y = 16.0f;
    a.z = 5.0f;
    b.x = 360.0f;
    b.y = k * 0.92777777f;
    b.z = 5.0f;
    fn_888D0FE0(self, 0x5392b268, a, b);
}
