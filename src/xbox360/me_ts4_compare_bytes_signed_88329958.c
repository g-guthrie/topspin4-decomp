/* 0x88329958: Compares n bytes of a and b and returns the first non-zero difference a[i] - b[i] truncated to signed char (sign-extended), or 0. */
/* Matched on /Oc (agAH). Walk a copy of a and read b as p[b - a] (gives the subf/lbzx form); do-while after an n > 0 test; int return of a signed char. */
int fn_88329958(const unsigned char *a, const unsigned char *b, int n)
{
    const unsigned char *p = a;
    signed char d = 0;
    if (n > 0) {
        do {
            d = (signed char)(*p - p[b - a]);
            if (d != 0)
                break;
            p++;
        } while (--n > 0);
    }
    return d;
}
