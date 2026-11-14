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

extern char fn_88484248[];
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
ts4_word ts4_ref_holder_dtor_8847E9F0();
ts4_word fn_884812E0();
ts4_word fn_88484538();
ts4_word fn_88488740();
ts4_word fn_8848C010();
ts4_word fn_8848C0A0();
ts4_word fn_8848D2D8();
ts4_word fn_8848E3E0();
ts4_word fn_8848E420();
ts4_word fn_884911B8();
ts4_word fn_88492D88();
ts4_word fn_884936E0();
ts4_word ts4_if_call_seq_fn_884936E0_88493D50();
ts4_word fn_884942A8();
ts4_word fn_884944C0();
ts4_word fn_884980C0();
ts4_word fn_88498B98();
ts4_word fn_8849FE80();
ts4_word ts4_if_call_seq_fn_884A4CF8_884A1328();
ts4_word ts4_if_call_seq_fn_884A5688_884A14F8();
ts4_word ts4_if_call_seq_fn_884A6E18_884A1938();
ts4_word fn_884A1CA8();
ts4_word fn_884A1EA0();
ts4_word fn_884A2100();
ts4_word fn_884A21A8();
ts4_word fn_884A2AA0();
ts4_word fn_884A2E50();
ts4_word fn_884A2FE8();
ts4_word ts4_if_call_seq_fn_884A2E50_884A30F0();
ts4_word fn_884A4088();
ts4_word fn_884A4CF8();
ts4_word fn_884A5688();
ts4_word fn_884A6E18();
ts4_word fn_884A7430();
ts4_word fn_884A83D8();
ts4_word fn_884A8C80();
ts4_word fn_884A8D60();
ts4_word ts4_call_seq_fn_884A92F8_884A94E0();
ts4_word fn_884A9828();
ts4_word fn_884A9A20();
ts4_word ts4_call_seq_fn_884A9950_884A9B78();
ts4_word ts4_if_call_seq_fn_884A9A20_884A9BD8();
ts4_word fn_884AA078();
ts4_word ts4_call_seq_fn_884AA708_884AA768();
ts4_word ts4_if_call_seq_fn_884AA078_884AA7D8();
ts4_word ts4_call_seq_fn_884AB258_884AB2B8();
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
ts4_word ts4_if_get_u32_off8_885F4C70();
ts4_word ts4_if_call_seq_u32_off18_885F4D78();
ts4_word ts4_noop_884927F8();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x8847A9C0: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, lbl_88083774, u32@0x0, lbl_88083788 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_8847A9C0(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;
    unsigned char t4;
    float t6;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)40, (ts4_word)44);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88083774;
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)40;
    *(unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    t4 = *(unsigned char *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88083788;
    *(unsigned char *)((char *)(ts4_word)(t3) + 8) = (unsigned char)t4;
    *(float *)((char *)(ts4_word)(t3) + 12) = (*(float *)((char *)(ts4_word)(a0) + 12));
    t6 = *(float *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_8808379C;
    *(float *)((char *)(ts4_word)(t3) + 16) = t6;
    *(ts4_word *)((char *)(ts4_word)(t3) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20));
    *(ts4_word *)((char *)(ts4_word)(t3) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
    *(ts4_word *)((char *)(ts4_word)(t3) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
    *(ts4_word *)((char *)(ts4_word)(t3) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32));
    *(ts4_word *)((char *)(ts4_word)(t3) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36));
    return t3;
}

/* Swing_DLL.xex 0x8847B008: fn  */
ts4_word ts4_fn_8847B008(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8847B0E8: fn  */
ts4_word ts4_fn_8847B0E8(void)
{
    return 1;
}

/* Swing_DLL.xex 0x8847B0F0: set u8@0x0 */
void ts4_set_u8_off0_8847B0F0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8847B100: set u8@0x0 */
void ts4_set_u8_off0_8847B100(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8847B3B0: call_seq fn_8847B208, lbl_88083CFC, u8@0x8, u32@0x0 */
ts4_word ts4_call_seq_fn_8847B208_8847B3B0(ts4_word a0)
{
    fn_8847B208((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88083CFC;
    return a0;
}

/* Swing_DLL.xex 0x8847B4D0: get u32@0x20, u32@0x0, u32@0x4 */
void ts4_get_u32_off20_8847B4D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(t1 << 3);
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x8847B638: set u8@0x0 */
void ts4_set_u8_off0_8847B638(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x8847B648: fn  */
ts4_word ts4_fn_8847B648(void)
{
    return 10;
}

/* Swing_DLL.xex 0x8847B6A0: get u32@0x28 */
ts4_word ts4_get_u32_off28_8847B6A0(ts4_word a0, ts4_word a1)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 40)) + (a1 << 4));
}

/* Swing_DLL.xex 0x8847BEF8: call_seq u32@0x4c, fn_885068E8, fn_8847B888 */
ts4_word ts4_call_seq_u32_off4c_8847BEF8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;

    fn_885068E8((ts4_word)a1, (ts4_word)a2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 76)), (ts4_word)8);
    t3 = fn_8847B888((ts4_word)a0, (ts4_word)(a0 + 24), (ts4_word)a1, (ts4_word)a2);
    return t3;
}

/* Swing_DLL.xex 0x8847C920: if_call_seq fn_8847B7E8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8847B7E8_8847C920(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8847B7E8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)44);
    }
    return a0;
}

/* Swing_DLL.xex 0x8847C9B8: tailcall fn_88478648 */
ts4_word ts4_tailcall_fn_88478648_8847C9B8(ts4_word a0, ts4_word a1)
{
    return fn_88478648((ts4_word)(a0 + 16), (ts4_word)150, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8847CA58: fn  */
ts4_word ts4_fn_8847CA58(void)
{
    return 1;
}

/* Swing_DLL.xex 0x8847D148: tailcall fn_88478648 */
ts4_word ts4_tailcall_fn_88478648_8847D148(ts4_word a0, ts4_word a1)
{
    return fn_88478648((ts4_word)(a0 + 16), (ts4_word)132, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8847D200: fn  */
ts4_word ts4_fn_8847D200(void)
{
    return 18;
}

/* Swing_DLL.xex 0x8847D718: tailcall fn_88478648 */
ts4_word ts4_tailcall_fn_88478648_8847D718(ts4_word a0, ts4_word a1)
{
    return fn_88478648((ts4_word)(a0 + 16), (ts4_word)198, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8847D728: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_8847D728(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)8;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)80;
    return;
}

/* Swing_DLL.xex 0x8847D7E8: fn  */
ts4_word ts4_fn_8847D7E8(void)
{
    return 2;
}

/* Swing_DLL.xex 0x8847DD00: get  */
float ts4_get_8847DD00(void)
{
    return (*(float *)lbl_88001A20);
}

/* Swing_DLL.xex 0x8847DD18: set  */
void ts4_set_8847DD18(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 8) = f1;
    return;
}

/* Swing_DLL.xex 0x8847E828: get u32@0xc, u32@0x0, u32@0x2c, vcall, u32@0x10, u32@0x14 */
ts4_word ts4_get_u32_offc_8847E828(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 44))))((ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)(a0 + 16);
    *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)12;
    return t4;
}

/* Swing_DLL.xex 0x8847E898: set  */
void ts4_set_8847E898(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 28) = f1;
    return;
}

/* Swing_DLL.xex 0x8847E8A8: get u32@0xc, u32@0x0, u32@0xc, vcall */
ts4_word ts4_get_u32_offc_8847E8A8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x8847E8E8: fn  */
ts4_word ts4_fn_8847E8E8(void)
{
    return 13;
}

/* Swing_DLL.xex 0x8847E8F0: get u32@0xc */
ts4_word ts4_get_u32_offc_8847E8F0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x8847E8F8: get u32@0xc */
ts4_word ts4_get_u32_offc_8847E8F8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x8847EB20: if_call_seq ts4_ref_holder_dtor_8847E9F0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8847E9F0_8847EB20(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_ref_holder_dtor_8847E9F0((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)44);
    }
    return a0;
}

/* Swing_DLL.xex 0x8847FA50: get u32@0x0, u32@0x20 */
ts4_word ts4_get_u32_off0_8847FA50(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 32))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8847FEE0: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_8847FEE0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)7;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)60;
    return;
}

/* Swing_DLL.xex 0x8847FEF8: tailcall fn_88420E00 */
ts4_word ts4_tailcall_fn_88420E00_8847FEF8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88420E00((ts4_word)a2, (ts4_word)a1, (ts4_word)(a0 + 96));
}

/* Swing_DLL.xex 0x8847FF08: fn  */
ts4_word ts4_fn_8847FF08(void)
{
    return 3;
}

/* Swing_DLL.xex 0x884801B0: set u32@0x10, u32@0x14, u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off10_884801B0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)(a0 + 12);
    *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)12;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)384;
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)7;
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)8;
    return;
}

/* Swing_DLL.xex 0x88480A18: tailcall fn_88478648 */
ts4_word ts4_tailcall_fn_88478648_88480A18(ts4_word a0, ts4_word a1)
{
    return fn_88478648((ts4_word)(a0 + 16), (ts4_word)148, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88480AE8: fn  */
ts4_word ts4_fn_88480AE8(void)
{
    return 14;
}

/* Swing_DLL.xex 0x88480DE8: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, lbl_88083774, u32@0x0, lbl_88083788 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_88480DE8(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;
    unsigned char t4;
    float t6;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)36, (ts4_word)44);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88083774;
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)36;
    *(unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    t4 = *(unsigned char *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88083788;
    *(unsigned char *)((char *)(ts4_word)(t3) + 8) = (unsigned char)t4;
    *(float *)((char *)(ts4_word)(t3) + 12) = (*(float *)((char *)(ts4_word)(a0) + 12));
    t6 = *(float *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880843CC;
    *(float *)((char *)(ts4_word)(t3) + 16) = t6;
    *(float *)((char *)(ts4_word)(t3) + 20) = (*(float *)((char *)(ts4_word)(a0) + 20));
    *(float *)((char *)(ts4_word)(t3) + 24) = (*(float *)((char *)(ts4_word)(a0) + 24));
    *(float *)((char *)(ts4_word)(t3) + 28) = (*(float *)((char *)(ts4_word)(a0) + 28));
    *(float *)((char *)(ts4_word)(t3) + 32) = (*(float *)((char *)(ts4_word)(a0) + 32));
    return t3;
}

/* Swing_DLL.xex 0x88480EB8: fn  */
ts4_word ts4_fn_88480EB8(void)
{
    return 102;
}

/* Swing_DLL.xex 0x88481B80: set u8@0x0 */
void ts4_set_u8_off0_88481B80(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88481B90: if_call_seq fn_884812E0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884812E0_88481B90(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884812E0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)44);
    }
    return a0;
}

/* Swing_DLL.xex 0x88481E08: tailcall fn_88478648 */
ts4_word ts4_tailcall_fn_88478648_88481E08(ts4_word a0, ts4_word a1)
{
    return fn_88478648((ts4_word)(a0 + 16), (ts4_word)192, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88481E18: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_88481E18(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)8;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)72;
    return;
}

/* Swing_DLL.xex 0x88481ED0: fn  */
ts4_word ts4_fn_88481ED0(void)
{
    return 6;
}

/* Swing_DLL.xex 0x88482318: tailcall fn_88478648 */
ts4_word ts4_tailcall_fn_88478648_88482318(ts4_word a0, ts4_word a1)
{
    return fn_88478648((ts4_word)(a0 + 16), (ts4_word)112, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88482388: fn  */
ts4_word ts4_fn_88482388(void)
{
    return 15;
}

/* Swing_DLL.xex 0x88482570: tailcall fn_88478648 */
ts4_word ts4_tailcall_fn_88478648_88482570(ts4_word a0, ts4_word a1)
{
    return fn_88478648((ts4_word)(a0 + 16), (ts4_word)172, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88482778: fn  */
ts4_word ts4_fn_88482778(void)
{
    return 19;
}

/* Swing_DLL.xex 0x88482A00: call_seq fn_8841F998, fn_8841F998 */
ts4_word ts4_call_seq_fn_8841F998_88482A00(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    fn_8841F998((ts4_word)(a0 + 32), (ts4_word)a1);
    t2 = fn_8841F998((ts4_word)(a0 + 80), (ts4_word)a2);
    return t2;
}

/* Swing_DLL.xex 0x88482A48: tailcall fn_88478648 */
ts4_word ts4_tailcall_fn_88478648_88482A48(ts4_word a0, ts4_word a1)
{
    return fn_88478648((ts4_word)(a0 + 16), (ts4_word)116, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88482B18: fn  */
ts4_word ts4_fn_88482B18(void)
{
    return 16;
}

/* Swing_DLL.xex 0x88482C20: fn  */
ts4_word ts4_fn_88482C20(void)
{
    return 1;
}

/* Swing_DLL.xex 0x884834E0: addr lbl_8803A308, u32@0x0 */
void ts4_addr_lbl_8803A308_884834E0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88485578: addr fn_88484248, fn_88484538 */
ts4_word ts4_addr_fn_88484248_88485578(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_88484538((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)(ts4_word)fn_88484248, (ts4_word)a4);
}

/* Swing_DLL.xex 0x88485860: fn  */
ts4_word ts4_fn_88485860(void)
{
    return 2;
}

/* Swing_DLL.xex 0x88485DD0: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, lbl_88083774, u32@0x0, lbl_88083788 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_88485DD0(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;
    unsigned char t4;
    float t6;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)28, (ts4_word)44);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88083774;
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)28;
    *(unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    t4 = *(unsigned char *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88083788;
    *(unsigned char *)((char *)(ts4_word)(t3) + 8) = (unsigned char)t4;
    *(float *)((char *)(ts4_word)(t3) + 12) = (*(float *)((char *)(ts4_word)(a0) + 12));
    t6 = *(float *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88084C94;
    *(float *)((char *)(ts4_word)(t3) + 16) = t6;
    *(float *)((char *)(ts4_word)(t3) + 20) = (*(float *)((char *)(ts4_word)(a0) + 20));
    *(float *)((char *)(ts4_word)(t3) + 24) = (*(float *)((char *)(ts4_word)(a0) + 24));
    return t3;
}

/* Swing_DLL.xex 0x88485E70: fn  */
ts4_word ts4_fn_88485E70(void)
{
    return 100;
}

/* Swing_DLL.xex 0x88486458: tailcall fn_88478648 */
ts4_word ts4_tailcall_fn_88478648_88486458(ts4_word a0, ts4_word a1)
{
    return fn_88478648((ts4_word)(a0 + 16), (ts4_word)56, (ts4_word)a1);
}

/* Swing_DLL.xex 0x884864C0: fn  */
ts4_word ts4_fn_884864C0(void)
{
    return 8;
}

/* Swing_DLL.xex 0x88486528: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, lbl_88083774, u32@0x0, lbl_88083788 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_88486528(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;
    unsigned char t4;
    float t6;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)32, (ts4_word)44);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88083774;
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)32;
    *(unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    t4 = *(unsigned char *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88083788;
    *(unsigned char *)((char *)(ts4_word)(t3) + 8) = (unsigned char)t4;
    *(float *)((char *)(ts4_word)(t3) + 12) = (*(float *)((char *)(ts4_word)(a0) + 12));
    t6 = *(float *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88084F6C;
    *(float *)((char *)(ts4_word)(t3) + 16) = t6;
    *(float *)((char *)(ts4_word)(t3) + 20) = (*(float *)((char *)(ts4_word)(a0) + 20));
    *(float *)((char *)(ts4_word)(t3) + 24) = (*(float *)((char *)(ts4_word)(a0) + 24));
    *(unsigned char *)((char *)(ts4_word)(t3) + 28) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 28));
    return t3;
}

/* Swing_DLL.xex 0x88486698: tailcall fn_88478648 */
ts4_word ts4_tailcall_fn_88478648_88486698(ts4_word a0, ts4_word a1)
{
    return fn_88478648((ts4_word)(a0 + 16), (ts4_word)292, (ts4_word)a1);
}

/* Swing_DLL.xex 0x884866D8: fn  */
ts4_word ts4_fn_884866D8(void)
{
    return 9;
}

/* Swing_DLL.xex 0x88487020: if_call_seq u32@0x0, u32@0x8, u32@0xc, u32@0x4, fn_88498B98, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off0_88487020(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)16;
        fn_88498B98((ts4_word)(a0 + 28), (ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    }
    return a0;
}

/* Swing_DLL.xex 0x884876C0: set u32@0xfc */
void ts4_set_u32_offfc_884876C0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 252) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x884876D0: get u32@0xf8, u32@0x0 */
void ts4_get_u32_offf8_884876D0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 248));
    return;
}

/* Swing_DLL.xex 0x884876E0: get u32@0x0, u32@0xf8 */
void ts4_get_u32_off0_884876E0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 248) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    return;
}

/* Swing_DLL.xex 0x88489320: if_call_seq lbl_880869E8, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880869E8_88489320(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880869E8;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x88489368: fn  */
ts4_word ts4_fn_88489368(ts4_word a0)
{
    return (a0 + 384);
}

/* Swing_DLL.xex 0x88489370: if_call_seq fn_88488740, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88488740_88489370(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88488740();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x8848A900: addr lbl_8803A308, u32@0x0 */
void ts4_addr_lbl_8803A308_8848A900(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x8848AD98: set u32@0x8, lbl_88087470, u16@0x6, u32@0x0 */
void ts4_set_u32_off8_8848AD98(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087470;
    return;
}

/* Swing_DLL.xex 0x8848AF58: if_call_seq lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_lbl_8803A308_8848AF58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)34);
    }
    return a0;
}

/* Swing_DLL.xex 0x8848B030: fn  */
ts4_word ts4_fn_8848B030(ts4_word a0)
{
    return (a0 + 68);
}

/* Swing_DLL.xex 0x8848B110: get u32@0x14, u32@0x30 */
ts4_word ts4_get_u32_off14_8848B110(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 48))))((ts4_word)(a0 + 20), (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8848B128: get u32@0x14, u32@0x34 */
ts4_word ts4_get_u32_off14_8848B128(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 52))))((ts4_word)(a0 + 20), (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8848B198: get u32@0x20 */
ts4_word ts4_get_u32_off20_8848B198(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) + -20);
}

/* Swing_DLL.xex 0x8848B9C0: set u32@0x8, lbl_88087484, u16@0x6, u32@0x0 */
void ts4_set_u32_off8_8848B9C0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087484;
    return;
}

/* Swing_DLL.xex 0x8848B9E0: tailcall fn_8848C010 */
ts4_word ts4_tailcall_fn_8848C010_8848B9E0(ts4_word a0)
{
    return fn_8848C010((ts4_word)(a0 + 32));
}

/* Swing_DLL.xex 0x8848BD08: if_call_seq u32@0x3c, lbl_880874EC, u32@0x0, u16@0x4, u32@0xc, fn_8848E420 */
ts4_word ts4_if_call_seq_u32_off3c_8848BD08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    unsigned short t2;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880874EC;
    t2 = *(unsigned short *)((char *)(ts4_word)(t1) + 4);
    if ((ts4_word)t2 != 0) {
        fn_8848E420((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)(a0 + 68), (ts4_word)1);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    fn_88476CB0((ts4_word)(a0 + 68));
    t7 = fn_8848C0A0((ts4_word)(a0 + 20));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return t7;
}

/* Swing_DLL.xex 0x8848C148: if_call_seq fn_8848C0A0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8848C0A0_8848C148(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8848C0A0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)44);
    }
    return a0;
}

/* Swing_DLL.xex 0x8848E320: call_seq fn_8849FE80, fn_8848D2D8 */
ts4_word ts4_call_seq_fn_8849FE80_8848E320(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_8849FE80();
    t2 = fn_8848D2D8((ts4_word)a0, (ts4_word)a1);
    return t2;
}

/* Swing_DLL.xex 0x884926D8: if_get u32@0x8, u32@0x0 */
ts4_word ts4_if_get_u32_off8_884926D8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)(a1 + 1) == (int)t1) {
        return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    }
    return 512;
}

/* Swing_DLL.xex 0x884927D0: get u32@0x14, u32@0x8, fn_8848E3E0 */
ts4_word ts4_get_u32_off14_884927D0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_8848E3E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 20))) + 8)), (ts4_word)a1);
}

/* Swing_DLL.xex 0x884928D0: if_get u32@0x8, u32@0x8, u32@0xc, u32@0x8, u32@0xc, u32@0x10 */
void ts4_if_get_u32_off8_884928D0(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p3 = (ts4_word)t1;
    if ((int)t2 > (int)t1) {
        p3 = (ts4_word)t2;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)p3;
    t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t5 + t4);
    t7 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(t7 + t6);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 20)) + t8);
    return;
}

/* Swing_DLL.xex 0x88493288: if_call_seq fn_88492D88, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88492D88_88493288(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88492D88();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)50);
    }
    return a0;
}

/* Swing_DLL.xex 0x884932F0: get u32@0x8 */
void ts4_get_u32_off8_884932F0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    *(float *)((char *)(ts4_word)(t1) + 20) = (*(float *)((char *)(ts4_word)(a0) + 8));
    *(float *)((char *)(ts4_word)(t1) + 24) = (*(float *)((char *)(ts4_word)(a0) + 8));
    return;
}

/* Swing_DLL.xex 0x88493308: addr lbl_88087714, u16@0x6, u32@0x0 */
void ts4_addr_lbl_88087714_88493308(ts4_word a0)
{
    float t1;
    float t2;

    t1 = *(float *)lbl_8802E87C;
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    t2 = *(float *)lbl_880023AC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087714;
    *(float *)((char *)(ts4_word)(a0) + 8) = t1;
    *(float *)((char *)(ts4_word)(a0) + 12) = t2;
    return;
}

/* Swing_DLL.xex 0x88493650: if_call_seq lbl_88087754, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_88087754_88493650(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087754;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x88493698: if_call_seq lbl_88087764, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_88087764_88493698(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087764;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x88493D40: tailcall ts4_if_call_seq_fn_884936E0_88493D50 */
ts4_word ts4_tailcall_fn_88493D50_88493D40(ts4_word a0)
{
    return ts4_if_call_seq_fn_884936E0_88493D50((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x88493E60: if_call_seq u32@0x0, u32@0x4, u8@0x5, u8@0x5, fn_8854D9B0, fn_884942A8 */
ts4_word ts4_if_call_seq_u32_off0_88493E60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    unsigned char t3;
    unsigned char t4;
    ts4_word t5;
    ts4_word t6;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t3 = *(unsigned char *)((char *)(ts4_word)(t1) + 5);
    t4 = *(unsigned char *)((char *)(ts4_word)(t2) + 5);
    t5 = fn_8854D9B0((ts4_word)(((signed char)t3) + t1), (ts4_word)(((signed char)t4) + t2), (ts4_word)a2, (ts4_word)a3, (ts4_word)t4, (ts4_word)((signed char)t3), (ts4_word)((signed char)t4), (ts4_word)t2);
    p7 = (ts4_word)t5;
    if ((ts4_word)t5 != 0) {
        t6 = fn_884942A8((ts4_word)t5);
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Swing_DLL.xex 0x88493F88: if_get u8@0x0 */
ts4_word ts4_if_get_u8_off0_88493F88(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == 4) {
        return (a0 + 48);
    }
    return (a0 + 32);
}

/* Swing_DLL.xex 0x884943A0: get u32@0x10, u8@0x10, u32@0xb8, u32@0x18, u32@0x8, u32@0x0 */
ts4_word ts4_get_u32_off10_884943A0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t5 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((((signed char)(*(unsigned char *)((char *)(ts4_word)(t1) + 16))) + t1)) + 184))) + 24))) + 8);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 40))))((ts4_word)t5, (ts4_word)a0);
    t9 = fn_884942A8((ts4_word)a0);
    return t9;
}

/* Swing_DLL.xex 0x88494400: call_seq fn_884790C8, lbl_88084CAC, u8@0x8, u32@0x0 */
ts4_word ts4_call_seq_fn_884790C8_88494400(ts4_word a0)
{
    fn_884790C8((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88084CAC;
    return a0;
}

/* Swing_DLL.xex 0x88494448: call_seq fn_884790C8, lbl_88084EBC, u8@0x8, u32@0x0 */
ts4_word ts4_call_seq_fn_884790C8_88494448(ts4_word a0)
{
    fn_884790C8((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88084EBC;
    return a0;
}

/* Swing_DLL.xex 0x88495638: call_seq fn_884980C0, u32@0x0, u32@0x8, u32@0x6c, fn_884944C0 */
ts4_word ts4_call_seq_fn_884980C0_88495638(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;

    t1 = fn_884980C0((ts4_word)a0, (ts4_word)a1, (ts4_word)(a2 + 128), (ts4_word)a3, (ts4_word)a4, (ts4_word)208);
    fn_884944C0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 0))) + 8))) + 108)), (ts4_word)a3, (ts4_word)a4);
    return t1;
}

/* Swing_DLL.xex 0x8849AA60: get u32@0x18, u32@0x1c, u32@0x18 */
void ts4_get_u32_off18_8849AA60(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(t1 + 1);
    return;
}

/* Swing_DLL.xex 0x8849AA78: get u32@0x18, u32@0x1c, u32@0x18 */
void ts4_get_u32_off18_8849AA78(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(t1 + -1);
    return;
}

/* Swing_DLL.xex 0x8849AAC0: if_call_seq lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_lbl_8803A308_8849AAC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)4);
    }
    return a0;
}

/* Swing_DLL.xex 0x8849BA18: call_seq u8@0x25, u8@0x25, ts4_noop_884927F8, u32@0x18, fn_884911B8 */
ts4_word ts4_call_seq_u8_off25_8849BA18(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[3];
    unsigned char t1;
    ts4_word t4;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 37);
    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 37) = (unsigned char)(t1 & 0x3f);
    loc50[2] = (ts4_word)(2147483648);
    ts4_noop_884927F8();
    t4 = fn_884911B8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t4;
}

/* Swing_DLL.xex 0x8849C7F0: set u8@0x0 */
void ts4_set_u8_off0_8849C7F0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8849F020: get u32@0x28, u16@0x2, fn_88478648 */
ts4_word ts4_get_u32_off28_8849F020(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    return fn_88478648((ts4_word)t1, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(t1) + 2)), (ts4_word)a1);
}

/* Swing_DLL.xex 0x8849F030: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_8849F030(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8849F040: fn  */
ts4_word ts4_fn_8849F040(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8849F048: set u8@0x0 */
void ts4_set_u8_off0_8849F048(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x8849F058: fn  */
ts4_word ts4_fn_8849F058(void)
{
    return 11;
}

/* Swing_DLL.xex 0x884A1120: if_addr lbl_88087A40, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88087A40_884A1120(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087A40;
    return;
}

/* Swing_DLL.xex 0x884A1158: addr lbl_88087A40 */
ts4_word ts4_addr_lbl_88087A40_884A1158(void)
{
    return (ts4_word)lbl_88087A40;
}

/* Swing_DLL.xex 0x884A1168: if_call_seq ts4_if_call_seq_u32_off18_885F4B48, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_885F4B48_884A1168(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_if_call_seq_u32_off18_885F4B48((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)41);
    }
    return a0;
}

/* Swing_DLL.xex 0x884A11D0: if_call_seq lbl_88087A7C, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_88087A7C_884A11D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087A7C;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x884A1320: tailcall ts4_if_call_seq_fn_884A4CF8_884A1328 */
ts4_word ts4_tailcall_fn_884A1328_884A1320(ts4_word a0)
{
    return ts4_if_call_seq_fn_884A4CF8_884A1328((ts4_word)(a0 + -20));
}

/* Swing_DLL.xex 0x884A1390: if_addr lbl_88087B44, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88087B44_884A1390(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087B44;
    return;
}

/* Swing_DLL.xex 0x884A13C8: addr lbl_88087B44 */
ts4_word ts4_addr_lbl_88087B44_884A13C8(void)
{
    return (ts4_word)lbl_88087B44;
}

/* Swing_DLL.xex 0x884A14F0: tailcall ts4_if_call_seq_fn_884A5688_884A14F8 */
ts4_word ts4_tailcall_fn_884A14F8_884A14F0(ts4_word a0)
{
    return ts4_if_call_seq_fn_884A5688_884A14F8((ts4_word)(a0 + -20));
}

/* Swing_DLL.xex 0x884A1630: tailcall ts4_if_call_seq_lbl_88080084_8843AF20 */
ts4_word ts4_tailcall_fn_8843AF20_884A1630(ts4_word a0)
{
    return ts4_if_call_seq_lbl_88080084_8843AF20((ts4_word)(a0 + -20));
}

/* Swing_DLL.xex 0x884A1638: if_addr lbl_88087CF8, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88087CF8_884A1638(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087CF8;
    return;
}

/* Swing_DLL.xex 0x884A1670: addr lbl_88087CF8 */
ts4_word ts4_addr_lbl_88087CF8_884A1670(void)
{
    return (ts4_word)lbl_88087CF8;
}

/* Swing_DLL.xex 0x884A1680: if_call_seq ts4_if_call_seq_u32_off18_885F4D78, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_885F4D78_884A1680(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_if_call_seq_u32_off18_885F4D78((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)41);
    }
    return a0;
}

/* Swing_DLL.xex 0x884A1910: tailcall ts4_if_call_seq_fn_884A6E18_884A1938 */
ts4_word ts4_tailcall_fn_884A1938_884A1910(ts4_word a0)
{
    return ts4_if_call_seq_fn_884A6E18_884A1938((ts4_word)(a0 + -12));
}

/* Swing_DLL.xex 0x884A1920: tailcall ts4_if_call_seq_fn_884A6E18_884A1938 */
ts4_word ts4_tailcall_fn_884A1938_884A1920(ts4_word a0)
{
    return ts4_if_call_seq_fn_884A6E18_884A1938((ts4_word)(a0 + -48));
}

/* Swing_DLL.xex 0x884A1928: tailcall ts4_if_call_seq_fn_884A6E18_884A1938 */
ts4_word ts4_tailcall_fn_884A1938_884A1928(ts4_word a0)
{
    return ts4_if_call_seq_fn_884A6E18_884A1938((ts4_word)(a0 + -20));
}

/* Swing_DLL.xex 0x884A1930: tailcall ts4_if_call_seq_fn_884A6E18_884A1938 */
ts4_word ts4_tailcall_fn_884A1938_884A1930(ts4_word a0)
{
    return ts4_if_call_seq_fn_884A6E18_884A1938((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884A19B8: if_addr lbl_88087EDC, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88087EDC_884A19B8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087EDC;
    return;
}

/* Swing_DLL.xex 0x884A19D8: addr lbl_88087EDC */
ts4_word ts4_addr_lbl_88087EDC_884A19D8(void)
{
    return (ts4_word)lbl_88087EDC;
}

/* Swing_DLL.xex 0x884A19E8: if_call_seq fn_884A4088, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884A4088_884A19E8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884A4088();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)13);
    }
    return a0;
}

/* Swing_DLL.xex 0x884A1A68: if_addr lbl_88087F04, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88087F04_884A1A68(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087F04;
    return;
}

/* Swing_DLL.xex 0x884A1A88: addr lbl_88087F04 */
ts4_word ts4_addr_lbl_88087F04_884A1A88(void)
{
    return (ts4_word)lbl_88087F04;
}

/* Swing_DLL.xex 0x884A1A98: if_call_seq fn_884A7430, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884A7430_884A1A98(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884A7430();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)47);
    }
    return a0;
}

/* Swing_DLL.xex 0x884A1B28: if_addr lbl_88087FDC, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88087FDC_884A1B28(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087FDC;
    return;
}

/* Swing_DLL.xex 0x884A1B48: addr lbl_88087FDC */
ts4_word ts4_addr_lbl_88087FDC_884A1B48(void)
{
    return (ts4_word)lbl_88087FDC;
}

/* Swing_DLL.xex 0x884A1B58: if_call_seq fn_884A83D8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884A83D8_884A1B58(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884A83D8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)44);
    }
    return a0;
}

/* Swing_DLL.xex 0x884A1BC0: if_addr lbl_8808804C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8808804C_884A1BC0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808804C;
    return;
}

/* Swing_DLL.xex 0x884A1BF8: addr lbl_8808804C */
ts4_word ts4_addr_lbl_8808804C_884A1BF8(void)
{
    return (ts4_word)lbl_8808804C;
}

/* Swing_DLL.xex 0x884A1C20: tailcall fn_884A1CA8 */
ts4_word ts4_tailcall_fn_884A1CA8_884A1C20(ts4_word a0)
{
    return fn_884A1CA8((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x884A1C28: tailcall fn_884A1CA8 */
ts4_word ts4_tailcall_fn_884A1CA8_884A1C28(ts4_word a0)
{
    return fn_884A1CA8((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x884A1D48: if_call_seq fn_884A8C80, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884A8C80_884A1D48(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884A8C80();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)13);
    }
    return a0;
}

/* Swing_DLL.xex 0x884A1DC8: if_addr lbl_88088158, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88088158_884A1DC8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88088158;
    return;
}

/* Swing_DLL.xex 0x884A1DE8: addr lbl_88088158 */
ts4_word ts4_addr_lbl_88088158_884A1DE8(void)
{
    return (ts4_word)lbl_88088158;
}

/* Swing_DLL.xex 0x884A1DF8: if_call_seq lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_lbl_8803A308_884A1DF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)5);
    }
    return a0;
}

/* Swing_DLL.xex 0x884A1E70: if_addr lbl_88088180, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88088180_884A1E70(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88088180;
    return;
}

/* Swing_DLL.xex 0x884A1E90: addr lbl_88088180 */
ts4_word ts4_addr_lbl_88088180_884A1E90(void)
{
    return (ts4_word)lbl_88088180;
}

/* Swing_DLL.xex 0x884A1F68: if_call_seq fn_884A1EA0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884A1EA0_884A1F68(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884A1EA0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)13);
    }
    return a0;
}

/* Swing_DLL.xex 0x884A1FF0: if_addr lbl_880881D8, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_880881D8_884A1FF0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880881D8;
    return;
}

/* Swing_DLL.xex 0x884A2010: addr lbl_880881D8 */
ts4_word ts4_addr_lbl_880881D8_884A2010(void)
{
    return (ts4_word)lbl_880881D8;
}

/* Swing_DLL.xex 0x884A2020: if_call_seq fn_884A8D60, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884A8D60_884A2020(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884A8D60();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)13);
    }
    return a0;
}

/* Swing_DLL.xex 0x884A2088: if_addr lbl_880882AC, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_880882AC_884A2088(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880882AC;
    return;
}

/* Swing_DLL.xex 0x884A20C0: addr lbl_880882AC */
ts4_word ts4_addr_lbl_880882AC_884A20C0(void)
{
    return (ts4_word)lbl_880882AC;
}

/* Swing_DLL.xex 0x884A20F0: tailcall fn_884A2100 */
ts4_word ts4_tailcall_fn_884A2100_884A20F0(ts4_word a0)
{
    return fn_884A2100((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x884A20F8: tailcall fn_884A21A8 */
ts4_word ts4_tailcall_fn_884A21A8_884A20F8(ts4_word a0)
{
    return fn_884A21A8((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x884A2278: if_call_seq lbl_8808859C, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_8808859C_884A2278(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808859C;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x884A2328: if_call_seq lbl_880885AC, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880885AC_884A2328(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880885AC;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x884A2370: call_seq ts4_call_seq_fn_884B30A8_884B34E0, ts4_call_seq_fn_884B2580_884B2DC8, ts4_call_seq_fn_884B2238_884B2298, ts4_call_seq_fn_884B17D8_884B1838, ts4_call_seq_fn_884B09F8_884B0A58, ts4_call_seq_fn_884B0288_884B02E8 */
ts4_word ts4_call_seq_fn_884B34E0_884A2370(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    ts4_word t14;
    ts4_word t15;
    ts4_word t16;
    ts4_word t17;

    t1 = ts4_call_seq_fn_884B30A8_884B34E0();
    t2 = ts4_call_seq_fn_884B2580_884B2DC8((ts4_word)t1);
    t3 = ts4_call_seq_fn_884B2238_884B2298((ts4_word)t2);
    t4 = ts4_call_seq_fn_884B17D8_884B1838((ts4_word)t3);
    t5 = ts4_call_seq_fn_884B09F8_884B0A58((ts4_word)t4);
    t6 = ts4_call_seq_fn_884B0288_884B02E8((ts4_word)t5);
    t7 = ts4_call_seq_fn_884B0160_884B01C0((ts4_word)t6);
    t8 = ts4_call_seq_fn_884AFF80_884B0030((ts4_word)t7);
    t9 = ts4_call_seq_fn_884AF270_884AF2D0((ts4_word)t8);
    t10 = ts4_call_seq_fn_884AE808_884AE868((ts4_word)t9);
    t11 = ts4_call_seq_fn_884AE1F8_884AE258((ts4_word)t10);
    t12 = ts4_call_seq_fn_884ACBC8_884ACC28((ts4_word)t11);
    t13 = ts4_call_seq_fn_884ABB50_884ABBB0((ts4_word)t12);
    t14 = ts4_call_seq_fn_884AB258_884AB2B8((ts4_word)t13);
    t15 = ts4_call_seq_fn_884AA708_884AA768((ts4_word)t14);
    t16 = ts4_call_seq_fn_884A9950_884A9B78((ts4_word)t15);
    t17 = ts4_call_seq_fn_884A92F8_884A94E0((ts4_word)t16);
    return t17;
}

/* Swing_DLL.xex 0x884A2C88: tailcall fn_884A2AA0 */
ts4_word ts4_tailcall_fn_884A2AA0_884A2C88(ts4_word a0)
{
    return fn_884A2AA0((ts4_word)(a0 + -88));
}

/* Swing_DLL.xex 0x884A3060: if_call_seq fn_884A2FE8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_fn_884A2FE8_884A3060(ts4_word a0, ts4_word a1)
{
    fn_884A2FE8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x884A30B0: addr lbl_88088658 */
ts4_word ts4_addr_lbl_88088658_884A30B0(void)
{
    return (ts4_word)lbl_88088658;
}

/* Swing_DLL.xex 0x884A30C0: tailcall ts4_if_call_seq_fn_884A2E50_884A30F0 */
ts4_word ts4_tailcall_fn_884A30F0_884A30C0(ts4_word a0)
{
    return ts4_if_call_seq_fn_884A2E50_884A30F0((ts4_word)(a0 + -88));
}

/* Swing_DLL.xex 0x884A30C8: tailcall ts4_if_call_seq_fn_884A2E50_884A30F0 */
ts4_word ts4_tailcall_fn_884A30F0_884A30C8(ts4_word a0)
{
    return ts4_if_call_seq_fn_884A2E50_884A30F0((ts4_word)(a0 + -92));
}

/* Swing_DLL.xex 0x884A30D0: tailcall ts4_if_call_seq_fn_884A2E50_884A30F0 */
ts4_word ts4_tailcall_fn_884A30F0_884A30D0(ts4_word a0)
{
    return ts4_if_call_seq_fn_884A2E50_884A30F0((ts4_word)(a0 + -96));
}

/* Swing_DLL.xex 0x884A30D8: tailcall ts4_if_call_seq_fn_884A2E50_884A30F0 */
ts4_word ts4_tailcall_fn_884A30F0_884A30D8(ts4_word a0)
{
    return ts4_if_call_seq_fn_884A2E50_884A30F0((ts4_word)(a0 + -100));
}

/* Swing_DLL.xex 0x884A30E0: tailcall ts4_if_call_seq_fn_884A2E50_884A30F0 */
ts4_word ts4_tailcall_fn_884A30F0_884A30E0(ts4_word a0)
{
    return ts4_if_call_seq_fn_884A2E50_884A30F0((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884A30E8: tailcall ts4_if_call_seq_fn_884A2E50_884A30F0 */
ts4_word ts4_tailcall_fn_884A30F0_884A30E8(ts4_word a0)
{
    return ts4_if_call_seq_fn_884A2E50_884A30F0((ts4_word)(a0 + -104));
}

/* Swing_DLL.xex 0x884A5480: set u8@0x0 */
void ts4_set_u8_off0_884A5480(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x884A5490: set u8@0x0 */
void ts4_set_u8_off0_884A5490(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x884A54A0: set u8@0x0 */
void ts4_set_u8_off0_884A54A0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x884A54B0: set u8@0x0 */
void ts4_set_u8_off0_884A54B0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x884A63B0: set  */
void ts4_set_884A63B0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 72) = f1;
    return;
}

/* Swing_DLL.xex 0x884A63B8: call_seq ts4_if_get_u32_off8_885F4C70, u32@0x18 */
ts4_word ts4_call_seq_fn_885F4C70_884A63B8(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_if_get_u32_off8_885F4C70((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x884A6C00: set u8@0x0 */
void ts4_set_u8_off0_884A6C00(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x884A6C10: set u8@0x0 */
void ts4_set_u8_off0_884A6C10(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x884A6C20: set u8@0x0 */
void ts4_set_u8_off0_884A6C20(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x884A6C30: set u8@0x0 */
void ts4_set_u8_off0_884A6C30(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x884A6D78: get u32@0x38 */
ts4_word ts4_get_u32_off38_884A6D78(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 56));
}

/* Swing_DLL.xex 0x884A7308: fn  */
ts4_word ts4_fn_884A7308(void)
{
    return 0;
}

/* Swing_DLL.xex 0x884A9290: call_seq fn_884B70D0, u8@0x28, lbl_8808880C, lbl_880887EC, lbl_880887DC, u32@0x0 */
ts4_word ts4_call_seq_fn_884B70D0_884A9290(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    fn_884B70D0();
    *(unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808880C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_880887EC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_880887DC;
    return a0;
}

/* Swing_DLL.xex 0x884A92F8: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_884B70D0, lbl_8808880C */
ts4_word ts4_call_seq_u32_lbl_88CACF08_884A92F8(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)44, (ts4_word)53);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)44;
    fn_884B70D0((ts4_word)t3, (ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_8808880C;
    *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)(ts4_word)lbl_880887EC;
    *(ts4_word *)((char *)(ts4_word)(t3) + 32) = (ts4_word)(ts4_word)lbl_880887DC;
    *(unsigned char *)((char *)(ts4_word)(t3) + 40) = (unsigned char)0;
    return (t3 + 8);
}

/* Swing_DLL.xex 0x884A9388: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_884B70D0, lbl_8808880C */
ts4_word ts4_call_seq_u32_lbl_88CACF08_884A9388(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)44, (ts4_word)53);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)44;
    fn_884B70D0((ts4_word)t3, (ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_8808880C;
    *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)(ts4_word)lbl_880887EC;
    *(ts4_word *)((char *)(ts4_word)(t3) + 32) = (ts4_word)(ts4_word)lbl_880887DC;
    *(unsigned char *)((char *)(ts4_word)(t3) + 40) = (unsigned char)1;
    return (t3 + 8);
}

/* Swing_DLL.xex 0x884A97E0: set u32@0x0, u32@0x0 */
void ts4_set_u32_off0_884A97E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x884A97F0: if_get u8@0x20, u32@lbl_88D25FA4, u32@lbl_88D25FA8 */
ts4_word ts4_if_get_u8_off20_884A97F0(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)lbl_88D25FA4);
    }
    return (*(ts4_word *)lbl_88D25FA8);
}

/* Swing_DLL.xex 0x884A9818: tailcall fn_884A9828 */
ts4_word ts4_tailcall_fn_884A9828_884A9818(ts4_word a0)
{
    return fn_884A9828((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884A98E8: call_seq fn_884B70D0, lbl_8808885C, lbl_8808883C, lbl_8808882C, u32@0x0, u32@0x8 */
ts4_word ts4_call_seq_fn_884B70D0_884A98E8(ts4_word a0)
{
    fn_884B70D0();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808885C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_8808883C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_8808882C;
    fn_885EBB08((ts4_word)(a0 + 40), (ts4_word)((458752) | 41248));
    return a0;
}

/* Swing_DLL.xex 0x884A9BB8: get u32@lbl_88D25FAC */
ts4_word ts4_get_u32_lbl_88D25FAC_884A9BB8(void)
{
    return (*(ts4_word *)lbl_88D25FAC);
}

/* Swing_DLL.xex 0x884A9BC8: tailcall ts4_if_call_seq_fn_884A9A20_884A9BD8 */
ts4_word ts4_tailcall_fn_884A9BD8_884A9BC8(ts4_word a0)
{
    return ts4_if_call_seq_fn_884A9A20_884A9BD8((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884A9BD0: tailcall ts4_if_call_seq_fn_884A9A20_884A9BD8 */
ts4_word ts4_tailcall_fn_884A9BD8_884A9BD0(ts4_word a0)
{
    return ts4_if_call_seq_fn_884A9A20_884A9BD8((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884A9C40: if_call_seq lbl_88088878, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_88088878_884A9C40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88088878;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x884A9CD8: addr lbl_880444EC */
ts4_word ts4_addr_lbl_880444EC_884A9CD8(void)
{
    return (ts4_word)lbl_880444EC;
}

/* Swing_DLL.xex 0x884AA7A8: get u32@lbl_88D25FB0 */
ts4_word ts4_get_u32_lbl_88D25FB0_884AA7A8(void)
{
    return (*(ts4_word *)lbl_88D25FB0);
}

/* Swing_DLL.xex 0x884AA7C0: tailcall ts4_if_call_seq_fn_884AA078_884AA7D8 */
ts4_word ts4_tailcall_fn_884AA7D8_884AA7C0(ts4_word a0)
{
    return ts4_if_call_seq_fn_884AA078_884AA7D8((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884AB5A8: tailcall fn_884AB2F8 */
ts4_word ts4_tailcall_fn_884AB2F8_884AB5A8(ts4_word a0)
{
    return fn_884AB2F8((ts4_word)(a0 + -32));
}
