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
ts4_word ts4_if_call_seq_fn_884AB9E0_884AC4D0();
ts4_word fn_884ACC68();
ts4_word fn_884AD668();
ts4_word fn_884AD8C0();
ts4_word ts4_if_call_seq_fn_884AD668_884ADA38();
ts4_word fn_884ADAA0();
ts4_word fn_884ADB38();
ts4_word fn_884ADE48();
ts4_word ts4_if_call_seq_fn_884ADE48_884AE640();
ts4_word fn_884AE750();
ts4_word ts4_if_call_seq_lbl_88088CE4_884AEB68();
ts4_word fn_884AEBF8();
ts4_word fn_884AEDA0();
ts4_word fn_884AF130();
ts4_word ts4_if_call_seq_fn_884AF130_884AFAB8();
ts4_word fn_884AFC48();
ts4_word ts4_if_call_seq_fn_884AFC48_884B0088();
ts4_word fn_884B0A98();
ts4_word fn_884B0DF0();
ts4_word ts4_if_call_seq_fn_884B0DF0_884B1008();
ts4_word fn_884B1510();
ts4_word ts4_if_call_seq_fn_884B1510_884B1938();
ts4_word fn_884B19A0();
ts4_word fn_884B1B48();
ts4_word fn_884B2148();
ts4_word fn_884B2470();
ts4_word ts4_if_call_seq_fn_884B2470_884B2E30();
ts4_word fn_884B2F98();
ts4_word ts4_if_call_seq_fn_884B2F98_884B3548();
ts4_word fn_884B4F10();
ts4_word fn_884B50B8();
ts4_word fn_884B6FF8();
ts4_word fn_884B70D0();
ts4_word ts4_if_call_seq_fn_884B6FF8_884B7210();
ts4_word fn_884B74E8();
ts4_word fn_884B96F0();
ts4_word fn_884B97D8();
ts4_word ts4_if_call_seq_fn_884B97D8_884B9E70();
ts4_word fn_884BB330();
ts4_word ts4_if_call_seq_fn_884BF7F8_884BED00();
ts4_word fn_884BEE70();
ts4_word fn_884BF008();
ts4_word fn_884BF468();
ts4_word fn_884BF5A8();
ts4_word fn_884BF898();
ts4_word fn_884C0670();
ts4_word fn_884C26E0();
ts4_word fn_884C4FA8();
ts4_word fn_884C9150();
ts4_word fn_884CAD68();
ts4_word fn_884CB388();
ts4_word fn_884CC7B8();
ts4_word fn_884CD260();
ts4_word fn_884CD318();
ts4_word fn_884CD990();
ts4_word fn_884CE440();
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

/* Swing_DLL.xex 0x884AB830: get u32@lbl_88D25FB4 */
ts4_word ts4_get_u32_lbl_88D25FB4_884AB830(void)
{
    return (*(ts4_word *)lbl_88D25FB4);
}

/* Swing_DLL.xex 0x884AB860: if_call_seq fn_884AB648, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884AB648_884AB860(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884AB648();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884ABBB0: call_seq fn_884ABB50, lbl_88088A34, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D25FC0 */
ts4_word ts4_call_seq_fn_884ABB50_884ABBB0(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_88088A34, (ts4_word)(ts4_word)fn_884ABB50);
    *(ts4_word *)lbl_88D25FC0 = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x884AC4A8: get u32@lbl_88D25FC0 */
ts4_word ts4_get_u32_lbl_88D25FC0_884AC4A8(void)
{
    return (*(ts4_word *)lbl_88D25FC0);
}

/* Swing_DLL.xex 0x884AC4B8: tailcall ts4_if_call_seq_fn_884AB9E0_884AC4D0 */
ts4_word ts4_tailcall_fn_884AC4D0_884AC4B8(ts4_word a0)
{
    return ts4_if_call_seq_fn_884AB9E0_884AC4D0((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884AC4C0: tailcall ts4_if_call_seq_fn_884AB9E0_884AC4D0 */
ts4_word ts4_tailcall_fn_884AC4D0_884AC4C0(ts4_word a0)
{
    return ts4_if_call_seq_fn_884AB9E0_884AC4D0((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884AC4C8: tailcall ts4_if_call_seq_fn_884AB9E0_884AC4D0 */
ts4_word ts4_tailcall_fn_884AC4D0_884AC4C8(ts4_word a0)
{
    return ts4_if_call_seq_fn_884AB9E0_884AC4D0((ts4_word)(a0 + -40));
}

/* Swing_DLL.xex 0x884AC538: set u8@0x61 */
void ts4_set_u8_off61_884AC538(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 97) = (unsigned char)a1;
    return;
}

/* Swing_DLL.xex 0x884AC540: set u8@0x65 */
void ts4_set_u8_off65_884AC540(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 101) = (unsigned char)a1;
    return;
}

/* Swing_DLL.xex 0x884AC548: set u8@0x62 */
void ts4_set_u8_off62_884AC548(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 98) = (unsigned char)a1;
    return;
}

/* Swing_DLL.xex 0x884AC550: set u8@0x63 */
void ts4_set_u8_off63_884AC550(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 99) = (unsigned char)a1;
    return;
}

/* Swing_DLL.xex 0x884AC558: set u8@0x64 */
void ts4_set_u8_off64_884AC558(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 100) = (unsigned char)a1;
    return;
}

/* Swing_DLL.xex 0x884AC560: get u32@0x0, u32@0x18, u32@0x10 */
ts4_word ts4_get_u32_off0_884AC560(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    (void)a2;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 16))))((ts4_word)a0, (ts4_word)t2, (ts4_word)a1, (ts4_word)a3);
}

/* Swing_DLL.xex 0x884AC578: tailcall fn_884235C0 */
ts4_word ts4_tailcall_fn_884235C0_884AC578(ts4_word a0)
{
    return fn_884235C0((ts4_word)(a0 + 84));
}

/* Swing_DLL.xex 0x884AC7A8: get u32@-0x14, u32@0x0, fn_884AD8C0, u32@0x10, u32@lbl_88D25FC4, vcall */
ts4_word ts4_get_u32_0x14_884AC7A8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + -20);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = fn_884AD8C0((ts4_word)a1);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 16);
    t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))(t4))((ts4_word)t1, (ts4_word)(a1 + 224), (ts4_word)t3, (ts4_word)(*(ts4_word *)lbl_88D25FC4));
    return t6;
}

/* Swing_DLL.xex 0x884ACC28: call_seq fn_884ACBC8, lbl_88088AE4, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D25FC4 */
ts4_word ts4_call_seq_fn_884ACBC8_884ACC28(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_88088AE4, (ts4_word)(ts4_word)fn_884ACBC8);
    *(ts4_word *)lbl_88D25FC4 = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x884AD5C8: tailcall fn_884ACC68 */
ts4_word ts4_tailcall_fn_884ACC68_884AD5C8(ts4_word a0)
{
    return fn_884ACC68((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884AD958: get u32@lbl_88D25FC4 */
ts4_word ts4_get_u32_lbl_88D25FC4_884AD958(void)
{
    return (*(ts4_word *)lbl_88D25FC4);
}

/* Swing_DLL.xex 0x884AD968: tailcall ts4_if_call_seq_fn_884AD668_884ADA38 */
ts4_word ts4_tailcall_fn_884ADA38_884AD968(ts4_word a0)
{
    return ts4_if_call_seq_fn_884AD668_884ADA38((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884AD970: tailcall ts4_if_call_seq_fn_884AD668_884ADA38 */
ts4_word ts4_tailcall_fn_884ADA38_884AD970(ts4_word a0)
{
    return ts4_if_call_seq_fn_884AD668_884ADA38((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884AD978: tailcall ts4_if_call_seq_fn_884AD668_884ADA38 */
ts4_word ts4_tailcall_fn_884ADA38_884AD978(ts4_word a0)
{
    return ts4_if_call_seq_fn_884AD668_884ADA38((ts4_word)(a0 + -40));
}

/* Swing_DLL.xex 0x884AD980: tailcall ts4_if_call_seq_fn_884AD668_884ADA38 */
ts4_word ts4_tailcall_fn_884ADA38_884AD980(ts4_word a0)
{
    return ts4_if_call_seq_fn_884AD668_884ADA38((ts4_word)(a0 + -44));
}

/* Swing_DLL.xex 0x884ADCC8: tailcall fn_884ADAA0 */
ts4_word ts4_tailcall_fn_884ADAA0_884ADCC8(ts4_word a0)
{
    return fn_884ADAA0((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884ADCD0: tailcall fn_884ADB38 */
ts4_word ts4_tailcall_fn_884ADB38_884ADCD0(ts4_word a0)
{
    return fn_884ADB38((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884AE258: call_seq fn_884AE1F8, lbl_88086BE4, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D25FD4 */
ts4_word ts4_call_seq_fn_884AE1F8_884AE258(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_88086BE4, (ts4_word)(ts4_word)fn_884AE1F8);
    *(ts4_word *)lbl_88D25FD4 = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x884AE590: get u32@lbl_88D25FD4 */
ts4_word ts4_get_u32_lbl_88D25FD4_884AE590(void)
{
    return (*(ts4_word *)lbl_88D25FD4);
}

/* Swing_DLL.xex 0x884AE5A0: tailcall ts4_if_call_seq_fn_884ADE48_884AE640 */
ts4_word ts4_tailcall_fn_884AE640_884AE5A0(ts4_word a0)
{
    return ts4_if_call_seq_fn_884ADE48_884AE640((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884AE5A8: tailcall ts4_if_call_seq_fn_884ADE48_884AE640 */
ts4_word ts4_tailcall_fn_884AE640_884AE5A8(ts4_word a0)
{
    return ts4_if_call_seq_fn_884ADE48_884AE640((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884AE5B0: tailcall ts4_if_call_seq_fn_884ADE48_884AE640 */
ts4_word ts4_tailcall_fn_884AE640_884AE5B0(ts4_word a0)
{
    return ts4_if_call_seq_fn_884ADE48_884AE640((ts4_word)(a0 + -40));
}

/* Swing_DLL.xex 0x884AE5B8: tailcall ts4_if_call_seq_fn_884ADE48_884AE640 */
ts4_word ts4_tailcall_fn_884AE640_884AE5B8(ts4_word a0)
{
    return ts4_if_call_seq_fn_884ADE48_884AE640((ts4_word)(a0 + -44));
}

/* Swing_DLL.xex 0x884AE6A8: call_seq fn_884B70D0, lbl_88088CE4, lbl_88088CC4, lbl_88088CB4, u32@0x0, u32@0x8 */
ts4_word ts4_call_seq_fn_884B70D0_884AE6A8(ts4_word a0)
{
    fn_884B70D0();
    *(float *)((char *)(ts4_word)(a0) + 48) = (*(float *)lbl_88028BE0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88088CE4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_88088CC4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_88088CB4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x884AE718: addr lbl_88C24FE0, u32@0x0, u32@0x0 */
void ts4_addr_lbl_88C24FE0_884AE718(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(ts4_word)lbl_88C24FE0;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)3;
    return;
}

/* Swing_DLL.xex 0x884AE868: call_seq fn_884AE808, lbl_88088CA0, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D25FDC */
ts4_word ts4_call_seq_fn_884AE808_884AE868(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_88088CA0, (ts4_word)(ts4_word)fn_884AE808);
    *(ts4_word *)lbl_88D25FDC = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x884AE8C0: call_seq lbl_88088CE4, lbl_88088CC4, lbl_88088CB4, u32@0x0, u32@0x8, u32@0x20 */
ts4_word ts4_call_seq_lbl_88088CE4_884AE8C0(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88088CE4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_88088CC4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_88088CB4;
    fn_884AE750((ts4_word)a0);
    t2 = fn_884B6FF8((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x884AEB48: get u32@lbl_88D25FDC */
ts4_word ts4_get_u32_lbl_88D25FDC_884AEB48(void)
{
    return (*(ts4_word *)lbl_88D25FDC);
}

/* Swing_DLL.xex 0x884AEB58: tailcall ts4_if_call_seq_lbl_88088CE4_884AEB68 */
ts4_word ts4_tailcall_fn_884AEB68_884AEB58(ts4_word a0)
{
    return ts4_if_call_seq_lbl_88088CE4_884AEB68((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884AEB60: tailcall ts4_if_call_seq_lbl_88088CE4_884AEB68 */
ts4_word ts4_tailcall_fn_884AEB68_884AEB60(ts4_word a0)
{
    return ts4_if_call_seq_lbl_88088CE4_884AEB68((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884AF008: tailcall fn_884AEBF8 */
ts4_word ts4_tailcall_fn_884AEBF8_884AF008(ts4_word a0)
{
    return fn_884AEBF8((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884AF010: tailcall fn_884AEDA0 */
ts4_word ts4_tailcall_fn_884AEDA0_884AF010(ts4_word a0)
{
    return fn_884AEDA0((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884AF2D0: call_seq fn_884AF270, lbl_88088CF0, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D25FE0 */
ts4_word ts4_call_seq_fn_884AF270_884AF2D0(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_88088CF0, (ts4_word)(ts4_word)fn_884AF270);
    *(ts4_word *)lbl_88D25FE0 = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x884AFA88: get u32@lbl_88D25FE0 */
ts4_word ts4_get_u32_lbl_88D25FE0_884AFA88(void)
{
    return (*(ts4_word *)lbl_88D25FE0);
}

/* Swing_DLL.xex 0x884AFA98: tailcall ts4_if_call_seq_fn_884AF130_884AFAB8 */
ts4_word ts4_tailcall_fn_884AFAB8_884AFA98(ts4_word a0)
{
    return ts4_if_call_seq_fn_884AF130_884AFAB8((ts4_word)(a0 + -44));
}

/* Swing_DLL.xex 0x884AFAA0: tailcall ts4_if_call_seq_fn_884AF130_884AFAB8 */
ts4_word ts4_tailcall_fn_884AFAB8_884AFAA0(ts4_word a0)
{
    return ts4_if_call_seq_fn_884AF130_884AFAB8((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884AFAA8: tailcall ts4_if_call_seq_fn_884AF130_884AFAB8 */
ts4_word ts4_tailcall_fn_884AFAB8_884AFAA8(ts4_word a0)
{
    return ts4_if_call_seq_fn_884AF130_884AFAB8((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884AFAB0: tailcall ts4_if_call_seq_fn_884AF130_884AFAB8 */
ts4_word ts4_tailcall_fn_884AFAB8_884AFAB0(ts4_word a0)
{
    return ts4_if_call_seq_fn_884AF130_884AFAB8((ts4_word)(a0 + -40));
}

/* Swing_DLL.xex 0x884AFB20: get u32@lbl_88D25FE4 */
ts4_word ts4_get_u32_lbl_88D25FE4_884AFB20(void)
{
    return (*(ts4_word *)lbl_88D25FE4);
}

/* Swing_DLL.xex 0x884B0030: call_seq fn_884AFF80, lbl_88088DE8, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D25FE4 */
ts4_word ts4_call_seq_fn_884AFF80_884B0030(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_88088DE8, (ts4_word)(ts4_word)fn_884AFF80);
    *(ts4_word *)lbl_88D25FE4 = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x884B0070: tailcall ts4_if_call_seq_fn_884AFC48_884B0088 */
ts4_word ts4_tailcall_fn_884B0088_884B0070(ts4_word a0)
{
    return ts4_if_call_seq_fn_884AFC48_884B0088((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884B0078: tailcall ts4_if_call_seq_fn_884AFC48_884B0088 */
ts4_word ts4_tailcall_fn_884B0088_884B0078(ts4_word a0)
{
    return ts4_if_call_seq_fn_884AFC48_884B0088((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884B0080: tailcall ts4_if_call_seq_fn_884AFC48_884B0088 */
ts4_word ts4_tailcall_fn_884B0088_884B0080(ts4_word a0)
{
    return ts4_if_call_seq_fn_884AFC48_884B0088((ts4_word)(a0 + -40));
}

/* Swing_DLL.xex 0x884B00F0: call_seq fn_884B96F0, lbl_88088ED8, lbl_88088EB8, lbl_88088EA8, u32@0x0, lbl_88088E98 */
ts4_word ts4_call_seq_fn_884B96F0_884B00F0(ts4_word a0, ts4_word a1)
{
    fn_884B96F0((ts4_word)a0, (ts4_word)a1, (ts4_word)((4278190080) | 32768));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88088ED8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_88088EB8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_88088EA8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(ts4_word)lbl_88088E98;
    return a0;
}

/* Swing_DLL.xex 0x884B0158: fn  */
ts4_word ts4_fn_884B0158(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (a1 + 52);
}

/* Swing_DLL.xex 0x884B01C0: call_seq fn_884B0160, lbl_88088E78, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D25FE8 */
ts4_word ts4_call_seq_fn_884B0160_884B01C0(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_88088E78, (ts4_word)(ts4_word)fn_884B0160);
    *(ts4_word *)lbl_88D25FE8 = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x884B0200: get u32@lbl_88D25FE8 */
ts4_word ts4_get_u32_lbl_88D25FE8_884B0200(void)
{
    return (*(ts4_word *)lbl_88D25FE8);
}

/* Swing_DLL.xex 0x884B0210: tailcall ts4_if_call_seq_fn_884B97D8_884B9E70 */
ts4_word ts4_tailcall_fn_884B9E70_884B0210(ts4_word a0)
{
    return ts4_if_call_seq_fn_884B97D8_884B9E70((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884B0218: call_seq fn_884B96F0, lbl_88088F44, lbl_88088F24, lbl_88088F14, u32@0x0, lbl_88088F04 */
ts4_word ts4_call_seq_fn_884B96F0_884B0218(ts4_word a0, ts4_word a1)
{
    fn_884B96F0((ts4_word)a0, (ts4_word)a1, (ts4_word)((4278190080) | 255));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88088F44;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_88088F24;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_88088F14;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(ts4_word)lbl_88088F04;
    return a0;
}

/* Swing_DLL.xex 0x884B0280: fn  */
ts4_word ts4_fn_884B0280(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (a1 + 40);
}

/* Swing_DLL.xex 0x884B02E8: call_seq fn_884B0288, lbl_88088EE8, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D25FEC */
ts4_word ts4_call_seq_fn_884B0288_884B02E8(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_88088EE8, (ts4_word)(ts4_word)fn_884B0288);
    *(ts4_word *)lbl_88D25FEC = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x884B0328: get u32@lbl_88D25FEC */
ts4_word ts4_get_u32_lbl_88D25FEC_884B0328(void)
{
    return (*(ts4_word *)lbl_88D25FEC);
}

/* Swing_DLL.xex 0x884B0338: tailcall ts4_if_call_seq_fn_884B97D8_884B9E70 */
ts4_word ts4_tailcall_fn_884B9E70_884B0338(ts4_word a0)
{
    return ts4_if_call_seq_fn_884B97D8_884B9E70((ts4_word)(a0 + -40));
}

/* Swing_DLL.xex 0x884B0340: get u32@-0x14, u32@0x0, u32@lbl_88D25FF0, u32@0x10 */
ts4_word ts4_get_u32_0x14_884B0340(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + -20);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)lbl_88D25FF0;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 16))))((ts4_word)t1, (ts4_word)(a1 + 224), (ts4_word)(a1 + 19), (ts4_word)t3);
}

/* Swing_DLL.xex 0x884B0A58: call_seq fn_884B09F8, lbl_88088F54, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D25FF0 */
ts4_word ts4_call_seq_fn_884B09F8_884B0A58(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_88088F54, (ts4_word)(ts4_word)fn_884B09F8);
    *(ts4_word *)lbl_88D25FF0 = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x884B0D50: tailcall fn_884B0A98 */
ts4_word ts4_tailcall_fn_884B0A98_884B0D50(ts4_word a0)
{
    return fn_884B0A98((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884B0FD8: get u32@lbl_88D25FF0 */
ts4_word ts4_get_u32_lbl_88D25FF0_884B0FD8(void)
{
    return (*(ts4_word *)lbl_88D25FF0);
}

/* Swing_DLL.xex 0x884B0FF0: tailcall ts4_if_call_seq_fn_884B0DF0_884B1008 */
ts4_word ts4_tailcall_fn_884B1008_884B0FF0(ts4_word a0)
{
    return ts4_if_call_seq_fn_884B0DF0_884B1008((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884B1838: call_seq fn_884B17D8, lbl_880876A0, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D25FFC */
ts4_word ts4_call_seq_fn_884B17D8_884B1838(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_880876A0, (ts4_word)(ts4_word)fn_884B17D8);
    *(ts4_word *)lbl_88D25FFC = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x884B1878: call_seq fn_884BB330, fn_884E5920, fn_884E5920, fn_884E5920, fn_884E5390 */
ts4_word ts4_call_seq_fn_884BB330_884B1878(ts4_word a0)
{
    fn_884BB330((ts4_word)a0);
    fn_884E5920((ts4_word)(a0 + 208));
    fn_884E5920((ts4_word)(a0 + 352));
    fn_884E5920((ts4_word)(a0 + 496));
    fn_884E5390((ts4_word)(a0 + 640));
    return a0;
}

/* Swing_DLL.xex 0x884B18C8: call_seq ts4_if_call_seq_u32_off8_884E2100, ts4_if_call_seq_u32_off8_884E2100, ts4_if_call_seq_u32_off8_884E2100, ts4_if_call_seq_u32_off8_884E2100 */
ts4_word ts4_call_seq_fn_884E2100_884B18C8(ts4_word a0)
{
    ts4_word t4;

    ts4_if_call_seq_u32_off8_884E2100((ts4_word)(a0 + 640));
    ts4_if_call_seq_u32_off8_884E2100((ts4_word)(a0 + 496));
    ts4_if_call_seq_u32_off8_884E2100((ts4_word)(a0 + 352));
    t4 = ts4_if_call_seq_u32_off8_884E2100((ts4_word)(a0 + 208));
    return t4;
}

/* Swing_DLL.xex 0x884B1910: get u32@lbl_88D25FFC */
ts4_word ts4_get_u32_lbl_88D25FFC_884B1910(void)
{
    return (*(ts4_word *)lbl_88D25FFC);
}

/* Swing_DLL.xex 0x884B1920: tailcall ts4_if_call_seq_fn_884B1510_884B1938 */
ts4_word ts4_tailcall_fn_884B1938_884B1920(ts4_word a0)
{
    return ts4_if_call_seq_fn_884B1510_884B1938((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884B1928: tailcall ts4_if_call_seq_fn_884B1510_884B1938 */
ts4_word ts4_tailcall_fn_884B1938_884B1928(ts4_word a0)
{
    return ts4_if_call_seq_fn_884B1510_884B1938((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884B1930: tailcall ts4_if_call_seq_fn_884B1510_884B1938 */
ts4_word ts4_tailcall_fn_884B1938_884B1930(ts4_word a0)
{
    return ts4_if_call_seq_fn_884B1510_884B1938((ts4_word)(a0 + -40));
}

/* Swing_DLL.xex 0x884B2030: tailcall fn_884B19A0 */
ts4_word ts4_tailcall_fn_884B19A0_884B2030(ts4_word a0)
{
    return fn_884B19A0((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884B2038: tailcall fn_884B1B48 */
ts4_word ts4_tailcall_fn_884B1B48_884B2038(ts4_word a0)
{
    return fn_884B1B48((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884B2298: call_seq fn_884B2238, lbl_88089090, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D26000 */
ts4_word ts4_call_seq_fn_884B2238_884B2298(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_88089090, (ts4_word)(ts4_word)fn_884B2238);
    *(ts4_word *)lbl_88D26000 = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x884B22D8: get u32@lbl_88D26000 */
ts4_word ts4_get_u32_lbl_88D26000_884B22D8(void)
{
    return (*(ts4_word *)lbl_88D26000);
}

/* Swing_DLL.xex 0x884B2308: if_call_seq fn_884B2148, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884B2148_884B2308(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884B2148();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884B2DC8: call_seq fn_884B2580, lbl_88089160, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D26004 */
ts4_word ts4_call_seq_fn_884B2580_884B2DC8(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_88089160, (ts4_word)(ts4_word)fn_884B2580);
    *(ts4_word *)lbl_88D26004 = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x884B2E08: get u32@lbl_88D26004 */
ts4_word ts4_get_u32_lbl_88D26004_884B2E08(void)
{
    return (*(ts4_word *)lbl_88D26004);
}

/* Swing_DLL.xex 0x884B2E18: tailcall ts4_if_call_seq_fn_884B2470_884B2E30 */
ts4_word ts4_tailcall_fn_884B2E30_884B2E18(ts4_word a0)
{
    return ts4_if_call_seq_fn_884B2470_884B2E30((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884B2E20: tailcall ts4_if_call_seq_fn_884B2470_884B2E30 */
ts4_word ts4_tailcall_fn_884B2E30_884B2E20(ts4_word a0)
{
    return ts4_if_call_seq_fn_884B2470_884B2E30((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884B2E28: tailcall ts4_if_call_seq_fn_884B2470_884B2E30 */
ts4_word ts4_tailcall_fn_884B2E30_884B2E28(ts4_word a0)
{
    return ts4_if_call_seq_fn_884B2470_884B2E30((ts4_word)(a0 + -40));
}

/* Swing_DLL.xex 0x884B34E0: call_seq fn_884B30A8, lbl_88086B70, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D26008 */
ts4_word ts4_call_seq_fn_884B30A8_884B34E0(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_88086B70, (ts4_word)(ts4_word)fn_884B30A8);
    *(ts4_word *)lbl_88D26008 = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x884B3520: get u32@lbl_88D26008 */
ts4_word ts4_get_u32_lbl_88D26008_884B3520(void)
{
    return (*(ts4_word *)lbl_88D26008);
}

/* Swing_DLL.xex 0x884B3530: tailcall ts4_if_call_seq_fn_884B2F98_884B3548 */
ts4_word ts4_tailcall_fn_884B3548_884B3530(ts4_word a0)
{
    return ts4_if_call_seq_fn_884B2F98_884B3548((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884B3538: tailcall ts4_if_call_seq_fn_884B2F98_884B3548 */
ts4_word ts4_tailcall_fn_884B3548_884B3538(ts4_word a0)
{
    return ts4_if_call_seq_fn_884B2F98_884B3548((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884B3540: tailcall ts4_if_call_seq_fn_884B2F98_884B3548 */
ts4_word ts4_tailcall_fn_884B3548_884B3540(ts4_word a0)
{
    return ts4_if_call_seq_fn_884B2F98_884B3548((ts4_word)(a0 + -40));
}

/* Swing_DLL.xex 0x884B35B0: if_call_seq lbl_8808923C, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_8808923C_884B35B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808923C;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x884B4E88: call_seq lbl_88089248, fn_884B50B8 */
ts4_word ts4_call_seq_lbl_88089248_884B4E88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word loc50[1];
    ts4_word t1;

    (void)a3;
    loc50[0] = (ts4_word)(ts4_word)lbl_88089248;
    t1 = fn_884B50B8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_88089248);
    return t1;
}

/* Swing_DLL.xex 0x884B4EB8: call_seq u32@0x0, u32@0x8, fn_884B4F10, fn_884B50B8, fn_88423D60 */
ts4_word ts4_call_seq_u32_off0_884B4EB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word t2;
    ts4_word t5;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0))) + 8);
    fn_884B4F10((ts4_word)(ts4_word)&loc50[0], (ts4_word)a2, (ts4_word)a3);
    fn_884B50B8((ts4_word)a0, (ts4_word)a1, (ts4_word)t2, (ts4_word)(ts4_word)&loc50[0]);
    t5 = fn_88423D60((ts4_word)(ts4_word)&loc54[0]);
    return t5;
}

/* Swing_DLL.xex 0x884B4F88: tailcall fn_88423788 */
ts4_word ts4_tailcall_fn_88423788_884B4F88(ts4_word a0, ts4_word a1)
{
    return fn_88423788((ts4_word)(a0 + 4), (ts4_word)a1, (ts4_word)0);
}

/* Swing_DLL.xex 0x884B4F98: if_call_seq fn_88423D60, lbl_8808923C, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_fn_88423D60_884B4F98(ts4_word a0, ts4_word a1)
{
    fn_88423D60((ts4_word)(a0 + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808923C;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x884B6F68: if_call_seq lbl_880894F4, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880894F4_884B6F68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880894F4;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x884B6FB0: if_call_seq lbl_88089504, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_88089504_884B6FB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88089504;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x884B7200: tailcall ts4_if_call_seq_fn_884B6FF8_884B7210 */
ts4_word ts4_tailcall_fn_884B7210_884B7200(ts4_word a0)
{
    return ts4_if_call_seq_fn_884B6FF8_884B7210((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884B7208: tailcall ts4_if_call_seq_fn_884B6FF8_884B7210 */
ts4_word ts4_tailcall_fn_884B7210_884B7208(ts4_word a0)
{
    return ts4_if_call_seq_fn_884B6FF8_884B7210((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884B7A20: if_call_seq fn_884B74E8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884B74E8_884B7A20(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884B74E8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x884B7A88: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_884B7A88(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)8;
    return;
}

/* Swing_DLL.xex 0x884B7AD0: set u32@0x10 */
void ts4_set_u32_off10_884B7AD0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x884B9E68: tailcall ts4_if_call_seq_fn_884B97D8_884B9E70 */
ts4_word ts4_tailcall_fn_884B9E70_884B9E68(ts4_word a0)
{
    return ts4_if_call_seq_fn_884B97D8_884B9E70((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884B9ED8: get  */
void ts4_get_884B9ED8(ts4_word a0)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)lbl_88028BDC);
    return;
}

/* Swing_DLL.xex 0x884B9EE8: addr lbl_88089704, u16@0x6, u32@0x0, u32@0x0, u32@0x8, u32@0xc */
void ts4_addr_lbl_88089704_884B9EE8(ts4_word a0, ts4_word a1)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88089704;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x884B9F10: set u32@0xc */
void ts4_set_u32_offc_884B9F10(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x884BB2D0: if_call_seq lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_lbl_8803A308_884BB2D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884BB5D8: set u32@0x18 */
void ts4_set_u32_off18_884BB5D8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x884BB5E0: set  */
void ts4_set_884BB5E0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 8) = f1;
    return;
}

/* Swing_DLL.xex 0x884BB5F0: set  */
void ts4_set_884BB5F0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    return;
}

/* Swing_DLL.xex 0x884BE210: set u32@0x0 */
void ts4_set_u32_off0_884BE210(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x884BE220: set u32@0x0 */
void ts4_set_u32_off0_884BE220(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x884BEC78: addr lbl_880897DC */
ts4_word ts4_addr_lbl_880897DC_884BEC78(void)
{
    return (ts4_word)lbl_880897DC;
}

/* Swing_DLL.xex 0x884BECF8: tailcall ts4_if_call_seq_fn_884BF7F8_884BED00 */
ts4_word ts4_tailcall_fn_884BED00_884BECF8(ts4_word a0)
{
    return ts4_if_call_seq_fn_884BF7F8_884BED00((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884BED68: if_call_seq fn_884BF898, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884BF898_884BED68(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884BF898((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)11);
    }
    return a0;
}

/* Swing_DLL.xex 0x884BEE10: if_addr lbl_880898DC, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_880898DC_884BEE10(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880898DC;
    return;
}

/* Swing_DLL.xex 0x884BEE30: addr lbl_880898DC */
ts4_word ts4_addr_lbl_880898DC_884BEE30(void)
{
    return (ts4_word)lbl_880898DC;
}

/* Swing_DLL.xex 0x884BEE40: if_addr lbl_880898EC, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_880898EC_884BEE40(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880898EC;
    return;
}

/* Swing_DLL.xex 0x884BEE60: addr lbl_880898EC */
ts4_word ts4_addr_lbl_880898EC_884BEE60(void)
{
    return (ts4_word)lbl_880898EC;
}

/* Swing_DLL.xex 0x884BEEE8: if_call_seq fn_884BEE70, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884BEE70_884BEEE8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884BEE70((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)11);
    }
    return a0;
}

/* Swing_DLL.xex 0x884BEF50: if_call_seq fn_884C0670, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884C0670_884BEF50(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884C0670();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)11);
    }
    return a0;
}

/* Swing_DLL.xex 0x884BEFD8: if_addr lbl_88089C0C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88089C0C_884BEFD8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88089C0C;
    return;
}

/* Swing_DLL.xex 0x884BEFF8: addr lbl_88089C0C */
ts4_word ts4_addr_lbl_88089C0C_884BEFF8(void)
{
    return (ts4_word)lbl_88089C0C;
}

/* Swing_DLL.xex 0x884BF090: if_call_seq fn_884BF008, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884BF008_884BF090(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884BF008();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)11);
    }
    return a0;
}

/* Swing_DLL.xex 0x884BF110: if_addr lbl_88089C9C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88089C9C_884BF110(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88089C9C;
    return;
}

/* Swing_DLL.xex 0x884BF130: addr lbl_88089C9C */
ts4_word ts4_addr_lbl_88089C9C_884BF130(void)
{
    return (ts4_word)lbl_88089C9C;
}

/* Swing_DLL.xex 0x884BF140: if_addr lbl_88089D7C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88089D7C_884BF140(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88089D7C;
    return;
}

/* Swing_DLL.xex 0x884BF178: addr lbl_88089D7C */
ts4_word ts4_addr_lbl_88089D7C_884BF178(void)
{
    return (ts4_word)lbl_88089D7C;
}

/* Swing_DLL.xex 0x884BF188: if_addr lbl_88089D90, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88089D90_884BF188(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88089D90;
    return;
}

/* Swing_DLL.xex 0x884BF1C0: addr lbl_88089D90 */
ts4_word ts4_addr_lbl_88089D90_884BF1C0(void)
{
    return (ts4_word)lbl_88089D90;
}

/* Swing_DLL.xex 0x884BF1F0: if_addr lbl_88089E2C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88089E2C_884BF1F0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88089E2C;
    return;
}

/* Swing_DLL.xex 0x884BF210: addr lbl_88089E2C */
ts4_word ts4_addr_lbl_88089E2C_884BF210(void)
{
    return (ts4_word)lbl_88089E2C;
}

/* Swing_DLL.xex 0x884BF2C0: if_addr lbl_88089F34, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88089F34_884BF2C0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88089F34;
    return;
}

/* Swing_DLL.xex 0x884BF2E0: addr lbl_88089F34 */
ts4_word ts4_addr_lbl_88089F34_884BF2E0(void)
{
    return (ts4_word)lbl_88089F34;
}

/* Swing_DLL.xex 0x884BF2F0: if_call_seq lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_lbl_8803A308_884BF2F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)11);
    }
    return a0;
}

/* Swing_DLL.xex 0x884BF368: if_addr lbl_88089F94, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88089F94_884BF368(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88089F94;
    return;
}

/* Swing_DLL.xex 0x884BF388: addr lbl_88089F94 */
ts4_word ts4_addr_lbl_88089F94_884BF388(void)
{
    return (ts4_word)lbl_88089F94;
}

/* Swing_DLL.xex 0x884BF438: if_addr lbl_8808A00C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8808A00C_884BF438(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808A00C;
    return;
}

/* Swing_DLL.xex 0x884BF458: addr lbl_8808A00C */
ts4_word ts4_addr_lbl_8808A00C_884BF458(void)
{
    return (ts4_word)lbl_8808A00C;
}

/* Swing_DLL.xex 0x884BF4F8: if_call_seq fn_884BF468, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884BF468_884BF4F8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884BF468();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)11);
    }
    return a0;
}

/* Swing_DLL.xex 0x884BF578: if_addr lbl_8808A0CC, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8808A0CC_884BF578(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808A0CC;
    return;
}

/* Swing_DLL.xex 0x884BF598: addr lbl_8808A0CC */
ts4_word ts4_addr_lbl_8808A0CC_884BF598(void)
{
    return (ts4_word)lbl_8808A0CC;
}

/* Swing_DLL.xex 0x884BF620: if_call_seq fn_884BF5A8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884BF5A8_884BF620(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884BF5A8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)11);
    }
    return a0;
}

/* Swing_DLL.xex 0x884BF6A0: if_addr lbl_8808A13C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8808A13C_884BF6A0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808A13C;
    return;
}

/* Swing_DLL.xex 0x884BF6C0: addr lbl_8808A13C */
ts4_word ts4_addr_lbl_8808A13C_884BF6C0(void)
{
    return (ts4_word)lbl_8808A13C;
}

/* Swing_DLL.xex 0x884BF6F0: if_addr lbl_8808A544, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8808A544_884BF6F0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808A544;
    return;
}

/* Swing_DLL.xex 0x884BF710: addr lbl_8808A544 */
ts4_word ts4_addr_lbl_8808A544_884BF710(void)
{
    return (ts4_word)lbl_8808A544;
}

/* Swing_DLL.xex 0x884BF720: if_call_seq fn_884C26E0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884C26E0_884BF720(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884C26E0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)11);
    }
    return a0;
}

/* Swing_DLL.xex 0x884BF7F8: addr lbl_88087754, lbl_8803A308, u32@0x8, u32@0x0 */
void ts4_addr_lbl_88087754_884BF7F8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_88087754;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x884BF818: if_get u32@0x4, u32@0x4, u32@0x8 */
void ts4_if_get_u32_off4_884BF818(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != (ts4_word)t2) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)1;
    return;
}

/* Swing_DLL.xex 0x884C12F0: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, lbl_88089D7C, u16@0x4, u32@0x0 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_884C12F0(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)20, (ts4_word)11);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)20;
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88089D7C;
    *(unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)(*(unsigned short *)((char *)(ts4_word)(a0) + 4));
    *(unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)(*(unsigned short *)((char *)(ts4_word)(a0) + 6));
    *(float *)((char *)(ts4_word)(t3) + 8) = (*(float *)((char *)(ts4_word)(a0) + 8));
    *(float *)((char *)(ts4_word)(t3) + 12) = (*(float *)((char *)(ts4_word)(a0) + 12));
    *(unsigned char *)((char *)(ts4_word)(t3) + 16) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 16));
    *(unsigned char *)((char *)(ts4_word)(t3) + 17) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 17));
    return t3;
}

/* Swing_DLL.xex 0x884C1DB8: addr lbl_8808A13C, u16@0x6, u32@0x0 */
void ts4_addr_lbl_8808A13C_884C1DB8(ts4_word a0)
{
    float t1;
    float t2;

    t1 = *(float *)lbl_88001A20;
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    t2 = *(float *)lbl_88001A68;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808A13C;
    *(float *)((char *)(ts4_word)(a0) + 8) = t1;
    *(float *)((char *)(ts4_word)(a0) + 12) = t1;
    *(float *)((char *)(ts4_word)(a0) + 16) = t2;
    return;
}

/* Swing_DLL.xex 0x884C1EC0: tailcall ts4_if_call_seq_u32_off18_885F4C88 */
ts4_word ts4_tailcall_fn_885F4C88_884C1EC0(ts4_word a0)
{
    return ts4_if_call_seq_u32_off18_885F4C88((ts4_word)a0);
}

/* Swing_DLL.xex 0x884C1EC8: get  */
float ts4_get_884C1EC8(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 184));
}

/* Swing_DLL.xex 0x884C1ED0: get u32@0x3c, u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_off3c_884C1ED0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884C4FA0: tailcall fn_884C4FA8 */
ts4_word ts4_tailcall_fn_884C4FA8_884C4FA0(ts4_word a0)
{
    return fn_884C4FA8((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x884C5378: get u32@lbl_88D3CB50 */
ts4_word ts4_get_u32_lbl_88D3CB50_884C5378(void)
{
    return (*(ts4_word *)lbl_88D3CB50);
}

/* Swing_DLL.xex 0x884C5388: get u32@lbl_88D3CB4C */
ts4_word ts4_get_u32_lbl_88D3CB4C_884C5388(void)
{
    return (*(ts4_word *)lbl_88D3CB4C);
}

/* Swing_DLL.xex 0x884C5398: get u32@lbl_88CAD568 */
ts4_word ts4_get_u32_lbl_88CAD568_884C5398(void)
{
    return (*(ts4_word *)lbl_88CAD568);
}

/* Swing_DLL.xex 0x884C5448: fn  */
ts4_word ts4_fn_884C5448(ts4_word a0)
{
    return (a0 + 8);
}

/* Swing_DLL.xex 0x884C5450: fn  */
ts4_word ts4_fn_884C5450(ts4_word a0)
{
    return (a0 + 20);
}

/* Swing_DLL.xex 0x884C5458: addr lbl_8808BFAC */
ts4_word ts4_addr_lbl_8808BFAC_884C5458(void)
{
    return (ts4_word)lbl_8808BFAC;
}

/* Swing_DLL.xex 0x884C9308: if_call_seq fn_884C9150, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884C9150_884C9308(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884C9150((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x884C95D8: if_call_seq lbl_8808C1A8, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_8808C1A8_884C95D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808C1A8;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x884C9818: get u32@0x18 */
ts4_word ts4_get_u32_off18_884C9818(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

/* Swing_DLL.xex 0x884C9820: get u32@0x1c */
ts4_word ts4_get_u32_off1c_884C9820(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 28));
}

/* Swing_DLL.xex 0x884C9828: get u32@0x1c, u32@0x14 */
ts4_word ts4_get_u32_off1c_884C9828(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 20));
}

/* Swing_DLL.xex 0x884C9838: get u32@0x20 */
ts4_word ts4_get_u32_off20_884C9838(ts4_word a0, ts4_word a1)
{
    return (((a1 + (a1 << 1)) << 4) + (*(ts4_word *)((char *)(ts4_word)(a0) + 32)));
}

/* Swing_DLL.xex 0x884CAFD8: if_get u32@0x20, u32@0x0, u32@0x70, u32@0x28, u32@0x14, vcall */
ts4_word ts4_if_get_u32_off20_884CAFD8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 112);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 40);
    t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(t4))((ts4_word)a1, (ts4_word)((*(ts4_word *)((char *)(ts4_word)((((a2 + (a2 << 1)) << 4) + t1)) + 20)) + t3), (ts4_word)0);
    if ((int)t6 == 0) {
        t7 = fn_884CAD68((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        return t7;
    }
    return 1;
}

/* Swing_DLL.xex 0x884CC130: if_call_seq fn_884D3860, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884D3860_884CC130(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884D3860();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x884CC198: set u32@0x34, fn_88423660, u32@0x0, u32@0x34, u32@0x14, vcall */
ts4_word ts4_set_u32_off34_884CC198(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)a1;
    fn_88423660((ts4_word)(a0 + 40));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 20))))((ts4_word)a0, (ts4_word)t3, (ts4_word)(a0 + 52));
    return t5;
}

/* Swing_DLL.xex 0x884CC1F8: if_call_seq fn_88423D60, lbl_8808C1A8, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_fn_88423D60_884CC1F8(ts4_word a0, ts4_word a1)
{
    fn_88423D60((ts4_word)(a0 + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808C1A8;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x884CC368: tailcall fn_88423660 */
ts4_word ts4_tailcall_fn_88423660_884CC368(ts4_word a0)
{
    return fn_88423660((ts4_word)(a0 + 40));
}

/* Swing_DLL.xex 0x884CC370: tailcall fn_88423DC8 */
ts4_word ts4_tailcall_fn_88423DC8_884CC370(ts4_word a0)
{
    return fn_88423DC8((ts4_word)(a0 + 40));
}

/* Swing_DLL.xex 0x884CC868: if_call_seq fn_884CC7B8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884CC7B8_884CC868(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884CC7B8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x884CCB38: if_call_seq fn_884CB388, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884CB388_884CCB38(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884CB388();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)6);
    }
    return a0;
}

/* Swing_DLL.xex 0x884CCBA0: set u32@0x0, u32@0x8, u32@0xc, u32@0x4 */
void ts4_set_u32_off0_884CCBA0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x884CCBB8: if_call_seq u32@0x0, u32@0x8, u32@0xc, ts4_get_u32_off0_8841EAC8, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off0_884CCBB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p2;
    ts4_word t1;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a3;
    if ((ts4_word)a3 != 0) {
        t1 = ts4_get_u32_off0_8841EAC8((ts4_word)a3);
        p2 = (ts4_word)t1;
    } else {
        p2 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)p2;
    return a0;
}

/* Swing_DLL.xex 0x884CCDF0: call_seq fn_884210E8 */
ts4_word ts4_call_seq_fn_884210E8_884CCDF0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_884210E8((ts4_word)a0, (ts4_word)a1);
    return (t1 == 0);
}

/* Swing_DLL.xex 0x884CE050: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_884CD260 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_884CE050(void)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)36, (ts4_word)21);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)36;
    t4 = fn_884CD260((ts4_word)t3);
    return t4;
}

/* Swing_DLL.xex 0x884CE090: tailcall fn_884CD990 */
ts4_word ts4_tailcall_fn_884CD990_884CE090(ts4_word a0)
{
    return fn_884CD990((ts4_word)a0);
}

/* Swing_DLL.xex 0x884CE098: if_call_seq fn_885E78C8, u32@0x0 */
ts4_word ts4_if_call_seq_fn_885E78C8_884CE098(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;

    t1 = fn_885E78C8((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 == 0) {
        t2 = loc50[0];
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t2;
        return t1;
    }
    return 1;
}

/* Swing_DLL.xex 0x884CE0F0: if_call_seq ts4_get_u32_off0_8841EAC8, fn_885E76C0 */
ts4_word ts4_if_call_seq_fn_8841EAC8_884CE0F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t4;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a2 != 0) {
        p3 = (ts4_word)a2;
    } else {
        t1 = ts4_get_u32_off0_8841EAC8((ts4_word)a1);
        p3 = (ts4_word)t1;
    }
    t4 = fn_885E76C0((ts4_word)(a0 + 12), (ts4_word)p3, (ts4_word)a1);
    return t4;
}

/* Swing_DLL.xex 0x884CE1B8: tailcall fn_885E7AD8 */
ts4_word ts4_tailcall_fn_885E7AD8_884CE1B8(ts4_word a0, ts4_word a1)
{
    return fn_885E7AD8((ts4_word)(a0 + 12), (ts4_word)a1, (ts4_word)0);
}

/* Swing_DLL.xex 0x884CE3D8: if_call_seq fn_884CD318, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884CD318_884CE3D8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884CD318();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x884CE798: if_call_seq fn_8841E4A0, fn_8841DC28, u8@0x0, fn_884CE440, fn_8841DBA0, fn_8841DBA0 */
ts4_word ts4_if_call_seq_fn_8841E4A0_884CE798(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc58[3];
    ts4_word loc50[1];
    ts4_word t2;
    unsigned char t3;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    fn_8841E4A0((ts4_word)(ts4_word)&loc58[0]);
    t2 = fn_8841DC28((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
    t3 = *(unsigned char *)((char *)(ts4_word)(t2) + 0);
    if ((ts4_word)t3 != 0) {
        t4 = loc58[2];
        t5 = fn_884CE440((ts4_word)a0, (ts4_word)t4, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
        fn_8841DBA0((ts4_word)(ts4_word)&loc58[0]);
        return t5;
    }
    fn_8841DBA0((ts4_word)(ts4_word)&loc58[0]);
    return 0;
}

/* Swing_DLL.xex 0x884CE818: get u32@lbl_88D26F84, u32@lbl_88D26FCC, u32@0x0, u32@0xc, vcall, lbl_88D26F54 */
ts4_word ts4_get_u32_lbl_88D26F84_884CE818(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)lbl_88D26F84;
    t2 = *(ts4_word *)lbl_88D26FCC;
    t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1);
    t6 = fn_884CE440((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88D26F54, (ts4_word)t5, (ts4_word)t2);
    return t6;
}

/* Swing_DLL.xex 0x884CE938: get u32@0x8 */
ts4_word ts4_get_u32_off8_884CE938(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Swing_DLL.xex 0x884CE988: set u32@0xc, u32@0x10, lbl_8808C36C, u32@0x8, u16@0x6, u32@0x0 */
void ts4_set_u32_offc_884CE988(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808C36C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}
