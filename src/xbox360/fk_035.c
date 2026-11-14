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
extern char lbl_8803EFC0[];
extern char lbl_8803EFD0[];
extern char lbl_8803EFE8[];
extern char lbl_8803F00C[];
extern char lbl_8803F030[];
extern char lbl_8803F048[];
extern char lbl_8803F064[];
extern char lbl_8803F084[];
extern char lbl_8803F094[];
extern char lbl_8803F0AC[];
extern char lbl_8803F0C8[];
extern char lbl_8803F5BC[];
extern char lbl_8803F5C8[];
extern char lbl_8803F5D4[];
extern char lbl_8803F5E0[];
extern char lbl_8803F660[];
extern char lbl_8803F670[];
extern char lbl_8803F690[];
extern char lbl_8803F6B0[];
extern char lbl_8803F6CC[];
extern char lbl_8803F6D8[];
extern char lbl_8803F9C0[];
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
extern char lbl_88040290[];
extern char lbl_880402A0[];
extern char lbl_880402B0[];
extern char lbl_880402BC[];
extern char lbl_880402CC[];
extern char lbl_880402E4[];
extern char lbl_88040300[];
extern char lbl_88040318[];
extern char lbl_8804032C[];
extern char lbl_88040344[];
extern char lbl_88040364[];
extern char lbl_88040380[];
extern char lbl_88040394[];
extern char lbl_880403AC[];
extern char lbl_880403C4[];
extern char lbl_880403DC[];
extern char lbl_880403FC[];
extern char lbl_88040424[];
extern char lbl_8804044C[];
extern char lbl_88040470[];
extern char lbl_88040494[];
extern char lbl_880404B8[];
extern char lbl_880404E0[];
extern char lbl_88040508[];
extern char lbl_88040534[];
extern char lbl_88040560[];
extern char lbl_88040590[];
extern char lbl_880405C0[];
extern char lbl_880405E4[];
extern char lbl_88040608[];
extern char lbl_88040630[];
extern char lbl_88040668[];
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
extern char lbl_88042E20[];
extern char lbl_88042E48[];
extern char lbl_880433FC[];
extern char lbl_8804342C[];
extern char lbl_88043ED0[];
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
extern char lbl_88045194[];
extern char lbl_88045224[];
extern char lbl_880453D8[];
extern char lbl_88045580[];
extern char lbl_880455E0[];
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
extern char lbl_88047050[];
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
extern char lbl_8804C428[];
extern char lbl_8804E57C[];
extern char lbl_8804FAD0[];
extern char lbl_8804FB14[];
extern char lbl_8804FB50[];
extern char lbl_8804FB8C[];
extern char lbl_8804FBA0[];
extern char lbl_8804FC28[];
extern char lbl_8804FC7C[];
extern char lbl_8804FCCC[];
extern char lbl_8804FD98[];
extern char lbl_8804FDF4[];
extern char lbl_8804FE30[];
extern char lbl_8804FE74[];
extern char lbl_8804FEB0[];
extern char lbl_8804FEC8[];
extern char lbl_8804FF34[];
extern char lbl_8804FF98[];
extern char lbl_8804FFC4[];
extern char lbl_880501A0[];
extern char lbl_880501B4[];
extern char lbl_88B51E48[];
extern char lbl_88B51EF0[];
extern char lbl_88B51F20[];
extern char lbl_88B51FE0[];
extern char lbl_88B51FE8[];
extern char lbl_88B52018[];
extern char lbl_88B520D8[];
extern char lbl_88B520DC[];
extern char lbl_88B520F4[];
extern char lbl_88B52124[];
extern char lbl_88B52128[];
extern char lbl_88B52140[];
extern char lbl_88B52188[];
extern char lbl_88B521B8[];
extern char lbl_88B522D8[];
extern char lbl_88B52368[];
extern char lbl_88B52428[];
extern char lbl_88B52500[];
extern char lbl_88B525C0[];
extern char lbl_88B52668[];
extern char lbl_88B52788[];
extern char lbl_88B527E8[];
extern char lbl_88B528F0[];
extern char lbl_88B529C8[];
extern char lbl_88B529F8[];
extern char lbl_88B52A10[];
extern char lbl_88B52A58[];
extern char lbl_88B52A70[];
extern char lbl_88B52AB8[];
extern char lbl_88B52B18[];
extern char lbl_88B52B60[];
extern char lbl_88B52BC0[];
extern char lbl_88B52BF0[];
extern char lbl_88B52C08[];
extern char lbl_88B52C20[];
extern char lbl_88B52C80[];
extern char lbl_88B52C98[];
extern char lbl_88B52CC8[];
extern char lbl_88B52CE0[];
extern char lbl_88B52D10[];
extern char lbl_88B52D28[];
extern char lbl_88B52D40[];
extern char lbl_88B52D58[];
extern char lbl_88B52DA0[];
extern char lbl_88B52DD0[];
extern char lbl_88B52E00[];
extern char lbl_88B52E48[];
extern char lbl_88B52EC4[];
extern char lbl_88B52EC8[];
extern char lbl_88B52F40[];
extern char lbl_88B52F70[];
extern char lbl_88B52F88[];
extern char lbl_88B52FA4[];
extern char lbl_88B52FA8[];
extern char lbl_88B53008[];
extern char lbl_88B53020[];
extern char lbl_88B53050[];
extern char lbl_88B53080[];
extern char lbl_88B530B0[];
extern char lbl_88B530F8[];
extern char lbl_88B531A0[];
extern char lbl_88B531E8[];
extern char lbl_88B53248[];
extern char lbl_88B532D8[];
extern char lbl_88B532F0[];
extern char lbl_88B53320[];
extern char lbl_88B53368[];
extern char lbl_88B533B0[];
extern char lbl_88B533C8[];
extern char lbl_88B533F8[];
extern char lbl_88B53458[];
extern char lbl_88B53470[];
extern char lbl_88B534A0[];
extern char lbl_88B534B8[];
extern char lbl_88B534D0[];
extern char lbl_88B5351C[];
extern char lbl_88B53534[];
extern char lbl_88B53538[];
extern char lbl_88B535A0[];
extern char lbl_88B535B8[];
extern char lbl_88B535E8[];
extern char lbl_88B53630[];
extern char lbl_88B53660[];
extern char lbl_88B53690[];
extern char lbl_88B536F0[];
extern char lbl_88B53738[];
extern char lbl_88B537C8[];
extern char lbl_88B53840[];
extern char lbl_88B53848[];
extern char lbl_88B53890[];
extern char lbl_88B538F0[];
extern char lbl_88B53938[];
extern char lbl_88B53980[];
extern char lbl_88B53A28[];
extern char lbl_88B53A70[];
extern char lbl_88B53AA0[];
extern char lbl_88B53B30[];
extern char lbl_88B53BC0[];
extern char lbl_88B53C80[];
extern char lbl_88B53CB0[];
extern char lbl_88B53CC8[];
extern char lbl_88B53CF8[];
extern char lbl_88B53D70[];
extern char lbl_88B53DB8[];
extern char lbl_88B53DE8[];
extern char lbl_88B53E78[];
extern char lbl_88B53F08[];
extern char lbl_88B53F80[];
extern char lbl_88B53FC8[];
extern char lbl_88B54028[];
extern char lbl_88B54040[];
extern char lbl_88B540B8[];
extern char lbl_88B540E8[];
extern char lbl_88B54118[];
extern char lbl_88B54178[];
extern char lbl_88B541A8[];
extern char lbl_88B541F0[];
extern char lbl_88B54280[];
extern char lbl_88B54434[];
extern char lbl_88B54468[];
extern char lbl_88B54510[];
extern char lbl_88B54528[];
extern char lbl_88B54540[];
extern char lbl_88B54570[];
extern char lbl_88B54618[];
extern char lbl_88B54648[];
extern char lbl_88B54660[];
extern char lbl_88B54690[];
extern char lbl_88B546A8[];
extern char lbl_88B546C4[];
extern char lbl_88B546F8[];
extern char lbl_88B54788[];
extern char lbl_88B5478C[];
extern char lbl_88B54790[];
extern char lbl_88B54798[];
extern char lbl_88B54810[];
extern char lbl_88B54828[];
extern char lbl_88B54840[];
extern char lbl_88B54858[];
extern char lbl_88B548A0[];
extern char lbl_88B548B8[];
extern char lbl_88B548E8[];
extern char lbl_88B54960[];
extern char lbl_88B549A8[];
extern char lbl_88B549F0[];
extern char lbl_88B54AC8[];
extern char lbl_88B54AF8[];
extern char lbl_88B54B28[];
extern char lbl_88B54C00[];
extern char lbl_88B54C48[];
extern char lbl_88B54CA8[];
extern char lbl_88B54D08[];
extern char lbl_88B54D68[];
extern char lbl_88B54E28[];
extern char lbl_88B54FC0[];
extern char lbl_88B54FD8[];
extern char lbl_88B54FF0[];
extern char lbl_88B55020[];
extern char lbl_88B55050[];
extern char lbl_88B55068[];
extern char lbl_88B55098[];
extern char lbl_88B550E0[];
extern char lbl_88B55128[];
extern char lbl_88B551B8[];
extern char lbl_88B55200[];
extern char lbl_88B55230[];
extern char lbl_88B55260[];
extern char lbl_88B55290[];
extern char lbl_88B552A8[];
extern char lbl_88B552C0[];
extern char lbl_88B552F0[];
extern char lbl_88B55308[];
extern char lbl_88B563B8[];
extern char lbl_88B56430[];
extern char lbl_88B56478[];
extern char lbl_88B564F0[];
extern char lbl_88B56628[];
extern char lbl_88B56670[];
extern char lbl_88B56730[];
extern char lbl_88B56790[];
extern char lbl_88CB933C[];
extern char lbl_88CB97EC[];
extern char lbl_88CB981C[];
extern char lbl_88CB984C[];
extern char lbl_88CB987C[];
extern char lbl_88CB98AC[];
extern char lbl_88CB98DC[];
extern char lbl_88CB990C[];
extern char lbl_88CB993C[];
extern char lbl_88CB996C[];
extern char lbl_88CB999C[];
extern char lbl_88CB99CC[];
extern char lbl_88CB99FC[];
extern char lbl_88CB9A2C[];
extern char lbl_88CB9A5C[];
extern char lbl_88CB9A8C[];
extern char lbl_88CB9ABC[];
extern char lbl_88CB9AEC[];
extern char lbl_88CB9B1C[];
extern char lbl_88CB9B4C[];
extern char lbl_88CB9B7C[];
extern char lbl_88CB9BAC[];
extern char lbl_88CB9BDC[];
extern char lbl_88CB9C0C[];
extern char lbl_88CB9C3C[];
extern char lbl_88CB9C6C[];
extern char lbl_88CB9C9C[];
extern char lbl_88CB9CCC[];
extern char lbl_88CB9CFC[];
extern char lbl_88CB9D2C[];
extern char lbl_88CB9D5C[];
extern char lbl_88CB9D8C[];
extern char lbl_88CB9DBC[];
extern char lbl_88CB9DEC[];
extern char lbl_88CB9E1C[];
extern char lbl_88CB9E4C[];
extern char lbl_88CB9E7C[];
extern char lbl_88CB9EAC[];
extern char lbl_88CB9EDC[];
extern char lbl_88CB9F0C[];
extern char lbl_88CB9F3C[];
extern char lbl_88CB9F6C[];
extern char lbl_88CB9F9C[];
extern char lbl_88CB9FCC[];
extern char lbl_88CB9FFC[];
extern char lbl_88CBA02C[];
extern char lbl_88CBA05C[];
extern char lbl_88CBA08C[];
extern char lbl_88CBA0BC[];
extern char lbl_88CBA0EC[];
extern char lbl_88CBA11C[];
extern char lbl_88CBA14C[];
extern char lbl_88CBA17C[];
extern char lbl_88CBA1AC[];
extern char lbl_88CBA1DC[];
extern char lbl_88CBA20C[];
extern char lbl_88CBA23C[];
extern char lbl_88CBA26C[];
extern char lbl_88CBA29C[];
extern char lbl_88CBA2CC[];
extern char lbl_88CBA2FC[];
extern char lbl_88CBA32C[];
extern char lbl_88CBA35C[];
extern char lbl_88CBA38C[];
extern char lbl_88CBA3BC[];
extern char lbl_88CBA3EC[];
extern char lbl_88CBA41C[];
extern char lbl_88CBA44C[];
extern char lbl_88CBA47C[];
extern char lbl_88CBA4AC[];
extern char lbl_88CBA4DC[];
extern char lbl_88CBA50C[];
extern char lbl_88CBA53C[];
extern char lbl_88CBA56C[];
extern char lbl_88CBA59C[];
extern char lbl_88CBA5CC[];
extern char lbl_88CBA5FC[];
extern char lbl_88CBA62C[];
extern char lbl_88CBA65C[];
extern char lbl_88CBA68C[];
extern char lbl_88CBA6BC[];
extern char lbl_88CBA6EC[];
extern char lbl_88CBA71C[];
extern char lbl_88CBA74C[];
extern char lbl_88CBA77C[];
extern char lbl_88CBA7AC[];
extern char lbl_88CBA7DC[];
extern char lbl_88CBA80C[];
extern char lbl_88CBA83C[];
extern char lbl_88CBA86C[];
extern char lbl_88CBA89C[];
extern char lbl_88CBA8CC[];
extern char lbl_88CBA8FC[];
extern char lbl_88CBA92C[];
extern char lbl_88CBA95C[];
extern char lbl_88CBA98C[];
extern char lbl_88CBA9BC[];
extern char lbl_88CBA9EC[];
extern char lbl_88CBAA1C[];
extern char lbl_88CBAA4C[];
extern char lbl_88CBAA7C[];
extern char lbl_88CBAAAC[];
extern char lbl_88CBAADC[];
extern char lbl_88CBAB0C[];
extern char lbl_88CBAB3C[];
extern char lbl_88CBAB6C[];
extern char lbl_88CBAB9C[];
extern char lbl_88CBABCC[];
extern char lbl_88CBABFC[];
extern char lbl_88CBAC2C[];
extern char lbl_88CBAC5C[];
extern char lbl_88CBAC8C[];
extern char lbl_88CBACBC[];
extern char lbl_88CBACEC[];
extern char lbl_88CBAD1C[];
extern char lbl_88CBAD4C[];
extern char lbl_88CBAD7C[];
extern char lbl_88CBADAC[];
extern char lbl_88CBADDC[];
extern char lbl_88CBAE0C[];
extern char lbl_88CBAE3C[];
extern char lbl_88CBAE6C[];
extern char lbl_88CBAE9C[];
extern char lbl_88CBAECC[];
extern char lbl_88CBAEFC[];
extern char lbl_88CBAF2C[];
extern char lbl_88CBAF5C[];
extern char lbl_88CBAF8C[];
extern char lbl_88CBAFBC[];
extern char lbl_88CBAFEC[];
extern char lbl_88CBB01C[];
extern char lbl_88CBB04C[];
extern char lbl_88CBB07C[];
extern char lbl_88CBB0AC[];
extern char lbl_88CBB0DC[];
extern char lbl_88CBB10C[];
extern char lbl_88CBB13C[];
extern char lbl_88CBB16C[];
extern char lbl_88CBB19C[];
extern char lbl_88CBB1CC[];
extern char lbl_88CBB1FC[];
extern char lbl_88CBB22C[];
extern char lbl_88CBB25C[];
extern char lbl_88CBB28C[];
extern char lbl_88CBB2BC[];
extern char lbl_88CBB2EC[];
extern char lbl_88CBB31C[];
extern char lbl_88CBB34C[];
extern char lbl_88CBB37C[];
extern char lbl_88CBB3AC[];
extern char lbl_88CBB3DC[];
extern char lbl_88CBB40C[];
extern char lbl_88CBB43C[];
extern char lbl_88CBB46C[];
extern char lbl_88CBB49C[];
extern char lbl_88CBB4FC[];
extern char lbl_88CBB52C[];
extern char lbl_88CBB55C[];
extern char lbl_88CBB58C[];
extern char lbl_88CBB5BC[];
extern char lbl_88CBB5EC[];
extern char lbl_88CBB61C[];
extern char lbl_88CBB64C[];
extern char lbl_88CBB67C[];
extern char lbl_88CBB6AC[];
extern char lbl_88CBB6DC[];
extern char lbl_88CBB70C[];
extern char lbl_88CBB73C[];
extern char lbl_88CBB76C[];
extern char lbl_88CBB79C[];
extern char lbl_88CBB7CC[];
extern char lbl_88CBB7FC[];
extern char lbl_88CBB82C[];
extern char lbl_88CBB85C[];
extern char lbl_88CBB88C[];
extern char lbl_88CBB8BC[];
extern char lbl_88CBB8EC[];
extern char lbl_88CBB91C[];
extern char lbl_88CBB94C[];
extern char lbl_88CBB97C[];
extern char lbl_88CBB9AC[];
extern char lbl_88CBB9DC[];
extern char lbl_88CBBA0C[];
extern char lbl_88CBBA3C[];
extern char lbl_88CBBA6C[];
extern char lbl_88CBBA9C[];
extern char lbl_88CBBACC[];
extern char lbl_88CBBAFC[];
extern char lbl_88CBBB2C[];
extern char lbl_88CBBB5C[];
extern char lbl_88CBBB8C[];
extern char lbl_88CBBBBC[];
extern char lbl_88CBBBEC[];
ts4_word fn_8841F080();

/* Swing_DLL.xex 0x889F2528: call_seq lbl_88B51E48, lbl_8803F5C8, lbl_88CB97EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51E48_889F2528(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB97EC, (ts4_word)(ts4_word)lbl_8803F5C8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51E48, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2598: call_seq lbl_88B51EF0, lbl_8804C310, lbl_88CB981C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51EF0_889F2598(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB981C, (ts4_word)(ts4_word)lbl_8804C310, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51EF0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2608: call_seq lbl_88B51F20, lbl_8803ED20, lbl_88CB984C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51F20_889F2608(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB984C, (ts4_word)(ts4_word)lbl_8803ED20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51F20, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2678: addr lbl_88B563B8, u32@lbl_88B51FE0, u32@0x8 */
void ts4_addr_lbl_88B563B8_889F2678(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B563B8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B51FE0);
    return;
}

/* Swing_DLL.xex 0x889F2690: call_seq lbl_88B563B8, lbl_8804C33C, lbl_88CB987C, lbl_8804FAD0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B563B8_889F2690(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB987C, (ts4_word)(ts4_word)lbl_8804C33C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804FAD0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B563B8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2700: call_seq lbl_88B51FE8, lbl_8803ED28, lbl_88CB98AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51FE8_889F2700(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB98AC, (ts4_word)(ts4_word)lbl_8803ED28, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51FE8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2770: call_seq lbl_88B52018, lbl_8803ED14, lbl_88CB98DC, lbl_8804FB14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52018_889F2770(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB98DC, (ts4_word)(ts4_word)lbl_8803ED14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804FB14, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B52018, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F27E0: addr lbl_88B56430, u32@lbl_88B520D8, u32@0x20 */
void ts4_addr_lbl_88B56430_889F27E0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B56430) + 32) = (ts4_word)(*(ts4_word *)lbl_88B520D8);
    return;
}

/* Swing_DLL.xex 0x889F27F8: call_seq lbl_88B56430, lbl_8804E57C, lbl_88CB990C, lbl_8804FB50, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56430_889F27F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB990C, (ts4_word)(ts4_word)lbl_8804E57C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804FB50, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B56430, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2868: call_seq lbl_88B520DC, lbl_8804C348, lbl_88CB993C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B520DC_889F2868(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB993C, (ts4_word)(ts4_word)lbl_8804C348, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B520DC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F28D8: call_seq lbl_88B520F4, lbl_8804C358, lbl_88CB996C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B520F4_889F28D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB996C, (ts4_word)(ts4_word)lbl_8804C358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B520F4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2948: addr lbl_88B56478, u32@lbl_88B52124, u32@0x8 */
void ts4_addr_lbl_88B56478_889F2948(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B56478) + 8) = (ts4_word)(*(ts4_word *)lbl_88B52124);
    return;
}

/* Swing_DLL.xex 0x889F2960: call_seq lbl_88B56478, lbl_8804C380, lbl_88CB999C, lbl_8804FB8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56478_889F2960(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB999C, (ts4_word)(ts4_word)lbl_8804C380, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804FB8C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B56478, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F29D0: call_seq lbl_88B52128, lbl_88042408, lbl_88CB99CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52128_889F29D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB99CC, (ts4_word)(ts4_word)lbl_88042408, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52128, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2A40: call_seq lbl_88B52140, lbl_880423F8, lbl_88CB99FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52140_889F2A40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB99FC, (ts4_word)(ts4_word)lbl_880423F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52140, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2AB0: call_seq lbl_88B52188, lbl_8804C390, lbl_88CB9A2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52188_889F2AB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9A2C, (ts4_word)(ts4_word)lbl_8804C390, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52188, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2B20: call_seq lbl_88B521B8, lbl_8804C3A0, lbl_88CB9A5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B521B8_889F2B20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9A5C, (ts4_word)(ts4_word)lbl_8804C3A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B521B8, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2B90: call_seq lbl_88B522D8, lbl_8804C3B0, lbl_88CB9A8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B522D8_889F2B90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9A8C, (ts4_word)(ts4_word)lbl_8804C3B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B522D8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2C00: call_seq lbl_88B52368, lbl_8804C3C4, lbl_88CB9ABC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52368_889F2C00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9ABC, (ts4_word)(ts4_word)lbl_8804C3C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52368, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2C70: call_seq lbl_88B52428, lbl_8804C3DC, lbl_88CB9AEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52428_889F2C70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9AEC, (ts4_word)(ts4_word)lbl_8804C3DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52428, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2CE0: call_seq lbl_88B52500, lbl_8804C3F8, lbl_88CB9B1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52500_889F2CE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9B1C, (ts4_word)(ts4_word)lbl_8804C3F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52500, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2D50: call_seq lbl_88B525C0, lbl_8804C410, lbl_88CB9B4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B525C0_889F2D50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9B4C, (ts4_word)(ts4_word)lbl_8804C410, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B525C0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2DC0: call_seq lbl_88B52668, lbl_8804FBA0, lbl_8803F5BC, lbl_88CB9B7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52668_889F2DC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9B7C, (ts4_word)(ts4_word)lbl_8803F5BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52668, (ts4_word)12, (ts4_word)(ts4_word)lbl_8804FBA0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2E38: call_seq lbl_88B52788, lbl_8804C428, lbl_88CB9BAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52788_889F2E38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9BAC, (ts4_word)(ts4_word)lbl_8804C428, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52788, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2EA8: call_seq lbl_88B527E8, lbl_8803F5E0, lbl_88CB9BDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B527E8_889F2EA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9BDC, (ts4_word)(ts4_word)lbl_8803F5E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B527E8, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2F18: call_seq lbl_88B528F0, lbl_88040278, lbl_88CB9C0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B528F0_889F2F18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9C0C, (ts4_word)(ts4_word)lbl_88040278, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B528F0, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2F88: call_seq lbl_88B529C8, lbl_8803ED58, lbl_88CB9C3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B529C8_889F2F88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9C3C, (ts4_word)(ts4_word)lbl_8803ED58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B529C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2FF8: call_seq lbl_88B529F8, lbl_8803ED40, lbl_88CB9C6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B529F8_889F2FF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9C6C, (ts4_word)(ts4_word)lbl_8803ED40, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B529F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3068: call_seq lbl_88B52A10, lbl_880433FC, lbl_88CB9C9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52A10_889F3068(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9C9C, (ts4_word)(ts4_word)lbl_880433FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52A10, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F30D8: call_seq lbl_88B52A58, lbl_8804342C, lbl_88CB9CCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52A58_889F30D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9CCC, (ts4_word)(ts4_word)lbl_8804342C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52A58, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3148: call_seq lbl_88B52A70, lbl_88CB933C, lbl_8803ED7C, lbl_88CB9CFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52A70_889F3148(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9CFC, (ts4_word)(ts4_word)lbl_8803ED7C, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52A70, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F31C0: call_seq lbl_88B52AB8, lbl_88046454, lbl_88CB9D2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52AB8_889F31C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9D2C, (ts4_word)(ts4_word)lbl_88046454, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52AB8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3230: call_seq lbl_88B52B18, lbl_88CB9D2C, lbl_8804233C, lbl_88CB9D5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52B18_889F3230(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9D5C, (ts4_word)(ts4_word)lbl_8804233C, (ts4_word)(ts4_word)lbl_88CB9D2C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52B18, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F32A8: call_seq lbl_880469C4, lbl_88CB9D8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880469C4_889F32A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9D8C, (ts4_word)(ts4_word)lbl_880469C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3308: call_seq lbl_88B52B60, lbl_88CBB58C, lbl_88042E48, lbl_88CB9DBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52B60_889F3308(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9DBC, (ts4_word)(ts4_word)lbl_88042E48, (ts4_word)(ts4_word)lbl_88CBB58C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52B60, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3380: call_seq lbl_88046B60, lbl_88CB9DEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046B60_889F3380(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9DEC, (ts4_word)(ts4_word)lbl_88046B60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F33E0: call_seq lbl_88CB933C, lbl_88042318, lbl_88CB9E1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB933C_889F33E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9E1C, (ts4_word)(ts4_word)lbl_88042318, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3448: call_seq lbl_88046A84, lbl_88CB9E4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A84_889F3448(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9E4C, (ts4_word)(ts4_word)lbl_88046A84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F34A8: call_seq lbl_88B52BC0, lbl_88CB9E1C, lbl_8804232C, lbl_88CB9E7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52BC0_889F34A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9E7C, (ts4_word)(ts4_word)lbl_8804232C, (ts4_word)(ts4_word)lbl_88CB9E1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52BC0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3520: call_seq lbl_88B52BF0, lbl_88CB9E1C, lbl_8804690C, lbl_88CB9EAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52BF0_889F3520(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9EAC, (ts4_word)(ts4_word)lbl_8804690C, (ts4_word)(ts4_word)lbl_88CB9E1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52BF0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3598: call_seq lbl_88CB9E1C, lbl_8804671C, lbl_88CB9EDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB9E1C_889F3598(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9EDC, (ts4_word)(ts4_word)lbl_8804671C, (ts4_word)(ts4_word)lbl_88CB9E1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3600: call_seq lbl_88046A50, lbl_88CB9F0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A50_889F3600(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9F0C, (ts4_word)(ts4_word)lbl_88046A50, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3660: call_seq lbl_88B52C08, lbl_88CB933C, lbl_88041284, lbl_88CB9F3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52C08_889F3660(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9F3C, (ts4_word)(ts4_word)lbl_88041284, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52C08, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F36D8: call_seq lbl_88B52C20, lbl_88046220, lbl_88CB9F6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52C20_889F36D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9F6C, (ts4_word)(ts4_word)lbl_88046220, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52C20, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3748: call_seq lbl_88B52C80, lbl_88CBA08C, lbl_8804694C, lbl_88CB9F9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52C80_889F3748(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9F9C, (ts4_word)(ts4_word)lbl_8804694C, (ts4_word)(ts4_word)lbl_88CBA08C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52C80, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F37C0: call_seq lbl_88B52C98, lbl_88CB9F3C, lbl_88040110, lbl_88CB9FCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52C98_889F37C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9FCC, (ts4_word)(ts4_word)lbl_88040110, (ts4_word)(ts4_word)lbl_88CB9F3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52C98, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3838: call_seq lbl_88B52CC8, lbl_88CB9F3C, lbl_88040100, lbl_88CB9FFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52CC8_889F3838(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB9FFC, (ts4_word)(ts4_word)lbl_88040100, (ts4_word)(ts4_word)lbl_88CB9F3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52CC8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F38B0: call_seq lbl_88B52CE0, lbl_88CBA08C, lbl_8804011C, lbl_88CBA02C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52CE0_889F38B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA02C, (ts4_word)(ts4_word)lbl_8804011C, (ts4_word)(ts4_word)lbl_88CBA08C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52CE0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3928: call_seq lbl_88B52D10, lbl_88CB9F3C, lbl_880400A8, lbl_88CBA05C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52D10_889F3928(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA05C, (ts4_word)(ts4_word)lbl_880400A8, (ts4_word)(ts4_word)lbl_88CB9F3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52D10, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F39A0: call_seq lbl_88B52D28, lbl_88CBA53C, lbl_88042370, lbl_88CBA08C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52D28_889F39A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA08C, (ts4_word)(ts4_word)lbl_88042370, (ts4_word)(ts4_word)lbl_88CBA53C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52D28, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3A18: call_seq lbl_88B52D40, lbl_88CBA29C, lbl_88041B24, lbl_88CBA0BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52D40_889F3A18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA0BC, (ts4_word)(ts4_word)lbl_88041B24, (ts4_word)(ts4_word)lbl_88CBA29C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52D40, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3A90: call_seq lbl_88B52D58, lbl_88CBA05C, lbl_880468C8, lbl_88CBA0EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52D58_889F3A90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA0EC, (ts4_word)(ts4_word)lbl_880468C8, (ts4_word)(ts4_word)lbl_88CBA05C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52D58, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3B08: call_seq lbl_88B52DA0, lbl_88CBA08C, lbl_880400E8, lbl_88CBA11C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52DA0_889F3B08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA11C, (ts4_word)(ts4_word)lbl_880400E8, (ts4_word)(ts4_word)lbl_88CBA08C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52DA0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3B80: call_seq lbl_88B52DD0, lbl_88CBA08C, lbl_880400D0, lbl_88CBA14C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52DD0_889F3B80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA14C, (ts4_word)(ts4_word)lbl_880400D0, (ts4_word)(ts4_word)lbl_88CBA08C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52DD0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3BF8: call_seq lbl_88B52E00, lbl_880463D4, lbl_88CBA17C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52E00_889F3BF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA17C, (ts4_word)(ts4_word)lbl_880463D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52E00, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3C68: call_seq lbl_88B52E48, lbl_88CBA08C, lbl_88046868, lbl_88CBA1AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52E48_889F3C68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA1AC, (ts4_word)(ts4_word)lbl_88046868, (ts4_word)(ts4_word)lbl_88CBA08C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52E48, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3CE0: call_seq lbl_88B52EC8, lbl_88CBA08C, lbl_8803EFC0, lbl_88CBA1DC, lbl_8804FC28, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52EC8_889F3CE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA1DC, (ts4_word)(ts4_word)lbl_8803EFC0, (ts4_word)(ts4_word)lbl_88CBA08C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804FC28, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B52EC8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3D58: call_seq lbl_88CBA32C, lbl_880467DC, lbl_88CBA20C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBA32C_889F3D58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA20C, (ts4_word)(ts4_word)lbl_880467DC, (ts4_word)(ts4_word)lbl_88CBA32C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3DC0: call_seq lbl_88CB9F3C, lbl_88046AE0, lbl_88CBA23C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB9F3C_889F3DC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA23C, (ts4_word)(ts4_word)lbl_88046AE0, (ts4_word)(ts4_word)lbl_88CB9F3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3E28: call_seq lbl_88B52F40, lbl_88042358, lbl_88CBA26C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52F40_889F3E28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA26C, (ts4_word)(ts4_word)lbl_88042358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52F40, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3E98: call_seq lbl_88B52F70, lbl_88CBA05C, lbl_8804234C, lbl_88CBA29C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52F70_889F3E98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA29C, (ts4_word)(ts4_word)lbl_8804234C, (ts4_word)(ts4_word)lbl_88CBA05C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52F70, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3F10: call_seq lbl_88B52F88, lbl_88046320, lbl_88CBA2CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52F88_889F3F10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA2CC, (ts4_word)(ts4_word)lbl_88046320, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B52F88, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F3F80: addr lbl_88B564F0, u32@lbl_88B52EC4, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88B564F0_889F3F80(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B52EC4;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B564F0) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B564F0) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x889F3FA0: call_seq lbl_88B564F0, lbl_8803EFE8, lbl_88CBA2FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B564F0_889F3FA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA2FC, (ts4_word)(ts4_word)lbl_8803EFE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B564F0, (ts4_word)13, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4010: call_seq lbl_88B52FA8, lbl_88CBA05C, lbl_8803EF9C, lbl_88CBA32C, lbl_8804FC7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B52FA8_889F4010(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA32C, (ts4_word)(ts4_word)lbl_8803EF9C, (ts4_word)(ts4_word)lbl_88CBA05C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804FC7C, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B52FA8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4088: call_seq lbl_88B53008, lbl_88CB9FFC, lbl_880423C0, lbl_88CBA35C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53008_889F4088(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA35C, (ts4_word)(ts4_word)lbl_880423C0, (ts4_word)(ts4_word)lbl_88CB9FFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53008, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4100: call_seq lbl_88B53020, lbl_880462E8, lbl_88CBA38C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53020_889F4100(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA38C, (ts4_word)(ts4_word)lbl_880462E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53020, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4170: call_seq lbl_88B53050, lbl_88CB9F3C, lbl_8804675C, lbl_88CBA3BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53050_889F4170(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA3BC, (ts4_word)(ts4_word)lbl_8804675C, (ts4_word)(ts4_word)lbl_88CB9F3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53050, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F41E8: call_seq lbl_88B53080, lbl_88CBA53C, lbl_8803F9D4, lbl_88CBA3EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53080_889F41E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA3EC, (ts4_word)(ts4_word)lbl_8803F9D4, (ts4_word)(ts4_word)lbl_88CBA53C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53080, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4260: call_seq lbl_88CB9F3C, lbl_88046AB4, lbl_88CBA41C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB9F3C_889F4260(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA41C, (ts4_word)(ts4_word)lbl_88046AB4, (ts4_word)(ts4_word)lbl_88CB9F3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F42C8: call_seq lbl_88B530B0, lbl_88CBA23C, lbl_880466D4, lbl_88CBA44C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B530B0_889F42C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA44C, (ts4_word)(ts4_word)lbl_880466D4, (ts4_word)(ts4_word)lbl_88CBA23C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B530B0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4340: call_seq lbl_88B530F8, lbl_88CBA23C, lbl_88046A18, lbl_88CBA47C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B530F8_889F4340(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA47C, (ts4_word)(ts4_word)lbl_88046A18, (ts4_word)(ts4_word)lbl_88CBA23C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B530F8, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F43B8: call_seq lbl_88B531A0, lbl_880423A4, lbl_88CBA4AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B531A0_889F43B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA4AC, (ts4_word)(ts4_word)lbl_880423A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B531A0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4428: call_seq lbl_88B531E8, lbl_88CBA05C, lbl_88042390, lbl_88CBA4DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B531E8_889F4428(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA4DC, (ts4_word)(ts4_word)lbl_88042390, (ts4_word)(ts4_word)lbl_88CBA05C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B531E8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F44A0: call_seq lbl_88CBA08C, lbl_88043ED0, lbl_88CBA50C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBA08C_889F44A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA50C, (ts4_word)(ts4_word)lbl_88043ED0, (ts4_word)(ts4_word)lbl_88CBA08C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4508: call_seq lbl_88CB9F3C, lbl_8804696C, lbl_88CBA53C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB9F3C_889F4508(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA53C, (ts4_word)(ts4_word)lbl_8804696C, (ts4_word)(ts4_word)lbl_88CB9F3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4570: call_seq lbl_88B53248, lbl_8803F00C, lbl_88CBA56C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53248_889F4570(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA56C, (ts4_word)(ts4_word)lbl_8803F00C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53248, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F45E0: call_seq lbl_88B532D8, lbl_88CBA32C, lbl_88046574, lbl_88CBA59C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B532D8_889F45E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA59C, (ts4_word)(ts4_word)lbl_88046574, (ts4_word)(ts4_word)lbl_88CBA32C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B532D8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4658: call_seq lbl_88B532F0, lbl_88CBA47C, lbl_88046518, lbl_88CBA5CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B532F0_889F4658(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA5CC, (ts4_word)(ts4_word)lbl_88046518, (ts4_word)(ts4_word)lbl_88CBA47C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B532F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F46D0: call_seq lbl_88B53320, lbl_88CB9F3C, lbl_880400BC, lbl_88CBA5FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53320_889F46D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA5FC, (ts4_word)(ts4_word)lbl_880400BC, (ts4_word)(ts4_word)lbl_88CB9F3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53320, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4748: call_seq lbl_88B53368, lbl_88CBA08C, lbl_88042380, lbl_88CBA62C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53368_889F4748(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA62C, (ts4_word)(ts4_word)lbl_88042380, (ts4_word)(ts4_word)lbl_88CBA08C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53368, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F47C0: call_seq lbl_88B533B0, lbl_88CB9FFC, lbl_880423D4, lbl_88CBA65C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B533B0_889F47C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA65C, (ts4_word)(ts4_word)lbl_880423D4, (ts4_word)(ts4_word)lbl_88CB9FFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B533B0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4838: call_seq lbl_88B533C8, lbl_88CBA05C, lbl_88046498, lbl_88CBA68C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B533C8_889F4838(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA68C, (ts4_word)(ts4_word)lbl_88046498, (ts4_word)(ts4_word)lbl_88CBA05C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B533C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F48B0: call_seq lbl_88B533F8, lbl_88CB933C, lbl_88047050, lbl_88CBA6BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B533F8_889F48B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA6BC, (ts4_word)(ts4_word)lbl_88047050, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B533F8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4928: call_seq lbl_88B53458, lbl_88CBA6BC, lbl_88045B44, lbl_88CBA6EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53458_889F4928(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA6EC, (ts4_word)(ts4_word)lbl_88045B44, (ts4_word)(ts4_word)lbl_88CBA6BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53458, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F49A0: call_seq lbl_88B53470, lbl_88CBA6BC, lbl_88045B24, lbl_88CBA71C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53470_889F49A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA71C, (ts4_word)(ts4_word)lbl_88045B24, (ts4_word)(ts4_word)lbl_88CBA6BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53470, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4A18: call_seq lbl_88B534A0, lbl_88CBA6BC, lbl_880459C0, lbl_88CBA74C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B534A0_889F4A18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA74C, (ts4_word)(ts4_word)lbl_880459C0, (ts4_word)(ts4_word)lbl_88CBA6BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B534A0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4A90: addr lbl_88B56628, u32@lbl_88B52FA4, u32@0x8 */
void ts4_addr_lbl_88B56628_889F4A90(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B56628) + 8) = (ts4_word)(*(ts4_word *)lbl_88B52FA4);
    return;
}

/* Swing_DLL.xex 0x889F4AA8: call_seq lbl_88B56628, lbl_88045224, lbl_88CBA77C, lbl_8804FCCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56628_889F4AA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA77C, (ts4_word)(ts4_word)lbl_88045224, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804FCCC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B56628, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4B18: call_seq lbl_88B534B8, lbl_88045194, lbl_88CBA7AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B534B8_889F4B18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA7AC, (ts4_word)(ts4_word)lbl_88045194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B534B8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4B88: call_seq lbl_88B534D0, lbl_8803EF90, lbl_88CBA7DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B534D0_889F4B88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA7DC, (ts4_word)(ts4_word)lbl_8803EF90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B534D0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4BF8: call_seq lbl_88B5351C, lbl_88CB933C, lbl_8803FA04, lbl_88CBA80C, lbl_8804FD98, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5351C_889F4BF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA80C, (ts4_word)(ts4_word)lbl_8803FA04, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804FD98, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B5351C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4C68: call_seq lbl_88B53538, lbl_88042170, lbl_88CBA83C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53538_889F4C68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA83C, (ts4_word)(ts4_word)lbl_88042170, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53538, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4CD8: addr lbl_88B56670, u32@lbl_88B53534, u32@0x50 */
void ts4_addr_lbl_88B56670_889F4CD8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B56670) + 80) = (ts4_word)(*(ts4_word *)lbl_88B53534);
    return;
}

/* Swing_DLL.xex 0x889F4CF0: call_seq lbl_88B56670, lbl_88CB933C, lbl_8803F0C8, lbl_88CBA86C, lbl_8804FDF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56670_889F4CF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA86C, (ts4_word)(ts4_word)lbl_8803F0C8, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804FDF4, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B56670, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4D68: call_seq lbl_88B535A0, lbl_88CBA80C, lbl_8804044C, lbl_88CBA89C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B535A0_889F4D68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA89C, (ts4_word)(ts4_word)lbl_8804044C, (ts4_word)(ts4_word)lbl_88CBA80C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B535A0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4DE0: call_seq lbl_88B535B8, lbl_88CBA80C, lbl_880403DC, lbl_88CBA8CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B535B8_889F4DE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA8CC, (ts4_word)(ts4_word)lbl_880403DC, (ts4_word)(ts4_word)lbl_88CBA80C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B535B8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4E58: call_seq lbl_88B535E8, lbl_88040630, lbl_88CBA8FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B535E8_889F4E58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA8FC, (ts4_word)(ts4_word)lbl_88040630, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B535E8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4EC8: call_seq lbl_88B53630, lbl_88040608, lbl_88CBA92C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53630_889F4EC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA92C, (ts4_word)(ts4_word)lbl_88040608, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53630, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4F38: call_seq lbl_88B53660, lbl_88CBA80C, lbl_88040394, lbl_88CBA95C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53660_889F4F38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA95C, (ts4_word)(ts4_word)lbl_88040394, (ts4_word)(ts4_word)lbl_88CBA80C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53660, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F4FB0: call_seq lbl_88B53690, lbl_88040590, lbl_88CBA98C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53690_889F4FB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA98C, (ts4_word)(ts4_word)lbl_88040590, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53690, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5020: call_seq lbl_88B536F0, lbl_88040560, lbl_88CBA9BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B536F0_889F5020(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA9BC, (ts4_word)(ts4_word)lbl_88040560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B536F0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5090: call_seq lbl_8804FE30, lbl_88B53738, lbl_88CBA80C, lbl_8803F690, lbl_88CBA9EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8804FE30_889F5090(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBA9EC, (ts4_word)(ts4_word)lbl_8803F690, (ts4_word)(ts4_word)lbl_88CBA80C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53738, (ts4_word)6, (ts4_word)(ts4_word)lbl_8804FE30, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5108: call_seq lbl_88B537C8, lbl_88CBAA4C, lbl_88045734, lbl_88CBAA1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B537C8_889F5108(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAA1C, (ts4_word)(ts4_word)lbl_88045734, (ts4_word)(ts4_word)lbl_88CBAA4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B537C8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5180: call_seq lbl_88CB933C, lbl_88045A30, lbl_88CBAA4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB933C_889F5180(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAA4C, (ts4_word)(ts4_word)lbl_88045A30, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F51E8: addr lbl_88B56730, u32@lbl_88B53840, u32@0x38 */
void ts4_addr_lbl_88B56730_889F51E8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B56730) + 56) = (ts4_word)(*(ts4_word *)lbl_88B53840);
    return;
}

/* Swing_DLL.xex 0x889F5200: call_seq lbl_88B56730, lbl_88CBA80C, lbl_88040364, lbl_88CBAA7C, lbl_8804FE74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56730_889F5200(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAA7C, (ts4_word)(ts4_word)lbl_88040364, (ts4_word)(ts4_word)lbl_88CBA80C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804FE74, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B56730, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5278: call_seq lbl_88B53848, lbl_88CBA80C, lbl_88040344, lbl_88CBAAAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53848_889F5278(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAAAC, (ts4_word)(ts4_word)lbl_88040344, (ts4_word)(ts4_word)lbl_88CBA80C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53848, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F52F0: call_seq lbl_88B53890, lbl_88CBA9EC, lbl_8803F064, lbl_88CBAADC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53890_889F52F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAADC, (ts4_word)(ts4_word)lbl_8803F064, (ts4_word)(ts4_word)lbl_88CBA9EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53890, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5368: call_seq lbl_88B538F0, lbl_88040534, lbl_88CBAB0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B538F0_889F5368(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAB0C, (ts4_word)(ts4_word)lbl_88040534, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B538F0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F53D8: call_seq lbl_88B53938, lbl_88040508, lbl_88CBAB3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53938_889F53D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAB3C, (ts4_word)(ts4_word)lbl_88040508, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53938, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5448: call_seq lbl_88B53980, lbl_88CBA80C, lbl_8803F048, lbl_88CBAB6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53980_889F5448(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAB6C, (ts4_word)(ts4_word)lbl_8803F048, (ts4_word)(ts4_word)lbl_88CBA80C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53980, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F54C0: call_seq lbl_88B53A28, lbl_88CBA80C, lbl_880402E4, lbl_88CBAB9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53A28_889F54C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAB9C, (ts4_word)(ts4_word)lbl_880402E4, (ts4_word)(ts4_word)lbl_88CBA80C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53A28, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5538: call_seq lbl_88B53A70, lbl_88040424, lbl_88CBABCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53A70_889F5538(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBABCC, (ts4_word)(ts4_word)lbl_88040424, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53A70, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F55A8: call_seq lbl_88B53AA0, lbl_880403FC, lbl_88CBABFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53AA0_889F55A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBABFC, (ts4_word)(ts4_word)lbl_880403FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53AA0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5618: call_seq lbl_88B53B30, lbl_88CBA80C, lbl_880402CC, lbl_88CBAC2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53B30_889F5618(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAC2C, (ts4_word)(ts4_word)lbl_880402CC, (ts4_word)(ts4_word)lbl_88CBA80C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53B30, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5690: call_seq lbl_88B53BC0, lbl_88CBA80C, lbl_8803F6B0, lbl_88CBAC5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53BC0_889F5690(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAC5C, (ts4_word)(ts4_word)lbl_8803F6B0, (ts4_word)(ts4_word)lbl_88CBA80C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53BC0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5708: call_seq lbl_88CBA80C, lbl_88045AFC, lbl_88CBAC8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBA80C_889F5708(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAC8C, (ts4_word)(ts4_word)lbl_88045AFC, (ts4_word)(ts4_word)lbl_88CBA80C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5770: call_seq lbl_88B53C80, lbl_88CBA86C, lbl_8804589C, lbl_88CBACBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53C80_889F5770(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBACBC, (ts4_word)(ts4_word)lbl_8804589C, (ts4_word)(ts4_word)lbl_88CBA86C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53C80, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F57E8: call_seq lbl_88B53CB0, lbl_88CBA6BC, lbl_88045860, lbl_88CBACEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53CB0_889F57E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBACEC, (ts4_word)(ts4_word)lbl_88045860, (ts4_word)(ts4_word)lbl_88CBA6BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53CB0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5860: call_seq lbl_88B53CC8, lbl_880453D8, lbl_88CBAD1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53CC8_889F5860(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAD1C, (ts4_word)(ts4_word)lbl_880453D8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53CC8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F58D0: call_seq lbl_88B53CF8, lbl_88CBAC8C, lbl_880403C4, lbl_88CBAD4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53CF8_889F58D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAD4C, (ts4_word)(ts4_word)lbl_880403C4, (ts4_word)(ts4_word)lbl_88CBAC8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53CF8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5948: call_seq lbl_88B53D70, lbl_880405E4, lbl_88CBAD7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53D70_889F5948(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAD7C, (ts4_word)(ts4_word)lbl_880405E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53D70, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F59B8: call_seq lbl_88B53DB8, lbl_880405C0, lbl_88CBADAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53DB8_889F59B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBADAC, (ts4_word)(ts4_word)lbl_880405C0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53DB8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5A28: call_seq lbl_88B53DE8, lbl_88CBA80C, lbl_88040380, lbl_88CBADDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53DE8_889F5A28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBADDC, (ts4_word)(ts4_word)lbl_88040380, (ts4_word)(ts4_word)lbl_88CBA80C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53DE8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5AA0: call_seq lbl_88B53E78, lbl_8803FC48, lbl_88CBAE0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53E78_889F5AA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAE0C, (ts4_word)(ts4_word)lbl_8803FC48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53E78, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5B10: call_seq lbl_88B53F08, lbl_88CBAC8C, lbl_8803FC6C, lbl_88CBAE3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53F08_889F5B10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAE3C, (ts4_word)(ts4_word)lbl_8803FC6C, (ts4_word)(ts4_word)lbl_88CBAC8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53F08, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5B88: call_seq lbl_88B53F80, lbl_88045020, lbl_88CBAE6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53F80_889F5B88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAE6C, (ts4_word)(ts4_word)lbl_88045020, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53F80, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5BF8: call_seq lbl_88B53FC8, lbl_88CBAC8C, lbl_88040300, lbl_88CBAE9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B53FC8_889F5BF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAE9C, (ts4_word)(ts4_word)lbl_88040300, (ts4_word)(ts4_word)lbl_88CBAC8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B53FC8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5C70: call_seq lbl_88B54028, lbl_88CBA80C, lbl_880403AC, lbl_88CBAECC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54028_889F5C70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAECC, (ts4_word)(ts4_word)lbl_880403AC, (ts4_word)(ts4_word)lbl_88CBA80C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54028, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5CE8: call_seq lbl_88B54040, lbl_880422F8, lbl_88CBAEFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54040_889F5CE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAEFC, (ts4_word)(ts4_word)lbl_880422F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54040, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5D58: call_seq lbl_88B540B8, lbl_88CBA80C, lbl_8803FA18, lbl_88CBAF2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B540B8_889F5D58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAF2C, (ts4_word)(ts4_word)lbl_8803FA18, (ts4_word)(ts4_word)lbl_88CBA80C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B540B8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5DD0: call_seq lbl_8804FEB0, lbl_88CB933C, lbl_8803FBE0, lbl_88CBAF5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8804FEB0_889F5DD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAF5C, (ts4_word)(ts4_word)lbl_8803FBE0, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804FEB0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5E38: call_seq lbl_88B540E8, lbl_88CBAF5C, lbl_88045A70, lbl_88CBAF8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B540E8_889F5E38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAF8C, (ts4_word)(ts4_word)lbl_88045A70, (ts4_word)(ts4_word)lbl_88CBAF5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B540E8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5EB0: call_seq lbl_88B54118, lbl_88CBAF8C, lbl_8803FCA0, lbl_88CBAFBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54118_889F5EB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAFBC, (ts4_word)(ts4_word)lbl_8803FCA0, (ts4_word)(ts4_word)lbl_88CBAF8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54118, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5F28: call_seq lbl_88B54178, lbl_88CBAF8C, lbl_8803FC80, lbl_88CBAFEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54178_889F5F28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBAFEC, (ts4_word)(ts4_word)lbl_8803FC80, (ts4_word)(ts4_word)lbl_88CBAF8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54178, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F5FA0: call_seq lbl_88B541A8, lbl_88CBAF8C, lbl_8803F9E8, lbl_88CBB01C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B541A8_889F5FA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB01C, (ts4_word)(ts4_word)lbl_8803F9E8, (ts4_word)(ts4_word)lbl_88CBAF8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B541A8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6018: call_seq lbl_88B541F0, lbl_88CBA80C, lbl_8804032C, lbl_88CBB04C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B541F0_889F6018(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB04C, (ts4_word)(ts4_word)lbl_8804032C, (ts4_word)(ts4_word)lbl_88CBA80C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B541F0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6090: call_seq lbl_8804FEC8, lbl_88B54280, lbl_88CBB4FC, lbl_8803F6CC, lbl_88CBB07C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8804FEC8_889F6090(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB07C, (ts4_word)(ts4_word)lbl_8803F6CC, (ts4_word)(ts4_word)lbl_88CBB4FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54280, (ts4_word)18, (ts4_word)(ts4_word)lbl_8804FEC8, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6108: call_seq lbl_88CB933C, lbl_88045AA8, lbl_88CBB0AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB933C_889F6108(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB0AC, (ts4_word)(ts4_word)lbl_88045AA8, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6170: call_seq lbl_88CBB13C, lbl_880457FC, lbl_88CBB0DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBB13C_889F6170(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB0DC, (ts4_word)(ts4_word)lbl_880457FC, (ts4_word)(ts4_word)lbl_88CBB13C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F61D8: call_seq lbl_88CBB07C, lbl_880455E0, lbl_88CBB10C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBB07C_889F61D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB10C, (ts4_word)(ts4_word)lbl_880455E0, (ts4_word)(ts4_word)lbl_88CBB07C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6240: call_seq lbl_8804FF34, lbl_88CBB0AC, lbl_880459F8, lbl_88CBB13C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8804FF34_889F6240(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB13C, (ts4_word)(ts4_word)lbl_880459F8, (ts4_word)(ts4_word)lbl_88CBB0AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804FF34, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F62A8: call_seq lbl_88B54434, lbl_88045070, lbl_88CBB16C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54434_889F62A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB16C, (ts4_word)(ts4_word)lbl_88045070, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54434, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6318: call_seq lbl_88B54468, lbl_88CBB13C, lbl_88041DE0, lbl_88CBB19C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54468_889F6318(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB19C, (ts4_word)(ts4_word)lbl_88041DE0, (ts4_word)(ts4_word)lbl_88CBB13C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54468, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6390: call_seq lbl_88B54510, lbl_88CB933C, lbl_8803F5D4, lbl_88CBB1CC, lbl_8804FF98, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54510_889F6390(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB1CC, (ts4_word)(ts4_word)lbl_8803F5D4, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804FF98, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B54510, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6400: call_seq lbl_88B54528, lbl_88CBB28C, lbl_880402B0, lbl_88CBB1FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54528_889F6400(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB1FC, (ts4_word)(ts4_word)lbl_880402B0, (ts4_word)(ts4_word)lbl_88CBB28C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54528, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6478: call_seq lbl_88CBB25C, lbl_88040E04, lbl_88CBB22C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBB25C_889F6478(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB22C, (ts4_word)(ts4_word)lbl_88040E04, (ts4_word)(ts4_word)lbl_88CBB25C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F64E0: call_seq lbl_88B54540, lbl_88CBB28C, lbl_8803EFA8, lbl_88CBB25C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54540_889F64E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB25C, (ts4_word)(ts4_word)lbl_8803EFA8, (ts4_word)(ts4_word)lbl_88CBB28C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54540, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6558: call_seq lbl_88B54570, lbl_88CBB1CC, lbl_88040290, lbl_88CBB28C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54570_889F6558(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB28C, (ts4_word)(ts4_word)lbl_88040290, (ts4_word)(ts4_word)lbl_88CBB1CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54570, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F65D0: call_seq lbl_88CBB28C, lbl_880402A0, lbl_88CBB2BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBB28C_889F65D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB2BC, (ts4_word)(ts4_word)lbl_880402A0, (ts4_word)(ts4_word)lbl_88CBB28C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6638: call_seq lbl_88CBB1FC, lbl_88040E18, lbl_88CBB2EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBB1FC_889F6638(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB2EC, (ts4_word)(ts4_word)lbl_88040E18, (ts4_word)(ts4_word)lbl_88CBB1FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F66A0: call_seq lbl_88CBB2BC, lbl_88040E68, lbl_88CBB31C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBB2BC_889F66A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB31C, (ts4_word)(ts4_word)lbl_88040E68, (ts4_word)(ts4_word)lbl_88CBB2BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6708: call_seq lbl_88CBB1FC, lbl_88040DB0, lbl_88CBB34C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBB1FC_889F6708(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB34C, (ts4_word)(ts4_word)lbl_88040DB0, (ts4_word)(ts4_word)lbl_88CBB1FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6770: call_seq lbl_88B54618, lbl_88CBB3DC, lbl_8803F6D8, lbl_88CBB37C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54618_889F6770(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB37C, (ts4_word)(ts4_word)lbl_8803F6D8, (ts4_word)(ts4_word)lbl_88CBB3DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54618, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F67E8: call_seq lbl_88B54648, lbl_88CBB40C, lbl_88045914, lbl_88CBB3AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54648_889F67E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB3AC, (ts4_word)(ts4_word)lbl_88045914, (ts4_word)(ts4_word)lbl_88CBB40C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54648, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6860: call_seq lbl_88B54660, lbl_88CBB4FC, lbl_88047070, lbl_88CBB3DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54660_889F6860(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB3DC, (ts4_word)(ts4_word)lbl_88047070, (ts4_word)(ts4_word)lbl_88CBB4FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54660, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F68D8: call_seq lbl_88B54690, lbl_88CBB3DC, lbl_880402BC, lbl_88CBB40C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54690_889F68D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB40C, (ts4_word)(ts4_word)lbl_880402BC, (ts4_word)(ts4_word)lbl_88CBB3DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54690, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6950: call_seq lbl_88B546A8, lbl_88CBB40C, lbl_88045580, lbl_88CBB43C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B546A8_889F6950(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB43C, (ts4_word)(ts4_word)lbl_88045580, (ts4_word)(ts4_word)lbl_88CBB40C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B546A8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F69C8: call_seq lbl_88B546C4, lbl_8803F9C0, lbl_88CBB46C, lbl_8804FFC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B546C4_889F69C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB46C, (ts4_word)(ts4_word)lbl_8803F9C0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804FFC4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B546C4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6A38: call_seq lbl_88B546F8, lbl_88CB933C, lbl_8803F660, lbl_88CBB49C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B546F8_889F6A38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB49C, (ts4_word)(ts4_word)lbl_8803F660, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B546F8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6AB0: get u32@lbl_88B54790, lbl_88B56790, u32@lbl_88B5478C, u32@lbl_88B54788, u32@0x50, u32@0x110 */
void ts4_get_u32_lbl_88B54790_889F6AB0(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88B54790;
    t2 = *(ts4_word *)lbl_88B5478C;
    t3 = *(ts4_word *)lbl_88B54788;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B56790) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B56790) + 272) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B56790) + 560) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x889F6B58: call_seq lbl_88B54798, lbl_88CB933C, lbl_8803F084, lbl_88CBB4FC, lbl_880501A0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54798_889F6B58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB4FC, (ts4_word)(ts4_word)lbl_8803F084, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880501A0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B54798, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6BD0: call_seq lbl_88B54810, lbl_88CB933C, lbl_8804707C, lbl_88CBB52C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54810_889F6BD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB52C, (ts4_word)(ts4_word)lbl_8804707C, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54810, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6C48: call_seq lbl_88B54828, lbl_88CB9D5C, lbl_88044F38, lbl_88CBB55C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54828_889F6C48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB55C, (ts4_word)(ts4_word)lbl_88044F38, (ts4_word)(ts4_word)lbl_88CB9D5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54828, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6CC0: call_seq lbl_88B54840, lbl_88042E20, lbl_88CBB58C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54840_889F6CC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB58C, (ts4_word)(ts4_word)lbl_88042E20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54840, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6D30: call_seq lbl_88B54858, lbl_88CB933C, lbl_8803EFD0, lbl_88CBB5BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54858_889F6D30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB5BC, (ts4_word)(ts4_word)lbl_8803EFD0, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54858, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6DA8: call_seq lbl_88B548A0, lbl_88044F10, lbl_88CBB5EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B548A0_889F6DA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB5EC, (ts4_word)(ts4_word)lbl_88044F10, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B548A0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6E18: call_seq lbl_88B548B8, lbl_88CB933C, lbl_88044F90, lbl_88CBB61C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B548B8_889F6E18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB61C, (ts4_word)(ts4_word)lbl_88044F90, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B548B8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6E90: call_seq lbl_88B548E8, lbl_88CBB6DC, lbl_8803F670, lbl_88CBB64C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B548E8_889F6E90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB64C, (ts4_word)(ts4_word)lbl_8803F670, (ts4_word)(ts4_word)lbl_88CBB6DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B548E8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6F08: call_seq lbl_88B54960, lbl_880404E0, lbl_88CBB67C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54960_889F6F08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB67C, (ts4_word)(ts4_word)lbl_880404E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54960, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6F78: call_seq lbl_88B549A8, lbl_880404B8, lbl_88CBB6AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B549A8_889F6F78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB6AC, (ts4_word)(ts4_word)lbl_880404B8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B549A8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F6FE8: call_seq lbl_880501B4, lbl_88B549F0, lbl_88CBA80C, lbl_8803F030, lbl_88CBB6DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880501B4_889F6FE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB6DC, (ts4_word)(ts4_word)lbl_8803F030, (ts4_word)(ts4_word)lbl_88CBA80C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B549F0, (ts4_word)9, (ts4_word)(ts4_word)lbl_880501B4, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7060: call_seq lbl_88B54AC8, lbl_88040494, lbl_88CBB70C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54AC8_889F7060(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB70C, (ts4_word)(ts4_word)lbl_88040494, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54AC8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F70D0: call_seq lbl_88B54AF8, lbl_88040470, lbl_88CBB73C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54AF8_889F70D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB73C, (ts4_word)(ts4_word)lbl_88040470, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54AF8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7140: call_seq lbl_88B54B28, lbl_88CBA80C, lbl_88040318, lbl_88CBB76C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54B28_889F7140(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB76C, (ts4_word)(ts4_word)lbl_88040318, (ts4_word)(ts4_word)lbl_88CBA80C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54B28, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F71B8: call_seq lbl_88B54C00, lbl_88CBA71C, lbl_88044EA8, lbl_88CBB79C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54C00_889F71B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB79C, (ts4_word)(ts4_word)lbl_88044EA8, (ts4_word)(ts4_word)lbl_88CBA71C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54C00, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7230: call_seq lbl_88B54C48, lbl_88CBA71C, lbl_88044E64, lbl_88CBB7CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54C48_889F7230(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB7CC, (ts4_word)(ts4_word)lbl_88044E64, (ts4_word)(ts4_word)lbl_88CBA71C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54C48, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F72A8: call_seq lbl_88B54CA8, lbl_88CBA74C, lbl_88044DD0, lbl_88CBB7FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54CA8_889F72A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB7FC, (ts4_word)(ts4_word)lbl_88044DD0, (ts4_word)(ts4_word)lbl_88CBA74C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54CA8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7320: call_seq lbl_88B54D08, lbl_88CBA74C, lbl_88044CD0, lbl_88CBB82C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54D08_889F7320(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB82C, (ts4_word)(ts4_word)lbl_88044CD0, (ts4_word)(ts4_word)lbl_88CBA74C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54D08, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7398: call_seq lbl_88B54D68, lbl_88CBA71C, lbl_88044BD4, lbl_88CBB85C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54D68_889F7398(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB85C, (ts4_word)(ts4_word)lbl_88044BD4, (ts4_word)(ts4_word)lbl_88CBA71C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54D68, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7410: call_seq lbl_88B54E28, lbl_8803F094, lbl_88CBB88C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54E28_889F7410(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB88C, (ts4_word)(ts4_word)lbl_8803F094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54E28, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7480: call_seq lbl_88B54FC0, lbl_88CB9E1C, lbl_8803F0AC, lbl_88CBB8BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54FC0_889F7480(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB8BC, (ts4_word)(ts4_word)lbl_8803F0AC, (ts4_word)(ts4_word)lbl_88CB9E1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54FC0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F74F8: call_seq lbl_88B54FD8, lbl_88CB9E1C, lbl_88044E30, lbl_88CBB8EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54FD8_889F74F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB8EC, (ts4_word)(ts4_word)lbl_88044E30, (ts4_word)(ts4_word)lbl_88CB9E1C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54FD8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7570: call_seq lbl_88B54FF0, lbl_88CB9E1C, lbl_88044DF8, lbl_88CBB91C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B54FF0_889F7570(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB91C, (ts4_word)(ts4_word)lbl_88044DF8, (ts4_word)(ts4_word)lbl_88CB9E1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B54FF0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F75E8: call_seq lbl_88B55020, lbl_88044B54, lbl_88CBB94C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55020_889F75E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB94C, (ts4_word)(ts4_word)lbl_88044B54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55020, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7658: call_seq lbl_88B55050, lbl_88CB9E1C, lbl_88044D8C, lbl_88CBB97C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55050_889F7658(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB97C, (ts4_word)(ts4_word)lbl_88044D8C, (ts4_word)(ts4_word)lbl_88CB9E1C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55050, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F76D0: call_seq lbl_88B55068, lbl_88044A90, lbl_88CBB9AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55068_889F76D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB9AC, (ts4_word)(ts4_word)lbl_88044A90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55068, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7740: call_seq lbl_88B55098, lbl_88044ACC, lbl_88CBB9DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55098_889F7740(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBB9DC, (ts4_word)(ts4_word)lbl_88044ACC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55098, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F77B0: call_seq lbl_88B550E0, lbl_88CB933C, lbl_88044CFC, lbl_88CBBA0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B550E0_889F77B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBA0C, (ts4_word)(ts4_word)lbl_88044CFC, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B550E0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7828: call_seq lbl_88B55128, lbl_88CBA74C, lbl_8804705C, lbl_88CBBA3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55128_889F7828(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBA3C, (ts4_word)(ts4_word)lbl_8804705C, (ts4_word)(ts4_word)lbl_88CBA74C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55128, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F78A0: call_seq lbl_88B551B8, lbl_88044A58, lbl_88CBBA6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B551B8_889F78A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBA6C, (ts4_word)(ts4_word)lbl_88044A58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B551B8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7910: call_seq lbl_88B55200, lbl_88044B0C, lbl_88CBBA9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55200_889F7910(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBA9C, (ts4_word)(ts4_word)lbl_88044B0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55200, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7980: call_seq lbl_88B55230, lbl_88044B94, lbl_88CBBACC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55230_889F7980(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBACC, (ts4_word)(ts4_word)lbl_88044B94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55230, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F79F0: call_seq lbl_88B55260, lbl_88CB933C, lbl_88044D60, lbl_88CBBAFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55260_889F79F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBAFC, (ts4_word)(ts4_word)lbl_88044D60, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55260, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7A68: call_seq lbl_88B55290, lbl_88CB933C, lbl_88044C84, lbl_88CBBB2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55290_889F7A68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBB2C, (ts4_word)(ts4_word)lbl_88044C84, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55290, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7AE0: call_seq lbl_88B552A8, lbl_88CB933C, lbl_88044C48, lbl_88CBBB5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B552A8_889F7AE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBB5C, (ts4_word)(ts4_word)lbl_88044C48, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B552A8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7B58: call_seq lbl_88B552C0, lbl_88044A08, lbl_88CBBB8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B552C0_889F7B58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBB8C, (ts4_word)(ts4_word)lbl_88044A08, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B552C0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7BC8: call_seq lbl_88B552F0, lbl_88CB933C, lbl_88044C08, lbl_88CBBBBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B552F0_889F7BC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBBBC, (ts4_word)(ts4_word)lbl_88044C08, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B552F0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F7C40: call_seq lbl_88B55308, lbl_88040668, lbl_88CBBBEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B55308_889F7C40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CBBBEC, (ts4_word)(ts4_word)lbl_88040668, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B55308, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}
