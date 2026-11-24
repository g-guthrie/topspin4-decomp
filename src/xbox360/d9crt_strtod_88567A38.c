/* Swing_DLL.xex 0x88567A38-0x88567B94, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: strtod. */
typedef unsigned int u32;
typedef struct LocInfo {
    char pad0[0xac];
    int mb_cur_max;
    char pad1[0xc8 - 0xb0];
    const unsigned short *pctype;
} LocInfo;
typedef struct FltOut {
    u32 flags;
    int nbytes;
    u32 pad[2];
    double value;
} FltOut;
extern LocInfo *lbl_88C31878;
extern double lbl_880038D8;
extern double lbl_88090690;
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(void);
extern int ts4_if_get_u32_lbl_88C31878_88567FD8(int c, int mask, LocInfo **loc);
extern FltOut *fn_8856F908(FltOut *out, const char *s, LocInfo **loc);

double ts4_crt_strtod_88567A38(const char *nptr, char **endptr)
{
    FltOut buf;
    FltOut *r;
    const char *p = nptr;
    double ret;
    u32 *e;
    int sp;
    if (endptr)
        *endptr = (char *)nptr;
    if (nptr == 0) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0();
        return lbl_880038D8;
    }
    for (;;) {
        if (lbl_88C31878->mb_cur_max > 1)
            sp = ts4_if_get_u32_lbl_88C31878_88567FD8(*(const unsigned char *)p, 8, &lbl_88C31878);
        else
            sp = lbl_88C31878->pctype[*(const unsigned char *)p] & 8;
        if (!sp)
            break;
        ++p;
    }
    r = fn_8856F908(&buf, p, &lbl_88C31878);
    if (endptr)
        *endptr = (char *)(p + r->nbytes);
    if (r->flags & 0x240) {
        ret = lbl_880038D8;
        if (endptr)
            *endptr = (char *)nptr;
    } else if (r->flags & 0x81) {
        if (*p == '-')
            ret = -lbl_88090690;
        else
            ret = lbl_88090690;
        goto range_error;
    } else if ((r->flags & 0x100) && r->value == lbl_880038D8) {
        ret = lbl_880038D8;
range_error:
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 34;
    } else {
        ret = r->value;
    }
    return ret;
}
