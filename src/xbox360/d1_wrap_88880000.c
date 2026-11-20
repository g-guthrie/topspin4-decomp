/* Swing_DLL.xex 0x88888508-0x88888538, executable version 0.0.0.3.
 * Small wrappers: a stack frame around one or two calls. The names
 * describe that behaviour and end in the function address. */

extern void * ts4_crt_nh_malloc_88565258(int);
extern void fn_886263E8(void *);

void ts4_call_guarded_88888508(void)
{
    void *result1 = ts4_crt_nh_malloc_88565258(296);
    if (result1 != 0) {
        fn_886263E8(result1);
    }
}
