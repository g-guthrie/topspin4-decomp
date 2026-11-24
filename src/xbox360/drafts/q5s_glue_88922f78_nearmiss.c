/* nearmiss: 9 off; register swap only: the target keeps the object in r11 (mr r11,r3) and the hash in r10, ours swaps them. perm_auto --ltcg --targeted (94 candidates) and C/C++/inline/switch variants did not change the allocation. Check: --flags /Oc --context src/xbox360/pp1_pool_primer.c */
typedef unsigned int u32;
typedef struct Rel { int off; u32 hash; } Rel;
static __inline int known(u32 h) { return h == 0xFCF73E23 || h == 0x5559D5D6 || h == 0xC952E870 || h == 0x67860A08 || h == 0x5EFAFFB9; }
unsigned short fn_88922F78(Rel *o)
{
#if 4 == 1
    unsigned short r = 0;
    if (o->hash == 0xFCF73E23 || o->hash == 0x5559D5D6 || o->hash == 0xC952E870 || o->hash == 0x67860A08 || o->hash == 0x5EFAFFB9)
        r = *(unsigned short *)((char *)o + o->off + 4);
    return r;
#elif 4 == 2
    if (known(o->hash))
        return *(unsigned short *)((char *)o + o->off + 4);
    return 0;
#elif 4 == 3
    switch (o->hash) {
    case 0xFCF73E23: case 0x5559D5D6: case 0xC952E870: case 0x67860A08: case 0x5EFAFFB9:
        return *(unsigned short *)((char *)o + o->off + 4);
    }
    return 0;
#else
    Rel *p = o;
    unsigned short r = 0;
    u32 h = p->hash;
    if (h == 0xFCF73E23 || h == 0x5559D5D6 || h == 0xC952E870 || h == 0x67860A08 || h == 0x5EFAFFB9)
        r = *(unsigned short *)((char *)p + p->off + 4);
    return r;
#endif
}
