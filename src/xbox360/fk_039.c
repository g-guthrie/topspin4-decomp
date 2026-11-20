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

extern char ts4_addr_lbl_8803A308_88AFF578[];
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
extern char lbl_8803EC6C[];
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
extern char lbl_8803EE48[];
extern char lbl_8803EE7C[];
extern char lbl_8803EE88[];
extern char lbl_8803EEE8[];
extern char lbl_8803EEFC[];
extern char lbl_8803EF04[];
extern char lbl_8803EF9C[];
extern char lbl_8803EFC0[];
extern char lbl_8803EFE8[];
extern char lbl_8803F00C[];
extern char lbl_8803F5BC[];
extern char lbl_8803F5C8[];
extern char lbl_8803F5E0[];
extern char lbl_8803F960[];
extern char lbl_8803F974[];
extern char lbl_8803F988[];
extern char lbl_8803F99C[];
extern char lbl_8803F9B0[];
extern char lbl_8803F9D4[];
extern char lbl_8804002C[];
extern char lbl_88040040[];
extern char lbl_88040078[];
extern char lbl_880400A8[];
extern char lbl_880400BC[];
extern char lbl_880400D0[];
extern char lbl_880400E8[];
extern char lbl_88040100[];
extern char lbl_88040110[];
extern char lbl_8804011C[];
extern char lbl_88040188[];
extern char lbl_8804019C[];
extern char lbl_880401B0[];
extern char lbl_880401D8[];
extern char lbl_880401F0[];
extern char lbl_88040200[];
extern char lbl_88040218[];
extern char lbl_88040228[];
extern char lbl_88040260[];
extern char lbl_88040278[];
extern char lbl_88041128[];
extern char lbl_88041138[];
extern char lbl_8804114C[];
extern char lbl_8804115C[];
extern char lbl_8804116C[];
extern char lbl_88041174[];
extern char lbl_88041194[];
extern char lbl_880411C8[];
extern char lbl_880411DC[];
extern char lbl_880411F0[];
extern char lbl_88041204[];
extern char lbl_88041224[];
extern char lbl_88041238[];
extern char lbl_8804124C[];
extern char lbl_88041268[];
extern char lbl_88041284[];
extern char lbl_8804159C[];
extern char lbl_880415B4[];
extern char lbl_88041634[];
extern char lbl_88041930[];
extern char lbl_88041B24[];
extern char lbl_88042110[];
extern char lbl_88042140[];
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
extern char lbl_880443CC[];
extern char lbl_8804449C[];
extern char lbl_880444CC[];
extern char lbl_88044568[];
extern char lbl_880445A8[];
extern char lbl_880445E4[];
extern char lbl_88044744[];
extern char lbl_88044758[];
extern char lbl_88044784[];
extern char lbl_880447B8[];
extern char lbl_880447EC[];
extern char lbl_8804481C[];
extern char lbl_88045224[];
extern char lbl_880459C0[];
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
extern char lbl_88046678[];
extern char lbl_880466D4[];
extern char lbl_8804671C[];
extern char lbl_8804675C[];
extern char lbl_880467DC[];
extern char lbl_88046868[];
extern char lbl_880468C8[];
extern char lbl_8804690C[];
extern char lbl_8804694C[];
extern char lbl_8804696C[];
extern char lbl_88046994[];
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
extern char lbl_88046C78[];
extern char lbl_88046C94[];
extern char lbl_88047050[];
extern char lbl_88048610[];
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
extern char lbl_8804E4DC[];
extern char lbl_8804E4F4[];
extern char lbl_8804E50C[];
extern char lbl_8804E524[];
extern char lbl_8804E53C[];
extern char lbl_8804E560[];
extern char lbl_8804E57C[];
extern char lbl_88051480[];
extern char lbl_88051E38[];
extern char lbl_88052B7C[];
extern char lbl_88052BB8[];
extern char lbl_88052BEC[];
extern char lbl_88052C60[];
extern char lbl_88052D2C[];
extern char lbl_88052DD0[];
extern char lbl_88052E28[];
extern char lbl_88052E40[];
extern char lbl_88052E9C[];
extern char lbl_88052ED8[];
extern char lbl_88052EF4[];
extern char lbl_88053068[];
extern char lbl_880530BC[];
extern char lbl_880530E0[];
extern char lbl_88053124[];
extern char lbl_88053150[];
extern char lbl_88053194[];
extern char lbl_880531D0[];
extern char lbl_8805320C[];
extern char lbl_88053220[];
extern char lbl_88053298[];
extern char lbl_880532D4[];
extern char lbl_88053328[];
extern char lbl_88053378[];
extern char lbl_88053DD8[];
extern char lbl_88053DE8[];
extern char lbl_88053E90[];
extern char lbl_88053EAC[];
extern char lbl_88053F68[];
extern char lbl_88054050[];
extern char lbl_88054068[];
extern char lbl_88B60EE8[];
extern char lbl_88B60F30[];
extern char lbl_88B60F48[];
extern char lbl_88B60FF0[];
extern char lbl_88B61020[];
extern char lbl_88B61068[];
extern char lbl_88B610B0[];
extern char lbl_88B610F8[];
extern char lbl_88B61110[];
extern char lbl_88B61128[];
extern char lbl_88B619F8[];
extern char lbl_88B61A70[];
extern char lbl_88B61A74[];
extern char lbl_88B61AA4[];
extern char lbl_88B61AD8[];
extern char lbl_88B61B38[];
extern char lbl_88B61BB0[];
extern char lbl_88B61C58[];
extern char lbl_88B61C70[];
extern char lbl_88B61CE8[];
extern char lbl_88B61D90[];
extern char lbl_88B61DA8[];
extern char lbl_88B61E08[];
extern char lbl_88B61E20[];
extern char lbl_88B61E68[];
extern char lbl_88B61EF8[];
extern char lbl_88B61F88[];
extern char lbl_88B61FE8[];
extern char lbl_88B62018[];
extern char lbl_88B62078[];
extern char lbl_88B620DC[];
extern char lbl_88B620E0[];
extern char lbl_88B621E8[];
extern char lbl_88B62320[];
extern char lbl_88B62338[];
extern char lbl_88B62350[];
extern char lbl_88B62380[];
extern char lbl_88B62410[];
extern char lbl_88B62458[];
extern char lbl_88B624D0[];
extern char lbl_88B62518[];
extern char lbl_88B62548[];
extern char lbl_88B62560[];
extern char lbl_88B62590[];
extern char lbl_88B62728[];
extern char lbl_88B62740[];
extern char lbl_88B627E8[];
extern char lbl_88B628C0[];
extern char lbl_88B629C8[];
extern char lbl_88B629F8[];
extern char lbl_88B629FC[];
extern char lbl_88B62A2C[];
extern char lbl_88B62A30[];
extern char lbl_88B62B50[];
extern char lbl_88B62CA0[];
extern char lbl_88B62D18[];
extern char lbl_88B62D1C[];
extern char lbl_88B62D38[];
extern char lbl_88B62D80[];
extern char lbl_88B62DC8[];
extern char lbl_88B62F18[];
extern char lbl_88B62F60[];
extern char lbl_88B62F68[];
extern char lbl_88B62FB0[];
extern char lbl_88B62FE0[];
extern char lbl_88B62FF8[];
extern char lbl_88B63028[];
extern char lbl_88B630D0[];
extern char lbl_88B63100[];
extern char lbl_88B63130[];
extern char lbl_88B6313C[];
extern char lbl_88B6316C[];
extern char lbl_88B63184[];
extern char lbl_88B63188[];
extern char lbl_88B631B8[];
extern char lbl_88B631EC[];
extern char lbl_88B631F0[];
extern char lbl_88B63250[];
extern char lbl_88B63310[];
extern char lbl_88B63328[];
extern char lbl_88B633A0[];
extern char lbl_88B633B8[];
extern char lbl_88B633E8[];
extern char lbl_88B63418[];
extern char lbl_88B63448[];
extern char lbl_88B63460[];
extern char lbl_88B63490[];
extern char lbl_88B634A8[];
extern char lbl_88B634D8[];
extern char lbl_88B63580[];
extern char lbl_88B635B0[];
extern char lbl_88B635C8[];
extern char lbl_88B635F8[];
extern char lbl_88B636B8[];
extern char lbl_88B636C0[];
extern char lbl_88B636F0[];
extern char lbl_88B637B0[];
extern char lbl_88B637B4[];
extern char lbl_88B637CC[];
extern char lbl_88B637FC[];
extern char lbl_88B63800[];
extern char lbl_88B63818[];
extern char lbl_88B63860[];
extern char lbl_88B63890[];
extern char lbl_88B639B0[];
extern char lbl_88B63A40[];
extern char lbl_88B63B00[];
extern char lbl_88B63BD8[];
extern char lbl_88B63C98[];
extern char lbl_88B63D40[];
extern char lbl_88B63E60[];
extern char lbl_88B63EC0[];
extern char lbl_88B63FC8[];
extern char lbl_88B640A0[];
extern char lbl_88B640E8[];
extern char lbl_88B64100[];
extern char lbl_88B64148[];
extern char lbl_88B64160[];
extern char lbl_88B641A8[];
extern char lbl_88B64208[];
extern char lbl_88B64250[];
extern char lbl_88B642B0[];
extern char lbl_88B642E0[];
extern char lbl_88B642F8[];
extern char lbl_88B64310[];
extern char lbl_88B64328[];
extern char lbl_88B64388[];
extern char lbl_88B643A0[];
extern char lbl_88B643D0[];
extern char lbl_88B643EC[];
extern char lbl_88B6441C[];
extern char lbl_88B64434[];
extern char lbl_88B6444C[];
extern char lbl_88B64468[];
extern char lbl_88B644B0[];
extern char lbl_88B644E0[];
extern char lbl_88B64510[];
extern char lbl_88B64558[];
extern char lbl_88B645D0[];
extern char lbl_88B64648[];
extern char lbl_88B64678[];
extern char lbl_88B64690[];
extern char lbl_88B646A8[];
extern char lbl_88B646B0[];
extern char lbl_88B64728[];
extern char lbl_88B64740[];
extern char lbl_88B64770[];
extern char lbl_88B647A0[];
extern char lbl_88B647D0[];
extern char lbl_88B64818[];
extern char lbl_88B648C0[];
extern char lbl_88B64908[];
extern char lbl_88B64968[];
extern char lbl_88B649F8[];
extern char lbl_88B64A10[];
extern char lbl_88B64A40[];
extern char lbl_88B64A88[];
extern char lbl_88B64AD0[];
extern char lbl_88B64AE8[];
extern char lbl_88B64B18[];
extern char lbl_88B64B78[];
extern char lbl_88B64B90[];
extern char lbl_88B64BC0[];
extern char lbl_88B64BD8[];
extern char lbl_88B67918[];
extern char lbl_88B67960[];
extern char lbl_88B67A80[];
extern char lbl_88B67C18[];
extern char lbl_88B67E28[];
extern char lbl_88B67EB8[];
extern char lbl_88B67F48[];
extern char lbl_88B68008[];
extern char lbl_88B68098[];
extern char lbl_88B680C8[];
extern char lbl_88B680F8[];
extern char lbl_88B68128[];
extern char lbl_88B681A0[];
extern char lbl_88B681E8[];
extern char lbl_88B68260[];
extern char lbl_88B68398[];
extern char lbl_88CBFA5C[];
extern char lbl_88CC275C[];
extern char lbl_88CC278C[];
extern char lbl_88CC27BC[];
extern char lbl_88CC27EC[];
extern char lbl_88CC281C[];
extern char lbl_88CC284C[];
extern char lbl_88CC287C[];
extern char lbl_88CC28AC[];
extern char lbl_88CC28DC[];
extern char lbl_88CC290C[];
extern char lbl_88CC293C[];
extern char lbl_88CC296C[];
extern char lbl_88CC299C[];
extern char lbl_88CC29CC[];
extern char lbl_88CC29E4[];
extern char lbl_88CC2A14[];
extern char lbl_88CC2A44[];
extern char lbl_88CC2A74[];
extern char lbl_88CC2AA4[];
extern char lbl_88CC2AD4[];
extern char lbl_88CC2B04[];
extern char lbl_88CC2B34[];
extern char lbl_88CC2B64[];
extern char lbl_88CC2B94[];
extern char lbl_88CC2BC4[];
extern char lbl_88CC2BF4[];
extern char lbl_88CC2C24[];
extern char lbl_88CC2C54[];
extern char lbl_88CC2C84[];
extern char lbl_88CC2CB4[];
extern char lbl_88CC2CE4[];
extern char lbl_88CC2D14[];
extern char lbl_88CC2D44[];
extern char lbl_88CC2D74[];
extern char lbl_88CC2DA4[];
extern char lbl_88CC2DD4[];
extern char lbl_88CC2E04[];
extern char lbl_88CC2E34[];
extern char lbl_88CC2E64[];
extern char lbl_88CC2E94[];
extern char lbl_88CC2EC4[];
extern char lbl_88CC2EF4[];
extern char lbl_88CC2F24[];
extern char lbl_88CC2F54[];
extern char lbl_88CC2F84[];
extern char lbl_88CC2FB4[];
extern char lbl_88CC3014[];
extern char lbl_88CC3044[];
extern char lbl_88CC3074[];
extern char lbl_88CC30A4[];
extern char lbl_88CC30D4[];
extern char lbl_88CC3104[];
extern char lbl_88CC3134[];
extern char lbl_88CC3164[];
extern char lbl_88CC3194[];
extern char lbl_88CC31C4[];
extern char lbl_88CC3224[];
extern char lbl_88CC3284[];
extern char lbl_88CC32B4[];
extern char lbl_88CC32E4[];
extern char lbl_88CC3314[];
extern char lbl_88CC3344[];
extern char lbl_88CC3374[];
extern char lbl_88CC33A4[];
extern char lbl_88CC33D4[];
extern char lbl_88CC3404[];
extern char lbl_88CC3434[];
extern char lbl_88CC3464[];
extern char lbl_88CC3494[];
extern char lbl_88CC34C4[];
extern char lbl_88CC34F4[];
extern char lbl_88CC3524[];
extern char lbl_88CC3554[];
extern char lbl_88CC3584[];
extern char lbl_88CC35B4[];
extern char lbl_88CC35E4[];
extern char lbl_88CC3614[];
extern char lbl_88CC3644[];
extern char lbl_88CC3674[];
extern char lbl_88CC36A4[];
extern char lbl_88CC36D4[];
extern char lbl_88CC3704[];
extern char lbl_88CC3734[];
extern char lbl_88CC3764[];
extern char lbl_88CC3794[];
extern char lbl_88CC37C4[];
extern char lbl_88CC37F4[];
extern char lbl_88CC3824[];
extern char lbl_88CC3854[];
extern char lbl_88CC3884[];
extern char lbl_88CC38B4[];
extern char lbl_88CC38E4[];
extern char lbl_88CC3914[];
extern char lbl_88CC3944[];
extern char lbl_88CC3974[];
extern char lbl_88CC39A4[];
extern char lbl_88CC39D4[];
extern char lbl_88CC3A04[];
extern char lbl_88CC3A34[];
extern char lbl_88CC3A64[];
extern char lbl_88CC3A94[];
extern char lbl_88CC3AC4[];
extern char lbl_88CC3AF4[];
extern char lbl_88CC3B24[];
extern char lbl_88CC3B54[];
extern char lbl_88CC3B84[];
extern char lbl_88CC3BB4[];
extern char lbl_88CC3BE4[];
extern char lbl_88CC3C14[];
extern char lbl_88CC3C44[];
extern char lbl_88CC3C74[];
extern char lbl_88CC3CA4[];
extern char lbl_88CC3CD4[];
extern char lbl_88CC3D04[];
extern char lbl_88CC3D34[];
extern char lbl_88CC3D64[];
extern char lbl_88CC3D94[];
extern char lbl_88CC3DC4[];
extern char lbl_88CC3DF4[];
extern char lbl_88CC3E24[];
extern char lbl_88CC3E54[];
extern char lbl_88CC3E84[];
extern char lbl_88CC3EB4[];
extern char lbl_88CC3EE4[];
extern char lbl_88CC3F14[];
extern char lbl_88CC3F44[];
extern char lbl_88CC3F74[];
extern char lbl_88CC3FA4[];
extern char lbl_88CC3FD4[];
extern char lbl_88CC4004[];
extern char lbl_88CC4034[];
extern char lbl_88CC4064[];
extern char lbl_88CC4094[];
extern char lbl_88CC40C4[];
extern char lbl_88CC40F4[];
extern char lbl_88CC4124[];
extern char lbl_88CC4154[];
extern char lbl_88CC4184[];
extern char lbl_88CC41B4[];
extern char lbl_88CC41E4[];
extern char lbl_88CC4214[];
extern char lbl_88CC4244[];
extern char lbl_88CC4274[];
extern char lbl_88CC42A4[];
extern char lbl_88CC42D4[];
extern char lbl_88CC4304[];
extern char lbl_88CC4334[];
extern char lbl_88CC4364[];
extern char lbl_88CC4394[];
extern char lbl_88CC43C4[];
extern char lbl_88CC43F4[];
extern char lbl_88CC4424[];
extern char lbl_88CC4454[];
extern char lbl_88CC4484[];
extern char lbl_88CC44B4[];
extern char lbl_88CC44E4[];
extern char lbl_88CC4514[];
extern char lbl_88CC4544[];
extern char lbl_88CC4574[];
extern char lbl_88CC45A4[];
extern char lbl_88CC45D4[];
extern char lbl_88CC4604[];
extern char lbl_88CC4634[];
extern char lbl_88CC4664[];
extern char lbl_88CC4694[];
extern char lbl_88CC46C4[];
extern char lbl_88CC46F4[];
extern char lbl_88CC4724[];
extern char lbl_88CC4754[];
extern char lbl_88CC4784[];
extern char lbl_88CC47B4[];
extern char lbl_88CC47E4[];
extern char lbl_88CC4814[];
extern char lbl_88CC4844[];
extern char lbl_88CC4874[];
extern char lbl_88CC48A4[];
extern char lbl_88CC48D4[];
extern char lbl_88CC4904[];
extern char lbl_88CC4934[];
extern char lbl_88CC4964[];
extern char lbl_88CC4994[];
extern char lbl_88CC49C4[];
extern char lbl_88CC49F4[];
extern char lbl_88CC4A24[];
extern char lbl_88CC4A54[];
extern char lbl_88CC5864[];
ts4_word fn_8841F080();
ts4_word ts4_set_u32_offc_884CE988();
ts4_word fn_88563470();

/* Swing_DLL.xex 0x88A07FE8: call_seq lbl_88B60EE8, lbl_880443CC, lbl_88CC278C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60EE8_88A07FE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC278C, (ts4_word)(ts4_word)lbl_880443CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60EE8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08058: call_seq lbl_88B60F30, lbl_88CC275C, lbl_880445E4, lbl_88CC27BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60F30_88A08058(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC27BC, (ts4_word)(ts4_word)lbl_880445E4, (ts4_word)(ts4_word)lbl_88CC275C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60F30, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A080D0: call_seq lbl_88CBFA5C, lbl_8804481C, lbl_88CC27EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBFA5C_88A080D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC27EC, (ts4_word)(ts4_word)lbl_8804481C, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08138: call_seq lbl_88B60F48, lbl_88CC27EC, lbl_880445A8, lbl_88CC281C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60F48_88A08138(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC281C, (ts4_word)(ts4_word)lbl_880445A8, (ts4_word)(ts4_word)lbl_88CC27EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60F48, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A081B0: call_seq lbl_88B60FF0, lbl_8804449C, lbl_88CC284C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60FF0_88A081B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC284C, (ts4_word)(ts4_word)lbl_8804449C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60FF0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08220: call_seq lbl_88B61020, lbl_88CBFA5C, lbl_88044744, lbl_88CC287C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61020_88A08220(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC287C, (ts4_word)(ts4_word)lbl_88044744, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61020, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08298: call_seq lbl_88B61068, lbl_88CBFA5C, lbl_88044758, lbl_88CC28AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61068_88A08298(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC28AC, (ts4_word)(ts4_word)lbl_88044758, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61068, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08310: call_seq lbl_88CBFA5C, lbl_880447EC, lbl_88CC28DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBFA5C_88A08310(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC28DC, (ts4_word)(ts4_word)lbl_880447EC, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08378: call_seq lbl_88B610B0, lbl_88CC28DC, lbl_88044568, lbl_88CC290C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B610B0_88A08378(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC290C, (ts4_word)(ts4_word)lbl_88044568, (ts4_word)(ts4_word)lbl_88CC28DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B610B0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A083F0: call_seq lbl_88B610F8, lbl_88CBFA5C, lbl_880447B8, lbl_88CC293C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B610F8_88A083F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC293C, (ts4_word)(ts4_word)lbl_880447B8, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B610F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08468: call_seq lbl_88B61110, lbl_88CBFA5C, lbl_88044784, lbl_88CC296C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61110_88A08468(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC296C, (ts4_word)(ts4_word)lbl_88044784, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61110, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A084E0: call_seq lbl_88B61128, lbl_88CC293C, lbl_880444CC, lbl_88CC299C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61128_88A084E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC299C, (ts4_word)(ts4_word)lbl_880444CC, (ts4_word)(ts4_word)lbl_88CC293C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61128, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08558: call_seq lbl_88051480, lbl_88051E38, lbl_88CC29CC, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF578, fn_88563470 */
ts4_word ts4_call_seq_lbl_88051480_88A08558(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CC29CC, (ts4_word)(ts4_word)lbl_88051E38, (ts4_word)3, (ts4_word)(ts4_word)lbl_88051480);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF578);
    return t2;
}

/* Swing_DLL.xex 0x88A085A0: call_seq lbl_88B619F8, lbl_88046C94, lbl_88CC29E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B619F8_88A085A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC29E4, (ts4_word)(ts4_word)lbl_88046C94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B619F8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08610: addr lbl_88B67918, u32@lbl_88B61A70, u32@0x38 */
void ts4_addr_lbl_88B67918_88A08610(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B67918) + 56) = (ts4_word)(*(ts4_word *)lbl_88B61A70);
    return;
}

/* Swing_DLL.xex 0x88A08628: call_seq lbl_88052B7C, lbl_88B67918, lbl_8803EF04, lbl_88CC2A14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88052B7C_88A08628(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2A14, (ts4_word)(ts4_word)lbl_8803EF04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88052B7C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B67918, (ts4_word)3, (ts4_word)((ts4_word)lbl_88052B7C + 20), (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A086A0: call_seq lbl_88B61A74, lbl_88046C78, lbl_88CC2A44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61A74_88A086A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2A44, (ts4_word)(ts4_word)lbl_88046C78, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61A74, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08710: call_seq lbl_88B61AA4, lbl_8803EC6C, lbl_88CC2A74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61AA4_88A08710(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2A74, (ts4_word)(ts4_word)lbl_8803EC6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61AA4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08780: call_seq lbl_88B61AD8, lbl_88CC3554, lbl_8803EE48, lbl_88CC2AA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61AD8_88A08780(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2AA4, (ts4_word)(ts4_word)lbl_8803EE48, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61AD8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A087F8: call_seq lbl_88B61B38, lbl_88040040, lbl_88CC2AD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61B38_88A087F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2AD4, (ts4_word)(ts4_word)lbl_88040040, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61B38, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08868: call_seq lbl_88B61BB0, lbl_88CC2AA4, lbl_8803ECD0, lbl_88CC2B04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61BB0_88A08868(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2B04, (ts4_word)(ts4_word)lbl_8803ECD0, (ts4_word)(ts4_word)lbl_88CC2AA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61BB0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A088E0: call_seq lbl_88B61C58, lbl_88CC2AA4, lbl_8803ECB0, lbl_88CC2B34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61C58_88A088E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2B34, (ts4_word)(ts4_word)lbl_8803ECB0, (ts4_word)(ts4_word)lbl_88CC2AA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61C58, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08958: call_seq lbl_88B61C70, lbl_88040078, lbl_88CC2B64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61C70_88A08958(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2B64, (ts4_word)(ts4_word)lbl_88040078, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61C70, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A089C8: call_seq lbl_88B61CE8, lbl_88CC2AA4, lbl_8803EC94, lbl_88CC2B94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61CE8_88A089C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2B94, (ts4_word)(ts4_word)lbl_8803EC94, (ts4_word)(ts4_word)lbl_88CC2AA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61CE8, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08A40: call_seq lbl_88B61D90, lbl_88046C60, lbl_88CC2BC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61D90_88A08A40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2BC4, (ts4_word)(ts4_word)lbl_88046C60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61D90, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08AB0: call_seq lbl_88B61DA8, lbl_8803EE88, lbl_88CC2BF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61DA8_88A08AB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2BF4, (ts4_word)(ts4_word)lbl_8803EE88, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61DA8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08B20: call_seq lbl_88B61E08, lbl_88CC3554, lbl_8804002C, lbl_88CC2C24, lbl_88052BB8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61E08_88A08B20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2C24, (ts4_word)(ts4_word)lbl_8804002C, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88052BB8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B61E08, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08B90: call_seq lbl_88B61E20, lbl_88046C00, lbl_88CC2C54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61E20_88A08B90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2C54, (ts4_word)(ts4_word)lbl_88046C00, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61E20, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08C00: call_seq lbl_88B61E68, lbl_88046C24, lbl_88CC2C84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61E68_88A08C00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2C84, (ts4_word)(ts4_word)lbl_88046C24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61E68, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08C70: call_seq lbl_88B61EF8, lbl_88046C48, lbl_88CC2CB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61EF8_88A08C70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2CB4, (ts4_word)(ts4_word)lbl_88046C48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61EF8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08CE0: call_seq lbl_88CC3554, lbl_8803EC3C, lbl_88CC2CE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC3554_88A08CE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2CE4, (ts4_word)(ts4_word)lbl_8803EC3C, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08D48: call_seq lbl_88B61F88, lbl_88CC2CE4, lbl_8803ECF4, lbl_88CC2D14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61F88_88A08D48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2D14, (ts4_word)(ts4_word)lbl_8803ECF4, (ts4_word)(ts4_word)lbl_88CC2CE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61F88, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08DC0: call_seq lbl_88B61FE8, lbl_8803EEFC, lbl_88CC2D44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61FE8_88A08DC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2D44, (ts4_word)(ts4_word)lbl_8803EEFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61FE8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08E30: call_seq lbl_88B62018, lbl_8803EEE8, lbl_88CC2D74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62018_88A08E30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2D74, (ts4_word)(ts4_word)lbl_8803EEE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62018, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08EA0: call_seq lbl_88B62078, lbl_8803EE7C, lbl_88CC2DA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62078_88A08EA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2DA4, (ts4_word)(ts4_word)lbl_8803EE7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62078, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08F10: call_seq lbl_88B620E0, lbl_88042110, lbl_88CC2DD4, lbl_88052BEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B620E0_88A08F10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2DD4, (ts4_word)(ts4_word)lbl_88042110, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88052BEC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B620E0, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08F80: call_seq lbl_88B621E8, lbl_88041224, lbl_88CC2E04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B621E8_88A08F80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2E04, (ts4_word)(ts4_word)lbl_88041224, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B621E8, (ts4_word)13, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A08FF0: call_seq lbl_88B62320, lbl_88041204, lbl_88CC2E34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62320_88A08FF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2E34, (ts4_word)(ts4_word)lbl_88041204, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62320, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09060: call_seq lbl_88B62338, lbl_88041138, lbl_88CC2E64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62338_88A09060(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2E64, (ts4_word)(ts4_word)lbl_88041138, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62338, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A090D0: call_seq lbl_88B62350, lbl_8804114C, lbl_88CC2E94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62350_88A090D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2E94, (ts4_word)(ts4_word)lbl_8804114C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62350, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09140: call_seq lbl_88CC3344, lbl_88053DD8, lbl_88CC2EC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC3344_88A09140(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2EC4, (ts4_word)(ts4_word)lbl_88053DD8, (ts4_word)(ts4_word)lbl_88CC3344, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A091A8: call_seq lbl_88B62380, lbl_88CC2EC4, lbl_88041268, lbl_88CC2EF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62380_88A091A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2EF4, (ts4_word)(ts4_word)lbl_88041268, (ts4_word)(ts4_word)lbl_88CC2EC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62380, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09220: call_seq lbl_88CC2EF4, lbl_88053DE8, lbl_88CC2F24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC2EF4_88A09220(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2F24, (ts4_word)(ts4_word)lbl_88053DE8, (ts4_word)(ts4_word)lbl_88CC2EF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09288: call_seq lbl_88B62410, lbl_8804124C, lbl_88CC2F54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62410_88A09288(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2F54, (ts4_word)(ts4_word)lbl_8804124C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62410, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A092F8: call_seq lbl_88B62458, lbl_88CC2EC4, lbl_88041238, lbl_88CC2F84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62458_88A092F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2F84, (ts4_word)(ts4_word)lbl_88041238, (ts4_word)(ts4_word)lbl_88CC2EC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62458, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09370: call_seq lbl_88B624D0, lbl_8804115C, lbl_88CC2FB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B624D0_88A09370(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC2FB4, (ts4_word)(ts4_word)lbl_8804115C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B624D0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A093E0: addr lbl_88B67960, u32@lbl_88B620DC, u32@0x8 */
void ts4_addr_lbl_88B67960_88A093E0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B67960) + 8) = (ts4_word)(*(ts4_word *)lbl_88B620DC);
    return;
}

/* Swing_DLL.xex 0x88A09470: call_seq lbl_88B62518, lbl_88CC2EC4, lbl_8804159C, lbl_88CC3014, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62518_88A09470(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3014, (ts4_word)(ts4_word)lbl_8804159C, (ts4_word)(ts4_word)lbl_88CC2EC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62518, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A094E8: call_seq lbl_88B62548, lbl_88CC2EC4, lbl_88053E90, lbl_88CC3044, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62548_88A094E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3044, (ts4_word)(ts4_word)lbl_88053E90, (ts4_word)(ts4_word)lbl_88CC2EC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62548, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09560: call_seq lbl_88B62560, lbl_88CC2EC4, lbl_88040188, lbl_88CC3074, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62560_88A09560(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3074, (ts4_word)(ts4_word)lbl_88040188, (ts4_word)(ts4_word)lbl_88CC2EC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62560, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A095D8: call_seq lbl_88CC3344, lbl_88053EAC, lbl_88CC30A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC3344_88A095D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC30A4, (ts4_word)(ts4_word)lbl_88053EAC, (ts4_word)(ts4_word)lbl_88CC3344, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09640: call_seq lbl_88052C60, lbl_88B62590, lbl_88CC30A4, lbl_88041634, lbl_88CC30D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88052C60_88A09640(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC30D4, (ts4_word)(ts4_word)lbl_88041634, (ts4_word)(ts4_word)lbl_88CC30A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62590, (ts4_word)17, (ts4_word)(ts4_word)lbl_88052C60, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A096B8: call_seq lbl_88B62728, lbl_88CC30A4, lbl_880415B4, lbl_88CC3104, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62728_88A096B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3104, (ts4_word)(ts4_word)lbl_880415B4, (ts4_word)(ts4_word)lbl_88CC30A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62728, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09730: call_seq lbl_88B62740, lbl_88CC30A4, lbl_880411F0, lbl_88CC3134, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62740_88A09730(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3134, (ts4_word)(ts4_word)lbl_880411F0, (ts4_word)(ts4_word)lbl_88CC30A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62740, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A097A8: call_seq lbl_88B627E8, lbl_88CC30A4, lbl_880411C8, lbl_88CC3164, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B627E8_88A097A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3164, (ts4_word)(ts4_word)lbl_880411C8, (ts4_word)(ts4_word)lbl_88CC30A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B627E8, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09820: call_seq lbl_88B628C0, lbl_88CC30A4, lbl_88048610, lbl_88CC3194, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B628C0_88A09820(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3194, (ts4_word)(ts4_word)lbl_88048610, (ts4_word)(ts4_word)lbl_88CC30A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B628C0, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09898: call_seq lbl_88B629C8, lbl_88CC30A4, lbl_88042140, lbl_88CC31C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B629C8_88A09898(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC31C4, (ts4_word)(ts4_word)lbl_88042140, (ts4_word)(ts4_word)lbl_88CC30A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B629C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09910: addr lbl_88B67A80, u32@lbl_88B629F8, u32@0x68 */
void ts4_addr_lbl_88B67A80_88A09910(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B67A80) + 104) = (ts4_word)(*(ts4_word *)lbl_88B629F8);
    return;
}

/* Swing_DLL.xex 0x88A099A0: call_seq lbl_88052D2C, lbl_88B629FC, lbl_88CC3554, lbl_88053F68, lbl_88CC3224, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88052D2C_88A099A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3224, (ts4_word)(ts4_word)lbl_88053F68, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B629FC, (ts4_word)2, (ts4_word)(ts4_word)lbl_88052D2C, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09A18: addr lbl_88B67C18, u32@lbl_88B62A2C, u32@0xc8 */
void ts4_addr_lbl_88B67C18_88A09A18(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B67C18) + 200) = (ts4_word)(*(ts4_word *)lbl_88B62A2C);
    return;
}

/* Swing_DLL.xex 0x88A09AA8: call_seq lbl_88B62A30, lbl_880401B0, lbl_88CC3284, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62A30_88A09AA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3284, (ts4_word)(ts4_word)lbl_880401B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62A30, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09B18: call_seq lbl_88052DD0, lbl_88B62B50, lbl_88CC30A4, lbl_88040228, lbl_88CC32B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88052DD0_88A09B18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC32B4, (ts4_word)(ts4_word)lbl_88040228, (ts4_word)(ts4_word)lbl_88CC30A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62B50, (ts4_word)14, (ts4_word)(ts4_word)lbl_88052DD0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09B90: call_seq lbl_88B62CA0, lbl_88CC3164, lbl_880411DC, lbl_88CC32E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62CA0_88A09B90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC32E4, (ts4_word)(ts4_word)lbl_880411DC, (ts4_word)(ts4_word)lbl_88CC3164, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62CA0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09C08: addr lbl_88B67E28, u32@lbl_88B62D18, u32@0x8 */
void ts4_addr_lbl_88B67E28_88A09C08(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B67E28) + 8) = (ts4_word)(*(ts4_word *)lbl_88B62D18);
    return;
}

/* Swing_DLL.xex 0x88A09C20: call_seq lbl_88B67E28, lbl_88CC30A4, lbl_8804019C, lbl_88CC3314, lbl_88052E28, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B67E28_88A09C20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3314, (ts4_word)(ts4_word)lbl_8804019C, (ts4_word)(ts4_word)lbl_88CC30A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88052E28, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B67E28, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09C98: call_seq lbl_88B62D1C, lbl_88CC3554, lbl_8804116C, lbl_88CC3344, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62D1C_88A09C98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3344, (ts4_word)(ts4_word)lbl_8804116C, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62D1C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09D10: call_seq lbl_88B62D38, lbl_88041174, lbl_88CC3374, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62D38_88A09D10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3374, (ts4_word)(ts4_word)lbl_88041174, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62D38, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09D80: call_seq lbl_88B62D80, lbl_88041194, lbl_88CC33A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62D80_88A09D80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC33A4, (ts4_word)(ts4_word)lbl_88041194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62D80, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09DF0: call_seq lbl_88052E40, lbl_88B62DC8, lbl_88CC2EC4, lbl_88040218, lbl_88CC33D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88052E40_88A09DF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC33D4, (ts4_word)(ts4_word)lbl_88040218, (ts4_word)(ts4_word)lbl_88CC2EC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62DC8, (ts4_word)14, (ts4_word)(ts4_word)lbl_88052E40, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09E68: call_seq lbl_88052E9C, lbl_88CC3554, lbl_88041128, lbl_88CC3404, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88052E9C_88A09E68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3404, (ts4_word)(ts4_word)lbl_88041128, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88052E9C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09ED0: call_seq lbl_88B62F18, lbl_88041930, lbl_88CC3434, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62F18_88A09ED0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3434, (ts4_word)(ts4_word)lbl_88041930, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62F18, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09F40: addr lbl_88B67EB8, u32@lbl_88B62F60, u32@0x20 */
void ts4_addr_lbl_88B67EB8_88A09F40(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B67EB8) + 32) = (ts4_word)(*(ts4_word *)lbl_88B62F60);
    return;
}

/* Swing_DLL.xex 0x88A09F58: call_seq lbl_88B67EB8, lbl_88CC3404, lbl_88040260, lbl_88CC3464, lbl_88052ED8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B67EB8_88A09F58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3464, (ts4_word)(ts4_word)lbl_88040260, (ts4_word)(ts4_word)lbl_88CC3404, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88052ED8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B67EB8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A09FD0: call_seq lbl_88B62F68, lbl_88040200, lbl_88CC3494, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62F68_88A09FD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3494, (ts4_word)(ts4_word)lbl_88040200, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62F68, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A040: call_seq lbl_88B62FB0, lbl_880401D8, lbl_88CC34C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62FB0_88A0A040(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC34C4, (ts4_word)(ts4_word)lbl_880401D8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62FB0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A0B0: call_seq lbl_88B62FE0, lbl_880401F0, lbl_88CC34F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62FE0_88A0A0B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC34F4, (ts4_word)(ts4_word)lbl_880401F0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62FE0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A120: call_seq lbl_8803C97C, lbl_88CC3524, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803C97C_88A0A120(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3524, (ts4_word)(ts4_word)lbl_8803C97C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A180: call_seq lbl_88B62FF8, lbl_88CC3524, lbl_8803C9DC, lbl_88CC3554, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B62FF8_88A0A180(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)(ts4_word)lbl_8803C9DC, (ts4_word)(ts4_word)lbl_88CC3524, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B62FF8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A1F8: call_seq lbl_88B63028, lbl_8803CC5C, lbl_88CC3584, lbl_88052EF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63028_88A0A1F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3584, (ts4_word)(ts4_word)lbl_8803CC5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88052EF4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B63028, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A268: call_seq lbl_88B630D0, lbl_8803CCC4, lbl_88CC35B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B630D0_88A0A268(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC35B4, (ts4_word)(ts4_word)lbl_8803CCC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B630D0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A2D8: call_seq lbl_88B63100, lbl_8803CCD4, lbl_88CC35E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63100_88A0A2D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC35E4, (ts4_word)(ts4_word)lbl_8803CCD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63100, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A348: addr lbl_88B67F48, u32@lbl_88B63130, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88B67F48_88A0A348(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B63130;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B67F48) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B67F48) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A0A368: call_seq lbl_88B67F48, lbl_8803D124, lbl_88CC3614, lbl_88053068, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B67F48_88A0A368(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3614, (ts4_word)(ts4_word)lbl_8803D124, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88053068, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B67F48, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A3D8: call_seq lbl_88B6313C, lbl_8803D484, lbl_88CC3644, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6313C_88A0A3D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3644, (ts4_word)(ts4_word)lbl_8803D484, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6313C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A448: call_seq lbl_88B6316C, lbl_8803D4A8, lbl_88CC3674, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6316C_88A0A448(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3674, (ts4_word)(ts4_word)lbl_8803D4A8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6316C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A4B8: addr lbl_88B68008, u32@lbl_88B63184, u32@0x50 */
void ts4_addr_lbl_88B68008_88A0A4B8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B68008) + 80) = (ts4_word)(*(ts4_word *)lbl_88B63184);
    return;
}

/* Swing_DLL.xex 0x88A0A4D0: call_seq lbl_88B68008, lbl_8803D4C4, lbl_88CC36A4, lbl_880530BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68008_88A0A4D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC36A4, (ts4_word)(ts4_word)lbl_8803D4C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880530BC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B68008, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A540: call_seq lbl_88B63188, lbl_8803CAF0, lbl_88CC36D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63188_88A0A540(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC36D4, (ts4_word)(ts4_word)lbl_8803CAF0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63188, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A5B0: call_seq lbl_88B631B8, lbl_8803D194, lbl_88CC3704, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B631B8_88A0A5B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3704, (ts4_word)(ts4_word)lbl_8803D194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B631B8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A620: call_seq lbl_88B631F0, lbl_8803D2E0, lbl_88CC3734, lbl_880530E0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B631F0_88A0A620(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3734, (ts4_word)(ts4_word)lbl_8803D2E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880530E0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B631F0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A690: call_seq lbl_88B63250, lbl_8803D6A0, lbl_88CC3764, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63250_88A0A690(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3764, (ts4_word)(ts4_word)lbl_8803D6A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63250, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A700: call_seq lbl_88B63310, lbl_8803D914, lbl_88CC3794, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63310_88A0A700(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3794, (ts4_word)(ts4_word)lbl_8803D914, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63310, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A770: call_seq lbl_88B63328, lbl_8803D9E8, lbl_88CC37C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63328_88A0A770(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC37C4, (ts4_word)(ts4_word)lbl_8803D9E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63328, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A7E0: addr lbl_88B68098, u32@lbl_88B631EC, u32@0x20 */
void ts4_addr_lbl_88B68098_88A0A7E0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B68098) + 32) = (ts4_word)(*(ts4_word *)lbl_88B631EC);
    return;
}

/* Swing_DLL.xex 0x88A0A7F8: call_seq lbl_88B68098, lbl_8803F988, lbl_88CC37F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68098_88A0A7F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC37F4, (ts4_word)(ts4_word)lbl_8803F988, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68098, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A868: addr lbl_88B680C8, u32@lbl_88B631EC, u32@0x20 */
void ts4_addr_lbl_88B680C8_88A0A868(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B680C8) + 32) = (ts4_word)(*(ts4_word *)lbl_88B631EC);
    return;
}

/* Swing_DLL.xex 0x88A0A880: call_seq lbl_88B680C8, lbl_8803F974, lbl_88CC3824, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B680C8_88A0A880(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3824, (ts4_word)(ts4_word)lbl_8803F974, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B680C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A8F0: call_seq lbl_88B633A0, lbl_8804E4DC, lbl_88CC3854, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B633A0_88A0A8F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3854, (ts4_word)(ts4_word)lbl_8804E4DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B633A0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A960: addr lbl_88B680F8, u32@lbl_88B631EC, u32@0x20 */
void ts4_addr_lbl_88B680F8_88A0A960(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B680F8) + 32) = (ts4_word)(*(ts4_word *)lbl_88B631EC);
    return;
}

/* Swing_DLL.xex 0x88A0A978: call_seq lbl_88B680F8, lbl_8803F960, lbl_88CC3884, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B680F8_88A0A978(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3884, (ts4_word)(ts4_word)lbl_8803F960, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B680F8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0A9E8: call_seq lbl_88B633B8, lbl_8803F9B0, lbl_88CC38B4, lbl_88053124, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B633B8_88A0A9E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC38B4, (ts4_word)(ts4_word)lbl_8803F9B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88053124, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B633B8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0AA58: call_seq lbl_88B633E8, lbl_8803F99C, lbl_88CC38E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B633E8_88A0AA58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC38E4, (ts4_word)(ts4_word)lbl_8803F99C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B633E8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0AAC8: call_seq lbl_88B63418, lbl_8804E4F4, lbl_88CC3914, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63418_88A0AAC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3914, (ts4_word)(ts4_word)lbl_8804E4F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63418, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0AB38: call_seq lbl_88B63448, lbl_88CC3974, lbl_8804E50C, lbl_88CC3944, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63448_88A0AB38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3944, (ts4_word)(ts4_word)lbl_8804E50C, (ts4_word)(ts4_word)lbl_88CC3974, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63448, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0ABB0: call_seq lbl_88B63460, lbl_8804E524, lbl_88CC3974, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63460_88A0ABB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3974, (ts4_word)(ts4_word)lbl_8804E524, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63460, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0AC20: call_seq lbl_88B63490, lbl_8804E53C, lbl_88CC39A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63490_88A0AC20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC39A4, (ts4_word)(ts4_word)lbl_8804E53C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63490, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0AC90: call_seq lbl_88B634A8, lbl_8804E560, lbl_88CC39D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B634A8_88A0AC90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC39D4, (ts4_word)(ts4_word)lbl_8804E560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B634A8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0AD00: call_seq lbl_88B634D8, lbl_8803F5C8, lbl_88CC3A04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B634D8_88A0AD00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3A04, (ts4_word)(ts4_word)lbl_8803F5C8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B634D8, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0AD70: call_seq lbl_88B63580, lbl_88054050, lbl_88CC3A34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63580_88A0AD70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3A34, (ts4_word)(ts4_word)lbl_88054050, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63580, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0ADE0: call_seq lbl_88B635B0, lbl_88054068, lbl_88CC3A64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B635B0_88A0ADE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3A64, (ts4_word)(ts4_word)lbl_88054068, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B635B0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0AE50: call_seq lbl_88B635C8, lbl_8804C310, lbl_88CC3A94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B635C8_88A0AE50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3A94, (ts4_word)(ts4_word)lbl_8804C310, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B635C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0AEC0: call_seq lbl_88B635F8, lbl_8803ED20, lbl_88CC3AC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B635F8_88A0AEC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3AC4, (ts4_word)(ts4_word)lbl_8803ED20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B635F8, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0AF30: addr lbl_88B68128, u32@lbl_88B636B8, u32@0x8 */
void ts4_addr_lbl_88B68128_88A0AF30(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B68128) + 8) = (ts4_word)(*(ts4_word *)lbl_88B636B8);
    return;
}

/* Swing_DLL.xex 0x88A0AF48: call_seq lbl_88B68128, lbl_8804C33C, lbl_88CC3AF4, lbl_88053150, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68128_88A0AF48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3AF4, (ts4_word)(ts4_word)lbl_8804C33C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88053150, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B68128, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0AFB8: call_seq lbl_88B636C0, lbl_8803ED28, lbl_88CC3B24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B636C0_88A0AFB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3B24, (ts4_word)(ts4_word)lbl_8803ED28, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B636C0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B028: call_seq lbl_88B636F0, lbl_8803ED14, lbl_88CC3B54, lbl_88053194, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B636F0_88A0B028(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3B54, (ts4_word)(ts4_word)lbl_8803ED14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88053194, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B636F0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B098: addr lbl_88B681A0, u32@lbl_88B637B0, u32@0x20 */
void ts4_addr_lbl_88B681A0_88A0B098(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B681A0) + 32) = (ts4_word)(*(ts4_word *)lbl_88B637B0);
    return;
}

/* Swing_DLL.xex 0x88A0B0B0: call_seq lbl_88B681A0, lbl_8804E57C, lbl_88CC3B84, lbl_880531D0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B681A0_88A0B0B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3B84, (ts4_word)(ts4_word)lbl_8804E57C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880531D0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B681A0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B120: call_seq lbl_88B637B4, lbl_8804C348, lbl_88CC3BB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B637B4_88A0B120(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3BB4, (ts4_word)(ts4_word)lbl_8804C348, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B637B4, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B190: call_seq lbl_88B637CC, lbl_8804C358, lbl_88CC3BE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B637CC_88A0B190(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3BE4, (ts4_word)(ts4_word)lbl_8804C358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B637CC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B200: addr lbl_88B681E8, u32@lbl_88B637FC, u32@0x8 */
void ts4_addr_lbl_88B681E8_88A0B200(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B681E8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B637FC);
    return;
}

/* Swing_DLL.xex 0x88A0B218: call_seq lbl_88B681E8, lbl_8804C380, lbl_88CC3C14, lbl_8805320C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B681E8_88A0B218(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3C14, (ts4_word)(ts4_word)lbl_8804C380, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805320C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B681E8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B288: call_seq lbl_88B63800, lbl_88042408, lbl_88CC3C44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63800_88A0B288(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3C44, (ts4_word)(ts4_word)lbl_88042408, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63800, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B2F8: call_seq lbl_88B63818, lbl_880423F8, lbl_88CC3C74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63818_88A0B2F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3C74, (ts4_word)(ts4_word)lbl_880423F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63818, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B368: call_seq lbl_88B63860, lbl_8804C390, lbl_88CC3CA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63860_88A0B368(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3CA4, (ts4_word)(ts4_word)lbl_8804C390, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63860, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B3D8: call_seq lbl_88B63890, lbl_8804C3A0, lbl_88CC3CD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63890_88A0B3D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3CD4, (ts4_word)(ts4_word)lbl_8804C3A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63890, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B448: call_seq lbl_88B639B0, lbl_8804C3B0, lbl_88CC3D04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B639B0_88A0B448(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3D04, (ts4_word)(ts4_word)lbl_8804C3B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B639B0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B4B8: call_seq lbl_88B63A40, lbl_8804C3C4, lbl_88CC3D34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63A40_88A0B4B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3D34, (ts4_word)(ts4_word)lbl_8804C3C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63A40, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B528: call_seq lbl_88B63B00, lbl_8804C3DC, lbl_88CC3D64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63B00_88A0B528(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3D64, (ts4_word)(ts4_word)lbl_8804C3DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63B00, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B598: call_seq lbl_88B63BD8, lbl_8804C3F8, lbl_88CC3D94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63BD8_88A0B598(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3D94, (ts4_word)(ts4_word)lbl_8804C3F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63BD8, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B608: call_seq lbl_88B63C98, lbl_8804C410, lbl_88CC3DC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63C98_88A0B608(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3DC4, (ts4_word)(ts4_word)lbl_8804C410, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63C98, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B678: call_seq lbl_88B63D40, lbl_88053220, lbl_8803F5BC, lbl_88CC3DF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63D40_88A0B678(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3DF4, (ts4_word)(ts4_word)lbl_8803F5BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63D40, (ts4_word)12, (ts4_word)(ts4_word)lbl_88053220, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B6F0: call_seq lbl_88B63E60, lbl_8804C428, lbl_88CC3E24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63E60_88A0B6F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3E24, (ts4_word)(ts4_word)lbl_8804C428, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63E60, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B760: call_seq lbl_88B63EC0, lbl_8803F5E0, lbl_88CC3E54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63EC0_88A0B760(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3E54, (ts4_word)(ts4_word)lbl_8803F5E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63EC0, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B7D0: call_seq lbl_88B63FC8, lbl_88040278, lbl_88CC3E84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B63FC8_88A0B7D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3E84, (ts4_word)(ts4_word)lbl_88040278, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B63FC8, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B840: call_seq lbl_88B640A0, lbl_8803ED58, lbl_88CC3EB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B640A0_88A0B840(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3EB4, (ts4_word)(ts4_word)lbl_8803ED58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B640A0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B8B0: call_seq lbl_88B640E8, lbl_8803ED40, lbl_88CC3EE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B640E8_88A0B8B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3EE4, (ts4_word)(ts4_word)lbl_8803ED40, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B640E8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B920: call_seq lbl_88B64100, lbl_880433FC, lbl_88CC3F14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64100_88A0B920(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3F14, (ts4_word)(ts4_word)lbl_880433FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64100, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0B990: call_seq lbl_88B64148, lbl_8804342C, lbl_88CC3F44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64148_88A0B990(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3F44, (ts4_word)(ts4_word)lbl_8804342C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64148, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0BA00: call_seq lbl_88B64160, lbl_88CC3554, lbl_8803ED7C, lbl_88CC3F74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64160_88A0BA00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3F74, (ts4_word)(ts4_word)lbl_8803ED7C, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64160, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0BA78: call_seq lbl_88B641A8, lbl_88046454, lbl_88CC3FA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B641A8_88A0BA78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3FA4, (ts4_word)(ts4_word)lbl_88046454, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B641A8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0BAE8: call_seq lbl_88B64208, lbl_88CC3FA4, lbl_8804233C, lbl_88CC3FD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64208_88A0BAE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC3FD4, (ts4_word)(ts4_word)lbl_8804233C, (ts4_word)(ts4_word)lbl_88CC3FA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64208, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0BB60: call_seq lbl_880469C4, lbl_88CC4004, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880469C4_88A0BB60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4004, (ts4_word)(ts4_word)lbl_880469C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0BBC0: call_seq lbl_88B64250, lbl_88CC5864, lbl_88042E48, lbl_88CC4034, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64250_88A0BBC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4034, (ts4_word)(ts4_word)lbl_88042E48, (ts4_word)(ts4_word)lbl_88CC5864, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64250, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0BC38: call_seq lbl_88046B60, lbl_88CC4064, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046B60_88A0BC38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4064, (ts4_word)(ts4_word)lbl_88046B60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0BC98: call_seq lbl_88CC3554, lbl_88042318, lbl_88CC4094, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC3554_88A0BC98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4094, (ts4_word)(ts4_word)lbl_88042318, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0BD00: call_seq lbl_88046A84, lbl_88CC40C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A84_88A0BD00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC40C4, (ts4_word)(ts4_word)lbl_88046A84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0BD60: call_seq lbl_88B642B0, lbl_88CC4094, lbl_8804232C, lbl_88CC40F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B642B0_88A0BD60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC40F4, (ts4_word)(ts4_word)lbl_8804232C, (ts4_word)(ts4_word)lbl_88CC4094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B642B0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0BDD8: call_seq lbl_88B642E0, lbl_88CC4094, lbl_8804690C, lbl_88CC4124, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B642E0_88A0BDD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4124, (ts4_word)(ts4_word)lbl_8804690C, (ts4_word)(ts4_word)lbl_88CC4094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B642E0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0BE50: call_seq lbl_88CC4094, lbl_8804671C, lbl_88CC4154, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC4094_88A0BE50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4154, (ts4_word)(ts4_word)lbl_8804671C, (ts4_word)(ts4_word)lbl_88CC4094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0BEB8: call_seq lbl_88046A50, lbl_88CC4184, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A50_88A0BEB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4184, (ts4_word)(ts4_word)lbl_88046A50, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0BF18: call_seq lbl_88B642F8, lbl_88CC3554, lbl_88041284, lbl_88CC41B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B642F8_88A0BF18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC41B4, (ts4_word)(ts4_word)lbl_88041284, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B642F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0BF90: call_seq lbl_88046994, lbl_88CC41E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046994_88A0BF90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC41E4, (ts4_word)(ts4_word)lbl_88046994, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0BFF0: call_seq lbl_88B64310, lbl_88CC41E4, lbl_88046678, lbl_88CC4214, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64310_88A0BFF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4214, (ts4_word)(ts4_word)lbl_88046678, (ts4_word)(ts4_word)lbl_88CC41E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64310, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C068: call_seq lbl_88B64328, lbl_88046220, lbl_88CC4244, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64328_88A0C068(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4244, (ts4_word)(ts4_word)lbl_88046220, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64328, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C0D8: call_seq lbl_88B64388, lbl_88CC4364, lbl_8804694C, lbl_88CC4274, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64388_88A0C0D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4274, (ts4_word)(ts4_word)lbl_8804694C, (ts4_word)(ts4_word)lbl_88CC4364, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64388, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C150: call_seq lbl_88B643A0, lbl_88CC41B4, lbl_88040110, lbl_88CC42A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B643A0_88A0C150(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC42A4, (ts4_word)(ts4_word)lbl_88040110, (ts4_word)(ts4_word)lbl_88CC41B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B643A0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C1C8: call_seq lbl_88B643D0, lbl_88CC41B4, lbl_88040100, lbl_88CC42D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B643D0_88A0C1C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC42D4, (ts4_word)(ts4_word)lbl_88040100, (ts4_word)(ts4_word)lbl_88CC41B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B643D0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C240: call_seq lbl_88B643EC, lbl_88CC4364, lbl_8804011C, lbl_88CC4304, lbl_88053298, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B643EC_88A0C240(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4304, (ts4_word)(ts4_word)lbl_8804011C, (ts4_word)(ts4_word)lbl_88CC4364, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88053298, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B643EC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C2B8: call_seq lbl_88B6441C, lbl_88CC41B4, lbl_880400A8, lbl_88CC4334, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6441C_88A0C2B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4334, (ts4_word)(ts4_word)lbl_880400A8, (ts4_word)(ts4_word)lbl_88CC41B4, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6441C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C330: call_seq lbl_88B64434, lbl_88CC4814, lbl_88042370, lbl_88CC4364, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64434_88A0C330(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4364, (ts4_word)(ts4_word)lbl_88042370, (ts4_word)(ts4_word)lbl_88CC4814, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64434, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C3A8: call_seq lbl_88B6444C, lbl_88CC4574, lbl_88041B24, lbl_88CC4394, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6444C_88A0C3A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4394, (ts4_word)(ts4_word)lbl_88041B24, (ts4_word)(ts4_word)lbl_88CC4574, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6444C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C420: call_seq lbl_88B64468, lbl_88CC4334, lbl_880468C8, lbl_88CC43C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64468_88A0C420(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC43C4, (ts4_word)(ts4_word)lbl_880468C8, (ts4_word)(ts4_word)lbl_88CC4334, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64468, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C498: call_seq lbl_88B644B0, lbl_88CC4364, lbl_880400E8, lbl_88CC43F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B644B0_88A0C498(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC43F4, (ts4_word)(ts4_word)lbl_880400E8, (ts4_word)(ts4_word)lbl_88CC4364, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B644B0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C510: call_seq lbl_88B644E0, lbl_88CC4364, lbl_880400D0, lbl_88CC4424, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B644E0_88A0C510(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4424, (ts4_word)(ts4_word)lbl_880400D0, (ts4_word)(ts4_word)lbl_88CC4364, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B644E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C588: call_seq lbl_88B64510, lbl_880463D4, lbl_88CC4454, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64510_88A0C588(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4454, (ts4_word)(ts4_word)lbl_880463D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64510, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C5F8: call_seq lbl_88B64558, lbl_88CC4364, lbl_88046868, lbl_88CC4484, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64558_88A0C5F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4484, (ts4_word)(ts4_word)lbl_88046868, (ts4_word)(ts4_word)lbl_88CC4364, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64558, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C670: call_seq lbl_88B645D0, lbl_88CC4364, lbl_8803EFC0, lbl_88CC44B4, lbl_880532D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B645D0_88A0C670(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC44B4, (ts4_word)(ts4_word)lbl_8803EFC0, (ts4_word)(ts4_word)lbl_88CC4364, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880532D4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B645D0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C6E8: call_seq lbl_88CC4604, lbl_880467DC, lbl_88CC44E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC4604_88A0C6E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC44E4, (ts4_word)(ts4_word)lbl_880467DC, (ts4_word)(ts4_word)lbl_88CC4604, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C750: call_seq lbl_88CC41B4, lbl_88046AE0, lbl_88CC4514, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC41B4_88A0C750(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4514, (ts4_word)(ts4_word)lbl_88046AE0, (ts4_word)(ts4_word)lbl_88CC41B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C7B8: call_seq lbl_88B64648, lbl_88042358, lbl_88CC4544, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64648_88A0C7B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4544, (ts4_word)(ts4_word)lbl_88042358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64648, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C828: call_seq lbl_88B64678, lbl_88CC4334, lbl_8804234C, lbl_88CC4574, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64678_88A0C828(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4574, (ts4_word)(ts4_word)lbl_8804234C, (ts4_word)(ts4_word)lbl_88CC4334, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64678, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C8A0: call_seq lbl_88B64690, lbl_88046320, lbl_88CC45A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64690_88A0C8A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC45A4, (ts4_word)(ts4_word)lbl_88046320, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64690, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C910: addr lbl_88B68260, u32@lbl_88B646A8, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88B68260_88A0C910(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B646A8;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B68260) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B68260) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A0C930: call_seq lbl_88B68260, lbl_8803EFE8, lbl_88CC45D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68260_88A0C930(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC45D4, (ts4_word)(ts4_word)lbl_8803EFE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68260, (ts4_word)13, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0C9A0: call_seq lbl_88B646B0, lbl_88CC4334, lbl_8803EF9C, lbl_88CC4604, lbl_88053328, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B646B0_88A0C9A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4604, (ts4_word)(ts4_word)lbl_8803EF9C, (ts4_word)(ts4_word)lbl_88CC4334, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88053328, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B646B0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0CA18: call_seq lbl_88B64728, lbl_88CC42D4, lbl_880423C0, lbl_88CC4634, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64728_88A0CA18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4634, (ts4_word)(ts4_word)lbl_880423C0, (ts4_word)(ts4_word)lbl_88CC42D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64728, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0CA90: call_seq lbl_88B64740, lbl_880462E8, lbl_88CC4664, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64740_88A0CA90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4664, (ts4_word)(ts4_word)lbl_880462E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64740, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0CB00: call_seq lbl_88B64770, lbl_88CC41B4, lbl_8804675C, lbl_88CC4694, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64770_88A0CB00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4694, (ts4_word)(ts4_word)lbl_8804675C, (ts4_word)(ts4_word)lbl_88CC41B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64770, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0CB78: call_seq lbl_88B647A0, lbl_88CC4814, lbl_8803F9D4, lbl_88CC46C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B647A0_88A0CB78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC46C4, (ts4_word)(ts4_word)lbl_8803F9D4, (ts4_word)(ts4_word)lbl_88CC4814, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B647A0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0CBF0: call_seq lbl_88CC41B4, lbl_88046AB4, lbl_88CC46F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC41B4_88A0CBF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC46F4, (ts4_word)(ts4_word)lbl_88046AB4, (ts4_word)(ts4_word)lbl_88CC41B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0CC58: call_seq lbl_88B647D0, lbl_88CC4514, lbl_880466D4, lbl_88CC4724, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B647D0_88A0CC58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4724, (ts4_word)(ts4_word)lbl_880466D4, (ts4_word)(ts4_word)lbl_88CC4514, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B647D0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0CCD0: call_seq lbl_88B64818, lbl_88CC4514, lbl_88046A18, lbl_88CC4754, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64818_88A0CCD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4754, (ts4_word)(ts4_word)lbl_88046A18, (ts4_word)(ts4_word)lbl_88CC4514, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64818, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0CD48: call_seq lbl_88B648C0, lbl_880423A4, lbl_88CC4784, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B648C0_88A0CD48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4784, (ts4_word)(ts4_word)lbl_880423A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B648C0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0CDB8: call_seq lbl_88B64908, lbl_88CC4334, lbl_88042390, lbl_88CC47B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64908_88A0CDB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC47B4, (ts4_word)(ts4_word)lbl_88042390, (ts4_word)(ts4_word)lbl_88CC4334, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64908, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0CE30: call_seq lbl_88CC4364, lbl_88043ED0, lbl_88CC47E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC4364_88A0CE30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC47E4, (ts4_word)(ts4_word)lbl_88043ED0, (ts4_word)(ts4_word)lbl_88CC4364, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0CE98: call_seq lbl_88CC41B4, lbl_8804696C, lbl_88CC4814, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC41B4_88A0CE98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4814, (ts4_word)(ts4_word)lbl_8804696C, (ts4_word)(ts4_word)lbl_88CC41B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0CF00: call_seq lbl_88B64968, lbl_88CC3554, lbl_8803F00C, lbl_88CC4844, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64968_88A0CF00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4844, (ts4_word)(ts4_word)lbl_8803F00C, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64968, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0CF78: call_seq lbl_88B649F8, lbl_88CC4604, lbl_88046574, lbl_88CC4874, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B649F8_88A0CF78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4874, (ts4_word)(ts4_word)lbl_88046574, (ts4_word)(ts4_word)lbl_88CC4604, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B649F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0CFF0: call_seq lbl_88B64A10, lbl_88CC4754, lbl_88046518, lbl_88CC48A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64A10_88A0CFF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC48A4, (ts4_word)(ts4_word)lbl_88046518, (ts4_word)(ts4_word)lbl_88CC4754, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64A10, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D068: call_seq lbl_88B64A40, lbl_88CC41B4, lbl_880400BC, lbl_88CC48D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64A40_88A0D068(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC48D4, (ts4_word)(ts4_word)lbl_880400BC, (ts4_word)(ts4_word)lbl_88CC41B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64A40, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D0E0: call_seq lbl_88B64A88, lbl_88CC4364, lbl_88042380, lbl_88CC4904, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64A88_88A0D0E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4904, (ts4_word)(ts4_word)lbl_88042380, (ts4_word)(ts4_word)lbl_88CC4364, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64A88, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D158: call_seq lbl_88B64AD0, lbl_88CC42D4, lbl_880423D4, lbl_88CC4934, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64AD0_88A0D158(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4934, (ts4_word)(ts4_word)lbl_880423D4, (ts4_word)(ts4_word)lbl_88CC42D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64AD0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D1D0: call_seq lbl_88B64AE8, lbl_88CC4334, lbl_88046498, lbl_88CC4964, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64AE8_88A0D1D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4964, (ts4_word)(ts4_word)lbl_88046498, (ts4_word)(ts4_word)lbl_88CC4334, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64AE8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D248: call_seq lbl_88B64B18, lbl_88CC3554, lbl_88047050, lbl_88CC4994, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64B18_88A0D248(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4994, (ts4_word)(ts4_word)lbl_88047050, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64B18, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D2C0: call_seq lbl_88B64B78, lbl_88CC4994, lbl_88045B44, lbl_88CC49C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64B78_88A0D2C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC49C4, (ts4_word)(ts4_word)lbl_88045B44, (ts4_word)(ts4_word)lbl_88CC4994, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64B78, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D338: call_seq lbl_88B64B90, lbl_88CC4994, lbl_88045B24, lbl_88CC49F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64B90_88A0D338(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC49F4, (ts4_word)(ts4_word)lbl_88045B24, (ts4_word)(ts4_word)lbl_88CC4994, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64B90, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D3B0: call_seq lbl_88B64BC0, lbl_88CC4994, lbl_880459C0, lbl_88CC4A24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64BC0_88A0D3B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4A24, (ts4_word)(ts4_word)lbl_880459C0, (ts4_word)(ts4_word)lbl_88CC4994, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64BC0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D428: addr lbl_88B68398, u32@lbl_88B64BD8, u32@0x8 */
void ts4_addr_lbl_88B68398_88A0D428(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B68398) + 8) = (ts4_word)(*(ts4_word *)lbl_88B64BD8);
    return;
}

/* Swing_DLL.xex 0x88A0D440: call_seq lbl_88B68398, lbl_88045224, lbl_88CC4A54, lbl_88053378, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68398_88A0D440(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4A54, (ts4_word)(ts4_word)lbl_88045224, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88053378, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B68398, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}
