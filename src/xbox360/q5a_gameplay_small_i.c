/* Q5 batch I (Opus A): small gameplay helpers, byte-matched with and without /Oc.
 * Build b215 (TS4_MATCHING_DIR=work/matching-b215). */
typedef unsigned int u32;

typedef struct Q5Text { char *b; char *e; char *c; } Q5Text;
typedef struct Q5Svc224 Q5Svc224;
typedef struct Q5Svc224Vt {
    void *slots0[0xf];
    void (*add_name)(Q5Svc224 *self, Q5Text *name);              /* +0x3c */
    void *slot40;
    unsigned char (*test_name)(Q5Svc224 *self, const char *name); /* +0x44 */
} Q5Svc224Vt;
struct Q5Svc224 { Q5Svc224Vt *vt; };
typedef struct Q5Engine224 { char pad[0x224]; Q5Svc224 *svc; } Q5Engine224;
extern Q5Engine224 *lbl_88D45B1C;
extern char lbl_880DFEDC[];
extern char lbl_880DFFF8[];
extern void *ts4_assign_formatted_text(Q5Text *self, const char *text);
extern void ts4_destroy_owned_object(void *p);

/* Swing_DLL.xex 0x888683F0: for each of two fixed names, ask the engine service (+0x224) through
 * vtable slot +0x44 and, when it answers 1, build a text from the name and pass it to slot +0x3c. */
void ts4_register_two_names_888683F0(void)
{
    const char *names[2];
    const char **p;
    int i;
    names[0] = lbl_880DFEDC;
    names[1] = lbl_880DFFF8;
    p = names;
    for (i = 2; i != 0; i--, p++) {
        const char *n = *p;
        if (lbl_88D45B1C->svc->vt->test_name(lbl_88D45B1C->svc, n) == 1) {
            Q5Text t;
            ts4_assign_formatted_text(&t, n);
            lbl_88D45B1C->svc->vt->add_name(lbl_88D45B1C->svc, &t);
            ts4_destroy_owned_object(t.b);
        }
    }
}

typedef struct Q5BitIt { u32 *p; int off; } Q5BitIt;
typedef struct Q5BitOwner {
    char pad[0x6c];
    Q5BitIt first;      /* 0x6c */
    Q5BitIt last;       /* 0x74 */
    char pad7c[0x1528 - 0x7c];
    int mode;           /* 0x1528 */
    float value;        /* 0x152c */
} Q5BitOwner;

static int q5_bit_count(Q5BitIt f, Q5BitIt l)
{
    return (l.p - f.p) * 32 - f.off + l.off;
}

static void q5_bit_clear(Q5BitIt it, int n)
{
    int off = it.off + n;
    it.p += off / 32;
    off %= 32;
    if (off < 0) {
        off += 32;
        --it.p;
    }
    *it.p &= ~(1u << off);
}

/* Swing_DLL.xex 0x888C12C0: clear every bit of the bit vector [first, last) (vector<bool>-style
 * word pointer + bit offset iterators, cleared from the back), then store mode and value. */
void ts4_bits_reset_888C12C0(Q5BitOwner *self, int mode, float value)
{
    int i = q5_bit_count(self->first, self->last);
    while (i != 0) {
        --i;
        q5_bit_clear(self->first, i);
    }
    self->mode = mode;
    self->value = value;
}

typedef struct Q5RelF32 { int off; u32 count; } Q5RelF32;
typedef struct Q5CurveDesc { char pad[0x3c]; Q5RelF32 values; } Q5CurveDesc;
typedef struct Q5CurveSrc Q5CurveSrc;
typedef struct Q5CurveSrcVt {
    void *slots0[0xc];
    unsigned char (*ready)(Q5CurveSrc *self);              /* +0x30 */
    void *slots34[5];
    Q5CurveDesc *(*desc)(Q5CurveSrc *self, int which);     /* +0x48 */
} Q5CurveSrcVt;
struct Q5CurveSrc { Q5CurveSrcVt *vt; };
typedef struct Q5CurveUser { char pad[0x1c]; Q5CurveSrc src; char pad20[0x58]; void *override78; } Q5CurveUser;
extern float g_ts4_event_value; /* 0.0f */

/* Swing_DLL.xex 0x88656538: when the embedded curve source (+0x1c) is ready (slot +0x30) and no
 * override is set (+0x78), return entry i of the description's self-relative float array
 * (slot +0x48, array at +0x3c); otherwise 0.0f. */
float ts4_curve_value_88656538(Q5CurveUser *self, u32 i)
{
    Q5CurveSrc *s = &self->src;
    float zero = g_ts4_event_value;
    if (s->vt->ready(s) && self->override78 == 0) {
        Q5CurveSrcVt *vt = s->vt;
        Q5RelF32 *v = &vt->desc(s, 0)->values;
        if (i < v->count)
            return *(float *)((char *)v + (i * 4 + v->off));
    }
    return zero;
}
