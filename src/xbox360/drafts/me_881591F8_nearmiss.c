/* 0x881591F8 near miss (2 off, plain and LTCG, /Oc and /O1): grid ctor that stores w and h, zeroes the float vector at +8 and resizes it to w*h (ts4_fvec_resize_88158B28). */
/* The target reloads h (+4) before w (+0) for the multiply; operand order, a local accumulator and a size() helper all load +0 first. Check: work/army/ME/v.py chk. */
typedef struct Vec { float *begin; float *end; float *cap; } Vec;
typedef struct Grid { int w; int h; Vec cells; } Grid;
void ts4_fvec_resize_88158B28(Vec *v, unsigned n);
static __inline void vec_init(Vec *v) { v->begin = 0; v->end = 0; v->cap = 0; }
Grid *ts4_grid_ctor_881591F8(Grid *g, int w, int h)
{
    g->w = w;
    g->h = h;
    vec_init(&g->cells);
    ts4_fvec_resize_88158B28(&g->cells, g->w * g->h);
    return g;
}
