/* CX28 /Oc batch g: vector erase/clear helpers (Swing_DLL.xex). */
typedef unsigned int cx28_u32;

extern void fn_88150600(void *dst, void *src);

typedef struct cx28_e60 {
    char sub0[0x24];
    cx28_u32 w24, w28, w2c;
    char sub30[0x24];
    cx28_u32 w54, w58, w5c;
} cx28_e60;

typedef struct cx28_vec60 {
    cx28_e60 *begin;
    cx28_e60 *end;
} cx28_vec60;

extern void ts4_loop_call_seq_u32_offc_881661F8(cx28_e60 *first, cx28_e60 *last);

/* Swing_DLL.xex 0x88161C20: erase [dst, first) shifting the tail of 0x60-byte elements down; returns dst */
cx28_e60 *ts4_cx28_vec60_erase_88161C20(cx28_vec60 *v, cx28_e60 *dst, cx28_e60 *first)
{
    int n = v->end - first;
    cx28_e60 *p = dst;
    cx28_e60 *s;
    if (n > 0)
        s = first;
    while (n > 0) {
        fn_88150600(p->sub0, s->sub0);
        fn_88150600(p->sub0 + 0xc, s->sub0 + 0xc);
        fn_88150600(p->sub0 + 0x18, s->sub0 + 0x18);
        p->w24 = s->w24;
        p->w28 = s->w28;
        p->w2c = s->w2c;
        fn_88150600(p->sub30, s->sub30);
        fn_88150600(p->sub30 + 0xc, s->sub30 + 0xc);
        fn_88150600(p->sub30 + 0x18, s->sub30 + 0x18);
        p->w54 = s->w54;
        p->w58 = s->w58;
        p->w5c = s->w5c;
        n--;
        p++;
        s++;
    }
    ts4_loop_call_seq_u32_offc_881661F8(p, v->end);
    v->end = p;
    return dst;
}
