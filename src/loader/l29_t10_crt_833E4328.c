/* Loader_DLL.xex 0x833E4328-0x833E43D4, 0x833E5790-0x833E5838, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _wcsicmp and _wcslwr_s (ASCII-range case folding). */
typedef unsigned long ts4l_u32;
extern ts4l_u32 *ts4_if_call_seq_fn_833E8350_833E9F90(void);
extern void fn_833E9D50(ts4l_u32 *e);
extern ts4l_u32 fn_833F5438(unsigned short *s, ts4l_u32 n);

int ts4l_crt_wcsicmp_833E4328(const unsigned short *a, const unsigned short *b)
{
    unsigned short f, l;
    ts4l_u32 *e;
    if (a == 0) {
        e = ts4_if_call_seq_fn_833E8350_833E9F90();
        *e = 22;
        fn_833E9D50(e);
        return 0x7fffffff;
    }
    if (b == 0) {
        e = ts4_if_call_seq_fn_833E8350_833E9F90();
        *e = 22;
        fn_833E9D50(e);
        return 0x7fffffff;
    }
    do {
        f = (unsigned short)((*a >= 'A' && *a <= 'Z') ? *a + 32 : *a);
        l = (unsigned short)((*b >= 'A' && *b <= 'Z') ? *b + 32 : *b);
        a++;
        b++;
    } while (f != 0 && f == l);
    return (int)f - (int)l;
}

int ts4l_crt_wcslwr_s_833E5790(unsigned short *s, ts4l_u32 n)
{
    ts4l_u32 *e;
    if (s == 0) {
        e = ts4_if_call_seq_fn_833E8350_833E9F90();
        *e = 22;
        fn_833E9D50(e);
        return 22;
    }
    if (fn_833F5438(s, n) >= n) {
        *s = 0;
        e = ts4_if_call_seq_fn_833E8350_833E9F90();
        *e = 22;
        fn_833E9D50(e);
        return 22;
    }
    while (*s != 0) {
        if (*s >= 'A' && *s <= 'Z') *s += 32;
        s++;
    }
    return 0;
}

int ts4l_crt_wcsnicmp_833E50F8(const unsigned short *a, const unsigned short *b, ts4l_u32 n)
{
    unsigned short f, l;
    ts4l_u32 *e;
    int ret = 0;
    if (n != 0) {
        if (a == 0) {
            e = ts4_if_call_seq_fn_833E8350_833E9F90();
            *e = 22;
            fn_833E9D50(e);
            return 0x7fffffff;
        }
        if (b == 0) {
            e = ts4_if_call_seq_fn_833E8350_833E9F90();
            *e = 22;
            fn_833E9D50(e);
            return 0x7fffffff;
        }
        do {
            f = (unsigned short)((*a >= 'A' && *a <= 'Z') ? *a + 32 : *a);
            l = (unsigned short)((*b >= 'A' && *b <= 'Z') ? *b + 32 : *b);
            a++;
            b++;
        } while (--n != 0 && f != 0 && f == l);
        ret = (int)f - (int)l;
    }
    return ret;
}

int ts4l_crt_wcsnicmp_833E51C0(const unsigned short *a, const unsigned short *b, ts4l_u32 n)
{
    unsigned short f, l;
    ts4l_u32 *e;
    int ret = 0;
    if (n != 0) {
        if (a == 0) {
            e = ts4_if_call_seq_fn_833E8350_833E9F90();
            *e = 22;
            fn_833E9D50(e);
            return 0x7fffffff;
        }
        if (b == 0) {
            e = ts4_if_call_seq_fn_833E8350_833E9F90();
            *e = 22;
            fn_833E9D50(e);
            return 0x7fffffff;
        }
        do {
            f = (unsigned short)((*a >= 'A' && *a <= 'Z') ? *a + 32 : *a);
            l = (unsigned short)((*b >= 'A' && *b <= 'Z') ? *b + 32 : *b);
            a++;
            b++;
        } while (--n != 0 && f != 0 && f == l);
        ret = (int)f - (int)l;
    }
    return ret;
}

int ts4l_crt_wcslwr_s_833E5838(unsigned short *s, ts4l_u32 n)
{
    ts4l_u32 *e;
    if (s == 0) {
        e = ts4_if_call_seq_fn_833E8350_833E9F90();
        *e = 22;
        fn_833E9D50(e);
        return 22;
    }
    if (fn_833F5438(s, n) >= n) {
        *s = 0;
        e = ts4_if_call_seq_fn_833E8350_833E9F90();
        *e = 22;
        fn_833E9D50(e);
        return 22;
    }
    while (*s != 0) {
        if (*s >= 'A' && *s <= 'Z') *s += 32;
        s++;
    }
    return 0;
}
