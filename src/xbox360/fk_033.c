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

extern char ts4_addr_lbl_8803A308_88AFF518[];
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
extern char lbl_8803ED14[];
extern char lbl_8803ED20[];
extern char lbl_8803ED28[];
extern char lbl_8803ED40[];
extern char lbl_8803ED58[];
extern char lbl_8803ED7C[];
extern char lbl_8803EE48[];
extern char lbl_8803EE7C[];
extern char lbl_8803EE88[];
extern char lbl_8803EEE8[];
extern char lbl_8803EEFC[];
extern char lbl_8803EF04[];
extern char lbl_8803EF9C[];
extern char lbl_8803EFC0[];
extern char lbl_8803EFD0[];
extern char lbl_8803EFE8[];
extern char lbl_8803F00C[];
extern char lbl_8803F030[];
extern char lbl_8803F094[];
extern char lbl_8803F0AC[];
extern char lbl_8803F5BC[];
extern char lbl_8803F5C8[];
extern char lbl_8803F5E0[];
extern char lbl_8803F5F4[];
extern char lbl_8803F64C[];
extern char lbl_8803F670[];
extern char lbl_8803F960[];
extern char lbl_8803F974[];
extern char lbl_8803F988[];
extern char lbl_8803F99C[];
extern char lbl_8803F9B0[];
extern char lbl_8803F9D4[];
extern char lbl_8803FBF4[];
extern char lbl_8804002C[];
extern char lbl_88040040[];
extern char lbl_88040078[];
extern char lbl_880400A8[];
extern char lbl_880400BC[];
extern char lbl_880400D0[];
extern char lbl_880400E8[];
extern char lbl_88040100[];
extern char lbl_88040110[];
extern char lbl_8804011C[];
extern char lbl_88040278[];
extern char lbl_880404B8[];
extern char lbl_880404E0[];
extern char lbl_88040658[];
extern char lbl_88040668[];
extern char lbl_88041284[];
extern char lbl_88041B24[];
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
extern char lbl_88044268[];
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
extern char lbl_88046C00[];
extern char lbl_88046C24[];
extern char lbl_88046C48[];
extern char lbl_88046C60[];
extern char lbl_88046C78[];
extern char lbl_88046C94[];
extern char lbl_88047050[];
extern char lbl_8804705C[];
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
extern char lbl_8804D7E8[];
extern char lbl_8804E0B0[];
extern char lbl_8804E0E0[];
extern char lbl_8804E4DC[];
extern char lbl_8804E4F4[];
extern char lbl_8804E50C[];
extern char lbl_8804E524[];
extern char lbl_8804E53C[];
extern char lbl_8804E560[];
extern char lbl_8804E57C[];
extern char lbl_8804EA1C[];
extern char lbl_8804EA38[];
extern char lbl_8804EBA8[];
extern char lbl_8804EBFC[];
extern char lbl_8804EC20[];
extern char lbl_8804EC64[];
extern char lbl_8804EC90[];
extern char lbl_8804ECD4[];
extern char lbl_8804ED10[];
extern char lbl_8804ED4C[];
extern char lbl_8804ED60[];
extern char lbl_8804EDE8[];
extern char lbl_8804EE3C[];
extern char lbl_88B49D88[];
extern char lbl_88B49DA0[];
extern char lbl_88B49DB8[];
extern char lbl_88B49E00[];
extern char lbl_88B49E18[];
extern char lbl_88B49E48[];
extern char lbl_88B49EC0[];
extern char lbl_88B49F08[];
extern char lbl_88B49F50[];
extern char lbl_88B4A040[];
extern char lbl_88B4A088[];
extern char lbl_88B4A0E8[];
extern char lbl_88B4A148[];
extern char lbl_88B4A1A8[];
extern char lbl_88B4A268[];
extern char lbl_88B4A400[];
extern char lbl_88B4A418[];
extern char lbl_88B4A430[];
extern char lbl_88B4A460[];
extern char lbl_88B4A490[];
extern char lbl_88B4A4A8[];
extern char lbl_88B4A538[];
extern char lbl_88B4A580[];
extern char lbl_88B4A5B0[];
extern char lbl_88B4A5E0[];
extern char lbl_88B4A610[];
extern char lbl_88B4A628[];
extern char lbl_88B4A640[];
extern char lbl_88B4A670[];
extern char lbl_88B4A688[];
extern char lbl_88B4A760[];
extern char lbl_88B4A910[];
extern char lbl_88B4AAA8[];
extern char lbl_88B4AD18[];
extern char lbl_88B4AD90[];
extern char lbl_88B4ADD8[];
extern char lbl_88B4AE08[];
extern char lbl_88B4AE68[];
extern char lbl_88B4AEC8[];
extern char lbl_88B4AFB8[];
extern char lbl_88B4B000[];
extern char lbl_88B4B048[];
extern char lbl_88B4B060[];
extern char lbl_88B4B0A8[];
extern char lbl_88B4B0C0[];
extern char lbl_88B4B168[];
extern char lbl_88B4B198[];
extern char lbl_88B4B1E0[];
extern char lbl_88B4B228[];
extern char lbl_88B4B270[];
extern char lbl_88B4B288[];
extern char lbl_88B4B2A0[];
extern char lbl_88B4BB70[];
extern char lbl_88B4BBE8[];
extern char lbl_88B4BBEC[];
extern char lbl_88B4BC1C[];
extern char lbl_88B4BC50[];
extern char lbl_88B4BCB0[];
extern char lbl_88B4BD10[];
extern char lbl_88B4BDA0[];
extern char lbl_88B4BDB8[];
extern char lbl_88B4BE18[];
extern char lbl_88B4BEC0[];
extern char lbl_88B4BED8[];
extern char lbl_88B4BF38[];
extern char lbl_88B4BF50[];
extern char lbl_88B4BF98[];
extern char lbl_88B4C028[];
extern char lbl_88B4C0B8[];
extern char lbl_88B4C118[];
extern char lbl_88B4C148[];
extern char lbl_88B4C190[];
extern char lbl_88B4C1F0[];
extern char lbl_88B4C220[];
extern char lbl_88B4C2C8[];
extern char lbl_88B4C2F8[];
extern char lbl_88B4C328[];
extern char lbl_88B4C334[];
extern char lbl_88B4C364[];
extern char lbl_88B4C37C[];
extern char lbl_88B4C380[];
extern char lbl_88B4C3B0[];
extern char lbl_88B4C3E4[];
extern char lbl_88B4C3E8[];
extern char lbl_88B4C448[];
extern char lbl_88B4C508[];
extern char lbl_88B4C520[];
extern char lbl_88B4C598[];
extern char lbl_88B4C5B0[];
extern char lbl_88B4C5E0[];
extern char lbl_88B4C610[];
extern char lbl_88B4C640[];
extern char lbl_88B4C658[];
extern char lbl_88B4C688[];
extern char lbl_88B4C6A0[];
extern char lbl_88B4C6D0[];
extern char lbl_88B4C778[];
extern char lbl_88B4C7A8[];
extern char lbl_88B4C868[];
extern char lbl_88B4C870[];
extern char lbl_88B4C8A0[];
extern char lbl_88B4C960[];
extern char lbl_88B4C964[];
extern char lbl_88B4C97C[];
extern char lbl_88B4C9AC[];
extern char lbl_88B4C9B0[];
extern char lbl_88B4C9C8[];
extern char lbl_88B4CA10[];
extern char lbl_88B4CA40[];
extern char lbl_88B4CB60[];
extern char lbl_88B4CBF0[];
extern char lbl_88B4CCB0[];
extern char lbl_88B4CD88[];
extern char lbl_88B4CE48[];
extern char lbl_88B4CEF0[];
extern char lbl_88B4D010[];
extern char lbl_88B4D070[];
extern char lbl_88B4D178[];
extern char lbl_88B4D250[];
extern char lbl_88B4D280[];
extern char lbl_88B4D298[];
extern char lbl_88B4D2E0[];
extern char lbl_88B4D2F8[];
extern char lbl_88B4D340[];
extern char lbl_88B4D3A0[];
extern char lbl_88B4D3E8[];
extern char lbl_88B4D448[];
extern char lbl_88B4D478[];
extern char lbl_88B4D490[];
extern char lbl_88B4D4A8[];
extern char lbl_88B4D508[];
extern char lbl_88B4D520[];
extern char lbl_88B4D550[];
extern char lbl_88B4D568[];
extern char lbl_88B4D598[];
extern char lbl_88B4D5B0[];
extern char lbl_88B4D5C8[];
extern char lbl_88B4D5E0[];
extern char lbl_88B4D628[];
extern char lbl_88B4D658[];
extern char lbl_88B4D688[];
extern char lbl_88B4D6D0[];
extern char lbl_88B4D74C[];
extern char lbl_88B4D750[];
extern char lbl_88B4D7C8[];
extern char lbl_88B4D7F8[];
extern char lbl_88B4D810[];
extern char lbl_88B4D830[];
extern char lbl_88B4D890[];
extern char lbl_88B4D8A8[];
extern char lbl_88B4D8D8[];
extern char lbl_88B4D908[];
extern char lbl_88B4D938[];
extern char lbl_88B4D980[];
extern char lbl_88B4DA28[];
extern char lbl_88B4DA70[];
extern char lbl_88B4DAD0[];
extern char lbl_88B4DB60[];
extern char lbl_88B4DB78[];
extern char lbl_88B4DBA8[];
extern char lbl_88B4DBF0[];
extern char lbl_88B4DC38[];
extern char lbl_88B4DC80[];
extern char lbl_88B4DC98[];
extern char lbl_88B4DCC8[];
extern char lbl_88B4DD28[];
extern char lbl_88B50A60[];
extern char lbl_88B50AA8[];
extern char lbl_88B50B68[];
extern char lbl_88B50BF8[];
extern char lbl_88B50C28[];
extern char lbl_88B50C58[];
extern char lbl_88B50C88[];
extern char lbl_88B50D00[];
extern char lbl_88B50D48[];
extern char lbl_88B50DC0[];
extern char lbl_88CB303C[];
extern char lbl_88CB3A5C[];
extern char lbl_88CB3B1C[];
extern char lbl_88CB450C[];
extern char lbl_88CB453C[];
extern char lbl_88CB45FC[];
extern char lbl_88CB507C[];
extern char lbl_88CB50AC[];
extern char lbl_88CB50DC[];
extern char lbl_88CB510C[];
extern char lbl_88CB513C[];
extern char lbl_88CB516C[];
extern char lbl_88CB519C[];
extern char lbl_88CB51CC[];
extern char lbl_88CB51FC[];
extern char lbl_88CB522C[];
extern char lbl_88CB525C[];
extern char lbl_88CB528C[];
extern char lbl_88CB52BC[];
extern char lbl_88CB52EC[];
extern char lbl_88CB531C[];
extern char lbl_88CB534C[];
extern char lbl_88CB537C[];
extern char lbl_88CB53AC[];
extern char lbl_88CB53DC[];
extern char lbl_88CB540C[];
extern char lbl_88CB543C[];
extern char lbl_88CB546C[];
extern char lbl_88CB549C[];
extern char lbl_88CB54CC[];
extern char lbl_88CB54FC[];
extern char lbl_88CB552C[];
extern char lbl_88CB555C[];
extern char lbl_88CB558C[];
extern char lbl_88CB55BC[];
extern char lbl_88CB55EC[];
extern char lbl_88CB561C[];
extern char lbl_88CB564C[];
extern char lbl_88CB567C[];
extern char lbl_88CB56AC[];
extern char lbl_88CB56DC[];
extern char lbl_88CB570C[];
extern char lbl_88CB573C[];
extern char lbl_88CB576C[];
extern char lbl_88CB579C[];
extern char lbl_88CB57CC[];
extern char lbl_88CB57FC[];
extern char lbl_88CB582C[];
extern char lbl_88CB585C[];
extern char lbl_88CB588C[];
extern char lbl_88CB58BC[];
extern char lbl_88CB58EC[];
extern char lbl_88CB591C[];
extern char lbl_88CB594C[];
extern char lbl_88CB597C[];
extern char lbl_88CB59AC[];
extern char lbl_88CB59DC[];
extern char lbl_88CB5A0C[];
extern char lbl_88CB5A3C[];
extern char lbl_88CB5A6C[];
extern char lbl_88CB5A9C[];
extern char lbl_88CB5ACC[];
extern char lbl_88CB5AFC[];
extern char lbl_88CB5B2C[];
extern char lbl_88CB5B5C[];
extern char lbl_88CB5B8C[];
extern char lbl_88CB5BBC[];
extern char lbl_88CB5BD4[];
extern char lbl_88CB5C04[];
extern char lbl_88CB5C34[];
extern char lbl_88CB5C64[];
extern char lbl_88CB5C94[];
extern char lbl_88CB5CC4[];
extern char lbl_88CB5CF4[];
extern char lbl_88CB5D24[];
extern char lbl_88CB5D54[];
extern char lbl_88CB5D84[];
extern char lbl_88CB5DB4[];
extern char lbl_88CB5DE4[];
extern char lbl_88CB5E14[];
extern char lbl_88CB5E44[];
extern char lbl_88CB5E74[];
extern char lbl_88CB5EA4[];
extern char lbl_88CB5ED4[];
extern char lbl_88CB5F04[];
extern char lbl_88CB5F34[];
extern char lbl_88CB5F64[];
extern char lbl_88CB5F94[];
extern char lbl_88CB5FC4[];
extern char lbl_88CB5FF4[];
extern char lbl_88CB6024[];
extern char lbl_88CB6054[];
extern char lbl_88CB6084[];
extern char lbl_88CB60B4[];
extern char lbl_88CB60E4[];
extern char lbl_88CB6114[];
extern char lbl_88CB6144[];
extern char lbl_88CB6174[];
extern char lbl_88CB61A4[];
extern char lbl_88CB61D4[];
extern char lbl_88CB6204[];
extern char lbl_88CB6234[];
extern char lbl_88CB6264[];
extern char lbl_88CB6294[];
extern char lbl_88CB62C4[];
extern char lbl_88CB62F4[];
extern char lbl_88CB6324[];
extern char lbl_88CB6354[];
extern char lbl_88CB6384[];
extern char lbl_88CB63B4[];
extern char lbl_88CB63E4[];
extern char lbl_88CB6414[];
extern char lbl_88CB6444[];
extern char lbl_88CB6474[];
extern char lbl_88CB64A4[];
extern char lbl_88CB64D4[];
extern char lbl_88CB6504[];
extern char lbl_88CB6534[];
extern char lbl_88CB6564[];
extern char lbl_88CB6594[];
extern char lbl_88CB65C4[];
extern char lbl_88CB65F4[];
extern char lbl_88CB6624[];
extern char lbl_88CB6654[];
extern char lbl_88CB6684[];
extern char lbl_88CB66B4[];
extern char lbl_88CB66E4[];
extern char lbl_88CB6714[];
extern char lbl_88CB6744[];
extern char lbl_88CB6774[];
extern char lbl_88CB67A4[];
extern char lbl_88CB67D4[];
extern char lbl_88CB6804[];
extern char lbl_88CB6834[];
extern char lbl_88CB6864[];
extern char lbl_88CB6894[];
extern char lbl_88CB68C4[];
extern char lbl_88CB68F4[];
extern char lbl_88CB6924[];
extern char lbl_88CB6954[];
extern char lbl_88CB6984[];
extern char lbl_88CB69B4[];
extern char lbl_88CB69E4[];
extern char lbl_88CB6A14[];
extern char lbl_88CB6A44[];
extern char lbl_88CB6A74[];
extern char lbl_88CB6AA4[];
extern char lbl_88CB6AD4[];
extern char lbl_88CB6B04[];
extern char lbl_88CB6B34[];
extern char lbl_88CB6B64[];
extern char lbl_88CB6B94[];
extern char lbl_88CB6BC4[];
extern char lbl_88CB6BF4[];
extern char lbl_88CB6C24[];
extern char lbl_88CB6C54[];
extern char lbl_88CB6C84[];
extern char lbl_88CB6CB4[];
extern char lbl_88CB6CE4[];
extern char lbl_88CB6D14[];
extern char lbl_88CB6D44[];
extern char lbl_88CB6D74[];
extern char lbl_88CB6DA4[];
extern char lbl_88CB6DD4[];
extern char lbl_88CB6E04[];
extern char lbl_88CB6E34[];
extern char lbl_88CB6E64[];
extern char lbl_88CB6E94[];
extern char lbl_88CB6EC4[];
extern char lbl_88CB6EF4[];
extern char lbl_88CB6F24[];
extern char lbl_88CB6F54[];
extern char lbl_88CB6F84[];
extern char lbl_88CB6FB4[];
extern char lbl_88CB6FE4[];
extern char lbl_88CB7014[];
extern char lbl_88CB7044[];
extern char lbl_88CB7074[];
extern char lbl_88CB70A4[];
extern char lbl_88CB70D4[];
extern char lbl_88CB7104[];
extern char lbl_88CB7134[];
extern char lbl_88CB7164[];
extern char lbl_88CB7194[];
extern char lbl_88CB71C4[];
extern char lbl_88CB71F4[];
extern char lbl_88CB7224[];
extern char lbl_88CB7254[];
extern char lbl_88CB7284[];
extern char lbl_88CB72B4[];
extern char lbl_88CB72E4[];
extern char lbl_88CB7314[];
extern char lbl_88CB7344[];
extern char lbl_88CB7374[];
extern char lbl_88CB73A4[];
extern char lbl_88CB73D4[];
extern char lbl_88CB82A4[];
ts4_word fn_8841F080();
ts4_word ts4_set_u32_offc_884CE988();
ts4_word fn_88563470();

/* Swing_DLL.xex 0x889E78A0: call_seq lbl_88B49D88, lbl_88CB3A5C, lbl_88044F38, lbl_88CB507C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49D88_889E78A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB507C, (ts4_word)(ts4_word)lbl_88044F38, (ts4_word)(ts4_word)lbl_88CB3A5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49D88, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7918: call_seq lbl_88B49DA0, lbl_88042E20, lbl_88CB50AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49DA0_889E7918(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB50AC, (ts4_word)(ts4_word)lbl_88042E20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49DA0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7988: call_seq lbl_88B49DB8, lbl_88CB303C, lbl_8803EFD0, lbl_88CB50DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49DB8_889E7988(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB50DC, (ts4_word)(ts4_word)lbl_8803EFD0, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49DB8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7A00: call_seq lbl_88B49E00, lbl_88044F10, lbl_88CB510C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49E00_889E7A00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB510C, (ts4_word)(ts4_word)lbl_88044F10, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49E00, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7A70: call_seq lbl_88B49E18, lbl_88CB303C, lbl_88044F90, lbl_88CB513C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49E18_889E7A70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB513C, (ts4_word)(ts4_word)lbl_88044F90, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49E18, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7AE8: call_seq lbl_88B49E48, lbl_88CB51FC, lbl_8803F670, lbl_88CB516C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49E48_889E7AE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB516C, (ts4_word)(ts4_word)lbl_8803F670, (ts4_word)(ts4_word)lbl_88CB51FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49E48, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7B60: call_seq lbl_88B49EC0, lbl_880404E0, lbl_88CB519C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49EC0_889E7B60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB519C, (ts4_word)(ts4_word)lbl_880404E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49EC0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7BD0: call_seq lbl_88B49F08, lbl_880404B8, lbl_88CB51CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B49F08_889E7BD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB51CC, (ts4_word)(ts4_word)lbl_880404B8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49F08, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7C40: call_seq lbl_8804E0B0, lbl_88B49F50, lbl_88CB45FC, lbl_8803F030, lbl_88CB51FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8804E0B0_889E7C40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB51FC, (ts4_word)(ts4_word)lbl_8803F030, (ts4_word)(ts4_word)lbl_88CB45FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B49F50, (ts4_word)10, (ts4_word)(ts4_word)lbl_8804E0B0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7CB8: call_seq lbl_88B4A040, lbl_88CB450C, lbl_88044EA8, lbl_88CB522C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A040_889E7CB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB522C, (ts4_word)(ts4_word)lbl_88044EA8, (ts4_word)(ts4_word)lbl_88CB450C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A040, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7D30: call_seq lbl_88B4A088, lbl_88CB450C, lbl_88044E64, lbl_88CB525C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A088_889E7D30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB525C, (ts4_word)(ts4_word)lbl_88044E64, (ts4_word)(ts4_word)lbl_88CB450C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A088, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7DA8: call_seq lbl_88B4A0E8, lbl_88CB453C, lbl_88044DD0, lbl_88CB528C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A0E8_889E7DA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB528C, (ts4_word)(ts4_word)lbl_88044DD0, (ts4_word)(ts4_word)lbl_88CB453C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A0E8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7E20: call_seq lbl_88B4A148, lbl_88CB453C, lbl_88044CD0, lbl_88CB52BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A148_889E7E20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB52BC, (ts4_word)(ts4_word)lbl_88044CD0, (ts4_word)(ts4_word)lbl_88CB453C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A148, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7E98: call_seq lbl_88B4A1A8, lbl_88CB450C, lbl_88044BD4, lbl_88CB52EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A1A8_889E7E98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB52EC, (ts4_word)(ts4_word)lbl_88044BD4, (ts4_word)(ts4_word)lbl_88CB450C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A1A8, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7F10: call_seq lbl_88B4A268, lbl_8803F094, lbl_88CB531C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A268_889E7F10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB531C, (ts4_word)(ts4_word)lbl_8803F094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A268, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7F80: call_seq lbl_88B4A400, lbl_88CB3B1C, lbl_8803F0AC, lbl_88CB534C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A400_889E7F80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB534C, (ts4_word)(ts4_word)lbl_8803F0AC, (ts4_word)(ts4_word)lbl_88CB3B1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A400, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E7FF8: call_seq lbl_88B4A418, lbl_88CB3B1C, lbl_88044E30, lbl_88CB537C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A418_889E7FF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB537C, (ts4_word)(ts4_word)lbl_88044E30, (ts4_word)(ts4_word)lbl_88CB3B1C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A418, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8070: call_seq lbl_88B4A430, lbl_88CB3B1C, lbl_88044DF8, lbl_88CB53AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A430_889E8070(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB53AC, (ts4_word)(ts4_word)lbl_88044DF8, (ts4_word)(ts4_word)lbl_88CB3B1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A430, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E80E8: call_seq lbl_88B4A460, lbl_88044B54, lbl_88CB53DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A460_889E80E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB53DC, (ts4_word)(ts4_word)lbl_88044B54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A460, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8158: call_seq lbl_88B4A490, lbl_88CB3B1C, lbl_88044D8C, lbl_88CB540C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A490_889E8158(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB540C, (ts4_word)(ts4_word)lbl_88044D8C, (ts4_word)(ts4_word)lbl_88CB3B1C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A490, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E81D0: call_seq lbl_88B4A4A8, lbl_88CB453C, lbl_8804705C, lbl_88CB543C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A4A8_889E81D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB543C, (ts4_word)(ts4_word)lbl_8804705C, (ts4_word)(ts4_word)lbl_88CB453C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A4A8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8248: call_seq lbl_88B4A538, lbl_88044A58, lbl_88CB546C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A538_889E8248(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB546C, (ts4_word)(ts4_word)lbl_88044A58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A538, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E82B8: call_seq lbl_88B4A580, lbl_88044B0C, lbl_88CB549C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A580_889E82B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB549C, (ts4_word)(ts4_word)lbl_88044B0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A580, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8328: call_seq lbl_88B4A5B0, lbl_88044B94, lbl_88CB54CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A5B0_889E8328(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB54CC, (ts4_word)(ts4_word)lbl_88044B94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A5B0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8398: call_seq lbl_88B4A5E0, lbl_88CB303C, lbl_88044D60, lbl_88CB54FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A5E0_889E8398(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB54FC, (ts4_word)(ts4_word)lbl_88044D60, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A5E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8410: call_seq lbl_88B4A610, lbl_88CB303C, lbl_88044C84, lbl_88CB552C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A610_889E8410(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB552C, (ts4_word)(ts4_word)lbl_88044C84, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A610, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8488: call_seq lbl_88B4A628, lbl_88CB303C, lbl_88044C48, lbl_88CB555C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A628_889E8488(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB555C, (ts4_word)(ts4_word)lbl_88044C48, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A628, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8500: call_seq lbl_88B4A640, lbl_88044A08, lbl_88CB558C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A640_889E8500(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB558C, (ts4_word)(ts4_word)lbl_88044A08, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A640, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8570: call_seq lbl_88B4A670, lbl_88CB303C, lbl_88044C08, lbl_88CB55BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A670_889E8570(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB55BC, (ts4_word)(ts4_word)lbl_88044C08, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A670, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E85E8: call_seq lbl_88B4A688, lbl_88040668, lbl_88CB55EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A688_889E85E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB55EC, (ts4_word)(ts4_word)lbl_88040668, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A688, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8658: call_seq lbl_88B4A760, lbl_88CB303C, lbl_88040658, lbl_88CB561C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A760_889E8658(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB561C, (ts4_word)(ts4_word)lbl_88040658, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A760, (ts4_word)18, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E86D0: call_seq lbl_88B4A910, lbl_8803F5F4, lbl_88CB564C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4A910_889E86D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB564C, (ts4_word)(ts4_word)lbl_8803F5F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4A910, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8740: call_seq lbl_88B4AAA8, lbl_88CB453C, lbl_8803F64C, lbl_88CB567C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4AAA8_889E8740(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB567C, (ts4_word)(ts4_word)lbl_8803F64C, (ts4_word)(ts4_word)lbl_88CB453C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4AAA8, (ts4_word)26, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E87B8: call_seq lbl_88CB303C, lbl_8804494C, lbl_88CB56AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB303C_889E87B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB56AC, (ts4_word)(ts4_word)lbl_8804494C, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8820: call_seq lbl_88B4AD18, lbl_88CB56AC, lbl_88044700, lbl_88CB56DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4AD18_889E8820(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB56DC, (ts4_word)(ts4_word)lbl_88044700, (ts4_word)(ts4_word)lbl_88CB56AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4AD18, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8898: call_seq lbl_88CB303C, lbl_88044924, lbl_88CB570C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB303C_889E8898(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB570C, (ts4_word)(ts4_word)lbl_88044924, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8900: call_seq lbl_88B4AD90, lbl_88044438, lbl_88CB573C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4AD90_889E8900(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB573C, (ts4_word)(ts4_word)lbl_88044438, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4AD90, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8970: call_seq lbl_88B4ADD8, lbl_88CB570C, lbl_88044680, lbl_88CB576C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4ADD8_889E8970(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB576C, (ts4_word)(ts4_word)lbl_88044680, (ts4_word)(ts4_word)lbl_88CB570C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4ADD8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E89E8: call_seq lbl_88CB303C, lbl_880448C8, lbl_88CB579C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB303C_889E89E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB579C, (ts4_word)(ts4_word)lbl_880448C8, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8A50: call_seq lbl_88CB303C, lbl_880448FC, lbl_88CB57CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB303C_889E8A50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB57CC, (ts4_word)(ts4_word)lbl_880448FC, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8AB8: call_seq lbl_88B4AE08, lbl_88CB579C, lbl_88044524, lbl_88CB57FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4AE08_889E8AB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB57FC, (ts4_word)(ts4_word)lbl_88044524, (ts4_word)(ts4_word)lbl_88CB579C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4AE08, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8B30: call_seq lbl_88B4AE68, lbl_88CB57CC, lbl_880446BC, lbl_88CB582C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4AE68_889E8B30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB582C, (ts4_word)(ts4_word)lbl_880446BC, (ts4_word)(ts4_word)lbl_88CB57CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4AE68, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8BA8: call_seq lbl_88CB303C, lbl_8804489C, lbl_88CB585C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB303C_889E8BA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB585C, (ts4_word)(ts4_word)lbl_8804489C, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8C10: call_seq lbl_88B4AEC8, lbl_88CB585C, lbl_88044650, lbl_88CB588C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4AEC8_889E8C10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB588C, (ts4_word)(ts4_word)lbl_88044650, (ts4_word)(ts4_word)lbl_88CB585C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4AEC8, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8C88: call_seq lbl_88CB303C, lbl_88044874, lbl_88CB58BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB303C_889E8C88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB58BC, (ts4_word)(ts4_word)lbl_88044874, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8CF0: call_seq lbl_88B4AFB8, lbl_88CB58BC, lbl_8804461C, lbl_88CB58EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4AFB8_889E8CF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB58EC, (ts4_word)(ts4_word)lbl_8804461C, (ts4_word)(ts4_word)lbl_88CB58BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4AFB8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8D68: call_seq lbl_88B4B000, lbl_88044268, lbl_88CB591C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B000_889E8D68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB591C, (ts4_word)(ts4_word)lbl_88044268, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4B000, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8DD8: call_seq lbl_88B4B048, lbl_88CB303C, lbl_8804484C, lbl_88CB594C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B048_889E8DD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB594C, (ts4_word)(ts4_word)lbl_8804484C, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4B048, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8E50: call_seq lbl_88B4B060, lbl_880443CC, lbl_88CB597C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B060_889E8E50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB597C, (ts4_word)(ts4_word)lbl_880443CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4B060, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8EC0: call_seq lbl_88B4B0A8, lbl_88CB594C, lbl_880445E4, lbl_88CB59AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B0A8_889E8EC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB59AC, (ts4_word)(ts4_word)lbl_880445E4, (ts4_word)(ts4_word)lbl_88CB594C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4B0A8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8F38: call_seq lbl_88CB303C, lbl_8804481C, lbl_88CB59DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB303C_889E8F38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB59DC, (ts4_word)(ts4_word)lbl_8804481C, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E8FA0: call_seq lbl_88B4B0C0, lbl_88CB59DC, lbl_880445A8, lbl_88CB5A0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B0C0_889E8FA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5A0C, (ts4_word)(ts4_word)lbl_880445A8, (ts4_word)(ts4_word)lbl_88CB59DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4B0C0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9018: call_seq lbl_88B4B168, lbl_8804449C, lbl_88CB5A3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B168_889E9018(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5A3C, (ts4_word)(ts4_word)lbl_8804449C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4B168, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9088: call_seq lbl_88B4B198, lbl_88CB303C, lbl_88044744, lbl_88CB5A6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B198_889E9088(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5A6C, (ts4_word)(ts4_word)lbl_88044744, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4B198, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9100: call_seq lbl_88B4B1E0, lbl_88CB303C, lbl_88044758, lbl_88CB5A9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B1E0_889E9100(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5A9C, (ts4_word)(ts4_word)lbl_88044758, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4B1E0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9178: call_seq lbl_88CB303C, lbl_880447EC, lbl_88CB5ACC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB303C_889E9178(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5ACC, (ts4_word)(ts4_word)lbl_880447EC, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E91E0: call_seq lbl_88B4B228, lbl_88CB5ACC, lbl_88044568, lbl_88CB5AFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B228_889E91E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5AFC, (ts4_word)(ts4_word)lbl_88044568, (ts4_word)(ts4_word)lbl_88CB5ACC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4B228, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9258: call_seq lbl_88B4B270, lbl_88CB303C, lbl_880447B8, lbl_88CB5B2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B270_889E9258(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5B2C, (ts4_word)(ts4_word)lbl_880447B8, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4B270, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E92D0: call_seq lbl_88B4B288, lbl_88CB303C, lbl_88044784, lbl_88CB5B5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B288_889E92D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5B5C, (ts4_word)(ts4_word)lbl_88044784, (ts4_word)(ts4_word)lbl_88CB303C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4B288, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9348: call_seq lbl_88B4B2A0, lbl_88CB5B2C, lbl_880444CC, lbl_88CB5B8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4B2A0_889E9348(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5B8C, (ts4_word)(ts4_word)lbl_880444CC, (ts4_word)(ts4_word)lbl_88CB5B2C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4B2A0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E93C0: call_seq lbl_8804D7E8, lbl_8804E0E0, lbl_88CB5BBC, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF518, fn_88563470 */
ts4_word ts4_call_seq_lbl_8804D7E8_889E93C0(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CB5BBC, (ts4_word)(ts4_word)lbl_8804E0E0, (ts4_word)3, (ts4_word)(ts4_word)lbl_8804D7E8);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF518);
    return t2;
}

/* Swing_DLL.xex 0x889E9408: call_seq lbl_88B4BB70, lbl_88046C94, lbl_88CB5BD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4BB70_889E9408(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5BD4, (ts4_word)(ts4_word)lbl_88046C94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4BB70, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9478: addr lbl_88B50A60, u32@lbl_88B4BBE8, u32@0x38 */
void ts4_addr_lbl_88B50A60_889E9478(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B50A60) + 56) = (ts4_word)(*(ts4_word *)lbl_88B4BBE8);
    return;
}

/* Swing_DLL.xex 0x889E9490: call_seq lbl_88B50A60, lbl_8803EF04, lbl_88CB5C04, lbl_8804EA1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50A60_889E9490(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5C04, (ts4_word)(ts4_word)lbl_8803EF04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804EA1C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B50A60, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9500: call_seq lbl_88B4BBEC, lbl_88046C78, lbl_88CB5C34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4BBEC_889E9500(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5C34, (ts4_word)(ts4_word)lbl_88046C78, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4BBEC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9570: call_seq lbl_88B4BC1C, lbl_8803EC6C, lbl_88CB5C64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4BC1C_889E9570(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5C64, (ts4_word)(ts4_word)lbl_8803EC6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4BC1C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E95E0: call_seq lbl_88B4BC50, lbl_88CB5FF4, lbl_8803EE48, lbl_88CB5C94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4BC50_889E95E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5C94, (ts4_word)(ts4_word)lbl_8803EE48, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4BC50, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9658: call_seq lbl_88B4BCB0, lbl_88040040, lbl_88CB5CC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4BCB0_889E9658(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5CC4, (ts4_word)(ts4_word)lbl_88040040, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4BCB0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E96C8: call_seq lbl_88B4BD10, lbl_88CB5C94, lbl_8803ECD0, lbl_88CB5CF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4BD10_889E96C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5CF4, (ts4_word)(ts4_word)lbl_8803ECD0, (ts4_word)(ts4_word)lbl_88CB5C94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4BD10, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9740: call_seq lbl_88B4BDA0, lbl_88CB5C94, lbl_8803ECB0, lbl_88CB5D24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4BDA0_889E9740(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5D24, (ts4_word)(ts4_word)lbl_8803ECB0, (ts4_word)(ts4_word)lbl_88CB5C94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4BDA0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E97B8: call_seq lbl_88B4BDB8, lbl_88040078, lbl_88CB5D54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4BDB8_889E97B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5D54, (ts4_word)(ts4_word)lbl_88040078, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4BDB8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9828: call_seq lbl_88B4BE18, lbl_88CB5C94, lbl_8803EC94, lbl_88CB5D84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4BE18_889E9828(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5D84, (ts4_word)(ts4_word)lbl_8803EC94, (ts4_word)(ts4_word)lbl_88CB5C94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4BE18, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E98A0: call_seq lbl_88B4BEC0, lbl_88046C60, lbl_88CB5DB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4BEC0_889E98A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5DB4, (ts4_word)(ts4_word)lbl_88046C60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4BEC0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9910: call_seq lbl_88B4BED8, lbl_8803EE88, lbl_88CB5DE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4BED8_889E9910(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5DE4, (ts4_word)(ts4_word)lbl_8803EE88, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4BED8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9980: call_seq lbl_88B4BF38, lbl_88CB5FF4, lbl_8804002C, lbl_88CB5E14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4BF38_889E9980(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5E14, (ts4_word)(ts4_word)lbl_8804002C, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4BF38, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E99F8: call_seq lbl_88B4BF50, lbl_88046C00, lbl_88CB5E44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4BF50_889E99F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5E44, (ts4_word)(ts4_word)lbl_88046C00, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4BF50, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9A68: call_seq lbl_88B4BF98, lbl_88046C24, lbl_88CB5E74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4BF98_889E9A68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5E74, (ts4_word)(ts4_word)lbl_88046C24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4BF98, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9AD8: call_seq lbl_88B4C028, lbl_88046C48, lbl_88CB5EA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C028_889E9AD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5EA4, (ts4_word)(ts4_word)lbl_88046C48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C028, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9B48: call_seq lbl_88CB5FF4, lbl_8803EC3C, lbl_88CB5ED4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB5FF4_889E9B48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5ED4, (ts4_word)(ts4_word)lbl_8803EC3C, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9BB0: call_seq lbl_88B4C0B8, lbl_88CB5ED4, lbl_8803ECF4, lbl_88CB5F04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C0B8_889E9BB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5F04, (ts4_word)(ts4_word)lbl_8803ECF4, (ts4_word)(ts4_word)lbl_88CB5ED4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C0B8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9C28: call_seq lbl_88B4C118, lbl_8803EEFC, lbl_88CB5F34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C118_889E9C28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5F34, (ts4_word)(ts4_word)lbl_8803EEFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C118, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9C98: call_seq lbl_88B4C148, lbl_8803EEE8, lbl_88CB5F64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C148_889E9C98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5F64, (ts4_word)(ts4_word)lbl_8803EEE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C148, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9D08: call_seq lbl_88B4C190, lbl_8803EE7C, lbl_88CB5F94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C190_889E9D08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5F94, (ts4_word)(ts4_word)lbl_8803EE7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C190, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9D78: call_seq lbl_8803C97C, lbl_88CB5FC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803C97C_889E9D78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5FC4, (ts4_word)(ts4_word)lbl_8803C97C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9DD8: call_seq lbl_88B4C1F0, lbl_88CB5FC4, lbl_8803C9DC, lbl_88CB5FF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C1F0_889E9DD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)(ts4_word)lbl_8803C9DC, (ts4_word)(ts4_word)lbl_88CB5FC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C1F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9E50: call_seq lbl_88B4C220, lbl_8803CC5C, lbl_88CB6024, lbl_8804EA38, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C220_889E9E50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6024, (ts4_word)(ts4_word)lbl_8803CC5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804EA38, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B4C220, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9EC0: call_seq lbl_88B4C2C8, lbl_8803CCC4, lbl_88CB6054, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C2C8_889E9EC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6054, (ts4_word)(ts4_word)lbl_8803CCC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C2C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9F30: call_seq lbl_88B4C2F8, lbl_8803CCD4, lbl_88CB6084, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C2F8_889E9F30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6084, (ts4_word)(ts4_word)lbl_8803CCD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C2F8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889E9FA0: addr lbl_88B50AA8, u32@lbl_88B4C328, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88B50AA8_889E9FA0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B4C328;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B50AA8) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B50AA8) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x889E9FC0: call_seq lbl_88B50AA8, lbl_8803D124, lbl_88CB60B4, lbl_8804EBA8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50AA8_889E9FC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB60B4, (ts4_word)(ts4_word)lbl_8803D124, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804EBA8, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B50AA8, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA030: call_seq lbl_88B4C334, lbl_8803D484, lbl_88CB60E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C334_889EA030(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB60E4, (ts4_word)(ts4_word)lbl_8803D484, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C334, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA0A0: call_seq lbl_88B4C364, lbl_8803D4A8, lbl_88CB6114, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C364_889EA0A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6114, (ts4_word)(ts4_word)lbl_8803D4A8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C364, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA110: addr lbl_88B50B68, u32@lbl_88B4C37C, u32@0x50 */
void ts4_addr_lbl_88B50B68_889EA110(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B50B68) + 80) = (ts4_word)(*(ts4_word *)lbl_88B4C37C);
    return;
}

/* Swing_DLL.xex 0x889EA128: call_seq lbl_88B50B68, lbl_8803D4C4, lbl_88CB6144, lbl_8804EBFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50B68_889EA128(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6144, (ts4_word)(ts4_word)lbl_8803D4C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804EBFC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B50B68, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA198: call_seq lbl_88B4C380, lbl_8803CAF0, lbl_88CB6174, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C380_889EA198(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6174, (ts4_word)(ts4_word)lbl_8803CAF0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C380, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA208: call_seq lbl_88B4C3B0, lbl_8803D194, lbl_88CB61A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C3B0_889EA208(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB61A4, (ts4_word)(ts4_word)lbl_8803D194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C3B0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA278: call_seq lbl_88B4C3E8, lbl_8803D2E0, lbl_88CB61D4, lbl_8804EC20, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C3E8_889EA278(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB61D4, (ts4_word)(ts4_word)lbl_8803D2E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804EC20, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B4C3E8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA2E8: call_seq lbl_88B4C448, lbl_8803D6A0, lbl_88CB6204, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C448_889EA2E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6204, (ts4_word)(ts4_word)lbl_8803D6A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C448, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA358: call_seq lbl_88B4C508, lbl_8803D914, lbl_88CB6234, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C508_889EA358(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6234, (ts4_word)(ts4_word)lbl_8803D914, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C508, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA3C8: call_seq lbl_88B4C520, lbl_8803D9E8, lbl_88CB6264, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C520_889EA3C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6264, (ts4_word)(ts4_word)lbl_8803D9E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C520, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA438: addr lbl_88B50BF8, u32@lbl_88B4C3E4, u32@0x20 */
void ts4_addr_lbl_88B50BF8_889EA438(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B50BF8) + 32) = (ts4_word)(*(ts4_word *)lbl_88B4C3E4);
    return;
}

/* Swing_DLL.xex 0x889EA450: call_seq lbl_88B50BF8, lbl_8803F988, lbl_88CB6294, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50BF8_889EA450(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6294, (ts4_word)(ts4_word)lbl_8803F988, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50BF8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA4C0: addr lbl_88B50C28, u32@lbl_88B4C3E4, u32@0x20 */
void ts4_addr_lbl_88B50C28_889EA4C0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B50C28) + 32) = (ts4_word)(*(ts4_word *)lbl_88B4C3E4);
    return;
}

/* Swing_DLL.xex 0x889EA4D8: call_seq lbl_88B50C28, lbl_8803F974, lbl_88CB62C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50C28_889EA4D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB62C4, (ts4_word)(ts4_word)lbl_8803F974, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50C28, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA548: call_seq lbl_88B4C598, lbl_8804E4DC, lbl_88CB62F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C598_889EA548(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB62F4, (ts4_word)(ts4_word)lbl_8804E4DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C598, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA5B8: addr lbl_88B50C58, u32@lbl_88B4C3E4, u32@0x20 */
void ts4_addr_lbl_88B50C58_889EA5B8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B50C58) + 32) = (ts4_word)(*(ts4_word *)lbl_88B4C3E4);
    return;
}

/* Swing_DLL.xex 0x889EA5D0: call_seq lbl_88B50C58, lbl_8803F960, lbl_88CB6324, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50C58_889EA5D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6324, (ts4_word)(ts4_word)lbl_8803F960, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50C58, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA640: call_seq lbl_88B4C5B0, lbl_8803F9B0, lbl_88CB6354, lbl_8804EC64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C5B0_889EA640(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6354, (ts4_word)(ts4_word)lbl_8803F9B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804EC64, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B4C5B0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA6B0: call_seq lbl_88B4C5E0, lbl_8803F99C, lbl_88CB6384, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C5E0_889EA6B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6384, (ts4_word)(ts4_word)lbl_8803F99C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C5E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA720: call_seq lbl_88B4C610, lbl_8804E4F4, lbl_88CB63B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C610_889EA720(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB63B4, (ts4_word)(ts4_word)lbl_8804E4F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C610, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA790: call_seq lbl_88B4C640, lbl_88CB6414, lbl_8804E50C, lbl_88CB63E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C640_889EA790(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB63E4, (ts4_word)(ts4_word)lbl_8804E50C, (ts4_word)(ts4_word)lbl_88CB6414, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C640, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA808: call_seq lbl_88B4C658, lbl_8804E524, lbl_88CB6414, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C658_889EA808(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6414, (ts4_word)(ts4_word)lbl_8804E524, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C658, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA878: call_seq lbl_88B4C688, lbl_8804E53C, lbl_88CB6444, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C688_889EA878(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6444, (ts4_word)(ts4_word)lbl_8804E53C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C688, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA8E8: call_seq lbl_88B4C6A0, lbl_8804E560, lbl_88CB6474, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C6A0_889EA8E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6474, (ts4_word)(ts4_word)lbl_8804E560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C6A0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA958: call_seq lbl_88B4C6D0, lbl_8803F5C8, lbl_88CB64A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C6D0_889EA958(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB64A4, (ts4_word)(ts4_word)lbl_8803F5C8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C6D0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EA9C8: call_seq lbl_88B4C778, lbl_8804C310, lbl_88CB64D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C778_889EA9C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB64D4, (ts4_word)(ts4_word)lbl_8804C310, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C778, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EAA38: call_seq lbl_88B4C7A8, lbl_8803ED20, lbl_88CB6504, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C7A8_889EAA38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6504, (ts4_word)(ts4_word)lbl_8803ED20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C7A8, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EAAA8: addr lbl_88B50C88, u32@lbl_88B4C868, u32@0x8 */
void ts4_addr_lbl_88B50C88_889EAAA8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B50C88) + 8) = (ts4_word)(*(ts4_word *)lbl_88B4C868);
    return;
}

/* Swing_DLL.xex 0x889EAAC0: call_seq lbl_88B50C88, lbl_8804C33C, lbl_88CB6534, lbl_8804EC90, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50C88_889EAAC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6534, (ts4_word)(ts4_word)lbl_8804C33C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804EC90, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B50C88, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EAB30: call_seq lbl_88B4C870, lbl_8803ED28, lbl_88CB6564, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C870_889EAB30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6564, (ts4_word)(ts4_word)lbl_8803ED28, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C870, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EABA0: call_seq lbl_88B4C8A0, lbl_8803ED14, lbl_88CB6594, lbl_8804ECD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C8A0_889EABA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6594, (ts4_word)(ts4_word)lbl_8803ED14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804ECD4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B4C8A0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EAC10: addr lbl_88B50D00, u32@lbl_88B4C960, u32@0x20 */
void ts4_addr_lbl_88B50D00_889EAC10(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B50D00) + 32) = (ts4_word)(*(ts4_word *)lbl_88B4C960);
    return;
}

/* Swing_DLL.xex 0x889EAC28: call_seq lbl_88B50D00, lbl_8804E57C, lbl_88CB65C4, lbl_8804ED10, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50D00_889EAC28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB65C4, (ts4_word)(ts4_word)lbl_8804E57C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804ED10, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B50D00, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EAC98: call_seq lbl_88B4C964, lbl_8804C348, lbl_88CB65F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C964_889EAC98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB65F4, (ts4_word)(ts4_word)lbl_8804C348, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C964, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EAD08: call_seq lbl_88B4C97C, lbl_8804C358, lbl_88CB6624, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C97C_889EAD08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6624, (ts4_word)(ts4_word)lbl_8804C358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C97C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EAD78: addr lbl_88B50D48, u32@lbl_88B4C9AC, u32@0x8 */
void ts4_addr_lbl_88B50D48_889EAD78(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B50D48) + 8) = (ts4_word)(*(ts4_word *)lbl_88B4C9AC);
    return;
}

/* Swing_DLL.xex 0x889EAD90: call_seq lbl_88B50D48, lbl_8804C380, lbl_88CB6654, lbl_8804ED4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50D48_889EAD90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6654, (ts4_word)(ts4_word)lbl_8804C380, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804ED4C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B50D48, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EAE00: call_seq lbl_88B4C9B0, lbl_88042408, lbl_88CB6684, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C9B0_889EAE00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6684, (ts4_word)(ts4_word)lbl_88042408, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C9B0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EAE70: call_seq lbl_88B4C9C8, lbl_880423F8, lbl_88CB66B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4C9C8_889EAE70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB66B4, (ts4_word)(ts4_word)lbl_880423F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4C9C8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EAEE0: call_seq lbl_88B4CA10, lbl_8804C390, lbl_88CB66E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4CA10_889EAEE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB66E4, (ts4_word)(ts4_word)lbl_8804C390, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4CA10, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EAF50: call_seq lbl_88B4CA40, lbl_8804C3A0, lbl_88CB6714, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4CA40_889EAF50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6714, (ts4_word)(ts4_word)lbl_8804C3A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4CA40, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EAFC0: call_seq lbl_88B4CB60, lbl_8804C3B0, lbl_88CB6744, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4CB60_889EAFC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6744, (ts4_word)(ts4_word)lbl_8804C3B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4CB60, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB030: call_seq lbl_88B4CBF0, lbl_8804C3C4, lbl_88CB6774, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4CBF0_889EB030(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6774, (ts4_word)(ts4_word)lbl_8804C3C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4CBF0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB0A0: call_seq lbl_88B4CCB0, lbl_8804C3DC, lbl_88CB67A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4CCB0_889EB0A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB67A4, (ts4_word)(ts4_word)lbl_8804C3DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4CCB0, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB110: call_seq lbl_88B4CD88, lbl_8804C3F8, lbl_88CB67D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4CD88_889EB110(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB67D4, (ts4_word)(ts4_word)lbl_8804C3F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4CD88, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB180: call_seq lbl_88B4CE48, lbl_8804C410, lbl_88CB6804, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4CE48_889EB180(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6804, (ts4_word)(ts4_word)lbl_8804C410, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4CE48, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB1F0: call_seq lbl_88B4CEF0, lbl_8804ED60, lbl_8803F5BC, lbl_88CB6834, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4CEF0_889EB1F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6834, (ts4_word)(ts4_word)lbl_8803F5BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4CEF0, (ts4_word)12, (ts4_word)(ts4_word)lbl_8804ED60, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB268: call_seq lbl_88B4D010, lbl_8804C428, lbl_88CB6864, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D010_889EB268(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6864, (ts4_word)(ts4_word)lbl_8804C428, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D010, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB2D8: call_seq lbl_88B4D070, lbl_8803F5E0, lbl_88CB6894, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D070_889EB2D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6894, (ts4_word)(ts4_word)lbl_8803F5E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D070, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB348: call_seq lbl_88B4D178, lbl_88040278, lbl_88CB68C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D178_889EB348(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB68C4, (ts4_word)(ts4_word)lbl_88040278, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D178, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB3B8: call_seq lbl_88B4D250, lbl_8803ED58, lbl_88CB68F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D250_889EB3B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB68F4, (ts4_word)(ts4_word)lbl_8803ED58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D250, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB428: call_seq lbl_88B4D280, lbl_8803ED40, lbl_88CB6924, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D280_889EB428(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6924, (ts4_word)(ts4_word)lbl_8803ED40, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D280, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB498: call_seq lbl_88B4D298, lbl_880433FC, lbl_88CB6954, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D298_889EB498(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6954, (ts4_word)(ts4_word)lbl_880433FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D298, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB508: call_seq lbl_88B4D2E0, lbl_8804342C, lbl_88CB6984, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D2E0_889EB508(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6984, (ts4_word)(ts4_word)lbl_8804342C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D2E0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB578: call_seq lbl_88B4D2F8, lbl_88CB5FF4, lbl_8803ED7C, lbl_88CB69B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D2F8_889EB578(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB69B4, (ts4_word)(ts4_word)lbl_8803ED7C, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D2F8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB5F0: call_seq lbl_88B4D340, lbl_88046454, lbl_88CB69E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D340_889EB5F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB69E4, (ts4_word)(ts4_word)lbl_88046454, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D340, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB660: call_seq lbl_88B4D3A0, lbl_88CB69E4, lbl_8804233C, lbl_88CB6A14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D3A0_889EB660(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6A14, (ts4_word)(ts4_word)lbl_8804233C, (ts4_word)(ts4_word)lbl_88CB69E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D3A0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB6D8: call_seq lbl_880469C4, lbl_88CB6A44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880469C4_889EB6D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6A44, (ts4_word)(ts4_word)lbl_880469C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB738: call_seq lbl_88B4D3E8, lbl_88CB82A4, lbl_88042E48, lbl_88CB6A74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D3E8_889EB738(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6A74, (ts4_word)(ts4_word)lbl_88042E48, (ts4_word)(ts4_word)lbl_88CB82A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D3E8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB7B0: call_seq lbl_88046B60, lbl_88CB6AA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046B60_889EB7B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6AA4, (ts4_word)(ts4_word)lbl_88046B60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB810: call_seq lbl_88CB5FF4, lbl_88042318, lbl_88CB6AD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB5FF4_889EB810(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6AD4, (ts4_word)(ts4_word)lbl_88042318, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB878: call_seq lbl_88046A84, lbl_88CB6B04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A84_889EB878(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6B04, (ts4_word)(ts4_word)lbl_88046A84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB8D8: call_seq lbl_88B4D448, lbl_88CB6AD4, lbl_8804232C, lbl_88CB6B34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D448_889EB8D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6B34, (ts4_word)(ts4_word)lbl_8804232C, (ts4_word)(ts4_word)lbl_88CB6AD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D448, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB950: call_seq lbl_88B4D478, lbl_88CB6AD4, lbl_8804690C, lbl_88CB6B64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D478_889EB950(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6B64, (ts4_word)(ts4_word)lbl_8804690C, (ts4_word)(ts4_word)lbl_88CB6AD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D478, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EB9C8: call_seq lbl_88CB6AD4, lbl_8804671C, lbl_88CB6B94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB6AD4_889EB9C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6B94, (ts4_word)(ts4_word)lbl_8804671C, (ts4_word)(ts4_word)lbl_88CB6AD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EBA30: call_seq lbl_88046A50, lbl_88CB6BC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A50_889EBA30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6BC4, (ts4_word)(ts4_word)lbl_88046A50, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EBA90: call_seq lbl_88B4D490, lbl_88CB5FF4, lbl_88041284, lbl_88CB6BF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D490_889EBA90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6BF4, (ts4_word)(ts4_word)lbl_88041284, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D490, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EBB08: call_seq lbl_88B4D4A8, lbl_88046220, lbl_88CB6C24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D4A8_889EBB08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6C24, (ts4_word)(ts4_word)lbl_88046220, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D4A8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EBB78: call_seq lbl_88B4D508, lbl_88CB6D44, lbl_8804694C, lbl_88CB6C54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D508_889EBB78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6C54, (ts4_word)(ts4_word)lbl_8804694C, (ts4_word)(ts4_word)lbl_88CB6D44, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D508, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EBBF0: call_seq lbl_88B4D520, lbl_88CB6BF4, lbl_88040110, lbl_88CB6C84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D520_889EBBF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6C84, (ts4_word)(ts4_word)lbl_88040110, (ts4_word)(ts4_word)lbl_88CB6BF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D520, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EBC68: call_seq lbl_88B4D550, lbl_88CB6BF4, lbl_88040100, lbl_88CB6CB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D550_889EBC68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6CB4, (ts4_word)(ts4_word)lbl_88040100, (ts4_word)(ts4_word)lbl_88CB6BF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D550, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EBCE0: call_seq lbl_88B4D568, lbl_88CB6D44, lbl_8804011C, lbl_88CB6CE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D568_889EBCE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6CE4, (ts4_word)(ts4_word)lbl_8804011C, (ts4_word)(ts4_word)lbl_88CB6D44, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D568, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EBD58: call_seq lbl_88B4D598, lbl_88CB6BF4, lbl_880400A8, lbl_88CB6D14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D598_889EBD58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6D14, (ts4_word)(ts4_word)lbl_880400A8, (ts4_word)(ts4_word)lbl_88CB6BF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D598, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EBDD0: call_seq lbl_88B4D5B0, lbl_88CB71F4, lbl_88042370, lbl_88CB6D44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D5B0_889EBDD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6D44, (ts4_word)(ts4_word)lbl_88042370, (ts4_word)(ts4_word)lbl_88CB71F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D5B0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EBE48: call_seq lbl_88B4D5C8, lbl_88CB6F54, lbl_88041B24, lbl_88CB6D74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D5C8_889EBE48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6D74, (ts4_word)(ts4_word)lbl_88041B24, (ts4_word)(ts4_word)lbl_88CB6F54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D5C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EBEC0: call_seq lbl_88B4D5E0, lbl_88CB6D14, lbl_880468C8, lbl_88CB6DA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D5E0_889EBEC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6DA4, (ts4_word)(ts4_word)lbl_880468C8, (ts4_word)(ts4_word)lbl_88CB6D14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D5E0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EBF38: call_seq lbl_88B4D628, lbl_88CB6D44, lbl_880400E8, lbl_88CB6DD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D628_889EBF38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6DD4, (ts4_word)(ts4_word)lbl_880400E8, (ts4_word)(ts4_word)lbl_88CB6D44, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D628, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EBFB0: call_seq lbl_88B4D658, lbl_88CB6D44, lbl_880400D0, lbl_88CB6E04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D658_889EBFB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6E04, (ts4_word)(ts4_word)lbl_880400D0, (ts4_word)(ts4_word)lbl_88CB6D44, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D658, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC028: call_seq lbl_88B4D688, lbl_880463D4, lbl_88CB6E34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D688_889EC028(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6E34, (ts4_word)(ts4_word)lbl_880463D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D688, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC098: call_seq lbl_88B4D6D0, lbl_88CB6D44, lbl_88046868, lbl_88CB6E64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D6D0_889EC098(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6E64, (ts4_word)(ts4_word)lbl_88046868, (ts4_word)(ts4_word)lbl_88CB6D44, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D6D0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC110: call_seq lbl_88B4D750, lbl_88CB6D44, lbl_8803EFC0, lbl_88CB6E94, lbl_8804EDE8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D750_889EC110(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6E94, (ts4_word)(ts4_word)lbl_8803EFC0, (ts4_word)(ts4_word)lbl_88CB6D44, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804EDE8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B4D750, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC188: call_seq lbl_88CB6FE4, lbl_880467DC, lbl_88CB6EC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB6FE4_889EC188(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6EC4, (ts4_word)(ts4_word)lbl_880467DC, (ts4_word)(ts4_word)lbl_88CB6FE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC1F0: call_seq lbl_88CB6BF4, lbl_88046AE0, lbl_88CB6EF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB6BF4_889EC1F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6EF4, (ts4_word)(ts4_word)lbl_88046AE0, (ts4_word)(ts4_word)lbl_88CB6BF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC258: call_seq lbl_88B4D7C8, lbl_88042358, lbl_88CB6F24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D7C8_889EC258(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6F24, (ts4_word)(ts4_word)lbl_88042358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D7C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC2C8: call_seq lbl_88B4D7F8, lbl_88CB6D14, lbl_8804234C, lbl_88CB6F54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D7F8_889EC2C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6F54, (ts4_word)(ts4_word)lbl_8804234C, (ts4_word)(ts4_word)lbl_88CB6D14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D7F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC340: call_seq lbl_88B4D810, lbl_88046320, lbl_88CB6F84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D810_889EC340(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6F84, (ts4_word)(ts4_word)lbl_88046320, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D810, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC3B0: addr lbl_88B50DC0, u32@lbl_88B4D74C, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88B50DC0_889EC3B0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B4D74C;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B50DC0) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B50DC0) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x889EC3D0: call_seq lbl_88B50DC0, lbl_8803EFE8, lbl_88CB6FB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B50DC0_889EC3D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6FB4, (ts4_word)(ts4_word)lbl_8803EFE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B50DC0, (ts4_word)13, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC440: call_seq lbl_88B4D830, lbl_88CB6D14, lbl_8803EF9C, lbl_88CB6FE4, lbl_8804EE3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D830_889EC440(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB6FE4, (ts4_word)(ts4_word)lbl_8803EF9C, (ts4_word)(ts4_word)lbl_88CB6D14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804EE3C, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B4D830, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC4B8: call_seq lbl_88B4D890, lbl_88CB6CB4, lbl_880423C0, lbl_88CB7014, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D890_889EC4B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7014, (ts4_word)(ts4_word)lbl_880423C0, (ts4_word)(ts4_word)lbl_88CB6CB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D890, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC530: call_seq lbl_88B4D8A8, lbl_880462E8, lbl_88CB7044, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D8A8_889EC530(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7044, (ts4_word)(ts4_word)lbl_880462E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D8A8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC5A0: call_seq lbl_88B4D8D8, lbl_88CB6BF4, lbl_8804675C, lbl_88CB7074, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D8D8_889EC5A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7074, (ts4_word)(ts4_word)lbl_8804675C, (ts4_word)(ts4_word)lbl_88CB6BF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D8D8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC618: call_seq lbl_88B4D908, lbl_88CB71F4, lbl_8803F9D4, lbl_88CB70A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D908_889EC618(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB70A4, (ts4_word)(ts4_word)lbl_8803F9D4, (ts4_word)(ts4_word)lbl_88CB71F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D908, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC690: call_seq lbl_88CB6BF4, lbl_88046AB4, lbl_88CB70D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB6BF4_889EC690(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB70D4, (ts4_word)(ts4_word)lbl_88046AB4, (ts4_word)(ts4_word)lbl_88CB6BF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC6F8: call_seq lbl_88B4D938, lbl_88CB6EF4, lbl_880466D4, lbl_88CB7104, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D938_889EC6F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7104, (ts4_word)(ts4_word)lbl_880466D4, (ts4_word)(ts4_word)lbl_88CB6EF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D938, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC770: call_seq lbl_88B4D980, lbl_88CB6EF4, lbl_88046A18, lbl_88CB7134, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4D980_889EC770(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7134, (ts4_word)(ts4_word)lbl_88046A18, (ts4_word)(ts4_word)lbl_88CB6EF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4D980, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC7E8: call_seq lbl_88B4DA28, lbl_880423A4, lbl_88CB7164, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DA28_889EC7E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7164, (ts4_word)(ts4_word)lbl_880423A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DA28, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC858: call_seq lbl_88B4DA70, lbl_88CB6D14, lbl_88042390, lbl_88CB7194, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DA70_889EC858(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7194, (ts4_word)(ts4_word)lbl_88042390, (ts4_word)(ts4_word)lbl_88CB6D14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DA70, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC8D0: call_seq lbl_88CB6D44, lbl_88043ED0, lbl_88CB71C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB6D44_889EC8D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB71C4, (ts4_word)(ts4_word)lbl_88043ED0, (ts4_word)(ts4_word)lbl_88CB6D44, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC938: call_seq lbl_88CB6BF4, lbl_8804696C, lbl_88CB71F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CB6BF4_889EC938(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB71F4, (ts4_word)(ts4_word)lbl_8804696C, (ts4_word)(ts4_word)lbl_88CB6BF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889EC9A0: call_seq lbl_88B4DAD0, lbl_8803F00C, lbl_88CB7224, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DAD0_889EC9A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7224, (ts4_word)(ts4_word)lbl_8803F00C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DAD0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ECA10: call_seq lbl_88B4DB60, lbl_88CB6FE4, lbl_88046574, lbl_88CB7254, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DB60_889ECA10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7254, (ts4_word)(ts4_word)lbl_88046574, (ts4_word)(ts4_word)lbl_88CB6FE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DB60, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ECA88: call_seq lbl_88B4DB78, lbl_88CB7134, lbl_88046518, lbl_88CB7284, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DB78_889ECA88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7284, (ts4_word)(ts4_word)lbl_88046518, (ts4_word)(ts4_word)lbl_88CB7134, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DB78, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ECB00: call_seq lbl_88B4DBA8, lbl_88CB6BF4, lbl_880400BC, lbl_88CB72B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DBA8_889ECB00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB72B4, (ts4_word)(ts4_word)lbl_880400BC, (ts4_word)(ts4_word)lbl_88CB6BF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DBA8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ECB78: call_seq lbl_88B4DBF0, lbl_88CB6D44, lbl_88042380, lbl_88CB72E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DBF0_889ECB78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB72E4, (ts4_word)(ts4_word)lbl_88042380, (ts4_word)(ts4_word)lbl_88CB6D44, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DBF0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ECBF0: call_seq lbl_88B4DC38, lbl_8803FBF4, lbl_88CB7314, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DC38_889ECBF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7314, (ts4_word)(ts4_word)lbl_8803FBF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DC38, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ECC60: call_seq lbl_88B4DC80, lbl_88CB6CB4, lbl_880423D4, lbl_88CB7344, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DC80_889ECC60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7344, (ts4_word)(ts4_word)lbl_880423D4, (ts4_word)(ts4_word)lbl_88CB6CB4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DC80, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ECCD8: call_seq lbl_88B4DC98, lbl_88CB6D14, lbl_88046498, lbl_88CB7374, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DC98_889ECCD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB7374, (ts4_word)(ts4_word)lbl_88046498, (ts4_word)(ts4_word)lbl_88CB6D14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DC98, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ECD50: call_seq lbl_88B4DCC8, lbl_88CB5FF4, lbl_88047050, lbl_88CB73A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DCC8_889ECD50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB73A4, (ts4_word)(ts4_word)lbl_88047050, (ts4_word)(ts4_word)lbl_88CB5FF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DCC8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889ECDC8: call_seq lbl_88B4DD28, lbl_88CB73A4, lbl_88045B44, lbl_88CB73D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B4DD28_889ECDC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CB73D4, (ts4_word)(ts4_word)lbl_88045B44, (ts4_word)(ts4_word)lbl_88CB73A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B4DD28, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}
