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

extern char ts4_addr_lbl_8803A308_88AFF5A8[];
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
extern char lbl_8803EFA8[];
extern char lbl_8803EFD0[];
extern char lbl_8803F030[];
extern char lbl_8803F084[];
extern char lbl_8803F094[];
extern char lbl_8803F0AC[];
extern char lbl_8803F5D4[];
extern char lbl_8803F5F4[];
extern char lbl_8803F610[];
extern char lbl_8803F634[];
extern char lbl_8803F64C[];
extern char lbl_8803F660[];
extern char lbl_8803F6CC[];
extern char lbl_8803F6D8[];
extern char lbl_8803F960[];
extern char lbl_8803F974[];
extern char lbl_8803F988[];
extern char lbl_8803F99C[];
extern char lbl_8803F9B0[];
extern char lbl_8803F9C0[];
extern char lbl_8803F9E8[];
extern char lbl_8803FA18[];
extern char lbl_8803FBE0[];
extern char lbl_8803FC80[];
extern char lbl_8803FCA0[];
extern char lbl_8804002C[];
extern char lbl_88040040[];
extern char lbl_88040078[];
extern char lbl_880401D8[];
extern char lbl_880401F0[];
extern char lbl_88040200[];
extern char lbl_88040218[];
extern char lbl_88040228[];
extern char lbl_880402A0[];
extern char lbl_880402B0[];
extern char lbl_880402BC[];
extern char lbl_88040318[];
extern char lbl_8804032C[];
extern char lbl_88040658[];
extern char lbl_88040668[];
extern char lbl_88040DB0[];
extern char lbl_88040E04[];
extern char lbl_88040E18[];
extern char lbl_88040E68[];
extern char lbl_880410F8[];
extern char lbl_88041114[];
extern char lbl_8804115C[];
extern char lbl_8804116C[];
extern char lbl_88041174[];
extern char lbl_88041194[];
extern char lbl_880411C8[];
extern char lbl_880411DC[];
extern char lbl_880411F0[];
extern char lbl_88041204[];
extern char lbl_88041224[];
extern char lbl_88041238[];
extern char lbl_8804124C[];
extern char lbl_88041268[];
extern char lbl_8804159C[];
extern char lbl_880415B4[];
extern char lbl_880415D4[];
extern char lbl_880415F8[];
extern char lbl_88041618[];
extern char lbl_88041634[];
extern char lbl_88041930[];
extern char lbl_88041DE0[];
extern char lbl_88042074[];
extern char lbl_88042098[];
extern char lbl_88042110[];
extern char lbl_88042140[];
extern char lbl_880421C4[];
extern char lbl_880421E0[];
extern char lbl_88042200[];
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
extern char lbl_88045070[];
extern char lbl_88045580[];
extern char lbl_880455E0[];
extern char lbl_880456EC[];
extern char lbl_880457FC[];
extern char lbl_88045914[];
extern char lbl_880459F8[];
extern char lbl_88045A70[];
extern char lbl_88045AA8[];
extern char lbl_88046C00[];
extern char lbl_88046C24[];
extern char lbl_88046C48[];
extern char lbl_88046C60[];
extern char lbl_88046C78[];
extern char lbl_88046C94[];
extern char lbl_8804705C[];
extern char lbl_88047070[];
extern char lbl_8804707C[];
extern char lbl_88048610[];
extern char lbl_8804E4DC[];
extern char lbl_8804E4F4[];
extern char lbl_8804E50C[];
extern char lbl_8804E524[];
extern char lbl_8804E53C[];
extern char lbl_8804E560[];
extern char lbl_88053DD8[];
extern char lbl_88053DE8[];
extern char lbl_88053E90[];
extern char lbl_88053EAC[];
extern char lbl_88053F68[];
extern char lbl_880543A8[];
extern char lbl_88054FBC[];
extern char lbl_88054FD0[];
extern char lbl_88055034[];
extern char lbl_88055098[];
extern char lbl_880550C4[];
extern char lbl_880550D8[];
extern char lbl_880552D0[];
extern char lbl_880552FC[];
extern char lbl_88055328[];
extern char lbl_88055354[];
extern char lbl_88055368[];
extern char lbl_880553C0[];
extern char lbl_88055A3C[];
extern char lbl_88055A78[];
extern char lbl_88055AAC[];
extern char lbl_88055AC8[];
extern char lbl_88055ADC[];
extern char lbl_88055AFC[];
extern char lbl_88055B78[];
extern char lbl_88055C44[];
extern char lbl_88055CC0[];
extern char lbl_88055CD8[];
extern char lbl_88055D24[];
extern char lbl_88055D38[];
extern char lbl_88055D8C[];
extern char lbl_88055DB0[];
extern char lbl_88055DC4[];
extern char lbl_88055DD8[];
extern char lbl_88055F50[];
extern char lbl_88055FA4[];
extern char lbl_88055FE0[];
extern char lbl_88056018[];
extern char lbl_8805605C[];
extern char lbl_8805704C[];
extern char lbl_88B6C7C4[];
extern char lbl_88B6CA80[];
extern char lbl_88B6CAF8[];
extern char lbl_88B6CB40[];
extern char lbl_88B6CB70[];
extern char lbl_88B6CBD0[];
extern char lbl_88B6CC00[];
extern char lbl_88B6CC48[];
extern char lbl_88B6CC78[];
extern char lbl_88B6CC90[];
extern char lbl_88B6CE14[];
extern char lbl_88B6CE44[];
extern char lbl_88B6CE48[];
extern char lbl_88B6CEF0[];
extern char lbl_88B6CF20[];
extern char lbl_88B6CF50[];
extern char lbl_88B6CF68[];
extern char lbl_88B6CF98[];
extern char lbl_88B6CFB0[];
extern char lbl_88B6CFCC[];
extern char lbl_88B6D000[];
extern char lbl_88B6D0A8[];
extern char lbl_88B6D0AC[];
extern char lbl_88B6D0B0[];
extern char lbl_88B6D0B8[];
extern char lbl_88B6D148[];
extern char lbl_88B6D160[];
extern char lbl_88B6D178[];
extern char lbl_88B6D190[];
extern char lbl_88B6D1D8[];
extern char lbl_88B6D1F0[];
extern char lbl_88B6D228[];
extern char lbl_88B6D2D0[];
extern char lbl_88B6D2F0[];
extern char lbl_88B6D350[];
extern char lbl_88B6D368[];
extern char lbl_88B6D3B0[];
extern char lbl_88B6D410[];
extern char lbl_88B6D470[];
extern char lbl_88B6D4D0[];
extern char lbl_88B6D590[];
extern char lbl_88B6D758[];
extern char lbl_88B6D770[];
extern char lbl_88B6D788[];
extern char lbl_88B6D7B8[];
extern char lbl_88B6D7E8[];
extern char lbl_88B6D800[];
extern char lbl_88B6D830[];
extern char lbl_88B6D878[];
extern char lbl_88B6D8C0[];
extern char lbl_88B6D950[];
extern char lbl_88B6D998[];
extern char lbl_88B6D9C8[];
extern char lbl_88B6D9F8[];
extern char lbl_88B6DA28[];
extern char lbl_88B6DA40[];
extern char lbl_88B6DA58[];
extern char lbl_88B6DA88[];
extern char lbl_88B6DAA0[];
extern char lbl_88B6DB90[];
extern char lbl_88B6DD40[];
extern char lbl_88B6DED8[];
extern char lbl_88B6E130[];
extern char lbl_88B6E1A8[];
extern char lbl_88B6E1F0[];
extern char lbl_88B6E220[];
extern char lbl_88B6E280[];
extern char lbl_88B6E2E0[];
extern char lbl_88B6E3D0[];
extern char lbl_88B6E4C0[];
extern char lbl_88B6E508[];
extern char lbl_88B6E5E0[];
extern char lbl_88B6E5F8[];
extern char lbl_88B6E640[];
extern char lbl_88B6E688[];
extern char lbl_88B6E6A0[];
extern char lbl_88B6E6E8[];
extern char lbl_88B6E700[];
extern char lbl_88B6E7A8[];
extern char lbl_88B6E7D8[];
extern char lbl_88B6E820[];
extern char lbl_88B6E868[];
extern char lbl_88B6E8B0[];
extern char lbl_88B6E8C8[];
extern char lbl_88B6E8E0[];
extern char lbl_88B6F450[];
extern char lbl_88B6F468[];
extern char lbl_88B6F4E0[];
extern char lbl_88B6F768[];
extern char lbl_88B6F7E0[];
extern char lbl_88B6F7E4[];
extern char lbl_88B6F814[];
extern char lbl_88B6F848[];
extern char lbl_88B6F8A8[];
extern char lbl_88B6F920[];
extern char lbl_88B6F9C8[];
extern char lbl_88B6F9E0[];
extern char lbl_88B6FA58[];
extern char lbl_88B6FB00[];
extern char lbl_88B6FB18[];
extern char lbl_88B6FB78[];
extern char lbl_88B6FB90[];
extern char lbl_88B6FBD8[];
extern char lbl_88B6FC68[];
extern char lbl_88B6FCF8[];
extern char lbl_88B6FD58[];
extern char lbl_88B6FD88[];
extern char lbl_88B6FDE8[];
extern char lbl_88B6FE50[];
extern char lbl_88B6FF58[];
extern char lbl_88B70078[];
extern char lbl_88B70090[];
extern char lbl_88B70120[];
extern char lbl_88B70168[];
extern char lbl_88B701F8[];
extern char lbl_88B70240[];
extern char lbl_88B70244[];
extern char lbl_88B70274[];
extern char lbl_88B7028C[];
extern char lbl_88B70290[];
extern char lbl_88B70428[];
extern char lbl_88B70440[];
extern char lbl_88B704E8[];
extern char lbl_88B705C0[];
extern char lbl_88B706C8[];
extern char lbl_88B706F8[];
extern char lbl_88B70728[];
extern char lbl_88B707B8[];
extern char lbl_88B707BC[];
extern char lbl_88B707F0[];
extern char lbl_88B70868[];
extern char lbl_88B709A0[];
extern char lbl_88B70A90[];
extern char lbl_88B70AA8[];
extern char lbl_88B70B38[];
extern char lbl_88B70B50[];
extern char lbl_88B70B68[];
extern char lbl_88B70BB0[];
extern char lbl_88B70BF8[];
extern char lbl_88B70D18[];
extern char lbl_88B70D64[];
extern char lbl_88B70D68[];
extern char lbl_88B70DC8[];
extern char lbl_88B70DF8[];
extern char lbl_88B70E28[];
extern char lbl_88B70E5C[];
extern char lbl_88B70E60[];
extern char lbl_88B70F08[];
extern char lbl_88B70F38[];
extern char lbl_88B70F70[];
extern char lbl_88B70FA0[];
extern char lbl_88B70FB8[];
extern char lbl_88B70FC8[];
extern char lbl_88B71010[];
extern char lbl_88B71040[];
extern char lbl_88B71070[];
extern char lbl_88B710D0[];
extern char lbl_88B711C0[];
extern char lbl_88B711D8[];
extern char lbl_88B71250[];
extern char lbl_88B71268[];
extern char lbl_88B7126C[];
extern char lbl_88B7129C[];
extern char lbl_88B712CC[];
extern char lbl_88B712FC[];
extern char lbl_88B71314[];
extern char lbl_88B71344[];
extern char lbl_88B7135C[];
extern char lbl_88B75940[];
extern char lbl_88B75988[];
extern char lbl_88B75AA8[];
extern char lbl_88B75C40[];
extern char lbl_88B75D90[];
extern char lbl_88B75DC0[];
extern char lbl_88B75E80[];
extern char lbl_88B75F10[];
extern char lbl_88B75F40[];
extern char lbl_88B75F70[];
extern char lbl_88CC713C[];
extern char lbl_88CC7BBC[];
extern char lbl_88CC7C7C[];
extern char lbl_88CC8B1C[];
extern char lbl_88CC8B4C[];
extern char lbl_88CC8C0C[];
extern char lbl_88CC923C[];
extern char lbl_88CC926C[];
extern char lbl_88CC929C[];
extern char lbl_88CC92CC[];
extern char lbl_88CC92FC[];
extern char lbl_88CC932C[];
extern char lbl_88CC935C[];
extern char lbl_88CC938C[];
extern char lbl_88CC93BC[];
extern char lbl_88CC93EC[];
extern char lbl_88CC941C[];
extern char lbl_88CC944C[];
extern char lbl_88CC947C[];
extern char lbl_88CC94AC[];
extern char lbl_88CC94DC[];
extern char lbl_88CC950C[];
extern char lbl_88CC953C[];
extern char lbl_88CC956C[];
extern char lbl_88CC959C[];
extern char lbl_88CC95CC[];
extern char lbl_88CC95FC[];
extern char lbl_88CC962C[];
extern char lbl_88CC965C[];
extern char lbl_88CC968C[];
extern char lbl_88CC96BC[];
extern char lbl_88CC96EC[];
extern char lbl_88CC971C[];
extern char lbl_88CC974C[];
extern char lbl_88CC977C[];
extern char lbl_88CC97AC[];
extern char lbl_88CC97DC[];
extern char lbl_88CC980C[];
extern char lbl_88CC986C[];
extern char lbl_88CC989C[];
extern char lbl_88CC98CC[];
extern char lbl_88CC98FC[];
extern char lbl_88CC992C[];
extern char lbl_88CC995C[];
extern char lbl_88CC998C[];
extern char lbl_88CC99BC[];
extern char lbl_88CC99EC[];
extern char lbl_88CC9A1C[];
extern char lbl_88CC9A4C[];
extern char lbl_88CC9A7C[];
extern char lbl_88CC9AAC[];
extern char lbl_88CC9ADC[];
extern char lbl_88CC9B0C[];
extern char lbl_88CC9B3C[];
extern char lbl_88CC9B6C[];
extern char lbl_88CC9B9C[];
extern char lbl_88CC9BCC[];
extern char lbl_88CC9BFC[];
extern char lbl_88CC9C2C[];
extern char lbl_88CC9C5C[];
extern char lbl_88CC9C8C[];
extern char lbl_88CC9CBC[];
extern char lbl_88CC9CEC[];
extern char lbl_88CC9D1C[];
extern char lbl_88CC9D4C[];
extern char lbl_88CC9D7C[];
extern char lbl_88CC9DAC[];
extern char lbl_88CC9DDC[];
extern char lbl_88CC9E0C[];
extern char lbl_88CC9E3C[];
extern char lbl_88CC9E6C[];
extern char lbl_88CC9E9C[];
extern char lbl_88CC9ECC[];
extern char lbl_88CC9EFC[];
extern char lbl_88CC9F2C[];
extern char lbl_88CC9F5C[];
extern char lbl_88CC9F8C[];
extern char lbl_88CC9FBC[];
extern char lbl_88CC9FEC[];
extern char lbl_88CCA01C[];
extern char lbl_88CCA04C[];
extern char lbl_88CCA07C[];
extern char lbl_88CCA0AC[];
extern char lbl_88CCA0DC[];
extern char lbl_88CCA10C[];
extern char lbl_88CCA13C[];
extern char lbl_88CCA16C[];
extern char lbl_88CCA19C[];
extern char lbl_88CCA1CC[];
extern char lbl_88CCA1FC[];
extern char lbl_88CCA22C[];
extern char lbl_88CCA25C[];
extern char lbl_88CCA28C[];
extern char lbl_88CCA2BC[];
extern char lbl_88CCA2EC[];
extern char lbl_88CCA31C[];
extern char lbl_88CCA34C[];
extern char lbl_88CCA37C[];
extern char lbl_88CCA3AC[];
extern char lbl_88CCA3DC[];
extern char lbl_88CCA40C[];
extern char lbl_88CCA43C[];
extern char lbl_88CCA46C[];
extern char lbl_88CCA49C[];
extern char lbl_88CCA4CC[];
extern char lbl_88CCA4FC[];
extern char lbl_88CCA52C[];
extern char lbl_88CCA55C[];
extern char lbl_88CCA574[];
extern char lbl_88CCA5A4[];
extern char lbl_88CCA5D4[];
extern char lbl_88CCA604[];
extern char lbl_88CCA634[];
extern char lbl_88CCA664[];
extern char lbl_88CCA694[];
extern char lbl_88CCA6C4[];
extern char lbl_88CCA6F4[];
extern char lbl_88CCA724[];
extern char lbl_88CCA754[];
extern char lbl_88CCA784[];
extern char lbl_88CCA7B4[];
extern char lbl_88CCA7E4[];
extern char lbl_88CCA814[];
extern char lbl_88CCA844[];
extern char lbl_88CCA874[];
extern char lbl_88CCA8A4[];
extern char lbl_88CCA8D4[];
extern char lbl_88CCA904[];
extern char lbl_88CCA934[];
extern char lbl_88CCA964[];
extern char lbl_88CCA994[];
extern char lbl_88CCA9C4[];
extern char lbl_88CCA9F4[];
extern char lbl_88CCAA24[];
extern char lbl_88CCAA54[];
extern char lbl_88CCAA84[];
extern char lbl_88CCAAB4[];
extern char lbl_88CCAAE4[];
extern char lbl_88CCAB44[];
extern char lbl_88CCAB74[];
extern char lbl_88CCABA4[];
extern char lbl_88CCABD4[];
extern char lbl_88CCAC04[];
extern char lbl_88CCAC34[];
extern char lbl_88CCAC64[];
extern char lbl_88CCAC94[];
extern char lbl_88CCACC4[];
extern char lbl_88CCAD24[];
extern char lbl_88CCAD54[];
extern char lbl_88CCADB4[];
extern char lbl_88CCADE4[];
extern char lbl_88CCAE14[];
extern char lbl_88CCAE44[];
extern char lbl_88CCAE74[];
extern char lbl_88CCAEA4[];
extern char lbl_88CCAED4[];
extern char lbl_88CCAF04[];
extern char lbl_88CCAF34[];
extern char lbl_88CCAF64[];
extern char lbl_88CCAF94[];
extern char lbl_88CCAFC4[];
extern char lbl_88CCAFF4[];
extern char lbl_88CCB024[];
extern char lbl_88CCB054[];
extern char lbl_88CCB084[];
extern char lbl_88CCB0B4[];
extern char lbl_88CCB0E4[];
extern char lbl_88CCB114[];
extern char lbl_88CCB144[];
extern char lbl_88CCB174[];
extern char lbl_88CCB1A4[];
extern char lbl_88CCB1D4[];
extern char lbl_88CCB204[];
extern char lbl_88CCB234[];
extern char lbl_88CCB264[];
extern char lbl_88CCB294[];
extern char lbl_88CCB2C4[];
extern char lbl_88CCB2F4[];
extern char lbl_88CCB324[];
extern char lbl_88CCB354[];
extern char lbl_88CCB384[];
extern char lbl_88CCB3B4[];
extern char lbl_88CCB3E4[];
extern char lbl_88CCB414[];
extern char lbl_88CCB444[];
extern char lbl_88CCB474[];
extern char lbl_88CCB4A4[];
extern char lbl_88CCB4D4[];
extern char lbl_88CCB504[];
extern char lbl_88CCB534[];
extern char lbl_88CCB564[];
extern char lbl_88CCB594[];
extern char lbl_88CCB5C4[];
ts4_word fn_8841F080();
ts4_word ts4_set_u32_offc_884CE988();
ts4_word fn_88563470();

/* Swing_DLL.xex 0x88A182B8: call_seq lbl_88B6CA80, lbl_880422F8, lbl_88CC923C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6CA80_88A182B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC923C, (ts4_word)(ts4_word)lbl_880422F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6CA80, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18328: call_seq lbl_88B6CAF8, lbl_88CC8C0C, lbl_8803FA18, lbl_88CC926C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6CAF8_88A18328(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC926C, (ts4_word)(ts4_word)lbl_8803FA18, (ts4_word)(ts4_word)lbl_88CC8C0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6CAF8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A183A0: addr lbl_88B6F450, u32@lbl_88B6C7C4, u32@0x8 */
void ts4_addr_lbl_88B6F450_88A183A0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6F450) + 8) = (ts4_word)(*(ts4_word *)lbl_88B6C7C4);
    return;
}

/* Swing_DLL.xex 0x88A183B8: call_seq lbl_88B6F450, lbl_88CC713C, lbl_8803FBE0, lbl_88CC929C, lbl_88054FBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6F450_88A183B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC929C, (ts4_word)(ts4_word)lbl_8803FBE0, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88054FBC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6F450, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18428: call_seq lbl_88B6CB40, lbl_88CC929C, lbl_88045A70, lbl_88CC92CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6CB40_88A18428(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC92CC, (ts4_word)(ts4_word)lbl_88045A70, (ts4_word)(ts4_word)lbl_88CC929C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6CB40, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A184A0: call_seq lbl_88B6CB70, lbl_88CC92CC, lbl_8803FCA0, lbl_88CC92FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6CB70_88A184A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC92FC, (ts4_word)(ts4_word)lbl_8803FCA0, (ts4_word)(ts4_word)lbl_88CC92CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6CB70, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18518: call_seq lbl_88B6CBD0, lbl_88CC92CC, lbl_8803FC80, lbl_88CC932C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6CBD0_88A18518(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC932C, (ts4_word)(ts4_word)lbl_8803FC80, (ts4_word)(ts4_word)lbl_88CC92CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6CBD0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18590: call_seq lbl_88B6CC00, lbl_88CC92CC, lbl_8803F9E8, lbl_88CC935C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6CC00_88A18590(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC935C, (ts4_word)(ts4_word)lbl_8803F9E8, (ts4_word)(ts4_word)lbl_88CC92CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6CC00, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18608: call_seq lbl_88B6CC48, lbl_88042200, lbl_88CC938C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6CC48_88A18608(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC938C, (ts4_word)(ts4_word)lbl_88042200, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6CC48, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18678: call_seq lbl_88B6CC78, lbl_88CC8C0C, lbl_8804032C, lbl_88CC93BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6CC78_88A18678(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC93BC, (ts4_word)(ts4_word)lbl_8804032C, (ts4_word)(ts4_word)lbl_88CC8C0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6CC78, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A186F0: call_seq lbl_88054FD0, lbl_88B6CC90, lbl_88CC986C, lbl_8803F6CC, lbl_88CC93EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88054FD0_88A186F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC93EC, (ts4_word)(ts4_word)lbl_8803F6CC, (ts4_word)(ts4_word)lbl_88CC986C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6CC90, (ts4_word)16, (ts4_word)(ts4_word)lbl_88054FD0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18768: call_seq lbl_88CC713C, lbl_88045AA8, lbl_88CC941C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC713C_88A18768(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC941C, (ts4_word)(ts4_word)lbl_88045AA8, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A187D0: call_seq lbl_88CC94AC, lbl_880457FC, lbl_88CC944C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC94AC_88A187D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC944C, (ts4_word)(ts4_word)lbl_880457FC, (ts4_word)(ts4_word)lbl_88CC94AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18838: call_seq lbl_88CC93EC, lbl_880455E0, lbl_88CC947C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC93EC_88A18838(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC947C, (ts4_word)(ts4_word)lbl_880455E0, (ts4_word)(ts4_word)lbl_88CC93EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A188A0: call_seq lbl_88055034, lbl_88CC941C, lbl_880459F8, lbl_88CC94AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88055034_88A188A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC94AC, (ts4_word)(ts4_word)lbl_880459F8, (ts4_word)(ts4_word)lbl_88CC941C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88055034, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18908: call_seq lbl_88B6CE14, lbl_88045070, lbl_88CC94DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6CE14_88A18908(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC94DC, (ts4_word)(ts4_word)lbl_88045070, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6CE14, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18978: call_seq lbl_88B6CE48, lbl_88CC94AC, lbl_88041DE0, lbl_88CC950C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6CE48_88A18978(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC950C, (ts4_word)(ts4_word)lbl_88041DE0, (ts4_word)(ts4_word)lbl_88CC94AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6CE48, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A189F0: addr lbl_88B6F468, u32@lbl_88B6CE44, u32@0x8 */
void ts4_addr_lbl_88B6F468_88A189F0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6F468) + 8) = (ts4_word)(*(ts4_word *)lbl_88B6CE44);
    return;
}

/* Swing_DLL.xex 0x88A18A08: call_seq lbl_88B6F468, lbl_88CC713C, lbl_8803F5D4, lbl_88CC953C, lbl_88055098, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6F468_88A18A08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC953C, (ts4_word)(ts4_word)lbl_8803F5D4, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88055098, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6F468, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18A80: call_seq lbl_88CC953C, lbl_880402B0, lbl_88CC956C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC953C_88A18A80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC956C, (ts4_word)(ts4_word)lbl_880402B0, (ts4_word)(ts4_word)lbl_88CC953C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18AE8: call_seq lbl_88CC95CC, lbl_88040E04, lbl_88CC959C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC95CC_88A18AE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC959C, (ts4_word)(ts4_word)lbl_88040E04, (ts4_word)(ts4_word)lbl_88CC95CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18B50: call_seq lbl_88B6CEF0, lbl_88CC953C, lbl_8803EFA8, lbl_88CC95CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6CEF0_88A18B50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC95CC, (ts4_word)(ts4_word)lbl_8803EFA8, (ts4_word)(ts4_word)lbl_88CC953C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6CEF0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18BC8: call_seq lbl_88CC95CC, lbl_880456EC, lbl_88CC95FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC95CC_88A18BC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC95FC, (ts4_word)(ts4_word)lbl_880456EC, (ts4_word)(ts4_word)lbl_88CC95CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18C30: call_seq lbl_88CC953C, lbl_880402A0, lbl_88CC962C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC953C_88A18C30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC962C, (ts4_word)(ts4_word)lbl_880402A0, (ts4_word)(ts4_word)lbl_88CC953C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18C98: call_seq lbl_88CC956C, lbl_88040E18, lbl_88CC965C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC956C_88A18C98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC965C, (ts4_word)(ts4_word)lbl_88040E18, (ts4_word)(ts4_word)lbl_88CC956C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18D00: call_seq lbl_88CC962C, lbl_88040E68, lbl_88CC968C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC962C_88A18D00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC968C, (ts4_word)(ts4_word)lbl_88040E68, (ts4_word)(ts4_word)lbl_88CC962C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18D68: call_seq lbl_88CC956C, lbl_88040DB0, lbl_88CC96BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC956C_88A18D68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC96BC, (ts4_word)(ts4_word)lbl_88040DB0, (ts4_word)(ts4_word)lbl_88CC956C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18DD0: call_seq lbl_88B6CF20, lbl_88CC974C, lbl_8803F6D8, lbl_88CC96EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6CF20_88A18DD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC96EC, (ts4_word)(ts4_word)lbl_8803F6D8, (ts4_word)(ts4_word)lbl_88CC974C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6CF20, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18E48: call_seq lbl_88B6CF50, lbl_88CC977C, lbl_88045914, lbl_88CC971C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6CF50_88A18E48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC971C, (ts4_word)(ts4_word)lbl_88045914, (ts4_word)(ts4_word)lbl_88CC977C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6CF50, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18EC0: call_seq lbl_88B6CF68, lbl_88CC986C, lbl_88047070, lbl_88CC974C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6CF68_88A18EC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC974C, (ts4_word)(ts4_word)lbl_88047070, (ts4_word)(ts4_word)lbl_88CC986C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6CF68, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18F38: call_seq lbl_88B6CF98, lbl_88CC974C, lbl_880402BC, lbl_88CC977C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6CF98_88A18F38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC977C, (ts4_word)(ts4_word)lbl_880402BC, (ts4_word)(ts4_word)lbl_88CC974C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6CF98, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A18FB0: call_seq lbl_88B6CFB0, lbl_88CC977C, lbl_88045580, lbl_88CC97AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6CFB0_88A18FB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC97AC, (ts4_word)(ts4_word)lbl_88045580, (ts4_word)(ts4_word)lbl_88CC977C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6CFB0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19028: call_seq lbl_88B6CFCC, lbl_8803F9C0, lbl_88CC97DC, lbl_880550C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6CFCC_88A19028(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC97DC, (ts4_word)(ts4_word)lbl_8803F9C0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880550C4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6CFCC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19098: call_seq lbl_880550D8, lbl_88B6D000, lbl_88CC713C, lbl_8803F660, lbl_88CC980C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880550D8_88A19098(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC980C, (ts4_word)(ts4_word)lbl_8803F660, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D000, (ts4_word)7, (ts4_word)(ts4_word)lbl_880550D8, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19110: get u32@lbl_88B6D0B0, lbl_88B6F4E0, u32@lbl_88B6D0AC, u32@lbl_88B6D0A8, u32@0x50, u32@0x110 */
void ts4_get_u32_lbl_88B6D0B0_88A19110(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88B6D0B0;
    t2 = *(ts4_word *)lbl_88B6D0AC;
    t3 = *(ts4_word *)lbl_88B6D0A8;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6F4E0) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6F4E0) + 272) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6F4E0) + 560) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x88A191B8: call_seq lbl_88B6D0B8, lbl_88CC713C, lbl_8803F084, lbl_88CC986C, lbl_880552D0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D0B8_88A191B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC986C, (ts4_word)(ts4_word)lbl_8803F084, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880552D0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6D0B8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19230: call_seq lbl_88B6D148, lbl_88CC713C, lbl_8804707C, lbl_88CC989C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D148_88A19230(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC989C, (ts4_word)(ts4_word)lbl_8804707C, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D148, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A192A8: call_seq lbl_88B6D160, lbl_88CC7BBC, lbl_88044F38, lbl_88CC98CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D160_88A192A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC98CC, (ts4_word)(ts4_word)lbl_88044F38, (ts4_word)(ts4_word)lbl_88CC7BBC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D160, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19320: call_seq lbl_88B6D178, lbl_88042E20, lbl_88CC98FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D178_88A19320(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC98FC, (ts4_word)(ts4_word)lbl_88042E20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D178, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19390: call_seq lbl_88B6D190, lbl_88CC713C, lbl_8803EFD0, lbl_88CC992C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D190_88A19390(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC992C, (ts4_word)(ts4_word)lbl_8803EFD0, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D190, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19408: call_seq lbl_88B6D1D8, lbl_88044F10, lbl_88CC995C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D1D8_88A19408(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC995C, (ts4_word)(ts4_word)lbl_88044F10, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D1D8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19478: call_seq lbl_88B6D1F0, lbl_88CC713C, lbl_88044F90, lbl_88CC998C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D1F0_88A19478(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC998C, (ts4_word)(ts4_word)lbl_88044F90, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D1F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A194F0: call_seq lbl_88B6D228, lbl_880421E0, lbl_88CC99BC, lbl_88055328, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D228_88A194F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC99BC, (ts4_word)(ts4_word)lbl_880421E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88055328, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6D228, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19560: call_seq lbl_88B6D2D0, lbl_88CC8C0C, lbl_8803F030, lbl_88CC99EC, lbl_880552FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D2D0_88A19560(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC99EC, (ts4_word)(ts4_word)lbl_8803F030, (ts4_word)(ts4_word)lbl_88CC8C0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880552FC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6D2D0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A195D0: call_seq lbl_88B6D2F0, lbl_880421C4, lbl_88CC9A1C, lbl_88055354, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D2F0_88A195D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9A1C, (ts4_word)(ts4_word)lbl_880421C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88055354, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6D2F0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19640: call_seq lbl_88B6D350, lbl_88CC8C0C, lbl_88040318, lbl_88CC9A4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D350_88A19640(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9A4C, (ts4_word)(ts4_word)lbl_88040318, (ts4_word)(ts4_word)lbl_88CC8C0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D350, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A196B8: call_seq lbl_88B6D368, lbl_88CC8B1C, lbl_88044EA8, lbl_88CC9A7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D368_88A196B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9A7C, (ts4_word)(ts4_word)lbl_88044EA8, (ts4_word)(ts4_word)lbl_88CC8B1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D368, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19730: call_seq lbl_88B6D3B0, lbl_88CC8B1C, lbl_88044E64, lbl_88CC9AAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D3B0_88A19730(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9AAC, (ts4_word)(ts4_word)lbl_88044E64, (ts4_word)(ts4_word)lbl_88CC8B1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D3B0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A197A8: call_seq lbl_88B6D410, lbl_88CC8B4C, lbl_88044DD0, lbl_88CC9ADC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D410_88A197A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9ADC, (ts4_word)(ts4_word)lbl_88044DD0, (ts4_word)(ts4_word)lbl_88CC8B4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D410, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19820: call_seq lbl_88B6D470, lbl_88CC8B4C, lbl_88044CD0, lbl_88CC9B0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D470_88A19820(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9B0C, (ts4_word)(ts4_word)lbl_88044CD0, (ts4_word)(ts4_word)lbl_88CC8B4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D470, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19898: call_seq lbl_88B6D4D0, lbl_88CC8B1C, lbl_88044BD4, lbl_88CC9B3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D4D0_88A19898(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9B3C, (ts4_word)(ts4_word)lbl_88044BD4, (ts4_word)(ts4_word)lbl_88CC8B1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D4D0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19910: call_seq lbl_88B6D590, lbl_88055368, lbl_8803F094, lbl_88CC9B6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D590_88A19910(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9B6C, (ts4_word)(ts4_word)lbl_8803F094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D590, (ts4_word)19, (ts4_word)(ts4_word)lbl_88055368, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19988: call_seq lbl_88B6D758, lbl_88CC7C7C, lbl_8803F0AC, lbl_88CC9B9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D758_88A19988(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9B9C, (ts4_word)(ts4_word)lbl_8803F0AC, (ts4_word)(ts4_word)lbl_88CC7C7C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D758, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19A00: call_seq lbl_88B6D770, lbl_88CC7C7C, lbl_88044E30, lbl_88CC9BCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D770_88A19A00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9BCC, (ts4_word)(ts4_word)lbl_88044E30, (ts4_word)(ts4_word)lbl_88CC7C7C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D770, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19A78: call_seq lbl_88B6D788, lbl_88CC7C7C, lbl_88044DF8, lbl_88CC9BFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D788_88A19A78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9BFC, (ts4_word)(ts4_word)lbl_88044DF8, (ts4_word)(ts4_word)lbl_88CC7C7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D788, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19AF0: call_seq lbl_88B6D7B8, lbl_88044B54, lbl_88CC9C2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D7B8_88A19AF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9C2C, (ts4_word)(ts4_word)lbl_88044B54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D7B8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19B60: call_seq lbl_88B6D7E8, lbl_88CC7C7C, lbl_88044D8C, lbl_88CC9C5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D7E8_88A19B60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9C5C, (ts4_word)(ts4_word)lbl_88044D8C, (ts4_word)(ts4_word)lbl_88CC7C7C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D7E8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19BD8: call_seq lbl_88B6D800, lbl_88044A90, lbl_88CC9C8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D800_88A19BD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9C8C, (ts4_word)(ts4_word)lbl_88044A90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D800, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19C48: call_seq lbl_88B6D830, lbl_88044ACC, lbl_88CC9CBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D830_88A19C48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9CBC, (ts4_word)(ts4_word)lbl_88044ACC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D830, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19CB8: call_seq lbl_88B6D878, lbl_88CC713C, lbl_88044CFC, lbl_88CC9CEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D878_88A19CB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9CEC, (ts4_word)(ts4_word)lbl_88044CFC, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D878, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19D30: call_seq lbl_88B6D8C0, lbl_88CC8B4C, lbl_8804705C, lbl_88CC9D1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D8C0_88A19D30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9D1C, (ts4_word)(ts4_word)lbl_8804705C, (ts4_word)(ts4_word)lbl_88CC8B4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D8C0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19DA8: call_seq lbl_88B6D950, lbl_88044A58, lbl_88CC9D4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D950_88A19DA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9D4C, (ts4_word)(ts4_word)lbl_88044A58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D950, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19E18: call_seq lbl_88B6D998, lbl_88044B0C, lbl_88CC9D7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D998_88A19E18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9D7C, (ts4_word)(ts4_word)lbl_88044B0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D998, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19E88: call_seq lbl_88B6D9C8, lbl_88044B94, lbl_88CC9DAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D9C8_88A19E88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9DAC, (ts4_word)(ts4_word)lbl_88044B94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D9C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19EF8: call_seq lbl_88B6D9F8, lbl_88CC713C, lbl_88044D60, lbl_88CC9DDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6D9F8_88A19EF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9DDC, (ts4_word)(ts4_word)lbl_88044D60, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6D9F8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19F70: call_seq lbl_88B6DA28, lbl_88CC713C, lbl_88044C84, lbl_88CC9E0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6DA28_88A19F70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9E0C, (ts4_word)(ts4_word)lbl_88044C84, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6DA28, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A19FE8: call_seq lbl_88B6DA40, lbl_88CC713C, lbl_88044C48, lbl_88CC9E3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6DA40_88A19FE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9E3C, (ts4_word)(ts4_word)lbl_88044C48, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6DA40, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A060: call_seq lbl_88B6DA58, lbl_88044A08, lbl_88CC9E6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6DA58_88A1A060(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9E6C, (ts4_word)(ts4_word)lbl_88044A08, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6DA58, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A0D0: call_seq lbl_88B6DA88, lbl_88CC713C, lbl_88044C08, lbl_88CC9E9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6DA88_88A1A0D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9E9C, (ts4_word)(ts4_word)lbl_88044C08, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6DA88, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A148: call_seq lbl_88B6DAA0, lbl_88040668, lbl_88CC9ECC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6DAA0_88A1A148(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9ECC, (ts4_word)(ts4_word)lbl_88040668, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6DAA0, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A1B8: call_seq lbl_88B6DB90, lbl_88CC713C, lbl_88040658, lbl_88CC9EFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6DB90_88A1A1B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9EFC, (ts4_word)(ts4_word)lbl_88040658, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6DB90, (ts4_word)18, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A230: call_seq lbl_88B6DD40, lbl_8803F5F4, lbl_88CC9F2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6DD40_88A1A230(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9F2C, (ts4_word)(ts4_word)lbl_8803F5F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6DD40, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A2A0: call_seq lbl_88B6DED8, lbl_88CC8B4C, lbl_8803F64C, lbl_88CC9F5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6DED8_88A1A2A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9F5C, (ts4_word)(ts4_word)lbl_8803F64C, (ts4_word)(ts4_word)lbl_88CC8B4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6DED8, (ts4_word)25, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A318: call_seq lbl_88CC713C, lbl_8804494C, lbl_88CC9F8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC713C_88A1A318(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9F8C, (ts4_word)(ts4_word)lbl_8804494C, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A380: call_seq lbl_88B6E130, lbl_88CC9F8C, lbl_88044700, lbl_88CC9FBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E130_88A1A380(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9FBC, (ts4_word)(ts4_word)lbl_88044700, (ts4_word)(ts4_word)lbl_88CC9F8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E130, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A3F8: call_seq lbl_88CC713C, lbl_88044924, lbl_88CC9FEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC713C_88A1A3F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC9FEC, (ts4_word)(ts4_word)lbl_88044924, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A460: call_seq lbl_88B6E1A8, lbl_88044438, lbl_88CCA01C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E1A8_88A1A460(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA01C, (ts4_word)(ts4_word)lbl_88044438, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E1A8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A4D0: call_seq lbl_88B6E1F0, lbl_88CC9FEC, lbl_88044680, lbl_88CCA04C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E1F0_88A1A4D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA04C, (ts4_word)(ts4_word)lbl_88044680, (ts4_word)(ts4_word)lbl_88CC9FEC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E1F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A548: call_seq lbl_88CC713C, lbl_880448C8, lbl_88CCA07C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC713C_88A1A548(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA07C, (ts4_word)(ts4_word)lbl_880448C8, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A5B0: call_seq lbl_88CC713C, lbl_880448FC, lbl_88CCA0AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC713C_88A1A5B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA0AC, (ts4_word)(ts4_word)lbl_880448FC, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A618: call_seq lbl_88B6E220, lbl_88CCA07C, lbl_88044524, lbl_88CCA0DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E220_88A1A618(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA0DC, (ts4_word)(ts4_word)lbl_88044524, (ts4_word)(ts4_word)lbl_88CCA07C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E220, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A690: call_seq lbl_88B6E280, lbl_88CCA0AC, lbl_880446BC, lbl_88CCA10C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E280_88A1A690(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA10C, (ts4_word)(ts4_word)lbl_880446BC, (ts4_word)(ts4_word)lbl_88CCA0AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E280, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A708: call_seq lbl_88CC713C, lbl_8804489C, lbl_88CCA13C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC713C_88A1A708(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA13C, (ts4_word)(ts4_word)lbl_8804489C, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A770: call_seq lbl_88B6E2E0, lbl_88CCA13C, lbl_88044650, lbl_88CCA16C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E2E0_88A1A770(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA16C, (ts4_word)(ts4_word)lbl_88044650, (ts4_word)(ts4_word)lbl_88CCA13C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E2E0, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A7E8: call_seq lbl_88B6E3D0, lbl_88044324, lbl_88CCA19C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E3D0_88A1A7E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA19C, (ts4_word)(ts4_word)lbl_88044324, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E3D0, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A858: call_seq lbl_88B6E4C0, lbl_88044370, lbl_88CCA1CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E4C0_88A1A858(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA1CC, (ts4_word)(ts4_word)lbl_88044370, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E4C0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A8C8: call_seq lbl_88B6E508, lbl_8803F610, lbl_88CCA1FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E508_88A1A8C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA1FC, (ts4_word)(ts4_word)lbl_8803F610, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E508, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A938: call_seq lbl_88B6E5E0, lbl_8803F634, lbl_88CCA22C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E5E0_88A1A938(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA22C, (ts4_word)(ts4_word)lbl_8803F634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E5E0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1A9A8: call_seq lbl_88CC713C, lbl_88044874, lbl_88CCA25C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC713C_88A1A9A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA25C, (ts4_word)(ts4_word)lbl_88044874, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1AA10: call_seq lbl_88B6E5F8, lbl_88CCA25C, lbl_8804461C, lbl_88CCA28C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E5F8_88A1AA10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA28C, (ts4_word)(ts4_word)lbl_8804461C, (ts4_word)(ts4_word)lbl_88CCA25C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E5F8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1AA88: call_seq lbl_88B6E640, lbl_88044268, lbl_88CCA2BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E640_88A1AA88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA2BC, (ts4_word)(ts4_word)lbl_88044268, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E640, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1AAF8: call_seq lbl_88B6E688, lbl_88CC713C, lbl_8804484C, lbl_88CCA2EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E688_88A1AAF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA2EC, (ts4_word)(ts4_word)lbl_8804484C, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E688, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1AB70: call_seq lbl_88B6E6A0, lbl_880443CC, lbl_88CCA31C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E6A0_88A1AB70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA31C, (ts4_word)(ts4_word)lbl_880443CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E6A0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1ABE0: call_seq lbl_88B6E6E8, lbl_88CCA2EC, lbl_880445E4, lbl_88CCA34C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E6E8_88A1ABE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA34C, (ts4_word)(ts4_word)lbl_880445E4, (ts4_word)(ts4_word)lbl_88CCA2EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E6E8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1AC58: call_seq lbl_88CC713C, lbl_8804481C, lbl_88CCA37C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC713C_88A1AC58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA37C, (ts4_word)(ts4_word)lbl_8804481C, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1ACC0: call_seq lbl_88B6E700, lbl_88CCA37C, lbl_880445A8, lbl_88CCA3AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E700_88A1ACC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA3AC, (ts4_word)(ts4_word)lbl_880445A8, (ts4_word)(ts4_word)lbl_88CCA37C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E700, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1AD38: call_seq lbl_88B6E7A8, lbl_8804449C, lbl_88CCA3DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E7A8_88A1AD38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA3DC, (ts4_word)(ts4_word)lbl_8804449C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E7A8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1ADA8: call_seq lbl_88B6E7D8, lbl_88CC713C, lbl_88044744, lbl_88CCA40C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E7D8_88A1ADA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA40C, (ts4_word)(ts4_word)lbl_88044744, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E7D8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1AE20: call_seq lbl_88B6E820, lbl_88CC713C, lbl_88044758, lbl_88CCA43C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E820_88A1AE20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA43C, (ts4_word)(ts4_word)lbl_88044758, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E820, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1AE98: call_seq lbl_88CC713C, lbl_880447EC, lbl_88CCA46C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC713C_88A1AE98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA46C, (ts4_word)(ts4_word)lbl_880447EC, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1AF00: call_seq lbl_88B6E868, lbl_88CCA46C, lbl_88044568, lbl_88CCA49C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E868_88A1AF00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA49C, (ts4_word)(ts4_word)lbl_88044568, (ts4_word)(ts4_word)lbl_88CCA46C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E868, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1AF78: call_seq lbl_88B6E8B0, lbl_88CC713C, lbl_880447B8, lbl_88CCA4CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E8B0_88A1AF78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA4CC, (ts4_word)(ts4_word)lbl_880447B8, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E8B0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1AFF0: call_seq lbl_88B6E8C8, lbl_88CC713C, lbl_88044784, lbl_88CCA4FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E8C8_88A1AFF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA4FC, (ts4_word)(ts4_word)lbl_88044784, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E8C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B068: call_seq lbl_88B6E8E0, lbl_88CCA4CC, lbl_880444CC, lbl_88CCA52C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6E8E0_88A1B068(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA52C, (ts4_word)(ts4_word)lbl_880444CC, (ts4_word)(ts4_word)lbl_88CCA4CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6E8E0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B0E0: call_seq lbl_880543A8, lbl_880553C0, lbl_88CCA55C, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF5A8, fn_88563470 */
ts4_word ts4_call_seq_lbl_880543A8_88A1B0E0(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CCA55C, (ts4_word)(ts4_word)lbl_880553C0, (ts4_word)3, (ts4_word)(ts4_word)lbl_880543A8);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF5A8);
    return t2;
}

/* Swing_DLL.xex 0x88A1B128: call_seq lbl_88B6F768, lbl_88046C94, lbl_88CCA574, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6F768_88A1B128(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA574, (ts4_word)(ts4_word)lbl_88046C94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6F768, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B198: addr lbl_88B75940, u32@lbl_88B6F7E0, u32@0x38 */
void ts4_addr_lbl_88B75940_88A1B198(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B75940) + 56) = (ts4_word)(*(ts4_word *)lbl_88B6F7E0);
    return;
}

/* Swing_DLL.xex 0x88A1B1B0: call_seq lbl_88055A3C, lbl_88B75940, lbl_8803EF04, lbl_88CCA5A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88055A3C_88A1B1B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA5A4, (ts4_word)(ts4_word)lbl_8803EF04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88055A3C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B75940, (ts4_word)3, (ts4_word)((ts4_word)lbl_88055A3C + 20), (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B228: call_seq lbl_88B6F7E4, lbl_88046C78, lbl_88CCA5D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6F7E4_88A1B228(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA5D4, (ts4_word)(ts4_word)lbl_88046C78, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6F7E4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B298: call_seq lbl_88B6F814, lbl_8803EC6C, lbl_88CCA604, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6F814_88A1B298(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA604, (ts4_word)(ts4_word)lbl_8803EC6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6F814, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B308: call_seq lbl_88B6F848, lbl_88CCB114, lbl_8803EE48, lbl_88CCA634, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6F848_88A1B308(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA634, (ts4_word)(ts4_word)lbl_8803EE48, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6F848, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B380: call_seq lbl_88B6F8A8, lbl_88040040, lbl_88CCA664, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6F8A8_88A1B380(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA664, (ts4_word)(ts4_word)lbl_88040040, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6F8A8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B3F0: call_seq lbl_88B6F920, lbl_88CCA634, lbl_8803ECD0, lbl_88CCA694, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6F920_88A1B3F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA694, (ts4_word)(ts4_word)lbl_8803ECD0, (ts4_word)(ts4_word)lbl_88CCA634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6F920, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B468: call_seq lbl_88B6F9C8, lbl_88CCA634, lbl_8803ECB0, lbl_88CCA6C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6F9C8_88A1B468(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA6C4, (ts4_word)(ts4_word)lbl_8803ECB0, (ts4_word)(ts4_word)lbl_88CCA634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6F9C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B4E0: call_seq lbl_88B6F9E0, lbl_88040078, lbl_88CCA6F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6F9E0_88A1B4E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA6F4, (ts4_word)(ts4_word)lbl_88040078, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6F9E0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B550: call_seq lbl_88B6FA58, lbl_88CCA634, lbl_8803EC94, lbl_88CCA724, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6FA58_88A1B550(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA724, (ts4_word)(ts4_word)lbl_8803EC94, (ts4_word)(ts4_word)lbl_88CCA634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6FA58, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B5C8: call_seq lbl_88B6FB00, lbl_88046C60, lbl_88CCA754, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6FB00_88A1B5C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA754, (ts4_word)(ts4_word)lbl_88046C60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6FB00, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B638: call_seq lbl_88B6FB18, lbl_8803EE88, lbl_88CCA784, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6FB18_88A1B638(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA784, (ts4_word)(ts4_word)lbl_8803EE88, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6FB18, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B6A8: call_seq lbl_88B6FB78, lbl_88CCB114, lbl_8804002C, lbl_88CCA7B4, lbl_88055A78, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6FB78_88A1B6A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA7B4, (ts4_word)(ts4_word)lbl_8804002C, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88055A78, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6FB78, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B718: call_seq lbl_88B6FB90, lbl_88046C00, lbl_88CCA7E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6FB90_88A1B718(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA7E4, (ts4_word)(ts4_word)lbl_88046C00, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6FB90, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B788: call_seq lbl_88B6FBD8, lbl_88046C24, lbl_88CCA814, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6FBD8_88A1B788(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA814, (ts4_word)(ts4_word)lbl_88046C24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6FBD8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B7F8: call_seq lbl_88B6FC68, lbl_88046C48, lbl_88CCA844, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6FC68_88A1B7F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA844, (ts4_word)(ts4_word)lbl_88046C48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6FC68, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B868: call_seq lbl_88CCB114, lbl_8803EC3C, lbl_88CCA874, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCB114_88A1B868(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA874, (ts4_word)(ts4_word)lbl_8803EC3C, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B8D0: call_seq lbl_88B6FCF8, lbl_88CCA874, lbl_8803ECF4, lbl_88CCA8A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6FCF8_88A1B8D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA8A4, (ts4_word)(ts4_word)lbl_8803ECF4, (ts4_word)(ts4_word)lbl_88CCA874, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6FCF8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B948: call_seq lbl_88B6FD58, lbl_8803EEFC, lbl_88CCA8D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6FD58_88A1B948(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA8D4, (ts4_word)(ts4_word)lbl_8803EEFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6FD58, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1B9B8: call_seq lbl_88B6FD88, lbl_8803EEE8, lbl_88CCA904, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6FD88_88A1B9B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA904, (ts4_word)(ts4_word)lbl_8803EEE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6FD88, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1BA28: call_seq lbl_88B6FDE8, lbl_8803EE7C, lbl_88CCA934, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6FDE8_88A1BA28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA934, (ts4_word)(ts4_word)lbl_8803EE7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6FDE8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1BA98: call_seq lbl_88B6FE50, lbl_88042110, lbl_88CCA964, lbl_88055AAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6FE50_88A1BA98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA964, (ts4_word)(ts4_word)lbl_88042110, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88055AAC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6FE50, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1BB08: call_seq lbl_88B6FF58, lbl_88041224, lbl_88CCA994, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B6FF58_88A1BB08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA994, (ts4_word)(ts4_word)lbl_88041224, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6FF58, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1BB78: call_seq lbl_88B70078, lbl_88041204, lbl_88CCA9C4, lbl_88055AC8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70078_88A1BB78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA9C4, (ts4_word)(ts4_word)lbl_88041204, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88055AC8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B70078, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1BBE8: call_seq lbl_88CCAF04, lbl_88053DD8, lbl_88CCA9F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCAF04_88A1BBE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCA9F4, (ts4_word)(ts4_word)lbl_88053DD8, (ts4_word)(ts4_word)lbl_88CCAF04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1BC50: call_seq lbl_88055ADC, lbl_88B70090, lbl_88CCA9F4, lbl_88041268, lbl_88CCAA24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88055ADC_88A1BC50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAA24, (ts4_word)(ts4_word)lbl_88041268, (ts4_word)(ts4_word)lbl_88CCA9F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70090, (ts4_word)6, (ts4_word)(ts4_word)lbl_88055ADC, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1BCC8: call_seq lbl_88CCAA24, lbl_88053DE8, lbl_88CCAA54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCAA24_88A1BCC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAA54, (ts4_word)(ts4_word)lbl_88053DE8, (ts4_word)(ts4_word)lbl_88CCAA24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1BD30: call_seq lbl_88B70120, lbl_88CCB114, lbl_8804124C, lbl_88CCAA84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70120_88A1BD30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAA84, (ts4_word)(ts4_word)lbl_8804124C, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70120, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1BDA8: call_seq lbl_88055AFC, lbl_88B70168, lbl_88CCA9F4, lbl_88041238, lbl_88CCAAB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88055AFC_88A1BDA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAAB4, (ts4_word)(ts4_word)lbl_88041238, (ts4_word)(ts4_word)lbl_88CCA9F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70168, (ts4_word)6, (ts4_word)(ts4_word)lbl_88055AFC, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1BE20: call_seq lbl_88B701F8, lbl_8804115C, lbl_88CCAAE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B701F8_88A1BE20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAAE4, (ts4_word)(ts4_word)lbl_8804115C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B701F8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1BE90: addr lbl_88B75988, u32@lbl_88B70240, u32@0x8 */
void ts4_addr_lbl_88B75988_88A1BE90(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B75988) + 8) = (ts4_word)(*(ts4_word *)lbl_88B70240);
    return;
}

/* Swing_DLL.xex 0x88A1BF20: call_seq lbl_88B70244, lbl_88CCA9F4, lbl_8804159C, lbl_88CCAB44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70244_88A1BF20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAB44, (ts4_word)(ts4_word)lbl_8804159C, (ts4_word)(ts4_word)lbl_88CCA9F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70244, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1BF98: call_seq lbl_88B70274, lbl_88CCA9F4, lbl_88053E90, lbl_88CCAB74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70274_88A1BF98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAB74, (ts4_word)(ts4_word)lbl_88053E90, (ts4_word)(ts4_word)lbl_88CCA9F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70274, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C010: call_seq lbl_88CCAF04, lbl_88053EAC, lbl_88CCABA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCAF04_88A1C010(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCABA4, (ts4_word)(ts4_word)lbl_88053EAC, (ts4_word)(ts4_word)lbl_88CCAF04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C078: call_seq lbl_88055B78, lbl_88B70290, lbl_88CCABA4, lbl_88041634, lbl_88CCABD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88055B78_88A1C078(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCABD4, (ts4_word)(ts4_word)lbl_88041634, (ts4_word)(ts4_word)lbl_88CCABA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70290, (ts4_word)17, (ts4_word)(ts4_word)lbl_88055B78, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C0F0: call_seq lbl_88B70428, lbl_88CCABA4, lbl_880415B4, lbl_88CCAC04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70428_88A1C0F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAC04, (ts4_word)(ts4_word)lbl_880415B4, (ts4_word)(ts4_word)lbl_88CCABA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70428, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C168: call_seq lbl_88B70440, lbl_88CCABA4, lbl_880411F0, lbl_88CCAC34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70440_88A1C168(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAC34, (ts4_word)(ts4_word)lbl_880411F0, (ts4_word)(ts4_word)lbl_88CCABA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70440, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C1E0: call_seq lbl_88B704E8, lbl_88CCABA4, lbl_880411C8, lbl_88CCAC64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B704E8_88A1C1E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAC64, (ts4_word)(ts4_word)lbl_880411C8, (ts4_word)(ts4_word)lbl_88CCABA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B704E8, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C258: call_seq lbl_88B705C0, lbl_88CCABA4, lbl_88048610, lbl_88CCAC94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B705C0_88A1C258(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAC94, (ts4_word)(ts4_word)lbl_88048610, (ts4_word)(ts4_word)lbl_88CCABA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B705C0, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C2D0: call_seq lbl_88B706C8, lbl_88CCABA4, lbl_88042140, lbl_88CCACC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B706C8_88A1C2D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCACC4, (ts4_word)(ts4_word)lbl_88042140, (ts4_word)(ts4_word)lbl_88CCABA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B706C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C348: addr lbl_88B75AA8, u32@lbl_88B7028C, u32@0x68 */
void ts4_addr_lbl_88B75AA8_88A1C348(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B75AA8) + 104) = (ts4_word)(*(ts4_word *)lbl_88B7028C);
    return;
}

/* Swing_DLL.xex 0x88A1C3D8: call_seq lbl_88055C44, lbl_88B706F8, lbl_88CCB114, lbl_88053F68, lbl_88CCAD24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88055C44_88A1C3D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAD24, (ts4_word)(ts4_word)lbl_88053F68, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B706F8, (ts4_word)2, (ts4_word)(ts4_word)lbl_88055C44, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C450: call_seq lbl_88B70728, lbl_88042098, lbl_88CCAD54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70728_88A1C450(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAD54, (ts4_word)(ts4_word)lbl_88042098, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70728, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C4C0: addr lbl_88B75C40, u32@lbl_88B707B8, u32@0x50 */
void ts4_addr_lbl_88B75C40_88A1C4C0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B75C40) + 80) = (ts4_word)(*(ts4_word *)lbl_88B707B8);
    return;
}

/* Swing_DLL.xex 0x88A1C550: call_seq lbl_88B707BC, lbl_88CCABA4, lbl_88042074, lbl_88CCADB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B707BC_88A1C550(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCADB4, (ts4_word)(ts4_word)lbl_88042074, (ts4_word)(ts4_word)lbl_88CCABA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B707BC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C5C8: call_seq lbl_88055CC0, lbl_88B707F0, lbl_88CCABA4, lbl_88041618, lbl_88CCADE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88055CC0_88A1C5C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCADE4, (ts4_word)(ts4_word)lbl_88041618, (ts4_word)(ts4_word)lbl_88CCABA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B707F0, (ts4_word)5, (ts4_word)(ts4_word)lbl_88055CC0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C640: call_seq lbl_88B70868, lbl_880415F8, lbl_88CCAE14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70868_88A1C640(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAE14, (ts4_word)(ts4_word)lbl_880415F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70868, (ts4_word)13, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C6B0: call_seq lbl_88055CD8, lbl_88B709A0, lbl_88CCABA4, lbl_88040228, lbl_88CCAE44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88055CD8_88A1C6B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAE44, (ts4_word)(ts4_word)lbl_88040228, (ts4_word)(ts4_word)lbl_88CCABA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B709A0, (ts4_word)10, (ts4_word)(ts4_word)lbl_88055CD8, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C728: call_seq lbl_88B70A90, lbl_88CCABA4, lbl_880415D4, lbl_88CCAE74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70A90_88A1C728(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAE74, (ts4_word)(ts4_word)lbl_880415D4, (ts4_word)(ts4_word)lbl_88CCABA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70A90, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C7A0: call_seq lbl_88B70AA8, lbl_88CCAC64, lbl_880411DC, lbl_88CCAEA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70AA8_88A1C7A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAEA4, (ts4_word)(ts4_word)lbl_880411DC, (ts4_word)(ts4_word)lbl_88CCAC64, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70AA8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C818: call_seq lbl_88B70B38, lbl_88CCABA4, lbl_8805704C, lbl_88CCAED4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70B38_88A1C818(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAED4, (ts4_word)(ts4_word)lbl_8805704C, (ts4_word)(ts4_word)lbl_88CCABA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70B38, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C890: call_seq lbl_88B70B50, lbl_88CCB114, lbl_8804116C, lbl_88CCAF04, lbl_88055D24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70B50_88A1C890(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAF04, (ts4_word)(ts4_word)lbl_8804116C, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88055D24, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B70B50, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C900: call_seq lbl_88B70B68, lbl_88041174, lbl_88CCAF34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70B68_88A1C900(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAF34, (ts4_word)(ts4_word)lbl_88041174, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70B68, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C970: call_seq lbl_88B70BB0, lbl_88041194, lbl_88CCAF64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70BB0_88A1C970(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAF64, (ts4_word)(ts4_word)lbl_88041194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70BB0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1C9E0: call_seq lbl_88055D38, lbl_88B70BF8, lbl_88CCA9F4, lbl_88040218, lbl_88CCAF94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88055D38_88A1C9E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAF94, (ts4_word)(ts4_word)lbl_88040218, (ts4_word)(ts4_word)lbl_88CCA9F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70BF8, (ts4_word)12, (ts4_word)(ts4_word)lbl_88055D38, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1CA58: call_seq lbl_88B70D18, lbl_88041930, lbl_88CCAFC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70D18_88A1CA58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAFC4, (ts4_word)(ts4_word)lbl_88041930, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70D18, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1CAC8: call_seq lbl_88055D8C, lbl_88CCB114, lbl_88041114, lbl_88CCAFF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88055D8C_88A1CAC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCAFF4, (ts4_word)(ts4_word)lbl_88041114, (ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88055D8C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1CB30: addr lbl_88B75D90, u32@lbl_88B70D64, u32@0x20 */
void ts4_addr_lbl_88B75D90_88A1CB30(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B75D90) + 32) = (ts4_word)(*(ts4_word *)lbl_88B70D64);
    return;
}

/* Swing_DLL.xex 0x88A1CB48: call_seq lbl_88B75D90, lbl_88CCAFF4, lbl_880410F8, lbl_88CCB024, lbl_88055DB0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B75D90_88A1CB48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB024, (ts4_word)(ts4_word)lbl_880410F8, (ts4_word)(ts4_word)lbl_88CCAFF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88055DB0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B75D90, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1CBC0: call_seq lbl_88B70D68, lbl_88040200, lbl_88CCB054, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70D68_88A1CBC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB054, (ts4_word)(ts4_word)lbl_88040200, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70D68, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1CC30: call_seq lbl_88B70DC8, lbl_880401D8, lbl_88CCB084, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70DC8_88A1CC30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB084, (ts4_word)(ts4_word)lbl_880401D8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70DC8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1CCA0: call_seq lbl_88B70DF8, lbl_88055DC4, lbl_880401F0, lbl_88CCB0B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70DF8_88A1CCA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB0B4, (ts4_word)(ts4_word)lbl_880401F0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70DF8, (ts4_word)2, (ts4_word)(ts4_word)lbl_88055DC4, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1CD18: call_seq lbl_8803C97C, lbl_88CCB0E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803C97C_88A1CD18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB0E4, (ts4_word)(ts4_word)lbl_8803C97C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1CD78: call_seq lbl_88B70E28, lbl_88CCB0E4, lbl_8803C9DC, lbl_88CCB114, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70E28_88A1CD78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB114, (ts4_word)(ts4_word)lbl_8803C9DC, (ts4_word)(ts4_word)lbl_88CCB0E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70E28, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1CDF0: call_seq lbl_88B70E60, lbl_8803CC5C, lbl_88CCB144, lbl_88055DD8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70E60_88A1CDF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB144, (ts4_word)(ts4_word)lbl_8803CC5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88055DD8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B70E60, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1CE60: call_seq lbl_88B70F08, lbl_8803CCC4, lbl_88CCB174, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70F08_88A1CE60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB174, (ts4_word)(ts4_word)lbl_8803CCC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70F08, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1CED0: call_seq lbl_88B70F38, lbl_8803CCD4, lbl_88CCB1A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70F38_88A1CED0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB1A4, (ts4_word)(ts4_word)lbl_8803CCD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70F38, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1CF40: addr lbl_88B75DC0, u32@lbl_88B70E5C, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88B75DC0_88A1CF40(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B70E5C;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B75DC0) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B75DC0) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A1CF60: call_seq lbl_88B75DC0, lbl_8803D124, lbl_88CCB1D4, lbl_88055F50, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B75DC0_88A1CF60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB1D4, (ts4_word)(ts4_word)lbl_8803D124, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88055F50, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B75DC0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1CFD0: call_seq lbl_88B70F70, lbl_8803D484, lbl_88CCB204, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70F70_88A1CFD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB204, (ts4_word)(ts4_word)lbl_8803D484, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70F70, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D040: call_seq lbl_88B70FA0, lbl_8803D4A8, lbl_88CCB234, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70FA0_88A1D040(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB234, (ts4_word)(ts4_word)lbl_8803D4A8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B70FA0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D0B0: addr lbl_88B75E80, u32@lbl_88B70FB8, u32@0x50 */
void ts4_addr_lbl_88B75E80_88A1D0B0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B75E80) + 80) = (ts4_word)(*(ts4_word *)lbl_88B70FB8);
    return;
}

/* Swing_DLL.xex 0x88A1D0C8: call_seq lbl_88B75E80, lbl_8803D4C4, lbl_88CCB264, lbl_88055FA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B75E80_88A1D0C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB264, (ts4_word)(ts4_word)lbl_8803D4C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88055FA4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B75E80, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D138: call_seq lbl_88B70FC8, lbl_8803F9C0, lbl_88CCB294, lbl_88055FE0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B70FC8_88A1D138(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB294, (ts4_word)(ts4_word)lbl_8803F9C0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88055FE0, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B70FC8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D1A8: call_seq lbl_88B71010, lbl_8803CAF0, lbl_88CCB2C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71010_88A1D1A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB2C4, (ts4_word)(ts4_word)lbl_8803CAF0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71010, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D218: call_seq lbl_88B71040, lbl_8803D194, lbl_88CCB2F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71040_88A1D218(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB2F4, (ts4_word)(ts4_word)lbl_8803D194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71040, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D288: call_seq lbl_88B71070, lbl_8803D2E0, lbl_88CCB324, lbl_88056018, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71070_88A1D288(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB324, (ts4_word)(ts4_word)lbl_8803D2E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88056018, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B71070, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D2F8: call_seq lbl_88B710D0, lbl_8803D6A0, lbl_88CCB354, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B710D0_88A1D2F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB354, (ts4_word)(ts4_word)lbl_8803D6A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B710D0, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D368: call_seq lbl_88B711C0, lbl_8803D914, lbl_88CCB384, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B711C0_88A1D368(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB384, (ts4_word)(ts4_word)lbl_8803D914, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B711C0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D3D8: call_seq lbl_88B711D8, lbl_8803D9E8, lbl_88CCB3B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B711D8_88A1D3D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB3B4, (ts4_word)(ts4_word)lbl_8803D9E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B711D8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D448: addr lbl_88B75F10, u32@lbl_88B71268, u32@0x20 */
void ts4_addr_lbl_88B75F10_88A1D448(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B75F10) + 32) = (ts4_word)(*(ts4_word *)lbl_88B71268);
    return;
}

/* Swing_DLL.xex 0x88A1D460: call_seq lbl_88B75F10, lbl_8803F988, lbl_88CCB3E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B75F10_88A1D460(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB3E4, (ts4_word)(ts4_word)lbl_8803F988, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B75F10, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D4D0: addr lbl_88B75F40, u32@lbl_88B71268, u32@0x20 */
void ts4_addr_lbl_88B75F40_88A1D4D0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B75F40) + 32) = (ts4_word)(*(ts4_word *)lbl_88B71268);
    return;
}

/* Swing_DLL.xex 0x88A1D4E8: call_seq lbl_88B75F40, lbl_8803F974, lbl_88CCB414, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B75F40_88A1D4E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB414, (ts4_word)(ts4_word)lbl_8803F974, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B75F40, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D558: call_seq lbl_88B71250, lbl_8804E4DC, lbl_88CCB444, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71250_88A1D558(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB444, (ts4_word)(ts4_word)lbl_8804E4DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71250, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D5C8: addr lbl_88B75F70, u32@lbl_88B71268, u32@0x20 */
void ts4_addr_lbl_88B75F70_88A1D5C8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B75F70) + 32) = (ts4_word)(*(ts4_word *)lbl_88B71268);
    return;
}

/* Swing_DLL.xex 0x88A1D5E0: call_seq lbl_88B75F70, lbl_8803F960, lbl_88CCB474, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B75F70_88A1D5E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB474, (ts4_word)(ts4_word)lbl_8803F960, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B75F70, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D650: call_seq lbl_88B7126C, lbl_8803F9B0, lbl_88CCB4A4, lbl_8805605C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7126C_88A1D650(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB4A4, (ts4_word)(ts4_word)lbl_8803F9B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805605C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7126C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D6C0: call_seq lbl_88B7129C, lbl_8803F99C, lbl_88CCB4D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7129C_88A1D6C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB4D4, (ts4_word)(ts4_word)lbl_8803F99C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7129C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D730: call_seq lbl_88B712CC, lbl_8804E4F4, lbl_88CCB504, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B712CC_88A1D730(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB504, (ts4_word)(ts4_word)lbl_8804E4F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B712CC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D7A0: call_seq lbl_88B712FC, lbl_88CCB564, lbl_8804E50C, lbl_88CCB534, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B712FC_88A1D7A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB534, (ts4_word)(ts4_word)lbl_8804E50C, (ts4_word)(ts4_word)lbl_88CCB564, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B712FC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D818: call_seq lbl_88B71314, lbl_8804E524, lbl_88CCB564, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71314_88A1D818(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB564, (ts4_word)(ts4_word)lbl_8804E524, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71314, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D888: call_seq lbl_88B71344, lbl_8804E53C, lbl_88CCB594, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B71344_88A1D888(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB594, (ts4_word)(ts4_word)lbl_8804E53C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B71344, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A1D8F8: call_seq lbl_88B7135C, lbl_8804E560, lbl_88CCB5C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7135C_88A1D8F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCB5C4, (ts4_word)(ts4_word)lbl_8804E560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7135C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}
