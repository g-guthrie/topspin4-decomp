/* CX28 /Oc batch b: vector clear helpers (Swing_DLL.xex). */
typedef unsigned int cx28_u32;

typedef struct cx28_e54 {
    char sub0[0x24];
    cx28_u32 w24, w28, w2c;
    char sub30[0x18];
    float f48;
    cx28_u32 w4c, w50;
} cx28_e54;

typedef struct cx28_vec54 {
    cx28_e54 *begin;
    cx28_e54 *end;
} cx28_vec54;

extern void fn_88150600(void *dst, void *src);
extern void ts4_loop_call_seq_u32_offc_88166278(cx28_e54 *first, cx28_e54 *last);

/* Swing_DLL.xex 0x88161128: clear the vector (copy the empty tail onto the front, destroy what remains) */
void ts4_cx28_vec54_clear_88161128(cx28_vec54 *v)
{
    cx28_e54 *last = v->end;
    cx28_e54 *p = v->begin;
    cx28_e54 *s = last;
    int n = v->end - last;
    while (n > 0) {
        fn_88150600(p->sub0, s->sub0);
        fn_88150600(p->sub0 + 0xc, s->sub0 + 0xc);
        fn_88150600(p->sub0 + 0x18, s->sub0 + 0x18);
        p->w24 = s->w24;
        p->w28 = s->w28;
        p->w2c = s->w2c;
        fn_88150600(p->sub30, s->sub30);
        fn_88150600(p->sub30 + 0xc, s->sub30 + 0xc);
        p->f48 = s->f48;
        p->w4c = s->w4c;
        p->w50 = s->w50;
        n--;
        p++;
        s++;
    }
    ts4_loop_call_seq_u32_offc_88166278(p, v->end);
    v->end = p;
}
