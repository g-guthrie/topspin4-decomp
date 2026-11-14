/* Swing_DLL.xex 0x8856A4B8-0x8856CCFC, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: validated string routines. */
typedef unsigned int u32;
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(void);

char *ts4_crt_strlwr_8856CC88(char *s)
{
    char *p;
    u32 *e;
    if (s == 0) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0();
        return 0;
    }
    for (p = s; *p; ++p) {
        char c = *p;
        if (c >= 'A' && c <= 'Z')
            *p = c + 32;
    }
    return s;
}

char *ts4_crt_strupr_8856A4B8(char *s)
{
    char *p;
    u32 *e;
    if (s == 0) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0();
        return 0;
    }
    for (p = s; *p; ++p) {
        char c = *p;
        if (c >= 'a' && c <= 'z')
            *p = c - 32;
    }
    return s;
}
