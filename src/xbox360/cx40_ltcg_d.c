/* CW40 ltcg part d: range lookup caller that keeps r4-r6 live across ts4_find_in_range. LTCG route, context cx40_ctx_e.c. */
typedef unsigned int u32;
typedef unsigned char u8;
char **ts4_find_in_range_887E9720(char ***s, u32 *key, int b, u32 c);
typedef struct Cx40DO { void **vt; } Cx40DO;

/* 0x887E9860: with the guard held, does either range (+0x54, +0x48) contain the key. */
u8 ts4_range_has_either_887E9860(char *self, u32 *a, int b, u32 c)
{
    Cx40DO *g = (Cx40DO *)(self + 0x24);
    u32 res;
    ((void (*)(void *))g->vt[1])(g);
    res = (ts4_find_in_range_887E9720((char ***)(self + 0x54), a, b, c) != *(char ***)(self + 0x58)) || (ts4_find_in_range_887E9720((char ***)(self + 0x48), a, b, c) != *(char ***)(self + 0x4c));
    ((void (*)(void *))g->vt[2])(g);
    return (u8)res;
}
