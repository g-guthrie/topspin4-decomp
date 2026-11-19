/* 0x8856E7F8: Classifies a double: 1 for +inf, 2 for -inf, 3 for quiet NaN, 4 for signalling NaN, otherwise 0. */
/* Matched on /O1 (agAH). Read the bits through a pointer to the parameter (its home slot at 0x10(r1)); a local union copy uses -0x10(r1). */
typedef union DoubleBits { double d; struct { unsigned int hi; unsigned int lo; } w; unsigned short h[4]; } DoubleBits;
int fn_8856E7F8(double x)
{
    DoubleBits *u = (DoubleBits *)&x;
    unsigned short e;
    if (u->w.hi == 0x7FF00000u && u->w.lo == 0)
        return 1;
    if (u->w.hi == 0xFFF00000u && u->w.lo == 0)
        return 2;
    e = u->h[0] & 0x7FF8;
    if (e == 0x7FF8)
        return 3;
    if (e == 0x7FF0 && ((u->w.hi & 0x7FFFF) != 0 || u->w.lo != 0))
        return 4;
    return 0;
}
