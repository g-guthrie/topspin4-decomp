/* Swing_DLL.xex 0x8856C630-0x8856C940, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _close_nolock and _lseek_nolock. */
typedef unsigned int u32;
typedef struct IoInfo {
    int osfhnd;
    char osfile;
    char pad[0x48 - 5];
} IoInfo;
extern IoInfo *lbl_88D4E000[];
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern int fn_88574A70(int fh);
extern int fn_885749D8(int fh);
extern int ts4_if_get_u32_lbl_88C32048_8857A1E0(int handle);
extern u32 fn_8857BA40(int handle, u32 lo, int *hi, int method);
extern u32 ts4_tailcall_fn_88582660_8857B840(void);
extern void fn_88567F48(u32 oserr);

#define PIOINFO(i) (lbl_88D4E000[(i) >> 5] + ((i) & 31))

int ts4_crt_close_nolock_8856C630(int fh)
{
    u32 dosretval;
    if (fn_88574A70(fh) != -1) {
        if ((fh == 1 && (lbl_88D4E000[0][2].osfile & 1)) || (fh == 2 && (lbl_88D4E000[0][1].osfile & 1))) {
            if (fn_88574A70(1) == fn_88574A70(2)) {
                dosretval = 0;
                goto done;
            }
        }
        if (!ts4_if_get_u32_lbl_88C32048_8857A1E0(fn_88574A70(fh)))
            dosretval = ts4_tailcall_fn_88582660_8857B840();
        else
            dosretval = 0;
    } else
        dosretval = 0;
done:
    fn_885749D8(fh);
    PIOINFO(fh)->osfile = 0;
    if (dosretval) {
        fn_88567F48(dosretval);
        return -1;
    }
    return 0;
}

int ts4_crt_lseek_nolock_8856C888(int fh, int pos, int mthd)
{
    int h;
    u32 lo;
    u32 dosretval;
    u32 *e;
    h = fn_88574A70(fh);
    if (h == -1) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 9;
        return -1;
    }
    lo = fn_8857BA40(h, pos, 0, mthd);
    if (lo == (u32)-1)
        dosretval = ts4_tailcall_fn_88582660_8857B840();
    else
        dosretval = 0;
    if (dosretval) {
        fn_88567F48(dosretval);
        return -1;
    }
    PIOINFO(fh)->osfile &= ~2;
    return (int)lo;
}
