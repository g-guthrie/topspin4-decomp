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

extern char ts4_addr_lbl_8803A308_88AFF728[];
extern char ts4_addr_lbl_8803A308_88AFF740[];
extern char ts4_addr_lbl_8803A308_88AFF758[];
extern char ts4_addr_lbl_8803A308_88AFF7A0[];
extern char ts4_get_u32_lbl_88D3CB08_88AFF7E0[];
extern char ts4_addr_lbl_88D3CB10_88AFF7F0[];
extern char lbl_88076D10[];
extern char lbl_880790C0[];
extern char lbl_88079D38[];
extern char lbl_8807C4B0[];
extern char lbl_8807CF40[];
extern char lbl_8807F728[];
extern char lbl_8808B910[];
extern char lbl_8808C384[];
extern char lbl_880CE328[];
extern char lbl_88C00AD4[];
extern char lbl_88C00B94[];
extern char lbl_88C01630[];
extern char lbl_88C01664[];
extern char lbl_88C01AD8[];
extern char lbl_88C02374[];
extern char lbl_88C06218[];
extern char lbl_88C062F0[];
extern char lbl_88C06368[];
extern char lbl_88C06380[];
extern char lbl_88C063F8[];
extern char lbl_88C06968[];
extern char lbl_88C06B30[];
extern char lbl_88C06B94[];
extern char lbl_88C071BC[];
extern char lbl_88C07618[];
extern char lbl_88C07C10[];
extern char lbl_88C07F30[];
extern char lbl_88C07F34[];
extern char lbl_88C07FE4[];
extern char lbl_88C08960[];
extern char lbl_88C08964[];
extern char lbl_88C08EF0[];
extern char lbl_88C08F0C[];
extern char lbl_88C08F5C[];
extern char lbl_88C093B0[];
extern char lbl_88C09544[];
extern char lbl_88C0954C[];
extern char lbl_88C0A5A0[];
extern char lbl_88C0A5A4[];
extern char lbl_88C0A770[];
extern char lbl_88C0ADC0[];
extern char lbl_88C0ADF8[];
extern char lbl_88C0ADFC[];
extern char lbl_88C0B0F8[];
extern char lbl_88C0B234[];
extern char lbl_88C0B434[];
extern char lbl_88C0B540[];
extern char lbl_88C0C190[];
extern char lbl_88C0C258[];
extern char lbl_88C0C8E8[];
extern char lbl_88C0CD10[];
extern char lbl_88C0CD1C[];
extern char lbl_88C0CD6C[];
extern char lbl_88C0D598[];
extern char lbl_88C0D618[];
extern char lbl_88C0D7F8[];
extern char lbl_88C0DEEC[];
extern char lbl_88C0E1A8[];
extern char lbl_88C0E574[];
extern char lbl_88C0F6E0[];
extern char lbl_88C106D8[];
extern char lbl_88C10738[];
extern char lbl_88C10918[];
extern char lbl_88C109F0[];
extern char lbl_88C10B28[];
extern char lbl_88C10BB8[];
extern char lbl_88C10C78[];
extern char lbl_88C10E10[];
extern char lbl_88C10F78[];
extern char lbl_88C11080[];
extern char lbl_88C11188[];
extern char lbl_88C11260[];
extern char lbl_88C112F0[];
extern char lbl_88C113F8[];
extern char lbl_88C116F8[];
extern char lbl_88C11830[];
extern char lbl_88C11F98[];
extern char lbl_88C12058[];
extern char lbl_88C12100[];
extern char lbl_88C12568[];
extern char lbl_88C12640[];
extern char lbl_88C12730[];
extern char lbl_88C12868[];
extern char lbl_88C12898[];
extern char lbl_88C128C8[];
extern char lbl_88C128F8[];
extern char lbl_88C12970[];
extern char lbl_88C129B8[];
extern char lbl_88C12A30[];
extern char lbl_88C12B20[];
extern char lbl_88C12C10[];
extern char lbl_88C12D18[];
extern char lbl_88C12D90[];
extern char lbl_88C12E38[];
extern char lbl_88C12FA0[];
extern char lbl_88C13048[];
extern char lbl_88C13060[];
extern char lbl_88C13120[];
extern char lbl_88C13168[];
extern char lbl_88C13240[];
extern char lbl_88C132B8[];
extern char lbl_88C132D0[];
extern char lbl_88C13348[];
extern char lbl_88C13900[];
extern char lbl_88C13AC8[];
extern char lbl_88C13B2C[];
extern char lbl_88C14184[];
extern char lbl_88C145E0[];
extern char lbl_88C14BD8[];
extern char lbl_88C14EF8[];
extern char lbl_88C14EFC[];
extern char lbl_88C14FAC[];
extern char lbl_88C15958[];
extern char lbl_88C1595C[];
extern char lbl_88C15EE8[];
extern char lbl_88C15F04[];
extern char lbl_88C15F54[];
extern char lbl_88C163A8[];
extern char lbl_88C1653C[];
extern char lbl_88C16544[];
extern char lbl_88C17598[];
extern char lbl_88C1759C[];
extern char lbl_88C17768[];
extern char lbl_88C17DB8[];
extern char lbl_88C17DF0[];
extern char lbl_88C17DF4[];
extern char lbl_88C180F0[];
extern char lbl_88C1822C[];
extern char lbl_88C1842C[];
extern char lbl_88C18538[];
extern char lbl_88C19188[];
extern char lbl_88C19250[];
extern char lbl_88C198E0[];
extern char lbl_88C19D38[];
extern char lbl_88C19D44[];
extern char lbl_88C19D94[];
extern char lbl_88C1A5C0[];
extern char lbl_88C1A640[];
extern char lbl_88C1A820[];
extern char lbl_88C1AF14[];
extern char lbl_88C1B1D0[];
extern char lbl_88C1B59C[];
extern char lbl_88C1C018[];
extern char lbl_88C1C034[];
extern char lbl_88C1D6B8[];
extern char lbl_88C1D718[];
extern char lbl_88C1D8C8[];
extern char lbl_88C1D9A0[];
extern char lbl_88C1DAD8[];
extern char lbl_88C1DB68[];
extern char lbl_88C1DC28[];
extern char lbl_88C1DDC0[];
extern char lbl_88C1DF28[];
extern char lbl_88C1E030[];
extern char lbl_88C1E138[];
extern char lbl_88C1E210[];
extern char lbl_88C1E2A0[];
extern char lbl_88C1E3A8[];
extern char lbl_88C1E6A8[];
extern char lbl_88C1E7E0[];
extern char lbl_88C1EF48[];
extern char lbl_88C1F008[];
extern char lbl_88C1F0B0[];
extern char lbl_88C1F518[];
extern char lbl_88C1F5F0[];
extern char lbl_88C1F6E0[];
extern char lbl_88C1F818[];
extern char lbl_88C1F848[];
extern char lbl_88C1F878[];
extern char lbl_88C1F8A8[];
extern char lbl_88C1F920[];
extern char lbl_88C1F968[];
extern char lbl_88C1F9E0[];
extern char lbl_88C1FAD0[];
extern char lbl_88C1FBC0[];
extern char lbl_88C1FCC8[];
extern char lbl_88C1FD40[];
extern char lbl_88C1FDE8[];
extern char lbl_88C1FF50[];
extern char lbl_88C1FFF8[];
extern char lbl_88C20010[];
extern char lbl_88C200D0[];
extern char lbl_88C20118[];
extern char lbl_88C201F0[];
extern char lbl_88C20268[];
extern char lbl_88C20280[];
extern char lbl_88C202F8[];
extern char lbl_88C208B0[];
extern char lbl_88C208F8[];
extern char lbl_88C20E50[];
extern char lbl_88C20F38[];
extern char lbl_88C21028[];
extern char lbl_88C211A0[];
extern char lbl_88C211B8[];
extern char lbl_88C21320[];
extern char lbl_88C215D0[];
extern char lbl_88C217E0[];
extern char lbl_88C218EC[];
extern char lbl_88C21908[];
extern char lbl_88C21910[];
extern char lbl_88C22A38[];
extern char lbl_88C22A50[];
extern char lbl_88C22C38[];
extern char lbl_88C22C58[];
extern char lbl_88C22FF8[];
extern char lbl_88C23000[];
extern char lbl_88C23324[];
extern char lbl_88C23338[];
extern char lbl_88C23AB0[];
extern char lbl_88C23AC8[];
extern char lbl_88C23B30[];
extern char lbl_88C23B38[];
extern char lbl_88C23D1C[];
extern char lbl_88C23D38[];
extern char lbl_88C23E0C[];
extern char lbl_88C23E10[];
extern char lbl_88C23E28[];
extern char lbl_88C23E30[];
extern char lbl_88C249F0[];
extern char lbl_88C24A18[];
extern char lbl_88C24FD4[];
extern char lbl_88C25378[];
extern char lbl_88C25414[];
extern char lbl_88C259B0[];
extern char lbl_88C259F0[];
extern char lbl_88C25A40[];
extern char lbl_88C25A70[];
extern char lbl_88C25AE8[];
extern char lbl_88C25B00[];
extern char lbl_88C25B78[];
extern char lbl_88C25B90[];
extern char lbl_88C25C30[];
extern char lbl_88C25C48[];
extern char lbl_88C25F08[];
extern char lbl_88C26228[];
extern char lbl_88C2625C[];
extern char lbl_88C26690[];
extern char lbl_88C267B0[];
extern char lbl_88C30978[];
extern char lbl_88C309B0[];
extern char lbl_88C4533C[];
extern char lbl_88C45418[];
extern char lbl_88C4547C[];
extern char lbl_88C4584C[];
extern char lbl_88CAD560[];
extern char lbl_88D17C2C[];
extern char lbl_88D1D704[];
extern char lbl_88D2320C[];
extern char lbl_88D25FB8[];
extern char lbl_88D25FBC[];
extern char lbl_88D25FC8[];
extern char lbl_88D25FCC[];
extern char lbl_88D25FD8[];
extern char lbl_88D25FF4[];
extern char lbl_88D25FF8[];
extern char lbl_88D26F88[];
extern char lbl_88D3C95C[];
extern char lbl_88D3C988[];
extern char lbl_88D3CB08[];
extern char lbl_88D3CB10[];
ts4_word KeTlsAlloc();
ts4_word RtlInitializeCriticalSectionAndSpinCount();
ts4_word ts4_set_u32_offc_884CE988();
ts4_word ts4_set_u32_offc_884CE9B8();
ts4_word ts4_pack_bytes_dabc_884E1EE8();
ts4_word fn_88563470();
ts4_word ts4_set_u32_off0_885DD498();

/* Swing_DLL.xex 0x88AD4178: addr lbl_88C06218, u32@lbl_88C00AD4, u32@0x68 */
void ts4_addr_lbl_88C06218_88AD4178(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C06218) + 104) = (ts4_word)(*(ts4_word *)lbl_88C00AD4);
    return;
}

/* Swing_DLL.xex 0x88AD45A0: addr lbl_88C062F0, u32@lbl_88C00B94, u32@0x50 */
void ts4_addr_lbl_88C062F0_88AD45A0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C062F0) + 80) = (ts4_word)(*(ts4_word *)lbl_88C00B94);
    return;
}

/* Swing_DLL.xex 0x88AD53C0: addr lbl_88C06368, u32@lbl_88C01630, u32@0x8 */
void ts4_addr_lbl_88C06368_88AD53C0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C06368) + 8) = (ts4_word)(*(ts4_word *)lbl_88C01630);
    return;
}

/* Swing_DLL.xex 0x88AD54C0: addr lbl_88C06380, u32@lbl_88C01664, u32@0x20 */
void ts4_addr_lbl_88C06380_88AD54C0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C06380) + 32) = (ts4_word)(*(ts4_word *)lbl_88C01664);
    return;
}

/* Swing_DLL.xex 0x88AD5BF0: addr lbl_88C063F8, u32@lbl_88C01AD8, u32@0x8 */
void ts4_addr_lbl_88C063F8_88AD5BF0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C063F8) + 8) = (ts4_word)(*(ts4_word *)lbl_88C01AD8);
    return;
}

/* Swing_DLL.xex 0x88AD7190: addr lbl_88C06968, u32@lbl_88C02374, u32@0x80 */
void ts4_addr_lbl_88C06968_88AD7190(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C06968) + 128) = (ts4_word)(*(ts4_word *)lbl_88C02374);
    return;
}

/* Swing_DLL.xex 0x88AD8558: call_seq lbl_88076D10, lbl_880790C0, lbl_88D17C2C, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF728, fn_88563470 */
ts4_word ts4_call_seq_lbl_88076D10_88AD8558(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88D17C2C, (ts4_word)(ts4_word)lbl_880790C0, (ts4_word)5, (ts4_word)(ts4_word)lbl_88076D10);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF728);
    return t2;
}

/* Swing_DLL.xex 0x88AD8610: addr lbl_88C106D8, u32@lbl_88C06B30, u32@0x50 */
void ts4_addr_lbl_88C106D8_88AD8610(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C106D8) + 80) = (ts4_word)(*(ts4_word *)lbl_88C06B30);
    return;
}

/* Swing_DLL.xex 0x88AD8778: addr lbl_88C10738, u32@lbl_88C06B94, u32@0x8 */
void ts4_addr_lbl_88C10738_88AD8778(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C10738) + 8) = (ts4_word)(*(ts4_word *)lbl_88C06B94);
    return;
}

/* Swing_DLL.xex 0x88AD91F8: addr lbl_88C10918, u32@lbl_88C071BC, u32@0xc8 */
void ts4_addr_lbl_88C10918_88AD91F8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C10918) + 200) = (ts4_word)(*(ts4_word *)lbl_88C071BC);
    return;
}

/* Swing_DLL.xex 0x88AD9288: addr lbl_88C109F0, u32@lbl_88C07618, u32@0x8 */
void ts4_addr_lbl_88C109F0_88AD9288(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C109F0) + 8) = (ts4_word)(*(ts4_word *)lbl_88C07618);
    return;
}

/* Swing_DLL.xex 0x88AD9820: addr lbl_88C10B28, u32@lbl_88C07C10, u32@0x80 */
void ts4_addr_lbl_88C10B28_88AD9820(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C10B28) + 128) = (ts4_word)(*(ts4_word *)lbl_88C07C10);
    return;
}

/* Swing_DLL.xex 0x88AD9CA0: addr lbl_88C10BB8, u32@lbl_88C07F30, u32@0x68 */
void ts4_addr_lbl_88C10BB8_88AD9CA0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C10BB8) + 104) = (ts4_word)(*(ts4_word *)lbl_88C07F30);
    return;
}

/* Swing_DLL.xex 0x88AD9DA0: addr lbl_88C10C78, u32@lbl_88C07F34, u32@0x8 */
void ts4_addr_lbl_88C10C78_88AD9DA0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C10C78) + 8) = (ts4_word)(*(ts4_word *)lbl_88C07F34);
    return;
}

/* Swing_DLL.xex 0x88AD9EA8: addr lbl_88C10E10, u32@lbl_88C07FE4, u32@0xe0 */
void ts4_addr_lbl_88C10E10_88AD9EA8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C10E10) + 224) = (ts4_word)(*(ts4_word *)lbl_88C07FE4);
    return;
}

/* Swing_DLL.xex 0x88ADA780: addr lbl_88C10F78, u32@lbl_88C08960, u32@0xc8 */
void ts4_addr_lbl_88C10F78_88ADA780(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C10F78) + 200) = (ts4_word)(*(ts4_word *)lbl_88C08960);
    return;
}

/* Swing_DLL.xex 0x88ADAB58: addr lbl_88C11080, u32@lbl_88C08964, u32@0x50 */
void ts4_addr_lbl_88C11080_88ADAB58(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C11080) + 80) = (ts4_word)(*(ts4_word *)lbl_88C08964);
    return;
}

/* Swing_DLL.xex 0x88ADAEB8: addr lbl_88C11188, u32@lbl_88C08EF0, u32@0x38 */
void ts4_addr_lbl_88C11188_88ADAEB8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C11188) + 56) = (ts4_word)(*(ts4_word *)lbl_88C08EF0);
    return;
}

/* Swing_DLL.xex 0x88ADAFC0: addr lbl_88C11260, u32@lbl_88C08F0C, u32@0x8 */
void ts4_addr_lbl_88C11260_88ADAFC0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C11260) + 8) = (ts4_word)(*(ts4_word *)lbl_88C08F0C);
    return;
}

/* Swing_DLL.xex 0x88ADB800: addr lbl_88C112F0, u32@lbl_88C093B0, u32@0xe0 */
void ts4_addr_lbl_88C112F0_88ADB800(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C112F0) + 224) = (ts4_word)(*(ts4_word *)lbl_88C093B0);
    return;
}

/* Swing_DLL.xex 0x88ADB9D8: addr lbl_88C113F8, u32@lbl_88C08F5C, u32@0xe0 */
void ts4_addr_lbl_88C113F8_88ADB9D8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C113F8) + 224) = (ts4_word)(*(ts4_word *)lbl_88C08F5C);
    return;
}

/* Swing_DLL.xex 0x88ADBB00: addr lbl_88C116F8, u32@lbl_88C09544, u32@0x50 */
void ts4_addr_lbl_88C116F8_88ADBB00(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C116F8) + 80) = (ts4_word)(*(ts4_word *)lbl_88C09544);
    return;
}

/* Swing_DLL.xex 0x88ADBCF8: addr lbl_88C11830, u32@lbl_88C0954C, u32@0x20 */
void ts4_addr_lbl_88C11830_88ADBCF8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C11830) + 32) = (ts4_word)(*(ts4_word *)lbl_88C0954C);
    return;
}

/* Swing_DLL.xex 0x88ADCAA0: addr lbl_88C11F98, u32@lbl_88C0A5A0, u32@0x80, u32@0x98 */
void ts4_addr_lbl_88C11F98_88ADCAA0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88C0A5A0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C11F98) + 128) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C11F98) + 152) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88ADCBB0: addr lbl_88C12058, u32@lbl_88C0A5A4, u32@0x50 */
void ts4_addr_lbl_88C12058_88ADCBB0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C12058) + 80) = (ts4_word)(*(ts4_word *)lbl_88C0A5A4);
    return;
}

/* Swing_DLL.xex 0x88ADCD30: addr lbl_88C12100, u32@lbl_88C0A770, u32@0x38 */
void ts4_addr_lbl_88C12100_88ADCD30(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C12100) + 56) = (ts4_word)(*(ts4_word *)lbl_88C0A770);
    return;
}

/* Swing_DLL.xex 0x88ADD4B0: addr lbl_88C12568, u32@lbl_88C0ADC0, u32@0x50 */
void ts4_addr_lbl_88C12568_88ADD4B0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C12568) + 80) = (ts4_word)(*(ts4_word *)lbl_88C0ADC0);
    return;
}

/* Swing_DLL.xex 0x88ADD610: addr lbl_88C12640, u32@lbl_88C0ADF8, u32@0xc8 */
void ts4_addr_lbl_88C12640_88ADD610(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C12640) + 200) = (ts4_word)(*(ts4_word *)lbl_88C0ADF8);
    return;
}

/* Swing_DLL.xex 0x88ADD708: addr lbl_88C12730, u32@lbl_88C0ADFC, u32@0x50 */
void ts4_addr_lbl_88C12730_88ADD708(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C12730) + 80) = (ts4_word)(*(ts4_word *)lbl_88C0ADFC);
    return;
}

/* Swing_DLL.xex 0x88ADDBA8: addr lbl_88C12868, u32@lbl_88C0B0F8, u32@0x20 */
void ts4_addr_lbl_88C12868_88ADDBA8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C12868) + 32) = (ts4_word)(*(ts4_word *)lbl_88C0B0F8);
    return;
}

/* Swing_DLL.xex 0x88ADDC30: addr lbl_88C12898, u32@lbl_88C0B0F8, u32@0x20 */
void ts4_addr_lbl_88C12898_88ADDC30(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C12898) + 32) = (ts4_word)(*(ts4_word *)lbl_88C0B0F8);
    return;
}

/* Swing_DLL.xex 0x88ADDD28: addr lbl_88C128C8, u32@lbl_88C0B0F8, u32@0x20 */
void ts4_addr_lbl_88C128C8_88ADDD28(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C128C8) + 32) = (ts4_word)(*(ts4_word *)lbl_88C0B0F8);
    return;
}

/* Swing_DLL.xex 0x88ADE370: addr lbl_88C128F8, u32@lbl_88C0B234, u32@0x8 */
void ts4_addr_lbl_88C128F8_88ADE370(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C128F8) + 8) = (ts4_word)(*(ts4_word *)lbl_88C0B234);
    return;
}

/* Swing_DLL.xex 0x88ADE4E0: addr lbl_88C12970, u32@lbl_88C0B434, u32@0x20 */
void ts4_addr_lbl_88C12970_88ADE4E0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C12970) + 32) = (ts4_word)(*(ts4_word *)lbl_88C0B434);
    return;
}

/* Swing_DLL.xex 0x88ADE648: addr lbl_88C129B8, u32@lbl_88C0B540, u32@0x8 */
void ts4_addr_lbl_88C129B8_88ADE648(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C129B8) + 8) = (ts4_word)(*(ts4_word *)lbl_88C0B540);
    return;
}

/* Swing_DLL.xex 0x88ADF328: addr lbl_88C12A30, u32@lbl_88C0C190, u32@0x20 */
void ts4_addr_lbl_88C12A30_88ADF328(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C12A30) + 32) = (ts4_word)(*(ts4_word *)lbl_88C0C190);
    return;
}

/* Swing_DLL.xex 0x88ADF900: addr lbl_88C12B20, u32@lbl_88C0C258, u32@0xb0 */
void ts4_addr_lbl_88C12B20_88ADF900(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C12B20) + 176) = (ts4_word)(*(ts4_word *)lbl_88C0C258);
    return;
}

/* Swing_DLL.xex 0x88ADFA08: addr lbl_88C12C10, u32@lbl_88C0CD10, u32@0xb0 */
void ts4_addr_lbl_88C12C10_88ADFA08(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C12C10) + 176) = (ts4_word)(*(ts4_word *)lbl_88C0CD10);
    return;
}

/* Swing_DLL.xex 0x88ADFC60: addr lbl_88C12D18, u32@lbl_88C0CD10, u32@0x68 */
void ts4_addr_lbl_88C12D18_88ADFC60(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C12D18) + 104) = (ts4_word)(*(ts4_word *)lbl_88C0CD10);
    return;
}

/* Swing_DLL.xex 0x88AE04C8: addr lbl_88C12D90, u32@lbl_88C0CD10, u32@0x20 */
void ts4_addr_lbl_88C12D90_88AE04C8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C12D90) + 32) = (ts4_word)(*(ts4_word *)lbl_88C0CD10);
    return;
}

/* Swing_DLL.xex 0x88AE0638: addr lbl_88C12E38, u32@lbl_88C0C8E8, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88C12E38_88AE0638(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88C0C8E8;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C12E38) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C12E38) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AE06D0: addr lbl_88C12FA0, u32@lbl_88C0CD10, u32@0x68 */
void ts4_addr_lbl_88C12FA0_88AE06D0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C12FA0) + 104) = (ts4_word)(*(ts4_word *)lbl_88C0CD10);
    return;
}

/* Swing_DLL.xex 0x88AE0FE0: addr lbl_88C13048, u32@lbl_88C0CD1C, u32@0x8 */
void ts4_addr_lbl_88C13048_88AE0FE0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C13048) + 8) = (ts4_word)(*(ts4_word *)lbl_88C0CD1C);
    return;
}

/* Swing_DLL.xex 0x88AE17D0: addr lbl_88C13060, u32@lbl_88C0CD6C, u32@0x50 */
void ts4_addr_lbl_88C13060_88AE17D0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C13060) + 80) = (ts4_word)(*(ts4_word *)lbl_88C0CD6C);
    return;
}

/* Swing_DLL.xex 0x88AE2030: addr lbl_88C13120, u32@lbl_88C0D598, u32@0x8 */
void ts4_addr_lbl_88C13120_88AE2030(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C13120) + 8) = (ts4_word)(*(ts4_word *)lbl_88C0D598);
    return;
}

/* Swing_DLL.xex 0x88AE2208: addr lbl_88C13168, u32@lbl_88C0D618, u32@0x68 */
void ts4_addr_lbl_88C13168_88AE2208(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C13168) + 104) = (ts4_word)(*(ts4_word *)lbl_88C0D618);
    return;
}

/* Swing_DLL.xex 0x88AE2630: addr lbl_88C13240, u32@lbl_88C0D7F8, u32@0x50 */
void ts4_addr_lbl_88C13240_88AE2630(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C13240) + 80) = (ts4_word)(*(ts4_word *)lbl_88C0D7F8);
    return;
}

/* Swing_DLL.xex 0x88AE3450: addr lbl_88C132B8, u32@lbl_88C0DEEC, u32@0x8 */
void ts4_addr_lbl_88C132B8_88AE3450(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C132B8) + 8) = (ts4_word)(*(ts4_word *)lbl_88C0DEEC);
    return;
}

/* Swing_DLL.xex 0x88AE3550: addr lbl_88C132D0, u32@lbl_88C0E1A8, u32@0x20 */
void ts4_addr_lbl_88C132D0_88AE3550(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C132D0) + 32) = (ts4_word)(*(ts4_word *)lbl_88C0E1A8);
    return;
}

/* Swing_DLL.xex 0x88AE3C80: addr lbl_88C13348, u32@lbl_88C0E574, u32@0x8 */
void ts4_addr_lbl_88C13348_88AE3C80(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C13348) + 8) = (ts4_word)(*(ts4_word *)lbl_88C0E574);
    return;
}

/* Swing_DLL.xex 0x88AE5220: addr lbl_88C13900, u32@lbl_88C0F6E0, u32@0x80 */
void ts4_addr_lbl_88C13900_88AE5220(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C13900) + 128) = (ts4_word)(*(ts4_word *)lbl_88C0F6E0);
    return;
}

/* Swing_DLL.xex 0x88AE65E8: call_seq lbl_88079D38, lbl_8807C4B0, lbl_88D1D704, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF740, fn_88563470 */
ts4_word ts4_call_seq_lbl_88079D38_88AE65E8(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88D1D704, (ts4_word)(ts4_word)lbl_8807C4B0, (ts4_word)5, (ts4_word)(ts4_word)lbl_88079D38);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF740);
    return t2;
}

/* Swing_DLL.xex 0x88AE66A0: addr lbl_88C1D6B8, u32@lbl_88C13AC8, u32@0x50 */
void ts4_addr_lbl_88C1D6B8_88AE66A0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1D6B8) + 80) = (ts4_word)(*(ts4_word *)lbl_88C13AC8);
    return;
}

/* Swing_DLL.xex 0x88AE6808: addr lbl_88C1D718, u32@lbl_88C13B2C, u32@0x8 */
void ts4_addr_lbl_88C1D718_88AE6808(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1D718) + 8) = (ts4_word)(*(ts4_word *)lbl_88C13B2C);
    return;
}

/* Swing_DLL.xex 0x88AE72F8: addr lbl_88C1D8C8, u32@lbl_88C14184, u32@0xc8 */
void ts4_addr_lbl_88C1D8C8_88AE72F8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1D8C8) + 200) = (ts4_word)(*(ts4_word *)lbl_88C14184);
    return;
}

/* Swing_DLL.xex 0x88AE7388: addr lbl_88C1D9A0, u32@lbl_88C145E0, u32@0x8 */
void ts4_addr_lbl_88C1D9A0_88AE7388(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1D9A0) + 8) = (ts4_word)(*(ts4_word *)lbl_88C145E0);
    return;
}

/* Swing_DLL.xex 0x88AE7920: addr lbl_88C1DAD8, u32@lbl_88C14BD8, u32@0x80 */
void ts4_addr_lbl_88C1DAD8_88AE7920(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1DAD8) + 128) = (ts4_word)(*(ts4_word *)lbl_88C14BD8);
    return;
}

/* Swing_DLL.xex 0x88AE7DA0: addr lbl_88C1DB68, u32@lbl_88C14EF8, u32@0x68 */
void ts4_addr_lbl_88C1DB68_88AE7DA0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1DB68) + 104) = (ts4_word)(*(ts4_word *)lbl_88C14EF8);
    return;
}

/* Swing_DLL.xex 0x88AE7EA0: addr lbl_88C1DC28, u32@lbl_88C14EFC, u32@0x8 */
void ts4_addr_lbl_88C1DC28_88AE7EA0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1DC28) + 8) = (ts4_word)(*(ts4_word *)lbl_88C14EFC);
    return;
}

/* Swing_DLL.xex 0x88AE7FA8: addr lbl_88C1DDC0, u32@lbl_88C14FAC, u32@0xe0 */
void ts4_addr_lbl_88C1DDC0_88AE7FA8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1DDC0) + 224) = (ts4_word)(*(ts4_word *)lbl_88C14FAC);
    return;
}

/* Swing_DLL.xex 0x88AE8880: addr lbl_88C1DF28, u32@lbl_88C15958, u32@0xc8 */
void ts4_addr_lbl_88C1DF28_88AE8880(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1DF28) + 200) = (ts4_word)(*(ts4_word *)lbl_88C15958);
    return;
}

/* Swing_DLL.xex 0x88AE8C58: addr lbl_88C1E030, u32@lbl_88C1595C, u32@0x50 */
void ts4_addr_lbl_88C1E030_88AE8C58(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1E030) + 80) = (ts4_word)(*(ts4_word *)lbl_88C1595C);
    return;
}

/* Swing_DLL.xex 0x88AE8FB8: addr lbl_88C1E138, u32@lbl_88C15EE8, u32@0x38 */
void ts4_addr_lbl_88C1E138_88AE8FB8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1E138) + 56) = (ts4_word)(*(ts4_word *)lbl_88C15EE8);
    return;
}

/* Swing_DLL.xex 0x88AE90C0: addr lbl_88C1E210, u32@lbl_88C15F04, u32@0x8 */
void ts4_addr_lbl_88C1E210_88AE90C0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1E210) + 8) = (ts4_word)(*(ts4_word *)lbl_88C15F04);
    return;
}

/* Swing_DLL.xex 0x88AE9900: addr lbl_88C1E2A0, u32@lbl_88C163A8, u32@0xe0 */
void ts4_addr_lbl_88C1E2A0_88AE9900(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1E2A0) + 224) = (ts4_word)(*(ts4_word *)lbl_88C163A8);
    return;
}

/* Swing_DLL.xex 0x88AE9AD8: addr lbl_88C1E3A8, u32@lbl_88C15F54, u32@0xe0 */
void ts4_addr_lbl_88C1E3A8_88AE9AD8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1E3A8) + 224) = (ts4_word)(*(ts4_word *)lbl_88C15F54);
    return;
}

/* Swing_DLL.xex 0x88AE9C00: addr lbl_88C1E6A8, u32@lbl_88C1653C, u32@0x50 */
void ts4_addr_lbl_88C1E6A8_88AE9C00(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1E6A8) + 80) = (ts4_word)(*(ts4_word *)lbl_88C1653C);
    return;
}

/* Swing_DLL.xex 0x88AE9DF8: addr lbl_88C1E7E0, u32@lbl_88C16544, u32@0x20 */
void ts4_addr_lbl_88C1E7E0_88AE9DF8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1E7E0) + 32) = (ts4_word)(*(ts4_word *)lbl_88C16544);
    return;
}

/* Swing_DLL.xex 0x88AEABA0: addr lbl_88C1EF48, u32@lbl_88C17598, u32@0x80, u32@0x98 */
void ts4_addr_lbl_88C1EF48_88AEABA0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88C17598;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1EF48) + 128) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1EF48) + 152) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AEACB0: addr lbl_88C1F008, u32@lbl_88C1759C, u32@0x50 */
void ts4_addr_lbl_88C1F008_88AEACB0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1F008) + 80) = (ts4_word)(*(ts4_word *)lbl_88C1759C);
    return;
}

/* Swing_DLL.xex 0x88AEAE30: addr lbl_88C1F0B0, u32@lbl_88C17768, u32@0x38 */
void ts4_addr_lbl_88C1F0B0_88AEAE30(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1F0B0) + 56) = (ts4_word)(*(ts4_word *)lbl_88C17768);
    return;
}

/* Swing_DLL.xex 0x88AEB5B0: addr lbl_88C1F518, u32@lbl_88C17DB8, u32@0x50 */
void ts4_addr_lbl_88C1F518_88AEB5B0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1F518) + 80) = (ts4_word)(*(ts4_word *)lbl_88C17DB8);
    return;
}

/* Swing_DLL.xex 0x88AEB710: addr lbl_88C1F5F0, u32@lbl_88C17DF0, u32@0xc8 */
void ts4_addr_lbl_88C1F5F0_88AEB710(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1F5F0) + 200) = (ts4_word)(*(ts4_word *)lbl_88C17DF0);
    return;
}

/* Swing_DLL.xex 0x88AEB808: addr lbl_88C1F6E0, u32@lbl_88C17DF4, u32@0x50 */
void ts4_addr_lbl_88C1F6E0_88AEB808(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1F6E0) + 80) = (ts4_word)(*(ts4_word *)lbl_88C17DF4);
    return;
}

/* Swing_DLL.xex 0x88AEBCA8: addr lbl_88C1F818, u32@lbl_88C180F0, u32@0x20 */
void ts4_addr_lbl_88C1F818_88AEBCA8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1F818) + 32) = (ts4_word)(*(ts4_word *)lbl_88C180F0);
    return;
}

/* Swing_DLL.xex 0x88AEBD30: addr lbl_88C1F848, u32@lbl_88C180F0, u32@0x20 */
void ts4_addr_lbl_88C1F848_88AEBD30(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1F848) + 32) = (ts4_word)(*(ts4_word *)lbl_88C180F0);
    return;
}

/* Swing_DLL.xex 0x88AEBE28: addr lbl_88C1F878, u32@lbl_88C180F0, u32@0x20 */
void ts4_addr_lbl_88C1F878_88AEBE28(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1F878) + 32) = (ts4_word)(*(ts4_word *)lbl_88C180F0);
    return;
}

/* Swing_DLL.xex 0x88AEC470: addr lbl_88C1F8A8, u32@lbl_88C1822C, u32@0x8 */
void ts4_addr_lbl_88C1F8A8_88AEC470(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1F8A8) + 8) = (ts4_word)(*(ts4_word *)lbl_88C1822C);
    return;
}

/* Swing_DLL.xex 0x88AEC5E0: addr lbl_88C1F920, u32@lbl_88C1842C, u32@0x20 */
void ts4_addr_lbl_88C1F920_88AEC5E0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1F920) + 32) = (ts4_word)(*(ts4_word *)lbl_88C1842C);
    return;
}

/* Swing_DLL.xex 0x88AEC748: addr lbl_88C1F968, u32@lbl_88C18538, u32@0x8 */
void ts4_addr_lbl_88C1F968_88AEC748(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1F968) + 8) = (ts4_word)(*(ts4_word *)lbl_88C18538);
    return;
}

/* Swing_DLL.xex 0x88AED428: addr lbl_88C1F9E0, u32@lbl_88C19188, u32@0x20 */
void ts4_addr_lbl_88C1F9E0_88AED428(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1F9E0) + 32) = (ts4_word)(*(ts4_word *)lbl_88C19188);
    return;
}

/* Swing_DLL.xex 0x88AEDA00: addr lbl_88C1FAD0, u32@lbl_88C19250, u32@0xb0 */
void ts4_addr_lbl_88C1FAD0_88AEDA00(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1FAD0) + 176) = (ts4_word)(*(ts4_word *)lbl_88C19250);
    return;
}

/* Swing_DLL.xex 0x88AEDB08: addr lbl_88C1FBC0, u32@lbl_88C19D38, u32@0xb0 */
void ts4_addr_lbl_88C1FBC0_88AEDB08(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1FBC0) + 176) = (ts4_word)(*(ts4_word *)lbl_88C19D38);
    return;
}

/* Swing_DLL.xex 0x88AEDD60: addr lbl_88C1FCC8, u32@lbl_88C19D38, u32@0x68 */
void ts4_addr_lbl_88C1FCC8_88AEDD60(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1FCC8) + 104) = (ts4_word)(*(ts4_word *)lbl_88C19D38);
    return;
}

/* Swing_DLL.xex 0x88AEE5C8: addr lbl_88C1FD40, u32@lbl_88C19D38, u32@0x20 */
void ts4_addr_lbl_88C1FD40_88AEE5C8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1FD40) + 32) = (ts4_word)(*(ts4_word *)lbl_88C19D38);
    return;
}

/* Swing_DLL.xex 0x88AEE738: addr lbl_88C1FDE8, u32@lbl_88C198E0, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88C1FDE8_88AEE738(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88C198E0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1FDE8) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1FDE8) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AEE7D0: addr lbl_88C1FF50, u32@lbl_88C19D38, u32@0x68 */
void ts4_addr_lbl_88C1FF50_88AEE7D0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1FF50) + 104) = (ts4_word)(*(ts4_word *)lbl_88C19D38);
    return;
}

/* Swing_DLL.xex 0x88AEF0E0: addr lbl_88C1FFF8, u32@lbl_88C19D44, u32@0x8 */
void ts4_addr_lbl_88C1FFF8_88AEF0E0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C1FFF8) + 8) = (ts4_word)(*(ts4_word *)lbl_88C19D44);
    return;
}

/* Swing_DLL.xex 0x88AEF8D0: addr lbl_88C20010, u32@lbl_88C19D94, u32@0x50 */
void ts4_addr_lbl_88C20010_88AEF8D0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C20010) + 80) = (ts4_word)(*(ts4_word *)lbl_88C19D94);
    return;
}

/* Swing_DLL.xex 0x88AF0130: addr lbl_88C200D0, u32@lbl_88C1A5C0, u32@0x8 */
void ts4_addr_lbl_88C200D0_88AF0130(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C200D0) + 8) = (ts4_word)(*(ts4_word *)lbl_88C1A5C0);
    return;
}

/* Swing_DLL.xex 0x88AF0308: addr lbl_88C20118, u32@lbl_88C1A640, u32@0x68 */
void ts4_addr_lbl_88C20118_88AF0308(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C20118) + 104) = (ts4_word)(*(ts4_word *)lbl_88C1A640);
    return;
}

/* Swing_DLL.xex 0x88AF0730: addr lbl_88C201F0, u32@lbl_88C1A820, u32@0x50 */
void ts4_addr_lbl_88C201F0_88AF0730(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C201F0) + 80) = (ts4_word)(*(ts4_word *)lbl_88C1A820);
    return;
}

/* Swing_DLL.xex 0x88AF1550: addr lbl_88C20268, u32@lbl_88C1AF14, u32@0x8 */
void ts4_addr_lbl_88C20268_88AF1550(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C20268) + 8) = (ts4_word)(*(ts4_word *)lbl_88C1AF14);
    return;
}

/* Swing_DLL.xex 0x88AF1650: addr lbl_88C20280, u32@lbl_88C1B1D0, u32@0x20 */
void ts4_addr_lbl_88C20280_88AF1650(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C20280) + 32) = (ts4_word)(*(ts4_word *)lbl_88C1B1D0);
    return;
}

/* Swing_DLL.xex 0x88AF1D80: addr lbl_88C202F8, u32@lbl_88C1B59C, u32@0x8 */
void ts4_addr_lbl_88C202F8_88AF1D80(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C202F8) + 8) = (ts4_word)(*(ts4_word *)lbl_88C1B59C);
    return;
}

/* Swing_DLL.xex 0x88AF2A58: addr lbl_88C208B0, u32@lbl_88C1C018, u32@0x38 */
void ts4_addr_lbl_88C208B0_88AF2A58(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C208B0) + 56) = (ts4_word)(*(ts4_word *)lbl_88C1C018);
    return;
}

/* Swing_DLL.xex 0x88AF3338: addr lbl_88C208F8, u32@lbl_88C1C034, u32@0x80 */
void ts4_addr_lbl_88C208F8_88AF3338(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C208F8) + 128) = (ts4_word)(*(ts4_word *)lbl_88C1C034);
    return;
}

/* Swing_DLL.xex 0x88AF4700: call_seq lbl_8807CF40, lbl_8807F728, lbl_88D2320C, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF758, fn_88563470 */
ts4_word ts4_call_seq_lbl_8807CF40_88AF4700(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88D2320C, (ts4_word)(ts4_word)lbl_8807F728, (ts4_word)5, (ts4_word)(ts4_word)lbl_8807CF40);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF758);
    return t2;
}

/* Swing_DLL.xex 0x88AF4EA0: addr lbl_88C20F38, u32@lbl_88C20E50, u32@0xb0 */
void ts4_addr_lbl_88C20F38_88AF4EA0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C20F38) + 176) = (ts4_word)(*(ts4_word *)lbl_88C20E50);
    return;
}

/* Swing_DLL.xex 0x88AF5008: addr lbl_88C21028, u32@lbl_88C218EC, u32@0xb0 */
void ts4_addr_lbl_88C21028_88AF5008(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C21028) + 176) = (ts4_word)(*(ts4_word *)lbl_88C218EC);
    return;
}

/* Swing_DLL.xex 0x88AF5380: addr lbl_88C211B8, u32@lbl_88C211A0, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88C211B8_88AF5380(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88C211A0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C211B8) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C211B8) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AF5478: addr lbl_88C21320, u32@lbl_88C218EC, u32@0x68 */
void ts4_addr_lbl_88C21320_88AF5478(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C21320) + 104) = (ts4_word)(*(ts4_word *)lbl_88C218EC);
    return;
}

/* Swing_DLL.xex 0x88AF5980: addr lbl_88C215D0, u32@lbl_88C218EC, u32@0x68 */
void ts4_addr_lbl_88C215D0_88AF5980(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C215D0) + 104) = (ts4_word)(*(ts4_word *)lbl_88C218EC);
    return;
}

/* Swing_DLL.xex 0x88AF6178: addr lbl_88C217E0, u32@lbl_88C218EC, u32@0x20 */
void ts4_addr_lbl_88C217E0_88AF6178(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C217E0) + 32) = (ts4_word)(*(ts4_word *)lbl_88C218EC);
    return;
}

/* Swing_DLL.xex 0x88AF65E8: addr lbl_88C21910, u32@lbl_88C21908, u32@0x20 */
void ts4_addr_lbl_88C21910_88AF65E8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C21910) + 32) = (ts4_word)(*(ts4_word *)lbl_88C21908);
    return;
}

/* Swing_DLL.xex 0x88AF7040: addr lbl_88C22A50, u32@lbl_88C22A38, u32@0x20 */
void ts4_addr_lbl_88C22A50_88AF7040(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C22A50) + 32) = (ts4_word)(*(ts4_word *)lbl_88C22A38);
    return;
}

/* Swing_DLL.xex 0x88AF7228: addr lbl_88C22C58, u32@lbl_88C22C38, u32@0x68 */
void ts4_addr_lbl_88C22C58_88AF7228(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C22C58) + 104) = (ts4_word)(*(ts4_word *)lbl_88C22C38);
    return;
}

/* Swing_DLL.xex 0x88AF7C48: addr lbl_88C23000, u32@lbl_88C22FF8, u32@0x50 */
void ts4_addr_lbl_88C23000_88AF7C48(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C23000) + 80) = (ts4_word)(*(ts4_word *)lbl_88C22FF8);
    return;
}

/* Swing_DLL.xex 0x88AF8610: addr lbl_88C23338, u32@lbl_88C23324, u32@0x38 */
void ts4_addr_lbl_88C23338_88AF8610(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C23338) + 56) = (ts4_word)(*(ts4_word *)lbl_88C23324);
    return;
}

/* Swing_DLL.xex 0x88AF8FF0: addr lbl_88C23AC8, u32@lbl_88C23AB0, u32@0x8 */
void ts4_addr_lbl_88C23AC8_88AF8FF0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C23AC8) + 8) = (ts4_word)(*(ts4_word *)lbl_88C23AB0);
    return;
}

/* Swing_DLL.xex 0x88AF9158: addr lbl_88C23D1C, u32@lbl_88C23B30, u32@0x8 */
void ts4_addr_lbl_88C23D1C_88AF9158(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C23D1C) + 8) = (ts4_word)(*(ts4_word *)lbl_88C23B30);
    return;
}

/* Swing_DLL.xex 0x88AF9938: addr lbl_88C23D38, u32@lbl_88C23B38, u32@0x50 */
void ts4_addr_lbl_88C23D38_88AF9938(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C23D38) + 80) = (ts4_word)(*(ts4_word *)lbl_88C23B38);
    return;
}

/* Swing_DLL.xex 0x88AFA278: addr lbl_88C23E10, u32@lbl_88C23E0C, u32@0x8 */
void ts4_addr_lbl_88C23E10_88AFA278(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C23E10) + 8) = (ts4_word)(*(ts4_word *)lbl_88C23E0C);
    return;
}

/* Swing_DLL.xex 0x88AFA3E0: addr lbl_88C23E30, u32@lbl_88C23E28, u32@0x8 */
void ts4_addr_lbl_88C23E30_88AFA3E0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C23E30) + 8) = (ts4_word)(*(ts4_word *)lbl_88C23E28);
    return;
}

/* Swing_DLL.xex 0x88AFB160: addr lbl_88C24A18, u32@lbl_88C249F0, u32@0x80 */
void ts4_addr_lbl_88C24A18_88AFB160(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C24A18) + 128) = (ts4_word)(*(ts4_word *)lbl_88C249F0);
    return;
}

/* Swing_DLL.xex 0x88AFB600: call_seq ts4_pack_bytes_dabc_884E1EE8, u32@lbl_88D25FBC */
ts4_word ts4_call_seq_fn_884E1EE8_88AFB600(void)
{
    ts4_word t1;

    t1 = ts4_pack_bytes_dabc_884E1EE8((ts4_word)200, (ts4_word)200, (ts4_word)255, (ts4_word)80);
    *(ts4_word *)lbl_88D25FBC = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x88AFB638: call_seq ts4_pack_bytes_dabc_884E1EE8, u32@lbl_88D25FB8 */
ts4_word ts4_call_seq_fn_884E1EE8_88AFB638(void)
{
    ts4_word t1;

    t1 = ts4_pack_bytes_dabc_884E1EE8((ts4_word)200, (ts4_word)255, (ts4_word)200, (ts4_word)150);
    *(ts4_word *)lbl_88D25FB8 = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x88AFB670: call_seq ts4_pack_bytes_dabc_884E1EE8, u32@lbl_88D25FC8 */
ts4_word ts4_call_seq_fn_884E1EE8_88AFB670(void)
{
    ts4_word t1;

    t1 = ts4_pack_bytes_dabc_884E1EE8((ts4_word)240, (ts4_word)240, (ts4_word)240, (ts4_word)255);
    *(ts4_word *)lbl_88D25FC8 = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x88AFB6A8: call_seq ts4_pack_bytes_dabc_884E1EE8, u32@lbl_88D25FCC */
ts4_word ts4_call_seq_fn_884E1EE8_88AFB6A8(void)
{
    ts4_word t1;

    t1 = ts4_pack_bytes_dabc_884E1EE8((ts4_word)120, (ts4_word)120, (ts4_word)120, (ts4_word)255);
    *(ts4_word *)lbl_88D25FCC = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x88AFB6E0: call_seq ts4_pack_bytes_dabc_884E1EE8, u32@lbl_88D25FD8 */
ts4_word ts4_call_seq_fn_884E1EE8_88AFB6E0(void)
{
    ts4_word t1;

    t1 = ts4_pack_bytes_dabc_884E1EE8((ts4_word)240, (ts4_word)200, (ts4_word)0, (ts4_word)200);
    *(ts4_word *)lbl_88D25FD8 = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x88AFB718: addr lbl_88C24FD4, u32@lbl_88CAD560, u32@lbl_88CAD560, u32@0x4 */
void ts4_addr_lbl_88C24FD4_88AFB718(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAD560;
    *(ts4_word *)lbl_88CAD560 = (ts4_word)(ts4_word)lbl_88C24FD4;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C24FD4) + 4) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AFB738: call_seq ts4_pack_bytes_dabc_884E1EE8, u32@lbl_88D25FF4 */
ts4_word ts4_call_seq_fn_884E1EE8_88AFB738(void)
{
    ts4_word t1;

    t1 = ts4_pack_bytes_dabc_884E1EE8((ts4_word)140, (ts4_word)240, (ts4_word)140, (ts4_word)140);
    *(ts4_word *)lbl_88D25FF4 = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x88AFB770: call_seq ts4_pack_bytes_dabc_884E1EE8, u32@lbl_88D25FF8 */
ts4_word ts4_call_seq_fn_884E1EE8_88AFB770(void)
{
    ts4_word t1;

    t1 = ts4_pack_bytes_dabc_884E1EE8((ts4_word)70, (ts4_word)200, (ts4_word)70, (ts4_word)140);
    *(ts4_word *)lbl_88D25FF8 = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x88AFB7A8: addr lbl_88C25378, u32@lbl_88CAD560, u32@lbl_88CAD560, u32@0x4 */
void ts4_addr_lbl_88C25378_88AFB7A8(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAD560;
    *(ts4_word *)lbl_88CAD560 = (ts4_word)(ts4_word)lbl_88C25378;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C25378) + 4) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AFB7C8: addr lbl_88C25414, u32@lbl_88CAD560, u32@lbl_88CAD560, u32@0x4 */
void ts4_addr_lbl_88C25414_88AFB7C8(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAD560;
    *(ts4_word *)lbl_88CAD560 = (ts4_word)(ts4_word)lbl_88C25414;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C25414) + 4) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AFC7E8: addr lbl_88C259B0, u32@lbl_88C25A70, u32@0x20 */
void ts4_addr_lbl_88C259B0_88AFC7E8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C259B0) + 32) = (ts4_word)(*(ts4_word *)lbl_88C25A70);
    return;
}

/* Swing_DLL.xex 0x88AFC870: addr lbl_88C259F0, u32@lbl_88C25A70, u32@0x20 */
void ts4_addr_lbl_88C259F0_88AFC870(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C259F0) + 32) = (ts4_word)(*(ts4_word *)lbl_88C25A70);
    return;
}

/* Swing_DLL.xex 0x88AFC968: addr lbl_88C25A40, u32@lbl_88C25A70, u32@0x20 */
void ts4_addr_lbl_88C25A40_88AFC968(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C25A40) + 32) = (ts4_word)(*(ts4_word *)lbl_88C25A70);
    return;
}

/* Swing_DLL.xex 0x88AFCD00: addr lbl_88C25B00, u32@lbl_88C25AE8, u32@0x8 */
void ts4_addr_lbl_88C25B00_88AFCD00(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C25B00) + 8) = (ts4_word)(*(ts4_word *)lbl_88C25AE8);
    return;
}

/* Swing_DLL.xex 0x88AFCD88: addr lbl_88C25B90, u32@lbl_88C25B78, u32@0x8 */
void ts4_addr_lbl_88C25B90_88AFCD88(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C25B90) + 8) = (ts4_word)(*(ts4_word *)lbl_88C25B78);
    return;
}

/* Swing_DLL.xex 0x88AFCEF8: addr lbl_88C25C48, u32@lbl_88C25C30, u32@0x20 */
void ts4_addr_lbl_88C25C48_88AFCEF8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C25C48) + 32) = (ts4_word)(*(ts4_word *)lbl_88C25C30);
    return;
}

/* Swing_DLL.xex 0x88AFDD28: call_seq lbl_8808B910, lbl_880CE328, lbl_88D26F88, ts4_set_u32_offc_884CE9B8, ts4_addr_lbl_8803A308_88AFF7A0, fn_88563470 */
ts4_word ts4_call_seq_lbl_8808B910_88AFDD28(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE9B8((ts4_word)(ts4_word)lbl_88D26F88, (ts4_word)(ts4_word)lbl_880CE328, (ts4_word)-1, (ts4_word)(ts4_word)lbl_8808B910);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF7A0);
    return t2;
}

/* Swing_DLL.xex 0x88AFDD70: addr lbl_88C25F08, u32@lbl_88CAD560, u32@lbl_88CAD560, u32@0x4 */
void ts4_addr_lbl_88C25F08_88AFDD70(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAD560;
    *(ts4_word *)lbl_88CAD560 = (ts4_word)(ts4_word)lbl_88C25F08;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C25F08) + 4) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AFDD90: addr lbl_88C26228, u32@lbl_88CAD560, u32@lbl_88CAD560, u32@0x4 */
void ts4_addr_lbl_88C26228_88AFDD90(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAD560;
    *(ts4_word *)lbl_88CAD560 = (ts4_word)(ts4_word)lbl_88C26228;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C26228) + 4) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AFDDB0: addr lbl_88C2625C, u32@lbl_8808C384, u8@0x1 */
void ts4_addr_lbl_88C2625C_88AFDDB0(void)
{
    *(unsigned char *)((char *)(ts4_word)((ts4_word)lbl_88C2625C) + 1) = (unsigned char)(((*(ts4_word *)lbl_8808C384) + -1) == 0);
    return;
}

/* Swing_DLL.xex 0x88AFDDD8: addr lbl_88C26690, u32@lbl_88CAD560, u32@lbl_88CAD560, u32@0x4 */
void ts4_addr_lbl_88C26690_88AFDDD8(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAD560;
    *(ts4_word *)lbl_88CAD560 = (ts4_word)(ts4_word)lbl_88C26690;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C26690) + 4) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AFDDF8: addr lbl_88C267B0, u32@lbl_88CAD560, u32@lbl_88CAD560, u32@0x4 */
void ts4_addr_lbl_88C267B0_88AFDDF8(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAD560;
    *(ts4_word *)lbl_88CAD560 = (ts4_word)(ts4_word)lbl_88C267B0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C267B0) + 4) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AFE050: addr lbl_88C309B0, u32@lbl_88C30978, u32@0x38 */
void ts4_addr_lbl_88C309B0_88AFE050(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C309B0) + 56) = (ts4_word)(*(ts4_word *)lbl_88C30978);
    return;
}

/* Swing_DLL.xex 0x88AFE638: addr lbl_88D3C95C, lbl_88D3C988, ts4_set_u32_off0_885DD498 */
ts4_word ts4_addr_lbl_88D3C95C_88AFE638(void)
{
    return ts4_set_u32_off0_885DD498((ts4_word)(ts4_word)lbl_88D3C988, (ts4_word)(ts4_word)lbl_88D3C95C);
}

/* Swing_DLL.xex 0x88AFE650: addr lbl_88C4533C, u32@lbl_88CAD560, u32@lbl_88CAD560, u32@0x4 */
void ts4_addr_lbl_88C4533C_88AFE650(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAD560;
    *(ts4_word *)lbl_88CAD560 = (ts4_word)(ts4_word)lbl_88C4533C;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C4533C) + 4) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AFE670: call_seq KeTlsAlloc, ts4_get_u32_lbl_88D3CB08_88AFF7E0, u32@lbl_88D3CB08, fn_88563470 */
ts4_word ts4_call_seq_KeTlsAlloc_88AFE670(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = KeTlsAlloc();
    *(ts4_word *)lbl_88D3CB08 = (ts4_word)t1;
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_get_u32_lbl_88D3CB08_88AFF7E0);
    return t2;
}

/* Swing_DLL.xex 0x88AFE6A8: call_seq lbl_88D3CB10, RtlInitializeCriticalSectionAndSpinCount, u64@0x20, ts4_addr_lbl_88D3CB10_88AFF7F0, fn_88563470 */
ts4_word ts4_call_seq_lbl_88D3CB10_88AFE6A8(void)
{
    ts4_word t2;

    RtlInitializeCriticalSectionAndSpinCount((ts4_word)(ts4_word)lbl_88D3CB10, (ts4_word)0);
    *(ts4_u64 *)((char *)(ts4_word)((ts4_word)lbl_88D3CB10) + 32) = (ts4_u64)-1;
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_88D3CB10_88AFF7F0);
    return t2;
}

/* Swing_DLL.xex 0x88AFE6F8: addr lbl_88C45418, u32@lbl_88CAD560, u32@lbl_88CAD560, u32@0x4 */
void ts4_addr_lbl_88C45418_88AFE6F8(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAD560;
    *(ts4_word *)lbl_88CAD560 = (ts4_word)(ts4_word)lbl_88C45418;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C45418) + 4) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AFE718: addr lbl_88C4547C, u32@lbl_88CAD560, u32@lbl_88CAD560, u32@0x4 */
void ts4_addr_lbl_88C4547C_88AFE718(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAD560;
    *(ts4_word *)lbl_88CAD560 = (ts4_word)(ts4_word)lbl_88C4547C;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C4547C) + 4) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AFEE20: addr lbl_88C4584C, u32@lbl_88CAD560, u32@lbl_88CAD560, u32@0x4 */
void ts4_addr_lbl_88C4584C_88AFEE20(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAD560;
    *(ts4_word *)lbl_88CAD560 = (ts4_word)(ts4_word)lbl_88C4584C;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C4584C) + 4) = (ts4_word)t1;
    return;
}
