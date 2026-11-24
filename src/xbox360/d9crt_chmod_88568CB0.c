/* Swing_DLL.xex 0x88568CB0-0x88568D50, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _chmod. */
typedef unsigned int u32;
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern u32 *ts4_if_call_seq_fn_8856CD88_88567F10(void);
extern void fn_8856D2C0(void);
extern u32 ts4_if_call_seq_RtlInitAnsiString_8857C370(const char *path);
extern int fn_8857C4C0(const char *path, u32 attr);
extern u32 ts4_tailcall_fn_88582660_8857B840(void);
extern void fn_88567F48(u32 oserr);

int ts4_crt_chmod_88568CB0(const char *path, int mode)
{
    u32 attr;
    u32 *e;
    if (path == 0) {
        *ts4_if_call_seq_fn_8856CD88_88567F10() = 0;
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0();
        return -1;
    }
    attr = ts4_if_call_seq_RtlInitAnsiString_8857C370(path);
    if (attr == (u32)-1) {
        fn_88567F48(ts4_tailcall_fn_88582660_8857B840());
        return -1;
    }
    if (mode & 0x80)
        attr &= ~1u;
    else
        attr |= 1;
    if (!fn_8857C4C0(path, attr)) {
        fn_88567F48(ts4_tailcall_fn_88582660_8857B840());
        return -1;
    }
    return 0;
}
