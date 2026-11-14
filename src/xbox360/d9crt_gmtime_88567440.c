/* Swing_DLL.xex 0x88567440-0x8856749C, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: gmtime. */
typedef struct Ts4Tm Ts4Tm;
extern Ts4Tm *fn_885741C0(void);
extern int fn_885670E8(Ts4Tm *tb, const long long *t);

Ts4Tm *ts4_crt_gmtime_88567440(const long long *t)
{
    Ts4Tm *tb = fn_885741C0();
    if (tb == 0)
        return 0;
    return fn_885670E8(tb, t) == 0 ? tb : 0;
}
