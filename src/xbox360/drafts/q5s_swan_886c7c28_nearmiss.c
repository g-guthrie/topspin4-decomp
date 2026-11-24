/* nearmiss: 27 off (only cause: default weight kept in f31 + stfd/lfd instead of volatile f7 across the call).
 * Concrete blocker: unmatched transitive callee 0x886C48C8 (called by ts4_anim_layer_index_886C66C0); LTCG
 * keeps f7 live only when the whole callee tree is known. Check with --auto-context once 0x886C48C8 matches.
 * Sign test: `lhz; clrrwi 15` = high halfword & 0x8000. */
typedef unsigned int u32;
typedef struct Q5LayerCurve { char pad[0x50]; float weight; } Q5LayerCurve;
typedef struct Q5LayerDef { char pad[8]; Q5LayerCurve *curve; } Q5LayerDef;
typedef struct Q5Layer { char pad[4]; Q5LayerDef *def; } Q5Layer;
typedef struct Q5AnimStack { char pad[0x5c]; Q5Layer **layers; } Q5AnimStack;
typedef struct Q5AnimCfg { char pad[0x140]; float default_weight; } Q5AnimCfg;
typedef struct Q5AnimCfgHolder { char pad[0x48]; Q5AnimCfg *cfg; } Q5AnimCfgHolder;
typedef struct Q5AnimOwner { char pad[0x10]; Q5AnimCfgHolder *holder; } Q5AnimOwner;
typedef struct Q5AnimUser { char pad[8]; Q5AnimOwner *owner; Q5AnimStack *stack; } Q5AnimUser;
extern int ts4_anim_layer_index_886C66C0(Q5AnimStack *stack);
typedef union Q5FBits { float f; unsigned short h[2]; } Q5FBits;

/* Swing_DLL.xex 0x886C7C28 */
/* byte-gap: 27 off; LTCG keeps the default weight in volatile f7 across the layer lookup */
float ts4_layer_weight_886C7C28(Q5AnimUser *u)
{
    float def = u->owner->holder->cfg->default_weight;
    Q5AnimStack *st = u->stack;
    int i = ts4_anim_layer_index_886C66C0(st);
    Q5FBits w;
    if (i == -1)
        return def;
    w.f = st->layers[i]->def->curve->weight;
    if (w.h[0] & 0x8000)
        return def;
    return w.f;
}
