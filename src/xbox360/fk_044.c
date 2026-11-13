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

extern char ts4_addr_lbl_8803A308_88AFF5C0[];
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
extern char lbl_8803F030[];
extern char lbl_8803F094[];
extern char lbl_8803F0AC[];
extern char lbl_8803F5BC[];
extern char lbl_8803F5C8[];
extern char lbl_8803F5E0[];
extern char lbl_8803F5F4[];
extern char lbl_8803F610[];
extern char lbl_8803F634[];
extern char lbl_8803F64C[];
extern char lbl_8803F960[];
extern char lbl_8803F974[];
extern char lbl_8803F988[];
extern char lbl_8803F99C[];
extern char lbl_8803F9B0[];
extern char lbl_8803F9C0[];
extern char lbl_8804002C[];
extern char lbl_88040040[];
extern char lbl_88040078[];
extern char lbl_880401D8[];
extern char lbl_880401F0[];
extern char lbl_88040200[];
extern char lbl_88040218[];
extern char lbl_88040228[];
extern char lbl_88040278[];
extern char lbl_88040318[];
extern char lbl_88040658[];
extern char lbl_88040668[];
extern char lbl_88041114[];
extern char lbl_8804115C[];
extern char lbl_8804116C[];
extern char lbl_88041174[];
extern char lbl_88041194[];
extern char lbl_880411C8[];
extern char lbl_880411DC[];
extern char lbl_880411F0[];
extern char lbl_88041204[];
extern char lbl_88041238[];
extern char lbl_8804124C[];
extern char lbl_88041268[];
extern char lbl_88041578[];
extern char lbl_88041584[];
extern char lbl_880415D4[];
extern char lbl_880415F8[];
extern char lbl_88041618[];
extern char lbl_88041634[];
extern char lbl_88041930[];
extern char lbl_88042074[];
extern char lbl_88042098[];
extern char lbl_880420B8[];
extern char lbl_880420C8[];
extern char lbl_880420E4[];
extern char lbl_880420FC[];
extern char lbl_88042110[];
extern char lbl_88042128[];
extern char lbl_88042140[];
extern char lbl_880421C4[];
extern char lbl_8804233C[];
extern char lbl_880423F8[];
extern char lbl_88042408[];
extern char lbl_88042E48[];
extern char lbl_880433FC[];
extern char lbl_8804342C[];
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
extern char lbl_88046454[];
extern char lbl_880469C4[];
extern char lbl_88046B60[];
extern char lbl_88046C00[];
extern char lbl_88046C24[];
extern char lbl_88046C48[];
extern char lbl_88046C60[];
extern char lbl_88046C78[];
extern char lbl_88046C94[];
extern char lbl_8804705C[];
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
extern char lbl_88053DD8[];
extern char lbl_88053DE8[];
extern char lbl_88053E90[];
extern char lbl_88053EAC[];
extern char lbl_88053F68[];
extern char lbl_88054050[];
extern char lbl_88054068[];
extern char lbl_88055A18[];
extern char lbl_88056A34[];
extern char lbl_88056A8C[];
extern char lbl_88056AA0[];
extern char lbl_88056AF8[];
extern char lbl_8805704C[];
extern char lbl_880572A4[];
extern char lbl_880572E0[];
extern char lbl_88057314[];
extern char lbl_88057328[];
extern char lbl_8805736C[];
extern char lbl_88057380[];
extern char lbl_880573AC[];
extern char lbl_88057450[];
extern char lbl_8805749C[];
extern char lbl_8805753C[];
extern char lbl_880575A8[];
extern char lbl_880575CC[];
extern char lbl_88057614[];
extern char lbl_88057628[];
extern char lbl_8805767C[];
extern char lbl_88057734[];
extern char lbl_88057748[];
extern char lbl_88057764[];
extern char lbl_880578D8[];
extern char lbl_8805792C[];
extern char lbl_88057968[];
extern char lbl_880579A0[];
extern char lbl_880579E4[];
extern char lbl_88057A10[];
extern char lbl_88057A54[];
extern char lbl_88057A90[];
extern char lbl_88057ACC[];
extern char lbl_88057AE0[];
extern char lbl_88058A10[];
extern char lbl_88058A20[];
extern char lbl_88B742F0[];
extern char lbl_88B74308[];
extern char lbl_88B74368[];
extern char lbl_88B74380[];
extern char lbl_88B743C8[];
extern char lbl_88B74428[];
extern char lbl_88B74488[];
extern char lbl_88B744E8[];
extern char lbl_88B745A8[];
extern char lbl_88B74770[];
extern char lbl_88B74788[];
extern char lbl_88B747A0[];
extern char lbl_88B747D0[];
extern char lbl_88B74800[];
extern char lbl_88B74818[];
extern char lbl_88B74848[];
extern char lbl_88B74890[];
extern char lbl_88B748D8[];
extern char lbl_88B74968[];
extern char lbl_88B749B0[];
extern char lbl_88B749E0[];
extern char lbl_88B74A10[];
extern char lbl_88B74A40[];
extern char lbl_88B74A58[];
extern char lbl_88B74A70[];
extern char lbl_88B74AA0[];
extern char lbl_88B74AB8[];
extern char lbl_88B74BA8[];
extern char lbl_88B74D58[];
extern char lbl_88B74EF0[];
extern char lbl_88B75148[];
extern char lbl_88B751C0[];
extern char lbl_88B75208[];
extern char lbl_88B75238[];
extern char lbl_88B75298[];
extern char lbl_88B752F8[];
extern char lbl_88B753E8[];
extern char lbl_88B754D8[];
extern char lbl_88B75520[];
extern char lbl_88B755F8[];
extern char lbl_88B75610[];
extern char lbl_88B75658[];
extern char lbl_88B756A0[];
extern char lbl_88B756B8[];
extern char lbl_88B75700[];
extern char lbl_88B75718[];
extern char lbl_88B757C0[];
extern char lbl_88B757F0[];
extern char lbl_88B75838[];
extern char lbl_88B75880[];
extern char lbl_88B758C8[];
extern char lbl_88B758E0[];
extern char lbl_88B758F8[];
extern char lbl_88B76780[];
extern char lbl_88B767F8[];
extern char lbl_88B767FC[];
extern char lbl_88B7682C[];
extern char lbl_88B76860[];
extern char lbl_88B768C0[];
extern char lbl_88B76938[];
extern char lbl_88B769E0[];
extern char lbl_88B769F8[];
extern char lbl_88B76A70[];
extern char lbl_88B76B18[];
extern char lbl_88B76B30[];
extern char lbl_88B76B90[];
extern char lbl_88B76BA8[];
extern char lbl_88B76BF0[];
extern char lbl_88B76C80[];
extern char lbl_88B76D10[];
extern char lbl_88B76D70[];
extern char lbl_88B76DA0[];
extern char lbl_88B76E00[];
extern char lbl_88B76E60[];
extern char lbl_88B76EE0[];
extern char lbl_88B76FE8[];
extern char lbl_88B770F0[];
extern char lbl_88B77120[];
extern char lbl_88B771C8[];
extern char lbl_88B77210[];
extern char lbl_88B772B8[];
extern char lbl_88B77300[];
extern char lbl_88B77304[];
extern char lbl_88B77334[];
extern char lbl_88B7734C[];
extern char lbl_88B7737C[];
extern char lbl_88B77380[];
extern char lbl_88B773E0[];
extern char lbl_88B77410[];
extern char lbl_88B77590[];
extern char lbl_88B775A8[];
extern char lbl_88B77608[];
extern char lbl_88B776E0[];
extern char lbl_88B777E8[];
extern char lbl_88B77818[];
extern char lbl_88B77848[];
extern char lbl_88B778D8[];
extern char lbl_88B778DC[];
extern char lbl_88B77910[];
extern char lbl_88B779A0[];
extern char lbl_88B77AF0[];
extern char lbl_88B77BB0[];
extern char lbl_88B77BC8[];
extern char lbl_88B77C58[];
extern char lbl_88B77C70[];
extern char lbl_88B77C88[];
extern char lbl_88B77CA0[];
extern char lbl_88B77D00[];
extern char lbl_88B77D48[];
extern char lbl_88B77E68[];
extern char lbl_88B77EB8[];
extern char lbl_88B77EC0[];
extern char lbl_88B77F20[];
extern char lbl_88B77F50[];
extern char lbl_88B77F68[];
extern char lbl_88B77F9C[];
extern char lbl_88B77FA0[];
extern char lbl_88B78048[];
extern char lbl_88B78078[];
extern char lbl_88B780B0[];
extern char lbl_88B780E0[];
extern char lbl_88B780F8[];
extern char lbl_88B78108[];
extern char lbl_88B78150[];
extern char lbl_88B78180[];
extern char lbl_88B781B0[];
extern char lbl_88B78210[];
extern char lbl_88B78300[];
extern char lbl_88B78318[];
extern char lbl_88B78390[];
extern char lbl_88B783A8[];
extern char lbl_88B783AC[];
extern char lbl_88B783DC[];
extern char lbl_88B7840C[];
extern char lbl_88B7843C[];
extern char lbl_88B78454[];
extern char lbl_88B78484[];
extern char lbl_88B7849C[];
extern char lbl_88B784CC[];
extern char lbl_88B784D0[];
extern char lbl_88B78578[];
extern char lbl_88B785A8[];
extern char lbl_88B785C0[];
extern char lbl_88B785F0[];
extern char lbl_88B786B4[];
extern char lbl_88B786E4[];
extern char lbl_88B786E8[];
extern char lbl_88B787A8[];
extern char lbl_88B787C0[];
extern char lbl_88B787F0[];
extern char lbl_88B787F4[];
extern char lbl_88B78810[];
extern char lbl_88B78858[];
extern char lbl_88B78888[];
extern char lbl_88B789A8[];
extern char lbl_88B78A38[];
extern char lbl_88B78AF8[];
extern char lbl_88B78BD0[];
extern char lbl_88B78C90[];
extern char lbl_88B78D38[];
extern char lbl_88B78E58[];
extern char lbl_88B78EB8[];
extern char lbl_88B78FC0[];
extern char lbl_88B79098[];
extern char lbl_88B790E0[];
extern char lbl_88B790F8[];
extern char lbl_88B79140[];
extern char lbl_88B79158[];
extern char lbl_88B791A0[];
extern char lbl_88B79200[];
extern char lbl_88B79248[];
extern char lbl_88B7CA80[];
extern char lbl_88B7CAC8[];
extern char lbl_88B7CC18[];
extern char lbl_88B7CDB0[];
extern char lbl_88B7CEB8[];
extern char lbl_88B7CF78[];
extern char lbl_88B7D038[];
extern char lbl_88B7D0C8[];
extern char lbl_88B7D0F8[];
extern char lbl_88B7D128[];
extern char lbl_88B7D158[];
extern char lbl_88B7D1D0[];
extern char lbl_88B7D218[];
extern char lbl_88CCB114[];
extern char lbl_88CCBC84[];
extern char lbl_88CCCB24[];
extern char lbl_88CCCB54[];
extern char lbl_88CCCC14[];
extern char lbl_88CCD9C4[];
extern char lbl_88CCD9F4[];
extern char lbl_88CCDA24[];
extern char lbl_88CCDA54[];
extern char lbl_88CCDA84[];
extern char lbl_88CCDAB4[];
extern char lbl_88CCDAE4[];
extern char lbl_88CCDB14[];
extern char lbl_88CCDB44[];
extern char lbl_88CCDB74[];
extern char lbl_88CCDBA4[];
extern char lbl_88CCDBD4[];
extern char lbl_88CCDC04[];
extern char lbl_88CCDC34[];
extern char lbl_88CCDC64[];
extern char lbl_88CCDC94[];
extern char lbl_88CCDCC4[];
extern char lbl_88CCDCF4[];
extern char lbl_88CCDD24[];
extern char lbl_88CCDD54[];
extern char lbl_88CCDD84[];
extern char lbl_88CCDDB4[];
extern char lbl_88CCDDE4[];
extern char lbl_88CCDE14[];
extern char lbl_88CCDE44[];
extern char lbl_88CCDE74[];
extern char lbl_88CCDEA4[];
extern char lbl_88CCDED4[];
extern char lbl_88CCDF04[];
extern char lbl_88CCDF34[];
extern char lbl_88CCDF64[];
extern char lbl_88CCDF94[];
extern char lbl_88CCDFC4[];
extern char lbl_88CCDFF4[];
extern char lbl_88CCE024[];
extern char lbl_88CCE054[];
extern char lbl_88CCE084[];
extern char lbl_88CCE0B4[];
extern char lbl_88CCE0E4[];
extern char lbl_88CCE114[];
extern char lbl_88CCE144[];
extern char lbl_88CCE174[];
extern char lbl_88CCE1A4[];
extern char lbl_88CCE1D4[];
extern char lbl_88CCE204[];
extern char lbl_88CCE234[];
extern char lbl_88CCE264[];
extern char lbl_88CCE294[];
extern char lbl_88CCE2C4[];
extern char lbl_88CCE2F4[];
extern char lbl_88CCE324[];
extern char lbl_88CCE354[];
extern char lbl_88CCE384[];
extern char lbl_88CCE3B4[];
extern char lbl_88CCE3E4[];
extern char lbl_88CCE414[];
extern char lbl_88CCE444[];
extern char lbl_88CCE474[];
extern char lbl_88CCE4A4[];
extern char lbl_88CCE4D4[];
extern char lbl_88CCE504[];
extern char lbl_88CCE534[];
extern char lbl_88CCE54C[];
extern char lbl_88CCE57C[];
extern char lbl_88CCE5AC[];
extern char lbl_88CCE5DC[];
extern char lbl_88CCE60C[];
extern char lbl_88CCE63C[];
extern char lbl_88CCE66C[];
extern char lbl_88CCE69C[];
extern char lbl_88CCE6CC[];
extern char lbl_88CCE6FC[];
extern char lbl_88CCE72C[];
extern char lbl_88CCE75C[];
extern char lbl_88CCE78C[];
extern char lbl_88CCE7BC[];
extern char lbl_88CCE7EC[];
extern char lbl_88CCE81C[];
extern char lbl_88CCE84C[];
extern char lbl_88CCE87C[];
extern char lbl_88CCE8AC[];
extern char lbl_88CCE8DC[];
extern char lbl_88CCE90C[];
extern char lbl_88CCE93C[];
extern char lbl_88CCE96C[];
extern char lbl_88CCE99C[];
extern char lbl_88CCE9CC[];
extern char lbl_88CCE9FC[];
extern char lbl_88CCEA2C[];
extern char lbl_88CCEA5C[];
extern char lbl_88CCEA8C[];
extern char lbl_88CCEABC[];
extern char lbl_88CCEAEC[];
extern char lbl_88CCEB4C[];
extern char lbl_88CCEB7C[];
extern char lbl_88CCEBAC[];
extern char lbl_88CCEBDC[];
extern char lbl_88CCEC0C[];
extern char lbl_88CCEC3C[];
extern char lbl_88CCEC6C[];
extern char lbl_88CCEC9C[];
extern char lbl_88CCECCC[];
extern char lbl_88CCECFC[];
extern char lbl_88CCED2C[];
extern char lbl_88CCED5C[];
extern char lbl_88CCEDBC[];
extern char lbl_88CCEDEC[];
extern char lbl_88CCEE4C[];
extern char lbl_88CCEE7C[];
extern char lbl_88CCEEAC[];
extern char lbl_88CCEEDC[];
extern char lbl_88CCEF0C[];
extern char lbl_88CCEF3C[];
extern char lbl_88CCEF6C[];
extern char lbl_88CCEF9C[];
extern char lbl_88CCEFCC[];
extern char lbl_88CCEFFC[];
extern char lbl_88CCF02C[];
extern char lbl_88CCF05C[];
extern char lbl_88CCF08C[];
extern char lbl_88CCF0BC[];
extern char lbl_88CCF0EC[];
extern char lbl_88CCF14C[];
extern char lbl_88CCF17C[];
extern char lbl_88CCF1AC[];
extern char lbl_88CCF1DC[];
extern char lbl_88CCF20C[];
extern char lbl_88CCF23C[];
extern char lbl_88CCF26C[];
extern char lbl_88CCF29C[];
extern char lbl_88CCF2CC[];
extern char lbl_88CCF2FC[];
extern char lbl_88CCF32C[];
extern char lbl_88CCF35C[];
extern char lbl_88CCF38C[];
extern char lbl_88CCF3BC[];
extern char lbl_88CCF3EC[];
extern char lbl_88CCF41C[];
extern char lbl_88CCF44C[];
extern char lbl_88CCF47C[];
extern char lbl_88CCF4AC[];
extern char lbl_88CCF4DC[];
extern char lbl_88CCF50C[];
extern char lbl_88CCF53C[];
extern char lbl_88CCF56C[];
extern char lbl_88CCF59C[];
extern char lbl_88CCF5CC[];
extern char lbl_88CCF5FC[];
extern char lbl_88CCF62C[];
extern char lbl_88CCF65C[];
extern char lbl_88CCF68C[];
extern char lbl_88CCF6BC[];
extern char lbl_88CCF6EC[];
extern char lbl_88CCF71C[];
extern char lbl_88CCF74C[];
extern char lbl_88CCF77C[];
extern char lbl_88CCF7AC[];
extern char lbl_88CCF7DC[];
extern char lbl_88CCF80C[];
extern char lbl_88CCF83C[];
extern char lbl_88CCF86C[];
extern char lbl_88CCF89C[];
extern char lbl_88CCF8CC[];
extern char lbl_88CCF8FC[];
extern char lbl_88CCF92C[];
extern char lbl_88CCF95C[];
extern char lbl_88CCF98C[];
extern char lbl_88CCF9BC[];
extern char lbl_88CCF9EC[];
extern char lbl_88CCFA1C[];
extern char lbl_88CCFA4C[];
extern char lbl_88CCFA7C[];
extern char lbl_88CCFAAC[];
extern char lbl_88CCFADC[];
extern char lbl_88CCFB0C[];
extern char lbl_88CCFB3C[];
extern char lbl_88CCFB6C[];
extern char lbl_88CCFB9C[];
extern char lbl_88CCFBCC[];
extern char lbl_88CCFBFC[];
extern char lbl_88CCFC2C[];
extern char lbl_88CCFC5C[];
extern char lbl_88CCFC8C[];
extern char lbl_88CCFCBC[];
extern char lbl_88CCFCEC[];
extern char lbl_88CCFD1C[];
extern char lbl_88CCFD4C[];
extern char lbl_88CD19CC[];
ts4_word fn_8841F080();
ts4_word ts4_set_u32_offc_884CE988();
ts4_word fn_88563470();

/* Swing_DLL.xex 0x88A23070: call_seq lbl_88B742F0, lbl_88CCCC14, lbl_8803F030, lbl_88CCD9C4, lbl_88056A34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B742F0_88A23070(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD9C4, (ts4_word)(ts4_word)lbl_8803F030, (ts4_word)(ts4_word)lbl_88CCCC14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88056A34, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B742F0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A230E0: call_seq lbl_88B74308, lbl_880421C4, lbl_88CCD9F4, lbl_88056A8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74308_88A230E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD9F4, (ts4_word)(ts4_word)lbl_880421C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88056A8C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B74308, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23150: call_seq lbl_88B74368, lbl_88CCCC14, lbl_88040318, lbl_88CCDA24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74368_88A23150(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDA24, (ts4_word)(ts4_word)lbl_88040318, (ts4_word)(ts4_word)lbl_88CCCC14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74368, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A231C8: call_seq lbl_88B74380, lbl_88CCCB24, lbl_88044EA8, lbl_88CCDA54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74380_88A231C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDA54, (ts4_word)(ts4_word)lbl_88044EA8, (ts4_word)(ts4_word)lbl_88CCCB24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74380, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23240: call_seq lbl_88B743C8, lbl_88CCCB24, lbl_88044E64, lbl_88CCDA84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B743C8_88A23240(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDA84, (ts4_word)(ts4_word)lbl_88044E64, (ts4_word)(ts4_word)lbl_88CCCB24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B743C8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A232B8: call_seq lbl_88B74428, lbl_88CCCB54, lbl_88044DD0, lbl_88CCDAB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74428_88A232B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDAB4, (ts4_word)(ts4_word)lbl_88044DD0, (ts4_word)(ts4_word)lbl_88CCCB54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74428, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23330: call_seq lbl_88B74488, lbl_88CCCB54, lbl_88044CD0, lbl_88CCDAE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74488_88A23330(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDAE4, (ts4_word)(ts4_word)lbl_88044CD0, (ts4_word)(ts4_word)lbl_88CCCB54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74488, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A233A8: call_seq lbl_88B744E8, lbl_88CCCB24, lbl_88044BD4, lbl_88CCDB14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B744E8_88A233A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDB14, (ts4_word)(ts4_word)lbl_88044BD4, (ts4_word)(ts4_word)lbl_88CCCB24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B744E8, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23420: call_seq lbl_88B745A8, lbl_88056AA0, lbl_8803F094, lbl_88CCDB44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B745A8_88A23420(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDB44, (ts4_word)(ts4_word)lbl_8803F094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B745A8, (ts4_word)19, (ts4_word)(ts4_word)lbl_88056AA0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23498: call_seq lbl_88B74770, lbl_88CCBC84, lbl_8803F0AC, lbl_88CCDB74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74770_88A23498(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDB74, (ts4_word)(ts4_word)lbl_8803F0AC, (ts4_word)(ts4_word)lbl_88CCBC84, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74770, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23510: call_seq lbl_88B74788, lbl_88CCBC84, lbl_88044E30, lbl_88CCDBA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74788_88A23510(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDBA4, (ts4_word)(ts4_word)lbl_88044E30, (ts4_word)(ts4_word)lbl_88CCBC84, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74788, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23588: call_seq lbl_88B747A0, lbl_88CCBC84, lbl_88044DF8, lbl_88CCDBD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B747A0_88A23588(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDBD4, (ts4_word)(ts4_word)lbl_88044DF8, (ts4_word)(ts4_word)lbl_88CCBC84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B747A0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23600: call_seq lbl_88B747D0, lbl_88044B54, lbl_88CCDC04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B747D0_88A23600(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDC04, (ts4_word)(ts4_word)lbl_88044B54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B747D0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23670: call_seq lbl_88B74800, lbl_88CCBC84, lbl_88044D8C, lbl_88CCDC34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74800_88A23670(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDC34, (ts4_word)(ts4_word)lbl_88044D8C, (ts4_word)(ts4_word)lbl_88CCBC84, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74800, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A236E8: call_seq lbl_88B74818, lbl_88044A90, lbl_88CCDC64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74818_88A236E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDC64, (ts4_word)(ts4_word)lbl_88044A90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74818, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23758: call_seq lbl_88B74848, lbl_88044ACC, lbl_88CCDC94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74848_88A23758(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDC94, (ts4_word)(ts4_word)lbl_88044ACC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74848, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A237C8: call_seq lbl_88B74890, lbl_88CCB114, lbl_88044CFC, lbl_88CCDCC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74890_88A237C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDCC4, (ts4_word)(ts4_word)lbl_88044CFC, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74890, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23840: call_seq lbl_88B748D8, lbl_88CCCB54, lbl_8804705C, lbl_88CCDCF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B748D8_88A23840(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDCF4, (ts4_word)(ts4_word)lbl_8804705C, (ts4_word)(ts4_word)lbl_88CCCB54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B748D8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A238B8: call_seq lbl_88B74968, lbl_88044A58, lbl_88CCDD24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74968_88A238B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDD24, (ts4_word)(ts4_word)lbl_88044A58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74968, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23928: call_seq lbl_88B749B0, lbl_88044B0C, lbl_88CCDD54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B749B0_88A23928(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDD54, (ts4_word)(ts4_word)lbl_88044B0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B749B0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23998: call_seq lbl_88B749E0, lbl_88044B94, lbl_88CCDD84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B749E0_88A23998(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDD84, (ts4_word)(ts4_word)lbl_88044B94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B749E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23A08: call_seq lbl_88B74A10, lbl_88CCB114, lbl_88044D60, lbl_88CCDDB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74A10_88A23A08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDDB4, (ts4_word)(ts4_word)lbl_88044D60, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74A10, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23A80: call_seq lbl_88B74A40, lbl_88CCB114, lbl_88044C84, lbl_88CCDDE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74A40_88A23A80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDDE4, (ts4_word)(ts4_word)lbl_88044C84, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74A40, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23AF8: call_seq lbl_88B74A58, lbl_88CCB114, lbl_88044C48, lbl_88CCDE14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74A58_88A23AF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDE14, (ts4_word)(ts4_word)lbl_88044C48, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74A58, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23B70: call_seq lbl_88B74A70, lbl_88044A08, lbl_88CCDE44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74A70_88A23B70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDE44, (ts4_word)(ts4_word)lbl_88044A08, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74A70, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23BE0: call_seq lbl_88B74AA0, lbl_88CCB114, lbl_88044C08, lbl_88CCDE74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74AA0_88A23BE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDE74, (ts4_word)(ts4_word)lbl_88044C08, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74AA0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23C58: call_seq lbl_88B74AB8, lbl_88040668, lbl_88CCDEA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74AB8_88A23C58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDEA4, (ts4_word)(ts4_word)lbl_88040668, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74AB8, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23CC8: call_seq lbl_88B74BA8, lbl_88CCB114, lbl_88040658, lbl_88CCDED4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74BA8_88A23CC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDED4, (ts4_word)(ts4_word)lbl_88040658, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74BA8, (ts4_word)18, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23D40: call_seq lbl_88B74D58, lbl_8803F5F4, lbl_88CCDF04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74D58_88A23D40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDF04, (ts4_word)(ts4_word)lbl_8803F5F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74D58, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23DB0: call_seq lbl_88B74EF0, lbl_88CCCB54, lbl_8803F64C, lbl_88CCDF34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74EF0_88A23DB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDF34, (ts4_word)(ts4_word)lbl_8803F64C, (ts4_word)(ts4_word)lbl_88CCCB54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74EF0, (ts4_word)25, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23E28: call_seq lbl_88CCB114, lbl_8804494C, lbl_88CCDF64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCB114_88A23E28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDF64, (ts4_word)(ts4_word)lbl_8804494C, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23E90: call_seq lbl_88B75148, lbl_88CCDF64, lbl_88044700, lbl_88CCDF94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B75148_88A23E90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDF94, (ts4_word)(ts4_word)lbl_88044700, (ts4_word)(ts4_word)lbl_88CCDF64, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B75148, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23F08: call_seq lbl_88CCB114, lbl_88044924, lbl_88CCDFC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCB114_88A23F08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDFC4, (ts4_word)(ts4_word)lbl_88044924, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23F70: call_seq lbl_88B751C0, lbl_88044438, lbl_88CCDFF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B751C0_88A23F70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCDFF4, (ts4_word)(ts4_word)lbl_88044438, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B751C0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23FE0: call_seq lbl_88B75208, lbl_88CCDFC4, lbl_88044680, lbl_88CCE024, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B75208_88A23FE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE024, (ts4_word)(ts4_word)lbl_88044680, (ts4_word)(ts4_word)lbl_88CCDFC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B75208, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24058: call_seq lbl_88CCB114, lbl_880448C8, lbl_88CCE054, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCB114_88A24058(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE054, (ts4_word)(ts4_word)lbl_880448C8, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A240C0: call_seq lbl_88CCB114, lbl_880448FC, lbl_88CCE084, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCB114_88A240C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE084, (ts4_word)(ts4_word)lbl_880448FC, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24128: call_seq lbl_88B75238, lbl_88CCE054, lbl_88044524, lbl_88CCE0B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B75238_88A24128(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE0B4, (ts4_word)(ts4_word)lbl_88044524, (ts4_word)(ts4_word)lbl_88CCE054, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B75238, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A241A0: call_seq lbl_88B75298, lbl_88CCE084, lbl_880446BC, lbl_88CCE0E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B75298_88A241A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE0E4, (ts4_word)(ts4_word)lbl_880446BC, (ts4_word)(ts4_word)lbl_88CCE084, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B75298, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24218: call_seq lbl_88CCB114, lbl_8804489C, lbl_88CCE114, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCB114_88A24218(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE114, (ts4_word)(ts4_word)lbl_8804489C, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24280: call_seq lbl_88B752F8, lbl_88CCE114, lbl_88044650, lbl_88CCE144, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B752F8_88A24280(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE144, (ts4_word)(ts4_word)lbl_88044650, (ts4_word)(ts4_word)lbl_88CCE114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B752F8, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A242F8: call_seq lbl_88B753E8, lbl_88044324, lbl_88CCE174, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B753E8_88A242F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE174, (ts4_word)(ts4_word)lbl_88044324, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B753E8, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24368: call_seq lbl_88B754D8, lbl_88044370, lbl_88CCE1A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B754D8_88A24368(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE1A4, (ts4_word)(ts4_word)lbl_88044370, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B754D8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A243D8: call_seq lbl_88B75520, lbl_8803F610, lbl_88CCE1D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B75520_88A243D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE1D4, (ts4_word)(ts4_word)lbl_8803F610, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B75520, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24448: call_seq lbl_88B755F8, lbl_8803F634, lbl_88CCE204, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B755F8_88A24448(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE204, (ts4_word)(ts4_word)lbl_8803F634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B755F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A244B8: call_seq lbl_88CCB114, lbl_88044874, lbl_88CCE234, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCB114_88A244B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE234, (ts4_word)(ts4_word)lbl_88044874, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24520: call_seq lbl_88B75610, lbl_88CCE234, lbl_8804461C, lbl_88CCE264, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B75610_88A24520(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE264, (ts4_word)(ts4_word)lbl_8804461C, (ts4_word)(ts4_word)lbl_88CCE234, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B75610, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24598: call_seq lbl_88B75658, lbl_88044268, lbl_88CCE294, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B75658_88A24598(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE294, (ts4_word)(ts4_word)lbl_88044268, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B75658, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24608: call_seq lbl_88B756A0, lbl_88CCB114, lbl_8804484C, lbl_88CCE2C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B756A0_88A24608(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE2C4, (ts4_word)(ts4_word)lbl_8804484C, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B756A0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24680: call_seq lbl_88B756B8, lbl_880443CC, lbl_88CCE2F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B756B8_88A24680(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE2F4, (ts4_word)(ts4_word)lbl_880443CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B756B8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A246F0: call_seq lbl_88B75700, lbl_88CCE2C4, lbl_880445E4, lbl_88CCE324, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B75700_88A246F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE324, (ts4_word)(ts4_word)lbl_880445E4, (ts4_word)(ts4_word)lbl_88CCE2C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B75700, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24768: call_seq lbl_88CCB114, lbl_8804481C, lbl_88CCE354, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCB114_88A24768(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE354, (ts4_word)(ts4_word)lbl_8804481C, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A247D0: call_seq lbl_88B75718, lbl_88CCE354, lbl_880445A8, lbl_88CCE384, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B75718_88A247D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE384, (ts4_word)(ts4_word)lbl_880445A8, (ts4_word)(ts4_word)lbl_88CCE354, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B75718, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24848: call_seq lbl_88B757C0, lbl_8804449C, lbl_88CCE3B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B757C0_88A24848(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE3B4, (ts4_word)(ts4_word)lbl_8804449C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B757C0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A248B8: call_seq lbl_88B757F0, lbl_88CCB114, lbl_88044744, lbl_88CCE3E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B757F0_88A248B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE3E4, (ts4_word)(ts4_word)lbl_88044744, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B757F0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24930: call_seq lbl_88B75838, lbl_88CCB114, lbl_88044758, lbl_88CCE414, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B75838_88A24930(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE414, (ts4_word)(ts4_word)lbl_88044758, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B75838, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A249A8: call_seq lbl_88CCB114, lbl_880447EC, lbl_88CCE444, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCB114_88A249A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE444, (ts4_word)(ts4_word)lbl_880447EC, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24A10: call_seq lbl_88B75880, lbl_88CCE444, lbl_88044568, lbl_88CCE474, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B75880_88A24A10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE474, (ts4_word)(ts4_word)lbl_88044568, (ts4_word)(ts4_word)lbl_88CCE444, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B75880, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24A88: call_seq lbl_88B758C8, lbl_88CCB114, lbl_880447B8, lbl_88CCE4A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B758C8_88A24A88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE4A4, (ts4_word)(ts4_word)lbl_880447B8, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B758C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24B00: call_seq lbl_88B758E0, lbl_88CCB114, lbl_88044784, lbl_88CCE4D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B758E0_88A24B00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE4D4, (ts4_word)(ts4_word)lbl_88044784, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B758E0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24B78: call_seq lbl_88B758F8, lbl_88CCE4A4, lbl_880444CC, lbl_88CCE504, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B758F8_88A24B78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE504, (ts4_word)(ts4_word)lbl_880444CC, (ts4_word)(ts4_word)lbl_88CCE4A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B758F8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24BF0: call_seq lbl_88055A18, lbl_88056AF8, lbl_88CCE534, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF5C0, fn_88563470 */
ts4_word ts4_call_seq_lbl_88055A18_88A24BF0(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CCE534, (ts4_word)(ts4_word)lbl_88056AF8, (ts4_word)4, (ts4_word)(ts4_word)lbl_88055A18);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF5C0);
    return t2;
}

/* Swing_DLL.xex 0x88A24C38: call_seq lbl_88B76780, lbl_88046C94, lbl_88CCE54C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76780_88A24C38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE54C, (ts4_word)(ts4_word)lbl_88046C94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B76780, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24CA8: addr lbl_88B7CA80, u32@lbl_88B767F8, u32@0x38 */
void ts4_addr_lbl_88B7CA80_88A24CA8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7CA80) + 56) = (ts4_word)(*(ts4_word *)lbl_88B767F8);
    return;
}

/* Swing_DLL.xex 0x88A24CC0: call_seq lbl_880572A4, lbl_88B7CA80, lbl_8803EF04, lbl_88CCE57C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880572A4_88A24CC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE57C, (ts4_word)(ts4_word)lbl_8803EF04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880572A4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7CA80, (ts4_word)3, (ts4_word)((ts4_word)lbl_880572A4 + 20), (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24D38: call_seq lbl_88B767FC, lbl_88046C78, lbl_88CCE5AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B767FC_88A24D38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE5AC, (ts4_word)(ts4_word)lbl_88046C78, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B767FC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24DA8: call_seq lbl_88B7682C, lbl_8803EC6C, lbl_88CCE5DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7682C_88A24DA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE5DC, (ts4_word)(ts4_word)lbl_8803EC6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7682C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24E18: call_seq lbl_88B76860, lbl_88CCF20C, lbl_8803EE48, lbl_88CCE60C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76860_88A24E18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE60C, (ts4_word)(ts4_word)lbl_8803EE48, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B76860, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24E90: call_seq lbl_88B768C0, lbl_88040040, lbl_88CCE63C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B768C0_88A24E90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE63C, (ts4_word)(ts4_word)lbl_88040040, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B768C0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24F00: call_seq lbl_88B76938, lbl_88CCE60C, lbl_8803ECD0, lbl_88CCE66C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76938_88A24F00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE66C, (ts4_word)(ts4_word)lbl_8803ECD0, (ts4_word)(ts4_word)lbl_88CCE60C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B76938, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24F78: call_seq lbl_88B769E0, lbl_88CCE60C, lbl_8803ECB0, lbl_88CCE69C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B769E0_88A24F78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE69C, (ts4_word)(ts4_word)lbl_8803ECB0, (ts4_word)(ts4_word)lbl_88CCE60C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B769E0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A24FF0: call_seq lbl_88B769F8, lbl_88040078, lbl_88CCE6CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B769F8_88A24FF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE6CC, (ts4_word)(ts4_word)lbl_88040078, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B769F8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25060: call_seq lbl_88B76A70, lbl_88CCE60C, lbl_8803EC94, lbl_88CCE6FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76A70_88A25060(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE6FC, (ts4_word)(ts4_word)lbl_8803EC94, (ts4_word)(ts4_word)lbl_88CCE60C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B76A70, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A250D8: call_seq lbl_88B76B18, lbl_88046C60, lbl_88CCE72C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76B18_88A250D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE72C, (ts4_word)(ts4_word)lbl_88046C60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B76B18, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25148: call_seq lbl_88B76B30, lbl_8803EE88, lbl_88CCE75C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76B30_88A25148(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE75C, (ts4_word)(ts4_word)lbl_8803EE88, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B76B30, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A251B8: call_seq lbl_88B76B90, lbl_88CCF20C, lbl_8804002C, lbl_88CCE78C, lbl_880572E0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76B90_88A251B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE78C, (ts4_word)(ts4_word)lbl_8804002C, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880572E0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B76B90, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25228: call_seq lbl_88B76BA8, lbl_88046C00, lbl_88CCE7BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76BA8_88A25228(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE7BC, (ts4_word)(ts4_word)lbl_88046C00, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B76BA8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25298: call_seq lbl_88B76BF0, lbl_88046C24, lbl_88CCE7EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76BF0_88A25298(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE7EC, (ts4_word)(ts4_word)lbl_88046C24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B76BF0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25308: call_seq lbl_88B76C80, lbl_88046C48, lbl_88CCE81C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76C80_88A25308(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE81C, (ts4_word)(ts4_word)lbl_88046C48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B76C80, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25378: call_seq lbl_88CCF20C, lbl_8803EC3C, lbl_88CCE84C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCF20C_88A25378(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE84C, (ts4_word)(ts4_word)lbl_8803EC3C, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A253E0: call_seq lbl_88B76D10, lbl_88CCE84C, lbl_8803ECF4, lbl_88CCE87C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76D10_88A253E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE87C, (ts4_word)(ts4_word)lbl_8803ECF4, (ts4_word)(ts4_word)lbl_88CCE84C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B76D10, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25458: call_seq lbl_88B76D70, lbl_8803EEFC, lbl_88CCE8AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76D70_88A25458(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE8AC, (ts4_word)(ts4_word)lbl_8803EEFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B76D70, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A254C8: call_seq lbl_88B76DA0, lbl_8803EEE8, lbl_88CCE8DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76DA0_88A254C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE8DC, (ts4_word)(ts4_word)lbl_8803EEE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B76DA0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25538: call_seq lbl_88B76E00, lbl_8803EE7C, lbl_88CCE90C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76E00_88A25538(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE90C, (ts4_word)(ts4_word)lbl_8803EE7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B76E00, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A255A8: call_seq lbl_88B76E60, lbl_88041578, lbl_88CCE93C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76E60_88A255A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE93C, (ts4_word)(ts4_word)lbl_88041578, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B76E60, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25618: call_seq lbl_88B76EE0, lbl_88042110, lbl_88CCE96C, lbl_88057314, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76EE0_88A25618(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE96C, (ts4_word)(ts4_word)lbl_88042110, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057314, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B76EE0, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25688: call_seq lbl_88B76FE8, lbl_88057328, lbl_880420FC, lbl_88CCE99C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76FE8_88A25688(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE99C, (ts4_word)(ts4_word)lbl_880420FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B76FE8, (ts4_word)11, (ts4_word)(ts4_word)lbl_88057328, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25700: call_seq lbl_88B770F0, lbl_88041204, lbl_88CCE9CC, lbl_8805736C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B770F0_88A25700(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE9CC, (ts4_word)(ts4_word)lbl_88041204, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805736C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B770F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25770: call_seq lbl_88CCEF9C, lbl_88053DD8, lbl_88CCE9FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCEF9C_88A25770(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCE9FC, (ts4_word)(ts4_word)lbl_88053DD8, (ts4_word)(ts4_word)lbl_88CCEF9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A257D8: call_seq lbl_88057380, lbl_88B77120, lbl_88CCE9FC, lbl_88041268, lbl_88CCEA2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88057380_88A257D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEA2C, (ts4_word)(ts4_word)lbl_88041268, (ts4_word)(ts4_word)lbl_88CCE9FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77120, (ts4_word)7, (ts4_word)(ts4_word)lbl_88057380, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25850: call_seq lbl_88CCEA2C, lbl_88053DE8, lbl_88CCEA5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCEA2C_88A25850(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEA5C, (ts4_word)(ts4_word)lbl_88053DE8, (ts4_word)(ts4_word)lbl_88CCEA2C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A258B8: call_seq lbl_88B771C8, lbl_88CCF20C, lbl_8804124C, lbl_88CCEA8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B771C8_88A258B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEA8C, (ts4_word)(ts4_word)lbl_8804124C, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B771C8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25930: call_seq lbl_880573AC, lbl_88B77210, lbl_88CCE9FC, lbl_88041238, lbl_88CCEABC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880573AC_88A25930(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEABC, (ts4_word)(ts4_word)lbl_88041238, (ts4_word)(ts4_word)lbl_88CCE9FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77210, (ts4_word)7, (ts4_word)(ts4_word)lbl_880573AC, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A259A8: call_seq lbl_88B772B8, lbl_8804115C, lbl_88CCEAEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B772B8_88A259A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEAEC, (ts4_word)(ts4_word)lbl_8804115C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B772B8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25A18: addr lbl_88B7CAC8, u32@lbl_88B77300, u32@0x8 */
void ts4_addr_lbl_88B7CAC8_88A25A18(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7CAC8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B77300);
    return;
}

/* Swing_DLL.xex 0x88A25AA8: call_seq lbl_88B77304, lbl_88CCE9FC, lbl_88041584, lbl_88CCEB4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77304_88A25AA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEB4C, (ts4_word)(ts4_word)lbl_88041584, (ts4_word)(ts4_word)lbl_88CCE9FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77304, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25B20: call_seq lbl_88B77334, lbl_88CCE9FC, lbl_88053E90, lbl_88CCEB7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77334_88A25B20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEB7C, (ts4_word)(ts4_word)lbl_88053E90, (ts4_word)(ts4_word)lbl_88CCE9FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77334, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25B98: call_seq lbl_88CCEF9C, lbl_88053EAC, lbl_88CCEBAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCEF9C_88A25B98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEBAC, (ts4_word)(ts4_word)lbl_88053EAC, (ts4_word)(ts4_word)lbl_88CCEF9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25C00: call_seq lbl_88B7734C, lbl_88CCEBAC, lbl_88042128, lbl_88CCEBDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7734C_88A25C00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEBDC, (ts4_word)(ts4_word)lbl_88042128, (ts4_word)(ts4_word)lbl_88CCEBAC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7734C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25C78: call_seq lbl_88B77380, lbl_880420B8, lbl_88CCEC0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77380_88A25C78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEC0C, (ts4_word)(ts4_word)lbl_880420B8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77380, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25CE8: call_seq lbl_88B773E0, lbl_880420E4, lbl_88CCEC3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B773E0_88A25CE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEC3C, (ts4_word)(ts4_word)lbl_880420E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B773E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25D58: call_seq lbl_88057450, lbl_88B77410, lbl_88CCEBAC, lbl_88041634, lbl_88CCEC6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88057450_88A25D58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEC6C, (ts4_word)(ts4_word)lbl_88041634, (ts4_word)(ts4_word)lbl_88CCEBAC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77410, (ts4_word)16, (ts4_word)(ts4_word)lbl_88057450, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25DD0: call_seq lbl_88B77590, lbl_88CCEBAC, lbl_880420C8, lbl_88CCEC9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77590_88A25DD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEC9C, (ts4_word)(ts4_word)lbl_880420C8, (ts4_word)(ts4_word)lbl_88CCEBAC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77590, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25E48: call_seq lbl_8805749C, lbl_88B775A8, lbl_88CCEBAC, lbl_880411F0, lbl_88CCECCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805749C_88A25E48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCECCC, (ts4_word)(ts4_word)lbl_880411F0, (ts4_word)(ts4_word)lbl_88CCEBAC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B775A8, (ts4_word)4, (ts4_word)(ts4_word)lbl_8805749C, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25EC0: call_seq lbl_88B77608, lbl_88CCEBAC, lbl_880411C8, lbl_88CCECFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77608_88A25EC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCECFC, (ts4_word)(ts4_word)lbl_880411C8, (ts4_word)(ts4_word)lbl_88CCEBAC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77608, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25F38: call_seq lbl_88B776E0, lbl_88CCEBAC, lbl_88048610, lbl_88CCED2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B776E0_88A25F38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCED2C, (ts4_word)(ts4_word)lbl_88048610, (ts4_word)(ts4_word)lbl_88CCEBAC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B776E0, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A25FB0: call_seq lbl_88B777E8, lbl_88CCEBAC, lbl_88042140, lbl_88CCED5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B777E8_88A25FB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCED5C, (ts4_word)(ts4_word)lbl_88042140, (ts4_word)(ts4_word)lbl_88CCEBAC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B777E8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26028: addr lbl_88B7CC18, u32@lbl_88B7737C, u32@0x68 */
void ts4_addr_lbl_88B7CC18_88A26028(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7CC18) + 104) = (ts4_word)(*(ts4_word *)lbl_88B7737C);
    return;
}

/* Swing_DLL.xex 0x88A260B8: call_seq lbl_8805753C, lbl_88B77818, lbl_88CCF20C, lbl_88053F68, lbl_88CCEDBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805753C_88A260B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEDBC, (ts4_word)(ts4_word)lbl_88053F68, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77818, (ts4_word)2, (ts4_word)(ts4_word)lbl_8805753C, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26130: call_seq lbl_88B77848, lbl_88042098, lbl_88CCEDEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77848_88A26130(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEDEC, (ts4_word)(ts4_word)lbl_88042098, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77848, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A261A0: addr lbl_88B7CDB0, u32@lbl_88B778D8, u32@0x50 */
void ts4_addr_lbl_88B7CDB0_88A261A0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7CDB0) + 80) = (ts4_word)(*(ts4_word *)lbl_88B778D8);
    return;
}

/* Swing_DLL.xex 0x88A26230: call_seq lbl_88B778DC, lbl_88CCEBAC, lbl_88042074, lbl_88CCEE4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B778DC_88A26230(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEE4C, (ts4_word)(ts4_word)lbl_88042074, (ts4_word)(ts4_word)lbl_88CCEBAC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B778DC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A262A8: call_seq lbl_880575A8, lbl_88B77910, lbl_88CCEBAC, lbl_88041618, lbl_88CCEE7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880575A8_88A262A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEE7C, (ts4_word)(ts4_word)lbl_88041618, (ts4_word)(ts4_word)lbl_88CCEBAC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77910, (ts4_word)6, (ts4_word)(ts4_word)lbl_880575A8, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26320: call_seq lbl_88B779A0, lbl_880415F8, lbl_88CCEEAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B779A0_88A26320(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEEAC, (ts4_word)(ts4_word)lbl_880415F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B779A0, (ts4_word)14, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26390: call_seq lbl_880575CC, lbl_88B77AF0, lbl_88CCEBAC, lbl_88040228, lbl_88CCEEDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880575CC_88A26390(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEEDC, (ts4_word)(ts4_word)lbl_88040228, (ts4_word)(ts4_word)lbl_88CCEBAC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77AF0, (ts4_word)8, (ts4_word)(ts4_word)lbl_880575CC, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26408: call_seq lbl_88B77BB0, lbl_88CCEBAC, lbl_880415D4, lbl_88CCEF0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77BB0_88A26408(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEF0C, (ts4_word)(ts4_word)lbl_880415D4, (ts4_word)(ts4_word)lbl_88CCEBAC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77BB0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26480: call_seq lbl_88B77BC8, lbl_88CCECFC, lbl_880411DC, lbl_88CCEF3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77BC8_88A26480(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEF3C, (ts4_word)(ts4_word)lbl_880411DC, (ts4_word)(ts4_word)lbl_88CCECFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77BC8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A264F8: call_seq lbl_88B77C58, lbl_88CCEBAC, lbl_8805704C, lbl_88CCEF6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77C58_88A264F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEF6C, (ts4_word)(ts4_word)lbl_8805704C, (ts4_word)(ts4_word)lbl_88CCEBAC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77C58, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26570: call_seq lbl_88B77C70, lbl_88CCF20C, lbl_8804116C, lbl_88CCEF9C, lbl_88057614, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77C70_88A26570(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEF9C, (ts4_word)(ts4_word)lbl_8804116C, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057614, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B77C70, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A265E0: call_seq lbl_88CCF20C, lbl_88058A10, lbl_88CCEFCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCF20C_88A265E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEFCC, (ts4_word)(ts4_word)lbl_88058A10, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26648: call_seq lbl_88B77C88, lbl_88CCEFCC, lbl_88058A20, lbl_88CCEFFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77C88_88A26648(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCEFFC, (ts4_word)(ts4_word)lbl_88058A20, (ts4_word)(ts4_word)lbl_88CCEFCC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77C88, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A266C0: call_seq lbl_88B77CA0, lbl_88041174, lbl_88CCF02C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77CA0_88A266C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF02C, (ts4_word)(ts4_word)lbl_88041174, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77CA0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26730: call_seq lbl_88B77D00, lbl_88041194, lbl_88CCF05C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77D00_88A26730(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF05C, (ts4_word)(ts4_word)lbl_88041194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77D00, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A267A0: call_seq lbl_88057628, lbl_88B77D48, lbl_88CCE9FC, lbl_88040218, lbl_88CCF08C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88057628_88A267A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF08C, (ts4_word)(ts4_word)lbl_88040218, (ts4_word)(ts4_word)lbl_88CCE9FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77D48, (ts4_word)12, (ts4_word)(ts4_word)lbl_88057628, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26818: call_seq lbl_88B77E68, lbl_88041930, lbl_88CCF0BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77E68_88A26818(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF0BC, (ts4_word)(ts4_word)lbl_88041930, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77E68, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26888: call_seq lbl_8805767C, lbl_88CCF20C, lbl_88041114, lbl_88CCF0EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805767C_88A26888(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF0EC, (ts4_word)(ts4_word)lbl_88041114, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805767C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A268F0: addr lbl_88B7CEB8, u32@lbl_88B77EB8, u32@0x50 */
void ts4_addr_lbl_88B7CEB8_88A268F0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7CEB8) + 80) = (ts4_word)(*(ts4_word *)lbl_88B77EB8);
    return;
}

/* Swing_DLL.xex 0x88A26980: call_seq lbl_88B77EC0, lbl_88057748, lbl_88040200, lbl_88CCF14C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77EC0_88A26980(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF14C, (ts4_word)(ts4_word)lbl_88040200, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77EC0, (ts4_word)4, (ts4_word)(ts4_word)lbl_88057748, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A269F8: call_seq lbl_88B77F20, lbl_880401D8, lbl_88CCF17C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77F20_88A269F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF17C, (ts4_word)(ts4_word)lbl_880401D8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77F20, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26A68: call_seq lbl_88B77F50, lbl_88CCF20C, lbl_880401F0, lbl_88CCF1AC, lbl_88057734, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77F50_88A26A68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF1AC, (ts4_word)(ts4_word)lbl_880401F0, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057734, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B77F50, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26AD8: call_seq lbl_8803C97C, lbl_88CCF1DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803C97C_88A26AD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF1DC, (ts4_word)(ts4_word)lbl_8803C97C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26B38: call_seq lbl_88B77F68, lbl_88CCF1DC, lbl_8803C9DC, lbl_88CCF20C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77F68_88A26B38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)(ts4_word)lbl_8803C9DC, (ts4_word)(ts4_word)lbl_88CCF1DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B77F68, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26BB0: call_seq lbl_88B77FA0, lbl_8803CC5C, lbl_88CCF23C, lbl_88057764, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B77FA0_88A26BB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF23C, (ts4_word)(ts4_word)lbl_8803CC5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057764, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B77FA0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26C20: call_seq lbl_88B78048, lbl_8803CCC4, lbl_88CCF26C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78048_88A26C20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF26C, (ts4_word)(ts4_word)lbl_8803CCC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78048, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26C90: call_seq lbl_88B78078, lbl_8803CCD4, lbl_88CCF29C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78078_88A26C90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF29C, (ts4_word)(ts4_word)lbl_8803CCD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78078, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26D00: addr lbl_88B7CF78, u32@lbl_88B77F9C, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88B7CF78_88A26D00(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B77F9C;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7CF78) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7CF78) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A26D20: call_seq lbl_88B7CF78, lbl_8803D124, lbl_88CCF2CC, lbl_880578D8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7CF78_88A26D20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF2CC, (ts4_word)(ts4_word)lbl_8803D124, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880578D8, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B7CF78, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26D90: call_seq lbl_88B780B0, lbl_8803D484, lbl_88CCF2FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B780B0_88A26D90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF2FC, (ts4_word)(ts4_word)lbl_8803D484, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B780B0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26E00: call_seq lbl_88B780E0, lbl_8803D4A8, lbl_88CCF32C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B780E0_88A26E00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF32C, (ts4_word)(ts4_word)lbl_8803D4A8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B780E0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26E70: addr lbl_88B7D038, u32@lbl_88B780F8, u32@0x50 */
void ts4_addr_lbl_88B7D038_88A26E70(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D038) + 80) = (ts4_word)(*(ts4_word *)lbl_88B780F8);
    return;
}

/* Swing_DLL.xex 0x88A26E88: call_seq lbl_88B7D038, lbl_8803D4C4, lbl_88CCF35C, lbl_8805792C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7D038_88A26E88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF35C, (ts4_word)(ts4_word)lbl_8803D4C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805792C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7D038, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26EF8: call_seq lbl_88B78108, lbl_8803F9C0, lbl_88CCF38C, lbl_88057968, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78108_88A26EF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF38C, (ts4_word)(ts4_word)lbl_8803F9C0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057968, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B78108, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26F68: call_seq lbl_88B78150, lbl_8803CAF0, lbl_88CCF3BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78150_88A26F68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF3BC, (ts4_word)(ts4_word)lbl_8803CAF0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78150, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A26FD8: call_seq lbl_88B78180, lbl_8803D194, lbl_88CCF3EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78180_88A26FD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF3EC, (ts4_word)(ts4_word)lbl_8803D194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78180, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27048: call_seq lbl_88B781B0, lbl_8803D2E0, lbl_88CCF41C, lbl_880579A0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B781B0_88A27048(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF41C, (ts4_word)(ts4_word)lbl_8803D2E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880579A0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B781B0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A270B8: call_seq lbl_88B78210, lbl_8803D6A0, lbl_88CCF44C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78210_88A270B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF44C, (ts4_word)(ts4_word)lbl_8803D6A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78210, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27128: call_seq lbl_88B78300, lbl_8803D914, lbl_88CCF47C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78300_88A27128(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF47C, (ts4_word)(ts4_word)lbl_8803D914, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78300, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27198: call_seq lbl_88B78318, lbl_8803D9E8, lbl_88CCF4AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78318_88A27198(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF4AC, (ts4_word)(ts4_word)lbl_8803D9E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78318, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27208: addr lbl_88B7D0C8, u32@lbl_88B783A8, u32@0x20 */
void ts4_addr_lbl_88B7D0C8_88A27208(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D0C8) + 32) = (ts4_word)(*(ts4_word *)lbl_88B783A8);
    return;
}

/* Swing_DLL.xex 0x88A27220: call_seq lbl_88B7D0C8, lbl_8803F988, lbl_88CCF4DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7D0C8_88A27220(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF4DC, (ts4_word)(ts4_word)lbl_8803F988, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7D0C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27290: addr lbl_88B7D0F8, u32@lbl_88B783A8, u32@0x20 */
void ts4_addr_lbl_88B7D0F8_88A27290(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D0F8) + 32) = (ts4_word)(*(ts4_word *)lbl_88B783A8);
    return;
}

/* Swing_DLL.xex 0x88A272A8: call_seq lbl_88B7D0F8, lbl_8803F974, lbl_88CCF50C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7D0F8_88A272A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF50C, (ts4_word)(ts4_word)lbl_8803F974, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7D0F8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27318: call_seq lbl_88B78390, lbl_8804E4DC, lbl_88CCF53C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78390_88A27318(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF53C, (ts4_word)(ts4_word)lbl_8804E4DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78390, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27388: addr lbl_88B7D128, u32@lbl_88B783A8, u32@0x20 */
void ts4_addr_lbl_88B7D128_88A27388(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D128) + 32) = (ts4_word)(*(ts4_word *)lbl_88B783A8);
    return;
}

/* Swing_DLL.xex 0x88A273A0: call_seq lbl_88B7D128, lbl_8803F960, lbl_88CCF56C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7D128_88A273A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF56C, (ts4_word)(ts4_word)lbl_8803F960, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7D128, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27410: call_seq lbl_88B783AC, lbl_8803F9B0, lbl_88CCF59C, lbl_880579E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B783AC_88A27410(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF59C, (ts4_word)(ts4_word)lbl_8803F9B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880579E4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B783AC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27480: call_seq lbl_88B783DC, lbl_8803F99C, lbl_88CCF5CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B783DC_88A27480(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF5CC, (ts4_word)(ts4_word)lbl_8803F99C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B783DC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A274F0: call_seq lbl_88B7840C, lbl_8804E4F4, lbl_88CCF5FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7840C_88A274F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF5FC, (ts4_word)(ts4_word)lbl_8804E4F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7840C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27560: call_seq lbl_88B7843C, lbl_88CCF65C, lbl_8804E50C, lbl_88CCF62C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7843C_88A27560(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF62C, (ts4_word)(ts4_word)lbl_8804E50C, (ts4_word)(ts4_word)lbl_88CCF65C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7843C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A275D8: call_seq lbl_88B78454, lbl_8804E524, lbl_88CCF65C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78454_88A275D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF65C, (ts4_word)(ts4_word)lbl_8804E524, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78454, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27648: call_seq lbl_88B78484, lbl_8804E53C, lbl_88CCF68C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78484_88A27648(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF68C, (ts4_word)(ts4_word)lbl_8804E53C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78484, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A276B8: call_seq lbl_88B7849C, lbl_8804E560, lbl_88CCF6BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7849C_88A276B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF6BC, (ts4_word)(ts4_word)lbl_8804E560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7849C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27728: call_seq lbl_88B784D0, lbl_8803F5C8, lbl_88CCF6EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B784D0_88A27728(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF6EC, (ts4_word)(ts4_word)lbl_8803F5C8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B784D0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27798: call_seq lbl_88B78578, lbl_88054050, lbl_88CCF71C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78578_88A27798(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF71C, (ts4_word)(ts4_word)lbl_88054050, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78578, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27808: call_seq lbl_88B785A8, lbl_88054068, lbl_88CCF74C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B785A8_88A27808(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF74C, (ts4_word)(ts4_word)lbl_88054068, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B785A8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27878: call_seq lbl_88B785C0, lbl_8804C310, lbl_88CCF77C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B785C0_88A27878(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF77C, (ts4_word)(ts4_word)lbl_8804C310, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B785C0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A278E8: call_seq lbl_88B785F0, lbl_8803ED20, lbl_88CCF7AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B785F0_88A278E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF7AC, (ts4_word)(ts4_word)lbl_8803ED20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B785F0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27958: addr lbl_88B7D158, u32@lbl_88B784CC, u32@0x8 */
void ts4_addr_lbl_88B7D158_88A27958(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D158) + 8) = (ts4_word)(*(ts4_word *)lbl_88B784CC);
    return;
}

/* Swing_DLL.xex 0x88A27970: call_seq lbl_88B7D158, lbl_8804C33C, lbl_88CCF7DC, lbl_88057A10, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7D158_88A27970(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF7DC, (ts4_word)(ts4_word)lbl_8804C33C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057A10, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7D158, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A279E0: call_seq lbl_88B786B4, lbl_8803ED28, lbl_88CCF80C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B786B4_88A279E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF80C, (ts4_word)(ts4_word)lbl_8803ED28, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B786B4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27A50: call_seq lbl_88B786E8, lbl_8803ED14, lbl_88CCF83C, lbl_88057A54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B786E8_88A27A50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF83C, (ts4_word)(ts4_word)lbl_8803ED14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057A54, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B786E8, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27AC0: addr lbl_88B7D1D0, u32@lbl_88B786E4, u32@0x20 */
void ts4_addr_lbl_88B7D1D0_88A27AC0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D1D0) + 32) = (ts4_word)(*(ts4_word *)lbl_88B786E4);
    return;
}

/* Swing_DLL.xex 0x88A27AD8: call_seq lbl_88B7D1D0, lbl_8804E57C, lbl_88CCF86C, lbl_88057A90, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7D1D0_88A27AD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF86C, (ts4_word)(ts4_word)lbl_8804E57C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057A90, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7D1D0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27B48: call_seq lbl_88B787A8, lbl_8804C348, lbl_88CCF89C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B787A8_88A27B48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF89C, (ts4_word)(ts4_word)lbl_8804C348, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B787A8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27BB8: call_seq lbl_88B787C0, lbl_8804C358, lbl_88CCF8CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B787C0_88A27BB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF8CC, (ts4_word)(ts4_word)lbl_8804C358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B787C0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27C28: addr lbl_88B7D218, u32@lbl_88B787F0, u32@0x8 */
void ts4_addr_lbl_88B7D218_88A27C28(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D218) + 8) = (ts4_word)(*(ts4_word *)lbl_88B787F0);
    return;
}

/* Swing_DLL.xex 0x88A27C40: call_seq lbl_88B7D218, lbl_8804C380, lbl_88CCF8FC, lbl_88057ACC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7D218_88A27C40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF8FC, (ts4_word)(ts4_word)lbl_8804C380, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057ACC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7D218, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27CB0: call_seq lbl_88B787F4, lbl_88042408, lbl_88CCF92C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B787F4_88A27CB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF92C, (ts4_word)(ts4_word)lbl_88042408, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B787F4, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27D20: call_seq lbl_88B78810, lbl_880423F8, lbl_88CCF95C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78810_88A27D20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF95C, (ts4_word)(ts4_word)lbl_880423F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78810, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27D90: call_seq lbl_88B78858, lbl_8804C390, lbl_88CCF98C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78858_88A27D90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF98C, (ts4_word)(ts4_word)lbl_8804C390, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78858, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27E00: call_seq lbl_88B78888, lbl_8804C3A0, lbl_88CCF9BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78888_88A27E00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF9BC, (ts4_word)(ts4_word)lbl_8804C3A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78888, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27E70: call_seq lbl_88B789A8, lbl_8804C3B0, lbl_88CCF9EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B789A8_88A27E70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCF9EC, (ts4_word)(ts4_word)lbl_8804C3B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B789A8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27EE0: call_seq lbl_88B78A38, lbl_8804C3C4, lbl_88CCFA1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78A38_88A27EE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFA1C, (ts4_word)(ts4_word)lbl_8804C3C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78A38, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27F50: call_seq lbl_88B78AF8, lbl_8804C3DC, lbl_88CCFA4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78AF8_88A27F50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFA4C, (ts4_word)(ts4_word)lbl_8804C3DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78AF8, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A27FC0: call_seq lbl_88B78BD0, lbl_8804C3F8, lbl_88CCFA7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78BD0_88A27FC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFA7C, (ts4_word)(ts4_word)lbl_8804C3F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78BD0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28030: call_seq lbl_88B78C90, lbl_8804C410, lbl_88CCFAAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78C90_88A28030(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFAAC, (ts4_word)(ts4_word)lbl_8804C410, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78C90, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A280A0: call_seq lbl_88B78D38, lbl_88057AE0, lbl_8803F5BC, lbl_88CCFADC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78D38_88A280A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFADC, (ts4_word)(ts4_word)lbl_8803F5BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78D38, (ts4_word)12, (ts4_word)(ts4_word)lbl_88057AE0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28118: call_seq lbl_88B78E58, lbl_8804C428, lbl_88CCFB0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78E58_88A28118(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFB0C, (ts4_word)(ts4_word)lbl_8804C428, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78E58, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28188: call_seq lbl_88B78EB8, lbl_8803F5E0, lbl_88CCFB3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78EB8_88A28188(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFB3C, (ts4_word)(ts4_word)lbl_8803F5E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78EB8, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A281F8: call_seq lbl_88B78FC0, lbl_88040278, lbl_88CCFB6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B78FC0_88A281F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFB6C, (ts4_word)(ts4_word)lbl_88040278, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B78FC0, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28268: call_seq lbl_88B79098, lbl_8803ED58, lbl_88CCFB9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79098_88A28268(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFB9C, (ts4_word)(ts4_word)lbl_8803ED58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79098, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A282D8: call_seq lbl_88B790E0, lbl_8803ED40, lbl_88CCFBCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B790E0_88A282D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFBCC, (ts4_word)(ts4_word)lbl_8803ED40, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B790E0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28348: call_seq lbl_88B790F8, lbl_880433FC, lbl_88CCFBFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B790F8_88A28348(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFBFC, (ts4_word)(ts4_word)lbl_880433FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B790F8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A283B8: call_seq lbl_88B79140, lbl_8804342C, lbl_88CCFC2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79140_88A283B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFC2C, (ts4_word)(ts4_word)lbl_8804342C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79140, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28428: call_seq lbl_88B79158, lbl_88CCF20C, lbl_8803ED7C, lbl_88CCFC5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79158_88A28428(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFC5C, (ts4_word)(ts4_word)lbl_8803ED7C, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79158, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A284A0: call_seq lbl_88B791A0, lbl_88046454, lbl_88CCFC8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B791A0_88A284A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFC8C, (ts4_word)(ts4_word)lbl_88046454, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B791A0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28510: call_seq lbl_88B79200, lbl_88CCFC8C, lbl_8804233C, lbl_88CCFCBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79200_88A28510(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFCBC, (ts4_word)(ts4_word)lbl_8804233C, (ts4_word)(ts4_word)lbl_88CCFC8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79200, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28588: call_seq lbl_880469C4, lbl_88CCFCEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880469C4_88A28588(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFCEC, (ts4_word)(ts4_word)lbl_880469C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A285E8: call_seq lbl_88B79248, lbl_88CD19CC, lbl_88042E48, lbl_88CCFD1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79248_88A285E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFD1C, (ts4_word)(ts4_word)lbl_88042E48, (ts4_word)(ts4_word)lbl_88CD19CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79248, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28660: call_seq lbl_88046B60, lbl_88CCFD4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046B60_88A28660(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFD4C, (ts4_word)(ts4_word)lbl_88046B60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}
