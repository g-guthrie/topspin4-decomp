/* 0x8856E7E0: unbiased binary exponent of a double read from its high halfword (frexp style) */
/* Matched on /Os plain and LTCG (work/army/ME/v.py chk). */
int ts4_double_exponent_8856E7E0(double x)
{
    int e = ((*(unsigned short *)&x >> 4) & 0x7ff) - 0x3fe;
    return (short)e;
}
