/* W7A batch G: LTCG-route functions whose callee is a matched function (context: ga1_gameplay_a.c with /Ob1,
   pp1_pool_primer.c; /Oc). */

/* 0x88648020: append a tagged element (source record, two floats, a float pair) to the controller's vector. */
typedef struct W7aEl_8020 { unsigned head; void *rec; float f8, fc, f10, f14; unsigned char b18; } W7aEl_8020;
typedef struct W7aHd_8020 { int rel; } W7aHd_8020;
typedef struct W7aObj8_8020 { char pad[0x60]; W7aHd_8020 h; } W7aObj8_8020;
typedef struct W7aObj_8020 { char pad[8]; W7aObj8_8020 *o8; } W7aObj_8020;
typedef struct W7aVec_8020 { int pad; W7aEl_8020 *end; W7aEl_8020 *cap; char p2[0xa8 - 0xc]; W7aObj_8020 *o; } W7aVec_8020;
extern W7aEl_8020 *ts4_element_vector_emplace_zeroed_88646318(W7aVec_8020 *vec);
void ts4_push_tagged_element_88648020(W7aVec_8020 *v, int idx, float a, const float *p, float b)
{
    W7aHd_8020 *h = &v->o->o8->h;
    void *src = (char *)h + (idx * 0x1c + h->rel);
    W7aEl_8020 *e = ts4_element_vector_emplace_zeroed_88646318(v);
    e->f10 = b;
    e->f14 = a;
    e->rec = src;
    e->head = 1;
    e->b18 = 1;
    e->fc = p[0];
    e->f8 = p[1];
}
