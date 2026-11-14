/* Swing_DLL.xex 0x88567E68-0x88567FB8, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: OS error to errno mapping and _dosmaperr. */
typedef unsigned int u32;
typedef struct ErrEntry { u32 oscode; u32 errnocode; } ErrEntry;
extern ErrEntry lbl_88C31028[45];
extern u32 lbl_88C31190[2];
extern u32 *fn_8856CD88(void);

#ifdef _MSC_VER
__declspec(noinline)
#endif
int ts4_crt_get_errno_from_oserr_88567E68(u32 oserr)
{
    u32 i;
    for (i = 0; i < 45; ++i) {
        if (oserr == lbl_88C31028[i].oscode)
            return lbl_88C31028[i].errnocode;
    }
    if (oserr >= 19 && oserr <= 36)
        return 13;
    if (oserr >= 188 && oserr <= 202)
        return 8;
    return 22;
}

static u32 *crt_doserrno(void)
{
    u32 *ptd = fn_8856CD88();
    if (!ptd)
        return &lbl_88C31190[1];
    return ptd + 3;
}

static u32 *crt_errno(void)
{
    u32 *ptd = fn_8856CD88();
    if (!ptd)
        return &lbl_88C31190[0];
    return ptd + 2;
}

void ts4_crt_dosmaperr_88567F48(u32 oserr)
{
    *crt_doserrno() = oserr;
    *crt_errno() = ts4_crt_get_errno_from_oserr_88567E68(oserr);
}
