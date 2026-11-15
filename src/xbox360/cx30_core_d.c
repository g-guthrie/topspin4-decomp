/* CX30 part d: functions that need /Oc (64-bit divide without the divide-by-zero trap). */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned long long u64;

/* 0x88607FB0: xorshift/LCG step on the state at +4/+8, result reduced modulo n */
typedef struct Cx30Rng { u8 pad[4]; u32 a; u32 b; } Cx30Rng;
u32 ts4_rng_next_mod_88607FB0(Cx30Rng *r, u32 n)
{
    u32 x = r->a;
    u32 y = r->b * 0x10dcd;
    x ^= x >> 15;
    x ^= x << 17;
    r->b = y;
    r->a = x;
    return (u32)((u64)(y ^ x) % (u64)n);
}
