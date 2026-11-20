/* 0x882CF300: sibling of 882B2688 using the tagged allocator fn_88888668(n*16, 0x24810000): builds n linear-resampling taps {prev, weight, next, 1-weight} over total samples, clamping or wrapping at the ends */
/* Matched on /O1 plain only (agV, v.py chk). */
typedef struct Tap { int prev; float w0; int next; float w1; } Tap;
void *fn_88888668(unsigned int size, unsigned int tag);

Tap *fn_882CF300(unsigned int total, unsigned int n, int wrap)
{
    Tap *t;
    float step;
    unsigned int i;
    t = (Tap *)fn_88888668(n << 4, 0x24810000);
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
