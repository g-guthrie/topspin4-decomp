/* 8866D218: clears the owner's +0x18 word and sets the four floats at +0x694 of owner->ctx->player to
 * g_ts4_event_value (0.0f). LTCG route, /Oc: the four stores go through an inline taking &player->quad. */
extern const float g_ts4_event_value;
typedef struct { float a,b,c,d; } Q; typedef struct { char p[0x694]; Q q; } P;
typedef struct { char q[0x74]; P *p; } G;
typedef struct { int x,y; G *g; char q[0x18-0xc]; int f18; } S;
static void clr(Q*q){q->a=g_ts4_event_value;q->b=g_ts4_event_value;q->c=g_ts4_event_value;q->d=g_ts4_event_value;}
void fn_8866D218(S *s){ s->f18=0; clr(&s->g->p->q); }
