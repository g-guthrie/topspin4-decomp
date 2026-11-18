/* W7A batch A: small gameplay functions (plain route, /Oc) */
#ifdef _MSC_VER
#define W7A_UNUSED
#else
#define W7A_UNUSED __attribute__((unused))
#endif

/* 0x886811A0: call the random-float helper with the same value for both bounds. */
typedef struct W7a811A0 { unsigned char pad[8]; float *p8; void *c; } W7a811A0;
float ts4_rng_range_8861E598(void *c, float a, float b);
static __inline float *w7a_gp811A0(W7a811A0 *s) { return s->p8; }
float ts4_call_float_same_args_886811A0(W7a811A0 *s)
{
    return ts4_rng_range_8861E598(s->c, *w7a_gp811A0(s), *w7a_gp811A0(s));
}

/* 0x886C4878: is x inside [first->lo, last->hi] of a non-empty pointer range. */
typedef struct W7aE4878 { char pad[0x24]; float lo; float hi; } W7aE4878;
typedef struct W7aS4878 { char pad[4]; W7aE4878 **begin; W7aE4878 **end; } W7aS4878;
unsigned char ts4_value_in_range_886C4878(W7aS4878 *s, float x)
{
    unsigned char r = 0;
    W7aE4878 *a;
    if (((volatile W7aS4878 *)s)->begin != ((volatile W7aS4878 *)s)->end) {
        a = *((volatile W7aS4878 *)s)->begin;
        r = a->lo <= x && x <= s->end[-1]->hi;
    }
    return r;
}

/* 0x8865DB50: is the elapsed count (match time - mark) within the limit. */
typedef struct W7aC5DB50 { char pad[0x310]; int t; } W7aC5DB50;
typedef struct W7aB5DB50 { char pad[0x30]; W7aC5DB50 *c; } W7aB5DB50;
typedef struct W7aD5DB50 { char pad[0xdf4]; float lim; } W7aD5DB50;
typedef struct W7aA5DB50 { char pad[0x48]; W7aB5DB50 *b; char p2[0x74 - 0x4c]; W7aD5DB50 *d; } W7aA5DB50;
typedef struct W7aS5DB50 { char pad[0x154]; W7aA5DB50 *a; char p2[0x2a0 - 0x158]; int v; } W7aS5DB50;
unsigned char ts4_elapsed_within_limit_8865DB50(W7aS5DB50 *s)
{
    unsigned char r;
    r = s->v > -1 && (float)(s->a->b->c->t - s->v) <= s->a->d->lim;
    return r;
}

/* 0x886C4058: gather 32-bit table entries for a run of 16-bit indices (self-relative table). */
typedef struct W7aH4058 { int rel; } W7aH4058;
typedef struct W7aO4058 { char pad[0xc]; int stride; char p2[0x84 - 0x10]; W7aH4058 hdr; } W7aO4058;
typedef struct W7aD4058 { char pad[0xc]; unsigned *out; } W7aD4058;
typedef struct W7aS4058 { char pad[0x30]; unsigned short *idx; } W7aS4058;
void ts4_gather_table_entries_886C4058(W7aS4058 *s, W7aO4058 *o, int a, int b, int c, W7aD4058 *d)
{
    int pad0 W7A_UNUSED = 0;
    unsigned short *end = s->idx + b;
    unsigned short *p;
    W7aH4058 *h = &o->hdr;
    unsigned *table = (unsigned *)((char *)h + h->rel);
    int stride = o->stride;
    unsigned *dst = d->out;
    p = s->idx + a;
    for (; p != end; p++) {
        *dst++ = table[*p * stride + c];
    }
}

/* 0x886714C0: copy a float between two fields and tag the current element of a self-relative array. */
typedef struct W7aH14C0 { int rel; } W7aH14C0;
typedef struct W7aP44_14C0 { char pad[0x104]; W7aH14C0 hdr; } W7aP44_14C0;
typedef struct W7aP48_14C0 { char pad[0x44]; W7aP44_14C0 *p44; } W7aP48_14C0;
typedef struct W7aP74_14C0 { char pad[0x544]; float f544; char p2[0xd08 - 0x548]; float fd08; } W7aP74_14C0;
typedef struct W7aC14C0 { char pad[0x14]; int idx; char p2[0x48 - 0x18]; W7aP48_14C0 *p48; char p3[0x74 - 0x4c]; W7aP74_14C0 *p74; } W7aC14C0;
typedef struct W7aS14C0 { char pad[0xcc]; W7aC14C0 *c; } W7aS14C0;
typedef struct W7aEl14C0 { char pad[0xb4]; unsigned v; } W7aEl14C0;
void ts4_tag_current_element_886714C0(W7aS14C0 *s)
{
    W7aC14C0 *c = s->c;
    W7aH14C0 *h;
    W7aEl14C0 *e;
    W7aP74_14C0 *q = c->p74;
    h = &c->p48->p44->hdr;
    q->f544 = q->fd08;
    e = (W7aEl14C0 *)((char *)h + (c->idx * 0x140 + h->rel));
    e->v = 0xccb6e1ac;
}

/* 0x886C5098: address of the element min(i, count - 1) of a self-relative array of 0x30-byte records. */
typedef struct W7aH5098 { int rel; } W7aH5098;
typedef struct W7aB5098 { char pad[0x38c]; W7aH5098 hdr; int count; } W7aB5098;
typedef struct W7aO5098 { char pad[0x14]; W7aB5098 *b; } W7aO5098;
void *ts4_clamped_record_886C5098(W7aO5098 *o, int i)
{
    int pad0 W7A_UNUSED = 0, pad1 W7A_UNUSED = 0, pad2 W7A_UNUSED = 0;
    W7aB5098 *b = o->b;
    W7aH5098 *h;
    int idx = b->count - 1;
    if (i < idx) idx = i;
    h = &b->hdr;
    return (char *)h + idx * 0x30 + h->rel;
}

/* 0x8865E980: record the pair of floats in the slot (tick mod count) of a self-relative array. */
typedef struct W7aH_E980 { int rel; int count; } W7aH_E980;
typedef struct W7aEl_E980 { float a, b; } W7aEl_E980;
typedef struct W7aP74_E980 { char pad[0x4cc]; W7aH_E980 hdr; char p2[0x9d0 - 0x4d4]; float f9d0; float f9d4; } W7aP74_E980;
typedef struct W7aC30_E980 { char pad[0x310]; int t; } W7aC30_E980;
typedef struct W7aP48_E980 { char pad[0x30]; W7aC30_E980 *c; } W7aP48_E980;
typedef struct W7aO_E980 { char pad[0x48]; W7aP48_E980 *p48; char p2[0x74 - 0x4c]; W7aP74_E980 *p74; } W7aO_E980;
typedef struct W7aS_E980 { char pad[8]; W7aO_E980 *o; } W7aS_E980;
void ts4_record_float_pair_slot_8865E980(W7aS_E980 *s)
{
    W7aO_E980 *o = s->o;
    W7aP74_E980 *q = o->p74;
    W7aH_E980 *h = &q->hdr;
    int idx = o->p48->c->t % h->count;
    W7aEl_E980 *e = (W7aEl_E980 *)((char *)h + (idx * 8 + h->rel));
    e->a = q->f9d4;
    e->b = q->f9d0;
}

/* 0x886C7150: first 16-byte record of a relative array whose key equals *key; 0 if none. */
typedef struct W7aRel7150 { int off; int count; } W7aRel7150;
typedef struct W7aRec7150 { unsigned key; int w1, w2, w3; } W7aRec7150;
typedef struct W7aO7150 { char pad[4]; struct { char pad[0x64]; W7aRel7150 rel; } *b; } W7aO7150;
static __inline W7aRec7150 *w7a_rbegin7150(W7aRel7150 *a)
{
    if (a->off == -1) return 0;
    return (W7aRec7150 *)((char *)a + a->off);
}
static __inline W7aRec7150 *w7a_rend7150(W7aRel7150 *a)
{
    W7aRec7150 *e = 0;
    if (a->off != -1) e = (W7aRec7150 *)((char *)a + (a->count * 16 + a->off));
    return e;
}
W7aRec7150 *ts4_find_record_by_key_886C7150(W7aO7150 *o, const unsigned *key)
{
    W7aRec7150 *r = 0;
    W7aRec7150 *p;
    W7aRec7150 *b = w7a_rbegin7150(&o->b->rel);
    W7aRec7150 *e = w7a_rend7150(&o->b->rel);
    for (p = b; p != e; p++) {
        if (p->key == *key) {
            r = p;
            break;
        }
    }
    return r;
}

/* 0x8865E490: when the elapsed-time budget (counter + offset) is below the match clock, flag the world and resync the counter. */
typedef struct W7aC30_E490 { char pad[0x310]; int t; } W7aC30_E490;
typedef struct W7aP48_E490 { char pad[0x30]; W7aC30_E490 *c; } W7aP48_E490;
typedef struct W7aP6c_E490 { char pad[0xa68]; float f; } W7aP6c_E490;
typedef struct W7aP44_E490 { char pad[0x6c]; W7aP6c_E490 *p6c; } W7aP44_E490;
typedef struct W7aP74_E490 { char pad[0xfa0]; unsigned char flag; } W7aP74_E490;
typedef struct W7aO_E490 { char pad[0x44]; W7aP44_E490 *p44; W7aP48_E490 *p48; char p2[0x74 - 0x4c]; W7aP74_E490 *p74; } W7aO_E490;
typedef struct W7aS_E490 { char pad[0x1c]; W7aO_E490 *o; char p2[0x40 - 0x20]; int v40; int v44; unsigned v48; } W7aS_E490;
void ts4_resync_counter_if_late_8865E490(W7aS_E490 *s)
{
    W7aO_E490 *o = s->o;
    int ok;
    float sum = (float)s->v48;
    W7aP6c_E490 *p = o->p44->p6c;
    s->v40 = 0;
    sum = sum + p->f;
    ok = sum < (float)o->p48->c->t;
    if (s->v44 != 0 && (unsigned char)ok) {
        o->p74->flag = 1;
        s->v44 = 0;
        s->v48 = s->o->p48->c->t;
    }
}

/* 0x8865D6E8: last index in the ranges of an animation block whose self-relative table entry equals a fixed hash; -1 if none. */
typedef struct W7aRec_D6E8 { int lo, hi; } W7aRec_D6E8;
typedef struct W7aH_D6E8 { int rel; } W7aH_D6E8;
typedef struct W7aS_D6E8 { char pad[0x24]; W7aH_D6E8 h; } W7aS_D6E8;
typedef struct W7aO_D6E8 { char pad[0x18]; int rel18; int n1c; char p2[0x30 - 0x20]; unsigned char b30; } W7aO_D6E8;
int ts4_last_index_with_hash_8865D6E8(W7aS_D6E8 *s, W7aO_D6E8 *o)
{
    int r = -1;
    if (o->b30 != 0 && o->n1c > 0) {
        int n = o->n1c;
        W7aRec_D6E8 *rec = (W7aRec_D6E8 *)((char *)o + o->rel18 + 0x3c);
        do {
            int k;
            int hi = rec->hi;
            for (k = rec->lo; k <= hi; k++) {
                W7aH_D6E8 *h = &s->h;
                unsigned v = *(unsigned *)((char *)h + (k * 4 + h->rel));
                if (v == 0x71198650) r = k;
            }
            rec = (W7aRec_D6E8 *)((char *)rec + 0x30);
        } while (--n != 0);
    }
    return r;
}

/* 0x88667FA8: bump the per-side counters of the current and the other side in a self-relative record array. */
typedef struct W7aH_7FA8 { int rel; } W7aH_7FA8;
typedef struct W7aR_7FA8 { char pad[0x70]; int w70, w74, w78; char p2[0x98 - 0x7c]; int w98; char p3[0x134 - 0x9c]; } W7aR_7FA8;
typedef struct W7aB_7FA8 { char pad[0x5c]; W7aH_7FA8 hdr; } W7aB_7FA8;
typedef struct W7aP_7FA8 { char pad[0x90]; int w90; char p2[0xc4 - 0x94]; unsigned char bc4; char p3[0xd4 - 0xc5]; unsigned char bd4; char p4[2]; unsigned char bd7; int wd8; } W7aP_7FA8;
typedef struct W7aS_7FA8 { char pad[0x20]; W7aP_7FA8 *p; char p2[4]; W7aB_7FA8 *b; } W7aS_7FA8;
static __inline int *w7a_inc7FA8(int *p) { *p = *p + 1; return p; }
static __inline W7aR_7FA8 *w7a_rec7FA8(W7aS_7FA8 *s, int i)
{
    W7aH_7FA8 *h = &s->b->hdr;
    return (W7aR_7FA8 *)((char *)h + i * 0x134 + h->rel);
}
void ts4_bump_side_counters_88667FA8(W7aS_7FA8 *s)
{
    int pad0 W7A_UNUSED = 0, pad1 W7A_UNUSED = 0;
    W7aP_7FA8 *p = s->p;
    int i;
    if (p->bd4 == 0) return;
    if (p->bd7 != 0) return;
    if (p->bc4 != 0) return;
    i = p->w90;
    w7a_inc7FA8(&w7a_rec7FA8(s, i)->w70);
    w7a_inc7FA8(&w7a_rec7FA8(s, i ^ 1)->w74);
    if (p->wd8 == i)
        w7a_inc7FA8(&w7a_rec7FA8(s, p->wd8)->w78);
    else
        w7a_inc7FA8(&w7a_rec7FA8(s, p->wd8)->w98);
}

/* 0x88668780: bump the per-side tallies (two self-relative record arrays) unless the match flag blocks it. */
typedef struct W7aH_8780 { int rel; } W7aH_8780;
typedef struct W7aA_8780 { int w0, w4; char pad[0x40 - 8]; } W7aA_8780;
typedef struct W7aB_8780 { char pad[0xc]; int wc, w10; char p2[0x134 - 0x14]; } W7aB_8780;
typedef struct W7aBA_8780 { char pad[0x4c]; W7aH_8780 hdr; } W7aBA_8780;
typedef struct W7aBB_8780 { char pad[0x5c]; W7aH_8780 hdr; } W7aBB_8780;
typedef struct W7aP20_8780 { char pad[0x90]; int w90; } W7aP20_8780;
typedef struct W7aP44_8780 { char pad[0x9a]; unsigned char b9a; } W7aP44_8780;
typedef struct W7aId_8780 { char pad[0x2c]; unsigned id; } W7aId_8780;
typedef struct W7aP5c_8780 { char pad[0x20]; W7aId_8780 *p20; } W7aP5c_8780;
typedef struct W7aP34_8780 { char pad[0x44]; W7aP44_8780 *p44; char p2[0x5c - 0x48]; W7aP5c_8780 *p5c; } W7aP34_8780;
typedef struct W7aS_8780 { char pad[0x20]; W7aP20_8780 *p20; char p2[4]; W7aBA_8780 *ba; char p3[8]; W7aP34_8780 *p34; } W7aS_8780;
static __inline int *w7a_inc8780(int *p) { *p = *p + 1; return p; }
static __inline W7aA_8780 *w7a_ra8780(W7aS_8780 *s, int i)
{
    W7aH_8780 *h = &((W7aBA_8780 *)s->ba)->hdr;
    return (W7aA_8780 *)((char *)h + i * 0x40 + h->rel);
}
/* second instance of the accessor: dead locals shift the symbol numbering for its call site only */
static __inline W7aA_8780 *w7a_ra2_8780(W7aS_8780 *s, int i)
{
    int pb0 W7A_UNUSED = 0, pb1 W7A_UNUSED = 0, pb2 W7A_UNUSED = 0, pb3 W7A_UNUSED = 0;
    W7aH_8780 *h = &((W7aBA_8780 *)s->ba)->hdr;
    return (W7aA_8780 *)((char *)h + i * 0x40 + h->rel);
}
static __inline W7aB_8780 *w7a_rb8780(W7aS_8780 *s, int i)
{
    W7aH_8780 *h = &((W7aBB_8780 *)s->ba)->hdr;
    return (W7aB_8780 *)((char *)h + i * 0x134 + h->rel);
}
void ts4_bump_side_tallies_88668780(W7aS_8780 *s)
{
    int pa0 W7A_UNUSED = 0, pa1 W7A_UNUSED = 0, pa2 W7A_UNUSED = 0, pa3 W7A_UNUSED = 0;
    int i = s->p20->w90;
    if (s->p34->p5c->p20->id == 0x8f903dfb) return;
    w7a_inc8780(&w7a_ra8780(s, i)->w0);
    w7a_inc8780(&w7a_rb8780(s, i)->wc);
    if (s->p34->p44->b9a != 0) return;
    w7a_inc8780(&w7a_ra2_8780(s, i)->w4);
    w7a_inc8780(&w7a_rb8780(s, i)->w10);
}
