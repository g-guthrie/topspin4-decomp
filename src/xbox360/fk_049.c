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

extern char ts4_addr_lbl_8803A308_88AFF608[];
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
extern char lbl_8804002C[];
extern char lbl_88040040[];
extern char lbl_88040078[];
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
extern char lbl_8804115C[];
extern char lbl_88041204[];
extern char lbl_88041238[];
extern char lbl_8804124C[];
extern char lbl_88041268[];
extern char lbl_88041578[];
extern char lbl_88041584[];
extern char lbl_88041634[];
extern char lbl_88041DE0[];
extern char lbl_880420B8[];
extern char lbl_880420C8[];
extern char lbl_880420E4[];
extern char lbl_880420FC[];
extern char lbl_88042110[];
extern char lbl_88042128[];
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
extern char lbl_88042E20[];
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
extern char lbl_88045C4C[];
extern char lbl_88045DD8[];
extern char lbl_88045E10[];
extern char lbl_88045E90[];
extern char lbl_88045F4C[];
extern char lbl_88045FC0[];
extern char lbl_880460D0[];
extern char lbl_88046144[];
extern char lbl_88046C00[];
extern char lbl_88046C24[];
extern char lbl_88046C48[];
extern char lbl_88046C60[];
extern char lbl_88046C78[];
extern char lbl_88046C94[];
extern char lbl_88047050[];
extern char lbl_8804705C[];
extern char lbl_88047070[];
extern char lbl_8804707C[];
extern char lbl_88053DD8[];
extern char lbl_88053DE8[];
extern char lbl_88053E90[];
extern char lbl_88053EAC[];
extern char lbl_8805A548[];
extern char lbl_8805B240[];
extern char lbl_8805B2F8[];
extern char lbl_8805B354[];
extern char lbl_8805B398[];
extern char lbl_8805B3C4[];
extern char lbl_8805B400[];
extern char lbl_8805B424[];
extern char lbl_8805B458[];
extern char lbl_8805B484[];
extern char lbl_8805B498[];
extern char lbl_8805B4F4[];
extern char lbl_8805B508[];
extern char lbl_8805B56C[];
extern char lbl_8805B5D0[];
extern char lbl_8805B5E4[];
extern char lbl_8805B804[];
extern char lbl_8805B830[];
extern char lbl_8805B85C[];
extern char lbl_8805B888[];
extern char lbl_8805B8A0[];
extern char lbl_8805B8F8[];
extern char lbl_8805BF24[];
extern char lbl_8805BF68[];
extern char lbl_8805BF94[];
extern char lbl_8805BFC8[];
extern char lbl_8805BFDC[];
extern char lbl_8805C020[];
extern char lbl_8805C034[];
extern char lbl_8805C060[];
extern char lbl_8805C100[];
extern char lbl_88B8861C[];
extern char lbl_88B88620[];
extern char lbl_88B88680[];
extern char lbl_88B88728[];
extern char lbl_88B887A0[];
extern char lbl_88B887E8[];
extern char lbl_88B88878[];
extern char lbl_88B888D8[];
extern char lbl_88B88920[];
extern char lbl_88B88950[];
extern char lbl_88B88980[];
extern char lbl_88B88998[];
extern char lbl_88B889F8[];
extern char lbl_88B88A10[];
extern char lbl_88B88A40[];
extern char lbl_88B88A58[];
extern char lbl_88B88A70[];
extern char lbl_88B88ABC[];
extern char lbl_88B88AD4[];
extern char lbl_88B88AD8[];
extern char lbl_88B88B40[];
extern char lbl_88B88B70[];
extern char lbl_88B88B90[];
extern char lbl_88B88BD8[];
extern char lbl_88B88BF0[];
extern char lbl_88B88C80[];
extern char lbl_88B88C98[];
extern char lbl_88B88D10[];
extern char lbl_88B88D14[];
extern char lbl_88B88D44[];
extern char lbl_88B88D60[];
extern char lbl_88B88E08[];
extern char lbl_88B88E20[];
extern char lbl_88B88E50[];
extern char lbl_88B88E70[];
extern char lbl_88B88F18[];
extern char lbl_88B88F60[];
extern char lbl_88B89038[];
extern char lbl_88B89068[];
extern char lbl_88B89080[];
extern char lbl_88B890B0[];
extern char lbl_88B89140[];
extern char lbl_88B89188[];
extern char lbl_88B891A0[];
extern char lbl_88B89230[];
extern char lbl_88B89308[];
extern char lbl_88B89350[];
extern char lbl_88B893C8[];
extern char lbl_88B893F8[];
extern char lbl_88B89470[];
extern char lbl_88B894B8[];
extern char lbl_88B894BC[];
extern char lbl_88B894F0[];
extern char lbl_88B89550[];
extern char lbl_88B89580[];
extern char lbl_88B895C8[];
extern char lbl_88B895F8[];
extern char lbl_88B89610[];
extern char lbl_88B89790[];
extern char lbl_88B897C0[];
extern char lbl_88B89868[];
extern char lbl_88B8986C[];
extern char lbl_88B8989C[];
extern char lbl_88B898CC[];
extern char lbl_88B898E4[];
extern char lbl_88B89914[];
extern char lbl_88B8992C[];
extern char lbl_88B89948[];
extern char lbl_88B899F0[];
extern char lbl_88B899F4[];
extern char lbl_88B899F8[];
extern char lbl_88B89A00[];
extern char lbl_88B89A90[];
extern char lbl_88B89AA8[];
extern char lbl_88B89AC0[];
extern char lbl_88B89AD8[];
extern char lbl_88B89B20[];
extern char lbl_88B89B38[];
extern char lbl_88B89B70[];
extern char lbl_88B89C18[];
extern char lbl_88B89C38[];
extern char lbl_88B89C98[];
extern char lbl_88B89CB0[];
extern char lbl_88B89CF8[];
extern char lbl_88B89D58[];
extern char lbl_88B89DB8[];
extern char lbl_88B89E18[];
extern char lbl_88B89ED8[];
extern char lbl_88B8A0A0[];
extern char lbl_88B8A0B8[];
extern char lbl_88B8A0D0[];
extern char lbl_88B8A100[];
extern char lbl_88B8A130[];
extern char lbl_88B8A148[];
extern char lbl_88B8A178[];
extern char lbl_88B8A1C0[];
extern char lbl_88B8A208[];
extern char lbl_88B8A298[];
extern char lbl_88B8A2E0[];
extern char lbl_88B8A310[];
extern char lbl_88B8A340[];
extern char lbl_88B8A370[];
extern char lbl_88B8A388[];
extern char lbl_88B8A3A0[];
extern char lbl_88B8A3D0[];
extern char lbl_88B8A3E8[];
extern char lbl_88B8A4D8[];
extern char lbl_88B8A688[];
extern char lbl_88B8A820[];
extern char lbl_88B8AA78[];
extern char lbl_88B8AAF0[];
extern char lbl_88B8AB38[];
extern char lbl_88B8AB68[];
extern char lbl_88B8ABC8[];
extern char lbl_88B8AC28[];
extern char lbl_88B8AD18[];
extern char lbl_88B8AE08[];
extern char lbl_88B8AE50[];
extern char lbl_88B8AF28[];
extern char lbl_88B8AF40[];
extern char lbl_88B8AF88[];
extern char lbl_88B8AFD0[];
extern char lbl_88B8AFE8[];
extern char lbl_88B8B030[];
extern char lbl_88B8B048[];
extern char lbl_88B8B0F0[];
extern char lbl_88B8B120[];
extern char lbl_88B8B168[];
extern char lbl_88B8B1B0[];
extern char lbl_88B8B1F8[];
extern char lbl_88B8B210[];
extern char lbl_88B8B228[];
extern char lbl_88B8BEB8[];
extern char lbl_88B8BF00[];
extern char lbl_88B8BFD8[];
extern char lbl_88B8C050[];
extern char lbl_88B8C068[];
extern char lbl_88B8C128[];
extern char lbl_88B8C410[];
extern char lbl_88B8C488[];
extern char lbl_88B8C48C[];
extern char lbl_88B8C4BC[];
extern char lbl_88B8C4EC[];
extern char lbl_88B8C4F0[];
extern char lbl_88B8C580[];
extern char lbl_88B8C6A0[];
extern char lbl_88B8C6B8[];
extern char lbl_88B8C748[];
extern char lbl_88B8C838[];
extern char lbl_88B8C850[];
extern char lbl_88B8C8B4[];
extern char lbl_88B8C8D0[];
extern char lbl_88B8C918[];
extern char lbl_88B8C9A8[];
extern char lbl_88B8CA38[];
extern char lbl_88B8CA98[];
extern char lbl_88B8CAC8[];
extern char lbl_88B8CB28[];
extern char lbl_88B8CB88[];
extern char lbl_88B8CC00[];
extern char lbl_88B8CD08[];
extern char lbl_88B8CE14[];
extern char lbl_88B8CE44[];
extern char lbl_88B8CE48[];
extern char lbl_88B8CEF0[];
extern char lbl_88B8CF38[];
extern char lbl_88B8CFF8[];
extern char lbl_88B8D040[];
extern char lbl_88B8D070[];
extern char lbl_88B8D088[];
extern char lbl_88B8D0B8[];
extern char lbl_88B8D118[];
extern char lbl_88B8D148[];
extern char lbl_88B8D2C8[];
extern char lbl_88B92A28[];
extern char lbl_88B92A70[];
extern char lbl_88B92AE8[];
extern char lbl_88CD73FC[];
extern char lbl_88CD7EDC[];
extern char lbl_88CD7F9C[];
extern char lbl_88CD89BC[];
extern char lbl_88CD8CEC[];
extern char lbl_88CD8D1C[];
extern char lbl_88CD8D4C[];
extern char lbl_88CD8D7C[];
extern char lbl_88CD8DAC[];
extern char lbl_88CD8DDC[];
extern char lbl_88CD8E0C[];
extern char lbl_88CD8E3C[];
extern char lbl_88CD8E6C[];
extern char lbl_88CD8E9C[];
extern char lbl_88CD8ECC[];
extern char lbl_88CD8EFC[];
extern char lbl_88CD8F2C[];
extern char lbl_88CD8F5C[];
extern char lbl_88CD8F8C[];
extern char lbl_88CD8FBC[];
extern char lbl_88CD8FEC[];
extern char lbl_88CD901C[];
extern char lbl_88CD904C[];
extern char lbl_88CD907C[];
extern char lbl_88CD90AC[];
extern char lbl_88CD90DC[];
extern char lbl_88CD910C[];
extern char lbl_88CD913C[];
extern char lbl_88CD916C[];
extern char lbl_88CD919C[];
extern char lbl_88CD91CC[];
extern char lbl_88CD91FC[];
extern char lbl_88CD922C[];
extern char lbl_88CD925C[];
extern char lbl_88CD928C[];
extern char lbl_88CD92BC[];
extern char lbl_88CD92EC[];
extern char lbl_88CD931C[];
extern char lbl_88CD934C[];
extern char lbl_88CD937C[];
extern char lbl_88CD93AC[];
extern char lbl_88CD93DC[];
extern char lbl_88CD940C[];
extern char lbl_88CD943C[];
extern char lbl_88CD946C[];
extern char lbl_88CD949C[];
extern char lbl_88CD94CC[];
extern char lbl_88CD94FC[];
extern char lbl_88CD952C[];
extern char lbl_88CD955C[];
extern char lbl_88CD958C[];
extern char lbl_88CD95BC[];
extern char lbl_88CD95EC[];
extern char lbl_88CD961C[];
extern char lbl_88CD964C[];
extern char lbl_88CD967C[];
extern char lbl_88CD96AC[];
extern char lbl_88CD96DC[];
extern char lbl_88CD970C[];
extern char lbl_88CD973C[];
extern char lbl_88CD976C[];
extern char lbl_88CD979C[];
extern char lbl_88CD97CC[];
extern char lbl_88CD97FC[];
extern char lbl_88CD982C[];
extern char lbl_88CD985C[];
extern char lbl_88CD988C[];
extern char lbl_88CD98BC[];
extern char lbl_88CD98EC[];
extern char lbl_88CD991C[];
extern char lbl_88CD994C[];
extern char lbl_88CD997C[];
extern char lbl_88CD99AC[];
extern char lbl_88CD99DC[];
extern char lbl_88CD9A0C[];
extern char lbl_88CD9A3C[];
extern char lbl_88CD9A6C[];
extern char lbl_88CD9A9C[];
extern char lbl_88CD9ACC[];
extern char lbl_88CD9AFC[];
extern char lbl_88CD9B2C[];
extern char lbl_88CD9B5C[];
extern char lbl_88CD9B8C[];
extern char lbl_88CD9BBC[];
extern char lbl_88CD9BEC[];
extern char lbl_88CD9C1C[];
extern char lbl_88CD9C7C[];
extern char lbl_88CD9CAC[];
extern char lbl_88CD9CDC[];
extern char lbl_88CD9D0C[];
extern char lbl_88CD9D3C[];
extern char lbl_88CD9D6C[];
extern char lbl_88CD9D9C[];
extern char lbl_88CD9DCC[];
extern char lbl_88CD9DFC[];
extern char lbl_88CD9E2C[];
extern char lbl_88CD9E5C[];
extern char lbl_88CD9E8C[];
extern char lbl_88CD9EBC[];
extern char lbl_88CD9EEC[];
extern char lbl_88CD9F1C[];
extern char lbl_88CD9F4C[];
extern char lbl_88CD9F7C[];
extern char lbl_88CD9FAC[];
extern char lbl_88CD9FDC[];
extern char lbl_88CDA00C[];
extern char lbl_88CDA03C[];
extern char lbl_88CDA06C[];
extern char lbl_88CDA09C[];
extern char lbl_88CDA0CC[];
extern char lbl_88CDA0FC[];
extern char lbl_88CDA12C[];
extern char lbl_88CDA15C[];
extern char lbl_88CDA18C[];
extern char lbl_88CDA1BC[];
extern char lbl_88CDA1EC[];
extern char lbl_88CDA21C[];
extern char lbl_88CDA24C[];
extern char lbl_88CDA27C[];
extern char lbl_88CDA2AC[];
extern char lbl_88CDA2DC[];
extern char lbl_88CDA30C[];
extern char lbl_88CDA33C[];
extern char lbl_88CDA36C[];
extern char lbl_88CDA39C[];
extern char lbl_88CDA3CC[];
extern char lbl_88CDA3FC[];
extern char lbl_88CDA42C[];
extern char lbl_88CDA45C[];
extern char lbl_88CDA48C[];
extern char lbl_88CDA4BC[];
extern char lbl_88CDA4EC[];
extern char lbl_88CDA51C[];
extern char lbl_88CDA54C[];
extern char lbl_88CDA57C[];
extern char lbl_88CDA5AC[];
extern char lbl_88CDA5DC[];
extern char lbl_88CDA60C[];
extern char lbl_88CDA63C[];
extern char lbl_88CDA66C[];
extern char lbl_88CDA69C[];
extern char lbl_88CDA6CC[];
extern char lbl_88CDA6FC[];
extern char lbl_88CDA72C[];
extern char lbl_88CDA75C[];
extern char lbl_88CDA78C[];
extern char lbl_88CDA7BC[];
extern char lbl_88CDA7EC[];
extern char lbl_88CDA81C[];
extern char lbl_88CDA84C[];
extern char lbl_88CDA87C[];
extern char lbl_88CDA8AC[];
extern char lbl_88CDA8DC[];
extern char lbl_88CDA90C[];
extern char lbl_88CDA93C[];
extern char lbl_88CDA96C[];
extern char lbl_88CDA984[];
extern char lbl_88CDA9B4[];
extern char lbl_88CDA9E4[];
extern char lbl_88CDAA14[];
extern char lbl_88CDAA44[];
extern char lbl_88CDAA74[];
extern char lbl_88CDAAA4[];
extern char lbl_88CDAAD4[];
extern char lbl_88CDAB04[];
extern char lbl_88CDAB34[];
extern char lbl_88CDAB64[];
extern char lbl_88CDAB94[];
extern char lbl_88CDABC4[];
extern char lbl_88CDABF4[];
extern char lbl_88CDAC24[];
extern char lbl_88CDAC54[];
extern char lbl_88CDAC84[];
extern char lbl_88CDACB4[];
extern char lbl_88CDACE4[];
extern char lbl_88CDAD14[];
extern char lbl_88CDAD44[];
extern char lbl_88CDAD74[];
extern char lbl_88CDADA4[];
extern char lbl_88CDADD4[];
extern char lbl_88CDAE04[];
extern char lbl_88CDAE34[];
extern char lbl_88CDAE64[];
extern char lbl_88CDAE94[];
extern char lbl_88CDAEC4[];
extern char lbl_88CDAEF4[];
extern char lbl_88CDAF24[];
extern char lbl_88CDAF84[];
extern char lbl_88CDAFB4[];
extern char lbl_88CDAFE4[];
extern char lbl_88CDB014[];
extern char lbl_88CDB044[];
extern char lbl_88CDB074[];
extern char lbl_88CDB0A4[];
extern char lbl_88CDB0D4[];
extern char lbl_88CDB3D4[];
extern char lbl_88CDB644[];
ts4_word fn_8841F080();
ts4_word ts4_set_u32_offc_884CE988();
ts4_word fn_88563470();

/* Swing_DLL.xex 0x88A3E378: call_seq lbl_88B88620, lbl_88CD89BC, lbl_88046144, lbl_88CD8CEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88620_88A3E378(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8CEC, (ts4_word)(ts4_word)lbl_88046144, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88620, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E3F0: call_seq lbl_88B88680, lbl_88CD89BC, lbl_880460D0, lbl_88CD8D1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88680_88A3E3F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8D1C, (ts4_word)(ts4_word)lbl_880460D0, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88680, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E468: call_seq lbl_88B88728, lbl_88CD89BC, lbl_88045DD8, lbl_88CD8D4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88728_88A3E468(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8D4C, (ts4_word)(ts4_word)lbl_88045DD8, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88728, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E4E0: call_seq lbl_88B887A0, lbl_88CD89BC, lbl_88045FC0, lbl_88CD8D7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B887A0_88A3E4E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8D7C, (ts4_word)(ts4_word)lbl_88045FC0, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B887A0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E558: call_seq lbl_88B887E8, lbl_88CD89BC, lbl_88045F4C, lbl_88CD8DAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B887E8_88A3E558(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8DAC, (ts4_word)(ts4_word)lbl_88045F4C, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B887E8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E5D0: call_seq lbl_88B88878, lbl_88CD89BC, lbl_88045E10, lbl_88CD8DDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88878_88A3E5D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8DDC, (ts4_word)(ts4_word)lbl_88045E10, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88878, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E648: call_seq lbl_88B888D8, lbl_88CD89BC, lbl_880422DC, lbl_88CD8E0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B888D8_88A3E648(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8E0C, (ts4_word)(ts4_word)lbl_880422DC, (ts4_word)(ts4_word)lbl_88CD89BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B888D8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E6C0: call_seq lbl_88B88920, lbl_88CD8E0C, lbl_88045C4C, lbl_88CD8E3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88920_88A3E6C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8E3C, (ts4_word)(ts4_word)lbl_88045C4C, (ts4_word)(ts4_word)lbl_88CD8E0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88920, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E738: call_seq lbl_88B88950, lbl_88CD8E0C, lbl_88043EE0, lbl_88CD8E6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88950_88A3E738(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8E6C, (ts4_word)(ts4_word)lbl_88043EE0, (ts4_word)(ts4_word)lbl_88CD8E0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88950, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E7B0: call_seq lbl_88CD8E0C, lbl_88045B88, lbl_88CD8E9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD8E0C_88A3E7B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8E9C, (ts4_word)(ts4_word)lbl_88045B88, (ts4_word)(ts4_word)lbl_88CD8E0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E818: call_seq lbl_88B88980, lbl_88CD8E0C, lbl_88045E90, lbl_88CD8ECC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88980_88A3E818(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8ECC, (ts4_word)(ts4_word)lbl_88045E90, (ts4_word)(ts4_word)lbl_88CD8E0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88980, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E890: call_seq lbl_88B88998, lbl_88CD73FC, lbl_88047050, lbl_88CD8EFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88998_88A3E890(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8EFC, (ts4_word)(ts4_word)lbl_88047050, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88998, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E908: call_seq lbl_88B889F8, lbl_88CD8EFC, lbl_88045B44, lbl_88CD8F2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B889F8_88A3E908(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8F2C, (ts4_word)(ts4_word)lbl_88045B44, (ts4_word)(ts4_word)lbl_88CD8EFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B889F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E980: call_seq lbl_88B88A10, lbl_88CD8EFC, lbl_88045B24, lbl_88CD8F5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88A10_88A3E980(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8F5C, (ts4_word)(ts4_word)lbl_88045B24, (ts4_word)(ts4_word)lbl_88CD8EFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88A10, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3E9F8: call_seq lbl_88B88A40, lbl_88CD8EFC, lbl_880459C0, lbl_88CD8F8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88A40_88A3E9F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8F8C, (ts4_word)(ts4_word)lbl_880459C0, (ts4_word)(ts4_word)lbl_88CD8EFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88A40, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3EA70: addr lbl_88B8BEB8, u32@lbl_88B8861C, u32@0x8 */
void ts4_addr_lbl_88B8BEB8_88A3EA70(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8BEB8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B8861C);
    return;
}

/* Swing_DLL.xex 0x88A3EA88: call_seq lbl_88B8BEB8, lbl_88045224, lbl_88CD8FBC, lbl_8805B240, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8BEB8_88A3EA88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8FBC, (ts4_word)(ts4_word)lbl_88045224, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805B240, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B8BEB8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3EAF8: call_seq lbl_88B88A58, lbl_88045194, lbl_88CD8FEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88A58_88A3EAF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD8FEC, (ts4_word)(ts4_word)lbl_88045194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88A58, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3EB68: call_seq lbl_88B88A70, lbl_8803EF90, lbl_88CD901C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88A70_88A3EB68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD901C, (ts4_word)(ts4_word)lbl_8803EF90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88A70, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3EBD8: call_seq lbl_88B88ABC, lbl_88CD73FC, lbl_8803FA04, lbl_88CD904C, lbl_8805B2F8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88ABC_88A3EBD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD904C, (ts4_word)(ts4_word)lbl_8803FA04, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805B2F8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B88ABC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3EC48: call_seq lbl_88B88AD8, lbl_88042170, lbl_88CD907C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88AD8_88A3EC48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD907C, (ts4_word)(ts4_word)lbl_88042170, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88AD8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3ECB8: addr lbl_88B8BF00, u32@lbl_88B88AD4, u32@0x68 */
void ts4_addr_lbl_88B8BF00_88A3ECB8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8BF00) + 104) = (ts4_word)(*(ts4_word *)lbl_88B88AD4);
    return;
}

/* Swing_DLL.xex 0x88A3ECD0: call_seq lbl_88B8BF00, lbl_88CD73FC, lbl_8803F0C8, lbl_88CD90AC, lbl_8805B354, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8BF00_88A3ECD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD90AC, (ts4_word)(ts4_word)lbl_8803F0C8, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805B354, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B8BF00, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3ED48: call_seq lbl_88B88B40, lbl_880422B8, lbl_88CD90DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88B40_88A3ED48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD90DC, (ts4_word)(ts4_word)lbl_880422B8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88B40, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3EDB8: call_seq lbl_88B88B70, lbl_88CD904C, lbl_880403DC, lbl_88CD910C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88B70_88A3EDB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD910C, (ts4_word)(ts4_word)lbl_880403DC, (ts4_word)(ts4_word)lbl_88CD904C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88B70, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3EE30: call_seq lbl_88B88B90, lbl_8804229C, lbl_88CD913C, lbl_8805B398, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88B90_88A3EE30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD913C, (ts4_word)(ts4_word)lbl_8804229C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805B398, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B88B90, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3EEA0: call_seq lbl_88B88BD8, lbl_88CD904C, lbl_88040394, lbl_88CD916C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88BD8_88A3EEA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD916C, (ts4_word)(ts4_word)lbl_88040394, (ts4_word)(ts4_word)lbl_88CD904C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88BD8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3EF18: call_seq lbl_88B88BF0, lbl_88042260, lbl_88CD919C, lbl_8805B3C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88BF0_88A3EF18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD919C, (ts4_word)(ts4_word)lbl_88042260, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805B3C4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B88BF0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3EF88: call_seq lbl_88B88C80, lbl_88CD904C, lbl_8803F690, lbl_88CD91CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88C80_88A3EF88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD91CC, (ts4_word)(ts4_word)lbl_8803F690, (ts4_word)(ts4_word)lbl_88CD904C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88C80, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F000: call_seq lbl_88B88C98, lbl_88CD922C, lbl_88045734, lbl_88CD91FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88C98_88A3F000(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD91FC, (ts4_word)(ts4_word)lbl_88045734, (ts4_word)(ts4_word)lbl_88CD922C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88C98, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F078: call_seq lbl_88CD73FC, lbl_88045A30, lbl_88CD922C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD73FC_88A3F078(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD922C, (ts4_word)(ts4_word)lbl_88045A30, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F0E0: addr lbl_88B8BFD8, u32@lbl_88B88D10, u32@0x50 */
void ts4_addr_lbl_88B8BFD8_88A3F0E0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8BFD8) + 80) = (ts4_word)(*(ts4_word *)lbl_88B88D10);
    return;
}

/* Swing_DLL.xex 0x88A3F0F8: call_seq lbl_88B8BFD8, lbl_88CD904C, lbl_88040364, lbl_88CD925C, lbl_8805B400, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8BFD8_88A3F0F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD925C, (ts4_word)(ts4_word)lbl_88040364, (ts4_word)(ts4_word)lbl_88CD904C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805B400, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B8BFD8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F170: call_seq lbl_88B88D14, lbl_8804223C, lbl_88CD928C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88D14_88A3F170(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD928C, (ts4_word)(ts4_word)lbl_8804223C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88D14, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F1E0: call_seq lbl_88B88D44, lbl_88CD904C, lbl_88040344, lbl_88CD92BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88D44_88A3F1E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD92BC, (ts4_word)(ts4_word)lbl_88040344, (ts4_word)(ts4_word)lbl_88CD904C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88D44, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F258: call_seq lbl_88B88D60, lbl_8804221C, lbl_88CD92EC, lbl_8805B424, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88D60_88A3F258(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD92EC, (ts4_word)(ts4_word)lbl_8804221C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805B424, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B88D60, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F2C8: call_seq lbl_88B88E08, lbl_88CD904C, lbl_8803F048, lbl_88CD931C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88E08_88A3F2C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD931C, (ts4_word)(ts4_word)lbl_8803F048, (ts4_word)(ts4_word)lbl_88CD904C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88E08, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F340: call_seq lbl_88B88E20, lbl_880421A0, lbl_88CD934C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88E20_88A3F340(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD934C, (ts4_word)(ts4_word)lbl_880421A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88E20, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F3B0: call_seq lbl_88B88E50, lbl_88CD904C, lbl_880402E4, lbl_88CD937C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88E50_88A3F3B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD937C, (ts4_word)(ts4_word)lbl_880402E4, (ts4_word)(ts4_word)lbl_88CD904C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88E50, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F428: call_seq lbl_88B88E70, lbl_88042184, lbl_88CD93AC, lbl_8805B458, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88E70_88A3F428(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD93AC, (ts4_word)(ts4_word)lbl_88042184, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805B458, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B88E70, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F498: call_seq lbl_88B88F18, lbl_88CD904C, lbl_880402CC, lbl_88CD93DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88F18_88A3F498(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD93DC, (ts4_word)(ts4_word)lbl_880402CC, (ts4_word)(ts4_word)lbl_88CD904C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88F18, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F510: call_seq lbl_88B88F60, lbl_88CD904C, lbl_8803F6B0, lbl_88CD940C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B88F60_88A3F510(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD940C, (ts4_word)(ts4_word)lbl_8803F6B0, (ts4_word)(ts4_word)lbl_88CD904C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B88F60, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F588: call_seq lbl_88CD904C, lbl_88045AFC, lbl_88CD943C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD904C_88A3F588(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD943C, (ts4_word)(ts4_word)lbl_88045AFC, (ts4_word)(ts4_word)lbl_88CD904C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F5F0: call_seq lbl_88B89038, lbl_88CD90AC, lbl_8804589C, lbl_88CD946C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89038_88A3F5F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD946C, (ts4_word)(ts4_word)lbl_8804589C, (ts4_word)(ts4_word)lbl_88CD90AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89038, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F668: call_seq lbl_88B89068, lbl_88CD8EFC, lbl_88045860, lbl_88CD949C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89068_88A3F668(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD949C, (ts4_word)(ts4_word)lbl_88045860, (ts4_word)(ts4_word)lbl_88CD8EFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89068, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F6E0: call_seq lbl_88B89080, lbl_880453D8, lbl_88CD94CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89080_88A3F6E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD94CC, (ts4_word)(ts4_word)lbl_880453D8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89080, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F750: call_seq lbl_88B890B0, lbl_88CD943C, lbl_880403C4, lbl_88CD94FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B890B0_88A3F750(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD94FC, (ts4_word)(ts4_word)lbl_880403C4, (ts4_word)(ts4_word)lbl_88CD943C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B890B0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F7C8: call_seq lbl_88B89140, lbl_88042284, lbl_88CD952C, lbl_8805B484, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89140_88A3F7C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD952C, (ts4_word)(ts4_word)lbl_88042284, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805B484, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B89140, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F838: call_seq lbl_88B89188, lbl_88CD904C, lbl_88040380, lbl_88CD955C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89188_88A3F838(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD955C, (ts4_word)(ts4_word)lbl_88040380, (ts4_word)(ts4_word)lbl_88CD904C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89188, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F8B0: call_seq lbl_88B891A0, lbl_8803FC48, lbl_88CD958C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B891A0_88A3F8B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD958C, (ts4_word)(ts4_word)lbl_8803FC48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B891A0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F920: call_seq lbl_8805B498, lbl_88B89230, lbl_88CD943C, lbl_8803FC6C, lbl_88CD95BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805B498_88A3F920(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD95BC, (ts4_word)(ts4_word)lbl_8803FC6C, (ts4_word)(ts4_word)lbl_88CD943C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89230, (ts4_word)9, (ts4_word)(ts4_word)lbl_8805B498, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3F998: call_seq lbl_88B89308, lbl_88045020, lbl_88CD95EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89308_88A3F998(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD95EC, (ts4_word)(ts4_word)lbl_88045020, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89308, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3FA08: call_seq lbl_88B89350, lbl_88CD943C, lbl_88040300, lbl_88CD961C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89350_88A3FA08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD961C, (ts4_word)(ts4_word)lbl_88040300, (ts4_word)(ts4_word)lbl_88CD943C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89350, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3FA80: call_seq lbl_88B893C8, lbl_88CD904C, lbl_880403AC, lbl_88CD964C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B893C8_88A3FA80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD964C, (ts4_word)(ts4_word)lbl_880403AC, (ts4_word)(ts4_word)lbl_88CD904C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B893C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3FAF8: call_seq lbl_88B893F8, lbl_880422F8, lbl_88CD967C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B893F8_88A3FAF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD967C, (ts4_word)(ts4_word)lbl_880422F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B893F8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3FB68: call_seq lbl_88B89470, lbl_88CD904C, lbl_8803FA18, lbl_88CD96AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89470_88A3FB68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD96AC, (ts4_word)(ts4_word)lbl_8803FA18, (ts4_word)(ts4_word)lbl_88CD904C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89470, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3FBE0: addr lbl_88B8C050, u32@lbl_88B894B8, u32@0x8 */
void ts4_addr_lbl_88B8C050_88A3FBE0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8C050) + 8) = (ts4_word)(*(ts4_word *)lbl_88B894B8);
    return;
}

/* Swing_DLL.xex 0x88A3FBF8: call_seq lbl_88B8C050, lbl_88CD73FC, lbl_8803FBE0, lbl_88CD96DC, lbl_8805B4F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8C050_88A3FBF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD96DC, (ts4_word)(ts4_word)lbl_8803FBE0, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805B4F4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B8C050, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3FC68: call_seq lbl_88B894BC, lbl_88CD96DC, lbl_88045A70, lbl_88CD970C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B894BC_88A3FC68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD970C, (ts4_word)(ts4_word)lbl_88045A70, (ts4_word)(ts4_word)lbl_88CD96DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B894BC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3FCE0: call_seq lbl_88B894F0, lbl_88CD970C, lbl_8803FCA0, lbl_88CD973C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B894F0_88A3FCE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD973C, (ts4_word)(ts4_word)lbl_8803FCA0, (ts4_word)(ts4_word)lbl_88CD970C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B894F0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3FD58: call_seq lbl_88B89550, lbl_88CD970C, lbl_8803FC80, lbl_88CD976C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89550_88A3FD58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD976C, (ts4_word)(ts4_word)lbl_8803FC80, (ts4_word)(ts4_word)lbl_88CD970C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89550, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3FDD0: call_seq lbl_88B89580, lbl_88CD970C, lbl_8803F9E8, lbl_88CD979C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89580_88A3FDD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD979C, (ts4_word)(ts4_word)lbl_8803F9E8, (ts4_word)(ts4_word)lbl_88CD970C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89580, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3FE48: call_seq lbl_88B895C8, lbl_88042200, lbl_88CD97CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B895C8_88A3FE48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD97CC, (ts4_word)(ts4_word)lbl_88042200, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B895C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3FEB8: call_seq lbl_88B895F8, lbl_88CD904C, lbl_8804032C, lbl_88CD97FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B895F8_88A3FEB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD97FC, (ts4_word)(ts4_word)lbl_8804032C, (ts4_word)(ts4_word)lbl_88CD904C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B895F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3FF30: call_seq lbl_8805B508, lbl_88B89610, lbl_88CD9C7C, lbl_8803F6CC, lbl_88CD982C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805B508_88A3FF30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD982C, (ts4_word)(ts4_word)lbl_8803F6CC, (ts4_word)(ts4_word)lbl_88CD9C7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89610, (ts4_word)16, (ts4_word)(ts4_word)lbl_8805B508, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A3FFA8: call_seq lbl_88CD73FC, lbl_88045AA8, lbl_88CD985C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD73FC_88A3FFA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD985C, (ts4_word)(ts4_word)lbl_88045AA8, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40010: call_seq lbl_88CD98EC, lbl_880457FC, lbl_88CD988C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD98EC_88A40010(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD988C, (ts4_word)(ts4_word)lbl_880457FC, (ts4_word)(ts4_word)lbl_88CD98EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40078: call_seq lbl_88CD982C, lbl_880455E0, lbl_88CD98BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD982C_88A40078(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD98BC, (ts4_word)(ts4_word)lbl_880455E0, (ts4_word)(ts4_word)lbl_88CD982C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A400E0: call_seq lbl_8805B56C, lbl_88CD985C, lbl_880459F8, lbl_88CD98EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805B56C_88A400E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD98EC, (ts4_word)(ts4_word)lbl_880459F8, (ts4_word)(ts4_word)lbl_88CD985C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805B56C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40148: call_seq lbl_88B89790, lbl_88045070, lbl_88CD991C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89790_88A40148(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD991C, (ts4_word)(ts4_word)lbl_88045070, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89790, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A401B8: call_seq lbl_88B897C0, lbl_88CD98EC, lbl_88041DE0, lbl_88CD994C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B897C0_88A401B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD994C, (ts4_word)(ts4_word)lbl_88041DE0, (ts4_word)(ts4_word)lbl_88CD98EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B897C0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40230: addr lbl_88B8C068, u32@lbl_88B89868, u32@0x8 */
void ts4_addr_lbl_88B8C068_88A40230(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8C068) + 8) = (ts4_word)(*(ts4_word *)lbl_88B89868);
    return;
}

/* Swing_DLL.xex 0x88A40248: call_seq lbl_88B8C068, lbl_88CD73FC, lbl_8803F5D4, lbl_88CD997C, lbl_8805B5D0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8C068_88A40248(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD997C, (ts4_word)(ts4_word)lbl_8803F5D4, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805B5D0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B8C068, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A402C0: call_seq lbl_88CD997C, lbl_880402B0, lbl_88CD99AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD997C_88A402C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD99AC, (ts4_word)(ts4_word)lbl_880402B0, (ts4_word)(ts4_word)lbl_88CD997C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40328: call_seq lbl_88CD9A0C, lbl_88040E04, lbl_88CD99DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD9A0C_88A40328(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD99DC, (ts4_word)(ts4_word)lbl_88040E04, (ts4_word)(ts4_word)lbl_88CD9A0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40390: call_seq lbl_88B8986C, lbl_88CD997C, lbl_8803EFA8, lbl_88CD9A0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8986C_88A40390(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9A0C, (ts4_word)(ts4_word)lbl_8803EFA8, (ts4_word)(ts4_word)lbl_88CD997C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8986C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40408: call_seq lbl_88CD9A0C, lbl_880456EC, lbl_88CD9A3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD9A0C_88A40408(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9A3C, (ts4_word)(ts4_word)lbl_880456EC, (ts4_word)(ts4_word)lbl_88CD9A0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40470: call_seq lbl_88CD997C, lbl_880402A0, lbl_88CD9A6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD997C_88A40470(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9A6C, (ts4_word)(ts4_word)lbl_880402A0, (ts4_word)(ts4_word)lbl_88CD997C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A404D8: call_seq lbl_88CD99AC, lbl_88040E18, lbl_88CD9A9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD99AC_88A404D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9A9C, (ts4_word)(ts4_word)lbl_88040E18, (ts4_word)(ts4_word)lbl_88CD99AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40540: call_seq lbl_88CD9A6C, lbl_88040E68, lbl_88CD9ACC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD9A6C_88A40540(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9ACC, (ts4_word)(ts4_word)lbl_88040E68, (ts4_word)(ts4_word)lbl_88CD9A6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A405A8: call_seq lbl_88CD99AC, lbl_88040DB0, lbl_88CD9AFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD99AC_88A405A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9AFC, (ts4_word)(ts4_word)lbl_88040DB0, (ts4_word)(ts4_word)lbl_88CD99AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40610: call_seq lbl_88B8989C, lbl_88CD9B8C, lbl_8803F6D8, lbl_88CD9B2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8989C_88A40610(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9B2C, (ts4_word)(ts4_word)lbl_8803F6D8, (ts4_word)(ts4_word)lbl_88CD9B8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8989C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40688: call_seq lbl_88B898CC, lbl_88CD9BBC, lbl_88045914, lbl_88CD9B5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B898CC_88A40688(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9B5C, (ts4_word)(ts4_word)lbl_88045914, (ts4_word)(ts4_word)lbl_88CD9BBC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B898CC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40700: call_seq lbl_88B898E4, lbl_88CD9C7C, lbl_88047070, lbl_88CD9B8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B898E4_88A40700(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9B8C, (ts4_word)(ts4_word)lbl_88047070, (ts4_word)(ts4_word)lbl_88CD9C7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B898E4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40778: call_seq lbl_88B89914, lbl_88CD9B8C, lbl_880402BC, lbl_88CD9BBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89914_88A40778(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9BBC, (ts4_word)(ts4_word)lbl_880402BC, (ts4_word)(ts4_word)lbl_88CD9B8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89914, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A407F0: call_seq lbl_88B8992C, lbl_88CD9BBC, lbl_88045580, lbl_88CD9BEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8992C_88A407F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9BEC, (ts4_word)(ts4_word)lbl_88045580, (ts4_word)(ts4_word)lbl_88CD9BBC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8992C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40868: call_seq lbl_8805B5E4, lbl_88B89948, lbl_88CD73FC, lbl_8803F660, lbl_88CD9C1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805B5E4_88A40868(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9C1C, (ts4_word)(ts4_word)lbl_8803F660, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89948, (ts4_word)7, (ts4_word)(ts4_word)lbl_8805B5E4, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A408E0: get u32@lbl_88B899F8, lbl_88B8C128, u32@lbl_88B899F4, u32@lbl_88B899F0, u32@0x50, u32@0x128 */
void ts4_get_u32_lbl_88B899F8_88A408E0(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88B899F8;
    t2 = *(ts4_word *)lbl_88B899F4;
    t3 = *(ts4_word *)lbl_88B899F0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8C128) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8C128) + 296) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B8C128) + 632) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x88A40988: call_seq lbl_88B89A00, lbl_88CD73FC, lbl_8803F084, lbl_88CD9C7C, lbl_8805B804, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89A00_88A40988(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9C7C, (ts4_word)(ts4_word)lbl_8803F084, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805B804, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B89A00, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40A00: call_seq lbl_88B89A90, lbl_88CD73FC, lbl_8804707C, lbl_88CD9CAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89A90_88A40A00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9CAC, (ts4_word)(ts4_word)lbl_8804707C, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89A90, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40A78: call_seq lbl_88B89AA8, lbl_88CD7EDC, lbl_88044F38, lbl_88CD9CDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89AA8_88A40A78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9CDC, (ts4_word)(ts4_word)lbl_88044F38, (ts4_word)(ts4_word)lbl_88CD7EDC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89AA8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40AF0: call_seq lbl_88B89AC0, lbl_88042E20, lbl_88CD9D0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89AC0_88A40AF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9D0C, (ts4_word)(ts4_word)lbl_88042E20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89AC0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40B60: call_seq lbl_88B89AD8, lbl_88CD73FC, lbl_8803EFD0, lbl_88CD9D3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89AD8_88A40B60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9D3C, (ts4_word)(ts4_word)lbl_8803EFD0, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89AD8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40BD8: call_seq lbl_88B89B20, lbl_88044F10, lbl_88CD9D6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89B20_88A40BD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9D6C, (ts4_word)(ts4_word)lbl_88044F10, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89B20, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40C48: call_seq lbl_88B89B38, lbl_88CD73FC, lbl_88044F90, lbl_88CD9D9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89B38_88A40C48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9D9C, (ts4_word)(ts4_word)lbl_88044F90, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89B38, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40CC0: call_seq lbl_88B89B70, lbl_880421E0, lbl_88CD9DCC, lbl_8805B85C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89B70_88A40CC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9DCC, (ts4_word)(ts4_word)lbl_880421E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805B85C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B89B70, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40D30: call_seq lbl_88B89C18, lbl_88CD904C, lbl_8803F030, lbl_88CD9DFC, lbl_8805B830, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89C18_88A40D30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9DFC, (ts4_word)(ts4_word)lbl_8803F030, (ts4_word)(ts4_word)lbl_88CD904C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805B830, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B89C18, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40DA0: call_seq lbl_88B89C38, lbl_880421C4, lbl_88CD9E2C, lbl_8805B888, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89C38_88A40DA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9E2C, (ts4_word)(ts4_word)lbl_880421C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805B888, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B89C38, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40E10: call_seq lbl_88B89C98, lbl_88CD904C, lbl_88040318, lbl_88CD9E5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89C98_88A40E10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9E5C, (ts4_word)(ts4_word)lbl_88040318, (ts4_word)(ts4_word)lbl_88CD904C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89C98, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40E88: call_seq lbl_88B89CB0, lbl_88CD8F5C, lbl_88044EA8, lbl_88CD9E8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89CB0_88A40E88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9E8C, (ts4_word)(ts4_word)lbl_88044EA8, (ts4_word)(ts4_word)lbl_88CD8F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89CB0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40F00: call_seq lbl_88B89CF8, lbl_88CD8F5C, lbl_88044E64, lbl_88CD9EBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89CF8_88A40F00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9EBC, (ts4_word)(ts4_word)lbl_88044E64, (ts4_word)(ts4_word)lbl_88CD8F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89CF8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40F78: call_seq lbl_88B89D58, lbl_88CD8F8C, lbl_88044DD0, lbl_88CD9EEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89D58_88A40F78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9EEC, (ts4_word)(ts4_word)lbl_88044DD0, (ts4_word)(ts4_word)lbl_88CD8F8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89D58, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A40FF0: call_seq lbl_88B89DB8, lbl_88CD8F8C, lbl_88044CD0, lbl_88CD9F1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89DB8_88A40FF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9F1C, (ts4_word)(ts4_word)lbl_88044CD0, (ts4_word)(ts4_word)lbl_88CD8F8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89DB8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41068: call_seq lbl_88B89E18, lbl_88CD8F5C, lbl_88044BD4, lbl_88CD9F4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89E18_88A41068(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9F4C, (ts4_word)(ts4_word)lbl_88044BD4, (ts4_word)(ts4_word)lbl_88CD8F5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89E18, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A410E0: call_seq lbl_88B89ED8, lbl_8805B8A0, lbl_8803F094, lbl_88CD9F7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B89ED8_88A410E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9F7C, (ts4_word)(ts4_word)lbl_8803F094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B89ED8, (ts4_word)19, (ts4_word)(ts4_word)lbl_8805B8A0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41158: call_seq lbl_88B8A0A0, lbl_88CD7F9C, lbl_8803F0AC, lbl_88CD9FAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A0A0_88A41158(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9FAC, (ts4_word)(ts4_word)lbl_8803F0AC, (ts4_word)(ts4_word)lbl_88CD7F9C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A0A0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A411D0: call_seq lbl_88B8A0B8, lbl_88CD7F9C, lbl_88044E30, lbl_88CD9FDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A0B8_88A411D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD9FDC, (ts4_word)(ts4_word)lbl_88044E30, (ts4_word)(ts4_word)lbl_88CD7F9C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A0B8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41248: call_seq lbl_88B8A0D0, lbl_88CD7F9C, lbl_88044DF8, lbl_88CDA00C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A0D0_88A41248(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA00C, (ts4_word)(ts4_word)lbl_88044DF8, (ts4_word)(ts4_word)lbl_88CD7F9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A0D0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A412C0: call_seq lbl_88B8A100, lbl_88044B54, lbl_88CDA03C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A100_88A412C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA03C, (ts4_word)(ts4_word)lbl_88044B54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A100, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41330: call_seq lbl_88B8A130, lbl_88CD7F9C, lbl_88044D8C, lbl_88CDA06C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A130_88A41330(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA06C, (ts4_word)(ts4_word)lbl_88044D8C, (ts4_word)(ts4_word)lbl_88CD7F9C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A130, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A413A8: call_seq lbl_88B8A148, lbl_88044A90, lbl_88CDA09C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A148_88A413A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA09C, (ts4_word)(ts4_word)lbl_88044A90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A148, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41418: call_seq lbl_88B8A178, lbl_88044ACC, lbl_88CDA0CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A178_88A41418(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA0CC, (ts4_word)(ts4_word)lbl_88044ACC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A178, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41488: call_seq lbl_88B8A1C0, lbl_88CD73FC, lbl_88044CFC, lbl_88CDA0FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A1C0_88A41488(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA0FC, (ts4_word)(ts4_word)lbl_88044CFC, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A1C0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41500: call_seq lbl_88B8A208, lbl_88CD8F8C, lbl_8804705C, lbl_88CDA12C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A208_88A41500(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA12C, (ts4_word)(ts4_word)lbl_8804705C, (ts4_word)(ts4_word)lbl_88CD8F8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A208, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41578: call_seq lbl_88B8A298, lbl_88044A58, lbl_88CDA15C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A298_88A41578(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA15C, (ts4_word)(ts4_word)lbl_88044A58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A298, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A415E8: call_seq lbl_88B8A2E0, lbl_88044B0C, lbl_88CDA18C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A2E0_88A415E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA18C, (ts4_word)(ts4_word)lbl_88044B0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A2E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41658: call_seq lbl_88B8A310, lbl_88044B94, lbl_88CDA1BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A310_88A41658(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA1BC, (ts4_word)(ts4_word)lbl_88044B94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A310, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A416C8: call_seq lbl_88B8A340, lbl_88CD73FC, lbl_88044D60, lbl_88CDA1EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A340_88A416C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA1EC, (ts4_word)(ts4_word)lbl_88044D60, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A340, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41740: call_seq lbl_88B8A370, lbl_88CD73FC, lbl_88044C84, lbl_88CDA21C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A370_88A41740(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA21C, (ts4_word)(ts4_word)lbl_88044C84, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A370, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A417B8: call_seq lbl_88B8A388, lbl_88CD73FC, lbl_88044C48, lbl_88CDA24C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A388_88A417B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA24C, (ts4_word)(ts4_word)lbl_88044C48, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A388, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41830: call_seq lbl_88B8A3A0, lbl_88044A08, lbl_88CDA27C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A3A0_88A41830(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA27C, (ts4_word)(ts4_word)lbl_88044A08, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A3A0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A418A0: call_seq lbl_88B8A3D0, lbl_88CD73FC, lbl_88044C08, lbl_88CDA2AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A3D0_88A418A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA2AC, (ts4_word)(ts4_word)lbl_88044C08, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A3D0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41918: call_seq lbl_88B8A3E8, lbl_88040668, lbl_88CDA2DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A3E8_88A41918(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA2DC, (ts4_word)(ts4_word)lbl_88040668, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A3E8, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41988: call_seq lbl_88B8A4D8, lbl_88CD73FC, lbl_88040658, lbl_88CDA30C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A4D8_88A41988(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA30C, (ts4_word)(ts4_word)lbl_88040658, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A4D8, (ts4_word)18, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41A00: call_seq lbl_88B8A688, lbl_8803F5F4, lbl_88CDA33C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A688_88A41A00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA33C, (ts4_word)(ts4_word)lbl_8803F5F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A688, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41A70: call_seq lbl_88B8A820, lbl_88CD8F8C, lbl_8803F64C, lbl_88CDA36C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8A820_88A41A70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA36C, (ts4_word)(ts4_word)lbl_8803F64C, (ts4_word)(ts4_word)lbl_88CD8F8C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8A820, (ts4_word)25, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41AE8: call_seq lbl_88CD73FC, lbl_8804494C, lbl_88CDA39C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD73FC_88A41AE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA39C, (ts4_word)(ts4_word)lbl_8804494C, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41B50: call_seq lbl_88B8AA78, lbl_88CDA39C, lbl_88044700, lbl_88CDA3CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8AA78_88A41B50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA3CC, (ts4_word)(ts4_word)lbl_88044700, (ts4_word)(ts4_word)lbl_88CDA39C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8AA78, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41BC8: call_seq lbl_88CD73FC, lbl_88044924, lbl_88CDA3FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD73FC_88A41BC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA3FC, (ts4_word)(ts4_word)lbl_88044924, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41C30: call_seq lbl_88B8AAF0, lbl_88044438, lbl_88CDA42C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8AAF0_88A41C30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA42C, (ts4_word)(ts4_word)lbl_88044438, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8AAF0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41CA0: call_seq lbl_88B8AB38, lbl_88CDA3FC, lbl_88044680, lbl_88CDA45C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8AB38_88A41CA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA45C, (ts4_word)(ts4_word)lbl_88044680, (ts4_word)(ts4_word)lbl_88CDA3FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8AB38, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41D18: call_seq lbl_88CD73FC, lbl_880448C8, lbl_88CDA48C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD73FC_88A41D18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA48C, (ts4_word)(ts4_word)lbl_880448C8, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41D80: call_seq lbl_88CD73FC, lbl_880448FC, lbl_88CDA4BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD73FC_88A41D80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA4BC, (ts4_word)(ts4_word)lbl_880448FC, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41DE8: call_seq lbl_88B8AB68, lbl_88CDA48C, lbl_88044524, lbl_88CDA4EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8AB68_88A41DE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA4EC, (ts4_word)(ts4_word)lbl_88044524, (ts4_word)(ts4_word)lbl_88CDA48C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8AB68, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41E60: call_seq lbl_88B8ABC8, lbl_88CDA4BC, lbl_880446BC, lbl_88CDA51C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8ABC8_88A41E60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA51C, (ts4_word)(ts4_word)lbl_880446BC, (ts4_word)(ts4_word)lbl_88CDA4BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8ABC8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41ED8: call_seq lbl_88CD73FC, lbl_8804489C, lbl_88CDA54C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD73FC_88A41ED8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA54C, (ts4_word)(ts4_word)lbl_8804489C, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41F40: call_seq lbl_88B8AC28, lbl_88CDA54C, lbl_88044650, lbl_88CDA57C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8AC28_88A41F40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA57C, (ts4_word)(ts4_word)lbl_88044650, (ts4_word)(ts4_word)lbl_88CDA54C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8AC28, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A41FB8: call_seq lbl_88B8AD18, lbl_88044324, lbl_88CDA5AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8AD18_88A41FB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA5AC, (ts4_word)(ts4_word)lbl_88044324, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8AD18, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42028: call_seq lbl_88B8AE08, lbl_88044370, lbl_88CDA5DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8AE08_88A42028(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA5DC, (ts4_word)(ts4_word)lbl_88044370, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8AE08, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42098: call_seq lbl_88B8AE50, lbl_8803F610, lbl_88CDA60C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8AE50_88A42098(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA60C, (ts4_word)(ts4_word)lbl_8803F610, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8AE50, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42108: call_seq lbl_88B8AF28, lbl_8803F634, lbl_88CDA63C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8AF28_88A42108(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA63C, (ts4_word)(ts4_word)lbl_8803F634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8AF28, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42178: call_seq lbl_88CD73FC, lbl_88044874, lbl_88CDA66C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD73FC_88A42178(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA66C, (ts4_word)(ts4_word)lbl_88044874, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A421E0: call_seq lbl_88B8AF40, lbl_88CDA66C, lbl_8804461C, lbl_88CDA69C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8AF40_88A421E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA69C, (ts4_word)(ts4_word)lbl_8804461C, (ts4_word)(ts4_word)lbl_88CDA66C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8AF40, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42258: call_seq lbl_88B8AF88, lbl_88044268, lbl_88CDA6CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8AF88_88A42258(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA6CC, (ts4_word)(ts4_word)lbl_88044268, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8AF88, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A422C8: call_seq lbl_88B8AFD0, lbl_88CD73FC, lbl_8804484C, lbl_88CDA6FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8AFD0_88A422C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA6FC, (ts4_word)(ts4_word)lbl_8804484C, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8AFD0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42340: call_seq lbl_88B8AFE8, lbl_880443CC, lbl_88CDA72C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8AFE8_88A42340(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA72C, (ts4_word)(ts4_word)lbl_880443CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8AFE8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A423B0: call_seq lbl_88B8B030, lbl_88CDA6FC, lbl_880445E4, lbl_88CDA75C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8B030_88A423B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA75C, (ts4_word)(ts4_word)lbl_880445E4, (ts4_word)(ts4_word)lbl_88CDA6FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8B030, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42428: call_seq lbl_88CD73FC, lbl_8804481C, lbl_88CDA78C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD73FC_88A42428(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA78C, (ts4_word)(ts4_word)lbl_8804481C, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42490: call_seq lbl_88B8B048, lbl_88CDA78C, lbl_880445A8, lbl_88CDA7BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8B048_88A42490(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA7BC, (ts4_word)(ts4_word)lbl_880445A8, (ts4_word)(ts4_word)lbl_88CDA78C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8B048, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42508: call_seq lbl_88B8B0F0, lbl_8804449C, lbl_88CDA7EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8B0F0_88A42508(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA7EC, (ts4_word)(ts4_word)lbl_8804449C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8B0F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42578: call_seq lbl_88B8B120, lbl_88CD73FC, lbl_88044744, lbl_88CDA81C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8B120_88A42578(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA81C, (ts4_word)(ts4_word)lbl_88044744, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8B120, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A425F0: call_seq lbl_88B8B168, lbl_88CD73FC, lbl_88044758, lbl_88CDA84C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8B168_88A425F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA84C, (ts4_word)(ts4_word)lbl_88044758, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8B168, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42668: call_seq lbl_88CD73FC, lbl_880447EC, lbl_88CDA87C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD73FC_88A42668(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA87C, (ts4_word)(ts4_word)lbl_880447EC, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A426D0: call_seq lbl_88B8B1B0, lbl_88CDA87C, lbl_88044568, lbl_88CDA8AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8B1B0_88A426D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA8AC, (ts4_word)(ts4_word)lbl_88044568, (ts4_word)(ts4_word)lbl_88CDA87C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8B1B0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42748: call_seq lbl_88B8B1F8, lbl_88CD73FC, lbl_880447B8, lbl_88CDA8DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8B1F8_88A42748(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA8DC, (ts4_word)(ts4_word)lbl_880447B8, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8B1F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A427C0: call_seq lbl_88B8B210, lbl_88CD73FC, lbl_88044784, lbl_88CDA90C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8B210_88A427C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA90C, (ts4_word)(ts4_word)lbl_88044784, (ts4_word)(ts4_word)lbl_88CD73FC, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8B210, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42838: call_seq lbl_88B8B228, lbl_88CDA8DC, lbl_880444CC, lbl_88CDA93C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8B228_88A42838(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA93C, (ts4_word)(ts4_word)lbl_880444CC, (ts4_word)(ts4_word)lbl_88CDA8DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8B228, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A428B0: call_seq lbl_8805A548, lbl_8805B8F8, lbl_88CDA96C, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF608, fn_88563470 */
ts4_word ts4_call_seq_lbl_8805A548_88A428B0(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CDA96C, (ts4_word)(ts4_word)lbl_8805B8F8, (ts4_word)4, (ts4_word)(ts4_word)lbl_8805A548);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF608);
    return t2;
}

/* Swing_DLL.xex 0x88A428F8: call_seq lbl_88B8C410, lbl_88046C94, lbl_88CDA984, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8C410_88A428F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA984, (ts4_word)(ts4_word)lbl_88046C94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8C410, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42968: addr lbl_88B92A28, u32@lbl_88B8C488, u32@0x38 */
void ts4_addr_lbl_88B92A28_88A42968(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B92A28) + 56) = (ts4_word)(*(ts4_word *)lbl_88B8C488);
    return;
}

/* Swing_DLL.xex 0x88A42980: call_seq lbl_8805BF24, lbl_88B92A28, lbl_8803EF04, lbl_88CDA9B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805BF24_88A42980(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA9B4, (ts4_word)(ts4_word)lbl_8803EF04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805BF24, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B92A28, (ts4_word)3, (ts4_word)((ts4_word)lbl_8805BF24 + 20), (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A429F8: call_seq lbl_88B8C48C, lbl_88046C78, lbl_88CDA9E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8C48C_88A429F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDA9E4, (ts4_word)(ts4_word)lbl_88046C78, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8C48C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42A68: call_seq lbl_88B8C4BC, lbl_8803EC6C, lbl_88CDAA14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8C4BC_88A42A68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAA14, (ts4_word)(ts4_word)lbl_8803EC6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8C4BC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42AD8: addr lbl_88B92A70, u32@lbl_88B8C4EC, u32@0x8 */
void ts4_addr_lbl_88B92A70_88A42AD8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B92A70) + 8) = (ts4_word)(*(ts4_word *)lbl_88B8C4EC);
    return;
}

/* Swing_DLL.xex 0x88A42AF0: call_seq lbl_88B92A70, lbl_88CDB644, lbl_8803EE48, lbl_88CDAA44, lbl_8805BF68, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B92A70_88A42AF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAA44, (ts4_word)(ts4_word)lbl_8803EE48, (ts4_word)(ts4_word)lbl_88CDB644, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805BF68, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B92A70, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42B68: call_seq lbl_88B8C4F0, lbl_88040040, lbl_88CDAA74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8C4F0_88A42B68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAA74, (ts4_word)(ts4_word)lbl_88040040, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8C4F0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42BD8: call_seq lbl_88B8C580, lbl_88CDAA44, lbl_8803ECD0, lbl_88CDAAA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8C580_88A42BD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAAA4, (ts4_word)(ts4_word)lbl_8803ECD0, (ts4_word)(ts4_word)lbl_88CDAA44, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8C580, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42C50: call_seq lbl_88B8C6A0, lbl_88CDAA44, lbl_8803ECB0, lbl_88CDAAD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8C6A0_88A42C50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAAD4, (ts4_word)(ts4_word)lbl_8803ECB0, (ts4_word)(ts4_word)lbl_88CDAA44, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8C6A0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42CC8: call_seq lbl_88B8C6B8, lbl_88040078, lbl_88CDAB04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8C6B8_88A42CC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAB04, (ts4_word)(ts4_word)lbl_88040078, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8C6B8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42D38: call_seq lbl_88B8C748, lbl_88CDAA44, lbl_8803EC94, lbl_88CDAB34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8C748_88A42D38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAB34, (ts4_word)(ts4_word)lbl_8803EC94, (ts4_word)(ts4_word)lbl_88CDAA44, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8C748, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42DB0: call_seq lbl_88B8C838, lbl_88046C60, lbl_88CDAB64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8C838_88A42DB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAB64, (ts4_word)(ts4_word)lbl_88046C60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8C838, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42E20: call_seq lbl_88B8C850, lbl_8803EE88, lbl_88CDAB94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8C850_88A42E20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAB94, (ts4_word)(ts4_word)lbl_8803EE88, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8C850, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42E90: call_seq lbl_88B8C8B4, lbl_88CDB644, lbl_8804002C, lbl_88CDABC4, lbl_8805BF94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8C8B4_88A42E90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDABC4, (ts4_word)(ts4_word)lbl_8804002C, (ts4_word)(ts4_word)lbl_88CDB644, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805BF94, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B8C8B4, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42F00: call_seq lbl_88B8C8D0, lbl_88046C00, lbl_88CDABF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8C8D0_88A42F00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDABF4, (ts4_word)(ts4_word)lbl_88046C00, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8C8D0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42F70: call_seq lbl_88B8C918, lbl_88046C24, lbl_88CDAC24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8C918_88A42F70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAC24, (ts4_word)(ts4_word)lbl_88046C24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8C918, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A42FE0: call_seq lbl_88B8C9A8, lbl_88046C48, lbl_88CDAC54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8C9A8_88A42FE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAC54, (ts4_word)(ts4_word)lbl_88046C48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8C9A8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43050: call_seq lbl_88CDB644, lbl_8803EC3C, lbl_88CDAC84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CDB644_88A43050(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAC84, (ts4_word)(ts4_word)lbl_8803EC3C, (ts4_word)(ts4_word)lbl_88CDB644, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A430B8: call_seq lbl_88B8CA38, lbl_88CDAC84, lbl_8803ECF4, lbl_88CDACB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8CA38_88A430B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDACB4, (ts4_word)(ts4_word)lbl_8803ECF4, (ts4_word)(ts4_word)lbl_88CDAC84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8CA38, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43130: call_seq lbl_88B8CA98, lbl_8803EEFC, lbl_88CDACE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8CA98_88A43130(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDACE4, (ts4_word)(ts4_word)lbl_8803EEFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8CA98, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A431A0: call_seq lbl_88B8CAC8, lbl_8803EEE8, lbl_88CDAD14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8CAC8_88A431A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAD14, (ts4_word)(ts4_word)lbl_8803EEE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8CAC8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43210: call_seq lbl_88B8CB28, lbl_8803EE7C, lbl_88CDAD44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8CB28_88A43210(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAD44, (ts4_word)(ts4_word)lbl_8803EE7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8CB28, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43280: call_seq lbl_88B8CB88, lbl_88041578, lbl_88CDAD74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8CB88_88A43280(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAD74, (ts4_word)(ts4_word)lbl_88041578, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8CB88, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A432F0: call_seq lbl_88B8CC00, lbl_88042110, lbl_88CDADA4, lbl_8805BFC8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8CC00_88A432F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDADA4, (ts4_word)(ts4_word)lbl_88042110, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805BFC8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B8CC00, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43360: call_seq lbl_88B8CD08, lbl_8805BFDC, lbl_880420FC, lbl_88CDADD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8CD08_88A43360(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDADD4, (ts4_word)(ts4_word)lbl_880420FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8CD08, (ts4_word)11, (ts4_word)(ts4_word)lbl_8805BFDC, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A433D8: call_seq lbl_88B8CE14, lbl_88041204, lbl_88CDAE04, lbl_8805C020, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8CE14_88A433D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAE04, (ts4_word)(ts4_word)lbl_88041204, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805C020, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B8CE14, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43448: call_seq lbl_88CDB3D4, lbl_88053DD8, lbl_88CDAE34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CDB3D4_88A43448(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAE34, (ts4_word)(ts4_word)lbl_88053DD8, (ts4_word)(ts4_word)lbl_88CDB3D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A434B0: call_seq lbl_8805C034, lbl_88B8CE48, lbl_88CDAE34, lbl_88041268, lbl_88CDAE64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805C034_88A434B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAE64, (ts4_word)(ts4_word)lbl_88041268, (ts4_word)(ts4_word)lbl_88CDAE34, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8CE48, (ts4_word)7, (ts4_word)(ts4_word)lbl_8805C034, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43528: call_seq lbl_88CDAE64, lbl_88053DE8, lbl_88CDAE94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CDAE64_88A43528(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAE94, (ts4_word)(ts4_word)lbl_88053DE8, (ts4_word)(ts4_word)lbl_88CDAE64, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43590: call_seq lbl_88B8CEF0, lbl_88CDB644, lbl_8804124C, lbl_88CDAEC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8CEF0_88A43590(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAEC4, (ts4_word)(ts4_word)lbl_8804124C, (ts4_word)(ts4_word)lbl_88CDB644, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8CEF0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43608: call_seq lbl_8805C060, lbl_88B8CF38, lbl_88CDAE34, lbl_88041238, lbl_88CDAEF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805C060_88A43608(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAEF4, (ts4_word)(ts4_word)lbl_88041238, (ts4_word)(ts4_word)lbl_88CDAE34, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8CF38, (ts4_word)8, (ts4_word)(ts4_word)lbl_8805C060, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43680: call_seq lbl_88B8CFF8, lbl_8804115C, lbl_88CDAF24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8CFF8_88A43680(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAF24, (ts4_word)(ts4_word)lbl_8804115C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8CFF8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A436F0: addr lbl_88B92AE8, u32@lbl_88B8CE44, u32@0x8 */
void ts4_addr_lbl_88B92AE8_88A436F0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B92AE8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B8CE44);
    return;
}

/* Swing_DLL.xex 0x88A43780: call_seq lbl_88B8D040, lbl_88CDAE34, lbl_88041584, lbl_88CDAF84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8D040_88A43780(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAF84, (ts4_word)(ts4_word)lbl_88041584, (ts4_word)(ts4_word)lbl_88CDAE34, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D040, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A437F8: call_seq lbl_88B8D070, lbl_88CDAE34, lbl_88053E90, lbl_88CDAFB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8D070_88A437F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAFB4, (ts4_word)(ts4_word)lbl_88053E90, (ts4_word)(ts4_word)lbl_88CDAE34, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D070, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43870: call_seq lbl_88CDB3D4, lbl_88053EAC, lbl_88CDAFE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CDB3D4_88A43870(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDAFE4, (ts4_word)(ts4_word)lbl_88053EAC, (ts4_word)(ts4_word)lbl_88CDB3D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A438D8: call_seq lbl_88B8D088, lbl_88CDAFE4, lbl_88042128, lbl_88CDB014, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8D088_88A438D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB014, (ts4_word)(ts4_word)lbl_88042128, (ts4_word)(ts4_word)lbl_88CDAFE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D088, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43950: call_seq lbl_88B8D0B8, lbl_880420B8, lbl_88CDB044, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8D0B8_88A43950(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB044, (ts4_word)(ts4_word)lbl_880420B8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D0B8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A439C0: call_seq lbl_88B8D118, lbl_880420E4, lbl_88CDB074, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8D118_88A439C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB074, (ts4_word)(ts4_word)lbl_880420E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D118, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43A30: call_seq lbl_8805C100, lbl_88B8D148, lbl_88CDAFE4, lbl_88041634, lbl_88CDB0A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805C100_88A43A30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB0A4, (ts4_word)(ts4_word)lbl_88041634, (ts4_word)(ts4_word)lbl_88CDAFE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D148, (ts4_word)16, (ts4_word)(ts4_word)lbl_8805C100, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43AA8: call_seq lbl_88B8D2C8, lbl_88CDAFE4, lbl_880420C8, lbl_88CDB0D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8D2C8_88A43AA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB0D4, (ts4_word)(ts4_word)lbl_880420C8, (ts4_word)(ts4_word)lbl_88CDAFE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D2C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}
