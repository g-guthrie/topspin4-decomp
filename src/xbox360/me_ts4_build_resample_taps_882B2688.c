/* 0x882B2688: builds n linear-resampling taps over total source samples: {prev index, weight, next index, 1-weight}, clamping or wrapping at the ends; returns the 16-byte tap array (overflow-checked alloc) */
/* Matched on /O1 plain only (agV, v.py chk). */
typedef struct Tap { int prev; float w0; int next; float w1; } Tap;
void *ts4_if_get_u32_lbl_88D45B38_88886180(unsigned int size);

Tap *fn_882B2688(unsigned int total, unsigned int n, int wrap)
{
    Tap *t;
    float step;
    unsigned int i;
    t = (Tap *)ts4_if_get_u32_lbl_88D45B38_88886180(n <= 0x0fffffff ? n << 4 : 0xffffffff);
    if (t) {
        step = (float)total / (float)n;
        for (i = 0; i < n; i++) {
            float pos = ((float)i + 0.5f) * step + 0.5f;
            int k = (int)pos;
            float frac = ((float)k + 1.0f) - pos;
            int prev, next;
            prev = k - 1;
            if (prev < 0)
                prev = wrap ? total - 1 : 0;
            next = k;
            if ((unsigned int)next >= total)
                next = wrap ? 0 : total - 1;
            t[i].w0 = frac;
            t[i].prev = prev;
            t[i].next = next;
            t[i].w1 = 1.0f - frac;
        }
    }
    return t;
}
