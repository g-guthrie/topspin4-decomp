/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char ts4_get_u32_off0_8847FA50[];
extern char fn_88484248[];
extern char ts4_call_seq_u32_lbl_88CACF08_884A92F8[];
extern char ts4_call_seq_u32_lbl_88CACF08_884A9388[];
extern char fn_884A9950[];
extern char fn_884AA708[];
extern char fn_884AB258[];
extern char lbl_88001A20[];
extern char lbl_880023AC[];
extern char lbl_8802E87C[];
extern char lbl_8803A308[];
extern char lbl_880444EC[];
extern char lbl_88083774[];
extern char lbl_88083788[];
extern char lbl_8808379C[];
extern char lbl_88083CFC[];
extern char lbl_880843CC[];
extern char lbl_88084C94[];
extern char lbl_88084CAC[];
extern char lbl_88084EBC[];
extern char lbl_88084F6C[];
extern char lbl_880869E8[];
extern char lbl_88087470[];
extern char lbl_88087484[];
extern char lbl_880874EC[];
extern char lbl_88087714[];
extern char lbl_88087754[];
extern char lbl_88087764[];
extern char lbl_88087A40[];
extern char lbl_88087A7C[];
extern char lbl_88087B44[];
extern char lbl_88087CF8[];
extern char lbl_88087EDC[];
extern char lbl_88087F04[];
extern char lbl_88087FDC[];
extern char lbl_8808804C[];
extern char lbl_88088158[];
extern char lbl_88088180[];
extern char lbl_880881D8[];
extern char lbl_880882AC[];
extern char lbl_8808859C[];
extern char lbl_880885AC[];
extern char lbl_88088658[];
extern char lbl_8808879C[];
extern char lbl_880887BC[];
extern char lbl_880887DC[];
extern char lbl_880887EC[];
extern char lbl_8808880C[];
extern char lbl_88088818[];
extern char lbl_8808882C[];
extern char lbl_8808883C[];
extern char lbl_8808885C[];
extern char lbl_88088878[];
extern char lbl_88088884[];
extern char lbl_88088910[];
extern char lbl_88CACF08[];
extern char lbl_88D25FA4[];
extern char lbl_88D25FA8[];
extern char lbl_88D25FAC[];
extern char lbl_88D25FB0[];
extern char lbl_88D25FB4[];
extern char lbl_88D26FD0[];
ts4_word KeTlsGetValue();
ts4_word fn_8841A510();
ts4_word fn_8841A590();
ts4_word fn_8841F998();
ts4_word fn_88420E00();
ts4_word ts4_if_call_seq_lbl_88080084_8843AF20();
ts4_word fn_88476CB0();
ts4_word fn_88478648();
ts4_word fn_884790C8();
ts4_word fn_8847B208();
ts4_word fn_8847B7E8();
ts4_word fn_8847B888();
ts4_word fn_8847E9F0();
ts4_word fn_884812E0();
ts4_word fn_88484538();
ts4_word fn_88488740();
ts4_word ts4_if_call_seq_u32_off3c_8848BD08();
ts4_word fn_8848C010();
ts4_word fn_8848C0A0();
ts4_word fn_8848D2D8();
ts4_word ts4_call_seq_fn_8849FE80_8848E320();
ts4_word fn_8848E3E0();
ts4_word fn_8848E420();
ts4_word fn_884911B8();
ts4_word fn_88492D88();
ts4_word fn_884936E0();
ts4_word fn_884942A8();
ts4_word fn_884944C0();
ts4_word fn_884980C0();
ts4_word fn_88498B98();
ts4_word fn_8849FE80();
ts4_word fn_884A1CA8();
ts4_word fn_884A1EA0();
ts4_word fn_884A2100();
ts4_word fn_884A21A8();
ts4_word fn_884A2AA0();
ts4_word fn_884A2E50();
ts4_word fn_884A2FE8();
ts4_word fn_884A4088();
ts4_word fn_884A4CF8();
ts4_word fn_884A5688();
ts4_word fn_884A6E18();
ts4_word fn_884A7430();
ts4_word fn_884A83D8();
ts4_word fn_884A8C80();
ts4_word fn_884A8D60();
ts4_word fn_884A9828();
ts4_word fn_884A9A20();
ts4_word fn_884AA078();
ts4_word fn_884AB2F8();
ts4_word ts4_call_seq_fn_884ABB50_884ABBB0();
ts4_word ts4_call_seq_fn_884ACBC8_884ACC28();
ts4_word ts4_call_seq_fn_884AE1F8_884AE258();
ts4_word ts4_call_seq_fn_884AE808_884AE868();
ts4_word ts4_call_seq_fn_884AF270_884AF2D0();
ts4_word ts4_call_seq_fn_884AFF80_884B0030();
ts4_word ts4_call_seq_fn_884B0160_884B01C0();
ts4_word ts4_call_seq_fn_884B0288_884B02E8();
ts4_word ts4_call_seq_fn_884B09F8_884B0A58();
ts4_word ts4_call_seq_fn_884B17D8_884B1838();
ts4_word ts4_call_seq_fn_884B2238_884B2298();
ts4_word ts4_call_seq_fn_884B2580_884B2DC8();
ts4_word ts4_call_seq_fn_884B30A8_884B34E0();
ts4_word fn_884B70D0();
ts4_word fn_884E1AE8();
ts4_word fn_885068E8();
ts4_word fn_8854D9B0();
ts4_word fn_885EBB08();
ts4_word ts4_if_call_seq_u32_off18_885F4B48();
ts4_word fn_885F4C70();
ts4_word ts4_if_call_seq_u32_off18_885F4D78();
ts4_word ts4_noop_884927F8();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x8847FA60: set u32@0x8, ts4_get_u32_off0_8847FA50, u32@0x4 */
void ts4_set_u32_off8_8847FA60(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)ts4_get_u32_off0_8847FA50;
    return;
}

/* Swing_DLL.xex 0x8848C1B0: if_call_seq ts4_if_call_seq_u32_off3c_8848BD08, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8848BD08_8848C1B0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_if_call_seq_u32_off3c_8848BD08((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)34);
    }
    return a0;
}

/* Swing_DLL.xex 0x884927C0: get u32@0x14, u32@0x8, ts4_call_seq_fn_8849FE80_8848E320 */
ts4_word ts4_get_u32_off14_884927C0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return ts4_call_seq_fn_8849FE80_8848E320((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 20))) + 8)), (ts4_word)a1);
}

/* Swing_DLL.xex 0x88493D50: if_call_seq fn_884936E0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884936E0_88493D50(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884936E0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)13);
    }
    return a0;
}

/* Swing_DLL.xex 0x884A1328: if_call_seq fn_884A4CF8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884A4CF8_884A1328(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884A4CF8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x884A14F8: if_call_seq fn_884A5688, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884A5688_884A14F8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884A5688();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x884A1938: if_call_seq fn_884A6E18, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884A6E18_884A1938(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884A6E18();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x884A30F0: if_call_seq fn_884A2E50, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884A2E50_884A30F0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884A2E50();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884A94E0: call_seq ts4_call_seq_u32_lbl_88CACF08_884A92F8, lbl_8808879C, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D26FD0, ts4_call_seq_u32_lbl_88CACF08_884A9388 */
ts4_word ts4_call_seq_fn_884A92F8_884A94E0(void)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_8808879C, (ts4_word)(ts4_word)ts4_call_seq_u32_lbl_88CACF08_884A92F8);
    t3 = *(ts4_word *)lbl_88D26FD0;
    *(ts4_word *)lbl_88D25FA8 = (ts4_word)t2;
    t4 = fn_884E1AE8((ts4_word)t3, (ts4_word)(ts4_word)lbl_880887BC, (ts4_word)(ts4_word)ts4_call_seq_u32_lbl_88CACF08_884A9388);
    *(ts4_word *)lbl_88D25FA4 = (ts4_word)t4;
    return t4;
}

/* Swing_DLL.xex 0x884A9B78: call_seq fn_884A9950, lbl_88088818, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D25FAC */
ts4_word ts4_call_seq_fn_884A9950_884A9B78(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_88088818, (ts4_word)(ts4_word)fn_884A9950);
    *(ts4_word *)lbl_88D25FAC = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x884A9BD8: if_call_seq fn_884A9A20, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884A9A20_884A9BD8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884A9A20((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884AA768: call_seq fn_884AA708, lbl_88088884, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D25FB0 */
ts4_word ts4_call_seq_fn_884AA708_884AA768(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_88088884, (ts4_word)(ts4_word)fn_884AA708);
    *(ts4_word *)lbl_88D25FB0 = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x884AA7D8: if_call_seq fn_884AA078, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884AA078_884AA7D8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884AA078();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884AB2B8: call_seq fn_884AB258, lbl_88088910, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D25FB4 */
ts4_word ts4_call_seq_fn_884AB258_884AB2B8(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_88088910, (ts4_word)(ts4_word)fn_884AB258);
    *(ts4_word *)lbl_88D25FB4 = (ts4_word)t2;
    return t2;
}

