/* agentA2 2026-11-18: still 3: named it2=it+1 before first call (3), volatile it2 (21). */
/* NEAR MISS draft (not built, not counted). See docs/agents/matching-tips.md, "Near misses parked". */
typedef unsigned int u32;
typedef struct Acc { u32 f0; float f4; } Acc;
typedef struct Self { u32 f0; Acc *f4; } Self;
typedef struct Node { int rel; u32 f4, f8, fc; char *f10; } Node;
typedef struct Child { char a[8]; } Child;
extern void fn_88262B00(Self *s, void *child, void *a, void *b, int off);
void f(Self *s, Node *n, void *a, void *b, int off){
 u32 bits = *(u32 *)(n->f10 + off);
 if (bits == 0) { fn_88262B00(s, (char *)n + n->rel, a, b, off); }
 else if (bits == 0x3f800000u) { fn_88262B00(s, (Child *)((char *)n + n->rel) + 1, a, b, off); }
 else { float w = *(float *)(n->f10 + off); float sv = s->f4->f4; Child *it = (Child *)((char *)n + n->rel);
  s->f4->f4 = (1.0f - w) * sv; fn_88262B00(s, it++, a, b, off); s->f4->f4 = sv * w; fn_88262B00(s, it, a, b, off); } }