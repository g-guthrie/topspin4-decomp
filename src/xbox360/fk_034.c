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

extern char ts4_addr_lbl_8803A308_88AFF530[];
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
extern char lbl_8803EE48[];
extern char lbl_8803EE7C[];
extern char lbl_8803EE88[];
extern char lbl_8803EEE8[];
extern char lbl_8803EEFC[];
extern char lbl_8803EF04[];
extern char lbl_8803EF90[];
extern char lbl_8803EFA8[];
extern char lbl_8803EFD0[];
extern char lbl_8803F030[];
extern char lbl_8803F048[];
extern char lbl_8803F064[];
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
extern char lbl_8803F670[];
extern char lbl_8803F690[];
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
extern char lbl_8803FA04[];
extern char lbl_8803FA18[];
extern char lbl_8803FBE0[];
extern char lbl_8803FC08[];
extern char lbl_8803FC24[];
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
extern char lbl_88041DE0[];
extern char lbl_88042170[];
extern char lbl_880422F8[];
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
extern char lbl_880448FC[];
extern char lbl_88044924[];
extern char lbl_8804494C[];
extern char lbl_88044A08[];
extern char lbl_88044A58[];
extern char lbl_88044B0C[];
extern char lbl_88044B54[];
extern char lbl_88044B94[];
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
extern char lbl_88045AA8[];
extern char lbl_88045AFC[];
extern char lbl_88045B24[];
extern char lbl_88046C00[];
extern char lbl_88046C24[];
extern char lbl_88046C48[];
extern char lbl_88046C60[];
extern char lbl_88046C78[];
extern char lbl_88046C94[];
extern char lbl_8804705C[];
extern char lbl_88047070[];
extern char lbl_8804707C[];
extern char lbl_8804E4DC[];
extern char lbl_8804E4F4[];
extern char lbl_8804E50C[];
extern char lbl_8804E524[];
extern char lbl_8804E53C[];
extern char lbl_8804E560[];
extern char lbl_8804E9F8[];
extern char lbl_8804EE8C[];
extern char lbl_8804EF60[];
extern char lbl_8804EFBC[];
extern char lbl_8804EFF8[];
extern char lbl_8804F03C[];
extern char lbl_8804F050[];
extern char lbl_8804F0BC[];
extern char lbl_8804F120[];
extern char lbl_8804F14C[];
extern char lbl_8804F328[];
extern char lbl_8804F33C[];
extern char lbl_8804F368[];
extern char lbl_8804F85C[];
extern char lbl_8804F878[];
extern char lbl_8804F9E8[];
extern char lbl_8804FA3C[];
extern char lbl_8804FA60[];
extern char lbl_8804FAA4[];
extern char lbl_88B4D82C[];
extern char lbl_88B4DD40[];
extern char lbl_88B4DD70[];
extern char lbl_88B4DD88[];
extern char lbl_88B4DDA0[];
extern char lbl_88B4DDEC[];
extern char lbl_88B4DE04[];
extern char lbl_88B4DE08[];
extern char lbl_88B4DE70[];
extern char lbl_88B4DE88[];
extern char lbl_88B4DEB8[];
extern char lbl_88B4DF00[];
extern char lbl_88B4DF30[];
extern char lbl_88B4DF60[];
extern char lbl_88B4DFC0[];
extern char lbl_88B4E008[];
extern char lbl_88B4E098[];
extern char lbl_88B4E110[];
extern char lbl_88B4E118[];
extern char lbl_88B4E160[];
extern char lbl_88B4E1C0[];
extern char lbl_88B4E208[];
extern char lbl_88B4E250[];
extern char lbl_88B4E2F8[];
extern char lbl_88B4E340[];
extern char lbl_88B4E370[];
extern char lbl_88B4E400[];
extern char lbl_88B4E490[];
extern char lbl_88B4E550[];
extern char lbl_88B4E580[];
extern char lbl_88B4E598[];
extern char lbl_88B4E5C8[];
extern char lbl_88B4E640[];
extern char lbl_88B4E670[];
extern char lbl_88B4E6B8[];
extern char lbl_88B4E700[];
extern char lbl_88B4E730[];
extern char lbl_88B4E7C0[];
extern char lbl_88B4E850[];
extern char lbl_88B4E8C8[];
extern char lbl_88B4E910[];
extern char lbl_88B4E970[];
extern char lbl_88B4E988[];
extern char lbl_88B4EA00[];
extern char lbl_88B4EA30[];
extern char lbl_88B4EAA8[];
extern char lbl_88B4EB08[];
extern char lbl_88B4EB80[];
extern char lbl_88B4EC10[];
extern char lbl_88B4EDC0[];
extern char lbl_88B4EDF0[];
extern char lbl_88B4EE9C[];
extern char lbl_88B4EEB4[];
extern char lbl_88B4EECC[];
extern char lbl_88B4EF00[];
extern char lbl_88B4EFA8[];
extern char lbl_88B4EFD8[];
extern char lbl_88B4EFF0[];
extern char lbl_88B4F020[];
extern char lbl_88B4F038[];
extern char lbl_88B4F050[];
extern char lbl_88B4F080[];
extern char lbl_88B4F114[];
extern char lbl_88B4F118[];
extern char lbl_88B4F11C[];
extern char lbl_88B4F128[];
extern char lbl_88B4F1A0[];
extern char lbl_88B4F1B8[];
extern char lbl_88B4F1D0[];
extern char lbl_88B4F1E8[];
extern char lbl_88B4F230[];
extern char lbl_88B4F248[];
extern char lbl_88B4F278[];
extern char lbl_88B4F2F0[];
extern char lbl_88B4F338[];
extern char lbl_88B4F380[];
extern char lbl_88B4F458[];
extern char lbl_88B4F488[];
extern char lbl_88B4F4B8[];
extern char lbl_88B4F590[];
extern char lbl_88B4F5D8[];
extern char lbl_88B4F638[];
extern char lbl_88B4F698[];
extern char lbl_88B4F6F8[];
extern char lbl_88B4F7B8[];
extern char lbl_88B4F950[];
extern char lbl_88B4F968[];
extern char lbl_88B4F980[];
extern char lbl_88B4F9B0[];
extern char lbl_88B4F9E0[];
extern char lbl_88B4F9F8[];
extern char lbl_88B4FA88[];
extern char lbl_88B4FAD0[];
extern char lbl_88B4FB00[];
extern char lbl_88B4FB30[];
extern char lbl_88B4FB60[];
extern char lbl_88B4FB78[];
extern char lbl_88B4FB90[];
extern char lbl_88B4FBC0[];
extern char lbl_88B4FBD8[];
extern char lbl_88B4FCB0[];
extern char lbl_88B4FE60[];
extern char lbl_88B4FFF8[];
extern char lbl_88B50268[];
extern char lbl_88B502E0[];
extern char lbl_88B50328[];
extern char lbl_88B50358[];
extern char lbl_88B503B8[];
extern char lbl_88B50418[];
extern char lbl_88B50508[];
extern char lbl_88B505F8[];
extern char lbl_88B50640[];
extern char lbl_88B50718[];
extern char lbl_88B50730[];
extern char lbl_88B50778[];
extern char lbl_88B507C0[];
extern char lbl_88B507D8[];
extern char lbl_88B50820[];
extern char lbl_88B50838[];
extern char lbl_88B508E0[];
extern char lbl_88B50910[];
extern char lbl_88B50958[];
extern char lbl_88B509A0[];
extern char lbl_88B509E8[];
extern char lbl_88B50A00[];
extern char lbl_88B50A18[];
extern char lbl_88B50EF8[];
extern char lbl_88B50F40[];
extern char lbl_88B51000[];
extern char lbl_88B51060[];
extern char lbl_88B512E8[];
extern char lbl_88B51360[];
extern char lbl_88B51364[];
extern char lbl_88B51394[];
extern char lbl_88B513C8[];
extern char lbl_88B51428[];
extern char lbl_88B51488[];
extern char lbl_88B51518[];
extern char lbl_88B51530[];
extern char lbl_88B51590[];
extern char lbl_88B51638[];
extern char lbl_88B51650[];
extern char lbl_88B516B0[];
extern char lbl_88B516C8[];
extern char lbl_88B51710[];
extern char lbl_88B517A0[];
extern char lbl_88B51830[];
extern char lbl_88B51890[];
extern char lbl_88B518C0[];
extern char lbl_88B51908[];
extern char lbl_88B51968[];
extern char lbl_88B51998[];
extern char lbl_88B51A40[];
extern char lbl_88B51A70[];
extern char lbl_88B51AA0[];
extern char lbl_88B51AAC[];
extern char lbl_88B51ADC[];
extern char lbl_88B51AF4[];
extern char lbl_88B51AF8[];
extern char lbl_88B51B28[];
extern char lbl_88B51B5C[];
extern char lbl_88B51B60[];
extern char lbl_88B51BC0[];
extern char lbl_88B51C80[];
extern char lbl_88B51C98[];
extern char lbl_88B51D10[];
extern char lbl_88B51D28[];
extern char lbl_88B51D58[];
extern char lbl_88B51D88[];
extern char lbl_88B51DB8[];
extern char lbl_88B51DD0[];
extern char lbl_88B51E00[];
extern char lbl_88B51E18[];
extern char lbl_88B56190[];
extern char lbl_88B561D8[];
extern char lbl_88B56298[];
extern char lbl_88B56328[];
extern char lbl_88B56358[];
extern char lbl_88B56388[];
extern char lbl_88CB5FF4[];
extern char lbl_88CB6A14[];
extern char lbl_88CB6AD4[];
extern char lbl_88CB73A4[];
extern char lbl_88CB7404[];
extern char lbl_88CB7434[];
extern char lbl_88CB7464[];
extern char lbl_88CB7494[];
extern char lbl_88CB74C4[];
extern char lbl_88CB74F4[];
extern char lbl_88CB7524[];
extern char lbl_88CB7554[];
extern char lbl_88CB7584[];
extern char lbl_88CB75B4[];
extern char lbl_88CB75E4[];
extern char lbl_88CB7614[];
extern char lbl_88CB7644[];
extern char lbl_88CB7674[];
extern char lbl_88CB76A4[];
extern char lbl_88CB76D4[];
extern char lbl_88CB7704[];
extern char lbl_88CB7734[];
extern char lbl_88CB7764[];
extern char lbl_88CB7794[];
extern char lbl_88CB77C4[];
extern char lbl_88CB77F4[];
extern char lbl_88CB7824[];
extern char lbl_88CB7854[];
extern char lbl_88CB7884[];
extern char lbl_88CB78B4[];
extern char lbl_88CB78E4[];
extern char lbl_88CB7914[];
extern char lbl_88CB7944[];
extern char lbl_88CB7974[];
extern char lbl_88CB79A4[];
extern char lbl_88CB79D4[];
extern char lbl_88CB7A04[];
extern char lbl_88CB7A34[];
extern char lbl_88CB7A64[];
extern char lbl_88CB7A94[];
extern char lbl_88CB7AC4[];
extern char lbl_88CB7AF4[];
extern char lbl_88CB7B24[];
extern char lbl_88CB7B54[];
extern char lbl_88CB7B84[];
extern char lbl_88CB7BB4[];
extern char lbl_88CB7BE4[];
extern char lbl_88CB7C14[];
extern char lbl_88CB7C44[];
extern char lbl_88CB7C74[];
extern char lbl_88CB7CA4[];
extern char lbl_88CB7CD4[];
extern char lbl_88CB7D04[];
extern char lbl_88CB7D34[];
extern char lbl_88CB7D64[];
extern char lbl_88CB7D94[];
extern char lbl_88CB7DC4[];
extern char lbl_88CB7DF4[];
extern char lbl_88CB7E24[];
extern char lbl_88CB7E54[];
extern char lbl_88CB7E84[];
extern char lbl_88CB7EB4[];
extern char lbl_88CB7EE4[];
extern char lbl_88CB7F14[];
extern char lbl_88CB7F44[];
extern char lbl_88CB7F74[];
extern char lbl_88CB7FA4[];
extern char lbl_88CB7FD4[];
extern char lbl_88CB8004[];
extern char lbl_88CB8034[];
extern char lbl_88CB8064[];
extern char lbl_88CB8094[];
extern char lbl_88CB80C4[];
extern char lbl_88CB80F4[];
extern char lbl_88CB8124[];
extern char lbl_88CB8154[];
extern char lbl_88CB8184[];
extern char lbl_88CB81B4[];
extern char lbl_88CB8214[];
extern char lbl_88CB8244[];
extern char lbl_88CB8274[];
extern char lbl_88CB82A4[];
extern char lbl_88CB82D4[];
extern char lbl_88CB8304[];
extern char lbl_88CB8334[];
extern char lbl_88CB8364[];
extern char lbl_88CB8394[];
extern char lbl_88CB83C4[];
extern char lbl_88CB83F4[];
extern char lbl_88CB8424[];
extern char lbl_88CB8454[];
extern char lbl_88CB8484[];
extern char lbl_88CB84B4[];
extern char lbl_88CB84E4[];
extern char lbl_88CB8514[];
extern char lbl_88CB8544[];
extern char lbl_88CB8574[];
extern char lbl_88CB85A4[];
extern char lbl_88CB85D4[];
extern char lbl_88CB8604[];
extern char lbl_88CB8634[];
extern char lbl_88CB8664[];
extern char lbl_88CB8694[];
extern char lbl_88CB86C4[];
extern char lbl_88CB86F4[];
extern char lbl_88CB8724[];
extern char lbl_88CB8754[];
extern char lbl_88CB8784[];
extern char lbl_88CB87B4[];
extern char lbl_88CB87E4[];
extern char lbl_88CB8814[];
extern char lbl_88CB8844[];
extern char lbl_88CB8874[];
extern char lbl_88CB88A4[];
extern char lbl_88CB88D4[];
extern char lbl_88CB8904[];
extern char lbl_88CB8934[];
extern char lbl_88CB8964[];
extern char lbl_88CB8994[];
extern char lbl_88CB89C4[];
extern char lbl_88CB89F4[];
extern char lbl_88CB8A24[];
extern char lbl_88CB8A54[];
extern char lbl_88CB8A84[];
extern char lbl_88CB8AB4[];
extern char lbl_88CB8AE4[];
extern char lbl_88CB8B14[];
extern char lbl_88CB8B44[];
extern char lbl_88CB8B74[];
extern char lbl_88CB8BA4[];
extern char lbl_88CB8BD4[];
extern char lbl_88CB8C04[];
extern char lbl_88CB8C34[];
extern char lbl_88CB8C64[];
extern char lbl_88CB8C94[];
extern char lbl_88CB8CC4[];
extern char lbl_88CB8CF4[];
extern char lbl_88CB8D24[];
extern char lbl_88CB8D54[];
extern char lbl_88CB8D84[];
extern char lbl_88CB8DB4[];
extern char lbl_88CB8DE4[];
extern char lbl_88CB8E14[];
extern char lbl_88CB8E44[];
extern char lbl_88CB8E74[];
extern char lbl_88CB8EA4[];
extern char lbl_88CB8ED4[];
extern char lbl_88CB8F04[];
extern char lbl_88CB8F1C[];
extern char lbl_88CB8F4C[];
extern char lbl_88CB8F7C[];
extern char lbl_88CB8FAC[];
extern char lbl_88CB8FDC[];
extern char lbl_88CB900C[];
extern char lbl_88CB903C[];
extern char lbl_88CB906C[];
extern char lbl_88CB909C[];
extern char lbl_88CB90CC[];
extern char lbl_88CB90FC[];
extern char lbl_88CB912C[];
extern char lbl_88CB915C[];
extern char lbl_88CB918C[];
extern char lbl_88CB91BC[];
extern char lbl_88CB91EC[];
extern char lbl_88CB921C[];
extern char lbl_88CB924C[];
extern char lbl_88CB927C[];
extern char lbl_88CB92AC[];
extern char lbl_88CB92DC[];
extern char lbl_88CB930C[];
extern char lbl_88CB933C[];
extern char lbl_88CB936C[];
extern char lbl_88CB939C[];
extern char lbl_88CB93CC[];
extern char lbl_88CB93FC[];
extern char lbl_88CB942C[];
extern char lbl_88CB945C[];
extern char lbl_88CB948C[];
extern char lbl_88CB94BC[];
extern char lbl_88CB94EC[];
extern char lbl_88CB951C[];
extern char lbl_88CB954C[];
extern char lbl_88CB957C[];
extern char lbl_88CB95AC[];
extern char lbl_88CB95DC[];
extern char lbl_88CB960C[];
extern char lbl_88CB963C[];
extern char lbl_88CB966C[];
extern char lbl_88CB969C[];
extern char lbl_88CB96CC[];
extern char lbl_88CB96FC[];
extern char lbl_88CB972C[];
extern char lbl_88CB975C[];
extern char lbl_88CB978C[];
extern char lbl_88CB97BC[];
ts4_word fn_8841F080();
ts4_word ts4_set_u32_offc_884CE988();
ts4_word fn_88563470();

/* Swing_DLL.xex 0x889ECE40: call_seq lbl_88B4DD40, lbl_88CB73A4, lbl_88045B24, lbl_88CB7404, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DD40_889ECE40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7404, (ts4_word)(ts4_word)lbl_88045B24, (ts4_word)(ts4_word)lbl_88CB73A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DD40, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ECEB8: call_seq lbl_88B4DD70, lbl_88CB73A4, lbl_880459C0, lbl_88CB7434, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DD70_889ECEB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7434, (ts4_word)(ts4_word)lbl_880459C0, (ts4_word)(ts4_word)lbl_88CB73A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DD70, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ECF30: addr lbl_88B50EF8, u32@lbl_88B4D82C, u32@0x8 */
void ts4_addr_lbl_88B50EF8_889ECF30(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B50EF8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B4D82C);
    return;
}

/* Swing_DLL.xex 0x889ECF48: call_seq lbl_88B50EF8, lbl_88045224, lbl_88CB7464, lbl_8804EE8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50EF8_889ECF48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7464, (ts4_word)(ts4_word)lbl_88045224, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804EE8C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B50EF8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ECFB8: call_seq lbl_88B4DD88, lbl_88045194, lbl_88CB7494, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DD88_889ECFB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7494, (ts4_word)(ts4_word)lbl_88045194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DD88, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED028: call_seq lbl_88B4DDA0, lbl_8803EF90, lbl_88CB74C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DDA0_889ED028(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB74C4, (ts4_word)(ts4_word)lbl_8803EF90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DDA0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED098: call_seq lbl_88B4DDEC, lbl_88CB5FF4, lbl_8803FA04, lbl_88CB74F4, lbl_8804EF60, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DDEC_889ED098(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)(ts4_word)lbl_8803FA04, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804EF60, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B4DDEC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED108: call_seq lbl_88B4DE08, lbl_88042170, lbl_88CB7524, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DE08_889ED108(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7524, (ts4_word)(ts4_word)lbl_88042170, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DE08, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED178: addr lbl_88B50F40, u32@lbl_88B4DE04, u32@0x50 */
void ts4_addr_lbl_88B50F40_889ED178(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B50F40) + 80) = (ts4_word)(*(ts4_word *)lbl_88B4DE04);
    return;
}

/* Swing_DLL.xex 0x889ED190: call_seq lbl_88B50F40, lbl_88CB5FF4, lbl_8803F0C8, lbl_88CB7554, lbl_8804EFBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50F40_889ED190(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7554, (ts4_word)(ts4_word)lbl_8803F0C8, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804EFBC, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B50F40, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED208: call_seq lbl_88B4DE70, lbl_88CB74F4, lbl_8804044C, lbl_88CB7584, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DE70_889ED208(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7584, (ts4_word)(ts4_word)lbl_8804044C, (ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DE70, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED280: call_seq lbl_88B4DE88, lbl_88CB74F4, lbl_880403DC, lbl_88CB75B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DE88_889ED280(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB75B4, (ts4_word)(ts4_word)lbl_880403DC, (ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DE88, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED2F8: call_seq lbl_88B4DEB8, lbl_88040630, lbl_88CB75E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DEB8_889ED2F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB75E4, (ts4_word)(ts4_word)lbl_88040630, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DEB8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED368: call_seq lbl_88B4DF00, lbl_88040608, lbl_88CB7614, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DF00_889ED368(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7614, (ts4_word)(ts4_word)lbl_88040608, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DF00, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED3D8: call_seq lbl_88B4DF30, lbl_88CB74F4, lbl_88040394, lbl_88CB7644, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DF30_889ED3D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7644, (ts4_word)(ts4_word)lbl_88040394, (ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DF30, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED450: call_seq lbl_88B4DF60, lbl_88040590, lbl_88CB7674, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DF60_889ED450(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7674, (ts4_word)(ts4_word)lbl_88040590, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DF60, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED4C0: call_seq lbl_88B4DFC0, lbl_88040560, lbl_88CB76A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DFC0_889ED4C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB76A4, (ts4_word)(ts4_word)lbl_88040560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DFC0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED530: call_seq lbl_8804EFF8, lbl_88B4E008, lbl_88CB74F4, lbl_8803F690, lbl_88CB76D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8804EFF8_889ED530(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB76D4, (ts4_word)(ts4_word)lbl_8803F690, (ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E008, (ts4_word)6, (ts4_word)(ts4_word)lbl_8804EFF8, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED5A8: call_seq lbl_88B4E098, lbl_88CB7734, lbl_88045734, lbl_88CB7704, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E098_889ED5A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7704, (ts4_word)(ts4_word)lbl_88045734, (ts4_word)(ts4_word)lbl_88CB7734, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E098, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED620: call_seq lbl_88CB5FF4, lbl_88045A30, lbl_88CB7734, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB5FF4_889ED620(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7734, (ts4_word)(ts4_word)lbl_88045A30, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED688: addr lbl_88B51000, u32@lbl_88B4E110, u32@0x38 */
void ts4_addr_lbl_88B51000_889ED688(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B51000) + 56) = (ts4_word)(*(ts4_word *)lbl_88B4E110);
    return;
}

/* Swing_DLL.xex 0x889ED6A0: call_seq lbl_88B51000, lbl_88CB74F4, lbl_88040364, lbl_88CB7764, lbl_8804F03C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51000_889ED6A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7764, (ts4_word)(ts4_word)lbl_88040364, (ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804F03C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B51000, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED718: call_seq lbl_88B4E118, lbl_88CB74F4, lbl_88040344, lbl_88CB7794, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E118_889ED718(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7794, (ts4_word)(ts4_word)lbl_88040344, (ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E118, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED790: call_seq lbl_88B4E160, lbl_88CB76D4, lbl_8803F064, lbl_88CB77C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E160_889ED790(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB77C4, (ts4_word)(ts4_word)lbl_8803F064, (ts4_word)(ts4_word)lbl_88CB76D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E160, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED808: call_seq lbl_88B4E1C0, lbl_88040534, lbl_88CB77F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E1C0_889ED808(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB77F4, (ts4_word)(ts4_word)lbl_88040534, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E1C0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED878: call_seq lbl_88B4E208, lbl_88040508, lbl_88CB7824, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E208_889ED878(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7824, (ts4_word)(ts4_word)lbl_88040508, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E208, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED8E8: call_seq lbl_88B4E250, lbl_88CB74F4, lbl_8803F048, lbl_88CB7854, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E250_889ED8E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7854, (ts4_word)(ts4_word)lbl_8803F048, (ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E250, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED960: call_seq lbl_88B4E2F8, lbl_88CB74F4, lbl_880402E4, lbl_88CB7884, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E2F8_889ED960(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7884, (ts4_word)(ts4_word)lbl_880402E4, (ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E2F8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ED9D8: call_seq lbl_88B4E340, lbl_88040424, lbl_88CB78B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E340_889ED9D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB78B4, (ts4_word)(ts4_word)lbl_88040424, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E340, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EDA48: call_seq lbl_88B4E370, lbl_880403FC, lbl_88CB78E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E370_889EDA48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB78E4, (ts4_word)(ts4_word)lbl_880403FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E370, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EDAB8: call_seq lbl_88B4E400, lbl_88CB74F4, lbl_880402CC, lbl_88CB7914, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E400_889EDAB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7914, (ts4_word)(ts4_word)lbl_880402CC, (ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E400, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EDB30: call_seq lbl_88B4E490, lbl_88CB74F4, lbl_8803F6B0, lbl_88CB7944, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E490_889EDB30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7944, (ts4_word)(ts4_word)lbl_8803F6B0, (ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E490, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EDBA8: call_seq lbl_88CB74F4, lbl_88045AFC, lbl_88CB7974, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB74F4_889EDBA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7974, (ts4_word)(ts4_word)lbl_88045AFC, (ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EDC10: call_seq lbl_88B4E550, lbl_88CB7554, lbl_8804589C, lbl_88CB79A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E550_889EDC10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB79A4, (ts4_word)(ts4_word)lbl_8804589C, (ts4_word)(ts4_word)lbl_88CB7554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E550, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EDC88: call_seq lbl_88B4E580, lbl_88CB73A4, lbl_88045860, lbl_88CB79D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E580_889EDC88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB79D4, (ts4_word)(ts4_word)lbl_88045860, (ts4_word)(ts4_word)lbl_88CB73A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E580, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EDD00: call_seq lbl_88B4E598, lbl_880453D8, lbl_88CB7A04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E598_889EDD00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7A04, (ts4_word)(ts4_word)lbl_880453D8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E598, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EDD70: call_seq lbl_88B4E5C8, lbl_88CB7974, lbl_880403C4, lbl_88CB7A34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E5C8_889EDD70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7A34, (ts4_word)(ts4_word)lbl_880403C4, (ts4_word)(ts4_word)lbl_88CB7974, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E5C8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EDDE8: call_seq lbl_88B4E640, lbl_8803FC24, lbl_88CB7A64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E640_889EDDE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7A64, (ts4_word)(ts4_word)lbl_8803FC24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E640, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EDE58: call_seq lbl_88B4E670, lbl_88CB74F4, lbl_8803FC08, lbl_88CB7A94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E670_889EDE58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7A94, (ts4_word)(ts4_word)lbl_8803FC08, (ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E670, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EDED0: call_seq lbl_88B4E6B8, lbl_880405E4, lbl_88CB7AC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E6B8_889EDED0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7AC4, (ts4_word)(ts4_word)lbl_880405E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E6B8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EDF40: call_seq lbl_88B4E700, lbl_880405C0, lbl_88CB7AF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E700_889EDF40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7AF4, (ts4_word)(ts4_word)lbl_880405C0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E700, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EDFB0: call_seq lbl_88B4E730, lbl_88CB74F4, lbl_88040380, lbl_88CB7B24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E730_889EDFB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7B24, (ts4_word)(ts4_word)lbl_88040380, (ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E730, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE028: call_seq lbl_88B4E7C0, lbl_8803FC48, lbl_88CB7B54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E7C0_889EE028(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7B54, (ts4_word)(ts4_word)lbl_8803FC48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E7C0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE098: call_seq lbl_88B4E850, lbl_88CB7974, lbl_8803FC6C, lbl_88CB7B84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E850_889EE098(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7B84, (ts4_word)(ts4_word)lbl_8803FC6C, (ts4_word)(ts4_word)lbl_88CB7974, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E850, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE110: call_seq lbl_88B4E8C8, lbl_88045020, lbl_88CB7BB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E8C8_889EE110(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7BB4, (ts4_word)(ts4_word)lbl_88045020, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E8C8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE180: call_seq lbl_88B4E910, lbl_88CB7974, lbl_88040300, lbl_88CB7BE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E910_889EE180(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7BE4, (ts4_word)(ts4_word)lbl_88040300, (ts4_word)(ts4_word)lbl_88CB7974, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E910, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE1F8: call_seq lbl_88B4E970, lbl_88CB74F4, lbl_880403AC, lbl_88CB7C14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E970_889EE1F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7C14, (ts4_word)(ts4_word)lbl_880403AC, (ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E970, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE270: call_seq lbl_88B4E988, lbl_880422F8, lbl_88CB7C44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4E988_889EE270(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7C44, (ts4_word)(ts4_word)lbl_880422F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4E988, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE2E0: call_seq lbl_88B4EA00, lbl_88CB74F4, lbl_8803FA18, lbl_88CB7C74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4EA00_889EE2E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7C74, (ts4_word)(ts4_word)lbl_8803FA18, (ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4EA00, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE358: call_seq lbl_88CB5FF4, lbl_8803FBE0, lbl_88CB7CA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB5FF4_889EE358(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7CA4, (ts4_word)(ts4_word)lbl_8803FBE0, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE3C0: call_seq lbl_88B4EA30, lbl_88CB7CA4, lbl_8803FCA0, lbl_88CB7CD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4EA30_889EE3C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7CD4, (ts4_word)(ts4_word)lbl_8803FCA0, (ts4_word)(ts4_word)lbl_88CB7CA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4EA30, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE438: call_seq lbl_88B4EAA8, lbl_88CB7CA4, lbl_8803FC80, lbl_88CB7D04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4EAA8_889EE438(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7D04, (ts4_word)(ts4_word)lbl_8803FC80, (ts4_word)(ts4_word)lbl_88CB7CA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4EAA8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE4B0: call_seq lbl_88B4EB08, lbl_88CB7CA4, lbl_8803F9E8, lbl_88CB7D34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4EB08_889EE4B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7D34, (ts4_word)(ts4_word)lbl_8803F9E8, (ts4_word)(ts4_word)lbl_88CB7CA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4EB08, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE528: call_seq lbl_88B4EB80, lbl_88CB74F4, lbl_8804032C, lbl_88CB7D64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4EB80_889EE528(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7D64, (ts4_word)(ts4_word)lbl_8804032C, (ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4EB80, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE5A0: call_seq lbl_8804F050, lbl_88B4EC10, lbl_88CB8214, lbl_8803F6CC, lbl_88CB7D94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8804F050_889EE5A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7D94, (ts4_word)(ts4_word)lbl_8803F6CC, (ts4_word)(ts4_word)lbl_88CB8214, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4EC10, (ts4_word)18, (ts4_word)(ts4_word)lbl_8804F050, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE618: call_seq lbl_88CB5FF4, lbl_88045AA8, lbl_88CB7DC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB5FF4_889EE618(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7DC4, (ts4_word)(ts4_word)lbl_88045AA8, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE680: call_seq lbl_88CB7E54, lbl_880457FC, lbl_88CB7DF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB7E54_889EE680(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7DF4, (ts4_word)(ts4_word)lbl_880457FC, (ts4_word)(ts4_word)lbl_88CB7E54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE6E8: call_seq lbl_88CB7D94, lbl_880455E0, lbl_88CB7E24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB7D94_889EE6E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7E24, (ts4_word)(ts4_word)lbl_880455E0, (ts4_word)(ts4_word)lbl_88CB7D94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE750: call_seq lbl_8804F0BC, lbl_88CB7DC4, lbl_880459F8, lbl_88CB7E54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8804F0BC_889EE750(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7E54, (ts4_word)(ts4_word)lbl_880459F8, (ts4_word)(ts4_word)lbl_88CB7DC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804F0BC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE7B8: call_seq lbl_88B4EDC0, lbl_88045070, lbl_88CB7E84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4EDC0_889EE7B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7E84, (ts4_word)(ts4_word)lbl_88045070, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4EDC0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE828: call_seq lbl_88B4EDF0, lbl_88CB7E54, lbl_88041DE0, lbl_88CB7EB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4EDF0_889EE828(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7EB4, (ts4_word)(ts4_word)lbl_88041DE0, (ts4_word)(ts4_word)lbl_88CB7E54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4EDF0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE8A0: call_seq lbl_88B4EE9C, lbl_88CB5FF4, lbl_8803F5D4, lbl_88CB7EE4, lbl_8804F120, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4EE9C_889EE8A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7EE4, (ts4_word)(ts4_word)lbl_8803F5D4, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804F120, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B4EE9C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE910: call_seq lbl_88B4EEB4, lbl_88CB7FA4, lbl_880402B0, lbl_88CB7F14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4EEB4_889EE910(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7F14, (ts4_word)(ts4_word)lbl_880402B0, (ts4_word)(ts4_word)lbl_88CB7FA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4EEB4, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE988: call_seq lbl_88CB7F74, lbl_88040E04, lbl_88CB7F44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB7F74_889EE988(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7F44, (ts4_word)(ts4_word)lbl_88040E04, (ts4_word)(ts4_word)lbl_88CB7F74, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EE9F0: call_seq lbl_88B4EECC, lbl_88CB7FA4, lbl_8803EFA8, lbl_88CB7F74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4EECC_889EE9F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7F74, (ts4_word)(ts4_word)lbl_8803EFA8, (ts4_word)(ts4_word)lbl_88CB7FA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4EECC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EEA68: call_seq lbl_88B4EF00, lbl_88CB7EE4, lbl_88040290, lbl_88CB7FA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4EF00_889EEA68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7FA4, (ts4_word)(ts4_word)lbl_88040290, (ts4_word)(ts4_word)lbl_88CB7EE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4EF00, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EEAE0: call_seq lbl_88CB7FA4, lbl_880402A0, lbl_88CB7FD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB7FA4_889EEAE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7FD4, (ts4_word)(ts4_word)lbl_880402A0, (ts4_word)(ts4_word)lbl_88CB7FA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EEB48: call_seq lbl_88CB7F14, lbl_88040E18, lbl_88CB8004, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB7F14_889EEB48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8004, (ts4_word)(ts4_word)lbl_88040E18, (ts4_word)(ts4_word)lbl_88CB7F14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EEBB0: call_seq lbl_88CB7FD4, lbl_88040E68, lbl_88CB8034, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB7FD4_889EEBB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8034, (ts4_word)(ts4_word)lbl_88040E68, (ts4_word)(ts4_word)lbl_88CB7FD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EEC18: call_seq lbl_88CB7F14, lbl_88040DB0, lbl_88CB8064, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB7F14_889EEC18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8064, (ts4_word)(ts4_word)lbl_88040DB0, (ts4_word)(ts4_word)lbl_88CB7F14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EEC80: call_seq lbl_88B4EFA8, lbl_88CB80F4, lbl_8803F6D8, lbl_88CB8094, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4EFA8_889EEC80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8094, (ts4_word)(ts4_word)lbl_8803F6D8, (ts4_word)(ts4_word)lbl_88CB80F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4EFA8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EECF8: call_seq lbl_88B4EFD8, lbl_88CB8124, lbl_88045914, lbl_88CB80C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4EFD8_889EECF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB80C4, (ts4_word)(ts4_word)lbl_88045914, (ts4_word)(ts4_word)lbl_88CB8124, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4EFD8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EED70: call_seq lbl_88B4EFF0, lbl_88CB8214, lbl_88047070, lbl_88CB80F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4EFF0_889EED70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB80F4, (ts4_word)(ts4_word)lbl_88047070, (ts4_word)(ts4_word)lbl_88CB8214, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4EFF0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EEDE8: call_seq lbl_88B4F020, lbl_88CB80F4, lbl_880402BC, lbl_88CB8124, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F020_889EEDE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8124, (ts4_word)(ts4_word)lbl_880402BC, (ts4_word)(ts4_word)lbl_88CB80F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F020, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EEE60: call_seq lbl_88B4F038, lbl_88CB8124, lbl_88045580, lbl_88CB8154, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F038_889EEE60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8154, (ts4_word)(ts4_word)lbl_88045580, (ts4_word)(ts4_word)lbl_88CB8124, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F038, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EEED8: call_seq lbl_88B4F050, lbl_8803F9C0, lbl_88CB8184, lbl_8804F14C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F050_889EEED8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8184, (ts4_word)(ts4_word)lbl_8803F9C0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804F14C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B4F050, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EEF48: call_seq lbl_88B4F080, lbl_88CB5FF4, lbl_8803F660, lbl_88CB81B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F080_889EEF48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB81B4, (ts4_word)(ts4_word)lbl_8803F660, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F080, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EEFC0: get u32@lbl_88B4F11C, lbl_88B51060, u32@lbl_88B4F118, u32@lbl_88B4F114, u32@0x50, u32@0x110 */
void ts4_get_u32_lbl_88B4F11C_889EEFC0(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88B4F11C;
    t2 = *(ts4_word *)lbl_88B4F118;
    t3 = *(ts4_word *)lbl_88B4F114;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B51060) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B51060) + 272) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B51060) + 560) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x889EF068: call_seq lbl_88B4F128, lbl_88CB5FF4, lbl_8803F084, lbl_88CB8214, lbl_8804F328, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F128_889EF068(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8214, (ts4_word)(ts4_word)lbl_8803F084, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804F328, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B4F128, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF0E0: call_seq lbl_88B4F1A0, lbl_88CB5FF4, lbl_8804707C, lbl_88CB8244, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F1A0_889EF0E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8244, (ts4_word)(ts4_word)lbl_8804707C, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F1A0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF158: call_seq lbl_88B4F1B8, lbl_88CB6A14, lbl_88044F38, lbl_88CB8274, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F1B8_889EF158(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8274, (ts4_word)(ts4_word)lbl_88044F38, (ts4_word)(ts4_word)lbl_88CB6A14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F1B8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF1D0: call_seq lbl_88B4F1D0, lbl_88042E20, lbl_88CB82A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F1D0_889EF1D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB82A4, (ts4_word)(ts4_word)lbl_88042E20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F1D0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF240: call_seq lbl_88B4F1E8, lbl_88CB5FF4, lbl_8803EFD0, lbl_88CB82D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F1E8_889EF240(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB82D4, (ts4_word)(ts4_word)lbl_8803EFD0, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F1E8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF2B8: call_seq lbl_88B4F230, lbl_88044F10, lbl_88CB8304, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F230_889EF2B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8304, (ts4_word)(ts4_word)lbl_88044F10, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F230, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF328: call_seq lbl_88B4F248, lbl_88CB5FF4, lbl_88044F90, lbl_88CB8334, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F248_889EF328(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8334, (ts4_word)(ts4_word)lbl_88044F90, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F248, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF3A0: call_seq lbl_88B4F278, lbl_88CB83F4, lbl_8803F670, lbl_88CB8364, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F278_889EF3A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8364, (ts4_word)(ts4_word)lbl_8803F670, (ts4_word)(ts4_word)lbl_88CB83F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F278, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF418: call_seq lbl_88B4F2F0, lbl_880404E0, lbl_88CB8394, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F2F0_889EF418(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8394, (ts4_word)(ts4_word)lbl_880404E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F2F0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF488: call_seq lbl_88B4F338, lbl_880404B8, lbl_88CB83C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F338_889EF488(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB83C4, (ts4_word)(ts4_word)lbl_880404B8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F338, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF4F8: call_seq lbl_8804F33C, lbl_88B4F380, lbl_88CB74F4, lbl_8803F030, lbl_88CB83F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8804F33C_889EF4F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB83F4, (ts4_word)(ts4_word)lbl_8803F030, (ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F380, (ts4_word)9, (ts4_word)(ts4_word)lbl_8804F33C, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF570: call_seq lbl_88B4F458, lbl_88040494, lbl_88CB8424, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F458_889EF570(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8424, (ts4_word)(ts4_word)lbl_88040494, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F458, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF5E0: call_seq lbl_88B4F488, lbl_88040470, lbl_88CB8454, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F488_889EF5E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8454, (ts4_word)(ts4_word)lbl_88040470, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F488, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF650: call_seq lbl_88B4F4B8, lbl_88CB74F4, lbl_88040318, lbl_88CB8484, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F4B8_889EF650(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8484, (ts4_word)(ts4_word)lbl_88040318, (ts4_word)(ts4_word)lbl_88CB74F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F4B8, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF6C8: call_seq lbl_88B4F590, lbl_88CB7404, lbl_88044EA8, lbl_88CB84B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F590_889EF6C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB84B4, (ts4_word)(ts4_word)lbl_88044EA8, (ts4_word)(ts4_word)lbl_88CB7404, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F590, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF740: call_seq lbl_88B4F5D8, lbl_88CB7404, lbl_88044E64, lbl_88CB84E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F5D8_889EF740(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB84E4, (ts4_word)(ts4_word)lbl_88044E64, (ts4_word)(ts4_word)lbl_88CB7404, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F5D8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF7B8: call_seq lbl_88B4F638, lbl_88CB7434, lbl_88044DD0, lbl_88CB8514, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F638_889EF7B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8514, (ts4_word)(ts4_word)lbl_88044DD0, (ts4_word)(ts4_word)lbl_88CB7434, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F638, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF830: call_seq lbl_88B4F698, lbl_88CB7434, lbl_88044CD0, lbl_88CB8544, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F698_889EF830(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8544, (ts4_word)(ts4_word)lbl_88044CD0, (ts4_word)(ts4_word)lbl_88CB7434, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F698, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF8A8: call_seq lbl_88B4F6F8, lbl_88CB7404, lbl_88044BD4, lbl_88CB8574, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F6F8_889EF8A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8574, (ts4_word)(ts4_word)lbl_88044BD4, (ts4_word)(ts4_word)lbl_88CB7404, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F6F8, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF920: call_seq lbl_88B4F7B8, lbl_8803F094, lbl_88CB85A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F7B8_889EF920(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB85A4, (ts4_word)(ts4_word)lbl_8803F094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F7B8, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EF990: call_seq lbl_88B4F950, lbl_88CB6AD4, lbl_8803F0AC, lbl_88CB85D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F950_889EF990(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB85D4, (ts4_word)(ts4_word)lbl_8803F0AC, (ts4_word)(ts4_word)lbl_88CB6AD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F950, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EFA08: call_seq lbl_88B4F968, lbl_88CB6AD4, lbl_88044E30, lbl_88CB8604, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F968_889EFA08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8604, (ts4_word)(ts4_word)lbl_88044E30, (ts4_word)(ts4_word)lbl_88CB6AD4, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F968, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EFA80: call_seq lbl_88B4F980, lbl_88CB6AD4, lbl_88044DF8, lbl_88CB8634, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F980_889EFA80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8634, (ts4_word)(ts4_word)lbl_88044DF8, (ts4_word)(ts4_word)lbl_88CB6AD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F980, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EFAF8: call_seq lbl_88B4F9B0, lbl_88044B54, lbl_88CB8664, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F9B0_889EFAF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8664, (ts4_word)(ts4_word)lbl_88044B54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F9B0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EFB68: call_seq lbl_88B4F9E0, lbl_88CB6AD4, lbl_88044D8C, lbl_88CB8694, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F9E0_889EFB68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8694, (ts4_word)(ts4_word)lbl_88044D8C, (ts4_word)(ts4_word)lbl_88CB6AD4, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F9E0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EFBE0: call_seq lbl_88B4F9F8, lbl_88CB7434, lbl_8804705C, lbl_88CB86C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4F9F8_889EFBE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB86C4, (ts4_word)(ts4_word)lbl_8804705C, (ts4_word)(ts4_word)lbl_88CB7434, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4F9F8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EFC58: call_seq lbl_88B4FA88, lbl_88044A58, lbl_88CB86F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4FA88_889EFC58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB86F4, (ts4_word)(ts4_word)lbl_88044A58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4FA88, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EFCC8: call_seq lbl_88B4FAD0, lbl_88044B0C, lbl_88CB8724, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4FAD0_889EFCC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8724, (ts4_word)(ts4_word)lbl_88044B0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4FAD0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EFD38: call_seq lbl_88B4FB00, lbl_88044B94, lbl_88CB8754, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4FB00_889EFD38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8754, (ts4_word)(ts4_word)lbl_88044B94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4FB00, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EFDA8: call_seq lbl_88B4FB30, lbl_88CB5FF4, lbl_88044D60, lbl_88CB8784, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4FB30_889EFDA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8784, (ts4_word)(ts4_word)lbl_88044D60, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4FB30, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EFE20: call_seq lbl_88B4FB60, lbl_88CB5FF4, lbl_88044C84, lbl_88CB87B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4FB60_889EFE20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB87B4, (ts4_word)(ts4_word)lbl_88044C84, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4FB60, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EFE98: call_seq lbl_88B4FB78, lbl_88CB5FF4, lbl_88044C48, lbl_88CB87E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4FB78_889EFE98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB87E4, (ts4_word)(ts4_word)lbl_88044C48, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4FB78, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EFF10: call_seq lbl_88B4FB90, lbl_88044A08, lbl_88CB8814, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4FB90_889EFF10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8814, (ts4_word)(ts4_word)lbl_88044A08, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4FB90, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EFF80: call_seq lbl_88B4FBC0, lbl_88CB5FF4, lbl_88044C08, lbl_88CB8844, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4FBC0_889EFF80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8844, (ts4_word)(ts4_word)lbl_88044C08, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4FBC0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EFFF8: call_seq lbl_88B4FBD8, lbl_88040668, lbl_88CB8874, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4FBD8_889EFFF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8874, (ts4_word)(ts4_word)lbl_88040668, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4FBD8, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0068: call_seq lbl_88B4FCB0, lbl_88CB5FF4, lbl_88040658, lbl_88CB88A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4FCB0_889F0068(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB88A4, (ts4_word)(ts4_word)lbl_88040658, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4FCB0, (ts4_word)18, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F00E0: call_seq lbl_88B4FE60, lbl_8803F5F4, lbl_88CB88D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4FE60_889F00E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB88D4, (ts4_word)(ts4_word)lbl_8803F5F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4FE60, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0150: call_seq lbl_88B4FFF8, lbl_88CB7434, lbl_8803F64C, lbl_88CB8904, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4FFF8_889F0150(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8904, (ts4_word)(ts4_word)lbl_8803F64C, (ts4_word)(ts4_word)lbl_88CB7434, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4FFF8, (ts4_word)26, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F01C8: call_seq lbl_88CB5FF4, lbl_8804494C, lbl_88CB8934, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB5FF4_889F01C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8934, (ts4_word)(ts4_word)lbl_8804494C, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0230: call_seq lbl_88B50268, lbl_88CB8934, lbl_88044700, lbl_88CB8964, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50268_889F0230(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8964, (ts4_word)(ts4_word)lbl_88044700, (ts4_word)(ts4_word)lbl_88CB8934, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50268, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F02A8: call_seq lbl_88CB5FF4, lbl_88044924, lbl_88CB8994, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB5FF4_889F02A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8994, (ts4_word)(ts4_word)lbl_88044924, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0310: call_seq lbl_88B502E0, lbl_88044438, lbl_88CB89C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B502E0_889F0310(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB89C4, (ts4_word)(ts4_word)lbl_88044438, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B502E0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0380: call_seq lbl_88B50328, lbl_88CB8994, lbl_88044680, lbl_88CB89F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50328_889F0380(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB89F4, (ts4_word)(ts4_word)lbl_88044680, (ts4_word)(ts4_word)lbl_88CB8994, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50328, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0460: call_seq lbl_88CB5FF4, lbl_880448FC, lbl_88CB8A54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB5FF4_889F0460(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8A54, (ts4_word)(ts4_word)lbl_880448FC, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F04C8: call_seq lbl_88B50358, lbl_88CB8A24, lbl_88044524, lbl_88CB8A84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50358_889F04C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8A84, (ts4_word)(ts4_word)lbl_88044524, (ts4_word)(ts4_word)lbl_88CB8A24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50358, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0540: call_seq lbl_88B503B8, lbl_88CB8A54, lbl_880446BC, lbl_88CB8AB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B503B8_889F0540(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8AB4, (ts4_word)(ts4_word)lbl_880446BC, (ts4_word)(ts4_word)lbl_88CB8A54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B503B8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F05B8: call_seq lbl_88CB5FF4, lbl_8804489C, lbl_88CB8AE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB5FF4_889F05B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8AE4, (ts4_word)(ts4_word)lbl_8804489C, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0620: call_seq lbl_88B50418, lbl_88CB8AE4, lbl_88044650, lbl_88CB8B14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50418_889F0620(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8B14, (ts4_word)(ts4_word)lbl_88044650, (ts4_word)(ts4_word)lbl_88CB8AE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50418, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0698: call_seq lbl_88B50508, lbl_88044324, lbl_88CB8B44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50508_889F0698(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8B44, (ts4_word)(ts4_word)lbl_88044324, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50508, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0708: call_seq lbl_88B505F8, lbl_88044370, lbl_88CB8B74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B505F8_889F0708(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8B74, (ts4_word)(ts4_word)lbl_88044370, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B505F8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0778: call_seq lbl_88B50640, lbl_8803F610, lbl_88CB8BA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50640_889F0778(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8BA4, (ts4_word)(ts4_word)lbl_8803F610, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50640, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F07E8: call_seq lbl_88B50718, lbl_8803F634, lbl_88CB8BD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50718_889F07E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8BD4, (ts4_word)(ts4_word)lbl_8803F634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50718, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0858: call_seq lbl_88CB5FF4, lbl_88044874, lbl_88CB8C04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB5FF4_889F0858(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8C04, (ts4_word)(ts4_word)lbl_88044874, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F08C0: call_seq lbl_88B50730, lbl_88CB8C04, lbl_8804461C, lbl_88CB8C34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50730_889F08C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8C34, (ts4_word)(ts4_word)lbl_8804461C, (ts4_word)(ts4_word)lbl_88CB8C04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50730, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0938: call_seq lbl_88B50778, lbl_88044268, lbl_88CB8C64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50778_889F0938(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8C64, (ts4_word)(ts4_word)lbl_88044268, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50778, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F09A8: call_seq lbl_88B507C0, lbl_88CB5FF4, lbl_8804484C, lbl_88CB8C94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B507C0_889F09A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8C94, (ts4_word)(ts4_word)lbl_8804484C, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B507C0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0A20: call_seq lbl_88B507D8, lbl_880443CC, lbl_88CB8CC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B507D8_889F0A20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8CC4, (ts4_word)(ts4_word)lbl_880443CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B507D8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0A90: call_seq lbl_88B50820, lbl_88CB8C94, lbl_880445E4, lbl_88CB8CF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50820_889F0A90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8CF4, (ts4_word)(ts4_word)lbl_880445E4, (ts4_word)(ts4_word)lbl_88CB8C94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50820, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0B08: call_seq lbl_88CB5FF4, lbl_8804481C, lbl_88CB8D24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB5FF4_889F0B08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8D24, (ts4_word)(ts4_word)lbl_8804481C, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0B70: call_seq lbl_88B50838, lbl_88CB8D24, lbl_880445A8, lbl_88CB8D54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50838_889F0B70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8D54, (ts4_word)(ts4_word)lbl_880445A8, (ts4_word)(ts4_word)lbl_88CB8D24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50838, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0BE8: call_seq lbl_88B508E0, lbl_8804449C, lbl_88CB8D84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B508E0_889F0BE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8D84, (ts4_word)(ts4_word)lbl_8804449C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B508E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0C58: call_seq lbl_88B50910, lbl_88CB5FF4, lbl_88044744, lbl_88CB8DB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50910_889F0C58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8DB4, (ts4_word)(ts4_word)lbl_88044744, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50910, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0CD0: call_seq lbl_88B50958, lbl_88CB5FF4, lbl_88044758, lbl_88CB8DE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50958_889F0CD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8DE4, (ts4_word)(ts4_word)lbl_88044758, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50958, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0D48: call_seq lbl_88CB5FF4, lbl_880447EC, lbl_88CB8E14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB5FF4_889F0D48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8E14, (ts4_word)(ts4_word)lbl_880447EC, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0DB0: call_seq lbl_88B509A0, lbl_88CB8E14, lbl_88044568, lbl_88CB8E44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B509A0_889F0DB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8E44, (ts4_word)(ts4_word)lbl_88044568, (ts4_word)(ts4_word)lbl_88CB8E14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B509A0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0E28: call_seq lbl_88B509E8, lbl_88CB5FF4, lbl_880447B8, lbl_88CB8E74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B509E8_889F0E28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8E74, (ts4_word)(ts4_word)lbl_880447B8, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B509E8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0EA0: call_seq lbl_88B50A00, lbl_88CB5FF4, lbl_88044784, lbl_88CB8EA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50A00_889F0EA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8EA4, (ts4_word)(ts4_word)lbl_88044784, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50A00, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0F18: call_seq lbl_88B50A18, lbl_88CB8E74, lbl_880444CC, lbl_88CB8ED4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50A18_889F0F18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8ED4, (ts4_word)(ts4_word)lbl_880444CC, (ts4_word)(ts4_word)lbl_88CB8E74, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50A18, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F0F90: call_seq lbl_8804E9F8, lbl_8804F368, lbl_88CB8F04, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF530, fn_88563470 */
ts4_word ts4_call_seq_lbl_8804E9F8_889F0F90(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CB8F04, (ts4_word)(ts4_word)lbl_8804F368, (ts4_word)3, (ts4_word)(ts4_word)lbl_8804E9F8);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF530);
    return t2;
}

/* Swing_DLL.xex 0x889F0FD8: call_seq lbl_88B512E8, lbl_88046C94, lbl_88CB8F1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B512E8_889F0FD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8F1C, (ts4_word)(ts4_word)lbl_88046C94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B512E8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1048: addr lbl_88B56190, u32@lbl_88B51360, u32@0x38 */
void ts4_addr_lbl_88B56190_889F1048(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B56190) + 56) = (ts4_word)(*(ts4_word *)lbl_88B51360);
    return;
}

/* Swing_DLL.xex 0x889F1060: call_seq lbl_88B56190, lbl_8803EF04, lbl_88CB8F4C, lbl_8804F85C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56190_889F1060(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8F4C, (ts4_word)(ts4_word)lbl_8803EF04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804F85C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B56190, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F10D0: call_seq lbl_88B51364, lbl_88046C78, lbl_88CB8F7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51364_889F10D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8F7C, (ts4_word)(ts4_word)lbl_88046C78, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51364, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1140: call_seq lbl_88B51394, lbl_8803EC6C, lbl_88CB8FAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51394_889F1140(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8FAC, (ts4_word)(ts4_word)lbl_8803EC6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51394, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F11B0: call_seq lbl_88B513C8, lbl_88CB933C, lbl_8803EE48, lbl_88CB8FDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B513C8_889F11B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB8FDC, (ts4_word)(ts4_word)lbl_8803EE48, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B513C8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1228: call_seq lbl_88B51428, lbl_88040040, lbl_88CB900C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51428_889F1228(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB900C, (ts4_word)(ts4_word)lbl_88040040, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51428, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1298: call_seq lbl_88B51488, lbl_88CB8FDC, lbl_8803ECD0, lbl_88CB903C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51488_889F1298(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB903C, (ts4_word)(ts4_word)lbl_8803ECD0, (ts4_word)(ts4_word)lbl_88CB8FDC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51488, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1310: call_seq lbl_88B51518, lbl_88CB8FDC, lbl_8803ECB0, lbl_88CB906C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51518_889F1310(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB906C, (ts4_word)(ts4_word)lbl_8803ECB0, (ts4_word)(ts4_word)lbl_88CB8FDC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51518, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1388: call_seq lbl_88B51530, lbl_88040078, lbl_88CB909C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51530_889F1388(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB909C, (ts4_word)(ts4_word)lbl_88040078, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51530, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F13F8: call_seq lbl_88B51590, lbl_88CB8FDC, lbl_8803EC94, lbl_88CB90CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51590_889F13F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB90CC, (ts4_word)(ts4_word)lbl_8803EC94, (ts4_word)(ts4_word)lbl_88CB8FDC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51590, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1470: call_seq lbl_88B51638, lbl_88046C60, lbl_88CB90FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51638_889F1470(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB90FC, (ts4_word)(ts4_word)lbl_88046C60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51638, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F14E0: call_seq lbl_88B51650, lbl_8803EE88, lbl_88CB912C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51650_889F14E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB912C, (ts4_word)(ts4_word)lbl_8803EE88, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51650, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1550: call_seq lbl_88B516B0, lbl_88CB933C, lbl_8804002C, lbl_88CB915C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B516B0_889F1550(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB915C, (ts4_word)(ts4_word)lbl_8804002C, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B516B0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F15C8: call_seq lbl_88B516C8, lbl_88046C00, lbl_88CB918C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B516C8_889F15C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB918C, (ts4_word)(ts4_word)lbl_88046C00, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B516C8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1638: call_seq lbl_88B51710, lbl_88046C24, lbl_88CB91BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51710_889F1638(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB91BC, (ts4_word)(ts4_word)lbl_88046C24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51710, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F16A8: call_seq lbl_88B517A0, lbl_88046C48, lbl_88CB91EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B517A0_889F16A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB91EC, (ts4_word)(ts4_word)lbl_88046C48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B517A0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1718: call_seq lbl_88CB933C, lbl_8803EC3C, lbl_88CB921C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB933C_889F1718(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB921C, (ts4_word)(ts4_word)lbl_8803EC3C, (ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1780: call_seq lbl_88B51830, lbl_88CB921C, lbl_8803ECF4, lbl_88CB924C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51830_889F1780(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB924C, (ts4_word)(ts4_word)lbl_8803ECF4, (ts4_word)(ts4_word)lbl_88CB921C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51830, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F17F8: call_seq lbl_88B51890, lbl_8803EEFC, lbl_88CB927C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51890_889F17F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB927C, (ts4_word)(ts4_word)lbl_8803EEFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51890, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1868: call_seq lbl_88B518C0, lbl_8803EEE8, lbl_88CB92AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B518C0_889F1868(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB92AC, (ts4_word)(ts4_word)lbl_8803EEE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B518C0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F18D8: call_seq lbl_88B51908, lbl_8803EE7C, lbl_88CB92DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51908_889F18D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB92DC, (ts4_word)(ts4_word)lbl_8803EE7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51908, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1948: call_seq lbl_8803C97C, lbl_88CB930C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803C97C_889F1948(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB930C, (ts4_word)(ts4_word)lbl_8803C97C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F19A8: call_seq lbl_88B51968, lbl_88CB930C, lbl_8803C9DC, lbl_88CB933C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51968_889F19A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB933C, (ts4_word)(ts4_word)lbl_8803C9DC, (ts4_word)(ts4_word)lbl_88CB930C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51968, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1A20: call_seq lbl_88B51998, lbl_8803CC5C, lbl_88CB936C, lbl_8804F878, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51998_889F1A20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB936C, (ts4_word)(ts4_word)lbl_8803CC5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804F878, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B51998, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1A90: call_seq lbl_88B51A40, lbl_8803CCC4, lbl_88CB939C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51A40_889F1A90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB939C, (ts4_word)(ts4_word)lbl_8803CCC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51A40, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1B00: call_seq lbl_88B51A70, lbl_8803CCD4, lbl_88CB93CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51A70_889F1B00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB93CC, (ts4_word)(ts4_word)lbl_8803CCD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51A70, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1B70: addr lbl_88B561D8, u32@lbl_88B51AA0, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88B561D8_889F1B70(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B51AA0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B561D8) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B561D8) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x889F1B90: call_seq lbl_88B561D8, lbl_8803D124, lbl_88CB93FC, lbl_8804F9E8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B561D8_889F1B90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB93FC, (ts4_word)(ts4_word)lbl_8803D124, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804F9E8, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B561D8, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1C00: call_seq lbl_88B51AAC, lbl_8803D484, lbl_88CB942C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51AAC_889F1C00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB942C, (ts4_word)(ts4_word)lbl_8803D484, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51AAC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1C70: call_seq lbl_88B51ADC, lbl_8803D4A8, lbl_88CB945C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51ADC_889F1C70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB945C, (ts4_word)(ts4_word)lbl_8803D4A8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51ADC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1CE0: addr lbl_88B56298, u32@lbl_88B51AF4, u32@0x50 */
void ts4_addr_lbl_88B56298_889F1CE0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B56298) + 80) = (ts4_word)(*(ts4_word *)lbl_88B51AF4);
    return;
}

/* Swing_DLL.xex 0x889F1CF8: call_seq lbl_88B56298, lbl_8803D4C4, lbl_88CB948C, lbl_8804FA3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56298_889F1CF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB948C, (ts4_word)(ts4_word)lbl_8803D4C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804FA3C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B56298, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1D68: call_seq lbl_88B51AF8, lbl_8803CAF0, lbl_88CB94BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51AF8_889F1D68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB94BC, (ts4_word)(ts4_word)lbl_8803CAF0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51AF8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1DD8: call_seq lbl_88B51B28, lbl_8803D194, lbl_88CB94EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51B28_889F1DD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB94EC, (ts4_word)(ts4_word)lbl_8803D194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51B28, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1E48: call_seq lbl_88B51B60, lbl_8803D2E0, lbl_88CB951C, lbl_8804FA60, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51B60_889F1E48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB951C, (ts4_word)(ts4_word)lbl_8803D2E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804FA60, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B51B60, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1EB8: call_seq lbl_88B51BC0, lbl_8803D6A0, lbl_88CB954C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51BC0_889F1EB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB954C, (ts4_word)(ts4_word)lbl_8803D6A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51BC0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1F28: call_seq lbl_88B51C80, lbl_8803D914, lbl_88CB957C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51C80_889F1F28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB957C, (ts4_word)(ts4_word)lbl_8803D914, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51C80, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F1F98: call_seq lbl_88B51C98, lbl_8803D9E8, lbl_88CB95AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51C98_889F1F98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB95AC, (ts4_word)(ts4_word)lbl_8803D9E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51C98, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2008: addr lbl_88B56328, u32@lbl_88B51B5C, u32@0x20 */
void ts4_addr_lbl_88B56328_889F2008(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B56328) + 32) = (ts4_word)(*(ts4_word *)lbl_88B51B5C);
    return;
}

/* Swing_DLL.xex 0x889F2020: call_seq lbl_88B56328, lbl_8803F988, lbl_88CB95DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56328_889F2020(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB95DC, (ts4_word)(ts4_word)lbl_8803F988, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56328, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2090: addr lbl_88B56358, u32@lbl_88B51B5C, u32@0x20 */
void ts4_addr_lbl_88B56358_889F2090(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B56358) + 32) = (ts4_word)(*(ts4_word *)lbl_88B51B5C);
    return;
}

/* Swing_DLL.xex 0x889F20A8: call_seq lbl_88B56358, lbl_8803F974, lbl_88CB960C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56358_889F20A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB960C, (ts4_word)(ts4_word)lbl_8803F974, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56358, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2118: call_seq lbl_88B51D10, lbl_8804E4DC, lbl_88CB963C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51D10_889F2118(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB963C, (ts4_word)(ts4_word)lbl_8804E4DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51D10, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2188: addr lbl_88B56388, u32@lbl_88B51B5C, u32@0x20 */
void ts4_addr_lbl_88B56388_889F2188(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B56388) + 32) = (ts4_word)(*(ts4_word *)lbl_88B51B5C);
    return;
}

/* Swing_DLL.xex 0x889F21A0: call_seq lbl_88B56388, lbl_8803F960, lbl_88CB966C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B56388_889F21A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB966C, (ts4_word)(ts4_word)lbl_8803F960, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B56388, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2210: call_seq lbl_88B51D28, lbl_8803F9B0, lbl_88CB969C, lbl_8804FAA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51D28_889F2210(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB969C, (ts4_word)(ts4_word)lbl_8803F9B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804FAA4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B51D28, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2280: call_seq lbl_88B51D58, lbl_8803F99C, lbl_88CB96CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51D58_889F2280(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB96CC, (ts4_word)(ts4_word)lbl_8803F99C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51D58, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F22F0: call_seq lbl_88B51D88, lbl_8804E4F4, lbl_88CB96FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51D88_889F22F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB96FC, (ts4_word)(ts4_word)lbl_8804E4F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51D88, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2360: call_seq lbl_88B51DB8, lbl_88CB975C, lbl_8804E50C, lbl_88CB972C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51DB8_889F2360(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB972C, (ts4_word)(ts4_word)lbl_8804E50C, (ts4_word)(ts4_word)lbl_88CB975C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51DB8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F23D8: call_seq lbl_88B51DD0, lbl_8804E524, lbl_88CB975C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51DD0_889F23D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB975C, (ts4_word)(ts4_word)lbl_8804E524, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51DD0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F2448: call_seq lbl_88B51E00, lbl_8804E53C, lbl_88CB978C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51E00_889F2448(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB978C, (ts4_word)(ts4_word)lbl_8804E53C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51E00, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889F24B8: call_seq lbl_88B51E18, lbl_8804E560, lbl_88CB97BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B51E18_889F24B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB97BC, (ts4_word)(ts4_word)lbl_8804E560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B51E18, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}
