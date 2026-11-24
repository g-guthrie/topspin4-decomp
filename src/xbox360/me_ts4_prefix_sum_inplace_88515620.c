/* 0x88515620: Turns a[0..n) into its running sum in place. */
/* Matched on /Oc (agAH). A separate element pointer alongside the counter gives the 4x unrolled loop plus the bdnz remainder loop seen in the target. */
void fn_88515620(float *a, unsigned int n)
{
    float sum = a[0];
    float *p = a + 1;
    unsigned int i;
    for (i = 1; i < n; i++, p++) {
        sum += *p;
        *p = sum;
    }
}
