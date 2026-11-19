/* Swing_DLL.xex 0x88516C28: Integer factorial: 1 for n <= 0, a stack table for n <= 10, then multiplies on from 11.
 * Leaf; the 11-entry table is built on the stack each call; /Oc. */
int fn_88516C28(int n)
{
    int table[11] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800 };
    int r, i;
    if (n <= 0) return 1;
    if (n <= 10) return table[n];
    r = table[10];
    for (i = 11; i <= n; i++) r *= i;
    return r;
}
