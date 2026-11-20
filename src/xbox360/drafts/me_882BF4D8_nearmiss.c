/* 0x882BF4D8: ctor; base init via fn_882B6B28, index range [first&~1, (last+1)&~1), 16-byte entry buffer, stride pair chosen by format. */
/* Near miss /O1 (agV): 2 off, the null test of the buffer is cmplwi cr0 here vs cr6 in the target (local, helper, ==0, C++ tried). */
typedef struct Desc { int p0; unsigned int fmt; } Desc;
typedef struct T {
    const void *vt;
    char pad0[0x3c - 4];
    unsigned int first;
    char pad1[0x44 - 0x40];
    unsigned int last;
    char pad2[0x80 - 0x48];
    void *buf;
    unsigned int lo;
    int c88;
    unsigned int hi;
    int c90, c94, c98;
    unsigned int n;
    int ca0;
    int ok;
    int sa8, sac;
} T;
extern char lbl_880023FC[];
void fn_882B6B28(T *t, Desc *d, int a, int b);
void *ts4_if_get_u32_lbl_88D45B38_88886180(unsigned int size);

T *fn_882BF4D8(T *t, Desc *d)
{
    unsigned int hi, n;
    fn_882B6B28(t, d, 0, 1);
    hi = (t->last + 1) & ~1u;
    t->vt = lbl_880023FC;
    t->c88 = 0;
    t->hi = hi;
    t->c94 = 0;
    t->c90 = 0;
    t->c98 = 0;
    t->ca0 = 0;
    t->ok = 1;
    t->lo = t->first & ~1u;
    n = hi - t->lo;
    t->n = n;
    t->buf = ts4_if_get_u32_lbl_88D45B38_88886180(n <= 0x0fffffff ? n << 4 : 0xffffffff);
    if (!t->buf)
        t->ok = 0;
    switch (d->fmt) {
    case 0x1828004B:
    case 0x1A20004B:
        t->sa8 = 0;
        t->sac = 8;
        break;
    case 0x1828004C:
    case 0x1A20004C:
        t->sac = 0;
        t->sa8 = 8;
        break;
    }
    return t;
}
