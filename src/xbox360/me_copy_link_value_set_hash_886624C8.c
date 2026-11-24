/* 886624C8: the 88661D28 link copy (inlined) followed by storing hash 0x9E51242B at ctx->f74 +0x9FC. Plain /Oc. */
typedef struct { int a; char q[0x42c-0x414]; int b; } Y;
typedef struct { char p[0x9fc]; unsigned int h; } T;
typedef struct { char p[0x410]; Y y; char r[0x544-0x430]; int c; } X;
typedef struct { char p[0x28]; X *x; } H;
typedef struct { char p[0x28]; int v; } K;
typedef struct { char p[0x5c]; K *k; } J;
typedef struct { char p[0x48]; J *j; char q[0x60-0x4c]; H *h; char r[0x74-0x64]; T *t; } G;
typedef struct { int x; G *g; } S;
static void set2(Y *y,int v){ y->b=-1; y->a=v; }
static void cp(S *s){ G *g=s->g; H *h=g->h; int v=g->j->k->v; h->x->c=v; set2(&h->x->y,v); }
void fn_886624C8(S *s){ cp(s); s->g->t->h=0x9e51242b; }
