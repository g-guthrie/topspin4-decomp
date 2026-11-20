typedef unsigned long ts4_word;
extern char lbl_88041FEC[];
extern char lbl_88042008[];
ts4_word ts4_get_u32_off0_88428960();
ts4_word ts4_get_u32_off0_884289C8();
ts4_word ts4_if_call_seq_u32_off4_88428890();
/* Swing_DLL.xex 0x88432FD0: if_call_seq lbl_88041FF8, ts4_if_call_seq_u32_off4_88428890, lbl_88041FEC, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428960, u8@0x0 */
ts4_word ts4_if_call_seq_lbl_88042008_88433078(ts4_word a0, ts4_word a1)
{
    ts4_word p9;
    ts4_word p11;
    struct { ts4_word loc50[2]; ts4_word loc58[2]; ts4_word loc60[4]; } LL;
    ts4_word t3;
    unsigned char t4;
    ts4_word t5;
    unsigned char t6;
    ts4_word t7;
    ts4_word t8;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88042008);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88041FEC);
    t3 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(ts4_word)&LL.loc60[0]);
    t4 = *(unsigned char *)((char *)(ts4_word)(t3) + 0);
    p11 = (ts4_word)t3;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(ts4_word)&LL.loc58[0]);
        t6 = *(unsigned char *)((char *)(ts4_word)(t5) + 0);
        p9 = (ts4_word)t5;
        if ((ts4_word)t6 != 0) {
            t7 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)0);
            *(ts4_word *)((char *)(ts4_word)(t7) + 0) = (ts4_word)0;
            t8 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)0);
            *(ts4_word *)((char *)(ts4_word)(t8) + 0) = (ts4_word)0;
            p9 = (ts4_word)t8;
        }
        p11 = (ts4_word)p9;
    }
    return p11;
}
