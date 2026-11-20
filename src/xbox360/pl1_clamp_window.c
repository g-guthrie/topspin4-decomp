/* Swing_DLL.xex 0x886D6D18: clamp a 2D window (start, start-(x-y)) into [0, len-1] with the fsel table select,
 * optionally pick the first key whose time is >= the clamped start, then forward to fn_88262B00.
 * LTCG route (pp1_pool_primer.c last). One dead local sets the (rel, base) operand order of the key-table add. */
static const float pl1_zero = 0.0f;
#ifdef _MSC_VER
#define PL1_PAD1 int pl1_pad0 = 0;
#else
#define PL1_PAD1
#endif
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct V2 { float x, y; } V2;
typedef struct Ent { u32 f0; float f4; } Ent;
typedef struct Tab { int rel; u32 count; } Tab;
typedef struct Hdr { int rel; } Hdr;
typedef struct Node {
    float f0;
    u32 f4;
    u16 idx;
    char pa[0xa];
    float f14;
    char p18[0x40];
    Hdr h58;
} Node;
typedef struct Inner { u32 f0; u32 f4; Node *n; u8 flag; } Inner;
extern void fn_88262B00(u32 *a, u32 b, void *ctx, float *out, float *rec);
static __inline float pmax(float a, float b) { return (a - b >= pl1_zero) ? a : b; }
static __inline float pmin(float a, float b) { return (a - b >= pl1_zero) ? b : a; }
void ts4_clamp_window_apply_886D6D18(Inner *in, void *ctx, float *rec, V2 *v, float f)
{
    PL1_PAD1
    Node *n = in->n;
    float t = n->f14 - 1.0f;
    float d = t * f;
    float x = v->x + d;
    float y = v->y + d;
    float out[2];
    float a, b;

    a = pmin(pmax(x, 0.0f), t);
    b = pmin(pmax(a - (x - y), 0.0f), t);
    out[0] = a;
    out[1] = b;
    if (in->flag == 1) {
        Hdr *h = &n->h58;
        Tab *tb = (Tab *)((char *)h + h->rel);
        u16 cnt = (u16)tb->count;
        u16 i;
        n->idx = cnt - 1;
        for (i = 0; i < cnt; i++) {
            Ent *e = (Ent *)((char *)tb + (i * 8 + tb->rel));
            if (!(out[0] > e->f4)) {
                n->idx = i;
                break;
            }
        }
    }
    n->f0 = 0.0f;
    fn_88262B00(&in->f4, in->f4, ctx, out, rec);
}
