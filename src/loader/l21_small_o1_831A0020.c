/* Loader_DLL.xex 0x831A0020-0x8340D70C, executable version 0.0.0.3.
 * Small call sequences that compile with /O1 (same code as the Swing_DLL.xex copies). */
typedef unsigned long ts4l_word;

#ifndef _MSC_VER
#define memset ts4l_host_memset
#endif
ts4l_word memset();
ts4l_word ts4_set_u32_off4_831A0AF0();
ts4l_word RtlInitAnsiString();
ts4l_word NtQueryFullAttributesFile();
ts4l_word fn_8340F088();
extern char lbl_8300CB34[];
extern char lbl_8300CAFC[];

ts4l_word ts4l_call_seq_fn_831A0AF0_831A0020(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    ts4_set_u32_off4_831A0AF0((ts4l_word)(a0 + 4), (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a3, (ts4l_word)a4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 148) = (ts4l_word)a4;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8300CB34;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(ts4l_word)lbl_8300CAFC;
    memset((ts4l_word)(a0 + 28), (ts4l_word)0, (ts4l_word)60);
    memset((ts4l_word)(a0 + 88), (ts4l_word)0, (ts4l_word)60);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 84) = (ts4l_word)(a0 + 28);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 144) = (ts4l_word)(a0 + 88);
    return a0;
}

ts4l_word ts4l_if_call_seq_RtlInitAnsiString_8340D6A8(ts4l_word a0)
{
    ts4l_word p5;
    ts4l_word loc50[1];
    ts4l_word loc58[3];
    ts4l_word loc70[13];
    int t2;
    ts4l_word t4;

    RtlInitAnsiString((ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)a0);
    loc58[0] = (ts4l_word)-3;
    loc58[2] = (ts4l_word)64;
    loc58[1] = (ts4l_word)(ts4l_word)&loc50[0];
    t2 = NtQueryFullAttributesFile((ts4l_word)(ts4l_word)&loc58[0], (ts4l_word)(ts4l_word)&loc70[0]);
    if ((int)t2 >= 0) {
        t4 = loc70[12];
        p5 = (ts4l_word)t4;
    } else {
        fn_8340F088((ts4l_word)t2);
        p5 = (ts4l_word)-1;
    }
    return p5;
}

ts4l_word ts4l_if_get_u32_off84_831F33C0(ts4l_word a0, ts4l_word a1)
{
    ts4l_word loc50[1];
    ts4l_word t1;
    ts4l_word t4;
    ts4l_word t5;
    int t8;
    int t9;
    ts4l_word t12;
    ts4l_word t13;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 132);
    t4 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 40))))((ts4l_word)t1);
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 132);
    t8 = ((ts4l_word (*)(ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t5) + 0))) + 32))))((ts4l_word)t5, (ts4l_word)(ts4l_word)&loc50[0]);
    if ((int)t8 >= 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)1;
        t9 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 148);
        if ((int)t9 != 0) {
            t12 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 128);
            t13 = loc50[0];
            if ((ts4l_word)(t12 + t13) > (ts4l_word)t4) {
                *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)0;
            } else {
                if ((ts4l_word)((t12 << 1) + t13) <= (ts4l_word)t4) {
                    *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)2;
                }
            }
        }
    }
    return t8;
}

extern int lbl_83544728;
int *ts4_if_call_seq_fn_833E8350_833E9F90(void);
void fn_833E9D50(void);

int ts4l_get_global_checked_8340A198(int *out)
{
    if (out == 0) {
        *ts4_if_call_seq_fn_833E8350_833E9F90() = 0x16;
        fn_833E9D50();
        return 0x16;
    }
    *out = lbl_83544728;
    return 0;
}
