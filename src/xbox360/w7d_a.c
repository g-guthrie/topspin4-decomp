/* W7D: small gameplay functions (LTCG route, /Oc). */

/* Swing_DLL.xex 0x8864B030: wait up to 200 on a handle; 1 on timeout, -1 on other nonzero */
struct W7dH { void *h; };
extern unsigned ts4_tailcall_fn_88582F30_8857A128(void *, int);
int ts4_wait_200_8864B030(struct W7dH **s)
{
    unsigned r = ts4_tailcall_fn_88582F30_8857A128((*s)->h, 200);
    if (r == 0x102)
        return 1;
    return 0 != r ? -1 : 0;
}

/* Swing_DLL.xex 0x8865B6C0: all three components of the position are >= the limits */
struct W7dTri { int a, b, c; };
struct W7dT { char pad[0xc]; struct W7dTri *lim; char pad2[0x84 - 0x10]; int x84, x88, x8c; };
unsigned char ts4_all_ge_8865B6C0(struct W7dT *s)
{
    struct W7dTri *l = s->lim;
    int x = s->x84 >= l->a;
    int y = s->x88 >= l->b;
    int z = s->x8c >= l->c;
    if ((unsigned char)x && (unsigned char)y && (unsigned char)z)
        return 1;
    return 0;
}

/* Swing_DLL.xex 0x8865C018: reset state fields and self-relative flags. Five dead locals only advance the symbol numbering (OP1 padding form). */
struct W7dRel { int rel; };
struct W7dE {
    char pad0[4]; unsigned char b4; char pad5[3];
    unsigned char b8, b9; char pad_a[2];
    struct W7dRel hdr;
    char pad10[0x18 - 0x10]; int f18, f1c;
    char pad20[0x28 - 0x20];
    unsigned char b28[12];
    unsigned char b34, b35;
    char pad36[0x38 - 0x36]; int f38;
};
struct W7dS { char pad[0x28]; struct W7dE *e; };
void ts4_clear_state_8865C018(struct W7dS *s)
{
    int w7d_p0 = 0, w7d_p1 = 0, w7d_p2 = 0, w7d_p3 = 0, w7d_p4 = 0;
    struct W7dE *e = s->e;
    struct W7dRel *h = &e->hdr;
    e->f38 = 0;
    e->b8 = 0;
    e->b9 = 0;
    *((unsigned char *)h + h->rel + 4) = 0;
    *((unsigned char *)h + h->rel + 6) = 0;
    *(int *)((char *)h + h->rel) = 0;
    *((unsigned char *)h + h->rel + 0xc) = 0;
    *((unsigned char *)h + h->rel + 0xe) = 0;
    *(int *)((char *)h + h->rel + 8) = 0;
    e->f18 = 0;
    e->f1c = 0;
    e->b28[0] = 0; e->b28[1] = 0; e->b28[2] = 0; e->b28[3] = 0; e->b28[4] = 0; e->b28[5] = 0;
    e->b28[6] = 0; e->b28[7] = 0; e->b28[8] = 0; e->b28[9] = 0; e->b28[10] = 0; e->b28[11] = 0;
    e->b35 = 0;
    e->b34 = 0;
    (void)w7d_p0; (void)w7d_p1; (void)w7d_p2; (void)w7d_p3; (void)w7d_p4;
}
