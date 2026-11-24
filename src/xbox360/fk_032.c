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

extern char lbl_8803C97C[];
extern char lbl_8803C9DC[];
extern char lbl_8803CAF0[];
extern char lbl_8803CC5C[];
extern char lbl_8803CCC4[];
extern char lbl_8803CCD4[];
extern char lbl_8803D124[];
extern char lbl_8803D194[];
extern char lbl_8803D2E0[];
extern char lbl_8803D484[];
extern char lbl_8803D4A8[];
extern char lbl_8803D4C4[];
extern char lbl_8803D6A0[];
extern char lbl_8803D914[];
extern char lbl_8803D9E8[];
extern char lbl_8803EC3C[];
extern char lbl_8803EC94[];
extern char lbl_8803ECB0[];
extern char lbl_8803ECD0[];
extern char lbl_8803ECF4[];
extern char lbl_8803ED14[];
extern char lbl_8803ED20[];
extern char lbl_8803ED28[];
extern char lbl_8803ED40[];
extern char lbl_8803ED58[];
extern char lbl_8803ED7C[];
extern char lbl_8803EE7C[];
extern char lbl_8803EE88[];
extern char lbl_8803EEE8[];
extern char lbl_8803EEFC[];
extern char lbl_8803EF90[];
extern char lbl_8803EF9C[];
extern char lbl_8803EFA8[];
extern char lbl_8803EFC0[];
extern char lbl_8803EFE8[];
extern char lbl_8803F00C[];
extern char lbl_8803F048[];
extern char lbl_8803F064[];
extern char lbl_8803F084[];
extern char lbl_8803F0C8[];
extern char lbl_8803F5BC[];
extern char lbl_8803F5C8[];
extern char lbl_8803F5D4[];
extern char lbl_8803F5E0[];
extern char lbl_8803F610[];
extern char lbl_8803F634[];
extern char lbl_8803F660[];
extern char lbl_8803F690[];
extern char lbl_8803F6B0[];
extern char lbl_8803F6CC[];
extern char lbl_8803F6D8[];
extern char lbl_8803F960[];
extern char lbl_8803F974[];
extern char lbl_8803F988[];
extern char lbl_8803F99C[];
extern char lbl_8803F9B0[];
extern char lbl_8803F9C0[];
extern char lbl_8803F9D4[];
extern char lbl_8803F9E8[];
extern char lbl_8803FA04[];
extern char lbl_8803FA18[];
extern char lbl_8803FBE0[];
extern char lbl_8803FBF4[];
extern char lbl_8803FC80[];
extern char lbl_8803FCA0[];
extern char lbl_8804002C[];
extern char lbl_88040078[];
extern char lbl_880400A8[];
extern char lbl_880400BC[];
extern char lbl_880400D0[];
extern char lbl_880400E8[];
extern char lbl_88040100[];
extern char lbl_88040110[];
extern char lbl_8804011C[];
extern char lbl_88040278[];
extern char lbl_88040290[];
extern char lbl_880402A0[];
extern char lbl_880402B0[];
extern char lbl_880402BC[];
extern char lbl_880402CC[];
extern char lbl_880402E4[];
extern char lbl_88040344[];
extern char lbl_88040364[];
extern char lbl_88040394[];
extern char lbl_880403AC[];
extern char lbl_880403DC[];
extern char lbl_880403FC[];
extern char lbl_88040424[];
extern char lbl_88040508[];
extern char lbl_88040534[];
extern char lbl_88040560[];
extern char lbl_88040590[];
extern char lbl_88040608[];
extern char lbl_88040630[];
extern char lbl_88040DB0[];
extern char lbl_88040E04[];
extern char lbl_88040E18[];
extern char lbl_88040E68[];
extern char lbl_88041284[];
extern char lbl_88041B24[];
extern char lbl_88041DE0[];
extern char lbl_88042170[];
extern char lbl_880422F8[];
extern char lbl_88042318[];
extern char lbl_8804232C[];
extern char lbl_8804233C[];
extern char lbl_8804234C[];
extern char lbl_88042358[];
extern char lbl_88042370[];
extern char lbl_88042380[];
extern char lbl_88042390[];
extern char lbl_880423A4[];
extern char lbl_880423C0[];
extern char lbl_880423D4[];
extern char lbl_880423F8[];
extern char lbl_88042408[];
extern char lbl_88042E48[];
extern char lbl_880433FC[];
extern char lbl_8804342C[];
extern char lbl_88043ED0[];
extern char lbl_88044324[];
extern char lbl_88044370[];
extern char lbl_88045070[];
extern char lbl_88045194[];
extern char lbl_88045224[];
extern char lbl_88045580[];
extern char lbl_880455E0[];
extern char lbl_88045734[];
extern char lbl_880457FC[];
extern char lbl_88045914[];
extern char lbl_880459C0[];
extern char lbl_880459F8[];
extern char lbl_88045A30[];
extern char lbl_88045AA8[];
extern char lbl_88045B24[];
extern char lbl_88045B44[];
extern char lbl_88046220[];
extern char lbl_880462E8[];
extern char lbl_88046320[];
extern char lbl_880463D4[];
extern char lbl_88046454[];
extern char lbl_88046498[];
extern char lbl_88046518[];
extern char lbl_88046574[];
extern char lbl_880466D4[];
extern char lbl_8804671C[];
extern char lbl_8804675C[];
extern char lbl_880467DC[];
extern char lbl_88046868[];
extern char lbl_880468C8[];
extern char lbl_8804690C[];
extern char lbl_8804694C[];
extern char lbl_8804696C[];
extern char lbl_880469C4[];
extern char lbl_88046A18[];
extern char lbl_88046A50[];
extern char lbl_88046A84[];
extern char lbl_88046AB4[];
extern char lbl_88046AE0[];
extern char lbl_88046B60[];
extern char lbl_88046C00[];
extern char lbl_88046C24[];
extern char lbl_88046C48[];
extern char lbl_88046C60[];
extern char lbl_88047050[];
extern char lbl_88047070[];
extern char lbl_8804707C[];
extern char lbl_8804C310[];
extern char lbl_8804C33C[];
extern char lbl_8804C348[];
extern char lbl_8804C358[];
extern char lbl_8804C380[];
extern char lbl_8804C390[];
extern char lbl_8804C3A0[];
extern char lbl_8804C3B0[];
extern char lbl_8804C3C4[];
extern char lbl_8804C3DC[];
extern char lbl_8804C3F8[];
extern char lbl_8804C410[];
extern char lbl_8804C428[];
extern char lbl_8804D824[];
extern char lbl_8804D990[];
extern char lbl_8804D9E4[];
extern char lbl_8804DA08[];
extern char lbl_8804DA78[];
extern char lbl_8804DABC[];
extern char lbl_8804DAF8[];
extern char lbl_8804DB34[];
extern char lbl_8804DB48[];
extern char lbl_8804DBD0[];
extern char lbl_8804DC24[];
extern char lbl_8804DC54[];
extern char lbl_8804DC90[];
extern char lbl_8804DD58[];
extern char lbl_8804DD6C[];
extern char lbl_8804DDB0[];
extern char lbl_8804DDC4[];
extern char lbl_8804DDD8[];
extern char lbl_8804DE44[];
extern char lbl_8804DED4[];
extern char lbl_8804E4DC[];
extern char lbl_8804E4F4[];
extern char lbl_8804E50C[];
extern char lbl_8804E524[];
extern char lbl_8804E53C[];
extern char lbl_8804E560[];
extern char lbl_8804E57C[];
extern char lbl_88B46B88[];
extern char lbl_88B46C18[];
extern char lbl_88B46C30[];
extern char lbl_88B46C90[];
extern char lbl_88B46D38[];
extern char lbl_88B46D50[];
extern char lbl_88B46DB0[];
extern char lbl_88B46DC8[];
extern char lbl_88B46E10[];
extern char lbl_88B46EA0[];
extern char lbl_88B46F30[];
extern char lbl_88B46F90[];
extern char lbl_88B46FC0[];
extern char lbl_88B47008[];
extern char lbl_88B47068[];
extern char lbl_88B47098[];
extern char lbl_88B47140[];
extern char lbl_88B47170[];
extern char lbl_88B471A0[];
extern char lbl_88B471AC[];
extern char lbl_88B471DC[];
extern char lbl_88B471F4[];
extern char lbl_88B471F8[];
extern char lbl_88B47228[];
extern char lbl_88B4725C[];
extern char lbl_88B47260[];
extern char lbl_88B472C0[];
extern char lbl_88B47380[];
extern char lbl_88B47398[];
extern char lbl_88B47410[];
extern char lbl_88B47428[];
extern char lbl_88B47458[];
extern char lbl_88B47488[];
extern char lbl_88B474B8[];
extern char lbl_88B474D0[];
extern char lbl_88B47500[];
extern char lbl_88B47518[];
extern char lbl_88B47548[];
extern char lbl_88B475F0[];
extern char lbl_88B47620[];
extern char lbl_88B476E0[];
extern char lbl_88B476E8[];
extern char lbl_88B47718[];
extern char lbl_88B477D8[];
extern char lbl_88B477DC[];
extern char lbl_88B477F4[];
extern char lbl_88B47824[];
extern char lbl_88B47828[];
extern char lbl_88B47840[];
extern char lbl_88B47888[];
extern char lbl_88B478B8[];
extern char lbl_88B479D8[];
extern char lbl_88B47A68[];
extern char lbl_88B47B28[];
extern char lbl_88B47C00[];
extern char lbl_88B47CC0[];
extern char lbl_88B47D68[];
extern char lbl_88B47E88[];
extern char lbl_88B47EE8[];
extern char lbl_88B47FF0[];
extern char lbl_88B480C8[];
extern char lbl_88B480F8[];
extern char lbl_88B48110[];
extern char lbl_88B48158[];
extern char lbl_88B48170[];
extern char lbl_88B481B8[];
extern char lbl_88B48218[];
extern char lbl_88B48260[];
extern char lbl_88B482C0[];
extern char lbl_88B482F0[];
extern char lbl_88B48308[];
extern char lbl_88B48320[];
extern char lbl_88B48380[];
extern char lbl_88B48398[];
extern char lbl_88B483C8[];
extern char lbl_88B483E0[];
extern char lbl_88B48410[];
extern char lbl_88B48428[];
extern char lbl_88B48440[];
extern char lbl_88B48458[];
extern char lbl_88B484A0[];
extern char lbl_88B484D0[];
extern char lbl_88B48500[];
extern char lbl_88B48548[];
extern char lbl_88B485C4[];
extern char lbl_88B485C8[];
extern char lbl_88B48640[];
extern char lbl_88B48670[];
extern char lbl_88B48688[];
extern char lbl_88B486A8[];
extern char lbl_88B48708[];
extern char lbl_88B48720[];
extern char lbl_88B48750[];
extern char lbl_88B48780[];
extern char lbl_88B487B0[];
extern char lbl_88B487F8[];
extern char lbl_88B488A0[];
extern char lbl_88B488E8[];
extern char lbl_88B48948[];
extern char lbl_88B489D8[];
extern char lbl_88B489F0[];
extern char lbl_88B48A20[];
extern char lbl_88B48A68[];
extern char lbl_88B48AB0[];
extern char lbl_88B48AF8[];
extern char lbl_88B48B10[];
extern char lbl_88B48B40[];
extern char lbl_88B48C30[];
extern char lbl_88B48C78[];
extern char lbl_88B48D50[];
extern char lbl_88B48D68[];
extern char lbl_88B48DC8[];
extern char lbl_88B48DE0[];
extern char lbl_88B48E10[];
extern char lbl_88B48E28[];
extern char lbl_88B48E2C[];
extern char lbl_88B48E48[];
extern char lbl_88B48E90[];
extern char lbl_88B48EA8[];
extern char lbl_88B48F08[];
extern char lbl_88B48F0C[];
extern char lbl_88B48F3C[];
extern char lbl_88B48F40[];
extern char lbl_88B48F88[];
extern char lbl_88B48FB8[];
extern char lbl_88B48FE8[];
extern char lbl_88B49048[];
extern char lbl_88B49090[];
extern char lbl_88B49120[];
extern char lbl_88B49198[];
extern char lbl_88B491E0[];
extern char lbl_88B49240[];
extern char lbl_88B49288[];
extern char lbl_88B492D0[];
extern char lbl_88B49378[];
extern char lbl_88B493C0[];
extern char lbl_88B493F0[];
extern char lbl_88B49480[];
extern char lbl_88B49510[];
extern char lbl_88B495D0[];
extern char lbl_88B495E8[];
extern char lbl_88B49660[];
extern char lbl_88B496A8[];
extern char lbl_88B49720[];
extern char lbl_88B49780[];
extern char lbl_88B497E0[];
extern char lbl_88B49994[];
extern char lbl_88B499C8[];
extern char lbl_88B49A70[];
extern char lbl_88B49A88[];
extern char lbl_88B49AA0[];
extern char lbl_88B49AD0[];
extern char lbl_88B49B78[];
extern char lbl_88B49BA8[];
extern char lbl_88B49BC0[];
extern char lbl_88B49BF0[];
extern char lbl_88B49C08[];
extern char lbl_88B49C24[];
extern char lbl_88B49C58[];
extern char lbl_88B49CE8[];
extern char lbl_88B49CEC[];
extern char lbl_88B49CF0[];
extern char lbl_88B49CF8[];
extern char lbl_88B49D70[];
extern char lbl_88B4B330[];
extern char lbl_88B4B3F0[];
extern char lbl_88B4B480[];
extern char lbl_88B4B4B0[];
extern char lbl_88B4B4E0[];
extern char lbl_88B4B510[];
extern char lbl_88B4B588[];
extern char lbl_88B4B5D0[];
extern char lbl_88B4B648[];
extern char lbl_88B4B780[];
extern char lbl_88B4B7C8[];
extern char lbl_88B4B888[];
extern char lbl_88B4B8E8[];
extern char lbl_88CB2CDC[];
extern char lbl_88CB2D3C[];
extern char lbl_88CB2D6C[];
extern char lbl_88CB2D9C[];
extern char lbl_88CB2DCC[];
extern char lbl_88CB2DFC[];
extern char lbl_88CB2E2C[];
extern char lbl_88CB2E5C[];
extern char lbl_88CB2E8C[];
extern char lbl_88CB2EBC[];
extern char lbl_88CB2EEC[];
extern char lbl_88CB2F1C[];
extern char lbl_88CB2F4C[];
extern char lbl_88CB2F7C[];
extern char lbl_88CB2FAC[];
extern char lbl_88CB2FDC[];
extern char lbl_88CB300C[];
extern char lbl_88CB303C[];
extern char lbl_88CB306C[];
extern char lbl_88CB309C[];
extern char lbl_88CB30CC[];
extern char lbl_88CB30FC[];
extern char lbl_88CB312C[];
extern char lbl_88CB315C[];
extern char lbl_88CB318C[];
extern char lbl_88CB31BC[];
extern char lbl_88CB31EC[];
extern char lbl_88CB321C[];
extern char lbl_88CB324C[];
extern char lbl_88CB327C[];
extern char lbl_88CB32AC[];
extern char lbl_88CB32DC[];
extern char lbl_88CB330C[];
extern char lbl_88CB333C[];
extern char lbl_88CB336C[];
extern char lbl_88CB339C[];
extern char lbl_88CB33CC[];
extern char lbl_88CB33FC[];
extern char lbl_88CB342C[];
extern char lbl_88CB345C[];
extern char lbl_88CB348C[];
extern char lbl_88CB34BC[];
extern char lbl_88CB34EC[];
extern char lbl_88CB351C[];
extern char lbl_88CB354C[];
extern char lbl_88CB357C[];
extern char lbl_88CB35AC[];
extern char lbl_88CB35DC[];
extern char lbl_88CB360C[];
extern char lbl_88CB363C[];
extern char lbl_88CB366C[];
extern char lbl_88CB369C[];
extern char lbl_88CB36CC[];
extern char lbl_88CB36FC[];
extern char lbl_88CB372C[];
extern char lbl_88CB375C[];
extern char lbl_88CB378C[];
extern char lbl_88CB37BC[];
extern char lbl_88CB37EC[];
extern char lbl_88CB381C[];
extern char lbl_88CB384C[];
extern char lbl_88CB387C[];
extern char lbl_88CB38AC[];
extern char lbl_88CB38DC[];
extern char lbl_88CB390C[];
extern char lbl_88CB393C[];
extern char lbl_88CB396C[];
extern char lbl_88CB399C[];
extern char lbl_88CB39CC[];
extern char lbl_88CB39FC[];
extern char lbl_88CB3A2C[];
extern char lbl_88CB3A5C[];
extern char lbl_88CB3A8C[];
extern char lbl_88CB3ABC[];
extern char lbl_88CB3AEC[];
extern char lbl_88CB3B1C[];
extern char lbl_88CB3B4C[];
extern char lbl_88CB3B7C[];
extern char lbl_88CB3BAC[];
extern char lbl_88CB3BDC[];
extern char lbl_88CB3C0C[];
extern char lbl_88CB3C3C[];
extern char lbl_88CB3C6C[];
extern char lbl_88CB3C9C[];
extern char lbl_88CB3CCC[];
extern char lbl_88CB3CFC[];
extern char lbl_88CB3D2C[];
extern char lbl_88CB3D5C[];
extern char lbl_88CB3D8C[];
extern char lbl_88CB3DBC[];
extern char lbl_88CB3DEC[];
extern char lbl_88CB3E1C[];
extern char lbl_88CB3E4C[];
extern char lbl_88CB3E7C[];
extern char lbl_88CB3EAC[];
extern char lbl_88CB3EDC[];
extern char lbl_88CB3F0C[];
extern char lbl_88CB3F3C[];
extern char lbl_88CB3F6C[];
extern char lbl_88CB3F9C[];
extern char lbl_88CB3FCC[];
extern char lbl_88CB3FFC[];
extern char lbl_88CB402C[];
extern char lbl_88CB405C[];
extern char lbl_88CB408C[];
extern char lbl_88CB40BC[];
extern char lbl_88CB40EC[];
extern char lbl_88CB411C[];
extern char lbl_88CB414C[];
extern char lbl_88CB417C[];
extern char lbl_88CB41AC[];
extern char lbl_88CB41DC[];
extern char lbl_88CB420C[];
extern char lbl_88CB423C[];
extern char lbl_88CB426C[];
extern char lbl_88CB429C[];
extern char lbl_88CB42CC[];
extern char lbl_88CB42FC[];
extern char lbl_88CB432C[];
extern char lbl_88CB435C[];
extern char lbl_88CB438C[];
extern char lbl_88CB43BC[];
extern char lbl_88CB43EC[];
extern char lbl_88CB441C[];
extern char lbl_88CB444C[];
extern char lbl_88CB447C[];
extern char lbl_88CB44AC[];
extern char lbl_88CB44DC[];
extern char lbl_88CB450C[];
extern char lbl_88CB453C[];
extern char lbl_88CB456C[];
extern char lbl_88CB459C[];
extern char lbl_88CB45CC[];
extern char lbl_88CB45FC[];
extern char lbl_88CB462C[];
extern char lbl_88CB465C[];
extern char lbl_88CB468C[];
extern char lbl_88CB46BC[];
extern char lbl_88CB46EC[];
extern char lbl_88CB471C[];
extern char lbl_88CB474C[];
extern char lbl_88CB477C[];
extern char lbl_88CB47AC[];
extern char lbl_88CB47DC[];
extern char lbl_88CB480C[];
extern char lbl_88CB483C[];
extern char lbl_88CB486C[];
extern char lbl_88CB489C[];
extern char lbl_88CB48CC[];
extern char lbl_88CB48FC[];
extern char lbl_88CB492C[];
extern char lbl_88CB495C[];
extern char lbl_88CB498C[];
extern char lbl_88CB49BC[];
extern char lbl_88CB49EC[];
extern char lbl_88CB4A1C[];
extern char lbl_88CB4A4C[];
extern char lbl_88CB4A7C[];
extern char lbl_88CB4AAC[];
extern char lbl_88CB4ADC[];
extern char lbl_88CB4B0C[];
extern char lbl_88CB4B3C[];
extern char lbl_88CB4B6C[];
extern char lbl_88CB4B9C[];
extern char lbl_88CB4BCC[];
extern char lbl_88CB4BFC[];
extern char lbl_88CB4C2C[];
extern char lbl_88CB4C5C[];
extern char lbl_88CB4C8C[];
extern char lbl_88CB4CBC[];
extern char lbl_88CB4CEC[];
extern char lbl_88CB4D1C[];
extern char lbl_88CB4D4C[];
extern char lbl_88CB4D7C[];
extern char lbl_88CB4DAC[];
extern char lbl_88CB4DDC[];
extern char lbl_88CB4E0C[];
extern char lbl_88CB4E3C[];
extern char lbl_88CB4E6C[];
extern char lbl_88CB4E9C[];
extern char lbl_88CB4ECC[];
extern char lbl_88CB4EFC[];
extern char lbl_88CB4F2C[];
extern char lbl_88CB4F5C[];
extern char lbl_88CB4F8C[];
extern char lbl_88CB4FBC[];
extern char lbl_88CB501C[];
extern char lbl_88CB504C[];
extern char lbl_88CB50AC[];
ts4_word fn_8841F080();

/* Swing_DLL.xex 0x889E2388: call_seq lbl_88B46B88, lbl_88CB2CDC, lbl_8803ECD0, lbl_88CB2D3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46B88_889E2388(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2D3C, (ts4_word)(ts4_word)lbl_8803ECD0, (ts4_word)(ts4_word)lbl_88CB2CDC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46B88, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2400: call_seq lbl_88B46C18, lbl_88CB2CDC, lbl_8803ECB0, lbl_88CB2D6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46C18_889E2400(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2D6C, (ts4_word)(ts4_word)lbl_8803ECB0, (ts4_word)(ts4_word)lbl_88CB2CDC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46C18, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2478: call_seq lbl_88B46C30, lbl_88040078, lbl_88CB2D9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46C30_889E2478(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2D9C, (ts4_word)(ts4_word)lbl_88040078, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46C30, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E24E8: call_seq lbl_88B46C90, lbl_88CB2CDC, lbl_8803EC94, lbl_88CB2DCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46C90_889E24E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2DCC, (ts4_word)(ts4_word)lbl_8803EC94, (ts4_word)(ts4_word)lbl_88CB2CDC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46C90, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2560: call_seq lbl_88B46D38, lbl_88046C60, lbl_88CB2DFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46D38_889E2560(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2DFC, (ts4_word)(ts4_word)lbl_88046C60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46D38, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E25D0: call_seq lbl_88B46D50, lbl_8803EE88, lbl_88CB2E2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46D50_889E25D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2E2C, (ts4_word)(ts4_word)lbl_8803EE88, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46D50, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2640: call_seq lbl_88B46DB0, lbl_88CB303C, lbl_8804002C, lbl_88CB2E5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46DB0_889E2640(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2E5C, (ts4_word)(ts4_word)lbl_8804002C, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46DB0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E26B8: call_seq lbl_88B46DC8, lbl_88046C00, lbl_88CB2E8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46DC8_889E26B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2E8C, (ts4_word)(ts4_word)lbl_88046C00, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46DC8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2728: call_seq lbl_88B46E10, lbl_88046C24, lbl_88CB2EBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46E10_889E2728(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2EBC, (ts4_word)(ts4_word)lbl_88046C24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46E10, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2798: call_seq lbl_88B46EA0, lbl_88046C48, lbl_88CB2EEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46EA0_889E2798(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2EEC, (ts4_word)(ts4_word)lbl_88046C48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46EA0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2808: call_seq lbl_88CB303C, lbl_8803EC3C, lbl_88CB2F1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB303C_889E2808(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2F1C, (ts4_word)(ts4_word)lbl_8803EC3C, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2870: call_seq lbl_88B46F30, lbl_88CB2F1C, lbl_8803ECF4, lbl_88CB2F4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46F30_889E2870(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2F4C, (ts4_word)(ts4_word)lbl_8803ECF4, (ts4_word)(ts4_word)lbl_88CB2F1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46F30, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E28E8: call_seq lbl_88B46F90, lbl_8803EEFC, lbl_88CB2F7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46F90_889E28E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2F7C, (ts4_word)(ts4_word)lbl_8803EEFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46F90, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2958: call_seq lbl_88B46FC0, lbl_8803EEE8, lbl_88CB2FAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46FC0_889E2958(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2FAC, (ts4_word)(ts4_word)lbl_8803EEE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46FC0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E29C8: call_seq lbl_88B47008, lbl_8803EE7C, lbl_88CB2FDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47008_889E29C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2FDC, (ts4_word)(ts4_word)lbl_8803EE7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47008, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2A38: call_seq lbl_8803C97C, lbl_88CB300C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803C97C_889E2A38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB300C, (ts4_word)(ts4_word)lbl_8803C97C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2A98: call_seq lbl_88B47068, lbl_88CB300C, lbl_8803C9DC, lbl_88CB303C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47068_889E2A98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)(ts4_word)lbl_8803C9DC, (ts4_word)(ts4_word)lbl_88CB300C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47068, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2B10: call_seq lbl_88B47098, lbl_8803CC5C, lbl_88CB306C, lbl_8804D824, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47098_889E2B10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB306C, (ts4_word)(ts4_word)lbl_8803CC5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804D824, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B47098, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2B80: call_seq lbl_88B47140, lbl_8803CCC4, lbl_88CB309C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47140_889E2B80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB309C, (ts4_word)(ts4_word)lbl_8803CCC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47140, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2BF0: call_seq lbl_88B47170, lbl_8803CCD4, lbl_88CB30CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47170_889E2BF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB30CC, (ts4_word)(ts4_word)lbl_8803CCD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47170, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2C60: addr lbl_88B4B330, u32@lbl_88B471A0, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88B4B330_889E2C60(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B471A0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B4B330) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B4B330) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x889E2C80: call_seq lbl_88B4B330, lbl_8803D124, lbl_88CB30FC, lbl_8804D990, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B330_889E2C80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB30FC, (ts4_word)(ts4_word)lbl_8803D124, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804D990, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B4B330, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2CF0: call_seq lbl_88B471AC, lbl_8803D484, lbl_88CB312C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B471AC_889E2CF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB312C, (ts4_word)(ts4_word)lbl_8803D484, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B471AC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2D60: call_seq lbl_88B471DC, lbl_8803D4A8, lbl_88CB315C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B471DC_889E2D60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB315C, (ts4_word)(ts4_word)lbl_8803D4A8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B471DC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2DD0: addr lbl_88B4B3F0, u32@lbl_88B471F4, u32@0x50 */
void ts4_addr_lbl_88B4B3F0_889E2DD0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B4B3F0) + 80) = (ts4_word)(*(ts4_word *)lbl_88B471F4);
    return;
}

/* Swing_DLL.xex 0x889E2DE8: call_seq lbl_88B4B3F0, lbl_8803D4C4, lbl_88CB318C, lbl_8804D9E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B3F0_889E2DE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB318C, (ts4_word)(ts4_word)lbl_8803D4C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804D9E4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B4B3F0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2E58: call_seq lbl_88B471F8, lbl_8803CAF0, lbl_88CB31BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B471F8_889E2E58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB31BC, (ts4_word)(ts4_word)lbl_8803CAF0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B471F8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2EC8: call_seq lbl_88B47228, lbl_8803D194, lbl_88CB31EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47228_889E2EC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB31EC, (ts4_word)(ts4_word)lbl_8803D194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47228, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2F38: call_seq lbl_88B47260, lbl_8803D2E0, lbl_88CB321C, lbl_8804DA08, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47260_889E2F38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB321C, (ts4_word)(ts4_word)lbl_8803D2E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804DA08, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B47260, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2FA8: call_seq lbl_88B472C0, lbl_8803D6A0, lbl_88CB324C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B472C0_889E2FA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB324C, (ts4_word)(ts4_word)lbl_8803D6A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B472C0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3018: call_seq lbl_88B47380, lbl_8803D914, lbl_88CB327C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47380_889E3018(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB327C, (ts4_word)(ts4_word)lbl_8803D914, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47380, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3088: call_seq lbl_88B47398, lbl_8803D9E8, lbl_88CB32AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47398_889E3088(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB32AC, (ts4_word)(ts4_word)lbl_8803D9E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47398, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E30F8: addr lbl_88B4B480, u32@lbl_88B4725C, u32@0x20 */
void ts4_addr_lbl_88B4B480_889E30F8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B4B480) + 32) = (ts4_word)(*(ts4_word *)lbl_88B4725C);
    return;
}

/* Swing_DLL.xex 0x889E3110: call_seq lbl_88B4B480, lbl_8803F988, lbl_88CB32DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B480_889E3110(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB32DC, (ts4_word)(ts4_word)lbl_8803F988, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4B480, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3180: addr lbl_88B4B4B0, u32@lbl_88B4725C, u32@0x20 */
void ts4_addr_lbl_88B4B4B0_889E3180(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B4B4B0) + 32) = (ts4_word)(*(ts4_word *)lbl_88B4725C);
    return;
}

/* Swing_DLL.xex 0x889E3198: call_seq lbl_88B4B4B0, lbl_8803F974, lbl_88CB330C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B4B0_889E3198(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB330C, (ts4_word)(ts4_word)lbl_8803F974, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4B4B0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3208: call_seq lbl_88B47410, lbl_8804E4DC, lbl_88CB333C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47410_889E3208(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB333C, (ts4_word)(ts4_word)lbl_8804E4DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47410, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3278: addr lbl_88B4B4E0, u32@lbl_88B4725C, u32@0x20 */
void ts4_addr_lbl_88B4B4E0_889E3278(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B4B4E0) + 32) = (ts4_word)(*(ts4_word *)lbl_88B4725C);
    return;
}

/* Swing_DLL.xex 0x889E3290: call_seq lbl_88B4B4E0, lbl_8803F960, lbl_88CB336C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B4E0_889E3290(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB336C, (ts4_word)(ts4_word)lbl_8803F960, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4B4E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3300: call_seq lbl_88B47428, lbl_8803F9B0, lbl_88CB339C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47428_889E3300(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB339C, (ts4_word)(ts4_word)lbl_8803F9B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47428, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3370: call_seq lbl_88B47458, lbl_8803F99C, lbl_88CB33CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47458_889E3370(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB33CC, (ts4_word)(ts4_word)lbl_8803F99C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47458, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E33E0: call_seq lbl_88B47488, lbl_8804E4F4, lbl_88CB33FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47488_889E33E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB33FC, (ts4_word)(ts4_word)lbl_8804E4F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47488, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3450: call_seq lbl_88B474B8, lbl_88CB345C, lbl_8804E50C, lbl_88CB342C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B474B8_889E3450(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB342C, (ts4_word)(ts4_word)lbl_8804E50C, (ts4_word)(ts4_word)lbl_88CB345C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B474B8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E34C8: call_seq lbl_88B474D0, lbl_8804E524, lbl_88CB345C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B474D0_889E34C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB345C, (ts4_word)(ts4_word)lbl_8804E524, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B474D0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3538: call_seq lbl_88B47500, lbl_8804E53C, lbl_88CB348C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47500_889E3538(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB348C, (ts4_word)(ts4_word)lbl_8804E53C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47500, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E35A8: call_seq lbl_88B47518, lbl_8804E560, lbl_88CB34BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47518_889E35A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB34BC, (ts4_word)(ts4_word)lbl_8804E560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47518, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3618: call_seq lbl_88B47548, lbl_8803F5C8, lbl_88CB34EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47548_889E3618(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB34EC, (ts4_word)(ts4_word)lbl_8803F5C8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47548, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3688: call_seq lbl_88B475F0, lbl_8804C310, lbl_88CB351C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B475F0_889E3688(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB351C, (ts4_word)(ts4_word)lbl_8804C310, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B475F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E36F8: call_seq lbl_88B47620, lbl_8803ED20, lbl_88CB354C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47620_889E36F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB354C, (ts4_word)(ts4_word)lbl_8803ED20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47620, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3768: addr lbl_88B4B510, u32@lbl_88B476E0, u32@0x8 */
void ts4_addr_lbl_88B4B510_889E3768(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B4B510) + 8) = (ts4_word)(*(ts4_word *)lbl_88B476E0);
    return;
}

/* Swing_DLL.xex 0x889E3780: call_seq lbl_88B4B510, lbl_8804C33C, lbl_88CB357C, lbl_8804DA78, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B510_889E3780(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB357C, (ts4_word)(ts4_word)lbl_8804C33C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804DA78, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B4B510, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E37F0: call_seq lbl_88B476E8, lbl_8803ED28, lbl_88CB35AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B476E8_889E37F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB35AC, (ts4_word)(ts4_word)lbl_8803ED28, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B476E8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3860: call_seq lbl_88B47718, lbl_8803ED14, lbl_88CB35DC, lbl_8804DABC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47718_889E3860(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB35DC, (ts4_word)(ts4_word)lbl_8803ED14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804DABC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B47718, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E38D0: addr lbl_88B4B588, u32@lbl_88B477D8, u32@0x20 */
void ts4_addr_lbl_88B4B588_889E38D0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B4B588) + 32) = (ts4_word)(*(ts4_word *)lbl_88B477D8);
    return;
}

/* Swing_DLL.xex 0x889E38E8: call_seq lbl_88B4B588, lbl_8804E57C, lbl_88CB360C, lbl_8804DAF8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B588_889E38E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB360C, (ts4_word)(ts4_word)lbl_8804E57C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804DAF8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B4B588, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3958: call_seq lbl_88B477DC, lbl_8804C348, lbl_88CB363C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B477DC_889E3958(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB363C, (ts4_word)(ts4_word)lbl_8804C348, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B477DC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E39C8: call_seq lbl_88B477F4, lbl_8804C358, lbl_88CB366C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B477F4_889E39C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB366C, (ts4_word)(ts4_word)lbl_8804C358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B477F4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3A38: addr lbl_88B4B5D0, u32@lbl_88B47824, u32@0x8 */
void ts4_addr_lbl_88B4B5D0_889E3A38(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B4B5D0) + 8) = (ts4_word)(*(ts4_word *)lbl_88B47824);
    return;
}

/* Swing_DLL.xex 0x889E3A50: call_seq lbl_88B4B5D0, lbl_8804C380, lbl_88CB369C, lbl_8804DB34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B5D0_889E3A50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB369C, (ts4_word)(ts4_word)lbl_8804C380, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804DB34, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B4B5D0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3AC0: call_seq lbl_88B47828, lbl_88042408, lbl_88CB36CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47828_889E3AC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB36CC, (ts4_word)(ts4_word)lbl_88042408, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47828, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3B30: call_seq lbl_88B47840, lbl_880423F8, lbl_88CB36FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47840_889E3B30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB36FC, (ts4_word)(ts4_word)lbl_880423F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47840, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3BA0: call_seq lbl_88B47888, lbl_8804C390, lbl_88CB372C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47888_889E3BA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB372C, (ts4_word)(ts4_word)lbl_8804C390, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47888, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3C10: call_seq lbl_88B478B8, lbl_8804C3A0, lbl_88CB375C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B478B8_889E3C10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB375C, (ts4_word)(ts4_word)lbl_8804C3A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B478B8, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3C80: call_seq lbl_88B479D8, lbl_8804C3B0, lbl_88CB378C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B479D8_889E3C80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB378C, (ts4_word)(ts4_word)lbl_8804C3B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B479D8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3CF0: call_seq lbl_88B47A68, lbl_8804C3C4, lbl_88CB37BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47A68_889E3CF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB37BC, (ts4_word)(ts4_word)lbl_8804C3C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47A68, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3D60: call_seq lbl_88B47B28, lbl_8804C3DC, lbl_88CB37EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47B28_889E3D60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB37EC, (ts4_word)(ts4_word)lbl_8804C3DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47B28, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3DD0: call_seq lbl_88B47C00, lbl_8804C3F8, lbl_88CB381C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47C00_889E3DD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB381C, (ts4_word)(ts4_word)lbl_8804C3F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47C00, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3E40: call_seq lbl_88B47CC0, lbl_8804C410, lbl_88CB384C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47CC0_889E3E40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB384C, (ts4_word)(ts4_word)lbl_8804C410, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47CC0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3EB0: call_seq lbl_88B47D68, lbl_8804DB48, lbl_8803F5BC, lbl_88CB387C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47D68_889E3EB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB387C, (ts4_word)(ts4_word)lbl_8803F5BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47D68, (ts4_word)12, (ts4_word)(ts4_word)lbl_8804DB48, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3F28: call_seq lbl_88B47E88, lbl_8804C428, lbl_88CB38AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47E88_889E3F28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB38AC, (ts4_word)(ts4_word)lbl_8804C428, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47E88, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E3F98: call_seq lbl_88B47EE8, lbl_8803F5E0, lbl_88CB38DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47EE8_889E3F98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB38DC, (ts4_word)(ts4_word)lbl_8803F5E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47EE8, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4008: call_seq lbl_88B47FF0, lbl_88040278, lbl_88CB390C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B47FF0_889E4008(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB390C, (ts4_word)(ts4_word)lbl_88040278, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B47FF0, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4078: call_seq lbl_88B480C8, lbl_8803ED58, lbl_88CB393C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B480C8_889E4078(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB393C, (ts4_word)(ts4_word)lbl_8803ED58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B480C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E40E8: call_seq lbl_88B480F8, lbl_8803ED40, lbl_88CB396C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B480F8_889E40E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB396C, (ts4_word)(ts4_word)lbl_8803ED40, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B480F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4158: call_seq lbl_88B48110, lbl_880433FC, lbl_88CB399C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48110_889E4158(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB399C, (ts4_word)(ts4_word)lbl_880433FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48110, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E41C8: call_seq lbl_88B48158, lbl_8804342C, lbl_88CB39CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48158_889E41C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB39CC, (ts4_word)(ts4_word)lbl_8804342C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48158, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4238: call_seq lbl_88B48170, lbl_88CB303C, lbl_8803ED7C, lbl_88CB39FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48170_889E4238(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB39FC, (ts4_word)(ts4_word)lbl_8803ED7C, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48170, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E42B0: call_seq lbl_88B481B8, lbl_88046454, lbl_88CB3A2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B481B8_889E42B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3A2C, (ts4_word)(ts4_word)lbl_88046454, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B481B8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4320: call_seq lbl_88B48218, lbl_88CB3A2C, lbl_8804233C, lbl_88CB3A5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48218_889E4320(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3A5C, (ts4_word)(ts4_word)lbl_8804233C, (ts4_word)(ts4_word)lbl_88CB3A2C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48218, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4398: call_seq lbl_880469C4, lbl_88CB3A8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880469C4_889E4398(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3A8C, (ts4_word)(ts4_word)lbl_880469C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E43F8: call_seq lbl_88B48260, lbl_88CB50AC, lbl_88042E48, lbl_88CB3ABC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48260_889E43F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3ABC, (ts4_word)(ts4_word)lbl_88042E48, (ts4_word)(ts4_word)lbl_88CB50AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48260, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4470: call_seq lbl_88046B60, lbl_88CB3AEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046B60_889E4470(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3AEC, (ts4_word)(ts4_word)lbl_88046B60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E44D0: call_seq lbl_88CB303C, lbl_88042318, lbl_88CB3B1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB303C_889E44D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3B1C, (ts4_word)(ts4_word)lbl_88042318, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4538: call_seq lbl_88046A84, lbl_88CB3B4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A84_889E4538(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3B4C, (ts4_word)(ts4_word)lbl_88046A84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4598: call_seq lbl_88B482C0, lbl_88CB3B1C, lbl_8804232C, lbl_88CB3B7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B482C0_889E4598(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3B7C, (ts4_word)(ts4_word)lbl_8804232C, (ts4_word)(ts4_word)lbl_88CB3B1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B482C0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4610: call_seq lbl_88B482F0, lbl_88CB3B1C, lbl_8804690C, lbl_88CB3BAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B482F0_889E4610(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3BAC, (ts4_word)(ts4_word)lbl_8804690C, (ts4_word)(ts4_word)lbl_88CB3B1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B482F0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4688: call_seq lbl_88CB3B1C, lbl_8804671C, lbl_88CB3BDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB3B1C_889E4688(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3BDC, (ts4_word)(ts4_word)lbl_8804671C, (ts4_word)(ts4_word)lbl_88CB3B1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E46F0: call_seq lbl_88046A50, lbl_88CB3C0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A50_889E46F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3C0C, (ts4_word)(ts4_word)lbl_88046A50, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4750: call_seq lbl_88B48308, lbl_88CB303C, lbl_88041284, lbl_88CB3C3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48308_889E4750(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3C3C, (ts4_word)(ts4_word)lbl_88041284, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48308, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E47C8: call_seq lbl_88B48320, lbl_88046220, lbl_88CB3C6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48320_889E47C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3C6C, (ts4_word)(ts4_word)lbl_88046220, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48320, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4838: call_seq lbl_88B48380, lbl_88CB3D8C, lbl_8804694C, lbl_88CB3C9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48380_889E4838(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3C9C, (ts4_word)(ts4_word)lbl_8804694C, (ts4_word)(ts4_word)lbl_88CB3D8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48380, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E48B0: call_seq lbl_88B48398, lbl_88CB3C3C, lbl_88040110, lbl_88CB3CCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48398_889E48B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3CCC, (ts4_word)(ts4_word)lbl_88040110, (ts4_word)(ts4_word)lbl_88CB3C3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48398, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4928: call_seq lbl_88B483C8, lbl_88CB3C3C, lbl_88040100, lbl_88CB3CFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B483C8_889E4928(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3CFC, (ts4_word)(ts4_word)lbl_88040100, (ts4_word)(ts4_word)lbl_88CB3C3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B483C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E49A0: call_seq lbl_88B483E0, lbl_88CB3D8C, lbl_8804011C, lbl_88CB3D2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B483E0_889E49A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3D2C, (ts4_word)(ts4_word)lbl_8804011C, (ts4_word)(ts4_word)lbl_88CB3D8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B483E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4A18: call_seq lbl_88B48410, lbl_88CB3C3C, lbl_880400A8, lbl_88CB3D5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48410_889E4A18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3D5C, (ts4_word)(ts4_word)lbl_880400A8, (ts4_word)(ts4_word)lbl_88CB3C3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48410, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4A90: call_seq lbl_88B48428, lbl_88CB423C, lbl_88042370, lbl_88CB3D8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48428_889E4A90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3D8C, (ts4_word)(ts4_word)lbl_88042370, (ts4_word)(ts4_word)lbl_88CB423C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48428, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4B08: call_seq lbl_88B48440, lbl_88CB3F9C, lbl_88041B24, lbl_88CB3DBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48440_889E4B08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3DBC, (ts4_word)(ts4_word)lbl_88041B24, (ts4_word)(ts4_word)lbl_88CB3F9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48440, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4B80: call_seq lbl_88B48458, lbl_88CB3D5C, lbl_880468C8, lbl_88CB3DEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48458_889E4B80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3DEC, (ts4_word)(ts4_word)lbl_880468C8, (ts4_word)(ts4_word)lbl_88CB3D5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48458, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4BF8: call_seq lbl_88B484A0, lbl_88CB3D8C, lbl_880400E8, lbl_88CB3E1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B484A0_889E4BF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3E1C, (ts4_word)(ts4_word)lbl_880400E8, (ts4_word)(ts4_word)lbl_88CB3D8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B484A0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4C70: call_seq lbl_88B484D0, lbl_88CB3D8C, lbl_880400D0, lbl_88CB3E4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B484D0_889E4C70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3E4C, (ts4_word)(ts4_word)lbl_880400D0, (ts4_word)(ts4_word)lbl_88CB3D8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B484D0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4CE8: call_seq lbl_88B48500, lbl_880463D4, lbl_88CB3E7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48500_889E4CE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3E7C, (ts4_word)(ts4_word)lbl_880463D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48500, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4D58: call_seq lbl_88B48548, lbl_88CB3D8C, lbl_88046868, lbl_88CB3EAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48548_889E4D58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3EAC, (ts4_word)(ts4_word)lbl_88046868, (ts4_word)(ts4_word)lbl_88CB3D8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48548, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4DD0: call_seq lbl_88B485C8, lbl_88CB3D8C, lbl_8803EFC0, lbl_88CB3EDC, lbl_8804DBD0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B485C8_889E4DD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3EDC, (ts4_word)(ts4_word)lbl_8803EFC0, (ts4_word)(ts4_word)lbl_88CB3D8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804DBD0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B485C8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4E48: call_seq lbl_88CB402C, lbl_880467DC, lbl_88CB3F0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB402C_889E4E48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3F0C, (ts4_word)(ts4_word)lbl_880467DC, (ts4_word)(ts4_word)lbl_88CB402C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4EB0: call_seq lbl_88CB3C3C, lbl_88046AE0, lbl_88CB3F3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB3C3C_889E4EB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3F3C, (ts4_word)(ts4_word)lbl_88046AE0, (ts4_word)(ts4_word)lbl_88CB3C3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4F18: call_seq lbl_88B48640, lbl_88042358, lbl_88CB3F6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48640_889E4F18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3F6C, (ts4_word)(ts4_word)lbl_88042358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48640, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E4F88: call_seq lbl_88B48670, lbl_88CB3D5C, lbl_8804234C, lbl_88CB3F9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48670_889E4F88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3F9C, (ts4_word)(ts4_word)lbl_8804234C, (ts4_word)(ts4_word)lbl_88CB3D5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48670, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5000: call_seq lbl_88B48688, lbl_88046320, lbl_88CB3FCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48688_889E5000(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3FCC, (ts4_word)(ts4_word)lbl_88046320, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48688, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5070: addr lbl_88B4B648, u32@lbl_88B485C4, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88B4B648_889E5070(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B485C4;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B4B648) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B4B648) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x889E5090: call_seq lbl_88B4B648, lbl_8803EFE8, lbl_88CB3FFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B648_889E5090(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB3FFC, (ts4_word)(ts4_word)lbl_8803EFE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4B648, (ts4_word)13, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5100: call_seq lbl_88B486A8, lbl_88CB3D5C, lbl_8803EF9C, lbl_88CB402C, lbl_8804DC24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B486A8_889E5100(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB402C, (ts4_word)(ts4_word)lbl_8803EF9C, (ts4_word)(ts4_word)lbl_88CB3D5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804DC24, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B486A8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5178: call_seq lbl_88B48708, lbl_88CB3CFC, lbl_880423C0, lbl_88CB405C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48708_889E5178(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB405C, (ts4_word)(ts4_word)lbl_880423C0, (ts4_word)(ts4_word)lbl_88CB3CFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48708, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E51F0: call_seq lbl_88B48720, lbl_880462E8, lbl_88CB408C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48720_889E51F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB408C, (ts4_word)(ts4_word)lbl_880462E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48720, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5260: call_seq lbl_88B48750, lbl_88CB3C3C, lbl_8804675C, lbl_88CB40BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48750_889E5260(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB40BC, (ts4_word)(ts4_word)lbl_8804675C, (ts4_word)(ts4_word)lbl_88CB3C3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48750, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E52D8: call_seq lbl_88B48780, lbl_88CB423C, lbl_8803F9D4, lbl_88CB40EC, lbl_8804DC54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48780_889E52D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB40EC, (ts4_word)(ts4_word)lbl_8803F9D4, (ts4_word)(ts4_word)lbl_88CB423C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804DC54, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B48780, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5350: call_seq lbl_88CB3C3C, lbl_88046AB4, lbl_88CB411C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB3C3C_889E5350(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB411C, (ts4_word)(ts4_word)lbl_88046AB4, (ts4_word)(ts4_word)lbl_88CB3C3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E53B8: call_seq lbl_88B487B0, lbl_88CB3F3C, lbl_880466D4, lbl_88CB414C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B487B0_889E53B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB414C, (ts4_word)(ts4_word)lbl_880466D4, (ts4_word)(ts4_word)lbl_88CB3F3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B487B0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5430: call_seq lbl_88B487F8, lbl_88CB3F3C, lbl_88046A18, lbl_88CB417C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B487F8_889E5430(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB417C, (ts4_word)(ts4_word)lbl_88046A18, (ts4_word)(ts4_word)lbl_88CB3F3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B487F8, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E54A8: call_seq lbl_88B488A0, lbl_880423A4, lbl_88CB41AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B488A0_889E54A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB41AC, (ts4_word)(ts4_word)lbl_880423A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B488A0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5518: call_seq lbl_88B488E8, lbl_88CB3D5C, lbl_88042390, lbl_88CB41DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B488E8_889E5518(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB41DC, (ts4_word)(ts4_word)lbl_88042390, (ts4_word)(ts4_word)lbl_88CB3D5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B488E8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5590: call_seq lbl_88CB3D8C, lbl_88043ED0, lbl_88CB420C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB3D8C_889E5590(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB420C, (ts4_word)(ts4_word)lbl_88043ED0, (ts4_word)(ts4_word)lbl_88CB3D8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E55F8: call_seq lbl_88CB3C3C, lbl_8804696C, lbl_88CB423C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB3C3C_889E55F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB423C, (ts4_word)(ts4_word)lbl_8804696C, (ts4_word)(ts4_word)lbl_88CB3C3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5660: call_seq lbl_88B48948, lbl_8803F00C, lbl_88CB426C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48948_889E5660(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB426C, (ts4_word)(ts4_word)lbl_8803F00C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48948, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E56D0: call_seq lbl_88B489D8, lbl_88CB402C, lbl_88046574, lbl_88CB429C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B489D8_889E56D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB429C, (ts4_word)(ts4_word)lbl_88046574, (ts4_word)(ts4_word)lbl_88CB402C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B489D8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5748: call_seq lbl_88B489F0, lbl_88CB417C, lbl_88046518, lbl_88CB42CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B489F0_889E5748(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB42CC, (ts4_word)(ts4_word)lbl_88046518, (ts4_word)(ts4_word)lbl_88CB417C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B489F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E57C0: call_seq lbl_88B48A20, lbl_88CB3C3C, lbl_880400BC, lbl_88CB42FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48A20_889E57C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB42FC, (ts4_word)(ts4_word)lbl_880400BC, (ts4_word)(ts4_word)lbl_88CB3C3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48A20, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5838: call_seq lbl_88B48A68, lbl_88CB3D8C, lbl_88042380, lbl_88CB432C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48A68_889E5838(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB432C, (ts4_word)(ts4_word)lbl_88042380, (ts4_word)(ts4_word)lbl_88CB3D8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48A68, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E58B0: call_seq lbl_88B48AB0, lbl_8803FBF4, lbl_88CB435C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48AB0_889E58B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB435C, (ts4_word)(ts4_word)lbl_8803FBF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48AB0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5920: call_seq lbl_88B48AF8, lbl_88CB3CFC, lbl_880423D4, lbl_88CB438C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48AF8_889E5920(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB438C, (ts4_word)(ts4_word)lbl_880423D4, (ts4_word)(ts4_word)lbl_88CB3CFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48AF8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5998: call_seq lbl_88B48B10, lbl_88CB3D5C, lbl_88046498, lbl_88CB43BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48B10_889E5998(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB43BC, (ts4_word)(ts4_word)lbl_88046498, (ts4_word)(ts4_word)lbl_88CB3D5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48B10, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5A10: call_seq lbl_88B48B40, lbl_88044324, lbl_88CB43EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48B40_889E5A10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB43EC, (ts4_word)(ts4_word)lbl_88044324, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48B40, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5A80: call_seq lbl_88B48C30, lbl_88044370, lbl_88CB441C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48C30_889E5A80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB441C, (ts4_word)(ts4_word)lbl_88044370, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48C30, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5AF0: call_seq lbl_88B48C78, lbl_8803F610, lbl_88CB444C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48C78_889E5AF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB444C, (ts4_word)(ts4_word)lbl_8803F610, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48C78, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5B60: call_seq lbl_88B48D50, lbl_8803F634, lbl_88CB447C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48D50_889E5B60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB447C, (ts4_word)(ts4_word)lbl_8803F634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48D50, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5BD0: call_seq lbl_88B48D68, lbl_88CB303C, lbl_88047050, lbl_88CB44AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48D68_889E5BD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB44AC, (ts4_word)(ts4_word)lbl_88047050, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48D68, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5C48: call_seq lbl_88B48DC8, lbl_88CB44AC, lbl_88045B44, lbl_88CB44DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48DC8_889E5C48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB44DC, (ts4_word)(ts4_word)lbl_88045B44, (ts4_word)(ts4_word)lbl_88CB44AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48DC8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5CC0: call_seq lbl_88B48DE0, lbl_88CB44AC, lbl_88045B24, lbl_88CB450C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48DE0_889E5CC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB450C, (ts4_word)(ts4_word)lbl_88045B24, (ts4_word)(ts4_word)lbl_88CB44AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48DE0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5D38: call_seq lbl_88B48E10, lbl_88CB44AC, lbl_880459C0, lbl_88CB453C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48E10_889E5D38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB453C, (ts4_word)(ts4_word)lbl_880459C0, (ts4_word)(ts4_word)lbl_88CB44AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48E10, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5DB0: addr lbl_88B4B780, u32@lbl_88B48E28, u32@0x8 */
void ts4_addr_lbl_88B4B780_889E5DB0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B4B780) + 8) = (ts4_word)(*(ts4_word *)lbl_88B48E28);
    return;
}

/* Swing_DLL.xex 0x889E5DC8: call_seq lbl_88B4B780, lbl_88045224, lbl_88CB456C, lbl_8804DC90, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B780_889E5DC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB456C, (ts4_word)(ts4_word)lbl_88045224, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804DC90, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B4B780, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5E38: call_seq lbl_88B48E2C, lbl_88045194, lbl_88CB459C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48E2C_889E5E38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB459C, (ts4_word)(ts4_word)lbl_88045194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48E2C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5EA8: call_seq lbl_88B48E48, lbl_8803EF90, lbl_88CB45CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48E48_889E5EA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB45CC, (ts4_word)(ts4_word)lbl_8803EF90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48E48, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5F18: call_seq lbl_88B48E90, lbl_88CB303C, lbl_8803FA04, lbl_88CB45FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48E90_889E5F18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB45FC, (ts4_word)(ts4_word)lbl_8803FA04, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48E90, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E5F90: call_seq lbl_88B48EA8, lbl_88042170, lbl_88CB462C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48EA8_889E5F90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB462C, (ts4_word)(ts4_word)lbl_88042170, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48EA8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6000: addr lbl_88B4B7C8, u32@lbl_88B48F08, u32@0x50 */
void ts4_addr_lbl_88B4B7C8_889E6000(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B4B7C8) + 80) = (ts4_word)(*(ts4_word *)lbl_88B48F08);
    return;
}

/* Swing_DLL.xex 0x889E6018: call_seq lbl_88B4B7C8, lbl_88CB303C, lbl_8803F0C8, lbl_88CB465C, lbl_8804DD58, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B7C8_889E6018(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB465C, (ts4_word)(ts4_word)lbl_8803F0C8, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804DD58, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B4B7C8, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6090: call_seq lbl_88B48F0C, lbl_88CB45FC, lbl_880403DC, lbl_88CB468C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48F0C_889E6090(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB468C, (ts4_word)(ts4_word)lbl_880403DC, (ts4_word)(ts4_word)lbl_88CB45FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48F0C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6108: call_seq lbl_88B48F40, lbl_88040630, lbl_88CB46BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48F40_889E6108(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB46BC, (ts4_word)(ts4_word)lbl_88040630, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48F40, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6178: call_seq lbl_88B48F88, lbl_88040608, lbl_88CB46EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48F88_889E6178(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB46EC, (ts4_word)(ts4_word)lbl_88040608, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48F88, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E61E8: call_seq lbl_88B48FB8, lbl_88CB45FC, lbl_88040394, lbl_88CB471C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48FB8_889E61E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB471C, (ts4_word)(ts4_word)lbl_88040394, (ts4_word)(ts4_word)lbl_88CB45FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48FB8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6260: call_seq lbl_88B48FE8, lbl_88040590, lbl_88CB474C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B48FE8_889E6260(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB474C, (ts4_word)(ts4_word)lbl_88040590, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B48FE8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E62D0: call_seq lbl_88B49048, lbl_88040560, lbl_88CB477C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49048_889E62D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB477C, (ts4_word)(ts4_word)lbl_88040560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49048, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6340: call_seq lbl_8804DD6C, lbl_88B49090, lbl_88CB45FC, lbl_8803F690, lbl_88CB47AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8804DD6C_889E6340(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB47AC, (ts4_word)(ts4_word)lbl_8803F690, (ts4_word)(ts4_word)lbl_88CB45FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49090, (ts4_word)6, (ts4_word)(ts4_word)lbl_8804DD6C, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E63B8: call_seq lbl_88B49120, lbl_88CB480C, lbl_88045734, lbl_88CB47DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49120_889E63B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB47DC, (ts4_word)(ts4_word)lbl_88045734, (ts4_word)(ts4_word)lbl_88CB480C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49120, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6430: call_seq lbl_88CB303C, lbl_88045A30, lbl_88CB480C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB303C_889E6430(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB480C, (ts4_word)(ts4_word)lbl_88045A30, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6498: addr lbl_88B4B888, u32@lbl_88B48F3C, u32@0x38 */
void ts4_addr_lbl_88B4B888_889E6498(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B4B888) + 56) = (ts4_word)(*(ts4_word *)lbl_88B48F3C);
    return;
}

/* Swing_DLL.xex 0x889E64B0: call_seq lbl_88B4B888, lbl_88CB45FC, lbl_88040364, lbl_88CB483C, lbl_8804DDB0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B888_889E64B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB483C, (ts4_word)(ts4_word)lbl_88040364, (ts4_word)(ts4_word)lbl_88CB45FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804DDB0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B4B888, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6528: call_seq lbl_88B49198, lbl_88CB45FC, lbl_88040344, lbl_88CB486C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49198_889E6528(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB486C, (ts4_word)(ts4_word)lbl_88040344, (ts4_word)(ts4_word)lbl_88CB45FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49198, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E65A0: call_seq lbl_88B491E0, lbl_88CB47AC, lbl_8803F064, lbl_88CB489C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B491E0_889E65A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB489C, (ts4_word)(ts4_word)lbl_8803F064, (ts4_word)(ts4_word)lbl_88CB47AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B491E0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6618: call_seq lbl_88B49240, lbl_88040534, lbl_88CB48CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49240_889E6618(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB48CC, (ts4_word)(ts4_word)lbl_88040534, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49240, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6688: call_seq lbl_88B49288, lbl_88040508, lbl_88CB48FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49288_889E6688(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB48FC, (ts4_word)(ts4_word)lbl_88040508, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49288, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E66F8: call_seq lbl_88B492D0, lbl_88CB45FC, lbl_8803F048, lbl_88CB492C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B492D0_889E66F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB492C, (ts4_word)(ts4_word)lbl_8803F048, (ts4_word)(ts4_word)lbl_88CB45FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B492D0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6770: call_seq lbl_88B49378, lbl_88CB45FC, lbl_880402E4, lbl_88CB495C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49378_889E6770(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB495C, (ts4_word)(ts4_word)lbl_880402E4, (ts4_word)(ts4_word)lbl_88CB45FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49378, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E67E8: call_seq lbl_88B493C0, lbl_88040424, lbl_88CB498C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B493C0_889E67E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB498C, (ts4_word)(ts4_word)lbl_88040424, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B493C0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6858: call_seq lbl_88B493F0, lbl_880403FC, lbl_88CB49BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B493F0_889E6858(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB49BC, (ts4_word)(ts4_word)lbl_880403FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B493F0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E68C8: call_seq lbl_88B49480, lbl_88CB45FC, lbl_880402CC, lbl_88CB49EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49480_889E68C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB49EC, (ts4_word)(ts4_word)lbl_880402CC, (ts4_word)(ts4_word)lbl_88CB45FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49480, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6940: call_seq lbl_88B49510, lbl_88CB45FC, lbl_8803F6B0, lbl_88CB4A1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49510_889E6940(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4A1C, (ts4_word)(ts4_word)lbl_8803F6B0, (ts4_word)(ts4_word)lbl_88CB45FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49510, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E69B8: call_seq lbl_88B495D0, lbl_88CB45FC, lbl_880403AC, lbl_88CB4A4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B495D0_889E69B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4A4C, (ts4_word)(ts4_word)lbl_880403AC, (ts4_word)(ts4_word)lbl_88CB45FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B495D0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6A30: call_seq lbl_88B495E8, lbl_880422F8, lbl_88CB4A7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B495E8_889E6A30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4A7C, (ts4_word)(ts4_word)lbl_880422F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B495E8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6AA0: call_seq lbl_88B49660, lbl_88CB45FC, lbl_8803FA18, lbl_88CB4AAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49660_889E6AA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4AAC, (ts4_word)(ts4_word)lbl_8803FA18, (ts4_word)(ts4_word)lbl_88CB45FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49660, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6B18: call_seq lbl_88CB303C, lbl_8803FBE0, lbl_88CB4ADC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB303C_889E6B18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4ADC, (ts4_word)(ts4_word)lbl_8803FBE0, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6B80: call_seq lbl_88B496A8, lbl_88CB4ADC, lbl_8803FCA0, lbl_88CB4B0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B496A8_889E6B80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4B0C, (ts4_word)(ts4_word)lbl_8803FCA0, (ts4_word)(ts4_word)lbl_88CB4ADC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B496A8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6BF8: call_seq lbl_88B49720, lbl_88CB4ADC, lbl_8803FC80, lbl_88CB4B3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49720_889E6BF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4B3C, (ts4_word)(ts4_word)lbl_8803FC80, (ts4_word)(ts4_word)lbl_88CB4ADC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49720, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6C70: call_seq lbl_88B49780, lbl_88CB4ADC, lbl_8803F9E8, lbl_88CB4B6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49780_889E6C70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4B6C, (ts4_word)(ts4_word)lbl_8803F9E8, (ts4_word)(ts4_word)lbl_88CB4ADC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49780, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6CE8: call_seq lbl_8804DDD8, lbl_88B497E0, lbl_88CB501C, lbl_8803F6CC, lbl_88CB4B9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8804DDD8_889E6CE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4B9C, (ts4_word)(ts4_word)lbl_8803F6CC, (ts4_word)(ts4_word)lbl_88CB501C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B497E0, (ts4_word)18, (ts4_word)(ts4_word)lbl_8804DDD8, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6D60: call_seq lbl_88CB303C, lbl_88045AA8, lbl_88CB4BCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB303C_889E6D60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4BCC, (ts4_word)(ts4_word)lbl_88045AA8, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6DC8: call_seq lbl_88CB4C5C, lbl_880457FC, lbl_88CB4BFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB4C5C_889E6DC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4BFC, (ts4_word)(ts4_word)lbl_880457FC, (ts4_word)(ts4_word)lbl_88CB4C5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6E30: call_seq lbl_88CB4B9C, lbl_880455E0, lbl_88CB4C2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB4B9C_889E6E30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4C2C, (ts4_word)(ts4_word)lbl_880455E0, (ts4_word)(ts4_word)lbl_88CB4B9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6E98: call_seq lbl_8804DDC4, lbl_88CB4BCC, lbl_880459F8, lbl_88CB4C5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8804DDC4_889E6E98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4C5C, (ts4_word)(ts4_word)lbl_880459F8, (ts4_word)(ts4_word)lbl_88CB4BCC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804DDC4, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6F00: call_seq lbl_88B49994, lbl_88045070, lbl_88CB4C8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49994_889E6F00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4C8C, (ts4_word)(ts4_word)lbl_88045070, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49994, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6F70: call_seq lbl_88B499C8, lbl_88CB4C5C, lbl_88041DE0, lbl_88CB4CBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B499C8_889E6F70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4CBC, (ts4_word)(ts4_word)lbl_88041DE0, (ts4_word)(ts4_word)lbl_88CB4C5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B499C8, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E6FE8: call_seq lbl_88B49A70, lbl_88CB303C, lbl_8803F5D4, lbl_88CB4CEC, lbl_8804DE44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49A70_889E6FE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4CEC, (ts4_word)(ts4_word)lbl_8803F5D4, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804DE44, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B49A70, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7058: call_seq lbl_88B49A88, lbl_88CB4DAC, lbl_880402B0, lbl_88CB4D1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49A88_889E7058(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4D1C, (ts4_word)(ts4_word)lbl_880402B0, (ts4_word)(ts4_word)lbl_88CB4DAC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49A88, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E70D0: call_seq lbl_88CB4D7C, lbl_88040E04, lbl_88CB4D4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB4D7C_889E70D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4D4C, (ts4_word)(ts4_word)lbl_88040E04, (ts4_word)(ts4_word)lbl_88CB4D7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7138: call_seq lbl_88B49AA0, lbl_88CB4DAC, lbl_8803EFA8, lbl_88CB4D7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49AA0_889E7138(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4D7C, (ts4_word)(ts4_word)lbl_8803EFA8, (ts4_word)(ts4_word)lbl_88CB4DAC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49AA0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E71B0: call_seq lbl_88B49AD0, lbl_88CB4CEC, lbl_88040290, lbl_88CB4DAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49AD0_889E71B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4DAC, (ts4_word)(ts4_word)lbl_88040290, (ts4_word)(ts4_word)lbl_88CB4CEC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49AD0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7228: call_seq lbl_88CB4DAC, lbl_880402A0, lbl_88CB4DDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB4DAC_889E7228(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4DDC, (ts4_word)(ts4_word)lbl_880402A0, (ts4_word)(ts4_word)lbl_88CB4DAC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7290: call_seq lbl_88CB4D1C, lbl_88040E18, lbl_88CB4E0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB4D1C_889E7290(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4E0C, (ts4_word)(ts4_word)lbl_88040E18, (ts4_word)(ts4_word)lbl_88CB4D1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E72F8: call_seq lbl_88CB4DDC, lbl_88040E68, lbl_88CB4E3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB4DDC_889E72F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4E3C, (ts4_word)(ts4_word)lbl_88040E68, (ts4_word)(ts4_word)lbl_88CB4DDC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7360: call_seq lbl_88CB4D1C, lbl_88040DB0, lbl_88CB4E6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB4D1C_889E7360(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4E6C, (ts4_word)(ts4_word)lbl_88040DB0, (ts4_word)(ts4_word)lbl_88CB4D1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E73C8: call_seq lbl_88B49B78, lbl_88CB4EFC, lbl_8803F6D8, lbl_88CB4E9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49B78_889E73C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4E9C, (ts4_word)(ts4_word)lbl_8803F6D8, (ts4_word)(ts4_word)lbl_88CB4EFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49B78, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7440: call_seq lbl_88B49BA8, lbl_88CB4F2C, lbl_88045914, lbl_88CB4ECC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49BA8_889E7440(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4ECC, (ts4_word)(ts4_word)lbl_88045914, (ts4_word)(ts4_word)lbl_88CB4F2C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49BA8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E74B8: call_seq lbl_88B49BC0, lbl_88CB501C, lbl_88047070, lbl_88CB4EFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49BC0_889E74B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4EFC, (ts4_word)(ts4_word)lbl_88047070, (ts4_word)(ts4_word)lbl_88CB501C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49BC0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7530: call_seq lbl_88B49BF0, lbl_88CB4EFC, lbl_880402BC, lbl_88CB4F2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49BF0_889E7530(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4F2C, (ts4_word)(ts4_word)lbl_880402BC, (ts4_word)(ts4_word)lbl_88CB4EFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49BF0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E75A8: call_seq lbl_88B49C08, lbl_88CB4F2C, lbl_88045580, lbl_88CB4F5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49C08_889E75A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4F5C, (ts4_word)(ts4_word)lbl_88045580, (ts4_word)(ts4_word)lbl_88CB4F2C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49C08, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7620: call_seq lbl_88B49C24, lbl_8803F9C0, lbl_88CB4F8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49C24_889E7620(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4F8C, (ts4_word)(ts4_word)lbl_8803F9C0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49C24, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7690: call_seq lbl_88B49C58, lbl_88CB303C, lbl_8803F660, lbl_88CB4FBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49C58_889E7690(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB4FBC, (ts4_word)(ts4_word)lbl_8803F660, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49C58, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7708: get u32@lbl_88B49CF0, lbl_88B4B8E8, u32@lbl_88B49CEC, u32@lbl_88B49CE8, u32@0x50, u32@0x110 */
void ts4_get_u32_lbl_88B49CF0_889E7708(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88B49CF0;
    t2 = *(ts4_word *)lbl_88B49CEC;
    t3 = *(ts4_word *)lbl_88B49CE8;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B4B8E8) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B4B8E8) + 272) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B4B8E8) + 560) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x889E77B0: call_seq lbl_88B49CF8, lbl_88CB303C, lbl_8803F084, lbl_88CB501C, lbl_8804DED4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49CF8_889E77B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB501C, (ts4_word)(ts4_word)lbl_8803F084, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804DED4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B49CF8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7828: call_seq lbl_88B49D70, lbl_88CB303C, lbl_8804707C, lbl_88CB504C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49D70_889E7828(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB504C, (ts4_word)(ts4_word)lbl_8804707C, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49D70, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}
