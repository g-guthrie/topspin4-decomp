/* Swing_DLL.xex 0x883E0960: Fisher-Yates style shuffle of n ints using ts4_crt_rand_88564110; if the new first element equals the
 * old last one, swaps it with a random later element so no value repeats across the boundary. agAE: /O1. */
int ts4_crt_rand_88564110(void);
void fn_883E0960(int *a, int n)
{
    int last = a[n - 1];
    int i, j, t;
    for (i = 0; i < n; i++) {
        j = ts4_crt_rand_88564110() % (n - i) + i;
        t = a[j];
        a[j] = a[i];
        a[i] = t;
    }
    if (a[0] == last) {
        j = ts4_crt_rand_88564110() % (n - 1) + 1;
        t = a[j];
        a[j] = a[0];
        a[0] = t;
    }
}
