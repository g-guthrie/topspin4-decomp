/* 0x886D7430: plays a named cue variant: looks the cue group up by name, loads its idx-th 40-byte
 * variant into the player, then returns one of the resulting candidates: the first one when asked, else
 * a random one. Returns 0 when the group or variant is missing or no candidate results. */
typedef struct Variant { char p[0x28]; } Variant;
typedef struct Group { int offset; unsigned int count; } Group;
typedef struct Catalog { char p[0x70]; char groups[4]; } Catalog;
typedef struct Res { char p[0x18]; Catalog *catalog; } Res;
typedef struct Rng { char p[0x12c]; char state[4]; } Rng;
typedef struct Ctx { char p[0x10]; Rng *rng; } Ctx;
typedef struct Player { char p[0x28]; Ctx *ctx; char p2[0x34 - 0x2c]; Res *res; char p3[0x54 - 0x38]; void **cand_begin; void **cand_end; } Player;
Group *fn_88265938(void *groups, const unsigned int *name);
void fn_886D2528(Player *p, Variant *v);
unsigned int ts4_rng_next_mod_88607FB0(void *rng, unsigned int n);
static __inline unsigned int pick(Rng *rng, unsigned int n) { if (n == 0) return 0; return ts4_rng_next_mod_88607FB0(rng->state, n); }
void *ts4_play_cue_variant_886D7430(Player *p, const unsigned int *name, unsigned int idx, unsigned char first)
{
    void *r = 0;
    Group *g = fn_88265938(p->res->catalog->groups, name);
    if (g != 0 && idx < g->count) {
        fn_886D2528(p, (Variant *)((char *)g + g->offset) + idx);
        if (p->cand_begin != p->cand_end) {
            unsigned int i;
            unsigned int n;
            if (!first) i = pick(p->ctx->rng, p->cand_end - p->cand_begin);
            else i = 0;
            r = p->cand_begin[i];
        }
    }
    return r;
}
