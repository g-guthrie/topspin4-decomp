/* Loader_DLL.xex 0x831D50A0-0x831D5134, executable version 0.0.0.3. */
typedef unsigned int u32;
struct BitW { u32 pad0; u32 *base; u32 *cur; u32 acc; u32 left; };

void ts4l_bitw_put_831D50A0(struct BitW *w, u32 val, u32 n)
{
    u32 v, left, r, *p;
    v = val & ~(0xFFFFFFFFu << n);
    left = w->left;
    if (left > n) {
        left -= n;
        w->left = left;
        w->acc ^= v << left;
        return;
    }
    p = w->cur;
    *p = (v >> (n - left)) ^ w->acc;
    w->cur = p + 1;
    w->base++;
    r = n - w->left;
    if (r != 0) {
        left = 32 - r;
        w->left = left;
        w->acc = v << left;
        return;
    }
    w->acc = 0;
    w->left = 32;
}
