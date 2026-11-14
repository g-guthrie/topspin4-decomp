/* Small accessor / thunk / constructor-like functions (family I, round 3).
   Each function belongs to a cluster of byte-identical functions found in
   Swing_DLL.xex (Xbox 360, MSVC 16.00.10224.00); the original address is in the
   comment above each definition. Bodies were derived from the disassembly and
   verified byte-for-byte with tools/fn_check.py. Parameters are untyped words
   (a0 = this/first argument); field accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char g_ts4_session_context[];
extern char lbl_880D5B10[];
extern char lbl_880D5B34[];
extern char lbl_880D60C0[];
extern char lbl_880D6B70[];
extern char lbl_880F43E8[];
extern char lbl_880F5918[];
extern char lbl_880F5930[];
extern char lbl_880F76D4[];
extern char lbl_880F76D8[];
extern char lbl_880F8608[];
extern char lbl_88C476A4[];
extern char lbl_88D3CD50[];
extern char lbl_88D41FC4[];
extern char lbl_88D45918[];
extern char lbl_88D459D4[];
extern char lbl_88D459E8[];
extern char lbl_88D45A08[];
extern char lbl_88D45A48[];
extern char lbl_88D45A84[];
extern char lbl_88D45B18[];
extern char lbl_88D45B1C[];
ts4_word ts4_if_call_seq_u32_off0_8819B0C8(ts4_word, ts4_word);
ts4_word fn_881B3778(ts4_word, ts4_word);
ts4_word fn_881B9148(ts4_word);
ts4_word ts4_loop_get_u32_off10_882109B8(ts4_word);
ts4_word ts4_loop_get_u32_off10_88210A68(ts4_word);
ts4_word fn_884F0318(ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word fn_884F0350(ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word fn_8856A3A0(ts4_word, ts4_word);
ts4_word fn_8857C1F8(ts4_word);
ts4_word fn_886140B8(ts4_word, ts4_word);
ts4_word fn_886197F0();
ts4_word fn_886198E0();
ts4_word ts4_if_get_u32_off0_8861AA88(ts4_word);
ts4_word fn_886220F8(ts4_word, ts4_word);
ts4_word fn_88636FA0(ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word ts4_type_register_886529C8(ts4_word);
ts4_word ts4_call_seq_lbl_880F5230_88652A90();
ts4_word fn_88655BC8(ts4_word);
ts4_word fn_88655C90(ts4_word);
ts4_word fn_886CA530(ts4_word);
ts4_word fn_886CA610(ts4_word);
ts4_word fn_886CF110(ts4_word);
ts4_word fn_886D9070(ts4_word);
ts4_word fn_887040A0(ts4_word, ts4_word);
ts4_word fn_88704288(ts4_word);
ts4_word fn_887043D8(ts4_word, ts4_word);
ts4_word fn_88704528(ts4_word, ts4_word);
ts4_word fn_887140B8(ts4_word, ts4_word);
ts4_word fn_887141A0(ts4_word, ts4_word);
ts4_word fn_88714280(ts4_word, ts4_word);
ts4_word fn_88714348(ts4_word, ts4_word);
ts4_word fn_887143E0(ts4_word, ts4_word);
ts4_word fn_88714478(ts4_word, ts4_word);
ts4_word ts4_if_set_ts4_handle_forward_88150770_88722000(ts4_word, ts4_word);
ts4_word ts4_if_get_ts4_handle_forward_88150770_88722610(ts4_word, ts4_word);
ts4_word fn_887563A8(ts4_word);
ts4_word fn_887D7D98(ts4_word, ts4_word, ts4_word);
ts4_word fn_887EC120(ts4_word);
ts4_word fn_887ECBD0();
ts4_word lua2_luaK_wstringK_888207C8(ts4_word, ts4_word);
ts4_word lua2_luaK_stringK_88820AF0(ts4_word, ts4_word);
ts4_word fn_88822420(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word lib3_lua_type_88822738(ts4_word, ts4_word);
ts4_word fn_8883F238();
ts4_word fn_8884E2A0(ts4_word);
ts4_word fn_8885B210(ts4_word);
ts4_word ts4_loop_call_seq_u32_off30_8886B150(ts4_word, ts4_word, ts4_word);
ts4_word fn_8886CC78(ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word ex3_inflateInit2__88875B18(ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word fn_8887C748(ts4_word);
ts4_word fn_888B1960(ts4_word);
ts4_word fn_888C93E8(ts4_word);
ts4_word fn_888D5340(ts4_word, ts4_word, ts4_word);
ts4_word fn_88916750(ts4_word, ts4_word);
ts4_word fn_88918908(ts4_word);
ts4_word fn_88919348(ts4_word);
ts4_word ts4_if_call_seq_u32_off20_88921680(ts4_word, ts4_word);
ts4_word fn_88926A70();
ts4_word fn_88926B40();
ts4_word fn_8892F328(ts4_word);
ts4_word fn_889395D8(ts4_word, ts4_word);
ts4_word fn_88939738(ts4_word, ts4_word);
ts4_word fn_88941780(ts4_word);
ts4_word fn_889461A8(ts4_word);
ts4_word ts4_find_service(ts4_word);
ts4_word ts4_object_finalize(ts4_word);

/* Swing_DLL.xex 0x885F94F0: get u16@0x30 */
ts4_word ts4_get_u16_off30_885F94F0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(a0) + 48));
}

/* Swing_DLL.xex 0x885F94F8: get u16@0x2e */
ts4_word ts4_get_u16_off2e_885F94F8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(a0) + 46));
}

/* Swing_DLL.xex 0x885F9508: get u16@0x2a */
ts4_word ts4_get_u16_off2a_885F9508(ts4_word a0)
{
    return (*(unsigned short *)((char *)(a0) + 42));
}

/* Swing_DLL.xex 0x885F9518: get u16@0x26 */
ts4_word ts4_get_u16_off26_885F9518(ts4_word a0)
{
    return (*(unsigned short *)((char *)(a0) + 38));
}

/* Swing_DLL.xex 0x885F98C8: get u16@0x30 */
ts4_word ts4_get_u16_off30_885F98C8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(a0) + 48));
}

/* Swing_DLL.xex 0x885F98D8: get u32@0x28 */
ts4_word ts4_get_u32_off28_885F98D8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(a0) + 40));
}

/* Swing_DLL.xex 0x885FAF30: fn  */
ts4_word ts4_fn_885FAF30(void)
{
    return 30;
}

/* Swing_DLL.xex 0x885FB0C0: fn  */
ts4_word ts4_fn_885FB0C0(void)
{
    return 32;
}

/* Swing_DLL.xex 0x885FB6B0: fn  */
ts4_word ts4_fn_885FB6B0(void)
{
    return 30;
}

/* Swing_DLL.xex 0x88601180: set u32@0x2c */
ts4_word ts4_set_u32_off2c_88601180(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(a0) + 44) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x886011A0: set u32@0x24 */
ts4_word ts4_set_u32_off24_886011A0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(a0) + 36) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88601368: fn  */
ts4_word ts4_fn_88601368(void)
{
    return 26;
}

/* Swing_DLL.xex 0x88602990: set u32@0x2c */
ts4_word ts4_set_u32_off2c_88602990(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(a0) + 44) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x886029B0: set u32@0x24 */
ts4_word ts4_set_u32_off24_886029B0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(a0) + 36) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88602A70: set u32@0x24 */
ts4_word ts4_set_u32_off24_88602A70(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(a0) + 36) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88602F60: fn  */
ts4_word ts4_fn_88602F60(void)
{
    return 26;
}

/* Swing_DLL.xex 0x886032E8: fn  */
ts4_word ts4_fn_886032E8(void)
{
    return 30;
}

/* Swing_DLL.xex 0x88603D28: set u32@0x0 */
ts4_word ts4_set_u32_off0_88603D28(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)a1;
    return 4;
}

/* Swing_DLL.xex 0x88603D58: set u32@0x0 */
ts4_word ts4_set_u32_off0_88603D58(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)a1;
    return 4;
}

/* Swing_DLL.xex 0x88605DE8: call_seq lbl_880F76D8, fn_8856A3A0 */
ts4_word ts4_call_seq_lbl_880F76D8_88605DE8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    (void)a0;
    t1 = fn_8856A3A0((ts4_word)(ts4_word)lbl_880F76D8, (ts4_word)a1);
    return (t1 == 0);
}

/* Swing_DLL.xex 0x88605E18: call_seq lbl_880F76D4, fn_8856A3A0 */
ts4_word ts4_call_seq_lbl_880F76D4_88605E18(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    (void)a0;
    t1 = fn_8856A3A0((ts4_word)(ts4_word)lbl_880F76D4, (ts4_word)a1);
    return (t1 == 0);
}

/* Swing_DLL.xex 0x88606040: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_88606040(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)a2;
    return;
}

/* Swing_DLL.xex 0x88606540: get u32@-0x8 */
ts4_word ts4_get_u32_0x8_88606540(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(ts4_word *)((char *)(a1) + -8));
}

/* Swing_DLL.xex 0x88606668: get u32@0x0, u32@0x4c */
ts4_word ts4_get_u32_off0_88606668(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 0))) + 76))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88606B00: get u32@0x0, u32@0x4c */
ts4_word ts4_get_u32_off0_88606B00(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 0))) + 76))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88607A28: get u32@0x0, u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_88607A28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(a0) + 0);
    t2 = *(ts4_word *)((char *)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(t1) + 8))))((ts4_word)a0, (ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88607A40: get u32@0x0, u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_88607A40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(a0) + 0);
    t2 = *(ts4_word *)((char *)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(t1) + 8))))((ts4_word)a0, (ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88607AA8: get u32@0x0, u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_88607AA8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(a0) + 0);
    t2 = *(ts4_word *)((char *)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(t1) + 8))))((ts4_word)a0, (ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88607AE0: get u32@0xc, u32@0x8 */
ts4_word ts4_get_u32_offc_88607AE0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 12);
    return ((int)(t1 - (*(ts4_word *)((char *)(a0) + 8))) >> 2);
}

/* Swing_DLL.xex 0x88607B88: if_get u32@0x4, u32@0x2c, u32@0x38, u32@0xc */
ts4_word ts4_if_get_u32_off4_88607B88(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a1;
    t1 = *(ts4_word *)((char *)(a0) + 4);
    if ((ts4_word)a2 != (ts4_word)((983040) | 65535)) {
        t2 = *(ts4_word *)((char *)(t1) + 44);
        t3 = *(ts4_word *)((char *)(t1) + 56);
        return ((((*(ts4_word *)((char *)((t2 + (a2 << 4))) + 12))) >> 5) + t3);
    }
    return 0;
}

/* Swing_DLL.xex 0x88607BC8: if_get u32@0x4, u32@0x2c, u32@0x38, u32@0xc */
ts4_word ts4_if_get_u32_off4_88607BC8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a1;
    t1 = *(ts4_word *)((char *)(a0) + 4);
    if ((ts4_word)a2 != (ts4_word)((983040) | 65535)) {
        t2 = *(ts4_word *)((char *)(t1) + 44);
        t3 = *(ts4_word *)((char *)(t1) + 56);
        return ((((*(ts4_word *)((char *)((t2 + (a2 << 4))) + 12))) >> 5) + t3);
    }
    return 0;
}

/* Swing_DLL.xex 0x88608058: set u32@0x4, u32@0x8 */
void ts4_set_u32_off4_88608058(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)a2;
    return;
}

/* Swing_DLL.xex 0x886085E8: get u32@0x178 */
ts4_word ts4_get_u32_off178_886085E8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(a0) + 376));
}

/* Swing_DLL.xex 0x88608850: get u32@0x178 */
ts4_word ts4_get_u32_off178_88608850(ts4_word a0)
{
    return (*(ts4_word *)((char *)(a0) + 376));
}

/* Swing_DLL.xex 0x88608948: get u32@0x178 */
ts4_word ts4_get_u32_off178_88608948(ts4_word a0)
{
    return (*(ts4_word *)((char *)(a0) + 376));
}

/* Swing_DLL.xex 0x88609468: get u32@0x40 */
ts4_word ts4_get_u32_off40_88609468(ts4_word a0)
{
    return (*(ts4_word *)((char *)(a0) + 64));
}

/* Swing_DLL.xex 0x8860B4C0: if_get u32@0x4, u32@0x2c, u32@0x38, u32@0xc */
ts4_word ts4_if_get_u32_off4_8860B4C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a1;
    t1 = *(ts4_word *)((char *)(a0) + 4);
    if ((ts4_word)a2 != (ts4_word)((983040) | 65535)) {
        t2 = *(ts4_word *)((char *)(t1) + 44);
        t3 = *(ts4_word *)((char *)(t1) + 56);
        return ((((*(ts4_word *)((char *)((t2 + (a2 << 4))) + 12))) >> 5) + t3);
    }
    return 0;
}

/* Swing_DLL.xex 0x8860BD30: get u32@0x10, fn_8857C1F8 */
ts4_word ts4_get_u32_off10_8860BD30(ts4_word a0)
{
    return fn_8857C1F8((ts4_word)(*(ts4_word *)((char *)(a0) + 16)));
}

/* Swing_DLL.xex 0x8861EF28: call_seq ts4_object_finalize, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_ts4_object_finalize_8861EF28(ts4_word a0)
{
    ts4_word t2;

    ts4_object_finalize((ts4_word)(a0 + 32));
    *(unsigned char *)((char *)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}

/* Swing_DLL.xex 0x88620C10: call_seq fn_886197F0, lbl_880F8608, u32@0x178, u32@0x17c, u32@0x0, u32@0x180 */
ts4_word ts4_call_seq_fn_886197F0_88620C10(ts4_word a0)
{
    fn_886197F0();
    *(ts4_word *)((char *)(a0) + 376) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 380) = (ts4_word)16;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8608;
    *(ts4_word *)((char *)(a0) + 384) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 388) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 392) = (ts4_word)16;
    *(unsigned char *)((char *)(a0) + 396) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x88620C70: call_seq fn_886198E0, lbl_880F8608, u32@0x178, u32@0x17c, u32@0x0, u32@0x180 */
ts4_word ts4_call_seq_fn_886198E0_88620C70(ts4_word a0)
{
    fn_886198E0();
    *(ts4_word *)((char *)(a0) + 376) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 380) = (ts4_word)16;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8608;
    *(ts4_word *)((char *)(a0) + 384) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 388) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 392) = (ts4_word)16;
    *(unsigned char *)((char *)(a0) + 396) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x88621460: get u32@0x224, ts4_if_get_u32_off0_8861AA88 */
ts4_word ts4_get_u32_off224_88621460(ts4_word a0)
{
    return ts4_if_get_u32_off0_8861AA88((ts4_word)(*(ts4_word *)((char *)(a0) + 548)));
}

/* Swing_DLL.xex 0x88636E30: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_88636E30(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(a1) + 0));
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(a1) + 4));
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(a1) + 8));
    return;
}

/* Swing_DLL.xex 0x88636E50: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_88636E50(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(a1) + 0));
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(a1) + 4));
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(a1) + 8));
    return;
}

/* Swing_DLL.xex 0x88637158: get u32@lbl_88D45B18, fn_88636FA0 */
ts4_word ts4_get_u32_lbl_88D45B18_88637158(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88636FA0((ts4_word)(*(ts4_word *)lbl_88D45B18), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88644A40: get u32@0x70 */
ts4_word ts4_get_u32_off70_88644A40(ts4_word a0)
{
    return (*(ts4_word *)((char *)(a0) + 112));
}

/* Swing_DLL.xex 0x8864D2B8: set u8@0xd, u8@0xe, u32@0x0, u32@0x4, u32@0x8, u32@0x10 */
void ts4_set_u8_offd_8864D2B8(ts4_word a0)
{
    *(unsigned char *)((char *)(a0) + 13) = (unsigned char)0;
    *(unsigned char *)((char *)(a0) + 14) = (unsigned char)0;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 36) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8864D2E8: set u8@0xd, u8@0xe, u32@0x0, u32@0x4, u32@0x8, u32@0x10 */
void ts4_set_u8_offd_8864D2E8(ts4_word a0)
{
    *(unsigned char *)((char *)(a0) + 13) = (unsigned char)0;
    *(unsigned char *)((char *)(a0) + 14) = (unsigned char)0;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 36) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8864DEA8: get u32@0x4, fn_884F0350 */
ts4_word ts4_get_u32_off4_8864DEA8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_884F0350((ts4_word)(*(ts4_word *)((char *)(a0) + 4)), (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Swing_DLL.xex 0x8864DEB8: get u32@0x4, fn_884F0318 */
ts4_word ts4_get_u32_off4_8864DEB8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_884F0318((ts4_word)(*(ts4_word *)((char *)(a0) + 4)), (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Swing_DLL.xex 0x8864F530: addr lbl_880F5930, u32@0x4, u32@0x0, u32@0x8, u32@0x10, u32@0xc */
void ts4_addr_lbl_880F5930_8864F530(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5930;
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8864F578: addr lbl_880F5918, u32@0x4, u32@0x0, u32@0x8, u32@0x10, u32@0xc */
void ts4_addr_lbl_880F5918_8864F578(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5918;
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88654220: call_seq ts4_call_seq_lbl_880F5230_88652A90, ts4_type_register_886529C8 */
ts4_word ts4_call_seq_fn_88652A90_88654220(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_call_seq_lbl_880F5230_88652A90();
    t2 = ts4_type_register_886529C8((ts4_word)t1);
    return t2;
}

/* Swing_DLL.xex 0x88656EC0: get u32@0x8, fn_88655C90 */
ts4_word ts4_get_u32_off8_88656EC0(ts4_word a0)
{
    return fn_88655C90((ts4_word)(*(ts4_word *)((char *)(a0) + 8)));
}

/* Swing_DLL.xex 0x88656EC8: get u32@0x8, fn_88655BC8 */
ts4_word ts4_get_u32_off8_88656EC8(ts4_word a0)
{
    return fn_88655BC8((ts4_word)(*(ts4_word *)((char *)(a0) + 8)));
}

/* Swing_DLL.xex 0x88657558: get u32@0x1c, u32@0x14, vcall, u8@0x8, fn_881B9148 */
ts4_word ts4_get_u32_off1c_88657558(ts4_word a0)
{
    ts4_word t4;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 28))) + 20))))((ts4_word)(a0 + 28));
    *(unsigned char *)((char *)(a0) + 8) = (unsigned char)0;
    t4 = fn_881B9148((ts4_word)(a0 + 16));
    return t4;
}

/* Swing_DLL.xex 0x8865A290: get u32@0x24, u32@0x10, u32@0xb8 */
ts4_word ts4_get_u32_off24_8865A290(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(a0) + 36);
    t2 = *(ts4_word *)((char *)(a0) + 16);
    return (*(ts4_word *)((char *)(((*(ts4_word *)((char *)(t1) + 184)) << 2)) + t2));
}

/* Swing_DLL.xex 0x8865A2A8: get u32@0x24, u32@0x10, u32@0xb8 */
ts4_word ts4_get_u32_off24_8865A2A8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(a0) + 36);
    t2 = *(ts4_word *)((char *)(a0) + 16);
    return (*(ts4_word *)((char *)(((*(ts4_word *)((char *)(t1) + 184)) << 2)) + t2));
}

/* Swing_DLL.xex 0x88660E18: get u32@0x18, u32@0x78, u32@0xe0, u8@0x0 */
void ts4_get_u32_off18_88660E18(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(unsigned char *)((char *)(a2) + 0) = (unsigned char)(((*(ts4_word *)((char *)((*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 24))) + 120))) + 224)) - a1) == 0);
    return;
}

/* Swing_DLL.xex 0x88660EC8: get u32@0x1c, u32@0x8, u8@0x0 */
void ts4_get_u32_off1c_88660EC8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(unsigned char *)((char *)(a2) + 0) = (unsigned char)(((*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 28))) + 8)) - a1) == 0);
    return;
}

/* Swing_DLL.xex 0x88679F98: addr lbl_880F43E8, u32@0x4, u32@0x0, u32@0x8, u32@0xc, u32@0x10 */
void ts4_addr_lbl_880F43E8_88679F98(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F43E8;
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 24) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886A0678: call_seq fn_886CF110, u32@0x1c, u32@0x18 */
ts4_word ts4_call_seq_fn_886CF110_886A0678(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_886CF110((ts4_word)a0);
    *(ts4_word *)((char *)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 24) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x886A0818: call_seq fn_886CF110, u32@0x1c, u32@0x18 */
ts4_word ts4_call_seq_fn_886CF110_886A0818(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_886CF110((ts4_word)a0);
    *(ts4_word *)((char *)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 24) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x886C3588: fn  */
ts4_word ts4_fn_886C3588(ts4_word a0, ts4_word a1)
{
    return (a0 + a1);
}

/* Swing_DLL.xex 0x886C3648: get u32@0x20 */
ts4_word ts4_get_u32_off20_886C3648(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(a0) + 32)) != 0);
}

/* Swing_DLL.xex 0x886C3BE8: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_886C3BE8(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886C3DF8: get u32@0x0 */
ts4_word ts4_get_u32_off0_886C3DF8(ts4_word a0, ts4_word a1)
{
    return ((a1 << 4) + (*(ts4_word *)((char *)(a0) + 0)));
}

/* Swing_DLL.xex 0x886C4588: addr lbl_880D6B70, u32@0x4, u32@0x0, u32@0x8, u32@0xc, u32@0x10 */
void ts4_addr_lbl_880D6B70_886C4588(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6B70;
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 24) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886C6558: set u32@0x74 */
void ts4_set_u32_off74_886C6558(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 116) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886CD560: get u32@0x28, u32@0x4b4, fn_886CA530 */
ts4_word ts4_get_u32_off28_886CD560(ts4_word a0)
{
    return fn_886CA530((ts4_word)(*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 40))) + 1204)));
}

/* Swing_DLL.xex 0x886CD570: get u32@0x28, u32@0x4b4, fn_886CA610 */
ts4_word ts4_get_u32_off28_886CD570(ts4_word a0)
{
    return fn_886CA610((ts4_word)(*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 40))) + 1204)));
}

/* Swing_DLL.xex 0x886DA838: get u32@0x28, fn_886D9070 */
ts4_word ts4_get_u32_off28_886DA838(ts4_word a0)
{
    return fn_886D9070((ts4_word)(*(ts4_word *)((char *)(a0) + 40)));
}

/* Swing_DLL.xex 0x886DABC8: get u32@0x28, fn_886D9070 */
ts4_word ts4_get_u32_off28_886DABC8(ts4_word a0)
{
    return fn_886D9070((ts4_word)(*(ts4_word *)((char *)(a0) + 40)));
}

/* Swing_DLL.xex 0x886EBD68: set u32@lbl_88D45A84 */
void ts4_set_u32_lbl_88D45A84_886EBD68(void)
{
    *(ts4_word *)lbl_88D45A84 = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886ECF68: set u32@0x8, u32@0xc */
void ts4_set_u32_off8_886ECF68(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88719CD8: call_seq fn_887143E0, fn_88714348, fn_88714478, fn_88714280, fn_887141A0, fn_887140B8 */
ts4_word ts4_call_seq_fn_887143E0_88719CD8(ts4_word a0, ts4_word a1)
{
    ts4_word t6;

    fn_887143E0((ts4_word)a0, (ts4_word)a1);
    fn_88714348((ts4_word)a0, (ts4_word)a1);
    fn_88714478((ts4_word)a0, (ts4_word)a1);
    fn_88714280((ts4_word)a0, (ts4_word)a1);
    fn_887141A0((ts4_word)a0, (ts4_word)a1);
    t6 = fn_887140B8((ts4_word)a0, (ts4_word)a1);
    return t6;
}

/* Swing_DLL.xex 0x8872B560: call_seq fn_88704288, fn_887043D8, fn_88704528, ts4_if_get_ts4_handle_forward_88150770_88722610, ts4_if_set_ts4_handle_forward_88150770_88722000, fn_887040A0 */
ts4_word ts4_call_seq_fn_88704288_8872B560(ts4_word a0, ts4_word a1)
{
    ts4_word t6;

    fn_88704288((ts4_word)a0);
    fn_887043D8((ts4_word)a0, (ts4_word)a1);
    fn_88704528((ts4_word)a0, (ts4_word)a1);
    ts4_if_get_ts4_handle_forward_88150770_88722610((ts4_word)a0, (ts4_word)a1);
    ts4_if_set_ts4_handle_forward_88150770_88722000((ts4_word)a0, (ts4_word)a1);
    t6 = fn_887040A0((ts4_word)a0, (ts4_word)a1);
    return t6;
}

/* Swing_DLL.xex 0x887567D0: get u32@0x10, fn_887563A8 */
ts4_word ts4_get_u32_off10_887567D0(ts4_word a0)
{
    return fn_887563A8((ts4_word)(*(ts4_word *)((char *)(a0) + 16)));
}

/* Swing_DLL.xex 0x88778398: addr lbl_88C476A4 */
ts4_word ts4_addr_lbl_88C476A4_88778398(void)
{
    return (ts4_word)lbl_88C476A4;
}

/* Swing_DLL.xex 0x887783A8: addr lbl_88C476A4 */
ts4_word ts4_addr_lbl_88C476A4_887783A8(void)
{
    return (ts4_word)lbl_88C476A4;
}

/* Swing_DLL.xex 0x88778D18: get u32@g_ts4_session_context, u32@0x1c */
ts4_word ts4_get_u32_g_ts4_session_context_88778D18(void)
{
    return (*(ts4_word *)((char *)((*(ts4_word *)g_ts4_session_context)) + 28));
}

/* Swing_DLL.xex 0x887796A8: get  */
float ts4_get_887796A8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(a1) + 68));
}

/* Swing_DLL.xex 0x887796F8: get  */
void ts4_get_887796F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(float *)((char *)(a1) + 52) = (*(float *)((char *)(a2) + 0));
    return;
}

/* Swing_DLL.xex 0x88779708: get  */
float ts4_get_88779708(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(a1) + 52));
}

/* Swing_DLL.xex 0x887797C0: get u32@lbl_88D45A48, u8@0x71 */
ts4_word ts4_get_u32_lbl_88D45A48_887797C0(void)
{
    return (*(unsigned char *)((char *)((*(ts4_word *)lbl_88D45A48)) + 113));
}

/* Swing_DLL.xex 0x887798E0: get u32@lbl_88D45A48, u8@0x71 */
ts4_word ts4_get_u32_lbl_88D45A48_887798E0(void)
{
    return (*(unsigned char *)((char *)((*(ts4_word *)lbl_88D45A48)) + 113));
}

/* Swing_DLL.xex 0x8877C720: get u32@lbl_88D41FC4, u32@0x70, ts4_loop_get_u32_off10_88210A68 */
ts4_word ts4_get_u32_lbl_88D41FC4_8877C720(void)
{
    return ts4_loop_get_u32_off10_88210A68((ts4_word)(*(ts4_word *)((char *)((*(ts4_word *)lbl_88D41FC4)) + 112)));
}

/* Swing_DLL.xex 0x8877C730: get u32@lbl_88D41FC4, u32@0x70, ts4_loop_get_u32_off10_882109B8 */
ts4_word ts4_get_u32_lbl_88D41FC4_8877C730(void)
{
    return ts4_loop_get_u32_off10_882109B8((ts4_word)(*(ts4_word *)((char *)((*(ts4_word *)lbl_88D41FC4)) + 112)));
}

/* Swing_DLL.xex 0x8877CF20: call_seq u32@0x8, u32@0xc, u32@0x0, fn_88822420 */
ts4_word ts4_call_seq_u32_off8_8877CF20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    t1 = *(ts4_word *)((char *)(a1) + 8);
    t2 = *(ts4_word *)((char *)(a1) + 12);
    fn_88822420((ts4_word)(*(ts4_word *)((char *)(t1) + 0)), (ts4_word)t2, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    return 0;
}

/* Swing_DLL.xex 0x88784590: call_seq ts4_if_call_seq_u32_off0_8819B0C8, u8@0x22, u8@0x22, u32@0x24, u32@0x24, u32@0x28 */
ts4_word ts4_call_seq_fn_8819B0C8_88784590(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = ts4_if_call_seq_u32_off0_8819B0C8((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    *(unsigned char *)((char *)(a0) + 34) = (unsigned char)(*(unsigned char *)((char *)(a1) + 34));
    *(ts4_word *)((char *)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(a1) + 36));
    *(ts4_word *)((char *)(a0) + 40) = (ts4_word)(*(ts4_word *)((char *)(a1) + 40));
    *(ts4_word *)((char *)(a0) + 44) = (ts4_word)(*(ts4_word *)((char *)(a1) + 44));
    return t1;
}

/* Swing_DLL.xex 0x88789828: call_seq ts4_find_service, u32@0x24, u32@0x28, fn_888D5340 */
ts4_word ts4_call_seq_ts4_find_service_88789828(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_find_service((ts4_word)((4216913920) | 23986));
    t2 = *(ts4_word *)((char *)(t1) + 36);
    fn_888D5340((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(t1) + 40)), (ts4_word)t2);
    return 0;
}

/* Swing_DLL.xex 0x88789860: call_seq ts4_find_service, u32@0x24, u32@0x28, fn_888D5340 */
ts4_word ts4_call_seq_ts4_find_service_88789860(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_find_service((ts4_word)((4216913920) | 23986));
    t2 = *(ts4_word *)((char *)(t1) + 36);
    fn_888D5340((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(t1) + 40)), (ts4_word)t2);
    return 0;
}

/* Swing_DLL.xex 0x887C4640: get u32@0x0, u32@0x8, fn_881B3778 */
ts4_word ts4_get_u32_off0_887C4640(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a1) + 0);
    return fn_881B3778((ts4_word)(*(ts4_word *)((char *)(a0) + 8)), (ts4_word)t1);
}

/* Swing_DLL.xex 0x887D97C0: tailcall fn_887D7D98 */
ts4_word ts4_tailcall_fn_887D7D98_887D97C0(ts4_word a0, ts4_word a1)
{
    return fn_887D7D98((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x887ED4C0: call_seq fn_887ECBD0, fn_887EC120 */
ts4_word ts4_call_seq_fn_887ECBD0_887ED4C0(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_887ECBD0();
    t2 = fn_887EC120((ts4_word)t1);
    return t2;
}

/* Swing_DLL.xex 0x88800CF0: get u32@0x1c, u32@0x14, vcall, u8@0x8, fn_881B9148 */
ts4_word ts4_get_u32_off1c_88800CF0(ts4_word a0)
{
    ts4_word t4;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 28))) + 20))))((ts4_word)(a0 + 28));
    *(unsigned char *)((char *)(a0) + 8) = (unsigned char)0;
    t4 = fn_881B9148((ts4_word)(a0 + 16));
    return t4;
}

/* Swing_DLL.xex 0x88803C20: call_seq u32@0x8, u32@0xc, u32@0x0, lib3_lua_type_88822738 */
ts4_word ts4_call_seq_u32_off8_88803C20(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    t1 = *(ts4_word *)((char *)(a1) + 8);
    t2 = *(ts4_word *)((char *)(a1) + 12);
    lib3_lua_type_88822738((ts4_word)(*(ts4_word *)((char *)(t1) + 0)), (ts4_word)t2);
    return 0;
}

/* Swing_DLL.xex 0x8880BFA0: get u32@0x0, u32@0x8, fn_881B3778 */
ts4_word ts4_get_u32_off0_8880BFA0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a1) + 0);
    return fn_881B3778((ts4_word)(*(ts4_word *)((char *)(a0) + 8)), (ts4_word)t1);
}

/* Swing_DLL.xex 0x888134C0: set u32@0x6c */
void ts4_set_u32_off6c_888134C0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(a0) + 108) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88814AE0: call_seq u32@0x30, lua2_luaK_wstringK_888207C8, u32@0x4, u32@0xc, u32@0x10, u32@0x0 */
ts4_word ts4_call_seq_u32_off30_88814AE0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    t2 = lua2_luaK_wstringK_888207C8((ts4_word)(*(ts4_word *)((char *)(a0) + 48)), (ts4_word)a2);
    *(ts4_word *)((char *)(a1) + 4) = (ts4_word)t2;
    *(ts4_word *)((char *)(a1) + 12) = (ts4_word)-1;
    *(ts4_word *)((char *)(a1) + 16) = (ts4_word)-1;
    *(ts4_word *)((char *)(a1) + 0) = (ts4_word)4;
    return t2;
}

/* Swing_DLL.xex 0x88814B30: call_seq u32@0x30, lua2_luaK_stringK_88820AF0, u32@0x4, u32@0xc, u32@0x10, u32@0x0 */
ts4_word ts4_call_seq_u32_off30_88814B30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    t2 = lua2_luaK_stringK_88820AF0((ts4_word)(*(ts4_word *)((char *)(a0) + 48)), (ts4_word)a2);
    *(ts4_word *)((char *)(a1) + 4) = (ts4_word)t2;
    *(ts4_word *)((char *)(a1) + 12) = (ts4_word)-1;
    *(ts4_word *)((char *)(a1) + 16) = (ts4_word)-1;
    *(ts4_word *)((char *)(a1) + 0) = (ts4_word)4;
    return t2;
}

/* Swing_DLL.xex 0x8881EF70: get u32@0x40 */
ts4_word ts4_get_u32_off40_8881EF70(ts4_word a0)
{
    return (*(ts4_word *)((char *)(a0) + 64));
}

/* Swing_DLL.xex 0x8882DB38: if_get u32@0x4, u32@0x0, u32@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_off4_8882DB38(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    t1 = *(ts4_word *)((char *)(a1) + 4);
    if ((ts4_word)t1 == 0) {
        return 0;
    }
    *(ts4_word *)((char *)(a2) + 0) = (ts4_word)t1;
    t2 = *(ts4_word *)((char *)(a1) + 0);
    *(ts4_word *)((char *)(a1) + 4) = (ts4_word)0;
    return t2;
}

/* Swing_DLL.xex 0x8882DB60: if_get u32@0x4, u32@0x0, u32@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_off4_8882DB60(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    t1 = *(ts4_word *)((char *)(a1) + 4);
    if ((ts4_word)t1 == 0) {
        return 0;
    }
    *(ts4_word *)((char *)(a2) + 0) = (ts4_word)t1;
    t2 = *(ts4_word *)((char *)(a1) + 0);
    *(ts4_word *)((char *)(a1) + 4) = (ts4_word)0;
    return t2;
}

/* Swing_DLL.xex 0x88832C68: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_88832C68(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)a2;
    return;
}

/* Swing_DLL.xex 0x888360B8: set u32@0x0, u32@0x8 */
void ts4_set_u32_off0_888360B8(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88836170: get  */
double ts4_get_88836170(ts4_word a0)
{
    return (*(double *)((char *)(a0) + 16));
}

/* Swing_DLL.xex 0x88836178: get  */
double ts4_get_88836178(ts4_word a0)
{
    return (*(double *)((char *)(a0) + 16));
}

/* Swing_DLL.xex 0x888361C0: get u32@0x8 */
ts4_word ts4_get_u32_off8_888361C0(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(a0) + 8)) + -2) == 0);
}

/* Swing_DLL.xex 0x888383B8: set u32@0x8, u32@0xc */
void ts4_set_u32_off8_888383B8(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88838450: set u32@0x8, u32@0xc */
void ts4_set_u32_off8_88838450(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88838490: set u32@0x8 */
void ts4_set_u32_off8_88838490(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x888386F0: get u32@lbl_88D459E8, u32@0x24 */
ts4_word ts4_get_u32_lbl_88D459E8_888386F0(void)
{
    return (*(ts4_word *)((char *)((*(ts4_word *)lbl_88D459E8)) + 36));
}

/* Swing_DLL.xex 0x88838730: get u32@lbl_88D459E8, u32@0x24 */
ts4_word ts4_get_u32_lbl_88D459E8_88838730(void)
{
    return (*(ts4_word *)((char *)((*(ts4_word *)lbl_88D459E8)) + 36));
}

/* Swing_DLL.xex 0x8883D088: call_seq ts4_object_finalize, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_ts4_object_finalize_8883D088(ts4_word a0)
{
    ts4_word t2;

    ts4_object_finalize((ts4_word)(a0 + 32));
    *(unsigned char *)((char *)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}

/* Swing_DLL.xex 0x88852490: tailcall fn_8884E2A0 */
ts4_word ts4_tailcall_fn_8884E2A0_88852490(ts4_word a0)
{
    return fn_8884E2A0((ts4_word)(a0 + 32));
}

/* Swing_DLL.xex 0x8885C280: get u32@0x44, fn_8885B210 */
ts4_word ts4_get_u32_off44_8885C280(ts4_word a0)
{
    return fn_8885B210((ts4_word)(*(ts4_word *)((char *)(a0) + 68)));
}

/* Swing_DLL.xex 0x88864EF8: if_get u32@lbl_88D45B1C, u32@0x224, u32@0x0, u32@0x48, vcall, u32@0x0 */
void ts4_if_get_u32_lbl_88D45B1C_88864EF8(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;

    t2 = *(ts4_word *)((char *)((*(ts4_word *)lbl_88D45B1C)) + 548);
    t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t2) + 0))) + 72))))((ts4_word)t2, (ts4_word)a0);
    if ((ts4_word)(t5 & 0xff) == 1) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t2) + 0))) + 60))))((ts4_word)t2, (ts4_word)a0);
    }
    return;
}

/* Swing_DLL.xex 0x88865118: get u32@lbl_88D45A08, u32@0x1c */
ts4_word ts4_get_u32_lbl_88D45A08_88865118(void)
{
    return (*(ts4_word *)((char *)((*(ts4_word *)lbl_88D45A08)) + 28));
}

/* Swing_DLL.xex 0x88867DD8: call_seq fn_8883F238, fn_886140B8 */
ts4_word ts4_call_seq_fn_8883F238_88867DD8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_8883F238();
    t2 = fn_886140B8((ts4_word)t1, (ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x8886B4C8: tailcall ts4_loop_call_seq_u32_off30_8886B150 */
ts4_word ts4_tailcall_fn_8886B150_8886B4C8(ts4_word a0, ts4_word a1)
{
    return ts4_loop_call_seq_u32_off30_8886B150((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x8886CE08: get u32@lbl_88D459D4, fn_8886CC78 */
ts4_word ts4_get_u32_lbl_88D459D4_8886CE08(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8886CC78((ts4_word)(*(ts4_word *)lbl_88D459D4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88875C50: tailcall ex3_inflateInit2__88875B18 */
ts4_word ts4_tailcall_fn_88875B18_88875C50(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ex3_inflateInit2__88875B18((ts4_word)a0, (ts4_word)15, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8887CB40: get u32@0x8, fn_8887C748 */
ts4_word ts4_get_u32_off8_8887CB40(ts4_word a0)
{
    return fn_8887C748((ts4_word)(*(ts4_word *)((char *)(a0) + 8)));
}

/* Swing_DLL.xex 0x88887F60: get u32@0x224, ts4_if_get_u32_off0_8861AA88 */
ts4_word ts4_get_u32_off224_88887F60(ts4_word a0)
{
    return ts4_if_get_u32_off0_8861AA88((ts4_word)(*(ts4_word *)((char *)(a0) + 548)));
}

/* Swing_DLL.xex 0x88890380: get u32@0x8, u8@0x0 */
void ts4_get_u32_off8_88890380(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(a0) + 0) = (unsigned char)((*(ts4_word *)((char *)(a1) + 8)) != 0);
    return;
}

/* Swing_DLL.xex 0x888AD388: get u32@0x0, u32@0x28 */
ts4_word ts4_get_u32_off0_888AD388(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 0))) + 40))))((ts4_word)a0, (ts4_word)1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x888AD3B0: get u32@0x0, u32@0x1c */
ts4_word ts4_get_u32_off0_888AD3B0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 0))) + 28))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x888AD408: get u32@0x0, u32@0x28 */
ts4_word ts4_get_u32_off0_888AD408(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 0))) + 40))))((ts4_word)a0, (ts4_word)1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x888B4F88: get u32@0x0, u32@0x8, vcall, fn_888B1960 */
ts4_word ts4_get_u32_off0_888B4F88(ts4_word a0)
{
    ts4_word t4;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 0))) + 8))))((ts4_word)a0);
    t4 = fn_888B1960((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x888B5130: get u32@0x0, u32@0x8, vcall, fn_888B1960 */
ts4_word ts4_get_u32_off0_888B5130(ts4_word a0)
{
    ts4_word t4;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 0))) + 8))))((ts4_word)a0);
    t4 = fn_888B1960((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x888BFB18: set  */
void ts4_set_888BFB18(ts4_word a0, float f1)
{
    *(float *)((char *)(a0) + 4) = f1;
    return;
}

/* Swing_DLL.xex 0x888BFE30: set u8@lbl_88D45918 */
void ts4_set_u8_lbl_88D45918_888BFE30(void)
{
    *(unsigned char *)lbl_88D45918 = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x888C0198: if_get u32@lbl_88D45B1C, u32@0x224, u32@0x0, u32@0x48, vcall, u32@0x0 */
void ts4_if_get_u32_lbl_88D45B1C_888C0198(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;

    t2 = *(ts4_word *)((char *)((*(ts4_word *)lbl_88D45B1C)) + 548);
    t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t2) + 0))) + 72))))((ts4_word)t2, (ts4_word)a0);
    if ((ts4_word)(t5 & 0xff) == 1) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t2) + 0))) + 60))))((ts4_word)t2, (ts4_word)a0);
    }
    return;
}

/* Swing_DLL.xex 0x888C0388: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x38 */
void ts4_set_u32_off0_888C0388(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 56) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888C03A8: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x38 */
void ts4_set_u32_off0_888C03A8(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 56) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888C9498: call_seq u8@0x8, fn_881B9148, fn_888C93E8 */
ts4_word ts4_call_seq_u8_off8_888C9498(ts4_word a0)
{
    ts4_word t2;

    *(unsigned char *)((char *)(a0) + 8) = (unsigned char)0;
    fn_881B9148((ts4_word)(a0 + 16));
    t2 = fn_888C93E8((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x888D5558: get u32@0x24, u32@0x28, fn_888D5340 */
ts4_word ts4_get_u32_off24_888D5558(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 36);
    return fn_888D5340((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(a0) + 40)), (ts4_word)t1);
}

/* Swing_DLL.xex 0x888D5568: get u32@0x24, u32@0x28, fn_888D5340 */
ts4_word ts4_get_u32_off24_888D5568(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 36);
    return fn_888D5340((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(a0) + 40)), (ts4_word)t1);
}

/* Swing_DLL.xex 0x888D6690: call_seq fn_8883F238, fn_886220F8 */
ts4_word ts4_call_seq_fn_8883F238_888D6690(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_8883F238();
    t2 = fn_886220F8((ts4_word)t1, (ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x8890C5C0: set  */
void ts4_set_8890C5C0(ts4_word a0, float f1)
{
    *(float *)((char *)(a0) + 4) = f1;
    return;
}

/* Swing_DLL.xex 0x889192E8: call_seq fn_889395D8, fn_889395D8 */
ts4_word ts4_call_seq_fn_889395D8_889192E8(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1068));
    t2 = fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1072));
    return t2;
}

/* Swing_DLL.xex 0x88919D48: addr lbl_88D3CD50, fn_88918908, u32@0x418, u32@0x0, u32@0x8, vcall */
ts4_word ts4_addr_lbl_88D3CD50_88919D48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t8;

    (void)a2;
    t1 = fn_88918908((ts4_word)(ts4_word)lbl_88D3CD50);
    *(ts4_word *)((char *)(t1) + 1048) = (ts4_word)a1;
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t1) + 0))) + 8))))((ts4_word)t1, (ts4_word)a0);
    fn_88916750((ts4_word)a3, (ts4_word)t1);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)0);
    return t8;
}

/* Swing_DLL.xex 0x88921948: addr lbl_88D3CD50, fn_88919348, u32@0x418, u32@0x0, u32@0x8, vcall */
ts4_word ts4_addr_lbl_88D3CD50_88921948(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t8;

    (void)a2;
    t1 = fn_88919348((ts4_word)(ts4_word)lbl_88D3CD50);
    *(ts4_word *)((char *)(t1) + 1048) = (ts4_word)a1;
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t1) + 0))) + 8))))((ts4_word)t1, (ts4_word)a0);
    ts4_if_call_seq_u32_off20_88921680((ts4_word)a3, (ts4_word)t1);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)0);
    return t8;
}

/* Swing_DLL.xex 0x889222F8: get u32@0x0, u32@0x40 */
ts4_word ts4_get_u32_off0_889222F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 0))) + 64))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x889224D0: get u32@0x0, u32@0x1c */
ts4_word ts4_get_u32_off0_889224D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 0))) + 28))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x889228E0: get u32@0x20 */
ts4_word ts4_get_u32_off20_889228E0(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(a0) + 32)) != 0);
}

/* Swing_DLL.xex 0x8892F468: if_call_seq fn_88926B40, fn_8892F328 */
ts4_word ts4_if_call_seq_fn_88926B40_8892F468(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_88926B40();
    if ((ts4_word)(t1 & 0xff) == 1) {
        fn_8892F328((ts4_word)a0);
    }
    return t1;
}

/* Swing_DLL.xex 0x8892F4B8: if_call_seq fn_88926A70, fn_8892F328 */
ts4_word ts4_if_call_seq_fn_88926A70_8892F4B8(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_88926A70();
    if ((ts4_word)(t1 & 0xff) == 1) {
        fn_8892F328((ts4_word)a0);
    }
    return t1;
}

/* Swing_DLL.xex 0x88931068: get u32@0x0, u32@0x40 */
ts4_word ts4_get_u32_off0_88931068(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 0))) + 64))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88931188: get u16@0x0, u16@0x0 */
void ts4_get_u16_off0_88931188(ts4_word a0, ts4_word a1)
{
    *(unsigned short *)((char *)(a0) + 0) = (unsigned short)(*(unsigned short *)((char *)(a1) + 0));
    return;
}

/* Swing_DLL.xex 0x889311D8: get u16@0x0, u16@0x0 */
void ts4_get_u16_off0_889311D8(ts4_word a0, ts4_word a1)
{
    *(unsigned short *)((char *)(a0) + 0) = (unsigned short)(*(unsigned short *)((char *)(a1) + 0));
    return;
}

/* Swing_DLL.xex 0x88931AE0: tailcall ts4_object_finalize */
ts4_word ts4_tailcall_ts4_object_finalize_88931AE0(ts4_word a0)
{
    return ts4_object_finalize((ts4_word)(a0 + 32));
}

/* Swing_DLL.xex 0x88931ED8: addr lbl_880D5B10, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5B10_88931ED8(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)-1;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5B10;
    return;
}

/* Swing_DLL.xex 0x88932AE0: get u32@0x8 */
ts4_word ts4_get_u32_off8_88932AE0(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(a0) + 8)) + -2) == 0);
}

/* Swing_DLL.xex 0x88932D38: get u32@0x4, fn_884F0350 */
ts4_word ts4_get_u32_off4_88932D38(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_884F0350((ts4_word)(*(ts4_word *)((char *)(a0) + 4)), (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Swing_DLL.xex 0x88934978: addr lbl_880D60C0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D60C0_88934978(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)-1;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D60C0;
    return;
}

/* Swing_DLL.xex 0x8893A9A0: tailcall fn_88939738 */
ts4_word ts4_tailcall_fn_88939738_8893A9A0(ts4_word a0, ts4_word a1)
{
    return fn_88939738((ts4_word)a1, (ts4_word)a0);
}

/* Swing_DLL.xex 0x8893BFC8: call_seq fn_889395D8, fn_88939738 */
ts4_word ts4_call_seq_fn_889395D8_8893BFC8(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1068));
    t2 = fn_88939738((ts4_word)a1, (ts4_word)(a0 + 1072));
    return t2;
}

/* Swing_DLL.xex 0x88945D30: call_seq u8@0x8, fn_881B9148, fn_88941780 */
ts4_word ts4_call_seq_u8_off8_88945D30(ts4_word a0)
{
    ts4_word t2;

    *(unsigned char *)((char *)(a0) + 8) = (unsigned char)0;
    fn_881B9148((ts4_word)(a0 + 16));
    t2 = fn_88941780((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x889462B0: call_seq u8@0x8, fn_881B9148, fn_889461A8 */
ts4_word ts4_call_seq_u8_off8_889462B0(ts4_word a0)
{
    ts4_word t2;

    *(unsigned char *)((char *)(a0) + 8) = (unsigned char)0;
    fn_881B9148((ts4_word)(a0 + 16));
    t2 = fn_889461A8((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x88994C18: addr lbl_880D5B34, u32@0x0 */
void ts4_addr_lbl_880D5B34_88994C18(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5B34;
    return;
}

/* Swing_DLL.xex 0x889953F8: set u32@0x6c */
void ts4_set_u32_off6c_889953F8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(a0) + 108) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x8899BFF0: set u32@0x0, u32@0x8 */
void ts4_set_u32_off0_8899BFF0(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8899C060: addr lbl_880D5B34, u32@0x0 */
void ts4_addr_lbl_880D5B34_8899C060(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5B34;
    return;
}
