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

extern char ts4_addr_lbl_8803A308_88AFF500[];
extern char lbl_8803EC6C[];
extern char lbl_8803ED40[];
extern char lbl_8803ED58[];
extern char lbl_8803ED7C[];
extern char lbl_8803EE48[];
extern char lbl_8803EF04[];
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
extern char lbl_8803F9D4[];
extern char lbl_8803F9E8[];
extern char lbl_8803FA04[];
extern char lbl_8803FA18[];
extern char lbl_8803FBE0[];
extern char lbl_8803FBF4[];
extern char lbl_8803FC80[];
extern char lbl_8803FCA0[];
extern char lbl_88040040[];
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
extern char lbl_88046C78[];
extern char lbl_88046C94[];
extern char lbl_88047050[];
extern char lbl_8804705C[];
extern char lbl_88047070[];
extern char lbl_8804707C[];
extern char lbl_8804C390[];
extern char lbl_8804C3A0[];
extern char lbl_8804C3B0[];
extern char lbl_8804C3C4[];
extern char lbl_8804C3DC[];
extern char lbl_8804C3F8[];
extern char lbl_8804C410[];
extern char lbl_8804C428[];
extern char lbl_8804C9C8[];
extern char lbl_8804CC64[];
extern char lbl_8804CCB8[];
extern char lbl_8804CCE8[];
extern char lbl_8804CD24[];
extern char lbl_8804CDEC[];
extern char lbl_8804CE28[];
extern char lbl_8804CE5C[];
extern char lbl_8804CEB8[];
extern char lbl_8804CECC[];
extern char lbl_8804D090[];
extern char lbl_8804D0E8[];
extern char lbl_8804D808[];
extern char lbl_88B42AE0[];
extern char lbl_88B42B10[];
extern char lbl_88B42C30[];
extern char lbl_88B42CC0[];
extern char lbl_88B42D80[];
extern char lbl_88B42E58[];
extern char lbl_88B42F18[];
extern char lbl_88B42FC0[];
extern char lbl_88B430C8[];
extern char lbl_88B43128[];
extern char lbl_88B43218[];
extern char lbl_88B432F0[];
extern char lbl_88B43320[];
extern char lbl_88B43338[];
extern char lbl_88B43380[];
extern char lbl_88B433E0[];
extern char lbl_88B43428[];
extern char lbl_88B43488[];
extern char lbl_88B434B8[];
extern char lbl_88B434D0[];
extern char lbl_88B434E8[];
extern char lbl_88B43548[];
extern char lbl_88B43560[];
extern char lbl_88B43590[];
extern char lbl_88B435A8[];
extern char lbl_88B435D8[];
extern char lbl_88B435F0[];
extern char lbl_88B43608[];
extern char lbl_88B43620[];
extern char lbl_88B43668[];
extern char lbl_88B43698[];
extern char lbl_88B436C8[];
extern char lbl_88B43710[];
extern char lbl_88B43788[];
extern char lbl_88B43800[];
extern char lbl_88B43830[];
extern char lbl_88B43848[];
extern char lbl_88B43860[];
extern char lbl_88B43868[];
extern char lbl_88B438C8[];
extern char lbl_88B438E0[];
extern char lbl_88B43910[];
extern char lbl_88B43944[];
extern char lbl_88B43974[];
extern char lbl_88B43978[];
extern char lbl_88B439C0[];
extern char lbl_88B43A68[];
extern char lbl_88B43AB0[];
extern char lbl_88B43B10[];
extern char lbl_88B43BA0[];
extern char lbl_88B43BB8[];
extern char lbl_88B43BE8[];
extern char lbl_88B43C30[];
extern char lbl_88B43C78[];
extern char lbl_88B43CC0[];
extern char lbl_88B43CD8[];
extern char lbl_88B43D08[];
extern char lbl_88B43DF8[];
extern char lbl_88B43E40[];
extern char lbl_88B43EE8[];
extern char lbl_88B43F00[];
extern char lbl_88B43F60[];
extern char lbl_88B43F78[];
extern char lbl_88B43FA8[];
extern char lbl_88B43FC0[];
extern char lbl_88B43FD8[];
extern char lbl_88B44024[];
extern char lbl_88B4403C[];
extern char lbl_88B44040[];
extern char lbl_88B440A0[];
extern char lbl_88B440D0[];
extern char lbl_88B44118[];
extern char lbl_88B44148[];
extern char lbl_88B44178[];
extern char lbl_88B441D8[];
extern char lbl_88B44220[];
extern char lbl_88B44298[];
extern char lbl_88B44310[];
extern char lbl_88B44318[];
extern char lbl_88B44360[];
extern char lbl_88B443C0[];
extern char lbl_88B44408[];
extern char lbl_88B44450[];
extern char lbl_88B444F8[];
extern char lbl_88B44540[];
extern char lbl_88B44570[];
extern char lbl_88B44600[];
extern char lbl_88B44690[];
extern char lbl_88B44738[];
extern char lbl_88B44750[];
extern char lbl_88B447C8[];
extern char lbl_88B44810[];
extern char lbl_88B44888[];
extern char lbl_88B448E8[];
extern char lbl_88B44948[];
extern char lbl_88B44AE0[];
extern char lbl_88B44B10[];
extern char lbl_88B44BBC[];
extern char lbl_88B44BD4[];
extern char lbl_88B44BEC[];
extern char lbl_88B44C20[];
extern char lbl_88B44CC8[];
extern char lbl_88B44CF8[];
extern char lbl_88B44D10[];
extern char lbl_88B44D40[];
extern char lbl_88B44D58[];
extern char lbl_88B44D70[];
extern char lbl_88B44E00[];
extern char lbl_88B44E04[];
extern char lbl_88B44E08[];
extern char lbl_88B44E10[];
extern char lbl_88B44E88[];
extern char lbl_88B44EA0[];
extern char lbl_88B44EB8[];
extern char lbl_88B44ED0[];
extern char lbl_88B44F18[];
extern char lbl_88B44F30[];
extern char lbl_88B44F60[];
extern char lbl_88B44FD8[];
extern char lbl_88B45020[];
extern char lbl_88B45068[];
extern char lbl_88B45140[];
extern char lbl_88B45188[];
extern char lbl_88B451E8[];
extern char lbl_88B45248[];
extern char lbl_88B452A8[];
extern char lbl_88B45368[];
extern char lbl_88B45500[];
extern char lbl_88B45518[];
extern char lbl_88B45530[];
extern char lbl_88B45560[];
extern char lbl_88B45590[];
extern char lbl_88B455A8[];
extern char lbl_88B45638[];
extern char lbl_88B45668[];
extern char lbl_88B45680[];
extern char lbl_88B45698[];
extern char lbl_88B456C8[];
extern char lbl_88B456E0[];
extern char lbl_88B457B8[];
extern char lbl_88B45968[];
extern char lbl_88B45B00[];
extern char lbl_88B45D70[];
extern char lbl_88B45DE8[];
extern char lbl_88B45E30[];
extern char lbl_88B45E60[];
extern char lbl_88B45EC0[];
extern char lbl_88B45F20[];
extern char lbl_88B46010[];
extern char lbl_88B46058[];
extern char lbl_88B460A0[];
extern char lbl_88B460B8[];
extern char lbl_88B46100[];
extern char lbl_88B46118[];
extern char lbl_88B461C0[];
extern char lbl_88B461F0[];
extern char lbl_88B46238[];
extern char lbl_88B46280[];
extern char lbl_88B462C8[];
extern char lbl_88B462E0[];
extern char lbl_88B462F8[];
extern char lbl_88B464F0[];
extern char lbl_88B46628[];
extern char lbl_88B46670[];
extern char lbl_88B46730[];
extern char lbl_88B46790[];
extern char lbl_88B469E8[];
extern char lbl_88B46A60[];
extern char lbl_88B46A64[];
extern char lbl_88B46A94[];
extern char lbl_88B46AC8[];
extern char lbl_88B46B28[];
extern char lbl_88B4B2E8[];
extern char lbl_88CB04A4[];
extern char lbl_88CB08C4[];
extern char lbl_88CB08F4[];
extern char lbl_88CB0924[];
extern char lbl_88CB0954[];
extern char lbl_88CB0984[];
extern char lbl_88CB09B4[];
extern char lbl_88CB09E4[];
extern char lbl_88CB0A14[];
extern char lbl_88CB0A44[];
extern char lbl_88CB0A74[];
extern char lbl_88CB0AA4[];
extern char lbl_88CB0AD4[];
extern char lbl_88CB0B04[];
extern char lbl_88CB0B34[];
extern char lbl_88CB0B64[];
extern char lbl_88CB0B94[];
extern char lbl_88CB0BC4[];
extern char lbl_88CB0BF4[];
extern char lbl_88CB0C24[];
extern char lbl_88CB0C54[];
extern char lbl_88CB0C84[];
extern char lbl_88CB0CB4[];
extern char lbl_88CB0CE4[];
extern char lbl_88CB0D14[];
extern char lbl_88CB0D44[];
extern char lbl_88CB0D74[];
extern char lbl_88CB0DA4[];
extern char lbl_88CB0DD4[];
extern char lbl_88CB0E04[];
extern char lbl_88CB0E34[];
extern char lbl_88CB0E64[];
extern char lbl_88CB0E94[];
extern char lbl_88CB0EC4[];
extern char lbl_88CB0EF4[];
extern char lbl_88CB0F24[];
extern char lbl_88CB0F54[];
extern char lbl_88CB0F84[];
extern char lbl_88CB0FB4[];
extern char lbl_88CB0FE4[];
extern char lbl_88CB1014[];
extern char lbl_88CB1044[];
extern char lbl_88CB1074[];
extern char lbl_88CB10A4[];
extern char lbl_88CB10D4[];
extern char lbl_88CB1104[];
extern char lbl_88CB1134[];
extern char lbl_88CB1164[];
extern char lbl_88CB1194[];
extern char lbl_88CB11C4[];
extern char lbl_88CB11F4[];
extern char lbl_88CB1224[];
extern char lbl_88CB1254[];
extern char lbl_88CB1284[];
extern char lbl_88CB12B4[];
extern char lbl_88CB12E4[];
extern char lbl_88CB1314[];
extern char lbl_88CB1344[];
extern char lbl_88CB1374[];
extern char lbl_88CB13A4[];
extern char lbl_88CB13D4[];
extern char lbl_88CB1404[];
extern char lbl_88CB1434[];
extern char lbl_88CB1464[];
extern char lbl_88CB1494[];
extern char lbl_88CB14C4[];
extern char lbl_88CB14F4[];
extern char lbl_88CB1524[];
extern char lbl_88CB1554[];
extern char lbl_88CB1584[];
extern char lbl_88CB15B4[];
extern char lbl_88CB15E4[];
extern char lbl_88CB1614[];
extern char lbl_88CB1644[];
extern char lbl_88CB1674[];
extern char lbl_88CB16A4[];
extern char lbl_88CB16D4[];
extern char lbl_88CB1704[];
extern char lbl_88CB1734[];
extern char lbl_88CB1764[];
extern char lbl_88CB1794[];
extern char lbl_88CB17C4[];
extern char lbl_88CB17F4[];
extern char lbl_88CB1824[];
extern char lbl_88CB1854[];
extern char lbl_88CB1884[];
extern char lbl_88CB18B4[];
extern char lbl_88CB18E4[];
extern char lbl_88CB1914[];
extern char lbl_88CB1944[];
extern char lbl_88CB1974[];
extern char lbl_88CB19A4[];
extern char lbl_88CB19D4[];
extern char lbl_88CB1A04[];
extern char lbl_88CB1A34[];
extern char lbl_88CB1A64[];
extern char lbl_88CB1A94[];
extern char lbl_88CB1AC4[];
extern char lbl_88CB1AF4[];
extern char lbl_88CB1B24[];
extern char lbl_88CB1B54[];
extern char lbl_88CB1B84[];
extern char lbl_88CB1BB4[];
extern char lbl_88CB1BE4[];
extern char lbl_88CB1C14[];
extern char lbl_88CB1C44[];
extern char lbl_88CB1C74[];
extern char lbl_88CB1CA4[];
extern char lbl_88CB1CD4[];
extern char lbl_88CB1D04[];
extern char lbl_88CB1D34[];
extern char lbl_88CB1D64[];
extern char lbl_88CB1D94[];
extern char lbl_88CB1DC4[];
extern char lbl_88CB1DF4[];
extern char lbl_88CB1E24[];
extern char lbl_88CB1E54[];
extern char lbl_88CB1E84[];
extern char lbl_88CB1EB4[];
extern char lbl_88CB1EE4[];
extern char lbl_88CB1F14[];
extern char lbl_88CB1F44[];
extern char lbl_88CB1F74[];
extern char lbl_88CB1FA4[];
extern char lbl_88CB1FD4[];
extern char lbl_88CB2004[];
extern char lbl_88CB2034[];
extern char lbl_88CB2064[];
extern char lbl_88CB2094[];
extern char lbl_88CB20F4[];
extern char lbl_88CB2124[];
extern char lbl_88CB2154[];
extern char lbl_88CB2184[];
extern char lbl_88CB21B4[];
extern char lbl_88CB21E4[];
extern char lbl_88CB2214[];
extern char lbl_88CB2244[];
extern char lbl_88CB2274[];
extern char lbl_88CB22A4[];
extern char lbl_88CB22D4[];
extern char lbl_88CB2304[];
extern char lbl_88CB2334[];
extern char lbl_88CB2364[];
extern char lbl_88CB2394[];
extern char lbl_88CB23C4[];
extern char lbl_88CB23F4[];
extern char lbl_88CB2424[];
extern char lbl_88CB2454[];
extern char lbl_88CB2484[];
extern char lbl_88CB24B4[];
extern char lbl_88CB24E4[];
extern char lbl_88CB2514[];
extern char lbl_88CB2544[];
extern char lbl_88CB2574[];
extern char lbl_88CB25A4[];
extern char lbl_88CB25D4[];
extern char lbl_88CB2604[];
extern char lbl_88CB2634[];
extern char lbl_88CB2664[];
extern char lbl_88CB2694[];
extern char lbl_88CB26C4[];
extern char lbl_88CB26F4[];
extern char lbl_88CB2724[];
extern char lbl_88CB2754[];
extern char lbl_88CB2784[];
extern char lbl_88CB27B4[];
extern char lbl_88CB27E4[];
extern char lbl_88CB2814[];
extern char lbl_88CB2844[];
extern char lbl_88CB2874[];
extern char lbl_88CB28A4[];
extern char lbl_88CB28D4[];
extern char lbl_88CB2904[];
extern char lbl_88CB2934[];
extern char lbl_88CB2964[];
extern char lbl_88CB2994[];
extern char lbl_88CB29C4[];
extern char lbl_88CB29F4[];
extern char lbl_88CB2A24[];
extern char lbl_88CB2A54[];
extern char lbl_88CB2A84[];
extern char lbl_88CB2AB4[];
extern char lbl_88CB2AE4[];
extern char lbl_88CB2B14[];
extern char lbl_88CB2B44[];
extern char lbl_88CB2B74[];
extern char lbl_88CB2BA4[];
extern char lbl_88CB2BD4[];
extern char lbl_88CB2C04[];
extern char lbl_88CB2C1C[];
extern char lbl_88CB2C4C[];
extern char lbl_88CB2C7C[];
extern char lbl_88CB2CAC[];
extern char lbl_88CB2CDC[];
extern char lbl_88CB2D0C[];
extern char lbl_88CB303C[];
ts4_word fn_8841F080();
ts4_word ts4_set_u32_offc_884CE988();
ts4_word fn_88563470();

/* Swing_DLL.xex 0x889DCB68: call_seq lbl_88B42AE0, lbl_8804C390, lbl_88CB08C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42AE0_889DCB68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB08C4, (ts4_word)(ts4_word)lbl_8804C390, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42AE0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DCBD8: call_seq lbl_88B42B10, lbl_8804C3A0, lbl_88CB08F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42B10_889DCBD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB08F4, (ts4_word)(ts4_word)lbl_8804C3A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42B10, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DCC48: call_seq lbl_88B42C30, lbl_8804C3B0, lbl_88CB0924, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42C30_889DCC48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0924, (ts4_word)(ts4_word)lbl_8804C3B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42C30, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DCCB8: call_seq lbl_88B42CC0, lbl_8804C3C4, lbl_88CB0954, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42CC0_889DCCB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0954, (ts4_word)(ts4_word)lbl_8804C3C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42CC0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DCD28: call_seq lbl_88B42D80, lbl_8804C3DC, lbl_88CB0984, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42D80_889DCD28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0984, (ts4_word)(ts4_word)lbl_8804C3DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42D80, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DCD98: call_seq lbl_88B42E58, lbl_8804C3F8, lbl_88CB09B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42E58_889DCD98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB09B4, (ts4_word)(ts4_word)lbl_8804C3F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42E58, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DCE08: call_seq lbl_88B42F18, lbl_8804C410, lbl_88CB09E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42F18_889DCE08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB09E4, (ts4_word)(ts4_word)lbl_8804C410, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42F18, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DCE78: call_seq lbl_88B42FC0, lbl_8803F5BC, lbl_88CB0A14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B42FC0_889DCE78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0A14, (ts4_word)(ts4_word)lbl_8803F5BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B42FC0, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DCEE8: call_seq lbl_88B430C8, lbl_8804C428, lbl_88CB0A44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B430C8_889DCEE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0A44, (ts4_word)(ts4_word)lbl_8804C428, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B430C8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DCF58: call_seq lbl_88B43128, lbl_8803F5E0, lbl_88CB0A74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43128_889DCF58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0A74, (ts4_word)(ts4_word)lbl_8803F5E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43128, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DCFC8: call_seq lbl_88B43218, lbl_88040278, lbl_88CB0AA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43218_889DCFC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0AA4, (ts4_word)(ts4_word)lbl_88040278, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43218, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD038: call_seq lbl_88B432F0, lbl_8803ED58, lbl_88CB0AD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B432F0_889DD038(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0AD4, (ts4_word)(ts4_word)lbl_8803ED58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B432F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD0A8: call_seq lbl_88B43320, lbl_8803ED40, lbl_88CB0B04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43320_889DD0A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0B04, (ts4_word)(ts4_word)lbl_8803ED40, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43320, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD118: call_seq lbl_88B43338, lbl_88CB04A4, lbl_8803ED7C, lbl_88CB0B34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43338_889DD118(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0B34, (ts4_word)(ts4_word)lbl_8803ED7C, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43338, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD190: call_seq lbl_88B43380, lbl_88046454, lbl_88CB0B64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43380_889DD190(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0B64, (ts4_word)(ts4_word)lbl_88046454, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43380, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD200: call_seq lbl_88B433E0, lbl_88CB0B64, lbl_8804233C, lbl_88CB0B94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B433E0_889DD200(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0B94, (ts4_word)(ts4_word)lbl_8804233C, (ts4_word)(ts4_word)lbl_88CB0B64, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B433E0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD278: call_seq lbl_880469C4, lbl_88CB0BC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880469C4_889DD278(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0BC4, (ts4_word)(ts4_word)lbl_880469C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD2D8: call_seq lbl_88B43428, lbl_88CB2184, lbl_88042E48, lbl_88CB0BF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43428_889DD2D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0BF4, (ts4_word)(ts4_word)lbl_88042E48, (ts4_word)(ts4_word)lbl_88CB2184, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43428, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD350: call_seq lbl_88046B60, lbl_88CB0C24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046B60_889DD350(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0C24, (ts4_word)(ts4_word)lbl_88046B60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD3B0: call_seq lbl_88CB04A4, lbl_88042318, lbl_88CB0C54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB04A4_889DD3B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0C54, (ts4_word)(ts4_word)lbl_88042318, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD418: call_seq lbl_88046A84, lbl_88CB0C84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A84_889DD418(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0C84, (ts4_word)(ts4_word)lbl_88046A84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD478: call_seq lbl_88B43488, lbl_88CB0C54, lbl_8804232C, lbl_88CB0CB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43488_889DD478(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0CB4, (ts4_word)(ts4_word)lbl_8804232C, (ts4_word)(ts4_word)lbl_88CB0C54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43488, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD4F0: call_seq lbl_88B434B8, lbl_88CB0C54, lbl_8804690C, lbl_88CB0CE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B434B8_889DD4F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0CE4, (ts4_word)(ts4_word)lbl_8804690C, (ts4_word)(ts4_word)lbl_88CB0C54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B434B8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD568: call_seq lbl_88CB0C54, lbl_8804671C, lbl_88CB0D14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB0C54_889DD568(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0D14, (ts4_word)(ts4_word)lbl_8804671C, (ts4_word)(ts4_word)lbl_88CB0C54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD5D0: call_seq lbl_88046A50, lbl_88CB0D44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A50_889DD5D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0D44, (ts4_word)(ts4_word)lbl_88046A50, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD630: call_seq lbl_88B434D0, lbl_88CB04A4, lbl_88041284, lbl_88CB0D74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B434D0_889DD630(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0D74, (ts4_word)(ts4_word)lbl_88041284, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B434D0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD6A8: call_seq lbl_88B434E8, lbl_88046220, lbl_88CB0DA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B434E8_889DD6A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0DA4, (ts4_word)(ts4_word)lbl_88046220, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B434E8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD718: call_seq lbl_88B43548, lbl_88CB0EC4, lbl_8804694C, lbl_88CB0DD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43548_889DD718(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0DD4, (ts4_word)(ts4_word)lbl_8804694C, (ts4_word)(ts4_word)lbl_88CB0EC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43548, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD790: call_seq lbl_88B43560, lbl_88CB0D74, lbl_88040110, lbl_88CB0E04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43560_889DD790(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0E04, (ts4_word)(ts4_word)lbl_88040110, (ts4_word)(ts4_word)lbl_88CB0D74, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43560, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD808: call_seq lbl_88B43590, lbl_88CB0D74, lbl_88040100, lbl_88CB0E34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43590_889DD808(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0E34, (ts4_word)(ts4_word)lbl_88040100, (ts4_word)(ts4_word)lbl_88CB0D74, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43590, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD880: call_seq lbl_88B435A8, lbl_88CB0EC4, lbl_8804011C, lbl_88CB0E64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B435A8_889DD880(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0E64, (ts4_word)(ts4_word)lbl_8804011C, (ts4_word)(ts4_word)lbl_88CB0EC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B435A8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD8F8: call_seq lbl_88B435D8, lbl_88CB0D74, lbl_880400A8, lbl_88CB0E94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B435D8_889DD8F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0E94, (ts4_word)(ts4_word)lbl_880400A8, (ts4_word)(ts4_word)lbl_88CB0D74, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B435D8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD970: call_seq lbl_88B435F0, lbl_88CB1374, lbl_88042370, lbl_88CB0EC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B435F0_889DD970(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0EC4, (ts4_word)(ts4_word)lbl_88042370, (ts4_word)(ts4_word)lbl_88CB1374, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B435F0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DD9E8: call_seq lbl_88B43608, lbl_88CB10D4, lbl_88041B24, lbl_88CB0EF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43608_889DD9E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0EF4, (ts4_word)(ts4_word)lbl_88041B24, (ts4_word)(ts4_word)lbl_88CB10D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43608, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DDA60: call_seq lbl_88B43620, lbl_88CB0E94, lbl_880468C8, lbl_88CB0F24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43620_889DDA60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0F24, (ts4_word)(ts4_word)lbl_880468C8, (ts4_word)(ts4_word)lbl_88CB0E94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43620, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DDAD8: call_seq lbl_88B43668, lbl_88CB0EC4, lbl_880400E8, lbl_88CB0F54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43668_889DDAD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0F54, (ts4_word)(ts4_word)lbl_880400E8, (ts4_word)(ts4_word)lbl_88CB0EC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43668, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DDB50: call_seq lbl_88B43698, lbl_88CB0EC4, lbl_880400D0, lbl_88CB0F84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43698_889DDB50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0F84, (ts4_word)(ts4_word)lbl_880400D0, (ts4_word)(ts4_word)lbl_88CB0EC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43698, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DDBC8: call_seq lbl_88B436C8, lbl_880463D4, lbl_88CB0FB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B436C8_889DDBC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0FB4, (ts4_word)(ts4_word)lbl_880463D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B436C8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DDC38: call_seq lbl_88B43710, lbl_88CB0EC4, lbl_88046868, lbl_88CB0FE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43710_889DDC38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB0FE4, (ts4_word)(ts4_word)lbl_88046868, (ts4_word)(ts4_word)lbl_88CB0EC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43710, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DDCB0: call_seq lbl_88B43788, lbl_88CB0EC4, lbl_8803EFC0, lbl_88CB1014, lbl_8804CC64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43788_889DDCB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1014, (ts4_word)(ts4_word)lbl_8803EFC0, (ts4_word)(ts4_word)lbl_88CB0EC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804CC64, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B43788, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DDD28: call_seq lbl_88CB1164, lbl_880467DC, lbl_88CB1044, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB1164_889DDD28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1044, (ts4_word)(ts4_word)lbl_880467DC, (ts4_word)(ts4_word)lbl_88CB1164, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DDD90: call_seq lbl_88CB0D74, lbl_88046AE0, lbl_88CB1074, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB0D74_889DDD90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1074, (ts4_word)(ts4_word)lbl_88046AE0, (ts4_word)(ts4_word)lbl_88CB0D74, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DDDF8: call_seq lbl_88B43800, lbl_88042358, lbl_88CB10A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43800_889DDDF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB10A4, (ts4_word)(ts4_word)lbl_88042358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43800, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DDE68: call_seq lbl_88B43830, lbl_88CB0E94, lbl_8804234C, lbl_88CB10D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43830_889DDE68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB10D4, (ts4_word)(ts4_word)lbl_8804234C, (ts4_word)(ts4_word)lbl_88CB0E94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43830, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DDEE0: call_seq lbl_88B43848, lbl_88046320, lbl_88CB1104, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43848_889DDEE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1104, (ts4_word)(ts4_word)lbl_88046320, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43848, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DDF50: addr lbl_88B464F0, u32@lbl_88B43860, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88B464F0_889DDF50(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B43860;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B464F0) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B464F0) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x889DDF70: call_seq lbl_88B464F0, lbl_8803EFE8, lbl_88CB1134, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B464F0_889DDF70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1134, (ts4_word)(ts4_word)lbl_8803EFE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B464F0, (ts4_word)13, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DDFE0: call_seq lbl_88B43868, lbl_88CB0E94, lbl_8803EF9C, lbl_88CB1164, lbl_8804CCB8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43868_889DDFE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1164, (ts4_word)(ts4_word)lbl_8803EF9C, (ts4_word)(ts4_word)lbl_88CB0E94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804CCB8, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B43868, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE058: call_seq lbl_88B438C8, lbl_88CB0E34, lbl_880423C0, lbl_88CB1194, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B438C8_889DE058(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1194, (ts4_word)(ts4_word)lbl_880423C0, (ts4_word)(ts4_word)lbl_88CB0E34, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B438C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE0D0: call_seq lbl_88B438E0, lbl_880462E8, lbl_88CB11C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B438E0_889DE0D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB11C4, (ts4_word)(ts4_word)lbl_880462E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B438E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE140: call_seq lbl_88B43910, lbl_88CB0D74, lbl_8804675C, lbl_88CB11F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43910_889DE140(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB11F4, (ts4_word)(ts4_word)lbl_8804675C, (ts4_word)(ts4_word)lbl_88CB0D74, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43910, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE1B8: call_seq lbl_88B43944, lbl_88CB1374, lbl_8803F9D4, lbl_88CB1224, lbl_8804CCE8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43944_889DE1B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1224, (ts4_word)(ts4_word)lbl_8803F9D4, (ts4_word)(ts4_word)lbl_88CB1374, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804CCE8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B43944, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE230: call_seq lbl_88CB0D74, lbl_88046AB4, lbl_88CB1254, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB0D74_889DE230(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1254, (ts4_word)(ts4_word)lbl_88046AB4, (ts4_word)(ts4_word)lbl_88CB0D74, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE298: call_seq lbl_88B43978, lbl_88CB1074, lbl_880466D4, lbl_88CB1284, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43978_889DE298(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1284, (ts4_word)(ts4_word)lbl_880466D4, (ts4_word)(ts4_word)lbl_88CB1074, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43978, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE310: call_seq lbl_88B439C0, lbl_88CB1074, lbl_88046A18, lbl_88CB12B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B439C0_889DE310(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB12B4, (ts4_word)(ts4_word)lbl_88046A18, (ts4_word)(ts4_word)lbl_88CB1074, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B439C0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE388: call_seq lbl_88B43A68, lbl_880423A4, lbl_88CB12E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43A68_889DE388(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB12E4, (ts4_word)(ts4_word)lbl_880423A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43A68, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE3F8: call_seq lbl_88B43AB0, lbl_88CB0E94, lbl_88042390, lbl_88CB1314, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43AB0_889DE3F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1314, (ts4_word)(ts4_word)lbl_88042390, (ts4_word)(ts4_word)lbl_88CB0E94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43AB0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE470: call_seq lbl_88CB0EC4, lbl_88043ED0, lbl_88CB1344, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB0EC4_889DE470(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1344, (ts4_word)(ts4_word)lbl_88043ED0, (ts4_word)(ts4_word)lbl_88CB0EC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE4D8: call_seq lbl_88CB0D74, lbl_8804696C, lbl_88CB1374, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB0D74_889DE4D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1374, (ts4_word)(ts4_word)lbl_8804696C, (ts4_word)(ts4_word)lbl_88CB0D74, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE540: call_seq lbl_88B43B10, lbl_8803F00C, lbl_88CB13A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43B10_889DE540(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB13A4, (ts4_word)(ts4_word)lbl_8803F00C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43B10, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE5B0: call_seq lbl_88B43BA0, lbl_88CB1164, lbl_88046574, lbl_88CB13D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43BA0_889DE5B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB13D4, (ts4_word)(ts4_word)lbl_88046574, (ts4_word)(ts4_word)lbl_88CB1164, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43BA0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE628: call_seq lbl_88B43BB8, lbl_88CB12B4, lbl_88046518, lbl_88CB1404, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43BB8_889DE628(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1404, (ts4_word)(ts4_word)lbl_88046518, (ts4_word)(ts4_word)lbl_88CB12B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43BB8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE6A0: call_seq lbl_88B43BE8, lbl_88CB0D74, lbl_880400BC, lbl_88CB1434, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43BE8_889DE6A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1434, (ts4_word)(ts4_word)lbl_880400BC, (ts4_word)(ts4_word)lbl_88CB0D74, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43BE8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE718: call_seq lbl_88B43C30, lbl_88CB0EC4, lbl_88042380, lbl_88CB1464, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43C30_889DE718(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1464, (ts4_word)(ts4_word)lbl_88042380, (ts4_word)(ts4_word)lbl_88CB0EC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43C30, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE790: call_seq lbl_88B43C78, lbl_8803FBF4, lbl_88CB1494, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43C78_889DE790(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1494, (ts4_word)(ts4_word)lbl_8803FBF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43C78, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE800: call_seq lbl_88B43CC0, lbl_88CB0E34, lbl_880423D4, lbl_88CB14C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43CC0_889DE800(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB14C4, (ts4_word)(ts4_word)lbl_880423D4, (ts4_word)(ts4_word)lbl_88CB0E34, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43CC0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE878: call_seq lbl_88B43CD8, lbl_88CB0E94, lbl_88046498, lbl_88CB14F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43CD8_889DE878(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB14F4, (ts4_word)(ts4_word)lbl_88046498, (ts4_word)(ts4_word)lbl_88CB0E94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43CD8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE8F0: call_seq lbl_88B43D08, lbl_88044324, lbl_88CB1524, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43D08_889DE8F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1524, (ts4_word)(ts4_word)lbl_88044324, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43D08, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE960: call_seq lbl_88B43DF8, lbl_88044370, lbl_88CB1554, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43DF8_889DE960(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1554, (ts4_word)(ts4_word)lbl_88044370, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43DF8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DE9D0: call_seq lbl_88B43E40, lbl_8803F610, lbl_88CB1584, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43E40_889DE9D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1584, (ts4_word)(ts4_word)lbl_8803F610, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43E40, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DEA40: call_seq lbl_88B43EE8, lbl_8803F634, lbl_88CB15B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43EE8_889DEA40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB15B4, (ts4_word)(ts4_word)lbl_8803F634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43EE8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DEAB0: call_seq lbl_88B43F00, lbl_88CB04A4, lbl_88047050, lbl_88CB15E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43F00_889DEAB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB15E4, (ts4_word)(ts4_word)lbl_88047050, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43F00, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DEB28: call_seq lbl_88B43F60, lbl_88CB15E4, lbl_88045B44, lbl_88CB1614, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43F60_889DEB28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1614, (ts4_word)(ts4_word)lbl_88045B44, (ts4_word)(ts4_word)lbl_88CB15E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43F60, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DEBA0: call_seq lbl_88B43F78, lbl_88CB15E4, lbl_88045B24, lbl_88CB1644, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43F78_889DEBA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1644, (ts4_word)(ts4_word)lbl_88045B24, (ts4_word)(ts4_word)lbl_88CB15E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43F78, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DEC18: call_seq lbl_88B43FA8, lbl_88CB15E4, lbl_880459C0, lbl_88CB1674, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43FA8_889DEC18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1674, (ts4_word)(ts4_word)lbl_880459C0, (ts4_word)(ts4_word)lbl_88CB15E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43FA8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DEC90: addr lbl_88B46628, u32@lbl_88B43974, u32@0x8 */
void ts4_addr_lbl_88B46628_889DEC90(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B46628) + 8) = (ts4_word)(*(ts4_word *)lbl_88B43974);
    return;
}

/* Swing_DLL.xex 0x889DECA8: call_seq lbl_88B46628, lbl_88045224, lbl_88CB16A4, lbl_8804CD24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46628_889DECA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB16A4, (ts4_word)(ts4_word)lbl_88045224, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804CD24, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B46628, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DED18: call_seq lbl_88B43FC0, lbl_88045194, lbl_88CB16D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43FC0_889DED18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB16D4, (ts4_word)(ts4_word)lbl_88045194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43FC0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DED88: call_seq lbl_88B43FD8, lbl_8803EF90, lbl_88CB1704, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B43FD8_889DED88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1704, (ts4_word)(ts4_word)lbl_8803EF90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B43FD8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DEDF8: call_seq lbl_88B44024, lbl_88CB04A4, lbl_8803FA04, lbl_88CB1734, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44024_889DEDF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1734, (ts4_word)(ts4_word)lbl_8803FA04, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44024, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DEE70: call_seq lbl_88B44040, lbl_88042170, lbl_88CB1764, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44040_889DEE70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1764, (ts4_word)(ts4_word)lbl_88042170, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44040, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DEEE0: addr lbl_88B46670, u32@lbl_88B4403C, u32@0x50 */
void ts4_addr_lbl_88B46670_889DEEE0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B46670) + 80) = (ts4_word)(*(ts4_word *)lbl_88B4403C);
    return;
}

/* Swing_DLL.xex 0x889DEEF8: call_seq lbl_88B46670, lbl_88CB04A4, lbl_8803F0C8, lbl_88CB1794, lbl_8804CDEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46670_889DEEF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1794, (ts4_word)(ts4_word)lbl_8803F0C8, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804CDEC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B46670, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DEF70: call_seq lbl_88B440A0, lbl_88CB1734, lbl_880403DC, lbl_88CB17C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B440A0_889DEF70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB17C4, (ts4_word)(ts4_word)lbl_880403DC, (ts4_word)(ts4_word)lbl_88CB1734, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B440A0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DEFE8: call_seq lbl_88B440D0, lbl_88040630, lbl_88CB17F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B440D0_889DEFE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB17F4, (ts4_word)(ts4_word)lbl_88040630, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B440D0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF058: call_seq lbl_88B44118, lbl_88040608, lbl_88CB1824, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44118_889DF058(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1824, (ts4_word)(ts4_word)lbl_88040608, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44118, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF0C8: call_seq lbl_88B44148, lbl_88CB1734, lbl_88040394, lbl_88CB1854, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44148_889DF0C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1854, (ts4_word)(ts4_word)lbl_88040394, (ts4_word)(ts4_word)lbl_88CB1734, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44148, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF140: call_seq lbl_88B44178, lbl_88040590, lbl_88CB1884, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44178_889DF140(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1884, (ts4_word)(ts4_word)lbl_88040590, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44178, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF1B0: call_seq lbl_88B441D8, lbl_88040560, lbl_88CB18B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B441D8_889DF1B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB18B4, (ts4_word)(ts4_word)lbl_88040560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B441D8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF220: call_seq lbl_88B44220, lbl_88CB1734, lbl_8803F690, lbl_88CB18E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44220_889DF220(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB18E4, (ts4_word)(ts4_word)lbl_8803F690, (ts4_word)(ts4_word)lbl_88CB1734, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44220, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF298: call_seq lbl_88B44298, lbl_88CB1944, lbl_88045734, lbl_88CB1914, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44298_889DF298(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1914, (ts4_word)(ts4_word)lbl_88045734, (ts4_word)(ts4_word)lbl_88CB1944, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44298, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF310: call_seq lbl_88CB04A4, lbl_88045A30, lbl_88CB1944, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB04A4_889DF310(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1944, (ts4_word)(ts4_word)lbl_88045A30, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF378: addr lbl_88B46730, u32@lbl_88B44310, u32@0x38 */
void ts4_addr_lbl_88B46730_889DF378(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B46730) + 56) = (ts4_word)(*(ts4_word *)lbl_88B44310);
    return;
}

/* Swing_DLL.xex 0x889DF390: call_seq lbl_88B46730, lbl_88CB1734, lbl_88040364, lbl_88CB1974, lbl_8804CE28, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46730_889DF390(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1974, (ts4_word)(ts4_word)lbl_88040364, (ts4_word)(ts4_word)lbl_88CB1734, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804CE28, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B46730, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF408: call_seq lbl_88B44318, lbl_88CB1734, lbl_88040344, lbl_88CB19A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44318_889DF408(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB19A4, (ts4_word)(ts4_word)lbl_88040344, (ts4_word)(ts4_word)lbl_88CB1734, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44318, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF480: call_seq lbl_88B44360, lbl_88CB18E4, lbl_8803F064, lbl_88CB19D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44360_889DF480(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB19D4, (ts4_word)(ts4_word)lbl_8803F064, (ts4_word)(ts4_word)lbl_88CB18E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44360, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF4F8: call_seq lbl_88B443C0, lbl_88040534, lbl_88CB1A04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B443C0_889DF4F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1A04, (ts4_word)(ts4_word)lbl_88040534, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B443C0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF568: call_seq lbl_88B44408, lbl_88040508, lbl_88CB1A34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44408_889DF568(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1A34, (ts4_word)(ts4_word)lbl_88040508, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44408, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF5D8: call_seq lbl_88B44450, lbl_88CB1734, lbl_8803F048, lbl_88CB1A64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44450_889DF5D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1A64, (ts4_word)(ts4_word)lbl_8803F048, (ts4_word)(ts4_word)lbl_88CB1734, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44450, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF650: call_seq lbl_88B444F8, lbl_88CB1734, lbl_880402E4, lbl_88CB1A94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B444F8_889DF650(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1A94, (ts4_word)(ts4_word)lbl_880402E4, (ts4_word)(ts4_word)lbl_88CB1734, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B444F8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF6C8: call_seq lbl_88B44540, lbl_88040424, lbl_88CB1AC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44540_889DF6C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1AC4, (ts4_word)(ts4_word)lbl_88040424, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44540, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF738: call_seq lbl_88B44570, lbl_880403FC, lbl_88CB1AF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44570_889DF738(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1AF4, (ts4_word)(ts4_word)lbl_880403FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44570, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF7A8: call_seq lbl_88B44600, lbl_88CB1734, lbl_880402CC, lbl_88CB1B24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44600_889DF7A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1B24, (ts4_word)(ts4_word)lbl_880402CC, (ts4_word)(ts4_word)lbl_88CB1734, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44600, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF820: call_seq lbl_88B44690, lbl_88CB1734, lbl_8803F6B0, lbl_88CB1B54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44690_889DF820(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1B54, (ts4_word)(ts4_word)lbl_8803F6B0, (ts4_word)(ts4_word)lbl_88CB1734, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44690, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF898: call_seq lbl_88B44738, lbl_88CB1734, lbl_880403AC, lbl_88CB1B84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44738_889DF898(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1B84, (ts4_word)(ts4_word)lbl_880403AC, (ts4_word)(ts4_word)lbl_88CB1734, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44738, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF910: call_seq lbl_88B44750, lbl_880422F8, lbl_88CB1BB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44750_889DF910(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1BB4, (ts4_word)(ts4_word)lbl_880422F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44750, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF980: call_seq lbl_88B447C8, lbl_88CB1734, lbl_8803FA18, lbl_88CB1BE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B447C8_889DF980(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1BE4, (ts4_word)(ts4_word)lbl_8803FA18, (ts4_word)(ts4_word)lbl_88CB1734, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B447C8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DF9F8: call_seq lbl_88CB04A4, lbl_8803FBE0, lbl_88CB1C14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB04A4_889DF9F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1C14, (ts4_word)(ts4_word)lbl_8803FBE0, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DFA60: call_seq lbl_88B44810, lbl_88CB1C14, lbl_8803FCA0, lbl_88CB1C44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44810_889DFA60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1C44, (ts4_word)(ts4_word)lbl_8803FCA0, (ts4_word)(ts4_word)lbl_88CB1C14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44810, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DFAD8: call_seq lbl_88B44888, lbl_88CB1C14, lbl_8803FC80, lbl_88CB1C74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44888_889DFAD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1C74, (ts4_word)(ts4_word)lbl_8803FC80, (ts4_word)(ts4_word)lbl_88CB1C14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44888, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DFB50: call_seq lbl_88B448E8, lbl_88CB1C14, lbl_8803F9E8, lbl_88CB1CA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B448E8_889DFB50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1CA4, (ts4_word)(ts4_word)lbl_8803F9E8, (ts4_word)(ts4_word)lbl_88CB1C14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B448E8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DFBC8: call_seq lbl_88B44948, lbl_88CB20F4, lbl_8803F6CC, lbl_88CB1CD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44948_889DFBC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1CD4, (ts4_word)(ts4_word)lbl_8803F6CC, (ts4_word)(ts4_word)lbl_88CB20F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44948, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DFC40: call_seq lbl_88CB04A4, lbl_88045AA8, lbl_88CB1D04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB04A4_889DFC40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1D04, (ts4_word)(ts4_word)lbl_88045AA8, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DFCA8: call_seq lbl_88CB1D94, lbl_880457FC, lbl_88CB1D34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB1D94_889DFCA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1D34, (ts4_word)(ts4_word)lbl_880457FC, (ts4_word)(ts4_word)lbl_88CB1D94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DFD10: call_seq lbl_88CB1CD4, lbl_880455E0, lbl_88CB1D64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB1CD4_889DFD10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1D64, (ts4_word)(ts4_word)lbl_880455E0, (ts4_word)(ts4_word)lbl_88CB1CD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DFD78: call_seq lbl_8804CE5C, lbl_88CB1D04, lbl_880459F8, lbl_88CB1D94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8804CE5C_889DFD78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1D94, (ts4_word)(ts4_word)lbl_880459F8, (ts4_word)(ts4_word)lbl_88CB1D04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804CE5C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DFDE0: call_seq lbl_88B44AE0, lbl_88045070, lbl_88CB1DC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44AE0_889DFDE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1DC4, (ts4_word)(ts4_word)lbl_88045070, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44AE0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DFE50: call_seq lbl_88B44B10, lbl_88CB1D94, lbl_88041DE0, lbl_88CB1DF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44B10_889DFE50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1DF4, (ts4_word)(ts4_word)lbl_88041DE0, (ts4_word)(ts4_word)lbl_88CB1D94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44B10, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DFEC8: call_seq lbl_88B44BBC, lbl_88CB04A4, lbl_8803F5D4, lbl_88CB1E24, lbl_8804CEB8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44BBC_889DFEC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1E24, (ts4_word)(ts4_word)lbl_8803F5D4, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804CEB8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B44BBC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DFF38: call_seq lbl_88B44BD4, lbl_88CB1EE4, lbl_880402B0, lbl_88CB1E54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44BD4_889DFF38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1E54, (ts4_word)(ts4_word)lbl_880402B0, (ts4_word)(ts4_word)lbl_88CB1EE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44BD4, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889DFFB0: call_seq lbl_88CB1EB4, lbl_88040E04, lbl_88CB1E84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB1EB4_889DFFB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1E84, (ts4_word)(ts4_word)lbl_88040E04, (ts4_word)(ts4_word)lbl_88CB1EB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0018: call_seq lbl_88B44BEC, lbl_88CB1EE4, lbl_8803EFA8, lbl_88CB1EB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44BEC_889E0018(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1EB4, (ts4_word)(ts4_word)lbl_8803EFA8, (ts4_word)(ts4_word)lbl_88CB1EE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44BEC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0090: call_seq lbl_88B44C20, lbl_88CB1E24, lbl_88040290, lbl_88CB1EE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44C20_889E0090(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1EE4, (ts4_word)(ts4_word)lbl_88040290, (ts4_word)(ts4_word)lbl_88CB1E24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44C20, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0108: call_seq lbl_88CB1EE4, lbl_880402A0, lbl_88CB1F14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB1EE4_889E0108(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1F14, (ts4_word)(ts4_word)lbl_880402A0, (ts4_word)(ts4_word)lbl_88CB1EE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0170: call_seq lbl_88CB1E54, lbl_88040E18, lbl_88CB1F44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB1E54_889E0170(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1F44, (ts4_word)(ts4_word)lbl_88040E18, (ts4_word)(ts4_word)lbl_88CB1E54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E01D8: call_seq lbl_88CB1F14, lbl_88040E68, lbl_88CB1F74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB1F14_889E01D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1F74, (ts4_word)(ts4_word)lbl_88040E68, (ts4_word)(ts4_word)lbl_88CB1F14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0240: call_seq lbl_88B44CC8, lbl_88CB2004, lbl_8803F6D8, lbl_88CB1FA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44CC8_889E0240(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1FA4, (ts4_word)(ts4_word)lbl_8803F6D8, (ts4_word)(ts4_word)lbl_88CB2004, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44CC8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E02B8: call_seq lbl_88B44CF8, lbl_88CB2034, lbl_88045914, lbl_88CB1FD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44CF8_889E02B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB1FD4, (ts4_word)(ts4_word)lbl_88045914, (ts4_word)(ts4_word)lbl_88CB2034, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44CF8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0330: call_seq lbl_88B44D10, lbl_88CB20F4, lbl_88047070, lbl_88CB2004, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44D10_889E0330(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2004, (ts4_word)(ts4_word)lbl_88047070, (ts4_word)(ts4_word)lbl_88CB20F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44D10, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E03A8: call_seq lbl_88B44D40, lbl_88CB2004, lbl_880402BC, lbl_88CB2034, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44D40_889E03A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2034, (ts4_word)(ts4_word)lbl_880402BC, (ts4_word)(ts4_word)lbl_88CB2004, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44D40, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0420: call_seq lbl_88B44D58, lbl_88CB2034, lbl_88045580, lbl_88CB2064, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44D58_889E0420(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2064, (ts4_word)(ts4_word)lbl_88045580, (ts4_word)(ts4_word)lbl_88CB2034, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44D58, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0498: call_seq lbl_88B44D70, lbl_88CB04A4, lbl_8803F660, lbl_88CB2094, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44D70_889E0498(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2094, (ts4_word)(ts4_word)lbl_8803F660, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44D70, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0510: get u32@lbl_88B44E08, lbl_88B46790, u32@lbl_88B44E04, u32@lbl_88B44E00, u32@0x50, u32@0x110 */
void ts4_get_u32_lbl_88B44E08_889E0510(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88B44E08;
    t2 = *(ts4_word *)lbl_88B44E04;
    t3 = *(ts4_word *)lbl_88B44E00;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B46790) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B46790) + 272) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B46790) + 560) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x889E05B8: call_seq lbl_88B44E10, lbl_88CB04A4, lbl_8803F084, lbl_88CB20F4, lbl_8804CECC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44E10_889E05B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB20F4, (ts4_word)(ts4_word)lbl_8803F084, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804CECC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B44E10, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0630: call_seq lbl_88B44E88, lbl_88CB04A4, lbl_8804707C, lbl_88CB2124, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44E88_889E0630(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2124, (ts4_word)(ts4_word)lbl_8804707C, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44E88, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E06A8: call_seq lbl_88B44EA0, lbl_88CB0B94, lbl_88044F38, lbl_88CB2154, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44EA0_889E06A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2154, (ts4_word)(ts4_word)lbl_88044F38, (ts4_word)(ts4_word)lbl_88CB0B94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44EA0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0720: call_seq lbl_88B44EB8, lbl_88042E20, lbl_88CB2184, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44EB8_889E0720(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2184, (ts4_word)(ts4_word)lbl_88042E20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44EB8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0790: call_seq lbl_88B44ED0, lbl_88CB04A4, lbl_8803EFD0, lbl_88CB21B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44ED0_889E0790(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB21B4, (ts4_word)(ts4_word)lbl_8803EFD0, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44ED0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0808: call_seq lbl_88B44F18, lbl_88044F10, lbl_88CB21E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44F18_889E0808(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB21E4, (ts4_word)(ts4_word)lbl_88044F10, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44F18, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0878: call_seq lbl_88B44F30, lbl_88CB04A4, lbl_88044F90, lbl_88CB2214, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44F30_889E0878(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2214, (ts4_word)(ts4_word)lbl_88044F90, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44F30, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E08F0: call_seq lbl_88B44F60, lbl_88CB22D4, lbl_8803F670, lbl_88CB2244, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44F60_889E08F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2244, (ts4_word)(ts4_word)lbl_8803F670, (ts4_word)(ts4_word)lbl_88CB22D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44F60, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0968: call_seq lbl_88B44FD8, lbl_880404E0, lbl_88CB2274, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B44FD8_889E0968(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2274, (ts4_word)(ts4_word)lbl_880404E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B44FD8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E09D8: call_seq lbl_88B45020, lbl_880404B8, lbl_88CB22A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45020_889E09D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB22A4, (ts4_word)(ts4_word)lbl_880404B8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45020, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0A48: call_seq lbl_88B45068, lbl_88CB1734, lbl_8803F030, lbl_88CB22D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45068_889E0A48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB22D4, (ts4_word)(ts4_word)lbl_8803F030, (ts4_word)(ts4_word)lbl_88CB1734, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45068, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0AC0: call_seq lbl_88B45140, lbl_88CB1644, lbl_88044EA8, lbl_88CB2304, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45140_889E0AC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2304, (ts4_word)(ts4_word)lbl_88044EA8, (ts4_word)(ts4_word)lbl_88CB1644, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45140, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0B38: call_seq lbl_88B45188, lbl_88CB1644, lbl_88044E64, lbl_88CB2334, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45188_889E0B38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2334, (ts4_word)(ts4_word)lbl_88044E64, (ts4_word)(ts4_word)lbl_88CB1644, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45188, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0BB0: call_seq lbl_88B451E8, lbl_88CB1674, lbl_88044DD0, lbl_88CB2364, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B451E8_889E0BB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2364, (ts4_word)(ts4_word)lbl_88044DD0, (ts4_word)(ts4_word)lbl_88CB1674, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B451E8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0C28: call_seq lbl_88B45248, lbl_88CB1674, lbl_88044CD0, lbl_88CB2394, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45248_889E0C28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2394, (ts4_word)(ts4_word)lbl_88044CD0, (ts4_word)(ts4_word)lbl_88CB1674, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45248, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0CA0: call_seq lbl_88B452A8, lbl_88CB1644, lbl_88044BD4, lbl_88CB23C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B452A8_889E0CA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB23C4, (ts4_word)(ts4_word)lbl_88044BD4, (ts4_word)(ts4_word)lbl_88CB1644, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B452A8, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0D18: call_seq lbl_88B45368, lbl_8804D090, lbl_8803F094, lbl_88CB23F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45368_889E0D18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB23F4, (ts4_word)(ts4_word)lbl_8803F094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45368, (ts4_word)17, (ts4_word)(ts4_word)lbl_8804D090, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0D90: call_seq lbl_88B45500, lbl_88CB0C54, lbl_8803F0AC, lbl_88CB2424, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45500_889E0D90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2424, (ts4_word)(ts4_word)lbl_8803F0AC, (ts4_word)(ts4_word)lbl_88CB0C54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45500, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0E08: call_seq lbl_88B45518, lbl_88CB0C54, lbl_88044E30, lbl_88CB2454, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45518_889E0E08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2454, (ts4_word)(ts4_word)lbl_88044E30, (ts4_word)(ts4_word)lbl_88CB0C54, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45518, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0E80: call_seq lbl_88B45530, lbl_88CB0C54, lbl_88044DF8, lbl_88CB2484, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45530_889E0E80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2484, (ts4_word)(ts4_word)lbl_88044DF8, (ts4_word)(ts4_word)lbl_88CB0C54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45530, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0EF8: call_seq lbl_88B45560, lbl_88044B54, lbl_88CB24B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45560_889E0EF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB24B4, (ts4_word)(ts4_word)lbl_88044B54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45560, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0F68: call_seq lbl_88B45590, lbl_88CB0C54, lbl_88044D8C, lbl_88CB24E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45590_889E0F68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB24E4, (ts4_word)(ts4_word)lbl_88044D8C, (ts4_word)(ts4_word)lbl_88CB0C54, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45590, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E0FE0: call_seq lbl_88B455A8, lbl_88CB1674, lbl_8804705C, lbl_88CB2514, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B455A8_889E0FE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2514, (ts4_word)(ts4_word)lbl_8804705C, (ts4_word)(ts4_word)lbl_88CB1674, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B455A8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1058: call_seq lbl_88B45638, lbl_88CB04A4, lbl_88044D60, lbl_88CB2544, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45638_889E1058(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2544, (ts4_word)(ts4_word)lbl_88044D60, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45638, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E10D0: call_seq lbl_88B45668, lbl_88CB04A4, lbl_88044C84, lbl_88CB2574, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45668_889E10D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2574, (ts4_word)(ts4_word)lbl_88044C84, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45668, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1148: call_seq lbl_88B45680, lbl_88CB04A4, lbl_88044C48, lbl_88CB25A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45680_889E1148(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB25A4, (ts4_word)(ts4_word)lbl_88044C48, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45680, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E11C0: call_seq lbl_88B45698, lbl_88044A08, lbl_88CB25D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45698_889E11C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB25D4, (ts4_word)(ts4_word)lbl_88044A08, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45698, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1230: call_seq lbl_88B456C8, lbl_88CB04A4, lbl_88044C08, lbl_88CB2604, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B456C8_889E1230(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2604, (ts4_word)(ts4_word)lbl_88044C08, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B456C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E12A8: call_seq lbl_88B456E0, lbl_88040668, lbl_88CB2634, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B456E0_889E12A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2634, (ts4_word)(ts4_word)lbl_88040668, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B456E0, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1318: call_seq lbl_88B457B8, lbl_88CB04A4, lbl_88040658, lbl_88CB2664, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B457B8_889E1318(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2664, (ts4_word)(ts4_word)lbl_88040658, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B457B8, (ts4_word)18, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1390: call_seq lbl_88B45968, lbl_8803F5F4, lbl_88CB2694, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45968_889E1390(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2694, (ts4_word)(ts4_word)lbl_8803F5F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45968, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1400: call_seq lbl_88B45B00, lbl_88CB1674, lbl_8803F64C, lbl_88CB26C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45B00_889E1400(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB26C4, (ts4_word)(ts4_word)lbl_8803F64C, (ts4_word)(ts4_word)lbl_88CB1674, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45B00, (ts4_word)26, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1478: call_seq lbl_88CB04A4, lbl_8804494C, lbl_88CB26F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB04A4_889E1478(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB26F4, (ts4_word)(ts4_word)lbl_8804494C, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E14E0: call_seq lbl_88B45D70, lbl_88CB26F4, lbl_88044700, lbl_88CB2724, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45D70_889E14E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2724, (ts4_word)(ts4_word)lbl_88044700, (ts4_word)(ts4_word)lbl_88CB26F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45D70, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1558: call_seq lbl_88CB04A4, lbl_88044924, lbl_88CB2754, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB04A4_889E1558(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2754, (ts4_word)(ts4_word)lbl_88044924, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E15C0: call_seq lbl_88B45DE8, lbl_88044438, lbl_88CB2784, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45DE8_889E15C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2784, (ts4_word)(ts4_word)lbl_88044438, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45DE8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1630: call_seq lbl_88B45E30, lbl_88CB2754, lbl_88044680, lbl_88CB27B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45E30_889E1630(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB27B4, (ts4_word)(ts4_word)lbl_88044680, (ts4_word)(ts4_word)lbl_88CB2754, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45E30, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E16A8: call_seq lbl_88CB04A4, lbl_880448C8, lbl_88CB27E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB04A4_889E16A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB27E4, (ts4_word)(ts4_word)lbl_880448C8, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1710: call_seq lbl_88CB04A4, lbl_880448FC, lbl_88CB2814, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB04A4_889E1710(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2814, (ts4_word)(ts4_word)lbl_880448FC, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1778: call_seq lbl_88B45E60, lbl_88CB27E4, lbl_88044524, lbl_88CB2844, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45E60_889E1778(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2844, (ts4_word)(ts4_word)lbl_88044524, (ts4_word)(ts4_word)lbl_88CB27E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45E60, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E17F0: call_seq lbl_88B45EC0, lbl_88CB2814, lbl_880446BC, lbl_88CB2874, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45EC0_889E17F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2874, (ts4_word)(ts4_word)lbl_880446BC, (ts4_word)(ts4_word)lbl_88CB2814, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45EC0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1868: call_seq lbl_88CB04A4, lbl_8804489C, lbl_88CB28A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB04A4_889E1868(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB28A4, (ts4_word)(ts4_word)lbl_8804489C, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E18D0: call_seq lbl_88B45F20, lbl_88CB28A4, lbl_88044650, lbl_88CB28D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B45F20_889E18D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB28D4, (ts4_word)(ts4_word)lbl_88044650, (ts4_word)(ts4_word)lbl_88CB28A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B45F20, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1948: call_seq lbl_88CB04A4, lbl_88044874, lbl_88CB2904, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB04A4_889E1948(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2904, (ts4_word)(ts4_word)lbl_88044874, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E19B0: call_seq lbl_88B46010, lbl_88CB2904, lbl_8804461C, lbl_88CB2934, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46010_889E19B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2934, (ts4_word)(ts4_word)lbl_8804461C, (ts4_word)(ts4_word)lbl_88CB2904, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46010, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1A28: call_seq lbl_88B46058, lbl_88044268, lbl_88CB2964, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46058_889E1A28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2964, (ts4_word)(ts4_word)lbl_88044268, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46058, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1A98: call_seq lbl_88B460A0, lbl_88CB04A4, lbl_8804484C, lbl_88CB2994, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B460A0_889E1A98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2994, (ts4_word)(ts4_word)lbl_8804484C, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B460A0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1B10: call_seq lbl_88B460B8, lbl_880443CC, lbl_88CB29C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B460B8_889E1B10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB29C4, (ts4_word)(ts4_word)lbl_880443CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B460B8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1B80: call_seq lbl_88B46100, lbl_88CB2994, lbl_880445E4, lbl_88CB29F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46100_889E1B80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB29F4, (ts4_word)(ts4_word)lbl_880445E4, (ts4_word)(ts4_word)lbl_88CB2994, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46100, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1BF8: call_seq lbl_88CB04A4, lbl_8804481C, lbl_88CB2A24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB04A4_889E1BF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2A24, (ts4_word)(ts4_word)lbl_8804481C, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1C60: call_seq lbl_88B46118, lbl_88CB2A24, lbl_880445A8, lbl_88CB2A54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46118_889E1C60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2A54, (ts4_word)(ts4_word)lbl_880445A8, (ts4_word)(ts4_word)lbl_88CB2A24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46118, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1CD8: call_seq lbl_88B461C0, lbl_8804449C, lbl_88CB2A84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B461C0_889E1CD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2A84, (ts4_word)(ts4_word)lbl_8804449C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B461C0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1D48: call_seq lbl_88B461F0, lbl_88CB04A4, lbl_88044744, lbl_88CB2AB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B461F0_889E1D48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2AB4, (ts4_word)(ts4_word)lbl_88044744, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B461F0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1DC0: call_seq lbl_88B46238, lbl_88CB04A4, lbl_88044758, lbl_88CB2AE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46238_889E1DC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2AE4, (ts4_word)(ts4_word)lbl_88044758, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46238, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1E38: call_seq lbl_88CB04A4, lbl_880447EC, lbl_88CB2B14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB04A4_889E1E38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2B14, (ts4_word)(ts4_word)lbl_880447EC, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1EA0: call_seq lbl_88B46280, lbl_88CB2B14, lbl_88044568, lbl_88CB2B44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46280_889E1EA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2B44, (ts4_word)(ts4_word)lbl_88044568, (ts4_word)(ts4_word)lbl_88CB2B14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46280, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1F18: call_seq lbl_88B462C8, lbl_88CB04A4, lbl_880447B8, lbl_88CB2B74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B462C8_889E1F18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2B74, (ts4_word)(ts4_word)lbl_880447B8, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B462C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E1F90: call_seq lbl_88B462E0, lbl_88CB04A4, lbl_88044784, lbl_88CB2BA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B462E0_889E1F90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2BA4, (ts4_word)(ts4_word)lbl_88044784, (ts4_word)(ts4_word)lbl_88CB04A4, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B462E0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2008: call_seq lbl_88B462F8, lbl_88CB2B74, lbl_880444CC, lbl_88CB2BD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B462F8_889E2008(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2BD4, (ts4_word)(ts4_word)lbl_880444CC, (ts4_word)(ts4_word)lbl_88CB2B74, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B462F8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2080: call_seq lbl_8804C9C8, lbl_8804D0E8, lbl_88CB2C04, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF500, fn_88563470 */
ts4_word ts4_call_seq_lbl_8804C9C8_889E2080(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CB2C04, (ts4_word)(ts4_word)lbl_8804D0E8, (ts4_word)3, (ts4_word)(ts4_word)lbl_8804C9C8);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF500);
    return t2;
}

/* Swing_DLL.xex 0x889E20C8: call_seq lbl_88B469E8, lbl_88046C94, lbl_88CB2C1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B469E8_889E20C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2C1C, (ts4_word)(ts4_word)lbl_88046C94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B469E8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2138: addr lbl_88B4B2E8, u32@lbl_88B46A60, u32@0x38 */
void ts4_addr_lbl_88B4B2E8_889E2138(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B4B2E8) + 56) = (ts4_word)(*(ts4_word *)lbl_88B46A60);
    return;
}

/* Swing_DLL.xex 0x889E2150: call_seq lbl_88B4B2E8, lbl_8803EF04, lbl_88CB2C4C, lbl_8804D808, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B2E8_889E2150(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2C4C, (ts4_word)(ts4_word)lbl_8803EF04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804D808, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B4B2E8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E21C0: call_seq lbl_88B46A64, lbl_88046C78, lbl_88CB2C7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46A64_889E21C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2C7C, (ts4_word)(ts4_word)lbl_88046C78, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46A64, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2230: call_seq lbl_88B46A94, lbl_8803EC6C, lbl_88CB2CAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46A94_889E2230(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2CAC, (ts4_word)(ts4_word)lbl_8803EC6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46A94, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E22A0: call_seq lbl_88B46AC8, lbl_88CB303C, lbl_8803EE48, lbl_88CB2CDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46AC8_889E22A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2CDC, (ts4_word)(ts4_word)lbl_8803EE48, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46AC8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E2318: call_seq lbl_88B46B28, lbl_88040040, lbl_88CB2D0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B46B28_889E2318(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB2D0C, (ts4_word)(ts4_word)lbl_88040040, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B46B28, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}
