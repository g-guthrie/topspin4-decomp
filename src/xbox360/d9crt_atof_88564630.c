/* Swing_DLL.xex 0x88564630-0x885646EC, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: atof. */
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
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(void);
extern int ts4_if_get_u32_lbl_88C31878_88567FD8(int c, int mask, LocInfo **loc);
extern FltOut *fn_8856F908(FltOut *out, const char *s, LocInfo **loc);

double ts4_crt_atof_88564630(const char *s)
{
    FltOut buf;
    u32 *e;
    int sp;
    if (s == 0) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0();
        return lbl_880038D8;
    }
    for (;;) {
        if (lbl_88C31878->mb_cur_max > 1)
            sp = ts4_if_get_u32_lbl_88C31878_88567FD8(*(const unsigned char *)s, 8, &lbl_88C31878);
        else
            sp = lbl_88C31878->pctype[*(const unsigned char *)s] & 8;
        if (!sp)
            break;
        ++s;
    }
    return fn_8856F908(&buf, s, &lbl_88C31878)->value;
}
