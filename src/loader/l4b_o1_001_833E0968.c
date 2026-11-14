/* Loader_DLL.xex 0x833E0968-0x83516398, executable version 0.0.0.3.
   Small accessor / call-sequence functions generated from the original
   control flow; parameters are untyped words and fields are byte offsets. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
typedef __int64 ts4l_s64;
#else
typedef unsigned long long ts4l_u64;
typedef long long ts4l_s64;
#endif
typedef unsigned long ts4l_word;

extern char fn_83516538[];
extern char lbl_8306F7D0[];
extern char lbl_8306F7EC[];
extern char lbl_83071CA8[];
extern char lbl_830738D8[];
extern char lbl_8307AA30[];
extern char lbl_8307EC20[];
extern char lbl_83086AC0[];
extern char lbl_8352F8F0[];
extern char lbl_835446D8[];
extern char lbl_83544784[];
ts4l_word RtlFreeAnsiString();
ts4l_word RtlInitUnicodeString();
ts4l_word RtlInitializeCriticalSection();
ts4l_word RtlUnicodeStringToAnsiString();
ts4l_word fn_833E0850();
ts4l_word fn_833E08D8();
ts4l_word fn_833E1758();
ts4l_word fn_833E3A30();
ts4l_word fn_833E4920();
ts4l_word fn_83400AD8();
ts4l_word fn_83400FE8();
ts4l_word fn_83401730();
ts4l_word fn_83401788();
ts4l_word fn_83401AB8();
ts4l_word fn_83401FE0();
ts4l_word fn_83402088();
ts4l_word fn_83405A08();
ts4l_word fn_8340D830();
ts4l_word fn_8340F288();
ts4l_word fn_834306C8();
ts4l_word fn_8343B7A0();
ts4l_word fn_8343F408();
ts4l_word fn_83450640();
ts4l_word fn_83450710();
ts4l_word fn_83476CB0();
ts4l_word fn_83482AE0();
ts4l_word fn_83486520();
ts4l_word fn_83486EF0();
ts4l_word fn_83487878();
ts4l_word fn_83487B40();
ts4l_word fn_83487FF8();
ts4l_word fn_83488598();
ts4l_word fn_83488800();

/* Loader_DLL.xex 0x833E0968: if_call_seq lbl_8306F7EC, u32@0x0, fn_833E08D8, fn_833E1758 */
ts4l_word ts4l_if_call_seq_lbl_8306F7EC_833E0968(ts4l_word a0, ts4l_word a1)
{

    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8306F7EC;
    fn_833E08D8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x833E09C0: if_call_seq fn_833E08D8, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_833E08D8_833E09C0(ts4l_word a0, ts4l_word a1)
{

    fn_833E08D8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x833E0A58: call_seq lbl_8306F7D0, u32@0x4, u32@0x0, u8@0x8, fn_833E0850, lbl_8306F7EC */
ts4l_word ts4l_call_seq_lbl_8306F7D0_833E0A58(ts4l_word a0, ts4l_word a1)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8306F7D0;
    *(unsigned char *)((char *)(ts4l_word)(a0) + 8) = (unsigned char)0;
    fn_833E0850((ts4l_word)a0, (ts4l_word)a1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8306F7EC;
    return a0;
}

/* Loader_DLL.xex 0x83401250: if_call_seq u8@0x4, u8@0x5, u32@0x0, fn_83400AD8, u32@0x0, u8@0x4 */
ts4l_word ts4l_if_call_seq_u8_off4_83401250(ts4l_word a0, int a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    *(unsigned char *)((char *)(ts4l_word)(a0) + 4) = (unsigned char)a1;
    *(unsigned char *)((char *)(ts4l_word)(a0) + 5) = (unsigned char)0;
    if ((int)a1 == 1) {
        t1 = fn_83400AD8((ts4l_word)1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)t1;
        if ((ts4l_word)t1 == 0) {
            *(unsigned char *)((char *)(ts4l_word)(a0) + 4) = (unsigned char)3;
        }
    } else {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    }
    return a0;
}

/* Loader_DLL.xex 0x83401F50: call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x4, fn_83401AB8 */
ts4l_word ts4l_call_seq_u32_off0_83401F50(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 0));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 4));
    fn_83401AB8((ts4l_word)a0, (ts4l_word)a2);
    return a0;
}

/* Loader_DLL.xex 0x834022A8: if_call_seq u32@0x0, lbl_83071CA8, u32@0x0, u32@0x4, u32@0x4, fn_83402088 */
ts4l_word ts4l_if_call_seq_u32_off0_834022A8(ts4l_word a0, ts4l_word a1)
{
    ts4l_word loc50[4];
    ts4l_word t4;
    ts4l_word t7;
    unsigned char t8;

    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 0));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 4));
    fn_83402088((ts4l_word)a0, (ts4l_word)(ts4l_word)lbl_83071CA8);
    t4 = fn_83405A08((ts4l_word)(ts4l_word)&loc50[0]);
    fn_83401AB8((ts4l_word)a0, (ts4l_word)t4);
    fn_83401FE0((ts4l_word)a0, (ts4l_word)125);
    t7 = *(ts4l_word *)lbl_835446D8;
    t8 = *(unsigned char *)((char *)(ts4l_word)(t7) + 0);
    if ((ts4l_word)t8 == 64) {
        *(ts4l_word *)lbl_835446D8 = (ts4l_word)(t7 + 1);
    }
    return a0;
}

/* Loader_DLL.xex 0x83402330: call_seq fn_83401730, u32@0x0, u32@0x0, u32@0x4, u32@0x4, fn_83401AB8 */
ts4l_word ts4l_call_seq_fn_83401730_83402330(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word loc50[2];
    ts4l_word t1;

    t1 = fn_83401730((ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)a1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 0));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 4));
    fn_83401AB8((ts4l_word)a0, (ts4l_word)a2);
    return a0;
}

/* Loader_DLL.xex 0x83402390: call_seq fn_83400FE8, u32@0x0, u32@0x0, u32@0x4, u32@0x4, fn_83401AB8 */
ts4l_word ts4l_call_seq_fn_83400FE8_83402390(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word loc50[2];
    ts4l_word t1;

    t1 = fn_83400FE8((ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)a1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 0));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 4));
    fn_83401AB8((ts4l_word)a0, (ts4l_word)a2);
    return a0;
}

/* Loader_DLL.xex 0x834023F0: call_seq fn_83401788, u32@0x0, u32@0x0, u32@0x4, u32@0x4, fn_83401AB8 */
ts4l_word ts4l_call_seq_fn_83401788_834023F0(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word loc50[2];
    ts4l_word t1;

    t1 = fn_83401788((ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)a1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 0));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 4));
    fn_83401AB8((ts4l_word)a0, (ts4l_word)a2);
    return a0;
}

/* Loader_DLL.xex 0x83414000: if_call_seq RtlInitUnicodeString, RtlUnicodeStringToAnsiString, lbl_83086AC0, fn_8340F288, RtlFreeAnsiString */
ts4l_word ts4l_if_call_seq_RtlInitUnicodeString_83414000(ts4l_word a0)
{
    ts4l_word p6;
    ts4l_word loc58[2];
    ts4l_word loc50[2];
    int t2;
    ts4l_word t3;
    ts4l_word t4;
    ts4l_word t5;

    RtlInitUnicodeString((ts4l_word)(ts4l_word)&loc58[0], (ts4l_word)a0);
    t2 = RtlUnicodeStringToAnsiString((ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)(ts4l_word)&loc58[0], (ts4l_word)1);
    if ((int)t2 < 0) {
        loc50[1] = (ts4l_word)(ts4l_word)lbl_83086AC0;
    }
    t3 = loc50[1];
    t4 = fn_8340F288((ts4l_word)t3);
    p6 = (ts4l_word)t4;
    if ((int)t2 >= 0) {
        t5 = RtlFreeAnsiString((ts4l_word)(ts4l_word)&loc50[0]);
        p6 = (ts4l_word)t5;
    }
    return p6;
}

/* Loader_DLL.xex 0x8343D7B0: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343D7B0(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343D800: if_call_seq lbl_830738D8, u32@0x0, fn_8343B7A0, u32@0x80, fn_8340D830, fn_834306C8 */
ts4l_word ts4l_if_call_seq_lbl_830738D8_8343D800(ts4l_word a0)
{
    ts4l_word t2;
    ts4l_word t5;

    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_830738D8;
    fn_8343B7A0();
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 128);
    if ((ts4l_word)t2 != 0) {
        fn_8340D830((ts4l_word)t2, (ts4l_word)(612433920));
    }
    t5 = fn_834306C8((ts4l_word)a0);
    return t5;
}

/* Loader_DLL.xex 0x8343D8A8: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343D8A8(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343D8F8: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343D8F8(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343D948: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343D948(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343D998: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343D998(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343D9E8: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343D9E8(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DA38: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DA38(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DA88: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DA88(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DAD8: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DAD8(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DB28: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DB28(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DB78: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DB78(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DBC8: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DBC8(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DC18: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DC18(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DC68: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DC68(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DCB8: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DCB8(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DD08: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DD08(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DD58: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DD58(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DDA8: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DDA8(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DDF8: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DDF8(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DE48: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DE48(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DE98: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DE98(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DEE8: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DEE8(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DF38: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DF38(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DF88: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DF88(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343DFD8: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343DFD8(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343E028: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343E028(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343E078: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343E078(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343E0C8: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343E0C8(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343E118: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343E118(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343E168: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343E168(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343E1B8: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343E1B8(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343E208: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343E208(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343E258: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343E258(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343E2A8: if_call_seq fn_834306C8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_834306C8_8343E2A8(ts4l_word a0, ts4l_word a1)
{

    fn_834306C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343F6B0: if_call_seq fn_8343F408, u32@0xc, u32@0x8, u32@0x10, u32@0x14 */
ts4l_word ts4l_if_call_seq_fn_8343F408_8343F6B0(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p4;
    int t1;
    ts4l_word t2;
    ts4l_word t3;

    t1 = fn_8343F408((ts4l_word)a0, (ts4l_word)a1);
    p4 = (ts4l_word)t1;
    if ((int)t1 >= 0) {
        t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 8);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 16) = (ts4l_word)t2;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)(t3 + t2);
        p4 = (ts4l_word)0;
    }
    return p4;
}

/* Loader_DLL.xex 0x83451030: call_seq lbl_8307AA30, fn_83450640, fn_83450710, u32@0x558, u32@0x558 */
ts4l_word ts4l_call_seq_lbl_8307AA30_83451030(ts4l_word a0)
{
    ts4l_word t2;

    fn_83450640((ts4l_word)a0, (ts4l_word)(ts4l_word)lbl_8307AA30, (ts4l_word)0);
    t2 = fn_83450710((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1368) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 1368)) | 16);
    return t2;
}

/* Loader_DLL.xex 0x834779B0: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_834779B0(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484050: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484050(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x834840F0: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_834840F0(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484190: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484190(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484230: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484230(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x834842D0: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_834842D0(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484370: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484370(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484410: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484410(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x834844B0: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_834844B0(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484550: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484550(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x834845F0: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_834845F0(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484690: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484690(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484730: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484730(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x834847D0: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_834847D0(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484870: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484870(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484910: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484910(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x834849B0: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_834849B0(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484A50: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484A50(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484AF0: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484AF0(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484B90: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484B90(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484C30: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484C30(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484CD0: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484CD0(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484D70: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484D70(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484E10: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484E10(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484EB0: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484EB0(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484F50: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484F50(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484FF0: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83484FF0(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83485090: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83485090(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83485130: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83485130(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x834851D0: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_834851D0(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83485270: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83485270(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83485310: if_call_seq fn_83476CB0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83476CB0_83485310(ts4l_word a0, ts4l_word a1)
{

    fn_83476CB0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83485658: if_call_seq lbl_8307EC20, u32@0x0, fn_83482AE0, u32@0x80, fn_833E1758, fn_83476CB0 */
ts4l_word ts4l_if_call_seq_lbl_8307EC20_83485658(ts4l_word a0)
{
    ts4l_word t2;
    ts4l_word t5;

    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307EC20;
    fn_83482AE0();
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 128);
    if ((ts4l_word)t2 != 0) {
        fn_833E1758((ts4l_word)t2);
    }
    t5 = fn_83476CB0((ts4l_word)a0);
    return t5;
}

/* Loader_DLL.xex 0x83488690: if_call_seq fn_83486EF0, fn_83487FF8 */
ts4l_word ts4l_if_call_seq_fn_83486EF0_83488690(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word p3;
    int t1;
    ts4l_word t2;

    t1 = fn_83486EF0((ts4l_word)(a0 + 8), (ts4l_word)a1, (ts4l_word)0, (ts4l_word)a2);
    p3 = (ts4l_word)t1;
    if ((int)t1 >= 0) {
        t2 = fn_83487FF8((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)a2);
        p3 = (ts4l_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x834886D8: if_call_seq fn_83488598, fn_83486520 */
ts4l_word ts4l_if_call_seq_fn_83488598_834886D8(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p3;
    int t1;
    ts4l_word t2;

    t1 = fn_83488598((ts4l_word)a0, (ts4l_word)a1);
    p3 = (ts4l_word)t1;
    if ((int)t1 >= 0) {
        t2 = fn_83486520((ts4l_word)a0);
        p3 = (ts4l_word)(((int)t2 >> 31) & t2);
    }
    return p3;
}

/* Loader_DLL.xex 0x83488720: if_call_seq fn_83487878, fn_83487B40, fn_83486520 */
ts4l_word ts4l_if_call_seq_fn_83487878_83488720(ts4l_word a0)
{
    ts4l_word p3;
    ts4l_word p5;
    int t1;
    ts4l_word t2;
    ts4l_word t4;

    t1 = fn_83487878();
    p3 = (ts4l_word)t1;
    if ((int)t1 >= 0) {
        t2 = fn_83487B40((ts4l_word)a0);
        p3 = (ts4l_word)(((int)t2 >> 31) & t2);
    }
    p5 = (ts4l_word)p3;
    if ((int)p3 >= 0) {
        t4 = fn_83486520((ts4l_word)a0);
        p5 = (ts4l_word)(((int)t4 >> 31) & t4);
    }
    return p5;
}

/* Loader_DLL.xex 0x834888B8: if_call_seq u32@lbl_83544784, fn_83488598, fn_83488598, fn_83486520 */
ts4l_word ts4l_if_call_seq_u32_lbl_83544784_834888B8(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p5;
    ts4l_word p6;
    int t1;
    int t3;
    ts4l_word t4;
    ts4l_word t2;

    t1 = *(ts4l_word *)lbl_83544784;
    if ((int)t1 != 0) {
        t3 = fn_83488598((ts4l_word)a0, (ts4l_word)a1);
        p5 = (ts4l_word)t3;
        if ((int)t3 >= 0) {
            t4 = fn_83486520((ts4l_word)a0);
            p5 = (ts4l_word)(((int)t4 >> 31) & t4);
        }
        p6 = (ts4l_word)p5;
    } else {
        t2 = fn_83488598((ts4l_word)a0, (ts4l_word)a1);
        p6 = (ts4l_word)t2;
    }
    return p6;
}

/* Loader_DLL.xex 0x83488990: if_call_seq u32@lbl_83544784, fn_83486EF0, fn_83487FF8, fn_83488800 */
ts4l_word ts4l_if_call_seq_u32_lbl_83544784_83488990(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word p4;
    ts4l_word p6;
    int t1;
    ts4l_word t5;
    int t2;
    ts4l_word t3;

    t1 = *(ts4l_word *)lbl_83544784;
    if ((int)t1 != 0) {
        t5 = fn_83488800((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)a2);
        p6 = (ts4l_word)t5;
    } else {
        t2 = fn_83486EF0((ts4l_word)(a0 + 8), (ts4l_word)a1, (ts4l_word)0, (ts4l_word)a2);
        p4 = (ts4l_word)t2;
        if ((int)t2 >= 0) {
            t3 = fn_83487FF8((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)a2);
            p4 = (ts4l_word)t3;
        }
        p6 = (ts4l_word)p4;
    }
    return p6;
}

/* Loader_DLL.xex 0x83515D98: call_seq lbl_8352F8F0, RtlInitializeCriticalSection, fn_833E3A30, fn_83516538, fn_833E4920 */
ts4l_word ts4l_call_seq_lbl_8352F8F0_83515D98(void)
{
    ts4l_word t3;

    RtlInitializeCriticalSection((ts4l_word)((ts4l_word)lbl_8352F8F0 + 512));
    fn_833E3A30((ts4l_word)(ts4l_word)lbl_8352F8F0, (ts4l_word)0, (ts4l_word)512);
    t3 = fn_833E4920((ts4l_word)(ts4l_word)fn_83516538);
    return t3;
}
