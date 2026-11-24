/* 0x888DC298: sends the vectors (y0, k * x0, 5) and (y1, k * x1, 5) with the hash 0x5392B268 through fn_888D0FE0,
 * where k = 1 when t == -1 and t / 180 (t * 0.0055555557) otherwise. 12-byte values pass by value in GPR pairs
 * (sister of 0x888D9420).
 * Matched on the LTCG route (/Oc, pool primer) with float literals (pool +0x38, +0x0, +0x788, +0x1E0): read as pool
 * externs, `t * K` came out `fmuls f13,f0,f5`; the literal gives the target's `fmuls f13,f5,f0`.
 * Standalone byte-exact unit for the backlog block in eq_q5_gameplay_small_f.c (left unchanged). */
typedef unsigned int u32;
typedef struct Ts4SendV3 { float x, y, z; } Ts4SendV3;
extern void fn_888D0FE0(void *self, u32 hash, Ts4SendV3 a, Ts4SendV3 b);

void ts4_send_scaled_5392B268_888DC298(void *self, float x0, float x1, float y0, float y1, float t)
{
    float k;
    Ts4SendV3 a, b;
    if (t == -1.0f)
        k = 1.0f;
    else
        k = t * 0.0055555557f;
    a.x = y0;
    a.y = k * x0;
    a.z = 5.0f;
    b.x = y1;
    b.y = k * x1;
    b.z = 5.0f;
    fn_888D0FE0(self, 0x5392b268, a, b);
}
