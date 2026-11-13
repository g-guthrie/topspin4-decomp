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

extern char lbl_8803ED14[];
extern char lbl_8803ED20[];
extern char lbl_8803ED28[];
extern char lbl_8803ED40[];
extern char lbl_8803ED58[];
extern char lbl_8803ED7C[];
extern char lbl_8803EF90[];
extern char lbl_8803EF9C[];
extern char lbl_8803EFA8[];
extern char lbl_8803EFD0[];
extern char lbl_8803EFE8[];
extern char lbl_8803F00C[];
extern char lbl_8803F048[];
extern char lbl_8803F084[];
extern char lbl_8803F0C8[];
extern char lbl_8803F5BC[];
extern char lbl_8803F5C8[];
extern char lbl_8803F5D4[];
extern char lbl_8803F5E0[];
extern char lbl_8803F660[];
extern char lbl_8803F690[];
extern char lbl_8803F6B0[];
extern char lbl_8803F6CC[];
extern char lbl_8803F6D8[];
extern char lbl_8803F9D4[];
extern char lbl_8803F9E8[];
extern char lbl_8803FA04[];
extern char lbl_8803FA18[];
extern char lbl_8803FBE0[];
extern char lbl_8803FC48[];
extern char lbl_8803FC6C[];
extern char lbl_8803FC80[];
extern char lbl_8803FCA0[];
extern char lbl_880400A8[];
extern char lbl_880400BC[];
extern char lbl_880400D0[];
extern char lbl_880400E8[];
extern char lbl_88040100[];
extern char lbl_88040110[];
extern char lbl_8804011C[];
extern char lbl_88040278[];
extern char lbl_880402A0[];
extern char lbl_880402B0[];
extern char lbl_880402BC[];
extern char lbl_880402CC[];
extern char lbl_880402E4[];
extern char lbl_88040300[];
extern char lbl_8804032C[];
extern char lbl_88040344[];
extern char lbl_88040364[];
extern char lbl_88040380[];
extern char lbl_88040394[];
extern char lbl_880403AC[];
extern char lbl_880403C4[];
extern char lbl_880403DC[];
extern char lbl_88040DB0[];
extern char lbl_88040E04[];
extern char lbl_88040E18[];
extern char lbl_88040E68[];
extern char lbl_88041284[];
extern char lbl_88041AFC[];
extern char lbl_88041B0C[];
extern char lbl_88041B24[];
extern char lbl_88041DE0[];
extern char lbl_8804215C[];
extern char lbl_88042170[];
extern char lbl_88042184[];
extern char lbl_880421A0[];
extern char lbl_880421E0[];
extern char lbl_88042200[];
extern char lbl_8804221C[];
extern char lbl_8804223C[];
extern char lbl_88042260[];
extern char lbl_88042284[];
extern char lbl_8804229C[];
extern char lbl_880422B8[];
extern char lbl_880422DC[];
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
extern char lbl_88042E20[];
extern char lbl_88042E48[];
extern char lbl_880433FC[];
extern char lbl_8804342C[];
extern char lbl_88043ED0[];
extern char lbl_88043EE0[];
extern char lbl_88044F10[];
extern char lbl_88044F38[];
extern char lbl_88044F90[];
extern char lbl_88045020[];
extern char lbl_88045070[];
extern char lbl_88045194[];
extern char lbl_88045224[];
extern char lbl_880453D8[];
extern char lbl_88045580[];
extern char lbl_880455E0[];
extern char lbl_880456EC[];
extern char lbl_88045734[];
extern char lbl_880457FC[];
extern char lbl_88045860[];
extern char lbl_8804589C[];
extern char lbl_88045914[];
extern char lbl_880459C0[];
extern char lbl_880459F8[];
extern char lbl_88045A30[];
extern char lbl_88045A70[];
extern char lbl_88045AA8[];
extern char lbl_88045AFC[];
extern char lbl_88045B24[];
extern char lbl_88045B44[];
extern char lbl_88045B88[];
extern char lbl_88045BCC[];
extern char lbl_88045C08[];
extern char lbl_88045C4C[];
extern char lbl_88045D00[];
extern char lbl_88045D4C[];
extern char lbl_88045D94[];
extern char lbl_88045DD8[];
extern char lbl_88045E10[];
extern char lbl_88045E48[];
extern char lbl_88045E90[];
extern char lbl_88045F18[];
extern char lbl_88045F4C[];
extern char lbl_88045F84[];
extern char lbl_88045FC0[];
extern char lbl_88045FF4[];
extern char lbl_88046098[];
extern char lbl_880460D0[];
extern char lbl_88046108[];
extern char lbl_88046144[];
extern char lbl_88046178[];
extern char lbl_880461A4[];
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
extern char lbl_8804E57C[];
extern char lbl_88054050[];
extern char lbl_88054068[];
extern char lbl_88056088[];
extern char lbl_880560CC[];
extern char lbl_88056108[];
extern char lbl_88056144[];
extern char lbl_88056158[];
extern char lbl_880561D0[];
extern char lbl_8805627C[];
extern char lbl_880563A0[];
extern char lbl_880563C8[];
extern char lbl_880563E0[];
extern char lbl_88056468[];
extern char lbl_88056520[];
extern char lbl_8805657C[];
extern char lbl_880565C0[];
extern char lbl_880565EC[];
extern char lbl_88056628[];
extern char lbl_8805664C[];
extern char lbl_88056680[];
extern char lbl_880566AC[];
extern char lbl_880566C0[];
extern char lbl_8805671C[];
extern char lbl_88056730[];
extern char lbl_88056794[];
extern char lbl_880567F8[];
extern char lbl_8805680C[];
extern char lbl_88056A08[];
extern char lbl_88056A60[];
extern char lbl_88B7138C[];
extern char lbl_88B71390[];
extern char lbl_88B71438[];
extern char lbl_88B71468[];
extern char lbl_88B71480[];
extern char lbl_88B714B0[];
extern char lbl_88B71574[];
extern char lbl_88B715A4[];
extern char lbl_88B715A8[];
extern char lbl_88B71668[];
extern char lbl_88B71680[];
extern char lbl_88B716B0[];
extern char lbl_88B716B4[];
extern char lbl_88B716D0[];
extern char lbl_88B71718[];
extern char lbl_88B71748[];
extern char lbl_88B71868[];
extern char lbl_88B718F8[];
extern char lbl_88B719B8[];
extern char lbl_88B71A90[];
extern char lbl_88B71B50[];
extern char lbl_88B71BF8[];
extern char lbl_88B71D18[];
extern char lbl_88B71D78[];
extern char lbl_88B71E80[];
extern char lbl_88B71F58[];
extern char lbl_88B71FA0[];
extern char lbl_88B71FB8[];
extern char lbl_88B72000[];
extern char lbl_88B72018[];
extern char lbl_88B72060[];
extern char lbl_88B720C0[];
extern char lbl_88B72108[];
extern char lbl_88B72168[];
extern char lbl_88B72198[];
extern char lbl_88B721B0[];
extern char lbl_88B721C8[];
extern char lbl_88B721E0[];
extern char lbl_88B72240[];
extern char lbl_88B72258[];
extern char lbl_88B72288[];
extern char lbl_88B722A0[];
extern char lbl_88B722D0[];
extern char lbl_88B722E8[];
extern char lbl_88B72300[];
extern char lbl_88B72318[];
extern char lbl_88B72360[];
extern char lbl_88B72390[];
extern char lbl_88B723C0[];
extern char lbl_88B72408[];
extern char lbl_88B72484[];
extern char lbl_88B72518[];
extern char lbl_88B72548[];
extern char lbl_88B72560[];
extern char lbl_88B7257C[];
extern char lbl_88B72580[];
extern char lbl_88B725F8[];
extern char lbl_88B72610[];
extern char lbl_88B72640[];
extern char lbl_88B72670[];
extern char lbl_88B726A0[];
extern char lbl_88B726E8[];
extern char lbl_88B72790[];
extern char lbl_88B727D8[];
extern char lbl_88B72838[];
extern char lbl_88B728C8[];
extern char lbl_88B728E0[];
extern char lbl_88B72910[];
extern char lbl_88B72958[];
extern char lbl_88B729A0[];
extern char lbl_88B729B8[];
extern char lbl_88B729EC[];
extern char lbl_88B72A1C[];
extern char lbl_88B72A34[];
extern char lbl_88B72A4C[];
extern char lbl_88B72A7C[];
extern char lbl_88B72AAC[];
extern char lbl_88B72ADC[];
extern char lbl_88B72AF4[];
extern char lbl_88B72B0C[];
extern char lbl_88B72B10[];
extern char lbl_88B72B58[];
extern char lbl_88B72BA0[];
extern char lbl_88B72BB8[];
extern char lbl_88B72BE8[];
extern char lbl_88B72C60[];
extern char lbl_88B72CF0[];
extern char lbl_88B72D50[];
extern char lbl_88B72DF8[];
extern char lbl_88B72E70[];
extern char lbl_88B72EB8[];
extern char lbl_88B72F48[];
extern char lbl_88B72FA8[];
extern char lbl_88B72FF0[];
extern char lbl_88B73020[];
extern char lbl_88B73050[];
extern char lbl_88B73068[];
extern char lbl_88B730C8[];
extern char lbl_88B730E0[];
extern char lbl_88B73110[];
extern char lbl_88B73128[];
extern char lbl_88B7312C[];
extern char lbl_88B73148[];
extern char lbl_88B73190[];
extern char lbl_88B731A8[];
extern char lbl_88B73208[];
extern char lbl_88B73214[];
extern char lbl_88B73244[];
extern char lbl_88B73260[];
extern char lbl_88B732A8[];
extern char lbl_88B732C4[];
extern char lbl_88B732C8[];
extern char lbl_88B73358[];
extern char lbl_88B73370[];
extern char lbl_88B733E8[];
extern char lbl_88B73418[];
extern char lbl_88B73438[];
extern char lbl_88B734E0[];
extern char lbl_88B734F8[];
extern char lbl_88B73528[];
extern char lbl_88B73540[];
extern char lbl_88B735E8[];
extern char lbl_88B73630[];
extern char lbl_88B73708[];
extern char lbl_88B73738[];
extern char lbl_88B73750[];
extern char lbl_88B73780[];
extern char lbl_88B73814[];
extern char lbl_88B73818[];
extern char lbl_88B73860[];
extern char lbl_88B73878[];
extern char lbl_88B73908[];
extern char lbl_88B739E0[];
extern char lbl_88B73A28[];
extern char lbl_88B73AA0[];
extern char lbl_88B73AD0[];
extern char lbl_88B73B48[];
extern char lbl_88B73B90[];
extern char lbl_88B73BC0[];
extern char lbl_88B73C20[];
extern char lbl_88B73C50[];
extern char lbl_88B73C98[];
extern char lbl_88B73CC8[];
extern char lbl_88B73CE0[];
extern char lbl_88B73E64[];
extern char lbl_88B73E94[];
extern char lbl_88B73E98[];
extern char lbl_88B73F40[];
extern char lbl_88B73F70[];
extern char lbl_88B73FA0[];
extern char lbl_88B73FB8[];
extern char lbl_88B73FE8[];
extern char lbl_88B74000[];
extern char lbl_88B74018[];
extern char lbl_88B740C4[];
extern char lbl_88B740C8[];
extern char lbl_88B740CC[];
extern char lbl_88B740D8[];
extern char lbl_88B74168[];
extern char lbl_88B74180[];
extern char lbl_88B74198[];
extern char lbl_88B741B0[];
extern char lbl_88B741F8[];
extern char lbl_88B74210[];
extern char lbl_88B74248[];
extern char lbl_88B75FA0[];
extern char lbl_88B76018[];
extern char lbl_88B76060[];
extern char lbl_88B760D8[];
extern char lbl_88B76210[];
extern char lbl_88B76228[];
extern char lbl_88B762D0[];
extern char lbl_88B76318[];
extern char lbl_88B763F0[];
extern char lbl_88B76468[];
extern char lbl_88B76480[];
extern char lbl_88B764F8[];
extern char lbl_88CCB114[];
extern char lbl_88CCB5F4[];
extern char lbl_88CCB624[];
extern char lbl_88CCB654[];
extern char lbl_88CCB684[];
extern char lbl_88CCB6B4[];
extern char lbl_88CCB6E4[];
extern char lbl_88CCB714[];
extern char lbl_88CCB744[];
extern char lbl_88CCB774[];
extern char lbl_88CCB7A4[];
extern char lbl_88CCB7D4[];
extern char lbl_88CCB804[];
extern char lbl_88CCB834[];
extern char lbl_88CCB864[];
extern char lbl_88CCB894[];
extern char lbl_88CCB8C4[];
extern char lbl_88CCB8F4[];
extern char lbl_88CCB924[];
extern char lbl_88CCB954[];
extern char lbl_88CCB984[];
extern char lbl_88CCB9B4[];
extern char lbl_88CCB9E4[];
extern char lbl_88CCBA14[];
extern char lbl_88CCBA44[];
extern char lbl_88CCBA74[];
extern char lbl_88CCBAA4[];
extern char lbl_88CCBAD4[];
extern char lbl_88CCBB04[];
extern char lbl_88CCBB34[];
extern char lbl_88CCBB64[];
extern char lbl_88CCBB94[];
extern char lbl_88CCBBC4[];
extern char lbl_88CCBBF4[];
extern char lbl_88CCBC24[];
extern char lbl_88CCBC54[];
extern char lbl_88CCBC84[];
extern char lbl_88CCBCB4[];
extern char lbl_88CCBCE4[];
extern char lbl_88CCBD14[];
extern char lbl_88CCBD44[];
extern char lbl_88CCBD74[];
extern char lbl_88CCBDA4[];
extern char lbl_88CCBDD4[];
extern char lbl_88CCBE04[];
extern char lbl_88CCBE34[];
extern char lbl_88CCBE64[];
extern char lbl_88CCBE94[];
extern char lbl_88CCBEC4[];
extern char lbl_88CCBEF4[];
extern char lbl_88CCBF24[];
extern char lbl_88CCBF54[];
extern char lbl_88CCBF84[];
extern char lbl_88CCBFB4[];
extern char lbl_88CCBFE4[];
extern char lbl_88CCC014[];
extern char lbl_88CCC044[];
extern char lbl_88CCC074[];
extern char lbl_88CCC0D4[];
extern char lbl_88CCC104[];
extern char lbl_88CCC134[];
extern char lbl_88CCC164[];
extern char lbl_88CCC194[];
extern char lbl_88CCC1C4[];
extern char lbl_88CCC1F4[];
extern char lbl_88CCC224[];
extern char lbl_88CCC254[];
extern char lbl_88CCC284[];
extern char lbl_88CCC2B4[];
extern char lbl_88CCC2E4[];
extern char lbl_88CCC314[];
extern char lbl_88CCC344[];
extern char lbl_88CCC374[];
extern char lbl_88CCC3A4[];
extern char lbl_88CCC3D4[];
extern char lbl_88CCC404[];
extern char lbl_88CCC434[];
extern char lbl_88CCC464[];
extern char lbl_88CCC494[];
extern char lbl_88CCC4C4[];
extern char lbl_88CCC4F4[];
extern char lbl_88CCC524[];
extern char lbl_88CCC554[];
extern char lbl_88CCC584[];
extern char lbl_88CCC5B4[];
extern char lbl_88CCC5E4[];
extern char lbl_88CCC614[];
extern char lbl_88CCC644[];
extern char lbl_88CCC674[];
extern char lbl_88CCC6A4[];
extern char lbl_88CCC6D4[];
extern char lbl_88CCC704[];
extern char lbl_88CCC734[];
extern char lbl_88CCC764[];
extern char lbl_88CCC794[];
extern char lbl_88CCC7C4[];
extern char lbl_88CCC7F4[];
extern char lbl_88CCC824[];
extern char lbl_88CCC854[];
extern char lbl_88CCC8B4[];
extern char lbl_88CCC8E4[];
extern char lbl_88CCC914[];
extern char lbl_88CCC944[];
extern char lbl_88CCC974[];
extern char lbl_88CCC9A4[];
extern char lbl_88CCC9D4[];
extern char lbl_88CCCA04[];
extern char lbl_88CCCA34[];
extern char lbl_88CCCA64[];
extern char lbl_88CCCA94[];
extern char lbl_88CCCAC4[];
extern char lbl_88CCCAF4[];
extern char lbl_88CCCB24[];
extern char lbl_88CCCB54[];
extern char lbl_88CCCB84[];
extern char lbl_88CCCBB4[];
extern char lbl_88CCCBE4[];
extern char lbl_88CCCC14[];
extern char lbl_88CCCC44[];
extern char lbl_88CCCC74[];
extern char lbl_88CCCCA4[];
extern char lbl_88CCCCD4[];
extern char lbl_88CCCD04[];
extern char lbl_88CCCD34[];
extern char lbl_88CCCD64[];
extern char lbl_88CCCD94[];
extern char lbl_88CCCDC4[];
extern char lbl_88CCCDF4[];
extern char lbl_88CCCE24[];
extern char lbl_88CCCE54[];
extern char lbl_88CCCE84[];
extern char lbl_88CCCEB4[];
extern char lbl_88CCCEE4[];
extern char lbl_88CCCF14[];
extern char lbl_88CCCF44[];
extern char lbl_88CCCF74[];
extern char lbl_88CCCFA4[];
extern char lbl_88CCCFD4[];
extern char lbl_88CCD004[];
extern char lbl_88CCD034[];
extern char lbl_88CCD064[];
extern char lbl_88CCD094[];
extern char lbl_88CCD0C4[];
extern char lbl_88CCD0F4[];
extern char lbl_88CCD124[];
extern char lbl_88CCD154[];
extern char lbl_88CCD184[];
extern char lbl_88CCD1B4[];
extern char lbl_88CCD1E4[];
extern char lbl_88CCD214[];
extern char lbl_88CCD244[];
extern char lbl_88CCD274[];
extern char lbl_88CCD2A4[];
extern char lbl_88CCD2D4[];
extern char lbl_88CCD304[];
extern char lbl_88CCD334[];
extern char lbl_88CCD364[];
extern char lbl_88CCD394[];
extern char lbl_88CCD3C4[];
extern char lbl_88CCD3F4[];
extern char lbl_88CCD424[];
extern char lbl_88CCD454[];
extern char lbl_88CCD484[];
extern char lbl_88CCD4B4[];
extern char lbl_88CCD4E4[];
extern char lbl_88CCD514[];
extern char lbl_88CCD544[];
extern char lbl_88CCD574[];
extern char lbl_88CCD5A4[];
extern char lbl_88CCD5D4[];
extern char lbl_88CCD604[];
extern char lbl_88CCD634[];
extern char lbl_88CCD664[];
extern char lbl_88CCD694[];
extern char lbl_88CCD6C4[];
extern char lbl_88CCD6F4[];
extern char lbl_88CCD724[];
extern char lbl_88CCD754[];
extern char lbl_88CCD784[];
extern char lbl_88CCD7B4[];
extern char lbl_88CCD7E4[];
extern char lbl_88CCD844[];
extern char lbl_88CCD874[];
extern char lbl_88CCD8A4[];
extern char lbl_88CCD8D4[];
extern char lbl_88CCD904[];
extern char lbl_88CCD934[];
extern char lbl_88CCD964[];
extern char lbl_88CCD994[];
ts4_word fn_8841F080();

/* Swing_DLL.xex 0x88A1D968: call_seq lbl_88B71390, lbl_8803F5C8, lbl_88CCB5F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71390_88A1D968(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB5F4, (ts4_word)(ts4_word)lbl_8803F5C8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71390, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D9D8: call_seq lbl_88B71438, lbl_88054050, lbl_88CCB624, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71438_88A1D9D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB624, (ts4_word)(ts4_word)lbl_88054050, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71438, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1DA48: call_seq lbl_88B71468, lbl_88054068, lbl_88CCB654, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71468_88A1DA48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB654, (ts4_word)(ts4_word)lbl_88054068, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71468, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1DAB8: call_seq lbl_88B71480, lbl_8804C310, lbl_88CCB684, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71480_88A1DAB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB684, (ts4_word)(ts4_word)lbl_8804C310, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71480, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1DB28: call_seq lbl_88B714B0, lbl_8803ED20, lbl_88CCB6B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B714B0_88A1DB28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB6B4, (ts4_word)(ts4_word)lbl_8803ED20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B714B0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1DB98: addr lbl_88B75FA0, u32@lbl_88B7138C, u32@0x8 */
void ts4_addr_lbl_88B75FA0_88A1DB98(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B75FA0) + 8) = (ts4_word)(*(ts4_word *)lbl_88B7138C);
    return;
}

/* Swing_DLL.xex 0x88A1DBB0: call_seq lbl_88B75FA0, lbl_8804C33C, lbl_88CCB6E4, lbl_88056088, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B75FA0_88A1DBB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB6E4, (ts4_word)(ts4_word)lbl_8804C33C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88056088, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B75FA0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1DC20: call_seq lbl_88B71574, lbl_8803ED28, lbl_88CCB714, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71574_88A1DC20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB714, (ts4_word)(ts4_word)lbl_8803ED28, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71574, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1DC90: call_seq lbl_88B715A8, lbl_8803ED14, lbl_88CCB744, lbl_880560CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B715A8_88A1DC90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB744, (ts4_word)(ts4_word)lbl_8803ED14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880560CC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B715A8, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1DD00: addr lbl_88B76018, u32@lbl_88B715A4, u32@0x20 */
void ts4_addr_lbl_88B76018_88A1DD00(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B76018) + 32) = (ts4_word)(*(ts4_word *)lbl_88B715A4);
    return;
}

/* Swing_DLL.xex 0x88A1DD18: call_seq lbl_88B76018, lbl_8804E57C, lbl_88CCB774, lbl_88056108, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76018_88A1DD18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB774, (ts4_word)(ts4_word)lbl_8804E57C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88056108, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B76018, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1DD88: call_seq lbl_88B71668, lbl_8804C348, lbl_88CCB7A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71668_88A1DD88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB7A4, (ts4_word)(ts4_word)lbl_8804C348, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71668, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1DDF8: call_seq lbl_88B71680, lbl_8804C358, lbl_88CCB7D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71680_88A1DDF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB7D4, (ts4_word)(ts4_word)lbl_8804C358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71680, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1DE68: addr lbl_88B76060, u32@lbl_88B716B0, u32@0x8 */
void ts4_addr_lbl_88B76060_88A1DE68(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B76060) + 8) = (ts4_word)(*(ts4_word *)lbl_88B716B0);
    return;
}

/* Swing_DLL.xex 0x88A1DE80: call_seq lbl_88B76060, lbl_8804C380, lbl_88CCB804, lbl_88056144, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76060_88A1DE80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB804, (ts4_word)(ts4_word)lbl_8804C380, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88056144, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B76060, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1DEF0: call_seq lbl_88B716B4, lbl_88042408, lbl_88CCB834, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B716B4_88A1DEF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB834, (ts4_word)(ts4_word)lbl_88042408, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B716B4, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1DF60: call_seq lbl_88B716D0, lbl_880423F8, lbl_88CCB864, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B716D0_88A1DF60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB864, (ts4_word)(ts4_word)lbl_880423F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B716D0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1DFD0: call_seq lbl_88B71718, lbl_8804C390, lbl_88CCB894, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71718_88A1DFD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB894, (ts4_word)(ts4_word)lbl_8804C390, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71718, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E040: call_seq lbl_88B71748, lbl_8804C3A0, lbl_88CCB8C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71748_88A1E040(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB8C4, (ts4_word)(ts4_word)lbl_8804C3A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71748, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E0B0: call_seq lbl_88B71868, lbl_8804C3B0, lbl_88CCB8F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71868_88A1E0B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB8F4, (ts4_word)(ts4_word)lbl_8804C3B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71868, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E120: call_seq lbl_88B718F8, lbl_8804C3C4, lbl_88CCB924, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B718F8_88A1E120(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB924, (ts4_word)(ts4_word)lbl_8804C3C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B718F8, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E190: call_seq lbl_88B719B8, lbl_8804C3DC, lbl_88CCB954, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B719B8_88A1E190(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB954, (ts4_word)(ts4_word)lbl_8804C3DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B719B8, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E200: call_seq lbl_88B71A90, lbl_8804C3F8, lbl_88CCB984, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71A90_88A1E200(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB984, (ts4_word)(ts4_word)lbl_8804C3F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71A90, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E270: call_seq lbl_88B71B50, lbl_8804C410, lbl_88CCB9B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71B50_88A1E270(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB9B4, (ts4_word)(ts4_word)lbl_8804C410, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71B50, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E2E0: call_seq lbl_88B71BF8, lbl_88056158, lbl_8803F5BC, lbl_88CCB9E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71BF8_88A1E2E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB9E4, (ts4_word)(ts4_word)lbl_8803F5BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71BF8, (ts4_word)12, (ts4_word)(ts4_word)lbl_88056158, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E358: call_seq lbl_88B71D18, lbl_8804C428, lbl_88CCBA14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71D18_88A1E358(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBA14, (ts4_word)(ts4_word)lbl_8804C428, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71D18, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E3C8: call_seq lbl_88B71D78, lbl_8803F5E0, lbl_88CCBA44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71D78_88A1E3C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBA44, (ts4_word)(ts4_word)lbl_8803F5E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71D78, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E438: call_seq lbl_88B71E80, lbl_88040278, lbl_88CCBA74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71E80_88A1E438(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBA74, (ts4_word)(ts4_word)lbl_88040278, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71E80, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E4A8: call_seq lbl_88B71F58, lbl_8803ED58, lbl_88CCBAA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71F58_88A1E4A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBAA4, (ts4_word)(ts4_word)lbl_8803ED58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71F58, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E518: call_seq lbl_88B71FA0, lbl_8803ED40, lbl_88CCBAD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71FA0_88A1E518(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBAD4, (ts4_word)(ts4_word)lbl_8803ED40, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71FA0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E588: call_seq lbl_88B71FB8, lbl_880433FC, lbl_88CCBB04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71FB8_88A1E588(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBB04, (ts4_word)(ts4_word)lbl_880433FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71FB8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E5F8: call_seq lbl_88B72000, lbl_8804342C, lbl_88CCBB34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72000_88A1E5F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBB34, (ts4_word)(ts4_word)lbl_8804342C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72000, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E668: call_seq lbl_88B72018, lbl_88CCB114, lbl_8803ED7C, lbl_88CCBB64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72018_88A1E668(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBB64, (ts4_word)(ts4_word)lbl_8803ED7C, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72018, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E6E0: call_seq lbl_88B72060, lbl_88046454, lbl_88CCBB94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72060_88A1E6E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBB94, (ts4_word)(ts4_word)lbl_88046454, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72060, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E750: call_seq lbl_88B720C0, lbl_88CCBB94, lbl_8804233C, lbl_88CCBBC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B720C0_88A1E750(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBBC4, (ts4_word)(ts4_word)lbl_8804233C, (ts4_word)(ts4_word)lbl_88CCBB94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B720C0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E7C8: call_seq lbl_880469C4, lbl_88CCBBF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880469C4_88A1E7C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBBF4, (ts4_word)(ts4_word)lbl_880469C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E828: call_seq lbl_88B72108, lbl_88CCD8D4, lbl_88042E48, lbl_88CCBC24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72108_88A1E828(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBC24, (ts4_word)(ts4_word)lbl_88042E48, (ts4_word)(ts4_word)lbl_88CCD8D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72108, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E8A0: call_seq lbl_88046B60, lbl_88CCBC54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046B60_88A1E8A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBC54, (ts4_word)(ts4_word)lbl_88046B60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E900: call_seq lbl_88CCB114, lbl_88042318, lbl_88CCBC84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCB114_88A1E900(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBC84, (ts4_word)(ts4_word)lbl_88042318, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E968: call_seq lbl_88046A84, lbl_88CCBCB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A84_88A1E968(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBCB4, (ts4_word)(ts4_word)lbl_88046A84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1E9C8: call_seq lbl_88B72168, lbl_88CCBC84, lbl_8804232C, lbl_88CCBCE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72168_88A1E9C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBCE4, (ts4_word)(ts4_word)lbl_8804232C, (ts4_word)(ts4_word)lbl_88CCBC84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72168, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1EA40: call_seq lbl_88B72198, lbl_88CCBC84, lbl_8804690C, lbl_88CCBD14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72198_88A1EA40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBD14, (ts4_word)(ts4_word)lbl_8804690C, (ts4_word)(ts4_word)lbl_88CCBC84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72198, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1EAB8: call_seq lbl_88CCBC84, lbl_8804671C, lbl_88CCBD44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCBC84_88A1EAB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBD44, (ts4_word)(ts4_word)lbl_8804671C, (ts4_word)(ts4_word)lbl_88CCBC84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1EB20: call_seq lbl_88046A50, lbl_88CCBD74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A50_88A1EB20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBD74, (ts4_word)(ts4_word)lbl_88046A50, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1EB80: call_seq lbl_88B721B0, lbl_88CCB114, lbl_88041284, lbl_88CCBDA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B721B0_88A1EB80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBDA4, (ts4_word)(ts4_word)lbl_88041284, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B721B0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1EBF8: call_seq lbl_88046994, lbl_88CCBDD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046994_88A1EBF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBDD4, (ts4_word)(ts4_word)lbl_88046994, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1EC58: call_seq lbl_88B721C8, lbl_88CCBDD4, lbl_88046678, lbl_88CCBE04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B721C8_88A1EC58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBE04, (ts4_word)(ts4_word)lbl_88046678, (ts4_word)(ts4_word)lbl_88CCBDD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B721C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1ECD0: call_seq lbl_88B721E0, lbl_88046220, lbl_88CCBE34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B721E0_88A1ECD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBE34, (ts4_word)(ts4_word)lbl_88046220, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B721E0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1ED40: call_seq lbl_88B72240, lbl_88CCBF54, lbl_8804694C, lbl_88CCBE64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72240_88A1ED40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBE64, (ts4_word)(ts4_word)lbl_8804694C, (ts4_word)(ts4_word)lbl_88CCBF54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72240, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1EDB8: call_seq lbl_88B72258, lbl_88CCBDA4, lbl_88040110, lbl_88CCBE94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72258_88A1EDB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBE94, (ts4_word)(ts4_word)lbl_88040110, (ts4_word)(ts4_word)lbl_88CCBDA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72258, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1EE30: call_seq lbl_88B72288, lbl_88CCBDA4, lbl_88040100, lbl_88CCBEC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72288_88A1EE30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBEC4, (ts4_word)(ts4_word)lbl_88040100, (ts4_word)(ts4_word)lbl_88CCBDA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72288, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1EEA8: call_seq lbl_88B722A0, lbl_88CCBF54, lbl_8804011C, lbl_88CCBEF4, lbl_880561D0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B722A0_88A1EEA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBEF4, (ts4_word)(ts4_word)lbl_8804011C, (ts4_word)(ts4_word)lbl_88CCBF54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880561D0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B722A0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1EF20: call_seq lbl_88B722D0, lbl_88CCBDA4, lbl_880400A8, lbl_88CCBF24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B722D0_88A1EF20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBF24, (ts4_word)(ts4_word)lbl_880400A8, (ts4_word)(ts4_word)lbl_88CCBDA4, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B722D0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1EF98: call_seq lbl_88B722E8, lbl_88CCC404, lbl_88042370, lbl_88CCBF54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B722E8_88A1EF98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBF54, (ts4_word)(ts4_word)lbl_88042370, (ts4_word)(ts4_word)lbl_88CCC404, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B722E8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F010: call_seq lbl_88B72300, lbl_88CCC164, lbl_88041B24, lbl_88CCBF84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72300_88A1F010(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBF84, (ts4_word)(ts4_word)lbl_88041B24, (ts4_word)(ts4_word)lbl_88CCC164, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72300, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F088: call_seq lbl_88B72318, lbl_88CCBF24, lbl_880468C8, lbl_88CCBFB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72318_88A1F088(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBFB4, (ts4_word)(ts4_word)lbl_880468C8, (ts4_word)(ts4_word)lbl_88CCBF24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72318, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F100: call_seq lbl_88B72360, lbl_88CCBF54, lbl_880400E8, lbl_88CCBFE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72360_88A1F100(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCBFE4, (ts4_word)(ts4_word)lbl_880400E8, (ts4_word)(ts4_word)lbl_88CCBF54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72360, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F178: call_seq lbl_88B72390, lbl_88CCBF54, lbl_880400D0, lbl_88CCC014, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72390_88A1F178(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC014, (ts4_word)(ts4_word)lbl_880400D0, (ts4_word)(ts4_word)lbl_88CCBF54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72390, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F1F0: call_seq lbl_88B723C0, lbl_880463D4, lbl_88CCC044, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B723C0_88A1F1F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC044, (ts4_word)(ts4_word)lbl_880463D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B723C0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F260: call_seq lbl_88B72408, lbl_88CCBF54, lbl_88046868, lbl_88CCC074, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72408_88A1F260(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC074, (ts4_word)(ts4_word)lbl_88046868, (ts4_word)(ts4_word)lbl_88CCBF54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72408, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F350: call_seq lbl_88CCC1F4, lbl_880467DC, lbl_88CCC0D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCC1F4_88A1F350(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC0D4, (ts4_word)(ts4_word)lbl_880467DC, (ts4_word)(ts4_word)lbl_88CCC1F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F3B8: call_seq lbl_88CCBDA4, lbl_88046AE0, lbl_88CCC104, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCBDA4_88A1F3B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC104, (ts4_word)(ts4_word)lbl_88046AE0, (ts4_word)(ts4_word)lbl_88CCBDA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F420: call_seq lbl_88B72518, lbl_88042358, lbl_88CCC134, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72518_88A1F420(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC134, (ts4_word)(ts4_word)lbl_88042358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72518, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F490: call_seq lbl_88B72548, lbl_88CCBF24, lbl_8804234C, lbl_88CCC164, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72548_88A1F490(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC164, (ts4_word)(ts4_word)lbl_8804234C, (ts4_word)(ts4_word)lbl_88CCBF24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72548, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F508: call_seq lbl_88B72560, lbl_88046320, lbl_88CCC194, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72560_88A1F508(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC194, (ts4_word)(ts4_word)lbl_88046320, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72560, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F578: addr lbl_88B760D8, u32@lbl_88B72484, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88B760D8_88A1F578(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B72484;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B760D8) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B760D8) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A1F598: call_seq lbl_88B760D8, lbl_8803EFE8, lbl_88CCC1C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B760D8_88A1F598(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC1C4, (ts4_word)(ts4_word)lbl_8803EFE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B760D8, (ts4_word)13, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F608: call_seq lbl_88B72580, lbl_88CCBF24, lbl_8803EF9C, lbl_88CCC1F4, lbl_8805627C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72580_88A1F608(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC1F4, (ts4_word)(ts4_word)lbl_8803EF9C, (ts4_word)(ts4_word)lbl_88CCBF24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805627C, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B72580, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F680: call_seq lbl_88B725F8, lbl_88CCBEC4, lbl_880423C0, lbl_88CCC224, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B725F8_88A1F680(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC224, (ts4_word)(ts4_word)lbl_880423C0, (ts4_word)(ts4_word)lbl_88CCBEC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B725F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F6F8: call_seq lbl_88B72610, lbl_880462E8, lbl_88CCC254, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72610_88A1F6F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC254, (ts4_word)(ts4_word)lbl_880462E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72610, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F768: call_seq lbl_88B72640, lbl_88CCBDA4, lbl_8804675C, lbl_88CCC284, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72640_88A1F768(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC284, (ts4_word)(ts4_word)lbl_8804675C, (ts4_word)(ts4_word)lbl_88CCBDA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72640, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F7E0: call_seq lbl_88B72670, lbl_88CCC404, lbl_8803F9D4, lbl_88CCC2B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72670_88A1F7E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC2B4, (ts4_word)(ts4_word)lbl_8803F9D4, (ts4_word)(ts4_word)lbl_88CCC404, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72670, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F858: call_seq lbl_88CCBDA4, lbl_88046AB4, lbl_88CCC2E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCBDA4_88A1F858(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC2E4, (ts4_word)(ts4_word)lbl_88046AB4, (ts4_word)(ts4_word)lbl_88CCBDA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F8C0: call_seq lbl_88B726A0, lbl_88CCC104, lbl_880466D4, lbl_88CCC314, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B726A0_88A1F8C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC314, (ts4_word)(ts4_word)lbl_880466D4, (ts4_word)(ts4_word)lbl_88CCC104, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B726A0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F938: call_seq lbl_88B726E8, lbl_88CCC104, lbl_88046A18, lbl_88CCC344, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B726E8_88A1F938(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC344, (ts4_word)(ts4_word)lbl_88046A18, (ts4_word)(ts4_word)lbl_88CCC104, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B726E8, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1F9B0: call_seq lbl_88B72790, lbl_880423A4, lbl_88CCC374, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72790_88A1F9B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC374, (ts4_word)(ts4_word)lbl_880423A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72790, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1FA20: call_seq lbl_88B727D8, lbl_88CCBF24, lbl_88042390, lbl_88CCC3A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B727D8_88A1FA20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC3A4, (ts4_word)(ts4_word)lbl_88042390, (ts4_word)(ts4_word)lbl_88CCBF24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B727D8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1FA98: call_seq lbl_88CCBF54, lbl_88043ED0, lbl_88CCC3D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCBF54_88A1FA98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC3D4, (ts4_word)(ts4_word)lbl_88043ED0, (ts4_word)(ts4_word)lbl_88CCBF54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1FB00: call_seq lbl_88CCBDA4, lbl_8804696C, lbl_88CCC404, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCBDA4_88A1FB00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC404, (ts4_word)(ts4_word)lbl_8804696C, (ts4_word)(ts4_word)lbl_88CCBDA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1FB68: call_seq lbl_88B72838, lbl_88CCB114, lbl_8803F00C, lbl_88CCC434, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72838_88A1FB68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC434, (ts4_word)(ts4_word)lbl_8803F00C, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72838, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1FBE0: call_seq lbl_88B728C8, lbl_88CCC1F4, lbl_88046574, lbl_88CCC464, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B728C8_88A1FBE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC464, (ts4_word)(ts4_word)lbl_88046574, (ts4_word)(ts4_word)lbl_88CCC1F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B728C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1FC58: call_seq lbl_88B728E0, lbl_88CCC344, lbl_88046518, lbl_88CCC494, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B728E0_88A1FC58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC494, (ts4_word)(ts4_word)lbl_88046518, (ts4_word)(ts4_word)lbl_88CCC344, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B728E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1FCD0: call_seq lbl_88B72910, lbl_88CCBDA4, lbl_880400BC, lbl_88CCC4C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72910_88A1FCD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC4C4, (ts4_word)(ts4_word)lbl_880400BC, (ts4_word)(ts4_word)lbl_88CCBDA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72910, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1FD48: call_seq lbl_88B72958, lbl_88CCBF54, lbl_88042380, lbl_88CCC4F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72958_88A1FD48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC4F4, (ts4_word)(ts4_word)lbl_88042380, (ts4_word)(ts4_word)lbl_88CCBF54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72958, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1FDC0: call_seq lbl_88B729A0, lbl_88CCBEC4, lbl_880423D4, lbl_88CCC524, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B729A0_88A1FDC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC524, (ts4_word)(ts4_word)lbl_880423D4, (ts4_word)(ts4_word)lbl_88CCBEC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B729A0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1FE38: call_seq lbl_88B729B8, lbl_88CCBF24, lbl_88046498, lbl_88CCC554, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B729B8_88A1FE38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC554, (ts4_word)(ts4_word)lbl_88046498, (ts4_word)(ts4_word)lbl_88CCBF24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B729B8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1FEB0: addr lbl_88B76210, u32@lbl_88B7257C, u32@0x8 */
void ts4_addr_lbl_88B76210_88A1FEB0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B76210) + 8) = (ts4_word)(*(ts4_word *)lbl_88B7257C);
    return;
}

/* Swing_DLL.xex 0x88A1FEC8: call_seq lbl_88B76210, lbl_8804215C, lbl_88CCC584, lbl_880563A0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76210_88A1FEC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)(ts4_word)lbl_8804215C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880563A0, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B76210, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1FF38: call_seq lbl_88B729EC, lbl_88CCC584, lbl_88041B0C, lbl_88CCC5B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B729EC_88A1FF38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC5B4, (ts4_word)(ts4_word)lbl_88041B0C, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B729EC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1FFB0: call_seq lbl_88B72A1C, lbl_88041AFC, lbl_88CCC5E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72A1C_88A1FFB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC5E4, (ts4_word)(ts4_word)lbl_88041AFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72A1C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20020: call_seq lbl_88CCC584, lbl_88046098, lbl_88CCC614, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCC584_88A20020(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC614, (ts4_word)(ts4_word)lbl_88046098, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20088: call_seq lbl_88B72A34, lbl_88CCC584, lbl_88045C08, lbl_88CCC644, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72A34_88A20088(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC644, (ts4_word)(ts4_word)lbl_88045C08, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72A34, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20100: call_seq lbl_88B72A4C, lbl_88CCC584, lbl_88045D4C, lbl_88CCC674, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72A4C_88A20100(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC674, (ts4_word)(ts4_word)lbl_88045D4C, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72A4C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20178: call_seq lbl_88B72A7C, lbl_88CCC584, lbl_88045D00, lbl_88CCC6A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72A7C_88A20178(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC6A4, (ts4_word)(ts4_word)lbl_88045D00, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72A7C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A201F0: call_seq lbl_88B72AAC, lbl_88CCC584, lbl_88045D94, lbl_88CCC6D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72AAC_88A201F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC6D4, (ts4_word)(ts4_word)lbl_88045D94, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72AAC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20268: call_seq lbl_88B72ADC, lbl_88CCC584, lbl_88045E48, lbl_88CCC704, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72ADC_88A20268(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC704, (ts4_word)(ts4_word)lbl_88045E48, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72ADC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A202E0: call_seq lbl_88B72AF4, lbl_88CCC584, lbl_88045FF4, lbl_88CCC734, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72AF4_88A202E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC734, (ts4_word)(ts4_word)lbl_88045FF4, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72AF4, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20358: call_seq lbl_88B72B10, lbl_88CCC584, lbl_88045F18, lbl_88CCC764, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72B10_88A20358(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC764, (ts4_word)(ts4_word)lbl_88045F18, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72B10, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A203D0: call_seq lbl_88B72B58, lbl_88CCC584, lbl_88045F84, lbl_88CCC794, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72B58_88A203D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC794, (ts4_word)(ts4_word)lbl_88045F84, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72B58, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20448: call_seq lbl_88B72BA0, lbl_88CCC584, lbl_880461A4, lbl_88CCC7C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72BA0_88A20448(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC7C4, (ts4_word)(ts4_word)lbl_880461A4, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72BA0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A204C0: call_seq lbl_88B72BB8, lbl_88CCC584, lbl_88046178, lbl_88CCC7F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72BB8_88A204C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC7F4, (ts4_word)(ts4_word)lbl_88046178, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72BB8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20538: call_seq lbl_880563C8, lbl_88B72BE8, lbl_88CCC584, lbl_88046108, lbl_88CCC824, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880563C8_88A20538(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC824, (ts4_word)(ts4_word)lbl_88046108, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72BE8, (ts4_word)5, (ts4_word)(ts4_word)lbl_880563C8, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A205B0: call_seq lbl_880563E0, lbl_88B72C60, lbl_88CCC584, lbl_88045BCC, lbl_88CCC854, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880563E0_88A205B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC854, (ts4_word)(ts4_word)lbl_88045BCC, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72C60, (ts4_word)6, (ts4_word)(ts4_word)lbl_880563E0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20628: addr lbl_88B76228, u32@lbl_88B72B0C, u32@0x50 */
void ts4_addr_lbl_88B76228_88A20628(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B76228) + 80) = (ts4_word)(*(ts4_word *)lbl_88B72B0C);
    return;
}

/* Swing_DLL.xex 0x88A206B8: call_seq lbl_88B72CF0, lbl_88CCC584, lbl_88046144, lbl_88CCC8B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72CF0_88A206B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC8B4, (ts4_word)(ts4_word)lbl_88046144, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72CF0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20730: call_seq lbl_88B72D50, lbl_88CCC584, lbl_880460D0, lbl_88CCC8E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72D50_88A20730(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC8E4, (ts4_word)(ts4_word)lbl_880460D0, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72D50, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A207A8: call_seq lbl_88B72DF8, lbl_88CCC584, lbl_88045DD8, lbl_88CCC914, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72DF8_88A207A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC914, (ts4_word)(ts4_word)lbl_88045DD8, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72DF8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20820: call_seq lbl_88B72E70, lbl_88CCC584, lbl_88045FC0, lbl_88CCC944, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72E70_88A20820(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC944, (ts4_word)(ts4_word)lbl_88045FC0, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72E70, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20898: call_seq lbl_88B72EB8, lbl_88CCC584, lbl_88045F4C, lbl_88CCC974, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72EB8_88A20898(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC974, (ts4_word)(ts4_word)lbl_88045F4C, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72EB8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20910: call_seq lbl_88B72F48, lbl_88CCC584, lbl_88045E10, lbl_88CCC9A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72F48_88A20910(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC9A4, (ts4_word)(ts4_word)lbl_88045E10, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72F48, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20988: call_seq lbl_88B72FA8, lbl_88CCC584, lbl_880422DC, lbl_88CCC9D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72FA8_88A20988(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCC9D4, (ts4_word)(ts4_word)lbl_880422DC, (ts4_word)(ts4_word)lbl_88CCC584, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72FA8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20A00: call_seq lbl_88B72FF0, lbl_88CCC9D4, lbl_88045C4C, lbl_88CCCA04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B72FF0_88A20A00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCA04, (ts4_word)(ts4_word)lbl_88045C4C, (ts4_word)(ts4_word)lbl_88CCC9D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B72FF0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20A78: call_seq lbl_88B73020, lbl_88CCC9D4, lbl_88043EE0, lbl_88CCCA34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73020_88A20A78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCA34, (ts4_word)(ts4_word)lbl_88043EE0, (ts4_word)(ts4_word)lbl_88CCC9D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73020, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20AF0: call_seq lbl_88CCC9D4, lbl_88045B88, lbl_88CCCA64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCC9D4_88A20AF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCA64, (ts4_word)(ts4_word)lbl_88045B88, (ts4_word)(ts4_word)lbl_88CCC9D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20B58: call_seq lbl_88B73050, lbl_88CCC9D4, lbl_88045E90, lbl_88CCCA94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73050_88A20B58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCA94, (ts4_word)(ts4_word)lbl_88045E90, (ts4_word)(ts4_word)lbl_88CCC9D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73050, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20BD0: call_seq lbl_88B73068, lbl_88CCB114, lbl_88047050, lbl_88CCCAC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73068_88A20BD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCAC4, (ts4_word)(ts4_word)lbl_88047050, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73068, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20C48: call_seq lbl_88B730C8, lbl_88CCCAC4, lbl_88045B44, lbl_88CCCAF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B730C8_88A20C48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCAF4, (ts4_word)(ts4_word)lbl_88045B44, (ts4_word)(ts4_word)lbl_88CCCAC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B730C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20CC0: call_seq lbl_88B730E0, lbl_88CCCAC4, lbl_88045B24, lbl_88CCCB24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B730E0_88A20CC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCB24, (ts4_word)(ts4_word)lbl_88045B24, (ts4_word)(ts4_word)lbl_88CCCAC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B730E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20D38: call_seq lbl_88B73110, lbl_88CCCAC4, lbl_880459C0, lbl_88CCCB54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73110_88A20D38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCB54, (ts4_word)(ts4_word)lbl_880459C0, (ts4_word)(ts4_word)lbl_88CCCAC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73110, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20DB0: addr lbl_88B762D0, u32@lbl_88B73128, u32@0x8 */
void ts4_addr_lbl_88B762D0_88A20DB0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B762D0) + 8) = (ts4_word)(*(ts4_word *)lbl_88B73128);
    return;
}

/* Swing_DLL.xex 0x88A20DC8: call_seq lbl_88B762D0, lbl_88045224, lbl_88CCCB84, lbl_88056468, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B762D0_88A20DC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCB84, (ts4_word)(ts4_word)lbl_88045224, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88056468, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B762D0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20E38: call_seq lbl_88B7312C, lbl_88045194, lbl_88CCCBB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7312C_88A20E38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCBB4, (ts4_word)(ts4_word)lbl_88045194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7312C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20EA8: call_seq lbl_88B73148, lbl_8803EF90, lbl_88CCCBE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73148_88A20EA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCBE4, (ts4_word)(ts4_word)lbl_8803EF90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73148, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20F18: call_seq lbl_88B73190, lbl_88CCB114, lbl_8803FA04, lbl_88CCCC14, lbl_88056520, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73190_88A20F18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCC14, (ts4_word)(ts4_word)lbl_8803FA04, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88056520, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B73190, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20F88: call_seq lbl_88B731A8, lbl_88042170, lbl_88CCCC44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B731A8_88A20F88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCC44, (ts4_word)(ts4_word)lbl_88042170, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B731A8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A20FF8: addr lbl_88B76318, u32@lbl_88B73208, u32@0x68 */
void ts4_addr_lbl_88B76318_88A20FF8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B76318) + 104) = (ts4_word)(*(ts4_word *)lbl_88B73208);
    return;
}

/* Swing_DLL.xex 0x88A21010: call_seq lbl_88B76318, lbl_88CCB114, lbl_8803F0C8, lbl_88CCCC74, lbl_8805657C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76318_88A21010(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCC74, (ts4_word)(ts4_word)lbl_8803F0C8, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805657C, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B76318, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21088: call_seq lbl_88B73214, lbl_880422B8, lbl_88CCCCA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73214_88A21088(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCCA4, (ts4_word)(ts4_word)lbl_880422B8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73214, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A210F8: call_seq lbl_88B73244, lbl_88CCCC14, lbl_880403DC, lbl_88CCCCD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73244_88A210F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCCD4, (ts4_word)(ts4_word)lbl_880403DC, (ts4_word)(ts4_word)lbl_88CCCC14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73244, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21170: call_seq lbl_88B73260, lbl_8804229C, lbl_88CCCD04, lbl_880565C0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73260_88A21170(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCD04, (ts4_word)(ts4_word)lbl_8804229C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880565C0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B73260, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A211E0: call_seq lbl_88B732A8, lbl_88CCCC14, lbl_88040394, lbl_88CCCD34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B732A8_88A211E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCD34, (ts4_word)(ts4_word)lbl_88040394, (ts4_word)(ts4_word)lbl_88CCCC14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B732A8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21258: call_seq lbl_88B732C8, lbl_88042260, lbl_88CCCD64, lbl_880565EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B732C8_88A21258(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCD64, (ts4_word)(ts4_word)lbl_88042260, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880565EC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B732C8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A212C8: call_seq lbl_88B73358, lbl_88CCCC14, lbl_8803F690, lbl_88CCCD94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73358_88A212C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCD94, (ts4_word)(ts4_word)lbl_8803F690, (ts4_word)(ts4_word)lbl_88CCCC14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73358, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21340: call_seq lbl_88B73370, lbl_88CCCDF4, lbl_88045734, lbl_88CCCDC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73370_88A21340(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCDC4, (ts4_word)(ts4_word)lbl_88045734, (ts4_word)(ts4_word)lbl_88CCCDF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73370, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A213B8: call_seq lbl_88CCB114, lbl_88045A30, lbl_88CCCDF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCB114_88A213B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCDF4, (ts4_word)(ts4_word)lbl_88045A30, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21420: addr lbl_88B763F0, u32@lbl_88B732C4, u32@0x50 */
void ts4_addr_lbl_88B763F0_88A21420(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B763F0) + 80) = (ts4_word)(*(ts4_word *)lbl_88B732C4);
    return;
}

/* Swing_DLL.xex 0x88A21438: call_seq lbl_88B763F0, lbl_88CCCC14, lbl_88040364, lbl_88CCCE24, lbl_88056628, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B763F0_88A21438(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCE24, (ts4_word)(ts4_word)lbl_88040364, (ts4_word)(ts4_word)lbl_88CCCC14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88056628, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B763F0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A214B0: call_seq lbl_88B733E8, lbl_8804223C, lbl_88CCCE54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B733E8_88A214B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCE54, (ts4_word)(ts4_word)lbl_8804223C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B733E8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21520: call_seq lbl_88B73418, lbl_88CCCC14, lbl_88040344, lbl_88CCCE84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73418_88A21520(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCE84, (ts4_word)(ts4_word)lbl_88040344, (ts4_word)(ts4_word)lbl_88CCCC14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73418, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21598: call_seq lbl_88B73438, lbl_8804221C, lbl_88CCCEB4, lbl_8805664C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73438_88A21598(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCEB4, (ts4_word)(ts4_word)lbl_8804221C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805664C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B73438, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21608: call_seq lbl_88B734E0, lbl_88CCCC14, lbl_8803F048, lbl_88CCCEE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B734E0_88A21608(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCEE4, (ts4_word)(ts4_word)lbl_8803F048, (ts4_word)(ts4_word)lbl_88CCCC14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B734E0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21680: call_seq lbl_88B734F8, lbl_880421A0, lbl_88CCCF14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B734F8_88A21680(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCF14, (ts4_word)(ts4_word)lbl_880421A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B734F8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A216F0: call_seq lbl_88B73528, lbl_88CCCC14, lbl_880402E4, lbl_88CCCF44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73528_88A216F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCF44, (ts4_word)(ts4_word)lbl_880402E4, (ts4_word)(ts4_word)lbl_88CCCC14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73528, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21768: call_seq lbl_88B73540, lbl_88042184, lbl_88CCCF74, lbl_88056680, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73540_88A21768(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCF74, (ts4_word)(ts4_word)lbl_88042184, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88056680, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B73540, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A217D8: call_seq lbl_88B735E8, lbl_88CCCC14, lbl_880402CC, lbl_88CCCFA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B735E8_88A217D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCFA4, (ts4_word)(ts4_word)lbl_880402CC, (ts4_word)(ts4_word)lbl_88CCCC14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B735E8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21850: call_seq lbl_88B73630, lbl_88CCCC14, lbl_8803F6B0, lbl_88CCCFD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73630_88A21850(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCCFD4, (ts4_word)(ts4_word)lbl_8803F6B0, (ts4_word)(ts4_word)lbl_88CCCC14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73630, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A218C8: call_seq lbl_88CCCC14, lbl_88045AFC, lbl_88CCD004, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCCC14_88A218C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD004, (ts4_word)(ts4_word)lbl_88045AFC, (ts4_word)(ts4_word)lbl_88CCCC14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21930: call_seq lbl_88B73708, lbl_88CCCC74, lbl_8804589C, lbl_88CCD034, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73708_88A21930(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD034, (ts4_word)(ts4_word)lbl_8804589C, (ts4_word)(ts4_word)lbl_88CCCC74, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73708, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A219A8: call_seq lbl_88B73738, lbl_88CCCAC4, lbl_88045860, lbl_88CCD064, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73738_88A219A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD064, (ts4_word)(ts4_word)lbl_88045860, (ts4_word)(ts4_word)lbl_88CCCAC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73738, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21A20: call_seq lbl_88B73750, lbl_880453D8, lbl_88CCD094, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73750_88A21A20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD094, (ts4_word)(ts4_word)lbl_880453D8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73750, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21A90: call_seq lbl_88B73780, lbl_88CCD004, lbl_880403C4, lbl_88CCD0C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73780_88A21A90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD0C4, (ts4_word)(ts4_word)lbl_880403C4, (ts4_word)(ts4_word)lbl_88CCD004, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73780, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21B08: call_seq lbl_88B73818, lbl_88042284, lbl_88CCD0F4, lbl_880566AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73818_88A21B08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD0F4, (ts4_word)(ts4_word)lbl_88042284, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880566AC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B73818, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21B78: call_seq lbl_88B73860, lbl_88CCCC14, lbl_88040380, lbl_88CCD124, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73860_88A21B78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD124, (ts4_word)(ts4_word)lbl_88040380, (ts4_word)(ts4_word)lbl_88CCCC14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73860, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21BF0: call_seq lbl_88B73878, lbl_8803FC48, lbl_88CCD154, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73878_88A21BF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD154, (ts4_word)(ts4_word)lbl_8803FC48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73878, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21C60: call_seq lbl_880566C0, lbl_88B73908, lbl_88CCD004, lbl_8803FC6C, lbl_88CCD184, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880566C0_88A21C60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD184, (ts4_word)(ts4_word)lbl_8803FC6C, (ts4_word)(ts4_word)lbl_88CCD004, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73908, (ts4_word)9, (ts4_word)(ts4_word)lbl_880566C0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21CD8: call_seq lbl_88B739E0, lbl_88045020, lbl_88CCD1B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B739E0_88A21CD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD1B4, (ts4_word)(ts4_word)lbl_88045020, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B739E0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21D48: call_seq lbl_88B73A28, lbl_88CCD004, lbl_88040300, lbl_88CCD1E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73A28_88A21D48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD1E4, (ts4_word)(ts4_word)lbl_88040300, (ts4_word)(ts4_word)lbl_88CCD004, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73A28, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21DC0: call_seq lbl_88B73AA0, lbl_88CCCC14, lbl_880403AC, lbl_88CCD214, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73AA0_88A21DC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD214, (ts4_word)(ts4_word)lbl_880403AC, (ts4_word)(ts4_word)lbl_88CCCC14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73AA0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21E38: call_seq lbl_88B73AD0, lbl_880422F8, lbl_88CCD244, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73AD0_88A21E38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD244, (ts4_word)(ts4_word)lbl_880422F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73AD0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21EA8: call_seq lbl_88B73B48, lbl_88CCCC14, lbl_8803FA18, lbl_88CCD274, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73B48_88A21EA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD274, (ts4_word)(ts4_word)lbl_8803FA18, (ts4_word)(ts4_word)lbl_88CCCC14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73B48, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21F20: addr lbl_88B76468, u32@lbl_88B73814, u32@0x8 */
void ts4_addr_lbl_88B76468_88A21F20(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B76468) + 8) = (ts4_word)(*(ts4_word *)lbl_88B73814);
    return;
}

/* Swing_DLL.xex 0x88A21F38: call_seq lbl_88B76468, lbl_88CCB114, lbl_8803FBE0, lbl_88CCD2A4, lbl_8805671C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76468_88A21F38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD2A4, (ts4_word)(ts4_word)lbl_8803FBE0, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805671C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B76468, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A21FA8: call_seq lbl_88B73B90, lbl_88CCD2A4, lbl_88045A70, lbl_88CCD2D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73B90_88A21FA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD2D4, (ts4_word)(ts4_word)lbl_88045A70, (ts4_word)(ts4_word)lbl_88CCD2A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73B90, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22020: call_seq lbl_88B73BC0, lbl_88CCD2D4, lbl_8803FCA0, lbl_88CCD304, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73BC0_88A22020(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD304, (ts4_word)(ts4_word)lbl_8803FCA0, (ts4_word)(ts4_word)lbl_88CCD2D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73BC0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22098: call_seq lbl_88B73C20, lbl_88CCD2D4, lbl_8803FC80, lbl_88CCD334, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73C20_88A22098(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD334, (ts4_word)(ts4_word)lbl_8803FC80, (ts4_word)(ts4_word)lbl_88CCD2D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73C20, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22110: call_seq lbl_88B73C50, lbl_88CCD2D4, lbl_8803F9E8, lbl_88CCD364, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73C50_88A22110(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD364, (ts4_word)(ts4_word)lbl_8803F9E8, (ts4_word)(ts4_word)lbl_88CCD2D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73C50, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22188: call_seq lbl_88B73C98, lbl_88042200, lbl_88CCD394, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73C98_88A22188(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD394, (ts4_word)(ts4_word)lbl_88042200, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73C98, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A221F8: call_seq lbl_88B73CC8, lbl_88CCCC14, lbl_8804032C, lbl_88CCD3C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73CC8_88A221F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD3C4, (ts4_word)(ts4_word)lbl_8804032C, (ts4_word)(ts4_word)lbl_88CCCC14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73CC8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22270: call_seq lbl_88056730, lbl_88B73CE0, lbl_88CCD844, lbl_8803F6CC, lbl_88CCD3F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88056730_88A22270(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD3F4, (ts4_word)(ts4_word)lbl_8803F6CC, (ts4_word)(ts4_word)lbl_88CCD844, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73CE0, (ts4_word)16, (ts4_word)(ts4_word)lbl_88056730, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A222E8: call_seq lbl_88CCB114, lbl_88045AA8, lbl_88CCD424, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCB114_88A222E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD424, (ts4_word)(ts4_word)lbl_88045AA8, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22350: call_seq lbl_88CCD4B4, lbl_880457FC, lbl_88CCD454, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCD4B4_88A22350(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD454, (ts4_word)(ts4_word)lbl_880457FC, (ts4_word)(ts4_word)lbl_88CCD4B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A223B8: call_seq lbl_88CCD3F4, lbl_880455E0, lbl_88CCD484, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCD3F4_88A223B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD484, (ts4_word)(ts4_word)lbl_880455E0, (ts4_word)(ts4_word)lbl_88CCD3F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22420: call_seq lbl_88056794, lbl_88CCD424, lbl_880459F8, lbl_88CCD4B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88056794_88A22420(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD4B4, (ts4_word)(ts4_word)lbl_880459F8, (ts4_word)(ts4_word)lbl_88CCD424, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88056794, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22488: call_seq lbl_88B73E64, lbl_88045070, lbl_88CCD4E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73E64_88A22488(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD4E4, (ts4_word)(ts4_word)lbl_88045070, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73E64, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A224F8: call_seq lbl_88B73E98, lbl_88CCD4B4, lbl_88041DE0, lbl_88CCD514, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73E98_88A224F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD514, (ts4_word)(ts4_word)lbl_88041DE0, (ts4_word)(ts4_word)lbl_88CCD4B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73E98, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22570: addr lbl_88B76480, u32@lbl_88B73E94, u32@0x8 */
void ts4_addr_lbl_88B76480_88A22570(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B76480) + 8) = (ts4_word)(*(ts4_word *)lbl_88B73E94);
    return;
}

/* Swing_DLL.xex 0x88A22588: call_seq lbl_88B76480, lbl_88CCB114, lbl_8803F5D4, lbl_88CCD544, lbl_880567F8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B76480_88A22588(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD544, (ts4_word)(ts4_word)lbl_8803F5D4, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880567F8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B76480, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22600: call_seq lbl_88CCD544, lbl_880402B0, lbl_88CCD574, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCD544_88A22600(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD574, (ts4_word)(ts4_word)lbl_880402B0, (ts4_word)(ts4_word)lbl_88CCD544, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22668: call_seq lbl_88CCD5D4, lbl_88040E04, lbl_88CCD5A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCD5D4_88A22668(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD5A4, (ts4_word)(ts4_word)lbl_88040E04, (ts4_word)(ts4_word)lbl_88CCD5D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A226D0: call_seq lbl_88B73F40, lbl_88CCD544, lbl_8803EFA8, lbl_88CCD5D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73F40_88A226D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD5D4, (ts4_word)(ts4_word)lbl_8803EFA8, (ts4_word)(ts4_word)lbl_88CCD544, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73F40, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22748: call_seq lbl_88CCD5D4, lbl_880456EC, lbl_88CCD604, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCD5D4_88A22748(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD604, (ts4_word)(ts4_word)lbl_880456EC, (ts4_word)(ts4_word)lbl_88CCD5D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A227B0: call_seq lbl_88CCD544, lbl_880402A0, lbl_88CCD634, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCD544_88A227B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD634, (ts4_word)(ts4_word)lbl_880402A0, (ts4_word)(ts4_word)lbl_88CCD544, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22818: call_seq lbl_88CCD574, lbl_88040E18, lbl_88CCD664, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCD574_88A22818(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD664, (ts4_word)(ts4_word)lbl_88040E18, (ts4_word)(ts4_word)lbl_88CCD574, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22880: call_seq lbl_88CCD634, lbl_88040E68, lbl_88CCD694, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCD634_88A22880(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD694, (ts4_word)(ts4_word)lbl_88040E68, (ts4_word)(ts4_word)lbl_88CCD634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A228E8: call_seq lbl_88CCD574, lbl_88040DB0, lbl_88CCD6C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCD574_88A228E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD6C4, (ts4_word)(ts4_word)lbl_88040DB0, (ts4_word)(ts4_word)lbl_88CCD574, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22950: call_seq lbl_88B73F70, lbl_88CCD754, lbl_8803F6D8, lbl_88CCD6F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73F70_88A22950(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD6F4, (ts4_word)(ts4_word)lbl_8803F6D8, (ts4_word)(ts4_word)lbl_88CCD754, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73F70, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A229C8: call_seq lbl_88B73FA0, lbl_88CCD784, lbl_88045914, lbl_88CCD724, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73FA0_88A229C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD724, (ts4_word)(ts4_word)lbl_88045914, (ts4_word)(ts4_word)lbl_88CCD784, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73FA0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22A40: call_seq lbl_88B73FB8, lbl_88CCD844, lbl_88047070, lbl_88CCD754, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73FB8_88A22A40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD754, (ts4_word)(ts4_word)lbl_88047070, (ts4_word)(ts4_word)lbl_88CCD844, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73FB8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22AB8: call_seq lbl_88B73FE8, lbl_88CCD754, lbl_880402BC, lbl_88CCD784, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B73FE8_88A22AB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD784, (ts4_word)(ts4_word)lbl_880402BC, (ts4_word)(ts4_word)lbl_88CCD754, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B73FE8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22B30: call_seq lbl_88B74000, lbl_88CCD784, lbl_88045580, lbl_88CCD7B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74000_88A22B30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD7B4, (ts4_word)(ts4_word)lbl_88045580, (ts4_word)(ts4_word)lbl_88CCD784, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74000, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22BA8: call_seq lbl_8805680C, lbl_88B74018, lbl_88CCB114, lbl_8803F660, lbl_88CCD7E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805680C_88A22BA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD7E4, (ts4_word)(ts4_word)lbl_8803F660, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74018, (ts4_word)7, (ts4_word)(ts4_word)lbl_8805680C, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22C20: get u32@lbl_88B740CC, lbl_88B764F8, u32@lbl_88B740C8, u32@lbl_88B740C4, u32@0x50, u32@0x110 */
void ts4_get_u32_lbl_88B740CC_88A22C20(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88B740CC;
    t2 = *(ts4_word *)lbl_88B740C8;
    t3 = *(ts4_word *)lbl_88B740C4;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B764F8) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B764F8) + 272) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B764F8) + 560) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x88A22CC8: call_seq lbl_88B740D8, lbl_88CCB114, lbl_8803F084, lbl_88CCD844, lbl_88056A08, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B740D8_88A22CC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD844, (ts4_word)(ts4_word)lbl_8803F084, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88056A08, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B740D8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22D40: call_seq lbl_88B74168, lbl_88CCB114, lbl_8804707C, lbl_88CCD874, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74168_88A22D40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD874, (ts4_word)(ts4_word)lbl_8804707C, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74168, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22DB8: call_seq lbl_88B74180, lbl_88CCBBC4, lbl_88044F38, lbl_88CCD8A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74180_88A22DB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD8A4, (ts4_word)(ts4_word)lbl_88044F38, (ts4_word)(ts4_word)lbl_88CCBBC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74180, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22E30: call_seq lbl_88B74198, lbl_88042E20, lbl_88CCD8D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74198_88A22E30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD8D4, (ts4_word)(ts4_word)lbl_88042E20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74198, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22EA0: call_seq lbl_88B741B0, lbl_88CCB114, lbl_8803EFD0, lbl_88CCD904, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B741B0_88A22EA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD904, (ts4_word)(ts4_word)lbl_8803EFD0, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B741B0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22F18: call_seq lbl_88B741F8, lbl_88044F10, lbl_88CCD934, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B741F8_88A22F18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD934, (ts4_word)(ts4_word)lbl_88044F10, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B741F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A22F88: call_seq lbl_88B74210, lbl_88CCB114, lbl_88044F90, lbl_88CCD964, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74210_88A22F88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD964, (ts4_word)(ts4_word)lbl_88044F90, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B74210, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A23000: call_seq lbl_88B74248, lbl_880421E0, lbl_88CCD994, lbl_88056A60, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B74248_88A23000(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCD994, (ts4_word)(ts4_word)lbl_880421E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88056A60, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B74248, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}
