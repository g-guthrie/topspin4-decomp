/* Loader_DLL.xex 0x8321F1D0-0x8321F274, executable version 0.0.0.3. */
/* Forward to a worker, store its result through the out pointer and map a zero
 * result to the failure code 0x8007000E (out of memory). */
extern int fn_830AF340();
extern int fn_830AF638();

int ts4l_call_store_result_8321F1D0(int u, int a, int b, int c, int d, int *out)
{
    int r;

    (void)u;
    (void)c;
    r = fn_830AF340(a, b, d);
    *out = r;
    return r == 0 ? 0x8007000e : 0;
}

int ts4l_call_store_result_8321F220(int u, int a, int b, int c, int d, int *out)
{
    int r;

    (void)u;
    r = fn_830AF638(a, b, c, d);
    *out = r;
    return r == 0 ? 0x8007000e : 0;
}
