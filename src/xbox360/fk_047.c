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

extern char ts4_addr_lbl_8803A308_88AFF5F0[];
extern char lbl_8803EC6C[];
extern char lbl_8803EC94[];
extern char lbl_8803ECB0[];
extern char lbl_8803ECD0[];
extern char lbl_8803EE48[];
extern char lbl_8803EE88[];
extern char lbl_8803EF04[];
extern char lbl_8803EF90[];
extern char lbl_8803EFA8[];
extern char lbl_8803EFD0[];
extern char lbl_8803F00C[];
extern char lbl_8803F030[];
extern char lbl_8803F048[];
extern char lbl_8803F084[];
extern char lbl_8803F094[];
extern char lbl_8803F0AC[];
extern char lbl_8803F0C8[];
extern char lbl_8803F5D4[];
extern char lbl_8803F5F4[];
extern char lbl_8803F610[];
extern char lbl_8803F634[];
extern char lbl_8803F64C[];
extern char lbl_8803F660[];
extern char lbl_8803F690[];
extern char lbl_8803F6B0[];
extern char lbl_8803F6CC[];
extern char lbl_8803F6D8[];
extern char lbl_8803F9E8[];
extern char lbl_8803FA04[];
extern char lbl_8803FA18[];
extern char lbl_8803FBE0[];
extern char lbl_8803FC48[];
extern char lbl_8803FC6C[];
extern char lbl_8803FC80[];
extern char lbl_8803FCA0[];
extern char lbl_88040040[];
extern char lbl_88040078[];
extern char lbl_880400BC[];
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
extern char lbl_88040658[];
extern char lbl_88040668[];
extern char lbl_88040DB0[];
extern char lbl_88040E04[];
extern char lbl_88040E18[];
extern char lbl_88040E68[];
extern char lbl_88041AFC[];
extern char lbl_88041B0C[];
extern char lbl_88041DE0[];
extern char lbl_8804215C[];
extern char lbl_88042170[];
extern char lbl_88042184[];
extern char lbl_880421A0[];
extern char lbl_880421C4[];
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
extern char lbl_88042380[];
extern char lbl_88042390[];
extern char lbl_880423D4[];
extern char lbl_88042E20[];
extern char lbl_88043ED0[];
extern char lbl_88043EE0[];
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
extern char lbl_88046498[];
extern char lbl_88046518[];
extern char lbl_88046574[];
extern char lbl_8804696C[];
extern char lbl_88046C60[];
extern char lbl_88046C78[];
extern char lbl_88046C94[];
extern char lbl_88047050[];
extern char lbl_8804705C[];
extern char lbl_88047070[];
extern char lbl_8804707C[];
extern char lbl_88058C60[];
extern char lbl_88059780[];
extern char lbl_880597A8[];
extern char lbl_880597C0[];
extern char lbl_88059848[];
extern char lbl_88059900[];
extern char lbl_8805995C[];
extern char lbl_880599A0[];
extern char lbl_880599CC[];
extern char lbl_88059A08[];
extern char lbl_88059A2C[];
extern char lbl_88059A60[];
extern char lbl_88059A8C[];
extern char lbl_88059AA0[];
extern char lbl_88059AFC[];
extern char lbl_88059B10[];
extern char lbl_88059B74[];
extern char lbl_88059BD8[];
extern char lbl_88059BEC[];
extern char lbl_88059DE8[];
extern char lbl_88059E14[];
extern char lbl_88059E40[];
extern char lbl_88059E6C[];
extern char lbl_88059E80[];
extern char lbl_88059ED8[];
extern char lbl_8805A56C[];
extern char lbl_8805A5B0[];
extern char lbl_88B80964[];
extern char lbl_88B80BC0[];
extern char lbl_88B80C20[];
extern char lbl_88B80CB0[];
extern char lbl_88B80CC8[];
extern char lbl_88B80CF8[];
extern char lbl_88B80D40[];
extern char lbl_88B80D88[];
extern char lbl_88B80DA0[];
extern char lbl_88B80DD4[];
extern char lbl_88B80E04[];
extern char lbl_88B80E1C[];
extern char lbl_88B80E34[];
extern char lbl_88B80E64[];
extern char lbl_88B80E94[];
extern char lbl_88B80EC4[];
extern char lbl_88B80EDC[];
extern char lbl_88B80EF4[];
extern char lbl_88B80EF8[];
extern char lbl_88B80F40[];
extern char lbl_88B80F88[];
extern char lbl_88B80FA0[];
extern char lbl_88B80FD0[];
extern char lbl_88B81048[];
extern char lbl_88B810D8[];
extern char lbl_88B81138[];
extern char lbl_88B811E0[];
extern char lbl_88B81258[];
extern char lbl_88B812A0[];
extern char lbl_88B81330[];
extern char lbl_88B81390[];
extern char lbl_88B813D8[];
extern char lbl_88B81408[];
extern char lbl_88B81438[];
extern char lbl_88B81450[];
extern char lbl_88B814B0[];
extern char lbl_88B814C8[];
extern char lbl_88B814F8[];
extern char lbl_88B81510[];
extern char lbl_88B81514[];
extern char lbl_88B81530[];
extern char lbl_88B81578[];
extern char lbl_88B81590[];
extern char lbl_88B815F0[];
extern char lbl_88B815FC[];
extern char lbl_88B8162C[];
extern char lbl_88B81648[];
extern char lbl_88B81690[];
extern char lbl_88B816AC[];
extern char lbl_88B816B0[];
extern char lbl_88B81740[];
extern char lbl_88B81758[];
extern char lbl_88B817D0[];
extern char lbl_88B81800[];
extern char lbl_88B81820[];
extern char lbl_88B818C8[];
extern char lbl_88B818E0[];
extern char lbl_88B81910[];
extern char lbl_88B81928[];
extern char lbl_88B819D0[];
extern char lbl_88B81A18[];
extern char lbl_88B81AF0[];
extern char lbl_88B81B20[];
extern char lbl_88B81B38[];
extern char lbl_88B81B68[];
extern char lbl_88B81BFC[];
extern char lbl_88B81C00[];
extern char lbl_88B81C48[];
extern char lbl_88B81C60[];
extern char lbl_88B81CF0[];
extern char lbl_88B81DC8[];
extern char lbl_88B81E10[];
extern char lbl_88B81E88[];
extern char lbl_88B81EB8[];
extern char lbl_88B81F30[];
extern char lbl_88B81F78[];
extern char lbl_88B81FA8[];
extern char lbl_88B82008[];
extern char lbl_88B82038[];
extern char lbl_88B82080[];
extern char lbl_88B820B0[];
extern char lbl_88B820C8[];
extern char lbl_88B8224C[];
extern char lbl_88B8227C[];
extern char lbl_88B82280[];
extern char lbl_88B82328[];
extern char lbl_88B82358[];
extern char lbl_88B82388[];
extern char lbl_88B823A0[];
extern char lbl_88B823D0[];
extern char lbl_88B823E8[];
extern char lbl_88B82400[];
extern char lbl_88B824AC[];
extern char lbl_88B824B0[];
extern char lbl_88B824B4[];
extern char lbl_88B824C0[];
extern char lbl_88B82550[];
extern char lbl_88B82568[];
extern char lbl_88B82580[];
extern char lbl_88B82598[];
extern char lbl_88B825E0[];
extern char lbl_88B825F8[];
extern char lbl_88B82630[];
extern char lbl_88B826D8[];
extern char lbl_88B826F0[];
extern char lbl_88B82750[];
extern char lbl_88B82768[];
extern char lbl_88B827B0[];
extern char lbl_88B82810[];
extern char lbl_88B82870[];
extern char lbl_88B828D0[];
extern char lbl_88B82990[];
extern char lbl_88B82B58[];
extern char lbl_88B82B70[];
extern char lbl_88B82B88[];
extern char lbl_88B82BB8[];
extern char lbl_88B82BE8[];
extern char lbl_88B82C00[];
extern char lbl_88B82C30[];
extern char lbl_88B82C78[];
extern char lbl_88B82CC0[];
extern char lbl_88B82D50[];
extern char lbl_88B82D98[];
extern char lbl_88B82DC8[];
extern char lbl_88B82DF8[];
extern char lbl_88B82E28[];
extern char lbl_88B82E40[];
extern char lbl_88B82E58[];
extern char lbl_88B82E88[];
extern char lbl_88B82EA0[];
extern char lbl_88B82F90[];
extern char lbl_88B83140[];
extern char lbl_88B832D8[];
extern char lbl_88B83530[];
extern char lbl_88B835A8[];
extern char lbl_88B835F0[];
extern char lbl_88B83620[];
extern char lbl_88B83680[];
extern char lbl_88B836E0[];
extern char lbl_88B837D0[];
extern char lbl_88B838C0[];
extern char lbl_88B83908[];
extern char lbl_88B839E0[];
extern char lbl_88B839F8[];
extern char lbl_88B83A40[];
extern char lbl_88B83A88[];
extern char lbl_88B83AA0[];
extern char lbl_88B83AE8[];
extern char lbl_88B83B00[];
extern char lbl_88B83BA8[];
extern char lbl_88B83BD8[];
extern char lbl_88B83C20[];
extern char lbl_88B83C68[];
extern char lbl_88B83CB0[];
extern char lbl_88B83CC8[];
extern char lbl_88B83CE0[];
extern char lbl_88B846E8[];
extern char lbl_88B84700[];
extern char lbl_88B847A8[];
extern char lbl_88B847F0[];
extern char lbl_88B848C8[];
extern char lbl_88B84940[];
extern char lbl_88B84958[];
extern char lbl_88B849D0[];
extern char lbl_88B84C58[];
extern char lbl_88B84CD0[];
extern char lbl_88B84CD4[];
extern char lbl_88B84D04[];
extern char lbl_88B84D34[];
extern char lbl_88B84D38[];
extern char lbl_88B84DC8[];
extern char lbl_88B84EE8[];
extern char lbl_88B84F00[];
extern char lbl_88B84F90[];
extern char lbl_88B85080[];
extern char lbl_88B85098[];
extern char lbl_88B8B270[];
extern char lbl_88B8B2B8[];
extern char lbl_88CD3304[];
extern char lbl_88CD3DB4[];
extern char lbl_88CD3E74[];
extern char lbl_88CD3F94[];
extern char lbl_88CD40B4[];
extern char lbl_88CD4114[];
extern char lbl_88CD4144[];
extern char lbl_88CD43E4[];
extern char lbl_88CD4534[];
extern char lbl_88CD4594[];
extern char lbl_88CD45C4[];
extern char lbl_88CD45F4[];
extern char lbl_88CD4624[];
extern char lbl_88CD4654[];
extern char lbl_88CD4684[];
extern char lbl_88CD46B4[];
extern char lbl_88CD46E4[];
extern char lbl_88CD4714[];
extern char lbl_88CD4744[];
extern char lbl_88CD4774[];
extern char lbl_88CD47A4[];
extern char lbl_88CD47D4[];
extern char lbl_88CD4804[];
extern char lbl_88CD4834[];
extern char lbl_88CD4864[];
extern char lbl_88CD4894[];
extern char lbl_88CD48C4[];
extern char lbl_88CD48F4[];
extern char lbl_88CD4924[];
extern char lbl_88CD4954[];
extern char lbl_88CD4984[];
extern char lbl_88CD49B4[];
extern char lbl_88CD49E4[];
extern char lbl_88CD4A14[];
extern char lbl_88CD4A44[];
extern char lbl_88CD4AA4[];
extern char lbl_88CD4AD4[];
extern char lbl_88CD4B04[];
extern char lbl_88CD4B34[];
extern char lbl_88CD4B64[];
extern char lbl_88CD4B94[];
extern char lbl_88CD4BC4[];
extern char lbl_88CD4BF4[];
extern char lbl_88CD4C24[];
extern char lbl_88CD4C54[];
extern char lbl_88CD4C84[];
extern char lbl_88CD4CB4[];
extern char lbl_88CD4CE4[];
extern char lbl_88CD4D14[];
extern char lbl_88CD4D44[];
extern char lbl_88CD4D74[];
extern char lbl_88CD4DA4[];
extern char lbl_88CD4DD4[];
extern char lbl_88CD4E04[];
extern char lbl_88CD4E34[];
extern char lbl_88CD4E64[];
extern char lbl_88CD4E94[];
extern char lbl_88CD4EC4[];
extern char lbl_88CD4EF4[];
extern char lbl_88CD4F24[];
extern char lbl_88CD4F54[];
extern char lbl_88CD4F84[];
extern char lbl_88CD4FB4[];
extern char lbl_88CD4FE4[];
extern char lbl_88CD5014[];
extern char lbl_88CD5044[];
extern char lbl_88CD5074[];
extern char lbl_88CD50A4[];
extern char lbl_88CD50D4[];
extern char lbl_88CD5104[];
extern char lbl_88CD5134[];
extern char lbl_88CD5164[];
extern char lbl_88CD5194[];
extern char lbl_88CD51C4[];
extern char lbl_88CD51F4[];
extern char lbl_88CD5224[];
extern char lbl_88CD5254[];
extern char lbl_88CD5284[];
extern char lbl_88CD52B4[];
extern char lbl_88CD52E4[];
extern char lbl_88CD5314[];
extern char lbl_88CD5344[];
extern char lbl_88CD5374[];
extern char lbl_88CD53A4[];
extern char lbl_88CD53D4[];
extern char lbl_88CD5404[];
extern char lbl_88CD5434[];
extern char lbl_88CD5464[];
extern char lbl_88CD5494[];
extern char lbl_88CD54C4[];
extern char lbl_88CD54F4[];
extern char lbl_88CD5524[];
extern char lbl_88CD5554[];
extern char lbl_88CD5584[];
extern char lbl_88CD55B4[];
extern char lbl_88CD55E4[];
extern char lbl_88CD5614[];
extern char lbl_88CD5644[];
extern char lbl_88CD5674[];
extern char lbl_88CD56A4[];
extern char lbl_88CD56D4[];
extern char lbl_88CD5704[];
extern char lbl_88CD5734[];
extern char lbl_88CD5764[];
extern char lbl_88CD5794[];
extern char lbl_88CD57C4[];
extern char lbl_88CD57F4[];
extern char lbl_88CD5824[];
extern char lbl_88CD5854[];
extern char lbl_88CD5884[];
extern char lbl_88CD58B4[];
extern char lbl_88CD58E4[];
extern char lbl_88CD5914[];
extern char lbl_88CD5944[];
extern char lbl_88CD5974[];
extern char lbl_88CD59A4[];
extern char lbl_88CD59D4[];
extern char lbl_88CD5A34[];
extern char lbl_88CD5A64[];
extern char lbl_88CD5A94[];
extern char lbl_88CD5AC4[];
extern char lbl_88CD5AF4[];
extern char lbl_88CD5B24[];
extern char lbl_88CD5B54[];
extern char lbl_88CD5B84[];
extern char lbl_88CD5BB4[];
extern char lbl_88CD5BE4[];
extern char lbl_88CD5C14[];
extern char lbl_88CD5C44[];
extern char lbl_88CD5C74[];
extern char lbl_88CD5CA4[];
extern char lbl_88CD5CD4[];
extern char lbl_88CD5D04[];
extern char lbl_88CD5D34[];
extern char lbl_88CD5D64[];
extern char lbl_88CD5D94[];
extern char lbl_88CD5DC4[];
extern char lbl_88CD5DF4[];
extern char lbl_88CD5E24[];
extern char lbl_88CD5E54[];
extern char lbl_88CD5E84[];
extern char lbl_88CD5EB4[];
extern char lbl_88CD5EE4[];
extern char lbl_88CD5F14[];
extern char lbl_88CD5F44[];
extern char lbl_88CD5F74[];
extern char lbl_88CD5FA4[];
extern char lbl_88CD5FD4[];
extern char lbl_88CD6004[];
extern char lbl_88CD6034[];
extern char lbl_88CD6064[];
extern char lbl_88CD6094[];
extern char lbl_88CD60C4[];
extern char lbl_88CD60F4[];
extern char lbl_88CD6124[];
extern char lbl_88CD6154[];
extern char lbl_88CD6184[];
extern char lbl_88CD61B4[];
extern char lbl_88CD61E4[];
extern char lbl_88CD6214[];
extern char lbl_88CD6244[];
extern char lbl_88CD6274[];
extern char lbl_88CD62A4[];
extern char lbl_88CD62D4[];
extern char lbl_88CD6304[];
extern char lbl_88CD6334[];
extern char lbl_88CD6364[];
extern char lbl_88CD6394[];
extern char lbl_88CD63C4[];
extern char lbl_88CD63F4[];
extern char lbl_88CD6424[];
extern char lbl_88CD6454[];
extern char lbl_88CD6484[];
extern char lbl_88CD64B4[];
extern char lbl_88CD64E4[];
extern char lbl_88CD6514[];
extern char lbl_88CD6544[];
extern char lbl_88CD6574[];
extern char lbl_88CD65A4[];
extern char lbl_88CD65D4[];
extern char lbl_88CD6604[];
extern char lbl_88CD6634[];
extern char lbl_88CD6664[];
extern char lbl_88CD6694[];
extern char lbl_88CD66C4[];
extern char lbl_88CD66F4[];
extern char lbl_88CD6724[];
extern char lbl_88CD673C[];
extern char lbl_88CD676C[];
extern char lbl_88CD679C[];
extern char lbl_88CD67CC[];
extern char lbl_88CD67FC[];
extern char lbl_88CD682C[];
extern char lbl_88CD685C[];
extern char lbl_88CD688C[];
extern char lbl_88CD68BC[];
extern char lbl_88CD68EC[];
extern char lbl_88CD691C[];
extern char lbl_88CD694C[];
extern char lbl_88CD73FC[];
ts4_word fn_8841F080();
ts4_word ts4_set_u32_offc_884CE988();
ts4_word fn_88563470();

/* Swing_DLL.xex 0x88A335A8: call_seq lbl_88B80BC0, lbl_88CD4114, lbl_88042390, lbl_88CD4594, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80BC0_88A335A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4594, (ts4_word)(ts4_word)lbl_88042390, (ts4_word)(ts4_word)lbl_88CD4114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80BC0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33620: call_seq lbl_88CD4144, lbl_88043ED0, lbl_88CD45C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD4144_88A33620(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD45C4, (ts4_word)(ts4_word)lbl_88043ED0, (ts4_word)(ts4_word)lbl_88CD4144, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33688: call_seq lbl_88CD3F94, lbl_8804696C, lbl_88CD45F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3F94_88A33688(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD45F4, (ts4_word)(ts4_word)lbl_8804696C, (ts4_word)(ts4_word)lbl_88CD3F94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A336F0: call_seq lbl_88B80C20, lbl_88CD3304, lbl_8803F00C, lbl_88CD4624, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80C20_88A336F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4624, (ts4_word)(ts4_word)lbl_8803F00C, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80C20, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33768: call_seq lbl_88B80CB0, lbl_88CD43E4, lbl_88046574, lbl_88CD4654, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80CB0_88A33768(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4654, (ts4_word)(ts4_word)lbl_88046574, (ts4_word)(ts4_word)lbl_88CD43E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80CB0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A337E0: call_seq lbl_88B80CC8, lbl_88CD4534, lbl_88046518, lbl_88CD4684, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80CC8_88A337E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4684, (ts4_word)(ts4_word)lbl_88046518, (ts4_word)(ts4_word)lbl_88CD4534, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80CC8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33858: call_seq lbl_88B80CF8, lbl_88CD3F94, lbl_880400BC, lbl_88CD46B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80CF8_88A33858(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD46B4, (ts4_word)(ts4_word)lbl_880400BC, (ts4_word)(ts4_word)lbl_88CD3F94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80CF8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A338D0: call_seq lbl_88B80D40, lbl_88CD4144, lbl_88042380, lbl_88CD46E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80D40_88A338D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD46E4, (ts4_word)(ts4_word)lbl_88042380, (ts4_word)(ts4_word)lbl_88CD4144, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80D40, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33948: call_seq lbl_88B80D88, lbl_88CD40B4, lbl_880423D4, lbl_88CD4714, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80D88_88A33948(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4714, (ts4_word)(ts4_word)lbl_880423D4, (ts4_word)(ts4_word)lbl_88CD40B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80D88, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A339C0: call_seq lbl_88B80DA0, lbl_88CD4114, lbl_88046498, lbl_88CD4744, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80DA0_88A339C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4744, (ts4_word)(ts4_word)lbl_88046498, (ts4_word)(ts4_word)lbl_88CD4114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80DA0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33A38: addr lbl_88B846E8, u32@lbl_88B80964, u32@0x8 */
void ts4_addr_lbl_88B846E8_88A33A38(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B846E8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B80964);
    return;
}

/* Swing_DLL.xex 0x88A33A50: call_seq lbl_88B846E8, lbl_8804215C, lbl_88CD4774, lbl_88059780, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B846E8_88A33A50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)(ts4_word)lbl_8804215C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059780, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B846E8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33AC0: call_seq lbl_88B80DD4, lbl_88CD4774, lbl_88041B0C, lbl_88CD47A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80DD4_88A33AC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD47A4, (ts4_word)(ts4_word)lbl_88041B0C, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80DD4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33B38: call_seq lbl_88B80E04, lbl_88041AFC, lbl_88CD47D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80E04_88A33B38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD47D4, (ts4_word)(ts4_word)lbl_88041AFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80E04, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33BA8: call_seq lbl_88CD4774, lbl_88046098, lbl_88CD4804, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD4774_88A33BA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4804, (ts4_word)(ts4_word)lbl_88046098, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33C10: call_seq lbl_88B80E1C, lbl_88CD4774, lbl_88045C08, lbl_88CD4834, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80E1C_88A33C10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4834, (ts4_word)(ts4_word)lbl_88045C08, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80E1C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33C88: call_seq lbl_88B80E34, lbl_88CD4774, lbl_88045D4C, lbl_88CD4864, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80E34_88A33C88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4864, (ts4_word)(ts4_word)lbl_88045D4C, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80E34, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33D00: call_seq lbl_88B80E64, lbl_88CD4774, lbl_88045D00, lbl_88CD4894, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80E64_88A33D00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4894, (ts4_word)(ts4_word)lbl_88045D00, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80E64, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33D78: call_seq lbl_88B80E94, lbl_88CD4774, lbl_88045D94, lbl_88CD48C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80E94_88A33D78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD48C4, (ts4_word)(ts4_word)lbl_88045D94, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80E94, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33DF0: call_seq lbl_88B80EC4, lbl_88CD4774, lbl_88045E48, lbl_88CD48F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80EC4_88A33DF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD48F4, (ts4_word)(ts4_word)lbl_88045E48, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80EC4, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33E68: call_seq lbl_88B80EDC, lbl_88CD4774, lbl_88045FF4, lbl_88CD4924, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80EDC_88A33E68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4924, (ts4_word)(ts4_word)lbl_88045FF4, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80EDC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33EE0: call_seq lbl_88B80EF8, lbl_88CD4774, lbl_88045F18, lbl_88CD4954, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80EF8_88A33EE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4954, (ts4_word)(ts4_word)lbl_88045F18, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80EF8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33F58: call_seq lbl_88B80F40, lbl_88CD4774, lbl_88045F84, lbl_88CD4984, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80F40_88A33F58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4984, (ts4_word)(ts4_word)lbl_88045F84, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80F40, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33FD0: call_seq lbl_88B80F88, lbl_88CD4774, lbl_880461A4, lbl_88CD49B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80F88_88A33FD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD49B4, (ts4_word)(ts4_word)lbl_880461A4, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80F88, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34048: call_seq lbl_88B80FA0, lbl_88CD4774, lbl_88046178, lbl_88CD49E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80FA0_88A34048(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD49E4, (ts4_word)(ts4_word)lbl_88046178, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80FA0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A340C0: call_seq lbl_880597A8, lbl_88B80FD0, lbl_88CD4774, lbl_88046108, lbl_88CD4A14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880597A8_88A340C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4A14, (ts4_word)(ts4_word)lbl_88046108, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80FD0, (ts4_word)5, (ts4_word)(ts4_word)lbl_880597A8, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34138: call_seq lbl_880597C0, lbl_88B81048, lbl_88CD4774, lbl_88045BCC, lbl_88CD4A44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880597C0_88A34138(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4A44, (ts4_word)(ts4_word)lbl_88045BCC, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81048, (ts4_word)6, (ts4_word)(ts4_word)lbl_880597C0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A341B0: addr lbl_88B84700, u32@lbl_88B80EF4, u32@0x50 */
void ts4_addr_lbl_88B84700_88A341B0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B84700) + 80) = (ts4_word)(*(ts4_word *)lbl_88B80EF4);
    return;
}

/* Swing_DLL.xex 0x88A34240: call_seq lbl_88B810D8, lbl_88CD4774, lbl_88046144, lbl_88CD4AA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B810D8_88A34240(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4AA4, (ts4_word)(ts4_word)lbl_88046144, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B810D8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A342B8: call_seq lbl_88B81138, lbl_88CD4774, lbl_880460D0, lbl_88CD4AD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81138_88A342B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4AD4, (ts4_word)(ts4_word)lbl_880460D0, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81138, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34330: call_seq lbl_88B811E0, lbl_88CD4774, lbl_88045DD8, lbl_88CD4B04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B811E0_88A34330(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4B04, (ts4_word)(ts4_word)lbl_88045DD8, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B811E0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A343A8: call_seq lbl_88B81258, lbl_88CD4774, lbl_88045FC0, lbl_88CD4B34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81258_88A343A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4B34, (ts4_word)(ts4_word)lbl_88045FC0, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81258, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34420: call_seq lbl_88B812A0, lbl_88CD4774, lbl_88045F4C, lbl_88CD4B64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B812A0_88A34420(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4B64, (ts4_word)(ts4_word)lbl_88045F4C, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B812A0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34498: call_seq lbl_88B81330, lbl_88CD4774, lbl_88045E10, lbl_88CD4B94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81330_88A34498(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4B94, (ts4_word)(ts4_word)lbl_88045E10, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81330, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34510: call_seq lbl_88B81390, lbl_88CD4774, lbl_880422DC, lbl_88CD4BC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81390_88A34510(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4BC4, (ts4_word)(ts4_word)lbl_880422DC, (ts4_word)(ts4_word)lbl_88CD4774, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81390, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34588: call_seq lbl_88B813D8, lbl_88CD4BC4, lbl_88045C4C, lbl_88CD4BF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B813D8_88A34588(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4BF4, (ts4_word)(ts4_word)lbl_88045C4C, (ts4_word)(ts4_word)lbl_88CD4BC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B813D8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34600: call_seq lbl_88B81408, lbl_88CD4BC4, lbl_88043EE0, lbl_88CD4C24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81408_88A34600(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4C24, (ts4_word)(ts4_word)lbl_88043EE0, (ts4_word)(ts4_word)lbl_88CD4BC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81408, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34678: call_seq lbl_88CD4BC4, lbl_88045B88, lbl_88CD4C54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD4BC4_88A34678(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4C54, (ts4_word)(ts4_word)lbl_88045B88, (ts4_word)(ts4_word)lbl_88CD4BC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A346E0: call_seq lbl_88B81438, lbl_88CD4BC4, lbl_88045E90, lbl_88CD4C84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81438_88A346E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4C84, (ts4_word)(ts4_word)lbl_88045E90, (ts4_word)(ts4_word)lbl_88CD4BC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81438, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34758: call_seq lbl_88B81450, lbl_88CD3304, lbl_88047050, lbl_88CD4CB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81450_88A34758(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4CB4, (ts4_word)(ts4_word)lbl_88047050, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81450, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A347D0: call_seq lbl_88B814B0, lbl_88CD4CB4, lbl_88045B44, lbl_88CD4CE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B814B0_88A347D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4CE4, (ts4_word)(ts4_word)lbl_88045B44, (ts4_word)(ts4_word)lbl_88CD4CB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B814B0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34848: call_seq lbl_88B814C8, lbl_88CD4CB4, lbl_88045B24, lbl_88CD4D14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B814C8_88A34848(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4D14, (ts4_word)(ts4_word)lbl_88045B24, (ts4_word)(ts4_word)lbl_88CD4CB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B814C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A348C0: call_seq lbl_88B814F8, lbl_88CD4CB4, lbl_880459C0, lbl_88CD4D44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B814F8_88A348C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4D44, (ts4_word)(ts4_word)lbl_880459C0, (ts4_word)(ts4_word)lbl_88CD4CB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B814F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34938: addr lbl_88B847A8, u32@lbl_88B81510, u32@0x8 */
void ts4_addr_lbl_88B847A8_88A34938(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B847A8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B81510);
    return;
}

/* Swing_DLL.xex 0x88A34950: call_seq lbl_88B847A8, lbl_88045224, lbl_88CD4D74, lbl_88059848, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B847A8_88A34950(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4D74, (ts4_word)(ts4_word)lbl_88045224, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059848, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B847A8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A349C0: call_seq lbl_88B81514, lbl_88045194, lbl_88CD4DA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81514_88A349C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4DA4, (ts4_word)(ts4_word)lbl_88045194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81514, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34A30: call_seq lbl_88B81530, lbl_8803EF90, lbl_88CD4DD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81530_88A34A30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4DD4, (ts4_word)(ts4_word)lbl_8803EF90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81530, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34AA0: call_seq lbl_88B81578, lbl_88CD3304, lbl_8803FA04, lbl_88CD4E04, lbl_88059900, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81578_88A34AA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4E04, (ts4_word)(ts4_word)lbl_8803FA04, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059900, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B81578, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34B10: call_seq lbl_88B81590, lbl_88042170, lbl_88CD4E34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81590_88A34B10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4E34, (ts4_word)(ts4_word)lbl_88042170, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81590, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34B80: addr lbl_88B847F0, u32@lbl_88B815F0, u32@0x68 */
void ts4_addr_lbl_88B847F0_88A34B80(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B847F0) + 104) = (ts4_word)(*(ts4_word *)lbl_88B815F0);
    return;
}

/* Swing_DLL.xex 0x88A34B98: call_seq lbl_88B847F0, lbl_88CD3304, lbl_8803F0C8, lbl_88CD4E64, lbl_8805995C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B847F0_88A34B98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4E64, (ts4_word)(ts4_word)lbl_8803F0C8, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805995C, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B847F0, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34C10: call_seq lbl_88B815FC, lbl_880422B8, lbl_88CD4E94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B815FC_88A34C10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4E94, (ts4_word)(ts4_word)lbl_880422B8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B815FC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34C80: call_seq lbl_88B8162C, lbl_88CD4E04, lbl_880403DC, lbl_88CD4EC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8162C_88A34C80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4EC4, (ts4_word)(ts4_word)lbl_880403DC, (ts4_word)(ts4_word)lbl_88CD4E04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8162C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34CF8: call_seq lbl_88B81648, lbl_8804229C, lbl_88CD4EF4, lbl_880599A0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81648_88A34CF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4EF4, (ts4_word)(ts4_word)lbl_8804229C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880599A0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B81648, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34D68: call_seq lbl_88B81690, lbl_88CD4E04, lbl_88040394, lbl_88CD4F24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81690_88A34D68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4F24, (ts4_word)(ts4_word)lbl_88040394, (ts4_word)(ts4_word)lbl_88CD4E04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81690, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34DE0: call_seq lbl_88B816B0, lbl_88042260, lbl_88CD4F54, lbl_880599CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B816B0_88A34DE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4F54, (ts4_word)(ts4_word)lbl_88042260, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880599CC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B816B0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34E50: call_seq lbl_88B81740, lbl_88CD4E04, lbl_8803F690, lbl_88CD4F84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81740_88A34E50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4F84, (ts4_word)(ts4_word)lbl_8803F690, (ts4_word)(ts4_word)lbl_88CD4E04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81740, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34EC8: call_seq lbl_88B81758, lbl_88CD4FE4, lbl_88045734, lbl_88CD4FB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81758_88A34EC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4FB4, (ts4_word)(ts4_word)lbl_88045734, (ts4_word)(ts4_word)lbl_88CD4FE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81758, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34F40: call_seq lbl_88CD3304, lbl_88045A30, lbl_88CD4FE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3304_88A34F40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4FE4, (ts4_word)(ts4_word)lbl_88045A30, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A34FA8: addr lbl_88B848C8, u32@lbl_88B816AC, u32@0x50 */
void ts4_addr_lbl_88B848C8_88A34FA8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B848C8) + 80) = (ts4_word)(*(ts4_word *)lbl_88B816AC);
    return;
}

/* Swing_DLL.xex 0x88A34FC0: call_seq lbl_88B848C8, lbl_88CD4E04, lbl_88040364, lbl_88CD5014, lbl_88059A08, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B848C8_88A34FC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5014, (ts4_word)(ts4_word)lbl_88040364, (ts4_word)(ts4_word)lbl_88CD4E04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059A08, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B848C8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35038: call_seq lbl_88B817D0, lbl_8804223C, lbl_88CD5044, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B817D0_88A35038(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5044, (ts4_word)(ts4_word)lbl_8804223C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B817D0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A350A8: call_seq lbl_88B81800, lbl_88CD4E04, lbl_88040344, lbl_88CD5074, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81800_88A350A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5074, (ts4_word)(ts4_word)lbl_88040344, (ts4_word)(ts4_word)lbl_88CD4E04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81800, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35120: call_seq lbl_88B81820, lbl_8804221C, lbl_88CD50A4, lbl_88059A2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81820_88A35120(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD50A4, (ts4_word)(ts4_word)lbl_8804221C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059A2C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B81820, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35190: call_seq lbl_88B818C8, lbl_88CD4E04, lbl_8803F048, lbl_88CD50D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B818C8_88A35190(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD50D4, (ts4_word)(ts4_word)lbl_8803F048, (ts4_word)(ts4_word)lbl_88CD4E04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B818C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35208: call_seq lbl_88B818E0, lbl_880421A0, lbl_88CD5104, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B818E0_88A35208(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5104, (ts4_word)(ts4_word)lbl_880421A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B818E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35278: call_seq lbl_88B81910, lbl_88CD4E04, lbl_880402E4, lbl_88CD5134, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81910_88A35278(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5134, (ts4_word)(ts4_word)lbl_880402E4, (ts4_word)(ts4_word)lbl_88CD4E04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81910, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A352F0: call_seq lbl_88B81928, lbl_88042184, lbl_88CD5164, lbl_88059A60, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81928_88A352F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5164, (ts4_word)(ts4_word)lbl_88042184, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059A60, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B81928, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35360: call_seq lbl_88B819D0, lbl_88CD4E04, lbl_880402CC, lbl_88CD5194, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B819D0_88A35360(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5194, (ts4_word)(ts4_word)lbl_880402CC, (ts4_word)(ts4_word)lbl_88CD4E04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B819D0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A353D8: call_seq lbl_88B81A18, lbl_88CD4E04, lbl_8803F6B0, lbl_88CD51C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81A18_88A353D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD51C4, (ts4_word)(ts4_word)lbl_8803F6B0, (ts4_word)(ts4_word)lbl_88CD4E04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81A18, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35450: call_seq lbl_88CD4E04, lbl_88045AFC, lbl_88CD51F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD4E04_88A35450(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD51F4, (ts4_word)(ts4_word)lbl_88045AFC, (ts4_word)(ts4_word)lbl_88CD4E04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A354B8: call_seq lbl_88B81AF0, lbl_88CD4E64, lbl_8804589C, lbl_88CD5224, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81AF0_88A354B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5224, (ts4_word)(ts4_word)lbl_8804589C, (ts4_word)(ts4_word)lbl_88CD4E64, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81AF0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35530: call_seq lbl_88B81B20, lbl_88CD4CB4, lbl_88045860, lbl_88CD5254, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81B20_88A35530(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5254, (ts4_word)(ts4_word)lbl_88045860, (ts4_word)(ts4_word)lbl_88CD4CB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81B20, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A355A8: call_seq lbl_88B81B38, lbl_880453D8, lbl_88CD5284, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81B38_88A355A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5284, (ts4_word)(ts4_word)lbl_880453D8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81B38, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35618: call_seq lbl_88B81B68, lbl_88CD51F4, lbl_880403C4, lbl_88CD52B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81B68_88A35618(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD52B4, (ts4_word)(ts4_word)lbl_880403C4, (ts4_word)(ts4_word)lbl_88CD51F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81B68, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35690: call_seq lbl_88B81C00, lbl_88042284, lbl_88CD52E4, lbl_88059A8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81C00_88A35690(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD52E4, (ts4_word)(ts4_word)lbl_88042284, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059A8C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B81C00, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35700: call_seq lbl_88B81C48, lbl_88CD4E04, lbl_88040380, lbl_88CD5314, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81C48_88A35700(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5314, (ts4_word)(ts4_word)lbl_88040380, (ts4_word)(ts4_word)lbl_88CD4E04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81C48, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35778: call_seq lbl_88B81C60, lbl_8803FC48, lbl_88CD5344, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81C60_88A35778(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5344, (ts4_word)(ts4_word)lbl_8803FC48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81C60, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A357E8: call_seq lbl_88059AA0, lbl_88B81CF0, lbl_88CD51F4, lbl_8803FC6C, lbl_88CD5374, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88059AA0_88A357E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5374, (ts4_word)(ts4_word)lbl_8803FC6C, (ts4_word)(ts4_word)lbl_88CD51F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81CF0, (ts4_word)9, (ts4_word)(ts4_word)lbl_88059AA0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35860: call_seq lbl_88B81DC8, lbl_88045020, lbl_88CD53A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81DC8_88A35860(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD53A4, (ts4_word)(ts4_word)lbl_88045020, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81DC8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A358D0: call_seq lbl_88B81E10, lbl_88CD51F4, lbl_88040300, lbl_88CD53D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81E10_88A358D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD53D4, (ts4_word)(ts4_word)lbl_88040300, (ts4_word)(ts4_word)lbl_88CD51F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81E10, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35948: call_seq lbl_88B81E88, lbl_88CD4E04, lbl_880403AC, lbl_88CD5404, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81E88_88A35948(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5404, (ts4_word)(ts4_word)lbl_880403AC, (ts4_word)(ts4_word)lbl_88CD4E04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81E88, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A359C0: call_seq lbl_88B81EB8, lbl_880422F8, lbl_88CD5434, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81EB8_88A359C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5434, (ts4_word)(ts4_word)lbl_880422F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81EB8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35A30: call_seq lbl_88B81F30, lbl_88CD4E04, lbl_8803FA18, lbl_88CD5464, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81F30_88A35A30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5464, (ts4_word)(ts4_word)lbl_8803FA18, (ts4_word)(ts4_word)lbl_88CD4E04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81F30, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35AA8: addr lbl_88B84940, u32@lbl_88B81BFC, u32@0x8 */
void ts4_addr_lbl_88B84940_88A35AA8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B84940) + 8) = (ts4_word)(*(ts4_word *)lbl_88B81BFC);
    return;
}

/* Swing_DLL.xex 0x88A35AC0: call_seq lbl_88B84940, lbl_88CD3304, lbl_8803FBE0, lbl_88CD5494, lbl_88059AFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B84940_88A35AC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5494, (ts4_word)(ts4_word)lbl_8803FBE0, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059AFC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B84940, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35B30: call_seq lbl_88B81F78, lbl_88CD5494, lbl_88045A70, lbl_88CD54C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81F78_88A35B30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD54C4, (ts4_word)(ts4_word)lbl_88045A70, (ts4_word)(ts4_word)lbl_88CD5494, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81F78, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35BA8: call_seq lbl_88B81FA8, lbl_88CD54C4, lbl_8803FCA0, lbl_88CD54F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B81FA8_88A35BA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD54F4, (ts4_word)(ts4_word)lbl_8803FCA0, (ts4_word)(ts4_word)lbl_88CD54C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B81FA8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35C20: call_seq lbl_88B82008, lbl_88CD54C4, lbl_8803FC80, lbl_88CD5524, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82008_88A35C20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5524, (ts4_word)(ts4_word)lbl_8803FC80, (ts4_word)(ts4_word)lbl_88CD54C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82008, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35C98: call_seq lbl_88B82038, lbl_88CD54C4, lbl_8803F9E8, lbl_88CD5554, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82038_88A35C98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5554, (ts4_word)(ts4_word)lbl_8803F9E8, (ts4_word)(ts4_word)lbl_88CD54C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82038, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35D10: call_seq lbl_88B82080, lbl_88042200, lbl_88CD5584, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82080_88A35D10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5584, (ts4_word)(ts4_word)lbl_88042200, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82080, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35D80: call_seq lbl_88B820B0, lbl_88CD4E04, lbl_8804032C, lbl_88CD55B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B820B0_88A35D80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD55B4, (ts4_word)(ts4_word)lbl_8804032C, (ts4_word)(ts4_word)lbl_88CD4E04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B820B0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35DF8: call_seq lbl_88059B10, lbl_88B820C8, lbl_88CD5A34, lbl_8803F6CC, lbl_88CD55E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88059B10_88A35DF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD55E4, (ts4_word)(ts4_word)lbl_8803F6CC, (ts4_word)(ts4_word)lbl_88CD5A34, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B820C8, (ts4_word)16, (ts4_word)(ts4_word)lbl_88059B10, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35E70: call_seq lbl_88CD3304, lbl_88045AA8, lbl_88CD5614, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3304_88A35E70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5614, (ts4_word)(ts4_word)lbl_88045AA8, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35ED8: call_seq lbl_88CD56A4, lbl_880457FC, lbl_88CD5644, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD56A4_88A35ED8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5644, (ts4_word)(ts4_word)lbl_880457FC, (ts4_word)(ts4_word)lbl_88CD56A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35F40: call_seq lbl_88CD55E4, lbl_880455E0, lbl_88CD5674, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD55E4_88A35F40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5674, (ts4_word)(ts4_word)lbl_880455E0, (ts4_word)(ts4_word)lbl_88CD55E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A35FA8: call_seq lbl_88059B74, lbl_88CD5614, lbl_880459F8, lbl_88CD56A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88059B74_88A35FA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD56A4, (ts4_word)(ts4_word)lbl_880459F8, (ts4_word)(ts4_word)lbl_88CD5614, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059B74, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36010: call_seq lbl_88B8224C, lbl_88045070, lbl_88CD56D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8224C_88A36010(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD56D4, (ts4_word)(ts4_word)lbl_88045070, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8224C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36080: call_seq lbl_88B82280, lbl_88CD56A4, lbl_88041DE0, lbl_88CD5704, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82280_88A36080(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5704, (ts4_word)(ts4_word)lbl_88041DE0, (ts4_word)(ts4_word)lbl_88CD56A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82280, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A360F8: addr lbl_88B84958, u32@lbl_88B8227C, u32@0x8 */
void ts4_addr_lbl_88B84958_88A360F8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B84958) + 8) = (ts4_word)(*(ts4_word *)lbl_88B8227C);
    return;
}

/* Swing_DLL.xex 0x88A36110: call_seq lbl_88B84958, lbl_88CD3304, lbl_8803F5D4, lbl_88CD5734, lbl_88059BD8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B84958_88A36110(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5734, (ts4_word)(ts4_word)lbl_8803F5D4, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059BD8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B84958, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36188: call_seq lbl_88CD5734, lbl_880402B0, lbl_88CD5764, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD5734_88A36188(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5764, (ts4_word)(ts4_word)lbl_880402B0, (ts4_word)(ts4_word)lbl_88CD5734, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A361F0: call_seq lbl_88CD57C4, lbl_88040E04, lbl_88CD5794, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD57C4_88A361F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5794, (ts4_word)(ts4_word)lbl_88040E04, (ts4_word)(ts4_word)lbl_88CD57C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36258: call_seq lbl_88B82328, lbl_88CD5734, lbl_8803EFA8, lbl_88CD57C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82328_88A36258(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD57C4, (ts4_word)(ts4_word)lbl_8803EFA8, (ts4_word)(ts4_word)lbl_88CD5734, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82328, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A362D0: call_seq lbl_88CD57C4, lbl_880456EC, lbl_88CD57F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD57C4_88A362D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD57F4, (ts4_word)(ts4_word)lbl_880456EC, (ts4_word)(ts4_word)lbl_88CD57C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36338: call_seq lbl_88CD5734, lbl_880402A0, lbl_88CD5824, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD5734_88A36338(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5824, (ts4_word)(ts4_word)lbl_880402A0, (ts4_word)(ts4_word)lbl_88CD5734, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A363A0: call_seq lbl_88CD5764, lbl_88040E18, lbl_88CD5854, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD5764_88A363A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5854, (ts4_word)(ts4_word)lbl_88040E18, (ts4_word)(ts4_word)lbl_88CD5764, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36408: call_seq lbl_88CD5824, lbl_88040E68, lbl_88CD5884, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD5824_88A36408(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5884, (ts4_word)(ts4_word)lbl_88040E68, (ts4_word)(ts4_word)lbl_88CD5824, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36470: call_seq lbl_88CD5764, lbl_88040DB0, lbl_88CD58B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD5764_88A36470(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD58B4, (ts4_word)(ts4_word)lbl_88040DB0, (ts4_word)(ts4_word)lbl_88CD5764, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A364D8: call_seq lbl_88B82358, lbl_88CD5944, lbl_8803F6D8, lbl_88CD58E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82358_88A364D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD58E4, (ts4_word)(ts4_word)lbl_8803F6D8, (ts4_word)(ts4_word)lbl_88CD5944, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82358, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36550: call_seq lbl_88B82388, lbl_88CD5974, lbl_88045914, lbl_88CD5914, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82388_88A36550(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5914, (ts4_word)(ts4_word)lbl_88045914, (ts4_word)(ts4_word)lbl_88CD5974, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82388, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A365C8: call_seq lbl_88B823A0, lbl_88CD5A34, lbl_88047070, lbl_88CD5944, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B823A0_88A365C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5944, (ts4_word)(ts4_word)lbl_88047070, (ts4_word)(ts4_word)lbl_88CD5A34, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B823A0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36640: call_seq lbl_88B823D0, lbl_88CD5944, lbl_880402BC, lbl_88CD5974, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B823D0_88A36640(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5974, (ts4_word)(ts4_word)lbl_880402BC, (ts4_word)(ts4_word)lbl_88CD5944, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B823D0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A366B8: call_seq lbl_88B823E8, lbl_88CD5974, lbl_88045580, lbl_88CD59A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B823E8_88A366B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD59A4, (ts4_word)(ts4_word)lbl_88045580, (ts4_word)(ts4_word)lbl_88CD5974, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B823E8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36730: call_seq lbl_88059BEC, lbl_88B82400, lbl_88CD3304, lbl_8803F660, lbl_88CD59D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88059BEC_88A36730(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD59D4, (ts4_word)(ts4_word)lbl_8803F660, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82400, (ts4_word)7, (ts4_word)(ts4_word)lbl_88059BEC, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A367A8: get u32@lbl_88B824B4, lbl_88B849D0, u32@lbl_88B824B0, u32@lbl_88B824AC, u32@0x50, u32@0x110 */
void ts4_get_u32_lbl_88B824B4_88A367A8(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88B824B4;
    t2 = *(ts4_word *)lbl_88B824B0;
    t3 = *(ts4_word *)lbl_88B824AC;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B849D0) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B849D0) + 272) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B849D0) + 560) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x88A36850: call_seq lbl_88B824C0, lbl_88CD3304, lbl_8803F084, lbl_88CD5A34, lbl_88059DE8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B824C0_88A36850(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5A34, (ts4_word)(ts4_word)lbl_8803F084, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059DE8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B824C0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A368C8: call_seq lbl_88B82550, lbl_88CD3304, lbl_8804707C, lbl_88CD5A64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82550_88A368C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5A64, (ts4_word)(ts4_word)lbl_8804707C, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82550, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36940: call_seq lbl_88B82568, lbl_88CD3DB4, lbl_88044F38, lbl_88CD5A94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82568_88A36940(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5A94, (ts4_word)(ts4_word)lbl_88044F38, (ts4_word)(ts4_word)lbl_88CD3DB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82568, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A369B8: call_seq lbl_88B82580, lbl_88042E20, lbl_88CD5AC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82580_88A369B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5AC4, (ts4_word)(ts4_word)lbl_88042E20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82580, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36A28: call_seq lbl_88B82598, lbl_88CD3304, lbl_8803EFD0, lbl_88CD5AF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82598_88A36A28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5AF4, (ts4_word)(ts4_word)lbl_8803EFD0, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82598, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36AA0: call_seq lbl_88B825E0, lbl_88044F10, lbl_88CD5B24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B825E0_88A36AA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5B24, (ts4_word)(ts4_word)lbl_88044F10, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B825E0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36B10: call_seq lbl_88B825F8, lbl_88CD3304, lbl_88044F90, lbl_88CD5B54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B825F8_88A36B10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5B54, (ts4_word)(ts4_word)lbl_88044F90, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B825F8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36B88: call_seq lbl_88B82630, lbl_880421E0, lbl_88CD5B84, lbl_88059E40, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82630_88A36B88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5B84, (ts4_word)(ts4_word)lbl_880421E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059E40, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B82630, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36BF8: call_seq lbl_88B826D8, lbl_88CD4E04, lbl_8803F030, lbl_88CD5BB4, lbl_88059E14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B826D8_88A36BF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5BB4, (ts4_word)(ts4_word)lbl_8803F030, (ts4_word)(ts4_word)lbl_88CD4E04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059E14, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B826D8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36C68: call_seq lbl_88B826F0, lbl_880421C4, lbl_88CD5BE4, lbl_88059E6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B826F0_88A36C68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5BE4, (ts4_word)(ts4_word)lbl_880421C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059E6C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B826F0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36CD8: call_seq lbl_88B82750, lbl_88CD4E04, lbl_88040318, lbl_88CD5C14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82750_88A36CD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5C14, (ts4_word)(ts4_word)lbl_88040318, (ts4_word)(ts4_word)lbl_88CD4E04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82750, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36D50: call_seq lbl_88B82768, lbl_88CD4D14, lbl_88044EA8, lbl_88CD5C44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82768_88A36D50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5C44, (ts4_word)(ts4_word)lbl_88044EA8, (ts4_word)(ts4_word)lbl_88CD4D14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82768, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36DC8: call_seq lbl_88B827B0, lbl_88CD4D14, lbl_88044E64, lbl_88CD5C74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B827B0_88A36DC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5C74, (ts4_word)(ts4_word)lbl_88044E64, (ts4_word)(ts4_word)lbl_88CD4D14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B827B0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36E40: call_seq lbl_88B82810, lbl_88CD4D44, lbl_88044DD0, lbl_88CD5CA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82810_88A36E40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5CA4, (ts4_word)(ts4_word)lbl_88044DD0, (ts4_word)(ts4_word)lbl_88CD4D44, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82810, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36EB8: call_seq lbl_88B82870, lbl_88CD4D44, lbl_88044CD0, lbl_88CD5CD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82870_88A36EB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5CD4, (ts4_word)(ts4_word)lbl_88044CD0, (ts4_word)(ts4_word)lbl_88CD4D44, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82870, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36F30: call_seq lbl_88B828D0, lbl_88CD4D14, lbl_88044BD4, lbl_88CD5D04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B828D0_88A36F30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5D04, (ts4_word)(ts4_word)lbl_88044BD4, (ts4_word)(ts4_word)lbl_88CD4D14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B828D0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A36FA8: call_seq lbl_88B82990, lbl_88059E80, lbl_8803F094, lbl_88CD5D34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82990_88A36FA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5D34, (ts4_word)(ts4_word)lbl_8803F094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82990, (ts4_word)19, (ts4_word)(ts4_word)lbl_88059E80, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37020: call_seq lbl_88B82B58, lbl_88CD3E74, lbl_8803F0AC, lbl_88CD5D64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82B58_88A37020(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5D64, (ts4_word)(ts4_word)lbl_8803F0AC, (ts4_word)(ts4_word)lbl_88CD3E74, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82B58, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37098: call_seq lbl_88B82B70, lbl_88CD3E74, lbl_88044E30, lbl_88CD5D94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82B70_88A37098(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5D94, (ts4_word)(ts4_word)lbl_88044E30, (ts4_word)(ts4_word)lbl_88CD3E74, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82B70, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37110: call_seq lbl_88B82B88, lbl_88CD3E74, lbl_88044DF8, lbl_88CD5DC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82B88_88A37110(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5DC4, (ts4_word)(ts4_word)lbl_88044DF8, (ts4_word)(ts4_word)lbl_88CD3E74, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82B88, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37188: call_seq lbl_88B82BB8, lbl_88044B54, lbl_88CD5DF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82BB8_88A37188(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5DF4, (ts4_word)(ts4_word)lbl_88044B54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82BB8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A371F8: call_seq lbl_88B82BE8, lbl_88CD3E74, lbl_88044D8C, lbl_88CD5E24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82BE8_88A371F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5E24, (ts4_word)(ts4_word)lbl_88044D8C, (ts4_word)(ts4_word)lbl_88CD3E74, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82BE8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37270: call_seq lbl_88B82C00, lbl_88044A90, lbl_88CD5E54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82C00_88A37270(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5E54, (ts4_word)(ts4_word)lbl_88044A90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82C00, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A372E0: call_seq lbl_88B82C30, lbl_88044ACC, lbl_88CD5E84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82C30_88A372E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5E84, (ts4_word)(ts4_word)lbl_88044ACC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82C30, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37350: call_seq lbl_88B82C78, lbl_88CD3304, lbl_88044CFC, lbl_88CD5EB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82C78_88A37350(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5EB4, (ts4_word)(ts4_word)lbl_88044CFC, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82C78, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A373C8: call_seq lbl_88B82CC0, lbl_88CD4D44, lbl_8804705C, lbl_88CD5EE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82CC0_88A373C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5EE4, (ts4_word)(ts4_word)lbl_8804705C, (ts4_word)(ts4_word)lbl_88CD4D44, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82CC0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37440: call_seq lbl_88B82D50, lbl_88044A58, lbl_88CD5F14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82D50_88A37440(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5F14, (ts4_word)(ts4_word)lbl_88044A58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82D50, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A374B0: call_seq lbl_88B82D98, lbl_88044B0C, lbl_88CD5F44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82D98_88A374B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5F44, (ts4_word)(ts4_word)lbl_88044B0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82D98, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37520: call_seq lbl_88B82DC8, lbl_88044B94, lbl_88CD5F74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82DC8_88A37520(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5F74, (ts4_word)(ts4_word)lbl_88044B94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82DC8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37590: call_seq lbl_88B82DF8, lbl_88CD3304, lbl_88044D60, lbl_88CD5FA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82DF8_88A37590(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5FA4, (ts4_word)(ts4_word)lbl_88044D60, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82DF8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37608: call_seq lbl_88B82E28, lbl_88CD3304, lbl_88044C84, lbl_88CD5FD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82E28_88A37608(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD5FD4, (ts4_word)(ts4_word)lbl_88044C84, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82E28, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37680: call_seq lbl_88B82E40, lbl_88CD3304, lbl_88044C48, lbl_88CD6004, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82E40_88A37680(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6004, (ts4_word)(ts4_word)lbl_88044C48, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82E40, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A376F8: call_seq lbl_88B82E58, lbl_88044A08, lbl_88CD6034, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82E58_88A376F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6034, (ts4_word)(ts4_word)lbl_88044A08, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82E58, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37768: call_seq lbl_88B82E88, lbl_88CD3304, lbl_88044C08, lbl_88CD6064, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82E88_88A37768(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6064, (ts4_word)(ts4_word)lbl_88044C08, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82E88, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A377E0: call_seq lbl_88B82EA0, lbl_88040668, lbl_88CD6094, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82EA0_88A377E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6094, (ts4_word)(ts4_word)lbl_88040668, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82EA0, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37850: call_seq lbl_88B82F90, lbl_88CD3304, lbl_88040658, lbl_88CD60C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B82F90_88A37850(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD60C4, (ts4_word)(ts4_word)lbl_88040658, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B82F90, (ts4_word)18, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A378C8: call_seq lbl_88B83140, lbl_8803F5F4, lbl_88CD60F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B83140_88A378C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD60F4, (ts4_word)(ts4_word)lbl_8803F5F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B83140, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37938: call_seq lbl_88B832D8, lbl_88CD4D44, lbl_8803F64C, lbl_88CD6124, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B832D8_88A37938(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6124, (ts4_word)(ts4_word)lbl_8803F64C, (ts4_word)(ts4_word)lbl_88CD4D44, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B832D8, (ts4_word)25, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A379B0: call_seq lbl_88CD3304, lbl_8804494C, lbl_88CD6154, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3304_88A379B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6154, (ts4_word)(ts4_word)lbl_8804494C, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37A18: call_seq lbl_88B83530, lbl_88CD6154, lbl_88044700, lbl_88CD6184, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B83530_88A37A18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6184, (ts4_word)(ts4_word)lbl_88044700, (ts4_word)(ts4_word)lbl_88CD6154, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B83530, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37A90: call_seq lbl_88CD3304, lbl_88044924, lbl_88CD61B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3304_88A37A90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD61B4, (ts4_word)(ts4_word)lbl_88044924, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37AF8: call_seq lbl_88B835A8, lbl_88044438, lbl_88CD61E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B835A8_88A37AF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD61E4, (ts4_word)(ts4_word)lbl_88044438, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B835A8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37B68: call_seq lbl_88B835F0, lbl_88CD61B4, lbl_88044680, lbl_88CD6214, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B835F0_88A37B68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6214, (ts4_word)(ts4_word)lbl_88044680, (ts4_word)(ts4_word)lbl_88CD61B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B835F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37BE0: call_seq lbl_88CD3304, lbl_880448C8, lbl_88CD6244, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3304_88A37BE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6244, (ts4_word)(ts4_word)lbl_880448C8, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37C48: call_seq lbl_88CD3304, lbl_880448FC, lbl_88CD6274, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3304_88A37C48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6274, (ts4_word)(ts4_word)lbl_880448FC, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37CB0: call_seq lbl_88B83620, lbl_88CD6244, lbl_88044524, lbl_88CD62A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B83620_88A37CB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD62A4, (ts4_word)(ts4_word)lbl_88044524, (ts4_word)(ts4_word)lbl_88CD6244, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B83620, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37D28: call_seq lbl_88B83680, lbl_88CD6274, lbl_880446BC, lbl_88CD62D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B83680_88A37D28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD62D4, (ts4_word)(ts4_word)lbl_880446BC, (ts4_word)(ts4_word)lbl_88CD6274, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B83680, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37DA0: call_seq lbl_88CD3304, lbl_8804489C, lbl_88CD6304, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3304_88A37DA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6304, (ts4_word)(ts4_word)lbl_8804489C, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37E08: call_seq lbl_88B836E0, lbl_88CD6304, lbl_88044650, lbl_88CD6334, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B836E0_88A37E08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6334, (ts4_word)(ts4_word)lbl_88044650, (ts4_word)(ts4_word)lbl_88CD6304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B836E0, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37E80: call_seq lbl_88B837D0, lbl_88044324, lbl_88CD6364, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B837D0_88A37E80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6364, (ts4_word)(ts4_word)lbl_88044324, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B837D0, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37EF0: call_seq lbl_88B838C0, lbl_88044370, lbl_88CD6394, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B838C0_88A37EF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6394, (ts4_word)(ts4_word)lbl_88044370, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B838C0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37F60: call_seq lbl_88B83908, lbl_8803F610, lbl_88CD63C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B83908_88A37F60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD63C4, (ts4_word)(ts4_word)lbl_8803F610, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B83908, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A37FD0: call_seq lbl_88B839E0, lbl_8803F634, lbl_88CD63F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B839E0_88A37FD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD63F4, (ts4_word)(ts4_word)lbl_8803F634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B839E0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38040: call_seq lbl_88CD3304, lbl_88044874, lbl_88CD6424, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3304_88A38040(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6424, (ts4_word)(ts4_word)lbl_88044874, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A380A8: call_seq lbl_88B839F8, lbl_88CD6424, lbl_8804461C, lbl_88CD6454, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B839F8_88A380A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6454, (ts4_word)(ts4_word)lbl_8804461C, (ts4_word)(ts4_word)lbl_88CD6424, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B839F8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38120: call_seq lbl_88B83A40, lbl_88044268, lbl_88CD6484, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B83A40_88A38120(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6484, (ts4_word)(ts4_word)lbl_88044268, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B83A40, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38190: call_seq lbl_88B83A88, lbl_88CD3304, lbl_8804484C, lbl_88CD64B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B83A88_88A38190(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD64B4, (ts4_word)(ts4_word)lbl_8804484C, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B83A88, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38208: call_seq lbl_88B83AA0, lbl_880443CC, lbl_88CD64E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B83AA0_88A38208(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD64E4, (ts4_word)(ts4_word)lbl_880443CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B83AA0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38278: call_seq lbl_88B83AE8, lbl_88CD64B4, lbl_880445E4, lbl_88CD6514, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B83AE8_88A38278(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6514, (ts4_word)(ts4_word)lbl_880445E4, (ts4_word)(ts4_word)lbl_88CD64B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B83AE8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A382F0: call_seq lbl_88CD3304, lbl_8804481C, lbl_88CD6544, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3304_88A382F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6544, (ts4_word)(ts4_word)lbl_8804481C, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38358: call_seq lbl_88B83B00, lbl_88CD6544, lbl_880445A8, lbl_88CD6574, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B83B00_88A38358(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6574, (ts4_word)(ts4_word)lbl_880445A8, (ts4_word)(ts4_word)lbl_88CD6544, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B83B00, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A383D0: call_seq lbl_88B83BA8, lbl_8804449C, lbl_88CD65A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B83BA8_88A383D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD65A4, (ts4_word)(ts4_word)lbl_8804449C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B83BA8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38440: call_seq lbl_88B83BD8, lbl_88CD3304, lbl_88044744, lbl_88CD65D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B83BD8_88A38440(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD65D4, (ts4_word)(ts4_word)lbl_88044744, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B83BD8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A384B8: call_seq lbl_88B83C20, lbl_88CD3304, lbl_88044758, lbl_88CD6604, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B83C20_88A384B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6604, (ts4_word)(ts4_word)lbl_88044758, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B83C20, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38530: call_seq lbl_88CD3304, lbl_880447EC, lbl_88CD6634, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3304_88A38530(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6634, (ts4_word)(ts4_word)lbl_880447EC, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38598: call_seq lbl_88B83C68, lbl_88CD6634, lbl_88044568, lbl_88CD6664, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B83C68_88A38598(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6664, (ts4_word)(ts4_word)lbl_88044568, (ts4_word)(ts4_word)lbl_88CD6634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B83C68, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38610: call_seq lbl_88B83CB0, lbl_88CD3304, lbl_880447B8, lbl_88CD6694, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B83CB0_88A38610(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD6694, (ts4_word)(ts4_word)lbl_880447B8, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B83CB0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38688: call_seq lbl_88B83CC8, lbl_88CD3304, lbl_88044784, lbl_88CD66C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B83CC8_88A38688(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD66C4, (ts4_word)(ts4_word)lbl_88044784, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B83CC8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38700: call_seq lbl_88B83CE0, lbl_88CD6694, lbl_880444CC, lbl_88CD66F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B83CE0_88A38700(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD66F4, (ts4_word)(ts4_word)lbl_880444CC, (ts4_word)(ts4_word)lbl_88CD6694, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B83CE0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38778: call_seq lbl_88058C60, lbl_88059ED8, lbl_88CD6724, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF5F0, fn_88563470 */
ts4_word ts4_call_seq_lbl_88058C60_88A38778(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CD6724, (ts4_word)(ts4_word)lbl_88059ED8, (ts4_word)4, (ts4_word)(ts4_word)lbl_88058C60);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF5F0);
    return t2;
}

/* Swing_DLL.xex 0x88A387C0: call_seq lbl_88B84C58, lbl_88046C94, lbl_88CD673C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B84C58_88A387C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD673C, (ts4_word)(ts4_word)lbl_88046C94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B84C58, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38830: addr lbl_88B8B270, u32@lbl_88B84CD0, u32@0x38 */
void ts4_addr_lbl_88B8B270_88A38830(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8B270) + 56) = (ts4_word)(*(ts4_word *)lbl_88B84CD0);
    return;
}

/* Swing_DLL.xex 0x88A38848: call_seq lbl_8805A56C, lbl_88B8B270, lbl_8803EF04, lbl_88CD676C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805A56C_88A38848(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD676C, (ts4_word)(ts4_word)lbl_8803EF04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805A56C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B8B270, (ts4_word)3, (ts4_word)((ts4_word)lbl_8805A56C + 20), (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A388C0: call_seq lbl_88B84CD4, lbl_88046C78, lbl_88CD679C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B84CD4_88A388C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD679C, (ts4_word)(ts4_word)lbl_88046C78, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B84CD4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38930: call_seq lbl_88B84D04, lbl_8803EC6C, lbl_88CD67CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B84D04_88A38930(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD67CC, (ts4_word)(ts4_word)lbl_8803EC6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B84D04, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A389A0: addr lbl_88B8B2B8, u32@lbl_88B84D34, u32@0x8 */
void ts4_addr_lbl_88B8B2B8_88A389A0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8B2B8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B84D34);
    return;
}

/* Swing_DLL.xex 0x88A389B8: call_seq lbl_88B8B2B8, lbl_88CD73FC, lbl_8803EE48, lbl_88CD67FC, lbl_8805A5B0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8B2B8_88A389B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD67FC, (ts4_word)(ts4_word)lbl_8803EE48, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805A5B0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B8B2B8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38A30: call_seq lbl_88B84D38, lbl_88040040, lbl_88CD682C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B84D38_88A38A30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD682C, (ts4_word)(ts4_word)lbl_88040040, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B84D38, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38AA0: call_seq lbl_88B84DC8, lbl_88CD67FC, lbl_8803ECD0, lbl_88CD685C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B84DC8_88A38AA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD685C, (ts4_word)(ts4_word)lbl_8803ECD0, (ts4_word)(ts4_word)lbl_88CD67FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B84DC8, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38B18: call_seq lbl_88B84EE8, lbl_88CD67FC, lbl_8803ECB0, lbl_88CD688C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B84EE8_88A38B18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD688C, (ts4_word)(ts4_word)lbl_8803ECB0, (ts4_word)(ts4_word)lbl_88CD67FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B84EE8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38B90: call_seq lbl_88B84F00, lbl_88040078, lbl_88CD68BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B84F00_88A38B90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD68BC, (ts4_word)(ts4_word)lbl_88040078, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B84F00, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38C00: call_seq lbl_88B84F90, lbl_88CD67FC, lbl_8803EC94, lbl_88CD68EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B84F90_88A38C00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD68EC, (ts4_word)(ts4_word)lbl_8803EC94, (ts4_word)(ts4_word)lbl_88CD67FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B84F90, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38C78: call_seq lbl_88B85080, lbl_88046C60, lbl_88CD691C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85080_88A38C78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD691C, (ts4_word)(ts4_word)lbl_88046C60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85080, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A38CE8: call_seq lbl_88B85098, lbl_8803EE88, lbl_88CD694C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B85098_88A38CE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD694C, (ts4_word)(ts4_word)lbl_8803EE88, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B85098, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}
