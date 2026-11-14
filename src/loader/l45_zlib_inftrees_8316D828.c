/* Loader_DLL.xex 0x8316D828-0x8316DAC8, executable version 0.0.0.3.
 * zlib 1.1.4 inftrees.c (first copy): inflate_trees_bits, inflate_trees_dynamic; huft_build is a same-TU static helper
 * (the real one is fn_8316D348, which needs /GS and is not delivered). */
#include "l45_zlib_inflate.h"

extern char lbl_83007FB4[];
extern char lbl_83007F90[];
extern char lbl_83008060[];
extern char lbl_83008044[];
extern char lbl_83008020[];
extern char lbl_83007FFC[];
extern char lbl_83007FDC[];
static const uInt cplens[31] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
                                35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258, 0, 0};
static const uInt cplext[31] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
                                3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0, 112, 112};
static const uInt cpdist[30] = {1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193,
                                257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145, 8193,
                                12289, 16385, 24577};
static const uInt cpdext[30] = {0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
                                7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13};


#ifdef _MSC_VER
__declspec(noinline)
#endif
#define BMAX 15
#define MANY 1440

static int huft_build(uInt *b, uInt n, uInt s, const uInt *d, const uInt *e,
                                  inflate_huft **t, uInt *m, inflate_huft *hp, uInt *hn,
                                  uInt *v)
{
    uInt a;
    uInt c[BMAX + 1];
    uInt f;
    int g;
    int h;
    register uInt i;
    register uInt j;
    register int k;
    int l;
    uInt mask;
    uInt *p;
    inflate_huft *q;
    struct inflate_huft_s r;
    inflate_huft *u[BMAX];
    register int w;
    uInt x[BMAX + 1];
    uInt *xp;
    int y;
    uInt z;

    p = c;
#define C0 *p++ = 0;
#define C2 C0 C0 C0 C0
#define C4 C2 C2 C2 C2
    C4
    p = b;
    i = n;
    do {
        c[*p++]++;
    } while (--i);
    if (c[0] == n) {
        *t = (inflate_huft *)0;
        *m = 0;
        return 0;
    }

    l = *m;
    for (j = 1; j <= BMAX; j++)
        if (c[j])
            break;
    k = j;
    if ((uInt)l < j)
        l = j;
    for (i = BMAX; i; i--)
        if (c[i])
            break;
    g = i;
    if ((uInt)l > i)
        l = i;
    *m = l;

    for (y = 1 << j; j < i; j++, y <<= 1)
        if ((y -= c[j]) < 0)
            return -3;
    if ((y -= c[i]) < 0)
        return -3;
    c[i] += y;

    x[1] = j = 0;
    p = c + 1;
    xp = x + 2;
    while (--i) {
        *xp++ = (j += *p++);
    }

    p = b;
    i = 0;
    do {
        if ((j = *p++) != 0)
            v[x[j]++] = i;
    } while (++i < n);
    n = x[g];

    x[0] = i = 0;
    p = v;
    h = -1;
    w = -l;
    u[0] = (inflate_huft *)0;
    q = (inflate_huft *)0;
    z = 0;

    for (; k <= g; k++) {
        a = c[k];
        while (a--) {
            while (k > w + l) {
                h++;
                w += l;

                z = g - w;
                z = z > (uInt)l ? l : z;
                if ((f = 1 << (j = k - w)) > a + 1) {
                    f -= a + 1;
                    xp = c + k;
                    if (j < z)
                        while (++j < z) {
                            if ((f <<= 1) <= *++xp)
                                break;
                            f -= *xp;
                        }
                }
                z = 1 << j;

                if (*hn + z > MANY)
                    return -3;
                u[h] = q = hp + *hn;
                *hn += z;

                if (h) {
                    x[h] = i;
                    r.bits = (Byte)l;
                    r.exop = (Byte)j;
                    j = i >> (w - l);
                    r.base = (uInt)(q - u[h - 1] - j);
                    u[h - 1][j] = r;
                } else
                    *t = q;
            }

            r.bits = (Byte)(k - w);
            if (p >= v + n)
                r.exop = 128 + 64;
            else if (*p < s) {
                r.exop = (Byte)(*p < 256 ? 0 : 32 + 64);
                r.base = *p++;
            } else {
                r.exop = (Byte)(e[*p - s] + 16 + 64);
                r.base = d[*p++ - s];
            }

            f = 1 << (k - w);
            for (j = i >> w; j < z; j += f)
                q[j] = r;

            for (j = 1 << (k - 1); i & j; j >>= 1)
                i ^= j;
            i ^= j;

            mask = (1 << w) - 1;
            while ((i & mask) != x[h]) {
                h--;
                w -= l;
                mask = (1 << w) - 1;
            }
        }
    }

    return y != 0 && g != 1 ? -5 : 0;
}

int ts4l_zlib_inflate_trees_bits_8316D828(uInt *c, uInt *bb, inflate_huft **tb, inflate_huft *hp,
                                          z_stream *z)
{
    int r;
    uInt hn = 0;
    uInt *v;

    if ((v = (uInt *)ZALLOC(z, 19, sizeof(uInt))) == (uInt *)0)
        return -4;

    r = huft_build(c, 19, 19, (uInt *)0, (uInt *)0, tb, bb, hp, &hn, v);
    if (r == -3)
        z->msg = lbl_83007FB4;
    else if (r == -5 || *bb == 0) {
        z->msg = lbl_83007F90;
        r = -3;
    }

    ZFREE(z, v);
    return r;
}

int ts4l_zlib_inflate_trees_dynamic_8316D908(uInt nl, uInt nd, uInt *c, uInt *bl, uInt *bd,
                                             inflate_huft **tl, inflate_huft **td,
                                             inflate_huft *hp, z_stream *z)
{
    int r;
    uInt hn = 0;
    uInt *v;

    if ((v = (uInt *)ZALLOC(z, 288, sizeof(uInt))) == (uInt *)0)
        return -4;

    r = huft_build(c, nl, 257, cplens, cplext, tl, bl, hp, &hn, v);
    if (r != 0 || *bl == 0) {
        if (r == -3)
            z->msg = lbl_83007FFC;
        else if (r != -4) {
            z->msg = lbl_83007FDC;
            r = -3;
        }
        ZFREE(z, v);
        return r;
    }

    r = huft_build(c + nl, nd, 0, cpdist, cpdext, td, bd, hp, &hn, v);
    if (r != 0 || (*bd == 0 && nl > 257)) {
        if (r == -3)
            z->msg = lbl_83008060;
        else if (r == -5) {
            z->msg = lbl_83008044;
            r = -3;
        } else if (r != -4) {
            z->msg = lbl_83008020;
            r = -3;
        }
        ZFREE(z, v);
        return r;
    }

    ZFREE(z, v);
    return 0;
}
