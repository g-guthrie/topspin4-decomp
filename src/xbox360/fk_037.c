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

extern char ts4_addr_lbl_8803A308_88AFF560[];
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
extern char lbl_8803EE48[];
extern char lbl_8803EE7C[];
extern char lbl_8803EE88[];
extern char lbl_8803EEE8[];
extern char lbl_8803EEFC[];
extern char lbl_8803EF04[];
extern char lbl_8803EFA8[];
extern char lbl_8803EFD0[];
extern char lbl_8803F030[];
extern char lbl_8803F048[];
extern char lbl_8803F084[];
extern char lbl_8803F094[];
extern char lbl_8803F0AC[];
extern char lbl_8803F5BC[];
extern char lbl_8803F5C8[];
extern char lbl_8803F5D4[];
extern char lbl_8803F5F4[];
extern char lbl_8803F610[];
extern char lbl_8803F634[];
extern char lbl_8803F64C[];
extern char lbl_8803F660[];
extern char lbl_8803F670[];
extern char lbl_8803F6B0[];
extern char lbl_8803F6CC[];
extern char lbl_8803F6D8[];
extern char lbl_8803F960[];
extern char lbl_8803F974[];
extern char lbl_8803F988[];
extern char lbl_8803F99C[];
extern char lbl_8803F9B0[];
extern char lbl_8803F9C0[];
extern char lbl_8803F9E8[];
extern char lbl_8803FA18[];
extern char lbl_8803FBE0[];
extern char lbl_8803FC48[];
extern char lbl_8803FC6C[];
extern char lbl_8803FC80[];
extern char lbl_8803FCA0[];
extern char lbl_8804002C[];
extern char lbl_88040040[];
extern char lbl_88040078[];
extern char lbl_88040290[];
extern char lbl_880402A0[];
extern char lbl_880402B0[];
extern char lbl_880402BC[];
extern char lbl_880402CC[];
extern char lbl_880402E4[];
extern char lbl_88040300[];
extern char lbl_88040318[];
extern char lbl_8804032C[];
extern char lbl_88040380[];
extern char lbl_880403AC[];
extern char lbl_880403C4[];
extern char lbl_880403FC[];
extern char lbl_88040424[];
extern char lbl_88040470[];
extern char lbl_88040494[];
extern char lbl_880404B8[];
extern char lbl_880404E0[];
extern char lbl_880405C0[];
extern char lbl_880405E4[];
extern char lbl_88040658[];
extern char lbl_88040668[];
extern char lbl_88040DB0[];
extern char lbl_88040E04[];
extern char lbl_88040E18[];
extern char lbl_88040E68[];
extern char lbl_88041DE0[];
extern char lbl_880422F8[];
extern char lbl_880423F8[];
extern char lbl_88042408[];
extern char lbl_88042E20[];
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
extern char lbl_88044A58[];
extern char lbl_88044A90[];
extern char lbl_88044ACC[];
extern char lbl_88044B0C[];
extern char lbl_88044B54[];
extern char lbl_88044B94[];
extern char lbl_88044BD4[];
extern char lbl_88044C08[];
extern char lbl_88044C48[];
extern char lbl_88044C84[];
extern char lbl_88044CD0[];
extern char lbl_88044CFC[];
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
extern char lbl_88045020[];
extern char lbl_88045070[];
extern char lbl_880453D8[];
extern char lbl_88045580[];
extern char lbl_880455E0[];
extern char lbl_880457FC[];
extern char lbl_88045860[];
extern char lbl_8804589C[];
extern char lbl_88045914[];
extern char lbl_880459F8[];
extern char lbl_88045A70[];
extern char lbl_88045AA8[];
extern char lbl_88045AFC[];
extern char lbl_88046C00[];
extern char lbl_88046C24[];
extern char lbl_88046C48[];
extern char lbl_88046C60[];
extern char lbl_88046C78[];
extern char lbl_88046C94[];
extern char lbl_8804705C[];
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
extern char lbl_8804E4DC[];
extern char lbl_8804E4F4[];
extern char lbl_8804E50C[];
extern char lbl_8804E524[];
extern char lbl_8804E53C[];
extern char lbl_8804E560[];
extern char lbl_8804E57C[];
extern char lbl_88050678[];
extern char lbl_88050D00[];
extern char lbl_88050D18[];
extern char lbl_88050D84[];
extern char lbl_88050DE8[];
extern char lbl_88050E14[];
extern char lbl_88050FF0[];
extern char lbl_88051004[];
extern char lbl_88051030[];
extern char lbl_880514A4[];
extern char lbl_880514D0[];
extern char lbl_88051640[];
extern char lbl_88051694[];
extern char lbl_880516B8[];
extern char lbl_880516FC[];
extern char lbl_88051728[];
extern char lbl_8805176C[];
extern char lbl_880517A8[];
extern char lbl_880517E4[];
extern char lbl_880517F8[];
extern char lbl_88B59110[];
extern char lbl_88B591B8[];
extern char lbl_88B59200[];
extern char lbl_88B59230[];
extern char lbl_88B592C0[];
extern char lbl_88B59350[];
extern char lbl_88B59410[];
extern char lbl_88B59440[];
extern char lbl_88B59458[];
extern char lbl_88B59488[];
extern char lbl_88B59500[];
extern char lbl_88B59548[];
extern char lbl_88B59578[];
extern char lbl_88B59608[];
extern char lbl_88B59698[];
extern char lbl_88B59758[];
extern char lbl_88B597A0[];
extern char lbl_88B59800[];
extern char lbl_88B59818[];
extern char lbl_88B59890[];
extern char lbl_88B598C0[];
extern char lbl_88B598F0[];
extern char lbl_88B59950[];
extern char lbl_88B59980[];
extern char lbl_88B599C8[];
extern char lbl_88B59A58[];
extern char lbl_88B59C0C[];
extern char lbl_88B59C40[];
extern char lbl_88B59CE8[];
extern char lbl_88B59D00[];
extern char lbl_88B59D18[];
extern char lbl_88B59D48[];
extern char lbl_88B59DF0[];
extern char lbl_88B59E20[];
extern char lbl_88B59E38[];
extern char lbl_88B59E68[];
extern char lbl_88B59E80[];
extern char lbl_88B59E9C[];
extern char lbl_88B59ED0[];
extern char lbl_88B59F60[];
extern char lbl_88B59F64[];
extern char lbl_88B59F68[];
extern char lbl_88B59F70[];
extern char lbl_88B5A000[];
extern char lbl_88B5A018[];
extern char lbl_88B5A030[];
extern char lbl_88B5A048[];
extern char lbl_88B5A090[];
extern char lbl_88B5A0A8[];
extern char lbl_88B5A0D8[];
extern char lbl_88B5A150[];
extern char lbl_88B5A198[];
extern char lbl_88B5A1E0[];
extern char lbl_88B5A2B8[];
extern char lbl_88B5A2E8[];
extern char lbl_88B5A318[];
extern char lbl_88B5A3F0[];
extern char lbl_88B5A438[];
extern char lbl_88B5A498[];
extern char lbl_88B5A4F8[];
extern char lbl_88B5A558[];
extern char lbl_88B5A618[];
extern char lbl_88B5A7B0[];
extern char lbl_88B5A7C8[];
extern char lbl_88B5A7E0[];
extern char lbl_88B5A810[];
extern char lbl_88B5A840[];
extern char lbl_88B5A858[];
extern char lbl_88B5A888[];
extern char lbl_88B5A8D0[];
extern char lbl_88B5A918[];
extern char lbl_88B5A9A8[];
extern char lbl_88B5A9F0[];
extern char lbl_88B5AA20[];
extern char lbl_88B5AA50[];
extern char lbl_88B5AA80[];
extern char lbl_88B5AA98[];
extern char lbl_88B5AAB0[];
extern char lbl_88B5AAE0[];
extern char lbl_88B5AAF8[];
extern char lbl_88B5ABD0[];
extern char lbl_88B5AD80[];
extern char lbl_88B5AF18[];
extern char lbl_88B5B188[];
extern char lbl_88B5B200[];
extern char lbl_88B5B248[];
extern char lbl_88B5B278[];
extern char lbl_88B5B2D8[];
extern char lbl_88B5B338[];
extern char lbl_88B5B428[];
extern char lbl_88B5B518[];
extern char lbl_88B5B560[];
extern char lbl_88B5B638[];
extern char lbl_88B5B650[];
extern char lbl_88B5B698[];
extern char lbl_88B5B6E0[];
extern char lbl_88B5B6F8[];
extern char lbl_88B5B740[];
extern char lbl_88B5B758[];
extern char lbl_88B5B800[];
extern char lbl_88B5B830[];
extern char lbl_88B5B878[];
extern char lbl_88B5B8C0[];
extern char lbl_88B5B908[];
extern char lbl_88B5B920[];
extern char lbl_88B5B938[];
extern char lbl_88B5BF80[];
extern char lbl_88B5C208[];
extern char lbl_88B5C280[];
extern char lbl_88B5C284[];
extern char lbl_88B5C2B4[];
extern char lbl_88B5C2E8[];
extern char lbl_88B5C348[];
extern char lbl_88B5C3A8[];
extern char lbl_88B5C438[];
extern char lbl_88B5C450[];
extern char lbl_88B5C4B0[];
extern char lbl_88B5C558[];
extern char lbl_88B5C570[];
extern char lbl_88B5C5D0[];
extern char lbl_88B5C5E8[];
extern char lbl_88B5C630[];
extern char lbl_88B5C6C0[];
extern char lbl_88B5C750[];
extern char lbl_88B5C7B0[];
extern char lbl_88B5C7E0[];
extern char lbl_88B5C828[];
extern char lbl_88B5C888[];
extern char lbl_88B5C8B8[];
extern char lbl_88B5C960[];
extern char lbl_88B5C990[];
extern char lbl_88B5C9C0[];
extern char lbl_88B5C9CC[];
extern char lbl_88B5C9FC[];
extern char lbl_88B5CA14[];
extern char lbl_88B5CA18[];
extern char lbl_88B5CA48[];
extern char lbl_88B5CA7C[];
extern char lbl_88B5CA80[];
extern char lbl_88B5CAE0[];
extern char lbl_88B5CBA0[];
extern char lbl_88B5CBB8[];
extern char lbl_88B5CC30[];
extern char lbl_88B5CC48[];
extern char lbl_88B5CC78[];
extern char lbl_88B5CCA8[];
extern char lbl_88B5CCD8[];
extern char lbl_88B5CCF0[];
extern char lbl_88B5CD20[];
extern char lbl_88B5CD38[];
extern char lbl_88B5CD68[];
extern char lbl_88B5CE10[];
extern char lbl_88B5CE40[];
extern char lbl_88B5CF00[];
extern char lbl_88B5CF08[];
extern char lbl_88B5CF38[];
extern char lbl_88B5CFF8[];
extern char lbl_88B5CFFC[];
extern char lbl_88B5D014[];
extern char lbl_88B5D044[];
extern char lbl_88B5D048[];
extern char lbl_88B5D060[];
extern char lbl_88B5D0A8[];
extern char lbl_88B5D0D8[];
extern char lbl_88B5D1F8[];
extern char lbl_88B5D288[];
extern char lbl_88B5D348[];
extern char lbl_88B5D420[];
extern char lbl_88B5D4E0[];
extern char lbl_88B5D588[];
extern char lbl_88B61170[];
extern char lbl_88B611B8[];
extern char lbl_88B61278[];
extern char lbl_88B61308[];
extern char lbl_88B61338[];
extern char lbl_88B61368[];
extern char lbl_88B61398[];
extern char lbl_88B61410[];
extern char lbl_88B61458[];
extern char lbl_88CBC6B4[];
extern char lbl_88CBD0D4[];
extern char lbl_88CBD194[];
extern char lbl_88CBDA64[];
extern char lbl_88CBDAC4[];
extern char lbl_88CBDAF4[];
extern char lbl_88CBDBB4[];
extern char lbl_88CBDC14[];
extern char lbl_88CBDF14[];
extern char lbl_88CBDF44[];
extern char lbl_88CBDF74[];
extern char lbl_88CBDFA4[];
extern char lbl_88CBDFD4[];
extern char lbl_88CBE004[];
extern char lbl_88CBE034[];
extern char lbl_88CBE064[];
extern char lbl_88CBE094[];
extern char lbl_88CBE0C4[];
extern char lbl_88CBE0F4[];
extern char lbl_88CBE124[];
extern char lbl_88CBE154[];
extern char lbl_88CBE184[];
extern char lbl_88CBE1B4[];
extern char lbl_88CBE1E4[];
extern char lbl_88CBE214[];
extern char lbl_88CBE244[];
extern char lbl_88CBE274[];
extern char lbl_88CBE2A4[];
extern char lbl_88CBE2D4[];
extern char lbl_88CBE304[];
extern char lbl_88CBE334[];
extern char lbl_88CBE364[];
extern char lbl_88CBE394[];
extern char lbl_88CBE3C4[];
extern char lbl_88CBE3F4[];
extern char lbl_88CBE424[];
extern char lbl_88CBE454[];
extern char lbl_88CBE484[];
extern char lbl_88CBE4B4[];
extern char lbl_88CBE4E4[];
extern char lbl_88CBE514[];
extern char lbl_88CBE544[];
extern char lbl_88CBE574[];
extern char lbl_88CBE5A4[];
extern char lbl_88CBE5D4[];
extern char lbl_88CBE604[];
extern char lbl_88CBE634[];
extern char lbl_88CBE664[];
extern char lbl_88CBE694[];
extern char lbl_88CBE6C4[];
extern char lbl_88CBE6F4[];
extern char lbl_88CBE724[];
extern char lbl_88CBE754[];
extern char lbl_88CBE784[];
extern char lbl_88CBE7B4[];
extern char lbl_88CBE7E4[];
extern char lbl_88CBE814[];
extern char lbl_88CBE844[];
extern char lbl_88CBE8A4[];
extern char lbl_88CBE8D4[];
extern char lbl_88CBE904[];
extern char lbl_88CBE934[];
extern char lbl_88CBE964[];
extern char lbl_88CBE994[];
extern char lbl_88CBE9C4[];
extern char lbl_88CBE9F4[];
extern char lbl_88CBEA24[];
extern char lbl_88CBEA54[];
extern char lbl_88CBEA84[];
extern char lbl_88CBEAB4[];
extern char lbl_88CBEAE4[];
extern char lbl_88CBEB14[];
extern char lbl_88CBEB44[];
extern char lbl_88CBEB74[];
extern char lbl_88CBEBA4[];
extern char lbl_88CBEBD4[];
extern char lbl_88CBEC04[];
extern char lbl_88CBEC34[];
extern char lbl_88CBEC64[];
extern char lbl_88CBEC94[];
extern char lbl_88CBECC4[];
extern char lbl_88CBECF4[];
extern char lbl_88CBED24[];
extern char lbl_88CBED54[];
extern char lbl_88CBED84[];
extern char lbl_88CBEDB4[];
extern char lbl_88CBEDE4[];
extern char lbl_88CBEE14[];
extern char lbl_88CBEE44[];
extern char lbl_88CBEE74[];
extern char lbl_88CBEEA4[];
extern char lbl_88CBEED4[];
extern char lbl_88CBEF04[];
extern char lbl_88CBEF34[];
extern char lbl_88CBEF64[];
extern char lbl_88CBEF94[];
extern char lbl_88CBEFC4[];
extern char lbl_88CBEFF4[];
extern char lbl_88CBF024[];
extern char lbl_88CBF054[];
extern char lbl_88CBF084[];
extern char lbl_88CBF0B4[];
extern char lbl_88CBF0E4[];
extern char lbl_88CBF114[];
extern char lbl_88CBF144[];
extern char lbl_88CBF174[];
extern char lbl_88CBF1A4[];
extern char lbl_88CBF1D4[];
extern char lbl_88CBF204[];
extern char lbl_88CBF234[];
extern char lbl_88CBF264[];
extern char lbl_88CBF294[];
extern char lbl_88CBF2C4[];
extern char lbl_88CBF2F4[];
extern char lbl_88CBF324[];
extern char lbl_88CBF354[];
extern char lbl_88CBF384[];
extern char lbl_88CBF3B4[];
extern char lbl_88CBF3E4[];
extern char lbl_88CBF414[];
extern char lbl_88CBF444[];
extern char lbl_88CBF474[];
extern char lbl_88CBF4A4[];
extern char lbl_88CBF4D4[];
extern char lbl_88CBF504[];
extern char lbl_88CBF534[];
extern char lbl_88CBF564[];
extern char lbl_88CBF594[];
extern char lbl_88CBF5C4[];
extern char lbl_88CBF5F4[];
extern char lbl_88CBF624[];
extern char lbl_88CBF63C[];
extern char lbl_88CBF66C[];
extern char lbl_88CBF69C[];
extern char lbl_88CBF6CC[];
extern char lbl_88CBF6FC[];
extern char lbl_88CBF72C[];
extern char lbl_88CBF75C[];
extern char lbl_88CBF78C[];
extern char lbl_88CBF7BC[];
extern char lbl_88CBF7EC[];
extern char lbl_88CBF81C[];
extern char lbl_88CBF84C[];
extern char lbl_88CBF87C[];
extern char lbl_88CBF8AC[];
extern char lbl_88CBF8DC[];
extern char lbl_88CBF90C[];
extern char lbl_88CBF93C[];
extern char lbl_88CBF96C[];
extern char lbl_88CBF99C[];
extern char lbl_88CBF9CC[];
extern char lbl_88CBF9FC[];
extern char lbl_88CBFA2C[];
extern char lbl_88CBFA5C[];
extern char lbl_88CBFA8C[];
extern char lbl_88CBFABC[];
extern char lbl_88CBFAEC[];
extern char lbl_88CBFB1C[];
extern char lbl_88CBFB4C[];
extern char lbl_88CBFB7C[];
extern char lbl_88CBFBAC[];
extern char lbl_88CBFBDC[];
extern char lbl_88CBFC0C[];
extern char lbl_88CBFC3C[];
extern char lbl_88CBFC6C[];
extern char lbl_88CBFC9C[];
extern char lbl_88CBFCCC[];
extern char lbl_88CBFCFC[];
extern char lbl_88CBFD2C[];
extern char lbl_88CBFD5C[];
extern char lbl_88CBFD8C[];
extern char lbl_88CBFDBC[];
extern char lbl_88CBFDEC[];
extern char lbl_88CBFE1C[];
extern char lbl_88CBFE4C[];
extern char lbl_88CBFE7C[];
extern char lbl_88CBFEAC[];
extern char lbl_88CBFEDC[];
extern char lbl_88CBFF0C[];
extern char lbl_88CBFF3C[];
extern char lbl_88CBFF6C[];
extern char lbl_88CBFF9C[];
extern char lbl_88CBFFCC[];
extern char lbl_88CBFFFC[];
extern char lbl_88CC002C[];
extern char lbl_88CC005C[];
extern char lbl_88CC008C[];
extern char lbl_88CC00BC[];
extern char lbl_88CC00EC[];
extern char lbl_88CC011C[];
extern char lbl_88CC014C[];
extern char lbl_88CC017C[];
extern char lbl_88CC01AC[];
extern char lbl_88CC01DC[];
extern char lbl_88CC020C[];
extern char lbl_88CC023C[];
extern char lbl_88CC026C[];
extern char lbl_88CC029C[];
ts4_word fn_8841F080();
ts4_word ts4_set_u32_offc_884CE988();
ts4_word fn_88563470();

/* Swing_DLL.xex 0x889FD108: call_seq lbl_88B59110, lbl_88CBDBB4, lbl_8803F048, lbl_88CBDF14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59110_889FD108(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDF14, (ts4_word)(ts4_word)lbl_8803F048, (ts4_word)(ts4_word)lbl_88CBDBB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59110, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD180: call_seq lbl_88B591B8, lbl_88CBDBB4, lbl_880402E4, lbl_88CBDF44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B591B8_889FD180(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDF44, (ts4_word)(ts4_word)lbl_880402E4, (ts4_word)(ts4_word)lbl_88CBDBB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B591B8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD1F8: call_seq lbl_88B59200, lbl_88040424, lbl_88CBDF74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59200_889FD1F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDF74, (ts4_word)(ts4_word)lbl_88040424, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59200, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD268: call_seq lbl_88B59230, lbl_880403FC, lbl_88CBDFA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59230_889FD268(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDFA4, (ts4_word)(ts4_word)lbl_880403FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59230, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD2D8: call_seq lbl_88B592C0, lbl_88CBDBB4, lbl_880402CC, lbl_88CBDFD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B592C0_889FD2D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDFD4, (ts4_word)(ts4_word)lbl_880402CC, (ts4_word)(ts4_word)lbl_88CBDBB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B592C0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD350: call_seq lbl_88B59350, lbl_88CBDBB4, lbl_8803F6B0, lbl_88CBE004, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59350_889FD350(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE004, (ts4_word)(ts4_word)lbl_8803F6B0, (ts4_word)(ts4_word)lbl_88CBDBB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59350, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD3C8: call_seq lbl_88CBDBB4, lbl_88045AFC, lbl_88CBE034, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBDBB4_889FD3C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE034, (ts4_word)(ts4_word)lbl_88045AFC, (ts4_word)(ts4_word)lbl_88CBDBB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD430: call_seq lbl_88B59410, lbl_88CBDC14, lbl_8804589C, lbl_88CBE064, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59410_889FD430(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE064, (ts4_word)(ts4_word)lbl_8804589C, (ts4_word)(ts4_word)lbl_88CBDC14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59410, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD4A8: call_seq lbl_88B59440, lbl_88CBDA64, lbl_88045860, lbl_88CBE094, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59440_889FD4A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE094, (ts4_word)(ts4_word)lbl_88045860, (ts4_word)(ts4_word)lbl_88CBDA64, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59440, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD520: call_seq lbl_88B59458, lbl_880453D8, lbl_88CBE0C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59458_889FD520(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE0C4, (ts4_word)(ts4_word)lbl_880453D8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59458, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD590: call_seq lbl_88B59488, lbl_88CBE034, lbl_880403C4, lbl_88CBE0F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59488_889FD590(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE0F4, (ts4_word)(ts4_word)lbl_880403C4, (ts4_word)(ts4_word)lbl_88CBE034, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59488, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD608: call_seq lbl_88B59500, lbl_880405E4, lbl_88CBE124, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59500_889FD608(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE124, (ts4_word)(ts4_word)lbl_880405E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59500, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD678: call_seq lbl_88B59548, lbl_880405C0, lbl_88CBE154, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59548_889FD678(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE154, (ts4_word)(ts4_word)lbl_880405C0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59548, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD6E8: call_seq lbl_88B59578, lbl_88CBDBB4, lbl_88040380, lbl_88CBE184, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59578_889FD6E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE184, (ts4_word)(ts4_word)lbl_88040380, (ts4_word)(ts4_word)lbl_88CBDBB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59578, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD760: call_seq lbl_88B59608, lbl_8803FC48, lbl_88CBE1B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59608_889FD760(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE1B4, (ts4_word)(ts4_word)lbl_8803FC48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59608, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD7D0: call_seq lbl_88B59698, lbl_88CBE034, lbl_8803FC6C, lbl_88CBE1E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59698_889FD7D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE1E4, (ts4_word)(ts4_word)lbl_8803FC6C, (ts4_word)(ts4_word)lbl_88CBE034, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59698, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD848: call_seq lbl_88B59758, lbl_88045020, lbl_88CBE214, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59758_889FD848(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE214, (ts4_word)(ts4_word)lbl_88045020, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59758, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD8B8: call_seq lbl_88B597A0, lbl_88CBE034, lbl_88040300, lbl_88CBE244, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B597A0_889FD8B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE244, (ts4_word)(ts4_word)lbl_88040300, (ts4_word)(ts4_word)lbl_88CBE034, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B597A0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD930: call_seq lbl_88B59800, lbl_88CBDBB4, lbl_880403AC, lbl_88CBE274, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59800_889FD930(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE274, (ts4_word)(ts4_word)lbl_880403AC, (ts4_word)(ts4_word)lbl_88CBDBB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59800, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD9A8: call_seq lbl_88B59818, lbl_880422F8, lbl_88CBE2A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59818_889FD9A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE2A4, (ts4_word)(ts4_word)lbl_880422F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59818, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FDA18: call_seq lbl_88B59890, lbl_88CBDBB4, lbl_8803FA18, lbl_88CBE2D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59890_889FDA18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE2D4, (ts4_word)(ts4_word)lbl_8803FA18, (ts4_word)(ts4_word)lbl_88CBDBB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59890, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FDA90: call_seq lbl_88050D00, lbl_88CBC6B4, lbl_8803FBE0, lbl_88CBE304, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88050D00_889FDA90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE304, (ts4_word)(ts4_word)lbl_8803FBE0, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88050D00, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FDAF8: call_seq lbl_88B598C0, lbl_88CBE304, lbl_88045A70, lbl_88CBE334, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B598C0_889FDAF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE334, (ts4_word)(ts4_word)lbl_88045A70, (ts4_word)(ts4_word)lbl_88CBE304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B598C0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FDB70: call_seq lbl_88B598F0, lbl_88CBE334, lbl_8803FCA0, lbl_88CBE364, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B598F0_889FDB70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE364, (ts4_word)(ts4_word)lbl_8803FCA0, (ts4_word)(ts4_word)lbl_88CBE334, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B598F0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FDBE8: call_seq lbl_88B59950, lbl_88CBE334, lbl_8803FC80, lbl_88CBE394, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59950_889FDBE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE394, (ts4_word)(ts4_word)lbl_8803FC80, (ts4_word)(ts4_word)lbl_88CBE334, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59950, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FDC60: call_seq lbl_88B59980, lbl_88CBE334, lbl_8803F9E8, lbl_88CBE3C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59980_889FDC60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE3C4, (ts4_word)(ts4_word)lbl_8803F9E8, (ts4_word)(ts4_word)lbl_88CBE334, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59980, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FDCD8: call_seq lbl_88B599C8, lbl_88CBDBB4, lbl_8804032C, lbl_88CBE3F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B599C8_889FDCD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE3F4, (ts4_word)(ts4_word)lbl_8804032C, (ts4_word)(ts4_word)lbl_88CBDBB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B599C8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FDD50: call_seq lbl_88050D18, lbl_88B59A58, lbl_88CBE8A4, lbl_8803F6CC, lbl_88CBE424, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88050D18_889FDD50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE424, (ts4_word)(ts4_word)lbl_8803F6CC, (ts4_word)(ts4_word)lbl_88CBE8A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59A58, (ts4_word)18, (ts4_word)(ts4_word)lbl_88050D18, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FDDC8: call_seq lbl_88CBC6B4, lbl_88045AA8, lbl_88CBE454, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBC6B4_889FDDC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE454, (ts4_word)(ts4_word)lbl_88045AA8, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FDE30: call_seq lbl_88CBE4E4, lbl_880457FC, lbl_88CBE484, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBE4E4_889FDE30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE484, (ts4_word)(ts4_word)lbl_880457FC, (ts4_word)(ts4_word)lbl_88CBE4E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FDE98: call_seq lbl_88CBE424, lbl_880455E0, lbl_88CBE4B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBE424_889FDE98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE4B4, (ts4_word)(ts4_word)lbl_880455E0, (ts4_word)(ts4_word)lbl_88CBE424, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FDF00: call_seq lbl_88050D84, lbl_88CBE454, lbl_880459F8, lbl_88CBE4E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88050D84_889FDF00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE4E4, (ts4_word)(ts4_word)lbl_880459F8, (ts4_word)(ts4_word)lbl_88CBE454, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88050D84, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FDF68: call_seq lbl_88B59C0C, lbl_88045070, lbl_88CBE514, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59C0C_889FDF68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE514, (ts4_word)(ts4_word)lbl_88045070, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59C0C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FDFD8: call_seq lbl_88B59C40, lbl_88CBE4E4, lbl_88041DE0, lbl_88CBE544, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59C40_889FDFD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE544, (ts4_word)(ts4_word)lbl_88041DE0, (ts4_word)(ts4_word)lbl_88CBE4E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59C40, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE050: call_seq lbl_88B59CE8, lbl_88CBC6B4, lbl_8803F5D4, lbl_88CBE574, lbl_88050DE8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59CE8_889FE050(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE574, (ts4_word)(ts4_word)lbl_8803F5D4, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88050DE8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B59CE8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE0C0: call_seq lbl_88B59D00, lbl_88CBE634, lbl_880402B0, lbl_88CBE5A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59D00_889FE0C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE5A4, (ts4_word)(ts4_word)lbl_880402B0, (ts4_word)(ts4_word)lbl_88CBE634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59D00, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE138: call_seq lbl_88CBE604, lbl_88040E04, lbl_88CBE5D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBE604_889FE138(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE5D4, (ts4_word)(ts4_word)lbl_88040E04, (ts4_word)(ts4_word)lbl_88CBE604, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE1A0: call_seq lbl_88B59D18, lbl_88CBE634, lbl_8803EFA8, lbl_88CBE604, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59D18_889FE1A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE604, (ts4_word)(ts4_word)lbl_8803EFA8, (ts4_word)(ts4_word)lbl_88CBE634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59D18, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE218: call_seq lbl_88B59D48, lbl_88CBE574, lbl_88040290, lbl_88CBE634, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59D48_889FE218(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE634, (ts4_word)(ts4_word)lbl_88040290, (ts4_word)(ts4_word)lbl_88CBE574, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59D48, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE290: call_seq lbl_88CBE634, lbl_880402A0, lbl_88CBE664, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBE634_889FE290(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE664, (ts4_word)(ts4_word)lbl_880402A0, (ts4_word)(ts4_word)lbl_88CBE634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE2F8: call_seq lbl_88CBE5A4, lbl_88040E18, lbl_88CBE694, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBE5A4_889FE2F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE694, (ts4_word)(ts4_word)lbl_88040E18, (ts4_word)(ts4_word)lbl_88CBE5A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE360: call_seq lbl_88CBE664, lbl_88040E68, lbl_88CBE6C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBE664_889FE360(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE6C4, (ts4_word)(ts4_word)lbl_88040E68, (ts4_word)(ts4_word)lbl_88CBE664, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE3C8: call_seq lbl_88CBE5A4, lbl_88040DB0, lbl_88CBE6F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBE5A4_889FE3C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE6F4, (ts4_word)(ts4_word)lbl_88040DB0, (ts4_word)(ts4_word)lbl_88CBE5A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE430: call_seq lbl_88B59DF0, lbl_88CBE784, lbl_8803F6D8, lbl_88CBE724, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59DF0_889FE430(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE724, (ts4_word)(ts4_word)lbl_8803F6D8, (ts4_word)(ts4_word)lbl_88CBE784, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59DF0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE4A8: call_seq lbl_88B59E20, lbl_88CBE7B4, lbl_88045914, lbl_88CBE754, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59E20_889FE4A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE754, (ts4_word)(ts4_word)lbl_88045914, (ts4_word)(ts4_word)lbl_88CBE7B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59E20, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE520: call_seq lbl_88B59E38, lbl_88CBE8A4, lbl_88047070, lbl_88CBE784, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59E38_889FE520(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE784, (ts4_word)(ts4_word)lbl_88047070, (ts4_word)(ts4_word)lbl_88CBE8A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59E38, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE598: call_seq lbl_88B59E68, lbl_88CBE784, lbl_880402BC, lbl_88CBE7B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59E68_889FE598(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE7B4, (ts4_word)(ts4_word)lbl_880402BC, (ts4_word)(ts4_word)lbl_88CBE784, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59E68, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE610: call_seq lbl_88B59E80, lbl_88CBE7B4, lbl_88045580, lbl_88CBE7E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59E80_889FE610(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE7E4, (ts4_word)(ts4_word)lbl_88045580, (ts4_word)(ts4_word)lbl_88CBE7B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59E80, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE688: call_seq lbl_88B59E9C, lbl_8803F9C0, lbl_88CBE814, lbl_88050E14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59E9C_889FE688(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE814, (ts4_word)(ts4_word)lbl_8803F9C0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88050E14, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B59E9C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE6F8: call_seq lbl_88B59ED0, lbl_88CBC6B4, lbl_8803F660, lbl_88CBE844, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59ED0_889FE6F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE844, (ts4_word)(ts4_word)lbl_8803F660, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59ED0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE770: get u32@lbl_88B59F68, lbl_88B5BF80, u32@lbl_88B59F64, u32@lbl_88B59F60, u32@0x50, u32@0x110 */
void ts4_get_u32_lbl_88B59F68_889FE770(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88B59F68;
    t2 = *(ts4_word *)lbl_88B59F64;
    t3 = *(ts4_word *)lbl_88B59F60;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B5BF80) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B5BF80) + 272) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B5BF80) + 560) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x889FE818: call_seq lbl_88B59F70, lbl_88CBC6B4, lbl_8803F084, lbl_88CBE8A4, lbl_88050FF0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59F70_889FE818(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE8A4, (ts4_word)(ts4_word)lbl_8803F084, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88050FF0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B59F70, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE890: call_seq lbl_88B5A000, lbl_88CBC6B4, lbl_8804707C, lbl_88CBE8D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A000_889FE890(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE8D4, (ts4_word)(ts4_word)lbl_8804707C, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A000, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE908: call_seq lbl_88B5A018, lbl_88CBD0D4, lbl_88044F38, lbl_88CBE904, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A018_889FE908(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE904, (ts4_word)(ts4_word)lbl_88044F38, (ts4_word)(ts4_word)lbl_88CBD0D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A018, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE980: call_seq lbl_88B5A030, lbl_88042E20, lbl_88CBE934, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A030_889FE980(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE934, (ts4_word)(ts4_word)lbl_88042E20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A030, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FE9F0: call_seq lbl_88B5A048, lbl_88CBC6B4, lbl_8803EFD0, lbl_88CBE964, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A048_889FE9F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE964, (ts4_word)(ts4_word)lbl_8803EFD0, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A048, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FEA68: call_seq lbl_88B5A090, lbl_88044F10, lbl_88CBE994, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A090_889FEA68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE994, (ts4_word)(ts4_word)lbl_88044F10, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A090, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FEAD8: call_seq lbl_88B5A0A8, lbl_88CBC6B4, lbl_88044F90, lbl_88CBE9C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A0A8_889FEAD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE9C4, (ts4_word)(ts4_word)lbl_88044F90, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A0A8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FEB50: call_seq lbl_88B5A0D8, lbl_88CBEA84, lbl_8803F670, lbl_88CBE9F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A0D8_889FEB50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBE9F4, (ts4_word)(ts4_word)lbl_8803F670, (ts4_word)(ts4_word)lbl_88CBEA84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A0D8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FEBC8: call_seq lbl_88B5A150, lbl_880404E0, lbl_88CBEA24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A150_889FEBC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEA24, (ts4_word)(ts4_word)lbl_880404E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A150, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FEC38: call_seq lbl_88B5A198, lbl_880404B8, lbl_88CBEA54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A198_889FEC38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEA54, (ts4_word)(ts4_word)lbl_880404B8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A198, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FECA8: call_seq lbl_88051004, lbl_88B5A1E0, lbl_88CBDBB4, lbl_8803F030, lbl_88CBEA84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88051004_889FECA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEA84, (ts4_word)(ts4_word)lbl_8803F030, (ts4_word)(ts4_word)lbl_88CBDBB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A1E0, (ts4_word)9, (ts4_word)(ts4_word)lbl_88051004, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FED20: call_seq lbl_88B5A2B8, lbl_88040494, lbl_88CBEAB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A2B8_889FED20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEAB4, (ts4_word)(ts4_word)lbl_88040494, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A2B8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FED90: call_seq lbl_88B5A2E8, lbl_88040470, lbl_88CBEAE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A2E8_889FED90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEAE4, (ts4_word)(ts4_word)lbl_88040470, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A2E8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FEE00: call_seq lbl_88B5A318, lbl_88CBDBB4, lbl_88040318, lbl_88CBEB14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A318_889FEE00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEB14, (ts4_word)(ts4_word)lbl_88040318, (ts4_word)(ts4_word)lbl_88CBDBB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A318, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FEE78: call_seq lbl_88B5A3F0, lbl_88CBDAC4, lbl_88044EA8, lbl_88CBEB44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A3F0_889FEE78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEB44, (ts4_word)(ts4_word)lbl_88044EA8, (ts4_word)(ts4_word)lbl_88CBDAC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A3F0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FEEF0: call_seq lbl_88B5A438, lbl_88CBDAC4, lbl_88044E64, lbl_88CBEB74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A438_889FEEF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEB74, (ts4_word)(ts4_word)lbl_88044E64, (ts4_word)(ts4_word)lbl_88CBDAC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A438, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FEF68: call_seq lbl_88B5A498, lbl_88CBDAF4, lbl_88044DD0, lbl_88CBEBA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A498_889FEF68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEBA4, (ts4_word)(ts4_word)lbl_88044DD0, (ts4_word)(ts4_word)lbl_88CBDAF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A498, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FEFE0: call_seq lbl_88B5A4F8, lbl_88CBDAF4, lbl_88044CD0, lbl_88CBEBD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A4F8_889FEFE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEBD4, (ts4_word)(ts4_word)lbl_88044CD0, (ts4_word)(ts4_word)lbl_88CBDAF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A4F8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF058: call_seq lbl_88B5A558, lbl_88CBDAC4, lbl_88044BD4, lbl_88CBEC04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A558_889FF058(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEC04, (ts4_word)(ts4_word)lbl_88044BD4, (ts4_word)(ts4_word)lbl_88CBDAC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A558, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF0D0: call_seq lbl_88B5A618, lbl_8803F094, lbl_88CBEC34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A618_889FF0D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEC34, (ts4_word)(ts4_word)lbl_8803F094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A618, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF140: call_seq lbl_88B5A7B0, lbl_88CBD194, lbl_8803F0AC, lbl_88CBEC64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A7B0_889FF140(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEC64, (ts4_word)(ts4_word)lbl_8803F0AC, (ts4_word)(ts4_word)lbl_88CBD194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A7B0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF1B8: call_seq lbl_88B5A7C8, lbl_88CBD194, lbl_88044E30, lbl_88CBEC94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A7C8_889FF1B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEC94, (ts4_word)(ts4_word)lbl_88044E30, (ts4_word)(ts4_word)lbl_88CBD194, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A7C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF230: call_seq lbl_88B5A7E0, lbl_88CBD194, lbl_88044DF8, lbl_88CBECC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A7E0_889FF230(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBECC4, (ts4_word)(ts4_word)lbl_88044DF8, (ts4_word)(ts4_word)lbl_88CBD194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A7E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF2A8: call_seq lbl_88B5A810, lbl_88044B54, lbl_88CBECF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A810_889FF2A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBECF4, (ts4_word)(ts4_word)lbl_88044B54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A810, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF318: call_seq lbl_88B5A840, lbl_88CBD194, lbl_88044D8C, lbl_88CBED24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A840_889FF318(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBED24, (ts4_word)(ts4_word)lbl_88044D8C, (ts4_word)(ts4_word)lbl_88CBD194, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A840, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF390: call_seq lbl_88B5A858, lbl_88044A90, lbl_88CBED54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A858_889FF390(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBED54, (ts4_word)(ts4_word)lbl_88044A90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A858, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF400: call_seq lbl_88B5A888, lbl_88044ACC, lbl_88CBED84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A888_889FF400(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBED84, (ts4_word)(ts4_word)lbl_88044ACC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A888, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF470: call_seq lbl_88B5A8D0, lbl_88CBC6B4, lbl_88044CFC, lbl_88CBEDB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A8D0_889FF470(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEDB4, (ts4_word)(ts4_word)lbl_88044CFC, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A8D0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF4E8: call_seq lbl_88B5A918, lbl_88CBDAF4, lbl_8804705C, lbl_88CBEDE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A918_889FF4E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEDE4, (ts4_word)(ts4_word)lbl_8804705C, (ts4_word)(ts4_word)lbl_88CBDAF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A918, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF560: call_seq lbl_88B5A9A8, lbl_88044A58, lbl_88CBEE14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A9A8_889FF560(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEE14, (ts4_word)(ts4_word)lbl_88044A58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A9A8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF5D0: call_seq lbl_88B5A9F0, lbl_88044B0C, lbl_88CBEE44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5A9F0_889FF5D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEE44, (ts4_word)(ts4_word)lbl_88044B0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5A9F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF640: call_seq lbl_88B5AA20, lbl_88044B94, lbl_88CBEE74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5AA20_889FF640(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEE74, (ts4_word)(ts4_word)lbl_88044B94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5AA20, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF6B0: call_seq lbl_88B5AA50, lbl_88CBC6B4, lbl_88044D60, lbl_88CBEEA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5AA50_889FF6B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEEA4, (ts4_word)(ts4_word)lbl_88044D60, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5AA50, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF728: call_seq lbl_88B5AA80, lbl_88CBC6B4, lbl_88044C84, lbl_88CBEED4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5AA80_889FF728(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEED4, (ts4_word)(ts4_word)lbl_88044C84, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5AA80, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF7A0: call_seq lbl_88B5AA98, lbl_88CBC6B4, lbl_88044C48, lbl_88CBEF04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5AA98_889FF7A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEF04, (ts4_word)(ts4_word)lbl_88044C48, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5AA98, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF818: call_seq lbl_88B5AAB0, lbl_88044A08, lbl_88CBEF34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5AAB0_889FF818(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEF34, (ts4_word)(ts4_word)lbl_88044A08, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5AAB0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF888: call_seq lbl_88B5AAE0, lbl_88CBC6B4, lbl_88044C08, lbl_88CBEF64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5AAE0_889FF888(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEF64, (ts4_word)(ts4_word)lbl_88044C08, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5AAE0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF900: call_seq lbl_88B5AAF8, lbl_88040668, lbl_88CBEF94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5AAF8_889FF900(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEF94, (ts4_word)(ts4_word)lbl_88040668, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5AAF8, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF970: call_seq lbl_88B5ABD0, lbl_88CBC6B4, lbl_88040658, lbl_88CBEFC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5ABD0_889FF970(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEFC4, (ts4_word)(ts4_word)lbl_88040658, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5ABD0, (ts4_word)18, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FF9E8: call_seq lbl_88B5AD80, lbl_8803F5F4, lbl_88CBEFF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5AD80_889FF9E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBEFF4, (ts4_word)(ts4_word)lbl_8803F5F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5AD80, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FFA58: call_seq lbl_88B5AF18, lbl_88CBDAF4, lbl_8803F64C, lbl_88CBF024, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5AF18_889FFA58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF024, (ts4_word)(ts4_word)lbl_8803F64C, (ts4_word)(ts4_word)lbl_88CBDAF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5AF18, (ts4_word)26, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FFAD0: call_seq lbl_88CBC6B4, lbl_8804494C, lbl_88CBF054, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBC6B4_889FFAD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF054, (ts4_word)(ts4_word)lbl_8804494C, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FFB38: call_seq lbl_88B5B188, lbl_88CBF054, lbl_88044700, lbl_88CBF084, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B188_889FFB38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF084, (ts4_word)(ts4_word)lbl_88044700, (ts4_word)(ts4_word)lbl_88CBF054, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B188, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FFBB0: call_seq lbl_88CBC6B4, lbl_88044924, lbl_88CBF0B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBC6B4_889FFBB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF0B4, (ts4_word)(ts4_word)lbl_88044924, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FFC18: call_seq lbl_88B5B200, lbl_88044438, lbl_88CBF0E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B200_889FFC18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF0E4, (ts4_word)(ts4_word)lbl_88044438, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B200, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FFC88: call_seq lbl_88B5B248, lbl_88CBF0B4, lbl_88044680, lbl_88CBF114, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B248_889FFC88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF114, (ts4_word)(ts4_word)lbl_88044680, (ts4_word)(ts4_word)lbl_88CBF0B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B248, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FFD00: call_seq lbl_88CBC6B4, lbl_880448C8, lbl_88CBF144, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBC6B4_889FFD00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF144, (ts4_word)(ts4_word)lbl_880448C8, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FFD68: call_seq lbl_88CBC6B4, lbl_880448FC, lbl_88CBF174, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBC6B4_889FFD68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF174, (ts4_word)(ts4_word)lbl_880448FC, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FFDD0: call_seq lbl_88B5B278, lbl_88CBF144, lbl_88044524, lbl_88CBF1A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B278_889FFDD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF1A4, (ts4_word)(ts4_word)lbl_88044524, (ts4_word)(ts4_word)lbl_88CBF144, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B278, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FFE48: call_seq lbl_88B5B2D8, lbl_88CBF174, lbl_880446BC, lbl_88CBF1D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B2D8_889FFE48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF1D4, (ts4_word)(ts4_word)lbl_880446BC, (ts4_word)(ts4_word)lbl_88CBF174, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B2D8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FFEC0: call_seq lbl_88CBC6B4, lbl_8804489C, lbl_88CBF204, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBC6B4_889FFEC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF204, (ts4_word)(ts4_word)lbl_8804489C, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FFF28: call_seq lbl_88B5B338, lbl_88CBF204, lbl_88044650, lbl_88CBF234, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B338_889FFF28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF234, (ts4_word)(ts4_word)lbl_88044650, (ts4_word)(ts4_word)lbl_88CBF204, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B338, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FFFA0: call_seq lbl_88B5B428, lbl_88044324, lbl_88CBF264, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B428_889FFFA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF264, (ts4_word)(ts4_word)lbl_88044324, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B428, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00010: call_seq lbl_88B5B518, lbl_88044370, lbl_88CBF294, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B518_88A00010(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF294, (ts4_word)(ts4_word)lbl_88044370, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B518, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00080: call_seq lbl_88B5B560, lbl_8803F610, lbl_88CBF2C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B560_88A00080(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF2C4, (ts4_word)(ts4_word)lbl_8803F610, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B560, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A000F0: call_seq lbl_88B5B638, lbl_8803F634, lbl_88CBF2F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B638_88A000F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF2F4, (ts4_word)(ts4_word)lbl_8803F634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B638, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00160: call_seq lbl_88CBC6B4, lbl_88044874, lbl_88CBF324, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBC6B4_88A00160(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF324, (ts4_word)(ts4_word)lbl_88044874, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A001C8: call_seq lbl_88B5B650, lbl_88CBF324, lbl_8804461C, lbl_88CBF354, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B650_88A001C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF354, (ts4_word)(ts4_word)lbl_8804461C, (ts4_word)(ts4_word)lbl_88CBF324, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B650, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00240: call_seq lbl_88B5B698, lbl_88044268, lbl_88CBF384, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B698_88A00240(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF384, (ts4_word)(ts4_word)lbl_88044268, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B698, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A002B0: call_seq lbl_88B5B6E0, lbl_88CBC6B4, lbl_8804484C, lbl_88CBF3B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B6E0_88A002B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF3B4, (ts4_word)(ts4_word)lbl_8804484C, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B6E0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00328: call_seq lbl_88B5B6F8, lbl_880443CC, lbl_88CBF3E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B6F8_88A00328(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF3E4, (ts4_word)(ts4_word)lbl_880443CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B6F8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00398: call_seq lbl_88B5B740, lbl_88CBF3B4, lbl_880445E4, lbl_88CBF414, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B740_88A00398(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF414, (ts4_word)(ts4_word)lbl_880445E4, (ts4_word)(ts4_word)lbl_88CBF3B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B740, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00410: call_seq lbl_88CBC6B4, lbl_8804481C, lbl_88CBF444, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBC6B4_88A00410(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF444, (ts4_word)(ts4_word)lbl_8804481C, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00478: call_seq lbl_88B5B758, lbl_88CBF444, lbl_880445A8, lbl_88CBF474, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B758_88A00478(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF474, (ts4_word)(ts4_word)lbl_880445A8, (ts4_word)(ts4_word)lbl_88CBF444, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B758, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A004F0: call_seq lbl_88B5B800, lbl_8804449C, lbl_88CBF4A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B800_88A004F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF4A4, (ts4_word)(ts4_word)lbl_8804449C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B800, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00560: call_seq lbl_88B5B830, lbl_88CBC6B4, lbl_88044744, lbl_88CBF4D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B830_88A00560(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF4D4, (ts4_word)(ts4_word)lbl_88044744, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B830, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A005D8: call_seq lbl_88B5B878, lbl_88CBC6B4, lbl_88044758, lbl_88CBF504, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B878_88A005D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF504, (ts4_word)(ts4_word)lbl_88044758, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B878, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00650: call_seq lbl_88CBC6B4, lbl_880447EC, lbl_88CBF534, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBC6B4_88A00650(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF534, (ts4_word)(ts4_word)lbl_880447EC, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A006B8: call_seq lbl_88B5B8C0, lbl_88CBF534, lbl_88044568, lbl_88CBF564, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B8C0_88A006B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF564, (ts4_word)(ts4_word)lbl_88044568, (ts4_word)(ts4_word)lbl_88CBF534, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B8C0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00730: call_seq lbl_88B5B908, lbl_88CBC6B4, lbl_880447B8, lbl_88CBF594, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B908_88A00730(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF594, (ts4_word)(ts4_word)lbl_880447B8, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B908, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A007A8: call_seq lbl_88B5B920, lbl_88CBC6B4, lbl_88044784, lbl_88CBF5C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B920_88A007A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF5C4, (ts4_word)(ts4_word)lbl_88044784, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B920, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00820: call_seq lbl_88B5B938, lbl_88CBF594, lbl_880444CC, lbl_88CBF5F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B938_88A00820(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF5F4, (ts4_word)(ts4_word)lbl_880444CC, (ts4_word)(ts4_word)lbl_88CBF594, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5B938, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00898: call_seq lbl_88050678, lbl_88051030, lbl_88CBF624, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF560, fn_88563470 */
ts4_word ts4_call_seq_lbl_88050678_88A00898(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CBF624, (ts4_word)(ts4_word)lbl_88051030, (ts4_word)3, (ts4_word)(ts4_word)lbl_88050678);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF560);
    return t2;
}

/* Swing_DLL.xex 0x88A008E0: call_seq lbl_88B5C208, lbl_88046C94, lbl_88CBF63C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C208_88A008E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF63C, (ts4_word)(ts4_word)lbl_88046C94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C208, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00950: addr lbl_88B61170, u32@lbl_88B5C280, u32@0x38 */
void ts4_addr_lbl_88B61170_88A00950(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B61170) + 56) = (ts4_word)(*(ts4_word *)lbl_88B5C280);
    return;
}

/* Swing_DLL.xex 0x88A00968: call_seq lbl_880514A4, lbl_88B61170, lbl_8803EF04, lbl_88CBF66C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880514A4_88A00968(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF66C, (ts4_word)(ts4_word)lbl_8803EF04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880514A4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B61170, (ts4_word)3, (ts4_word)((ts4_word)lbl_880514A4 + 20), (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A009E0: call_seq lbl_88B5C284, lbl_88046C78, lbl_88CBF69C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C284_88A009E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF69C, (ts4_word)(ts4_word)lbl_88046C78, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C284, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00A50: call_seq lbl_88B5C2B4, lbl_8803EC6C, lbl_88CBF6CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C2B4_88A00A50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF6CC, (ts4_word)(ts4_word)lbl_8803EC6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C2B4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00AC0: call_seq lbl_88B5C2E8, lbl_88CBFA5C, lbl_8803EE48, lbl_88CBF6FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C2E8_88A00AC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF6FC, (ts4_word)(ts4_word)lbl_8803EE48, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C2E8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00B38: call_seq lbl_88B5C348, lbl_88040040, lbl_88CBF72C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C348_88A00B38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF72C, (ts4_word)(ts4_word)lbl_88040040, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C348, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00BA8: call_seq lbl_88B5C3A8, lbl_88CBF6FC, lbl_8803ECD0, lbl_88CBF75C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C3A8_88A00BA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF75C, (ts4_word)(ts4_word)lbl_8803ECD0, (ts4_word)(ts4_word)lbl_88CBF6FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C3A8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00C20: call_seq lbl_88B5C438, lbl_88CBF6FC, lbl_8803ECB0, lbl_88CBF78C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C438_88A00C20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF78C, (ts4_word)(ts4_word)lbl_8803ECB0, (ts4_word)(ts4_word)lbl_88CBF6FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C438, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00C98: call_seq lbl_88B5C450, lbl_88040078, lbl_88CBF7BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C450_88A00C98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF7BC, (ts4_word)(ts4_word)lbl_88040078, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C450, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00D08: call_seq lbl_88B5C4B0, lbl_88CBF6FC, lbl_8803EC94, lbl_88CBF7EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C4B0_88A00D08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF7EC, (ts4_word)(ts4_word)lbl_8803EC94, (ts4_word)(ts4_word)lbl_88CBF6FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C4B0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00D80: call_seq lbl_88B5C558, lbl_88046C60, lbl_88CBF81C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C558_88A00D80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF81C, (ts4_word)(ts4_word)lbl_88046C60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C558, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00DF0: call_seq lbl_88B5C570, lbl_8803EE88, lbl_88CBF84C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C570_88A00DF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF84C, (ts4_word)(ts4_word)lbl_8803EE88, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C570, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00E60: call_seq lbl_88B5C5D0, lbl_88CBFA5C, lbl_8804002C, lbl_88CBF87C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C5D0_88A00E60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF87C, (ts4_word)(ts4_word)lbl_8804002C, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C5D0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00ED8: call_seq lbl_88B5C5E8, lbl_88046C00, lbl_88CBF8AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C5E8_88A00ED8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF8AC, (ts4_word)(ts4_word)lbl_88046C00, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C5E8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00F48: call_seq lbl_88B5C630, lbl_88046C24, lbl_88CBF8DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C630_88A00F48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF8DC, (ts4_word)(ts4_word)lbl_88046C24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C630, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A00FB8: call_seq lbl_88B5C6C0, lbl_88046C48, lbl_88CBF90C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C6C0_88A00FB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF90C, (ts4_word)(ts4_word)lbl_88046C48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C6C0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01028: call_seq lbl_88CBFA5C, lbl_8803EC3C, lbl_88CBF93C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBFA5C_88A01028(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF93C, (ts4_word)(ts4_word)lbl_8803EC3C, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01090: call_seq lbl_88B5C750, lbl_88CBF93C, lbl_8803ECF4, lbl_88CBF96C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C750_88A01090(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF96C, (ts4_word)(ts4_word)lbl_8803ECF4, (ts4_word)(ts4_word)lbl_88CBF93C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C750, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01108: call_seq lbl_88B5C7B0, lbl_8803EEFC, lbl_88CBF99C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C7B0_88A01108(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF99C, (ts4_word)(ts4_word)lbl_8803EEFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C7B0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01178: call_seq lbl_88B5C7E0, lbl_8803EEE8, lbl_88CBF9CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C7E0_88A01178(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF9CC, (ts4_word)(ts4_word)lbl_8803EEE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C7E0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A011E8: call_seq lbl_88B5C828, lbl_8803EE7C, lbl_88CBF9FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C828_88A011E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBF9FC, (ts4_word)(ts4_word)lbl_8803EE7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C828, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01258: call_seq lbl_8803C97C, lbl_88CBFA2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803C97C_88A01258(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFA2C, (ts4_word)(ts4_word)lbl_8803C97C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A012B8: call_seq lbl_88B5C888, lbl_88CBFA2C, lbl_8803C9DC, lbl_88CBFA5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C888_88A012B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)(ts4_word)lbl_8803C9DC, (ts4_word)(ts4_word)lbl_88CBFA2C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C888, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01330: call_seq lbl_88B5C8B8, lbl_8803CC5C, lbl_88CBFA8C, lbl_880514D0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C8B8_88A01330(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFA8C, (ts4_word)(ts4_word)lbl_8803CC5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880514D0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B5C8B8, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A013A0: call_seq lbl_88B5C960, lbl_8803CCC4, lbl_88CBFABC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C960_88A013A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFABC, (ts4_word)(ts4_word)lbl_8803CCC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C960, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01410: call_seq lbl_88B5C990, lbl_8803CCD4, lbl_88CBFAEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C990_88A01410(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFAEC, (ts4_word)(ts4_word)lbl_8803CCD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C990, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01480: addr lbl_88B611B8, u32@lbl_88B5C9C0, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88B611B8_88A01480(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B5C9C0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B611B8) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B611B8) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A014A0: call_seq lbl_88B611B8, lbl_8803D124, lbl_88CBFB1C, lbl_88051640, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B611B8_88A014A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFB1C, (ts4_word)(ts4_word)lbl_8803D124, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88051640, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B611B8, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01510: call_seq lbl_88B5C9CC, lbl_8803D484, lbl_88CBFB4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C9CC_88A01510(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFB4C, (ts4_word)(ts4_word)lbl_8803D484, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C9CC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01580: call_seq lbl_88B5C9FC, lbl_8803D4A8, lbl_88CBFB7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5C9FC_88A01580(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFB7C, (ts4_word)(ts4_word)lbl_8803D4A8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5C9FC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A015F0: addr lbl_88B61278, u32@lbl_88B5CA14, u32@0x50 */
void ts4_addr_lbl_88B61278_88A015F0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B61278) + 80) = (ts4_word)(*(ts4_word *)lbl_88B5CA14);
    return;
}

/* Swing_DLL.xex 0x88A01608: call_seq lbl_88B61278, lbl_8803D4C4, lbl_88CBFBAC, lbl_88051694, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61278_88A01608(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFBAC, (ts4_word)(ts4_word)lbl_8803D4C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88051694, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B61278, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01678: call_seq lbl_88B5CA18, lbl_8803CAF0, lbl_88CBFBDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CA18_88A01678(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFBDC, (ts4_word)(ts4_word)lbl_8803CAF0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5CA18, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A016E8: call_seq lbl_88B5CA48, lbl_8803D194, lbl_88CBFC0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CA48_88A016E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFC0C, (ts4_word)(ts4_word)lbl_8803D194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5CA48, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01758: call_seq lbl_88B5CA80, lbl_8803D2E0, lbl_88CBFC3C, lbl_880516B8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CA80_88A01758(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFC3C, (ts4_word)(ts4_word)lbl_8803D2E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880516B8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B5CA80, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A017C8: call_seq lbl_88B5CAE0, lbl_8803D6A0, lbl_88CBFC6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CAE0_88A017C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFC6C, (ts4_word)(ts4_word)lbl_8803D6A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5CAE0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01838: call_seq lbl_88B5CBA0, lbl_8803D914, lbl_88CBFC9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CBA0_88A01838(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFC9C, (ts4_word)(ts4_word)lbl_8803D914, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5CBA0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A018A8: call_seq lbl_88B5CBB8, lbl_8803D9E8, lbl_88CBFCCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CBB8_88A018A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFCCC, (ts4_word)(ts4_word)lbl_8803D9E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5CBB8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01918: addr lbl_88B61308, u32@lbl_88B5CA7C, u32@0x20 */
void ts4_addr_lbl_88B61308_88A01918(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B61308) + 32) = (ts4_word)(*(ts4_word *)lbl_88B5CA7C);
    return;
}

/* Swing_DLL.xex 0x88A01930: call_seq lbl_88B61308, lbl_8803F988, lbl_88CBFCFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61308_88A01930(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFCFC, (ts4_word)(ts4_word)lbl_8803F988, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61308, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A019A0: addr lbl_88B61338, u32@lbl_88B5CA7C, u32@0x20 */
void ts4_addr_lbl_88B61338_88A019A0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B61338) + 32) = (ts4_word)(*(ts4_word *)lbl_88B5CA7C);
    return;
}

/* Swing_DLL.xex 0x88A019B8: call_seq lbl_88B61338, lbl_8803F974, lbl_88CBFD2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61338_88A019B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFD2C, (ts4_word)(ts4_word)lbl_8803F974, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61338, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01A28: call_seq lbl_88B5CC30, lbl_8804E4DC, lbl_88CBFD5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CC30_88A01A28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFD5C, (ts4_word)(ts4_word)lbl_8804E4DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5CC30, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01A98: addr lbl_88B61368, u32@lbl_88B5CA7C, u32@0x20 */
void ts4_addr_lbl_88B61368_88A01A98(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B61368) + 32) = (ts4_word)(*(ts4_word *)lbl_88B5CA7C);
    return;
}

/* Swing_DLL.xex 0x88A01AB0: call_seq lbl_88B61368, lbl_8803F960, lbl_88CBFD8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61368_88A01AB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFD8C, (ts4_word)(ts4_word)lbl_8803F960, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B61368, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01B20: call_seq lbl_88B5CC48, lbl_8803F9B0, lbl_88CBFDBC, lbl_880516FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CC48_88A01B20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFDBC, (ts4_word)(ts4_word)lbl_8803F9B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880516FC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B5CC48, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01B90: call_seq lbl_88B5CC78, lbl_8803F99C, lbl_88CBFDEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CC78_88A01B90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFDEC, (ts4_word)(ts4_word)lbl_8803F99C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5CC78, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01C00: call_seq lbl_88B5CCA8, lbl_8804E4F4, lbl_88CBFE1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CCA8_88A01C00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFE1C, (ts4_word)(ts4_word)lbl_8804E4F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5CCA8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01C70: call_seq lbl_88B5CCD8, lbl_88CBFE7C, lbl_8804E50C, lbl_88CBFE4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CCD8_88A01C70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFE4C, (ts4_word)(ts4_word)lbl_8804E50C, (ts4_word)(ts4_word)lbl_88CBFE7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5CCD8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01CE8: call_seq lbl_88B5CCF0, lbl_8804E524, lbl_88CBFE7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CCF0_88A01CE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFE7C, (ts4_word)(ts4_word)lbl_8804E524, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5CCF0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01D58: call_seq lbl_88B5CD20, lbl_8804E53C, lbl_88CBFEAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CD20_88A01D58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFEAC, (ts4_word)(ts4_word)lbl_8804E53C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5CD20, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01DC8: call_seq lbl_88B5CD38, lbl_8804E560, lbl_88CBFEDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CD38_88A01DC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFEDC, (ts4_word)(ts4_word)lbl_8804E560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5CD38, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01E38: call_seq lbl_88B5CD68, lbl_8803F5C8, lbl_88CBFF0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CD68_88A01E38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFF0C, (ts4_word)(ts4_word)lbl_8803F5C8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5CD68, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01EA8: call_seq lbl_88B5CE10, lbl_8804C310, lbl_88CBFF3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CE10_88A01EA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFF3C, (ts4_word)(ts4_word)lbl_8804C310, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5CE10, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01F18: call_seq lbl_88B5CE40, lbl_8803ED20, lbl_88CBFF6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CE40_88A01F18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFF6C, (ts4_word)(ts4_word)lbl_8803ED20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5CE40, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A01F88: addr lbl_88B61398, u32@lbl_88B5CF00, u32@0x8 */
void ts4_addr_lbl_88B61398_88A01F88(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B61398) + 8) = (ts4_word)(*(ts4_word *)lbl_88B5CF00);
    return;
}

/* Swing_DLL.xex 0x88A01FA0: call_seq lbl_88B61398, lbl_8804C33C, lbl_88CBFF9C, lbl_88051728, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61398_88A01FA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFF9C, (ts4_word)(ts4_word)lbl_8804C33C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88051728, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B61398, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02010: call_seq lbl_88B5CF08, lbl_8803ED28, lbl_88CBFFCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CF08_88A02010(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFFCC, (ts4_word)(ts4_word)lbl_8803ED28, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5CF08, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02080: call_seq lbl_88B5CF38, lbl_8803ED14, lbl_88CBFFFC, lbl_8805176C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CF38_88A02080(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBFFFC, (ts4_word)(ts4_word)lbl_8803ED14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805176C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B5CF38, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A020F0: addr lbl_88B61410, u32@lbl_88B5CFF8, u32@0x20 */
void ts4_addr_lbl_88B61410_88A020F0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B61410) + 32) = (ts4_word)(*(ts4_word *)lbl_88B5CFF8);
    return;
}

/* Swing_DLL.xex 0x88A02108: call_seq lbl_88B61410, lbl_8804E57C, lbl_88CC002C, lbl_880517A8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61410_88A02108(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC002C, (ts4_word)(ts4_word)lbl_8804E57C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880517A8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B61410, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02178: call_seq lbl_88B5CFFC, lbl_8804C348, lbl_88CC005C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5CFFC_88A02178(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC005C, (ts4_word)(ts4_word)lbl_8804C348, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5CFFC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A021E8: call_seq lbl_88B5D014, lbl_8804C358, lbl_88CC008C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D014_88A021E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC008C, (ts4_word)(ts4_word)lbl_8804C358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D014, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02258: addr lbl_88B61458, u32@lbl_88B5D044, u32@0x8 */
void ts4_addr_lbl_88B61458_88A02258(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B61458) + 8) = (ts4_word)(*(ts4_word *)lbl_88B5D044);
    return;
}

/* Swing_DLL.xex 0x88A02270: call_seq lbl_88B61458, lbl_8804C380, lbl_88CC00BC, lbl_880517E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61458_88A02270(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC00BC, (ts4_word)(ts4_word)lbl_8804C380, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880517E4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B61458, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A022E0: call_seq lbl_88B5D048, lbl_88042408, lbl_88CC00EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D048_88A022E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC00EC, (ts4_word)(ts4_word)lbl_88042408, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D048, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02350: call_seq lbl_88B5D060, lbl_880423F8, lbl_88CC011C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D060_88A02350(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC011C, (ts4_word)(ts4_word)lbl_880423F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D060, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A023C0: call_seq lbl_88B5D0A8, lbl_8804C390, lbl_88CC014C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D0A8_88A023C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC014C, (ts4_word)(ts4_word)lbl_8804C390, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D0A8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02430: call_seq lbl_88B5D0D8, lbl_8804C3A0, lbl_88CC017C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D0D8_88A02430(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC017C, (ts4_word)(ts4_word)lbl_8804C3A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D0D8, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A024A0: call_seq lbl_88B5D1F8, lbl_8804C3B0, lbl_88CC01AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D1F8_88A024A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC01AC, (ts4_word)(ts4_word)lbl_8804C3B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D1F8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02510: call_seq lbl_88B5D288, lbl_8804C3C4, lbl_88CC01DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D288_88A02510(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC01DC, (ts4_word)(ts4_word)lbl_8804C3C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D288, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02580: call_seq lbl_88B5D348, lbl_8804C3DC, lbl_88CC020C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D348_88A02580(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC020C, (ts4_word)(ts4_word)lbl_8804C3DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D348, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A025F0: call_seq lbl_88B5D420, lbl_8804C3F8, lbl_88CC023C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D420_88A025F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC023C, (ts4_word)(ts4_word)lbl_8804C3F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D420, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02660: call_seq lbl_88B5D4E0, lbl_8804C410, lbl_88CC026C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D4E0_88A02660(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC026C, (ts4_word)(ts4_word)lbl_8804C410, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D4E0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A026D0: call_seq lbl_88B5D588, lbl_880517F8, lbl_8803F5BC, lbl_88CC029C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D588_88A026D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC029C, (ts4_word)(ts4_word)lbl_8803F5BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D588, (ts4_word)12, (ts4_word)(ts4_word)lbl_880517F8, (ts4_word)0, (ts4_word)0);
    return t1;
}
