/* CX28 /Oc batch p: vector resize (Swing_DLL.xex). */
typedef unsigned int cx28_u32;

typedef struct cx28_e12r {
    cx28_u32 w[3];
} cx28_e12r;

typedef struct cx28_vec12r {
    cx28_e12r *begin;
    cx28_e12r *end;
} cx28_vec12r;

extern void fn_88163390(cx28_vec12r *v, cx28_e12r *pos, cx28_u32 n, cx28_e12r *val);

/* Swing_DLL.xex 0x88161240: resize to n elements (shrink erases the tail, grow appends default elements) */
void ts4_cx28_vec12r_resize_88161240(cx28_vec12r *v, cx28_u32 n)
{
    cx28_e12r def;
    cx28_e12r *first;
    cx28_e12r *p;
    cx28_e12r *s;
    int cnt;
    def.w[0] = 0;
    def.w[1] = 0xfffff;
    def.w[2] = 0;
    if (n < (cx28_u32)(v->end - v->begin)) {
        first = v->end;
        p = v->begin + n;
        s = first;
        cnt = v->end - first;
        while (cnt > 0) {
            *p = *s;
            cnt--;
            p++;
            s++;
        }
        v->end = p;
    } else {
        fn_88163390(v, v->end, n - (v->end - v->begin), &def);
    }
}
