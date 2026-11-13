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

extern char ts4_addr_lbl_8803A308_88AFF4E8[];
extern char lbl_8803C97C[];
extern char lbl_8803C9DC[];
extern char lbl_8803CAF0[];
extern char lbl_8803CC5C[];
extern char lbl_8803CCC4[];
extern char lbl_8803CCD4[];
extern char lbl_8803D124[];
extern char lbl_8803D194[];
extern char lbl_8803D2E0[];
extern char lbl_8803D6A0[];
extern char lbl_8803D914[];
extern char lbl_8803D9E8[];
extern char lbl_8803EC3C[];
extern char lbl_8803EC6C[];
extern char lbl_8803EC94[];
extern char lbl_8803ECB0[];
extern char lbl_8803ECD0[];
extern char lbl_8803ECF4[];
extern char lbl_8803ED14[];
extern char lbl_8803ED20[];
extern char lbl_8803ED28[];
extern char lbl_8803ED7C[];
extern char lbl_8803EE0C[];
extern char lbl_8803EE24[];
extern char lbl_8803EE34[];
extern char lbl_8803EE48[];
extern char lbl_8803EE7C[];
extern char lbl_8803EE88[];
extern char lbl_8803EEE8[];
extern char lbl_8803EEFC[];
extern char lbl_8803EF04[];
extern char lbl_8803EF18[];
extern char lbl_8803EF34[];
extern char lbl_8803EF48[];
extern char lbl_8803EF58[];
extern char lbl_8803EF6C[];
extern char lbl_8803EF80[];
extern char lbl_8803EF90[];
extern char lbl_8803EF9C[];
extern char lbl_8803EFA8[];
extern char lbl_8803EFD0[];
extern char lbl_8803EFE8[];
extern char lbl_8803EFFC[];
extern char lbl_8803F00C[];
extern char lbl_8803F030[];
extern char lbl_8803F048[];
extern char lbl_8803F064[];
extern char lbl_8803F084[];
extern char lbl_8803F094[];
extern char lbl_8803F0AC[];
extern char lbl_8803F0C8[];
extern char lbl_8803F5C8[];
extern char lbl_8803F5D4[];
extern char lbl_8803F5F4[];
extern char lbl_8803F610[];
extern char lbl_8803F634[];
extern char lbl_8803F64C[];
extern char lbl_8803F660[];
extern char lbl_8803F670[];
extern char lbl_8803F690[];
extern char lbl_8803F6B0[];
extern char lbl_8803F6CC[];
extern char lbl_8803F6D8[];
extern char lbl_8803F9D4[];
extern char lbl_8803FA04[];
extern char lbl_8803FA18[];
extern char lbl_8803FBF4[];
extern char lbl_8804002C[];
extern char lbl_88040040[];
extern char lbl_88040078[];
extern char lbl_880400BC[];
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
extern char lbl_880404B8[];
extern char lbl_880404E0[];
extern char lbl_88040508[];
extern char lbl_88040534[];
extern char lbl_88040560[];
extern char lbl_88040590[];
extern char lbl_88040608[];
extern char lbl_88040630[];
extern char lbl_88040658[];
extern char lbl_88040668[];
extern char lbl_88040E04[];
extern char lbl_88040E18[];
extern char lbl_88040E68[];
extern char lbl_88041DE0[];
extern char lbl_88042170[];
extern char lbl_880422F8[];
extern char lbl_88042380[];
extern char lbl_88042390[];
extern char lbl_880423A4[];
extern char lbl_880423C0[];
extern char lbl_880423D4[];
extern char lbl_880423F8[];
extern char lbl_88042408[];
extern char lbl_88042E20[];
extern char lbl_88043ED0[];
extern char lbl_88044268[];
extern char lbl_88044324[];
extern char lbl_88044370[];
extern char lbl_880443CC[];
extern char lbl_88044438[];
extern char lbl_8804449C[];
extern char lbl_880444CC[];
extern char lbl_88044524[];
extern char lbl_88044568[];
extern char lbl_880445A8[];
extern char lbl_880445E4[];
extern char lbl_8804461C[];
extern char lbl_88044650[];
extern char lbl_88044680[];
extern char lbl_880446BC[];
extern char lbl_88044700[];
extern char lbl_88044744[];
extern char lbl_88044758[];
extern char lbl_88044784[];
extern char lbl_880447B8[];
extern char lbl_880447EC[];
extern char lbl_8804481C[];
extern char lbl_8804484C[];
extern char lbl_88044874[];
extern char lbl_8804489C[];
extern char lbl_880448C8[];
extern char lbl_880448FC[];
extern char lbl_88044924[];
extern char lbl_8804494C[];
extern char lbl_88044A08[];
extern char lbl_88044B54[];
extern char lbl_88044BD4[];
extern char lbl_88044C08[];
extern char lbl_88044C48[];
extern char lbl_88044C84[];
extern char lbl_88044CD0[];
extern char lbl_88044D60[];
extern char lbl_88044D8C[];
extern char lbl_88044DD0[];
extern char lbl_88044DF8[];
extern char lbl_88044E30[];
extern char lbl_88044E64[];
extern char lbl_88044EA8[];
extern char lbl_88044F10[];
extern char lbl_88044F38[];
extern char lbl_88044F90[];
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
extern char lbl_880462E8[];
extern char lbl_88046498[];
extern char lbl_88046574[];
extern char lbl_880466D4[];
extern char lbl_8804675C[];
extern char lbl_8804696C[];
extern char lbl_88046AB4[];
extern char lbl_88046C00[];
extern char lbl_88046C24[];
extern char lbl_88046C48[];
extern char lbl_88046C60[];
extern char lbl_88046C78[];
extern char lbl_88046C94[];
extern char lbl_88047050[];
extern char lbl_8804705C[];
extern char lbl_88047070[];
extern char lbl_8804707C[];
extern char lbl_8804B9D8[];
extern char lbl_8804BC48[];
extern char lbl_8804BC64[];
extern char lbl_8804BC90[];
extern char lbl_8804BCCC[];
extern char lbl_8804BD8C[];
extern char lbl_8804BDC8[];
extern char lbl_8804BDFC[];
extern char lbl_8804BE58[];
extern char lbl_8804BE6C[];
extern char lbl_8804BF60[];
extern char lbl_8804BF78[];
extern char lbl_8804C310[];
extern char lbl_8804C33C[];
extern char lbl_8804C348[];
extern char lbl_8804C358[];
extern char lbl_8804C380[];
extern char lbl_8804CB30[];
extern char lbl_8804CB7C[];
extern char lbl_8804CBA8[];
extern char lbl_8804CBEC[];
extern char lbl_8804CC28[];
extern char lbl_88B3ECB0[];
extern char lbl_88B3ED10[];
extern char lbl_88B3ED28[];
extern char lbl_88B3ED58[];
extern char lbl_88B3ED88[];
extern char lbl_88B3EDB8[];
extern char lbl_88B3EE00[];
extern char lbl_88B3EEC0[];
extern char lbl_88B3EF08[];
extern char lbl_88B3EF68[];
extern char lbl_88B3EFE0[];
extern char lbl_88B3EFF8[];
extern char lbl_88B3F040[];
extern char lbl_88B3F088[];
extern char lbl_88B3F0D0[];
extern char lbl_88B3F0E8[];
extern char lbl_88B3F118[];
extern char lbl_88B3F208[];
extern char lbl_88B3F20C[];
extern char lbl_88B3F23C[];
extern char lbl_88B3F240[];
extern char lbl_88B3F330[];
extern char lbl_88B3F378[];
extern char lbl_88B3F420[];
extern char lbl_88B3F438[];
extern char lbl_88B3F498[];
extern char lbl_88B3F4B0[];
extern char lbl_88B3F4E0[];
extern char lbl_88B3F4F8[];
extern char lbl_88B3F510[];
extern char lbl_88B3F544[];
extern char lbl_88B3F55C[];
extern char lbl_88B3F560[];
extern char lbl_88B3F5C0[];
extern char lbl_88B3F5F0[];
extern char lbl_88B3F638[];
extern char lbl_88B3F668[];
extern char lbl_88B3F698[];
extern char lbl_88B3F6F8[];
extern char lbl_88B3F740[];
extern char lbl_88B3F7B8[];
extern char lbl_88B3F818[];
extern char lbl_88B3F830[];
extern char lbl_88B3F890[];
extern char lbl_88B3F8C0[];
extern char lbl_88B3F8F0[];
extern char lbl_88B3F968[];
extern char lbl_88B3F970[];
extern char lbl_88B3F9B8[];
extern char lbl_88B3FA00[];
extern char lbl_88B3FA78[];
extern char lbl_88B3FAC0[];
extern char lbl_88B3FB08[];
extern char lbl_88B3FB80[];
extern char lbl_88B3FBC8[];
extern char lbl_88B3FC10[];
extern char lbl_88B3FCD0[];
extern char lbl_88B3FD18[];
extern char lbl_88B3FD48[];
extern char lbl_88B3FDD8[];
extern char lbl_88B3FE68[];
extern char lbl_88B3FF10[];
extern char lbl_88B3FF28[];
extern char lbl_88B3FFA0[];
extern char lbl_88B3FFE8[];
extern char lbl_88B40180[];
extern char lbl_88B401B0[];
extern char lbl_88B4025C[];
extern char lbl_88B40274[];
extern char lbl_88B4028C[];
extern char lbl_88B402A8[];
extern char lbl_88B40350[];
extern char lbl_88B40380[];
extern char lbl_88B40398[];
extern char lbl_88B403C8[];
extern char lbl_88B403E0[];
extern char lbl_88B403F8[];
extern char lbl_88B40488[];
extern char lbl_88B4048C[];
extern char lbl_88B40498[];
extern char lbl_88B40510[];
extern char lbl_88B40528[];
extern char lbl_88B40540[];
extern char lbl_88B40558[];
extern char lbl_88B405A0[];
extern char lbl_88B405B8[];
extern char lbl_88B405E8[];
extern char lbl_88B40630[];
extern char lbl_88B40690[];
extern char lbl_88B406F0[];
extern char lbl_88B40750[];
extern char lbl_88B40810[];
extern char lbl_88B40930[];
extern char lbl_88B40948[];
extern char lbl_88B40978[];
extern char lbl_88B409A8[];
extern char lbl_88B409C0[];
extern char lbl_88B40A50[];
extern char lbl_88B40A80[];
extern char lbl_88B40AB0[];
extern char lbl_88B40AC8[];
extern char lbl_88B40AE0[];
extern char lbl_88B40B10[];
extern char lbl_88B40B28[];
extern char lbl_88B40C00[];
extern char lbl_88B40DB0[];
extern char lbl_88B40F48[];
extern char lbl_88B411B8[];
extern char lbl_88B41230[];
extern char lbl_88B41278[];
extern char lbl_88B412A8[];
extern char lbl_88B41308[];
extern char lbl_88B41368[];
extern char lbl_88B41458[];
extern char lbl_88B414A0[];
extern char lbl_88B414E8[];
extern char lbl_88B41500[];
extern char lbl_88B41548[];
extern char lbl_88B41560[];
extern char lbl_88B41608[];
extern char lbl_88B41638[];
extern char lbl_88B41680[];
extern char lbl_88B416C8[];
extern char lbl_88B41710[];
extern char lbl_88B41728[];
extern char lbl_88B41740[];
extern char lbl_88B41938[];
extern char lbl_88B41A58[];
extern char lbl_88B41A70[];
extern char lbl_88B41AB8[];
extern char lbl_88B41B78[];
extern char lbl_88B41BD8[];
extern char lbl_88B41E00[];
extern char lbl_88B41E78[];
extern char lbl_88B41EA8[];
extern char lbl_88B41ED8[];
extern char lbl_88B41F08[];
extern char lbl_88B41F68[];
extern char lbl_88B41FC8[];
extern char lbl_88B42058[];
extern char lbl_88B42070[];
extern char lbl_88B420D0[];
extern char lbl_88B42178[];
extern char lbl_88B42190[];
extern char lbl_88B421F0[];
extern char lbl_88B42208[];
extern char lbl_88B42250[];
extern char lbl_88B422E0[];
extern char lbl_88B42370[];
extern char lbl_88B423D0[];
extern char lbl_88B42400[];
extern char lbl_88B42448[];
extern char lbl_88B42490[];
extern char lbl_88B424C0[];
extern char lbl_88B42568[];
extern char lbl_88B42598[];
extern char lbl_88B425C8[];
extern char lbl_88B425D4[];
extern char lbl_88B42604[];
extern char lbl_88B42638[];
extern char lbl_88B42698[];
extern char lbl_88B42758[];
extern char lbl_88B42770[];
extern char lbl_88B427E8[];
extern char lbl_88B42878[];
extern char lbl_88B428A8[];
extern char lbl_88B42950[];
extern char lbl_88B42958[];
extern char lbl_88B42988[];
extern char lbl_88B42A30[];
extern char lbl_88B42A48[];
extern char lbl_88B42A78[];
extern char lbl_88B42A7C[];
extern char lbl_88B42A98[];
extern char lbl_88B46340[];
extern char lbl_88B46400[];
extern char lbl_88B46478[];
extern char lbl_88CAD81C[];
extern char lbl_88CADF3C[];
extern char lbl_88CADFFC[];
extern char lbl_88CAE11C[];
extern char lbl_88CAE1DC[];
extern char lbl_88CAE23C[];
extern char lbl_88CAE26C[];
extern char lbl_88CAE41C[];
extern char lbl_88CAE4DC[];
extern char lbl_88CAE50C[];
extern char lbl_88CAE53C[];
extern char lbl_88CAE56C[];
extern char lbl_88CAE59C[];
extern char lbl_88CAE5CC[];
extern char lbl_88CAE5FC[];
extern char lbl_88CAE62C[];
extern char lbl_88CAE65C[];
extern char lbl_88CAE68C[];
extern char lbl_88CAE6BC[];
extern char lbl_88CAE6EC[];
extern char lbl_88CAE71C[];
extern char lbl_88CAE74C[];
extern char lbl_88CAE77C[];
extern char lbl_88CAE7AC[];
extern char lbl_88CAE7DC[];
extern char lbl_88CAE80C[];
extern char lbl_88CAE83C[];
extern char lbl_88CAE86C[];
extern char lbl_88CAE89C[];
extern char lbl_88CAE8CC[];
extern char lbl_88CAE8FC[];
extern char lbl_88CAE92C[];
extern char lbl_88CAE95C[];
extern char lbl_88CAE98C[];
extern char lbl_88CAE9BC[];
extern char lbl_88CAE9EC[];
extern char lbl_88CAEA1C[];
extern char lbl_88CAEA4C[];
extern char lbl_88CAEA7C[];
extern char lbl_88CAEAAC[];
extern char lbl_88CAEADC[];
extern char lbl_88CAEB0C[];
extern char lbl_88CAEB3C[];
extern char lbl_88CAEB6C[];
extern char lbl_88CAEB9C[];
extern char lbl_88CAEBCC[];
extern char lbl_88CAEBFC[];
extern char lbl_88CAEC2C[];
extern char lbl_88CAEC5C[];
extern char lbl_88CAEC8C[];
extern char lbl_88CAECBC[];
extern char lbl_88CAECEC[];
extern char lbl_88CAED1C[];
extern char lbl_88CAED4C[];
extern char lbl_88CAED7C[];
extern char lbl_88CAEDAC[];
extern char lbl_88CAEDDC[];
extern char lbl_88CAEE0C[];
extern char lbl_88CAEE3C[];
extern char lbl_88CAEE6C[];
extern char lbl_88CAEE9C[];
extern char lbl_88CAEECC[];
extern char lbl_88CAEEFC[];
extern char lbl_88CAEF2C[];
extern char lbl_88CAEF5C[];
extern char lbl_88CAEF8C[];
extern char lbl_88CAEFBC[];
extern char lbl_88CAEFEC[];
extern char lbl_88CAF01C[];
extern char lbl_88CAF04C[];
extern char lbl_88CAF07C[];
extern char lbl_88CAF0AC[];
extern char lbl_88CAF0DC[];
extern char lbl_88CAF10C[];
extern char lbl_88CAF13C[];
extern char lbl_88CAF16C[];
extern char lbl_88CAF19C[];
extern char lbl_88CAF1CC[];
extern char lbl_88CAF1FC[];
extern char lbl_88CAF22C[];
extern char lbl_88CAF25C[];
extern char lbl_88CAF28C[];
extern char lbl_88CAF2BC[];
extern char lbl_88CAF2EC[];
extern char lbl_88CAF31C[];
extern char lbl_88CAF34C[];
extern char lbl_88CAF37C[];
extern char lbl_88CAF3AC[];
extern char lbl_88CAF3DC[];
extern char lbl_88CAF40C[];
extern char lbl_88CAF43C[];
extern char lbl_88CAF46C[];
extern char lbl_88CAF49C[];
extern char lbl_88CAF4CC[];
extern char lbl_88CAF4FC[];
extern char lbl_88CAF52C[];
extern char lbl_88CAF55C[];
extern char lbl_88CAF58C[];
extern char lbl_88CAF5BC[];
extern char lbl_88CAF5EC[];
extern char lbl_88CAF61C[];
extern char lbl_88CAF64C[];
extern char lbl_88CAF67C[];
extern char lbl_88CAF6AC[];
extern char lbl_88CAF6DC[];
extern char lbl_88CAF70C[];
extern char lbl_88CAF73C[];
extern char lbl_88CAF76C[];
extern char lbl_88CAF79C[];
extern char lbl_88CAF7CC[];
extern char lbl_88CAF7FC[];
extern char lbl_88CAF82C[];
extern char lbl_88CAF85C[];
extern char lbl_88CAF88C[];
extern char lbl_88CAF8BC[];
extern char lbl_88CAF8EC[];
extern char lbl_88CAF91C[];
extern char lbl_88CAF94C[];
extern char lbl_88CAF97C[];
extern char lbl_88CAF9AC[];
extern char lbl_88CAF9DC[];
extern char lbl_88CAFA0C[];
extern char lbl_88CAFA3C[];
extern char lbl_88CAFA6C[];
extern char lbl_88CAFA9C[];
extern char lbl_88CAFACC[];
extern char lbl_88CAFAFC[];
extern char lbl_88CAFB2C[];
extern char lbl_88CAFB5C[];
extern char lbl_88CAFB8C[];
extern char lbl_88CAFBBC[];
extern char lbl_88CAFBEC[];
extern char lbl_88CAFC1C[];
extern char lbl_88CAFC4C[];
extern char lbl_88CAFC7C[];
extern char lbl_88CAFCAC[];
extern char lbl_88CAFCDC[];
extern char lbl_88CAFD0C[];
extern char lbl_88CAFD3C[];
extern char lbl_88CAFD6C[];
extern char lbl_88CAFD9C[];
extern char lbl_88CAFDCC[];
extern char lbl_88CAFDFC[];
extern char lbl_88CAFE2C[];
extern char lbl_88CAFE5C[];
extern char lbl_88CAFE8C[];
extern char lbl_88CAFEBC[];
extern char lbl_88CAFEEC[];
extern char lbl_88CAFF1C[];
extern char lbl_88CAFF4C[];
extern char lbl_88CAFF7C[];
extern char lbl_88CAFFAC[];
extern char lbl_88CAFFDC[];
extern char lbl_88CB000C[];
extern char lbl_88CB003C[];
extern char lbl_88CB006C[];
extern char lbl_88CB0084[];
extern char lbl_88CB00B4[];
extern char lbl_88CB00E4[];
extern char lbl_88CB0114[];
extern char lbl_88CB0144[];
extern char lbl_88CB0174[];
extern char lbl_88CB01A4[];
extern char lbl_88CB01D4[];
extern char lbl_88CB0204[];
extern char lbl_88CB0234[];
extern char lbl_88CB0264[];
extern char lbl_88CB0294[];
extern char lbl_88CB02C4[];
extern char lbl_88CB02F4[];
extern char lbl_88CB0324[];
extern char lbl_88CB0354[];
extern char lbl_88CB0384[];
extern char lbl_88CB03B4[];
extern char lbl_88CB03E4[];
extern char lbl_88CB0414[];
extern char lbl_88CB0444[];
extern char lbl_88CB0474[];
extern char lbl_88CB04A4[];
extern char lbl_88CB04D4[];
extern char lbl_88CB0504[];
extern char lbl_88CB0534[];
extern char lbl_88CB0564[];
extern char lbl_88CB0594[];
extern char lbl_88CB05C4[];
extern char lbl_88CB05F4[];
extern char lbl_88CB0624[];
extern char lbl_88CB0654[];
extern char lbl_88CB0684[];
extern char lbl_88CB06B4[];
extern char lbl_88CB06E4[];
extern char lbl_88CB0714[];
extern char lbl_88CB0744[];
extern char lbl_88CB0774[];
extern char lbl_88CB07A4[];
extern char lbl_88CB07D4[];
extern char lbl_88CB0804[];
extern char lbl_88CB0834[];
extern char lbl_88CB0864[];
extern char lbl_88CB0894[];
ts4_word fn_8841F080();
ts4_word ts4_set_u32_offc_884CE988();
ts4_word fn_88563470();

/* Swing_DLL.xex 0x889D7490: call_seq lbl_88B41938, lbl_8803EFE8, lbl_88CAE4DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41938_889D7490(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE4DC, (ts4_word)(ts4_word)lbl_8803EFE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41938, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7500: call_seq lbl_88B3ECB0, lbl_88CAE23C, lbl_8803EF9C, lbl_88CAE50C, lbl_8804BC48, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3ECB0_889D7500(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE50C, (ts4_word)(ts4_word)lbl_8803EF9C, (ts4_word)(ts4_word)lbl_88CAE23C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804BC48, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B3ECB0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7578: call_seq lbl_88B3ED10, lbl_88CAE1DC, lbl_880423C0, lbl_88CAE53C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3ED10_889D7578(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE53C, (ts4_word)(ts4_word)lbl_880423C0, (ts4_word)(ts4_word)lbl_88CAE1DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3ED10, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D75F0: call_seq lbl_88B3ED28, lbl_880462E8, lbl_88CAE56C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3ED28_889D75F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE56C, (ts4_word)(ts4_word)lbl_880462E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3ED28, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7660: call_seq lbl_88B3ED58, lbl_88CAE11C, lbl_8804675C, lbl_88CAE59C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3ED58_889D7660(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE59C, (ts4_word)(ts4_word)lbl_8804675C, (ts4_word)(ts4_word)lbl_88CAE11C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3ED58, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D76D8: call_seq lbl_88B3ED88, lbl_88CAE71C, lbl_8803F9D4, lbl_88CAE5CC, lbl_8804BC64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3ED88_889D76D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE5CC, (ts4_word)(ts4_word)lbl_8803F9D4, (ts4_word)(ts4_word)lbl_88CAE71C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804BC64, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B3ED88, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7750: call_seq lbl_88CAE11C, lbl_88046AB4, lbl_88CAE5FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAE11C_889D7750(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE5FC, (ts4_word)(ts4_word)lbl_88046AB4, (ts4_word)(ts4_word)lbl_88CAE11C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D77B8: call_seq lbl_88B3EDB8, lbl_88CAE41C, lbl_880466D4, lbl_88CAE62C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EDB8_889D77B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE62C, (ts4_word)(ts4_word)lbl_880466D4, (ts4_word)(ts4_word)lbl_88CAE41C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EDB8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7830: call_seq lbl_88B3EE00, lbl_88CAE41C, lbl_8803EF18, lbl_88CAE65C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EE00_889D7830(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE65C, (ts4_word)(ts4_word)lbl_8803EF18, (ts4_word)(ts4_word)lbl_88CAE41C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EE00, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D78A8: call_seq lbl_88B3EEC0, lbl_880423A4, lbl_88CAE68C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EEC0_889D78A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE68C, (ts4_word)(ts4_word)lbl_880423A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EEC0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7918: call_seq lbl_88B3EF08, lbl_88CAE23C, lbl_88042390, lbl_88CAE6BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EF08_889D7918(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE6BC, (ts4_word)(ts4_word)lbl_88042390, (ts4_word)(ts4_word)lbl_88CAE23C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EF08, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7990: call_seq lbl_88CAE26C, lbl_88043ED0, lbl_88CAE6EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAE26C_889D7990(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE6EC, (ts4_word)(ts4_word)lbl_88043ED0, (ts4_word)(ts4_word)lbl_88CAE26C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D79F8: call_seq lbl_88CAE11C, lbl_8804696C, lbl_88CAE71C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAE11C_889D79F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE71C, (ts4_word)(ts4_word)lbl_8804696C, (ts4_word)(ts4_word)lbl_88CAE11C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7A60: call_seq lbl_88B3EF68, lbl_8803F00C, lbl_88CAE74C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EF68_889D7A60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE74C, (ts4_word)(ts4_word)lbl_8803F00C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EF68, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7AD0: call_seq lbl_88B3EFE0, lbl_88CAE50C, lbl_88046574, lbl_88CAE77C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EFE0_889D7AD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE77C, (ts4_word)(ts4_word)lbl_88046574, (ts4_word)(ts4_word)lbl_88CAE50C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EFE0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7B48: call_seq lbl_88B3EFF8, lbl_88CAE11C, lbl_880400BC, lbl_88CAE7AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EFF8_889D7B48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE7AC, (ts4_word)(ts4_word)lbl_880400BC, (ts4_word)(ts4_word)lbl_88CAE11C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EFF8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7BC0: call_seq lbl_88B3F040, lbl_88CAE26C, lbl_88042380, lbl_88CAE7DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F040_889D7BC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE7DC, (ts4_word)(ts4_word)lbl_88042380, (ts4_word)(ts4_word)lbl_88CAE26C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F040, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7C38: call_seq lbl_88B3F088, lbl_8803FBF4, lbl_88CAE80C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F088_889D7C38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE80C, (ts4_word)(ts4_word)lbl_8803FBF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F088, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7CA8: call_seq lbl_88B3F0D0, lbl_88CAE1DC, lbl_880423D4, lbl_88CAE83C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F0D0_889D7CA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE83C, (ts4_word)(ts4_word)lbl_880423D4, (ts4_word)(ts4_word)lbl_88CAE1DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F0D0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7D20: call_seq lbl_88B3F0E8, lbl_88CAE23C, lbl_88046498, lbl_88CAE86C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F0E8_889D7D20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE86C, (ts4_word)(ts4_word)lbl_88046498, (ts4_word)(ts4_word)lbl_88CAE23C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F0E8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7D98: call_seq lbl_88B3F118, lbl_88CAE8CC, lbl_8803EE34, lbl_88CAE89C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F118_889D7D98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE89C, (ts4_word)(ts4_word)lbl_8803EE34, (ts4_word)(ts4_word)lbl_88CAE8CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F118, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7E10: addr lbl_88B41A58, u32@lbl_88B3F208, u32@0x8 */
void ts4_addr_lbl_88B41A58_889D7E10(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B41A58) + 8) = (ts4_word)(*(ts4_word *)lbl_88B3F208);
    return;
}

/* Swing_DLL.xex 0x889D7E28: call_seq lbl_88B41A58, lbl_8803EE0C, lbl_88CAE8CC, lbl_8804BC90, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41A58_889D7E28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE8CC, (ts4_word)(ts4_word)lbl_8803EE0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804BC90, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B41A58, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7E98: call_seq lbl_88B3F20C, lbl_8803EE24, lbl_88CAE8FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F20C_889D7E98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE8FC, (ts4_word)(ts4_word)lbl_8803EE24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F20C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7F08: call_seq lbl_88B3F240, lbl_88044324, lbl_88CAE92C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F240_889D7F08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE92C, (ts4_word)(ts4_word)lbl_88044324, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F240, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7F78: call_seq lbl_88B3F330, lbl_88044370, lbl_88CAE95C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F330_889D7F78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE95C, (ts4_word)(ts4_word)lbl_88044370, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F330, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7FE8: call_seq lbl_88B3F378, lbl_8803F610, lbl_88CAE98C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F378_889D7FE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE98C, (ts4_word)(ts4_word)lbl_8803F610, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F378, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8058: call_seq lbl_88B3F420, lbl_8803F634, lbl_88CAE9BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F420_889D8058(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE9BC, (ts4_word)(ts4_word)lbl_8803F634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F420, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D80C8: call_seq lbl_88B3F438, lbl_88CAD81C, lbl_88047050, lbl_88CAE9EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F438_889D80C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE9EC, (ts4_word)(ts4_word)lbl_88047050, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F438, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8140: call_seq lbl_88B3F498, lbl_88CAE9EC, lbl_88045B44, lbl_88CAEA1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F498_889D8140(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEA1C, (ts4_word)(ts4_word)lbl_88045B44, (ts4_word)(ts4_word)lbl_88CAE9EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F498, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D81B8: call_seq lbl_88B3F4B0, lbl_88CAE9EC, lbl_88045B24, lbl_88CAEA4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F4B0_889D81B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEA4C, (ts4_word)(ts4_word)lbl_88045B24, (ts4_word)(ts4_word)lbl_88CAE9EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F4B0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8230: call_seq lbl_88B3F4E0, lbl_88CAE9EC, lbl_880459C0, lbl_88CAEA7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F4E0_889D8230(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEA7C, (ts4_word)(ts4_word)lbl_880459C0, (ts4_word)(ts4_word)lbl_88CAE9EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F4E0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D82A8: addr lbl_88B41A70, u32@lbl_88B3F23C, u32@0x8 */
void ts4_addr_lbl_88B41A70_889D82A8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B41A70) + 8) = (ts4_word)(*(ts4_word *)lbl_88B3F23C);
    return;
}

/* Swing_DLL.xex 0x889D82C0: call_seq lbl_88B41A70, lbl_88045224, lbl_88CAEAAC, lbl_8804BCCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41A70_889D82C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEAAC, (ts4_word)(ts4_word)lbl_88045224, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804BCCC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B41A70, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8330: call_seq lbl_88B3F4F8, lbl_88045194, lbl_88CAEADC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F4F8_889D8330(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEADC, (ts4_word)(ts4_word)lbl_88045194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F4F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D83A0: call_seq lbl_88B3F510, lbl_8803EF90, lbl_88CAEB0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F510_889D83A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEB0C, (ts4_word)(ts4_word)lbl_8803EF90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F510, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8410: call_seq lbl_88B3F544, lbl_88CAD81C, lbl_8803FA04, lbl_88CAEB3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F544_889D8410(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEB3C, (ts4_word)(ts4_word)lbl_8803FA04, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F544, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8488: call_seq lbl_88B3F560, lbl_88042170, lbl_88CAEB6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F560_889D8488(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEB6C, (ts4_word)(ts4_word)lbl_88042170, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F560, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D84F8: addr lbl_88B41AB8, u32@lbl_88B3F55C, u32@0x50 */
void ts4_addr_lbl_88B41AB8_889D84F8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B41AB8) + 80) = (ts4_word)(*(ts4_word *)lbl_88B3F55C);
    return;
}

/* Swing_DLL.xex 0x889D8510: call_seq lbl_88B41AB8, lbl_88CAD81C, lbl_8803F0C8, lbl_88CAEB9C, lbl_8804BD8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41AB8_889D8510(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEB9C, (ts4_word)(ts4_word)lbl_8803F0C8, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804BD8C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B41AB8, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8588: call_seq lbl_88B3F5C0, lbl_88CAEB3C, lbl_880403DC, lbl_88CAEBCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F5C0_889D8588(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEBCC, (ts4_word)(ts4_word)lbl_880403DC, (ts4_word)(ts4_word)lbl_88CAEB3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F5C0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8600: call_seq lbl_88B3F5F0, lbl_88040630, lbl_88CAEBFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F5F0_889D8600(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEBFC, (ts4_word)(ts4_word)lbl_88040630, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F5F0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8670: call_seq lbl_88B3F638, lbl_88040608, lbl_88CAEC2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F638_889D8670(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEC2C, (ts4_word)(ts4_word)lbl_88040608, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F638, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D86E0: call_seq lbl_88B3F668, lbl_88CAEB3C, lbl_88040394, lbl_88CAEC5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F668_889D86E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEC5C, (ts4_word)(ts4_word)lbl_88040394, (ts4_word)(ts4_word)lbl_88CAEB3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F668, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8758: call_seq lbl_88B3F698, lbl_88040590, lbl_88CAEC8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F698_889D8758(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEC8C, (ts4_word)(ts4_word)lbl_88040590, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F698, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D87C8: call_seq lbl_88B3F6F8, lbl_88040560, lbl_88CAECBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F6F8_889D87C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAECBC, (ts4_word)(ts4_word)lbl_88040560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F6F8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8838: call_seq lbl_88B3F740, lbl_88CAEB3C, lbl_8803F690, lbl_88CAECEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F740_889D8838(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAECEC, (ts4_word)(ts4_word)lbl_8803F690, (ts4_word)(ts4_word)lbl_88CAEB3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F740, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D88B0: call_seq lbl_88B3F7B8, lbl_88CAED4C, lbl_8803EF80, lbl_88CAED1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F7B8_889D88B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAED1C, (ts4_word)(ts4_word)lbl_8803EF80, (ts4_word)(ts4_word)lbl_88CAED4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F7B8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8928: call_seq lbl_88B3F818, lbl_88CAD81C, lbl_8803EF34, lbl_88CAED4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F818_889D8928(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAED4C, (ts4_word)(ts4_word)lbl_8803EF34, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F818, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D89A0: call_seq lbl_88B3F830, lbl_88CAED4C, lbl_8803EF6C, lbl_88CAED7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F830_889D89A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAED7C, (ts4_word)(ts4_word)lbl_8803EF6C, (ts4_word)(ts4_word)lbl_88CAED4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F830, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8A18: call_seq lbl_88B3F890, lbl_88CAED4C, lbl_8803EF58, lbl_88CAEDAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F890_889D8A18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEDAC, (ts4_word)(ts4_word)lbl_8803EF58, (ts4_word)(ts4_word)lbl_88CAED4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F890, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8A90: call_seq lbl_88B3F8C0, lbl_88CAED4C, lbl_8803EF48, lbl_88CAEDDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F8C0_889D8A90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEDDC, (ts4_word)(ts4_word)lbl_8803EF48, (ts4_word)(ts4_word)lbl_88CAED4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F8C0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8B08: call_seq lbl_88B3F8F0, lbl_88CAEE3C, lbl_88045734, lbl_88CAEE0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F8F0_889D8B08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEE0C, (ts4_word)(ts4_word)lbl_88045734, (ts4_word)(ts4_word)lbl_88CAEE3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F8F0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8B80: call_seq lbl_88CAD81C, lbl_88045A30, lbl_88CAEE3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAD81C_889D8B80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEE3C, (ts4_word)(ts4_word)lbl_88045A30, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8BE8: addr lbl_88B41B78, u32@lbl_88B3F968, u32@0x38 */
void ts4_addr_lbl_88B41B78_889D8BE8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B41B78) + 56) = (ts4_word)(*(ts4_word *)lbl_88B3F968);
    return;
}

/* Swing_DLL.xex 0x889D8C00: call_seq lbl_88B41B78, lbl_88CAEB3C, lbl_88040364, lbl_88CAEE6C, lbl_8804BDC8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41B78_889D8C00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEE6C, (ts4_word)(ts4_word)lbl_88040364, (ts4_word)(ts4_word)lbl_88CAEB3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804BDC8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B41B78, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8C78: call_seq lbl_88B3F970, lbl_88CAEB3C, lbl_88040344, lbl_88CAEE9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F970_889D8C78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEE9C, (ts4_word)(ts4_word)lbl_88040344, (ts4_word)(ts4_word)lbl_88CAEB3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F970, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8CF0: call_seq lbl_88B3F9B8, lbl_88CAECEC, lbl_8803F064, lbl_88CAEECC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3F9B8_889D8CF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEECC, (ts4_word)(ts4_word)lbl_8803F064, (ts4_word)(ts4_word)lbl_88CAECEC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3F9B8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8D68: call_seq lbl_88B3FA00, lbl_88CAF01C, lbl_8803F670, lbl_88CAEEFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3FA00_889D8D68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEEFC, (ts4_word)(ts4_word)lbl_8803F670, (ts4_word)(ts4_word)lbl_88CAF01C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3FA00, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8DE0: call_seq lbl_88B3FA78, lbl_88040534, lbl_88CAEF2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3FA78_889D8DE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEF2C, (ts4_word)(ts4_word)lbl_88040534, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3FA78, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8E50: call_seq lbl_88B3FAC0, lbl_88040508, lbl_88CAEF5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3FAC0_889D8E50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEF5C, (ts4_word)(ts4_word)lbl_88040508, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3FAC0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8EC0: call_seq lbl_88B3FB08, lbl_88CAEB3C, lbl_8803F048, lbl_88CAEF8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3FB08_889D8EC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEF8C, (ts4_word)(ts4_word)lbl_8803F048, (ts4_word)(ts4_word)lbl_88CAEB3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3FB08, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8F38: call_seq lbl_88B3FB80, lbl_880404E0, lbl_88CAEFBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3FB80_889D8F38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEFBC, (ts4_word)(ts4_word)lbl_880404E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3FB80, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D8FA8: call_seq lbl_88B3FBC8, lbl_880404B8, lbl_88CAEFEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3FBC8_889D8FA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAEFEC, (ts4_word)(ts4_word)lbl_880404B8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3FBC8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9018: call_seq lbl_88B3FC10, lbl_88CAEB3C, lbl_8803F030, lbl_88CAF01C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3FC10_889D9018(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF01C, (ts4_word)(ts4_word)lbl_8803F030, (ts4_word)(ts4_word)lbl_88CAEB3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3FC10, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9090: call_seq lbl_88B3FCD0, lbl_88CAEB3C, lbl_880402E4, lbl_88CAF04C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3FCD0_889D9090(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF04C, (ts4_word)(ts4_word)lbl_880402E4, (ts4_word)(ts4_word)lbl_88CAEB3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3FCD0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9108: call_seq lbl_88B3FD18, lbl_88040424, lbl_88CAF07C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3FD18_889D9108(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF07C, (ts4_word)(ts4_word)lbl_88040424, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3FD18, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9178: call_seq lbl_88B3FD48, lbl_880403FC, lbl_88CAF0AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3FD48_889D9178(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF0AC, (ts4_word)(ts4_word)lbl_880403FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3FD48, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D91E8: call_seq lbl_88B3FDD8, lbl_88CAEB3C, lbl_880402CC, lbl_88CAF0DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3FDD8_889D91E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF0DC, (ts4_word)(ts4_word)lbl_880402CC, (ts4_word)(ts4_word)lbl_88CAEB3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3FDD8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9260: call_seq lbl_88B3FE68, lbl_88CAEB3C, lbl_8803F6B0, lbl_88CAF10C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3FE68_889D9260(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF10C, (ts4_word)(ts4_word)lbl_8803F6B0, (ts4_word)(ts4_word)lbl_88CAEB3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3FE68, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D92D8: call_seq lbl_88B3FF10, lbl_88CAEB3C, lbl_880403AC, lbl_88CAF13C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3FF10_889D92D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF13C, (ts4_word)(ts4_word)lbl_880403AC, (ts4_word)(ts4_word)lbl_88CAEB3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3FF10, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9350: call_seq lbl_88B3FF28, lbl_880422F8, lbl_88CAF16C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3FF28_889D9350(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF16C, (ts4_word)(ts4_word)lbl_880422F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3FF28, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D93C0: call_seq lbl_88B3FFA0, lbl_88CAEB3C, lbl_8803FA18, lbl_88CAF19C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3FFA0_889D93C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF19C, (ts4_word)(ts4_word)lbl_8803FA18, (ts4_word)(ts4_word)lbl_88CAEB3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3FFA0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9438: call_seq lbl_88B3FFE8, lbl_88CAF5EC, lbl_8803F6CC, lbl_88CAF1CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3FFE8_889D9438(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF1CC, (ts4_word)(ts4_word)lbl_8803F6CC, (ts4_word)(ts4_word)lbl_88CAF5EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3FFE8, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D94B0: call_seq lbl_88CAD81C, lbl_88045AA8, lbl_88CAF1FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAD81C_889D94B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF1FC, (ts4_word)(ts4_word)lbl_88045AA8, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9518: call_seq lbl_88CAF28C, lbl_880457FC, lbl_88CAF22C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAF28C_889D9518(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF22C, (ts4_word)(ts4_word)lbl_880457FC, (ts4_word)(ts4_word)lbl_88CAF28C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9580: call_seq lbl_88CAF1CC, lbl_880455E0, lbl_88CAF25C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAF1CC_889D9580(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF25C, (ts4_word)(ts4_word)lbl_880455E0, (ts4_word)(ts4_word)lbl_88CAF1CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D95E8: call_seq lbl_8804BDFC, lbl_88CAF1FC, lbl_880459F8, lbl_88CAF28C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8804BDFC_889D95E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF28C, (ts4_word)(ts4_word)lbl_880459F8, (ts4_word)(ts4_word)lbl_88CAF1FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804BDFC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9650: call_seq lbl_88B40180, lbl_88045070, lbl_88CAF2BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40180_889D9650(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF2BC, (ts4_word)(ts4_word)lbl_88045070, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40180, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D96C0: call_seq lbl_88B401B0, lbl_88CAF28C, lbl_88041DE0, lbl_88CAF2EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B401B0_889D96C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF2EC, (ts4_word)(ts4_word)lbl_88041DE0, (ts4_word)(ts4_word)lbl_88CAF28C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B401B0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9738: call_seq lbl_88B4025C, lbl_88CAD81C, lbl_8803F5D4, lbl_88CAF31C, lbl_8804BE58, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4025C_889D9738(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF31C, (ts4_word)(ts4_word)lbl_8803F5D4, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804BE58, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B4025C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D97A8: call_seq lbl_88B40274, lbl_88CAF3DC, lbl_880402B0, lbl_88CAF34C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40274_889D97A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF34C, (ts4_word)(ts4_word)lbl_880402B0, (ts4_word)(ts4_word)lbl_88CAF3DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40274, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9820: call_seq lbl_88CAF3AC, lbl_88040E04, lbl_88CAF37C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAF3AC_889D9820(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF37C, (ts4_word)(ts4_word)lbl_88040E04, (ts4_word)(ts4_word)lbl_88CAF3AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9888: call_seq lbl_88B4028C, lbl_88CAF3DC, lbl_8803EFA8, lbl_88CAF3AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4028C_889D9888(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF3AC, (ts4_word)(ts4_word)lbl_8803EFA8, (ts4_word)(ts4_word)lbl_88CAF3DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4028C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9900: call_seq lbl_88B402A8, lbl_88CAF31C, lbl_88040290, lbl_88CAF3DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B402A8_889D9900(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF3DC, (ts4_word)(ts4_word)lbl_88040290, (ts4_word)(ts4_word)lbl_88CAF31C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B402A8, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9978: call_seq lbl_88CAF3DC, lbl_880402A0, lbl_88CAF40C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAF3DC_889D9978(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF40C, (ts4_word)(ts4_word)lbl_880402A0, (ts4_word)(ts4_word)lbl_88CAF3DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D99E0: call_seq lbl_88CAF34C, lbl_88040E18, lbl_88CAF43C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAF34C_889D99E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF43C, (ts4_word)(ts4_word)lbl_88040E18, (ts4_word)(ts4_word)lbl_88CAF34C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9A48: call_seq lbl_88CAF40C, lbl_88040E68, lbl_88CAF46C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAF40C_889D9A48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF46C, (ts4_word)(ts4_word)lbl_88040E68, (ts4_word)(ts4_word)lbl_88CAF40C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9AB0: call_seq lbl_88B40350, lbl_88CAF4FC, lbl_8803F6D8, lbl_88CAF49C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40350_889D9AB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF49C, (ts4_word)(ts4_word)lbl_8803F6D8, (ts4_word)(ts4_word)lbl_88CAF4FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40350, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9B28: call_seq lbl_88B40380, lbl_88CAF52C, lbl_88045914, lbl_88CAF4CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40380_889D9B28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF4CC, (ts4_word)(ts4_word)lbl_88045914, (ts4_word)(ts4_word)lbl_88CAF52C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40380, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9BA0: call_seq lbl_88B40398, lbl_88CAF5EC, lbl_88047070, lbl_88CAF4FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40398_889D9BA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF4FC, (ts4_word)(ts4_word)lbl_88047070, (ts4_word)(ts4_word)lbl_88CAF5EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40398, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9C18: call_seq lbl_88B403C8, lbl_88CAF4FC, lbl_880402BC, lbl_88CAF52C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B403C8_889D9C18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF52C, (ts4_word)(ts4_word)lbl_880402BC, (ts4_word)(ts4_word)lbl_88CAF4FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B403C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9C90: call_seq lbl_88B403E0, lbl_88CAF52C, lbl_88045580, lbl_88CAF55C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B403E0_889D9C90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF55C, (ts4_word)(ts4_word)lbl_88045580, (ts4_word)(ts4_word)lbl_88CAF52C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B403E0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9D08: call_seq lbl_88B403F8, lbl_88CAD81C, lbl_8803F660, lbl_88CAF58C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B403F8_889D9D08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF58C, (ts4_word)(ts4_word)lbl_8803F660, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B403F8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9D80: addr lbl_88B41BD8, u32@lbl_88B4048C, u32@lbl_88B40488, u32@0xe0, u32@0x200 */
void ts4_addr_lbl_88B41BD8_889D9D80(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88B4048C;
    t2 = *(ts4_word *)lbl_88B40488;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B41BD8) + 224) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B41BD8) + 512) = (ts4_word)t2;
    return;
}

/* Swing_DLL.xex 0x889D9DA8: call_seq lbl_88B41BD8, lbl_88CAD81C, lbl_8803EFFC, lbl_88CAF5BC, lbl_8804BE6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41BD8_889D9DA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF5BC, (ts4_word)(ts4_word)lbl_8803EFFC, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804BE6C, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B41BD8, (ts4_word)23, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9E20: call_seq lbl_88B40498, lbl_88CAD81C, lbl_8803F084, lbl_88CAF5EC, lbl_8804BF60, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40498_889D9E20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF5EC, (ts4_word)(ts4_word)lbl_8803F084, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804BF60, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B40498, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9E98: call_seq lbl_88B40510, lbl_88CAD81C, lbl_8804707C, lbl_88CAF61C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40510_889D9E98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF61C, (ts4_word)(ts4_word)lbl_8804707C, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40510, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9F10: call_seq lbl_88B40528, lbl_88CADF3C, lbl_88044F38, lbl_88CAF64C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40528_889D9F10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF64C, (ts4_word)(ts4_word)lbl_88044F38, (ts4_word)(ts4_word)lbl_88CADF3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40528, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9F88: call_seq lbl_88B40540, lbl_88042E20, lbl_88CAF67C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40540_889D9F88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF67C, (ts4_word)(ts4_word)lbl_88042E20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40540, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D9FF8: call_seq lbl_88B40558, lbl_8803EFD0, lbl_88CAF6AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40558_889D9FF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF6AC, (ts4_word)(ts4_word)lbl_8803EFD0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40558, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA068: call_seq lbl_88B405A0, lbl_88044F10, lbl_88CAF6DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B405A0_889DA068(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF6DC, (ts4_word)(ts4_word)lbl_88044F10, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B405A0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA0D8: call_seq lbl_88B405B8, lbl_88CAD81C, lbl_88044F90, lbl_88CAF70C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B405B8_889DA0D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF70C, (ts4_word)(ts4_word)lbl_88044F90, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B405B8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA150: call_seq lbl_88B405E8, lbl_88CAEA4C, lbl_88044EA8, lbl_88CAF73C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B405E8_889DA150(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF73C, (ts4_word)(ts4_word)lbl_88044EA8, (ts4_word)(ts4_word)lbl_88CAEA4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B405E8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA1C8: call_seq lbl_88B40630, lbl_88CAEA4C, lbl_88044E64, lbl_88CAF76C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40630_889DA1C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF76C, (ts4_word)(ts4_word)lbl_88044E64, (ts4_word)(ts4_word)lbl_88CAEA4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40630, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA240: call_seq lbl_88B40690, lbl_88CAEA7C, lbl_88044DD0, lbl_88CAF79C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40690_889DA240(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF79C, (ts4_word)(ts4_word)lbl_88044DD0, (ts4_word)(ts4_word)lbl_88CAEA7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40690, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA2B8: call_seq lbl_88B406F0, lbl_88CAEA7C, lbl_88044CD0, lbl_88CAF7CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B406F0_889DA2B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF7CC, (ts4_word)(ts4_word)lbl_88044CD0, (ts4_word)(ts4_word)lbl_88CAEA7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B406F0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA330: call_seq lbl_88B40750, lbl_88CAEA4C, lbl_88044BD4, lbl_88CAF7FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40750_889DA330(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF7FC, (ts4_word)(ts4_word)lbl_88044BD4, (ts4_word)(ts4_word)lbl_88CAEA4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40750, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA3A8: call_seq lbl_88B40810, lbl_8803F094, lbl_88CAF82C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40810_889DA3A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF82C, (ts4_word)(ts4_word)lbl_8803F094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40810, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA418: call_seq lbl_88CADFFC, lbl_8803F0AC, lbl_88CAF85C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CADFFC_889DA418(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF85C, (ts4_word)(ts4_word)lbl_8803F0AC, (ts4_word)(ts4_word)lbl_88CADFFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA480: call_seq lbl_88B40930, lbl_88CADFFC, lbl_88044E30, lbl_88CAF88C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40930_889DA480(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF88C, (ts4_word)(ts4_word)lbl_88044E30, (ts4_word)(ts4_word)lbl_88CADFFC, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40930, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA4F8: call_seq lbl_88B40948, lbl_88CADFFC, lbl_88044DF8, lbl_88CAF8BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40948_889DA4F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF8BC, (ts4_word)(ts4_word)lbl_88044DF8, (ts4_word)(ts4_word)lbl_88CADFFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40948, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA570: call_seq lbl_88B40978, lbl_88044B54, lbl_88CAF8EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40978_889DA570(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF8EC, (ts4_word)(ts4_word)lbl_88044B54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40978, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA5E0: call_seq lbl_88B409A8, lbl_88CADFFC, lbl_88044D8C, lbl_88CAF91C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B409A8_889DA5E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF91C, (ts4_word)(ts4_word)lbl_88044D8C, (ts4_word)(ts4_word)lbl_88CADFFC, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B409A8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA658: call_seq lbl_88B409C0, lbl_88CAEA7C, lbl_8804705C, lbl_88CAF94C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B409C0_889DA658(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF94C, (ts4_word)(ts4_word)lbl_8804705C, (ts4_word)(ts4_word)lbl_88CAEA7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B409C0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA6D0: call_seq lbl_88B40A50, lbl_88CAD81C, lbl_8803ED7C, lbl_88CAF97C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40A50_889DA6D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF97C, (ts4_word)(ts4_word)lbl_8803ED7C, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40A50, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA748: call_seq lbl_88B40A80, lbl_88CAD81C, lbl_88044D60, lbl_88CAF9AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40A80_889DA748(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF9AC, (ts4_word)(ts4_word)lbl_88044D60, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40A80, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA7C0: call_seq lbl_88B40AB0, lbl_88CAD81C, lbl_88044C84, lbl_88CAF9DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40AB0_889DA7C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAF9DC, (ts4_word)(ts4_word)lbl_88044C84, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40AB0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA838: call_seq lbl_88B40AC8, lbl_88CAD81C, lbl_88044C48, lbl_88CAFA0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40AC8_889DA838(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFA0C, (ts4_word)(ts4_word)lbl_88044C48, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40AC8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA8B0: call_seq lbl_88B40AE0, lbl_88044A08, lbl_88CAFA3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40AE0_889DA8B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFA3C, (ts4_word)(ts4_word)lbl_88044A08, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40AE0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA920: call_seq lbl_88B40B10, lbl_88CAD81C, lbl_88044C08, lbl_88CAFA6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40B10_889DA920(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFA6C, (ts4_word)(ts4_word)lbl_88044C08, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40B10, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DA998: call_seq lbl_88B40B28, lbl_88040668, lbl_88CAFA9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40B28_889DA998(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFA9C, (ts4_word)(ts4_word)lbl_88040668, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40B28, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DAA08: call_seq lbl_88B40C00, lbl_88CAD81C, lbl_88040658, lbl_88CAFACC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40C00_889DAA08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFACC, (ts4_word)(ts4_word)lbl_88040658, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40C00, (ts4_word)18, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DAA80: call_seq lbl_88B40DB0, lbl_8803F5F4, lbl_88CAFAFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40DB0_889DAA80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFAFC, (ts4_word)(ts4_word)lbl_8803F5F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40DB0, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DAAF0: call_seq lbl_88B40F48, lbl_88CAEA7C, lbl_8803F64C, lbl_88CAFB2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B40F48_889DAAF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFB2C, (ts4_word)(ts4_word)lbl_8803F64C, (ts4_word)(ts4_word)lbl_88CAEA7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B40F48, (ts4_word)26, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DAB68: call_seq lbl_88CAD81C, lbl_8804494C, lbl_88CAFB5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAD81C_889DAB68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFB5C, (ts4_word)(ts4_word)lbl_8804494C, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DABD0: call_seq lbl_88B411B8, lbl_88CAFB5C, lbl_88044700, lbl_88CAFB8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B411B8_889DABD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFB8C, (ts4_word)(ts4_word)lbl_88044700, (ts4_word)(ts4_word)lbl_88CAFB5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B411B8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DAC48: call_seq lbl_88CAD81C, lbl_88044924, lbl_88CAFBBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAD81C_889DAC48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFBBC, (ts4_word)(ts4_word)lbl_88044924, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DACB0: call_seq lbl_88B41230, lbl_88044438, lbl_88CAFBEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41230_889DACB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFBEC, (ts4_word)(ts4_word)lbl_88044438, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41230, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DAD20: call_seq lbl_88B41278, lbl_88CAFBBC, lbl_88044680, lbl_88CAFC1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41278_889DAD20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFC1C, (ts4_word)(ts4_word)lbl_88044680, (ts4_word)(ts4_word)lbl_88CAFBBC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41278, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DAD98: call_seq lbl_88CAD81C, lbl_880448C8, lbl_88CAFC4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAD81C_889DAD98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFC4C, (ts4_word)(ts4_word)lbl_880448C8, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DAE00: call_seq lbl_88CAD81C, lbl_880448FC, lbl_88CAFC7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAD81C_889DAE00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFC7C, (ts4_word)(ts4_word)lbl_880448FC, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DAE68: call_seq lbl_88B412A8, lbl_88CAFC4C, lbl_88044524, lbl_88CAFCAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B412A8_889DAE68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFCAC, (ts4_word)(ts4_word)lbl_88044524, (ts4_word)(ts4_word)lbl_88CAFC4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B412A8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DAEE0: call_seq lbl_88B41308, lbl_88CAFC7C, lbl_880446BC, lbl_88CAFCDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41308_889DAEE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFCDC, (ts4_word)(ts4_word)lbl_880446BC, (ts4_word)(ts4_word)lbl_88CAFC7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41308, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DAF58: call_seq lbl_88CAD81C, lbl_8804489C, lbl_88CAFD0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAD81C_889DAF58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFD0C, (ts4_word)(ts4_word)lbl_8804489C, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DAFC0: call_seq lbl_88B41368, lbl_88CAFD0C, lbl_88044650, lbl_88CAFD3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41368_889DAFC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFD3C, (ts4_word)(ts4_word)lbl_88044650, (ts4_word)(ts4_word)lbl_88CAFD0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41368, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB038: call_seq lbl_88CAD81C, lbl_88044874, lbl_88CAFD6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAD81C_889DB038(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFD6C, (ts4_word)(ts4_word)lbl_88044874, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB0A0: call_seq lbl_88B41458, lbl_88CAFD6C, lbl_8804461C, lbl_88CAFD9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41458_889DB0A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFD9C, (ts4_word)(ts4_word)lbl_8804461C, (ts4_word)(ts4_word)lbl_88CAFD6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41458, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB118: call_seq lbl_88B414A0, lbl_88044268, lbl_88CAFDCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B414A0_889DB118(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFDCC, (ts4_word)(ts4_word)lbl_88044268, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B414A0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB188: call_seq lbl_88B414E8, lbl_88CAD81C, lbl_8804484C, lbl_88CAFDFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B414E8_889DB188(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFDFC, (ts4_word)(ts4_word)lbl_8804484C, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B414E8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB200: call_seq lbl_88B41500, lbl_880443CC, lbl_88CAFE2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41500_889DB200(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFE2C, (ts4_word)(ts4_word)lbl_880443CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41500, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB270: call_seq lbl_88B41548, lbl_88CAFDFC, lbl_880445E4, lbl_88CAFE5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41548_889DB270(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFE5C, (ts4_word)(ts4_word)lbl_880445E4, (ts4_word)(ts4_word)lbl_88CAFDFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41548, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB2E8: call_seq lbl_88CAD81C, lbl_8804481C, lbl_88CAFE8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAD81C_889DB2E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFE8C, (ts4_word)(ts4_word)lbl_8804481C, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB350: call_seq lbl_88B41560, lbl_88CAFE8C, lbl_880445A8, lbl_88CAFEBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41560_889DB350(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFEBC, (ts4_word)(ts4_word)lbl_880445A8, (ts4_word)(ts4_word)lbl_88CAFE8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41560, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB3C8: call_seq lbl_88B41608, lbl_8804449C, lbl_88CAFEEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41608_889DB3C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFEEC, (ts4_word)(ts4_word)lbl_8804449C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41608, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB438: call_seq lbl_88B41638, lbl_88CAD81C, lbl_88044744, lbl_88CAFF1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41638_889DB438(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFF1C, (ts4_word)(ts4_word)lbl_88044744, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41638, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB4B0: call_seq lbl_88B41680, lbl_88CAD81C, lbl_88044758, lbl_88CAFF4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41680_889DB4B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFF4C, (ts4_word)(ts4_word)lbl_88044758, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41680, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB528: call_seq lbl_88CAD81C, lbl_880447EC, lbl_88CAFF7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAD81C_889DB528(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFF7C, (ts4_word)(ts4_word)lbl_880447EC, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB590: call_seq lbl_88B416C8, lbl_88CAFF7C, lbl_88044568, lbl_88CAFFAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B416C8_889DB590(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFFAC, (ts4_word)(ts4_word)lbl_88044568, (ts4_word)(ts4_word)lbl_88CAFF7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B416C8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB608: call_seq lbl_88B41710, lbl_88CAD81C, lbl_880447B8, lbl_88CAFFDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41710_889DB608(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAFFDC, (ts4_word)(ts4_word)lbl_880447B8, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41710, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB680: call_seq lbl_88B41728, lbl_88CAD81C, lbl_88044784, lbl_88CB000C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41728_889DB680(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB000C, (ts4_word)(ts4_word)lbl_88044784, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41728, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB6F8: call_seq lbl_88B41740, lbl_88CAFFDC, lbl_880444CC, lbl_88CB003C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41740_889DB6F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB003C, (ts4_word)(ts4_word)lbl_880444CC, (ts4_word)(ts4_word)lbl_88CAFFDC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41740, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB770: call_seq lbl_8804B9D8, lbl_8804BF78, lbl_88CB006C, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF4E8, fn_88563470 */
ts4_word ts4_call_seq_lbl_8804B9D8_889DB770(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CB006C, (ts4_word)(ts4_word)lbl_8804BF78, (ts4_word)1, (ts4_word)(ts4_word)lbl_8804B9D8);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF4E8);
    return t2;
}

/* Swing_DLL.xex 0x889DB7B8: call_seq lbl_88B41E00, lbl_88046C94, lbl_88CB0084, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41E00_889DB7B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0084, (ts4_word)(ts4_word)lbl_88046C94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41E00, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB828: call_seq lbl_88B41E78, lbl_8803EF04, lbl_88CB00B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41E78_889DB828(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB00B4, (ts4_word)(ts4_word)lbl_8803EF04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41E78, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB898: call_seq lbl_88B41EA8, lbl_88046C78, lbl_88CB00E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41EA8_889DB898(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB00E4, (ts4_word)(ts4_word)lbl_88046C78, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41EA8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB908: call_seq lbl_88B41ED8, lbl_8803EC6C, lbl_88CB0114, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41ED8_889DB908(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0114, (ts4_word)(ts4_word)lbl_8803EC6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41ED8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB978: call_seq lbl_88B41F08, lbl_88CB04A4, lbl_8803EE48, lbl_88CB0144, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41F08_889DB978(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0144, (ts4_word)(ts4_word)lbl_8803EE48, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41F08, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DB9F0: call_seq lbl_88B41F68, lbl_88040040, lbl_88CB0174, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41F68_889DB9F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0174, (ts4_word)(ts4_word)lbl_88040040, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41F68, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DBA60: call_seq lbl_88B41FC8, lbl_88CB0144, lbl_8803ECD0, lbl_88CB01A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41FC8_889DBA60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB01A4, (ts4_word)(ts4_word)lbl_8803ECD0, (ts4_word)(ts4_word)lbl_88CB0144, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B41FC8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DBAD8: call_seq lbl_88B42058, lbl_88CB0144, lbl_8803ECB0, lbl_88CB01D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42058_889DBAD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB01D4, (ts4_word)(ts4_word)lbl_8803ECB0, (ts4_word)(ts4_word)lbl_88CB0144, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42058, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DBB50: call_seq lbl_88B42070, lbl_88040078, lbl_88CB0204, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42070_889DBB50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0204, (ts4_word)(ts4_word)lbl_88040078, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42070, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DBBC0: call_seq lbl_88B420D0, lbl_88CB0144, lbl_8803EC94, lbl_88CB0234, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B420D0_889DBBC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0234, (ts4_word)(ts4_word)lbl_8803EC94, (ts4_word)(ts4_word)lbl_88CB0144, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B420D0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DBC38: call_seq lbl_88B42178, lbl_88046C60, lbl_88CB0264, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42178_889DBC38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0264, (ts4_word)(ts4_word)lbl_88046C60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42178, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DBCA8: call_seq lbl_88B42190, lbl_8803EE88, lbl_88CB0294, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42190_889DBCA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0294, (ts4_word)(ts4_word)lbl_8803EE88, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42190, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DBD18: call_seq lbl_88B421F0, lbl_88CB04A4, lbl_8804002C, lbl_88CB02C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B421F0_889DBD18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB02C4, (ts4_word)(ts4_word)lbl_8804002C, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B421F0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DBD90: call_seq lbl_88B42208, lbl_88046C00, lbl_88CB02F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42208_889DBD90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB02F4, (ts4_word)(ts4_word)lbl_88046C00, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42208, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DBE00: call_seq lbl_88B42250, lbl_88046C24, lbl_88CB0324, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42250_889DBE00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0324, (ts4_word)(ts4_word)lbl_88046C24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42250, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DBE70: call_seq lbl_88B422E0, lbl_88046C48, lbl_88CB0354, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B422E0_889DBE70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0354, (ts4_word)(ts4_word)lbl_88046C48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B422E0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DBEE0: call_seq lbl_88CB04A4, lbl_8803EC3C, lbl_88CB0384, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB04A4_889DBEE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0384, (ts4_word)(ts4_word)lbl_8803EC3C, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DBF48: call_seq lbl_88B42370, lbl_88CB0384, lbl_8803ECF4, lbl_88CB03B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42370_889DBF48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB03B4, (ts4_word)(ts4_word)lbl_8803ECF4, (ts4_word)(ts4_word)lbl_88CB0384, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42370, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DBFC0: call_seq lbl_88B423D0, lbl_8803EEFC, lbl_88CB03E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B423D0_889DBFC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB03E4, (ts4_word)(ts4_word)lbl_8803EEFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B423D0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC030: call_seq lbl_88B42400, lbl_8803EEE8, lbl_88CB0414, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42400_889DC030(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0414, (ts4_word)(ts4_word)lbl_8803EEE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42400, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC0A0: call_seq lbl_88B42448, lbl_8803EE7C, lbl_88CB0444, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42448_889DC0A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0444, (ts4_word)(ts4_word)lbl_8803EE7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42448, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC110: call_seq lbl_8803C97C, lbl_88CB0474, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803C97C_889DC110(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0474, (ts4_word)(ts4_word)lbl_8803C97C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC170: call_seq lbl_88B42490, lbl_88CB0474, lbl_8803C9DC, lbl_88CB04A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42490_889DC170(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)(ts4_word)lbl_8803C9DC, (ts4_word)(ts4_word)lbl_88CB0474, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42490, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC1E8: call_seq lbl_88B424C0, lbl_8803CC5C, lbl_88CB04D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B424C0_889DC1E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB04D4, (ts4_word)(ts4_word)lbl_8803CC5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B424C0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC258: call_seq lbl_88B42568, lbl_8803CCC4, lbl_88CB0504, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42568_889DC258(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0504, (ts4_word)(ts4_word)lbl_8803CCC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42568, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC2C8: call_seq lbl_88B42598, lbl_8803CCD4, lbl_88CB0534, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42598_889DC2C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0534, (ts4_word)(ts4_word)lbl_8803CCD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42598, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC338: addr lbl_88B46340, u32@lbl_88B425C8, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88B46340_889DC338(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B425C8;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B46340) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B46340) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x889DC358: call_seq lbl_88B46340, lbl_8803D124, lbl_88CB0564, lbl_8804CB30, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46340_889DC358(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0564, (ts4_word)(ts4_word)lbl_8803D124, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804CB30, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B46340, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC3C8: call_seq lbl_88B425D4, lbl_8803CAF0, lbl_88CB0594, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B425D4_889DC3C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0594, (ts4_word)(ts4_word)lbl_8803CAF0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B425D4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC438: call_seq lbl_88B42604, lbl_8803D194, lbl_88CB05C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42604_889DC438(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB05C4, (ts4_word)(ts4_word)lbl_8803D194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42604, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC4A8: call_seq lbl_88B42638, lbl_8803D2E0, lbl_88CB05F4, lbl_8804CB7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42638_889DC4A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB05F4, (ts4_word)(ts4_word)lbl_8803D2E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804CB7C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B42638, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC518: call_seq lbl_88B42698, lbl_8803D6A0, lbl_88CB0624, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42698_889DC518(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0624, (ts4_word)(ts4_word)lbl_8803D6A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42698, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC588: call_seq lbl_88B42758, lbl_8803D914, lbl_88CB0654, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42758_889DC588(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0654, (ts4_word)(ts4_word)lbl_8803D914, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42758, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC5F8: call_seq lbl_88B42770, lbl_8803D9E8, lbl_88CB0684, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42770_889DC5F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0684, (ts4_word)(ts4_word)lbl_8803D9E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42770, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC668: call_seq lbl_88B427E8, lbl_8803F5C8, lbl_88CB06B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B427E8_889DC668(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB06B4, (ts4_word)(ts4_word)lbl_8803F5C8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B427E8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC6D8: call_seq lbl_88B42878, lbl_8804C310, lbl_88CB06E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42878_889DC6D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB06E4, (ts4_word)(ts4_word)lbl_8804C310, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42878, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC748: call_seq lbl_88B428A8, lbl_8803ED20, lbl_88CB0714, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B428A8_889DC748(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0714, (ts4_word)(ts4_word)lbl_8803ED20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B428A8, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC7B8: addr lbl_88B46400, u32@lbl_88B42950, u32@0x8 */
void ts4_addr_lbl_88B46400_889DC7B8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B46400) + 8) = (ts4_word)(*(ts4_word *)lbl_88B42950);
    return;
}

/* Swing_DLL.xex 0x889DC7D0: call_seq lbl_88B46400, lbl_8804C33C, lbl_88CB0744, lbl_8804CBA8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46400_889DC7D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0744, (ts4_word)(ts4_word)lbl_8804C33C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804CBA8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B46400, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC840: call_seq lbl_88B42958, lbl_8803ED28, lbl_88CB0774, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42958_889DC840(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0774, (ts4_word)(ts4_word)lbl_8803ED28, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42958, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC8B0: call_seq lbl_88B42988, lbl_8803ED14, lbl_88CB07A4, lbl_8804CBEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42988_889DC8B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB07A4, (ts4_word)(ts4_word)lbl_8803ED14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804CBEC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B42988, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC920: call_seq lbl_88B42A30, lbl_8804C348, lbl_88CB07D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42A30_889DC920(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB07D4, (ts4_word)(ts4_word)lbl_8804C348, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42A30, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DC990: call_seq lbl_88B42A48, lbl_8804C358, lbl_88CB0804, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42A48_889DC990(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0804, (ts4_word)(ts4_word)lbl_8804C358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42A48, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DCA00: addr lbl_88B46478, u32@lbl_88B42A78, u32@0x8 */
void ts4_addr_lbl_88B46478_889DCA00(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B46478) + 8) = (ts4_word)(*(ts4_word *)lbl_88B42A78);
    return;
}

/* Swing_DLL.xex 0x889DCA18: call_seq lbl_88B46478, lbl_8804C380, lbl_88CB0834, lbl_8804CC28, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46478_889DCA18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0834, (ts4_word)(ts4_word)lbl_8804C380, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804CC28, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B46478, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DCA88: call_seq lbl_88B42A7C, lbl_88042408, lbl_88CB0864, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42A7C_889DCA88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0864, (ts4_word)(ts4_word)lbl_88042408, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42A7C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DCAF8: call_seq lbl_88B42A98, lbl_880423F8, lbl_88CB0894, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42A98_889DCAF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0894, (ts4_word)(ts4_word)lbl_880423F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42A98, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}
