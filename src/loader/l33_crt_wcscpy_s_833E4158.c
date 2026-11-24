/* Loader_DLL.xex 0x833E4158-0x833E420C, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: wcscpy_s. */
typedef unsigned long ts4l_u32;
extern ts4l_u32 *ts4_if_call_seq_fn_833E8350_833E9F90(void);
extern void fn_833E9D50(ts4l_u32 *e);

int ts4l_crt_wcscpy_s_833E4158(unsigned short *dest, ts4l_u32 size, const unsigned short *src)
{
    ts4l_u32 *e;
    unsigned short *p;

    {
        int ok = !!(dest != 0 && size > 0);
        if (!ok) {
            e = ts4_if_call_seq_fn_833E8350_833E9F90();
            *e = 22;
            fn_833E9D50(e);
            return 22;
        }
    }
    if (src == 0) {
        *dest = 0;
        e = ts4_if_call_seq_fn_833E8350_833E9F90();
        *e = 22;
        fn_833E9D50(e);
        return 22;
    }
    p = dest;
    while ((*p++ = *src++) != 0 && --size != 0)
        ;
    if (size == 0) {
        *dest = 0;
        e = ts4_if_call_seq_fn_833E8350_833E9F90();
        *e = 34;
        fn_833E9D50(e);
        return 34;
    }
    return 0;
}
