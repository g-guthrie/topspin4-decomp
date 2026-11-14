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
extern char lbl_8803F5D4[];
extern char lbl_8803F5E0[];
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
extern char lbl_8803F9C0[];
extern char lbl_8803F9D4[];
extern char lbl_8803F9E8[];
extern char lbl_8803FA04[];
extern char lbl_8803FA18[];
extern char lbl_8803FBE0[];
extern char lbl_8803FBF4[];
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
extern char lbl_88040658[];
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
extern char lbl_88042E20[];
extern char lbl_88042E48[];
extern char lbl_880433FC[];
extern char lbl_8804342C[];
extern char lbl_88043ED0[];
extern char lbl_88044268[];
extern char lbl_88044324[];
extern char lbl_88044370[];
extern char lbl_88044438[];
extern char lbl_88044524[];
extern char lbl_8804461C[];
extern char lbl_88044650[];
extern char lbl_88044680[];
extern char lbl_880446BC[];
extern char lbl_88044700[];
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
extern char lbl_8804C428[];
extern char lbl_88051880[];
extern char lbl_880518D4[];
extern char lbl_88051924[];
extern char lbl_880519F0[];
extern char lbl_88051A4C[];
extern char lbl_88051A88[];
extern char lbl_88051ACC[];
extern char lbl_88051B08[];
extern char lbl_88051B20[];
extern char lbl_88051B8C[];
extern char lbl_88051BF0[];
extern char lbl_88051C1C[];
extern char lbl_88051DF8[];
extern char lbl_88051E0C[];
extern char lbl_88B5D6A8[];
extern char lbl_88B5D708[];
extern char lbl_88B5D810[];
extern char lbl_88B5D8E8[];
extern char lbl_88B5D918[];
extern char lbl_88B5D930[];
extern char lbl_88B5D978[];
extern char lbl_88B5D990[];
extern char lbl_88B5D9D8[];
extern char lbl_88B5DA38[];
extern char lbl_88B5DA80[];
extern char lbl_88B5DAE0[];
extern char lbl_88B5DB10[];
extern char lbl_88B5DB28[];
extern char lbl_88B5DB40[];
extern char lbl_88B5DBA0[];
extern char lbl_88B5DBB8[];
extern char lbl_88B5DBE8[];
extern char lbl_88B5DC00[];
extern char lbl_88B5DC30[];
extern char lbl_88B5DC48[];
extern char lbl_88B5DC60[];
extern char lbl_88B5DC78[];
extern char lbl_88B5DCC0[];
extern char lbl_88B5DCF0[];
extern char lbl_88B5DD20[];
extern char lbl_88B5DD68[];
extern char lbl_88B5DDE4[];
extern char lbl_88B5DDE8[];
extern char lbl_88B5DE60[];
extern char lbl_88B5DE90[];
extern char lbl_88B5DEA8[];
extern char lbl_88B5DEC4[];
extern char lbl_88B5DEC8[];
extern char lbl_88B5DF28[];
extern char lbl_88B5DF40[];
extern char lbl_88B5DF70[];
extern char lbl_88B5DFA0[];
extern char lbl_88B5DFD0[];
extern char lbl_88B5E018[];
extern char lbl_88B5E0C0[];
extern char lbl_88B5E108[];
extern char lbl_88B5E168[];
extern char lbl_88B5E1F8[];
extern char lbl_88B5E210[];
extern char lbl_88B5E240[];
extern char lbl_88B5E288[];
extern char lbl_88B5E2D0[];
extern char lbl_88B5E330[];
extern char lbl_88B5E348[];
extern char lbl_88B5E378[];
extern char lbl_88B5E3D8[];
extern char lbl_88B5E3F0[];
extern char lbl_88B5E420[];
extern char lbl_88B5E438[];
extern char lbl_88B5E450[];
extern char lbl_88B5E49C[];
extern char lbl_88B5E4B4[];
extern char lbl_88B5E4B8[];
extern char lbl_88B5E520[];
extern char lbl_88B5E538[];
extern char lbl_88B5E568[];
extern char lbl_88B5E5B0[];
extern char lbl_88B5E5E0[];
extern char lbl_88B5E610[];
extern char lbl_88B5E670[];
extern char lbl_88B5E6B8[];
extern char lbl_88B5E748[];
extern char lbl_88B5E7C0[];
extern char lbl_88B5E7C8[];
extern char lbl_88B5E810[];
extern char lbl_88B5E870[];
extern char lbl_88B5E8B8[];
extern char lbl_88B5E900[];
extern char lbl_88B5E9A8[];
extern char lbl_88B5E9F0[];
extern char lbl_88B5EA20[];
extern char lbl_88B5EAB0[];
extern char lbl_88B5EB40[];
extern char lbl_88B5EC00[];
extern char lbl_88B5EC30[];
extern char lbl_88B5EC48[];
extern char lbl_88B5EC78[];
extern char lbl_88B5ECF0[];
extern char lbl_88B5ED38[];
extern char lbl_88B5ED68[];
extern char lbl_88B5EDF8[];
extern char lbl_88B5EE88[];
extern char lbl_88B5EF48[];
extern char lbl_88B5EF90[];
extern char lbl_88B5EFF0[];
extern char lbl_88B5F008[];
extern char lbl_88B5F080[];
extern char lbl_88B5F0B0[];
extern char lbl_88B5F0E0[];
extern char lbl_88B5F140[];
extern char lbl_88B5F170[];
extern char lbl_88B5F1B8[];
extern char lbl_88B5F248[];
extern char lbl_88B5F3FC[];
extern char lbl_88B5F430[];
extern char lbl_88B5F4D8[];
extern char lbl_88B5F4F0[];
extern char lbl_88B5F508[];
extern char lbl_88B5F538[];
extern char lbl_88B5F5E0[];
extern char lbl_88B5F610[];
extern char lbl_88B5F628[];
extern char lbl_88B5F658[];
extern char lbl_88B5F670[];
extern char lbl_88B5F68C[];
extern char lbl_88B5F6C0[];
extern char lbl_88B5F750[];
extern char lbl_88B5F754[];
extern char lbl_88B5F758[];
extern char lbl_88B5F760[];
extern char lbl_88B5F7F0[];
extern char lbl_88B5F808[];
extern char lbl_88B5F820[];
extern char lbl_88B5F838[];
extern char lbl_88B5F880[];
extern char lbl_88B5F898[];
extern char lbl_88B5F8C8[];
extern char lbl_88B5F940[];
extern char lbl_88B5F988[];
extern char lbl_88B5F9D0[];
extern char lbl_88B5FAA8[];
extern char lbl_88B5FAD8[];
extern char lbl_88B5FB08[];
extern char lbl_88B5FBE0[];
extern char lbl_88B5FC28[];
extern char lbl_88B5FC88[];
extern char lbl_88B5FCE8[];
extern char lbl_88B5FD48[];
extern char lbl_88B5FE08[];
extern char lbl_88B5FFA0[];
extern char lbl_88B5FFB8[];
extern char lbl_88B5FFD0[];
extern char lbl_88B60000[];
extern char lbl_88B60030[];
extern char lbl_88B60048[];
extern char lbl_88B60078[];
extern char lbl_88B600C0[];
extern char lbl_88B60108[];
extern char lbl_88B60198[];
extern char lbl_88B601E0[];
extern char lbl_88B60210[];
extern char lbl_88B60240[];
extern char lbl_88B60270[];
extern char lbl_88B60288[];
extern char lbl_88B602A0[];
extern char lbl_88B602D0[];
extern char lbl_88B602E8[];
extern char lbl_88B603C0[];
extern char lbl_88B60570[];
extern char lbl_88B60708[];
extern char lbl_88B60978[];
extern char lbl_88B609F0[];
extern char lbl_88B60A38[];
extern char lbl_88B60A68[];
extern char lbl_88B60AC8[];
extern char lbl_88B60B28[];
extern char lbl_88B60C18[];
extern char lbl_88B60D08[];
extern char lbl_88B60D50[];
extern char lbl_88B60E28[];
extern char lbl_88B60E40[];
extern char lbl_88B60E88[];
extern char lbl_88B60ED0[];
extern char lbl_88B614D0[];
extern char lbl_88B61608[];
extern char lbl_88B61650[];
extern char lbl_88B61710[];
extern char lbl_88B61770[];
extern char lbl_88CBFA5C[];
extern char lbl_88CC02CC[];
extern char lbl_88CC02FC[];
extern char lbl_88CC032C[];
extern char lbl_88CC035C[];
extern char lbl_88CC038C[];
extern char lbl_88CC03BC[];
extern char lbl_88CC03EC[];
extern char lbl_88CC041C[];
extern char lbl_88CC044C[];
extern char lbl_88CC047C[];
extern char lbl_88CC04AC[];
extern char lbl_88CC04DC[];
extern char lbl_88CC050C[];
extern char lbl_88CC053C[];
extern char lbl_88CC056C[];
extern char lbl_88CC059C[];
extern char lbl_88CC05CC[];
extern char lbl_88CC05FC[];
extern char lbl_88CC062C[];
extern char lbl_88CC065C[];
extern char lbl_88CC068C[];
extern char lbl_88CC06BC[];
extern char lbl_88CC06EC[];
extern char lbl_88CC071C[];
extern char lbl_88CC074C[];
extern char lbl_88CC077C[];
extern char lbl_88CC07AC[];
extern char lbl_88CC07DC[];
extern char lbl_88CC080C[];
extern char lbl_88CC083C[];
extern char lbl_88CC086C[];
extern char lbl_88CC089C[];
extern char lbl_88CC08CC[];
extern char lbl_88CC08FC[];
extern char lbl_88CC092C[];
extern char lbl_88CC095C[];
extern char lbl_88CC098C[];
extern char lbl_88CC09BC[];
extern char lbl_88CC09EC[];
extern char lbl_88CC0A1C[];
extern char lbl_88CC0A4C[];
extern char lbl_88CC0A7C[];
extern char lbl_88CC0AAC[];
extern char lbl_88CC0ADC[];
extern char lbl_88CC0B0C[];
extern char lbl_88CC0B3C[];
extern char lbl_88CC0B6C[];
extern char lbl_88CC0B9C[];
extern char lbl_88CC0BCC[];
extern char lbl_88CC0BFC[];
extern char lbl_88CC0C2C[];
extern char lbl_88CC0C5C[];
extern char lbl_88CC0C8C[];
extern char lbl_88CC0CBC[];
extern char lbl_88CC0CEC[];
extern char lbl_88CC0D1C[];
extern char lbl_88CC0D4C[];
extern char lbl_88CC0D7C[];
extern char lbl_88CC0DAC[];
extern char lbl_88CC0DDC[];
extern char lbl_88CC0E0C[];
extern char lbl_88CC0E3C[];
extern char lbl_88CC0E6C[];
extern char lbl_88CC0E9C[];
extern char lbl_88CC0ECC[];
extern char lbl_88CC0EFC[];
extern char lbl_88CC0F2C[];
extern char lbl_88CC0F5C[];
extern char lbl_88CC0F8C[];
extern char lbl_88CC0FBC[];
extern char lbl_88CC0FEC[];
extern char lbl_88CC101C[];
extern char lbl_88CC104C[];
extern char lbl_88CC107C[];
extern char lbl_88CC10AC[];
extern char lbl_88CC10DC[];
extern char lbl_88CC110C[];
extern char lbl_88CC113C[];
extern char lbl_88CC116C[];
extern char lbl_88CC119C[];
extern char lbl_88CC11CC[];
extern char lbl_88CC11FC[];
extern char lbl_88CC122C[];
extern char lbl_88CC125C[];
extern char lbl_88CC128C[];
extern char lbl_88CC12BC[];
extern char lbl_88CC12EC[];
extern char lbl_88CC131C[];
extern char lbl_88CC134C[];
extern char lbl_88CC137C[];
extern char lbl_88CC13AC[];
extern char lbl_88CC13DC[];
extern char lbl_88CC140C[];
extern char lbl_88CC143C[];
extern char lbl_88CC146C[];
extern char lbl_88CC149C[];
extern char lbl_88CC14CC[];
extern char lbl_88CC14FC[];
extern char lbl_88CC152C[];
extern char lbl_88CC155C[];
extern char lbl_88CC158C[];
extern char lbl_88CC15BC[];
extern char lbl_88CC15EC[];
extern char lbl_88CC161C[];
extern char lbl_88CC164C[];
extern char lbl_88CC167C[];
extern char lbl_88CC16AC[];
extern char lbl_88CC16DC[];
extern char lbl_88CC170C[];
extern char lbl_88CC173C[];
extern char lbl_88CC176C[];
extern char lbl_88CC179C[];
extern char lbl_88CC17CC[];
extern char lbl_88CC17FC[];
extern char lbl_88CC182C[];
extern char lbl_88CC185C[];
extern char lbl_88CC188C[];
extern char lbl_88CC18BC[];
extern char lbl_88CC18EC[];
extern char lbl_88CC191C[];
extern char lbl_88CC194C[];
extern char lbl_88CC197C[];
extern char lbl_88CC19AC[];
extern char lbl_88CC19DC[];
extern char lbl_88CC1A0C[];
extern char lbl_88CC1A3C[];
extern char lbl_88CC1A6C[];
extern char lbl_88CC1A9C[];
extern char lbl_88CC1ACC[];
extern char lbl_88CC1AFC[];
extern char lbl_88CC1B2C[];
extern char lbl_88CC1B5C[];
extern char lbl_88CC1B8C[];
extern char lbl_88CC1BBC[];
extern char lbl_88CC1BEC[];
extern char lbl_88CC1C4C[];
extern char lbl_88CC1C7C[];
extern char lbl_88CC1CAC[];
extern char lbl_88CC1CDC[];
extern char lbl_88CC1D0C[];
extern char lbl_88CC1D3C[];
extern char lbl_88CC1D6C[];
extern char lbl_88CC1D9C[];
extern char lbl_88CC1DCC[];
extern char lbl_88CC1DFC[];
extern char lbl_88CC1E2C[];
extern char lbl_88CC1E5C[];
extern char lbl_88CC1E8C[];
extern char lbl_88CC1EBC[];
extern char lbl_88CC1EEC[];
extern char lbl_88CC1F1C[];
extern char lbl_88CC1F4C[];
extern char lbl_88CC1F7C[];
extern char lbl_88CC1FAC[];
extern char lbl_88CC1FDC[];
extern char lbl_88CC200C[];
extern char lbl_88CC203C[];
extern char lbl_88CC206C[];
extern char lbl_88CC209C[];
extern char lbl_88CC20CC[];
extern char lbl_88CC20FC[];
extern char lbl_88CC212C[];
extern char lbl_88CC215C[];
extern char lbl_88CC218C[];
extern char lbl_88CC21BC[];
extern char lbl_88CC21EC[];
extern char lbl_88CC221C[];
extern char lbl_88CC224C[];
extern char lbl_88CC227C[];
extern char lbl_88CC22AC[];
extern char lbl_88CC22DC[];
extern char lbl_88CC230C[];
extern char lbl_88CC233C[];
extern char lbl_88CC236C[];
extern char lbl_88CC239C[];
extern char lbl_88CC23CC[];
extern char lbl_88CC23FC[];
extern char lbl_88CC242C[];
extern char lbl_88CC245C[];
extern char lbl_88CC248C[];
extern char lbl_88CC24BC[];
extern char lbl_88CC24EC[];
extern char lbl_88CC251C[];
extern char lbl_88CC254C[];
extern char lbl_88CC257C[];
extern char lbl_88CC25AC[];
extern char lbl_88CC25DC[];
extern char lbl_88CC260C[];
extern char lbl_88CC263C[];
extern char lbl_88CC266C[];
extern char lbl_88CC269C[];
extern char lbl_88CC26CC[];
extern char lbl_88CC26FC[];
extern char lbl_88CC272C[];
extern char lbl_88CC275C[];
ts4_word fn_8841F080();

/* Swing_DLL.xex 0x88A02748: call_seq lbl_88B5D6A8, lbl_8804C428, lbl_88CC02CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D6A8_88A02748(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC02CC, (ts4_word)(ts4_word)lbl_8804C428, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D6A8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A027B8: call_seq lbl_88B5D708, lbl_8803F5E0, lbl_88CC02FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D708_88A027B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC02FC, (ts4_word)(ts4_word)lbl_8803F5E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D708, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02828: call_seq lbl_88B5D810, lbl_88040278, lbl_88CC032C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D810_88A02828(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC032C, (ts4_word)(ts4_word)lbl_88040278, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D810, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02898: call_seq lbl_88B5D8E8, lbl_8803ED58, lbl_88CC035C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D8E8_88A02898(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC035C, (ts4_word)(ts4_word)lbl_8803ED58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D8E8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02908: call_seq lbl_88B5D918, lbl_8803ED40, lbl_88CC038C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D918_88A02908(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC038C, (ts4_word)(ts4_word)lbl_8803ED40, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D918, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02978: call_seq lbl_88B5D930, lbl_880433FC, lbl_88CC03BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D930_88A02978(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC03BC, (ts4_word)(ts4_word)lbl_880433FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D930, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A029E8: call_seq lbl_88B5D978, lbl_8804342C, lbl_88CC03EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D978_88A029E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC03EC, (ts4_word)(ts4_word)lbl_8804342C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D978, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02A58: call_seq lbl_88B5D990, lbl_88CBFA5C, lbl_8803ED7C, lbl_88CC041C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D990_88A02A58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC041C, (ts4_word)(ts4_word)lbl_8803ED7C, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D990, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02AD0: call_seq lbl_88B5D9D8, lbl_88046454, lbl_88CC044C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5D9D8_88A02AD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC044C, (ts4_word)(ts4_word)lbl_88046454, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5D9D8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02B40: call_seq lbl_88B5DA38, lbl_88CC044C, lbl_8804233C, lbl_88CC047C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DA38_88A02B40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC047C, (ts4_word)(ts4_word)lbl_8804233C, (ts4_word)(ts4_word)lbl_88CC044C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DA38, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02BB8: call_seq lbl_880469C4, lbl_88CC04AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880469C4_88A02BB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC04AC, (ts4_word)(ts4_word)lbl_880469C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02C18: call_seq lbl_88B5DA80, lbl_88CC1CDC, lbl_88042E48, lbl_88CC04DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DA80_88A02C18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC04DC, (ts4_word)(ts4_word)lbl_88042E48, (ts4_word)(ts4_word)lbl_88CC1CDC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DA80, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02C90: call_seq lbl_88046B60, lbl_88CC050C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046B60_88A02C90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC050C, (ts4_word)(ts4_word)lbl_88046B60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02CF0: call_seq lbl_88CBFA5C, lbl_88042318, lbl_88CC053C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBFA5C_88A02CF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC053C, (ts4_word)(ts4_word)lbl_88042318, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02D58: call_seq lbl_88046A84, lbl_88CC056C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A84_88A02D58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC056C, (ts4_word)(ts4_word)lbl_88046A84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02DB8: call_seq lbl_88B5DAE0, lbl_88CC053C, lbl_8804232C, lbl_88CC059C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DAE0_88A02DB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC059C, (ts4_word)(ts4_word)lbl_8804232C, (ts4_word)(ts4_word)lbl_88CC053C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DAE0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02E30: call_seq lbl_88B5DB10, lbl_88CC053C, lbl_8804690C, lbl_88CC05CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DB10_88A02E30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC05CC, (ts4_word)(ts4_word)lbl_8804690C, (ts4_word)(ts4_word)lbl_88CC053C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DB10, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02EA8: call_seq lbl_88CC053C, lbl_8804671C, lbl_88CC05FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC053C_88A02EA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC05FC, (ts4_word)(ts4_word)lbl_8804671C, (ts4_word)(ts4_word)lbl_88CC053C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02F10: call_seq lbl_88046A50, lbl_88CC062C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A50_88A02F10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC062C, (ts4_word)(ts4_word)lbl_88046A50, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02F70: call_seq lbl_88B5DB28, lbl_88CBFA5C, lbl_88041284, lbl_88CC065C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DB28_88A02F70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC065C, (ts4_word)(ts4_word)lbl_88041284, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DB28, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A02FE8: call_seq lbl_88B5DB40, lbl_88046220, lbl_88CC068C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DB40_88A02FE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC068C, (ts4_word)(ts4_word)lbl_88046220, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DB40, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03058: call_seq lbl_88B5DBA0, lbl_88CC07AC, lbl_8804694C, lbl_88CC06BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DBA0_88A03058(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC06BC, (ts4_word)(ts4_word)lbl_8804694C, (ts4_word)(ts4_word)lbl_88CC07AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DBA0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A030D0: call_seq lbl_88B5DBB8, lbl_88CC065C, lbl_88040110, lbl_88CC06EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DBB8_88A030D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC06EC, (ts4_word)(ts4_word)lbl_88040110, (ts4_word)(ts4_word)lbl_88CC065C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DBB8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03148: call_seq lbl_88B5DBE8, lbl_88CC065C, lbl_88040100, lbl_88CC071C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DBE8_88A03148(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC071C, (ts4_word)(ts4_word)lbl_88040100, (ts4_word)(ts4_word)lbl_88CC065C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DBE8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A031C0: call_seq lbl_88B5DC00, lbl_88CC07AC, lbl_8804011C, lbl_88CC074C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DC00_88A031C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC074C, (ts4_word)(ts4_word)lbl_8804011C, (ts4_word)(ts4_word)lbl_88CC07AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DC00, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03238: call_seq lbl_88B5DC30, lbl_88CC065C, lbl_880400A8, lbl_88CC077C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DC30_88A03238(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC077C, (ts4_word)(ts4_word)lbl_880400A8, (ts4_word)(ts4_word)lbl_88CC065C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DC30, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A032B0: call_seq lbl_88B5DC48, lbl_88CC0C5C, lbl_88042370, lbl_88CC07AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DC48_88A032B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC07AC, (ts4_word)(ts4_word)lbl_88042370, (ts4_word)(ts4_word)lbl_88CC0C5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DC48, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03328: call_seq lbl_88B5DC60, lbl_88CC09BC, lbl_88041B24, lbl_88CC07DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DC60_88A03328(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC07DC, (ts4_word)(ts4_word)lbl_88041B24, (ts4_word)(ts4_word)lbl_88CC09BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DC60, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A033A0: call_seq lbl_88B5DC78, lbl_88CC077C, lbl_880468C8, lbl_88CC080C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DC78_88A033A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC080C, (ts4_word)(ts4_word)lbl_880468C8, (ts4_word)(ts4_word)lbl_88CC077C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DC78, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03418: call_seq lbl_88B5DCC0, lbl_88CC07AC, lbl_880400E8, lbl_88CC083C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DCC0_88A03418(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC083C, (ts4_word)(ts4_word)lbl_880400E8, (ts4_word)(ts4_word)lbl_88CC07AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DCC0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03490: call_seq lbl_88B5DCF0, lbl_88CC07AC, lbl_880400D0, lbl_88CC086C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DCF0_88A03490(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC086C, (ts4_word)(ts4_word)lbl_880400D0, (ts4_word)(ts4_word)lbl_88CC07AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DCF0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03508: call_seq lbl_88B5DD20, lbl_880463D4, lbl_88CC089C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DD20_88A03508(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC089C, (ts4_word)(ts4_word)lbl_880463D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DD20, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03578: call_seq lbl_88B5DD68, lbl_88CC07AC, lbl_88046868, lbl_88CC08CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DD68_88A03578(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC08CC, (ts4_word)(ts4_word)lbl_88046868, (ts4_word)(ts4_word)lbl_88CC07AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DD68, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A035F0: call_seq lbl_88B5DDE8, lbl_88CC07AC, lbl_8803EFC0, lbl_88CC08FC, lbl_88051880, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DDE8_88A035F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC08FC, (ts4_word)(ts4_word)lbl_8803EFC0, (ts4_word)(ts4_word)lbl_88CC07AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88051880, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B5DDE8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03668: call_seq lbl_88CC0A4C, lbl_880467DC, lbl_88CC092C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC0A4C_88A03668(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC092C, (ts4_word)(ts4_word)lbl_880467DC, (ts4_word)(ts4_word)lbl_88CC0A4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A036D0: call_seq lbl_88CC065C, lbl_88046AE0, lbl_88CC095C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC065C_88A036D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC095C, (ts4_word)(ts4_word)lbl_88046AE0, (ts4_word)(ts4_word)lbl_88CC065C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03738: call_seq lbl_88B5DE60, lbl_88042358, lbl_88CC098C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DE60_88A03738(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC098C, (ts4_word)(ts4_word)lbl_88042358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DE60, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A037A8: call_seq lbl_88B5DE90, lbl_88CC077C, lbl_8804234C, lbl_88CC09BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DE90_88A037A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC09BC, (ts4_word)(ts4_word)lbl_8804234C, (ts4_word)(ts4_word)lbl_88CC077C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DE90, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03820: call_seq lbl_88B5DEA8, lbl_88046320, lbl_88CC09EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DEA8_88A03820(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC09EC, (ts4_word)(ts4_word)lbl_88046320, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DEA8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03890: addr lbl_88B614D0, u32@lbl_88B5DDE4, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88B614D0_88A03890(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B5DDE4;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B614D0) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B614D0) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A038B0: call_seq lbl_88B614D0, lbl_8803EFE8, lbl_88CC0A1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B614D0_88A038B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0A1C, (ts4_word)(ts4_word)lbl_8803EFE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B614D0, (ts4_word)13, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03920: call_seq lbl_88B5DEC8, lbl_88CC077C, lbl_8803EF9C, lbl_88CC0A4C, lbl_880518D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DEC8_88A03920(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0A4C, (ts4_word)(ts4_word)lbl_8803EF9C, (ts4_word)(ts4_word)lbl_88CC077C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880518D4, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B5DEC8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03998: call_seq lbl_88B5DF28, lbl_88CC071C, lbl_880423C0, lbl_88CC0A7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DF28_88A03998(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0A7C, (ts4_word)(ts4_word)lbl_880423C0, (ts4_word)(ts4_word)lbl_88CC071C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DF28, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03A10: call_seq lbl_88B5DF40, lbl_880462E8, lbl_88CC0AAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DF40_88A03A10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0AAC, (ts4_word)(ts4_word)lbl_880462E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DF40, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03A80: call_seq lbl_88B5DF70, lbl_88CC065C, lbl_8804675C, lbl_88CC0ADC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DF70_88A03A80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0ADC, (ts4_word)(ts4_word)lbl_8804675C, (ts4_word)(ts4_word)lbl_88CC065C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DF70, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03AF8: call_seq lbl_88B5DFA0, lbl_88CC0C5C, lbl_8803F9D4, lbl_88CC0B0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DFA0_88A03AF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0B0C, (ts4_word)(ts4_word)lbl_8803F9D4, (ts4_word)(ts4_word)lbl_88CC0C5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DFA0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03B70: call_seq lbl_88CC065C, lbl_88046AB4, lbl_88CC0B3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC065C_88A03B70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0B3C, (ts4_word)(ts4_word)lbl_88046AB4, (ts4_word)(ts4_word)lbl_88CC065C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03BD8: call_seq lbl_88B5DFD0, lbl_88CC095C, lbl_880466D4, lbl_88CC0B6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5DFD0_88A03BD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0B6C, (ts4_word)(ts4_word)lbl_880466D4, (ts4_word)(ts4_word)lbl_88CC095C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5DFD0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03C50: call_seq lbl_88B5E018, lbl_88CC095C, lbl_88046A18, lbl_88CC0B9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E018_88A03C50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0B9C, (ts4_word)(ts4_word)lbl_88046A18, (ts4_word)(ts4_word)lbl_88CC095C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E018, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03CC8: call_seq lbl_88B5E0C0, lbl_880423A4, lbl_88CC0BCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E0C0_88A03CC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0BCC, (ts4_word)(ts4_word)lbl_880423A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E0C0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03D38: call_seq lbl_88B5E108, lbl_88CC077C, lbl_88042390, lbl_88CC0BFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E108_88A03D38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0BFC, (ts4_word)(ts4_word)lbl_88042390, (ts4_word)(ts4_word)lbl_88CC077C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E108, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03DB0: call_seq lbl_88CC07AC, lbl_88043ED0, lbl_88CC0C2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC07AC_88A03DB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0C2C, (ts4_word)(ts4_word)lbl_88043ED0, (ts4_word)(ts4_word)lbl_88CC07AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03E18: call_seq lbl_88CC065C, lbl_8804696C, lbl_88CC0C5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC065C_88A03E18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0C5C, (ts4_word)(ts4_word)lbl_8804696C, (ts4_word)(ts4_word)lbl_88CC065C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03E80: call_seq lbl_88B5E168, lbl_8803F00C, lbl_88CC0C8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E168_88A03E80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0C8C, (ts4_word)(ts4_word)lbl_8803F00C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E168, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03EF0: call_seq lbl_88B5E1F8, lbl_88CC0A4C, lbl_88046574, lbl_88CC0CBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E1F8_88A03EF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0CBC, (ts4_word)(ts4_word)lbl_88046574, (ts4_word)(ts4_word)lbl_88CC0A4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E1F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03F68: call_seq lbl_88B5E210, lbl_88CC0B9C, lbl_88046518, lbl_88CC0CEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E210_88A03F68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0CEC, (ts4_word)(ts4_word)lbl_88046518, (ts4_word)(ts4_word)lbl_88CC0B9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E210, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A03FE0: call_seq lbl_88B5E240, lbl_88CC065C, lbl_880400BC, lbl_88CC0D1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E240_88A03FE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0D1C, (ts4_word)(ts4_word)lbl_880400BC, (ts4_word)(ts4_word)lbl_88CC065C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E240, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04058: call_seq lbl_88B5E288, lbl_88CC07AC, lbl_88042380, lbl_88CC0D4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E288_88A04058(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0D4C, (ts4_word)(ts4_word)lbl_88042380, (ts4_word)(ts4_word)lbl_88CC07AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E288, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A040D0: call_seq lbl_88B5E2D0, lbl_8803FBF4, lbl_88CC0D7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E2D0_88A040D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0D7C, (ts4_word)(ts4_word)lbl_8803FBF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E2D0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04140: call_seq lbl_88B5E330, lbl_88CC071C, lbl_880423D4, lbl_88CC0DAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E330_88A04140(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0DAC, (ts4_word)(ts4_word)lbl_880423D4, (ts4_word)(ts4_word)lbl_88CC071C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E330, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A041B8: call_seq lbl_88B5E348, lbl_88CC077C, lbl_88046498, lbl_88CC0DDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E348_88A041B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0DDC, (ts4_word)(ts4_word)lbl_88046498, (ts4_word)(ts4_word)lbl_88CC077C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E348, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04230: call_seq lbl_88B5E378, lbl_88CBFA5C, lbl_88047050, lbl_88CC0E0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E378_88A04230(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0E0C, (ts4_word)(ts4_word)lbl_88047050, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E378, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A042A8: call_seq lbl_88B5E3D8, lbl_88CC0E0C, lbl_88045B44, lbl_88CC0E3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E3D8_88A042A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0E3C, (ts4_word)(ts4_word)lbl_88045B44, (ts4_word)(ts4_word)lbl_88CC0E0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E3D8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04320: call_seq lbl_88B5E3F0, lbl_88CC0E0C, lbl_88045B24, lbl_88CC0E6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E3F0_88A04320(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0E6C, (ts4_word)(ts4_word)lbl_88045B24, (ts4_word)(ts4_word)lbl_88CC0E0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E3F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04398: call_seq lbl_88B5E420, lbl_88CC0E0C, lbl_880459C0, lbl_88CC0E9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E420_88A04398(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0E9C, (ts4_word)(ts4_word)lbl_880459C0, (ts4_word)(ts4_word)lbl_88CC0E0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E420, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04410: addr lbl_88B61608, u32@lbl_88B5DEC4, u32@0x8 */
void ts4_addr_lbl_88B61608_88A04410(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B61608) + 8) = (ts4_word)(*(ts4_word *)lbl_88B5DEC4);
    return;
}

/* Swing_DLL.xex 0x88A04428: call_seq lbl_88B61608, lbl_88045224, lbl_88CC0ECC, lbl_88051924, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61608_88A04428(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0ECC, (ts4_word)(ts4_word)lbl_88045224, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88051924, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B61608, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04498: call_seq lbl_88B5E438, lbl_88045194, lbl_88CC0EFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E438_88A04498(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0EFC, (ts4_word)(ts4_word)lbl_88045194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E438, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04508: call_seq lbl_88B5E450, lbl_8803EF90, lbl_88CC0F2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E450_88A04508(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0F2C, (ts4_word)(ts4_word)lbl_8803EF90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E450, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04578: call_seq lbl_88B5E49C, lbl_88CBFA5C, lbl_8803FA04, lbl_88CC0F5C, lbl_880519F0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E49C_88A04578(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0F5C, (ts4_word)(ts4_word)lbl_8803FA04, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880519F0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B5E49C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A045E8: call_seq lbl_88B5E4B8, lbl_88042170, lbl_88CC0F8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E4B8_88A045E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0F8C, (ts4_word)(ts4_word)lbl_88042170, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E4B8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04658: addr lbl_88B61650, u32@lbl_88B5E4B4, u32@0x50 */
void ts4_addr_lbl_88B61650_88A04658(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B61650) + 80) = (ts4_word)(*(ts4_word *)lbl_88B5E4B4);
    return;
}

/* Swing_DLL.xex 0x88A04670: call_seq lbl_88B61650, lbl_88CBFA5C, lbl_8803F0C8, lbl_88CC0FBC, lbl_88051A4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61650_88A04670(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0FBC, (ts4_word)(ts4_word)lbl_8803F0C8, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88051A4C, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B61650, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A046E8: call_seq lbl_88B5E520, lbl_88CC0F5C, lbl_8804044C, lbl_88CC0FEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E520_88A046E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC0FEC, (ts4_word)(ts4_word)lbl_8804044C, (ts4_word)(ts4_word)lbl_88CC0F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E520, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04760: call_seq lbl_88B5E538, lbl_88CC0F5C, lbl_880403DC, lbl_88CC101C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E538_88A04760(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC101C, (ts4_word)(ts4_word)lbl_880403DC, (ts4_word)(ts4_word)lbl_88CC0F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E538, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A047D8: call_seq lbl_88B5E568, lbl_88040630, lbl_88CC104C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E568_88A047D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC104C, (ts4_word)(ts4_word)lbl_88040630, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E568, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04848: call_seq lbl_88B5E5B0, lbl_88040608, lbl_88CC107C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E5B0_88A04848(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC107C, (ts4_word)(ts4_word)lbl_88040608, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E5B0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A048B8: call_seq lbl_88B5E5E0, lbl_88CC0F5C, lbl_88040394, lbl_88CC10AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E5E0_88A048B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC10AC, (ts4_word)(ts4_word)lbl_88040394, (ts4_word)(ts4_word)lbl_88CC0F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E5E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04930: call_seq lbl_88B5E610, lbl_88040590, lbl_88CC10DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E610_88A04930(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC10DC, (ts4_word)(ts4_word)lbl_88040590, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E610, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A049A0: call_seq lbl_88B5E670, lbl_88040560, lbl_88CC110C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E670_88A049A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC110C, (ts4_word)(ts4_word)lbl_88040560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E670, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04A10: call_seq lbl_88051A88, lbl_88B5E6B8, lbl_88CC0F5C, lbl_8803F690, lbl_88CC113C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88051A88_88A04A10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC113C, (ts4_word)(ts4_word)lbl_8803F690, (ts4_word)(ts4_word)lbl_88CC0F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E6B8, (ts4_word)6, (ts4_word)(ts4_word)lbl_88051A88, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04A88: call_seq lbl_88B5E748, lbl_88CC119C, lbl_88045734, lbl_88CC116C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E748_88A04A88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC116C, (ts4_word)(ts4_word)lbl_88045734, (ts4_word)(ts4_word)lbl_88CC119C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E748, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04B00: call_seq lbl_88CBFA5C, lbl_88045A30, lbl_88CC119C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBFA5C_88A04B00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC119C, (ts4_word)(ts4_word)lbl_88045A30, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04B68: addr lbl_88B61710, u32@lbl_88B5E7C0, u32@0x38 */
void ts4_addr_lbl_88B61710_88A04B68(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B61710) + 56) = (ts4_word)(*(ts4_word *)lbl_88B5E7C0);
    return;
}

/* Swing_DLL.xex 0x88A04B80: call_seq lbl_88B61710, lbl_88CC0F5C, lbl_88040364, lbl_88CC11CC, lbl_88051ACC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B61710_88A04B80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC11CC, (ts4_word)(ts4_word)lbl_88040364, (ts4_word)(ts4_word)lbl_88CC0F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88051ACC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B61710, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04BF8: call_seq lbl_88B5E7C8, lbl_88CC0F5C, lbl_88040344, lbl_88CC11FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E7C8_88A04BF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC11FC, (ts4_word)(ts4_word)lbl_88040344, (ts4_word)(ts4_word)lbl_88CC0F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E7C8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04C70: call_seq lbl_88B5E810, lbl_88CC113C, lbl_8803F064, lbl_88CC122C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E810_88A04C70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC122C, (ts4_word)(ts4_word)lbl_8803F064, (ts4_word)(ts4_word)lbl_88CC113C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E810, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04CE8: call_seq lbl_88B5E870, lbl_88040534, lbl_88CC125C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E870_88A04CE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC125C, (ts4_word)(ts4_word)lbl_88040534, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E870, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04D58: call_seq lbl_88B5E8B8, lbl_88040508, lbl_88CC128C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E8B8_88A04D58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC128C, (ts4_word)(ts4_word)lbl_88040508, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E8B8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04DC8: call_seq lbl_88B5E900, lbl_88CC0F5C, lbl_8803F048, lbl_88CC12BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E900_88A04DC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC12BC, (ts4_word)(ts4_word)lbl_8803F048, (ts4_word)(ts4_word)lbl_88CC0F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E900, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04E40: call_seq lbl_88B5E9A8, lbl_88CC0F5C, lbl_880402E4, lbl_88CC12EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E9A8_88A04E40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC12EC, (ts4_word)(ts4_word)lbl_880402E4, (ts4_word)(ts4_word)lbl_88CC0F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E9A8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04EB8: call_seq lbl_88B5E9F0, lbl_88040424, lbl_88CC131C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5E9F0_88A04EB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC131C, (ts4_word)(ts4_word)lbl_88040424, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5E9F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04F28: call_seq lbl_88B5EA20, lbl_880403FC, lbl_88CC134C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5EA20_88A04F28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC134C, (ts4_word)(ts4_word)lbl_880403FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5EA20, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A04F98: call_seq lbl_88B5EAB0, lbl_88CC0F5C, lbl_880402CC, lbl_88CC137C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5EAB0_88A04F98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC137C, (ts4_word)(ts4_word)lbl_880402CC, (ts4_word)(ts4_word)lbl_88CC0F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5EAB0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05010: call_seq lbl_88B5EB40, lbl_88CC0F5C, lbl_8803F6B0, lbl_88CC13AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5EB40_88A05010(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC13AC, (ts4_word)(ts4_word)lbl_8803F6B0, (ts4_word)(ts4_word)lbl_88CC0F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5EB40, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05088: call_seq lbl_88CC0F5C, lbl_88045AFC, lbl_88CC13DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC0F5C_88A05088(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC13DC, (ts4_word)(ts4_word)lbl_88045AFC, (ts4_word)(ts4_word)lbl_88CC0F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A050F0: call_seq lbl_88B5EC00, lbl_88CC0FBC, lbl_8804589C, lbl_88CC140C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5EC00_88A050F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC140C, (ts4_word)(ts4_word)lbl_8804589C, (ts4_word)(ts4_word)lbl_88CC0FBC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5EC00, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05168: call_seq lbl_88B5EC30, lbl_88CC0E0C, lbl_88045860, lbl_88CC143C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5EC30_88A05168(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC143C, (ts4_word)(ts4_word)lbl_88045860, (ts4_word)(ts4_word)lbl_88CC0E0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5EC30, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A051E0: call_seq lbl_88B5EC48, lbl_880453D8, lbl_88CC146C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5EC48_88A051E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC146C, (ts4_word)(ts4_word)lbl_880453D8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5EC48, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05250: call_seq lbl_88B5EC78, lbl_88CC13DC, lbl_880403C4, lbl_88CC149C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5EC78_88A05250(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC149C, (ts4_word)(ts4_word)lbl_880403C4, (ts4_word)(ts4_word)lbl_88CC13DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5EC78, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A052C8: call_seq lbl_88B5ECF0, lbl_880405E4, lbl_88CC14CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5ECF0_88A052C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC14CC, (ts4_word)(ts4_word)lbl_880405E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5ECF0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05338: call_seq lbl_88B5ED38, lbl_880405C0, lbl_88CC14FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5ED38_88A05338(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC14FC, (ts4_word)(ts4_word)lbl_880405C0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5ED38, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A053A8: call_seq lbl_88B5ED68, lbl_88CC0F5C, lbl_88040380, lbl_88CC152C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5ED68_88A053A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC152C, (ts4_word)(ts4_word)lbl_88040380, (ts4_word)(ts4_word)lbl_88CC0F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5ED68, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05420: call_seq lbl_88B5EDF8, lbl_8803FC48, lbl_88CC155C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5EDF8_88A05420(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC155C, (ts4_word)(ts4_word)lbl_8803FC48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5EDF8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05490: call_seq lbl_88B5EE88, lbl_88CC13DC, lbl_8803FC6C, lbl_88CC158C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5EE88_88A05490(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC158C, (ts4_word)(ts4_word)lbl_8803FC6C, (ts4_word)(ts4_word)lbl_88CC13DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5EE88, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05508: call_seq lbl_88B5EF48, lbl_88045020, lbl_88CC15BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5EF48_88A05508(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC15BC, (ts4_word)(ts4_word)lbl_88045020, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5EF48, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05578: call_seq lbl_88B5EF90, lbl_88CC13DC, lbl_88040300, lbl_88CC15EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5EF90_88A05578(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC15EC, (ts4_word)(ts4_word)lbl_88040300, (ts4_word)(ts4_word)lbl_88CC13DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5EF90, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A055F0: call_seq lbl_88B5EFF0, lbl_88CC0F5C, lbl_880403AC, lbl_88CC161C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5EFF0_88A055F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC161C, (ts4_word)(ts4_word)lbl_880403AC, (ts4_word)(ts4_word)lbl_88CC0F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5EFF0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05668: call_seq lbl_88B5F008, lbl_880422F8, lbl_88CC164C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F008_88A05668(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC164C, (ts4_word)(ts4_word)lbl_880422F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F008, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A056D8: call_seq lbl_88B5F080, lbl_88CC0F5C, lbl_8803FA18, lbl_88CC167C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F080_88A056D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC167C, (ts4_word)(ts4_word)lbl_8803FA18, (ts4_word)(ts4_word)lbl_88CC0F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F080, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05750: call_seq lbl_88051B08, lbl_88CBFA5C, lbl_8803FBE0, lbl_88CC16AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88051B08_88A05750(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC16AC, (ts4_word)(ts4_word)lbl_8803FBE0, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88051B08, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A057B8: call_seq lbl_88B5F0B0, lbl_88CC16AC, lbl_88045A70, lbl_88CC16DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F0B0_88A057B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC16DC, (ts4_word)(ts4_word)lbl_88045A70, (ts4_word)(ts4_word)lbl_88CC16AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F0B0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05830: call_seq lbl_88B5F0E0, lbl_88CC16DC, lbl_8803FCA0, lbl_88CC170C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F0E0_88A05830(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC170C, (ts4_word)(ts4_word)lbl_8803FCA0, (ts4_word)(ts4_word)lbl_88CC16DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F0E0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A058A8: call_seq lbl_88B5F140, lbl_88CC16DC, lbl_8803FC80, lbl_88CC173C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F140_88A058A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC173C, (ts4_word)(ts4_word)lbl_8803FC80, (ts4_word)(ts4_word)lbl_88CC16DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F140, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05920: call_seq lbl_88B5F170, lbl_88CC16DC, lbl_8803F9E8, lbl_88CC176C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F170_88A05920(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC176C, (ts4_word)(ts4_word)lbl_8803F9E8, (ts4_word)(ts4_word)lbl_88CC16DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F170, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05998: call_seq lbl_88B5F1B8, lbl_88CC0F5C, lbl_8804032C, lbl_88CC179C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F1B8_88A05998(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC179C, (ts4_word)(ts4_word)lbl_8804032C, (ts4_word)(ts4_word)lbl_88CC0F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F1B8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05A10: call_seq lbl_88051B20, lbl_88B5F248, lbl_88CC1C4C, lbl_8803F6CC, lbl_88CC17CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88051B20_88A05A10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC17CC, (ts4_word)(ts4_word)lbl_8803F6CC, (ts4_word)(ts4_word)lbl_88CC1C4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F248, (ts4_word)18, (ts4_word)(ts4_word)lbl_88051B20, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05A88: call_seq lbl_88CBFA5C, lbl_88045AA8, lbl_88CC17FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBFA5C_88A05A88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC17FC, (ts4_word)(ts4_word)lbl_88045AA8, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05AF0: call_seq lbl_88CC188C, lbl_880457FC, lbl_88CC182C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC188C_88A05AF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC182C, (ts4_word)(ts4_word)lbl_880457FC, (ts4_word)(ts4_word)lbl_88CC188C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05B58: call_seq lbl_88CC17CC, lbl_880455E0, lbl_88CC185C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC17CC_88A05B58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC185C, (ts4_word)(ts4_word)lbl_880455E0, (ts4_word)(ts4_word)lbl_88CC17CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05BC0: call_seq lbl_88051B8C, lbl_88CC17FC, lbl_880459F8, lbl_88CC188C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88051B8C_88A05BC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC188C, (ts4_word)(ts4_word)lbl_880459F8, (ts4_word)(ts4_word)lbl_88CC17FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88051B8C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05C28: call_seq lbl_88B5F3FC, lbl_88045070, lbl_88CC18BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F3FC_88A05C28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC18BC, (ts4_word)(ts4_word)lbl_88045070, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F3FC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05C98: call_seq lbl_88B5F430, lbl_88CC188C, lbl_88041DE0, lbl_88CC18EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F430_88A05C98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC18EC, (ts4_word)(ts4_word)lbl_88041DE0, (ts4_word)(ts4_word)lbl_88CC188C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F430, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05D10: call_seq lbl_88B5F4D8, lbl_88CBFA5C, lbl_8803F5D4, lbl_88CC191C, lbl_88051BF0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F4D8_88A05D10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC191C, (ts4_word)(ts4_word)lbl_8803F5D4, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88051BF0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B5F4D8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05D80: call_seq lbl_88B5F4F0, lbl_88CC19DC, lbl_880402B0, lbl_88CC194C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F4F0_88A05D80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC194C, (ts4_word)(ts4_word)lbl_880402B0, (ts4_word)(ts4_word)lbl_88CC19DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F4F0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05DF8: call_seq lbl_88CC19AC, lbl_88040E04, lbl_88CC197C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC19AC_88A05DF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC197C, (ts4_word)(ts4_word)lbl_88040E04, (ts4_word)(ts4_word)lbl_88CC19AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05E60: call_seq lbl_88B5F508, lbl_88CC19DC, lbl_8803EFA8, lbl_88CC19AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F508_88A05E60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC19AC, (ts4_word)(ts4_word)lbl_8803EFA8, (ts4_word)(ts4_word)lbl_88CC19DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F508, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05ED8: call_seq lbl_88B5F538, lbl_88CC191C, lbl_88040290, lbl_88CC19DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F538_88A05ED8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC19DC, (ts4_word)(ts4_word)lbl_88040290, (ts4_word)(ts4_word)lbl_88CC191C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F538, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05F50: call_seq lbl_88CC19DC, lbl_880402A0, lbl_88CC1A0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC19DC_88A05F50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1A0C, (ts4_word)(ts4_word)lbl_880402A0, (ts4_word)(ts4_word)lbl_88CC19DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A05FB8: call_seq lbl_88CC194C, lbl_88040E18, lbl_88CC1A3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC194C_88A05FB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1A3C, (ts4_word)(ts4_word)lbl_88040E18, (ts4_word)(ts4_word)lbl_88CC194C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06020: call_seq lbl_88CC1A0C, lbl_88040E68, lbl_88CC1A6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC1A0C_88A06020(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1A6C, (ts4_word)(ts4_word)lbl_88040E68, (ts4_word)(ts4_word)lbl_88CC1A0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06088: call_seq lbl_88CC194C, lbl_88040DB0, lbl_88CC1A9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC194C_88A06088(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1A9C, (ts4_word)(ts4_word)lbl_88040DB0, (ts4_word)(ts4_word)lbl_88CC194C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A060F0: call_seq lbl_88B5F5E0, lbl_88CC1B2C, lbl_8803F6D8, lbl_88CC1ACC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F5E0_88A060F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1ACC, (ts4_word)(ts4_word)lbl_8803F6D8, (ts4_word)(ts4_word)lbl_88CC1B2C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F5E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06168: call_seq lbl_88B5F610, lbl_88CC1B5C, lbl_88045914, lbl_88CC1AFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F610_88A06168(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1AFC, (ts4_word)(ts4_word)lbl_88045914, (ts4_word)(ts4_word)lbl_88CC1B5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F610, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A061E0: call_seq lbl_88B5F628, lbl_88CC1C4C, lbl_88047070, lbl_88CC1B2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F628_88A061E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1B2C, (ts4_word)(ts4_word)lbl_88047070, (ts4_word)(ts4_word)lbl_88CC1C4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F628, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06258: call_seq lbl_88B5F658, lbl_88CC1B2C, lbl_880402BC, lbl_88CC1B5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F658_88A06258(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1B5C, (ts4_word)(ts4_word)lbl_880402BC, (ts4_word)(ts4_word)lbl_88CC1B2C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F658, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A062D0: call_seq lbl_88B5F670, lbl_88CC1B5C, lbl_88045580, lbl_88CC1B8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F670_88A062D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1B8C, (ts4_word)(ts4_word)lbl_88045580, (ts4_word)(ts4_word)lbl_88CC1B5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F670, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06348: call_seq lbl_88B5F68C, lbl_8803F9C0, lbl_88CC1BBC, lbl_88051C1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F68C_88A06348(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1BBC, (ts4_word)(ts4_word)lbl_8803F9C0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88051C1C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B5F68C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A063B8: call_seq lbl_88B5F6C0, lbl_88CBFA5C, lbl_8803F660, lbl_88CC1BEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F6C0_88A063B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1BEC, (ts4_word)(ts4_word)lbl_8803F660, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F6C0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06430: get u32@lbl_88B5F758, lbl_88B61770, u32@lbl_88B5F754, u32@lbl_88B5F750, u32@0x50, u32@0x110 */
void ts4_get_u32_lbl_88B5F758_88A06430(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88B5F758;
    t2 = *(ts4_word *)lbl_88B5F754;
    t3 = *(ts4_word *)lbl_88B5F750;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B61770) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B61770) + 272) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B61770) + 560) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x88A064D8: call_seq lbl_88B5F760, lbl_88CBFA5C, lbl_8803F084, lbl_88CC1C4C, lbl_88051DF8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F760_88A064D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1C4C, (ts4_word)(ts4_word)lbl_8803F084, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88051DF8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B5F760, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06550: call_seq lbl_88B5F7F0, lbl_88CBFA5C, lbl_8804707C, lbl_88CC1C7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F7F0_88A06550(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1C7C, (ts4_word)(ts4_word)lbl_8804707C, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F7F0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A065C8: call_seq lbl_88B5F808, lbl_88CC047C, lbl_88044F38, lbl_88CC1CAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F808_88A065C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1CAC, (ts4_word)(ts4_word)lbl_88044F38, (ts4_word)(ts4_word)lbl_88CC047C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F808, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06640: call_seq lbl_88B5F820, lbl_88042E20, lbl_88CC1CDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F820_88A06640(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1CDC, (ts4_word)(ts4_word)lbl_88042E20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F820, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A066B0: call_seq lbl_88B5F838, lbl_88CBFA5C, lbl_8803EFD0, lbl_88CC1D0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F838_88A066B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1D0C, (ts4_word)(ts4_word)lbl_8803EFD0, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F838, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06728: call_seq lbl_88B5F880, lbl_88044F10, lbl_88CC1D3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F880_88A06728(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1D3C, (ts4_word)(ts4_word)lbl_88044F10, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F880, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06798: call_seq lbl_88B5F898, lbl_88CBFA5C, lbl_88044F90, lbl_88CC1D6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F898_88A06798(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1D6C, (ts4_word)(ts4_word)lbl_88044F90, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F898, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06810: call_seq lbl_88B5F8C8, lbl_88CC1E2C, lbl_8803F670, lbl_88CC1D9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F8C8_88A06810(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1D9C, (ts4_word)(ts4_word)lbl_8803F670, (ts4_word)(ts4_word)lbl_88CC1E2C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F8C8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06888: call_seq lbl_88B5F940, lbl_880404E0, lbl_88CC1DCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F940_88A06888(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1DCC, (ts4_word)(ts4_word)lbl_880404E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F940, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A068F8: call_seq lbl_88B5F988, lbl_880404B8, lbl_88CC1DFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5F988_88A068F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1DFC, (ts4_word)(ts4_word)lbl_880404B8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F988, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06968: call_seq lbl_88051E0C, lbl_88B5F9D0, lbl_88CC0F5C, lbl_8803F030, lbl_88CC1E2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88051E0C_88A06968(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1E2C, (ts4_word)(ts4_word)lbl_8803F030, (ts4_word)(ts4_word)lbl_88CC0F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5F9D0, (ts4_word)9, (ts4_word)(ts4_word)lbl_88051E0C, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A069E0: call_seq lbl_88B5FAA8, lbl_88040494, lbl_88CC1E5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5FAA8_88A069E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1E5C, (ts4_word)(ts4_word)lbl_88040494, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5FAA8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06A50: call_seq lbl_88B5FAD8, lbl_88040470, lbl_88CC1E8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5FAD8_88A06A50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1E8C, (ts4_word)(ts4_word)lbl_88040470, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5FAD8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06AC0: call_seq lbl_88B5FB08, lbl_88CC0F5C, lbl_88040318, lbl_88CC1EBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5FB08_88A06AC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1EBC, (ts4_word)(ts4_word)lbl_88040318, (ts4_word)(ts4_word)lbl_88CC0F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5FB08, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06B38: call_seq lbl_88B5FBE0, lbl_88CC0E6C, lbl_88044EA8, lbl_88CC1EEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5FBE0_88A06B38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1EEC, (ts4_word)(ts4_word)lbl_88044EA8, (ts4_word)(ts4_word)lbl_88CC0E6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5FBE0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06BB0: call_seq lbl_88B5FC28, lbl_88CC0E6C, lbl_88044E64, lbl_88CC1F1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5FC28_88A06BB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1F1C, (ts4_word)(ts4_word)lbl_88044E64, (ts4_word)(ts4_word)lbl_88CC0E6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5FC28, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06C28: call_seq lbl_88B5FC88, lbl_88CC0E9C, lbl_88044DD0, lbl_88CC1F4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5FC88_88A06C28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1F4C, (ts4_word)(ts4_word)lbl_88044DD0, (ts4_word)(ts4_word)lbl_88CC0E9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5FC88, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06CA0: call_seq lbl_88B5FCE8, lbl_88CC0E9C, lbl_88044CD0, lbl_88CC1F7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5FCE8_88A06CA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1F7C, (ts4_word)(ts4_word)lbl_88044CD0, (ts4_word)(ts4_word)lbl_88CC0E9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5FCE8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06D18: call_seq lbl_88B5FD48, lbl_88CC0E6C, lbl_88044BD4, lbl_88CC1FAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5FD48_88A06D18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1FAC, (ts4_word)(ts4_word)lbl_88044BD4, (ts4_word)(ts4_word)lbl_88CC0E6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5FD48, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06D90: call_seq lbl_88B5FE08, lbl_8803F094, lbl_88CC1FDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5FE08_88A06D90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC1FDC, (ts4_word)(ts4_word)lbl_8803F094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5FE08, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06E00: call_seq lbl_88B5FFA0, lbl_88CC053C, lbl_8803F0AC, lbl_88CC200C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5FFA0_88A06E00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC200C, (ts4_word)(ts4_word)lbl_8803F0AC, (ts4_word)(ts4_word)lbl_88CC053C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5FFA0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06E78: call_seq lbl_88B5FFB8, lbl_88CC053C, lbl_88044E30, lbl_88CC203C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5FFB8_88A06E78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC203C, (ts4_word)(ts4_word)lbl_88044E30, (ts4_word)(ts4_word)lbl_88CC053C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5FFB8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06EF0: call_seq lbl_88B5FFD0, lbl_88CC053C, lbl_88044DF8, lbl_88CC206C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B5FFD0_88A06EF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC206C, (ts4_word)(ts4_word)lbl_88044DF8, (ts4_word)(ts4_word)lbl_88CC053C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B5FFD0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06F68: call_seq lbl_88B60000, lbl_88044B54, lbl_88CC209C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60000_88A06F68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC209C, (ts4_word)(ts4_word)lbl_88044B54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60000, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A06FD8: call_seq lbl_88B60030, lbl_88CC053C, lbl_88044D8C, lbl_88CC20CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60030_88A06FD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC20CC, (ts4_word)(ts4_word)lbl_88044D8C, (ts4_word)(ts4_word)lbl_88CC053C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60030, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07050: call_seq lbl_88B60048, lbl_88044A90, lbl_88CC20FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60048_88A07050(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC20FC, (ts4_word)(ts4_word)lbl_88044A90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60048, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A070C0: call_seq lbl_88B60078, lbl_88044ACC, lbl_88CC212C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60078_88A070C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC212C, (ts4_word)(ts4_word)lbl_88044ACC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60078, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07130: call_seq lbl_88B600C0, lbl_88CBFA5C, lbl_88044CFC, lbl_88CC215C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B600C0_88A07130(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC215C, (ts4_word)(ts4_word)lbl_88044CFC, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B600C0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A071A8: call_seq lbl_88B60108, lbl_88CC0E9C, lbl_8804705C, lbl_88CC218C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60108_88A071A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC218C, (ts4_word)(ts4_word)lbl_8804705C, (ts4_word)(ts4_word)lbl_88CC0E9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60108, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07220: call_seq lbl_88B60198, lbl_88044A58, lbl_88CC21BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60198_88A07220(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC21BC, (ts4_word)(ts4_word)lbl_88044A58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60198, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07290: call_seq lbl_88B601E0, lbl_88044B0C, lbl_88CC21EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B601E0_88A07290(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC21EC, (ts4_word)(ts4_word)lbl_88044B0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B601E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07300: call_seq lbl_88B60210, lbl_88044B94, lbl_88CC221C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60210_88A07300(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC221C, (ts4_word)(ts4_word)lbl_88044B94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60210, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07370: call_seq lbl_88B60240, lbl_88CBFA5C, lbl_88044D60, lbl_88CC224C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60240_88A07370(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC224C, (ts4_word)(ts4_word)lbl_88044D60, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60240, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A073E8: call_seq lbl_88B60270, lbl_88CBFA5C, lbl_88044C84, lbl_88CC227C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60270_88A073E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC227C, (ts4_word)(ts4_word)lbl_88044C84, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60270, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07460: call_seq lbl_88B60288, lbl_88CBFA5C, lbl_88044C48, lbl_88CC22AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60288_88A07460(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC22AC, (ts4_word)(ts4_word)lbl_88044C48, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60288, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A074D8: call_seq lbl_88B602A0, lbl_88044A08, lbl_88CC22DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B602A0_88A074D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC22DC, (ts4_word)(ts4_word)lbl_88044A08, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B602A0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07548: call_seq lbl_88B602D0, lbl_88CBFA5C, lbl_88044C08, lbl_88CC230C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B602D0_88A07548(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC230C, (ts4_word)(ts4_word)lbl_88044C08, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B602D0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A075C0: call_seq lbl_88B602E8, lbl_88040668, lbl_88CC233C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B602E8_88A075C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC233C, (ts4_word)(ts4_word)lbl_88040668, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B602E8, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07630: call_seq lbl_88B603C0, lbl_88CBFA5C, lbl_88040658, lbl_88CC236C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B603C0_88A07630(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC236C, (ts4_word)(ts4_word)lbl_88040658, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B603C0, (ts4_word)18, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A076A8: call_seq lbl_88B60570, lbl_8803F5F4, lbl_88CC239C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60570_88A076A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC239C, (ts4_word)(ts4_word)lbl_8803F5F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60570, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07718: call_seq lbl_88B60708, lbl_88CC0E9C, lbl_8803F64C, lbl_88CC23CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60708_88A07718(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC23CC, (ts4_word)(ts4_word)lbl_8803F64C, (ts4_word)(ts4_word)lbl_88CC0E9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60708, (ts4_word)26, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07790: call_seq lbl_88CBFA5C, lbl_8804494C, lbl_88CC23FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBFA5C_88A07790(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC23FC, (ts4_word)(ts4_word)lbl_8804494C, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A077F8: call_seq lbl_88B60978, lbl_88CC23FC, lbl_88044700, lbl_88CC242C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60978_88A077F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC242C, (ts4_word)(ts4_word)lbl_88044700, (ts4_word)(ts4_word)lbl_88CC23FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60978, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07870: call_seq lbl_88CBFA5C, lbl_88044924, lbl_88CC245C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBFA5C_88A07870(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC245C, (ts4_word)(ts4_word)lbl_88044924, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A078D8: call_seq lbl_88B609F0, lbl_88044438, lbl_88CC248C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B609F0_88A078D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC248C, (ts4_word)(ts4_word)lbl_88044438, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B609F0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07948: call_seq lbl_88B60A38, lbl_88CC245C, lbl_88044680, lbl_88CC24BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60A38_88A07948(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC24BC, (ts4_word)(ts4_word)lbl_88044680, (ts4_word)(ts4_word)lbl_88CC245C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60A38, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A079C0: call_seq lbl_88CBFA5C, lbl_880448C8, lbl_88CC24EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBFA5C_88A079C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC24EC, (ts4_word)(ts4_word)lbl_880448C8, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07A28: call_seq lbl_88CBFA5C, lbl_880448FC, lbl_88CC251C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBFA5C_88A07A28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC251C, (ts4_word)(ts4_word)lbl_880448FC, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07A90: call_seq lbl_88B60A68, lbl_88CC24EC, lbl_88044524, lbl_88CC254C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60A68_88A07A90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC254C, (ts4_word)(ts4_word)lbl_88044524, (ts4_word)(ts4_word)lbl_88CC24EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60A68, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07B08: call_seq lbl_88B60AC8, lbl_88CC251C, lbl_880446BC, lbl_88CC257C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60AC8_88A07B08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC257C, (ts4_word)(ts4_word)lbl_880446BC, (ts4_word)(ts4_word)lbl_88CC251C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60AC8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07B80: call_seq lbl_88CBFA5C, lbl_8804489C, lbl_88CC25AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBFA5C_88A07B80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC25AC, (ts4_word)(ts4_word)lbl_8804489C, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07BE8: call_seq lbl_88B60B28, lbl_88CC25AC, lbl_88044650, lbl_88CC25DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60B28_88A07BE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC25DC, (ts4_word)(ts4_word)lbl_88044650, (ts4_word)(ts4_word)lbl_88CC25AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60B28, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07C60: call_seq lbl_88B60C18, lbl_88044324, lbl_88CC260C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60C18_88A07C60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC260C, (ts4_word)(ts4_word)lbl_88044324, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60C18, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07CD0: call_seq lbl_88B60D08, lbl_88044370, lbl_88CC263C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60D08_88A07CD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC263C, (ts4_word)(ts4_word)lbl_88044370, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60D08, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07D40: call_seq lbl_88B60D50, lbl_8803F610, lbl_88CC266C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60D50_88A07D40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC266C, (ts4_word)(ts4_word)lbl_8803F610, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60D50, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07DB0: call_seq lbl_88B60E28, lbl_8803F634, lbl_88CC269C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60E28_88A07DB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC269C, (ts4_word)(ts4_word)lbl_8803F634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60E28, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07E20: call_seq lbl_88CBFA5C, lbl_88044874, lbl_88CC26CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CBFA5C_88A07E20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC26CC, (ts4_word)(ts4_word)lbl_88044874, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07E88: call_seq lbl_88B60E40, lbl_88CC26CC, lbl_8804461C, lbl_88CC26FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60E40_88A07E88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC26FC, (ts4_word)(ts4_word)lbl_8804461C, (ts4_word)(ts4_word)lbl_88CC26CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60E40, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07F00: call_seq lbl_88B60E88, lbl_88044268, lbl_88CC272C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60E88_88A07F00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC272C, (ts4_word)(ts4_word)lbl_88044268, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60E88, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A07F70: call_seq lbl_88B60ED0, lbl_88CBFA5C, lbl_8804484C, lbl_88CC275C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B60ED0_88A07F70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC275C, (ts4_word)(ts4_word)lbl_8804484C, (ts4_word)(ts4_word)lbl_88CBFA5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B60ED0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}
