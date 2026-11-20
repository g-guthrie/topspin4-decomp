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

extern char ts4_addr_lbl_8803A308_88AFF6B0[];
extern char ts4_addr_lbl_8803A308_88AFF6C8[];
extern char ts4_addr_lbl_8803A308_88AFF6E0[];
extern char ts4_addr_lbl_8803A308_88AFF6F8[];
extern char ts4_addr_lbl_8803A308_88AFF710[];
extern char lbl_88068FF0[];
extern char lbl_8806A870[];
extern char lbl_8806B030[];
extern char lbl_8806C8F8[];
extern char lbl_8806D1E8[];
extern char lbl_8806EB08[];
extern char lbl_88070ED8[];
extern char lbl_88072F40[];
extern char lbl_88074190[];
extern char lbl_880763D8[];
extern char lbl_88BC9AEC[];
extern char lbl_88BCCD90[];
extern char lbl_88BCCF40[];
extern char lbl_88BCCFA4[];
extern char lbl_88BCD384[];
extern char lbl_88BCD6D0[];
extern char lbl_88BCDD40[];
extern char lbl_88BCDE80[];
extern char lbl_88BCDEB8[];
extern char lbl_88BCDED4[];
extern char lbl_88BCEBE4[];
extern char lbl_88BCF1C0[];
extern char lbl_88BCF1C4[];
extern char lbl_88BCF8C0[];
extern char lbl_88BCF944[];
extern char lbl_88BCF9FC[];
extern char lbl_88BCFF28[];
extern char lbl_88BD0020[];
extern char lbl_88BD006C[];
extern char lbl_88BD1048[];
extern char lbl_88BD15D8[];
extern char lbl_88BD19AC[];
extern char lbl_88BD1B98[];
extern char lbl_88BD2200[];
extern char lbl_88BD220C[];
extern char lbl_88BD225C[];
extern char lbl_88BD2A28[];
extern char lbl_88BD2AA8[];
extern char lbl_88BD2C88[];
extern char lbl_88BD3334[];
extern char lbl_88BD35F0[];
extern char lbl_88BD39A4[];
extern char lbl_88BD4410[];
extern char lbl_88BD5498[];
extern char lbl_88BD54E0[];
extern char lbl_88BD5558[];
extern char lbl_88BD5690[];
extern char lbl_88BD5798[];
extern char lbl_88BD5840[];
extern char lbl_88BD59D8[];
extern char lbl_88BD5AC8[];
extern char lbl_88BD5BD0[];
extern char lbl_88BD5D98[];
extern char lbl_88BD5EB8[];
extern char lbl_88BD5EE8[];
extern char lbl_88BD5FA8[];
extern char lbl_88BD6080[];
extern char lbl_88BD60B0[];
extern char lbl_88BD60E0[];
extern char lbl_88BD6110[];
extern char lbl_88BD6188[];
extern char lbl_88BD61D0[];
extern char lbl_88BD6248[];
extern char lbl_88BD6308[];
extern char lbl_88BD63E0[];
extern char lbl_88BD64D0[];
extern char lbl_88BD65C0[];
extern char lbl_88BD6728[];
extern char lbl_88BD67D0[];
extern char lbl_88BD6908[];
extern char lbl_88BD6980[];
extern char lbl_88BD6A28[];
extern char lbl_88BD6A40[];
extern char lbl_88BD6AE8[];
extern char lbl_88BD6B30[];
extern char lbl_88BD6C08[];
extern char lbl_88BD6C80[];
extern char lbl_88BD6C98[];
extern char lbl_88BD6D10[];
extern char lbl_88BD7190[];
extern char lbl_88BD7340[];
extern char lbl_88BD73A4[];
extern char lbl_88BD7784[];
extern char lbl_88BD7AD0[];
extern char lbl_88BD8140[];
extern char lbl_88BD8280[];
extern char lbl_88BD82B8[];
extern char lbl_88BD82D4[];
extern char lbl_88BD8FE4[];
extern char lbl_88BD9620[];
extern char lbl_88BD9624[];
extern char lbl_88BD9D20[];
extern char lbl_88BD9DA4[];
extern char lbl_88BD9E5C[];
extern char lbl_88BDA388[];
extern char lbl_88BDA480[];
extern char lbl_88BDA4CC[];
extern char lbl_88BDB4A8[];
extern char lbl_88BDBA38[];
extern char lbl_88BDBE0C[];
extern char lbl_88BDBFF8[];
extern char lbl_88BDC660[];
extern char lbl_88BDC66C[];
extern char lbl_88BDC6BC[];
extern char lbl_88BDCE88[];
extern char lbl_88BDCF08[];
extern char lbl_88BDD0E8[];
extern char lbl_88BDD794[];
extern char lbl_88BDDA50[];
extern char lbl_88BDDE04[];
extern char lbl_88BDE870[];
extern char lbl_88BDF8F8[];
extern char lbl_88BDF940[];
extern char lbl_88BDF9B8[];
extern char lbl_88BDFAF0[];
extern char lbl_88BDFBF8[];
extern char lbl_88BDFCA0[];
extern char lbl_88BDFE38[];
extern char lbl_88BDFF28[];
extern char lbl_88BE0030[];
extern char lbl_88BE02A0[];
extern char lbl_88BE0408[];
extern char lbl_88BE0438[];
extern char lbl_88BE04F8[];
extern char lbl_88BE05D0[];
extern char lbl_88BE0600[];
extern char lbl_88BE0630[];
extern char lbl_88BE0660[];
extern char lbl_88BE06D8[];
extern char lbl_88BE0720[];
extern char lbl_88BE0798[];
extern char lbl_88BE0858[];
extern char lbl_88BE0930[];
extern char lbl_88BE0A20[];
extern char lbl_88BE0B10[];
extern char lbl_88BE0C78[];
extern char lbl_88BE0D20[];
extern char lbl_88BE0E58[];
extern char lbl_88BE0ED0[];
extern char lbl_88BE0F78[];
extern char lbl_88BE0F90[];
extern char lbl_88BE1038[];
extern char lbl_88BE1080[];
extern char lbl_88BE1158[];
extern char lbl_88BE11D0[];
extern char lbl_88BE11E8[];
extern char lbl_88BE1260[];
extern char lbl_88BE16E0[];
extern char lbl_88BE1890[];
extern char lbl_88BE18F4[];
extern char lbl_88BE1DAC[];
extern char lbl_88BE2278[];
extern char lbl_88BE2768[];
extern char lbl_88BE276C[];
extern char lbl_88BE2894[];
extern char lbl_88BE2A7C[];
extern char lbl_88BE3368[];
extern char lbl_88BE3B38[];
extern char lbl_88BE3B3C[];
extern char lbl_88BE3D30[];
extern char lbl_88BE3D34[];
extern char lbl_88BE4D58[];
extern char lbl_88BE4D5C[];
extern char lbl_88BE4F28[];
extern char lbl_88BE5548[];
extern char lbl_88BE5580[];
extern char lbl_88BE5584[];
extern char lbl_88BE571C[];
extern char lbl_88BE5B88[];
extern char lbl_88BE5C80[];
extern char lbl_88BE5CCC[];
extern char lbl_88BE676C[];
extern char lbl_88BE6924[];
extern char lbl_88BE6B88[];
extern char lbl_88BE7034[];
extern char lbl_88BE7550[];
extern char lbl_88BE7900[];
extern char lbl_88BE7904[];
extern char lbl_88BE7E34[];
extern char lbl_88BE7EF4[];
extern char lbl_88BE8990[];
extern char lbl_88BE89C4[];
extern char lbl_88BE8E38[];
extern char lbl_88BE96D4[];
extern char lbl_88BEAEC0[];
extern char lbl_88BEAF08[];
extern char lbl_88BEAF80[];
extern char lbl_88BEB058[];
extern char lbl_88BEB178[];
extern char lbl_88BEB1C0[];
extern char lbl_88BEB268[];
extern char lbl_88BEB490[];
extern char lbl_88BEB580[];
extern char lbl_88BEB688[];
extern char lbl_88BEB790[];
extern char lbl_88BEBA90[];
extern char lbl_88BEBBB0[];
extern char lbl_88BEC2D0[];
extern char lbl_88BEC378[];
extern char lbl_88BEC420[];
extern char lbl_88BEC888[];
extern char lbl_88BEC960[];
extern char lbl_88BECA50[];
extern char lbl_88BECB88[];
extern char lbl_88BECBB8[];
extern char lbl_88BECBE8[];
extern char lbl_88BECC18[];
extern char lbl_88BECC90[];
extern char lbl_88BECCD8[];
extern char lbl_88BECD50[];
extern char lbl_88BECE28[];
extern char lbl_88BECF18[];
extern char lbl_88BED008[];
extern char lbl_88BED170[];
extern char lbl_88BED218[];
extern char lbl_88BED290[];
extern char lbl_88BED368[];
extern char lbl_88BED410[];
extern char lbl_88BED428[];
extern char lbl_88BED4D0[];
extern char lbl_88BED518[];
extern char lbl_88BED5F0[];
extern char lbl_88BED668[];
extern char lbl_88BED680[];
extern char lbl_88BED6F8[];
extern char lbl_88BEDC68[];
extern char lbl_88BEDE18[];
extern char lbl_88BEDE7C[];
extern char lbl_88BEE334[];
extern char lbl_88BEE778[];
extern char lbl_88BEEDB8[];
extern char lbl_88BEEDBC[];
extern char lbl_88BEEEE4[];
extern char lbl_88BEF0CC[];
extern char lbl_88BEFA30[];
extern char lbl_88BF0140[];
extern char lbl_88BF0144[];
extern char lbl_88BF0338[];
extern char lbl_88BF033C[];
extern char lbl_88BF1270[];
extern char lbl_88BF1274[];
extern char lbl_88BF1440[];
extern char lbl_88BF1A60[];
extern char lbl_88BF1A98[];
extern char lbl_88BF1A9C[];
extern char lbl_88BF1D98[];
extern char lbl_88BF1ED4[];
extern char lbl_88BF20D4[];
extern char lbl_88BF21E0[];
extern char lbl_88BF2E30[];
extern char lbl_88BF2F40[];
extern char lbl_88BF2F4C[];
extern char lbl_88BF3A70[];
extern char lbl_88BF3A7C[];
extern char lbl_88BF3ACC[];
extern char lbl_88BF42E0[];
extern char lbl_88BF4360[];
extern char lbl_88BF4540[];
extern char lbl_88BF4C34[];
extern char lbl_88BF4EF0[];
extern char lbl_88BF52BC[];
extern char lbl_88BF63F8[];
extern char lbl_88BF73F0[];
extern char lbl_88BF7438[];
extern char lbl_88BF74B0[];
extern char lbl_88BF7588[];
extern char lbl_88BF76A8[];
extern char lbl_88BF76F0[];
extern char lbl_88BF7798[];
extern char lbl_88BF7930[];
extern char lbl_88BF7A80[];
extern char lbl_88BF7B88[];
extern char lbl_88BF7C90[];
extern char lbl_88BF7F90[];
extern char lbl_88BF80B0[];
extern char lbl_88BF8818[];
extern char lbl_88BF88C0[];
extern char lbl_88BF8968[];
extern char lbl_88BF8DD0[];
extern char lbl_88BF8EA8[];
extern char lbl_88BF8F98[];
extern char lbl_88BF90D0[];
extern char lbl_88BF9100[];
extern char lbl_88BF9130[];
extern char lbl_88BF9160[];
extern char lbl_88BF91D8[];
extern char lbl_88BF9220[];
extern char lbl_88BF9298[];
extern char lbl_88BF9370[];
extern char lbl_88BF9460[];
extern char lbl_88BF9568[];
extern char lbl_88BF96D0[];
extern char lbl_88BF9778[];
extern char lbl_88BF97F0[];
extern char lbl_88BF98C8[];
extern char lbl_88BF9970[];
extern char lbl_88BF9988[];
extern char lbl_88BF9A48[];
extern char lbl_88BF9A90[];
extern char lbl_88BF9B68[];
extern char lbl_88BF9BE0[];
extern char lbl_88BF9BF8[];
extern char lbl_88BF9C70[];
extern char lbl_88BFA1E0[];
extern char lbl_88BFA3A8[];
extern char lbl_88BFA40C[];
extern char lbl_88BFA8C4[];
extern char lbl_88BFAD08[];
extern char lbl_88BFB348[];
extern char lbl_88BFB34C[];
extern char lbl_88BFB474[];
extern char lbl_88BFB674[];
extern char lbl_88BFC158[];
extern char lbl_88BFC868[];
extern char lbl_88BFC86C[];
extern char lbl_88BFCA60[];
extern char lbl_88BFCBE8[];
extern char lbl_88BFD57C[];
extern char lbl_88BFDA48[];
extern char lbl_88BFDA4C[];
extern char lbl_88BFE0B4[];
extern char lbl_88BFE1F4[];
extern char lbl_88BFE1F8[];
extern char lbl_88BFE38C[];
extern char lbl_88BFE7F8[];
extern char lbl_88BFE8F0[];
extern char lbl_88BFE93C[];
extern char lbl_88BFF3DC[];
extern char lbl_88BFF594[];
extern char lbl_88BFF7F8[];
extern char lbl_88BFFCA4[];
extern char lbl_88C001D8[];
extern char lbl_88C005A0[];
extern char lbl_88C005A4[];
extern char lbl_88C03B60[];
extern char lbl_88C03BA8[];
extern char lbl_88C03C20[];
extern char lbl_88C03CF8[];
extern char lbl_88C03E18[];
extern char lbl_88C03E60[];
extern char lbl_88C03F08[];
extern char lbl_88C040A0[];
extern char lbl_88C04208[];
extern char lbl_88C04310[];
extern char lbl_88C04418[];
extern char lbl_88C04718[];
extern char lbl_88C04838[];
extern char lbl_88C04FA0[];
extern char lbl_88C05048[];
extern char lbl_88C050F0[];
extern char lbl_88C05558[];
extern char lbl_88C05630[];
extern char lbl_88C05720[];
extern char lbl_88C05858[];
extern char lbl_88C05888[];
extern char lbl_88C058B8[];
extern char lbl_88C058E8[];
extern char lbl_88C05960[];
extern char lbl_88C059A8[];
extern char lbl_88C05A20[];
extern char lbl_88C05AF8[];
extern char lbl_88C05BE8[];
extern char lbl_88C05CF0[];
extern char lbl_88C05E58[];
extern char lbl_88C05F00[];
extern char lbl_88C05F78[];
extern char lbl_88C06050[];
extern char lbl_88C060F8[];
extern char lbl_88C06110[];
extern char lbl_88C061D0[];
extern char lbl_88CFCB54[];
extern char lbl_88D01E4C[];
extern char lbl_88D07144[];
extern char lbl_88D0CA0C[];
extern char lbl_88D122D4[];
ts4_word ts4_set_u32_offc_884CE988();
ts4_word fn_88563470();

/* Swing_DLL.xex 0x88A948E0: addr lbl_88BCCD90, u32@lbl_88BC9AEC, u32@0x80 */
void ts4_addr_lbl_88BCCD90_88A948E0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCCD90) + 128) = (ts4_word)(*(ts4_word *)lbl_88BC9AEC);
    return;
}

/* Swing_DLL.xex 0x88A95D20: call_seq lbl_88068FF0, lbl_8806A870, lbl_88CFCB54, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF6B0, fn_88563470 */
ts4_word ts4_call_seq_lbl_88068FF0_88A95D20(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CFCB54, (ts4_word)(ts4_word)lbl_8806A870, (ts4_word)4, (ts4_word)(ts4_word)lbl_88068FF0);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF6B0);
    return t2;
}

/* Swing_DLL.xex 0x88A95DD8: addr lbl_88BD5498, u32@lbl_88BCCF40, u32@0x38 */
void ts4_addr_lbl_88BD5498_88A95DD8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD5498) + 56) = (ts4_word)(*(ts4_word *)lbl_88BCCF40);
    return;
}

/* Swing_DLL.xex 0x88A95F40: addr lbl_88BD54E0, u32@lbl_88BCCFA4, u32@0x8 */
void ts4_addr_lbl_88BD54E0_88A95F40(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD54E0) + 8) = (ts4_word)(*(ts4_word *)lbl_88BCCFA4);
    return;
}

/* Swing_DLL.xex 0x88A966E8: addr lbl_88BD5558, u32@lbl_88BCD384, u32@0x128 */
void ts4_addr_lbl_88BD5558_88A966E8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD5558) + 296) = (ts4_word)(*(ts4_word *)lbl_88BCD384);
    return;
}

/* Swing_DLL.xex 0x88A96868: addr lbl_88BD5690, u32@lbl_88BCD6D0, u32@0x8 */
void ts4_addr_lbl_88BD5690_88A96868(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD5690) + 8) = (ts4_word)(*(ts4_word *)lbl_88BCD6D0);
    return;
}

/* Swing_DLL.xex 0x88A96F38: addr lbl_88BD5798, u32@lbl_88BCDD40, u32@0x68 */
void ts4_addr_lbl_88BD5798_88A96F38(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD5798) + 104) = (ts4_word)(*(ts4_word *)lbl_88BCDD40);
    return;
}

/* Swing_DLL.xex 0x88A970B0: addr lbl_88BD5840, u32@lbl_88BCDE80, u32@0x8 */
void ts4_addr_lbl_88BD5840_88A970B0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD5840) + 8) = (ts4_word)(*(ts4_word *)lbl_88BCDE80);
    return;
}

/* Swing_DLL.xex 0x88A971B8: addr lbl_88BD59D8, u32@lbl_88BCDEB8, u32@0x68 */
void ts4_addr_lbl_88BD59D8_88A971B8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD59D8) + 104) = (ts4_word)(*(ts4_word *)lbl_88BCDEB8);
    return;
}

/* Swing_DLL.xex 0x88A97B60: addr lbl_88BD5AC8, u32@lbl_88BCDED4, u32@0x50 */
void ts4_addr_lbl_88BD5AC8_88A97B60(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD5AC8) + 80) = (ts4_word)(*(ts4_word *)lbl_88BCDED4);
    return;
}

/* Swing_DLL.xex 0x88A988A8: addr lbl_88BD5BD0, u32@lbl_88BCEBE4, u32@0x98 */
void ts4_addr_lbl_88BD5BD0_88A988A8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD5BD0) + 152) = (ts4_word)(*(ts4_word *)lbl_88BCEBE4);
    return;
}

/* Swing_DLL.xex 0x88A989A0: addr lbl_88BD5D98, u32@lbl_88BCF1C0, u32@0x50 */
void ts4_addr_lbl_88BD5D98_88A989A0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD5D98) + 80) = (ts4_word)(*(ts4_word *)lbl_88BCF1C0);
    return;
}

/* Swing_DLL.xex 0x88A98CE8: addr lbl_88BD5EB8, u32@lbl_88BCF1C4, u32@0x20 */
void ts4_addr_lbl_88BD5EB8_88A98CE8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD5EB8) + 32) = (ts4_word)(*(ts4_word *)lbl_88BCF1C4);
    return;
}

/* Swing_DLL.xex 0x88A991D8: addr lbl_88BD5EE8, u32@lbl_88BCF8C0, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88BD5EE8_88A991D8(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88BCF8C0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD5EE8) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD5EE8) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A993B8: addr lbl_88BD5FA8, u32@lbl_88BCF944, u32@0x50 */
void ts4_addr_lbl_88BD5FA8_88A993B8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD5FA8) + 80) = (ts4_word)(*(ts4_word *)lbl_88BCF944);
    return;
}

/* Swing_DLL.xex 0x88A99750: addr lbl_88BD6080, u32@lbl_88BCF9FC, u32@0x20 */
void ts4_addr_lbl_88BD6080_88A99750(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD6080) + 32) = (ts4_word)(*(ts4_word *)lbl_88BCF9FC);
    return;
}

/* Swing_DLL.xex 0x88A997D8: addr lbl_88BD60B0, u32@lbl_88BCF9FC, u32@0x20 */
void ts4_addr_lbl_88BD60B0_88A997D8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD60B0) + 32) = (ts4_word)(*(ts4_word *)lbl_88BCF9FC);
    return;
}

/* Swing_DLL.xex 0x88A998D0: addr lbl_88BD60E0, u32@lbl_88BCF9FC, u32@0x20 */
void ts4_addr_lbl_88BD60E0_88A998D0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD60E0) + 32) = (ts4_word)(*(ts4_word *)lbl_88BCF9FC);
    return;
}

/* Swing_DLL.xex 0x88A99F18: addr lbl_88BD6110, u32@lbl_88BCFF28, u32@0x8 */
void ts4_addr_lbl_88BD6110_88A99F18(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD6110) + 8) = (ts4_word)(*(ts4_word *)lbl_88BCFF28);
    return;
}

/* Swing_DLL.xex 0x88A9A088: addr lbl_88BD6188, u32@lbl_88BD0020, u32@0x20 */
void ts4_addr_lbl_88BD6188_88A9A088(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD6188) + 32) = (ts4_word)(*(ts4_word *)lbl_88BD0020);
    return;
}

/* Swing_DLL.xex 0x88A9A1F0: addr lbl_88BD61D0, u32@lbl_88BD006C, u32@0x8 */
void ts4_addr_lbl_88BD61D0_88A9A1F0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD61D0) + 8) = (ts4_word)(*(ts4_word *)lbl_88BD006C);
    return;
}

/* Swing_DLL.xex 0x88A9AD88: addr lbl_88BD6248, u32@lbl_88BD1048, u32@0x68 */
void ts4_addr_lbl_88BD6248_88A9AD88(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD6248) + 104) = (ts4_word)(*(ts4_word *)lbl_88BD1048);
    return;
}

/* Swing_DLL.xex 0x88A9B7C8: addr lbl_88BD6308, u32@lbl_88BD15D8, u32@0x8 */
void ts4_addr_lbl_88BD6308_88A9B7C8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD6308) + 8) = (ts4_word)(*(ts4_word *)lbl_88BD15D8);
    return;
}

/* Swing_DLL.xex 0x88A9C390: addr lbl_88BD63E0, u32@lbl_88BD19AC, u32@0xb0 */
void ts4_addr_lbl_88BD63E0_88A9C390(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD63E0) + 176) = (ts4_word)(*(ts4_word *)lbl_88BD19AC);
    return;
}

/* Swing_DLL.xex 0x88A9C498: addr lbl_88BD64D0, u32@lbl_88BD2200, u32@0xb0 */
void ts4_addr_lbl_88BD64D0_88A9C498(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD64D0) + 176) = (ts4_word)(*(ts4_word *)lbl_88BD2200);
    return;
}

/* Swing_DLL.xex 0x88A9C750: addr lbl_88BD65C0, u32@lbl_88BD1B98, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88BD65C0_88A9C750(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88BD1B98;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD65C0) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD65C0) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A9C7E8: addr lbl_88BD6728, u32@lbl_88BD2200, u32@0x68 */
void ts4_addr_lbl_88BD6728_88A9C7E8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD6728) + 104) = (ts4_word)(*(ts4_word *)lbl_88BD2200);
    return;
}

/* Swing_DLL.xex 0x88A9C8F0: addr lbl_88BD67D0, u32@lbl_88BD2200, u32@0xc8 */
void ts4_addr_lbl_88BD67D0_88A9C8F0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD67D0) + 200) = (ts4_word)(*(ts4_word *)lbl_88BD2200);
    return;
}

/* Swing_DLL.xex 0x88A9CE78: addr lbl_88BD6908, u32@lbl_88BD2200, u32@0x68 */
void ts4_addr_lbl_88BD6908_88A9CE78(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD6908) + 104) = (ts4_word)(*(ts4_word *)lbl_88BD2200);
    return;
}

/* Swing_DLL.xex 0x88A9D330: addr lbl_88BD6980, u32@lbl_88BD2200, u32@0x20 */
void ts4_addr_lbl_88BD6980_88A9D330(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD6980) + 32) = (ts4_word)(*(ts4_word *)lbl_88BD2200);
    return;
}

/* Swing_DLL.xex 0x88A9D518: addr lbl_88BD6A28, u32@lbl_88BD220C, u32@0x8 */
void ts4_addr_lbl_88BD6A28_88A9D518(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD6A28) + 8) = (ts4_word)(*(ts4_word *)lbl_88BD220C);
    return;
}

/* Swing_DLL.xex 0x88A9DD08: addr lbl_88BD6A40, u32@lbl_88BD225C, u32@0x50 */
void ts4_addr_lbl_88BD6A40_88A9DD08(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD6A40) + 80) = (ts4_word)(*(ts4_word *)lbl_88BD225C);
    return;
}

/* Swing_DLL.xex 0x88A9E500: addr lbl_88BD6AE8, u32@lbl_88BD2A28, u32@0x8 */
void ts4_addr_lbl_88BD6AE8_88A9E500(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD6AE8) + 8) = (ts4_word)(*(ts4_word *)lbl_88BD2A28);
    return;
}

/* Swing_DLL.xex 0x88A9E6D8: addr lbl_88BD6B30, u32@lbl_88BD2AA8, u32@0x68 */
void ts4_addr_lbl_88BD6B30_88A9E6D8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD6B30) + 104) = (ts4_word)(*(ts4_word *)lbl_88BD2AA8);
    return;
}

/* Swing_DLL.xex 0x88A9EB00: addr lbl_88BD6C08, u32@lbl_88BD2C88, u32@0x50 */
void ts4_addr_lbl_88BD6C08_88A9EB00(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD6C08) + 80) = (ts4_word)(*(ts4_word *)lbl_88BD2C88);
    return;
}

/* Swing_DLL.xex 0x88A9F838: addr lbl_88BD6C80, u32@lbl_88BD3334, u32@0x8 */
void ts4_addr_lbl_88BD6C80_88A9F838(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD6C80) + 8) = (ts4_word)(*(ts4_word *)lbl_88BD3334);
    return;
}

/* Swing_DLL.xex 0x88A9F938: addr lbl_88BD6C98, u32@lbl_88BD35F0, u32@0x20 */
void ts4_addr_lbl_88BD6C98_88A9F938(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD6C98) + 32) = (ts4_word)(*(ts4_word *)lbl_88BD35F0);
    return;
}

/* Swing_DLL.xex 0x88A9FFF8: addr lbl_88BD6D10, u32@lbl_88BD39A4, u32@0x8 */
void ts4_addr_lbl_88BD6D10_88A9FFF8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD6D10) + 8) = (ts4_word)(*(ts4_word *)lbl_88BD39A4);
    return;
}

/* Swing_DLL.xex 0x88AA13B0: addr lbl_88BD7190, u32@lbl_88BD4410, u32@0x80 */
void ts4_addr_lbl_88BD7190_88AA13B0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BD7190) + 128) = (ts4_word)(*(ts4_word *)lbl_88BD4410);
    return;
}

/* Swing_DLL.xex 0x88AA27F0: call_seq lbl_8806B030, lbl_8806C8F8, lbl_88D01E4C, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF6C8, fn_88563470 */
ts4_word ts4_call_seq_lbl_8806B030_88AA27F0(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88D01E4C, (ts4_word)(ts4_word)lbl_8806C8F8, (ts4_word)4, (ts4_word)(ts4_word)lbl_8806B030);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF6C8);
    return t2;
}

/* Swing_DLL.xex 0x88AA28A8: addr lbl_88BDF8F8, u32@lbl_88BD7340, u32@0x38 */
void ts4_addr_lbl_88BDF8F8_88AA28A8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BDF8F8) + 56) = (ts4_word)(*(ts4_word *)lbl_88BD7340);
    return;
}

/* Swing_DLL.xex 0x88AA2A10: addr lbl_88BDF940, u32@lbl_88BD73A4, u32@0x8 */
void ts4_addr_lbl_88BDF940_88AA2A10(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BDF940) + 8) = (ts4_word)(*(ts4_word *)lbl_88BD73A4);
    return;
}

/* Swing_DLL.xex 0x88AA31B8: addr lbl_88BDF9B8, u32@lbl_88BD7784, u32@0x128 */
void ts4_addr_lbl_88BDF9B8_88AA31B8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BDF9B8) + 296) = (ts4_word)(*(ts4_word *)lbl_88BD7784);
    return;
}

/* Swing_DLL.xex 0x88AA3338: addr lbl_88BDFAF0, u32@lbl_88BD7AD0, u32@0x8 */
void ts4_addr_lbl_88BDFAF0_88AA3338(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BDFAF0) + 8) = (ts4_word)(*(ts4_word *)lbl_88BD7AD0);
    return;
}

/* Swing_DLL.xex 0x88AA3A08: addr lbl_88BDFBF8, u32@lbl_88BD8140, u32@0x68 */
void ts4_addr_lbl_88BDFBF8_88AA3A08(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BDFBF8) + 104) = (ts4_word)(*(ts4_word *)lbl_88BD8140);
    return;
}

/* Swing_DLL.xex 0x88AA3B80: addr lbl_88BDFCA0, u32@lbl_88BD8280, u32@0x8 */
void ts4_addr_lbl_88BDFCA0_88AA3B80(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BDFCA0) + 8) = (ts4_word)(*(ts4_word *)lbl_88BD8280);
    return;
}

/* Swing_DLL.xex 0x88AA3C88: addr lbl_88BDFE38, u32@lbl_88BD82B8, u32@0x68 */
void ts4_addr_lbl_88BDFE38_88AA3C88(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BDFE38) + 104) = (ts4_word)(*(ts4_word *)lbl_88BD82B8);
    return;
}

/* Swing_DLL.xex 0x88AA4630: addr lbl_88BDFF28, u32@lbl_88BD82D4, u32@0x50 */
void ts4_addr_lbl_88BDFF28_88AA4630(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BDFF28) + 80) = (ts4_word)(*(ts4_word *)lbl_88BD82D4);
    return;
}

/* Swing_DLL.xex 0x88AA5378: addr lbl_88BE0030, u32@lbl_88BD8FE4, u32@0xe0 */
void ts4_addr_lbl_88BE0030_88AA5378(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0030) + 224) = (ts4_word)(*(ts4_word *)lbl_88BD8FE4);
    return;
}

/* Swing_DLL.xex 0x88AA5470: addr lbl_88BE02A0, u32@lbl_88BD9620, u32@0x50 */
void ts4_addr_lbl_88BE02A0_88AA5470(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE02A0) + 80) = (ts4_word)(*(ts4_word *)lbl_88BD9620);
    return;
}

/* Swing_DLL.xex 0x88AA57B8: addr lbl_88BE0408, u32@lbl_88BD9624, u32@0x20 */
void ts4_addr_lbl_88BE0408_88AA57B8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0408) + 32) = (ts4_word)(*(ts4_word *)lbl_88BD9624);
    return;
}

/* Swing_DLL.xex 0x88AA5CA8: addr lbl_88BE0438, u32@lbl_88BD9D20, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88BE0438_88AA5CA8(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88BD9D20;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0438) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0438) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AA5E88: addr lbl_88BE04F8, u32@lbl_88BD9DA4, u32@0x50 */
void ts4_addr_lbl_88BE04F8_88AA5E88(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE04F8) + 80) = (ts4_word)(*(ts4_word *)lbl_88BD9DA4);
    return;
}

/* Swing_DLL.xex 0x88AA6220: addr lbl_88BE05D0, u32@lbl_88BD9E5C, u32@0x20 */
void ts4_addr_lbl_88BE05D0_88AA6220(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE05D0) + 32) = (ts4_word)(*(ts4_word *)lbl_88BD9E5C);
    return;
}

/* Swing_DLL.xex 0x88AA62A8: addr lbl_88BE0600, u32@lbl_88BD9E5C, u32@0x20 */
void ts4_addr_lbl_88BE0600_88AA62A8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0600) + 32) = (ts4_word)(*(ts4_word *)lbl_88BD9E5C);
    return;
}

/* Swing_DLL.xex 0x88AA63A0: addr lbl_88BE0630, u32@lbl_88BD9E5C, u32@0x20 */
void ts4_addr_lbl_88BE0630_88AA63A0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0630) + 32) = (ts4_word)(*(ts4_word *)lbl_88BD9E5C);
    return;
}

/* Swing_DLL.xex 0x88AA69E8: addr lbl_88BE0660, u32@lbl_88BDA388, u32@0x8 */
void ts4_addr_lbl_88BE0660_88AA69E8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0660) + 8) = (ts4_word)(*(ts4_word *)lbl_88BDA388);
    return;
}

/* Swing_DLL.xex 0x88AA6B58: addr lbl_88BE06D8, u32@lbl_88BDA480, u32@0x20 */
void ts4_addr_lbl_88BE06D8_88AA6B58(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE06D8) + 32) = (ts4_word)(*(ts4_word *)lbl_88BDA480);
    return;
}

/* Swing_DLL.xex 0x88AA6CC0: addr lbl_88BE0720, u32@lbl_88BDA4CC, u32@0x8 */
void ts4_addr_lbl_88BE0720_88AA6CC0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0720) + 8) = (ts4_word)(*(ts4_word *)lbl_88BDA4CC);
    return;
}

/* Swing_DLL.xex 0x88AA7858: addr lbl_88BE0798, u32@lbl_88BDB4A8, u32@0x68 */
void ts4_addr_lbl_88BE0798_88AA7858(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0798) + 104) = (ts4_word)(*(ts4_word *)lbl_88BDB4A8);
    return;
}

/* Swing_DLL.xex 0x88AA8298: addr lbl_88BE0858, u32@lbl_88BDBA38, u32@0x8 */
void ts4_addr_lbl_88BE0858_88AA8298(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0858) + 8) = (ts4_word)(*(ts4_word *)lbl_88BDBA38);
    return;
}

/* Swing_DLL.xex 0x88AA8E60: addr lbl_88BE0930, u32@lbl_88BDBE0C, u32@0xb0 */
void ts4_addr_lbl_88BE0930_88AA8E60(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0930) + 176) = (ts4_word)(*(ts4_word *)lbl_88BDBE0C);
    return;
}

/* Swing_DLL.xex 0x88AA8F68: addr lbl_88BE0A20, u32@lbl_88BDC660, u32@0xb0 */
void ts4_addr_lbl_88BE0A20_88AA8F68(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0A20) + 176) = (ts4_word)(*(ts4_word *)lbl_88BDC660);
    return;
}

/* Swing_DLL.xex 0x88AA9220: addr lbl_88BE0B10, u32@lbl_88BDBFF8, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88BE0B10_88AA9220(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88BDBFF8;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0B10) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0B10) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AA92B8: addr lbl_88BE0C78, u32@lbl_88BDC660, u32@0x68 */
void ts4_addr_lbl_88BE0C78_88AA92B8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0C78) + 104) = (ts4_word)(*(ts4_word *)lbl_88BDC660);
    return;
}

/* Swing_DLL.xex 0x88AA93C0: addr lbl_88BE0D20, u32@lbl_88BDC660, u32@0xc8 */
void ts4_addr_lbl_88BE0D20_88AA93C0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0D20) + 200) = (ts4_word)(*(ts4_word *)lbl_88BDC660);
    return;
}

/* Swing_DLL.xex 0x88AA9948: addr lbl_88BE0E58, u32@lbl_88BDC660, u32@0x68 */
void ts4_addr_lbl_88BE0E58_88AA9948(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0E58) + 104) = (ts4_word)(*(ts4_word *)lbl_88BDC660);
    return;
}

/* Swing_DLL.xex 0x88AA9E00: addr lbl_88BE0ED0, u32@lbl_88BDC660, u32@0x20 */
void ts4_addr_lbl_88BE0ED0_88AA9E00(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0ED0) + 32) = (ts4_word)(*(ts4_word *)lbl_88BDC660);
    return;
}

/* Swing_DLL.xex 0x88AA9FE8: addr lbl_88BE0F78, u32@lbl_88BDC66C, u32@0x8 */
void ts4_addr_lbl_88BE0F78_88AA9FE8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0F78) + 8) = (ts4_word)(*(ts4_word *)lbl_88BDC66C);
    return;
}

/* Swing_DLL.xex 0x88AAA7D8: addr lbl_88BE0F90, u32@lbl_88BDC6BC, u32@0x50 */
void ts4_addr_lbl_88BE0F90_88AAA7D8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE0F90) + 80) = (ts4_word)(*(ts4_word *)lbl_88BDC6BC);
    return;
}

/* Swing_DLL.xex 0x88AAAFD0: addr lbl_88BE1038, u32@lbl_88BDCE88, u32@0x8 */
void ts4_addr_lbl_88BE1038_88AAAFD0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE1038) + 8) = (ts4_word)(*(ts4_word *)lbl_88BDCE88);
    return;
}

/* Swing_DLL.xex 0x88AAB1A8: addr lbl_88BE1080, u32@lbl_88BDCF08, u32@0x68 */
void ts4_addr_lbl_88BE1080_88AAB1A8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE1080) + 104) = (ts4_word)(*(ts4_word *)lbl_88BDCF08);
    return;
}

/* Swing_DLL.xex 0x88AAB5D0: addr lbl_88BE1158, u32@lbl_88BDD0E8, u32@0x50 */
void ts4_addr_lbl_88BE1158_88AAB5D0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE1158) + 80) = (ts4_word)(*(ts4_word *)lbl_88BDD0E8);
    return;
}

/* Swing_DLL.xex 0x88AAC308: addr lbl_88BE11D0, u32@lbl_88BDD794, u32@0x8 */
void ts4_addr_lbl_88BE11D0_88AAC308(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE11D0) + 8) = (ts4_word)(*(ts4_word *)lbl_88BDD794);
    return;
}

/* Swing_DLL.xex 0x88AAC408: addr lbl_88BE11E8, u32@lbl_88BDDA50, u32@0x20 */
void ts4_addr_lbl_88BE11E8_88AAC408(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE11E8) + 32) = (ts4_word)(*(ts4_word *)lbl_88BDDA50);
    return;
}

/* Swing_DLL.xex 0x88AACAC8: addr lbl_88BE1260, u32@lbl_88BDDE04, u32@0x8 */
void ts4_addr_lbl_88BE1260_88AACAC8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE1260) + 8) = (ts4_word)(*(ts4_word *)lbl_88BDDE04);
    return;
}

/* Swing_DLL.xex 0x88AADE80: addr lbl_88BE16E0, u32@lbl_88BDE870, u32@0x80 */
void ts4_addr_lbl_88BE16E0_88AADE80(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BE16E0) + 128) = (ts4_word)(*(ts4_word *)lbl_88BDE870);
    return;
}

/* Swing_DLL.xex 0x88AAF2C0: call_seq lbl_8806D1E8, lbl_8806EB08, lbl_88D07144, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF6E0, fn_88563470 */
ts4_word ts4_call_seq_lbl_8806D1E8_88AAF2C0(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88D07144, (ts4_word)(ts4_word)lbl_8806EB08, (ts4_word)4, (ts4_word)(ts4_word)lbl_8806D1E8);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF6E0);
    return t2;
}

/* Swing_DLL.xex 0x88AAF378: addr lbl_88BEAEC0, u32@lbl_88BE1890, u32@0x38 */
void ts4_addr_lbl_88BEAEC0_88AAF378(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEAEC0) + 56) = (ts4_word)(*(ts4_word *)lbl_88BE1890);
    return;
}

/* Swing_DLL.xex 0x88AAF4E0: addr lbl_88BEAF08, u32@lbl_88BE18F4, u32@0x8 */
void ts4_addr_lbl_88BEAF08_88AAF4E0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEAF08) + 8) = (ts4_word)(*(ts4_word *)lbl_88BE18F4);
    return;
}

/* Swing_DLL.xex 0x88AAFE48: addr lbl_88BEAF80, u32@lbl_88BE1DAC, u32@0xc8 */
void ts4_addr_lbl_88BEAF80_88AAFE48(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEAF80) + 200) = (ts4_word)(*(ts4_word *)lbl_88BE1DAC);
    return;
}

/* Swing_DLL.xex 0x88AAFFC8: addr lbl_88BEB058, u32@lbl_88BE2278, u32@0x8 */
void ts4_addr_lbl_88BEB058_88AAFFC8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEB058) + 8) = (ts4_word)(*(ts4_word *)lbl_88BE2278);
    return;
}

/* Swing_DLL.xex 0x88AB0460: addr lbl_88BEB178, u32@lbl_88BE2768, u32@0x38 */
void ts4_addr_lbl_88BEB178_88AB0460(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEB178) + 56) = (ts4_word)(*(ts4_word *)lbl_88BE2768);
    return;
}

/* Swing_DLL.xex 0x88AB06B0: addr lbl_88BEB1C0, u32@lbl_88BE276C, u32@0x68 */
void ts4_addr_lbl_88BEB1C0_88AB06B0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEB1C0) + 104) = (ts4_word)(*(ts4_word *)lbl_88BE276C);
    return;
}

/* Swing_DLL.xex 0x88AB0828: addr lbl_88BEB268, u32@lbl_88BE2894, u32@0x8 */
void ts4_addr_lbl_88BEB268_88AB0828(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEB268) + 8) = (ts4_word)(*(ts4_word *)lbl_88BE2894);
    return;
}

/* Swing_DLL.xex 0x88AB0930: addr lbl_88BEB490, u32@lbl_88BE2A7C, u32@0x68 */
void ts4_addr_lbl_88BEB490_88AB0930(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEB490) + 104) = (ts4_word)(*(ts4_word *)lbl_88BE2A7C);
    return;
}

/* Swing_DLL.xex 0x88AB12E8: addr lbl_88BEB580, u32@lbl_88BE3368, u32@0x50 */
void ts4_addr_lbl_88BEB580_88AB12E8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEB580) + 80) = (ts4_word)(*(ts4_word *)lbl_88BE3368);
    return;
}

/* Swing_DLL.xex 0x88AB1F60: addr lbl_88BEB688, u32@lbl_88BE3B3C, u32@0xe0 */
void ts4_addr_lbl_88BEB688_88AB1F60(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEB688) + 224) = (ts4_word)(*(ts4_word *)lbl_88BE3B3C);
    return;
}

/* Swing_DLL.xex 0x88AB2138: addr lbl_88BEB790, u32@lbl_88BE3B38, u32@0xe0 */
void ts4_addr_lbl_88BEB790_88AB2138(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEB790) + 224) = (ts4_word)(*(ts4_word *)lbl_88BE3B38);
    return;
}

/* Swing_DLL.xex 0x88AB2260: addr lbl_88BEBA90, u32@lbl_88BE3D30, u32@0x50 */
void ts4_addr_lbl_88BEBA90_88AB2260(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEBA90) + 80) = (ts4_word)(*(ts4_word *)lbl_88BE3D30);
    return;
}

/* Swing_DLL.xex 0x88AB25A8: addr lbl_88BEBBB0, u32@lbl_88BE3D34, u32@0x20 */
void ts4_addr_lbl_88BEBBB0_88AB25A8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEBBB0) + 32) = (ts4_word)(*(ts4_word *)lbl_88BE3D34);
    return;
}

/* Swing_DLL.xex 0x88AB3188: addr lbl_88BEC2D0, u32@lbl_88BE4D58, u32@0x80 */
void ts4_addr_lbl_88BEC2D0_88AB3188(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEC2D0) + 128) = (ts4_word)(*(ts4_word *)lbl_88BE4D58);
    return;
}

/* Swing_DLL.xex 0x88AB3290: addr lbl_88BEC378, u32@lbl_88BE4D5C, u32@0x50 */
void ts4_addr_lbl_88BEC378_88AB3290(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEC378) + 80) = (ts4_word)(*(ts4_word *)lbl_88BE4D5C);
    return;
}

/* Swing_DLL.xex 0x88AB3410: addr lbl_88BEC420, u32@lbl_88BE4F28, u32@0x38 */
void ts4_addr_lbl_88BEC420_88AB3410(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEC420) + 56) = (ts4_word)(*(ts4_word *)lbl_88BE4F28);
    return;
}

/* Swing_DLL.xex 0x88AB3B90: addr lbl_88BEC888, u32@lbl_88BE5548, u32@0x50 */
void ts4_addr_lbl_88BEC888_88AB3B90(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEC888) + 80) = (ts4_word)(*(ts4_word *)lbl_88BE5548);
    return;
}

/* Swing_DLL.xex 0x88AB3CF0: addr lbl_88BEC960, u32@lbl_88BE5580, u32@0xc8 */
void ts4_addr_lbl_88BEC960_88AB3CF0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEC960) + 200) = (ts4_word)(*(ts4_word *)lbl_88BE5580);
    return;
}

/* Swing_DLL.xex 0x88AB3DE8: addr lbl_88BECA50, u32@lbl_88BE5584, u32@0x50 */
void ts4_addr_lbl_88BECA50_88AB3DE8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BECA50) + 80) = (ts4_word)(*(ts4_word *)lbl_88BE5584);
    return;
}

/* Swing_DLL.xex 0x88AB4288: addr lbl_88BECB88, u32@lbl_88BE571C, u32@0x20 */
void ts4_addr_lbl_88BECB88_88AB4288(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BECB88) + 32) = (ts4_word)(*(ts4_word *)lbl_88BE571C);
    return;
}

/* Swing_DLL.xex 0x88AB4310: addr lbl_88BECBB8, u32@lbl_88BE571C, u32@0x20 */
void ts4_addr_lbl_88BECBB8_88AB4310(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BECBB8) + 32) = (ts4_word)(*(ts4_word *)lbl_88BE571C);
    return;
}

/* Swing_DLL.xex 0x88AB4408: addr lbl_88BECBE8, u32@lbl_88BE571C, u32@0x20 */
void ts4_addr_lbl_88BECBE8_88AB4408(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BECBE8) + 32) = (ts4_word)(*(ts4_word *)lbl_88BE571C);
    return;
}

/* Swing_DLL.xex 0x88AB4A50: addr lbl_88BECC18, u32@lbl_88BE5B88, u32@0x8 */
void ts4_addr_lbl_88BECC18_88AB4A50(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BECC18) + 8) = (ts4_word)(*(ts4_word *)lbl_88BE5B88);
    return;
}

/* Swing_DLL.xex 0x88AB4BC0: addr lbl_88BECC90, u32@lbl_88BE5C80, u32@0x20 */
void ts4_addr_lbl_88BECC90_88AB4BC0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BECC90) + 32) = (ts4_word)(*(ts4_word *)lbl_88BE5C80);
    return;
}

/* Swing_DLL.xex 0x88AB4D28: addr lbl_88BECCD8, u32@lbl_88BE5CCC, u32@0x8 */
void ts4_addr_lbl_88BECCD8_88AB4D28(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BECCD8) + 8) = (ts4_word)(*(ts4_word *)lbl_88BE5CCC);
    return;
}

/* Swing_DLL.xex 0x88AB5A08: addr lbl_88BECD50, u32@lbl_88BE676C, u32@0x8 */
void ts4_addr_lbl_88BECD50_88AB5A08(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BECD50) + 8) = (ts4_word)(*(ts4_word *)lbl_88BE676C);
    return;
}

/* Swing_DLL.xex 0x88AB6058: addr lbl_88BECE28, u32@lbl_88BE6924, u32@0xb0 */
void ts4_addr_lbl_88BECE28_88AB6058(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BECE28) + 176) = (ts4_word)(*(ts4_word *)lbl_88BE6924);
    return;
}

/* Swing_DLL.xex 0x88AB6160: addr lbl_88BECF18, u32@lbl_88BE7034, u32@0xb0 */
void ts4_addr_lbl_88BECF18_88AB6160(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BECF18) + 176) = (ts4_word)(*(ts4_word *)lbl_88BE7034);
    return;
}

/* Swing_DLL.xex 0x88AB63B0: addr lbl_88BED008, u32@lbl_88BE6B88, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88BED008_88AB63B0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88BE6B88;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BED008) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BED008) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AB6448: addr lbl_88BED170, u32@lbl_88BE7034, u32@0x68 */
void ts4_addr_lbl_88BED170_88AB6448(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BED170) + 104) = (ts4_word)(*(ts4_word *)lbl_88BE7034);
    return;
}

/* Swing_DLL.xex 0x88AB6548: addr lbl_88BED218, u32@lbl_88BE7034, u32@0x68 */
void ts4_addr_lbl_88BED218_88AB6548(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BED218) + 104) = (ts4_word)(*(ts4_word *)lbl_88BE7034);
    return;
}

/* Swing_DLL.xex 0x88AB6988: addr lbl_88BED290, u32@lbl_88BE7034, u32@0x68 */
void ts4_addr_lbl_88BED290_88AB6988(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BED290) + 104) = (ts4_word)(*(ts4_word *)lbl_88BE7034);
    return;
}

/* Swing_DLL.xex 0x88AB7010: addr lbl_88BED368, u32@lbl_88BE7034, u32@0x20 */
void ts4_addr_lbl_88BED368_88AB7010(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BED368) + 32) = (ts4_word)(*(ts4_word *)lbl_88BE7034);
    return;
}

/* Swing_DLL.xex 0x88AB7830: addr lbl_88BED410, u32@lbl_88BE7550, u32@0x8 */
void ts4_addr_lbl_88BED410_88AB7830(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BED410) + 8) = (ts4_word)(*(ts4_word *)lbl_88BE7550);
    return;
}

/* Swing_DLL.xex 0x88AB8020: addr lbl_88BED428, u32@lbl_88BE7900, u32@0x50 */
void ts4_addr_lbl_88BED428_88AB8020(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BED428) + 80) = (ts4_word)(*(ts4_word *)lbl_88BE7900);
    return;
}

/* Swing_DLL.xex 0x88AB8818: addr lbl_88BED4D0, u32@lbl_88BE7904, u32@0x8 */
void ts4_addr_lbl_88BED4D0_88AB8818(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BED4D0) + 8) = (ts4_word)(*(ts4_word *)lbl_88BE7904);
    return;
}

/* Swing_DLL.xex 0x88AB89F0: addr lbl_88BED518, u32@lbl_88BE7E34, u32@0x68 */
void ts4_addr_lbl_88BED518_88AB89F0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BED518) + 104) = (ts4_word)(*(ts4_word *)lbl_88BE7E34);
    return;
}

/* Swing_DLL.xex 0x88AB8E18: addr lbl_88BED5F0, u32@lbl_88BE7EF4, u32@0x50 */
void ts4_addr_lbl_88BED5F0_88AB8E18(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BED5F0) + 80) = (ts4_word)(*(ts4_word *)lbl_88BE7EF4);
    return;
}

/* Swing_DLL.xex 0x88AB9C38: addr lbl_88BED668, u32@lbl_88BE8990, u32@0x8 */
void ts4_addr_lbl_88BED668_88AB9C38(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BED668) + 8) = (ts4_word)(*(ts4_word *)lbl_88BE8990);
    return;
}

/* Swing_DLL.xex 0x88AB9D38: addr lbl_88BED680, u32@lbl_88BE89C4, u32@0x20 */
void ts4_addr_lbl_88BED680_88AB9D38(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BED680) + 32) = (ts4_word)(*(ts4_word *)lbl_88BE89C4);
    return;
}

/* Swing_DLL.xex 0x88ABA468: addr lbl_88BED6F8, u32@lbl_88BE8E38, u32@0x8 */
void ts4_addr_lbl_88BED6F8_88ABA468(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BED6F8) + 8) = (ts4_word)(*(ts4_word *)lbl_88BE8E38);
    return;
}

/* Swing_DLL.xex 0x88ABBA08: addr lbl_88BEDC68, u32@lbl_88BE96D4, u32@0x80 */
void ts4_addr_lbl_88BEDC68_88ABBA08(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BEDC68) + 128) = (ts4_word)(*(ts4_word *)lbl_88BE96D4);
    return;
}

/* Swing_DLL.xex 0x88ABCDD0: call_seq lbl_88070ED8, lbl_88072F40, lbl_88D0CA0C, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF6F8, fn_88563470 */
ts4_word ts4_call_seq_lbl_88070ED8_88ABCDD0(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88D0CA0C, (ts4_word)(ts4_word)lbl_88072F40, (ts4_word)5, (ts4_word)(ts4_word)lbl_88070ED8);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF6F8);
    return t2;
}

/* Swing_DLL.xex 0x88ABCE88: addr lbl_88BF73F0, u32@lbl_88BEDE18, u32@0x38 */
void ts4_addr_lbl_88BF73F0_88ABCE88(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF73F0) + 56) = (ts4_word)(*(ts4_word *)lbl_88BEDE18);
    return;
}

/* Swing_DLL.xex 0x88ABCFF0: addr lbl_88BF7438, u32@lbl_88BEDE7C, u32@0x8 */
void ts4_addr_lbl_88BF7438_88ABCFF0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF7438) + 8) = (ts4_word)(*(ts4_word *)lbl_88BEDE7C);
    return;
}

/* Swing_DLL.xex 0x88ABD958: addr lbl_88BF74B0, u32@lbl_88BEE334, u32@0xc8 */
void ts4_addr_lbl_88BF74B0_88ABD958(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF74B0) + 200) = (ts4_word)(*(ts4_word *)lbl_88BEE334);
    return;
}

/* Swing_DLL.xex 0x88ABD9E8: addr lbl_88BF7588, u32@lbl_88BEE778, u32@0x8 */
void ts4_addr_lbl_88BF7588_88ABD9E8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF7588) + 8) = (ts4_word)(*(ts4_word *)lbl_88BEE778);
    return;
}

/* Swing_DLL.xex 0x88ABDFE8: addr lbl_88BF76A8, u32@lbl_88BEEDB8, u32@0x38 */
void ts4_addr_lbl_88BF76A8_88ABDFE8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF76A8) + 56) = (ts4_word)(*(ts4_word *)lbl_88BEEDB8);
    return;
}

/* Swing_DLL.xex 0x88ABE238: addr lbl_88BF76F0, u32@lbl_88BEEDBC, u32@0x68 */
void ts4_addr_lbl_88BF76F0_88ABE238(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF76F0) + 104) = (ts4_word)(*(ts4_word *)lbl_88BEEDBC);
    return;
}

/* Swing_DLL.xex 0x88ABE3B0: addr lbl_88BF7798, u32@lbl_88BEEEE4, u32@0x8 */
void ts4_addr_lbl_88BF7798_88ABE3B0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF7798) + 8) = (ts4_word)(*(ts4_word *)lbl_88BEEEE4);
    return;
}

/* Swing_DLL.xex 0x88ABE4B8: addr lbl_88BF7930, u32@lbl_88BEF0CC, u32@0xc8 */
void ts4_addr_lbl_88BF7930_88ABE4B8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF7930) + 200) = (ts4_word)(*(ts4_word *)lbl_88BEF0CC);
    return;
}

/* Swing_DLL.xex 0x88ABEF60: addr lbl_88BF7A80, u32@lbl_88BEFA30, u32@0x50 */
void ts4_addr_lbl_88BF7A80_88ABEF60(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF7A80) + 80) = (ts4_word)(*(ts4_word *)lbl_88BEFA30);
    return;
}

/* Swing_DLL.xex 0x88ABFAE8: addr lbl_88BF7B88, u32@lbl_88BF0144, u32@0xe0 */
void ts4_addr_lbl_88BF7B88_88ABFAE8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF7B88) + 224) = (ts4_word)(*(ts4_word *)lbl_88BF0144);
    return;
}

/* Swing_DLL.xex 0x88ABFCC0: addr lbl_88BF7C90, u32@lbl_88BF0140, u32@0xe0 */
void ts4_addr_lbl_88BF7C90_88ABFCC0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF7C90) + 224) = (ts4_word)(*(ts4_word *)lbl_88BF0140);
    return;
}

/* Swing_DLL.xex 0x88ABFDE8: addr lbl_88BF7F90, u32@lbl_88BF0338, u32@0x50 */
void ts4_addr_lbl_88BF7F90_88ABFDE8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF7F90) + 80) = (ts4_word)(*(ts4_word *)lbl_88BF0338);
    return;
}

/* Swing_DLL.xex 0x88ABFFE0: addr lbl_88BF80B0, u32@lbl_88BF033C, u32@0x20 */
void ts4_addr_lbl_88BF80B0_88ABFFE0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF80B0) + 32) = (ts4_word)(*(ts4_word *)lbl_88BF033C);
    return;
}

/* Swing_DLL.xex 0x88AC0C98: addr lbl_88BF8818, u32@lbl_88BF1270, u32@0x80 */
void ts4_addr_lbl_88BF8818_88AC0C98(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF8818) + 128) = (ts4_word)(*(ts4_word *)lbl_88BF1270);
    return;
}

/* Swing_DLL.xex 0x88AC0DA0: addr lbl_88BF88C0, u32@lbl_88BF1274, u32@0x50 */
void ts4_addr_lbl_88BF88C0_88AC0DA0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF88C0) + 80) = (ts4_word)(*(ts4_word *)lbl_88BF1274);
    return;
}

/* Swing_DLL.xex 0x88AC0F20: addr lbl_88BF8968, u32@lbl_88BF1440, u32@0x38 */
void ts4_addr_lbl_88BF8968_88AC0F20(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF8968) + 56) = (ts4_word)(*(ts4_word *)lbl_88BF1440);
    return;
}

/* Swing_DLL.xex 0x88AC16A0: addr lbl_88BF8DD0, u32@lbl_88BF1A60, u32@0x50 */
void ts4_addr_lbl_88BF8DD0_88AC16A0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF8DD0) + 80) = (ts4_word)(*(ts4_word *)lbl_88BF1A60);
    return;
}

/* Swing_DLL.xex 0x88AC1800: addr lbl_88BF8EA8, u32@lbl_88BF1A98, u32@0xc8 */
void ts4_addr_lbl_88BF8EA8_88AC1800(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF8EA8) + 200) = (ts4_word)(*(ts4_word *)lbl_88BF1A98);
    return;
}

/* Swing_DLL.xex 0x88AC18F8: addr lbl_88BF8F98, u32@lbl_88BF1A9C, u32@0x50 */
void ts4_addr_lbl_88BF8F98_88AC18F8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF8F98) + 80) = (ts4_word)(*(ts4_word *)lbl_88BF1A9C);
    return;
}

/* Swing_DLL.xex 0x88AC1D98: addr lbl_88BF90D0, u32@lbl_88BF1D98, u32@0x20 */
void ts4_addr_lbl_88BF90D0_88AC1D98(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF90D0) + 32) = (ts4_word)(*(ts4_word *)lbl_88BF1D98);
    return;
}

/* Swing_DLL.xex 0x88AC1E20: addr lbl_88BF9100, u32@lbl_88BF1D98, u32@0x20 */
void ts4_addr_lbl_88BF9100_88AC1E20(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF9100) + 32) = (ts4_word)(*(ts4_word *)lbl_88BF1D98);
    return;
}

/* Swing_DLL.xex 0x88AC1F18: addr lbl_88BF9130, u32@lbl_88BF1D98, u32@0x20 */
void ts4_addr_lbl_88BF9130_88AC1F18(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF9130) + 32) = (ts4_word)(*(ts4_word *)lbl_88BF1D98);
    return;
}

/* Swing_DLL.xex 0x88AC2560: addr lbl_88BF9160, u32@lbl_88BF1ED4, u32@0x8 */
void ts4_addr_lbl_88BF9160_88AC2560(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF9160) + 8) = (ts4_word)(*(ts4_word *)lbl_88BF1ED4);
    return;
}

/* Swing_DLL.xex 0x88AC26D0: addr lbl_88BF91D8, u32@lbl_88BF20D4, u32@0x20 */
void ts4_addr_lbl_88BF91D8_88AC26D0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF91D8) + 32) = (ts4_word)(*(ts4_word *)lbl_88BF20D4);
    return;
}

/* Swing_DLL.xex 0x88AC2838: addr lbl_88BF9220, u32@lbl_88BF21E0, u32@0x8 */
void ts4_addr_lbl_88BF9220_88AC2838(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF9220) + 8) = (ts4_word)(*(ts4_word *)lbl_88BF21E0);
    return;
}

/* Swing_DLL.xex 0x88AC3518: addr lbl_88BF9298, u32@lbl_88BF2E30, u32@0x8 */
void ts4_addr_lbl_88BF9298_88AC3518(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF9298) + 8) = (ts4_word)(*(ts4_word *)lbl_88BF2E30);
    return;
}

/* Swing_DLL.xex 0x88AC3B68: addr lbl_88BF9370, u32@lbl_88BF2F40, u32@0xb0 */
void ts4_addr_lbl_88BF9370_88AC3B68(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF9370) + 176) = (ts4_word)(*(ts4_word *)lbl_88BF2F40);
    return;
}

/* Swing_DLL.xex 0x88AC3C70: addr lbl_88BF9460, u32@lbl_88BF3A70, u32@0xb0 */
void ts4_addr_lbl_88BF9460_88AC3C70(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF9460) + 176) = (ts4_word)(*(ts4_word *)lbl_88BF3A70);
    return;
}

/* Swing_DLL.xex 0x88AC3EC0: addr lbl_88BF9568, u32@lbl_88BF2F4C, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88BF9568_88AC3EC0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88BF2F4C;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF9568) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF9568) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AC3F58: addr lbl_88BF96D0, u32@lbl_88BF3A70, u32@0x68 */
void ts4_addr_lbl_88BF96D0_88AC3F58(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF96D0) + 104) = (ts4_word)(*(ts4_word *)lbl_88BF3A70);
    return;
}

/* Swing_DLL.xex 0x88AC4058: addr lbl_88BF9778, u32@lbl_88BF3A70, u32@0x68 */
void ts4_addr_lbl_88BF9778_88AC4058(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF9778) + 104) = (ts4_word)(*(ts4_word *)lbl_88BF3A70);
    return;
}

/* Swing_DLL.xex 0x88AC4498: addr lbl_88BF97F0, u32@lbl_88BF3A70, u32@0x68 */
void ts4_addr_lbl_88BF97F0_88AC4498(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF97F0) + 104) = (ts4_word)(*(ts4_word *)lbl_88BF3A70);
    return;
}

/* Swing_DLL.xex 0x88AC4B20: addr lbl_88BF98C8, u32@lbl_88BF3A70, u32@0x20 */
void ts4_addr_lbl_88BF98C8_88AC4B20(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF98C8) + 32) = (ts4_word)(*(ts4_word *)lbl_88BF3A70);
    return;
}

/* Swing_DLL.xex 0x88AC5340: addr lbl_88BF9970, u32@lbl_88BF3A7C, u32@0x8 */
void ts4_addr_lbl_88BF9970_88AC5340(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF9970) + 8) = (ts4_word)(*(ts4_word *)lbl_88BF3A7C);
    return;
}

/* Swing_DLL.xex 0x88AC5B30: addr lbl_88BF9988, u32@lbl_88BF3ACC, u32@0x50 */
void ts4_addr_lbl_88BF9988_88AC5B30(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF9988) + 80) = (ts4_word)(*(ts4_word *)lbl_88BF3ACC);
    return;
}

/* Swing_DLL.xex 0x88AC6328: addr lbl_88BF9A48, u32@lbl_88BF42E0, u32@0x8 */
void ts4_addr_lbl_88BF9A48_88AC6328(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF9A48) + 8) = (ts4_word)(*(ts4_word *)lbl_88BF42E0);
    return;
}

/* Swing_DLL.xex 0x88AC6500: addr lbl_88BF9A90, u32@lbl_88BF4360, u32@0x68 */
void ts4_addr_lbl_88BF9A90_88AC6500(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF9A90) + 104) = (ts4_word)(*(ts4_word *)lbl_88BF4360);
    return;
}

/* Swing_DLL.xex 0x88AC6928: addr lbl_88BF9B68, u32@lbl_88BF4540, u32@0x50 */
void ts4_addr_lbl_88BF9B68_88AC6928(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF9B68) + 80) = (ts4_word)(*(ts4_word *)lbl_88BF4540);
    return;
}

/* Swing_DLL.xex 0x88AC7748: addr lbl_88BF9BE0, u32@lbl_88BF4C34, u32@0x8 */
void ts4_addr_lbl_88BF9BE0_88AC7748(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF9BE0) + 8) = (ts4_word)(*(ts4_word *)lbl_88BF4C34);
    return;
}

/* Swing_DLL.xex 0x88AC7848: addr lbl_88BF9BF8, u32@lbl_88BF4EF0, u32@0x20 */
void ts4_addr_lbl_88BF9BF8_88AC7848(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF9BF8) + 32) = (ts4_word)(*(ts4_word *)lbl_88BF4EF0);
    return;
}

/* Swing_DLL.xex 0x88AC7F78: addr lbl_88BF9C70, u32@lbl_88BF52BC, u32@0x8 */
void ts4_addr_lbl_88BF9C70_88AC7F78(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BF9C70) + 8) = (ts4_word)(*(ts4_word *)lbl_88BF52BC);
    return;
}

/* Swing_DLL.xex 0x88AC9518: addr lbl_88BFA1E0, u32@lbl_88BF63F8, u32@0x80 */
void ts4_addr_lbl_88BFA1E0_88AC9518(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BFA1E0) + 128) = (ts4_word)(*(ts4_word *)lbl_88BF63F8);
    return;
}

/* Swing_DLL.xex 0x88ACA8E0: call_seq lbl_88074190, lbl_880763D8, lbl_88D122D4, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF710, fn_88563470 */
ts4_word ts4_call_seq_lbl_88074190_88ACA8E0(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88D122D4, (ts4_word)(ts4_word)lbl_880763D8, (ts4_word)5, (ts4_word)(ts4_word)lbl_88074190);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF710);
    return t2;
}

/* Swing_DLL.xex 0x88ACA998: addr lbl_88C03B60, u32@lbl_88BFA3A8, u32@0x38 */
void ts4_addr_lbl_88C03B60_88ACA998(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C03B60) + 56) = (ts4_word)(*(ts4_word *)lbl_88BFA3A8);
    return;
}

/* Swing_DLL.xex 0x88ACAB00: addr lbl_88C03BA8, u32@lbl_88BFA40C, u32@0x8 */
void ts4_addr_lbl_88C03BA8_88ACAB00(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C03BA8) + 8) = (ts4_word)(*(ts4_word *)lbl_88BFA40C);
    return;
}

/* Swing_DLL.xex 0x88ACB468: addr lbl_88C03C20, u32@lbl_88BFA8C4, u32@0xc8 */
void ts4_addr_lbl_88C03C20_88ACB468(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C03C20) + 200) = (ts4_word)(*(ts4_word *)lbl_88BFA8C4);
    return;
}

/* Swing_DLL.xex 0x88ACB4F8: addr lbl_88C03CF8, u32@lbl_88BFAD08, u32@0x8 */
void ts4_addr_lbl_88C03CF8_88ACB4F8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C03CF8) + 8) = (ts4_word)(*(ts4_word *)lbl_88BFAD08);
    return;
}

/* Swing_DLL.xex 0x88ACBAF8: addr lbl_88C03E18, u32@lbl_88BFB348, u32@0x38 */
void ts4_addr_lbl_88C03E18_88ACBAF8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C03E18) + 56) = (ts4_word)(*(ts4_word *)lbl_88BFB348);
    return;
}

/* Swing_DLL.xex 0x88ACBD48: addr lbl_88C03E60, u32@lbl_88BFB34C, u32@0x68 */
void ts4_addr_lbl_88C03E60_88ACBD48(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C03E60) + 104) = (ts4_word)(*(ts4_word *)lbl_88BFB34C);
    return;
}

/* Swing_DLL.xex 0x88ACBEC0: addr lbl_88C03F08, u32@lbl_88BFB474, u32@0x8 */
void ts4_addr_lbl_88C03F08_88ACBEC0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C03F08) + 8) = (ts4_word)(*(ts4_word *)lbl_88BFB474);
    return;
}

/* Swing_DLL.xex 0x88ACBFC8: addr lbl_88C040A0, u32@lbl_88BFB674, u32@0xe0 */
void ts4_addr_lbl_88C040A0_88ACBFC8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C040A0) + 224) = (ts4_word)(*(ts4_word *)lbl_88BFB674);
    return;
}

/* Swing_DLL.xex 0x88ACCB60: addr lbl_88C04208, u32@lbl_88BFC158, u32@0x50 */
void ts4_addr_lbl_88C04208_88ACCB60(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C04208) + 80) = (ts4_word)(*(ts4_word *)lbl_88BFC158);
    return;
}

/* Swing_DLL.xex 0x88ACD6E8: addr lbl_88C04310, u32@lbl_88BFC86C, u32@0xe0 */
void ts4_addr_lbl_88C04310_88ACD6E8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C04310) + 224) = (ts4_word)(*(ts4_word *)lbl_88BFC86C);
    return;
}

/* Swing_DLL.xex 0x88ACD8C0: addr lbl_88C04418, u32@lbl_88BFC868, u32@0xe0 */
void ts4_addr_lbl_88C04418_88ACD8C0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C04418) + 224) = (ts4_word)(*(ts4_word *)lbl_88BFC868);
    return;
}

/* Swing_DLL.xex 0x88ACD9E8: addr lbl_88C04718, u32@lbl_88BFCA60, u32@0x50 */
void ts4_addr_lbl_88C04718_88ACD9E8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C04718) + 80) = (ts4_word)(*(ts4_word *)lbl_88BFCA60);
    return;
}

/* Swing_DLL.xex 0x88ACDBE0: addr lbl_88C04838, u32@lbl_88BFCBE8, u32@0x20 */
void ts4_addr_lbl_88C04838_88ACDBE0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C04838) + 32) = (ts4_word)(*(ts4_word *)lbl_88BFCBE8);
    return;
}

/* Swing_DLL.xex 0x88ACE910: addr lbl_88C04FA0, u32@lbl_88BFD57C, u32@0x80 */
void ts4_addr_lbl_88C04FA0_88ACE910(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C04FA0) + 128) = (ts4_word)(*(ts4_word *)lbl_88BFD57C);
    return;
}

/* Swing_DLL.xex 0x88ACEA18: addr lbl_88C05048, u32@lbl_88BFDA48, u32@0x50 */
void ts4_addr_lbl_88C05048_88ACEA18(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C05048) + 80) = (ts4_word)(*(ts4_word *)lbl_88BFDA48);
    return;
}

/* Swing_DLL.xex 0x88ACEB98: addr lbl_88C050F0, u32@lbl_88BFDA4C, u32@0x38 */
void ts4_addr_lbl_88C050F0_88ACEB98(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C050F0) + 56) = (ts4_word)(*(ts4_word *)lbl_88BFDA4C);
    return;
}

/* Swing_DLL.xex 0x88ACF318: addr lbl_88C05558, u32@lbl_88BFE0B4, u32@0x50 */
void ts4_addr_lbl_88C05558_88ACF318(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C05558) + 80) = (ts4_word)(*(ts4_word *)lbl_88BFE0B4);
    return;
}

/* Swing_DLL.xex 0x88ACF478: addr lbl_88C05630, u32@lbl_88BFE1F4, u32@0xc8 */
void ts4_addr_lbl_88C05630_88ACF478(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C05630) + 200) = (ts4_word)(*(ts4_word *)lbl_88BFE1F4);
    return;
}

/* Swing_DLL.xex 0x88ACF570: addr lbl_88C05720, u32@lbl_88BFE1F8, u32@0x50 */
void ts4_addr_lbl_88C05720_88ACF570(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C05720) + 80) = (ts4_word)(*(ts4_word *)lbl_88BFE1F8);
    return;
}

/* Swing_DLL.xex 0x88ACFA10: addr lbl_88C05858, u32@lbl_88BFE38C, u32@0x20 */
void ts4_addr_lbl_88C05858_88ACFA10(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C05858) + 32) = (ts4_word)(*(ts4_word *)lbl_88BFE38C);
    return;
}

/* Swing_DLL.xex 0x88ACFA98: addr lbl_88C05888, u32@lbl_88BFE38C, u32@0x20 */
void ts4_addr_lbl_88C05888_88ACFA98(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C05888) + 32) = (ts4_word)(*(ts4_word *)lbl_88BFE38C);
    return;
}

/* Swing_DLL.xex 0x88ACFB90: addr lbl_88C058B8, u32@lbl_88BFE38C, u32@0x20 */
void ts4_addr_lbl_88C058B8_88ACFB90(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C058B8) + 32) = (ts4_word)(*(ts4_word *)lbl_88BFE38C);
    return;
}

/* Swing_DLL.xex 0x88AD01D8: addr lbl_88C058E8, u32@lbl_88BFE7F8, u32@0x8 */
void ts4_addr_lbl_88C058E8_88AD01D8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C058E8) + 8) = (ts4_word)(*(ts4_word *)lbl_88BFE7F8);
    return;
}

/* Swing_DLL.xex 0x88AD0348: addr lbl_88C05960, u32@lbl_88BFE8F0, u32@0x20 */
void ts4_addr_lbl_88C05960_88AD0348(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C05960) + 32) = (ts4_word)(*(ts4_word *)lbl_88BFE8F0);
    return;
}

/* Swing_DLL.xex 0x88AD04B0: addr lbl_88C059A8, u32@lbl_88BFE93C, u32@0x8 */
void ts4_addr_lbl_88C059A8_88AD04B0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C059A8) + 8) = (ts4_word)(*(ts4_word *)lbl_88BFE93C);
    return;
}

/* Swing_DLL.xex 0x88AD1190: addr lbl_88C05A20, u32@lbl_88BFF3DC, u32@0x8 */
void ts4_addr_lbl_88C05A20_88AD1190(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C05A20) + 8) = (ts4_word)(*(ts4_word *)lbl_88BFF3DC);
    return;
}

/* Swing_DLL.xex 0x88AD17E0: addr lbl_88C05AF8, u32@lbl_88BFF594, u32@0xb0 */
void ts4_addr_lbl_88C05AF8_88AD17E0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C05AF8) + 176) = (ts4_word)(*(ts4_word *)lbl_88BFF594);
    return;
}

/* Swing_DLL.xex 0x88AD18E8: addr lbl_88C05BE8, u32@lbl_88BFFCA4, u32@0xb0 */
void ts4_addr_lbl_88C05BE8_88AD18E8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C05BE8) + 176) = (ts4_word)(*(ts4_word *)lbl_88BFFCA4);
    return;
}

/* Swing_DLL.xex 0x88AD1B38: addr lbl_88C05CF0, u32@lbl_88BFF7F8, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88C05CF0_88AD1B38(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88BFF7F8;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C05CF0) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C05CF0) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88AD1BD0: addr lbl_88C05E58, u32@lbl_88BFFCA4, u32@0x68 */
void ts4_addr_lbl_88C05E58_88AD1BD0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C05E58) + 104) = (ts4_word)(*(ts4_word *)lbl_88BFFCA4);
    return;
}

/* Swing_DLL.xex 0x88AD1CD0: addr lbl_88C05F00, u32@lbl_88BFFCA4, u32@0x68 */
void ts4_addr_lbl_88C05F00_88AD1CD0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C05F00) + 104) = (ts4_word)(*(ts4_word *)lbl_88BFFCA4);
    return;
}

/* Swing_DLL.xex 0x88AD2110: addr lbl_88C05F78, u32@lbl_88BFFCA4, u32@0x68 */
void ts4_addr_lbl_88C05F78_88AD2110(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C05F78) + 104) = (ts4_word)(*(ts4_word *)lbl_88BFFCA4);
    return;
}

/* Swing_DLL.xex 0x88AD2798: addr lbl_88C06050, u32@lbl_88BFFCA4, u32@0x20 */
void ts4_addr_lbl_88C06050_88AD2798(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C06050) + 32) = (ts4_word)(*(ts4_word *)lbl_88BFFCA4);
    return;
}

/* Swing_DLL.xex 0x88AD2FB8: addr lbl_88C060F8, u32@lbl_88C001D8, u32@0x8 */
void ts4_addr_lbl_88C060F8_88AD2FB8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C060F8) + 8) = (ts4_word)(*(ts4_word *)lbl_88C001D8);
    return;
}

/* Swing_DLL.xex 0x88AD37A8: addr lbl_88C06110, u32@lbl_88C005A0, u32@0x50 */
void ts4_addr_lbl_88C06110_88AD37A8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C06110) + 80) = (ts4_word)(*(ts4_word *)lbl_88C005A0);
    return;
}

/* Swing_DLL.xex 0x88AD3FA0: addr lbl_88C061D0, u32@lbl_88C005A4, u32@0x8 */
void ts4_addr_lbl_88C061D0_88AD3FA0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C061D0) + 8) = (ts4_word)(*(ts4_word *)lbl_88C005A4);
    return;
}
