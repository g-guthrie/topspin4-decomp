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

extern char ts4_addr_lbl_8803A308_88AFF5D8[];
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
extern char lbl_8803EFE8[];
extern char lbl_8803F5BC[];
extern char lbl_8803F5C8[];
extern char lbl_8803F5E0[];
extern char lbl_8803F610[];
extern char lbl_8803F634[];
extern char lbl_8803F960[];
extern char lbl_8803F974[];
extern char lbl_8803F988[];
extern char lbl_8803F99C[];
extern char lbl_8803F9B0[];
extern char lbl_8803F9C0[];
extern char lbl_8803F9D4[];
extern char lbl_8804002C[];
extern char lbl_88040040[];
extern char lbl_88040078[];
extern char lbl_880400A8[];
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
extern char lbl_88041B24[];
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
extern char lbl_88042318[];
extern char lbl_8804232C[];
extern char lbl_8804233C[];
extern char lbl_8804234C[];
extern char lbl_88042358[];
extern char lbl_88042370[];
extern char lbl_880423A4[];
extern char lbl_880423C0[];
extern char lbl_880423F8[];
extern char lbl_88042408[];
extern char lbl_88042E48[];
extern char lbl_880433FC[];
extern char lbl_8804342C[];
extern char lbl_88044268[];
extern char lbl_88044324[];
extern char lbl_88044370[];
extern char lbl_880443CC[];
extern char lbl_8804449C[];
extern char lbl_880444CC[];
extern char lbl_88044568[];
extern char lbl_880445A8[];
extern char lbl_880445E4[];
extern char lbl_8804461C[];
extern char lbl_88044650[];
extern char lbl_880446BC[];
extern char lbl_88044744[];
extern char lbl_88044758[];
extern char lbl_88044784[];
extern char lbl_880447B8[];
extern char lbl_880447EC[];
extern char lbl_8804481C[];
extern char lbl_8804484C[];
extern char lbl_88044874[];
extern char lbl_8804489C[];
extern char lbl_88046220[];
extern char lbl_880462E8[];
extern char lbl_88046320[];
extern char lbl_880463D4[];
extern char lbl_88046454[];
extern char lbl_88046678[];
extern char lbl_880466D4[];
extern char lbl_8804671C[];
extern char lbl_8804675C[];
extern char lbl_880467DC[];
extern char lbl_88046868[];
extern char lbl_880468C8[];
extern char lbl_8804690C[];
extern char lbl_8804694C[];
extern char lbl_88046994[];
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
extern char lbl_88057280[];
extern char lbl_88058480[];
extern char lbl_88058A10[];
extern char lbl_88058A20[];
extern char lbl_88058C84[];
extern char lbl_88058CC0[];
extern char lbl_88058CF4[];
extern char lbl_88058D08[];
extern char lbl_88058D4C[];
extern char lbl_88058D60[];
extern char lbl_88058D8C[];
extern char lbl_88058E28[];
extern char lbl_88058E74[];
extern char lbl_88058F14[];
extern char lbl_88058F80[];
extern char lbl_88058FA4[];
extern char lbl_88058FEC[];
extern char lbl_88059058[];
extern char lbl_88059090[];
extern char lbl_88059188[];
extern char lbl_8805919C[];
extern char lbl_880591B8[];
extern char lbl_88059330[];
extern char lbl_88059384[];
extern char lbl_880593C0[];
extern char lbl_880593F8[];
extern char lbl_8805943C[];
extern char lbl_88059468[];
extern char lbl_880594AC[];
extern char lbl_880594E8[];
extern char lbl_88059524[];
extern char lbl_88059538[];
extern char lbl_880595B0[];
extern char lbl_8805965C[];
extern char lbl_88B7C3D8[];
extern char lbl_88B7C438[];
extern char lbl_88B7C528[];
extern char lbl_88B7C618[];
extern char lbl_88B7C660[];
extern char lbl_88B7C738[];
extern char lbl_88B7C750[];
extern char lbl_88B7C798[];
extern char lbl_88B7C7E0[];
extern char lbl_88B7C7F8[];
extern char lbl_88B7C840[];
extern char lbl_88B7C858[];
extern char lbl_88B7C900[];
extern char lbl_88B7C930[];
extern char lbl_88B7C978[];
extern char lbl_88B7C9C0[];
extern char lbl_88B7CA08[];
extern char lbl_88B7CA20[];
extern char lbl_88B7CA38[];
extern char lbl_88B7D938[];
extern char lbl_88B7D9B0[];
extern char lbl_88B7D9B4[];
extern char lbl_88B7D9E4[];
extern char lbl_88B7DA18[];
extern char lbl_88B7DA78[];
extern char lbl_88B7DAF0[];
extern char lbl_88B7DB98[];
extern char lbl_88B7DBB0[];
extern char lbl_88B7DC28[];
extern char lbl_88B7DCD0[];
extern char lbl_88B7DCE8[];
extern char lbl_88B7DD48[];
extern char lbl_88B7DD60[];
extern char lbl_88B7DDA8[];
extern char lbl_88B7DE38[];
extern char lbl_88B7DEC8[];
extern char lbl_88B7DF28[];
extern char lbl_88B7DF58[];
extern char lbl_88B7DFB8[];
extern char lbl_88B7E018[];
extern char lbl_88B7E098[];
extern char lbl_88B7E1A0[];
extern char lbl_88B7E2A8[];
extern char lbl_88B7E2D8[];
extern char lbl_88B7E380[];
extern char lbl_88B7E3C8[];
extern char lbl_88B7E488[];
extern char lbl_88B7E4D0[];
extern char lbl_88B7E4D4[];
extern char lbl_88B7E504[];
extern char lbl_88B7E51C[];
extern char lbl_88B7E54C[];
extern char lbl_88B7E550[];
extern char lbl_88B7E5B0[];
extern char lbl_88B7E5E0[];
extern char lbl_88B7E760[];
extern char lbl_88B7E778[];
extern char lbl_88B7E7D8[];
extern char lbl_88B7E8B0[];
extern char lbl_88B7E9B8[];
extern char lbl_88B7E9E8[];
extern char lbl_88B7EA18[];
extern char lbl_88B7EAA8[];
extern char lbl_88B7EAAC[];
extern char lbl_88B7EAE0[];
extern char lbl_88B7EB70[];
extern char lbl_88B7ECC0[];
extern char lbl_88B7ED80[];
extern char lbl_88B7ED98[];
extern char lbl_88B7EE28[];
extern char lbl_88B7EE40[];
extern char lbl_88B7EE58[];
extern char lbl_88B7EE70[];
extern char lbl_88B7EED8[];
extern char lbl_88B7EF98[];
extern char lbl_88B7EFE0[];
extern char lbl_88B7F160[];
extern char lbl_88B7F168[];
extern char lbl_88B7F1C8[];
extern char lbl_88B7F1F8[];
extern char lbl_88B7F210[];
extern char lbl_88B7F244[];
extern char lbl_88B7F248[];
extern char lbl_88B7F2F0[];
extern char lbl_88B7F320[];
extern char lbl_88B7F358[];
extern char lbl_88B7F388[];
extern char lbl_88B7F3A0[];
extern char lbl_88B7F3B0[];
extern char lbl_88B7F3F8[];
extern char lbl_88B7F428[];
extern char lbl_88B7F458[];
extern char lbl_88B7F4B8[];
extern char lbl_88B7F5A8[];
extern char lbl_88B7F5C0[];
extern char lbl_88B7F638[];
extern char lbl_88B7F650[];
extern char lbl_88B7F654[];
extern char lbl_88B7F684[];
extern char lbl_88B7F6B4[];
extern char lbl_88B7F6E4[];
extern char lbl_88B7F6FC[];
extern char lbl_88B7F72C[];
extern char lbl_88B7F744[];
extern char lbl_88B7F774[];
extern char lbl_88B7F778[];
extern char lbl_88B7F820[];
extern char lbl_88B7F850[];
extern char lbl_88B7F868[];
extern char lbl_88B7F898[];
extern char lbl_88B7F95C[];
extern char lbl_88B7F98C[];
extern char lbl_88B7F990[];
extern char lbl_88B7FA50[];
extern char lbl_88B7FA68[];
extern char lbl_88B7FA98[];
extern char lbl_88B7FA9C[];
extern char lbl_88B7FAB8[];
extern char lbl_88B7FB00[];
extern char lbl_88B7FB30[];
extern char lbl_88B7FC50[];
extern char lbl_88B7FCE0[];
extern char lbl_88B7FDA0[];
extern char lbl_88B7FE78[];
extern char lbl_88B7FF38[];
extern char lbl_88B7FFE0[];
extern char lbl_88B80100[];
extern char lbl_88B80160[];
extern char lbl_88B80268[];
extern char lbl_88B80340[];
extern char lbl_88B80388[];
extern char lbl_88B803A0[];
extern char lbl_88B803E8[];
extern char lbl_88B80400[];
extern char lbl_88B80448[];
extern char lbl_88B804A8[];
extern char lbl_88B804F0[];
extern char lbl_88B80550[];
extern char lbl_88B80580[];
extern char lbl_88B80598[];
extern char lbl_88B805B0[];
extern char lbl_88B805C8[];
extern char lbl_88B80628[];
extern char lbl_88B80640[];
extern char lbl_88B80670[];
extern char lbl_88B80688[];
extern char lbl_88B806B8[];
extern char lbl_88B806D0[];
extern char lbl_88B806E8[];
extern char lbl_88B80700[];
extern char lbl_88B80748[];
extern char lbl_88B80778[];
extern char lbl_88B807A8[];
extern char lbl_88B807F0[];
extern char lbl_88B8086C[];
extern char lbl_88B80900[];
extern char lbl_88B80930[];
extern char lbl_88B80948[];
extern char lbl_88B80968[];
extern char lbl_88B809E0[];
extern char lbl_88B809F8[];
extern char lbl_88B80A28[];
extern char lbl_88B80A58[];
extern char lbl_88B80A88[];
extern char lbl_88B80AD0[];
extern char lbl_88B80B78[];
extern char lbl_88B83D28[];
extern char lbl_88B83D70[];
extern char lbl_88B83ED8[];
extern char lbl_88B84070[];
extern char lbl_88B84178[];
extern char lbl_88B84298[];
extern char lbl_88B84358[];
extern char lbl_88B843E8[];
extern char lbl_88B84418[];
extern char lbl_88B84448[];
extern char lbl_88B84478[];
extern char lbl_88B844F0[];
extern char lbl_88B84538[];
extern char lbl_88B845B0[];
extern char lbl_88CCF20C[];
extern char lbl_88CD217C[];
extern char lbl_88CD21DC[];
extern char lbl_88CD220C[];
extern char lbl_88CD223C[];
extern char lbl_88CD226C[];
extern char lbl_88CD229C[];
extern char lbl_88CD22CC[];
extern char lbl_88CD22FC[];
extern char lbl_88CD232C[];
extern char lbl_88CD235C[];
extern char lbl_88CD238C[];
extern char lbl_88CD23BC[];
extern char lbl_88CD23EC[];
extern char lbl_88CD241C[];
extern char lbl_88CD244C[];
extern char lbl_88CD247C[];
extern char lbl_88CD24AC[];
extern char lbl_88CD24DC[];
extern char lbl_88CD250C[];
extern char lbl_88CD253C[];
extern char lbl_88CD256C[];
extern char lbl_88CD259C[];
extern char lbl_88CD25CC[];
extern char lbl_88CD25FC[];
extern char lbl_88CD262C[];
extern char lbl_88CD2644[];
extern char lbl_88CD2674[];
extern char lbl_88CD26A4[];
extern char lbl_88CD26D4[];
extern char lbl_88CD2704[];
extern char lbl_88CD2734[];
extern char lbl_88CD2764[];
extern char lbl_88CD2794[];
extern char lbl_88CD27C4[];
extern char lbl_88CD27F4[];
extern char lbl_88CD2824[];
extern char lbl_88CD2854[];
extern char lbl_88CD2884[];
extern char lbl_88CD28B4[];
extern char lbl_88CD28E4[];
extern char lbl_88CD2914[];
extern char lbl_88CD2944[];
extern char lbl_88CD2974[];
extern char lbl_88CD29A4[];
extern char lbl_88CD29D4[];
extern char lbl_88CD2A04[];
extern char lbl_88CD2A34[];
extern char lbl_88CD2A64[];
extern char lbl_88CD2A94[];
extern char lbl_88CD2AC4[];
extern char lbl_88CD2AF4[];
extern char lbl_88CD2B24[];
extern char lbl_88CD2B54[];
extern char lbl_88CD2B84[];
extern char lbl_88CD2BB4[];
extern char lbl_88CD2BE4[];
extern char lbl_88CD2C44[];
extern char lbl_88CD2C74[];
extern char lbl_88CD2CA4[];
extern char lbl_88CD2CD4[];
extern char lbl_88CD2D04[];
extern char lbl_88CD2D34[];
extern char lbl_88CD2D64[];
extern char lbl_88CD2D94[];
extern char lbl_88CD2DC4[];
extern char lbl_88CD2DF4[];
extern char lbl_88CD2E24[];
extern char lbl_88CD2E54[];
extern char lbl_88CD2EB4[];
extern char lbl_88CD2EE4[];
extern char lbl_88CD2F44[];
extern char lbl_88CD2F74[];
extern char lbl_88CD2FA4[];
extern char lbl_88CD2FD4[];
extern char lbl_88CD3004[];
extern char lbl_88CD3034[];
extern char lbl_88CD3064[];
extern char lbl_88CD3094[];
extern char lbl_88CD30C4[];
extern char lbl_88CD30F4[];
extern char lbl_88CD3124[];
extern char lbl_88CD3154[];
extern char lbl_88CD3184[];
extern char lbl_88CD31B4[];
extern char lbl_88CD31E4[];
extern char lbl_88CD3244[];
extern char lbl_88CD3274[];
extern char lbl_88CD32A4[];
extern char lbl_88CD32D4[];
extern char lbl_88CD3304[];
extern char lbl_88CD3334[];
extern char lbl_88CD3364[];
extern char lbl_88CD3394[];
extern char lbl_88CD33C4[];
extern char lbl_88CD33F4[];
extern char lbl_88CD3424[];
extern char lbl_88CD3454[];
extern char lbl_88CD3484[];
extern char lbl_88CD34B4[];
extern char lbl_88CD34E4[];
extern char lbl_88CD3514[];
extern char lbl_88CD3544[];
extern char lbl_88CD3574[];
extern char lbl_88CD35A4[];
extern char lbl_88CD35D4[];
extern char lbl_88CD3604[];
extern char lbl_88CD3634[];
extern char lbl_88CD3664[];
extern char lbl_88CD3694[];
extern char lbl_88CD36C4[];
extern char lbl_88CD36F4[];
extern char lbl_88CD3724[];
extern char lbl_88CD3754[];
extern char lbl_88CD3784[];
extern char lbl_88CD37B4[];
extern char lbl_88CD37E4[];
extern char lbl_88CD3814[];
extern char lbl_88CD3844[];
extern char lbl_88CD3874[];
extern char lbl_88CD38A4[];
extern char lbl_88CD38D4[];
extern char lbl_88CD3904[];
extern char lbl_88CD3934[];
extern char lbl_88CD3964[];
extern char lbl_88CD3994[];
extern char lbl_88CD39C4[];
extern char lbl_88CD39F4[];
extern char lbl_88CD3A24[];
extern char lbl_88CD3A54[];
extern char lbl_88CD3A84[];
extern char lbl_88CD3AB4[];
extern char lbl_88CD3AE4[];
extern char lbl_88CD3B14[];
extern char lbl_88CD3B44[];
extern char lbl_88CD3B74[];
extern char lbl_88CD3BA4[];
extern char lbl_88CD3BD4[];
extern char lbl_88CD3C04[];
extern char lbl_88CD3C34[];
extern char lbl_88CD3C64[];
extern char lbl_88CD3C94[];
extern char lbl_88CD3CC4[];
extern char lbl_88CD3CF4[];
extern char lbl_88CD3D24[];
extern char lbl_88CD3D54[];
extern char lbl_88CD3D84[];
extern char lbl_88CD3DB4[];
extern char lbl_88CD3DE4[];
extern char lbl_88CD3E14[];
extern char lbl_88CD3E44[];
extern char lbl_88CD3E74[];
extern char lbl_88CD3EA4[];
extern char lbl_88CD3ED4[];
extern char lbl_88CD3F04[];
extern char lbl_88CD3F34[];
extern char lbl_88CD3F64[];
extern char lbl_88CD3F94[];
extern char lbl_88CD3FC4[];
extern char lbl_88CD3FF4[];
extern char lbl_88CD4024[];
extern char lbl_88CD4054[];
extern char lbl_88CD4084[];
extern char lbl_88CD40B4[];
extern char lbl_88CD40E4[];
extern char lbl_88CD4114[];
extern char lbl_88CD4144[];
extern char lbl_88CD4174[];
extern char lbl_88CD41A4[];
extern char lbl_88CD41D4[];
extern char lbl_88CD4204[];
extern char lbl_88CD4234[];
extern char lbl_88CD4264[];
extern char lbl_88CD42C4[];
extern char lbl_88CD42F4[];
extern char lbl_88CD4324[];
extern char lbl_88CD4354[];
extern char lbl_88CD4384[];
extern char lbl_88CD43B4[];
extern char lbl_88CD43E4[];
extern char lbl_88CD4414[];
extern char lbl_88CD4444[];
extern char lbl_88CD4474[];
extern char lbl_88CD44A4[];
extern char lbl_88CD44D4[];
extern char lbl_88CD4504[];
extern char lbl_88CD4534[];
extern char lbl_88CD4564[];
extern char lbl_88CD45F4[];
extern char lbl_88CD5AC4[];
ts4_word fn_8841F080();
ts4_word ts4_set_u32_offc_884CE988();
ts4_word fn_88563470();

/* Swing_DLL.xex 0x88A2DF60: call_seq lbl_88B7C3D8, lbl_88CD217C, lbl_880446BC, lbl_88CD21DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C3D8_88A2DF60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD21DC, (ts4_word)(ts4_word)lbl_880446BC, (ts4_word)(ts4_word)lbl_88CD217C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C3D8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2DFD8: call_seq lbl_88CCF20C, lbl_8804489C, lbl_88CD220C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCF20C_88A2DFD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD220C, (ts4_word)(ts4_word)lbl_8804489C, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E040: call_seq lbl_88B7C438, lbl_88CD220C, lbl_88044650, lbl_88CD223C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C438_88A2E040(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD223C, (ts4_word)(ts4_word)lbl_88044650, (ts4_word)(ts4_word)lbl_88CD220C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C438, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E0B8: call_seq lbl_88B7C528, lbl_88044324, lbl_88CD226C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C528_88A2E0B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD226C, (ts4_word)(ts4_word)lbl_88044324, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C528, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E128: call_seq lbl_88B7C618, lbl_88044370, lbl_88CD229C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C618_88A2E128(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD229C, (ts4_word)(ts4_word)lbl_88044370, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C618, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E198: call_seq lbl_88B7C660, lbl_8803F610, lbl_88CD22CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C660_88A2E198(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD22CC, (ts4_word)(ts4_word)lbl_8803F610, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C660, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E208: call_seq lbl_88B7C738, lbl_8803F634, lbl_88CD22FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C738_88A2E208(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD22FC, (ts4_word)(ts4_word)lbl_8803F634, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C738, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E278: call_seq lbl_88CCF20C, lbl_88044874, lbl_88CD232C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCF20C_88A2E278(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD232C, (ts4_word)(ts4_word)lbl_88044874, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E2E0: call_seq lbl_88B7C750, lbl_88CD232C, lbl_8804461C, lbl_88CD235C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C750_88A2E2E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD235C, (ts4_word)(ts4_word)lbl_8804461C, (ts4_word)(ts4_word)lbl_88CD232C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C750, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E358: call_seq lbl_88B7C798, lbl_88044268, lbl_88CD238C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C798_88A2E358(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD238C, (ts4_word)(ts4_word)lbl_88044268, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C798, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E3C8: call_seq lbl_88B7C7E0, lbl_88CCF20C, lbl_8804484C, lbl_88CD23BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C7E0_88A2E3C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD23BC, (ts4_word)(ts4_word)lbl_8804484C, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C7E0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E440: call_seq lbl_88B7C7F8, lbl_880443CC, lbl_88CD23EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C7F8_88A2E440(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD23EC, (ts4_word)(ts4_word)lbl_880443CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C7F8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E4B0: call_seq lbl_88B7C840, lbl_88CD23BC, lbl_880445E4, lbl_88CD241C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C840_88A2E4B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD241C, (ts4_word)(ts4_word)lbl_880445E4, (ts4_word)(ts4_word)lbl_88CD23BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C840, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E528: call_seq lbl_88CCF20C, lbl_8804481C, lbl_88CD244C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCF20C_88A2E528(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD244C, (ts4_word)(ts4_word)lbl_8804481C, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E590: call_seq lbl_88B7C858, lbl_88CD244C, lbl_880445A8, lbl_88CD247C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C858_88A2E590(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD247C, (ts4_word)(ts4_word)lbl_880445A8, (ts4_word)(ts4_word)lbl_88CD244C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C858, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E608: call_seq lbl_88B7C900, lbl_8804449C, lbl_88CD24AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C900_88A2E608(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD24AC, (ts4_word)(ts4_word)lbl_8804449C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C900, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E678: call_seq lbl_88B7C930, lbl_88CCF20C, lbl_88044744, lbl_88CD24DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C930_88A2E678(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD24DC, (ts4_word)(ts4_word)lbl_88044744, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C930, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E6F0: call_seq lbl_88B7C978, lbl_88CCF20C, lbl_88044758, lbl_88CD250C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C978_88A2E6F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD250C, (ts4_word)(ts4_word)lbl_88044758, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C978, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E768: call_seq lbl_88CCF20C, lbl_880447EC, lbl_88CD253C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCF20C_88A2E768(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD253C, (ts4_word)(ts4_word)lbl_880447EC, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E7D0: call_seq lbl_88B7C9C0, lbl_88CD253C, lbl_88044568, lbl_88CD256C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C9C0_88A2E7D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD256C, (ts4_word)(ts4_word)lbl_88044568, (ts4_word)(ts4_word)lbl_88CD253C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C9C0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E848: call_seq lbl_88B7CA08, lbl_88CCF20C, lbl_880447B8, lbl_88CD259C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7CA08_88A2E848(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD259C, (ts4_word)(ts4_word)lbl_880447B8, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7CA08, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E8C0: call_seq lbl_88B7CA20, lbl_88CCF20C, lbl_88044784, lbl_88CD25CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7CA20_88A2E8C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD25CC, (ts4_word)(ts4_word)lbl_88044784, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7CA20, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E938: call_seq lbl_88B7CA38, lbl_88CD259C, lbl_880444CC, lbl_88CD25FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7CA38_88A2E938(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD25FC, (ts4_word)(ts4_word)lbl_880444CC, (ts4_word)(ts4_word)lbl_88CD259C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7CA38, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2E9B0: call_seq lbl_88057280, lbl_88058480, lbl_88CD262C, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF5D8, fn_88563470 */
ts4_word ts4_call_seq_lbl_88057280_88A2E9B0(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CD262C, (ts4_word)(ts4_word)lbl_88058480, (ts4_word)4, (ts4_word)(ts4_word)lbl_88057280);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF5D8);
    return t2;
}

/* Swing_DLL.xex 0x88A2E9F8: call_seq lbl_88B7D938, lbl_88046C94, lbl_88CD2644, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7D938_88A2E9F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2644, (ts4_word)(ts4_word)lbl_88046C94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7D938, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2EA68: addr lbl_88B83D28, u32@lbl_88B7D9B0, u32@0x38 */
void ts4_addr_lbl_88B83D28_88A2EA68(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B83D28) + 56) = (ts4_word)(*(ts4_word *)lbl_88B7D9B0);
    return;
}

/* Swing_DLL.xex 0x88A2EA80: call_seq lbl_88058C84, lbl_88B83D28, lbl_8803EF04, lbl_88CD2674, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88058C84_88A2EA80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2674, (ts4_word)(ts4_word)lbl_8803EF04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88058C84, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B83D28, (ts4_word)3, (ts4_word)((ts4_word)lbl_88058C84 + 20), (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2EAF8: call_seq lbl_88B7D9B4, lbl_88046C78, lbl_88CD26A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7D9B4_88A2EAF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD26A4, (ts4_word)(ts4_word)lbl_88046C78, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7D9B4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2EB68: call_seq lbl_88B7D9E4, lbl_8803EC6C, lbl_88CD26D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7D9E4_88A2EB68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD26D4, (ts4_word)(ts4_word)lbl_8803EC6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7D9E4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2EBD8: call_seq lbl_88B7DA18, lbl_88CD3304, lbl_8803EE48, lbl_88CD2704, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7DA18_88A2EBD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2704, (ts4_word)(ts4_word)lbl_8803EE48, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7DA18, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2EC50: call_seq lbl_88B7DA78, lbl_88040040, lbl_88CD2734, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7DA78_88A2EC50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2734, (ts4_word)(ts4_word)lbl_88040040, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7DA78, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2ECC0: call_seq lbl_88B7DAF0, lbl_88CD2704, lbl_8803ECD0, lbl_88CD2764, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7DAF0_88A2ECC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2764, (ts4_word)(ts4_word)lbl_8803ECD0, (ts4_word)(ts4_word)lbl_88CD2704, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7DAF0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2ED38: call_seq lbl_88B7DB98, lbl_88CD2704, lbl_8803ECB0, lbl_88CD2794, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7DB98_88A2ED38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2794, (ts4_word)(ts4_word)lbl_8803ECB0, (ts4_word)(ts4_word)lbl_88CD2704, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7DB98, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2EDB0: call_seq lbl_88B7DBB0, lbl_88040078, lbl_88CD27C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7DBB0_88A2EDB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD27C4, (ts4_word)(ts4_word)lbl_88040078, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7DBB0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2EE20: call_seq lbl_88B7DC28, lbl_88CD2704, lbl_8803EC94, lbl_88CD27F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7DC28_88A2EE20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD27F4, (ts4_word)(ts4_word)lbl_8803EC94, (ts4_word)(ts4_word)lbl_88CD2704, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7DC28, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2EE98: call_seq lbl_88B7DCD0, lbl_88046C60, lbl_88CD2824, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7DCD0_88A2EE98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2824, (ts4_word)(ts4_word)lbl_88046C60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7DCD0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2EF08: call_seq lbl_88B7DCE8, lbl_8803EE88, lbl_88CD2854, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7DCE8_88A2EF08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2854, (ts4_word)(ts4_word)lbl_8803EE88, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7DCE8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2EF78: call_seq lbl_88B7DD48, lbl_88CD3304, lbl_8804002C, lbl_88CD2884, lbl_88058CC0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7DD48_88A2EF78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2884, (ts4_word)(ts4_word)lbl_8804002C, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88058CC0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7DD48, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2EFE8: call_seq lbl_88B7DD60, lbl_88046C00, lbl_88CD28B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7DD60_88A2EFE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD28B4, (ts4_word)(ts4_word)lbl_88046C00, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7DD60, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F058: call_seq lbl_88B7DDA8, lbl_88046C24, lbl_88CD28E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7DDA8_88A2F058(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD28E4, (ts4_word)(ts4_word)lbl_88046C24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7DDA8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F0C8: call_seq lbl_88B7DE38, lbl_88046C48, lbl_88CD2914, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7DE38_88A2F0C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2914, (ts4_word)(ts4_word)lbl_88046C48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7DE38, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F138: call_seq lbl_88CD3304, lbl_8803EC3C, lbl_88CD2944, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3304_88A2F138(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2944, (ts4_word)(ts4_word)lbl_8803EC3C, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F1A0: call_seq lbl_88B7DEC8, lbl_88CD2944, lbl_8803ECF4, lbl_88CD2974, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7DEC8_88A2F1A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2974, (ts4_word)(ts4_word)lbl_8803ECF4, (ts4_word)(ts4_word)lbl_88CD2944, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7DEC8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F218: call_seq lbl_88B7DF28, lbl_8803EEFC, lbl_88CD29A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7DF28_88A2F218(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD29A4, (ts4_word)(ts4_word)lbl_8803EEFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7DF28, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F288: call_seq lbl_88B7DF58, lbl_8803EEE8, lbl_88CD29D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7DF58_88A2F288(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD29D4, (ts4_word)(ts4_word)lbl_8803EEE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7DF58, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F2F8: call_seq lbl_88B7DFB8, lbl_8803EE7C, lbl_88CD2A04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7DFB8_88A2F2F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2A04, (ts4_word)(ts4_word)lbl_8803EE7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7DFB8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F368: call_seq lbl_88B7E018, lbl_88041578, lbl_88CD2A34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7E018_88A2F368(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2A34, (ts4_word)(ts4_word)lbl_88041578, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7E018, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F3D8: call_seq lbl_88B7E098, lbl_88042110, lbl_88CD2A64, lbl_88058CF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7E098_88A2F3D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2A64, (ts4_word)(ts4_word)lbl_88042110, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88058CF4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7E098, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F448: call_seq lbl_88B7E1A0, lbl_88058D08, lbl_880420FC, lbl_88CD2A94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7E1A0_88A2F448(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2A94, (ts4_word)(ts4_word)lbl_880420FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7E1A0, (ts4_word)11, (ts4_word)(ts4_word)lbl_88058D08, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F4C0: call_seq lbl_88B7E2A8, lbl_88041204, lbl_88CD2AC4, lbl_88058D4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7E2A8_88A2F4C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2AC4, (ts4_word)(ts4_word)lbl_88041204, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88058D4C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7E2A8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F530: call_seq lbl_88CD3094, lbl_88053DD8, lbl_88CD2AF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3094_88A2F530(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2AF4, (ts4_word)(ts4_word)lbl_88053DD8, (ts4_word)(ts4_word)lbl_88CD3094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F598: call_seq lbl_88058D60, lbl_88B7E2D8, lbl_88CD2AF4, lbl_88041268, lbl_88CD2B24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88058D60_88A2F598(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2B24, (ts4_word)(ts4_word)lbl_88041268, (ts4_word)(ts4_word)lbl_88CD2AF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7E2D8, (ts4_word)7, (ts4_word)(ts4_word)lbl_88058D60, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F610: call_seq lbl_88CD2B24, lbl_88053DE8, lbl_88CD2B54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD2B24_88A2F610(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2B54, (ts4_word)(ts4_word)lbl_88053DE8, (ts4_word)(ts4_word)lbl_88CD2B24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F678: call_seq lbl_88B7E380, lbl_88CD3304, lbl_8804124C, lbl_88CD2B84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7E380_88A2F678(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2B84, (ts4_word)(ts4_word)lbl_8804124C, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7E380, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F6F0: call_seq lbl_88058D8C, lbl_88B7E3C8, lbl_88CD2AF4, lbl_88041238, lbl_88CD2BB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88058D8C_88A2F6F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2BB4, (ts4_word)(ts4_word)lbl_88041238, (ts4_word)(ts4_word)lbl_88CD2AF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7E3C8, (ts4_word)8, (ts4_word)(ts4_word)lbl_88058D8C, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F768: call_seq lbl_88B7E488, lbl_8804115C, lbl_88CD2BE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7E488_88A2F768(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2BE4, (ts4_word)(ts4_word)lbl_8804115C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7E488, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F7D8: addr lbl_88B83D70, u32@lbl_88B7E4D0, u32@0x8 */
void ts4_addr_lbl_88B83D70_88A2F7D8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B83D70) + 8) = (ts4_word)(*(ts4_word *)lbl_88B7E4D0);
    return;
}

/* Swing_DLL.xex 0x88A2F868: call_seq lbl_88B7E4D4, lbl_88CD2AF4, lbl_88041584, lbl_88CD2C44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7E4D4_88A2F868(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2C44, (ts4_word)(ts4_word)lbl_88041584, (ts4_word)(ts4_word)lbl_88CD2AF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7E4D4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F8E0: call_seq lbl_88B7E504, lbl_88CD2AF4, lbl_88053E90, lbl_88CD2C74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7E504_88A2F8E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2C74, (ts4_word)(ts4_word)lbl_88053E90, (ts4_word)(ts4_word)lbl_88CD2AF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7E504, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F958: call_seq lbl_88CD3094, lbl_88053EAC, lbl_88CD2CA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3094_88A2F958(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2CA4, (ts4_word)(ts4_word)lbl_88053EAC, (ts4_word)(ts4_word)lbl_88CD3094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2F9C0: call_seq lbl_88B7E51C, lbl_88CD2CA4, lbl_88042128, lbl_88CD2CD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7E51C_88A2F9C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2CD4, (ts4_word)(ts4_word)lbl_88042128, (ts4_word)(ts4_word)lbl_88CD2CA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7E51C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2FA38: call_seq lbl_88B7E550, lbl_880420B8, lbl_88CD2D04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7E550_88A2FA38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2D04, (ts4_word)(ts4_word)lbl_880420B8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7E550, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2FAA8: call_seq lbl_88B7E5B0, lbl_880420E4, lbl_88CD2D34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7E5B0_88A2FAA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2D34, (ts4_word)(ts4_word)lbl_880420E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7E5B0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2FB18: call_seq lbl_88058E28, lbl_88B7E5E0, lbl_88CD2CA4, lbl_88041634, lbl_88CD2D64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88058E28_88A2FB18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2D64, (ts4_word)(ts4_word)lbl_88041634, (ts4_word)(ts4_word)lbl_88CD2CA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7E5E0, (ts4_word)16, (ts4_word)(ts4_word)lbl_88058E28, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2FB90: call_seq lbl_88B7E760, lbl_88CD2CA4, lbl_880420C8, lbl_88CD2D94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7E760_88A2FB90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2D94, (ts4_word)(ts4_word)lbl_880420C8, (ts4_word)(ts4_word)lbl_88CD2CA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7E760, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2FC08: call_seq lbl_88058E74, lbl_88B7E778, lbl_88CD2CA4, lbl_880411F0, lbl_88CD2DC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88058E74_88A2FC08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2DC4, (ts4_word)(ts4_word)lbl_880411F0, (ts4_word)(ts4_word)lbl_88CD2CA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7E778, (ts4_word)4, (ts4_word)(ts4_word)lbl_88058E74, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2FC80: call_seq lbl_88B7E7D8, lbl_88CD2CA4, lbl_880411C8, lbl_88CD2DF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7E7D8_88A2FC80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2DF4, (ts4_word)(ts4_word)lbl_880411C8, (ts4_word)(ts4_word)lbl_88CD2CA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7E7D8, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2FCF8: call_seq lbl_88B7E8B0, lbl_88CD2CA4, lbl_88048610, lbl_88CD2E24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7E8B0_88A2FCF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2E24, (ts4_word)(ts4_word)lbl_88048610, (ts4_word)(ts4_word)lbl_88CD2CA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7E8B0, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2FD70: call_seq lbl_88B7E9B8, lbl_88CD2CA4, lbl_88042140, lbl_88CD2E54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7E9B8_88A2FD70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2E54, (ts4_word)(ts4_word)lbl_88042140, (ts4_word)(ts4_word)lbl_88CD2CA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7E9B8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2FDE8: addr lbl_88B83ED8, u32@lbl_88B7E54C, u32@0x68 */
void ts4_addr_lbl_88B83ED8_88A2FDE8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B83ED8) + 104) = (ts4_word)(*(ts4_word *)lbl_88B7E54C);
    return;
}

/* Swing_DLL.xex 0x88A2FE78: call_seq lbl_88058F14, lbl_88B7E9E8, lbl_88CD3304, lbl_88053F68, lbl_88CD2EB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88058F14_88A2FE78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2EB4, (ts4_word)(ts4_word)lbl_88053F68, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7E9E8, (ts4_word)2, (ts4_word)(ts4_word)lbl_88058F14, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2FEF0: call_seq lbl_88B7EA18, lbl_88042098, lbl_88CD2EE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7EA18_88A2FEF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2EE4, (ts4_word)(ts4_word)lbl_88042098, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7EA18, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2FF60: addr lbl_88B84070, u32@lbl_88B7EAA8, u32@0x50 */
void ts4_addr_lbl_88B84070_88A2FF60(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B84070) + 80) = (ts4_word)(*(ts4_word *)lbl_88B7EAA8);
    return;
}

/* Swing_DLL.xex 0x88A2FFF0: call_seq lbl_88B7EAAC, lbl_88CD2CA4, lbl_88042074, lbl_88CD2F44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7EAAC_88A2FFF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2F44, (ts4_word)(ts4_word)lbl_88042074, (ts4_word)(ts4_word)lbl_88CD2CA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7EAAC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30068: call_seq lbl_88058F80, lbl_88B7EAE0, lbl_88CD2CA4, lbl_88041618, lbl_88CD2F74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88058F80_88A30068(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2F74, (ts4_word)(ts4_word)lbl_88041618, (ts4_word)(ts4_word)lbl_88CD2CA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7EAE0, (ts4_word)6, (ts4_word)(ts4_word)lbl_88058F80, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A300E0: call_seq lbl_88B7EB70, lbl_880415F8, lbl_88CD2FA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7EB70_88A300E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2FA4, (ts4_word)(ts4_word)lbl_880415F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7EB70, (ts4_word)14, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30150: call_seq lbl_88058FA4, lbl_88B7ECC0, lbl_88CD2CA4, lbl_88040228, lbl_88CD2FD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88058FA4_88A30150(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD2FD4, (ts4_word)(ts4_word)lbl_88040228, (ts4_word)(ts4_word)lbl_88CD2CA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7ECC0, (ts4_word)8, (ts4_word)(ts4_word)lbl_88058FA4, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A301C8: call_seq lbl_88B7ED80, lbl_88CD2CA4, lbl_880415D4, lbl_88CD3004, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7ED80_88A301C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3004, (ts4_word)(ts4_word)lbl_880415D4, (ts4_word)(ts4_word)lbl_88CD2CA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7ED80, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30240: call_seq lbl_88B7ED98, lbl_88CD2DF4, lbl_880411DC, lbl_88CD3034, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7ED98_88A30240(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3034, (ts4_word)(ts4_word)lbl_880411DC, (ts4_word)(ts4_word)lbl_88CD2DF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7ED98, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A302B8: call_seq lbl_88B7EE28, lbl_88CD2CA4, lbl_8805704C, lbl_88CD3064, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7EE28_88A302B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3064, (ts4_word)(ts4_word)lbl_8805704C, (ts4_word)(ts4_word)lbl_88CD2CA4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7EE28, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30330: call_seq lbl_88B7EE40, lbl_88CD3304, lbl_8804116C, lbl_88CD3094, lbl_88058FEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7EE40_88A30330(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3094, (ts4_word)(ts4_word)lbl_8804116C, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88058FEC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7EE40, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A303A0: call_seq lbl_88CD3304, lbl_88058A10, lbl_88CD30C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3304_88A303A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD30C4, (ts4_word)(ts4_word)lbl_88058A10, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30408: call_seq lbl_88B7EE58, lbl_88CD30C4, lbl_88058A20, lbl_88CD30F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7EE58_88A30408(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD30F4, (ts4_word)(ts4_word)lbl_88058A20, (ts4_word)(ts4_word)lbl_88CD30C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7EE58, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30480: call_seq lbl_88B7EE70, lbl_8804205C, lbl_88CD3124, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7EE70_88A30480(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3124, (ts4_word)(ts4_word)lbl_8804205C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7EE70, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A304F0: call_seq lbl_88059058, lbl_88B7EED8, lbl_88041174, lbl_88CD3154, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88059058_88A304F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3154, (ts4_word)(ts4_word)lbl_88041174, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059058, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7EED8, (ts4_word)8, (ts4_word)((ts4_word)lbl_88059058 + 20), (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30568: call_seq lbl_88B7EF98, lbl_88041194, lbl_88CD3184, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7EF98_88A30568(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3184, (ts4_word)(ts4_word)lbl_88041194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7EF98, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A305D8: call_seq lbl_88059090, lbl_88B7EFE0, lbl_88CD2AF4, lbl_88040218, lbl_88CD31B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88059090_88A305D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD31B4, (ts4_word)(ts4_word)lbl_88040218, (ts4_word)(ts4_word)lbl_88CD2AF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7EFE0, (ts4_word)16, (ts4_word)(ts4_word)lbl_88059090, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30650: call_seq lbl_88CD2AF4, lbl_88041114, lbl_88CD31E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD2AF4_88A30650(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD31E4, (ts4_word)(ts4_word)lbl_88041114, (ts4_word)(ts4_word)lbl_88CD2AF4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A306B8: addr lbl_88B84178, u32@lbl_88B7F160, u32@0x50 */
void ts4_addr_lbl_88B84178_88A306B8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B84178) + 80) = (ts4_word)(*(ts4_word *)lbl_88B7F160);
    return;
}

/* Swing_DLL.xex 0x88A30748: call_seq lbl_88B7F168, lbl_8805919C, lbl_88040200, lbl_88CD3244, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F168_88A30748(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3244, (ts4_word)(ts4_word)lbl_88040200, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F168, (ts4_word)4, (ts4_word)(ts4_word)lbl_8805919C, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A307C0: call_seq lbl_88B7F1C8, lbl_880401D8, lbl_88CD3274, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F1C8_88A307C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3274, (ts4_word)(ts4_word)lbl_880401D8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F1C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30830: call_seq lbl_88B7F1F8, lbl_88CD3304, lbl_880401F0, lbl_88CD32A4, lbl_88059188, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F1F8_88A30830(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD32A4, (ts4_word)(ts4_word)lbl_880401F0, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059188, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7F1F8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A308A0: call_seq lbl_8803C97C, lbl_88CD32D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803C97C_88A308A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD32D4, (ts4_word)(ts4_word)lbl_8803C97C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30900: call_seq lbl_88B7F210, lbl_88CD32D4, lbl_8803C9DC, lbl_88CD3304, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F210_88A30900(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)(ts4_word)lbl_8803C9DC, (ts4_word)(ts4_word)lbl_88CD32D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F210, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30978: call_seq lbl_88B7F248, lbl_8803CC5C, lbl_88CD3334, lbl_880591B8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F248_88A30978(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3334, (ts4_word)(ts4_word)lbl_8803CC5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880591B8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7F248, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A309E8: call_seq lbl_88B7F2F0, lbl_8803CCC4, lbl_88CD3364, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F2F0_88A309E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3364, (ts4_word)(ts4_word)lbl_8803CCC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F2F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30A58: call_seq lbl_88B7F320, lbl_8803CCD4, lbl_88CD3394, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F320_88A30A58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3394, (ts4_word)(ts4_word)lbl_8803CCD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F320, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30AC8: addr lbl_88B84298, u32@lbl_88B7F244, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88B84298_88A30AC8(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B7F244;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B84298) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B84298) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A30AE8: call_seq lbl_88B84298, lbl_8803D124, lbl_88CD33C4, lbl_88059330, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B84298_88A30AE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD33C4, (ts4_word)(ts4_word)lbl_8803D124, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059330, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B84298, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30B58: call_seq lbl_88B7F358, lbl_8803D484, lbl_88CD33F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F358_88A30B58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD33F4, (ts4_word)(ts4_word)lbl_8803D484, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F358, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30BC8: call_seq lbl_88B7F388, lbl_8803D4A8, lbl_88CD3424, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F388_88A30BC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3424, (ts4_word)(ts4_word)lbl_8803D4A8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F388, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30C38: addr lbl_88B84358, u32@lbl_88B7F3A0, u32@0x50 */
void ts4_addr_lbl_88B84358_88A30C38(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B84358) + 80) = (ts4_word)(*(ts4_word *)lbl_88B7F3A0);
    return;
}

/* Swing_DLL.xex 0x88A30C50: call_seq lbl_88B84358, lbl_8803D4C4, lbl_88CD3454, lbl_88059384, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B84358_88A30C50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3454, (ts4_word)(ts4_word)lbl_8803D4C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059384, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B84358, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30CC0: call_seq lbl_88B7F3B0, lbl_8803F9C0, lbl_88CD3484, lbl_880593C0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F3B0_88A30CC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3484, (ts4_word)(ts4_word)lbl_8803F9C0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880593C0, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B7F3B0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30D30: call_seq lbl_88B7F3F8, lbl_8803CAF0, lbl_88CD34B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F3F8_88A30D30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD34B4, (ts4_word)(ts4_word)lbl_8803CAF0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F3F8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30DA0: call_seq lbl_88B7F428, lbl_8803D194, lbl_88CD34E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F428_88A30DA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD34E4, (ts4_word)(ts4_word)lbl_8803D194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F428, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30E10: call_seq lbl_88B7F458, lbl_8803D2E0, lbl_88CD3514, lbl_880593F8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F458_88A30E10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3514, (ts4_word)(ts4_word)lbl_8803D2E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880593F8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7F458, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30E80: call_seq lbl_88B7F4B8, lbl_8803D6A0, lbl_88CD3544, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F4B8_88A30E80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3544, (ts4_word)(ts4_word)lbl_8803D6A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F4B8, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30EF0: call_seq lbl_88B7F5A8, lbl_8803D914, lbl_88CD3574, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F5A8_88A30EF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3574, (ts4_word)(ts4_word)lbl_8803D914, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F5A8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30F60: call_seq lbl_88B7F5C0, lbl_8803D9E8, lbl_88CD35A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F5C0_88A30F60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD35A4, (ts4_word)(ts4_word)lbl_8803D9E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F5C0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A30FD0: addr lbl_88B843E8, u32@lbl_88B7F650, u32@0x20 */
void ts4_addr_lbl_88B843E8_88A30FD0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B843E8) + 32) = (ts4_word)(*(ts4_word *)lbl_88B7F650);
    return;
}

/* Swing_DLL.xex 0x88A30FE8: call_seq lbl_88B843E8, lbl_8803F988, lbl_88CD35D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B843E8_88A30FE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD35D4, (ts4_word)(ts4_word)lbl_8803F988, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B843E8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31058: addr lbl_88B84418, u32@lbl_88B7F650, u32@0x20 */
void ts4_addr_lbl_88B84418_88A31058(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B84418) + 32) = (ts4_word)(*(ts4_word *)lbl_88B7F650);
    return;
}

/* Swing_DLL.xex 0x88A31070: call_seq lbl_88B84418, lbl_8803F974, lbl_88CD3604, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B84418_88A31070(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3604, (ts4_word)(ts4_word)lbl_8803F974, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B84418, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A310E0: call_seq lbl_88B7F638, lbl_8804E4DC, lbl_88CD3634, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F638_88A310E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3634, (ts4_word)(ts4_word)lbl_8804E4DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F638, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31150: addr lbl_88B84448, u32@lbl_88B7F650, u32@0x20 */
void ts4_addr_lbl_88B84448_88A31150(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B84448) + 32) = (ts4_word)(*(ts4_word *)lbl_88B7F650);
    return;
}

/* Swing_DLL.xex 0x88A31168: call_seq lbl_88B84448, lbl_8803F960, lbl_88CD3664, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B84448_88A31168(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3664, (ts4_word)(ts4_word)lbl_8803F960, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B84448, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A311D8: call_seq lbl_88B7F654, lbl_8803F9B0, lbl_88CD3694, lbl_8805943C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F654_88A311D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3694, (ts4_word)(ts4_word)lbl_8803F9B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805943C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7F654, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31248: call_seq lbl_88B7F684, lbl_8803F99C, lbl_88CD36C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F684_88A31248(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD36C4, (ts4_word)(ts4_word)lbl_8803F99C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F684, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A312B8: call_seq lbl_88B7F6B4, lbl_8804E4F4, lbl_88CD36F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F6B4_88A312B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD36F4, (ts4_word)(ts4_word)lbl_8804E4F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F6B4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31328: call_seq lbl_88B7F6E4, lbl_88CD3754, lbl_8804E50C, lbl_88CD3724, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F6E4_88A31328(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3724, (ts4_word)(ts4_word)lbl_8804E50C, (ts4_word)(ts4_word)lbl_88CD3754, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F6E4, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A313A0: call_seq lbl_88B7F6FC, lbl_8804E524, lbl_88CD3754, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F6FC_88A313A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3754, (ts4_word)(ts4_word)lbl_8804E524, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F6FC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31410: call_seq lbl_88B7F72C, lbl_8804E53C, lbl_88CD3784, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F72C_88A31410(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3784, (ts4_word)(ts4_word)lbl_8804E53C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F72C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31480: call_seq lbl_88B7F744, lbl_8804E560, lbl_88CD37B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F744_88A31480(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD37B4, (ts4_word)(ts4_word)lbl_8804E560, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F744, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A314F0: call_seq lbl_88B7F778, lbl_8803F5C8, lbl_88CD37E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F778_88A314F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD37E4, (ts4_word)(ts4_word)lbl_8803F5C8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F778, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31560: call_seq lbl_88B7F820, lbl_88054050, lbl_88CD3814, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F820_88A31560(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3814, (ts4_word)(ts4_word)lbl_88054050, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F820, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A315D0: call_seq lbl_88B7F850, lbl_88054068, lbl_88CD3844, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F850_88A315D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3844, (ts4_word)(ts4_word)lbl_88054068, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F850, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31640: call_seq lbl_88B7F868, lbl_8804C310, lbl_88CD3874, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F868_88A31640(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3874, (ts4_word)(ts4_word)lbl_8804C310, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F868, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A316B0: call_seq lbl_88B7F898, lbl_8803ED20, lbl_88CD38A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F898_88A316B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD38A4, (ts4_word)(ts4_word)lbl_8803ED20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F898, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31720: addr lbl_88B84478, u32@lbl_88B7F774, u32@0x8 */
void ts4_addr_lbl_88B84478_88A31720(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B84478) + 8) = (ts4_word)(*(ts4_word *)lbl_88B7F774);
    return;
}

/* Swing_DLL.xex 0x88A31738: call_seq lbl_88B84478, lbl_8804C33C, lbl_88CD38D4, lbl_88059468, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B84478_88A31738(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD38D4, (ts4_word)(ts4_word)lbl_8804C33C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059468, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B84478, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A317A8: call_seq lbl_88B7F95C, lbl_8803ED28, lbl_88CD3904, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F95C_88A317A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3904, (ts4_word)(ts4_word)lbl_8803ED28, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7F95C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31818: call_seq lbl_88B7F990, lbl_8803ED14, lbl_88CD3934, lbl_880594AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7F990_88A31818(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3934, (ts4_word)(ts4_word)lbl_8803ED14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880594AC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7F990, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31888: addr lbl_88B844F0, u32@lbl_88B7F98C, u32@0x20 */
void ts4_addr_lbl_88B844F0_88A31888(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B844F0) + 32) = (ts4_word)(*(ts4_word *)lbl_88B7F98C);
    return;
}

/* Swing_DLL.xex 0x88A318A0: call_seq lbl_88B844F0, lbl_8804E57C, lbl_88CD3964, lbl_880594E8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B844F0_88A318A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3964, (ts4_word)(ts4_word)lbl_8804E57C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880594E8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B844F0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31910: call_seq lbl_88B7FA50, lbl_8804C348, lbl_88CD3994, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7FA50_88A31910(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3994, (ts4_word)(ts4_word)lbl_8804C348, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7FA50, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31980: call_seq lbl_88B7FA68, lbl_8804C358, lbl_88CD39C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7FA68_88A31980(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD39C4, (ts4_word)(ts4_word)lbl_8804C358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7FA68, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A319F0: addr lbl_88B84538, u32@lbl_88B7FA98, u32@0x8 */
void ts4_addr_lbl_88B84538_88A319F0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B84538) + 8) = (ts4_word)(*(ts4_word *)lbl_88B7FA98);
    return;
}

/* Swing_DLL.xex 0x88A31A08: call_seq lbl_88B84538, lbl_8804C380, lbl_88CD39F4, lbl_88059524, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B84538_88A31A08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD39F4, (ts4_word)(ts4_word)lbl_8804C380, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88059524, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B84538, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31A78: call_seq lbl_88B7FA9C, lbl_88042408, lbl_88CD3A24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7FA9C_88A31A78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3A24, (ts4_word)(ts4_word)lbl_88042408, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7FA9C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31AE8: call_seq lbl_88B7FAB8, lbl_880423F8, lbl_88CD3A54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7FAB8_88A31AE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3A54, (ts4_word)(ts4_word)lbl_880423F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7FAB8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31B58: call_seq lbl_88B7FB00, lbl_8804C390, lbl_88CD3A84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7FB00_88A31B58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3A84, (ts4_word)(ts4_word)lbl_8804C390, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7FB00, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31BC8: call_seq lbl_88B7FB30, lbl_8804C3A0, lbl_88CD3AB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7FB30_88A31BC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3AB4, (ts4_word)(ts4_word)lbl_8804C3A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7FB30, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31C38: call_seq lbl_88B7FC50, lbl_8804C3B0, lbl_88CD3AE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7FC50_88A31C38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3AE4, (ts4_word)(ts4_word)lbl_8804C3B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7FC50, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31CA8: call_seq lbl_88B7FCE0, lbl_8804C3C4, lbl_88CD3B14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7FCE0_88A31CA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3B14, (ts4_word)(ts4_word)lbl_8804C3C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7FCE0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31D18: call_seq lbl_88B7FDA0, lbl_8804C3DC, lbl_88CD3B44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7FDA0_88A31D18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3B44, (ts4_word)(ts4_word)lbl_8804C3DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7FDA0, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31D88: call_seq lbl_88B7FE78, lbl_8804C3F8, lbl_88CD3B74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7FE78_88A31D88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3B74, (ts4_word)(ts4_word)lbl_8804C3F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7FE78, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31DF8: call_seq lbl_88B7FF38, lbl_8804C410, lbl_88CD3BA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7FF38_88A31DF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3BA4, (ts4_word)(ts4_word)lbl_8804C410, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7FF38, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31E68: call_seq lbl_88B7FFE0, lbl_88059538, lbl_8803F5BC, lbl_88CD3BD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7FFE0_88A31E68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3BD4, (ts4_word)(ts4_word)lbl_8803F5BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7FFE0, (ts4_word)12, (ts4_word)(ts4_word)lbl_88059538, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31EE0: call_seq lbl_88B80100, lbl_8804C428, lbl_88CD3C04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80100_88A31EE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3C04, (ts4_word)(ts4_word)lbl_8804C428, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80100, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31F50: call_seq lbl_88B80160, lbl_8803F5E0, lbl_88CD3C34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80160_88A31F50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3C34, (ts4_word)(ts4_word)lbl_8803F5E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80160, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A31FC0: call_seq lbl_88B80268, lbl_88040278, lbl_88CD3C64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80268_88A31FC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3C64, (ts4_word)(ts4_word)lbl_88040278, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80268, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32030: call_seq lbl_88B80340, lbl_8803ED58, lbl_88CD3C94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80340_88A32030(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3C94, (ts4_word)(ts4_word)lbl_8803ED58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80340, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A320A0: call_seq lbl_88B80388, lbl_8803ED40, lbl_88CD3CC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80388_88A320A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3CC4, (ts4_word)(ts4_word)lbl_8803ED40, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80388, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32110: call_seq lbl_88B803A0, lbl_880433FC, lbl_88CD3CF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B803A0_88A32110(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3CF4, (ts4_word)(ts4_word)lbl_880433FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B803A0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32180: call_seq lbl_88B803E8, lbl_8804342C, lbl_88CD3D24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B803E8_88A32180(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3D24, (ts4_word)(ts4_word)lbl_8804342C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B803E8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A321F0: call_seq lbl_88B80400, lbl_88CD3304, lbl_8803ED7C, lbl_88CD3D54, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80400_88A321F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3D54, (ts4_word)(ts4_word)lbl_8803ED7C, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80400, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32268: call_seq lbl_88B80448, lbl_88046454, lbl_88CD3D84, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80448_88A32268(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3D84, (ts4_word)(ts4_word)lbl_88046454, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80448, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A322D8: call_seq lbl_88B804A8, lbl_88CD3D84, lbl_8804233C, lbl_88CD3DB4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B804A8_88A322D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3DB4, (ts4_word)(ts4_word)lbl_8804233C, (ts4_word)(ts4_word)lbl_88CD3D84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B804A8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32350: call_seq lbl_880469C4, lbl_88CD3DE4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880469C4_88A32350(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3DE4, (ts4_word)(ts4_word)lbl_880469C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A323B0: call_seq lbl_88B804F0, lbl_88CD5AC4, lbl_88042E48, lbl_88CD3E14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B804F0_88A323B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3E14, (ts4_word)(ts4_word)lbl_88042E48, (ts4_word)(ts4_word)lbl_88CD5AC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B804F0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32428: call_seq lbl_88046B60, lbl_88CD3E44, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046B60_88A32428(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3E44, (ts4_word)(ts4_word)lbl_88046B60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32488: call_seq lbl_88CD3304, lbl_88042318, lbl_88CD3E74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3304_88A32488(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3E74, (ts4_word)(ts4_word)lbl_88042318, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A324F0: call_seq lbl_88046A84, lbl_88CD3EA4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A84_88A324F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3EA4, (ts4_word)(ts4_word)lbl_88046A84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32550: call_seq lbl_88B80550, lbl_88CD3E74, lbl_8804232C, lbl_88CD3ED4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80550_88A32550(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3ED4, (ts4_word)(ts4_word)lbl_8804232C, (ts4_word)(ts4_word)lbl_88CD3E74, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80550, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A325C8: call_seq lbl_88B80580, lbl_88CD3E74, lbl_8804690C, lbl_88CD3F04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80580_88A325C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3F04, (ts4_word)(ts4_word)lbl_8804690C, (ts4_word)(ts4_word)lbl_88CD3E74, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80580, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32640: call_seq lbl_88CD3E74, lbl_8804671C, lbl_88CD3F34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3E74_88A32640(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3F34, (ts4_word)(ts4_word)lbl_8804671C, (ts4_word)(ts4_word)lbl_88CD3E74, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A326A8: call_seq lbl_88046A50, lbl_88CD3F64, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A50_88A326A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3F64, (ts4_word)(ts4_word)lbl_88046A50, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32708: call_seq lbl_88B80598, lbl_88CD3304, lbl_88041284, lbl_88CD3F94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80598_88A32708(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3F94, (ts4_word)(ts4_word)lbl_88041284, (ts4_word)(ts4_word)lbl_88CD3304, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80598, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32780: call_seq lbl_88046994, lbl_88CD3FC4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046994_88A32780(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3FC4, (ts4_word)(ts4_word)lbl_88046994, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A327E0: call_seq lbl_88B805B0, lbl_88CD3FC4, lbl_88046678, lbl_88CD3FF4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B805B0_88A327E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD3FF4, (ts4_word)(ts4_word)lbl_88046678, (ts4_word)(ts4_word)lbl_88CD3FC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B805B0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32858: call_seq lbl_88B805C8, lbl_88046220, lbl_88CD4024, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B805C8_88A32858(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4024, (ts4_word)(ts4_word)lbl_88046220, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B805C8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A328C8: call_seq lbl_88B80628, lbl_88CD4144, lbl_8804694C, lbl_88CD4054, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80628_88A328C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4054, (ts4_word)(ts4_word)lbl_8804694C, (ts4_word)(ts4_word)lbl_88CD4144, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80628, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32940: call_seq lbl_88B80640, lbl_88CD3F94, lbl_88040110, lbl_88CD4084, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80640_88A32940(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4084, (ts4_word)(ts4_word)lbl_88040110, (ts4_word)(ts4_word)lbl_88CD3F94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80640, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A329B8: call_seq lbl_88B80670, lbl_88CD3F94, lbl_88040100, lbl_88CD40B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80670_88A329B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD40B4, (ts4_word)(ts4_word)lbl_88040100, (ts4_word)(ts4_word)lbl_88CD3F94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80670, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32A30: call_seq lbl_88B80688, lbl_88CD4144, lbl_8804011C, lbl_88CD40E4, lbl_880595B0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80688_88A32A30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD40E4, (ts4_word)(ts4_word)lbl_8804011C, (ts4_word)(ts4_word)lbl_88CD4144, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880595B0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B80688, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32AA8: call_seq lbl_88B806B8, lbl_88CD3F94, lbl_880400A8, lbl_88CD4114, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B806B8_88A32AA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4114, (ts4_word)(ts4_word)lbl_880400A8, (ts4_word)(ts4_word)lbl_88CD3F94, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B806B8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32B20: call_seq lbl_88B806D0, lbl_88CD45F4, lbl_88042370, lbl_88CD4144, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B806D0_88A32B20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4144, (ts4_word)(ts4_word)lbl_88042370, (ts4_word)(ts4_word)lbl_88CD45F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B806D0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32B98: call_seq lbl_88B806E8, lbl_88CD4354, lbl_88041B24, lbl_88CD4174, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B806E8_88A32B98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4174, (ts4_word)(ts4_word)lbl_88041B24, (ts4_word)(ts4_word)lbl_88CD4354, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B806E8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32C10: call_seq lbl_88B80700, lbl_88CD4114, lbl_880468C8, lbl_88CD41A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80700_88A32C10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD41A4, (ts4_word)(ts4_word)lbl_880468C8, (ts4_word)(ts4_word)lbl_88CD4114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80700, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32C88: call_seq lbl_88B80748, lbl_88CD4144, lbl_880400E8, lbl_88CD41D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80748_88A32C88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD41D4, (ts4_word)(ts4_word)lbl_880400E8, (ts4_word)(ts4_word)lbl_88CD4144, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80748, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32D00: call_seq lbl_88B80778, lbl_88CD4144, lbl_880400D0, lbl_88CD4204, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80778_88A32D00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4204, (ts4_word)(ts4_word)lbl_880400D0, (ts4_word)(ts4_word)lbl_88CD4144, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80778, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32D78: call_seq lbl_88B807A8, lbl_880463D4, lbl_88CD4234, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B807A8_88A32D78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4234, (ts4_word)(ts4_word)lbl_880463D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B807A8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32DE8: call_seq lbl_88B807F0, lbl_88CD4144, lbl_88046868, lbl_88CD4264, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B807F0_88A32DE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4264, (ts4_word)(ts4_word)lbl_88046868, (ts4_word)(ts4_word)lbl_88CD4144, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B807F0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32ED8: call_seq lbl_88CD43E4, lbl_880467DC, lbl_88CD42C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD43E4_88A32ED8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD42C4, (ts4_word)(ts4_word)lbl_880467DC, (ts4_word)(ts4_word)lbl_88CD43E4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32F40: call_seq lbl_88CD3F94, lbl_88046AE0, lbl_88CD42F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3F94_88A32F40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD42F4, (ts4_word)(ts4_word)lbl_88046AE0, (ts4_word)(ts4_word)lbl_88CD3F94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A32FA8: call_seq lbl_88B80900, lbl_88042358, lbl_88CD4324, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80900_88A32FA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4324, (ts4_word)(ts4_word)lbl_88042358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80900, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33018: call_seq lbl_88B80930, lbl_88CD4114, lbl_8804234C, lbl_88CD4354, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80930_88A33018(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4354, (ts4_word)(ts4_word)lbl_8804234C, (ts4_word)(ts4_word)lbl_88CD4114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80930, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33090: call_seq lbl_88B80948, lbl_88046320, lbl_88CD4384, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80948_88A33090(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4384, (ts4_word)(ts4_word)lbl_88046320, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80948, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33100: addr lbl_88B845B0, u32@lbl_88B8086C, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88B845B0_88A33100(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B8086C;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B845B0) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B845B0) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A33120: call_seq lbl_88B845B0, lbl_8803EFE8, lbl_88CD43B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B845B0_88A33120(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD43B4, (ts4_word)(ts4_word)lbl_8803EFE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B845B0, (ts4_word)13, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33190: call_seq lbl_88B80968, lbl_88CD4114, lbl_8803EF9C, lbl_88CD43E4, lbl_8805965C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80968_88A33190(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD43E4, (ts4_word)(ts4_word)lbl_8803EF9C, (ts4_word)(ts4_word)lbl_88CD4114, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805965C, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B80968, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33208: call_seq lbl_88B809E0, lbl_88CD40B4, lbl_880423C0, lbl_88CD4414, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B809E0_88A33208(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4414, (ts4_word)(ts4_word)lbl_880423C0, (ts4_word)(ts4_word)lbl_88CD40B4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B809E0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33280: call_seq lbl_88B809F8, lbl_880462E8, lbl_88CD4444, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B809F8_88A33280(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4444, (ts4_word)(ts4_word)lbl_880462E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B809F8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A332F0: call_seq lbl_88B80A28, lbl_88CD3F94, lbl_8804675C, lbl_88CD4474, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80A28_88A332F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4474, (ts4_word)(ts4_word)lbl_8804675C, (ts4_word)(ts4_word)lbl_88CD3F94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80A28, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33368: call_seq lbl_88B80A58, lbl_88CD45F4, lbl_8803F9D4, lbl_88CD44A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80A58_88A33368(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD44A4, (ts4_word)(ts4_word)lbl_8803F9D4, (ts4_word)(ts4_word)lbl_88CD45F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80A58, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A333E0: call_seq lbl_88CD3F94, lbl_88046AB4, lbl_88CD44D4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD3F94_88A333E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD44D4, (ts4_word)(ts4_word)lbl_88046AB4, (ts4_word)(ts4_word)lbl_88CD3F94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33448: call_seq lbl_88B80A88, lbl_88CD42F4, lbl_880466D4, lbl_88CD4504, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80A88_88A33448(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4504, (ts4_word)(ts4_word)lbl_880466D4, (ts4_word)(ts4_word)lbl_88CD42F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80A88, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A334C0: call_seq lbl_88B80AD0, lbl_88CD42F4, lbl_88046A18, lbl_88CD4534, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80AD0_88A334C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4534, (ts4_word)(ts4_word)lbl_88046A18, (ts4_word)(ts4_word)lbl_88CD42F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80AD0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A33538: call_seq lbl_88B80B78, lbl_880423A4, lbl_88CD4564, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B80B78_88A33538(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD4564, (ts4_word)(ts4_word)lbl_880423A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B80B78, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}
