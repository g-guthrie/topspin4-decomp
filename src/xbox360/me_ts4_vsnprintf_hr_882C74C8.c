/* 0x882C74C8: StringCchVPrintf-style: E_INVALIDARG (0x80070057) for size 0, formats size-1 chars via the 885655D0 wrapper, terminates the buffer and returns 0x8007007A when truncated */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
int ts4_tailcall_fn_885654E8_885655D0(char *buf, unsigned int size, const char *fmt, void *args);
int ts4_vsnprintf_hr_882C74C8(char *buf, unsigned int size, const char *fmt, void *args)
{
    int hr = 0;
    unsigned int max;
    int n;
    if (!size) {
        hr = (int)0x80070057;
    } else {
        max = size - 1;
        n = ts4_tailcall_fn_885654E8_885655D0(buf, max, fmt, args);
        if (n < 0 || (unsigned int)n > max) {
            hr = (int)0x8007007A;
            buf[max] = 0;
        } else if ((unsigned int)n == max) {
            buf[max] = 0;
        }
    }
    return hr;
}
