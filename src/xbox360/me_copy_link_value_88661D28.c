/* 88661D28: copies ctx->f48->f5c->value (+0x28) into ctx->f60->obj (+0x28) at +0x544 and +0x410, and sets +0x42C to -1.
 * Plain /Oc. The +0x410/+0x42C pair must be stored through an inline taking &obj->pair; with the plain obj pointer
 * the reloaded obj gets r4 instead of reusing r11. */
typedef struct { int a; char q[0x42c-0x414]; int b; } Y;
typedef struct { char p[0x410]; Y y; char r[0x544-0x430]; int c; } X;
typedef struct { char p[0x28]; X *x; } H;
typedef struct { char p[0x28]; int v; } K;
typedef struct { char p[0x5c]; K *k; } J;
typedef struct { char p[0x48]; J *j; char q[0x60-0x4c]; H *h; } G;
typedef struct { int x; G *g; } S;
static void set2(Y *y,int v){ y->b=-1; y->a=v; }
void fn_88661D28(S *s){ G *g=s->g; H *h=g->h; int v=g->j->k->v; h->x->c=v; set2(&h->x->y,v); }
