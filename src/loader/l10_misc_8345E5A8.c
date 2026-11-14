/* Loader_DLL.xex 0x8345E5A8-0x8345E5A8, executable version 0.0.0.3.
   Hand-cracked single functions. */
extern int fn_8345E408();

/* Bump a per-slot counter, or hand the slot's entry and sign-extended
   tag byte to the generic handler. */
void ts4l_count_or_dispatch_8345E5A8(int **o, int a, int b)
{
    if (((int *)o)[3]) {
        int *t = o[a + 0x17];
        int *p = t + b;
        (*p)++;
    } else {
        int *t = o[a + 0x13];
        fn_8345E408(o, t[b], ((signed char *)t)[b + 0x400]);
    }
}
