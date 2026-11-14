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

extern char lbl_88001A20[];
extern char lbl_88028BDC[];
extern char lbl_8803A098[];
extern char lbl_8803A308[];
extern char lbl_8803A320[];
extern char lbl_8803A3B4[];
extern char lbl_8803A3CC[];
extern char lbl_8803A444[];
extern char lbl_8803A844[];
extern char lbl_8803A920[];
extern char lbl_8803AA08[];
extern char lbl_8803AE14[];
extern char lbl_8803B244[];
extern char lbl_8803BC48[];
extern char lbl_8803C474[];
extern char lbl_8803C85C[];
extern char lbl_8803E7B4[];
extern char lbl_8803E868[];
extern char lbl_8803EB14[];
extern char lbl_8803EB40[];
extern char lbl_8803EBA4[];
extern char lbl_8803F4F8[];
extern char lbl_8803F50C[];
extern char lbl_8803FE58[];
extern char lbl_8803FE64[];
extern char lbl_8803FE70[];
extern char lbl_8803FE7C[];
extern char lbl_88042D48[];
extern char lbl_88042D54[];
extern char lbl_88042D60[];
extern char lbl_88042D6C[];
extern char lbl_88042D78[];
extern char lbl_88042D84[];
extern char lbl_88042D94[];
extern char lbl_88052B58[];
extern char lbl_8805A548[];
extern char lbl_8806D1E8[];
extern char lbl_88B3302C[];
extern char lbl_88B3C200[];
extern char lbl_88B3C350[];
extern char lbl_88B3C5B8[];
extern char lbl_88B3CBD4[];
extern char lbl_88B3D288[];
extern char lbl_88B3D3A8[];
extern char lbl_88CACF08[];
extern char lbl_88CAD578[];
extern char lbl_88D26FCC[];
ts4_word KeTlsGetValue();
ts4_word fn_88315F10();
ts4_word ts4_fetch_then_use_float_88317A60();
ts4_word ts4_call_then_conditionally_forward_result_88317BD8();
ts4_word fn_8832EDB0();
ts4_word fn_883DD2B0();
ts4_word fn_883E1EF0();
ts4_word fn_883FB008();
ts4_word fn_883FBA90();
ts4_word fn_883FBB88();
ts4_word fn_883FBBD8();
ts4_word fn_883FC9E8();
ts4_word fn_883FF100();
ts4_word fn_88401528();
ts4_word fn_88401DA0();
ts4_word fn_884025C0();
ts4_word fn_884027D8();
ts4_word fn_884029E8();
ts4_word fn_88403BC8();
ts4_word fn_88403ED8();
ts4_word fn_88406148();
ts4_word fn_88406238();
ts4_word fn_88407630();
ts4_word ts4_if_call_seq_fn_88406148_884083E0();
ts4_word fn_88408D58();
ts4_word ts4_if_call_seq_u16_off4_88409D28();
ts4_word ts4_if_call_seq_u16_off4_8840C448();
ts4_word ts4_call_seq_lbl_8803AA08_8840E3D8();
ts4_word fn_8840E420();
ts4_word fn_88412948();
ts4_word ts4_if_call_seq_u16_off4_88413F98();
ts4_word fn_88419938();
ts4_word fn_8841A258();
ts4_word fn_8841A510();
ts4_word fn_8841A590();
ts4_word fn_8841D058();
ts4_word fn_8841D800();
ts4_word fn_8841DBA0();
ts4_word fn_8841ED98();
ts4_word fn_8841FDB8();
ts4_word fn_88420A90();
ts4_word fn_88420B68();
ts4_word fn_88421450();
ts4_word fn_88423660();
ts4_word fn_88423788();
ts4_word fn_88423CE0();
ts4_word fn_88423D60();
ts4_word fn_88425490();
ts4_word fn_88426030();
ts4_word ts4_addr_lbl_88B3C5B8_88426110();
ts4_word fn_88426FF8();
ts4_word fn_88427338();
ts4_word fn_88427958();
ts4_word fn_88427C08();
ts4_word fn_88427C18();
ts4_word fn_88427CA8();
ts4_word ts4_if_set_fn_88425490_884292B8();
ts4_word fn_8842B078();
ts4_word fn_88431250();
ts4_word fn_88432B08();
ts4_word fn_88433DD8();
ts4_word fn_88434B38();
ts4_word fn_884C5468();
ts4_word fn_884C6220();
ts4_word ts4_tailcall_fn_884CD990_884CE090();
ts4_word ts4_tailcall_NetDll_socket_884F0240();
ts4_word ts4_tailcall_NetDll_closesocket_884F0258();
ts4_word fn_885630C0();
ts4_word fn_88563500();
ts4_word fn_885646F8();
ts4_word fn_885647D0();
ts4_word ts4_tailcall_fn_88564828_88564B08();
ts4_word ts4_tailcall_fn_885654E8_885655D0();
ts4_word ts4_lookup_then_forward_88317AA8();
ts4_word ts4_lookup_then_forward_88317C20();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x883F77B0: set u32@0x0 */
ts4_word ts4_set_u32_off0_883F77B0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
    return 37;
}

/* Swing_DLL.xex 0x883F7898: get u32@0x4 */
ts4_word ts4_get_u32_off4_883F7898(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 148));
    return 0;
}

/* Swing_DLL.xex 0x883F78D8: set u8@0x0 */
ts4_word ts4_set_u8_off0_883F78D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(unsigned char *)((char *)(ts4_word)(a2) + 0) = (unsigned char)0;
    return 0;
}

/* Swing_DLL.xex 0x883F78E8: get u32@0x10, u32@0x0 */
ts4_word ts4_get_u32_off10_883F78E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a1;
    (void)a2;
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16));
    return 0;
}

/* Swing_DLL.xex 0x883F7938: tailcall fn_883E1EF0 */
ts4_word ts4_tailcall_fn_883E1EF0_883F7938(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_883E1EF0((ts4_word)a1, (ts4_word)a1);
}

/* Swing_DLL.xex 0x883F9E78: tailcall fn_883DD2B0 */
ts4_word ts4_tailcall_fn_883DD2B0_883F9E78(ts4_word a0)
{
    return fn_883DD2B0((ts4_word)a0);
}

/* Swing_DLL.xex 0x883F9E80: set u32@0x68 */
ts4_word ts4_set_u32_off68_883F9E80(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x883F9E90: if_get u32@0x68, u32@0x0 */
ts4_word ts4_if_get_u32_off68_883F9E90(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 104));
    return 0;
}

/* Swing_DLL.xex 0x883FAF58: if_call_seq u32@0x14, lbl_8803A098, u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
ts4_word ts4_if_call_seq_u32_off14_883FAF58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_8803A098, (ts4_word)235);
    }
    return 0;
}

/* Swing_DLL.xex 0x883FB088: if_call_seq u32@0x14, u32@0x8, fn_8832EDB0 */
ts4_word ts4_if_call_seq_u32_off14_883FB088(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)2, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) << 3));
    }
    return 0;
}

/* Swing_DLL.xex 0x883FB190: call_seq fn_883FB008 */
ts4_word ts4_call_seq_fn_883FB008_883FB190(ts4_word a0, ts4_word a1)
{
    fn_883FB008((ts4_word)(a0 + 8), (ts4_word)a1);
    return 0;
}

/* Swing_DLL.xex 0x883FB2B0: get u32@0x8 */
ts4_word ts4_get_u32_off8_883FB2B0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Swing_DLL.xex 0x883FB510: set u8@0x1d */
ts4_word ts4_set_u8_off1d_883FB510(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 29) = (unsigned char)1;
    return 0;
}

/* Swing_DLL.xex 0x883FB590: get u32@0x80, ts4_fetch_then_use_float_88317A60 */
ts4_word ts4_get_u32_off80_883FB590(ts4_word a0)
{
    return ts4_fetch_then_use_float_88317A60((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 128)));
}

/* Swing_DLL.xex 0x883FB598: get u32@0x80, ts4_lookup_then_forward_88317AA8 */
ts4_word ts4_get_u32_off80_883FB598(ts4_word a0)
{
    return ts4_lookup_then_forward_88317AA8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 128)));
}

/* Swing_DLL.xex 0x883FB610: get u32@0x80, ts4_call_then_conditionally_forward_result_88317BD8 */
ts4_word ts4_get_u32_off80_883FB610(ts4_word a0)
{
    return ts4_call_then_conditionally_forward_result_88317BD8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 128)));
}

/* Swing_DLL.xex 0x883FB618: get u32@0x80, ts4_lookup_then_forward_88317C20 */
ts4_word ts4_get_u32_off80_883FB618(ts4_word a0)
{
    return ts4_lookup_then_forward_88317C20((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 128)));
}

/* Swing_DLL.xex 0x883FB6A0: set u32@0x98, u32@0x9c */
ts4_word ts4_set_u32_off98_883FB6A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 156) = (ts4_word)a2;
    return 0;
}

/* Swing_DLL.xex 0x883FBC28: call_seq fn_883FBBD8 */
ts4_word ts4_call_seq_fn_883FBBD8_883FBC28(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_883FBBD8((ts4_word)(a0 + 32));
    return (t1 != 0);
}

/* Swing_DLL.xex 0x883FBFA8: tailcall fn_883FBA90 */
ts4_word ts4_tailcall_fn_883FBA90_883FBFA8(ts4_word a0)
{
    return fn_883FBA90((ts4_word)(a0 + 64));
}

/* Swing_DLL.xex 0x883FBFB0: tailcall fn_883FBB88 */
ts4_word ts4_tailcall_fn_883FBB88_883FBFB0(ts4_word a0)
{
    return fn_883FBB88((ts4_word)(a0 + 64));
}

/* Swing_DLL.xex 0x883FCD98: tailcall fn_883FC9E8 */
ts4_word ts4_tailcall_fn_883FC9E8_883FCD98(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_883FC9E8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Swing_DLL.xex 0x883FCDA0: get u32@0xc, u32@0xc */
void ts4_get_u32_offc_883FCDA0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) + 1);
    return;
}

/* Swing_DLL.xex 0x883FCDB0: set u32@0x1c */
ts4_word ts4_set_u32_off1c_883FCDB0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x883FD018: call_seq fn_8832EDB0 */
ts4_word ts4_call_seq_fn_8832EDB0_883FD018(ts4_word a0, ts4_word a1)
{
    (void)a0;
    fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)2, (ts4_word)40);
    return 0;
}

/* Swing_DLL.xex 0x883FD1A0: call_seq fn_8832EDB0 */
ts4_word ts4_call_seq_fn_8832EDB0_883FD1A0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)2, (ts4_word)32);
    return 0;
}

/* Swing_DLL.xex 0x883FD250: get u8@0x11, u8@0x0 */
ts4_word ts4_get_u8_off11_883FD250(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    *(unsigned char *)((char *)(ts4_word)(a2) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 17));
    return 0;
}

/* Swing_DLL.xex 0x883FD260: call_seq fn_8832EDB0 */
ts4_word ts4_call_seq_fn_8832EDB0_883FD260(ts4_word a0, ts4_word a1)
{
    (void)a0;
    fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)2, (ts4_word)20);
    return 0;
}

/* Swing_DLL.xex 0x883FD308: fn  */
ts4_word ts4_fn_883FD308(void)
{
    return 1;
}

/* Swing_DLL.xex 0x883FD4F0: fn  */
ts4_word ts4_fn_883FD4F0(void)
{
    return 3;
}

/* Swing_DLL.xex 0x883FD578: set u32@0x14, u32@0x18, u32@0x1c, u32@0x20, u32@0x24, u32@0x28 */
ts4_word ts4_set_u32_off14_883FD578(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 84) = (*(float *)lbl_88001A20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x883FE958: set u32@0x14, u32@0x18, u32@0x1c, u32@0x20, u16@0x24 */
ts4_word ts4_set_u32_off14_883FE958(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 36) = (unsigned short)0;
    return 0;
}

/* Swing_DLL.xex 0x883FF158: if_call_seq u32@0x8, u32@0xc, fn_8832EDB0 */
ts4_word ts4_if_call_seq_u32_off8_883FF158(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)2, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) << 2));
    }
    return 0;
}

/* Swing_DLL.xex 0x883FF4C0: if_get u32@0x4, u32@0xa4, u64@0x10 */
void ts4_if_get_u32_off4_883FF4C0(ts4_word a0, ts4_u64 a1)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 164);
    if ((ts4_word)t2 == 0) {
        return;
    }
    *(ts4_u64 *)((char *)(ts4_word)(t2) + 16) = (ts4_u64)a1;
    return;
}

/* Swing_DLL.xex 0x883FF7C0: set u32@0x44 */
ts4_word ts4_set_u32_off44_883FF7C0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)2;
    return 0;
}

/* Swing_DLL.xex 0x883FF7D8: call_seq fn_883FF100 */
ts4_word ts4_call_seq_fn_883FF100_883FF7D8(ts4_word a0)
{
    fn_883FF100((ts4_word)(a0 + 20));
    return 0;
}

/* Swing_DLL.xex 0x883FFA98: get u8@0x8 */
ts4_word ts4_get_u8_off8_883FFA98(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 8));
}

/* Swing_DLL.xex 0x883FFAB8: get u8@0x31 */
ts4_word ts4_get_u8_off31_883FFAB8(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 49));
}

/* Swing_DLL.xex 0x883FFAC0: get u8@0x30 */
ts4_word ts4_get_u8_off30_883FFAC0(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 48));
}

/* Swing_DLL.xex 0x883FFAD8: if_get u8@0x30, u8@0x30, u8@0x31, u64@0x40, u64@0x38 */
void ts4_if_get_u8_off30_883FFAD8(ts4_word a0, ts4_word a1)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 48);
    if ((ts4_word)(a1 & 0xff) == (ts4_word)t1) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 48) = (unsigned char)a1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 49) = (unsigned char)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 64) = (ts4_u64)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 56) = (ts4_u64)0;
    return;
}

/* Swing_DLL.xex 0x883FFB00: if_get u8@0x31, u8@0x31, u8@0x30, u64@0x40, u64@0x38 */
void ts4_if_get_u8_off31_883FFB00(ts4_word a0, ts4_word a1)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 49);
    if ((ts4_word)(a1 & 0xff) == (ts4_word)t1) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 49) = (unsigned char)a1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 48) = (unsigned char)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 64) = (ts4_u64)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 56) = (ts4_u64)0;
    return;
}

/* Swing_DLL.xex 0x884014D0: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_884014D0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x884014E0: call_seq lbl_8803A320, fn_8841D058, u8@0x0 */
ts4_word ts4_call_seq_lbl_8803A320_884014E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    fn_8841D058((ts4_word)a2, (ts4_word)(ts4_word)lbl_8803A320);
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x884019B0: call_seq fn_88401528 */
ts4_word ts4_call_seq_fn_88401528_884019B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    fn_88401528((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)1, (ts4_word)0);
    return a0;
}

/* Swing_DLL.xex 0x884019E8: call_seq fn_88401528 */
ts4_word ts4_call_seq_fn_88401528_884019E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    fn_88401528((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)2, (ts4_word)0);
    return a0;
}

/* Swing_DLL.xex 0x88401A20: call_seq fn_88401528 */
ts4_word ts4_call_seq_fn_88401528_88401A20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    fn_88401528((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)3, (ts4_word)0);
    return a0;
}

/* Swing_DLL.xex 0x88401F80: set u8@0x0 */
void ts4_set_u8_off0_88401F80(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88401F90: if_call_seq fn_88401DA0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88401DA0_88401F90(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88401DA0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)62);
    }
    return a0;
}

/* Swing_DLL.xex 0x88401FF8: set u8@0x0 */
void ts4_set_u8_off0_88401FF8(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88402FB0: call_seq fn_884025C0 */
ts4_word ts4_call_seq_fn_884025C0_88402FB0(void)
{
    ts4_word t1;

    t1 = fn_884025C0();
    return (t1 + 4);
}

/* Swing_DLL.xex 0x88402FD8: call_seq fn_884027D8 */
ts4_word ts4_call_seq_fn_884027D8_88402FD8(void)
{
    ts4_word t1;

    t1 = fn_884027D8();
    return (t1 + 16);
}

/* Swing_DLL.xex 0x88403840: if_addr lbl_8803A444, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8803A444_88403840(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A444;
    return;
}

/* Swing_DLL.xex 0x88403878: addr lbl_8803A444 */
ts4_word ts4_addr_lbl_8803A444_88403878(void)
{
    return (ts4_word)lbl_8803A444;
}

/* Swing_DLL.xex 0x88403888: if_call_seq ts4_if_call_seq_u16_off4_88409D28, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88409D28_88403888(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_if_call_seq_u16_off4_88409D28();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)58);
    }
    return a0;
}

/* Swing_DLL.xex 0x88403940: addr lbl_8803A844 */
ts4_word ts4_addr_lbl_8803A844_88403940(void)
{
    return (ts4_word)lbl_8803A844;
}

/* Swing_DLL.xex 0x88403950: get u32@0x18, u32@0x0, u32@0xc */
ts4_word ts4_get_u32_off18_88403950(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88403A70: if_call_seq ts4_if_call_seq_u16_off4_8840C448, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8840C448_88403A70(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_if_call_seq_u16_off4_8840C448();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)56);
    }
    return a0;
}

/* Swing_DLL.xex 0x88403AF0: if_addr lbl_8803A920, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8803A920_88403AF0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A920;
    return;
}

/* Swing_DLL.xex 0x88403B10: addr lbl_8803A920 */
ts4_word ts4_addr_lbl_8803A920_88403B10(void)
{
    return (ts4_word)lbl_8803A920;
}

/* Swing_DLL.xex 0x88403B20: if_call_seq lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_lbl_8803A308_88403B20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)55);
    }
    return a0;
}

/* Swing_DLL.xex 0x88403B98: if_addr lbl_8803AA08, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8803AA08_88403B98(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803AA08;
    return;
}

/* Swing_DLL.xex 0x88403BB8: addr lbl_8803AA08 */
ts4_word ts4_addr_lbl_8803AA08_88403BB8(void)
{
    return (ts4_word)lbl_8803AA08;
}

/* Swing_DLL.xex 0x88403C60: if_call_seq ts4_call_seq_lbl_8803AA08_8840E3D8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8840E3D8_88403C60(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_call_seq_lbl_8803AA08_8840E3D8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)59);
    }
    return a0;
}

/* Swing_DLL.xex 0x88403D18: addr lbl_8803AE14 */
ts4_word ts4_addr_lbl_8803AE14_88403D18(void)
{
    return (ts4_word)lbl_8803AE14;
}

/* Swing_DLL.xex 0x88403D28: if_call_seq fn_88412948, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88412948_88403D28(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88412948();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)56);
    }
    return a0;
}

/* Swing_DLL.xex 0x88403DE8: addr lbl_8803B244 */
ts4_word ts4_addr_lbl_8803B244_88403DE8(void)
{
    return (ts4_word)lbl_8803B244;
}

/* Swing_DLL.xex 0x88403DF8: if_call_seq ts4_if_call_seq_u16_off4_88413F98, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88413F98_88403DF8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_if_call_seq_u16_off4_88413F98();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)56);
    }
    return a0;
}

/* Swing_DLL.xex 0x88403ED0: tailcall fn_88403ED8 */
ts4_word ts4_tailcall_fn_88403ED8_88403ED0(ts4_word a0)
{
    return fn_88403ED8((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x884054A0: if_call_seq lbl_8803BC48, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_8803BC48_884054A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803BC48;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x88408218: get u32@0x1c, u32@0x20, u32@0x10, fn_88407630 */
ts4_word ts4_get_u32_off1c_88408218(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 32);
    return fn_88407630((ts4_word)a0, (ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 16)), (ts4_word)a2, (ts4_word)t2, (ts4_word)a3, (ts4_word)0);
}

/* Swing_DLL.xex 0x88408238: tailcall fn_88407630 */
ts4_word ts4_tailcall_fn_88407630_88408238(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return fn_88407630((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)1);
}

/* Swing_DLL.xex 0x884082C0: tailcall fn_88406238 */
ts4_word ts4_tailcall_fn_88406238_884082C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_88406238((ts4_word)a0, (ts4_word)a3, (ts4_word)a2, (ts4_word)a1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)a4);
}

/* Swing_DLL.xex 0x884082E0: tailcall fn_88406238 */
ts4_word ts4_tailcall_fn_88406238_884082E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_88406238((ts4_word)a0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)a3, (ts4_word)a2, (ts4_word)a1, (ts4_word)a4);
}

/* Swing_DLL.xex 0x884083D8: tailcall ts4_if_call_seq_fn_88406148_884083E0 */
ts4_word ts4_tailcall_fn_884083E0_884083D8(ts4_word a0)
{
    return ts4_if_call_seq_fn_88406148_884083E0((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x88408F10: if_call_seq fn_88408D58, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88408D58_88408F10(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88408D58();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)60);
    }
    return a0;
}

/* Swing_DLL.xex 0x88409508: get  */
float ts4_get_88409508(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 48));
}

/* Swing_DLL.xex 0x8840B5B0: get u32@0x24 */
ts4_word ts4_get_u32_off24_8840B5B0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 36));
}

/* Swing_DLL.xex 0x8840D698: if_get u32@0x10, u32@0x14 */
ts4_word ts4_if_get_u32_off10_8840D698(ts4_word a0)
{
    ts4_word p2;
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p2 = (ts4_word)1;
    if ((int)t1 > 0) {
        p2 = (ts4_word)2;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((int)t3 > 0) {
        return (p2 + 1);
    }
    return p2;
}

/* Swing_DLL.xex 0x8840F140: set u16@0x0, u8@0x2 */
void ts4_set_u16_off0_8840F140(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 0) = (unsigned short)256;
    *(unsigned char *)((char *)(ts4_word)(a0) + 2) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8840F2F0: set u16@0x16, u16@0x14, u16@0x12, u16@0x10, u8@0x19, u8@0x18 */
void ts4_set_u16_off16_8840F2F0(ts4_word a0)
{
    float t1;

    *(unsigned short *)((char *)(ts4_word)(a0) + 22) = (unsigned short)3;
    *(unsigned short *)((char *)(ts4_word)(a0) + 20) = (unsigned short)3;
    t1 = *(float *)lbl_88028BDC;
    *(unsigned short *)((char *)(ts4_word)(a0) + 18) = (unsigned short)3;
    *(float *)((char *)(ts4_word)(a0) + 12) = t1;
    *(unsigned short *)((char *)(ts4_word)(a0) + 16) = (unsigned short)3;
    *(float *)((char *)(ts4_word)(a0) + 8) = t1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 25) = (unsigned char)1;
    *(float *)((char *)(ts4_word)(a0) + 4) = t1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)1;
    *(float *)((char *)(ts4_word)(a0) + 0) = t1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 26) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 27) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88411D18: get u32@0x24 */
ts4_word ts4_get_u32_off24_88411D18(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 36));
}

/* Swing_DLL.xex 0x88411D20: fn  */
ts4_word ts4_fn_88411D20(void)
{
    return 3;
}

/* Swing_DLL.xex 0x88411ED8: get u32@0x5c, u32@0x68, u32@0x44, u32@0x74 */
ts4_word ts4_get_u32_off5c_88411ED8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    return (((((t2 + t1) + t3) + 32) << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 116)));
}

/* Swing_DLL.xex 0x88413590: get u32@0x24 */
ts4_word ts4_get_u32_off24_88413590(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 36));
}

/* Swing_DLL.xex 0x88418500: if_addr lbl_8803C474, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8803C474_88418500(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803C474;
    return;
}

/* Swing_DLL.xex 0x88418520: addr lbl_8803C474 */
ts4_word ts4_addr_lbl_8803C474_88418520(void)
{
    return (ts4_word)lbl_8803C474;
}

/* Swing_DLL.xex 0x88418530: if_call_seq fn_88419938, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88419938_88418530(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88419938();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)14);
    }
    return a0;
}

/* Swing_DLL.xex 0x88419E10: get u32@0x14, u32@0x14 */
void ts4_get_u32_off14_88419E10(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20)) + 1);
    return;
}

/* Swing_DLL.xex 0x8841A7C8: call_seq fn_8841A510, u32@0x0, u32@0x4, u32@0x8 */
ts4_word ts4_call_seq_fn_8841A510_8841A7C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = fn_8841A510((ts4_word)a0, (ts4_word)(a1 + 16));
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)((36962304) | 22102);
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)a2;
    return (t1 + 16);
}

/* Swing_DLL.xex 0x8841A8E8: if_addr lbl_8803C85C, u32@0x0, fn_8841A258, u32@lbl_88B3C200, vcall */
ts4_word ts4_if_addr_lbl_8803C85C_8841A8E8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803C85C;
    fn_8841A258();
    if ((ts4_word)(a1 & 0x1) != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)lbl_88B3C200)))((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8841A960: addr lbl_8803A308 */
ts4_word ts4_addr_lbl_8803A308_8841A960(void)
{
    return (ts4_word)lbl_8803A308;
}

/* Swing_DLL.xex 0x8841D7B0: get u32@0x8, u32@0x4, u32@0x0, u32@0x0, u32@0x10, vcall */
ts4_word ts4_get_u32_off8_8841D7B0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1, (ts4_word)t3, (ts4_word)(t2 + -1));
    return a0;
}

/* Swing_DLL.xex 0x8841D878: get u32@0x8, u32@0x4, u32@0xc, fn_8841D800 */
ts4_word ts4_get_u32_off8_8841D878(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return fn_8841D800((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t1);
}

/* Swing_DLL.xex 0x8841E450: get u32@0x8, u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_off8_8841E450(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8841E9E0: if_call_seq fn_8841DBA0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8841DBA0_8841E9E0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8841DBA0((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)26);
    }
    return a0;
}

/* Swing_DLL.xex 0x8841EAC8: get u32@0x0 */
ts4_word ts4_get_u32_off0_8841EAC8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Swing_DLL.xex 0x8841EAD0: get u32@0x4 */
ts4_word ts4_get_u32_off4_8841EAD0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Swing_DLL.xex 0x8841EAD8: get u32@0x4 */
ts4_word ts4_get_u32_off4_8841EAD8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Swing_DLL.xex 0x8841EB68: fn  */
ts4_word ts4_fn_8841EB68(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8841EB70: fn  */
ts4_word ts4_fn_8841EB70(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8841EB78: get u32@0xc */
ts4_word ts4_get_u32_offc_8841EB78(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x8841ECD8: get u32@0x14 */
ts4_word ts4_get_u32_off14_8841ECD8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x8841ED78: get u32@0x1c */
ts4_word ts4_get_u32_off1c_8841ED78(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 28));
}

/* Swing_DLL.xex 0x8841EF28: get u32@0x8 */
ts4_word ts4_get_u32_off8_8841EF28(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Swing_DLL.xex 0x8841F670: if_call_seq ts4_addr_lbl_88B3C5B8_88426110, u16@0x8, u32@0x0, u16@0x8, fn_88421450 */
ts4_word ts4_if_call_seq_fn_88426110_8841F670(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    unsigned short t2;

    t1 = ts4_addr_lbl_88B3C5B8_88426110((ts4_word)a2);
    t2 = *(unsigned short *)((char *)(ts4_word)(t1) + 8);
    if ((ts4_word)t2 <= 64) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a2;
        fn_88421450((ts4_word)(a0 + 16), (ts4_word)a1, (ts4_word)((short)(*(unsigned short *)((char *)(ts4_word)(t1) + 8))));
        return 0;
    }
    return 1;
}

/* Swing_DLL.xex 0x8841FF98: tailcall fn_8841FDB8 */
ts4_word ts4_tailcall_fn_8841FDB8_8841FF98(ts4_word a0)
{
    return fn_8841FDB8((ts4_word)a0);
}

/* Swing_DLL.xex 0x88420BF0: call_seq fn_88420B68 */
ts4_word ts4_call_seq_fn_88420B68_88420BF0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t1;

    t1 = fn_88420B68((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    return t1;
}

/* Swing_DLL.xex 0x88420C20: tailcall fn_88420A90 */
ts4_word ts4_tailcall_fn_88420A90_88420C20(ts4_word a0)
{
    return fn_88420A90((ts4_word)a0);
}

/* Swing_DLL.xex 0x88421050: tailcall ts4_tailcall_fn_885654E8_885655D0 */
ts4_word ts4_tailcall_fn_885655D0_88421050(ts4_word a0)
{
    return ts4_tailcall_fn_885654E8_885655D0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88421118: tailcall fn_885630C0 */
ts4_word ts4_tailcall_fn_885630C0_88421118(ts4_word a0)
{
    return fn_885630C0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88421360: tailcall ts4_tailcall_fn_88564828_88564B08 */
ts4_word ts4_tailcall_fn_88564B08_88421360(ts4_word a0)
{
    return ts4_tailcall_fn_88564828_88564B08((ts4_word)a0, (ts4_word)0, (ts4_word)0);
}

/* Swing_DLL.xex 0x88421398: tailcall fn_885646F8 */
ts4_word ts4_tailcall_fn_885646F8_88421398(ts4_word a0)
{
    return fn_885646F8((ts4_word)a0);
}

/* Swing_DLL.xex 0x884213A0: tailcall fn_88563500 */
ts4_word ts4_tailcall_fn_88563500_884213A0(ts4_word a0)
{
    return fn_88563500((ts4_word)a0);
}

/* Swing_DLL.xex 0x884213A8: tailcall fn_885647D0 */
ts4_word ts4_tailcall_fn_885647D0_884213A8(ts4_word a0)
{
    return fn_885647D0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88425308: addr lbl_8803E7B4, u16@0x6, u32@0x0 */
void ts4_addr_lbl_8803E7B4_88425308(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803E7B4;
    return;
}

/* Swing_DLL.xex 0x88425320: addr lbl_8803A308, u32@0x0 */
void ts4_addr_lbl_8803A308_88425320(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x884253A0: get u32@0x8, u32@0x0, u32@0xc, vcall */
ts4_word ts4_get_u32_off8_884253A0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x88425450: get u32@0x8, u32@0x0, u32@0xc, vcall */
ts4_word ts4_get_u32_off8_88425450(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x88425528: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, ts4_if_set_fn_88425490_884292B8 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_88425528(void)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)36, (ts4_word)21);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)36;
    t4 = ts4_if_set_fn_88425490_884292B8((ts4_word)t3, (ts4_word)-1);
    return t4;
}

/* Swing_DLL.xex 0x88425628: addr lbl_88B3C350 */
ts4_word ts4_addr_lbl_88B3C350_88425628(void)
{
    return (ts4_word)lbl_88B3C350;
}

/* Swing_DLL.xex 0x88425D40: fn  */
ts4_word ts4_fn_88425D40(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88425D48: fn  */
ts4_word ts4_fn_88425D48(void)
{
    return -1;
}

/* Swing_DLL.xex 0x88425D50: set u8@0x0 */
void ts4_set_u8_off0_88425D50(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88425E20: get u32@0x10, u8@0x0 */
void ts4_get_u32_off10_88425E20(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)((*(ts4_word *)((char *)(ts4_word)(a1) + 16)) != 0);
    return;
}

/* Swing_DLL.xex 0x88425E38: get u32@0xc, u32@0x14 */
ts4_word ts4_get_u32_offc_88425E38(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12));
    return 0;
}

/* Swing_DLL.xex 0x88425E50: if_get u32@0x14, u32@0xc */
ts4_word ts4_if_get_u32_off14_88425E50(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((int)t1 >= 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t1;
        return 0;
    }
    return 1;
}

/* Swing_DLL.xex 0x88425E70: set u8@0x0 */
void ts4_set_u8_off0_88425E70(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88425EF0: get u32@0xc */
ts4_word ts4_get_u32_offc_88425EF0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x884260A8: if_call_seq fn_88426030, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88426030_884260A8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88426030((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)26);
    }
    return a0;
}

/* Swing_DLL.xex 0x88426130: get u32@0x4 */
ts4_word ts4_get_u32_off4_88426130(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Swing_DLL.xex 0x88426138: get u32@0x4 */
ts4_word ts4_get_u32_off4_88426138(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Swing_DLL.xex 0x88426140: get u32@0x8 */
ts4_word ts4_get_u32_off8_88426140(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Swing_DLL.xex 0x88426148: get u16@0xe */
ts4_word ts4_get_u16_offe_88426148(ts4_word a0)
{
    return ((short)(*(unsigned short *)((char *)(ts4_word)(a0) + 14)));
}

/* Swing_DLL.xex 0x88426158: get u32@0x8 */
ts4_word ts4_get_u32_off8_88426158(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Swing_DLL.xex 0x884263E8: get u8@0xd */
ts4_word ts4_get_u8_offd_884263E8(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 13));
}

/* Swing_DLL.xex 0x88427198: get u32@0x8, u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_off8_88427198(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884271C8: get u32@0x8, u32@0x0, u32@0xc, vcall */
ts4_word ts4_get_u32_off8_884271C8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x88427208: get u32@0x8 */
ts4_word ts4_get_u32_off8_88427208(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Swing_DLL.xex 0x88427688: tailcall fn_88426FF8 */
ts4_word ts4_tailcall_fn_88426FF8_88427688(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88426FF8((ts4_word)a0, (ts4_word)a1, (ts4_word)2, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88427698: tailcall fn_88426FF8 */
ts4_word ts4_tailcall_fn_88426FF8_88427698(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88426FF8((ts4_word)a0, (ts4_word)a1, (ts4_word)2, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884276A8: tailcall fn_88426FF8 */
ts4_word ts4_tailcall_fn_88426FF8_884276A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88426FF8((ts4_word)a0, (ts4_word)a1, (ts4_word)4, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884276B8: tailcall fn_88426FF8 */
ts4_word ts4_tailcall_fn_88426FF8_884276B8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88426FF8((ts4_word)a0, (ts4_word)a1, (ts4_word)4, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884276C8: tailcall fn_88426FF8 */
ts4_word ts4_tailcall_fn_88426FF8_884276C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88426FF8((ts4_word)a0, (ts4_word)a1, (ts4_word)8, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884276D8: tailcall fn_88426FF8 */
ts4_word ts4_tailcall_fn_88426FF8_884276D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88426FF8((ts4_word)a0, (ts4_word)a1, (ts4_word)8, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884276E8: tailcall fn_88426FF8 */
ts4_word ts4_tailcall_fn_88426FF8_884276E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88426FF8((ts4_word)a0, (ts4_word)a1, (ts4_word)4, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884276F8: tailcall fn_88426FF8 */
ts4_word ts4_tailcall_fn_88426FF8_884276F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88426FF8((ts4_word)a0, (ts4_word)a1, (ts4_word)8, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88427810: if_call_seq fn_88427338, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88427338_88427810(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88427338((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)26);
    }
    return a0;
}

/* Swing_DLL.xex 0x88427AD8: call_seq fn_88427C18, fn_88427958, fn_88427C08 */
ts4_word ts4_call_seq_fn_88427C18_88427AD8(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t3;

    fn_88427C18((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    fn_88427958((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    t3 = fn_88427C08((ts4_word)(ts4_word)&loc50[0]);
    return t3;
}

/* Swing_DLL.xex 0x88427C38: set u8@0x0 */
void ts4_set_u8_off0_88427C38(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88427C48: if_call_seq lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_lbl_8803A308_88427C48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)26);
    }
    return a0;
}

/* Swing_DLL.xex 0x88428130: tailcall fn_88427CA8 */
ts4_word ts4_tailcall_fn_88427CA8_88428130(ts4_word a0)
{
    return fn_88427CA8((ts4_word)a0);
}

/* Swing_DLL.xex 0x88428208: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, lbl_8803EB14, u16@0x4, u32@0x0 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_88428208(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)20, (ts4_word)21);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)20;
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_8803EB14;
    *(unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    fn_88423CE0((ts4_word)(t3 + 8));
    return t3;
}

/* Swing_DLL.xex 0x88428340: tailcall fn_88423660 */
ts4_word ts4_tailcall_fn_88423660_88428340(ts4_word a0)
{
    return fn_88423660((ts4_word)(a0 + 8));
}

/* Swing_DLL.xex 0x88428348: get u32@0x0, fn_88423788 */
ts4_word ts4_get_u32_off0_88428348(ts4_word a0, ts4_word a1)
{
    return fn_88423788((ts4_word)(a0 + 8), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)0);
}

/* Swing_DLL.xex 0x88428358: if_call_seq fn_88423D60, lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4 */
ts4_word ts4_if_call_seq_fn_88423D60_88428358(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88423D60((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x88428460: call_seq lbl_8803EB40, u16@0x6, u32@0x0, fn_88423CE0 */
ts4_word ts4_call_seq_lbl_8803EB40_88428460(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803EB40;
    fn_88423CE0((ts4_word)(a0 + 8));
    return a0;
}

/* Swing_DLL.xex 0x88428568: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, lbl_8803EB40, u16@0x4, u32@0x0 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_88428568(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)20, (ts4_word)45);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)20;
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_8803EB40;
    *(unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    fn_88423CE0((ts4_word)(t3 + 8));
    return t3;
}

/* Swing_DLL.xex 0x88428788: if_call_seq fn_88423D60, lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4 */
ts4_word ts4_if_call_seq_fn_88423D60_88428788(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88423D60((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)45);
    }
    return a0;
}

/* Swing_DLL.xex 0x88428818: if_call_seq u32@0x0, fn_8841ED98, u32@0x4, u16@0x12, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_88428818(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    t1 = fn_8841ED98((ts4_word)a2, (ts4_word)a3);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((*(unsigned short *)((char *)(ts4_word)(t1) + 18)) + a1);
    }
    return t1;
}

/* Swing_DLL.xex 0x88428890: if_call_seq u32@0x4, u32@0x0, u32@0x0, fn_8841ED98, u32@0x4, u16@0x12 */
ts4_word ts4_if_call_seq_u32_off4_88428890(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    t3 = fn_8841ED98((ts4_word)t1, (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((*(unsigned short *)((char *)(ts4_word)(t3) + 18)) + t2);
    }
    return a0;
}

/* Swing_DLL.xex 0x884288F8: if_call_seq u32@0x0, fn_8841ED98, u32@0x4, u16@0x12, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_884288F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    t1 = fn_8841ED98((ts4_word)a2, (ts4_word)a3);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((*(unsigned short *)((char *)(ts4_word)(t1) + 18)) + a1);
    }
    return a0;
}

/* Swing_DLL.xex 0x88428960: get u32@0x0, u8@0x0 */
void ts4_get_u32_off0_88428960(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)((*(ts4_word *)((char *)(ts4_word)(a1) + 0)) != 0);
    return;
}

/* Swing_DLL.xex 0x88428978: get u32@0x0 */
ts4_word ts4_get_u32_off0_88428978(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Swing_DLL.xex 0x88428980: get u32@0x0 */
ts4_word ts4_get_u32_off0_88428980(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Swing_DLL.xex 0x88428988: get u32@0x0 */
ts4_word ts4_get_u32_off0_88428988(ts4_word a0, ts4_word a1)
{
    return ((a1 << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x88428998: get u32@0x0 */
ts4_word ts4_get_u32_off0_88428998(ts4_word a0, ts4_word a1)
{
    return ((a1 << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x884289A8: get u32@0x0 */
ts4_word ts4_get_u32_off0_884289A8(ts4_word a0, ts4_word a1)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + a1);
}

/* Swing_DLL.xex 0x884289B8: get u32@0x0 */
ts4_word ts4_get_u32_off0_884289B8(ts4_word a0, ts4_word a1)
{
    return ((a1 << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x884289C8: get u32@0x0 */
ts4_word ts4_get_u32_off0_884289C8(ts4_word a0, ts4_word a1)
{
    return ((a1 << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x884289D8: get u32@0x0 */
ts4_word ts4_get_u32_off0_884289D8(ts4_word a0, ts4_word a1)
{
    return ((a1 << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x884289E8: get u32@0x0 */
ts4_word ts4_get_u32_off0_884289E8(ts4_word a0, ts4_word a1)
{
    return ((a1 << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x88428A18: get u32@0x0 */
ts4_word ts4_get_u32_off0_88428A18(ts4_word a0, ts4_word a1)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + a1);
}

/* Swing_DLL.xex 0x88428A28: get u32@0x0 */
ts4_word ts4_get_u32_off0_88428A28(ts4_word a0, ts4_word a1)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + a1);
}

/* Swing_DLL.xex 0x88428A60: get u32@0x0 */
ts4_word ts4_get_u32_off0_88428A60(ts4_word a0, ts4_word a1)
{
    return ((a1 << 6) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x88428A98: get u32@0x0 */
ts4_word ts4_get_u32_off0_88428A98(ts4_word a0, ts4_word a1)
{
    return (((a1 + (a1 << 1)) << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x88428AC0: get u32@0x4 */
ts4_word ts4_get_u32_off4_88428AC0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Swing_DLL.xex 0x88428B30: get u32@0x0, u32@0x0, u32@0x4, u32@0x4 */
void ts4_get_u32_off0_88428B30(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    return;
}

/* Swing_DLL.xex 0x88428EA0: if_call_seq u32@0x20, ts4_tailcall_NetDll_closesocket_884F0258, u32@0x20 */
ts4_word ts4_if_call_seq_u32_off20_88428EA0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    p3 = (ts4_word)t1;
    if ((int)t1 != -1) {
        t2 = ts4_tailcall_NetDll_closesocket_884F0258((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)-1;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x88429030: fn  */
ts4_word ts4_fn_88429030(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88429110: if_call_seq u32@0x20, lbl_8803EBA4, u32@0x0, ts4_tailcall_NetDll_closesocket_884F0258, u32@0x20, lbl_8803A308 */
ts4_word ts4_if_call_seq_u32_off20_88429110(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803EBA4;
    p3 = (ts4_word)t1;
    if ((int)t1 != -1) {
        t2 = ts4_tailcall_NetDll_closesocket_884F0258((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)-1;
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(ts4_word)lbl_8803A308;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_8803A308;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p3;
}

/* Swing_DLL.xex 0x88429788: if_call_seq u32@0x20, lbl_8803EBA4, u32@0x0, ts4_tailcall_NetDll_closesocket_884F0258, u32@0x20, lbl_8803A308 */
ts4_word ts4_if_call_seq_u32_off20_88429788(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803EBA4;
    if ((int)t1 != -1) {
        ts4_tailcall_NetDll_closesocket_884F0258((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)-1;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(ts4_word)lbl_8803A308;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_8803A308;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t5 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t5, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x88429B48: call_seq lbl_8803A3CC, lbl_8803F4F8, fn_884C5468, lbl_8803A3B4, lbl_8803F50C, fn_884C5468 */
ts4_word ts4_call_seq_lbl_8803A3CC_88429B48(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_884C5468((ts4_word)a0, (ts4_word)(ts4_word)lbl_8803F4F8, (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803A3CC);
    t2 = fn_884C5468((ts4_word)a0, (ts4_word)(ts4_word)lbl_8803F50C, (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803A3B4);
    return t2;
}

/* Swing_DLL.xex 0x8842A828: call_seq lbl_8803FE64, lbl_8803FE7C, fn_884C5468, lbl_8803FE58, lbl_8803FE70, fn_884C5468 */
ts4_word ts4_call_seq_lbl_8803FE64_8842A828(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_884C5468((ts4_word)a0, (ts4_word)(ts4_word)lbl_8803FE7C, (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803FE64);
    t2 = fn_884C5468((ts4_word)a0, (ts4_word)(ts4_word)lbl_8803FE70, (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803FE58);
    return t2;
}

/* Swing_DLL.xex 0x8842A890: call_seq lbl_8803FE64, lbl_8803FE7C, fn_884C5468, lbl_8803FE58, lbl_8803FE70, fn_884C5468 */
ts4_word ts4_call_seq_lbl_8803FE64_8842A890(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_884C5468((ts4_word)a0, (ts4_word)(ts4_word)lbl_8803FE7C, (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803FE64);
    t2 = fn_884C5468((ts4_word)a0, (ts4_word)(ts4_word)lbl_8803FE70, (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803FE58);
    return t2;
}

/* Swing_DLL.xex 0x8842B1B8: if_call_seq lbl_88052B58, u32@lbl_88D26FCC, ts4_tailcall_fn_884CD990_884CE090, lbl_88B3CBD4, fn_884C6220, fn_8842B078 */
ts4_word ts4_if_call_seq_lbl_88052B58_8842B1B8(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t2;
    ts4_word t3;

    t2 = ts4_tailcall_fn_884CD990_884CE090((ts4_word)(*(ts4_word *)lbl_88D26FCC), (ts4_word)(ts4_word)lbl_88052B58);
    t3 = fn_884C6220((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88B3CBD4, (ts4_word)t2);
    if ((int)t3 == 0) {
        fn_8842B078((ts4_word)a0);
        p5 = (ts4_word)0;
    } else {
        p5 = (ts4_word)1;
    }
    return p5;
}

/* Swing_DLL.xex 0x88431FF8: call_seq fn_88432B08, u32@lbl_88CAD578, lbl_8805A548, u32@lbl_88D26FCC, ts4_tailcall_fn_884CD990_884CE090, lbl_88B3D288 */
ts4_word ts4_call_seq_fn_88432B08_88431FF8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t3;
    ts4_word t4;

    fn_88432B08((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    *(ts4_word *)lbl_88CAD578 = (ts4_word)(ts4_word)&loc50[0];
    t3 = ts4_tailcall_fn_884CD990_884CE090((ts4_word)(*(ts4_word *)lbl_88D26FCC), (ts4_word)(ts4_word)lbl_8805A548);
    t4 = fn_884C6220((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88B3D288, (ts4_word)t3);
    *(ts4_word *)lbl_88CAD578 = (ts4_word)0;
    fn_88423D60((ts4_word)(ts4_word)&loc50[0]);
    return t4;
}

/* Swing_DLL.xex 0x88432B70: if_call_seq fn_88423788, fn_88431250, u8@0x0 */
ts4_word ts4_if_call_seq_fn_88423788_88432B70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    t1 = fn_88423788((ts4_word)a1, (ts4_word)a2, (ts4_word)0);
    if ((ts4_word)t1 != 0) {
        fn_88431250((ts4_word)a0, (ts4_word)t1, (ts4_word)a3);
    } else {
        *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    }
    return a0;
}

/* Swing_DLL.xex 0x88433ED8: call_seq lbl_88042D94, fn_88433DD8, lbl_88042D84, fn_88433DD8, lbl_88042D78, fn_88433DD8 */
ts4_word ts4_call_seq_lbl_88042D94_88433ED8(ts4_word a0, ts4_word a1)
{
    ts4_word t7;

    fn_88433DD8((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88042D94);
    fn_88433DD8((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88042D84);
    fn_88433DD8((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88042D78);
    fn_88433DD8((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88042D6C);
    fn_88433DD8((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88042D60);
    fn_88433DD8((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88042D54);
    t7 = fn_88433DD8((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88042D48);
    return t7;
}

/* Swing_DLL.xex 0x88434C20: call_seq fn_88434B38, lbl_8806D1E8, u32@lbl_88D26FCC, ts4_tailcall_fn_884CD990_884CE090, lbl_88B3D3A8, fn_884C6220 */
ts4_word ts4_call_seq_fn_88434B38_88434C20(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    ts4_word t4;

    fn_88434B38();
    t3 = ts4_tailcall_fn_884CD990_884CE090((ts4_word)(*(ts4_word *)lbl_88D26FCC), (ts4_word)(ts4_word)lbl_8806D1E8);
    t4 = fn_884C6220((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88B3D3A8, (ts4_word)t3);
    return t4;
}
