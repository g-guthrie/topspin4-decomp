/* 0x8856E7B8: replaces the exponent of x with e (ldexp-style helper, pairs with ts4_double_exponent_8856E7E0) */
/* Matched on /Os plain and LTCG (work/army/ME/v.py chk). */
double ts4_double_set_exponent_8856E7B8(double x, int e)
{
    double y = x;
    *(unsigned short *)&y = (unsigned short)((*(unsigned short *)&x & 0x800f) | ((e + 0x3fe) << 4));
    return y;
}
