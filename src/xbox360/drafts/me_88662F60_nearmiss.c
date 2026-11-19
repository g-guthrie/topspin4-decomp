/* me_88662F60 near-miss: 17 off (plain /Oc). When the player context is ready, take body pos with x replaced by
   body+0x920 and store it to body+0x930 when the rules' custom mode id is 0xD826E563, else back to body+0x920.
   Re-reading c->pc through an inline accessor gives a clrrwi copy, but on the wrong load: the target copies pc for
   the body (+0x74) load while the +0x4c load comes straight off r10. 8 variants. */
#include "vx1_vector.h"
typedef struct Body { char p[0x8e0]; __vector4 pos; char q[0x30]; float aim_x; char r[0xc]; __vector4 alt_target; } Body;
typedef struct Rules { char p[0xac]; unsigned int mode_id; char q[0x27a]; unsigned char custom; } Rules;
typedef struct RulesRef { char p[0x30]; Rules *r; } RulesRef;
typedef struct Match { char p[0x20]; RulesRef *rr; } Match;
typedef struct PlayerCtx { char p[0x10]; unsigned char ready; char q[0x3b]; Match *m; char r[0x24]; Body *body; } PlayerCtx;
typedef struct Ctl { char p[0x1c]; PlayerCtx *pc; } Ctl;
static __inline PlayerCtx *getpc(PlayerCtx *p) { return p; }
static __inline PlayerCtx *pcof(Ctl *c) { return c->pc; }

void fn_88662F60(Ctl *c)
{
    PlayerCtx *pc = c->pc;
    Vx1Vec v;
    unsigned char alt;
    if (!pc->ready) return;
    {
        Body *b = pcof(c)->body;
        Rules *r = pcof(c)->m->rr->r;
        v.v = __vrlimi(b->pos, __lvlx(&b->aim_x, 0), 8, 0);
        alt = 0;
        if (r->custom && r->mode_id == 0xD826E563u) alt = 1;
    }
    if (alt) pc->body->alt_target = v.v;
    else *(__vector4 *)&pc->body->aim_x = v.v;
}
