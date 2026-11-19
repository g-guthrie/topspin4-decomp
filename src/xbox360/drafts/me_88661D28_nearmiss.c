/* 88661D28 near miss (3 off, plain/LTCG, all /O levels): the reloaded x pointer gets r4 where the target reuses r11 (same r11/r10 family as 88662510). */
typedef struct { char p[0x410]; int a; char q[0x42c-0x414]; int b; char r[0x544-0x430]; int c; } X;
typedef struct { char p[0x28]; X *x; } H;
typedef struct { char p[0x28]; int v; } K;
typedef struct { char p[0x5c]; K *k; } J;
typedef struct { char p[0x48]; J *j; char q[0x60-0x4c]; H *h; } G;
typedef struct { int x; G *g; } S;
static void set2(X *x,int v){ x->b=-1; x->a=v; }
void fn_88661D28(S *s){ G *g=s->g; H *h=g->h; int v=g->j->k->v; h->x->c=v; set2(h->x,v); }
