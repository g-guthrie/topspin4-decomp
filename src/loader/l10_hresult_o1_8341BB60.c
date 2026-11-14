/* Loader_DLL.xex 0x8341BB60-0x8341BEE0, executable version 0.0.0.3.
   Wrappers that call a worker, store its result through an output
   pointer and return a fixed failure status when the result is zero.
   Built with /O1. */
extern int fn_830AD900();
extern int fn_830ADC38();
extern int fn_830ADA28();
extern int fn_830ADB38();

int ts4l_store_result_or_fail_8341BB60(int a, int b, int *out)
{
    int r = fn_830AD900(a, b);
    *out = r;
    return r ? 0 : 0x8007000E;
}

int ts4l_store_result_or_fail_8341BCF0(int a, int b, int *out)
{
    int r = fn_830ADC38(a, b);
    *out = r;
    return r ? 0 : 0x8007000E;
}

int ts4l_store_result_or_fail_8341BDF0(int a, int b, int c, int *out)
{
    int r = fn_830ADA28(a, b, c);
    *out = r;
    return r ? 0 : 0x8007000E;
}

int ts4l_store_result_or_fail_8341BEE0(int a, int b, int c, int *out)
{
    int r = fn_830ADB38(a, b, c);
    *out = r;
    return r ? 0 : 0x8007000E;
}
