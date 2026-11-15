/* Swing_DLL.xex 0x886C5130: random number below n from the global generator, 0 when there is none. */
typedef unsigned int u32;
extern u32 ts4_rng_next_mod_88607FB0(void *rng, u32 n);
typedef struct MeRngOwner { char pad[0x12c]; int rng; } MeRngOwner;
extern MeRngOwner *lbl_88D45AF4;
u32 ts4_global_rng_next_mod_886C5130(u32 n)
{
    MeRngOwner *g = lbl_88D45AF4;
    u32 res = 0;
    if (g)
        res = n ? ts4_rng_next_mod_88607FB0(&g->rng, n) : 0;
    return res;
}
