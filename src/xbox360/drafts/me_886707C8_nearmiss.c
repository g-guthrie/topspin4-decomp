/* NEAR MISS draft (not built, not counted). See docs/agents/matching-tips.md, "Near misses parked". */
typedef unsigned int u32;
typedef struct Src { u32 f0, f4, f8, fc; } Src;
typedef struct Ctx { char p[0x108]; char tbl[4]; } Ctx;
typedef struct Self { u32 f0, f4; void *f8, *fc, *f10; } Self;
extern void *fn_8826CC60(void *tbl, u32 *key);
void f(Self *s, Src *src, Ctx *c){ u32 k[3]; u32 b, d; void *t; k[0] = src->f4; b = src->f8; t = c->tbl; d = src->fc; k[1] = b; k[2] = d;
 s->f8 = fn_8826CC60(t, &k[0]);
 if (b != 0) s->fc = fn_8826CC60(t, &k[1]); else s->fc = 0;
 if (d != 0) s->f10 = fn_8826CC60(t, &k[2]); else s->f10 = 0; }