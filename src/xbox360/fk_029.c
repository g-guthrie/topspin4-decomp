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

extern char __imp_XboxHardwareInfo[];
extern char ts4_get_u32_lbl_88D48854_88AFF0C8[];
extern char ts4_call_seq_lbl_88C6C278_88AFF0D8[];
extern char ts4_call_seq_lbl_88C6C28C_88AFF128[];
extern char ts4_call_seq_lbl_88C6C2A0_88AFF178[];
extern char ts4_call_seq_lbl_88C6C2C4_88AFF1C8[];
extern char ts4_call_seq_lbl_88C6C300_88AFF218[];
extern char ts4_addr_lbl_88C6C3E8_88AFF2B8[];
extern char ts4_addr_lbl_88C6C6AC_88AFF2D0[];
extern char fn_88AFF328[];
extern char ts4_addr_lbl_880D19F0_88AFF390[];
extern char ts4_tailcall_fn_88224B38_88AFF3D0[];
extern char ts4_call_seq_lbl_88C6E268_88AFF458[];
extern char ts4_addr_lbl_88C74928_88AFF4B8[];
extern char ts4_get_u32_lbl_88CACF08_88AFF4C8[];
extern char ts4_get_u32_lbl_88CAD338_88AFF4D8[];
extern char lbl_8803A3E0[];
extern char lbl_8803A45C[];
extern char lbl_8803A580[];
extern char lbl_8803A610[];
extern char lbl_8803A87C[];
extern char lbl_8803A8B4[];
extern char lbl_8803A8EC[];
extern char lbl_8803A954[];
extern char lbl_8803AC80[];
extern char lbl_8803ACA8[];
extern char lbl_8803ACD8[];
extern char lbl_8803AE48[];
extern char lbl_8803AEC8[];
extern char lbl_8803AF00[];
extern char lbl_8803AFD0[];
extern char lbl_8803B0C0[];
extern char lbl_8803B150[];
extern char lbl_8803B27C[];
extern char lbl_8803B2AC[];
extern char lbl_8803B2DC[];
extern char lbl_8803B374[];
extern char lbl_8803B388[];
extern char lbl_8803B3D8[];
extern char lbl_8803B450[];
extern char lbl_8803B47C[];
extern char lbl_8803B4AC[];
extern char lbl_8803B4DC[];
extern char lbl_8803B4FC[];
extern char lbl_8803B520[];
extern char lbl_8803B550[];
extern char lbl_8803B588[];
extern char lbl_8803B5E8[];
extern char lbl_8803B638[];
extern char lbl_8803B650[];
extern char lbl_8803B6B0[];
extern char lbl_8803B6C8[];
extern char lbl_8803B710[];
extern char lbl_8803B788[];
extern char lbl_8803B870[];
extern char lbl_8803B8B8[];
extern char lbl_8803B948[];
extern char lbl_8803B9D8[];
extern char lbl_8803B9FC[];
extern char lbl_8803BA20[];
extern char lbl_8803BA38[];
extern char lbl_8803BB40[];
extern char lbl_8803BBA4[];
extern char lbl_8803C410[];
extern char lbl_8803C484[];
extern char lbl_8803C698[];
extern char lbl_8803C814[];
extern char lbl_8803C83C[];
extern char lbl_8803C97C[];
extern char lbl_8803C9AC[];
extern char lbl_8803C9DC[];
extern char lbl_8803CA30[];
extern char lbl_8803CA60[];
extern char lbl_8803CAF0[];
extern char lbl_8803CAF8[];
extern char lbl_8803CB20[];
extern char lbl_8803CB50[];
extern char lbl_8803CC34[];
extern char lbl_8803CC5C[];
extern char lbl_8803CC80[];
extern char lbl_8803CC94[];
extern char lbl_8803CCC4[];
extern char lbl_8803CCD4[];
extern char lbl_8803D0E8[];
extern char lbl_8803D124[];
extern char lbl_8803D164[];
extern char lbl_8803D194[];
extern char lbl_8803D250[];
extern char lbl_8803D268[];
extern char lbl_8803D2E0[];
extern char lbl_8803D2F8[];
extern char lbl_8803D328[];
extern char lbl_8803D340[];
extern char lbl_8803D35C[];
extern char lbl_8803D410[];
extern char lbl_8803D440[];
extern char lbl_8803D470[];
extern char lbl_8803D484[];
extern char lbl_8803D4A8[];
extern char lbl_8803D4C4[];
extern char lbl_8803D5C8[];
extern char lbl_8803D6A0[];
extern char lbl_8803D760[];
extern char lbl_8803D788[];
extern char lbl_8803D7D0[];
extern char lbl_8803D808[];
extern char lbl_8803D868[];
extern char lbl_8803D8C8[];
extern char lbl_8803D8E0[];
extern char lbl_8803D8FC[];
extern char lbl_8803D914[];
extern char lbl_8803D970[];
extern char lbl_8803D9E8[];
extern char lbl_8803EC58[];
extern char lbl_8803EC80[];
extern char lbl_8803ED14[];
extern char lbl_8803ED20[];
extern char lbl_8803ED28[];
extern char lbl_8803ED40[];
extern char lbl_8803ED58[];
extern char lbl_8803ED90[];
extern char lbl_8803EDC0[];
extern char lbl_8803EDF0[];
extern char lbl_8803EE48[];
extern char lbl_8803EE5C[];
extern char lbl_8803EE7C[];
extern char lbl_8803EE88[];
extern char lbl_8803EE98[];
extern char lbl_8803EEB0[];
extern char lbl_8803EECC[];
extern char lbl_8803EEE8[];
extern char lbl_8803EEFC[];
extern char lbl_8803EF04[];
extern char lbl_8803EFC0[];
extern char lbl_8803F5BC[];
extern char lbl_8803F5C8[];
extern char lbl_8803F5E0[];
extern char lbl_880400A8[];
extern char lbl_880400D0[];
extern char lbl_880400E8[];
extern char lbl_88040100[];
extern char lbl_88040110[];
extern char lbl_8804011C[];
extern char lbl_88040278[];
extern char lbl_88041284[];
extern char lbl_88041B24[];
extern char lbl_88042318[];
extern char lbl_8804232C[];
extern char lbl_8804233C[];
extern char lbl_8804234C[];
extern char lbl_88042358[];
extern char lbl_88042370[];
extern char lbl_880423F8[];
extern char lbl_88042408[];
extern char lbl_88042E48[];
extern char lbl_88046220[];
extern char lbl_88046320[];
extern char lbl_880463D4[];
extern char lbl_88046454[];
extern char lbl_8804671C[];
extern char lbl_880467DC[];
extern char lbl_88046868[];
extern char lbl_880468C8[];
extern char lbl_8804690C[];
extern char lbl_8804694C[];
extern char lbl_880469C4[];
extern char lbl_88046A50[];
extern char lbl_88046A84[];
extern char lbl_88046AE0[];
extern char lbl_88046B60[];
extern char lbl_88046C94[];
extern char lbl_8804BB40[];
extern char lbl_8804BB94[];
extern char lbl_8804BBD8[];
extern char lbl_8804BC14[];
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
extern char lbl_880DCF40[];
extern char lbl_880DCF48[];
extern char lbl_880DCF4C[];
extern char lbl_880DCF54[];
extern char lbl_880DCF5C[];
extern char lbl_880DCF64[];
extern char lbl_880DCF6C[];
extern char lbl_880DD198[];
extern char lbl_880DD398[];
extern char lbl_880E49F0[];
extern char lbl_880E8CA8[];
extern char lbl_880E8CAC[];
extern char lbl_880EA6F0[];
extern char lbl_880FCB8C[];
extern char lbl_88B3AA40[];
extern char lbl_88B3AC90[];
extern char lbl_88B3B768[];
extern char lbl_88B3B910[];
extern char lbl_88B3B928[];
extern char lbl_88B3BA38[];
extern char lbl_88B3BA40[];
extern char lbl_88B3BD64[];
extern char lbl_88B3BD78[];
extern char lbl_88B3BE68[];
extern char lbl_88B3BE90[];
extern char lbl_88B3BEF0[];
extern char lbl_88B3BEF4[];
extern char lbl_88B3BF10[];
extern char lbl_88B3C030[];
extern char lbl_88B3C068[];
extern char lbl_88B3C338[];
extern char lbl_88B3C7E0[];
extern char lbl_88B3C7F4[];
extern char lbl_88B3D478[];
extern char lbl_88B3D4F0[];
extern char lbl_88B3D520[];
extern char lbl_88B3D550[];
extern char lbl_88B3D580[];
extern char lbl_88B3D5E0[];
extern char lbl_88B3D640[];
extern char lbl_88B3D6D0[];
extern char lbl_88B3D6E8[];
extern char lbl_88B3D748[];
extern char lbl_88B3D7F0[];
extern char lbl_88B3D850[];
extern char lbl_88B3D8C8[];
extern char lbl_88B3D8F8[];
extern char lbl_88B3D9A0[];
extern char lbl_88B3D9D0[];
extern char lbl_88B3DA00[];
extern char lbl_88B3DA0C[];
extern char lbl_88B3DA3C[];
extern char lbl_88B3DA6C[];
extern char lbl_88B3DA70[];
extern char lbl_88B3DB30[];
extern char lbl_88B3DB48[];
extern char lbl_88B3DBC0[];
extern char lbl_88B3DC50[];
extern char lbl_88B3DC80[];
extern char lbl_88B3DD2C[];
extern char lbl_88B3DD5C[];
extern char lbl_88B3DD60[];
extern char lbl_88B3DDF0[];
extern char lbl_88B3DE08[];
extern char lbl_88B3DE38[];
extern char lbl_88B3DE50[];
extern char lbl_88B3DE98[];
extern char lbl_88B3DEC8[];
extern char lbl_88B3DFE8[];
extern char lbl_88B3E078[];
extern char lbl_88B3E138[];
extern char lbl_88B3E210[];
extern char lbl_88B3E2D0[];
extern char lbl_88B3E378[];
extern char lbl_88B3E3C0[];
extern char lbl_88B3E420[];
extern char lbl_88B3E450[];
extern char lbl_88B3E558[];
extern char lbl_88B3E5B8[];
extern char lbl_88B3E6A8[];
extern char lbl_88B3E780[];
extern char lbl_88B3E7B0[];
extern char lbl_88B3E7C8[];
extern char lbl_88B3E828[];
extern char lbl_88B3E870[];
extern char lbl_88B3E8D0[];
extern char lbl_88B3E900[];
extern char lbl_88B3E918[];
extern char lbl_88B3E930[];
extern char lbl_88B3E990[];
extern char lbl_88B3E9A8[];
extern char lbl_88B3E9D8[];
extern char lbl_88B3E9F0[];
extern char lbl_88B3EA20[];
extern char lbl_88B3EA38[];
extern char lbl_88B3EA50[];
extern char lbl_88B3EA68[];
extern char lbl_88B3EAB0[];
extern char lbl_88B3EAE0[];
extern char lbl_88B3EB10[];
extern char lbl_88B3EB58[];
extern char lbl_88B3EBD0[];
extern char lbl_88B3EC48[];
extern char lbl_88B3EC78[];
extern char lbl_88B3EC90[];
extern char lbl_88B3ECA8[];
extern char lbl_88B41788[];
extern char lbl_88B41848[];
extern char lbl_88B418C0[];
extern char lbl_88B41938[];
extern char lbl_88C6C3E8[];
extern char lbl_88C6E1A8[];
extern char lbl_88C6E260[];
extern char lbl_88C6E264[];
extern char lbl_88C6E268[];
extern char lbl_88C74928[];
extern char lbl_88CAC9C8[];
extern char lbl_88CAC9F8[];
extern char lbl_88CACA28[];
extern char lbl_88CACA58[];
extern char lbl_88CACAB8[];
extern char lbl_88CACAE8[];
extern char lbl_88CACB18[];
extern char lbl_88CACB48[];
extern char lbl_88CACB78[];
extern char lbl_88CACBA8[];
extern char lbl_88CACBD8[];
extern char lbl_88CACC08[];
extern char lbl_88CACC38[];
extern char lbl_88CACC68[];
extern char lbl_88CACC98[];
extern char lbl_88CACCC8[];
extern char lbl_88CACCF8[];
extern char lbl_88CACD28[];
extern char lbl_88CACD58[];
extern char lbl_88CACD88[];
extern char lbl_88CACDB8[];
extern char lbl_88CACDE8[];
extern char lbl_88CACE18[];
extern char lbl_88CACE48[];
extern char lbl_88CACE78[];
extern char lbl_88CACEA8[];
extern char lbl_88CACED8[];
extern char lbl_88CACF08[];
extern char lbl_88CACF0C[];
extern char lbl_88CACF3C[];
extern char lbl_88CACF6C[];
extern char lbl_88CACF9C[];
extern char lbl_88CACFCC[];
extern char lbl_88CACFFC[];
extern char lbl_88CAD02C[];
extern char lbl_88CAD05C[];
extern char lbl_88CAD08C[];
extern char lbl_88CAD0BC[];
extern char lbl_88CAD0EC[];
extern char lbl_88CAD11C[];
extern char lbl_88CAD14C[];
extern char lbl_88CAD17C[];
extern char lbl_88CAD1AC[];
extern char lbl_88CAD1DC[];
extern char lbl_88CAD20C[];
extern char lbl_88CAD23C[];
extern char lbl_88CAD26C[];
extern char lbl_88CAD29C[];
extern char lbl_88CAD2CC[];
extern char lbl_88CAD2FC[];
extern char lbl_88CAD338[];
extern char lbl_88CAD560[];
extern char lbl_88CAD57C[];
extern char lbl_88CAD5AC[];
extern char lbl_88CAD5DC[];
extern char lbl_88CAD60C[];
extern char lbl_88CAD63C[];
extern char lbl_88CAD66C[];
extern char lbl_88CAD69C[];
extern char lbl_88CAD6CC[];
extern char lbl_88CAD6FC[];
extern char lbl_88CAD72C[];
extern char lbl_88CAD75C[];
extern char lbl_88CAD78C[];
extern char lbl_88CAD7BC[];
extern char lbl_88CAD7EC[];
extern char lbl_88CAD81C[];
extern char lbl_88CAD84C[];
extern char lbl_88CAD87C[];
extern char lbl_88CAD8AC[];
extern char lbl_88CAD8DC[];
extern char lbl_88CAD90C[];
extern char lbl_88CAD93C[];
extern char lbl_88CAD96C[];
extern char lbl_88CAD99C[];
extern char lbl_88CAD9CC[];
extern char lbl_88CAD9FC[];
extern char lbl_88CADA2C[];
extern char lbl_88CADA5C[];
extern char lbl_88CADA8C[];
extern char lbl_88CADABC[];
extern char lbl_88CADAEC[];
extern char lbl_88CADB1C[];
extern char lbl_88CADB4C[];
extern char lbl_88CADB7C[];
extern char lbl_88CADBAC[];
extern char lbl_88CADBDC[];
extern char lbl_88CADC0C[];
extern char lbl_88CADC3C[];
extern char lbl_88CADC6C[];
extern char lbl_88CADC9C[];
extern char lbl_88CADCCC[];
extern char lbl_88CADCFC[];
extern char lbl_88CADD2C[];
extern char lbl_88CADD5C[];
extern char lbl_88CADD8C[];
extern char lbl_88CADDBC[];
extern char lbl_88CADDEC[];
extern char lbl_88CADE1C[];
extern char lbl_88CADE4C[];
extern char lbl_88CADE7C[];
extern char lbl_88CADEAC[];
extern char lbl_88CADEDC[];
extern char lbl_88CADF0C[];
extern char lbl_88CADF3C[];
extern char lbl_88CADF6C[];
extern char lbl_88CADF9C[];
extern char lbl_88CADFCC[];
extern char lbl_88CADFFC[];
extern char lbl_88CAE02C[];
extern char lbl_88CAE05C[];
extern char lbl_88CAE08C[];
extern char lbl_88CAE0BC[];
extern char lbl_88CAE0EC[];
extern char lbl_88CAE11C[];
extern char lbl_88CAE14C[];
extern char lbl_88CAE17C[];
extern char lbl_88CAE1AC[];
extern char lbl_88CAE1DC[];
extern char lbl_88CAE20C[];
extern char lbl_88CAE23C[];
extern char lbl_88CAE26C[];
extern char lbl_88CAE29C[];
extern char lbl_88CAE2CC[];
extern char lbl_88CAE2FC[];
extern char lbl_88CAE32C[];
extern char lbl_88CAE35C[];
extern char lbl_88CAE38C[];
extern char lbl_88CAE3BC[];
extern char lbl_88CAE3EC[];
extern char lbl_88CAE41C[];
extern char lbl_88CAE44C[];
extern char lbl_88CAE47C[];
extern char lbl_88CAE4AC[];
extern char lbl_88CAE50C[];
extern char lbl_88CAE71C[];
extern char lbl_88CAF67C[];
extern char lbl_88D45B38[];
extern char lbl_88D463D4[];
extern char lbl_88D463D8[];
extern char lbl_88D463DC[];
extern char lbl_88D463E0[];
extern char lbl_88D463E4[];
extern char lbl_88D463E8[];
extern char lbl_88D463EC[];
extern char lbl_88D463F0[];
extern char lbl_88D46410[];
extern char lbl_88D467B0[];
extern char lbl_88D48854[];
extern char lbl_88D48864[];
extern char lbl_88D48868[];
extern char lbl_88D492B0[];
extern char ts4_noop_88AFEF38[];
extern char ts4_noop_88AFEF40[];
extern char ts4_noop_88AFEF48[];
extern char ts4_noop_88AFEF50[];
extern char ts4_noop_88AFEF58[];
extern char ts4_noop_88AFEF60[];
extern char ts4_noop_88AFEF68[];
extern char ts4_noop_88AFEF70[];
extern char ts4_noop_88AFEF78[];
extern char ts4_noop_88AFEF80[];
extern char ts4_noop_88AFEF88[];
extern char ts4_noop_88AFF0C0[];
extern char ts4_noop_88AFF2C8[];
extern char ts4_noop_88AFF360[];
extern char ts4_noop_88AFF368[];
extern char ts4_noop_88AFF370[];
extern char ts4_noop_88AFF378[];
extern char ts4_noop_88AFF380[];
extern char ts4_noop_88AFF388[];
extern char ts4_noop_88AFF3D8[];
ts4_word KeReleaseSemaphore();
ts4_word KeTlsAlloc();
ts4_word KeWaitForSingleObject();
ts4_word fn_8818A6A0();
ts4_word fn_8822D3D0();
ts4_word fn_88255AA0();
ts4_word fn_8830EC08();
ts4_word ts4_addr_ts4_forward_88315998_883159B0();
ts4_word fn_88325A40();
ts4_word fn_8841F080();
ts4_word fn_88563470();
ts4_word fn_88564470();
ts4_word fn_88564550();
ts4_word fn_8856C178();
ts4_word fn_8860D250();
ts4_word fn_888240B8();
ts4_word ts4_lua_opt_number_default_8882EA98();
ts4_word ts4_assign_formatted_text();

/* Swing_DLL.xex 0x889CFEB8: call_seq ts4_lua_opt_number_default_8882EA98, fn_88564550, fn_888240B8 */
ts4_word ts4_call_seq_fn_8882EA98_889CFEB8(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_lua_opt_number_default_8882EA98((ts4_word)a0, (ts4_word)1);
    fn_88564550((ts4_word)t1);
    fn_888240B8((ts4_word)a0);
    return 1;
}

/* Swing_DLL.xex 0x889CFEF8: call_seq ts4_lua_opt_number_default_8882EA98, fn_88564470, fn_888240B8 */
ts4_word ts4_call_seq_fn_8882EA98_889CFEF8(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_lua_opt_number_default_8882EA98((ts4_word)a0, (ts4_word)1);
    fn_88564470((ts4_word)t1);
    fn_888240B8((ts4_word)a0);
    return 1;
}

/* Swing_DLL.xex 0x889D18C8: if_call_seq KeTlsAlloc, u32@lbl_88C6E1A8, lbl_880FCB8C, fn_8856C178, u32@lbl_88C6E1A8 */
ts4_word ts4_if_call_seq_KeTlsAlloc_889D18C8(void)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = KeTlsAlloc();
    *(ts4_word *)lbl_88C6E1A8 = (ts4_word)t1;
    p3 = (ts4_word)t1;
    if ((int)t1 == -1) {
        t2 = fn_8856C178((ts4_word)(ts4_word)lbl_880FCB8C);
        *(ts4_word *)lbl_88C6E1A8 = (ts4_word)-2;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x889D1D50: get u32@__imp_XboxHardwareInfo, u8@0x4 */
ts4_word ts4_get_u32__imp_XboxHardwareInfo_889D1D50(void)
{
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)__imp_XboxHardwareInfo)) + 4));
}

/* Swing_DLL.xex 0x889D1DA0: tailcall KeReleaseSemaphore */
ts4_word ts4_tailcall_KeReleaseSemaphore_889D1DA0(ts4_word a0)
{
    return KeReleaseSemaphore((ts4_word)a0, (ts4_word)1, (ts4_word)1, (ts4_word)0);
}

/* Swing_DLL.xex 0x889D1DB0: if_get u32@-0x8, u32@0x14, KeWaitForSingleObject */
ts4_word ts4_if_get_u32_0x8_889D1DB0(ts4_word a0)
{
    ts4_word p3;
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + -8))) + 20);
    p3 = (ts4_word)t2;
    if ((int)t2 >= 0) {
        p3 = (ts4_word)(t2 + a0);
    }
    return KeWaitForSingleObject((ts4_word)p3, (ts4_word)3, (ts4_word)1, (ts4_word)0, (ts4_word)0);
}

/* Swing_DLL.xex 0x889D1EB0: addr ts4_noop_88AFEF38, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFEF38_889D1EB0(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFEF38);
}

/* Swing_DLL.xex 0x889D1EC0: addr ts4_noop_88AFEF40, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFEF40_889D1EC0(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFEF40);
}

/* Swing_DLL.xex 0x889D1ED0: addr ts4_noop_88AFEF48, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFEF48_889D1ED0(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFEF48);
}

/* Swing_DLL.xex 0x889D1EE0: addr ts4_noop_88AFEF50, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFEF50_889D1EE0(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFEF50);
}

/* Swing_DLL.xex 0x889D1EF0: addr ts4_noop_88AFEF58, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFEF58_889D1EF0(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFEF58);
}

/* Swing_DLL.xex 0x889D1F00: addr ts4_noop_88AFEF60, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFEF60_889D1F00(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFEF60);
}

/* Swing_DLL.xex 0x889D1F10: addr ts4_noop_88AFEF68, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFEF68_889D1F10(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFEF68);
}

/* Swing_DLL.xex 0x889D1F20: addr ts4_noop_88AFEF70, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFEF70_889D1F20(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFEF70);
}

/* Swing_DLL.xex 0x889D1F30: addr ts4_noop_88AFEF78, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFEF78_889D1F30(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFEF78);
}

/* Swing_DLL.xex 0x889D1F40: addr ts4_noop_88AFEF80, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFEF80_889D1F40(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFEF80);
}

/* Swing_DLL.xex 0x889D1F50: addr ts4_noop_88AFEF88, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFEF88_889D1F50(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFEF88);
}

/* Swing_DLL.xex 0x889D2368: call_seq lbl_880DCF40, fn_8818A6A0, u32@lbl_88D463D4 */
ts4_word ts4_call_seq_lbl_880DCF40_889D2368(void)
{
    ts4_word t1;

    t1 = fn_8818A6A0((ts4_word)(ts4_word)lbl_880DCF40, (ts4_word)1, (ts4_word)255);
    *(ts4_word *)lbl_88D463D4 = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x889D23A0: call_seq lbl_880DCF48, fn_8818A6A0, u32@lbl_88D463D8 */
ts4_word ts4_call_seq_lbl_880DCF48_889D23A0(void)
{
    ts4_word t1;

    t1 = fn_8818A6A0((ts4_word)(ts4_word)lbl_880DCF48, (ts4_word)1, (ts4_word)0);
    *(ts4_word *)lbl_88D463D8 = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x889D23D8: call_seq lbl_880DCF4C, fn_8818A6A0, u32@lbl_88D463DC */
ts4_word ts4_call_seq_lbl_880DCF4C_889D23D8(void)
{
    ts4_word t1;

    t1 = fn_8818A6A0((ts4_word)(ts4_word)lbl_880DCF4C, (ts4_word)1, (ts4_word)0);
    *(ts4_word *)lbl_88D463DC = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x889D2410: call_seq lbl_880DCF54, fn_8818A6A0, u32@lbl_88D463E0 */
ts4_word ts4_call_seq_lbl_880DCF54_889D2410(void)
{
    ts4_word t1;

    t1 = fn_8818A6A0((ts4_word)(ts4_word)lbl_880DCF54, (ts4_word)1, (ts4_word)255);
    *(ts4_word *)lbl_88D463E0 = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x889D2448: call_seq lbl_880DCF5C, fn_8818A6A0, u32@lbl_88D463E4 */
ts4_word ts4_call_seq_lbl_880DCF5C_889D2448(void)
{
    ts4_word t1;

    t1 = fn_8818A6A0((ts4_word)(ts4_word)lbl_880DCF5C, (ts4_word)1, (ts4_word)0);
    *(ts4_word *)lbl_88D463E4 = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x889D2480: call_seq lbl_880DCF64, fn_8818A6A0, u32@lbl_88D463E8 */
ts4_word ts4_call_seq_lbl_880DCF64_889D2480(void)
{
    ts4_word t1;

    t1 = fn_8818A6A0((ts4_word)(ts4_word)lbl_880DCF64, (ts4_word)1, (ts4_word)0);
    *(ts4_word *)lbl_88D463E8 = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x889D24B8: call_seq lbl_880DCF6C, fn_8818A6A0, u32@lbl_88D463EC */
ts4_word ts4_call_seq_lbl_880DCF6C_889D24B8(void)
{
    ts4_word t1;

    t1 = fn_8818A6A0((ts4_word)(ts4_word)lbl_880DCF6C, (ts4_word)1, (ts4_word)0);
    *(ts4_word *)lbl_88D463EC = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x889D24F0: call_seq lbl_880DD198, fn_8818A6A0, u32@lbl_88D463F0 */
ts4_word ts4_call_seq_lbl_880DD198_889D24F0(void)
{
    ts4_word t1;

    t1 = fn_8818A6A0((ts4_word)(ts4_word)lbl_880DD198, (ts4_word)1, (ts4_word)0);
    *(ts4_word *)lbl_88D463F0 = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x889D2568: call_seq lbl_880DD398, fn_8818A6A0, u32@lbl_88D46410 */
ts4_word ts4_call_seq_lbl_880DD398_889D2568(void)
{
    ts4_word t1;

    t1 = fn_8818A6A0((ts4_word)(ts4_word)lbl_880DD398, (ts4_word)1, (ts4_word)0);
    *(ts4_word *)lbl_88D46410 = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x889D2A88: addr lbl_88D467B0, u32@lbl_88D467B0, u32@0x8, u32@0x10, u32@0x18, u32@0x20 */
void ts4_addr_lbl_88D467B0_889D2A88(void)
{
    *(ts4_word *)lbl_88D467B0 = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D467B0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D467B0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D467B0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D467B0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D467B0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D467B0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D467B0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D467B0) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D467B0) + 72) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x889D2AF0: addr ts4_noop_88AFF0C0, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFF0C0_889D2AF0(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFF0C0);
}

/* Swing_DLL.xex 0x889D2BF8: call_seq lbl_880E49F0, lbl_88D48854, ts4_assign_formatted_text, ts4_get_u32_lbl_88D48854_88AFF0C8, fn_88563470 */
ts4_word ts4_call_seq_lbl_880E49F0_889D2BF8(void)
{
    ts4_word t2;

    ts4_assign_formatted_text((ts4_word)(ts4_word)lbl_88D48854, (ts4_word)(ts4_word)lbl_880E49F0);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_get_u32_lbl_88D48854_88AFF0C8);
    return t2;
}

/* Swing_DLL.xex 0x889D2C78: addr ts4_call_seq_lbl_88C6C278_88AFF0D8, fn_88563470 */
ts4_word ts4_addr_fn_88AFF0D8_889D2C78(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_call_seq_lbl_88C6C278_88AFF0D8);
}

/* Swing_DLL.xex 0x889D2C88: addr ts4_call_seq_lbl_88C6C28C_88AFF128, fn_88563470 */
ts4_word ts4_addr_fn_88AFF128_889D2C88(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_call_seq_lbl_88C6C28C_88AFF128);
}

/* Swing_DLL.xex 0x889D2C98: addr ts4_call_seq_lbl_88C6C2A0_88AFF178, fn_88563470 */
ts4_word ts4_addr_fn_88AFF178_889D2C98(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_call_seq_lbl_88C6C2A0_88AFF178);
}

/* Swing_DLL.xex 0x889D2CA8: addr ts4_call_seq_lbl_88C6C2C4_88AFF1C8, fn_88563470 */
ts4_word ts4_addr_fn_88AFF1C8_889D2CA8(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_call_seq_lbl_88C6C2C4_88AFF1C8);
}

/* Swing_DLL.xex 0x889D2CB8: addr ts4_call_seq_lbl_88C6C300_88AFF218, fn_88563470 */
ts4_word ts4_addr_fn_88AFF218_889D2CB8(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_call_seq_lbl_88C6C300_88AFF218);
}

/* Swing_DLL.xex 0x889D2CC8: call_seq lbl_880E8CA8, fn_8818A6A0, u32@lbl_88D48864 */
ts4_word ts4_call_seq_lbl_880E8CA8_889D2CC8(void)
{
    ts4_word t1;

    t1 = fn_8818A6A0((ts4_word)(ts4_word)lbl_880E8CA8, (ts4_word)1, (ts4_word)255);
    *(ts4_word *)lbl_88D48864 = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x889D2D00: call_seq lbl_880E8CAC, fn_8818A6A0, u32@lbl_88D48868 */
ts4_word ts4_call_seq_lbl_880E8CAC_889D2D00(void)
{
    ts4_word t1;

    t1 = fn_8818A6A0((ts4_word)(ts4_word)lbl_880E8CAC, (ts4_word)0, (ts4_word)255);
    *(ts4_word *)lbl_88D48868 = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x889D2D58: if_call_seq lbl_88C6C3E8, u32@lbl_88D45B38, fn_8860D250, u32@0xc, lbl_880EA6F0, ts4_addr_lbl_88C6C3E8_88AFF2B8 */
ts4_word ts4_if_call_seq_lbl_88C6C3E8_889D2D58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C3E8) + 12) = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C3E8) + 0) = (ts4_word)(ts4_word)lbl_880EA6F0;
    t4 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_88C6C3E8_88AFF2B8);
    return t4;
}

/* Swing_DLL.xex 0x889D2DD8: addr ts4_noop_88AFF2C8, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFF2C8_889D2DD8(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFF2C8);
}

/* Swing_DLL.xex 0x889D2DE8: addr ts4_addr_lbl_88C6C6AC_88AFF2D0, fn_88563470 */
ts4_word ts4_addr_fn_88AFF2D0_889D2DE8(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_88C6C6AC_88AFF2D0);
}

/* Swing_DLL.xex 0x889D30F0: call_seq fn_88255AA0, lbl_88D492B0, u32@lbl_88D492B0, u32@0x4, u32@0x8, fn_88255AA0 */
ts4_word ts4_call_seq_fn_88255AA0_889D30F0(void)
{
    ts4_word loc50[1];
    ts4_word t3;

    loc50[0] = (ts4_word)0;
    fn_88255AA0((ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)lbl_88D492B0 = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D492B0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D492B0) + 8) = (ts4_word)0;
    fn_88255AA0((ts4_word)((ts4_word)lbl_88D492B0 + 8));
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D492B0) + 12) = (ts4_word)0;
    t3 = fn_88563470((ts4_word)(ts4_word)fn_88AFF328);
    return t3;
}

/* Swing_DLL.xex 0x889D3160: addr ts4_noop_88AFF360, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFF360_889D3160(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFF360);
}

/* Swing_DLL.xex 0x889D3170: addr ts4_noop_88AFF368, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFF368_889D3170(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFF368);
}

/* Swing_DLL.xex 0x889D3180: addr ts4_noop_88AFF370, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFF370_889D3180(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFF370);
}

/* Swing_DLL.xex 0x889D3190: addr ts4_noop_88AFF378, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFF378_889D3190(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFF378);
}

/* Swing_DLL.xex 0x889D31A0: addr ts4_noop_88AFF380, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFF380_889D31A0(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFF380);
}

/* Swing_DLL.xex 0x889D31B0: addr ts4_noop_88AFF388, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFF388_889D31B0(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFF388);
}

/* Swing_DLL.xex 0x889D31C0: addr ts4_addr_lbl_880D19F0_88AFF390, fn_88563470 */
ts4_word ts4_addr_fn_88AFF390_889D31C0(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_880D19F0_88AFF390);
}

/* Swing_DLL.xex 0x889D31F8: call_seq fn_8822D3D0, ts4_tailcall_fn_88224B38_88AFF3D0, fn_88563470 */
ts4_word ts4_call_seq_fn_8822D3D0_889D31F8(void)
{
    ts4_word t2;

    fn_8822D3D0();
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_tailcall_fn_88224B38_88AFF3D0);
    return t2;
}

/* Swing_DLL.xex 0x889D3288: addr ts4_noop_88AFF3D8, fn_88563470 */
ts4_word ts4_addr_ts4_noop_88AFF3D8_889D3288(void)
{
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFF3D8);
}

/* Swing_DLL.xex 0x889D3310: addr lbl_88C74928, u32@0x4c, u32@lbl_88C6E260, u32@lbl_88C6E264 */
void ts4_addr_lbl_88C74928_889D3310(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C74928) + 76) = (ts4_word)256;
    *(ts4_word *)lbl_88C6E260 = (ts4_word)0;
    *(ts4_word *)lbl_88C6E264 = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x889D3340: call_seq lbl_88C6E268, fn_8830EC08, ts4_call_seq_lbl_88C6E268_88AFF458, fn_88563470 */
ts4_word ts4_call_seq_lbl_88C6E268_889D3340(void)
{
    ts4_word t2;

    fn_8830EC08((ts4_word)(ts4_word)lbl_88C6E268);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_call_seq_lbl_88C6E268_88AFF458);
    return t2;
}

/* Swing_DLL.xex 0x889D3378: call_seq lbl_88C74928, ts4_addr_ts4_forward_88315998_883159B0, ts4_addr_lbl_88C74928_88AFF4B8, fn_88563470 */
ts4_word ts4_call_seq_lbl_88C74928_889D3378(void)
{
    ts4_word t2;

    ts4_addr_ts4_forward_88315998_883159B0((ts4_word)(ts4_word)lbl_88C74928);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_88C74928_88AFF4B8);
    return t2;
}

/* Swing_DLL.xex 0x889D33B0: addr lbl_88B3AA40, fn_88325A40 */
ts4_word ts4_addr_lbl_88B3AA40_889D33B0(void)
{
    return fn_88325A40((ts4_word)((ts4_word)lbl_88B3AA40 + 24));
}

/* Swing_DLL.xex 0x889D33C0: addr lbl_88B3AC90, fn_88325A40 */
ts4_word ts4_addr_lbl_88B3AC90_889D33C0(void)
{
    return fn_88325A40((ts4_word)((ts4_word)lbl_88B3AC90 + 24));
}

/* Swing_DLL.xex 0x889D3410: call_seq lbl_8803A3E0, lbl_88CACE18, lbl_8803A45C, lbl_88CAC9C8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803A3E0_889D3410(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAC9C8, (ts4_word)(ts4_word)lbl_8803A45C, (ts4_word)(ts4_word)lbl_88CACE18, (ts4_word)64, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803A3E0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3488: call_seq lbl_8803A580, lbl_8803A87C, lbl_88CAC9F8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803A580_889D3488(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAC9F8, (ts4_word)(ts4_word)lbl_8803A87C, (ts4_word)0, (ts4_word)20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803A580, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D34F8: call_seq lbl_8803A610, lbl_88CACE48, lbl_8803A8B4, lbl_88CACA28, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803A610_889D34F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACA28, (ts4_word)(ts4_word)lbl_8803A8B4, (ts4_word)(ts4_word)lbl_88CACE48, (ts4_word)104, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803A610, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3570: call_seq lbl_8803A8EC, lbl_88CACE48, lbl_8803A954, lbl_88CACA58, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803A8EC_889D3570(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACA58, (ts4_word)(ts4_word)lbl_8803A954, (ts4_word)(ts4_word)lbl_88CACE48, (ts4_word)52, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803A8EC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3690: call_seq lbl_88B3B768, lbl_8803AE48, lbl_88CACAB8, lbl_8803AC80, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3B768_889D3690(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACAB8, (ts4_word)(ts4_word)lbl_8803AE48, (ts4_word)0, (ts4_word)28, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803AC80, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B3B768, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3700: call_seq lbl_8803ACA8, lbl_8803AEC8, lbl_88CACAE8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803ACA8_889D3700(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACAE8, (ts4_word)(ts4_word)lbl_8803AEC8, (ts4_word)0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803ACA8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3770: call_seq lbl_8803ACD8, lbl_88CACE48, lbl_8803AF00, lbl_88CACB18, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803ACD8_889D3770(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACB18, (ts4_word)(ts4_word)lbl_8803AF00, (ts4_word)(ts4_word)lbl_88CACE48, (ts4_word)128, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803ACD8, (ts4_word)13, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D37E8: call_seq lbl_8803AFD0, lbl_8803B27C, lbl_88CACB48, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803AFD0_889D37E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACB48, (ts4_word)(ts4_word)lbl_8803B27C, (ts4_word)0, (ts4_word)36, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803AFD0, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3858: call_seq lbl_8803B0C0, lbl_8803B2AC, lbl_88CACB78, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803B0C0_889D3858(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACB78, (ts4_word)(ts4_word)lbl_8803B2AC, (ts4_word)0, (ts4_word)20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803B0C0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D38C8: call_seq lbl_8803B150, lbl_88CACE48, lbl_8803B2DC, lbl_88CACBA8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803B150_889D38C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACBA8, (ts4_word)(ts4_word)lbl_8803B2DC, (ts4_word)(ts4_word)lbl_88CACE48, (ts4_word)96, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803B150, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3940: addr lbl_88B3B928, u32@lbl_88B3B910, u32@0x50 */
void ts4_addr_lbl_88B3B928_889D3940(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B3B928) + 80) = (ts4_word)(*(ts4_word *)lbl_88B3B910);
    return;
}

/* Swing_DLL.xex 0x889D3958: call_seq lbl_88B3B928, lbl_8803B388, lbl_88CACBD8, lbl_8803B374, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3B928_889D3958(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACBD8, (ts4_word)(ts4_word)lbl_8803B388, (ts4_word)0, (ts4_word)24, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803B374, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B3B928, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D39C8: call_seq lbl_8803B3D8, lbl_8803B450, lbl_88CACC08, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803B3D8_889D39C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACC08, (ts4_word)(ts4_word)lbl_8803B450, (ts4_word)0, (ts4_word)40, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803B3D8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3A38: call_seq lbl_8803B47C, lbl_8803B4DC, lbl_88CACC38, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803B47C_889D3A38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACC38, (ts4_word)(ts4_word)lbl_8803B4DC, (ts4_word)0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803B47C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3AA8: call_seq lbl_8803B4AC, lbl_8803B4FC, lbl_88CACC68, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803B4AC_889D3AA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACC68, (ts4_word)(ts4_word)lbl_8803B4FC, (ts4_word)0, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803B4AC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3B18: call_seq lbl_8803B520, lbl_8803B550, lbl_88CACC98, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803B520_889D3B18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACC98, (ts4_word)(ts4_word)lbl_8803B550, (ts4_word)0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803B520, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3B88: call_seq lbl_8803B588, lbl_8803B5E8, lbl_88CACCC8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803B588_889D3B88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACCC8, (ts4_word)(ts4_word)lbl_8803B5E8, (ts4_word)0, (ts4_word)80, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803B588, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3BF8: call_seq lbl_8803B638, lbl_8803B6B0, lbl_88CACCF8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803B638_889D3BF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACCF8, (ts4_word)(ts4_word)lbl_8803B6B0, (ts4_word)0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803B638, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3C68: call_seq lbl_8803B650, lbl_8803B6C8, lbl_88CACD28, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803B650_889D3C68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACD28, (ts4_word)(ts4_word)lbl_8803B6C8, (ts4_word)0, (ts4_word)24, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803B650, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3CD8: call_seq lbl_8803B710, lbl_8803B788, lbl_88CACD58, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803B710_889D3CD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACD58, (ts4_word)(ts4_word)lbl_8803B788, (ts4_word)0, (ts4_word)36, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803B710, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3D48: call_seq lbl_8803B870, lbl_8803B9D8, lbl_88CACD88, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803B870_889D3D48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACD88, (ts4_word)(ts4_word)lbl_8803B9D8, (ts4_word)0, (ts4_word)64, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803B870, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3DB8: call_seq lbl_8803B8B8, lbl_8803B9FC, lbl_88CACDB8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803B8B8_889D3DB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACDB8, (ts4_word)(ts4_word)lbl_8803B9FC, (ts4_word)0, (ts4_word)112, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803B8B8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3E28: call_seq lbl_8803B948, lbl_8803BA20, lbl_88CACDE8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803B948_889D3E28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACDE8, (ts4_word)(ts4_word)lbl_8803BA20, (ts4_word)0, (ts4_word)48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803B948, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3E98: call_seq lbl_88CACF0C, lbl_8803BA38, lbl_88CACE18, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CACF0C_889D3E98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACE18, (ts4_word)(ts4_word)lbl_8803BA38, (ts4_word)(ts4_word)lbl_88CACF0C, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3F00: addr lbl_88B3BA40, u32@lbl_88B3BA38, u32@0x8 */
void ts4_addr_lbl_88B3BA40_889D3F00(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B3BA40) + 8) = (ts4_word)(*(ts4_word *)lbl_88B3BA38);
    return;
}

/* Swing_DLL.xex 0x889D3F18: call_seq lbl_88B3BA40, lbl_88CACF0C, lbl_8803BBA4, lbl_88CACE48, lbl_8803BB40, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3BA40_889D3F18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACE48, (ts4_word)(ts4_word)lbl_8803BBA4, (ts4_word)(ts4_word)lbl_88CACF0C, (ts4_word)36, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803BB40, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B3BA40, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D3F90: call_seq lbl_8803C410, lbl_88CACF0C, lbl_8803C484, lbl_88CACE78, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803C410_889D3F90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACE78, (ts4_word)(ts4_word)lbl_8803C484, (ts4_word)(ts4_word)lbl_88CACF0C, (ts4_word)48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803C410, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D4008: call_seq lbl_8803C698, lbl_8803C814, lbl_88CACEA8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803C698_889D4008(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACEA8, (ts4_word)(ts4_word)lbl_8803C814, (ts4_word)0, (ts4_word)48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803C698, (ts4_word)12, (ts4_word)((ts4_word)lbl_8803C698 + 288), (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D4078: call_seq lbl_8803C83C, lbl_88CACED8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803C83C_889D4078(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACED8, (ts4_word)(ts4_word)lbl_8803C83C, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D40D8: call_seq KeTlsAlloc, ts4_get_u32_lbl_88CACF08_88AFF4C8, u32@lbl_88CACF08, fn_88563470 */
ts4_word ts4_call_seq_KeTlsAlloc_889D40D8(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = KeTlsAlloc();
    *(ts4_word *)lbl_88CACF08 = (ts4_word)t1;
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_get_u32_lbl_88CACF08_88AFF4C8);
    return t2;
}

/* Swing_DLL.xex 0x889D4110: call_seq lbl_8803C9AC, lbl_88CAD2FC, lbl_8803C9DC, lbl_88CACF0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803C9AC_889D4110(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACF0C, (ts4_word)(ts4_word)lbl_8803C9DC, (ts4_word)(ts4_word)lbl_88CAD2FC, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803C9AC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D4188: call_seq lbl_8803CA30, lbl_8803CAF0, lbl_88CACF3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803CA30_889D4188(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACF3C, (ts4_word)(ts4_word)lbl_8803CAF0, (ts4_word)0, (ts4_word)32, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803CA30, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D41F8: call_seq lbl_8803CA60, lbl_8803CAF8, lbl_88CACF6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803CA60_889D41F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACF6C, (ts4_word)(ts4_word)lbl_8803CAF8, (ts4_word)0, (ts4_word)32, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803CA60, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D4268: call_seq lbl_8803CB20, lbl_8803CB50, lbl_88CACF9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803CB20_889D4268(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACF9C, (ts4_word)(ts4_word)lbl_8803CB50, (ts4_word)0, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803CB20, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D42D8: addr lbl_88B3BD78, u32@lbl_88B3BD64, u32@0xc8 */
void ts4_addr_lbl_88B3BD78_889D42D8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B3BD78) + 200) = (ts4_word)(*(ts4_word *)lbl_88B3BD64);
    return;
}

/* Swing_DLL.xex 0x889D42F0: call_seq lbl_88B3BD78, lbl_8803CC5C, lbl_88CACFCC, lbl_8803CC34, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3BD78_889D42F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACFCC, (ts4_word)(ts4_word)lbl_8803CC5C, (ts4_word)0, (ts4_word)48, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803CC34, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B3BD78, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D4360: call_seq lbl_8803CC94, lbl_8803CCC4, lbl_88CACFFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803CC94_889D4360(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CACFFC, (ts4_word)(ts4_word)lbl_8803CCC4, (ts4_word)0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803CC94, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D43D0: addr lbl_88B3BE90, u32@lbl_88B3BE68, u32@0x50 */
void ts4_addr_lbl_88B3BE90_889D43D0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B3BE90) + 80) = (ts4_word)(*(ts4_word *)lbl_88B3BE68);
    return;
}

/* Swing_DLL.xex 0x889D43E8: call_seq lbl_88B3BE90, lbl_8803CCD4, lbl_88CAD02C, lbl_8803CC80, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3BE90_889D43E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD02C, (ts4_word)(ts4_word)lbl_8803CCD4, (ts4_word)0, (ts4_word)20, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803CC80, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B3BE90, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D4458: addr lbl_88B3BF10, u32@lbl_88B3BEF0, u32@lbl_88B3BEF4, u32@0x50, u32@0x68, u32@0x98 */
void ts4_addr_lbl_88B3BF10_889D4458(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88B3BEF0;
    t2 = *(ts4_word *)lbl_88B3BEF4;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B3BF10) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B3BF10) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B3BF10) + 152) = (ts4_word)t2;
    return;
}

/* Swing_DLL.xex 0x889D4480: call_seq lbl_88B3BF10, lbl_8803D124, lbl_88CAD05C, lbl_8803D0E8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3BF10_889D4480(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD05C, (ts4_word)(ts4_word)lbl_8803D124, (ts4_word)0, (ts4_word)24, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803D0E8, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B3BF10, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D44F0: call_seq lbl_8803D164, lbl_8803D194, lbl_88CAD08C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803D164_889D44F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD08C, (ts4_word)(ts4_word)lbl_8803D194, (ts4_word)0, (ts4_word)32, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803D164, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D4560: call_seq lbl_8803D268, lbl_8803D2E0, lbl_88CAD0BC, lbl_8803D250, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803D268_889D4560(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD0BC, (ts4_word)(ts4_word)lbl_8803D2E0, (ts4_word)0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803D250, (ts4_word)1, (ts4_word)(ts4_word)lbl_8803D268, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D45D0: call_seq lbl_8803D2F8, lbl_8803D340, lbl_88CAD0EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803D2F8_889D45D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD0EC, (ts4_word)(ts4_word)lbl_8803D340, (ts4_word)0, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803D2F8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D4640: call_seq lbl_8803D328, lbl_8803D35C, lbl_88CAD11C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803D328_889D4640(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD11C, (ts4_word)(ts4_word)lbl_8803D35C, (ts4_word)0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803D328, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D46B0: call_seq lbl_8803D410, lbl_8803D484, lbl_88CAD14C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803D410_889D46B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD14C, (ts4_word)(ts4_word)lbl_8803D484, (ts4_word)0, (ts4_word)16, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803D410, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D4720: call_seq lbl_8803D440, lbl_8803D4A8, lbl_88CAD17C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803D440_889D4720(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD17C, (ts4_word)(ts4_word)lbl_8803D4A8, (ts4_word)0, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803D440, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D4790: addr lbl_88B3C068, u32@lbl_88B3C030, u32@0x50 */
void ts4_addr_lbl_88B3C068_889D4790(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B3C068) + 80) = (ts4_word)(*(ts4_word *)lbl_88B3C030);
    return;
}

/* Swing_DLL.xex 0x889D47A8: call_seq lbl_88B3C068, lbl_8803D4C4, lbl_88CAD1AC, lbl_8803D470, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3C068_889D47A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD1AC, (ts4_word)(ts4_word)lbl_8803D4C4, (ts4_word)0, (ts4_word)36, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803D470, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B3C068, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D4818: call_seq lbl_8803D5C8, lbl_8803D6A0, lbl_88CAD1DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803D5C8_889D4818(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD1DC, (ts4_word)(ts4_word)lbl_8803D6A0, (ts4_word)0, (ts4_word)176, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803D5C8, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D4888: call_seq lbl_8803D788, lbl_8803D7D0, lbl_88CAD20C, lbl_8803D760, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803D788_889D4888(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD20C, (ts4_word)(ts4_word)lbl_8803D7D0, (ts4_word)0, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803D760, (ts4_word)2, (ts4_word)(ts4_word)lbl_8803D788, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D48F8: call_seq lbl_8803D808, lbl_8803D8C8, lbl_88CAD23C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803D808_889D48F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD23C, (ts4_word)(ts4_word)lbl_8803D8C8, (ts4_word)0, (ts4_word)16, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803D808, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D4968: call_seq lbl_8803D868, lbl_8803D8E0, lbl_88CAD26C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803D868_889D4968(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD26C, (ts4_word)(ts4_word)lbl_8803D8E0, (ts4_word)0, (ts4_word)16, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803D868, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D49D8: call_seq lbl_8803D8FC, lbl_8803D914, lbl_88CAD29C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803D8FC_889D49D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD29C, (ts4_word)(ts4_word)lbl_8803D914, (ts4_word)0, (ts4_word)16, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803D8FC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D4A48: call_seq lbl_8803D970, lbl_8803D9E8, lbl_88CAD2CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803D970_889D4A48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD2CC, (ts4_word)(ts4_word)lbl_8803D9E8, (ts4_word)0, (ts4_word)80, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8803D970, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D4AB8: call_seq lbl_8803C97C, lbl_88CAD2FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803C97C_889D4AB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD2FC, (ts4_word)(ts4_word)lbl_8803C97C, (ts4_word)0, (ts4_word)4, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D4B18: addr lbl_88B3C338, u32@lbl_88CAD560, u32@lbl_88CAD560, u32@0x4 */
void ts4_addr_lbl_88B3C338_889D4B18(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAD560;
    *(ts4_word *)lbl_88CAD560 = (ts4_word)(ts4_word)lbl_88B3C338;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B3C338) + 4) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x889D4B38: call_seq KeTlsAlloc, ts4_get_u32_lbl_88CAD338_88AFF4D8, u32@lbl_88CAD338, fn_88563470 */
ts4_word ts4_call_seq_KeTlsAlloc_889D4B38(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = KeTlsAlloc();
    *(ts4_word *)lbl_88CAD338 = (ts4_word)t1;
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_get_u32_lbl_88CAD338_88AFF4D8);
    return t2;
}

/* Swing_DLL.xex 0x889D4FC0: addr lbl_88B3C7E0, u32@lbl_88CAD560, u32@lbl_88CAD560, u32@0x4 */
void ts4_addr_lbl_88B3C7E0_889D4FC0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAD560;
    *(ts4_word *)lbl_88CAD560 = (ts4_word)(ts4_word)lbl_88B3C7E0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B3C7E0) + 4) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x889D4FE0: addr lbl_88B3C7F4, u32@lbl_88CAD560, u32@lbl_88CAD560, u32@0x4 */
void ts4_addr_lbl_88B3C7F4_889D4FE0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAD560;
    *(ts4_word *)lbl_88CAD560 = (ts4_word)(ts4_word)lbl_88B3C7F4;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B3C7F4) + 4) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x889D5000: call_seq lbl_88B3D478, lbl_88046C94, lbl_88CAD57C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3D478_889D5000(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD57C, (ts4_word)(ts4_word)lbl_88046C94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3D478, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5070: call_seq lbl_88B3D4F0, lbl_8803EF04, lbl_88CAD5AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3D4F0_889D5070(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD5AC, (ts4_word)(ts4_word)lbl_8803EF04, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3D4F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D50E0: call_seq lbl_88B3D520, lbl_8803EDF0, lbl_88CAD5DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3D520_889D50E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD5DC, (ts4_word)(ts4_word)lbl_8803EDF0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3D520, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5150: call_seq lbl_88B3D550, lbl_8803EC80, lbl_88CAD60C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3D550_889D5150(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD60C, (ts4_word)(ts4_word)lbl_8803EC80, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3D550, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D51C0: call_seq lbl_88B3D580, lbl_88CAD81C, lbl_8803EE48, lbl_88CAD63C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3D580_889D51C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD63C, (ts4_word)(ts4_word)lbl_8803EE48, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3D580, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5238: call_seq lbl_88B3D5E0, lbl_8803EDC0, lbl_88CAD66C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3D5E0_889D5238(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD66C, (ts4_word)(ts4_word)lbl_8803EDC0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3D5E0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D52A8: call_seq lbl_88B3D640, lbl_88CAD63C, lbl_8803EEB0, lbl_88CAD69C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3D640_889D52A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD69C, (ts4_word)(ts4_word)lbl_8803EEB0, (ts4_word)(ts4_word)lbl_88CAD63C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3D640, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5320: call_seq lbl_88B3D6D0, lbl_88CAD63C, lbl_8803EE98, lbl_88CAD6CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3D6D0_889D5320(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD6CC, (ts4_word)(ts4_word)lbl_8803EE98, (ts4_word)(ts4_word)lbl_88CAD63C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3D6D0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5398: call_seq lbl_88B3D6E8, lbl_8803ED90, lbl_88CAD6FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3D6E8_889D5398(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD6FC, (ts4_word)(ts4_word)lbl_8803ED90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3D6E8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5408: call_seq lbl_88B3D748, lbl_88CAD63C, lbl_8803EE5C, lbl_88CAD72C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3D748_889D5408(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD72C, (ts4_word)(ts4_word)lbl_8803EE5C, (ts4_word)(ts4_word)lbl_88CAD63C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3D748, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5480: call_seq lbl_88B3D7F0, lbl_8803EE88, lbl_88CAD75C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3D7F0_889D5480(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD75C, (ts4_word)(ts4_word)lbl_8803EE88, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3D7F0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D54F0: call_seq lbl_88CAD81C, lbl_8803EC58, lbl_88CAD78C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAD81C_889D54F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD78C, (ts4_word)(ts4_word)lbl_8803EC58, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5558: call_seq lbl_88B3D850, lbl_88CAD78C, lbl_8803EECC, lbl_88CAD7BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3D850_889D5558(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD7BC, (ts4_word)(ts4_word)lbl_8803EECC, (ts4_word)(ts4_word)lbl_88CAD78C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3D850, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D55D0: call_seq lbl_8803C97C, lbl_88CAD7EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8803C97C_889D55D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD7EC, (ts4_word)(ts4_word)lbl_8803C97C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5630: call_seq lbl_88B3D8C8, lbl_88CAD7EC, lbl_8803C9DC, lbl_88CAD81C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3D8C8_889D5630(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)(ts4_word)lbl_8803C9DC, (ts4_word)(ts4_word)lbl_88CAD7EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3D8C8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D56A8: call_seq lbl_88B3D8F8, lbl_8803CC5C, lbl_88CAD84C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3D8F8_889D56A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD84C, (ts4_word)(ts4_word)lbl_8803CC5C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3D8F8, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5718: call_seq lbl_88B3D9A0, lbl_8803CCC4, lbl_88CAD87C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3D9A0_889D5718(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD87C, (ts4_word)(ts4_word)lbl_8803CCC4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3D9A0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5788: call_seq lbl_88B3D9D0, lbl_8803CCD4, lbl_88CAD8AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3D9D0_889D5788(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD8AC, (ts4_word)(ts4_word)lbl_8803CCD4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3D9D0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D57F8: addr lbl_88B41788, u32@lbl_88B3DA00, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88B41788_889D57F8(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B3DA00;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B41788) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B41788) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x889D5818: call_seq lbl_88B41788, lbl_8803D124, lbl_88CAD8DC, lbl_8804BB40, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41788_889D5818(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD8DC, (ts4_word)(ts4_word)lbl_8803D124, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804BB40, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B41788, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5888: call_seq lbl_88B3DA0C, lbl_8803CAF0, lbl_88CAD90C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3DA0C_889D5888(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD90C, (ts4_word)(ts4_word)lbl_8803CAF0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3DA0C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D58F8: call_seq lbl_88B3DA3C, lbl_8803D194, lbl_88CAD93C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3DA3C_889D58F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD93C, (ts4_word)(ts4_word)lbl_8803D194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3DA3C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5968: call_seq lbl_88B3DA70, lbl_8803D6A0, lbl_88CAD96C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3DA70_889D5968(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD96C, (ts4_word)(ts4_word)lbl_8803D6A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3DA70, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D59D8: call_seq lbl_88B3DB30, lbl_8803D914, lbl_88CAD99C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3DB30_889D59D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD99C, (ts4_word)(ts4_word)lbl_8803D914, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3DB30, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5A48: call_seq lbl_88B3DB48, lbl_8803D9E8, lbl_88CAD9CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3DB48_889D5A48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD9CC, (ts4_word)(ts4_word)lbl_8803D9E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3DB48, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5AB8: call_seq lbl_88B3DBC0, lbl_8803F5C8, lbl_88CAD9FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3DBC0_889D5AB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAD9FC, (ts4_word)(ts4_word)lbl_8803F5C8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3DBC0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5B28: call_seq lbl_88B3DC50, lbl_8804C310, lbl_88CADA2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3DC50_889D5B28(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADA2C, (ts4_word)(ts4_word)lbl_8804C310, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3DC50, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5B98: call_seq lbl_88B3DC80, lbl_8803ED20, lbl_88CADA5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3DC80_889D5B98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADA5C, (ts4_word)(ts4_word)lbl_8803ED20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3DC80, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5C08: addr lbl_88B41848, u32@lbl_88B3DA6C, u32@0x8 */
void ts4_addr_lbl_88B41848_889D5C08(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B41848) + 8) = (ts4_word)(*(ts4_word *)lbl_88B3DA6C);
    return;
}

/* Swing_DLL.xex 0x889D5C20: call_seq lbl_88B41848, lbl_8804C33C, lbl_88CADA8C, lbl_8804BB94, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B41848_889D5C20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADA8C, (ts4_word)(ts4_word)lbl_8804C33C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804BB94, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B41848, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5C90: call_seq lbl_88B3DD2C, lbl_8803ED28, lbl_88CADABC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3DD2C_889D5C90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADABC, (ts4_word)(ts4_word)lbl_8803ED28, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3DD2C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5D00: call_seq lbl_88B3DD60, lbl_8803ED14, lbl_88CADAEC, lbl_8804BBD8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3DD60_889D5D00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADAEC, (ts4_word)(ts4_word)lbl_8803ED14, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804BBD8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B3DD60, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5D70: call_seq lbl_88B3DDF0, lbl_8804C348, lbl_88CADB1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3DDF0_889D5D70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADB1C, (ts4_word)(ts4_word)lbl_8804C348, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3DDF0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5DE0: call_seq lbl_88B3DE08, lbl_8804C358, lbl_88CADB4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3DE08_889D5DE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADB4C, (ts4_word)(ts4_word)lbl_8804C358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3DE08, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5E50: addr lbl_88B418C0, u32@lbl_88B3DD5C, u32@0x8 */
void ts4_addr_lbl_88B418C0_889D5E50(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B418C0) + 8) = (ts4_word)(*(ts4_word *)lbl_88B3DD5C);
    return;
}

/* Swing_DLL.xex 0x889D5E68: call_seq lbl_88B418C0, lbl_8804C380, lbl_88CADB7C, lbl_8804BC14, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B418C0_889D5E68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADB7C, (ts4_word)(ts4_word)lbl_8804C380, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8804BC14, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B418C0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5ED8: call_seq lbl_88B3DE38, lbl_88042408, lbl_88CADBAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3DE38_889D5ED8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADBAC, (ts4_word)(ts4_word)lbl_88042408, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3DE38, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5F48: call_seq lbl_88B3DE50, lbl_880423F8, lbl_88CADBDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3DE50_889D5F48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADBDC, (ts4_word)(ts4_word)lbl_880423F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3DE50, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D5FB8: call_seq lbl_88B3DE98, lbl_8804C390, lbl_88CADC0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3DE98_889D5FB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADC0C, (ts4_word)(ts4_word)lbl_8804C390, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3DE98, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6028: call_seq lbl_88B3DEC8, lbl_8804C3A0, lbl_88CADC3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3DEC8_889D6028(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADC3C, (ts4_word)(ts4_word)lbl_8804C3A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3DEC8, (ts4_word)12, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6098: call_seq lbl_88B3DFE8, lbl_8804C3B0, lbl_88CADC6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3DFE8_889D6098(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADC6C, (ts4_word)(ts4_word)lbl_8804C3B0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3DFE8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6108: call_seq lbl_88B3E078, lbl_8804C3C4, lbl_88CADC9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E078_889D6108(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADC9C, (ts4_word)(ts4_word)lbl_8804C3C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E078, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6178: call_seq lbl_88B3E138, lbl_8804C3DC, lbl_88CADCCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E138_889D6178(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADCCC, (ts4_word)(ts4_word)lbl_8804C3DC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E138, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D61E8: call_seq lbl_88B3E210, lbl_8804C3F8, lbl_88CADCFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E210_889D61E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADCFC, (ts4_word)(ts4_word)lbl_8804C3F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E210, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6258: call_seq lbl_88B3E2D0, lbl_8804C410, lbl_88CADD2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E2D0_889D6258(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADD2C, (ts4_word)(ts4_word)lbl_8804C410, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E2D0, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D62C8: call_seq lbl_88B3E378, lbl_8803EEFC, lbl_88CADD5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E378_889D62C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADD5C, (ts4_word)(ts4_word)lbl_8803EEFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E378, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6338: call_seq lbl_88B3E3C0, lbl_8803EEE8, lbl_88CADD8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E3C0_889D6338(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADD8C, (ts4_word)(ts4_word)lbl_8803EEE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E3C0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D63A8: call_seq lbl_88B3E420, lbl_8803EE7C, lbl_88CADDBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E420_889D63A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADDBC, (ts4_word)(ts4_word)lbl_8803EE7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E420, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6418: call_seq lbl_88B3E450, lbl_8803F5BC, lbl_88CADDEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E450_889D6418(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADDEC, (ts4_word)(ts4_word)lbl_8803F5BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E450, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6488: call_seq lbl_88B3E558, lbl_8804C428, lbl_88CADE1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E558_889D6488(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADE1C, (ts4_word)(ts4_word)lbl_8804C428, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E558, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D64F8: call_seq lbl_88B3E5B8, lbl_8803F5E0, lbl_88CADE4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E5B8_889D64F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADE4C, (ts4_word)(ts4_word)lbl_8803F5E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E5B8, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6568: call_seq lbl_88B3E6A8, lbl_88040278, lbl_88CADE7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E6A8_889D6568(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADE7C, (ts4_word)(ts4_word)lbl_88040278, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E6A8, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D65D8: call_seq lbl_88B3E780, lbl_8803ED58, lbl_88CADEAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E780_889D65D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADEAC, (ts4_word)(ts4_word)lbl_8803ED58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E780, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6648: call_seq lbl_88B3E7B0, lbl_8803ED40, lbl_88CADEDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E7B0_889D6648(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADEDC, (ts4_word)(ts4_word)lbl_8803ED40, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E7B0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D66B8: call_seq lbl_88B3E7C8, lbl_88046454, lbl_88CADF0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E7C8_889D66B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADF0C, (ts4_word)(ts4_word)lbl_88046454, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E7C8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6728: call_seq lbl_88B3E828, lbl_88CADF0C, lbl_8804233C, lbl_88CADF3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E828_889D6728(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADF3C, (ts4_word)(ts4_word)lbl_8804233C, (ts4_word)(ts4_word)lbl_88CADF0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E828, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D67A0: call_seq lbl_880469C4, lbl_88CADF6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880469C4_889D67A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADF6C, (ts4_word)(ts4_word)lbl_880469C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6800: call_seq lbl_88B3E870, lbl_88CAF67C, lbl_88042E48, lbl_88CADF9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E870_889D6800(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADF9C, (ts4_word)(ts4_word)lbl_88042E48, (ts4_word)(ts4_word)lbl_88CAF67C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E870, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6878: call_seq lbl_88046B60, lbl_88CADFCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046B60_889D6878(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADFCC, (ts4_word)(ts4_word)lbl_88046B60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D68D8: call_seq lbl_88CAD81C, lbl_88042318, lbl_88CADFFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAD81C_889D68D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CADFFC, (ts4_word)(ts4_word)lbl_88042318, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6940: call_seq lbl_88046A84, lbl_88CAE02C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A84_889D6940(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE02C, (ts4_word)(ts4_word)lbl_88046A84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D69A0: call_seq lbl_88B3E8D0, lbl_88CADFFC, lbl_8804232C, lbl_88CAE05C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E8D0_889D69A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE05C, (ts4_word)(ts4_word)lbl_8804232C, (ts4_word)(ts4_word)lbl_88CADFFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E8D0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6A18: call_seq lbl_88B3E900, lbl_88CADFFC, lbl_8804690C, lbl_88CAE08C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E900_889D6A18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE08C, (ts4_word)(ts4_word)lbl_8804690C, (ts4_word)(ts4_word)lbl_88CADFFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E900, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6A90: call_seq lbl_88CADFFC, lbl_8804671C, lbl_88CAE0BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CADFFC_889D6A90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE0BC, (ts4_word)(ts4_word)lbl_8804671C, (ts4_word)(ts4_word)lbl_88CADFFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6AF8: call_seq lbl_88046A50, lbl_88CAE0EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A50_889D6AF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE0EC, (ts4_word)(ts4_word)lbl_88046A50, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6B58: call_seq lbl_88B3E918, lbl_88CAD81C, lbl_88041284, lbl_88CAE11C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E918_889D6B58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE11C, (ts4_word)(ts4_word)lbl_88041284, (ts4_word)(ts4_word)lbl_88CAD81C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E918, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6BD0: call_seq lbl_88B3E930, lbl_88046220, lbl_88CAE14C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E930_889D6BD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE14C, (ts4_word)(ts4_word)lbl_88046220, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E930, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6C40: call_seq lbl_88B3E990, lbl_88CAE26C, lbl_8804694C, lbl_88CAE17C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E990_889D6C40(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE17C, (ts4_word)(ts4_word)lbl_8804694C, (ts4_word)(ts4_word)lbl_88CAE26C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E990, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6CB8: call_seq lbl_88B3E9A8, lbl_88CAE11C, lbl_88040110, lbl_88CAE1AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E9A8_889D6CB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE1AC, (ts4_word)(ts4_word)lbl_88040110, (ts4_word)(ts4_word)lbl_88CAE11C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E9A8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6D30: call_seq lbl_88B3E9D8, lbl_88CAE11C, lbl_88040100, lbl_88CAE1DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E9D8_889D6D30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE1DC, (ts4_word)(ts4_word)lbl_88040100, (ts4_word)(ts4_word)lbl_88CAE11C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E9D8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6DA8: call_seq lbl_88B3E9F0, lbl_88CAE26C, lbl_8804011C, lbl_88CAE20C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3E9F0_889D6DA8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE20C, (ts4_word)(ts4_word)lbl_8804011C, (ts4_word)(ts4_word)lbl_88CAE26C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3E9F0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6E20: call_seq lbl_88B3EA20, lbl_88CAE11C, lbl_880400A8, lbl_88CAE23C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EA20_889D6E20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE23C, (ts4_word)(ts4_word)lbl_880400A8, (ts4_word)(ts4_word)lbl_88CAE11C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EA20, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6E98: call_seq lbl_88B3EA38, lbl_88CAE71C, lbl_88042370, lbl_88CAE26C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EA38_889D6E98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE26C, (ts4_word)(ts4_word)lbl_88042370, (ts4_word)(ts4_word)lbl_88CAE71C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EA38, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6F10: call_seq lbl_88B3EA50, lbl_88CAE47C, lbl_88041B24, lbl_88CAE29C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EA50_889D6F10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE29C, (ts4_word)(ts4_word)lbl_88041B24, (ts4_word)(ts4_word)lbl_88CAE47C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EA50, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D6F88: call_seq lbl_88B3EA68, lbl_88CAE23C, lbl_880468C8, lbl_88CAE2CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EA68_889D6F88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE2CC, (ts4_word)(ts4_word)lbl_880468C8, (ts4_word)(ts4_word)lbl_88CAE23C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EA68, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7000: call_seq lbl_88B3EAB0, lbl_88CAE26C, lbl_880400E8, lbl_88CAE2FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EAB0_889D7000(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE2FC, (ts4_word)(ts4_word)lbl_880400E8, (ts4_word)(ts4_word)lbl_88CAE26C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EAB0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7078: call_seq lbl_88B3EAE0, lbl_88CAE26C, lbl_880400D0, lbl_88CAE32C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EAE0_889D7078(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE32C, (ts4_word)(ts4_word)lbl_880400D0, (ts4_word)(ts4_word)lbl_88CAE26C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EAE0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D70F0: call_seq lbl_88B3EB10, lbl_880463D4, lbl_88CAE35C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EB10_889D70F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE35C, (ts4_word)(ts4_word)lbl_880463D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EB10, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7160: call_seq lbl_88B3EB58, lbl_88CAE26C, lbl_88046868, lbl_88CAE38C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EB58_889D7160(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE38C, (ts4_word)(ts4_word)lbl_88046868, (ts4_word)(ts4_word)lbl_88CAE26C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EB58, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D71D8: call_seq lbl_88B3EBD0, lbl_88CAE26C, lbl_8803EFC0, lbl_88CAE3BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EBD0_889D71D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE3BC, (ts4_word)(ts4_word)lbl_8803EFC0, (ts4_word)(ts4_word)lbl_88CAE26C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EBD0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7250: call_seq lbl_88CAE50C, lbl_880467DC, lbl_88CAE3EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAE50C_889D7250(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE3EC, (ts4_word)(ts4_word)lbl_880467DC, (ts4_word)(ts4_word)lbl_88CAE50C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D72B8: call_seq lbl_88CAE11C, lbl_88046AE0, lbl_88CAE41C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CAE11C_889D72B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE41C, (ts4_word)(ts4_word)lbl_88046AE0, (ts4_word)(ts4_word)lbl_88CAE11C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7320: call_seq lbl_88B3EC48, lbl_88042358, lbl_88CAE44C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EC48_889D7320(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE44C, (ts4_word)(ts4_word)lbl_88042358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EC48, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7390: call_seq lbl_88B3EC78, lbl_88CAE23C, lbl_8804234C, lbl_88CAE47C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EC78_889D7390(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE47C, (ts4_word)(ts4_word)lbl_8804234C, (ts4_word)(ts4_word)lbl_88CAE23C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EC78, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7408: call_seq lbl_88B3EC90, lbl_88046320, lbl_88CAE4AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B3EC90_889D7408(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CAE4AC, (ts4_word)(ts4_word)lbl_88046320, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B3EC90, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x889D7478: addr lbl_88B41938, u32@lbl_88B3ECA8, u32@0x68 */
void ts4_addr_lbl_88B41938_889D7478(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B41938) + 104) = (ts4_word)(*(ts4_word *)lbl_88B3ECA8);
    return;
}
