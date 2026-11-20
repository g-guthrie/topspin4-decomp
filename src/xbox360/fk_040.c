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

extern char ts4_addr_lbl_8803A308_88AFF590[];
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
extern char lbl_8803F9C0[];
extern char lbl_8803F9E8[];
extern char lbl_8803FA04[];
extern char lbl_8803FA18[];
extern char lbl_8803FBE0[];
extern char lbl_8803FC48[];
extern char lbl_8803FC6C[];
extern char lbl_8803FC80[];
extern char lbl_8803FCA0[];
extern char lbl_8804002C[];
extern char lbl_88040040[];
extern char lbl_88040078[];
extern char lbl_88040228[];
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
extern char lbl_88041138[];
extern char lbl_8804114C[];
extern char lbl_8804115C[];
extern char lbl_8804116C[];
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
extern char lbl_88041DE0[];
extern char lbl_88042074[];
extern char lbl_88042098[];
extern char lbl_88042110[];
extern char lbl_88042140[];
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
extern char lbl_880453D8[];
extern char lbl_88045580[];
extern char lbl_880455E0[];
extern char lbl_88045734[];
extern char lbl_880457FC[];
extern char lbl_88045860[];
extern char lbl_8804589C[];
extern char lbl_88045914[];
extern char lbl_880459F8[];
extern char lbl_88045A30[];
extern char lbl_88045A70[];
extern char lbl_88045AA8[];
extern char lbl_88045AFC[];
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
extern char lbl_88052B58[];
extern char lbl_88053448[];
extern char lbl_880534A4[];
extern char lbl_880534E0[];
extern char lbl_88053524[];
extern char lbl_88053538[];
extern char lbl_88053590[];
extern char lbl_880535A8[];
extern char lbl_88053614[];
extern char lbl_88053678[];
extern char lbl_880536A4[];
extern char lbl_880536B8[];
extern char lbl_880538A0[];
extern char lbl_880538B4[];
extern char lbl_880538E0[];
extern char lbl_88053DD8[];
extern char lbl_88053DE8[];
extern char lbl_88053E90[];
extern char lbl_88053EAC[];
extern char lbl_88053F68[];
extern char lbl_880543CC[];
extern char lbl_88054408[];
extern char lbl_8805443C[];
extern char lbl_880544B0[];
extern char lbl_8805457C[];
extern char lbl_880545F8[];
extern char lbl_88054610[];
extern char lbl_88B64BDC[];
extern char lbl_88B64BF8[];
extern char lbl_88B64C40[];
extern char lbl_88B64C58[];
extern char lbl_88B64CB8[];
extern char lbl_88B64CC4[];
extern char lbl_88B64CDC[];
extern char lbl_88B64D0C[];
extern char lbl_88B64D10[];
extern char lbl_88B64D58[];
extern char lbl_88B64D88[];
extern char lbl_88B64DB8[];
extern char lbl_88B64E18[];
extern char lbl_88B64E60[];
extern char lbl_88B64EF0[];
extern char lbl_88B64F68[];
extern char lbl_88B64FB0[];
extern char lbl_88B65010[];
extern char lbl_88B65058[];
extern char lbl_88B650A0[];
extern char lbl_88B65148[];
extern char lbl_88B65190[];
extern char lbl_88B651C0[];
extern char lbl_88B65250[];
extern char lbl_88B652E0[];
extern char lbl_88B653A0[];
extern char lbl_88B653D0[];
extern char lbl_88B653E8[];
extern char lbl_88B65418[];
extern char lbl_88B65490[];
extern char lbl_88B654D8[];
extern char lbl_88B65508[];
extern char lbl_88B65598[];
extern char lbl_88B65628[];
extern char lbl_88B656E8[];
extern char lbl_88B65730[];
extern char lbl_88B65790[];
extern char lbl_88B657A8[];
extern char lbl_88B65820[];
extern char lbl_88B65854[];
extern char lbl_88B65888[];
extern char lbl_88B658E8[];
extern char lbl_88B65918[];
extern char lbl_88B65960[];
extern char lbl_88B659F0[];
extern char lbl_88B65BA0[];
extern char lbl_88B65BD0[];
extern char lbl_88B65C7C[];
extern char lbl_88B65C94[];
extern char lbl_88B65CAC[];
extern char lbl_88B65CE0[];
extern char lbl_88B65D88[];
extern char lbl_88B65DB8[];
extern char lbl_88B65DD0[];
extern char lbl_88B65E00[];
extern char lbl_88B65E18[];
extern char lbl_88B65E30[];
extern char lbl_88B65E60[];
extern char lbl_88B65F0C[];
extern char lbl_88B65F10[];
extern char lbl_88B65F14[];
extern char lbl_88B65F20[];
extern char lbl_88B65FB0[];
extern char lbl_88B65FC8[];
extern char lbl_88B65FE0[];
extern char lbl_88B65FF8[];
extern char lbl_88B66040[];
extern char lbl_88B66058[];
extern char lbl_88B66088[];
extern char lbl_88B66100[];
extern char lbl_88B66148[];
extern char lbl_88B66190[];
extern char lbl_88B66268[];
extern char lbl_88B66298[];
extern char lbl_88B662C8[];
extern char lbl_88B663A0[];
extern char lbl_88B663E8[];
extern char lbl_88B66448[];
extern char lbl_88B664A8[];
extern char lbl_88B66508[];
extern char lbl_88B665C8[];
extern char lbl_88B66760[];
extern char lbl_88B66778[];
extern char lbl_88B66790[];
extern char lbl_88B667C0[];
extern char lbl_88B667F0[];
extern char lbl_88B66808[];
extern char lbl_88B66838[];
extern char lbl_88B66880[];
extern char lbl_88B668C8[];
extern char lbl_88B66958[];
extern char lbl_88B669A0[];
extern char lbl_88B669D0[];
extern char lbl_88B66A00[];
extern char lbl_88B66A30[];
extern char lbl_88B66A48[];
extern char lbl_88B66A60[];
extern char lbl_88B66A90[];
extern char lbl_88B66AA8[];
extern char lbl_88B66B80[];
extern char lbl_88B66D30[];
extern char lbl_88B66EC8[];
extern char lbl_88B67120[];
extern char lbl_88B67198[];
extern char lbl_88B671E0[];
extern char lbl_88B67210[];
extern char lbl_88B67270[];
extern char lbl_88B672D0[];
extern char lbl_88B673C0[];
extern char lbl_88B674B0[];
extern char lbl_88B674F8[];
extern char lbl_88B675D0[];
extern char lbl_88B675E8[];
extern char lbl_88B67630[];
extern char lbl_88B67678[];
extern char lbl_88B67690[];
extern char lbl_88B676D8[];
extern char lbl_88B676F0[];
extern char lbl_88B67798[];
extern char lbl_88B677C8[];
extern char lbl_88B67810[];
extern char lbl_88B67858[];
extern char lbl_88B678A0[];
extern char lbl_88B678B8[];
extern char lbl_88B678D0[];
extern char lbl_88B683E0[];
extern char lbl_88B684A0[];
extern char lbl_88B68500[];
extern char lbl_88B68788[];
extern char lbl_88B68800[];
extern char lbl_88B68804[];
extern char lbl_88B68834[];
extern char lbl_88B68868[];
extern char lbl_88B688C8[];
extern char lbl_88B68940[];
extern char lbl_88B689E8[];
extern char lbl_88B68A00[];
extern char lbl_88B68A78[];
extern char lbl_88B68B20[];
extern char lbl_88B68B38[];
extern char lbl_88B68B98[];
extern char lbl_88B68BB0[];
extern char lbl_88B68BF8[];
extern char lbl_88B68C88[];
extern char lbl_88B68D18[];
extern char lbl_88B68D78[];
extern char lbl_88B68DA8[];
extern char lbl_88B68E08[];
extern char lbl_88B68E6C[];
extern char lbl_88B68E70[];
extern char lbl_88B68F78[];
extern char lbl_88B690B0[];
extern char lbl_88B690C8[];
extern char lbl_88B690E0[];
extern char lbl_88B69110[];
extern char lbl_88B691A0[];
extern char lbl_88B691E8[];
extern char lbl_88B69260[];
extern char lbl_88B692A8[];
extern char lbl_88B692D8[];
extern char lbl_88B692F0[];
extern char lbl_88B69488[];
extern char lbl_88B694A0[];
extern char lbl_88B69548[];
extern char lbl_88B69620[];
extern char lbl_88B69728[];
extern char lbl_88B69758[];
extern char lbl_88B6975C[];
extern char lbl_88B6978C[];
extern char lbl_88B69790[];
extern char lbl_88B69820[];
extern char lbl_88B69850[];
extern char lbl_88B698C8[];
extern char lbl_88B69A00[];
extern char lbl_88B69AF0[];
extern char lbl_88B69B08[];
extern char lbl_88B69B80[];
extern char lbl_88B6E928[];
extern char lbl_88B6E970[];
extern char lbl_88B6EA90[];
extern char lbl_88B6EC28[];
extern char lbl_88CC3554[];
extern char lbl_88CC3FD4[];
extern char lbl_88CC4094[];
extern char lbl_88CC4994[];
extern char lbl_88CC49F4[];
extern char lbl_88CC4A24[];
extern char lbl_88CC4A84[];
extern char lbl_88CC4AB4[];
extern char lbl_88CC4AE4[];
extern char lbl_88CC4B14[];
extern char lbl_88CC4B44[];
extern char lbl_88CC4B74[];
extern char lbl_88CC4BA4[];
extern char lbl_88CC4BD4[];
extern char lbl_88CC4C04[];
extern char lbl_88CC4C34[];
extern char lbl_88CC4C64[];
extern char lbl_88CC4C94[];
extern char lbl_88CC4CC4[];
extern char lbl_88CC4CF4[];
extern char lbl_88CC4D24[];
extern char lbl_88CC4D54[];
extern char lbl_88CC4D84[];
extern char lbl_88CC4DB4[];
extern char lbl_88CC4DE4[];
extern char lbl_88CC4E14[];
extern char lbl_88CC4E44[];
extern char lbl_88CC4E74[];
extern char lbl_88CC4EA4[];
extern char lbl_88CC4ED4[];
extern char lbl_88CC4F04[];
extern char lbl_88CC4F34[];
extern char lbl_88CC4F64[];
extern char lbl_88CC4F94[];
extern char lbl_88CC4FC4[];
extern char lbl_88CC4FF4[];
extern char lbl_88CC5024[];
extern char lbl_88CC5054[];
extern char lbl_88CC5084[];
extern char lbl_88CC50B4[];
extern char lbl_88CC50E4[];
extern char lbl_88CC5114[];
extern char lbl_88CC5144[];
extern char lbl_88CC5174[];
extern char lbl_88CC51A4[];
extern char lbl_88CC51D4[];
extern char lbl_88CC5204[];
extern char lbl_88CC5234[];
extern char lbl_88CC5264[];
extern char lbl_88CC5294[];
extern char lbl_88CC52C4[];
extern char lbl_88CC52F4[];
extern char lbl_88CC5324[];
extern char lbl_88CC5354[];
extern char lbl_88CC5384[];
extern char lbl_88CC53B4[];
extern char lbl_88CC53E4[];
extern char lbl_88CC5414[];
extern char lbl_88CC5444[];
extern char lbl_88CC5474[];
extern char lbl_88CC54A4[];
extern char lbl_88CC54D4[];
extern char lbl_88CC5504[];
extern char lbl_88CC5534[];
extern char lbl_88CC5564[];
extern char lbl_88CC5594[];
extern char lbl_88CC55C4[];
extern char lbl_88CC55F4[];
extern char lbl_88CC5624[];
extern char lbl_88CC5654[];
extern char lbl_88CC5684[];
extern char lbl_88CC56B4[];
extern char lbl_88CC56E4[];
extern char lbl_88CC5714[];
extern char lbl_88CC5744[];
extern char lbl_88CC5774[];
extern char lbl_88CC57D4[];
extern char lbl_88CC5804[];
extern char lbl_88CC5834[];
extern char lbl_88CC5864[];
extern char lbl_88CC5894[];
extern char lbl_88CC58C4[];
extern char lbl_88CC58F4[];
extern char lbl_88CC5924[];
extern char lbl_88CC5954[];
extern char lbl_88CC5984[];
extern char lbl_88CC59B4[];
extern char lbl_88CC59E4[];
extern char lbl_88CC5A14[];
extern char lbl_88CC5A44[];
extern char lbl_88CC5A74[];
extern char lbl_88CC5AA4[];
extern char lbl_88CC5AD4[];
extern char lbl_88CC5B04[];
extern char lbl_88CC5B34[];
extern char lbl_88CC5B64[];
extern char lbl_88CC5B94[];
extern char lbl_88CC5BC4[];
extern char lbl_88CC5BF4[];
extern char lbl_88CC5C24[];
extern char lbl_88CC5C54[];
extern char lbl_88CC5C84[];
extern char lbl_88CC5CB4[];
extern char lbl_88CC5CE4[];
extern char lbl_88CC5D14[];
extern char lbl_88CC5D44[];
extern char lbl_88CC5D74[];
extern char lbl_88CC5DA4[];
extern char lbl_88CC5DD4[];
extern char lbl_88CC5E04[];
extern char lbl_88CC5E34[];
extern char lbl_88CC5E64[];
extern char lbl_88CC5E94[];
extern char lbl_88CC5EC4[];
extern char lbl_88CC5EF4[];
extern char lbl_88CC5F24[];
extern char lbl_88CC5F54[];
extern char lbl_88CC5F84[];
extern char lbl_88CC5FB4[];
extern char lbl_88CC5FE4[];
extern char lbl_88CC6014[];
extern char lbl_88CC6044[];
extern char lbl_88CC6074[];
extern char lbl_88CC60A4[];
extern char lbl_88CC60D4[];
extern char lbl_88CC6104[];
extern char lbl_88CC6134[];
extern char lbl_88CC6164[];
extern char lbl_88CC6194[];
extern char lbl_88CC61C4[];
extern char lbl_88CC61F4[];
extern char lbl_88CC6224[];
extern char lbl_88CC6254[];
extern char lbl_88CC6284[];
extern char lbl_88CC62B4[];
extern char lbl_88CC62E4[];
extern char lbl_88CC6314[];
extern char lbl_88CC6344[];
extern char lbl_88CC6374[];
extern char lbl_88CC63A4[];
extern char lbl_88CC63D4[];
extern char lbl_88CC6404[];
extern char lbl_88CC6434[];
extern char lbl_88CC6464[];
extern char lbl_88CC6494[];
extern char lbl_88CC64C4[];
extern char lbl_88CC64F4[];
extern char lbl_88CC6524[];
extern char lbl_88CC6554[];
extern char lbl_88CC656C[];
extern char lbl_88CC659C[];
extern char lbl_88CC65CC[];
extern char lbl_88CC65FC[];
extern char lbl_88CC662C[];
extern char lbl_88CC665C[];
extern char lbl_88CC668C[];
extern char lbl_88CC66BC[];
extern char lbl_88CC66EC[];
extern char lbl_88CC671C[];
extern char lbl_88CC674C[];
extern char lbl_88CC677C[];
extern char lbl_88CC67AC[];
extern char lbl_88CC67DC[];
extern char lbl_88CC680C[];
extern char lbl_88CC683C[];
extern char lbl_88CC686C[];
extern char lbl_88CC689C[];
extern char lbl_88CC68CC[];
extern char lbl_88CC68FC[];
extern char lbl_88CC692C[];
extern char lbl_88CC695C[];
extern char lbl_88CC698C[];
extern char lbl_88CC69BC[];
extern char lbl_88CC69EC[];
extern char lbl_88CC6A1C[];
extern char lbl_88CC6A4C[];
extern char lbl_88CC6A7C[];
extern char lbl_88CC6AAC[];
extern char lbl_88CC6ADC[];
extern char lbl_88CC6B0C[];
extern char lbl_88CC6B3C[];
extern char lbl_88CC6B9C[];
extern char lbl_88CC6BCC[];
extern char lbl_88CC6BFC[];
extern char lbl_88CC6C2C[];
extern char lbl_88CC6C5C[];
extern char lbl_88CC6C8C[];
extern char lbl_88CC6CBC[];
extern char lbl_88CC6CEC[];
extern char lbl_88CC6D1C[];
extern char lbl_88CC6D7C[];
extern char lbl_88CC6DAC[];
extern char lbl_88CC6E0C[];
extern char lbl_88CC6E3C[];
extern char lbl_88CC6E6C[];
extern char lbl_88CC6E9C[];
extern char lbl_88CC6ECC[];
extern char lbl_88CC6EFC[];
extern char lbl_88CC6F2C[];
extern char lbl_88CC713C[];
ts4_word fn_8841F080();
ts4_word ts4_set_u32_offc_884CE988();
ts4_word fn_88563470();

/* Swing_DLL.xex 0x88A0D4B0: call_seq lbl_88B64BDC, lbl_88045194, lbl_88CC4A84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64BDC_88A0D4B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4A84, (ts4_word)(ts4_word)lbl_88045194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64BDC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D520: call_seq lbl_88B64BF8, lbl_8803EF90, lbl_88CC4AB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64BF8_88A0D520(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4AB4, (ts4_word)(ts4_word)lbl_8803EF90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64BF8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D590: call_seq lbl_88B64C40, lbl_88CC3554, lbl_8803FA04, lbl_88CC4AE4, lbl_88053448, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64C40_88A0D590(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4AE4, (ts4_word)(ts4_word)lbl_8803FA04, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88053448, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B64C40, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D600: call_seq lbl_88B64C58, lbl_88042170, lbl_88CC4B14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64C58_88A0D600(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4B14, (ts4_word)(ts4_word)lbl_88042170, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64C58, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D670: addr lbl_88B683E0, u32@lbl_88B64CB8, u32@0x50 */
void ts4_addr_lbl_88B683E0_88A0D670(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B683E0) + 80) = (ts4_word)(*(ts4_word *)lbl_88B64CB8);
    return;
}

/* Swing_DLL.xex 0x88A0D688: call_seq lbl_88B683E0, lbl_88CC3554, lbl_8803F0C8, lbl_88CC4B44, lbl_880534A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B683E0_88A0D688(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4B44, (ts4_word)(ts4_word)lbl_8803F0C8, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880534A4, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B683E0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D700: call_seq lbl_88B64CC4, lbl_88CC4AE4, lbl_8804044C, lbl_88CC4B74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64CC4_88A0D700(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4B74, (ts4_word)(ts4_word)lbl_8804044C, (ts4_word)(ts4_word)lbl_88CC4AE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64CC4, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D778: call_seq lbl_88B64CDC, lbl_88CC4AE4, lbl_880403DC, lbl_88CC4BA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64CDC_88A0D778(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4BA4, (ts4_word)(ts4_word)lbl_880403DC, (ts4_word)(ts4_word)lbl_88CC4AE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64CDC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D7F0: call_seq lbl_88B64D10, lbl_88040630, lbl_88CC4BD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64D10_88A0D7F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4BD4, (ts4_word)(ts4_word)lbl_88040630, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64D10, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D860: call_seq lbl_88B64D58, lbl_88040608, lbl_88CC4C04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64D58_88A0D860(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4C04, (ts4_word)(ts4_word)lbl_88040608, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64D58, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D8D0: call_seq lbl_88B64D88, lbl_88CC4AE4, lbl_88040394, lbl_88CC4C34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64D88_88A0D8D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4C34, (ts4_word)(ts4_word)lbl_88040394, (ts4_word)(ts4_word)lbl_88CC4AE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64D88, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D948: call_seq lbl_88B64DB8, lbl_88040590, lbl_88CC4C64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64DB8_88A0D948(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4C64, (ts4_word)(ts4_word)lbl_88040590, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64DB8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0D9B8: call_seq lbl_88B64E18, lbl_88040560, lbl_88CC4C94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64E18_88A0D9B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4C94, (ts4_word)(ts4_word)lbl_88040560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64E18, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0DA28: call_seq lbl_880534E0, lbl_88B64E60, lbl_88CC4AE4, lbl_8803F690, lbl_88CC4CC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880534E0_88A0DA28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4CC4, (ts4_word)(ts4_word)lbl_8803F690, (ts4_word)(ts4_word)lbl_88CC4AE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64E60, (ts4_word)6, (ts4_word)(ts4_word)lbl_880534E0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0DAA0: call_seq lbl_88B64EF0, lbl_88CC4D24, lbl_88045734, lbl_88CC4CF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64EF0_88A0DAA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4CF4, (ts4_word)(ts4_word)lbl_88045734, (ts4_word)(ts4_word)lbl_88CC4D24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64EF0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0DB18: call_seq lbl_88CC3554, lbl_88045A30, lbl_88CC4D24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC3554_88A0DB18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4D24, (ts4_word)(ts4_word)lbl_88045A30, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0DB80: addr lbl_88B684A0, u32@lbl_88B64D0C, u32@0x38 */
void ts4_addr_lbl_88B684A0_88A0DB80(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B684A0) + 56) = (ts4_word)(*(ts4_word *)lbl_88B64D0C);
    return;
}

/* Swing_DLL.xex 0x88A0DB98: call_seq lbl_88B684A0, lbl_88CC4AE4, lbl_88040364, lbl_88CC4D54, lbl_88053524, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B684A0_88A0DB98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4D54, (ts4_word)(ts4_word)lbl_88040364, (ts4_word)(ts4_word)lbl_88CC4AE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88053524, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B684A0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0DC10: call_seq lbl_88B64F68, lbl_88CC4AE4, lbl_88040344, lbl_88CC4D84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64F68_88A0DC10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4D84, (ts4_word)(ts4_word)lbl_88040344, (ts4_word)(ts4_word)lbl_88CC4AE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64F68, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0DC88: call_seq lbl_88B64FB0, lbl_88CC4CC4, lbl_8803F064, lbl_88CC4DB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B64FB0_88A0DC88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4DB4, (ts4_word)(ts4_word)lbl_8803F064, (ts4_word)(ts4_word)lbl_88CC4CC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B64FB0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0DD00: call_seq lbl_88B65010, lbl_88040534, lbl_88CC4DE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65010_88A0DD00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4DE4, (ts4_word)(ts4_word)lbl_88040534, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65010, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0DD70: call_seq lbl_88B65058, lbl_88040508, lbl_88CC4E14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65058_88A0DD70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4E14, (ts4_word)(ts4_word)lbl_88040508, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65058, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0DDE0: call_seq lbl_88B650A0, lbl_88CC4AE4, lbl_8803F048, lbl_88CC4E44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B650A0_88A0DDE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4E44, (ts4_word)(ts4_word)lbl_8803F048, (ts4_word)(ts4_word)lbl_88CC4AE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B650A0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0DE58: call_seq lbl_88B65148, lbl_88CC4AE4, lbl_880402E4, lbl_88CC4E74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65148_88A0DE58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4E74, (ts4_word)(ts4_word)lbl_880402E4, (ts4_word)(ts4_word)lbl_88CC4AE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65148, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0DED0: call_seq lbl_88B65190, lbl_88040424, lbl_88CC4EA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65190_88A0DED0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4EA4, (ts4_word)(ts4_word)lbl_88040424, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65190, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0DF40: call_seq lbl_88B651C0, lbl_880403FC, lbl_88CC4ED4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B651C0_88A0DF40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4ED4, (ts4_word)(ts4_word)lbl_880403FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B651C0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0DFB0: call_seq lbl_88B65250, lbl_88CC4AE4, lbl_880402CC, lbl_88CC4F04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65250_88A0DFB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4F04, (ts4_word)(ts4_word)lbl_880402CC, (ts4_word)(ts4_word)lbl_88CC4AE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65250, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E028: call_seq lbl_88B652E0, lbl_88CC4AE4, lbl_8803F6B0, lbl_88CC4F34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B652E0_88A0E028(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4F34, (ts4_word)(ts4_word)lbl_8803F6B0, (ts4_word)(ts4_word)lbl_88CC4AE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B652E0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E0A0: call_seq lbl_88CC4AE4, lbl_88045AFC, lbl_88CC4F64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC4AE4_88A0E0A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4F64, (ts4_word)(ts4_word)lbl_88045AFC, (ts4_word)(ts4_word)lbl_88CC4AE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E108: call_seq lbl_88B653A0, lbl_88CC4B44, lbl_8804589C, lbl_88CC4F94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B653A0_88A0E108(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4F94, (ts4_word)(ts4_word)lbl_8804589C, (ts4_word)(ts4_word)lbl_88CC4B44, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B653A0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E180: call_seq lbl_88B653D0, lbl_88CC4994, lbl_88045860, lbl_88CC4FC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B653D0_88A0E180(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4FC4, (ts4_word)(ts4_word)lbl_88045860, (ts4_word)(ts4_word)lbl_88CC4994, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B653D0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E1F8: call_seq lbl_88B653E8, lbl_880453D8, lbl_88CC4FF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B653E8_88A0E1F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC4FF4, (ts4_word)(ts4_word)lbl_880453D8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B653E8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E268: call_seq lbl_88B65418, lbl_88CC4F64, lbl_880403C4, lbl_88CC5024, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65418_88A0E268(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5024, (ts4_word)(ts4_word)lbl_880403C4, (ts4_word)(ts4_word)lbl_88CC4F64, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65418, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E2E0: call_seq lbl_88B65490, lbl_880405E4, lbl_88CC5054, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65490_88A0E2E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5054, (ts4_word)(ts4_word)lbl_880405E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65490, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E350: call_seq lbl_88B654D8, lbl_880405C0, lbl_88CC5084, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B654D8_88A0E350(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5084, (ts4_word)(ts4_word)lbl_880405C0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B654D8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E3C0: call_seq lbl_88B65508, lbl_88CC4AE4, lbl_88040380, lbl_88CC50B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65508_88A0E3C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC50B4, (ts4_word)(ts4_word)lbl_88040380, (ts4_word)(ts4_word)lbl_88CC4AE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65508, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E438: call_seq lbl_88B65598, lbl_8803FC48, lbl_88CC50E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65598_88A0E438(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC50E4, (ts4_word)(ts4_word)lbl_8803FC48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65598, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E4A8: call_seq lbl_88053538, lbl_88B65628, lbl_88CC4F64, lbl_8803FC6C, lbl_88CC5114, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88053538_88A0E4A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5114, (ts4_word)(ts4_word)lbl_8803FC6C, (ts4_word)(ts4_word)lbl_88CC4F64, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65628, (ts4_word)8, (ts4_word)(ts4_word)lbl_88053538, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E520: call_seq lbl_88B656E8, lbl_88045020, lbl_88CC5144, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B656E8_88A0E520(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5144, (ts4_word)(ts4_word)lbl_88045020, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B656E8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E590: call_seq lbl_88B65730, lbl_88CC4F64, lbl_88040300, lbl_88CC5174, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65730_88A0E590(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5174, (ts4_word)(ts4_word)lbl_88040300, (ts4_word)(ts4_word)lbl_88CC4F64, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65730, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E608: call_seq lbl_88B65790, lbl_88CC4AE4, lbl_880403AC, lbl_88CC51A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65790_88A0E608(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC51A4, (ts4_word)(ts4_word)lbl_880403AC, (ts4_word)(ts4_word)lbl_88CC4AE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65790, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E680: call_seq lbl_88B657A8, lbl_880422F8, lbl_88CC51D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B657A8_88A0E680(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC51D4, (ts4_word)(ts4_word)lbl_880422F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B657A8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E6F0: call_seq lbl_88B65820, lbl_88CC4AE4, lbl_8803FA18, lbl_88CC5204, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65820_88A0E6F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5204, (ts4_word)(ts4_word)lbl_8803FA18, (ts4_word)(ts4_word)lbl_88CC4AE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65820, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E768: call_seq lbl_88053590, lbl_88CC3554, lbl_8803FBE0, lbl_88CC5234, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88053590_88A0E768(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5234, (ts4_word)(ts4_word)lbl_8803FBE0, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88053590, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E7D0: call_seq lbl_88B65854, lbl_88CC5234, lbl_88045A70, lbl_88CC5264, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65854_88A0E7D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5264, (ts4_word)(ts4_word)lbl_88045A70, (ts4_word)(ts4_word)lbl_88CC5234, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65854, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E848: call_seq lbl_88B65888, lbl_88CC5264, lbl_8803FCA0, lbl_88CC5294, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65888_88A0E848(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5294, (ts4_word)(ts4_word)lbl_8803FCA0, (ts4_word)(ts4_word)lbl_88CC5264, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65888, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E8C0: call_seq lbl_88B658E8, lbl_88CC5264, lbl_8803FC80, lbl_88CC52C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B658E8_88A0E8C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC52C4, (ts4_word)(ts4_word)lbl_8803FC80, (ts4_word)(ts4_word)lbl_88CC5264, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B658E8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E938: call_seq lbl_88B65918, lbl_88CC5264, lbl_8803F9E8, lbl_88CC52F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65918_88A0E938(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC52F4, (ts4_word)(ts4_word)lbl_8803F9E8, (ts4_word)(ts4_word)lbl_88CC5264, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65918, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0E9B0: call_seq lbl_88B65960, lbl_88CC4AE4, lbl_8804032C, lbl_88CC5324, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65960_88A0E9B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5324, (ts4_word)(ts4_word)lbl_8804032C, (ts4_word)(ts4_word)lbl_88CC4AE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65960, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0EA28: call_seq lbl_880535A8, lbl_88B659F0, lbl_88CC57D4, lbl_8803F6CC, lbl_88CC5354, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880535A8_88A0EA28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5354, (ts4_word)(ts4_word)lbl_8803F6CC, (ts4_word)(ts4_word)lbl_88CC57D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B659F0, (ts4_word)18, (ts4_word)(ts4_word)lbl_880535A8, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0EAA0: call_seq lbl_88CC3554, lbl_88045AA8, lbl_88CC5384, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC3554_88A0EAA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5384, (ts4_word)(ts4_word)lbl_88045AA8, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0EB08: call_seq lbl_88CC5414, lbl_880457FC, lbl_88CC53B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC5414_88A0EB08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC53B4, (ts4_word)(ts4_word)lbl_880457FC, (ts4_word)(ts4_word)lbl_88CC5414, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0EB70: call_seq lbl_88CC5354, lbl_880455E0, lbl_88CC53E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC5354_88A0EB70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC53E4, (ts4_word)(ts4_word)lbl_880455E0, (ts4_word)(ts4_word)lbl_88CC5354, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0EBD8: call_seq lbl_88053614, lbl_88CC5384, lbl_880459F8, lbl_88CC5414, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88053614_88A0EBD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5414, (ts4_word)(ts4_word)lbl_880459F8, (ts4_word)(ts4_word)lbl_88CC5384, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88053614, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0EC40: call_seq lbl_88B65BA0, lbl_88045070, lbl_88CC5444, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65BA0_88A0EC40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5444, (ts4_word)(ts4_word)lbl_88045070, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65BA0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0ECB0: call_seq lbl_88B65BD0, lbl_88CC5414, lbl_88041DE0, lbl_88CC5474, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65BD0_88A0ECB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5474, (ts4_word)(ts4_word)lbl_88041DE0, (ts4_word)(ts4_word)lbl_88CC5414, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65BD0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0ED28: call_seq lbl_88B65C7C, lbl_88CC3554, lbl_8803F5D4, lbl_88CC54A4, lbl_88053678, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65C7C_88A0ED28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC54A4, (ts4_word)(ts4_word)lbl_8803F5D4, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88053678, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B65C7C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0ED98: call_seq lbl_88B65C94, lbl_88CC5564, lbl_880402B0, lbl_88CC54D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65C94_88A0ED98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC54D4, (ts4_word)(ts4_word)lbl_880402B0, (ts4_word)(ts4_word)lbl_88CC5564, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65C94, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0EE10: call_seq lbl_88CC5534, lbl_88040E04, lbl_88CC5504, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC5534_88A0EE10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5504, (ts4_word)(ts4_word)lbl_88040E04, (ts4_word)(ts4_word)lbl_88CC5534, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0EE78: call_seq lbl_88B65CAC, lbl_88CC5564, lbl_8803EFA8, lbl_88CC5534, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65CAC_88A0EE78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5534, (ts4_word)(ts4_word)lbl_8803EFA8, (ts4_word)(ts4_word)lbl_88CC5564, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65CAC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0EEF0: call_seq lbl_88B65CE0, lbl_88CC54A4, lbl_88040290, lbl_88CC5564, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65CE0_88A0EEF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5564, (ts4_word)(ts4_word)lbl_88040290, (ts4_word)(ts4_word)lbl_88CC54A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65CE0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0EF68: call_seq lbl_88CC5564, lbl_880402A0, lbl_88CC5594, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC5564_88A0EF68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5594, (ts4_word)(ts4_word)lbl_880402A0, (ts4_word)(ts4_word)lbl_88CC5564, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0EFD0: call_seq lbl_88CC54D4, lbl_88040E18, lbl_88CC55C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC54D4_88A0EFD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC55C4, (ts4_word)(ts4_word)lbl_88040E18, (ts4_word)(ts4_word)lbl_88CC54D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F038: call_seq lbl_88CC5594, lbl_88040E68, lbl_88CC55F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC5594_88A0F038(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC55F4, (ts4_word)(ts4_word)lbl_88040E68, (ts4_word)(ts4_word)lbl_88CC5594, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F0A0: call_seq lbl_88CC54D4, lbl_88040DB0, lbl_88CC5624, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC54D4_88A0F0A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5624, (ts4_word)(ts4_word)lbl_88040DB0, (ts4_word)(ts4_word)lbl_88CC54D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F108: call_seq lbl_88B65D88, lbl_88CC56B4, lbl_8803F6D8, lbl_88CC5654, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65D88_88A0F108(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5654, (ts4_word)(ts4_word)lbl_8803F6D8, (ts4_word)(ts4_word)lbl_88CC56B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65D88, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F180: call_seq lbl_88B65DB8, lbl_88CC56E4, lbl_88045914, lbl_88CC5684, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65DB8_88A0F180(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5684, (ts4_word)(ts4_word)lbl_88045914, (ts4_word)(ts4_word)lbl_88CC56E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65DB8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F1F8: call_seq lbl_88B65DD0, lbl_88CC57D4, lbl_88047070, lbl_88CC56B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65DD0_88A0F1F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC56B4, (ts4_word)(ts4_word)lbl_88047070, (ts4_word)(ts4_word)lbl_88CC57D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65DD0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F270: call_seq lbl_88B65E00, lbl_88CC56B4, lbl_880402BC, lbl_88CC56E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65E00_88A0F270(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC56E4, (ts4_word)(ts4_word)lbl_880402BC, (ts4_word)(ts4_word)lbl_88CC56B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65E00, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F2E8: call_seq lbl_88B65E18, lbl_88CC56E4, lbl_88045580, lbl_88CC5714, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65E18_88A0F2E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5714, (ts4_word)(ts4_word)lbl_88045580, (ts4_word)(ts4_word)lbl_88CC56E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65E18, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F360: call_seq lbl_88B65E30, lbl_8803F9C0, lbl_88CC5744, lbl_880536A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65E30_88A0F360(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5744, (ts4_word)(ts4_word)lbl_8803F9C0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880536A4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B65E30, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F3D0: call_seq lbl_880536B8, lbl_88B65E60, lbl_88CC3554, lbl_8803F660, lbl_88CC5774, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880536B8_88A0F3D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5774, (ts4_word)(ts4_word)lbl_8803F660, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65E60, (ts4_word)7, (ts4_word)(ts4_word)lbl_880536B8, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F448: get u32@lbl_88B65F14, lbl_88B68500, u32@lbl_88B65F10, u32@lbl_88B65F0C, u32@0x50, u32@0x110 */
void ts4_get_u32_lbl_88B65F14_88A0F448(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88B65F14;
    t2 = *(ts4_word *)lbl_88B65F10;
    t3 = *(ts4_word *)lbl_88B65F0C;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B68500) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B68500) + 272) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B68500) + 560) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x88A0F4F0: call_seq lbl_88B65F20, lbl_88CC3554, lbl_8803F084, lbl_88CC57D4, lbl_880538A0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65F20_88A0F4F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC57D4, (ts4_word)(ts4_word)lbl_8803F084, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880538A0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B65F20, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F568: call_seq lbl_88B65FB0, lbl_88CC3554, lbl_8804707C, lbl_88CC5804, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65FB0_88A0F568(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5804, (ts4_word)(ts4_word)lbl_8804707C, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65FB0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F5E0: call_seq lbl_88B65FC8, lbl_88CC3FD4, lbl_88044F38, lbl_88CC5834, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65FC8_88A0F5E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5834, (ts4_word)(ts4_word)lbl_88044F38, (ts4_word)(ts4_word)lbl_88CC3FD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65FC8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F658: call_seq lbl_88B65FE0, lbl_88042E20, lbl_88CC5864, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65FE0_88A0F658(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5864, (ts4_word)(ts4_word)lbl_88042E20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65FE0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F6C8: call_seq lbl_88B65FF8, lbl_88CC3554, lbl_8803EFD0, lbl_88CC5894, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B65FF8_88A0F6C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5894, (ts4_word)(ts4_word)lbl_8803EFD0, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B65FF8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F740: call_seq lbl_88B66040, lbl_88044F10, lbl_88CC58C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66040_88A0F740(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC58C4, (ts4_word)(ts4_word)lbl_88044F10, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66040, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F7B0: call_seq lbl_88B66058, lbl_88CC3554, lbl_88044F90, lbl_88CC58F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66058_88A0F7B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC58F4, (ts4_word)(ts4_word)lbl_88044F90, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66058, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F828: call_seq lbl_88B66088, lbl_88CC59B4, lbl_8803F670, lbl_88CC5924, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66088_88A0F828(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5924, (ts4_word)(ts4_word)lbl_8803F670, (ts4_word)(ts4_word)lbl_88CC59B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66088, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F8A0: call_seq lbl_88B66100, lbl_880404E0, lbl_88CC5954, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66100_88A0F8A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5954, (ts4_word)(ts4_word)lbl_880404E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66100, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F910: call_seq lbl_88B66148, lbl_880404B8, lbl_88CC5984, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66148_88A0F910(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5984, (ts4_word)(ts4_word)lbl_880404B8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66148, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F980: call_seq lbl_880538B4, lbl_88B66190, lbl_88CC4AE4, lbl_8803F030, lbl_88CC59B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880538B4_88A0F980(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC59B4, (ts4_word)(ts4_word)lbl_8803F030, (ts4_word)(ts4_word)lbl_88CC4AE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66190, (ts4_word)9, (ts4_word)(ts4_word)lbl_880538B4, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0F9F8: call_seq lbl_88B66268, lbl_88040494, lbl_88CC59E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66268_88A0F9F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC59E4, (ts4_word)(ts4_word)lbl_88040494, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66268, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0FA68: call_seq lbl_88B66298, lbl_88040470, lbl_88CC5A14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66298_88A0FA68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5A14, (ts4_word)(ts4_word)lbl_88040470, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66298, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0FAD8: call_seq lbl_88B662C8, lbl_88CC4AE4, lbl_88040318, lbl_88CC5A44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B662C8_88A0FAD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5A44, (ts4_word)(ts4_word)lbl_88040318, (ts4_word)(ts4_word)lbl_88CC4AE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B662C8, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0FB50: call_seq lbl_88B663A0, lbl_88CC49F4, lbl_88044EA8, lbl_88CC5A74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B663A0_88A0FB50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5A74, (ts4_word)(ts4_word)lbl_88044EA8, (ts4_word)(ts4_word)lbl_88CC49F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B663A0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0FBC8: call_seq lbl_88B663E8, lbl_88CC49F4, lbl_88044E64, lbl_88CC5AA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B663E8_88A0FBC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5AA4, (ts4_word)(ts4_word)lbl_88044E64, (ts4_word)(ts4_word)lbl_88CC49F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B663E8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0FC40: call_seq lbl_88B66448, lbl_88CC4A24, lbl_88044DD0, lbl_88CC5AD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66448_88A0FC40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5AD4, (ts4_word)(ts4_word)lbl_88044DD0, (ts4_word)(ts4_word)lbl_88CC4A24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66448, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0FCB8: call_seq lbl_88B664A8, lbl_88CC4A24, lbl_88044CD0, lbl_88CC5B04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B664A8_88A0FCB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5B04, (ts4_word)(ts4_word)lbl_88044CD0, (ts4_word)(ts4_word)lbl_88CC4A24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B664A8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0FD30: call_seq lbl_88B66508, lbl_88CC49F4, lbl_88044BD4, lbl_88CC5B34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66508_88A0FD30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5B34, (ts4_word)(ts4_word)lbl_88044BD4, (ts4_word)(ts4_word)lbl_88CC49F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66508, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0FDA8: call_seq lbl_88B665C8, lbl_8803F094, lbl_88CC5B64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B665C8_88A0FDA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5B64, (ts4_word)(ts4_word)lbl_8803F094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B665C8, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0FE18: call_seq lbl_88B66760, lbl_88CC4094, lbl_8803F0AC, lbl_88CC5B94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66760_88A0FE18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5B94, (ts4_word)(ts4_word)lbl_8803F0AC, (ts4_word)(ts4_word)lbl_88CC4094, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66760, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0FE90: call_seq lbl_88B66778, lbl_88CC4094, lbl_88044E30, lbl_88CC5BC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66778_88A0FE90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5BC4, (ts4_word)(ts4_word)lbl_88044E30, (ts4_word)(ts4_word)lbl_88CC4094, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66778, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0FF08: call_seq lbl_88B66790, lbl_88CC4094, lbl_88044DF8, lbl_88CC5BF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66790_88A0FF08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5BF4, (ts4_word)(ts4_word)lbl_88044DF8, (ts4_word)(ts4_word)lbl_88CC4094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66790, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0FF80: call_seq lbl_88B667C0, lbl_88044B54, lbl_88CC5C24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B667C0_88A0FF80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5C24, (ts4_word)(ts4_word)lbl_88044B54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B667C0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A0FFF0: call_seq lbl_88B667F0, lbl_88CC4094, lbl_88044D8C, lbl_88CC5C54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B667F0_88A0FFF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5C54, (ts4_word)(ts4_word)lbl_88044D8C, (ts4_word)(ts4_word)lbl_88CC4094, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B667F0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10068: call_seq lbl_88B66808, lbl_88044A90, lbl_88CC5C84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66808_88A10068(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5C84, (ts4_word)(ts4_word)lbl_88044A90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66808, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A100D8: call_seq lbl_88B66838, lbl_88044ACC, lbl_88CC5CB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66838_88A100D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5CB4, (ts4_word)(ts4_word)lbl_88044ACC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66838, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10148: call_seq lbl_88B66880, lbl_88CC3554, lbl_88044CFC, lbl_88CC5CE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66880_88A10148(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5CE4, (ts4_word)(ts4_word)lbl_88044CFC, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66880, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A101C0: call_seq lbl_88B668C8, lbl_88CC4A24, lbl_8804705C, lbl_88CC5D14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B668C8_88A101C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5D14, (ts4_word)(ts4_word)lbl_8804705C, (ts4_word)(ts4_word)lbl_88CC4A24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B668C8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10238: call_seq lbl_88B66958, lbl_88044A58, lbl_88CC5D44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66958_88A10238(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5D44, (ts4_word)(ts4_word)lbl_88044A58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66958, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A102A8: call_seq lbl_88B669A0, lbl_88044B0C, lbl_88CC5D74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B669A0_88A102A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5D74, (ts4_word)(ts4_word)lbl_88044B0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B669A0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10318: call_seq lbl_88B669D0, lbl_88044B94, lbl_88CC5DA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B669D0_88A10318(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5DA4, (ts4_word)(ts4_word)lbl_88044B94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B669D0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10388: call_seq lbl_88B66A00, lbl_88CC3554, lbl_88044D60, lbl_88CC5DD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66A00_88A10388(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5DD4, (ts4_word)(ts4_word)lbl_88044D60, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66A00, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10400: call_seq lbl_88B66A30, lbl_88CC3554, lbl_88044C84, lbl_88CC5E04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66A30_88A10400(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5E04, (ts4_word)(ts4_word)lbl_88044C84, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66A30, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10478: call_seq lbl_88B66A48, lbl_88CC3554, lbl_88044C48, lbl_88CC5E34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66A48_88A10478(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5E34, (ts4_word)(ts4_word)lbl_88044C48, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66A48, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A104F0: call_seq lbl_88B66A60, lbl_88044A08, lbl_88CC5E64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66A60_88A104F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5E64, (ts4_word)(ts4_word)lbl_88044A08, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66A60, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10560: call_seq lbl_88B66A90, lbl_88CC3554, lbl_88044C08, lbl_88CC5E94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66A90_88A10560(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5E94, (ts4_word)(ts4_word)lbl_88044C08, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66A90, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A105D8: call_seq lbl_88B66AA8, lbl_88040668, lbl_88CC5EC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66AA8_88A105D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5EC4, (ts4_word)(ts4_word)lbl_88040668, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66AA8, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10648: call_seq lbl_88B66B80, lbl_88CC3554, lbl_88040658, lbl_88CC5EF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66B80_88A10648(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5EF4, (ts4_word)(ts4_word)lbl_88040658, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66B80, (ts4_word)18, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A106C0: call_seq lbl_88B66D30, lbl_8803F5F4, lbl_88CC5F24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66D30_88A106C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5F24, (ts4_word)(ts4_word)lbl_8803F5F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66D30, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10730: call_seq lbl_88B66EC8, lbl_88CC4A24, lbl_8803F64C, lbl_88CC5F54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B66EC8_88A10730(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5F54, (ts4_word)(ts4_word)lbl_8803F64C, (ts4_word)(ts4_word)lbl_88CC4A24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B66EC8, (ts4_word)25, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A107A8: call_seq lbl_88CC3554, lbl_8804494C, lbl_88CC5F84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC3554_88A107A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5F84, (ts4_word)(ts4_word)lbl_8804494C, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10810: call_seq lbl_88B67120, lbl_88CC5F84, lbl_88044700, lbl_88CC5FB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B67120_88A10810(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5FB4, (ts4_word)(ts4_word)lbl_88044700, (ts4_word)(ts4_word)lbl_88CC5F84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B67120, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10888: call_seq lbl_88CC3554, lbl_88044924, lbl_88CC5FE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC3554_88A10888(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC5FE4, (ts4_word)(ts4_word)lbl_88044924, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A108F0: call_seq lbl_88B67198, lbl_88044438, lbl_88CC6014, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B67198_88A108F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6014, (ts4_word)(ts4_word)lbl_88044438, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B67198, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10960: call_seq lbl_88B671E0, lbl_88CC5FE4, lbl_88044680, lbl_88CC6044, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B671E0_88A10960(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6044, (ts4_word)(ts4_word)lbl_88044680, (ts4_word)(ts4_word)lbl_88CC5FE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B671E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A109D8: call_seq lbl_88CC3554, lbl_880448C8, lbl_88CC6074, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC3554_88A109D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6074, (ts4_word)(ts4_word)lbl_880448C8, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10A40: call_seq lbl_88CC3554, lbl_880448FC, lbl_88CC60A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC3554_88A10A40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC60A4, (ts4_word)(ts4_word)lbl_880448FC, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10AA8: call_seq lbl_88B67210, lbl_88CC6074, lbl_88044524, lbl_88CC60D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B67210_88A10AA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC60D4, (ts4_word)(ts4_word)lbl_88044524, (ts4_word)(ts4_word)lbl_88CC6074, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B67210, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10B20: call_seq lbl_88B67270, lbl_88CC60A4, lbl_880446BC, lbl_88CC6104, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B67270_88A10B20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6104, (ts4_word)(ts4_word)lbl_880446BC, (ts4_word)(ts4_word)lbl_88CC60A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B67270, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10B98: call_seq lbl_88CC3554, lbl_8804489C, lbl_88CC6134, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC3554_88A10B98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6134, (ts4_word)(ts4_word)lbl_8804489C, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10C00: call_seq lbl_88B672D0, lbl_88CC6134, lbl_88044650, lbl_88CC6164, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B672D0_88A10C00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6164, (ts4_word)(ts4_word)lbl_88044650, (ts4_word)(ts4_word)lbl_88CC6134, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B672D0, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10C78: call_seq lbl_88B673C0, lbl_88044324, lbl_88CC6194, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B673C0_88A10C78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6194, (ts4_word)(ts4_word)lbl_88044324, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B673C0, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10CE8: call_seq lbl_88B674B0, lbl_88044370, lbl_88CC61C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B674B0_88A10CE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC61C4, (ts4_word)(ts4_word)lbl_88044370, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B674B0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10D58: call_seq lbl_88B674F8, lbl_8803F610, lbl_88CC61F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B674F8_88A10D58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC61F4, (ts4_word)(ts4_word)lbl_8803F610, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B674F8, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10DC8: call_seq lbl_88B675D0, lbl_8803F634, lbl_88CC6224, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B675D0_88A10DC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6224, (ts4_word)(ts4_word)lbl_8803F634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B675D0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10E38: call_seq lbl_88CC3554, lbl_88044874, lbl_88CC6254, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC3554_88A10E38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6254, (ts4_word)(ts4_word)lbl_88044874, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10EA0: call_seq lbl_88B675E8, lbl_88CC6254, lbl_8804461C, lbl_88CC6284, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B675E8_88A10EA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6284, (ts4_word)(ts4_word)lbl_8804461C, (ts4_word)(ts4_word)lbl_88CC6254, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B675E8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10F18: call_seq lbl_88B67630, lbl_88044268, lbl_88CC62B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B67630_88A10F18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC62B4, (ts4_word)(ts4_word)lbl_88044268, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B67630, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A10F88: call_seq lbl_88B67678, lbl_88CC3554, lbl_8804484C, lbl_88CC62E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B67678_88A10F88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC62E4, (ts4_word)(ts4_word)lbl_8804484C, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B67678, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11000: call_seq lbl_88B67690, lbl_880443CC, lbl_88CC6314, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B67690_88A11000(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6314, (ts4_word)(ts4_word)lbl_880443CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B67690, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11070: call_seq lbl_88B676D8, lbl_88CC62E4, lbl_880445E4, lbl_88CC6344, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B676D8_88A11070(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6344, (ts4_word)(ts4_word)lbl_880445E4, (ts4_word)(ts4_word)lbl_88CC62E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B676D8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A110E8: call_seq lbl_88CC3554, lbl_8804481C, lbl_88CC6374, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC3554_88A110E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6374, (ts4_word)(ts4_word)lbl_8804481C, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11150: call_seq lbl_88B676F0, lbl_88CC6374, lbl_880445A8, lbl_88CC63A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B676F0_88A11150(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC63A4, (ts4_word)(ts4_word)lbl_880445A8, (ts4_word)(ts4_word)lbl_88CC6374, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B676F0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A111C8: call_seq lbl_88B67798, lbl_8804449C, lbl_88CC63D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B67798_88A111C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC63D4, (ts4_word)(ts4_word)lbl_8804449C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B67798, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11238: call_seq lbl_88B677C8, lbl_88CC3554, lbl_88044744, lbl_88CC6404, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B677C8_88A11238(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6404, (ts4_word)(ts4_word)lbl_88044744, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B677C8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A112B0: call_seq lbl_88B67810, lbl_88CC3554, lbl_88044758, lbl_88CC6434, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B67810_88A112B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6434, (ts4_word)(ts4_word)lbl_88044758, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B67810, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11328: call_seq lbl_88CC3554, lbl_880447EC, lbl_88CC6464, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC3554_88A11328(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6464, (ts4_word)(ts4_word)lbl_880447EC, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11390: call_seq lbl_88B67858, lbl_88CC6464, lbl_88044568, lbl_88CC6494, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B67858_88A11390(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6494, (ts4_word)(ts4_word)lbl_88044568, (ts4_word)(ts4_word)lbl_88CC6464, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B67858, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11408: call_seq lbl_88B678A0, lbl_88CC3554, lbl_880447B8, lbl_88CC64C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B678A0_88A11408(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC64C4, (ts4_word)(ts4_word)lbl_880447B8, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B678A0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11480: call_seq lbl_88B678B8, lbl_88CC3554, lbl_88044784, lbl_88CC64F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B678B8_88A11480(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC64F4, (ts4_word)(ts4_word)lbl_88044784, (ts4_word)(ts4_word)lbl_88CC3554, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B678B8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A114F8: call_seq lbl_88B678D0, lbl_88CC64C4, lbl_880444CC, lbl_88CC6524, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B678D0_88A114F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6524, (ts4_word)(ts4_word)lbl_880444CC, (ts4_word)(ts4_word)lbl_88CC64C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B678D0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11570: call_seq lbl_88052B58, lbl_880538E0, lbl_88CC6554, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF590, fn_88563470 */
ts4_word ts4_call_seq_lbl_88052B58_88A11570(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CC6554, (ts4_word)(ts4_word)lbl_880538E0, (ts4_word)3, (ts4_word)(ts4_word)lbl_88052B58);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF590);
    return t2;
}

/* Swing_DLL.xex 0x88A115B8: call_seq lbl_88B68788, lbl_88046C94, lbl_88CC656C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68788_88A115B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC656C, (ts4_word)(ts4_word)lbl_88046C94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68788, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11628: addr lbl_88B6E928, u32@lbl_88B68800, u32@0x38 */
void ts4_addr_lbl_88B6E928_88A11628(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6E928) + 56) = (ts4_word)(*(ts4_word *)lbl_88B68800);
    return;
}

/* Swing_DLL.xex 0x88A11640: call_seq lbl_880543CC, lbl_88B6E928, lbl_8803EF04, lbl_88CC659C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880543CC_88A11640(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC659C, (ts4_word)(ts4_word)lbl_8803EF04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880543CC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B6E928, (ts4_word)3, (ts4_word)((ts4_word)lbl_880543CC + 20), (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A116B8: call_seq lbl_88B68804, lbl_88046C78, lbl_88CC65CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68804_88A116B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC65CC, (ts4_word)(ts4_word)lbl_88046C78, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68804, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11728: call_seq lbl_88B68834, lbl_8803EC6C, lbl_88CC65FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68834_88A11728(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC65FC, (ts4_word)(ts4_word)lbl_8803EC6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68834, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11798: call_seq lbl_88B68868, lbl_88CC713C, lbl_8803EE48, lbl_88CC662C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68868_88A11798(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC662C, (ts4_word)(ts4_word)lbl_8803EE48, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68868, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11810: call_seq lbl_88B688C8, lbl_88040040, lbl_88CC665C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B688C8_88A11810(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC665C, (ts4_word)(ts4_word)lbl_88040040, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B688C8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11880: call_seq lbl_88B68940, lbl_88CC662C, lbl_8803ECD0, lbl_88CC668C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68940_88A11880(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC668C, (ts4_word)(ts4_word)lbl_8803ECD0, (ts4_word)(ts4_word)lbl_88CC662C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68940, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A118F8: call_seq lbl_88B689E8, lbl_88CC662C, lbl_8803ECB0, lbl_88CC66BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B689E8_88A118F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC66BC, (ts4_word)(ts4_word)lbl_8803ECB0, (ts4_word)(ts4_word)lbl_88CC662C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B689E8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11970: call_seq lbl_88B68A00, lbl_88040078, lbl_88CC66EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68A00_88A11970(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC66EC, (ts4_word)(ts4_word)lbl_88040078, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68A00, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A119E0: call_seq lbl_88B68A78, lbl_88CC662C, lbl_8803EC94, lbl_88CC671C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68A78_88A119E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC671C, (ts4_word)(ts4_word)lbl_8803EC94, (ts4_word)(ts4_word)lbl_88CC662C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68A78, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11A58: call_seq lbl_88B68B20, lbl_88046C60, lbl_88CC674C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68B20_88A11A58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC674C, (ts4_word)(ts4_word)lbl_88046C60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68B20, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11AC8: call_seq lbl_88B68B38, lbl_8803EE88, lbl_88CC677C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68B38_88A11AC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC677C, (ts4_word)(ts4_word)lbl_8803EE88, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68B38, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11B38: call_seq lbl_88B68B98, lbl_88CC713C, lbl_8804002C, lbl_88CC67AC, lbl_88054408, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68B98_88A11B38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC67AC, (ts4_word)(ts4_word)lbl_8804002C, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88054408, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B68B98, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11BA8: call_seq lbl_88B68BB0, lbl_88046C00, lbl_88CC67DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68BB0_88A11BA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC67DC, (ts4_word)(ts4_word)lbl_88046C00, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68BB0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11C18: call_seq lbl_88B68BF8, lbl_88046C24, lbl_88CC680C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68BF8_88A11C18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC680C, (ts4_word)(ts4_word)lbl_88046C24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68BF8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11C88: call_seq lbl_88B68C88, lbl_88046C48, lbl_88CC683C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68C88_88A11C88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC683C, (ts4_word)(ts4_word)lbl_88046C48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68C88, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11CF8: call_seq lbl_88CC713C, lbl_8803EC3C, lbl_88CC686C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC713C_88A11CF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC686C, (ts4_word)(ts4_word)lbl_8803EC3C, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11D60: call_seq lbl_88B68D18, lbl_88CC686C, lbl_8803ECF4, lbl_88CC689C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68D18_88A11D60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC689C, (ts4_word)(ts4_word)lbl_8803ECF4, (ts4_word)(ts4_word)lbl_88CC686C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68D18, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11DD8: call_seq lbl_88B68D78, lbl_8803EEFC, lbl_88CC68CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68D78_88A11DD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC68CC, (ts4_word)(ts4_word)lbl_8803EEFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68D78, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11E48: call_seq lbl_88B68DA8, lbl_8803EEE8, lbl_88CC68FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68DA8_88A11E48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC68FC, (ts4_word)(ts4_word)lbl_8803EEE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68DA8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11EB8: call_seq lbl_88B68E08, lbl_8803EE7C, lbl_88CC692C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68E08_88A11EB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC692C, (ts4_word)(ts4_word)lbl_8803EE7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68E08, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11F28: call_seq lbl_88B68E70, lbl_88042110, lbl_88CC695C, lbl_8805443C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68E70_88A11F28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC695C, (ts4_word)(ts4_word)lbl_88042110, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805443C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B68E70, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A11F98: call_seq lbl_88B68F78, lbl_88041224, lbl_88CC698C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B68F78_88A11F98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC698C, (ts4_word)(ts4_word)lbl_88041224, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B68F78, (ts4_word)13, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12008: call_seq lbl_88B690B0, lbl_88041204, lbl_88CC69BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B690B0_88A12008(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC69BC, (ts4_word)(ts4_word)lbl_88041204, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B690B0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12078: call_seq lbl_88B690C8, lbl_88041138, lbl_88CC69EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B690C8_88A12078(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC69EC, (ts4_word)(ts4_word)lbl_88041138, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B690C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A120E8: call_seq lbl_88B690E0, lbl_8804114C, lbl_88CC6A1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B690E0_88A120E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6A1C, (ts4_word)(ts4_word)lbl_8804114C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B690E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12158: call_seq lbl_88CC6F2C, lbl_88053DD8, lbl_88CC6A4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC6F2C_88A12158(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6A4C, (ts4_word)(ts4_word)lbl_88053DD8, (ts4_word)(ts4_word)lbl_88CC6F2C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A121C0: call_seq lbl_88B69110, lbl_88CC6A4C, lbl_88041268, lbl_88CC6A7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69110_88A121C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6A7C, (ts4_word)(ts4_word)lbl_88041268, (ts4_word)(ts4_word)lbl_88CC6A4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69110, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12238: call_seq lbl_88CC6A7C, lbl_88053DE8, lbl_88CC6AAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC6A7C_88A12238(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6AAC, (ts4_word)(ts4_word)lbl_88053DE8, (ts4_word)(ts4_word)lbl_88CC6A7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A122A0: call_seq lbl_88B691A0, lbl_8804124C, lbl_88CC6ADC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B691A0_88A122A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6ADC, (ts4_word)(ts4_word)lbl_8804124C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B691A0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12310: call_seq lbl_88B691E8, lbl_88CC6A4C, lbl_88041238, lbl_88CC6B0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B691E8_88A12310(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6B0C, (ts4_word)(ts4_word)lbl_88041238, (ts4_word)(ts4_word)lbl_88CC6A4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B691E8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12388: call_seq lbl_88B69260, lbl_8804115C, lbl_88CC6B3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69260_88A12388(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6B3C, (ts4_word)(ts4_word)lbl_8804115C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69260, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A123F8: addr lbl_88B6E970, u32@lbl_88B68E6C, u32@0x8 */
void ts4_addr_lbl_88B6E970_88A123F8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6E970) + 8) = (ts4_word)(*(ts4_word *)lbl_88B68E6C);
    return;
}

/* Swing_DLL.xex 0x88A12488: call_seq lbl_88B692A8, lbl_88CC6A4C, lbl_8804159C, lbl_88CC6B9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B692A8_88A12488(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6B9C, (ts4_word)(ts4_word)lbl_8804159C, (ts4_word)(ts4_word)lbl_88CC6A4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B692A8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12500: call_seq lbl_88B692D8, lbl_88CC6A4C, lbl_88053E90, lbl_88CC6BCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B692D8_88A12500(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6BCC, (ts4_word)(ts4_word)lbl_88053E90, (ts4_word)(ts4_word)lbl_88CC6A4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B692D8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12578: call_seq lbl_88CC6F2C, lbl_88053EAC, lbl_88CC6BFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CC6F2C_88A12578(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6BFC, (ts4_word)(ts4_word)lbl_88053EAC, (ts4_word)(ts4_word)lbl_88CC6F2C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A125E0: call_seq lbl_880544B0, lbl_88B692F0, lbl_88CC6BFC, lbl_88041634, lbl_88CC6C2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880544B0_88A125E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6C2C, (ts4_word)(ts4_word)lbl_88041634, (ts4_word)(ts4_word)lbl_88CC6BFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B692F0, (ts4_word)17, (ts4_word)(ts4_word)lbl_880544B0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12658: call_seq lbl_88B69488, lbl_88CC6BFC, lbl_880415B4, lbl_88CC6C5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69488_88A12658(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6C5C, (ts4_word)(ts4_word)lbl_880415B4, (ts4_word)(ts4_word)lbl_88CC6BFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69488, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A126D0: call_seq lbl_88B694A0, lbl_88CC6BFC, lbl_880411F0, lbl_88CC6C8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B694A0_88A126D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6C8C, (ts4_word)(ts4_word)lbl_880411F0, (ts4_word)(ts4_word)lbl_88CC6BFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B694A0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12748: call_seq lbl_88B69548, lbl_88CC6BFC, lbl_880411C8, lbl_88CC6CBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69548_88A12748(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6CBC, (ts4_word)(ts4_word)lbl_880411C8, (ts4_word)(ts4_word)lbl_88CC6BFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69548, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A127C0: call_seq lbl_88B69620, lbl_88CC6BFC, lbl_88048610, lbl_88CC6CEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69620_88A127C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6CEC, (ts4_word)(ts4_word)lbl_88048610, (ts4_word)(ts4_word)lbl_88CC6BFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69620, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12838: call_seq lbl_88B69728, lbl_88CC6BFC, lbl_88042140, lbl_88CC6D1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69728_88A12838(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6D1C, (ts4_word)(ts4_word)lbl_88042140, (ts4_word)(ts4_word)lbl_88CC6BFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69728, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A128B0: addr lbl_88B6EA90, u32@lbl_88B69758, u32@0x68 */
void ts4_addr_lbl_88B6EA90_88A128B0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6EA90) + 104) = (ts4_word)(*(ts4_word *)lbl_88B69758);
    return;
}

/* Swing_DLL.xex 0x88A12940: call_seq lbl_8805457C, lbl_88B6975C, lbl_88CC713C, lbl_88053F68, lbl_88CC6D7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805457C_88A12940(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6D7C, (ts4_word)(ts4_word)lbl_88053F68, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B6975C, (ts4_word)2, (ts4_word)(ts4_word)lbl_8805457C, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A129B8: call_seq lbl_88B69790, lbl_88042098, lbl_88CC6DAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69790_88A129B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6DAC, (ts4_word)(ts4_word)lbl_88042098, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69790, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12A28: addr lbl_88B6EC28, u32@lbl_88B6978C, u32@0x50 */
void ts4_addr_lbl_88B6EC28_88A12A28(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B6EC28) + 80) = (ts4_word)(*(ts4_word *)lbl_88B6978C);
    return;
}

/* Swing_DLL.xex 0x88A12AB8: call_seq lbl_88B69820, lbl_88CC6BFC, lbl_88042074, lbl_88CC6E0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69820_88A12AB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6E0C, (ts4_word)(ts4_word)lbl_88042074, (ts4_word)(ts4_word)lbl_88CC6BFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69820, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12B30: call_seq lbl_880545F8, lbl_88B69850, lbl_88CC6BFC, lbl_88041618, lbl_88CC6E3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880545F8_88A12B30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6E3C, (ts4_word)(ts4_word)lbl_88041618, (ts4_word)(ts4_word)lbl_88CC6BFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69850, (ts4_word)5, (ts4_word)(ts4_word)lbl_880545F8, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12BA8: call_seq lbl_88B698C8, lbl_880415F8, lbl_88CC6E6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B698C8_88A12BA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6E6C, (ts4_word)(ts4_word)lbl_880415F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B698C8, (ts4_word)13, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12C18: call_seq lbl_88054610, lbl_88B69A00, lbl_88CC6BFC, lbl_88040228, lbl_88CC6E9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88054610_88A12C18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6E9C, (ts4_word)(ts4_word)lbl_88040228, (ts4_word)(ts4_word)lbl_88CC6BFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69A00, (ts4_word)10, (ts4_word)(ts4_word)lbl_88054610, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12C90: call_seq lbl_88B69AF0, lbl_88CC6BFC, lbl_880415D4, lbl_88CC6ECC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69AF0_88A12C90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6ECC, (ts4_word)(ts4_word)lbl_880415D4, (ts4_word)(ts4_word)lbl_88CC6BFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69AF0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12D08: call_seq lbl_88B69B08, lbl_88CC6CBC, lbl_880411DC, lbl_88CC6EFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69B08_88A12D08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6EFC, (ts4_word)(ts4_word)lbl_880411DC, (ts4_word)(ts4_word)lbl_88CC6CBC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69B08, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A12D80: call_seq lbl_88B69B80, lbl_88CC713C, lbl_8804116C, lbl_88CC6F2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B69B80_88A12D80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CC6F2C, (ts4_word)(ts4_word)lbl_8804116C, (ts4_word)(ts4_word)lbl_88CC713C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B69B80, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}
