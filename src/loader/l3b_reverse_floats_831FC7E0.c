/* Loader_DLL.xex 0x831FC7E0-0x8326F238, executable version 0.0.0.3.
 * In-place reversal of a float array. */



void ts4l_reverse_floats_831FC7E0(float *a, int n)
{
    int i;
    float *p = a;
    float *q = a + n - 1;
    float t;
    for (i = 0; i < n / 2; i++) {
        t = *p;
        *p = *q;
        *q = t;
        p++;
        q--;
    }
}

void ts4l_reverse_floats_8326F238(float *a, int n)
{
    int i;
    float *p = a;
    float *q = a + n - 1;
    float t;
    for (i = 0; i < n / 2; i++) {
        t = *p;
        *p = *q;
        *q = t;
        p++;
        q--;
    }
}
