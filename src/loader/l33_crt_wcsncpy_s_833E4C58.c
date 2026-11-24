/* Loader_DLL.xex 0x833E4C58-0x833E4DA0, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: wcsncpy_s. */
typedef unsigned long ts4l_u32;
extern ts4l_u32 *ts4_if_call_seq_fn_833E8350_833E9F90(void);
extern void fn_833E9D50(ts4l_u32 *e);

int ts4l_crt_wcsncpy_s_833E4C58(unsigned short *dest, ts4l_u32 size, const unsigned short *src, ts4l_u32 count)
{
    ts4l_u32 *e;
    unsigned short *p;
    ts4l_u32 available;

    if (count == 0 && dest == 0 && size == 0)
        return 0;
    {
        int ok = !!(dest != 0 && size > 0);
        if (!ok) {
            e = ts4_if_call_seq_fn_833E8350_833E9F90();
            *e = 22;
            fn_833E9D50(e);
            return 22;
        }
    }
    if (count == 0) {
        *dest = 0;
        return 0;
    }
    if (src == 0) {
        *dest = 0;
        e = ts4_if_call_seq_fn_833E8350_833E9F90();
        *e = 22;
        fn_833E9D50(e);
        return 22;
    }
    p = dest;
    available = size;
    if (count == (ts4l_u32)-1) {
        while ((*p++ = *src++) != 0 && --available > 0)
            ;
    } else {
        while ((*p++ = *src++) != 0 && --available > 0 && --count > 0)
            ;
        if (count == 0)
            *p = 0;
    }
    if (available == 0) {
        if (count == (ts4l_u32)-1) {
            dest[size - 1] = 0;
            return 80;
        }
        *dest = 0;
        e = ts4_if_call_seq_fn_833E8350_833E9F90();
        *e = 34;
        fn_833E9D50(e);
        return 34;
    }
    return 0;
}
