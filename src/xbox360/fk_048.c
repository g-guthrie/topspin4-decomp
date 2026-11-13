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
extern char lbl_8803CB50[];
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
extern char lbl_8803ECF4[];
extern char lbl_8803ED14[];
extern char lbl_8803ED20[];
extern char lbl_8803ED28[];
extern char lbl_8803ED40[];
extern char lbl_8803ED58[];
extern char lbl_8803ED7C[];
extern char lbl_8803EE7C[];
extern char lbl_8803EEE8[];
extern char lbl_8803EEFC[];
extern char lbl_8803EF9C[];
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
extern char lbl_8803F9C0[];
extern char lbl_8803F9D4[];
extern char lbl_8804002C[];
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
extern char lbl_88040228[];
extern char lbl_88040278[];
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
extern char lbl_88041284[];
extern char lbl_88041578[];
extern char lbl_88041584[];
extern char lbl_880415D4[];
extern char lbl_880415F8[];
extern char lbl_88041618[];
extern char lbl_88041634[];
extern char lbl_88041AFC[];
extern char lbl_88041B0C[];
extern char lbl_88041B24[];
extern char lbl_88041E68[];
extern char lbl_88041E7C[];
extern char lbl_88041E98[];
extern char lbl_88041EBC[];
extern char lbl_8804205C[];
extern char lbl_88042074[];
extern char lbl_88042098[];
extern char lbl_880420B8[];
extern char lbl_880420C8[];
extern char lbl_880420E4[];
extern char lbl_880420FC[];
extern char lbl_88042110[];
extern char lbl_88042128[];
extern char lbl_88042140[];
extern char lbl_8804215C[];
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
extern char lbl_88045BCC[];
extern char lbl_88045C08[];
extern char lbl_88045D00[];
extern char lbl_88045D4C[];
extern char lbl_88045D94[];
extern char lbl_88045E48[];
extern char lbl_88045F18[];
extern char lbl_88045F84[];
extern char lbl_88045FF4[];
extern char lbl_88046098[];
extern char lbl_88046108[];
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
extern char lbl_88046820[];
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
extern char lbl_88046B18[];
extern char lbl_88046B60[];
extern char lbl_88046C00[];
extern char lbl_88046C24[];
extern char lbl_88046C48[];
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
extern char lbl_8805704C[];
extern char lbl_88058A10[];
extern char lbl_88058A20[];
extern char lbl_8805A5DC[];
extern char lbl_8805A610[];
extern char lbl_8805A624[];
extern char lbl_8805A668[];
extern char lbl_8805A67C[];
extern char lbl_8805A6A8[];
extern char lbl_8805A748[];
extern char lbl_8805A794[];
extern char lbl_8805A834[];
extern char lbl_8805A8A0[];
extern char lbl_8805A8C4[];
extern char lbl_8805A90C[];
extern char lbl_8805A978[];
extern char lbl_8805A9B0[];
extern char lbl_8805AAA8[];
extern char lbl_8805AABC[];
extern char lbl_8805AAD8[];
extern char lbl_8805AC58[];
extern char lbl_8805ACAC[];
extern char lbl_8805ACE8[];
extern char lbl_8805AD20[];
extern char lbl_8805AD64[];
extern char lbl_8805AD90[];
extern char lbl_8805ADD4[];
extern char lbl_8805AE10[];
extern char lbl_8805AE4C[];
extern char lbl_8805AE60[];
extern char lbl_8805AED8[];
extern char lbl_8805AF04[];
extern char lbl_8805AF18[];
extern char lbl_8805AFD8[];
extern char lbl_8805B054[];
extern char lbl_8805B178[];
extern char lbl_8805B1A0[];
extern char lbl_8805B1B8[];
extern char lbl_88B850FC[];
extern char lbl_88B85118[];
extern char lbl_88B85160[];
extern char lbl_88B851F0[];
extern char lbl_88B85280[];
extern char lbl_88B852E0[];
extern char lbl_88B85310[];
extern char lbl_88B85370[];
extern char lbl_88B853D0[];
extern char lbl_88B85448[];
extern char lbl_88B85550[];
extern char lbl_88B8565C[];
extern char lbl_88B8568C[];
extern char lbl_88B85690[];
extern char lbl_88B85738[];
extern char lbl_88B85780[];
extern char lbl_88B85840[];
extern char lbl_88B85888[];
extern char lbl_88B858B8[];
extern char lbl_88B858D0[];
extern char lbl_88B85900[];
extern char lbl_88B85960[];
extern char lbl_88B85990[];
extern char lbl_88B85B10[];
extern char lbl_88B85B28[];
extern char lbl_88B85B88[];
extern char lbl_88B85C60[];
extern char lbl_88B85D68[];
extern char lbl_88B85D98[];
extern char lbl_88B85D9C[];
extern char lbl_88B85DCC[];
extern char lbl_88B85DD0[];
extern char lbl_88B85E60[];
extern char lbl_88B85E90[];
extern char lbl_88B85F20[];
extern char lbl_88B86070[];
extern char lbl_88B86130[];
extern char lbl_88B86148[];
extern char lbl_88B861D8[];
extern char lbl_88B861F4[];
extern char lbl_88B8620C[];
extern char lbl_88B86228[];
extern char lbl_88B86288[];
extern char lbl_88B86348[];
extern char lbl_88B86390[];
extern char lbl_88B86514[];
extern char lbl_88B86520[];
extern char lbl_88B86580[];
extern char lbl_88B865B0[];
extern char lbl_88B865C8[];
extern char lbl_88B865F8[];
extern char lbl_88B866A0[];
extern char lbl_88B866D0[];
extern char lbl_88B86700[];
extern char lbl_88B8670C[];
extern char lbl_88B86724[];
extern char lbl_88B86754[];
extern char lbl_88B8676C[];
extern char lbl_88B86778[];
extern char lbl_88B867C0[];
extern char lbl_88B867F0[];
extern char lbl_88B86824[];
extern char lbl_88B86828[];
extern char lbl_88B86888[];
extern char lbl_88B86990[];
extern char lbl_88B869A8[];
extern char lbl_88B86A20[];
extern char lbl_88B86A38[];
extern char lbl_88B86A68[];
extern char lbl_88B86A98[];
extern char lbl_88B86AC8[];
extern char lbl_88B86AE0[];
extern char lbl_88B86B10[];
extern char lbl_88B86B28[];
extern char lbl_88B86B58[];
extern char lbl_88B86C00[];
extern char lbl_88B86C30[];
extern char lbl_88B86C48[];
extern char lbl_88B86C78[];
extern char lbl_88B86D38[];
extern char lbl_88B86D40[];
extern char lbl_88B86D70[];
extern char lbl_88B86E30[];
extern char lbl_88B86E34[];
extern char lbl_88B86E4C[];
extern char lbl_88B86E7C[];
extern char lbl_88B86E80[];
extern char lbl_88B86E98[];
extern char lbl_88B86EE0[];
extern char lbl_88B86F10[];
extern char lbl_88B87030[];
extern char lbl_88B870C0[];
extern char lbl_88B87180[];
extern char lbl_88B87258[];
extern char lbl_88B87318[];
extern char lbl_88B873C0[];
extern char lbl_88B874E0[];
extern char lbl_88B87540[];
extern char lbl_88B87648[];
extern char lbl_88B87720[];
extern char lbl_88B87768[];
extern char lbl_88B87780[];
extern char lbl_88B877C8[];
extern char lbl_88B877E0[];
extern char lbl_88B87828[];
extern char lbl_88B87888[];
extern char lbl_88B878D0[];
extern char lbl_88B87934[];
extern char lbl_88B87964[];
extern char lbl_88B8797C[];
extern char lbl_88B87994[];
extern char lbl_88B879B0[];
extern char lbl_88B87A10[];
extern char lbl_88B87A28[];
extern char lbl_88B87A58[];
extern char lbl_88B87A70[];
extern char lbl_88B87AA0[];
extern char lbl_88B87AB8[];
extern char lbl_88B87AD0[];
extern char lbl_88B87B48[];
extern char lbl_88B87B90[];
extern char lbl_88B87BC0[];
extern char lbl_88B87BF0[];
extern char lbl_88B87C38[];
extern char lbl_88B87CB4[];
extern char lbl_88B87D4C[];
extern char lbl_88B87D50[];
extern char lbl_88B87DB0[];
extern char lbl_88B87E40[];
extern char lbl_88B87E70[];
extern char lbl_88B87E88[];
extern char lbl_88B87EA0[];
extern char lbl_88B87EA8[];
extern char lbl_88B87F20[];
extern char lbl_88B87F38[];
extern char lbl_88B87F68[];
extern char lbl_88B87F98[];
extern char lbl_88B87FC8[];
extern char lbl_88B88010[];
extern char lbl_88B880B8[];
extern char lbl_88B88100[];
extern char lbl_88B88160[];
extern char lbl_88B881F0[];
extern char lbl_88B88208[];
extern char lbl_88B88238[];
extern char lbl_88B88280[];
extern char lbl_88B882C8[];
extern char lbl_88B882E0[];
extern char lbl_88B88310[];
extern char lbl_88B88318[];
extern char lbl_88B88348[];
extern char lbl_88B88360[];
extern char lbl_88B88378[];
extern char lbl_88B883A8[];
extern char lbl_88B883D8[];
extern char lbl_88B88408[];
extern char lbl_88B88420[];
extern char lbl_88B88438[];
extern char lbl_88B88480[];
extern char lbl_88B884C8[];
extern char lbl_88B884E0[];
extern char lbl_88B88510[];
extern char lbl_88B88588[];
extern char lbl_88B88618[];
extern char lbl_88B8B330[];
extern char lbl_88B8B498[];
extern char lbl_88B8B630[];
extern char lbl_88B8B738[];
extern char lbl_88B8B858[];
extern char lbl_88B8B918[];
extern char lbl_88B8B9A8[];
extern char lbl_88B8B9D8[];
extern char lbl_88B8BA08[];
extern char lbl_88B8BA38[];
extern char lbl_88B8BAB0[];
extern char lbl_88B8BAF8[];
extern char lbl_88B8BB70[];
extern char lbl_88B8BC30[];
extern char lbl_88B8BCC0[];
extern char lbl_88B8BDF8[];
extern char lbl_88B8BE10[];
extern char lbl_88CD697C[];
extern char lbl_88CD69AC[];
extern char lbl_88CD69DC[];
extern char lbl_88CD6A0C[];
extern char lbl_88CD6A3C[];
extern char lbl_88CD6A6C[];
extern char lbl_88CD6A9C[];
extern char lbl_88CD6ACC[];
extern char lbl_88CD6AFC[];
extern char lbl_88CD6B2C[];
extern char lbl_88CD6B5C[];
extern char lbl_88CD6B8C[];
extern char lbl_88CD6BBC[];
extern char lbl_88CD6BEC[];
extern char lbl_88CD6C1C[];
extern char lbl_88CD6C4C[];
extern char lbl_88CD6C7C[];
extern char lbl_88CD6CAC[];
extern char lbl_88CD6CDC[];
extern char lbl_88CD6D3C[];
extern char lbl_88CD6D6C[];
extern char lbl_88CD6D9C[];
extern char lbl_88CD6DCC[];
extern char lbl_88CD6DFC[];
extern char lbl_88CD6E2C[];
extern char lbl_88CD6E5C[];
extern char lbl_88CD6E8C[];
extern char lbl_88CD6EBC[];
extern char lbl_88CD6EEC[];
extern char lbl_88CD6F1C[];
extern char lbl_88CD6F4C[];
extern char lbl_88CD6FAC[];
extern char lbl_88CD6FDC[];
extern char lbl_88CD703C[];
extern char lbl_88CD706C[];
extern char lbl_88CD709C[];
extern char lbl_88CD70CC[];
extern char lbl_88CD70FC[];
extern char lbl_88CD712C[];
extern char lbl_88CD715C[];
extern char lbl_88CD718C[];
extern char lbl_88CD71BC[];
extern char lbl_88CD71EC[];
extern char lbl_88CD721C[];
extern char lbl_88CD724C[];
extern char lbl_88CD727C[];
extern char lbl_88CD72AC[];
extern char lbl_88CD72DC[];
extern char lbl_88CD733C[];
extern char lbl_88CD736C[];
extern char lbl_88CD739C[];
extern char lbl_88CD73CC[];
extern char lbl_88CD73FC[];
extern char lbl_88CD742C[];
extern char lbl_88CD745C[];
extern char lbl_88CD748C[];
extern char lbl_88CD74BC[];
extern char lbl_88CD74EC[];
extern char lbl_88CD751C[];
extern char lbl_88CD754C[];
extern char lbl_88CD757C[];
extern char lbl_88CD75AC[];
extern char lbl_88CD75DC[];
extern char lbl_88CD760C[];
extern char lbl_88CD763C[];
extern char lbl_88CD766C[];
extern char lbl_88CD769C[];
extern char lbl_88CD76CC[];
extern char lbl_88CD76FC[];
extern char lbl_88CD772C[];
extern char lbl_88CD775C[];
extern char lbl_88CD778C[];
extern char lbl_88CD77BC[];
extern char lbl_88CD77EC[];
extern char lbl_88CD781C[];
extern char lbl_88CD784C[];
extern char lbl_88CD787C[];
extern char lbl_88CD78AC[];
extern char lbl_88CD78DC[];
extern char lbl_88CD790C[];
extern char lbl_88CD793C[];
extern char lbl_88CD796C[];
extern char lbl_88CD799C[];
extern char lbl_88CD79CC[];
extern char lbl_88CD79FC[];
extern char lbl_88CD7A2C[];
extern char lbl_88CD7A5C[];
extern char lbl_88CD7A8C[];
extern char lbl_88CD7ABC[];
extern char lbl_88CD7AEC[];
extern char lbl_88CD7B1C[];
extern char lbl_88CD7B4C[];
extern char lbl_88CD7B7C[];
extern char lbl_88CD7BAC[];
extern char lbl_88CD7BDC[];
extern char lbl_88CD7C0C[];
extern char lbl_88CD7C3C[];
extern char lbl_88CD7C6C[];
extern char lbl_88CD7C9C[];
extern char lbl_88CD7CCC[];
extern char lbl_88CD7CFC[];
extern char lbl_88CD7D2C[];
extern char lbl_88CD7D5C[];
extern char lbl_88CD7D8C[];
extern char lbl_88CD7DBC[];
extern char lbl_88CD7DEC[];
extern char lbl_88CD7E1C[];
extern char lbl_88CD7E4C[];
extern char lbl_88CD7E7C[];
extern char lbl_88CD7EAC[];
extern char lbl_88CD7EDC[];
extern char lbl_88CD7F0C[];
extern char lbl_88CD7F3C[];
extern char lbl_88CD7F6C[];
extern char lbl_88CD7F9C[];
extern char lbl_88CD7FCC[];
extern char lbl_88CD7FFC[];
extern char lbl_88CD802C[];
extern char lbl_88CD805C[];
extern char lbl_88CD808C[];
extern char lbl_88CD80BC[];
extern char lbl_88CD80EC[];
extern char lbl_88CD811C[];
extern char lbl_88CD814C[];
extern char lbl_88CD817C[];
extern char lbl_88CD81AC[];
extern char lbl_88CD81DC[];
extern char lbl_88CD820C[];
extern char lbl_88CD823C[];
extern char lbl_88CD826C[];
extern char lbl_88CD829C[];
extern char lbl_88CD82CC[];
extern char lbl_88CD82FC[];
extern char lbl_88CD832C[];
extern char lbl_88CD835C[];
extern char lbl_88CD838C[];
extern char lbl_88CD83BC[];
extern char lbl_88CD83EC[];
extern char lbl_88CD844C[];
extern char lbl_88CD847C[];
extern char lbl_88CD84AC[];
extern char lbl_88CD84DC[];
extern char lbl_88CD850C[];
extern char lbl_88CD853C[];
extern char lbl_88CD856C[];
extern char lbl_88CD859C[];
extern char lbl_88CD85CC[];
extern char lbl_88CD85FC[];
extern char lbl_88CD862C[];
extern char lbl_88CD865C[];
extern char lbl_88CD868C[];
extern char lbl_88CD86BC[];
extern char lbl_88CD86EC[];
extern char lbl_88CD871C[];
extern char lbl_88CD874C[];
extern char lbl_88CD877C[];
extern char lbl_88CD87AC[];
extern char lbl_88CD87DC[];
extern char lbl_88CD880C[];
extern char lbl_88CD883C[];
extern char lbl_88CD886C[];
extern char lbl_88CD889C[];
extern char lbl_88CD88CC[];
extern char lbl_88CD88FC[];
extern char lbl_88CD892C[];
extern char lbl_88CD895C[];
extern char lbl_88CD898C[];
extern char lbl_88CD89BC[];
extern char lbl_88CD89EC[];
extern char lbl_88CD8A1C[];
extern char lbl_88CD8A4C[];
extern char lbl_88CD8A7C[];
extern char lbl_88CD8AAC[];
extern char lbl_88CD8ADC[];
extern char lbl_88CD8B0C[];
extern char lbl_88CD8B3C[];
extern char lbl_88CD8B6C[];
extern char lbl_88CD8B9C[];
extern char lbl_88CD8BCC[];
extern char lbl_88CD8BFC[];
extern char lbl_88CD8C2C[];
extern char lbl_88CD8C5C[];
extern char lbl_88CD8C8C[];
extern char lbl_88CD9D0C[];
ts4_word fn_8841F080();

/* Swing_DLL.xex 0x88A38D58: call_seq lbl_88B850FC, lbl_88CD73FC, lbl_8804002C, lbl_88CD697C, lbl_8805A5DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B850FC_88A38D58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD697C, (ts4_word)(ts4_word)lbl_8804002C, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805A5DC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B850FC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38DC8: call_seq lbl_88B85118, lbl_88046C00, lbl_88CD69AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85118_88A38DC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD69AC, (ts4_word)(ts4_word)lbl_88046C00, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85118, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38E38: call_seq lbl_88B85160, lbl_88046C24, lbl_88CD69DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85160_88A38E38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD69DC, (ts4_word)(ts4_word)lbl_88046C24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85160, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38EA8: call_seq lbl_88B851F0, lbl_88046C48, lbl_88CD6A0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B851F0_88A38EA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6A0C, (ts4_word)(ts4_word)lbl_88046C48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B851F0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38F18: call_seq lbl_88CD73FC, lbl_8803EC3C, lbl_88CD6A3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD73FC_88A38F18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6A3C, (ts4_word)(ts4_word)lbl_8803EC3C, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38F80: call_seq lbl_88B85280, lbl_88CD6A3C, lbl_8803ECF4, lbl_88CD6A6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85280_88A38F80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6A6C, (ts4_word)(ts4_word)lbl_8803ECF4, (ts4_word)(ts4_word)lbl_88CD6A3C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85280, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38FF8: call_seq lbl_88B852E0, lbl_8803EEFC, lbl_88CD6A9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B852E0_88A38FF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6A9C, (ts4_word)(ts4_word)lbl_8803EEFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B852E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39068: call_seq lbl_88B85310, lbl_8803EEE8, lbl_88CD6ACC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85310_88A39068(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6ACC, (ts4_word)(ts4_word)lbl_8803EEE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85310, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A390D8: call_seq lbl_88B85370, lbl_8803EE7C, lbl_88CD6AFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85370_88A390D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6AFC, (ts4_word)(ts4_word)lbl_8803EE7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85370, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39148: call_seq lbl_88B853D0, lbl_88041578, lbl_88CD6B2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B853D0_88A39148(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6B2C, (ts4_word)(ts4_word)lbl_88041578, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B853D0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A391B8: call_seq lbl_88B85448, lbl_88042110, lbl_88CD6B5C, lbl_8805A610, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85448_88A391B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6B5C, (ts4_word)(ts4_word)lbl_88042110, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805A610, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B85448, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39228: call_seq lbl_88B85550, lbl_8805A624, lbl_880420FC, lbl_88CD6B8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85550_88A39228(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6B8C, (ts4_word)(ts4_word)lbl_880420FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85550, (ts4_word)11, (ts4_word)(ts4_word)lbl_8805A624, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A392A0: call_seq lbl_88B8565C, lbl_88041204, lbl_88CD6BBC, lbl_8805A668, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8565C_88A392A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6BBC, (ts4_word)(ts4_word)lbl_88041204, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805A668, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B8565C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39310: call_seq lbl_88CD718C, lbl_88053DD8, lbl_88CD6BEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD718C_88A39310(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6BEC, (ts4_word)(ts4_word)lbl_88053DD8, (ts4_word)(ts4_word)lbl_88CD718C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39378: call_seq lbl_8805A67C, lbl_88B85690, lbl_88CD6BEC, lbl_88041268, lbl_88CD6C1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805A67C_88A39378(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6C1C, (ts4_word)(ts4_word)lbl_88041268, (ts4_word)(ts4_word)lbl_88CD6BEC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85690, (ts4_word)7, (ts4_word)(ts4_word)lbl_8805A67C, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A393F0: call_seq lbl_88CD6C1C, lbl_88053DE8, lbl_88CD6C4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD6C1C_88A393F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6C4C, (ts4_word)(ts4_word)lbl_88053DE8, (ts4_word)(ts4_word)lbl_88CD6C1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39458: call_seq lbl_88B85738, lbl_88CD73FC, lbl_8804124C, lbl_88CD6C7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85738_88A39458(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6C7C, (ts4_word)(ts4_word)lbl_8804124C, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85738, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A394D0: call_seq lbl_8805A6A8, lbl_88B85780, lbl_88CD6BEC, lbl_88041238, lbl_88CD6CAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805A6A8_88A394D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6CAC, (ts4_word)(ts4_word)lbl_88041238, (ts4_word)(ts4_word)lbl_88CD6BEC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85780, (ts4_word)8, (ts4_word)(ts4_word)lbl_8805A6A8, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39548: call_seq lbl_88B85840, lbl_8804115C, lbl_88CD6CDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85840_88A39548(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6CDC, (ts4_word)(ts4_word)lbl_8804115C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85840, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A395B8: addr lbl_88B8B330, u32@lbl_88B8568C, u32@0x8 */
void ts4_addr_lbl_88B8B330_88A395B8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8B330) + 8) = (ts4_word)(*(ts4_word *)lbl_88B8568C);
    return;
}

/* Swing_DLL.xex 0x88A39648: call_seq lbl_88B85888, lbl_88CD6BEC, lbl_88041584, lbl_88CD6D3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85888_88A39648(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6D3C, (ts4_word)(ts4_word)lbl_88041584, (ts4_word)(ts4_word)lbl_88CD6BEC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85888, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A396C0: call_seq lbl_88B858B8, lbl_88CD6BEC, lbl_88053E90, lbl_88CD6D6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B858B8_88A396C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6D6C, (ts4_word)(ts4_word)lbl_88053E90, (ts4_word)(ts4_word)lbl_88CD6BEC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B858B8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39738: call_seq lbl_88CD718C, lbl_88053EAC, lbl_88CD6D9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD718C_88A39738(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6D9C, (ts4_word)(ts4_word)lbl_88053EAC, (ts4_word)(ts4_word)lbl_88CD718C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A397A0: call_seq lbl_88B858D0, lbl_88CD6D9C, lbl_88042128, lbl_88CD6DCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B858D0_88A397A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6DCC, (ts4_word)(ts4_word)lbl_88042128, (ts4_word)(ts4_word)lbl_88CD6D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B858D0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39818: call_seq lbl_88B85900, lbl_880420B8, lbl_88CD6DFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85900_88A39818(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6DFC, (ts4_word)(ts4_word)lbl_880420B8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85900, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39888: call_seq lbl_88B85960, lbl_880420E4, lbl_88CD6E2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85960_88A39888(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6E2C, (ts4_word)(ts4_word)lbl_880420E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85960, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A398F8: call_seq lbl_8805A748, lbl_88B85990, lbl_88CD6D9C, lbl_88041634, lbl_88CD6E5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805A748_88A398F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6E5C, (ts4_word)(ts4_word)lbl_88041634, (ts4_word)(ts4_word)lbl_88CD6D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85990, (ts4_word)16, (ts4_word)(ts4_word)lbl_8805A748, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39970: call_seq lbl_88B85B10, lbl_88CD6D9C, lbl_880420C8, lbl_88CD6E8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85B10_88A39970(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6E8C, (ts4_word)(ts4_word)lbl_880420C8, (ts4_word)(ts4_word)lbl_88CD6D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85B10, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A399E8: call_seq lbl_8805A794, lbl_88B85B28, lbl_88CD6D9C, lbl_880411F0, lbl_88CD6EBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805A794_88A399E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6EBC, (ts4_word)(ts4_word)lbl_880411F0, (ts4_word)(ts4_word)lbl_88CD6D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85B28, (ts4_word)4, (ts4_word)(ts4_word)lbl_8805A794, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39A60: call_seq lbl_88B85B88, lbl_88CD6D9C, lbl_880411C8, lbl_88CD6EEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85B88_88A39A60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6EEC, (ts4_word)(ts4_word)lbl_880411C8, (ts4_word)(ts4_word)lbl_88CD6D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85B88, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39AD8: call_seq lbl_88B85C60, lbl_88CD6D9C, lbl_88048610, lbl_88CD6F1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85C60_88A39AD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6F1C, (ts4_word)(ts4_word)lbl_88048610, (ts4_word)(ts4_word)lbl_88CD6D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85C60, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39B50: call_seq lbl_88B85D68, lbl_88CD6D9C, lbl_88042140, lbl_88CD6F4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85D68_88A39B50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6F4C, (ts4_word)(ts4_word)lbl_88042140, (ts4_word)(ts4_word)lbl_88CD6D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85D68, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39BC8: addr lbl_88B8B498, u32@lbl_88B85D98, u32@0x68 */
void ts4_addr_lbl_88B8B498_88A39BC8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8B498) + 104) = (ts4_word)(*(ts4_word *)lbl_88B85D98);
    return;
}

/* Swing_DLL.xex 0x88A39C58: call_seq lbl_8805A834, lbl_88B85D9C, lbl_88CD73FC, lbl_88053F68, lbl_88CD6FAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805A834_88A39C58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6FAC, (ts4_word)(ts4_word)lbl_88053F68, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85D9C, (ts4_word)2, (ts4_word)(ts4_word)lbl_8805A834, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39CD0: call_seq lbl_88B85DD0, lbl_88042098, lbl_88CD6FDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85DD0_88A39CD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6FDC, (ts4_word)(ts4_word)lbl_88042098, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85DD0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39D40: addr lbl_88B8B630, u32@lbl_88B85DCC, u32@0x50 */
void ts4_addr_lbl_88B8B630_88A39D40(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8B630) + 80) = (ts4_word)(*(ts4_word *)lbl_88B85DCC);
    return;
}

/* Swing_DLL.xex 0x88A39DD0: call_seq lbl_88B85E60, lbl_88CD6D9C, lbl_88042074, lbl_88CD703C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85E60_88A39DD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD703C, (ts4_word)(ts4_word)lbl_88042074, (ts4_word)(ts4_word)lbl_88CD6D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85E60, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39E48: call_seq lbl_8805A8A0, lbl_88B85E90, lbl_88CD6D9C, lbl_88041618, lbl_88CD706C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805A8A0_88A39E48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD706C, (ts4_word)(ts4_word)lbl_88041618, (ts4_word)(ts4_word)lbl_88CD6D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85E90, (ts4_word)6, (ts4_word)(ts4_word)lbl_8805A8A0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39EC0: call_seq lbl_88B85F20, lbl_880415F8, lbl_88CD709C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85F20_88A39EC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD709C, (ts4_word)(ts4_word)lbl_880415F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85F20, (ts4_word)14, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39F30: call_seq lbl_8805A8C4, lbl_88B86070, lbl_88CD6D9C, lbl_88040228, lbl_88CD70CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805A8C4_88A39F30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD70CC, (ts4_word)(ts4_word)lbl_88040228, (ts4_word)(ts4_word)lbl_88CD6D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86070, (ts4_word)8, (ts4_word)(ts4_word)lbl_8805A8C4, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A39FA8: call_seq lbl_88B86130, lbl_88CD6D9C, lbl_880415D4, lbl_88CD70FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86130_88A39FA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD70FC, (ts4_word)(ts4_word)lbl_880415D4, (ts4_word)(ts4_word)lbl_88CD6D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86130, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A020: call_seq lbl_88B86148, lbl_88CD6EEC, lbl_880411DC, lbl_88CD712C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86148_88A3A020(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD712C, (ts4_word)(ts4_word)lbl_880411DC, (ts4_word)(ts4_word)lbl_88CD6EEC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86148, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A098: call_seq lbl_88B861D8, lbl_88CD6D9C, lbl_8805704C, lbl_88CD715C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B861D8_88A3A098(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD715C, (ts4_word)(ts4_word)lbl_8805704C, (ts4_word)(ts4_word)lbl_88CD6D9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B861D8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A110: call_seq lbl_88B861F4, lbl_88CD73FC, lbl_8804116C, lbl_88CD718C, lbl_8805A90C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B861F4_88A3A110(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD718C, (ts4_word)(ts4_word)lbl_8804116C, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805A90C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B861F4, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A180: call_seq lbl_88CD73FC, lbl_88058A10, lbl_88CD71BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD73FC_88A3A180(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD71BC, (ts4_word)(ts4_word)lbl_88058A10, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A1E8: call_seq lbl_88B8620C, lbl_88CD71BC, lbl_88058A20, lbl_88CD71EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8620C_88A3A1E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD71EC, (ts4_word)(ts4_word)lbl_88058A20, (ts4_word)(ts4_word)lbl_88CD71BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8620C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A260: call_seq lbl_88B86228, lbl_8804205C, lbl_88CD721C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86228_88A3A260(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD721C, (ts4_word)(ts4_word)lbl_8804205C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86228, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A2D0: call_seq lbl_8805A978, lbl_88B86288, lbl_88041174, lbl_88CD724C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805A978_88A3A2D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD724C, (ts4_word)(ts4_word)lbl_88041174, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805A978, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B86288, (ts4_word)8, (ts4_word)((ts4_word)lbl_8805A978 + 20), (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A348: call_seq lbl_88B86348, lbl_88041194, lbl_88CD727C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86348_88A3A348(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD727C, (ts4_word)(ts4_word)lbl_88041194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86348, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A3B8: call_seq lbl_8805A9B0, lbl_88B86390, lbl_88CD6BEC, lbl_88040218, lbl_88CD72AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805A9B0_88A3A3B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD72AC, (ts4_word)(ts4_word)lbl_88040218, (ts4_word)(ts4_word)lbl_88CD6BEC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86390, (ts4_word)16, (ts4_word)(ts4_word)lbl_8805A9B0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A430: call_seq lbl_88CD6BEC, lbl_88041114, lbl_88CD72DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD6BEC_88A3A430(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD72DC, (ts4_word)(ts4_word)lbl_88041114, (ts4_word)(ts4_word)lbl_88CD6BEC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A498: addr lbl_88B8B738, u32@lbl_88B86514, u32@0x50 */
void ts4_addr_lbl_88B8B738_88A3A498(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8B738) + 80) = (ts4_word)(*(ts4_word *)lbl_88B86514);
    return;
}

/* Swing_DLL.xex 0x88A3A528: call_seq lbl_88B86520, lbl_8805AABC, lbl_88040200, lbl_88CD733C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86520_88A3A528(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD733C, (ts4_word)(ts4_word)lbl_88040200, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86520, (ts4_word)4, (ts4_word)(ts4_word)lbl_8805AABC, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A5A0: call_seq lbl_88B86580, lbl_880401D8, lbl_88CD736C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86580_88A3A5A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD736C, (ts4_word)(ts4_word)lbl_880401D8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86580, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A610: call_seq lbl_88B865B0, lbl_88CD73FC, lbl_880401F0, lbl_88CD739C, lbl_8805AAA8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B865B0_88A3A610(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD739C, (ts4_word)(ts4_word)lbl_880401F0, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805AAA8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B865B0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A680: call_seq lbl_8803C97C, lbl_88CD73CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803C97C_88A3A680(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD73CC, (ts4_word)(ts4_word)lbl_8803C97C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A6E0: call_seq lbl_88B865C8, lbl_88CD73CC, lbl_8803C9DC, lbl_88CD73FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B865C8_88A3A6E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)(ts4_word)lbl_8803C9DC, (ts4_word)(ts4_word)lbl_88CD73CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B865C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A758: call_seq lbl_88B865F8, lbl_8803CC5C, lbl_88CD742C, lbl_8805AAD8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B865F8_88A3A758(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD742C, (ts4_word)(ts4_word)lbl_8803CC5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805AAD8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B865F8, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A7C8: call_seq lbl_88B866A0, lbl_8803CCC4, lbl_88CD745C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B866A0_88A3A7C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD745C, (ts4_word)(ts4_word)lbl_8803CCC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B866A0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A838: call_seq lbl_88B866D0, lbl_8803CCD4, lbl_88CD748C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B866D0_88A3A838(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD748C, (ts4_word)(ts4_word)lbl_8803CCD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B866D0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A8A8: addr lbl_88B8B858, u32@lbl_88B86700, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88B8B858_88A3A8A8(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B86700;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8B858) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8B858) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A3A8C8: call_seq lbl_88B8B858, lbl_8803D124, lbl_88CD74BC, lbl_8805AC58, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8B858_88A3A8C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD74BC, (ts4_word)(ts4_word)lbl_8803D124, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805AC58, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B8B858, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A938: call_seq lbl_88B8670C, lbl_8803CB50, lbl_88CD74EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8670C_88A3A938(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD74EC, (ts4_word)(ts4_word)lbl_8803CB50, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8670C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3A9A8: call_seq lbl_88B86724, lbl_8803D484, lbl_88CD751C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86724_88A3A9A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD751C, (ts4_word)(ts4_word)lbl_8803D484, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86724, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3AA18: call_seq lbl_88B86754, lbl_8803D4A8, lbl_88CD754C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86754_88A3AA18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD754C, (ts4_word)(ts4_word)lbl_8803D4A8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86754, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3AA88: addr lbl_88B8B918, u32@lbl_88B8676C, u32@0x50 */
void ts4_addr_lbl_88B8B918_88A3AA88(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8B918) + 80) = (ts4_word)(*(ts4_word *)lbl_88B8676C);
    return;
}

/* Swing_DLL.xex 0x88A3AAA0: call_seq lbl_88B8B918, lbl_8803D4C4, lbl_88CD757C, lbl_8805ACAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8B918_88A3AAA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD757C, (ts4_word)(ts4_word)lbl_8803D4C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805ACAC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B8B918, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3AB10: call_seq lbl_88B86778, lbl_8803F9C0, lbl_88CD75AC, lbl_8805ACE8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86778_88A3AB10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD75AC, (ts4_word)(ts4_word)lbl_8803F9C0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805ACE8, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B86778, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3AB80: call_seq lbl_88B867C0, lbl_8803CAF0, lbl_88CD75DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B867C0_88A3AB80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD75DC, (ts4_word)(ts4_word)lbl_8803CAF0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B867C0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3ABF0: call_seq lbl_88B867F0, lbl_8803D194, lbl_88CD760C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B867F0_88A3ABF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD760C, (ts4_word)(ts4_word)lbl_8803D194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B867F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3AC60: call_seq lbl_88B86828, lbl_8803D2E0, lbl_88CD763C, lbl_8805AD20, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86828_88A3AC60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD763C, (ts4_word)(ts4_word)lbl_8803D2E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805AD20, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B86828, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3ACD0: call_seq lbl_88B86888, lbl_8803D6A0, lbl_88CD766C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86888_88A3ACD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD766C, (ts4_word)(ts4_word)lbl_8803D6A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86888, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3AD40: call_seq lbl_88B86990, lbl_8803D914, lbl_88CD769C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86990_88A3AD40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD769C, (ts4_word)(ts4_word)lbl_8803D914, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86990, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3ADB0: call_seq lbl_88B869A8, lbl_8803D9E8, lbl_88CD76CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B869A8_88A3ADB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD76CC, (ts4_word)(ts4_word)lbl_8803D9E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B869A8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3AE20: addr lbl_88B8B9A8, u32@lbl_88B86824, u32@0x20 */
void ts4_addr_lbl_88B8B9A8_88A3AE20(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8B9A8) + 32) = (ts4_word)(*(ts4_word *)lbl_88B86824);
    return;
}

/* Swing_DLL.xex 0x88A3AE38: call_seq lbl_88B8B9A8, lbl_8803F988, lbl_88CD76FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8B9A8_88A3AE38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD76FC, (ts4_word)(ts4_word)lbl_8803F988, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8B9A8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3AEA8: addr lbl_88B8B9D8, u32@lbl_88B86824, u32@0x20 */
void ts4_addr_lbl_88B8B9D8_88A3AEA8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8B9D8) + 32) = (ts4_word)(*(ts4_word *)lbl_88B86824);
    return;
}

/* Swing_DLL.xex 0x88A3AEC0: call_seq lbl_88B8B9D8, lbl_8803F974, lbl_88CD772C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8B9D8_88A3AEC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD772C, (ts4_word)(ts4_word)lbl_8803F974, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8B9D8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3AF30: call_seq lbl_88B86A20, lbl_8804E4DC, lbl_88CD775C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86A20_88A3AF30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD775C, (ts4_word)(ts4_word)lbl_8804E4DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86A20, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3AFA0: addr lbl_88B8BA08, u32@lbl_88B86824, u32@0x20 */
void ts4_addr_lbl_88B8BA08_88A3AFA0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8BA08) + 32) = (ts4_word)(*(ts4_word *)lbl_88B86824);
    return;
}

/* Swing_DLL.xex 0x88A3AFB8: call_seq lbl_88B8BA08, lbl_8803F960, lbl_88CD778C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8BA08_88A3AFB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD778C, (ts4_word)(ts4_word)lbl_8803F960, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8BA08, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B028: call_seq lbl_88B86A38, lbl_8803F9B0, lbl_88CD77BC, lbl_8805AD64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86A38_88A3B028(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD77BC, (ts4_word)(ts4_word)lbl_8803F9B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805AD64, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B86A38, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B098: call_seq lbl_88B86A68, lbl_8803F99C, lbl_88CD77EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86A68_88A3B098(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD77EC, (ts4_word)(ts4_word)lbl_8803F99C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86A68, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B108: call_seq lbl_88B86A98, lbl_8804E4F4, lbl_88CD781C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86A98_88A3B108(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD781C, (ts4_word)(ts4_word)lbl_8804E4F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86A98, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B178: call_seq lbl_88B86AC8, lbl_88CD787C, lbl_8804E50C, lbl_88CD784C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86AC8_88A3B178(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD784C, (ts4_word)(ts4_word)lbl_8804E50C, (ts4_word)(ts4_word)lbl_88CD787C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86AC8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B1F0: call_seq lbl_88B86AE0, lbl_8804E524, lbl_88CD787C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86AE0_88A3B1F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD787C, (ts4_word)(ts4_word)lbl_8804E524, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86AE0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B260: call_seq lbl_88B86B10, lbl_8804E53C, lbl_88CD78AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86B10_88A3B260(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD78AC, (ts4_word)(ts4_word)lbl_8804E53C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86B10, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B2D0: call_seq lbl_88B86B28, lbl_8804E560, lbl_88CD78DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86B28_88A3B2D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD78DC, (ts4_word)(ts4_word)lbl_8804E560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86B28, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B340: call_seq lbl_88B86B58, lbl_8803F5C8, lbl_88CD790C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86B58_88A3B340(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD790C, (ts4_word)(ts4_word)lbl_8803F5C8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86B58, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B3B0: call_seq lbl_88B86C00, lbl_88054050, lbl_88CD793C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86C00_88A3B3B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD793C, (ts4_word)(ts4_word)lbl_88054050, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86C00, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B420: call_seq lbl_88B86C30, lbl_88054068, lbl_88CD796C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86C30_88A3B420(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD796C, (ts4_word)(ts4_word)lbl_88054068, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86C30, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B490: call_seq lbl_88B86C48, lbl_8804C310, lbl_88CD799C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86C48_88A3B490(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD799C, (ts4_word)(ts4_word)lbl_8804C310, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86C48, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B500: call_seq lbl_88B86C78, lbl_8803ED20, lbl_88CD79CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86C78_88A3B500(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD79CC, (ts4_word)(ts4_word)lbl_8803ED20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86C78, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B570: addr lbl_88B8BA38, u32@lbl_88B86D38, u32@0x8 */
void ts4_addr_lbl_88B8BA38_88A3B570(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8BA38) + 8) = (ts4_word)(*(ts4_word *)lbl_88B86D38);
    return;
}

/* Swing_DLL.xex 0x88A3B588: call_seq lbl_88B8BA38, lbl_8804C33C, lbl_88CD79FC, lbl_8805AD90, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8BA38_88A3B588(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD79FC, (ts4_word)(ts4_word)lbl_8804C33C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805AD90, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B8BA38, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B5F8: call_seq lbl_88B86D40, lbl_8803ED28, lbl_88CD7A2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86D40_88A3B5F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7A2C, (ts4_word)(ts4_word)lbl_8803ED28, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86D40, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B668: call_seq lbl_88B86D70, lbl_8803ED14, lbl_88CD7A5C, lbl_8805ADD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86D70_88A3B668(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7A5C, (ts4_word)(ts4_word)lbl_8803ED14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805ADD4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B86D70, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B6D8: addr lbl_88B8BAB0, u32@lbl_88B86E30, u32@0x20 */
void ts4_addr_lbl_88B8BAB0_88A3B6D8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8BAB0) + 32) = (ts4_word)(*(ts4_word *)lbl_88B86E30);
    return;
}

/* Swing_DLL.xex 0x88A3B6F0: call_seq lbl_88B8BAB0, lbl_8804E57C, lbl_88CD7A8C, lbl_8805AE10, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8BAB0_88A3B6F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7A8C, (ts4_word)(ts4_word)lbl_8804E57C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805AE10, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B8BAB0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B760: call_seq lbl_88B86E34, lbl_8804C348, lbl_88CD7ABC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86E34_88A3B760(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7ABC, (ts4_word)(ts4_word)lbl_8804C348, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86E34, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B7D0: call_seq lbl_88B86E4C, lbl_8804C358, lbl_88CD7AEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86E4C_88A3B7D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7AEC, (ts4_word)(ts4_word)lbl_8804C358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86E4C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B840: addr lbl_88B8BAF8, u32@lbl_88B86E7C, u32@0x8 */
void ts4_addr_lbl_88B8BAF8_88A3B840(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8BAF8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B86E7C);
    return;
}

/* Swing_DLL.xex 0x88A3B858: call_seq lbl_88B8BAF8, lbl_8804C380, lbl_88CD7B1C, lbl_8805AE4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8BAF8_88A3B858(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7B1C, (ts4_word)(ts4_word)lbl_8804C380, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805AE4C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B8BAF8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B8C8: call_seq lbl_88B86E80, lbl_88042408, lbl_88CD7B4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86E80_88A3B8C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7B4C, (ts4_word)(ts4_word)lbl_88042408, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86E80, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B938: call_seq lbl_88B86E98, lbl_880423F8, lbl_88CD7B7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86E98_88A3B938(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7B7C, (ts4_word)(ts4_word)lbl_880423F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86E98, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3B9A8: call_seq lbl_88B86EE0, lbl_8804C390, lbl_88CD7BAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86EE0_88A3B9A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7BAC, (ts4_word)(ts4_word)lbl_8804C390, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86EE0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3BA18: call_seq lbl_88B86F10, lbl_8804C3A0, lbl_88CD7BDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B86F10_88A3BA18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7BDC, (ts4_word)(ts4_word)lbl_8804C3A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B86F10, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3BA88: call_seq lbl_88B87030, lbl_8804C3B0, lbl_88CD7C0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87030_88A3BA88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7C0C, (ts4_word)(ts4_word)lbl_8804C3B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87030, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3BAF8: call_seq lbl_88B870C0, lbl_8804C3C4, lbl_88CD7C3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B870C0_88A3BAF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7C3C, (ts4_word)(ts4_word)lbl_8804C3C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B870C0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3BB68: call_seq lbl_88B87180, lbl_8804C3DC, lbl_88CD7C6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87180_88A3BB68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7C6C, (ts4_word)(ts4_word)lbl_8804C3DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87180, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3BBD8: call_seq lbl_88B87258, lbl_8804C3F8, lbl_88CD7C9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87258_88A3BBD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7C9C, (ts4_word)(ts4_word)lbl_8804C3F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87258, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3BC48: call_seq lbl_88B87318, lbl_8804C410, lbl_88CD7CCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87318_88A3BC48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7CCC, (ts4_word)(ts4_word)lbl_8804C410, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87318, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3BCB8: call_seq lbl_88B873C0, lbl_8805AE60, lbl_8803F5BC, lbl_88CD7CFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B873C0_88A3BCB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7CFC, (ts4_word)(ts4_word)lbl_8803F5BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B873C0, (ts4_word)12, (ts4_word)(ts4_word)lbl_8805AE60, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3BD30: call_seq lbl_88B874E0, lbl_8804C428, lbl_88CD7D2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B874E0_88A3BD30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7D2C, (ts4_word)(ts4_word)lbl_8804C428, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B874E0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3BDA0: call_seq lbl_88B87540, lbl_8803F5E0, lbl_88CD7D5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87540_88A3BDA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7D5C, (ts4_word)(ts4_word)lbl_8803F5E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87540, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3BE10: call_seq lbl_88B87648, lbl_88040278, lbl_88CD7D8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87648_88A3BE10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7D8C, (ts4_word)(ts4_word)lbl_88040278, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87648, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3BE80: call_seq lbl_88B87720, lbl_8803ED58, lbl_88CD7DBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87720_88A3BE80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7DBC, (ts4_word)(ts4_word)lbl_8803ED58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87720, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3BEF0: call_seq lbl_88B87768, lbl_8803ED40, lbl_88CD7DEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87768_88A3BEF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7DEC, (ts4_word)(ts4_word)lbl_8803ED40, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87768, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3BF60: call_seq lbl_88B87780, lbl_880433FC, lbl_88CD7E1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87780_88A3BF60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7E1C, (ts4_word)(ts4_word)lbl_880433FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87780, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3BFD0: call_seq lbl_88B877C8, lbl_8804342C, lbl_88CD7E4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B877C8_88A3BFD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7E4C, (ts4_word)(ts4_word)lbl_8804342C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B877C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C040: call_seq lbl_88B877E0, lbl_88CD73FC, lbl_8803ED7C, lbl_88CD7E7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B877E0_88A3C040(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7E7C, (ts4_word)(ts4_word)lbl_8803ED7C, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B877E0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C0B8: call_seq lbl_88B87828, lbl_88046454, lbl_88CD7EAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87828_88A3C0B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7EAC, (ts4_word)(ts4_word)lbl_88046454, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87828, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C128: call_seq lbl_88B87888, lbl_88CD7EAC, lbl_8804233C, lbl_88CD7EDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87888_88A3C128(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7EDC, (ts4_word)(ts4_word)lbl_8804233C, (ts4_word)(ts4_word)lbl_88CD7EAC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87888, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C1A0: call_seq lbl_880469C4, lbl_88CD7F0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880469C4_88A3C1A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7F0C, (ts4_word)(ts4_word)lbl_880469C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C200: call_seq lbl_88B878D0, lbl_88CD9D0C, lbl_88042E48, lbl_88CD7F3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B878D0_88A3C200(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7F3C, (ts4_word)(ts4_word)lbl_88042E48, (ts4_word)(ts4_word)lbl_88CD9D0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B878D0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C278: call_seq lbl_88046B60, lbl_88CD7F6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046B60_88A3C278(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7F6C, (ts4_word)(ts4_word)lbl_88046B60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C2D8: call_seq lbl_88CD73FC, lbl_88042318, lbl_88CD7F9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD73FC_88A3C2D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7F9C, (ts4_word)(ts4_word)lbl_88042318, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C340: call_seq lbl_8805AED8, lbl_88CD73FC, lbl_88046B18, lbl_88CD7FCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805AED8_88A3C340(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7FCC, (ts4_word)(ts4_word)lbl_88046B18, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805AED8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C3A8: call_seq lbl_88046A84, lbl_88CD7FFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A84_88A3C3A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD7FFC, (ts4_word)(ts4_word)lbl_88046A84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C408: call_seq lbl_88CD7FCC, lbl_88046820, lbl_88CD802C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD7FCC_88A3C408(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD802C, (ts4_word)(ts4_word)lbl_88046820, (ts4_word)(ts4_word)lbl_88CD7FCC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C470: call_seq lbl_88B87934, lbl_88CD7F9C, lbl_8804232C, lbl_88CD805C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87934_88A3C470(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD805C, (ts4_word)(ts4_word)lbl_8804232C, (ts4_word)(ts4_word)lbl_88CD7F9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87934, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C4E8: call_seq lbl_88B87964, lbl_88CD7F9C, lbl_8804690C, lbl_88CD808C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87964_88A3C4E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD808C, (ts4_word)(ts4_word)lbl_8804690C, (ts4_word)(ts4_word)lbl_88CD7F9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87964, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C560: call_seq lbl_88CD7F9C, lbl_8804671C, lbl_88CD80BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD7F9C_88A3C560(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD80BC, (ts4_word)(ts4_word)lbl_8804671C, (ts4_word)(ts4_word)lbl_88CD7F9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C5C8: call_seq lbl_88046A50, lbl_88CD80EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A50_88A3C5C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD80EC, (ts4_word)(ts4_word)lbl_88046A50, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C628: call_seq lbl_88B8797C, lbl_88CD73FC, lbl_88041284, lbl_88CD811C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8797C_88A3C628(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD811C, (ts4_word)(ts4_word)lbl_88041284, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8797C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C6A0: call_seq lbl_88046994, lbl_88CD814C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046994_88A3C6A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD814C, (ts4_word)(ts4_word)lbl_88046994, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C700: call_seq lbl_88B87994, lbl_88CD814C, lbl_88046678, lbl_88CD817C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87994_88A3C700(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD817C, (ts4_word)(ts4_word)lbl_88046678, (ts4_word)(ts4_word)lbl_88CD814C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87994, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C778: call_seq lbl_88B879B0, lbl_88046220, lbl_88CD81AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B879B0_88A3C778(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD81AC, (ts4_word)(ts4_word)lbl_88046220, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B879B0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C7E8: call_seq lbl_88B87A10, lbl_88CD82CC, lbl_8804694C, lbl_88CD81DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87A10_88A3C7E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD81DC, (ts4_word)(ts4_word)lbl_8804694C, (ts4_word)(ts4_word)lbl_88CD82CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87A10, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C860: call_seq lbl_88B87A28, lbl_88CD811C, lbl_88040110, lbl_88CD820C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87A28_88A3C860(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD820C, (ts4_word)(ts4_word)lbl_88040110, (ts4_word)(ts4_word)lbl_88CD811C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87A28, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C8D8: call_seq lbl_88B87A58, lbl_88CD811C, lbl_88040100, lbl_88CD823C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87A58_88A3C8D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD823C, (ts4_word)(ts4_word)lbl_88040100, (ts4_word)(ts4_word)lbl_88CD811C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87A58, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C950: call_seq lbl_88B87A70, lbl_88CD82CC, lbl_8804011C, lbl_88CD826C, lbl_8805AF04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87A70_88A3C950(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD826C, (ts4_word)(ts4_word)lbl_8804011C, (ts4_word)(ts4_word)lbl_88CD82CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805AF04, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B87A70, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3C9C8: call_seq lbl_88B87AA0, lbl_88CD811C, lbl_880400A8, lbl_88CD829C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87AA0_88A3C9C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD829C, (ts4_word)(ts4_word)lbl_880400A8, (ts4_word)(ts4_word)lbl_88CD811C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87AA0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3CA40: call_seq lbl_88B87AB8, lbl_88CD883C, lbl_88042370, lbl_88CD82CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87AB8_88A3CA40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD82CC, (ts4_word)(ts4_word)lbl_88042370, (ts4_word)(ts4_word)lbl_88CD883C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87AB8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3CAB8: call_seq lbl_8805AF18, lbl_88B87AD0, lbl_88CD82CC, lbl_88041B24, lbl_88CD82FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805AF18_88A3CAB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD82FC, (ts4_word)(ts4_word)lbl_88041B24, (ts4_word)(ts4_word)lbl_88CD82CC, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87AD0, (ts4_word)5, (ts4_word)(ts4_word)lbl_8805AF18, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3CB30: call_seq lbl_88B87B48, lbl_88CD829C, lbl_880468C8, lbl_88CD832C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87B48_88A3CB30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD832C, (ts4_word)(ts4_word)lbl_880468C8, (ts4_word)(ts4_word)lbl_88CD829C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87B48, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3CBA8: call_seq lbl_88B87B90, lbl_88CD82CC, lbl_880400E8, lbl_88CD835C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87B90_88A3CBA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD835C, (ts4_word)(ts4_word)lbl_880400E8, (ts4_word)(ts4_word)lbl_88CD82CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87B90, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3CC20: call_seq lbl_88B87BC0, lbl_88CD82CC, lbl_880400D0, lbl_88CD838C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87BC0_88A3CC20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD838C, (ts4_word)(ts4_word)lbl_880400D0, (ts4_word)(ts4_word)lbl_88CD82CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87BC0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3CC98: call_seq lbl_88B87BF0, lbl_880463D4, lbl_88CD83BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87BF0_88A3CC98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD83BC, (ts4_word)(ts4_word)lbl_880463D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87BF0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3CD08: call_seq lbl_88B87C38, lbl_88CD82CC, lbl_88046868, lbl_88CD83EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87C38_88A3CD08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD83EC, (ts4_word)(ts4_word)lbl_88046868, (ts4_word)(ts4_word)lbl_88CD82CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87C38, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3CDF8: addr lbl_88B8BB70, u32@lbl_88B87D4C, u32@lbl_88B87CB4, u32@0x8, u32@0x38 */
void ts4_addr_lbl_88B8BB70_88A3CDF8(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88B87D4C;
    t2 = *(ts4_word *)lbl_88B87CB4;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8BB70) + 8) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8BB70) + 56) = (ts4_word)t2;
    return;
}

/* Swing_DLL.xex 0x88A3CE20: call_seq lbl_88B8BB70, lbl_88041E7C, lbl_88CD844C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8BB70_88A3CE20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD844C, (ts4_word)(ts4_word)lbl_88041E7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8BB70, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3CE90: addr lbl_88B8BC30, u32@lbl_88B87CB4, u32@0x68 */
void ts4_addr_lbl_88B8BC30_88A3CE90(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8BC30) + 104) = (ts4_word)(*(ts4_word *)lbl_88B87CB4);
    return;
}

/* Swing_DLL.xex 0x88A3CEA8: call_seq lbl_88B8BC30, lbl_88CD844C, lbl_88041E98, lbl_88CD847C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8BC30_88A3CEA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD847C, (ts4_word)(ts4_word)lbl_88041E98, (ts4_word)(ts4_word)lbl_88CD844C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8BC30, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3CF20: call_seq lbl_88B87D50, lbl_88CD844C, lbl_88041EBC, lbl_88CD84AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87D50_88A3CF20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD84AC, (ts4_word)(ts4_word)lbl_88041EBC, (ts4_word)(ts4_word)lbl_88CD844C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87D50, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3CF98: call_seq lbl_88B87DB0, lbl_88CD829C, lbl_88041E68, lbl_88CD84DC, lbl_8805AFD8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87DB0_88A3CF98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD84DC, (ts4_word)(ts4_word)lbl_88041E68, (ts4_word)(ts4_word)lbl_88CD829C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805AFD8, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B87DB0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D010: call_seq lbl_88CD862C, lbl_880467DC, lbl_88CD850C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD862C_88A3D010(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD850C, (ts4_word)(ts4_word)lbl_880467DC, (ts4_word)(ts4_word)lbl_88CD862C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D078: call_seq lbl_88CD811C, lbl_88046AE0, lbl_88CD853C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD811C_88A3D078(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD853C, (ts4_word)(ts4_word)lbl_88046AE0, (ts4_word)(ts4_word)lbl_88CD811C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D0E0: call_seq lbl_88B87E40, lbl_88042358, lbl_88CD856C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87E40_88A3D0E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD856C, (ts4_word)(ts4_word)lbl_88042358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87E40, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D150: call_seq lbl_88B87E70, lbl_88CD829C, lbl_8804234C, lbl_88CD859C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87E70_88A3D150(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD859C, (ts4_word)(ts4_word)lbl_8804234C, (ts4_word)(ts4_word)lbl_88CD829C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87E70, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D1C8: call_seq lbl_88B87E88, lbl_88046320, lbl_88CD85CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87E88_88A3D1C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD85CC, (ts4_word)(ts4_word)lbl_88046320, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87E88, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D238: addr lbl_88B8BCC0, u32@lbl_88B87EA0, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88B8BCC0_88A3D238(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B87EA0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8BCC0) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8BCC0) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A3D258: call_seq lbl_88B8BCC0, lbl_8803EFE8, lbl_88CD85FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8BCC0_88A3D258(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD85FC, (ts4_word)(ts4_word)lbl_8803EFE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8BCC0, (ts4_word)13, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D2C8: call_seq lbl_88B87EA8, lbl_88CD829C, lbl_8803EF9C, lbl_88CD862C, lbl_8805B054, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87EA8_88A3D2C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD862C, (ts4_word)(ts4_word)lbl_8803EF9C, (ts4_word)(ts4_word)lbl_88CD829C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805B054, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B87EA8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D340: call_seq lbl_88B87F20, lbl_88CD823C, lbl_880423C0, lbl_88CD865C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87F20_88A3D340(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD865C, (ts4_word)(ts4_word)lbl_880423C0, (ts4_word)(ts4_word)lbl_88CD823C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87F20, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D3B8: call_seq lbl_88B87F38, lbl_880462E8, lbl_88CD868C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87F38_88A3D3B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD868C, (ts4_word)(ts4_word)lbl_880462E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87F38, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D428: call_seq lbl_88B87F68, lbl_88CD811C, lbl_8804675C, lbl_88CD86BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87F68_88A3D428(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD86BC, (ts4_word)(ts4_word)lbl_8804675C, (ts4_word)(ts4_word)lbl_88CD811C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87F68, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D4A0: call_seq lbl_88B87F98, lbl_88CD883C, lbl_8803F9D4, lbl_88CD86EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87F98_88A3D4A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD86EC, (ts4_word)(ts4_word)lbl_8803F9D4, (ts4_word)(ts4_word)lbl_88CD883C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87F98, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D518: call_seq lbl_88CD811C, lbl_88046AB4, lbl_88CD871C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD811C_88A3D518(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD871C, (ts4_word)(ts4_word)lbl_88046AB4, (ts4_word)(ts4_word)lbl_88CD811C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D580: call_seq lbl_88B87FC8, lbl_88CD853C, lbl_880466D4, lbl_88CD874C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B87FC8_88A3D580(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD874C, (ts4_word)(ts4_word)lbl_880466D4, (ts4_word)(ts4_word)lbl_88CD853C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B87FC8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D5F8: call_seq lbl_88B88010, lbl_88CD853C, lbl_88046A18, lbl_88CD877C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88010_88A3D5F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD877C, (ts4_word)(ts4_word)lbl_88046A18, (ts4_word)(ts4_word)lbl_88CD853C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88010, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D670: call_seq lbl_88B880B8, lbl_880423A4, lbl_88CD87AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B880B8_88A3D670(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD87AC, (ts4_word)(ts4_word)lbl_880423A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B880B8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D6E0: call_seq lbl_88B88100, lbl_88CD829C, lbl_88042390, lbl_88CD87DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88100_88A3D6E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD87DC, (ts4_word)(ts4_word)lbl_88042390, (ts4_word)(ts4_word)lbl_88CD829C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88100, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D758: call_seq lbl_88CD82CC, lbl_88043ED0, lbl_88CD880C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD82CC_88A3D758(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD880C, (ts4_word)(ts4_word)lbl_88043ED0, (ts4_word)(ts4_word)lbl_88CD82CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D7C0: call_seq lbl_88CD811C, lbl_8804696C, lbl_88CD883C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD811C_88A3D7C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD883C, (ts4_word)(ts4_word)lbl_8804696C, (ts4_word)(ts4_word)lbl_88CD811C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D828: call_seq lbl_88B88160, lbl_88CD73FC, lbl_8803F00C, lbl_88CD886C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88160_88A3D828(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD886C, (ts4_word)(ts4_word)lbl_8803F00C, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88160, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D8A0: call_seq lbl_88B881F0, lbl_88CD862C, lbl_88046574, lbl_88CD889C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B881F0_88A3D8A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD889C, (ts4_word)(ts4_word)lbl_88046574, (ts4_word)(ts4_word)lbl_88CD862C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B881F0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D918: call_seq lbl_88B88208, lbl_88CD877C, lbl_88046518, lbl_88CD88CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88208_88A3D918(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD88CC, (ts4_word)(ts4_word)lbl_88046518, (ts4_word)(ts4_word)lbl_88CD877C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88208, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3D990: call_seq lbl_88B88238, lbl_88CD811C, lbl_880400BC, lbl_88CD88FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88238_88A3D990(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD88FC, (ts4_word)(ts4_word)lbl_880400BC, (ts4_word)(ts4_word)lbl_88CD811C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88238, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3DA08: call_seq lbl_88B88280, lbl_88CD82CC, lbl_88042380, lbl_88CD892C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88280_88A3DA08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD892C, (ts4_word)(ts4_word)lbl_88042380, (ts4_word)(ts4_word)lbl_88CD82CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88280, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3DA80: call_seq lbl_88B882C8, lbl_88CD823C, lbl_880423D4, lbl_88CD895C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B882C8_88A3DA80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD895C, (ts4_word)(ts4_word)lbl_880423D4, (ts4_word)(ts4_word)lbl_88CD823C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B882C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3DAF8: call_seq lbl_88B882E0, lbl_88CD829C, lbl_88046498, lbl_88CD898C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B882E0_88A3DAF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD898C, (ts4_word)(ts4_word)lbl_88046498, (ts4_word)(ts4_word)lbl_88CD829C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B882E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3DB70: addr lbl_88B8BDF8, u32@lbl_88B88310, u32@0x8 */
void ts4_addr_lbl_88B8BDF8_88A3DB70(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8BDF8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B88310);
    return;
}

/* Swing_DLL.xex 0x88A3DB88: call_seq lbl_88B8BDF8, lbl_8804215C, lbl_88CD89BC, lbl_8805B178, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8BDF8_88A3DB88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)(ts4_word)lbl_8804215C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805B178, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B8BDF8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3DBF8: call_seq lbl_88B88318, lbl_88CD89BC, lbl_88041B0C, lbl_88CD89EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88318_88A3DBF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD89EC, (ts4_word)(ts4_word)lbl_88041B0C, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88318, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3DC70: call_seq lbl_88B88348, lbl_88041AFC, lbl_88CD8A1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88348_88A3DC70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8A1C, (ts4_word)(ts4_word)lbl_88041AFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88348, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3DCE0: call_seq lbl_88CD89BC, lbl_88046098, lbl_88CD8A4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD89BC_88A3DCE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8A4C, (ts4_word)(ts4_word)lbl_88046098, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3DD48: call_seq lbl_88B88360, lbl_88CD89BC, lbl_88045C08, lbl_88CD8A7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88360_88A3DD48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8A7C, (ts4_word)(ts4_word)lbl_88045C08, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88360, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3DDC0: call_seq lbl_88B88378, lbl_88CD89BC, lbl_88045D4C, lbl_88CD8AAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88378_88A3DDC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8AAC, (ts4_word)(ts4_word)lbl_88045D4C, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88378, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3DE38: call_seq lbl_88B883A8, lbl_88CD89BC, lbl_88045D00, lbl_88CD8ADC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B883A8_88A3DE38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8ADC, (ts4_word)(ts4_word)lbl_88045D00, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B883A8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3DEB0: call_seq lbl_88B883D8, lbl_88CD89BC, lbl_88045D94, lbl_88CD8B0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B883D8_88A3DEB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8B0C, (ts4_word)(ts4_word)lbl_88045D94, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B883D8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3DF28: call_seq lbl_88B88408, lbl_88CD89BC, lbl_88045E48, lbl_88CD8B3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88408_88A3DF28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8B3C, (ts4_word)(ts4_word)lbl_88045E48, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88408, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3DFA0: call_seq lbl_88B88420, lbl_88CD89BC, lbl_88045FF4, lbl_88CD8B6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88420_88A3DFA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8B6C, (ts4_word)(ts4_word)lbl_88045FF4, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88420, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E018: call_seq lbl_88B88438, lbl_88CD89BC, lbl_88045F18, lbl_88CD8B9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88438_88A3E018(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8B9C, (ts4_word)(ts4_word)lbl_88045F18, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88438, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E090: call_seq lbl_88B88480, lbl_88CD89BC, lbl_88045F84, lbl_88CD8BCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88480_88A3E090(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8BCC, (ts4_word)(ts4_word)lbl_88045F84, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88480, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E108: call_seq lbl_88B884C8, lbl_88CD89BC, lbl_880461A4, lbl_88CD8BFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B884C8_88A3E108(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8BFC, (ts4_word)(ts4_word)lbl_880461A4, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B884C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E180: call_seq lbl_88B884E0, lbl_88CD89BC, lbl_88046178, lbl_88CD8C2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B884E0_88A3E180(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8C2C, (ts4_word)(ts4_word)lbl_88046178, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B884E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E1F8: call_seq lbl_8805B1A0, lbl_88B88510, lbl_88CD89BC, lbl_88046108, lbl_88CD8C5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805B1A0_88A3E1F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8C5C, (ts4_word)(ts4_word)lbl_88046108, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88510, (ts4_word)5, (ts4_word)(ts4_word)lbl_8805B1A0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E270: call_seq lbl_8805B1B8, lbl_88B88588, lbl_88CD89BC, lbl_88045BCC, lbl_88CD8C8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805B1B8_88A3E270(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8C8C, (ts4_word)(ts4_word)lbl_88045BCC, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88588, (ts4_word)6, (ts4_word)(ts4_word)lbl_8805B1B8, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E2E8: addr lbl_88B8BE10, u32@lbl_88B88618, u32@0x50 */
void ts4_addr_lbl_88B8BE10_88A3E2E8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8BE10) + 80) = (ts4_word)(*(ts4_word *)lbl_88B88618);
    return;
}
