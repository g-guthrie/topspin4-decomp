/* CW40 part f: guard-wrapped range lookups on the sub-object at +0x24 (0x887E9000 block). */
typedef unsigned int u32;
typedef unsigned char u8;

char **ts4_find_in_range_887E9720(char ***s, u32 *key, int b, u32 c);
extern void ts4_vec_erase_one_881AAE10(void *, void *);
typedef struct Cx40FO { void **vt; } Cx40FO;

/* 0x887E97E8: with the guard held, does the range at +0x54 contain the key. */
u32 ts4_range_has_887E97E8(char *self, u32 *a, int b, u32 c)
{
    Cx40FO *g = (Cx40FO *)(self + 0x24);
    u32 res;
    ((void (*)(void *))g->vt[1])(g);
    res = ((char *)*(char ***)(self + 0x58) - (char *)ts4_find_in_range_887E9720((char ***)(self + 0x54), a, b, c)) != 0;
    ((void (*)(void *))g->vt[2])(g);
    return res;
}

/* 0x887E98F0: with the guard held, delete the entry found in the range at +0x54; 1 when one was removed. */
u32 ts4_range_remove_887E98F0(char *self, u32 *a, int b, u32 c)
{
    Cx40FO *g = (Cx40FO *)(self + 0x24);
    char ***v;
    char **it;
    u32 res;
    ((void (*)(void *))g->vt[1])(g);
    v = (char ***)(self + 0x54);
    res = 0;
    it = ts4_find_in_range_887E9720(v, a, b, c);
    if (it != *(char ***)(self + 0x58)) {
        Cx40FO *o = *(Cx40FO **)it;
        if (o != 0) ((void (*)(void *, int))o->vt[0])(o, 1);
        ts4_vec_erase_one_881AAE10(v, it);
        res = 1;
    }
    ((void (*)(void *))g->vt[2])(g);
    return res;
}
