/* Swing_DLL.xex 0x883C00E0: kiss_fft kf_factor: splits n into radix factors (4, 2, 3, 5, 7, ...), writing (p, n/p) pairs to facbuf,
 * with floor((float)sqrt(n)) as the search bound. agAE: plain /O2 (base flags); /Oc drops the divide traps and /O1 rotates the loop. */
double floor(double x);
double sqrt(double x);
#pragma intrinsic(sqrt)
void fn_883C00E0(int n, int *facbuf)
{
    int p = 4;
    double floor_sqrt = floor((float)sqrt((double)n));
    do {
        while (n % p) {
            switch (p) {
            case 4: p = 2; break;
            case 2: p = 3; break;
            default: p += 2; break;
            }
            if (p > floor_sqrt) p = n;
        }
        n /= p;
        *facbuf++ = p;
        *facbuf++ = n;
    } while (n > 1);
}
