/* PL2 pilot: analyser block init (Top Spin 4, Xbox 360, Swing_DLL.xex). */
typedef unsigned int u32;
typedef struct PL2Graphs { char p[0x8c]; char in8c[0x48]; char outd4[4]; } PL2Graphs;
typedef struct PL2Tune { char p[0xa40]; char a40[0xb10 - 0xa40]; char b10[4]; } PL2Tune;
typedef struct PL2Tune2 { char p[0xa0]; char a0[4]; } PL2Tune2;
typedef struct PL2Own { char p[0x2c]; PL2Tune2 *t2c; char p2[0x44 - 0x30]; PL2Graphs *graphs; char p3[0x74 - 0x48];
    PL2Tune *t74; char p4[0x330 - 0x78]; char in330[4]; } PL2Own;
typedef struct PL2An { char d[0x44]; } PL2An;
typedef struct PL2Sub38 { char d[0xdc]; } PL2Sub38;
typedef struct PL2Self {
    char p0[0x10];
    char x10[4];
    char *x14;
    void *x18;
    char p1c[0x2c - 0x1c];
    char *x2c;
    char *x30;
    PL2Own *x34;
    PL2Sub38 x38;
    char *x114;
    char *x118;
    char p11c[0x125 - 0x11c];
    unsigned char b125;
    char p126[0x154 - 0x126];
    PL2Own *owner;
    PL2An a158, a19c, a1e0, a224;
} PL2Self;
void *ts4_graph_set_find_8866F028(PL2Graphs *g, const u32 *name);
void fn_88911668(PL2An *a, void *inputs, void *graph, void *gin, void *gout);
void fn_886BACC0(PL2Sub38 *s, PL2Own *o, char *p);
static __inline void pl2_bind(PL2Self *s, PL2An *a, u32 name)
{
    PL2Own *o = s->owner;
    PL2Graphs *g = o->graphs;
    fn_88911668(a, o->in330, ts4_graph_set_find_8866F028(g, &name), g->in8c, g->outd4);
}
/* Initialise an analyser block: store the owner, self-links, tuning-table addresses, initialise the
 * sub-object at +0x38, then bind four analysers (+0x158, +0x19C, +0x1E0, +0x224) to the owner's graphs
 * named 0x71198650, 0x4FD4C7A4, 0xDF1F8733, 0xDAF2ECBD (no null check on the found graph).
 * The b125 store goes through a block-local member pointer so it keeps its source position (SC2 rule).
 * Swing_DLL.xex 0x886BDB58 */
void ts4_analysers_init_886BDB58(PL2Self *s, PL2Own *o)
{
    s->owner = o;
    { unsigned char *b = &s->b125; *b = 0; }
    s->x18 = s;
    s->x14 = s->x10;
    s->x34 = o;
    s->x2c = o->t74->a40;
    s->x30 = o->t2c->a0;
    s->x114 = o->t74->a40;
    fn_886BACC0(&s->x38, o, o->t74->b10);
    s->x118 = o->t74->b10;
    pl2_bind(s, &s->a158, 0x71198650);
    pl2_bind(s, &s->a19c, 0x4FD4C7A4);
    pl2_bind(s, &s->a1e0, 0xDF1F8733);
    pl2_bind(s, &s->a224, 0xDAF2ECBD);
}
