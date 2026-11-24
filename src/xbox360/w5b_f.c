/* W5B batch F */
static const float w5b_zero = 0.0f;
static __inline float w5b_min(float a, float b) { return (a - b >= w5b_zero) ? b : a; }
static __inline float w5b_max(float a, float b) { return (a - b >= w5b_zero) ? a : b; }

extern void fn_886C5820(float *a, float *b, float *out);

typedef struct W5fRect { unsigned char pad00[8]; float x; float y; } W5fRect;

int ts4_rect_overlap_project_886C9110(W5fRect *a, W5fRect *b, float *out1, float *out2)
{
    float ox = w5b_max(a->x, b->x);
    float oy = w5b_min(a->y, b->y);
    int hit = 1;
    if (ox > oy)
        hit = 0;
    if ((unsigned char)hit) {
        float p[2], q[2];
        q[0] = ox; q[1] = oy;
        p[0] = a->x; p[1] = a->y;
        fn_886C5820(p, q, out1);
        p[0] = b->x; p[1] = b->y;
        fn_886C5820(p, q, out2);
    }
    return hit;
}
