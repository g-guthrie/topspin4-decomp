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
extern char lbl_8803ED14[];
extern char lbl_8803ED20[];
extern char lbl_8803ED28[];
extern char lbl_8803ED40[];
extern char lbl_8803ED58[];
extern char lbl_8803ED7C[];
extern char lbl_8803EF90[];
extern char lbl_8803EF9C[];
extern char lbl_8803EFC0[];
extern char lbl_8803EFE8[];
extern char lbl_8803F00C[];
extern char lbl_8803F048[];
extern char lbl_8803F0C8[];
extern char lbl_8803F5BC[];
extern char lbl_8803F5C8[];
extern char lbl_8803F5E0[];
extern char lbl_8803F690[];
extern char lbl_8803F6B0[];
extern char lbl_8803F960[];
extern char lbl_8803F974[];
extern char lbl_8803F988[];
extern char lbl_8803F99C[];
extern char lbl_8803F9B0[];
extern char lbl_8803F9D4[];
extern char lbl_8803FA04[];
extern char lbl_8803FC48[];
extern char lbl_8803FC6C[];
extern char lbl_880400A8[];
extern char lbl_880400BC[];
extern char lbl_880400D0[];
extern char lbl_880400E8[];
extern char lbl_88040100[];
extern char lbl_88040110[];
extern char lbl_8804011C[];
extern char lbl_880401D8[];
extern char lbl_880401F0[];
extern char lbl_88040200[];
extern char lbl_88040218[];
extern char lbl_88040260[];
extern char lbl_88040278[];
extern char lbl_880402CC[];
extern char lbl_880402E4[];
extern char lbl_88040300[];
extern char lbl_88040344[];
extern char lbl_88040364[];
extern char lbl_88040380[];
extern char lbl_88040394[];
extern char lbl_880403AC[];
extern char lbl_880403C4[];
extern char lbl_880403DC[];
extern char lbl_88041128[];
extern char lbl_88041174[];
extern char lbl_88041194[];
extern char lbl_88041284[];
extern char lbl_88041930[];
extern char lbl_88041AFC[];
extern char lbl_88041B0C[];
extern char lbl_88041B24[];
extern char lbl_8804215C[];
extern char lbl_88042170[];
extern char lbl_88042184[];
extern char lbl_880421A0[];
extern char lbl_8804221C[];
extern char lbl_8804223C[];
extern char lbl_88042260[];
extern char lbl_88042284[];
extern char lbl_8804229C[];
extern char lbl_880422B8[];
extern char lbl_880422DC[];
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
extern char lbl_88043EE0[];
extern char lbl_88045020[];
extern char lbl_88045194[];
extern char lbl_88045224[];
extern char lbl_880453D8[];
extern char lbl_88045734[];
extern char lbl_88045860[];
extern char lbl_8804589C[];
extern char lbl_880459C0[];
extern char lbl_88045A30[];
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
extern char lbl_88054050[];
extern char lbl_88054068[];
extern char lbl_88054648[];
extern char lbl_8805469C[];
extern char lbl_880546D0[];
extern char lbl_880546EC[];
extern char lbl_88054860[];
extern char lbl_880548B4[];
extern char lbl_880548D8[];
extern char lbl_8805491C[];
extern char lbl_88054948[];
extern char lbl_8805498C[];
extern char lbl_880549C8[];
extern char lbl_88054A04[];
extern char lbl_88054A18[];
extern char lbl_88054A90[];
extern char lbl_88054ACC[];
extern char lbl_88054B20[];
extern char lbl_88054C40[];
extern char lbl_88054C68[];
extern char lbl_88054C80[];
extern char lbl_88054D08[];
extern char lbl_88054DC0[];
extern char lbl_88054E1C[];
extern char lbl_88054E60[];
extern char lbl_88054E8C[];
extern char lbl_88054EC8[];
extern char lbl_88054EEC[];
extern char lbl_88054F20[];
extern char lbl_88054F4C[];
extern char lbl_88054F60[];
extern char lbl_88B69B98[];
extern char lbl_88B69BE0[];
extern char lbl_88B69C28[];
extern char lbl_88B69D4C[];
extern char lbl_88B69D50[];
extern char lbl_88B69D98[];
extern char lbl_88B69DF8[];
extern char lbl_88B69E28[];
extern char lbl_88B69E40[];
extern char lbl_88B69E74[];
extern char lbl_88B69E78[];
extern char lbl_88B69F20[];
extern char lbl_88B69F50[];
extern char lbl_88B69F88[];
extern char lbl_88B69FB8[];
extern char lbl_88B69FD0[];
extern char lbl_88B69FD4[];
extern char lbl_88B6A004[];
extern char lbl_88B6A038[];
extern char lbl_88B6A098[];
extern char lbl_88B6A188[];
extern char lbl_88B6A1A0[];
extern char lbl_88B6A218[];
extern char lbl_88B6A230[];
extern char lbl_88B6A234[];
extern char lbl_88B6A264[];
extern char lbl_88B6A294[];
extern char lbl_88B6A2C4[];
extern char lbl_88B6A2DC[];
extern char lbl_88B6A30C[];
extern char lbl_88B6A324[];
extern char lbl_88B6A354[];
extern char lbl_88B6A358[];
extern char lbl_88B6A400[];
extern char lbl_88B6A430[];
extern char lbl_88B6A448[];
extern char lbl_88B6A478[];
extern char lbl_88B6A53C[];
extern char lbl_88B6A56C[];
extern char lbl_88B6A570[];
extern char lbl_88B6A630[];
extern char lbl_88B6A648[];
extern char lbl_88B6A678[];
extern char lbl_88B6A67C[];
extern char lbl_88B6A698[];
extern char lbl_88B6A6E0[];
extern char lbl_88B6A710[];
extern char lbl_88B6A830[];
extern char lbl_88B6A8C0[];
extern char lbl_88B6A980[];
extern char lbl_88B6AA58[];
extern char lbl_88B6AB18[];
extern char lbl_88B6ABC0[];
extern char lbl_88B6ACE0[];
extern char lbl_88B6AD40[];
extern char lbl_88B6AE48[];
extern char lbl_88B6AF20[];
extern char lbl_88B6AF68[];
extern char lbl_88B6AF80[];
extern char lbl_88B6AFC8[];
extern char lbl_88B6AFE0[];
extern char lbl_88B6B028[];
extern char lbl_88B6B088[];
extern char lbl_88B6B0D0[];
extern char lbl_88B6B130[];
extern char lbl_88B6B160[];
extern char lbl_88B6B178[];
extern char lbl_88B6B190[];
extern char lbl_88B6B1A8[];
extern char lbl_88B6B208[];
extern char lbl_88B6B220[];
extern char lbl_88B6B250[];
extern char lbl_88B6B268[];
extern char lbl_88B6B298[];
extern char lbl_88B6B2B0[];
extern char lbl_88B6B2C8[];
extern char lbl_88B6B2E0[];
extern char lbl_88B6B328[];
extern char lbl_88B6B358[];
extern char lbl_88B6B388[];
extern char lbl_88B6B3D0[];
extern char lbl_88B6B44C[];
extern char lbl_88B6B450[];
extern char lbl_88B6B4C8[];
extern char lbl_88B6B4F8[];
extern char lbl_88B6B510[];
extern char lbl_88B6B52C[];
extern char lbl_88B6B530[];
extern char lbl_88B6B5A8[];
extern char lbl_88B6B5C0[];
extern char lbl_88B6B5F0[];
extern char lbl_88B6B620[];
extern char lbl_88B6B650[];
extern char lbl_88B6B698[];
extern char lbl_88B6B740[];
extern char lbl_88B6B788[];
extern char lbl_88B6B7E8[];
extern char lbl_88B6B878[];
extern char lbl_88B6B890[];
extern char lbl_88B6B8C0[];
extern char lbl_88B6B908[];
extern char lbl_88B6B950[];
extern char lbl_88B6B968[];
extern char lbl_88B6B99C[];
extern char lbl_88B6B9CC[];
extern char lbl_88B6B9E4[];
extern char lbl_88B6B9FC[];
extern char lbl_88B6BA2C[];
extern char lbl_88B6BA5C[];
extern char lbl_88B6BA8C[];
extern char lbl_88B6BAA4[];
extern char lbl_88B6BABC[];
extern char lbl_88B6BAC0[];
extern char lbl_88B6BB08[];
extern char lbl_88B6BB50[];
extern char lbl_88B6BB68[];
extern char lbl_88B6BB98[];
extern char lbl_88B6BC10[];
extern char lbl_88B6BCA0[];
extern char lbl_88B6BD00[];
extern char lbl_88B6BDA8[];
extern char lbl_88B6BE20[];
extern char lbl_88B6BE68[];
extern char lbl_88B6BEF8[];
extern char lbl_88B6BF58[];
extern char lbl_88B6BFA0[];
extern char lbl_88B6BFD0[];
extern char lbl_88B6C000[];
extern char lbl_88B6C018[];
extern char lbl_88B6C078[];
extern char lbl_88B6C090[];
extern char lbl_88B6C0C0[];
extern char lbl_88B6C0D8[];
extern char lbl_88B6C0DC[];
extern char lbl_88B6C0F8[];
extern char lbl_88B6C140[];
extern char lbl_88B6C158[];
extern char lbl_88B6C1B8[];
extern char lbl_88B6C1C4[];
extern char lbl_88B6C1F4[];
extern char lbl_88B6C210[];
extern char lbl_88B6C258[];
extern char lbl_88B6C274[];
extern char lbl_88B6C278[];
extern char lbl_88B6C308[];
extern char lbl_88B6C320[];
extern char lbl_88B6C398[];
extern char lbl_88B6C3C8[];
extern char lbl_88B6C3E8[];
extern char lbl_88B6C490[];
extern char lbl_88B6C4A8[];
extern char lbl_88B6C4D8[];
extern char lbl_88B6C4F0[];
extern char lbl_88B6C598[];
extern char lbl_88B6C5E0[];
extern char lbl_88B6C6B8[];
extern char lbl_88B6C6E8[];
extern char lbl_88B6C700[];
extern char lbl_88B6C730[];
extern char lbl_88B6C7C8[];
extern char lbl_88B6C810[];
extern char lbl_88B6C828[];
extern char lbl_88B6C8B8[];
extern char lbl_88B6C990[];
extern char lbl_88B6C9D8[];
extern char lbl_88B6CA50[];
extern char lbl_88B6ED78[];
extern char lbl_88B6EDA8[];
extern char lbl_88B6EE68[];
extern char lbl_88B6EEF8[];
extern char lbl_88B6EF28[];
extern char lbl_88B6EF58[];
extern char lbl_88B6EF88[];
extern char lbl_88B6F000[];
extern char lbl_88B6F048[];
extern char lbl_88B6F0C0[];
extern char lbl_88B6F1F8[];
extern char lbl_88B6F210[];
extern char lbl_88B6F2B8[];
extern char lbl_88B6F300[];
extern char lbl_88B6F3D8[];
extern char lbl_88CC6A4C[];
extern char lbl_88CC6F5C[];
extern char lbl_88CC6F8C[];
extern char lbl_88CC6FBC[];
extern char lbl_88CC6FEC[];
extern char lbl_88CC701C[];
extern char lbl_88CC704C[];
extern char lbl_88CC707C[];
extern char lbl_88CC70AC[];
extern char lbl_88CC70DC[];
extern char lbl_88CC710C[];
extern char lbl_88CC713C[];
extern char lbl_88CC716C[];
extern char lbl_88CC719C[];
extern char lbl_88CC71CC[];
extern char lbl_88CC71FC[];
extern char lbl_88CC722C[];
extern char lbl_88CC725C[];
extern char lbl_88CC728C[];
extern char lbl_88CC72BC[];
extern char lbl_88CC72EC[];
extern char lbl_88CC731C[];
extern char lbl_88CC734C[];
extern char lbl_88CC737C[];
extern char lbl_88CC73AC[];
extern char lbl_88CC73DC[];
extern char lbl_88CC740C[];
extern char lbl_88CC743C[];
extern char lbl_88CC746C[];
extern char lbl_88CC749C[];
extern char lbl_88CC74CC[];
extern char lbl_88CC74FC[];
extern char lbl_88CC752C[];
extern char lbl_88CC755C[];
extern char lbl_88CC758C[];
extern char lbl_88CC75BC[];
extern char lbl_88CC75EC[];
extern char lbl_88CC761C[];
extern char lbl_88CC764C[];
extern char lbl_88CC767C[];
extern char lbl_88CC76AC[];
extern char lbl_88CC76DC[];
extern char lbl_88CC770C[];
extern char lbl_88CC773C[];
extern char lbl_88CC776C[];
extern char lbl_88CC779C[];
extern char lbl_88CC77CC[];
extern char lbl_88CC77FC[];
extern char lbl_88CC782C[];
extern char lbl_88CC785C[];
extern char lbl_88CC788C[];
extern char lbl_88CC78BC[];
extern char lbl_88CC78EC[];
extern char lbl_88CC791C[];
extern char lbl_88CC794C[];
extern char lbl_88CC797C[];
extern char lbl_88CC79AC[];
extern char lbl_88CC79DC[];
extern char lbl_88CC7A0C[];
extern char lbl_88CC7A3C[];
extern char lbl_88CC7A6C[];
extern char lbl_88CC7A9C[];
extern char lbl_88CC7ACC[];
extern char lbl_88CC7AFC[];
extern char lbl_88CC7B2C[];
extern char lbl_88CC7B5C[];
extern char lbl_88CC7B8C[];
extern char lbl_88CC7BBC[];
extern char lbl_88CC7BEC[];
extern char lbl_88CC7C1C[];
extern char lbl_88CC7C4C[];
extern char lbl_88CC7C7C[];
extern char lbl_88CC7CAC[];
extern char lbl_88CC7CDC[];
extern char lbl_88CC7D0C[];
extern char lbl_88CC7D3C[];
extern char lbl_88CC7D6C[];
extern char lbl_88CC7D9C[];
extern char lbl_88CC7DCC[];
extern char lbl_88CC7DFC[];
extern char lbl_88CC7E2C[];
extern char lbl_88CC7E5C[];
extern char lbl_88CC7E8C[];
extern char lbl_88CC7EBC[];
extern char lbl_88CC7EEC[];
extern char lbl_88CC7F1C[];
extern char lbl_88CC7F4C[];
extern char lbl_88CC7F7C[];
extern char lbl_88CC7FAC[];
extern char lbl_88CC7FDC[];
extern char lbl_88CC800C[];
extern char lbl_88CC803C[];
extern char lbl_88CC806C[];
extern char lbl_88CC809C[];
extern char lbl_88CC80CC[];
extern char lbl_88CC80FC[];
extern char lbl_88CC812C[];
extern char lbl_88CC815C[];
extern char lbl_88CC818C[];
extern char lbl_88CC81BC[];
extern char lbl_88CC81EC[];
extern char lbl_88CC821C[];
extern char lbl_88CC824C[];
extern char lbl_88CC827C[];
extern char lbl_88CC82AC[];
extern char lbl_88CC82DC[];
extern char lbl_88CC830C[];
extern char lbl_88CC833C[];
extern char lbl_88CC836C[];
extern char lbl_88CC839C[];
extern char lbl_88CC83CC[];
extern char lbl_88CC83FC[];
extern char lbl_88CC842C[];
extern char lbl_88CC845C[];
extern char lbl_88CC848C[];
extern char lbl_88CC84BC[];
extern char lbl_88CC84EC[];
extern char lbl_88CC851C[];
extern char lbl_88CC854C[];
extern char lbl_88CC857C[];
extern char lbl_88CC85AC[];
extern char lbl_88CC85DC[];
extern char lbl_88CC860C[];
extern char lbl_88CC863C[];
extern char lbl_88CC866C[];
extern char lbl_88CC869C[];
extern char lbl_88CC86CC[];
extern char lbl_88CC86FC[];
extern char lbl_88CC872C[];
extern char lbl_88CC875C[];
extern char lbl_88CC878C[];
extern char lbl_88CC87BC[];
extern char lbl_88CC87EC[];
extern char lbl_88CC881C[];
extern char lbl_88CC884C[];
extern char lbl_88CC88AC[];
extern char lbl_88CC88DC[];
extern char lbl_88CC890C[];
extern char lbl_88CC893C[];
extern char lbl_88CC896C[];
extern char lbl_88CC899C[];
extern char lbl_88CC89CC[];
extern char lbl_88CC89FC[];
extern char lbl_88CC8A2C[];
extern char lbl_88CC8A5C[];
extern char lbl_88CC8A8C[];
extern char lbl_88CC8ABC[];
extern char lbl_88CC8AEC[];
extern char lbl_88CC8B1C[];
extern char lbl_88CC8B4C[];
extern char lbl_88CC8B7C[];
extern char lbl_88CC8BAC[];
extern char lbl_88CC8BDC[];
extern char lbl_88CC8C0C[];
extern char lbl_88CC8C3C[];
extern char lbl_88CC8C6C[];
extern char lbl_88CC8C9C[];
extern char lbl_88CC8CCC[];
extern char lbl_88CC8CFC[];
extern char lbl_88CC8D2C[];
extern char lbl_88CC8D5C[];
extern char lbl_88CC8D8C[];
extern char lbl_88CC8DBC[];
extern char lbl_88CC8DEC[];
extern char lbl_88CC8E1C[];
extern char lbl_88CC8E4C[];
extern char lbl_88CC8E7C[];
extern char lbl_88CC8EAC[];
extern char lbl_88CC8EDC[];
extern char lbl_88CC8F0C[];
extern char lbl_88CC8F3C[];
extern char lbl_88CC8F6C[];
extern char lbl_88CC8F9C[];
extern char lbl_88CC8FCC[];
extern char lbl_88CC8FFC[];
extern char lbl_88CC902C[];
extern char lbl_88CC905C[];
extern char lbl_88CC908C[];
extern char lbl_88CC90BC[];
extern char lbl_88CC90EC[];
extern char lbl_88CC911C[];
extern char lbl_88CC914C[];
extern char lbl_88CC917C[];
extern char lbl_88CC91AC[];
extern char lbl_88CC91DC[];
extern char lbl_88CC920C[];
extern char lbl_88CC98FC[];
ts4_word fn_8841F080();

/* Swing_DLL.xex 0x88A12DF8: call_seq lbl_88B69B98, lbl_88041174, lbl_88CC6F5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69B98_88A12DF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6F5C, (ts4_word)(ts4_word)lbl_88041174, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69B98, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12E68: call_seq lbl_88B69BE0, lbl_88041194, lbl_88CC6F8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69BE0_88A12E68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6F8C, (ts4_word)(ts4_word)lbl_88041194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69BE0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12ED8: call_seq lbl_88054648, lbl_88B69C28, lbl_88CC6A4C, lbl_88040218, lbl_88CC6FBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88054648_88A12ED8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6FBC, (ts4_word)(ts4_word)lbl_88040218, (ts4_word)(ts4_word)lbl_88CC6A4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69C28, (ts4_word)12, (ts4_word)(ts4_word)lbl_88054648, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12F50: call_seq lbl_8805469C, lbl_88CC713C, lbl_88041128, lbl_88CC6FEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805469C_88A12F50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6FEC, (ts4_word)(ts4_word)lbl_88041128, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805469C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12FB8: call_seq lbl_88B69D50, lbl_88041930, lbl_88CC701C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69D50_88A12FB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC701C, (ts4_word)(ts4_word)lbl_88041930, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69D50, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13028: addr lbl_88B6ED78, u32@lbl_88B69D4C, u32@0x20 */
void ts4_addr_lbl_88B6ED78_88A13028(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6ED78) + 32) = (ts4_word)(*(ts4_word *)lbl_88B69D4C);
    return;
}

/* Swing_DLL.xex 0x88A13040: call_seq lbl_88B6ED78, lbl_88CC6FEC, lbl_88040260, lbl_88CC704C, lbl_880546D0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6ED78_88A13040(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC704C, (ts4_word)(ts4_word)lbl_88040260, (ts4_word)(ts4_word)lbl_88CC6FEC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880546D0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6ED78, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A130B8: call_seq lbl_88B69D98, lbl_88040200, lbl_88CC707C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69D98_88A130B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC707C, (ts4_word)(ts4_word)lbl_88040200, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69D98, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13128: call_seq lbl_88B69DF8, lbl_880401D8, lbl_88CC70AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69DF8_88A13128(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC70AC, (ts4_word)(ts4_word)lbl_880401D8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69DF8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13198: call_seq lbl_88B69E28, lbl_880401F0, lbl_88CC70DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69E28_88A13198(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC70DC, (ts4_word)(ts4_word)lbl_880401F0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69E28, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13208: call_seq lbl_8803C97C, lbl_88CC710C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803C97C_88A13208(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC710C, (ts4_word)(ts4_word)lbl_8803C97C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13268: call_seq lbl_88B69E40, lbl_88CC710C, lbl_8803C9DC, lbl_88CC713C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69E40_88A13268(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)(ts4_word)lbl_8803C9DC, (ts4_word)(ts4_word)lbl_88CC710C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69E40, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A132E0: call_seq lbl_88B69E78, lbl_8803CC5C, lbl_88CC716C, lbl_880546EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69E78_88A132E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC716C, (ts4_word)(ts4_word)lbl_8803CC5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880546EC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B69E78, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13350: call_seq lbl_88B69F20, lbl_8803CCC4, lbl_88CC719C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69F20_88A13350(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC719C, (ts4_word)(ts4_word)lbl_8803CCC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69F20, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A133C0: call_seq lbl_88B69F50, lbl_8803CCD4, lbl_88CC71CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69F50_88A133C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC71CC, (ts4_word)(ts4_word)lbl_8803CCD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69F50, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13430: addr lbl_88B6EDA8, u32@lbl_88B69E74, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88B6EDA8_88A13430(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B69E74;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6EDA8) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6EDA8) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A13450: call_seq lbl_88B6EDA8, lbl_8803D124, lbl_88CC71FC, lbl_88054860, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6EDA8_88A13450(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC71FC, (ts4_word)(ts4_word)lbl_8803D124, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88054860, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B6EDA8, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A134C0: call_seq lbl_88B69F88, lbl_8803D484, lbl_88CC722C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69F88_88A134C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC722C, (ts4_word)(ts4_word)lbl_8803D484, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69F88, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13530: call_seq lbl_88B69FB8, lbl_8803D4A8, lbl_88CC725C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69FB8_88A13530(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC725C, (ts4_word)(ts4_word)lbl_8803D4A8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69FB8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A135A0: addr lbl_88B6EE68, u32@lbl_88B69FD0, u32@0x50 */
void ts4_addr_lbl_88B6EE68_88A135A0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6EE68) + 80) = (ts4_word)(*(ts4_word *)lbl_88B69FD0);
    return;
}

/* Swing_DLL.xex 0x88A135B8: call_seq lbl_88B6EE68, lbl_8803D4C4, lbl_88CC728C, lbl_880548B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6EE68_88A135B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC728C, (ts4_word)(ts4_word)lbl_8803D4C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880548B4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6EE68, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13628: call_seq lbl_88B69FD4, lbl_8803CAF0, lbl_88CC72BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69FD4_88A13628(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC72BC, (ts4_word)(ts4_word)lbl_8803CAF0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69FD4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13698: call_seq lbl_88B6A004, lbl_8803D194, lbl_88CC72EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A004_88A13698(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC72EC, (ts4_word)(ts4_word)lbl_8803D194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A004, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13708: call_seq lbl_88B6A038, lbl_8803D2E0, lbl_88CC731C, lbl_880548D8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A038_88A13708(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC731C, (ts4_word)(ts4_word)lbl_8803D2E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880548D8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6A038, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13778: call_seq lbl_88B6A098, lbl_8803D6A0, lbl_88CC734C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A098_88A13778(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC734C, (ts4_word)(ts4_word)lbl_8803D6A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A098, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A137E8: call_seq lbl_88B6A188, lbl_8803D914, lbl_88CC737C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A188_88A137E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC737C, (ts4_word)(ts4_word)lbl_8803D914, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A188, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13858: call_seq lbl_88B6A1A0, lbl_8803D9E8, lbl_88CC73AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A1A0_88A13858(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC73AC, (ts4_word)(ts4_word)lbl_8803D9E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A1A0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A138C8: addr lbl_88B6EEF8, u32@lbl_88B6A230, u32@0x20 */
void ts4_addr_lbl_88B6EEF8_88A138C8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6EEF8) + 32) = (ts4_word)(*(ts4_word *)lbl_88B6A230);
    return;
}

/* Swing_DLL.xex 0x88A138E0: call_seq lbl_88B6EEF8, lbl_8803F988, lbl_88CC73DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6EEF8_88A138E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC73DC, (ts4_word)(ts4_word)lbl_8803F988, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6EEF8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13950: addr lbl_88B6EF28, u32@lbl_88B6A230, u32@0x20 */
void ts4_addr_lbl_88B6EF28_88A13950(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6EF28) + 32) = (ts4_word)(*(ts4_word *)lbl_88B6A230);
    return;
}

/* Swing_DLL.xex 0x88A13968: call_seq lbl_88B6EF28, lbl_8803F974, lbl_88CC740C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6EF28_88A13968(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC740C, (ts4_word)(ts4_word)lbl_8803F974, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6EF28, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A139D8: call_seq lbl_88B6A218, lbl_8804E4DC, lbl_88CC743C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A218_88A139D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC743C, (ts4_word)(ts4_word)lbl_8804E4DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A218, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13A48: addr lbl_88B6EF58, u32@lbl_88B6A230, u32@0x20 */
void ts4_addr_lbl_88B6EF58_88A13A48(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6EF58) + 32) = (ts4_word)(*(ts4_word *)lbl_88B6A230);
    return;
}

/* Swing_DLL.xex 0x88A13A60: call_seq lbl_88B6EF58, lbl_8803F960, lbl_88CC746C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6EF58_88A13A60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC746C, (ts4_word)(ts4_word)lbl_8803F960, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6EF58, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13AD0: call_seq lbl_88B6A234, lbl_8803F9B0, lbl_88CC749C, lbl_8805491C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A234_88A13AD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC749C, (ts4_word)(ts4_word)lbl_8803F9B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805491C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6A234, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13B40: call_seq lbl_88B6A264, lbl_8803F99C, lbl_88CC74CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A264_88A13B40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC74CC, (ts4_word)(ts4_word)lbl_8803F99C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A264, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13BB0: call_seq lbl_88B6A294, lbl_8804E4F4, lbl_88CC74FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A294_88A13BB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC74FC, (ts4_word)(ts4_word)lbl_8804E4F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A294, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13C20: call_seq lbl_88B6A2C4, lbl_88CC755C, lbl_8804E50C, lbl_88CC752C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A2C4_88A13C20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC752C, (ts4_word)(ts4_word)lbl_8804E50C, (ts4_word)(ts4_word)lbl_88CC755C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A2C4, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13C98: call_seq lbl_88B6A2DC, lbl_8804E524, lbl_88CC755C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A2DC_88A13C98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC755C, (ts4_word)(ts4_word)lbl_8804E524, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A2DC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13D08: call_seq lbl_88B6A30C, lbl_8804E53C, lbl_88CC758C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A30C_88A13D08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC758C, (ts4_word)(ts4_word)lbl_8804E53C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A30C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13D78: call_seq lbl_88B6A324, lbl_8804E560, lbl_88CC75BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A324_88A13D78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC75BC, (ts4_word)(ts4_word)lbl_8804E560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A324, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13DE8: call_seq lbl_88B6A358, lbl_8803F5C8, lbl_88CC75EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A358_88A13DE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC75EC, (ts4_word)(ts4_word)lbl_8803F5C8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A358, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13E58: call_seq lbl_88B6A400, lbl_88054050, lbl_88CC761C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A400_88A13E58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC761C, (ts4_word)(ts4_word)lbl_88054050, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A400, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13EC8: call_seq lbl_88B6A430, lbl_88054068, lbl_88CC764C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A430_88A13EC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC764C, (ts4_word)(ts4_word)lbl_88054068, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A430, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13F38: call_seq lbl_88B6A448, lbl_8804C310, lbl_88CC767C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A448_88A13F38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC767C, (ts4_word)(ts4_word)lbl_8804C310, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A448, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A13FA8: call_seq lbl_88B6A478, lbl_8803ED20, lbl_88CC76AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A478_88A13FA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC76AC, (ts4_word)(ts4_word)lbl_8803ED20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A478, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14018: addr lbl_88B6EF88, u32@lbl_88B6A354, u32@0x8 */
void ts4_addr_lbl_88B6EF88_88A14018(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6EF88) + 8) = (ts4_word)(*(ts4_word *)lbl_88B6A354);
    return;
}

/* Swing_DLL.xex 0x88A14030: call_seq lbl_88B6EF88, lbl_8804C33C, lbl_88CC76DC, lbl_88054948, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6EF88_88A14030(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC76DC, (ts4_word)(ts4_word)lbl_8804C33C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88054948, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6EF88, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A140A0: call_seq lbl_88B6A53C, lbl_8803ED28, lbl_88CC770C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A53C_88A140A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC770C, (ts4_word)(ts4_word)lbl_8803ED28, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A53C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14110: call_seq lbl_88B6A570, lbl_8803ED14, lbl_88CC773C, lbl_8805498C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A570_88A14110(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC773C, (ts4_word)(ts4_word)lbl_8803ED14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805498C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6A570, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14180: addr lbl_88B6F000, u32@lbl_88B6A56C, u32@0x20 */
void ts4_addr_lbl_88B6F000_88A14180(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6F000) + 32) = (ts4_word)(*(ts4_word *)lbl_88B6A56C);
    return;
}

/* Swing_DLL.xex 0x88A14198: call_seq lbl_88B6F000, lbl_8804E57C, lbl_88CC776C, lbl_880549C8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6F000_88A14198(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC776C, (ts4_word)(ts4_word)lbl_8804E57C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880549C8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6F000, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14208: call_seq lbl_88B6A630, lbl_8804C348, lbl_88CC779C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A630_88A14208(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC779C, (ts4_word)(ts4_word)lbl_8804C348, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A630, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14278: call_seq lbl_88B6A648, lbl_8804C358, lbl_88CC77CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A648_88A14278(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC77CC, (ts4_word)(ts4_word)lbl_8804C358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A648, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A142E8: addr lbl_88B6F048, u32@lbl_88B6A678, u32@0x8 */
void ts4_addr_lbl_88B6F048_88A142E8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6F048) + 8) = (ts4_word)(*(ts4_word *)lbl_88B6A678);
    return;
}

/* Swing_DLL.xex 0x88A14300: call_seq lbl_88B6F048, lbl_8804C380, lbl_88CC77FC, lbl_88054A04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6F048_88A14300(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC77FC, (ts4_word)(ts4_word)lbl_8804C380, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88054A04, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6F048, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14370: call_seq lbl_88B6A67C, lbl_88042408, lbl_88CC782C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A67C_88A14370(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC782C, (ts4_word)(ts4_word)lbl_88042408, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A67C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A143E0: call_seq lbl_88B6A698, lbl_880423F8, lbl_88CC785C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A698_88A143E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC785C, (ts4_word)(ts4_word)lbl_880423F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A698, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14450: call_seq lbl_88B6A6E0, lbl_8804C390, lbl_88CC788C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A6E0_88A14450(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC788C, (ts4_word)(ts4_word)lbl_8804C390, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A6E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A144C0: call_seq lbl_88B6A710, lbl_8804C3A0, lbl_88CC78BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A710_88A144C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC78BC, (ts4_word)(ts4_word)lbl_8804C3A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A710, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14530: call_seq lbl_88B6A830, lbl_8804C3B0, lbl_88CC78EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A830_88A14530(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC78EC, (ts4_word)(ts4_word)lbl_8804C3B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A830, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A145A0: call_seq lbl_88B6A8C0, lbl_8804C3C4, lbl_88CC791C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A8C0_88A145A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC791C, (ts4_word)(ts4_word)lbl_8804C3C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A8C0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14610: call_seq lbl_88B6A980, lbl_8804C3DC, lbl_88CC794C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6A980_88A14610(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC794C, (ts4_word)(ts4_word)lbl_8804C3DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6A980, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14680: call_seq lbl_88B6AA58, lbl_8804C3F8, lbl_88CC797C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6AA58_88A14680(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC797C, (ts4_word)(ts4_word)lbl_8804C3F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6AA58, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A146F0: call_seq lbl_88B6AB18, lbl_8804C410, lbl_88CC79AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6AB18_88A146F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC79AC, (ts4_word)(ts4_word)lbl_8804C410, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6AB18, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14760: call_seq lbl_88B6ABC0, lbl_88054A18, lbl_8803F5BC, lbl_88CC79DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6ABC0_88A14760(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC79DC, (ts4_word)(ts4_word)lbl_8803F5BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6ABC0, (ts4_word)12, (ts4_word)(ts4_word)lbl_88054A18, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A147D8: call_seq lbl_88B6ACE0, lbl_8804C428, lbl_88CC7A0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6ACE0_88A147D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7A0C, (ts4_word)(ts4_word)lbl_8804C428, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6ACE0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14848: call_seq lbl_88B6AD40, lbl_8803F5E0, lbl_88CC7A3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6AD40_88A14848(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7A3C, (ts4_word)(ts4_word)lbl_8803F5E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6AD40, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A148B8: call_seq lbl_88B6AE48, lbl_88040278, lbl_88CC7A6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6AE48_88A148B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7A6C, (ts4_word)(ts4_word)lbl_88040278, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6AE48, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14928: call_seq lbl_88B6AF20, lbl_8803ED58, lbl_88CC7A9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6AF20_88A14928(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7A9C, (ts4_word)(ts4_word)lbl_8803ED58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6AF20, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14998: call_seq lbl_88B6AF68, lbl_8803ED40, lbl_88CC7ACC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6AF68_88A14998(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7ACC, (ts4_word)(ts4_word)lbl_8803ED40, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6AF68, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14A08: call_seq lbl_88B6AF80, lbl_880433FC, lbl_88CC7AFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6AF80_88A14A08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7AFC, (ts4_word)(ts4_word)lbl_880433FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6AF80, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14A78: call_seq lbl_88B6AFC8, lbl_8804342C, lbl_88CC7B2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6AFC8_88A14A78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7B2C, (ts4_word)(ts4_word)lbl_8804342C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6AFC8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14AE8: call_seq lbl_88B6AFE0, lbl_88CC713C, lbl_8803ED7C, lbl_88CC7B5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6AFE0_88A14AE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7B5C, (ts4_word)(ts4_word)lbl_8803ED7C, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6AFE0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14B60: call_seq lbl_88B6B028, lbl_88046454, lbl_88CC7B8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B028_88A14B60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7B8C, (ts4_word)(ts4_word)lbl_88046454, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B028, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14BD0: call_seq lbl_88B6B088, lbl_88CC7B8C, lbl_8804233C, lbl_88CC7BBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B088_88A14BD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7BBC, (ts4_word)(ts4_word)lbl_8804233C, (ts4_word)(ts4_word)lbl_88CC7B8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B088, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14C48: call_seq lbl_880469C4, lbl_88CC7BEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880469C4_88A14C48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7BEC, (ts4_word)(ts4_word)lbl_880469C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14CA8: call_seq lbl_88B6B0D0, lbl_88CC98FC, lbl_88042E48, lbl_88CC7C1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B0D0_88A14CA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7C1C, (ts4_word)(ts4_word)lbl_88042E48, (ts4_word)(ts4_word)lbl_88CC98FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B0D0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14D20: call_seq lbl_88046B60, lbl_88CC7C4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046B60_88A14D20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7C4C, (ts4_word)(ts4_word)lbl_88046B60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14D80: call_seq lbl_88CC713C, lbl_88042318, lbl_88CC7C7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC713C_88A14D80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7C7C, (ts4_word)(ts4_word)lbl_88042318, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14DE8: call_seq lbl_88046A84, lbl_88CC7CAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A84_88A14DE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7CAC, (ts4_word)(ts4_word)lbl_88046A84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14E48: call_seq lbl_88B6B130, lbl_88CC7C7C, lbl_8804232C, lbl_88CC7CDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B130_88A14E48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7CDC, (ts4_word)(ts4_word)lbl_8804232C, (ts4_word)(ts4_word)lbl_88CC7C7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B130, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14EC0: call_seq lbl_88B6B160, lbl_88CC7C7C, lbl_8804690C, lbl_88CC7D0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B160_88A14EC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7D0C, (ts4_word)(ts4_word)lbl_8804690C, (ts4_word)(ts4_word)lbl_88CC7C7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B160, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14F38: call_seq lbl_88CC7C7C, lbl_8804671C, lbl_88CC7D3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC7C7C_88A14F38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7D3C, (ts4_word)(ts4_word)lbl_8804671C, (ts4_word)(ts4_word)lbl_88CC7C7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A14FA0: call_seq lbl_88046A50, lbl_88CC7D6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A50_88A14FA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7D6C, (ts4_word)(ts4_word)lbl_88046A50, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15000: call_seq lbl_88B6B178, lbl_88CC713C, lbl_88041284, lbl_88CC7D9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B178_88A15000(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7D9C, (ts4_word)(ts4_word)lbl_88041284, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B178, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15078: call_seq lbl_88046994, lbl_88CC7DCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046994_88A15078(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7DCC, (ts4_word)(ts4_word)lbl_88046994, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A150D8: call_seq lbl_88B6B190, lbl_88CC7DCC, lbl_88046678, lbl_88CC7DFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B190_88A150D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7DFC, (ts4_word)(ts4_word)lbl_88046678, (ts4_word)(ts4_word)lbl_88CC7DCC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B190, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15150: call_seq lbl_88B6B1A8, lbl_88046220, lbl_88CC7E2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B1A8_88A15150(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7E2C, (ts4_word)(ts4_word)lbl_88046220, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B1A8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A151C0: call_seq lbl_88B6B208, lbl_88CC7F4C, lbl_8804694C, lbl_88CC7E5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B208_88A151C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7E5C, (ts4_word)(ts4_word)lbl_8804694C, (ts4_word)(ts4_word)lbl_88CC7F4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B208, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15238: call_seq lbl_88B6B220, lbl_88CC7D9C, lbl_88040110, lbl_88CC7E8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B220_88A15238(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7E8C, (ts4_word)(ts4_word)lbl_88040110, (ts4_word)(ts4_word)lbl_88CC7D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B220, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A152B0: call_seq lbl_88B6B250, lbl_88CC7D9C, lbl_88040100, lbl_88CC7EBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B250_88A152B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7EBC, (ts4_word)(ts4_word)lbl_88040100, (ts4_word)(ts4_word)lbl_88CC7D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B250, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15328: call_seq lbl_88B6B268, lbl_88CC7F4C, lbl_8804011C, lbl_88CC7EEC, lbl_88054A90, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B268_88A15328(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7EEC, (ts4_word)(ts4_word)lbl_8804011C, (ts4_word)(ts4_word)lbl_88CC7F4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88054A90, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6B268, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A153A0: call_seq lbl_88B6B298, lbl_88CC7D9C, lbl_880400A8, lbl_88CC7F1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B298_88A153A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7F1C, (ts4_word)(ts4_word)lbl_880400A8, (ts4_word)(ts4_word)lbl_88CC7D9C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B298, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15418: call_seq lbl_88B6B2B0, lbl_88CC83FC, lbl_88042370, lbl_88CC7F4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B2B0_88A15418(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7F4C, (ts4_word)(ts4_word)lbl_88042370, (ts4_word)(ts4_word)lbl_88CC83FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B2B0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15490: call_seq lbl_88B6B2C8, lbl_88CC815C, lbl_88041B24, lbl_88CC7F7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B2C8_88A15490(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7F7C, (ts4_word)(ts4_word)lbl_88041B24, (ts4_word)(ts4_word)lbl_88CC815C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B2C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15508: call_seq lbl_88B6B2E0, lbl_88CC7F1C, lbl_880468C8, lbl_88CC7FAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B2E0_88A15508(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7FAC, (ts4_word)(ts4_word)lbl_880468C8, (ts4_word)(ts4_word)lbl_88CC7F1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B2E0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15580: call_seq lbl_88B6B328, lbl_88CC7F4C, lbl_880400E8, lbl_88CC7FDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B328_88A15580(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC7FDC, (ts4_word)(ts4_word)lbl_880400E8, (ts4_word)(ts4_word)lbl_88CC7F4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B328, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A155F8: call_seq lbl_88B6B358, lbl_88CC7F4C, lbl_880400D0, lbl_88CC800C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B358_88A155F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC800C, (ts4_word)(ts4_word)lbl_880400D0, (ts4_word)(ts4_word)lbl_88CC7F4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B358, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15670: call_seq lbl_88B6B388, lbl_880463D4, lbl_88CC803C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B388_88A15670(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC803C, (ts4_word)(ts4_word)lbl_880463D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B388, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A156E0: call_seq lbl_88B6B3D0, lbl_88CC7F4C, lbl_88046868, lbl_88CC806C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B3D0_88A156E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC806C, (ts4_word)(ts4_word)lbl_88046868, (ts4_word)(ts4_word)lbl_88CC7F4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B3D0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15758: call_seq lbl_88B6B450, lbl_88CC7F4C, lbl_8803EFC0, lbl_88CC809C, lbl_88054ACC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B450_88A15758(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC809C, (ts4_word)(ts4_word)lbl_8803EFC0, (ts4_word)(ts4_word)lbl_88CC7F4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88054ACC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6B450, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A157D0: call_seq lbl_88CC81EC, lbl_880467DC, lbl_88CC80CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC81EC_88A157D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC80CC, (ts4_word)(ts4_word)lbl_880467DC, (ts4_word)(ts4_word)lbl_88CC81EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15838: call_seq lbl_88CC7D9C, lbl_88046AE0, lbl_88CC80FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC7D9C_88A15838(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC80FC, (ts4_word)(ts4_word)lbl_88046AE0, (ts4_word)(ts4_word)lbl_88CC7D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A158A0: call_seq lbl_88B6B4C8, lbl_88042358, lbl_88CC812C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B4C8_88A158A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC812C, (ts4_word)(ts4_word)lbl_88042358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B4C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15910: call_seq lbl_88B6B4F8, lbl_88CC7F1C, lbl_8804234C, lbl_88CC815C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B4F8_88A15910(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC815C, (ts4_word)(ts4_word)lbl_8804234C, (ts4_word)(ts4_word)lbl_88CC7F1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B4F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15988: call_seq lbl_88B6B510, lbl_88046320, lbl_88CC818C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B510_88A15988(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC818C, (ts4_word)(ts4_word)lbl_88046320, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B510, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A159F8: addr lbl_88B6F0C0, u32@lbl_88B6B44C, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88B6F0C0_88A159F8(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B6B44C;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6F0C0) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6F0C0) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A15A18: call_seq lbl_88B6F0C0, lbl_8803EFE8, lbl_88CC81BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6F0C0_88A15A18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC81BC, (ts4_word)(ts4_word)lbl_8803EFE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6F0C0, (ts4_word)13, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15A88: call_seq lbl_88B6B530, lbl_88CC7F1C, lbl_8803EF9C, lbl_88CC81EC, lbl_88054B20, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B530_88A15A88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC81EC, (ts4_word)(ts4_word)lbl_8803EF9C, (ts4_word)(ts4_word)lbl_88CC7F1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88054B20, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B6B530, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15B00: call_seq lbl_88B6B5A8, lbl_88CC7EBC, lbl_880423C0, lbl_88CC821C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B5A8_88A15B00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC821C, (ts4_word)(ts4_word)lbl_880423C0, (ts4_word)(ts4_word)lbl_88CC7EBC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B5A8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15B78: call_seq lbl_88B6B5C0, lbl_880462E8, lbl_88CC824C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B5C0_88A15B78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC824C, (ts4_word)(ts4_word)lbl_880462E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B5C0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15BE8: call_seq lbl_88B6B5F0, lbl_88CC7D9C, lbl_8804675C, lbl_88CC827C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B5F0_88A15BE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC827C, (ts4_word)(ts4_word)lbl_8804675C, (ts4_word)(ts4_word)lbl_88CC7D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B5F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15C60: call_seq lbl_88B6B620, lbl_88CC83FC, lbl_8803F9D4, lbl_88CC82AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B620_88A15C60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC82AC, (ts4_word)(ts4_word)lbl_8803F9D4, (ts4_word)(ts4_word)lbl_88CC83FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B620, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15CD8: call_seq lbl_88CC7D9C, lbl_88046AB4, lbl_88CC82DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC7D9C_88A15CD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC82DC, (ts4_word)(ts4_word)lbl_88046AB4, (ts4_word)(ts4_word)lbl_88CC7D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15D40: call_seq lbl_88B6B650, lbl_88CC80FC, lbl_880466D4, lbl_88CC830C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B650_88A15D40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC830C, (ts4_word)(ts4_word)lbl_880466D4, (ts4_word)(ts4_word)lbl_88CC80FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B650, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15DB8: call_seq lbl_88B6B698, lbl_88CC80FC, lbl_88046A18, lbl_88CC833C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B698_88A15DB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC833C, (ts4_word)(ts4_word)lbl_88046A18, (ts4_word)(ts4_word)lbl_88CC80FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B698, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15E30: call_seq lbl_88B6B740, lbl_880423A4, lbl_88CC836C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B740_88A15E30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC836C, (ts4_word)(ts4_word)lbl_880423A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B740, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15EA0: call_seq lbl_88B6B788, lbl_88CC7F1C, lbl_88042390, lbl_88CC839C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B788_88A15EA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC839C, (ts4_word)(ts4_word)lbl_88042390, (ts4_word)(ts4_word)lbl_88CC7F1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B788, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15F18: call_seq lbl_88CC7F4C, lbl_88043ED0, lbl_88CC83CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC7F4C_88A15F18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC83CC, (ts4_word)(ts4_word)lbl_88043ED0, (ts4_word)(ts4_word)lbl_88CC7F4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15F80: call_seq lbl_88CC7D9C, lbl_8804696C, lbl_88CC83FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC7D9C_88A15F80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC83FC, (ts4_word)(ts4_word)lbl_8804696C, (ts4_word)(ts4_word)lbl_88CC7D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A15FE8: call_seq lbl_88B6B7E8, lbl_88CC713C, lbl_8803F00C, lbl_88CC842C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B7E8_88A15FE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC842C, (ts4_word)(ts4_word)lbl_8803F00C, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B7E8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16060: call_seq lbl_88B6B878, lbl_88CC81EC, lbl_88046574, lbl_88CC845C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B878_88A16060(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC845C, (ts4_word)(ts4_word)lbl_88046574, (ts4_word)(ts4_word)lbl_88CC81EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B878, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A160D8: call_seq lbl_88B6B890, lbl_88CC833C, lbl_88046518, lbl_88CC848C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B890_88A160D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC848C, (ts4_word)(ts4_word)lbl_88046518, (ts4_word)(ts4_word)lbl_88CC833C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B890, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16150: call_seq lbl_88B6B8C0, lbl_88CC7D9C, lbl_880400BC, lbl_88CC84BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B8C0_88A16150(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC84BC, (ts4_word)(ts4_word)lbl_880400BC, (ts4_word)(ts4_word)lbl_88CC7D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B8C0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A161C8: call_seq lbl_88B6B908, lbl_88CC7F4C, lbl_88042380, lbl_88CC84EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B908_88A161C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC84EC, (ts4_word)(ts4_word)lbl_88042380, (ts4_word)(ts4_word)lbl_88CC7F4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B908, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16240: call_seq lbl_88B6B950, lbl_88CC7EBC, lbl_880423D4, lbl_88CC851C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B950_88A16240(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC851C, (ts4_word)(ts4_word)lbl_880423D4, (ts4_word)(ts4_word)lbl_88CC7EBC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B950, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A162B8: call_seq lbl_88B6B968, lbl_88CC7F1C, lbl_88046498, lbl_88CC854C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B968_88A162B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC854C, (ts4_word)(ts4_word)lbl_88046498, (ts4_word)(ts4_word)lbl_88CC7F1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B968, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16330: addr lbl_88B6F1F8, u32@lbl_88B6B52C, u32@0x8 */
void ts4_addr_lbl_88B6F1F8_88A16330(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6F1F8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B6B52C);
    return;
}

/* Swing_DLL.xex 0x88A16348: call_seq lbl_88B6F1F8, lbl_8804215C, lbl_88CC857C, lbl_88054C40, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6F1F8_88A16348(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)(ts4_word)lbl_8804215C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88054C40, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B6F1F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A163B8: call_seq lbl_88B6B99C, lbl_88CC857C, lbl_88041B0C, lbl_88CC85AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B99C_88A163B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC85AC, (ts4_word)(ts4_word)lbl_88041B0C, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B99C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16430: call_seq lbl_88B6B9CC, lbl_88041AFC, lbl_88CC85DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B9CC_88A16430(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC85DC, (ts4_word)(ts4_word)lbl_88041AFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B9CC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A164A0: call_seq lbl_88CC857C, lbl_88046098, lbl_88CC860C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC857C_88A164A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC860C, (ts4_word)(ts4_word)lbl_88046098, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16508: call_seq lbl_88B6B9E4, lbl_88CC857C, lbl_88045C08, lbl_88CC863C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B9E4_88A16508(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC863C, (ts4_word)(ts4_word)lbl_88045C08, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B9E4, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16580: call_seq lbl_88B6B9FC, lbl_88CC857C, lbl_88045D4C, lbl_88CC866C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6B9FC_88A16580(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC866C, (ts4_word)(ts4_word)lbl_88045D4C, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6B9FC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A165F8: call_seq lbl_88B6BA2C, lbl_88CC857C, lbl_88045D00, lbl_88CC869C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6BA2C_88A165F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC869C, (ts4_word)(ts4_word)lbl_88045D00, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BA2C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16670: call_seq lbl_88B6BA5C, lbl_88CC857C, lbl_88045D94, lbl_88CC86CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6BA5C_88A16670(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC86CC, (ts4_word)(ts4_word)lbl_88045D94, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BA5C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A166E8: call_seq lbl_88B6BA8C, lbl_88CC857C, lbl_88045E48, lbl_88CC86FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6BA8C_88A166E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC86FC, (ts4_word)(ts4_word)lbl_88045E48, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BA8C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16760: call_seq lbl_88B6BAA4, lbl_88CC857C, lbl_88045FF4, lbl_88CC872C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6BAA4_88A16760(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC872C, (ts4_word)(ts4_word)lbl_88045FF4, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BAA4, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A167D8: call_seq lbl_88B6BAC0, lbl_88CC857C, lbl_88045F18, lbl_88CC875C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6BAC0_88A167D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC875C, (ts4_word)(ts4_word)lbl_88045F18, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BAC0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16850: call_seq lbl_88B6BB08, lbl_88CC857C, lbl_88045F84, lbl_88CC878C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6BB08_88A16850(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC878C, (ts4_word)(ts4_word)lbl_88045F84, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BB08, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A168C8: call_seq lbl_88B6BB50, lbl_88CC857C, lbl_880461A4, lbl_88CC87BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6BB50_88A168C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC87BC, (ts4_word)(ts4_word)lbl_880461A4, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BB50, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16940: call_seq lbl_88B6BB68, lbl_88CC857C, lbl_88046178, lbl_88CC87EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6BB68_88A16940(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC87EC, (ts4_word)(ts4_word)lbl_88046178, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BB68, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A169B8: call_seq lbl_88054C68, lbl_88B6BB98, lbl_88CC857C, lbl_88046108, lbl_88CC881C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88054C68_88A169B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC881C, (ts4_word)(ts4_word)lbl_88046108, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BB98, (ts4_word)5, (ts4_word)(ts4_word)lbl_88054C68, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16A30: call_seq lbl_88054C80, lbl_88B6BC10, lbl_88CC857C, lbl_88045BCC, lbl_88CC884C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88054C80_88A16A30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC884C, (ts4_word)(ts4_word)lbl_88045BCC, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BC10, (ts4_word)6, (ts4_word)(ts4_word)lbl_88054C80, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16AA8: addr lbl_88B6F210, u32@lbl_88B6BABC, u32@0x50 */
void ts4_addr_lbl_88B6F210_88A16AA8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6F210) + 80) = (ts4_word)(*(ts4_word *)lbl_88B6BABC);
    return;
}

/* Swing_DLL.xex 0x88A16B38: call_seq lbl_88B6BCA0, lbl_88CC857C, lbl_88046144, lbl_88CC88AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6BCA0_88A16B38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC88AC, (ts4_word)(ts4_word)lbl_88046144, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BCA0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16BB0: call_seq lbl_88B6BD00, lbl_88CC857C, lbl_880460D0, lbl_88CC88DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6BD00_88A16BB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC88DC, (ts4_word)(ts4_word)lbl_880460D0, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BD00, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16C28: call_seq lbl_88B6BDA8, lbl_88CC857C, lbl_88045DD8, lbl_88CC890C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6BDA8_88A16C28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC890C, (ts4_word)(ts4_word)lbl_88045DD8, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BDA8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16CA0: call_seq lbl_88B6BE20, lbl_88CC857C, lbl_88045FC0, lbl_88CC893C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6BE20_88A16CA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC893C, (ts4_word)(ts4_word)lbl_88045FC0, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BE20, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16D18: call_seq lbl_88B6BE68, lbl_88CC857C, lbl_88045F4C, lbl_88CC896C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6BE68_88A16D18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC896C, (ts4_word)(ts4_word)lbl_88045F4C, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BE68, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16D90: call_seq lbl_88B6BEF8, lbl_88CC857C, lbl_88045E10, lbl_88CC899C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6BEF8_88A16D90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC899C, (ts4_word)(ts4_word)lbl_88045E10, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BEF8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16E08: call_seq lbl_88B6BF58, lbl_88CC857C, lbl_880422DC, lbl_88CC89CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6BF58_88A16E08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC89CC, (ts4_word)(ts4_word)lbl_880422DC, (ts4_word)(ts4_word)lbl_88CC857C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BF58, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16E80: call_seq lbl_88B6BFA0, lbl_88CC89CC, lbl_88045C4C, lbl_88CC89FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6BFA0_88A16E80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC89FC, (ts4_word)(ts4_word)lbl_88045C4C, (ts4_word)(ts4_word)lbl_88CC89CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BFA0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16EF8: call_seq lbl_88B6BFD0, lbl_88CC89CC, lbl_88043EE0, lbl_88CC8A2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6BFD0_88A16EF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8A2C, (ts4_word)(ts4_word)lbl_88043EE0, (ts4_word)(ts4_word)lbl_88CC89CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6BFD0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16F70: call_seq lbl_88CC89CC, lbl_88045B88, lbl_88CC8A5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC89CC_88A16F70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8A5C, (ts4_word)(ts4_word)lbl_88045B88, (ts4_word)(ts4_word)lbl_88CC89CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A16FD8: call_seq lbl_88B6C000, lbl_88CC89CC, lbl_88045E90, lbl_88CC8A8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C000_88A16FD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8A8C, (ts4_word)(ts4_word)lbl_88045E90, (ts4_word)(ts4_word)lbl_88CC89CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C000, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17050: call_seq lbl_88B6C018, lbl_88CC713C, lbl_88047050, lbl_88CC8ABC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C018_88A17050(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8ABC, (ts4_word)(ts4_word)lbl_88047050, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C018, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A170C8: call_seq lbl_88B6C078, lbl_88CC8ABC, lbl_88045B44, lbl_88CC8AEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C078_88A170C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8AEC, (ts4_word)(ts4_word)lbl_88045B44, (ts4_word)(ts4_word)lbl_88CC8ABC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C078, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17140: call_seq lbl_88B6C090, lbl_88CC8ABC, lbl_88045B24, lbl_88CC8B1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C090_88A17140(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8B1C, (ts4_word)(ts4_word)lbl_88045B24, (ts4_word)(ts4_word)lbl_88CC8ABC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C090, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A171B8: call_seq lbl_88B6C0C0, lbl_88CC8ABC, lbl_880459C0, lbl_88CC8B4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C0C0_88A171B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8B4C, (ts4_word)(ts4_word)lbl_880459C0, (ts4_word)(ts4_word)lbl_88CC8ABC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C0C0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17230: addr lbl_88B6F2B8, u32@lbl_88B6C0D8, u32@0x8 */
void ts4_addr_lbl_88B6F2B8_88A17230(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6F2B8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B6C0D8);
    return;
}

/* Swing_DLL.xex 0x88A17248: call_seq lbl_88B6F2B8, lbl_88045224, lbl_88CC8B7C, lbl_88054D08, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6F2B8_88A17248(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8B7C, (ts4_word)(ts4_word)lbl_88045224, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88054D08, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6F2B8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A172B8: call_seq lbl_88B6C0DC, lbl_88045194, lbl_88CC8BAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C0DC_88A172B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8BAC, (ts4_word)(ts4_word)lbl_88045194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C0DC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17328: call_seq lbl_88B6C0F8, lbl_8803EF90, lbl_88CC8BDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C0F8_88A17328(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8BDC, (ts4_word)(ts4_word)lbl_8803EF90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C0F8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17398: call_seq lbl_88B6C140, lbl_88CC713C, lbl_8803FA04, lbl_88CC8C0C, lbl_88054DC0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C140_88A17398(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8C0C, (ts4_word)(ts4_word)lbl_8803FA04, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88054DC0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6C140, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17408: call_seq lbl_88B6C158, lbl_88042170, lbl_88CC8C3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C158_88A17408(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8C3C, (ts4_word)(ts4_word)lbl_88042170, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C158, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17478: addr lbl_88B6F300, u32@lbl_88B6C1B8, u32@0x68 */
void ts4_addr_lbl_88B6F300_88A17478(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6F300) + 104) = (ts4_word)(*(ts4_word *)lbl_88B6C1B8);
    return;
}

/* Swing_DLL.xex 0x88A17490: call_seq lbl_88B6F300, lbl_88CC713C, lbl_8803F0C8, lbl_88CC8C6C, lbl_88054E1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6F300_88A17490(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8C6C, (ts4_word)(ts4_word)lbl_8803F0C8, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88054E1C, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B6F300, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17508: call_seq lbl_88B6C1C4, lbl_880422B8, lbl_88CC8C9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C1C4_88A17508(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8C9C, (ts4_word)(ts4_word)lbl_880422B8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C1C4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17578: call_seq lbl_88B6C1F4, lbl_88CC8C0C, lbl_880403DC, lbl_88CC8CCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C1F4_88A17578(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8CCC, (ts4_word)(ts4_word)lbl_880403DC, (ts4_word)(ts4_word)lbl_88CC8C0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C1F4, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A175F0: call_seq lbl_88B6C210, lbl_8804229C, lbl_88CC8CFC, lbl_88054E60, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C210_88A175F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8CFC, (ts4_word)(ts4_word)lbl_8804229C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88054E60, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6C210, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17660: call_seq lbl_88B6C258, lbl_88CC8C0C, lbl_88040394, lbl_88CC8D2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C258_88A17660(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8D2C, (ts4_word)(ts4_word)lbl_88040394, (ts4_word)(ts4_word)lbl_88CC8C0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C258, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A176D8: call_seq lbl_88B6C278, lbl_88042260, lbl_88CC8D5C, lbl_88054E8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C278_88A176D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8D5C, (ts4_word)(ts4_word)lbl_88042260, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88054E8C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6C278, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17748: call_seq lbl_88B6C308, lbl_88CC8C0C, lbl_8803F690, lbl_88CC8D8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C308_88A17748(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8D8C, (ts4_word)(ts4_word)lbl_8803F690, (ts4_word)(ts4_word)lbl_88CC8C0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C308, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A177C0: call_seq lbl_88B6C320, lbl_88CC8DEC, lbl_88045734, lbl_88CC8DBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C320_88A177C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8DBC, (ts4_word)(ts4_word)lbl_88045734, (ts4_word)(ts4_word)lbl_88CC8DEC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C320, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17838: call_seq lbl_88CC713C, lbl_88045A30, lbl_88CC8DEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC713C_88A17838(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8DEC, (ts4_word)(ts4_word)lbl_88045A30, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A178A0: addr lbl_88B6F3D8, u32@lbl_88B6C274, u32@0x50 */
void ts4_addr_lbl_88B6F3D8_88A178A0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6F3D8) + 80) = (ts4_word)(*(ts4_word *)lbl_88B6C274);
    return;
}

/* Swing_DLL.xex 0x88A178B8: call_seq lbl_88B6F3D8, lbl_88CC8C0C, lbl_88040364, lbl_88CC8E1C, lbl_88054EC8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6F3D8_88A178B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8E1C, (ts4_word)(ts4_word)lbl_88040364, (ts4_word)(ts4_word)lbl_88CC8C0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88054EC8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6F3D8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17930: call_seq lbl_88B6C398, lbl_8804223C, lbl_88CC8E4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C398_88A17930(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8E4C, (ts4_word)(ts4_word)lbl_8804223C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C398, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A179A0: call_seq lbl_88B6C3C8, lbl_88CC8C0C, lbl_88040344, lbl_88CC8E7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C3C8_88A179A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8E7C, (ts4_word)(ts4_word)lbl_88040344, (ts4_word)(ts4_word)lbl_88CC8C0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C3C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17A18: call_seq lbl_88B6C3E8, lbl_8804221C, lbl_88CC8EAC, lbl_88054EEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C3E8_88A17A18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8EAC, (ts4_word)(ts4_word)lbl_8804221C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88054EEC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6C3E8, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17A88: call_seq lbl_88B6C490, lbl_88CC8C0C, lbl_8803F048, lbl_88CC8EDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C490_88A17A88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8EDC, (ts4_word)(ts4_word)lbl_8803F048, (ts4_word)(ts4_word)lbl_88CC8C0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C490, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17B00: call_seq lbl_88B6C4A8, lbl_880421A0, lbl_88CC8F0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C4A8_88A17B00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8F0C, (ts4_word)(ts4_word)lbl_880421A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C4A8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17B70: call_seq lbl_88B6C4D8, lbl_88CC8C0C, lbl_880402E4, lbl_88CC8F3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C4D8_88A17B70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8F3C, (ts4_word)(ts4_word)lbl_880402E4, (ts4_word)(ts4_word)lbl_88CC8C0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C4D8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17BE8: call_seq lbl_88B6C4F0, lbl_88042184, lbl_88CC8F6C, lbl_88054F20, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C4F0_88A17BE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8F6C, (ts4_word)(ts4_word)lbl_88042184, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88054F20, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6C4F0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17C58: call_seq lbl_88B6C598, lbl_88CC8C0C, lbl_880402CC, lbl_88CC8F9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C598_88A17C58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8F9C, (ts4_word)(ts4_word)lbl_880402CC, (ts4_word)(ts4_word)lbl_88CC8C0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C598, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17CD0: call_seq lbl_88B6C5E0, lbl_88CC8C0C, lbl_8803F6B0, lbl_88CC8FCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C5E0_88A17CD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8FCC, (ts4_word)(ts4_word)lbl_8803F6B0, (ts4_word)(ts4_word)lbl_88CC8C0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C5E0, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17D48: call_seq lbl_88CC8C0C, lbl_88045AFC, lbl_88CC8FFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC8C0C_88A17D48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC8FFC, (ts4_word)(ts4_word)lbl_88045AFC, (ts4_word)(ts4_word)lbl_88CC8C0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17DB0: call_seq lbl_88B6C6B8, lbl_88CC8C6C, lbl_8804589C, lbl_88CC902C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C6B8_88A17DB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC902C, (ts4_word)(ts4_word)lbl_8804589C, (ts4_word)(ts4_word)lbl_88CC8C6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C6B8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17E28: call_seq lbl_88B6C6E8, lbl_88CC8ABC, lbl_88045860, lbl_88CC905C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C6E8_88A17E28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC905C, (ts4_word)(ts4_word)lbl_88045860, (ts4_word)(ts4_word)lbl_88CC8ABC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C6E8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17EA0: call_seq lbl_88B6C700, lbl_880453D8, lbl_88CC908C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C700_88A17EA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC908C, (ts4_word)(ts4_word)lbl_880453D8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C700, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17F10: call_seq lbl_88B6C730, lbl_88CC8FFC, lbl_880403C4, lbl_88CC90BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C730_88A17F10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC90BC, (ts4_word)(ts4_word)lbl_880403C4, (ts4_word)(ts4_word)lbl_88CC8FFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C730, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17F88: call_seq lbl_88B6C7C8, lbl_88042284, lbl_88CC90EC, lbl_88054F4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C7C8_88A17F88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC90EC, (ts4_word)(ts4_word)lbl_88042284, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88054F4C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6C7C8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A17FF8: call_seq lbl_88B6C810, lbl_88CC8C0C, lbl_88040380, lbl_88CC911C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C810_88A17FF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC911C, (ts4_word)(ts4_word)lbl_88040380, (ts4_word)(ts4_word)lbl_88CC8C0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C810, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18070: call_seq lbl_88B6C828, lbl_8803FC48, lbl_88CC914C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C828_88A18070(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC914C, (ts4_word)(ts4_word)lbl_8803FC48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C828, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A180E0: call_seq lbl_88054F60, lbl_88B6C8B8, lbl_88CC8FFC, lbl_8803FC6C, lbl_88CC917C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88054F60_88A180E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC917C, (ts4_word)(ts4_word)lbl_8803FC6C, (ts4_word)(ts4_word)lbl_88CC8FFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C8B8, (ts4_word)9, (ts4_word)(ts4_word)lbl_88054F60, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18158: call_seq lbl_88B6C990, lbl_88045020, lbl_88CC91AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C990_88A18158(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC91AC, (ts4_word)(ts4_word)lbl_88045020, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C990, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A181C8: call_seq lbl_88B6C9D8, lbl_88CC8FFC, lbl_88040300, lbl_88CC91DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6C9D8_88A181C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC91DC, (ts4_word)(ts4_word)lbl_88040300, (ts4_word)(ts4_word)lbl_88CC8FFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6C9D8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18240: call_seq lbl_88B6CA50, lbl_88CC8C0C, lbl_880403AC, lbl_88CC920C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6CA50_88A18240(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC920C, (ts4_word)(ts4_word)lbl_880403AC, (ts4_word)(ts4_word)lbl_88CC8C0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6CA50, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}
