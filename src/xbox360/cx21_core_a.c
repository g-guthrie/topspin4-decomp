/* CW21 part a: game core small helpers (0x88150000-0x8815ACE0). */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Cx21Rec2c { u8 pad[0x1c]; u32 key; u8 pad2[0x2c - 0x20]; } Cx21Rec2c;
typedef struct Cx21Vec2c { u8 pad0[4]; u32 base; u8 pad1[0x68 - 8]; Cx21Rec2c *begin; Cx21Rec2c *end; } Cx21Vec2c;

/* 0x88158738: minimum key over 0x2c-byte records, seeded by the field at +4 */
u32 ts4_min_key_88158738(Cx21Vec2c *s)
{
    u32 r = s->base;
    u32 n = s->end - s->begin;
    u32 i = 0;
    if (n) do {
        u32 k = s->begin[i].key;
        if (k < r) r = k;
        i++;
    } while (i < n);
    return r;
}

/* self-relative array of 0x50-byte records, keyed by the first word */
typedef struct Cx21Rel50 { u32 rel; u32 count; } Cx21Rel50;

/* 0x88153818: find the record with the given key */
u32 *ts4_find_rel50_88153818(Cx21Rel50 *h, u32 *key)
{
    u32 *r = 0;
    int i;
    for (i = 0; i < (int)h->count; i++) {
        u32 *e = (u32 *)((char *)h + (i * 0x50 + h->rel));
        if (*e == *key) { r = e; break; }
    }
    return r;
}

/* ---- float matrix: width, height, then a float vector of width*height ---- */
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif
typedef struct Cx21FVec { float *first; float *last; float *cap; } Cx21FVec;
typedef struct Cx21Mat { u32 w; u32 h; Cx21FVec v; } Cx21Mat;
extern void ts4_fvec_resize_88158B28(Cx21FVec *v, u32 n);

static void zero_vec(Cx21FVec *v)
{
    volatile Cx21FVec *vv = v;
    vv->first = 0;
    vv->last = 0;
    vv->cap = 0;
}

/* 0x88159180: copy-construct */
Cx21Mat *ts4_mat_copy_88159180(Cx21Mat *m, const Cx21Mat *src)
{
    u32 n;
    m->w = src->w;
    m->h = src->h;
    zero_vec(&m->v);
    ts4_fvec_resize_88158B28(&m->v, m->w * m->h);
    n = m->w * m->h;
    if (n != 0) memcpy(m->v.first, src->v.first, n * 4);
    return m;
}
