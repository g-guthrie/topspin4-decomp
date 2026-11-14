/* Swing_DLL.xex 0x88574528-0x88574610, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: strcat_s. */
typedef unsigned int u32;
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(void);

int ts4_crt_strcat_s_88574528(char *dest, u32 size, const char *src)
{
    char *p;
    u32 avail = size;
    u32 *e;
    {
        int ok = !!(dest != 0 && size > 0);
        if (!ok) {
            e = ts4_if_call_seq_fn_8856CD88_88567ED8();
            *e = 22;
            fn_8856D2C0();
            return 22;
        }
    }
    if (src == 0) {
        *dest = 0;
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0();
        return 22;
    }
    p = dest;
    while (avail > 0 && *p != 0) {
        --avail;
        ++p;
    }
    if (avail == 0) {
        *dest = 0;
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0();
        return 22;
    }
    while ((*p++ = *src++) != 0 && --avail > 0)
        ;
    if (avail == 0) {
        *dest = 0;
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 34;
        fn_8856D2C0();
        return 34;
    }
    return 0;
}
