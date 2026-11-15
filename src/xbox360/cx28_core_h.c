/* CX28 batch h: vector insert-with-grow helpers (Swing_DLL.xex). */
typedef unsigned int cx28_u32;

typedef struct cx28_e16 {
    cx28_u32 w[4];
} cx28_e16;

typedef struct cx28_vec16 {
    cx28_e16 *begin;
    cx28_e16 *end;
    cx28_e16 *cap;
} cx28_vec16;

extern void *lbl_88D45B38;
extern void *ts4_if_call_seq_fn_88883CD0_8860D250(void *);
extern void *fn_88613570(void *owner, cx28_u32 size, cx28_u32 align, void *cap_ptr);
extern void ts4_destroy_owned_object(void *);

typedef struct cx28_e12 {
    cx28_u32 w[3];
} cx28_e12;

typedef struct cx28_vec12 {
    cx28_e12 *begin;
    cx28_e12 *end;
    cx28_e12 *cap;
} cx28_vec12;

/* Swing_DLL.xex 0x88162858: grow a vector of 12-byte elements and copy the existing ones across (no new element) */
void ts4_cx28_vec12_grow_88162858(cx28_vec12 *v, cx28_e12 *pos)
{
    cx28_u32 one = 1;
    cx28_u32 cnt = v->end - v->begin;
    cx28_u32 *m;
    cx28_u32 ncap;
    cx28_e12 *buf;
    cx28_e12 *s;
    cx28_e12 *d;
    if (cnt < 1)
        m = &one;
    else
        m = &cnt;
    ncap = *m + cnt;
    buf = 0;
    if (ncap != 0) {
        void *o = lbl_88D45B38;
        buf = (cx28_e12 *)fn_88613570(o ? ts4_if_call_seq_fn_88883CD0_8860D250(o) : 0, ncap * 12, 4, &v->cap);
    }
    d = buf;
    for (s = v->begin; s != pos; s++, d++) {
        if (d)
            *d = *s;
    }
    ts4_destroy_owned_object(v->begin);
    v->begin = buf;
    v->end = d;
    v->cap = buf + ncap;
}
