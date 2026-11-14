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

extern char fn_884ABB50[];
extern char fn_884ACBC8[];
extern char fn_884AE1F8[];
extern char fn_884AE808[];
extern char fn_884AF270[];
extern char fn_884AFF80[];
extern char fn_884B0160[];
extern char fn_884B0288[];
extern char fn_884B09F8[];
extern char fn_884B17D8[];
extern char fn_884B2238[];
extern char fn_884B2580[];
extern char fn_884B30A8[];
extern char lbl_88001A20[];
extern char lbl_88001A68[];
extern char lbl_88028BDC[];
extern char lbl_88028BE0[];
extern char lbl_8803A308[];
extern char lbl_88086B70[];
extern char lbl_88086BE4[];
extern char lbl_880876A0[];
extern char lbl_88087754[];
extern char lbl_88088A34[];
extern char lbl_88088AE4[];
extern char lbl_88088CA0[];
extern char lbl_88088CB4[];
extern char lbl_88088CC4[];
extern char lbl_88088CE4[];
extern char lbl_88088CF0[];
extern char lbl_88088DE8[];
extern char lbl_88088E78[];
extern char lbl_88088E98[];
extern char lbl_88088EA8[];
extern char lbl_88088EB8[];
extern char lbl_88088ED8[];
extern char lbl_88088EE8[];
extern char lbl_88088F04[];
extern char lbl_88088F14[];
extern char lbl_88088F24[];
extern char lbl_88088F44[];
extern char lbl_88088F54[];
extern char lbl_88089090[];
extern char lbl_88089160[];
extern char lbl_8808923C[];
extern char lbl_88089248[];
extern char lbl_880894F4[];
extern char lbl_88089504[];
extern char lbl_88089704[];
extern char lbl_880897DC[];
extern char lbl_880898DC[];
extern char lbl_880898EC[];
extern char lbl_88089C0C[];
extern char lbl_88089C9C[];
extern char lbl_88089D7C[];
extern char lbl_88089D90[];
extern char lbl_88089E2C[];
extern char lbl_88089F34[];
extern char lbl_88089F94[];
extern char lbl_8808A00C[];
extern char lbl_8808A0CC[];
extern char lbl_8808A13C[];
extern char lbl_8808A544[];
extern char lbl_8808BFAC[];
extern char lbl_8808C1A8[];
extern char lbl_8808C36C[];
extern char lbl_88C24FE0[];
extern char lbl_88CACF08[];
extern char lbl_88CAD568[];
extern char lbl_88D25FB4[];
extern char lbl_88D25FC0[];
extern char lbl_88D25FC4[];
extern char lbl_88D25FD4[];
extern char lbl_88D25FDC[];
extern char lbl_88D25FE0[];
extern char lbl_88D25FE4[];
extern char lbl_88D25FE8[];
extern char lbl_88D25FEC[];
extern char lbl_88D25FF0[];
extern char lbl_88D25FFC[];
extern char lbl_88D26000[];
extern char lbl_88D26004[];
extern char lbl_88D26008[];
extern char lbl_88D26F54[];
extern char lbl_88D26F84[];
extern char lbl_88D26FCC[];
extern char lbl_88D26FD0[];
extern char lbl_88D3CB4C[];
extern char lbl_88D3CB50[];
ts4_word KeTlsGetValue();
ts4_word fn_8841A510();
ts4_word fn_8841A590();
ts4_word fn_8841DBA0();
ts4_word fn_8841DC28();
ts4_word fn_8841E4A0();
ts4_word ts4_get_u32_off0_8841EAC8();
ts4_word fn_884210E8();
ts4_word fn_884235C0();
ts4_word fn_88423660();
ts4_word fn_88423788();
ts4_word fn_88423D60();
ts4_word fn_88423DC8();
ts4_word fn_884AB648();
ts4_word fn_884AB9E0();
ts4_word fn_884ACC68();
ts4_word fn_884AD668();
ts4_word fn_884AD8C0();
ts4_word fn_884ADAA0();
ts4_word fn_884ADB38();
ts4_word fn_884ADE48();
ts4_word fn_884AE750();
ts4_word fn_884AEBF8();
ts4_word fn_884AEDA0();
ts4_word fn_884AF130();
ts4_word fn_884AFC48();
ts4_word fn_884B0A98();
ts4_word fn_884B0DF0();
ts4_word fn_884B1510();
ts4_word fn_884B19A0();
ts4_word fn_884B1B48();
ts4_word fn_884B2148();
ts4_word fn_884B2470();
ts4_word fn_884B2F98();
ts4_word ts4_loop_call_seq_lbl_88089254_884B4F10();
ts4_word fn_884B50B8();
ts4_word fn_884B6FF8();
ts4_word fn_884B70D0();
ts4_word fn_884B74E8();
ts4_word fn_884B96F0();
ts4_word fn_884B97D8();
ts4_word fn_884BB330();
ts4_word fn_884BEE70();
ts4_word fn_884BF008();
ts4_word fn_884BF468();
ts4_word fn_884BF5A8();
ts4_word ts4_addr_lbl_88087754_884BF7F8();
ts4_word fn_884BF898();
ts4_word fn_884C0670();
ts4_word fn_884C26E0();
ts4_word fn_884C4FA8();
ts4_word ts4_ref_holder_dtor_nullable_member_884C9150();
ts4_word fn_884CAD68();
ts4_word fn_884CB388();
ts4_word fn_884CC7B8();
ts4_word fn_884CD260();
ts4_word fn_884CD318();
ts4_word fn_884CD990();
ts4_word fn_884CE440();
ts4_word ts4_if_call_seq_fn_8841E4A0_884CE798();
ts4_word fn_884D3860();
ts4_word fn_884E1AE8();
ts4_word ts4_if_call_seq_u32_off8_884E2100();
ts4_word fn_884E5390();
ts4_word fn_884E5920();
ts4_word fn_885E76C0();
ts4_word fn_885E78C8();
ts4_word fn_885E7AD8();
ts4_word ts4_if_call_seq_u32_off18_885F4C88();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x884AC4D0: if_call_seq fn_884AB9E0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884AB9E0_884AC4D0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884AB9E0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884ADA38: if_call_seq fn_884AD668, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884AD668_884ADA38(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884AD668();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884AE640: if_call_seq fn_884ADE48, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884ADE48_884AE640(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884ADE48();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884AEB68: if_call_seq lbl_88088CE4, lbl_88088CC4, lbl_88088CB4, u32@0x0, u32@0x8, u32@0x20 */
ts4_word ts4_if_call_seq_lbl_88088CE4_884AEB68(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88088CE4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_88088CC4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_88088CB4;
    fn_884AE750((ts4_word)a0);
    fn_884B6FF8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t4 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t4, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884AFAB8: if_call_seq fn_884AF130, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884AF130_884AFAB8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884AF130();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884B0088: if_call_seq fn_884AFC48, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884AFC48_884B0088(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884AFC48();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884B1008: if_call_seq fn_884B0DF0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884B0DF0_884B1008(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884B0DF0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884B1938: if_call_seq fn_884B1510, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884B1510_884B1938(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884B1510();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)17);
    }
    return a0;
}

/* Swing_DLL.xex 0x884B2E30: if_call_seq fn_884B2470, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884B2470_884B2E30(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884B2470();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)17);
    }
    return a0;
}

/* Swing_DLL.xex 0x884B3548: if_call_seq fn_884B2F98, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884B2F98_884B3548(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884B2F98();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)17);
    }
    return a0;
}

/* Swing_DLL.xex 0x884B7210: if_call_seq fn_884B6FF8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884B6FF8_884B7210(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884B6FF8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884B9E70: if_call_seq fn_884B97D8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884B97D8_884B9E70(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884B97D8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884BED00: if_call_seq ts4_addr_lbl_88087754_884BF7F8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884BF7F8_884BED00(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_addr_lbl_88087754_884BF7F8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)11);
    }
    return a0;
}

/* Swing_DLL.xex 0x884CE8E0: get u32@lbl_88D26F84, u32@lbl_88D26FCC, u32@0x0, u32@0xc, vcall, lbl_88D26F54 */
ts4_word ts4_get_u32_lbl_88D26F84_884CE8E0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)lbl_88D26F84;
    t2 = *(ts4_word *)lbl_88D26FCC;
    t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1);
    t6 = ts4_if_call_seq_fn_8841E4A0_884CE798((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88D26F54, (ts4_word)t5, (ts4_word)t2);
    return t6;
}

