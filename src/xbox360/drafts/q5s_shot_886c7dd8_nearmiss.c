/* nearmiss: 36 off (size 0x9c vs 0xa0, --auto-context /Oc); concrete blocker: transitive callee fn_886C48C8
 * (inlined into ts4_anim_layer_index_886C66C0) is unmatched (drafts/q5s_swan_886c48c8_nearmiss.c), so the
 * callee body LTCG sees differs and the target keeps t in volatile f7 across the call and returns 0 via r30,
 * while ours spills t to f31. Same blocker as drafts/q5s_swan_886c7c28_nearmiss.c.
 * 0x886C7DD8: 1 when the current anim layer entry is the idle clip (name hash 0x7C161A2B) and
 * t + k(0x130) < start - layer time (sign bit of the difference). */
typedef struct Q5AnimHashRef { unsigned int hash; } Q5AnimHashRef;
typedef struct Q5AnimEnt { char p[0x28]; float start; char q[0x40]; Q5AnimHashRef *name; } Q5AnimEnt;
typedef struct Q5AnimLay { char p[0x18]; float time; char q[0x40]; Q5AnimEnt **ents; } Q5AnimLay;
typedef struct Q5AnimHolder { char p[0x30]; Q5AnimLay lay; } Q5AnimHolder;
typedef struct Q5AnimUser { char p[0x28]; Q5AnimHolder *h; } Q5AnimUser;
typedef union Q5FBits { float f; unsigned short h[2]; } Q5FBits;
int ts4_anim_layer_index_886C66C0(Q5AnimLay *l);
extern float g_ts4_script_constants[];
int ts4_anim_idle_before_886C7DD8(Q5AnimUser *u, float t)
{
    Q5AnimHolder *h = u->h;
    int r = 0;
    int i = ts4_anim_layer_index_886C66C0(&h->lay);
    Q5AnimEnt *e;
    Q5FBits d;
    if (i != -1) {
        e = h->lay.ents[i];
        if (e->name->hash == 0x7C161A2Bu) {
            d.f = (t + g_ts4_script_constants[0x130 / 4]) - (e->start - h->lay.time);
            return d.h[0] >> 15;
        }
    }
    return r;
}
