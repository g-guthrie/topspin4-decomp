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

extern char ts4_addr_lbl_8803A308_88AFF548[];
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
extern char lbl_8803EF90[];
extern char lbl_8803EF9C[];
extern char lbl_8803EFC0[];
extern char lbl_8803EFE8[];
extern char lbl_8803F00C[];
extern char lbl_8803F064[];
extern char lbl_8803F0C8[];
extern char lbl_8803F5BC[];
extern char lbl_8803F5C8[];
extern char lbl_8803F5E0[];
extern char lbl_8803F5F4[];
extern char lbl_8803F610[];
extern char lbl_8803F634[];
extern char lbl_8803F64C[];
extern char lbl_8803F690[];
extern char lbl_8803F960[];
extern char lbl_8803F974[];
extern char lbl_8803F988[];
extern char lbl_8803F99C[];
extern char lbl_8803F9B0[];
extern char lbl_8803F9D4[];
extern char lbl_8803FA04[];
extern char lbl_8803FBF4[];
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
extern char lbl_88040278[];
extern char lbl_88040344[];
extern char lbl_88040364[];
extern char lbl_88040394[];
extern char lbl_880403DC[];
extern char lbl_8804044C[];
extern char lbl_88040508[];
extern char lbl_88040534[];
extern char lbl_88040560[];
extern char lbl_88040590[];
extern char lbl_88040608[];
extern char lbl_88040630[];
extern char lbl_88040658[];
extern char lbl_88041284[];
extern char lbl_88041B24[];
extern char lbl_88042170[];
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
extern char lbl_88045194[];
extern char lbl_88045224[];
extern char lbl_88045734[];
extern char lbl_880459C0[];
extern char lbl_88045A30[];
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
extern char lbl_88046C78[];
extern char lbl_88046C94[];
extern char lbl_88047050[];
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
extern char lbl_8804F838[];
extern char lbl_880501E0[];
extern char lbl_8805069C[];
extern char lbl_880506C8[];
extern char lbl_88050838[];
extern char lbl_8805088C[];
extern char lbl_880508B0[];
extern char lbl_880508F4[];
extern char lbl_88050920[];
extern char lbl_88050964[];
extern char lbl_880509A0[];
extern char lbl_880509DC[];
extern char lbl_880509F0[];
extern char lbl_88050A78[];
extern char lbl_88050ACC[];
extern char lbl_88050B1C[];
extern char lbl_88050BE8[];
extern char lbl_88050C44[];
extern char lbl_88050C80[];
extern char lbl_88050CC4[];
extern char lbl_88B553E0[];
extern char lbl_88B55590[];
extern char lbl_88B55728[];
extern char lbl_88B55998[];
extern char lbl_88B55A10[];
extern char lbl_88B55A58[];
extern char lbl_88B55A88[];
extern char lbl_88B55AE8[];
extern char lbl_88B55B48[];
extern char lbl_88B55C38[];
extern char lbl_88B55D28[];
extern char lbl_88B55D70[];
extern char lbl_88B55E48[];
extern char lbl_88B55E60[];
extern char lbl_88B55EA8[];
extern char lbl_88B55EF0[];
extern char lbl_88B55F08[];
extern char lbl_88B55F50[];
extern char lbl_88B55F68[];
extern char lbl_88B56010[];
extern char lbl_88B56040[];
extern char lbl_88B56088[];
extern char lbl_88B560D0[];
extern char lbl_88B56118[];
extern char lbl_88B56130[];
extern char lbl_88B56148[];
extern char lbl_88B56A18[];
extern char lbl_88B56A90[];
extern char lbl_88B56A94[];
extern char lbl_88B56AC4[];
extern char lbl_88B56AF8[];
extern char lbl_88B56B58[];
extern char lbl_88B56BB8[];
extern char lbl_88B56C48[];
extern char lbl_88B56C60[];
extern char lbl_88B56CC0[];
extern char lbl_88B56D68[];
extern char lbl_88B56D80[];
extern char lbl_88B56DE0[];
extern char lbl_88B56DF8[];
extern char lbl_88B56E40[];
extern char lbl_88B56ED0[];
extern char lbl_88B56F60[];
extern char lbl_88B56FC0[];
extern char lbl_88B56FF0[];
extern char lbl_88B57038[];
extern char lbl_88B57098[];
extern char lbl_88B570C8[];
extern char lbl_88B57170[];
extern char lbl_88B571A0[];
extern char lbl_88B571D0[];
extern char lbl_88B571DC[];
extern char lbl_88B5720C[];
extern char lbl_88B57224[];
extern char lbl_88B57228[];
extern char lbl_88B57258[];
extern char lbl_88B5728C[];
extern char lbl_88B57290[];
extern char lbl_88B572F0[];
extern char lbl_88B573B0[];
extern char lbl_88B573C8[];
extern char lbl_88B57440[];
extern char lbl_88B57458[];
extern char lbl_88B57488[];
extern char lbl_88B574B8[];
extern char lbl_88B574E8[];
extern char lbl_88B57500[];
extern char lbl_88B57530[];
extern char lbl_88B57548[];
extern char lbl_88B57578[];
extern char lbl_88B57620[];
extern char lbl_88B57650[];
extern char lbl_88B57710[];
extern char lbl_88B57718[];
extern char lbl_88B57748[];
extern char lbl_88B57808[];
extern char lbl_88B5780C[];
extern char lbl_88B57824[];
extern char lbl_88B57854[];
extern char lbl_88B57858[];
extern char lbl_88B57870[];
extern char lbl_88B578B8[];
extern char lbl_88B578E8[];
extern char lbl_88B57A08[];
extern char lbl_88B57A98[];
extern char lbl_88B57B58[];
extern char lbl_88B57C30[];
extern char lbl_88B57CF0[];
extern char lbl_88B57D98[];
extern char lbl_88B57EB8[];
extern char lbl_88B57F18[];
extern char lbl_88B58020[];
extern char lbl_88B580F8[];
extern char lbl_88B58128[];
extern char lbl_88B58140[];
extern char lbl_88B58188[];
extern char lbl_88B581A0[];
extern char lbl_88B581E8[];
extern char lbl_88B58248[];
extern char lbl_88B58290[];
extern char lbl_88B582F0[];
extern char lbl_88B58320[];
extern char lbl_88B58338[];
extern char lbl_88B58350[];
extern char lbl_88B583B0[];
extern char lbl_88B583C8[];
extern char lbl_88B583F8[];
extern char lbl_88B58410[];
extern char lbl_88B58440[];
extern char lbl_88B58458[];
extern char lbl_88B58470[];
extern char lbl_88B58488[];
extern char lbl_88B584D0[];
extern char lbl_88B58500[];
extern char lbl_88B58530[];
extern char lbl_88B58578[];
extern char lbl_88B585F4[];
extern char lbl_88B585F8[];
extern char lbl_88B58670[];
extern char lbl_88B586A0[];
extern char lbl_88B586B8[];
extern char lbl_88B586D4[];
extern char lbl_88B586D8[];
extern char lbl_88B58738[];
extern char lbl_88B58750[];
extern char lbl_88B58780[];
extern char lbl_88B587B0[];
extern char lbl_88B587E0[];
extern char lbl_88B58828[];
extern char lbl_88B588D0[];
extern char lbl_88B58918[];
extern char lbl_88B58978[];
extern char lbl_88B58A08[];
extern char lbl_88B58A20[];
extern char lbl_88B58A50[];
extern char lbl_88B58A98[];
extern char lbl_88B58AE0[];
extern char lbl_88B58B40[];
extern char lbl_88B58B58[];
extern char lbl_88B58B88[];
extern char lbl_88B58BE8[];
extern char lbl_88B58C00[];
extern char lbl_88B58C30[];
extern char lbl_88B58C48[];
extern char lbl_88B58C60[];
extern char lbl_88B58CAC[];
extern char lbl_88B58CC4[];
extern char lbl_88B58CC8[];
extern char lbl_88B58D30[];
extern char lbl_88B58D48[];
extern char lbl_88B58D78[];
extern char lbl_88B58DC0[];
extern char lbl_88B58DF0[];
extern char lbl_88B58E20[];
extern char lbl_88B58E80[];
extern char lbl_88B58EC8[];
extern char lbl_88B58F58[];
extern char lbl_88B58FD0[];
extern char lbl_88B58FD8[];
extern char lbl_88B59020[];
extern char lbl_88B59080[];
extern char lbl_88B590C8[];
extern char lbl_88B5B980[];
extern char lbl_88B5B9C8[];
extern char lbl_88B5BA88[];
extern char lbl_88B5BB18[];
extern char lbl_88B5BB48[];
extern char lbl_88B5BB78[];
extern char lbl_88B5BBA8[];
extern char lbl_88B5BC20[];
extern char lbl_88B5BC68[];
extern char lbl_88B5BCE0[];
extern char lbl_88B5BE18[];
extern char lbl_88B5BE60[];
extern char lbl_88B5BF20[];
extern char lbl_88CB933C[];
extern char lbl_88CBA74C[];
extern char lbl_88CBBC1C[];
extern char lbl_88CBBC4C[];
extern char lbl_88CBBC7C[];
extern char lbl_88CBBCAC[];
extern char lbl_88CBBCDC[];
extern char lbl_88CBBD0C[];
extern char lbl_88CBBD3C[];
extern char lbl_88CBBD6C[];
extern char lbl_88CBBD9C[];
extern char lbl_88CBBDCC[];
extern char lbl_88CBBDFC[];
extern char lbl_88CBBE2C[];
extern char lbl_88CBBE5C[];
extern char lbl_88CBBE8C[];
extern char lbl_88CBBEBC[];
extern char lbl_88CBBEEC[];
extern char lbl_88CBBF1C[];
extern char lbl_88CBBF4C[];
extern char lbl_88CBBF7C[];
extern char lbl_88CBBFAC[];
extern char lbl_88CBBFDC[];
extern char lbl_88CBC00C[];
extern char lbl_88CBC03C[];
extern char lbl_88CBC06C[];
extern char lbl_88CBC09C[];
extern char lbl_88CBC0CC[];
extern char lbl_88CBC0FC[];
extern char lbl_88CBC12C[];
extern char lbl_88CBC15C[];
extern char lbl_88CBC18C[];
extern char lbl_88CBC1BC[];
extern char lbl_88CBC1EC[];
extern char lbl_88CBC21C[];
extern char lbl_88CBC24C[];
extern char lbl_88CBC27C[];
extern char lbl_88CBC294[];
extern char lbl_88CBC2C4[];
extern char lbl_88CBC2F4[];
extern char lbl_88CBC324[];
extern char lbl_88CBC354[];
extern char lbl_88CBC384[];
extern char lbl_88CBC3B4[];
extern char lbl_88CBC3E4[];
extern char lbl_88CBC414[];
extern char lbl_88CBC444[];
extern char lbl_88CBC474[];
extern char lbl_88CBC4A4[];
extern char lbl_88CBC4D4[];
extern char lbl_88CBC504[];
extern char lbl_88CBC534[];
extern char lbl_88CBC564[];
extern char lbl_88CBC594[];
extern char lbl_88CBC5C4[];
extern char lbl_88CBC5F4[];
extern char lbl_88CBC624[];
extern char lbl_88CBC654[];
extern char lbl_88CBC684[];
extern char lbl_88CBC6B4[];
extern char lbl_88CBC6E4[];
extern char lbl_88CBC714[];
extern char lbl_88CBC744[];
extern char lbl_88CBC774[];
extern char lbl_88CBC7A4[];
extern char lbl_88CBC7D4[];
extern char lbl_88CBC804[];
extern char lbl_88CBC834[];
extern char lbl_88CBC864[];
extern char lbl_88CBC894[];
extern char lbl_88CBC8C4[];
extern char lbl_88CBC8F4[];
extern char lbl_88CBC924[];
extern char lbl_88CBC954[];
extern char lbl_88CBC984[];
extern char lbl_88CBC9B4[];
extern char lbl_88CBC9E4[];
extern char lbl_88CBCA14[];
extern char lbl_88CBCA44[];
extern char lbl_88CBCA74[];
extern char lbl_88CBCAA4[];
extern char lbl_88CBCAD4[];
extern char lbl_88CBCB04[];
extern char lbl_88CBCB34[];
extern char lbl_88CBCB64[];
extern char lbl_88CBCB94[];
extern char lbl_88CBCBC4[];
extern char lbl_88CBCBF4[];
extern char lbl_88CBCC24[];
extern char lbl_88CBCC54[];
extern char lbl_88CBCC84[];
extern char lbl_88CBCCB4[];
extern char lbl_88CBCCE4[];
extern char lbl_88CBCD14[];
extern char lbl_88CBCD44[];
extern char lbl_88CBCD74[];
extern char lbl_88CBCDA4[];
extern char lbl_88CBCDD4[];
extern char lbl_88CBCE04[];
extern char lbl_88CBCE34[];
extern char lbl_88CBCE64[];
extern char lbl_88CBCE94[];
extern char lbl_88CBCEC4[];
extern char lbl_88CBCEF4[];
extern char lbl_88CBCF24[];
extern char lbl_88CBCF54[];
extern char lbl_88CBCF84[];
extern char lbl_88CBCFB4[];
extern char lbl_88CBCFE4[];
extern char lbl_88CBD014[];
extern char lbl_88CBD044[];
extern char lbl_88CBD074[];
extern char lbl_88CBD0A4[];
extern char lbl_88CBD0D4[];
extern char lbl_88CBD104[];
extern char lbl_88CBD134[];
extern char lbl_88CBD164[];
extern char lbl_88CBD194[];
extern char lbl_88CBD1C4[];
extern char lbl_88CBD1F4[];
extern char lbl_88CBD224[];
extern char lbl_88CBD254[];
extern char lbl_88CBD284[];
extern char lbl_88CBD2B4[];
extern char lbl_88CBD2E4[];
extern char lbl_88CBD314[];
extern char lbl_88CBD344[];
extern char lbl_88CBD374[];
extern char lbl_88CBD3A4[];
extern char lbl_88CBD3D4[];
extern char lbl_88CBD404[];
extern char lbl_88CBD434[];
extern char lbl_88CBD464[];
extern char lbl_88CBD494[];
extern char lbl_88CBD4C4[];
extern char lbl_88CBD4F4[];
extern char lbl_88CBD524[];
extern char lbl_88CBD554[];
extern char lbl_88CBD584[];
extern char lbl_88CBD5B4[];
extern char lbl_88CBD5E4[];
extern char lbl_88CBD614[];
extern char lbl_88CBD644[];
extern char lbl_88CBD674[];
extern char lbl_88CBD6A4[];
extern char lbl_88CBD6D4[];
extern char lbl_88CBD704[];
extern char lbl_88CBD734[];
extern char lbl_88CBD764[];
extern char lbl_88CBD794[];
extern char lbl_88CBD7C4[];
extern char lbl_88CBD7F4[];
extern char lbl_88CBD824[];
extern char lbl_88CBD854[];
extern char lbl_88CBD884[];
extern char lbl_88CBD8B4[];
extern char lbl_88CBD8E4[];
extern char lbl_88CBD914[];
extern char lbl_88CBD944[];
extern char lbl_88CBD974[];
extern char lbl_88CBD9A4[];
extern char lbl_88CBD9D4[];
extern char lbl_88CBDA04[];
extern char lbl_88CBDA34[];
extern char lbl_88CBDA64[];
extern char lbl_88CBDA94[];
extern char lbl_88CBDAC4[];
extern char lbl_88CBDAF4[];
extern char lbl_88CBDB24[];
extern char lbl_88CBDB54[];
extern char lbl_88CBDB84[];
extern char lbl_88CBDBB4[];
extern char lbl_88CBDBE4[];
extern char lbl_88CBDC14[];
extern char lbl_88CBDC44[];
extern char lbl_88CBDC74[];
extern char lbl_88CBDCA4[];
extern char lbl_88CBDCD4[];
extern char lbl_88CBDD04[];
extern char lbl_88CBDD34[];
extern char lbl_88CBDD64[];
extern char lbl_88CBDD94[];
extern char lbl_88CBDDC4[];
extern char lbl_88CBDDF4[];
extern char lbl_88CBDE24[];
extern char lbl_88CBDE54[];
extern char lbl_88CBDE84[];
extern char lbl_88CBDEB4[];
extern char lbl_88CBDEE4[];
extern char lbl_88CBE934[];
ts4_word fn_8841F080();
ts4_word ts4_set_u32_offc_884CE988();
ts4_word fn_88563470();

/* Swing_DLL.xex 0x889F7CB0: call_seq lbl_88B553E0, lbl_88CB933C, lbl_88040658, lbl_88CBBC1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B553E0_889F7CB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBC1C, (ts4_word)(ts4_word)lbl_88040658, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B553E0, (ts4_word)18, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7D28: call_seq lbl_88B55590, lbl_8803F5F4, lbl_88CBBC4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55590_889F7D28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBC4C, (ts4_word)(ts4_word)lbl_8803F5F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55590, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7D98: call_seq lbl_88B55728, lbl_88CBA74C, lbl_8803F64C, lbl_88CBBC7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55728_889F7D98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBC7C, (ts4_word)(ts4_word)lbl_8803F64C, (ts4_word)(ts4_word)lbl_88CBA74C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55728, (ts4_word)26, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7E10: call_seq lbl_88CB933C, lbl_8804494C, lbl_88CBBCAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB933C_889F7E10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBCAC, (ts4_word)(ts4_word)lbl_8804494C, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7E78: call_seq lbl_88B55998, lbl_88CBBCAC, lbl_88044700, lbl_88CBBCDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55998_889F7E78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBCDC, (ts4_word)(ts4_word)lbl_88044700, (ts4_word)(ts4_word)lbl_88CBBCAC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55998, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7EF0: call_seq lbl_88CB933C, lbl_88044924, lbl_88CBBD0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB933C_889F7EF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBD0C, (ts4_word)(ts4_word)lbl_88044924, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7F58: call_seq lbl_88B55A10, lbl_88044438, lbl_88CBBD3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55A10_889F7F58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBD3C, (ts4_word)(ts4_word)lbl_88044438, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55A10, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7FC8: call_seq lbl_88B55A58, lbl_88CBBD0C, lbl_88044680, lbl_88CBBD6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55A58_889F7FC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBD6C, (ts4_word)(ts4_word)lbl_88044680, (ts4_word)(ts4_word)lbl_88CBBD0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55A58, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8040: call_seq lbl_88CB933C, lbl_880448C8, lbl_88CBBD9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB933C_889F8040(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBD9C, (ts4_word)(ts4_word)lbl_880448C8, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F80A8: call_seq lbl_88CB933C, lbl_880448FC, lbl_88CBBDCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB933C_889F80A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBDCC, (ts4_word)(ts4_word)lbl_880448FC, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8110: call_seq lbl_88B55A88, lbl_88CBBD9C, lbl_88044524, lbl_88CBBDFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55A88_889F8110(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBDFC, (ts4_word)(ts4_word)lbl_88044524, (ts4_word)(ts4_word)lbl_88CBBD9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55A88, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8188: call_seq lbl_88B55AE8, lbl_88CBBDCC, lbl_880446BC, lbl_88CBBE2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55AE8_889F8188(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBE2C, (ts4_word)(ts4_word)lbl_880446BC, (ts4_word)(ts4_word)lbl_88CBBDCC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55AE8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8200: call_seq lbl_88CB933C, lbl_8804489C, lbl_88CBBE5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB933C_889F8200(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBE5C, (ts4_word)(ts4_word)lbl_8804489C, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8268: call_seq lbl_88B55B48, lbl_88CBBE5C, lbl_88044650, lbl_88CBBE8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55B48_889F8268(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBE8C, (ts4_word)(ts4_word)lbl_88044650, (ts4_word)(ts4_word)lbl_88CBBE5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55B48, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F82E0: call_seq lbl_88B55C38, lbl_88044324, lbl_88CBBEBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55C38_889F82E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBEBC, (ts4_word)(ts4_word)lbl_88044324, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55C38, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8350: call_seq lbl_88B55D28, lbl_88044370, lbl_88CBBEEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55D28_889F8350(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBEEC, (ts4_word)(ts4_word)lbl_88044370, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55D28, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F83C0: call_seq lbl_88B55D70, lbl_8803F610, lbl_88CBBF1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55D70_889F83C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBF1C, (ts4_word)(ts4_word)lbl_8803F610, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55D70, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8430: call_seq lbl_88B55E48, lbl_8803F634, lbl_88CBBF4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55E48_889F8430(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBF4C, (ts4_word)(ts4_word)lbl_8803F634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55E48, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F84A0: call_seq lbl_88CB933C, lbl_88044874, lbl_88CBBF7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB933C_889F84A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBF7C, (ts4_word)(ts4_word)lbl_88044874, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8508: call_seq lbl_88B55E60, lbl_88CBBF7C, lbl_8804461C, lbl_88CBBFAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55E60_889F8508(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBFAC, (ts4_word)(ts4_word)lbl_8804461C, (ts4_word)(ts4_word)lbl_88CBBF7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55E60, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8580: call_seq lbl_88B55EA8, lbl_88044268, lbl_88CBBFDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55EA8_889F8580(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBFDC, (ts4_word)(ts4_word)lbl_88044268, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55EA8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F85F0: call_seq lbl_88B55EF0, lbl_88CB933C, lbl_8804484C, lbl_88CBC00C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55EF0_889F85F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC00C, (ts4_word)(ts4_word)lbl_8804484C, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55EF0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8668: call_seq lbl_88B55F08, lbl_880443CC, lbl_88CBC03C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55F08_889F8668(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC03C, (ts4_word)(ts4_word)lbl_880443CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55F08, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F86D8: call_seq lbl_88B55F50, lbl_88CBC00C, lbl_880445E4, lbl_88CBC06C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55F50_889F86D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC06C, (ts4_word)(ts4_word)lbl_880445E4, (ts4_word)(ts4_word)lbl_88CBC00C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55F50, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8750: call_seq lbl_88CB933C, lbl_8804481C, lbl_88CBC09C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB933C_889F8750(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC09C, (ts4_word)(ts4_word)lbl_8804481C, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F87B8: call_seq lbl_88B55F68, lbl_88CBC09C, lbl_880445A8, lbl_88CBC0CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55F68_889F87B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC0CC, (ts4_word)(ts4_word)lbl_880445A8, (ts4_word)(ts4_word)lbl_88CBC09C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55F68, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8830: call_seq lbl_88B56010, lbl_8804449C, lbl_88CBC0FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56010_889F8830(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC0FC, (ts4_word)(ts4_word)lbl_8804449C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56010, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F88A0: call_seq lbl_88B56040, lbl_88CB933C, lbl_88044744, lbl_88CBC12C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56040_889F88A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC12C, (ts4_word)(ts4_word)lbl_88044744, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56040, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8918: call_seq lbl_88B56088, lbl_88CB933C, lbl_88044758, lbl_88CBC15C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56088_889F8918(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC15C, (ts4_word)(ts4_word)lbl_88044758, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56088, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8990: call_seq lbl_88CB933C, lbl_880447EC, lbl_88CBC18C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB933C_889F8990(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC18C, (ts4_word)(ts4_word)lbl_880447EC, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F89F8: call_seq lbl_88B560D0, lbl_88CBC18C, lbl_88044568, lbl_88CBC1BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B560D0_889F89F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC1BC, (ts4_word)(ts4_word)lbl_88044568, (ts4_word)(ts4_word)lbl_88CBC18C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B560D0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8A70: call_seq lbl_88B56118, lbl_88CB933C, lbl_880447B8, lbl_88CBC1EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56118_889F8A70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC1EC, (ts4_word)(ts4_word)lbl_880447B8, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56118, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8AE8: call_seq lbl_88B56130, lbl_88CB933C, lbl_88044784, lbl_88CBC21C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56130_889F8AE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC21C, (ts4_word)(ts4_word)lbl_88044784, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56130, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8B60: call_seq lbl_88B56148, lbl_88CBC1EC, lbl_880444CC, lbl_88CBC24C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56148_889F8B60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC24C, (ts4_word)(ts4_word)lbl_880444CC, (ts4_word)(ts4_word)lbl_88CBC1EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56148, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8BD8: call_seq lbl_8804F838, lbl_880501E0, lbl_88CBC27C, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF548, fn_88563470 */
ts4_word ts4_call_seq_lbl_8804F838_889F8BD8(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CBC27C, (ts4_word)(ts4_word)lbl_880501E0, (ts4_word)3, (ts4_word)(ts4_word)lbl_8804F838);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF548);
    return t2;
}

/* Swing_DLL.xex 0x889F8C20: call_seq lbl_88B56A18, lbl_88046C94, lbl_88CBC294, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56A18_889F8C20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC294, (ts4_word)(ts4_word)lbl_88046C94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56A18, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8C90: addr lbl_88B5B980, u32@lbl_88B56A90, u32@0x38 */
void ts4_addr_lbl_88B5B980_889F8C90(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B5B980) + 56) = (ts4_word)(*(ts4_word *)lbl_88B56A90);
    return;
}

/* Swing_DLL.xex 0x889F8CA8: call_seq lbl_8805069C, lbl_88B5B980, lbl_8803EF04, lbl_88CBC2C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805069C_889F8CA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC2C4, (ts4_word)(ts4_word)lbl_8803EF04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805069C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B5B980, (ts4_word)3, (ts4_word)((ts4_word)lbl_8805069C + 20), (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8D20: call_seq lbl_88B56A94, lbl_88046C78, lbl_88CBC2F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56A94_889F8D20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC2F4, (ts4_word)(ts4_word)lbl_88046C78, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56A94, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8D90: call_seq lbl_88B56AC4, lbl_8803EC6C, lbl_88CBC324, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56AC4_889F8D90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC324, (ts4_word)(ts4_word)lbl_8803EC6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56AC4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8E00: call_seq lbl_88B56AF8, lbl_88CBC6B4, lbl_8803EE48, lbl_88CBC354, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56AF8_889F8E00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC354, (ts4_word)(ts4_word)lbl_8803EE48, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56AF8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8E78: call_seq lbl_88B56B58, lbl_88040040, lbl_88CBC384, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56B58_889F8E78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC384, (ts4_word)(ts4_word)lbl_88040040, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56B58, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8EE8: call_seq lbl_88B56BB8, lbl_88CBC354, lbl_8803ECD0, lbl_88CBC3B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56BB8_889F8EE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC3B4, (ts4_word)(ts4_word)lbl_8803ECD0, (ts4_word)(ts4_word)lbl_88CBC354, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56BB8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8F60: call_seq lbl_88B56C48, lbl_88CBC354, lbl_8803ECB0, lbl_88CBC3E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56C48_889F8F60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC3E4, (ts4_word)(ts4_word)lbl_8803ECB0, (ts4_word)(ts4_word)lbl_88CBC354, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56C48, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F8FD8: call_seq lbl_88B56C60, lbl_88040078, lbl_88CBC414, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56C60_889F8FD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC414, (ts4_word)(ts4_word)lbl_88040078, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56C60, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9048: call_seq lbl_88B56CC0, lbl_88CBC354, lbl_8803EC94, lbl_88CBC444, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56CC0_889F9048(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC444, (ts4_word)(ts4_word)lbl_8803EC94, (ts4_word)(ts4_word)lbl_88CBC354, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56CC0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F90C0: call_seq lbl_88B56D68, lbl_88046C60, lbl_88CBC474, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56D68_889F90C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC474, (ts4_word)(ts4_word)lbl_88046C60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56D68, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9130: call_seq lbl_88B56D80, lbl_8803EE88, lbl_88CBC4A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56D80_889F9130(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC4A4, (ts4_word)(ts4_word)lbl_8803EE88, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56D80, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F91A0: call_seq lbl_88B56DE0, lbl_88CBC6B4, lbl_8804002C, lbl_88CBC4D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56DE0_889F91A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC4D4, (ts4_word)(ts4_word)lbl_8804002C, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56DE0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9218: call_seq lbl_88B56DF8, lbl_88046C00, lbl_88CBC504, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56DF8_889F9218(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC504, (ts4_word)(ts4_word)lbl_88046C00, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56DF8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9288: call_seq lbl_88B56E40, lbl_88046C24, lbl_88CBC534, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56E40_889F9288(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC534, (ts4_word)(ts4_word)lbl_88046C24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56E40, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F92F8: call_seq lbl_88B56ED0, lbl_88046C48, lbl_88CBC564, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56ED0_889F92F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC564, (ts4_word)(ts4_word)lbl_88046C48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56ED0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9368: call_seq lbl_88CBC6B4, lbl_8803EC3C, lbl_88CBC594, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBC6B4_889F9368(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC594, (ts4_word)(ts4_word)lbl_8803EC3C, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F93D0: call_seq lbl_88B56F60, lbl_88CBC594, lbl_8803ECF4, lbl_88CBC5C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56F60_889F93D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC5C4, (ts4_word)(ts4_word)lbl_8803ECF4, (ts4_word)(ts4_word)lbl_88CBC594, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56F60, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9448: call_seq lbl_88B56FC0, lbl_8803EEFC, lbl_88CBC5F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56FC0_889F9448(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC5F4, (ts4_word)(ts4_word)lbl_8803EEFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56FC0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F94B8: call_seq lbl_88B56FF0, lbl_8803EEE8, lbl_88CBC624, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56FF0_889F94B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC624, (ts4_word)(ts4_word)lbl_8803EEE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56FF0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9528: call_seq lbl_88B57038, lbl_8803EE7C, lbl_88CBC654, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57038_889F9528(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC654, (ts4_word)(ts4_word)lbl_8803EE7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57038, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9598: call_seq lbl_8803C97C, lbl_88CBC684, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803C97C_889F9598(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC684, (ts4_word)(ts4_word)lbl_8803C97C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F95F8: call_seq lbl_88B57098, lbl_88CBC684, lbl_8803C9DC, lbl_88CBC6B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57098_889F95F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)(ts4_word)lbl_8803C9DC, (ts4_word)(ts4_word)lbl_88CBC684, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57098, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9670: call_seq lbl_88B570C8, lbl_8803CC5C, lbl_88CBC6E4, lbl_880506C8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B570C8_889F9670(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC6E4, (ts4_word)(ts4_word)lbl_8803CC5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880506C8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B570C8, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F96E0: call_seq lbl_88B57170, lbl_8803CCC4, lbl_88CBC714, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57170_889F96E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC714, (ts4_word)(ts4_word)lbl_8803CCC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57170, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9750: call_seq lbl_88B571A0, lbl_8803CCD4, lbl_88CBC744, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B571A0_889F9750(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC744, (ts4_word)(ts4_word)lbl_8803CCD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B571A0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F97C0: addr lbl_88B5B9C8, u32@lbl_88B571D0, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88B5B9C8_889F97C0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B571D0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B5B9C8) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B5B9C8) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x889F97E0: call_seq lbl_88B5B9C8, lbl_8803D124, lbl_88CBC774, lbl_88050838, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5B9C8_889F97E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC774, (ts4_word)(ts4_word)lbl_8803D124, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88050838, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B5B9C8, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9850: call_seq lbl_88B571DC, lbl_8803D484, lbl_88CBC7A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B571DC_889F9850(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC7A4, (ts4_word)(ts4_word)lbl_8803D484, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B571DC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F98C0: call_seq lbl_88B5720C, lbl_8803D4A8, lbl_88CBC7D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5720C_889F98C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC7D4, (ts4_word)(ts4_word)lbl_8803D4A8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5720C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9930: addr lbl_88B5BA88, u32@lbl_88B57224, u32@0x50 */
void ts4_addr_lbl_88B5BA88_889F9930(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B5BA88) + 80) = (ts4_word)(*(ts4_word *)lbl_88B57224);
    return;
}

/* Swing_DLL.xex 0x889F9948: call_seq lbl_88B5BA88, lbl_8803D4C4, lbl_88CBC804, lbl_8805088C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5BA88_889F9948(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC804, (ts4_word)(ts4_word)lbl_8803D4C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805088C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B5BA88, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F99B8: call_seq lbl_88B57228, lbl_8803CAF0, lbl_88CBC834, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57228_889F99B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC834, (ts4_word)(ts4_word)lbl_8803CAF0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57228, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9A28: call_seq lbl_88B57258, lbl_8803D194, lbl_88CBC864, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57258_889F9A28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC864, (ts4_word)(ts4_word)lbl_8803D194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57258, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9A98: call_seq lbl_88B57290, lbl_8803D2E0, lbl_88CBC894, lbl_880508B0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57290_889F9A98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC894, (ts4_word)(ts4_word)lbl_8803D2E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880508B0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B57290, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9B08: call_seq lbl_88B572F0, lbl_8803D6A0, lbl_88CBC8C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B572F0_889F9B08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC8C4, (ts4_word)(ts4_word)lbl_8803D6A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B572F0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9B78: call_seq lbl_88B573B0, lbl_8803D914, lbl_88CBC8F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B573B0_889F9B78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC8F4, (ts4_word)(ts4_word)lbl_8803D914, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B573B0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9BE8: call_seq lbl_88B573C8, lbl_8803D9E8, lbl_88CBC924, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B573C8_889F9BE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC924, (ts4_word)(ts4_word)lbl_8803D9E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B573C8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9C58: addr lbl_88B5BB18, u32@lbl_88B5728C, u32@0x20 */
void ts4_addr_lbl_88B5BB18_889F9C58(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B5BB18) + 32) = (ts4_word)(*(ts4_word *)lbl_88B5728C);
    return;
}

/* Swing_DLL.xex 0x889F9C70: call_seq lbl_88B5BB18, lbl_8803F988, lbl_88CBC954, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5BB18_889F9C70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC954, (ts4_word)(ts4_word)lbl_8803F988, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5BB18, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9CE0: addr lbl_88B5BB48, u32@lbl_88B5728C, u32@0x20 */
void ts4_addr_lbl_88B5BB48_889F9CE0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B5BB48) + 32) = (ts4_word)(*(ts4_word *)lbl_88B5728C);
    return;
}

/* Swing_DLL.xex 0x889F9CF8: call_seq lbl_88B5BB48, lbl_8803F974, lbl_88CBC984, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5BB48_889F9CF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC984, (ts4_word)(ts4_word)lbl_8803F974, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5BB48, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9D68: call_seq lbl_88B57440, lbl_8804E4DC, lbl_88CBC9B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57440_889F9D68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC9B4, (ts4_word)(ts4_word)lbl_8804E4DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57440, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9DD8: addr lbl_88B5BB78, u32@lbl_88B5728C, u32@0x20 */
void ts4_addr_lbl_88B5BB78_889F9DD8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B5BB78) + 32) = (ts4_word)(*(ts4_word *)lbl_88B5728C);
    return;
}

/* Swing_DLL.xex 0x889F9DF0: call_seq lbl_88B5BB78, lbl_8803F960, lbl_88CBC9E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5BB78_889F9DF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBC9E4, (ts4_word)(ts4_word)lbl_8803F960, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5BB78, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9E60: call_seq lbl_88B57458, lbl_8803F9B0, lbl_88CBCA14, lbl_880508F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57458_889F9E60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCA14, (ts4_word)(ts4_word)lbl_8803F9B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880508F4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B57458, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9ED0: call_seq lbl_88B57488, lbl_8803F99C, lbl_88CBCA44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57488_889F9ED0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCA44, (ts4_word)(ts4_word)lbl_8803F99C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57488, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9F40: call_seq lbl_88B574B8, lbl_8804E4F4, lbl_88CBCA74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B574B8_889F9F40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCA74, (ts4_word)(ts4_word)lbl_8804E4F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B574B8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F9FB0: call_seq lbl_88B574E8, lbl_88CBCAD4, lbl_8804E50C, lbl_88CBCAA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B574E8_889F9FB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCAA4, (ts4_word)(ts4_word)lbl_8804E50C, (ts4_word)(ts4_word)lbl_88CBCAD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B574E8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA028: call_seq lbl_88B57500, lbl_8804E524, lbl_88CBCAD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57500_889FA028(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCAD4, (ts4_word)(ts4_word)lbl_8804E524, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57500, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA098: call_seq lbl_88B57530, lbl_8804E53C, lbl_88CBCB04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57530_889FA098(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCB04, (ts4_word)(ts4_word)lbl_8804E53C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57530, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA108: call_seq lbl_88B57548, lbl_8804E560, lbl_88CBCB34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57548_889FA108(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCB34, (ts4_word)(ts4_word)lbl_8804E560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57548, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA178: call_seq lbl_88B57578, lbl_8803F5C8, lbl_88CBCB64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57578_889FA178(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCB64, (ts4_word)(ts4_word)lbl_8803F5C8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57578, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA1E8: call_seq lbl_88B57620, lbl_8804C310, lbl_88CBCB94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57620_889FA1E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCB94, (ts4_word)(ts4_word)lbl_8804C310, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57620, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA258: call_seq lbl_88B57650, lbl_8803ED20, lbl_88CBCBC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57650_889FA258(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCBC4, (ts4_word)(ts4_word)lbl_8803ED20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57650, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA2C8: addr lbl_88B5BBA8, u32@lbl_88B57710, u32@0x8 */
void ts4_addr_lbl_88B5BBA8_889FA2C8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B5BBA8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B57710);
    return;
}

/* Swing_DLL.xex 0x889FA2E0: call_seq lbl_88B5BBA8, lbl_8804C33C, lbl_88CBCBF4, lbl_88050920, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5BBA8_889FA2E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCBF4, (ts4_word)(ts4_word)lbl_8804C33C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88050920, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B5BBA8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA350: call_seq lbl_88B57718, lbl_8803ED28, lbl_88CBCC24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57718_889FA350(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCC24, (ts4_word)(ts4_word)lbl_8803ED28, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57718, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA3C0: call_seq lbl_88B57748, lbl_8803ED14, lbl_88CBCC54, lbl_88050964, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57748_889FA3C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCC54, (ts4_word)(ts4_word)lbl_8803ED14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88050964, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B57748, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA430: addr lbl_88B5BC20, u32@lbl_88B57808, u32@0x20 */
void ts4_addr_lbl_88B5BC20_889FA430(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B5BC20) + 32) = (ts4_word)(*(ts4_word *)lbl_88B57808);
    return;
}

/* Swing_DLL.xex 0x889FA448: call_seq lbl_88B5BC20, lbl_8804E57C, lbl_88CBCC84, lbl_880509A0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5BC20_889FA448(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCC84, (ts4_word)(ts4_word)lbl_8804E57C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880509A0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B5BC20, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA4B8: call_seq lbl_88B5780C, lbl_8804C348, lbl_88CBCCB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5780C_889FA4B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCCB4, (ts4_word)(ts4_word)lbl_8804C348, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5780C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA528: call_seq lbl_88B57824, lbl_8804C358, lbl_88CBCCE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57824_889FA528(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCCE4, (ts4_word)(ts4_word)lbl_8804C358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57824, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA598: addr lbl_88B5BC68, u32@lbl_88B57854, u32@0x8 */
void ts4_addr_lbl_88B5BC68_889FA598(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B5BC68) + 8) = (ts4_word)(*(ts4_word *)lbl_88B57854);
    return;
}

/* Swing_DLL.xex 0x889FA5B0: call_seq lbl_88B5BC68, lbl_8804C380, lbl_88CBCD14, lbl_880509DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5BC68_889FA5B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCD14, (ts4_word)(ts4_word)lbl_8804C380, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880509DC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B5BC68, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA620: call_seq lbl_88B57858, lbl_88042408, lbl_88CBCD44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57858_889FA620(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCD44, (ts4_word)(ts4_word)lbl_88042408, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57858, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA690: call_seq lbl_88B57870, lbl_880423F8, lbl_88CBCD74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57870_889FA690(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCD74, (ts4_word)(ts4_word)lbl_880423F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57870, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA700: call_seq lbl_88B578B8, lbl_8804C390, lbl_88CBCDA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B578B8_889FA700(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCDA4, (ts4_word)(ts4_word)lbl_8804C390, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B578B8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA770: call_seq lbl_88B578E8, lbl_8804C3A0, lbl_88CBCDD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B578E8_889FA770(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCDD4, (ts4_word)(ts4_word)lbl_8804C3A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B578E8, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA7E0: call_seq lbl_88B57A08, lbl_8804C3B0, lbl_88CBCE04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57A08_889FA7E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCE04, (ts4_word)(ts4_word)lbl_8804C3B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57A08, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA850: call_seq lbl_88B57A98, lbl_8804C3C4, lbl_88CBCE34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57A98_889FA850(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCE34, (ts4_word)(ts4_word)lbl_8804C3C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57A98, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA8C0: call_seq lbl_88B57B58, lbl_8804C3DC, lbl_88CBCE64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57B58_889FA8C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCE64, (ts4_word)(ts4_word)lbl_8804C3DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57B58, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA930: call_seq lbl_88B57C30, lbl_8804C3F8, lbl_88CBCE94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57C30_889FA930(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCE94, (ts4_word)(ts4_word)lbl_8804C3F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57C30, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FA9A0: call_seq lbl_88B57CF0, lbl_8804C410, lbl_88CBCEC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57CF0_889FA9A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCEC4, (ts4_word)(ts4_word)lbl_8804C410, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57CF0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FAA10: call_seq lbl_88B57D98, lbl_880509F0, lbl_8803F5BC, lbl_88CBCEF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57D98_889FAA10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCEF4, (ts4_word)(ts4_word)lbl_8803F5BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57D98, (ts4_word)12, (ts4_word)(ts4_word)lbl_880509F0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FAA88: call_seq lbl_88B57EB8, lbl_8804C428, lbl_88CBCF24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57EB8_889FAA88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCF24, (ts4_word)(ts4_word)lbl_8804C428, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57EB8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FAAF8: call_seq lbl_88B57F18, lbl_8803F5E0, lbl_88CBCF54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B57F18_889FAAF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCF54, (ts4_word)(ts4_word)lbl_8803F5E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B57F18, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FAB68: call_seq lbl_88B58020, lbl_88040278, lbl_88CBCF84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58020_889FAB68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCF84, (ts4_word)(ts4_word)lbl_88040278, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58020, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FABD8: call_seq lbl_88B580F8, lbl_8803ED58, lbl_88CBCFB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B580F8_889FABD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCFB4, (ts4_word)(ts4_word)lbl_8803ED58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B580F8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FAC48: call_seq lbl_88B58128, lbl_8803ED40, lbl_88CBCFE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58128_889FAC48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBCFE4, (ts4_word)(ts4_word)lbl_8803ED40, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58128, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FACB8: call_seq lbl_88B58140, lbl_880433FC, lbl_88CBD014, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58140_889FACB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD014, (ts4_word)(ts4_word)lbl_880433FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58140, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FAD28: call_seq lbl_88B58188, lbl_8804342C, lbl_88CBD044, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58188_889FAD28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD044, (ts4_word)(ts4_word)lbl_8804342C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58188, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FAD98: call_seq lbl_88B581A0, lbl_88CBC6B4, lbl_8803ED7C, lbl_88CBD074, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B581A0_889FAD98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD074, (ts4_word)(ts4_word)lbl_8803ED7C, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B581A0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FAE10: call_seq lbl_88B581E8, lbl_88046454, lbl_88CBD0A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B581E8_889FAE10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD0A4, (ts4_word)(ts4_word)lbl_88046454, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B581E8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FAE80: call_seq lbl_88B58248, lbl_88CBD0A4, lbl_8804233C, lbl_88CBD0D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58248_889FAE80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD0D4, (ts4_word)(ts4_word)lbl_8804233C, (ts4_word)(ts4_word)lbl_88CBD0A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58248, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FAEF8: call_seq lbl_880469C4, lbl_88CBD104, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880469C4_889FAEF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD104, (ts4_word)(ts4_word)lbl_880469C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FAF58: call_seq lbl_88B58290, lbl_88CBE934, lbl_88042E48, lbl_88CBD134, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58290_889FAF58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD134, (ts4_word)(ts4_word)lbl_88042E48, (ts4_word)(ts4_word)lbl_88CBE934, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58290, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FAFD0: call_seq lbl_88046B60, lbl_88CBD164, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046B60_889FAFD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD164, (ts4_word)(ts4_word)lbl_88046B60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB030: call_seq lbl_88CBC6B4, lbl_88042318, lbl_88CBD194, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBC6B4_889FB030(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD194, (ts4_word)(ts4_word)lbl_88042318, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB098: call_seq lbl_88046A84, lbl_88CBD1C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A84_889FB098(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD1C4, (ts4_word)(ts4_word)lbl_88046A84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB0F8: call_seq lbl_88B582F0, lbl_88CBD194, lbl_8804232C, lbl_88CBD1F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B582F0_889FB0F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD1F4, (ts4_word)(ts4_word)lbl_8804232C, (ts4_word)(ts4_word)lbl_88CBD194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B582F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB170: call_seq lbl_88B58320, lbl_88CBD194, lbl_8804690C, lbl_88CBD224, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58320_889FB170(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD224, (ts4_word)(ts4_word)lbl_8804690C, (ts4_word)(ts4_word)lbl_88CBD194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58320, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB1E8: call_seq lbl_88CBD194, lbl_8804671C, lbl_88CBD254, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBD194_889FB1E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD254, (ts4_word)(ts4_word)lbl_8804671C, (ts4_word)(ts4_word)lbl_88CBD194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB250: call_seq lbl_88046A50, lbl_88CBD284, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A50_889FB250(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD284, (ts4_word)(ts4_word)lbl_88046A50, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB2B0: call_seq lbl_88B58338, lbl_88CBC6B4, lbl_88041284, lbl_88CBD2B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58338_889FB2B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD2B4, (ts4_word)(ts4_word)lbl_88041284, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58338, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB328: call_seq lbl_88B58350, lbl_88046220, lbl_88CBD2E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58350_889FB328(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD2E4, (ts4_word)(ts4_word)lbl_88046220, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58350, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB398: call_seq lbl_88B583B0, lbl_88CBD404, lbl_8804694C, lbl_88CBD314, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B583B0_889FB398(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD314, (ts4_word)(ts4_word)lbl_8804694C, (ts4_word)(ts4_word)lbl_88CBD404, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B583B0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB410: call_seq lbl_88B583C8, lbl_88CBD2B4, lbl_88040110, lbl_88CBD344, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B583C8_889FB410(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD344, (ts4_word)(ts4_word)lbl_88040110, (ts4_word)(ts4_word)lbl_88CBD2B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B583C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB488: call_seq lbl_88B583F8, lbl_88CBD2B4, lbl_88040100, lbl_88CBD374, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B583F8_889FB488(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD374, (ts4_word)(ts4_word)lbl_88040100, (ts4_word)(ts4_word)lbl_88CBD2B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B583F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB500: call_seq lbl_88B58410, lbl_88CBD404, lbl_8804011C, lbl_88CBD3A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58410_889FB500(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD3A4, (ts4_word)(ts4_word)lbl_8804011C, (ts4_word)(ts4_word)lbl_88CBD404, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58410, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB578: call_seq lbl_88B58440, lbl_88CBD2B4, lbl_880400A8, lbl_88CBD3D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58440_889FB578(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD3D4, (ts4_word)(ts4_word)lbl_880400A8, (ts4_word)(ts4_word)lbl_88CBD2B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58440, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB5F0: call_seq lbl_88B58458, lbl_88CBD8B4, lbl_88042370, lbl_88CBD404, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58458_889FB5F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD404, (ts4_word)(ts4_word)lbl_88042370, (ts4_word)(ts4_word)lbl_88CBD8B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58458, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB668: call_seq lbl_88B58470, lbl_88CBD614, lbl_88041B24, lbl_88CBD434, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58470_889FB668(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD434, (ts4_word)(ts4_word)lbl_88041B24, (ts4_word)(ts4_word)lbl_88CBD614, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58470, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB6E0: call_seq lbl_88B58488, lbl_88CBD3D4, lbl_880468C8, lbl_88CBD464, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58488_889FB6E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD464, (ts4_word)(ts4_word)lbl_880468C8, (ts4_word)(ts4_word)lbl_88CBD3D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58488, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB758: call_seq lbl_88B584D0, lbl_88CBD404, lbl_880400E8, lbl_88CBD494, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B584D0_889FB758(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD494, (ts4_word)(ts4_word)lbl_880400E8, (ts4_word)(ts4_word)lbl_88CBD404, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B584D0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB7D0: call_seq lbl_88B58500, lbl_88CBD404, lbl_880400D0, lbl_88CBD4C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58500_889FB7D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD4C4, (ts4_word)(ts4_word)lbl_880400D0, (ts4_word)(ts4_word)lbl_88CBD404, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58500, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB848: call_seq lbl_88B58530, lbl_880463D4, lbl_88CBD4F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58530_889FB848(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD4F4, (ts4_word)(ts4_word)lbl_880463D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58530, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB8B8: call_seq lbl_88B58578, lbl_88CBD404, lbl_88046868, lbl_88CBD524, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58578_889FB8B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD524, (ts4_word)(ts4_word)lbl_88046868, (ts4_word)(ts4_word)lbl_88CBD404, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58578, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB930: call_seq lbl_88B585F8, lbl_88CBD404, lbl_8803EFC0, lbl_88CBD554, lbl_88050A78, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B585F8_889FB930(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD554, (ts4_word)(ts4_word)lbl_8803EFC0, (ts4_word)(ts4_word)lbl_88CBD404, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88050A78, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B585F8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FB9A8: call_seq lbl_88CBD6A4, lbl_880467DC, lbl_88CBD584, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBD6A4_889FB9A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD584, (ts4_word)(ts4_word)lbl_880467DC, (ts4_word)(ts4_word)lbl_88CBD6A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FBA10: call_seq lbl_88CBD2B4, lbl_88046AE0, lbl_88CBD5B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBD2B4_889FBA10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD5B4, (ts4_word)(ts4_word)lbl_88046AE0, (ts4_word)(ts4_word)lbl_88CBD2B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FBA78: call_seq lbl_88B58670, lbl_88042358, lbl_88CBD5E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58670_889FBA78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD5E4, (ts4_word)(ts4_word)lbl_88042358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58670, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FBAE8: call_seq lbl_88B586A0, lbl_88CBD3D4, lbl_8804234C, lbl_88CBD614, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B586A0_889FBAE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD614, (ts4_word)(ts4_word)lbl_8804234C, (ts4_word)(ts4_word)lbl_88CBD3D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B586A0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FBB60: call_seq lbl_88B586B8, lbl_88046320, lbl_88CBD644, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B586B8_889FBB60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD644, (ts4_word)(ts4_word)lbl_88046320, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B586B8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FBBD0: addr lbl_88B5BCE0, u32@lbl_88B585F4, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88B5BCE0_889FBBD0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B585F4;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B5BCE0) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B5BCE0) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x889FBBF0: call_seq lbl_88B5BCE0, lbl_8803EFE8, lbl_88CBD674, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5BCE0_889FBBF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD674, (ts4_word)(ts4_word)lbl_8803EFE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5BCE0, (ts4_word)13, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FBC60: call_seq lbl_88B586D8, lbl_88CBD3D4, lbl_8803EF9C, lbl_88CBD6A4, lbl_88050ACC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B586D8_889FBC60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD6A4, (ts4_word)(ts4_word)lbl_8803EF9C, (ts4_word)(ts4_word)lbl_88CBD3D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88050ACC, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B586D8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FBCD8: call_seq lbl_88B58738, lbl_88CBD374, lbl_880423C0, lbl_88CBD6D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58738_889FBCD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD6D4, (ts4_word)(ts4_word)lbl_880423C0, (ts4_word)(ts4_word)lbl_88CBD374, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58738, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FBD50: call_seq lbl_88B58750, lbl_880462E8, lbl_88CBD704, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58750_889FBD50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD704, (ts4_word)(ts4_word)lbl_880462E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58750, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FBDC0: call_seq lbl_88B58780, lbl_88CBD2B4, lbl_8804675C, lbl_88CBD734, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58780_889FBDC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD734, (ts4_word)(ts4_word)lbl_8804675C, (ts4_word)(ts4_word)lbl_88CBD2B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58780, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FBE38: call_seq lbl_88B587B0, lbl_88CBD8B4, lbl_8803F9D4, lbl_88CBD764, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B587B0_889FBE38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD764, (ts4_word)(ts4_word)lbl_8803F9D4, (ts4_word)(ts4_word)lbl_88CBD8B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B587B0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FBEB0: call_seq lbl_88CBD2B4, lbl_88046AB4, lbl_88CBD794, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBD2B4_889FBEB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD794, (ts4_word)(ts4_word)lbl_88046AB4, (ts4_word)(ts4_word)lbl_88CBD2B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FBF18: call_seq lbl_88B587E0, lbl_88CBD5B4, lbl_880466D4, lbl_88CBD7C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B587E0_889FBF18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD7C4, (ts4_word)(ts4_word)lbl_880466D4, (ts4_word)(ts4_word)lbl_88CBD5B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B587E0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FBF90: call_seq lbl_88B58828, lbl_88CBD5B4, lbl_88046A18, lbl_88CBD7F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58828_889FBF90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD7F4, (ts4_word)(ts4_word)lbl_88046A18, (ts4_word)(ts4_word)lbl_88CBD5B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58828, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC008: call_seq lbl_88B588D0, lbl_880423A4, lbl_88CBD824, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B588D0_889FC008(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD824, (ts4_word)(ts4_word)lbl_880423A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B588D0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC078: call_seq lbl_88B58918, lbl_88CBD3D4, lbl_88042390, lbl_88CBD854, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58918_889FC078(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD854, (ts4_word)(ts4_word)lbl_88042390, (ts4_word)(ts4_word)lbl_88CBD3D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58918, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC0F0: call_seq lbl_88CBD404, lbl_88043ED0, lbl_88CBD884, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBD404_889FC0F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD884, (ts4_word)(ts4_word)lbl_88043ED0, (ts4_word)(ts4_word)lbl_88CBD404, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC158: call_seq lbl_88CBD2B4, lbl_8804696C, lbl_88CBD8B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBD2B4_889FC158(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD8B4, (ts4_word)(ts4_word)lbl_8804696C, (ts4_word)(ts4_word)lbl_88CBD2B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC1C0: call_seq lbl_88B58978, lbl_8803F00C, lbl_88CBD8E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58978_889FC1C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD8E4, (ts4_word)(ts4_word)lbl_8803F00C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58978, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC230: call_seq lbl_88B58A08, lbl_88CBD6A4, lbl_88046574, lbl_88CBD914, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58A08_889FC230(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD914, (ts4_word)(ts4_word)lbl_88046574, (ts4_word)(ts4_word)lbl_88CBD6A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58A08, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC2A8: call_seq lbl_88B58A20, lbl_88CBD7F4, lbl_88046518, lbl_88CBD944, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58A20_889FC2A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD944, (ts4_word)(ts4_word)lbl_88046518, (ts4_word)(ts4_word)lbl_88CBD7F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58A20, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC320: call_seq lbl_88B58A50, lbl_88CBD2B4, lbl_880400BC, lbl_88CBD974, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58A50_889FC320(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD974, (ts4_word)(ts4_word)lbl_880400BC, (ts4_word)(ts4_word)lbl_88CBD2B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58A50, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC398: call_seq lbl_88B58A98, lbl_88CBD404, lbl_88042380, lbl_88CBD9A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58A98_889FC398(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD9A4, (ts4_word)(ts4_word)lbl_88042380, (ts4_word)(ts4_word)lbl_88CBD404, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58A98, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC410: call_seq lbl_88B58AE0, lbl_8803FBF4, lbl_88CBD9D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58AE0_889FC410(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBD9D4, (ts4_word)(ts4_word)lbl_8803FBF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58AE0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC480: call_seq lbl_88B58B40, lbl_88CBD374, lbl_880423D4, lbl_88CBDA04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58B40_889FC480(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDA04, (ts4_word)(ts4_word)lbl_880423D4, (ts4_word)(ts4_word)lbl_88CBD374, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58B40, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC4F8: call_seq lbl_88B58B58, lbl_88CBD3D4, lbl_88046498, lbl_88CBDA34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58B58_889FC4F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDA34, (ts4_word)(ts4_word)lbl_88046498, (ts4_word)(ts4_word)lbl_88CBD3D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58B58, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC570: call_seq lbl_88B58B88, lbl_88CBC6B4, lbl_88047050, lbl_88CBDA64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58B88_889FC570(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDA64, (ts4_word)(ts4_word)lbl_88047050, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58B88, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC5E8: call_seq lbl_88B58BE8, lbl_88CBDA64, lbl_88045B44, lbl_88CBDA94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58BE8_889FC5E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDA94, (ts4_word)(ts4_word)lbl_88045B44, (ts4_word)(ts4_word)lbl_88CBDA64, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58BE8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC660: call_seq lbl_88B58C00, lbl_88CBDA64, lbl_88045B24, lbl_88CBDAC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58C00_889FC660(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDAC4, (ts4_word)(ts4_word)lbl_88045B24, (ts4_word)(ts4_word)lbl_88CBDA64, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58C00, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC6D8: call_seq lbl_88B58C30, lbl_88CBDA64, lbl_880459C0, lbl_88CBDAF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58C30_889FC6D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDAF4, (ts4_word)(ts4_word)lbl_880459C0, (ts4_word)(ts4_word)lbl_88CBDA64, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58C30, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC750: addr lbl_88B5BE18, u32@lbl_88B586D4, u32@0x8 */
void ts4_addr_lbl_88B5BE18_889FC750(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B5BE18) + 8) = (ts4_word)(*(ts4_word *)lbl_88B586D4);
    return;
}

/* Swing_DLL.xex 0x889FC768: call_seq lbl_88B5BE18, lbl_88045224, lbl_88CBDB24, lbl_88050B1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5BE18_889FC768(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDB24, (ts4_word)(ts4_word)lbl_88045224, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88050B1C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B5BE18, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC7D8: call_seq lbl_88B58C48, lbl_88045194, lbl_88CBDB54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58C48_889FC7D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDB54, (ts4_word)(ts4_word)lbl_88045194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58C48, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC848: call_seq lbl_88B58C60, lbl_8803EF90, lbl_88CBDB84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58C60_889FC848(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDB84, (ts4_word)(ts4_word)lbl_8803EF90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58C60, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC8B8: call_seq lbl_88B58CAC, lbl_88CBC6B4, lbl_8803FA04, lbl_88CBDBB4, lbl_88050BE8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58CAC_889FC8B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDBB4, (ts4_word)(ts4_word)lbl_8803FA04, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88050BE8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B58CAC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC928: call_seq lbl_88B58CC8, lbl_88042170, lbl_88CBDBE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58CC8_889FC928(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDBE4, (ts4_word)(ts4_word)lbl_88042170, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58CC8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FC998: addr lbl_88B5BE60, u32@lbl_88B58CC4, u32@0x50 */
void ts4_addr_lbl_88B5BE60_889FC998(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B5BE60) + 80) = (ts4_word)(*(ts4_word *)lbl_88B58CC4);
    return;
}

/* Swing_DLL.xex 0x889FC9B0: call_seq lbl_88B5BE60, lbl_88CBC6B4, lbl_8803F0C8, lbl_88CBDC14, lbl_88050C44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5BE60_889FC9B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDC14, (ts4_word)(ts4_word)lbl_8803F0C8, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88050C44, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B5BE60, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FCA28: call_seq lbl_88B58D30, lbl_88CBDBB4, lbl_8804044C, lbl_88CBDC44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58D30_889FCA28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDC44, (ts4_word)(ts4_word)lbl_8804044C, (ts4_word)(ts4_word)lbl_88CBDBB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58D30, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FCAA0: call_seq lbl_88B58D48, lbl_88CBDBB4, lbl_880403DC, lbl_88CBDC74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58D48_889FCAA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDC74, (ts4_word)(ts4_word)lbl_880403DC, (ts4_word)(ts4_word)lbl_88CBDBB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58D48, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FCB18: call_seq lbl_88B58D78, lbl_88040630, lbl_88CBDCA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58D78_889FCB18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDCA4, (ts4_word)(ts4_word)lbl_88040630, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58D78, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FCB88: call_seq lbl_88B58DC0, lbl_88040608, lbl_88CBDCD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58DC0_889FCB88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDCD4, (ts4_word)(ts4_word)lbl_88040608, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58DC0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FCBF8: call_seq lbl_88B58DF0, lbl_88CBDBB4, lbl_88040394, lbl_88CBDD04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58DF0_889FCBF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDD04, (ts4_word)(ts4_word)lbl_88040394, (ts4_word)(ts4_word)lbl_88CBDBB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58DF0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FCC70: call_seq lbl_88B58E20, lbl_88040590, lbl_88CBDD34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58E20_889FCC70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDD34, (ts4_word)(ts4_word)lbl_88040590, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58E20, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FCCE0: call_seq lbl_88B58E80, lbl_88040560, lbl_88CBDD64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58E80_889FCCE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDD64, (ts4_word)(ts4_word)lbl_88040560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58E80, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FCD50: call_seq lbl_88050C80, lbl_88B58EC8, lbl_88CBDBB4, lbl_8803F690, lbl_88CBDD94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88050C80_889FCD50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDD94, (ts4_word)(ts4_word)lbl_8803F690, (ts4_word)(ts4_word)lbl_88CBDBB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58EC8, (ts4_word)6, (ts4_word)(ts4_word)lbl_88050C80, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FCDC8: call_seq lbl_88B58F58, lbl_88CBDDF4, lbl_88045734, lbl_88CBDDC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58F58_889FCDC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDDC4, (ts4_word)(ts4_word)lbl_88045734, (ts4_word)(ts4_word)lbl_88CBDDF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58F58, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FCE40: call_seq lbl_88CBC6B4, lbl_88045A30, lbl_88CBDDF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBC6B4_889FCE40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDDF4, (ts4_word)(ts4_word)lbl_88045A30, (ts4_word)(ts4_word)lbl_88CBC6B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FCEA8: addr lbl_88B5BF20, u32@lbl_88B58FD0, u32@0x38 */
void ts4_addr_lbl_88B5BF20_889FCEA8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B5BF20) + 56) = (ts4_word)(*(ts4_word *)lbl_88B58FD0);
    return;
}

/* Swing_DLL.xex 0x889FCEC0: call_seq lbl_88B5BF20, lbl_88CBDBB4, lbl_88040364, lbl_88CBDE24, lbl_88050CC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5BF20_889FCEC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDE24, (ts4_word)(ts4_word)lbl_88040364, (ts4_word)(ts4_word)lbl_88CBDBB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88050CC4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B5BF20, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FCF38: call_seq lbl_88B58FD8, lbl_88CBDBB4, lbl_88040344, lbl_88CBDE54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B58FD8_889FCF38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDE54, (ts4_word)(ts4_word)lbl_88040344, (ts4_word)(ts4_word)lbl_88CBDBB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B58FD8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FCFB0: call_seq lbl_88B59020, lbl_88CBDD94, lbl_8803F064, lbl_88CBDE84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59020_889FCFB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDE84, (ts4_word)(ts4_word)lbl_8803F064, (ts4_word)(ts4_word)lbl_88CBDD94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59020, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD028: call_seq lbl_88B59080, lbl_88040534, lbl_88CBDEB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B59080_889FD028(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDEB4, (ts4_word)(ts4_word)lbl_88040534, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B59080, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889FD098: call_seq lbl_88B590C8, lbl_88040508, lbl_88CBDEE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B590C8_889FD098(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBDEE4, (ts4_word)(ts4_word)lbl_88040508, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B590C8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}
