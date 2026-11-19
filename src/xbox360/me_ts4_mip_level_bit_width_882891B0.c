/* 0x882891B0: Bit width (32 - clz) of the largest of width-2L, height-2L and max(depth-2L, 1) for level L. */
/* Matched on /O1 (agAH). A nested MAX macro (it re-evaluates inner terms) with the intrinsic _CountLeadingZeros. */
#define MAX(a, b) ((a) > (b) ? (a) : (b))
unsigned int _CountLeadingZeros(unsigned long v);
#pragma intrinsic(_CountLeadingZeros)
int fn_882891B0(unsigned int width, unsigned int height, int depth, int level)
{
    int t = level * 2;
    unsigned int size = MAX(width - t, MAX(height - t, MAX(depth - t, 1)));
    return 32 - _CountLeadingZeros(size);
}
