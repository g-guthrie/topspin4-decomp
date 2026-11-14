/* Swing_DLL.xex 0x881AD8E0-0x881AD968, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;
struct elem { u32 a; u8 b; u32 c, d, e, f, g, h, i, j, k; };
struct vec { struct elem *first; struct elem *last; };
void ts4_vec_erase_tail_881AD8E0(struct vec *v)
{
    struct elem *dst = v->first;
    struct elem *src = v->last;
    int n = (int)(v->last - src);
    for (; n > 0; --n) {
        dst->a = src->a; dst->b = src->b; dst->c = src->c; dst->d = src->d; dst->e = src->e;
        dst->f = src->f; dst->g = src->g; dst->h = src->h; dst->i = src->i; dst->j = src->j; dst->k = src->k;
        ++dst;
        ++src;
    }
    v->last = dst;
}
