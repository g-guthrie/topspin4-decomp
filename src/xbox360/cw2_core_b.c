/* CW2 batch b: vector clear / erase-all helpers over fixed-size elements (Swing_DLL.xex).
   Compiled with /Oc: the element count is a signed divide by the element size. */
typedef unsigned int cw2_u32;
typedef unsigned char cw2_u8;

void fn_881BD170(void *, void *);
void fn_88166108(void *, void *);
void ts4_destroy_rec30_range_88166178(void *, void *);
void fn_88162CC8(void *, void *);
void fn_88150600(void *, void *);

/* 0x28-byte element: five words, one byte, one word, one 12-byte sub-object */
struct Cw2E28 {
    cw2_u32 w0, w1, w2, w3, w4;
    cw2_u8 b;
    cw2_u8 pad[3];
    cw2_u32 w5;
    char sub[0xc];
};
struct Cw2Vec28 {
    struct Cw2E28 *begin;
    struct Cw2E28 *end;
};

static struct Cw2E28 *cw2_copy28(struct Cw2E28 *first, struct Cw2E28 *last, struct Cw2E28 *dst)
{
    int n = last - first;
    for (; n > 0; --n) {
        dst->w0 = first->w0;
        dst->w1 = first->w1;
        dst->w2 = first->w2;
        dst->w3 = first->w3;
        dst->w4 = first->w4;
        dst->b = first->b;
        dst->w5 = first->w5;
        fn_881BD170(dst->sub, first->sub);
        ++first;
        ++dst;
    }
    return dst;
}

/* Swing_DLL.xex 0x88160E20: erase the whole range of 0x28-byte elements (destroy the tail, set end) */
void ts4_cw2_vec28_clear_88160E20(struct Cw2Vec28 *v)
{
    struct Cw2E28 *dst = cw2_copy28(v->end, v->end, v->begin);
    fn_88166108(dst, v->end);
    v->end = dst;
}

/* 0x30-byte element: a sub-object copied by fn_88162CC8, then three 12-byte sub-objects copied by fn_88150600 */
struct Cw2E30 {
    char a[0xc];
    char b[0xc];
    char c[0xc];
    char d[0xc];
};
struct Cw2Vec30 {
    struct Cw2E30 *begin;
    struct Cw2E30 *end;
};

static struct Cw2E30 *cw2_copy30(struct Cw2E30 *first, struct Cw2E30 *last, struct Cw2E30 *dst)
{
    int n = last - first;
    for (; n > 0; --n) {
        fn_88162CC8(dst, first);
        fn_88150600(dst->b, first->b);
        fn_88150600(dst->c, first->c);
        fn_88150600(dst->d, first->d);
        ++first;
        ++dst;
    }
    return dst;
}

/* Swing_DLL.xex 0x88160F30: erase the whole range of 0x30-byte elements */
void ts4_cw2_vec30_clear_88160F30(struct Cw2Vec30 *v)
{
    struct Cw2E30 *dst = cw2_copy30(v->end, v->end, v->begin);
    ts4_destroy_rec30_range_88166178(dst, v->end);
    v->end = dst;
}
