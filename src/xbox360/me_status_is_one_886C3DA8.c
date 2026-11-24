/* Swing_DLL.xex 0x886C3DA8: status callback, true when *status == 1.
 * The 64-bit return type is what keeps the `li r3,1; cmpwi; beqlr; li r3,0` branch form;
 * with a 32-bit return the compiler folds the test to cntlzw/extrwi. */
#ifdef _MSC_VER
typedef __int64 ts4_s64;
#else
typedef long long ts4_s64;
#endif
ts4_s64 ts4_status_is_one_886C3DA8(void *self, int *status)
{
    (void)self;
    if (*status == 1)
        return 1;
    return 0;
}
