/* W7A batch L: LTCG-route functions (context: cw1_ctx_format_text.c + pp1_pool_primer.c, /Oc) */
#ifdef _MSC_VER
#define W7A_UNUSED
#else
#define W7A_UNUSED __attribute__((unused))
#endif

extern int ts4_format_text(char *dst, unsigned size, const char *fmt, ...);
extern const char lbl_880D312C[];

/* 0x8865AEF8: when the debug flag is set, format two values into a stack scratch string. */
typedef struct W7aC_AEF8 { char pad[0x48]; unsigned char f48; } W7aC_AEF8;
typedef struct W7aB_AEF8 { char pad[0x28]; W7aC_AEF8 *c; } W7aB_AEF8;
typedef struct W7aS_AEF8 { char pad[0x1c]; W7aB_AEF8 *b; char p2[0x40 - 0x20]; unsigned v40; unsigned v44; } W7aS_AEF8;
void ts4_format_debug_pair_8865AEF8(W7aS_AEF8 *s)
{
    char buf[0x20];
    if (s->b->c->f48 != 0) {
        ts4_format_text(buf, 0x20, lbl_880D312C, s->v44);
        ts4_format_text(buf, 0x20, lbl_880D312C, s->v40);
    }
}

/* 0x8865B058: store the fade frame count of each entry; fail at the first entry below 1.0. */
typedef struct W7aE_B058 { char pad[0x10]; float f10; } W7aE_B058;
typedef struct W7aH_B058 { int rel; int count; } W7aH_B058;
typedef struct W7aB_B058 { char pad[0x10]; W7aH_B058 hdr; } W7aB_B058;
typedef struct W7aS_B058 { char pad[0x28]; W7aB_B058 *b; char p2[0x40 - 0x2c]; int v40; } W7aS_B058;
int ts4_fade_frames_all_ready_8865B058(W7aS_B058 *s)
{
    int pad0 W7A_UNUSED = 0, pad1 W7A_UNUSED = 0, pad2 W7A_UNUSED = 0, pad3 W7A_UNUSED = 0;
    int i;
    int r = 1;
    int n = s->b->hdr.count;
    for (i = 0; i < n; i++) {
        W7aH_B058 *h = &s->b->hdr;
        W7aE_B058 *e = (W7aE_B058 *)((char *)h + (i * 0x70 + h->rel));
        s->v40 = (int)((1.0f - e->f10) * 60.0f);
        if (e->f10 < 1.0f) {
            r = 0;
            break;
        }
    }
    return r;
}

/* 0x886C3A48: bilinear weights from the fractions a (+0x30) and b (+0x34); w38 is the remainder. */
typedef struct W7aS_3A48 { char pad[0x28]; float f28, f2c, a, b, w38, w3c, w40, w44; } W7aS_3A48;
void ts4_bilinear_weights_886C3A48(W7aS_3A48 *s)
{
    float a = s->a;
    float b = s->b;
    float c = s->f28;
    float d = s->f2c;
    float p = d * a;
    s->w44 = b;
    s->w40 = p * (1.0f - b);
    s->w3c = (1.0f - a) * c * (1.0f - b);
    s->w38 = 1.0f - s->w3c - s->w40 - b;
}
