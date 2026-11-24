/* Swing_DLL.xex 0x888C0528: random integer in [0, n) from the generator in the game globals (xorshift + LCG *69069, as ts4_rng_range_8861E598); 0 when n is 0. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned __int64 u64;
typedef struct Ts4Rng { u32 pad_00; u32 xs; u32 lcg; } Ts4Rng;
typedef struct GameGlobals { u8 pad[0x228]; Ts4Rng rng; } GameGlobals;
extern GameGlobals *lbl_88D45B1C;

u32 ts4_rng_global_below_888C0528(u32 n)
{
    Ts4Rng *r = &lbl_88D45B1C->rng;
    u32 x, l;
    if (n != 0) {
        x = r->xs;
        x ^= x >> 15;
        l = r->lcg * 0x10DCD;
        r->lcg = l;
        x ^= x << 17;
        r->xs = x;
        return (u32)((u64)(l ^ x) % (u64)n);
    }
    return 0;
}
