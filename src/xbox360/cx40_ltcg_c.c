/* CW40 ltcg part c: callers of the hash selector ts4_set_u32_off0_887F7B18 (r9 stays live across the call). LTCG route, context cx40_ctx_c.c. */
typedef unsigned int u32;
typedef unsigned char u8;

extern u32 *ts4_set_u32_off0_887F7B18(u32 *, u8);
extern void fn_881B5820(void *), fn_881B5708(void *), fn_881B55F0(void *);
extern void fn_881B5A88(void *), fn_881B5BD0(void *);

/* 0x887F8870: select one of three handlers by the hash of the object at +0x28. */
u32 ts4_dispatch_by_hash_887F8870(char *self)
{
    char *p = *(char **)(self + 0x28);
    char *q = p + *(int *)p;
    u32 tmp;
    switch (*ts4_set_u32_off0_887F7B18(&tmp, q[1])) {
    case 0x4538B1F4u: fn_881B5820(self); break;
    case 0x95B29297u: fn_881B5708(self); break;
    case 0xCD0B222Fu: fn_881B55F0(self); break;
    }
    return 1;
}

/* 0x887F8330: same selector over the table at +0x28+0xc, two handlers. */
u32 ts4_dispatch_by_hash_887F8330(char *self)
{
    char *p = *(char **)(self + 0x28) + 0xc;
    char *q = p + *(int *)p;
    u32 tmp;
    switch (*ts4_set_u32_off0_887F7B18(&tmp, q[1])) {
    case 0x95B29297u: fn_881B5BD0(self); break;
    case 0xCD0B222Fu: fn_881B5A88(self); break;
    }
    return 1;
}
