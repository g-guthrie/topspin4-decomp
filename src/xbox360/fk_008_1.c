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
ts4_word ts4_loop_call_seq_fn_884027D8_884029E8();
ts4_word ts4_call_seq_fn_884025C0_88402FB0();
ts4_word ts4_call_seq_fn_884027D8_88402FD8();
ts4_word fn_88403BC8();
ts4_word fn_88403ED8();
ts4_word fn_88406148();
ts4_word fn_88406238();
ts4_word fn_88407630();
ts4_word fn_88408D58();
ts4_word fn_8840E420();
ts4_word fn_88412948();
ts4_word fn_88419938();
ts4_word fn_8841A258();
ts4_word fn_8841A510();
ts4_word fn_8841A590();
ts4_word ts4_call_seq_fn_8841A510_8841A7C8();
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
ts4_word ts4_get_u32_off4_88426130();
ts4_word fn_88426FF8();
ts4_word ts4_ref_holder_dtor_88427338();
ts4_word fn_88427958();
ts4_word fn_88427C08();
ts4_word fn_88427C18();
ts4_word fn_88427CA8();
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

/* Swing_DLL.xex 0x884083E0: if_call_seq fn_88406148, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88406148_884083E0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88406148();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)61);
    }
    return a0;
}

/* Swing_DLL.xex 0x88409D28: if_call_seq u16@0x4, lbl_8803A444, u32@0x0, u32@0x38, u32@0x34, u32@lbl_88CACF08 */
ts4_word ts4_if_call_seq_u16_off4_88409D28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p7;
    unsigned short t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A444;
    p7 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
        t5 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t6 = fn_8841A590((ts4_word)t5, (ts4_word)t3, (ts4_word)(t2 << 4), (ts4_word)58);
        p7 = (ts4_word)t6;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p7;
}

/* Swing_DLL.xex 0x8840C448: if_call_seq u16@0x4, lbl_8803A844, u32@0x0, u32@0x64, u32@0x60, u32@lbl_88CACF08 */
ts4_word ts4_if_call_seq_u16_off4_8840C448(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p7;
    unsigned short t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A844;
    p7 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 100);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
        t5 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t6 = fn_8841A590((ts4_word)t5, (ts4_word)t3, (ts4_word)t2, (ts4_word)56);
        p7 = (ts4_word)t6;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p7;
}

/* Swing_DLL.xex 0x8840E3D8: call_seq lbl_8803AA08, u32@0x0, fn_88403BC8, lbl_8803A308, u32@0x0 */
ts4_word ts4_call_seq_lbl_8803AA08_8840E3D8(ts4_word a0)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803AA08;
    t1 = fn_88403BC8((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return t1;
}

/* Swing_DLL.xex 0x8840ED90: call_seq ts4_call_seq_fn_884027D8_88402FD8, u32@0x0, ts4_call_seq_fn_884025C0_88402FB0, u32@0x0, ts4_loop_call_seq_fn_884027D8_884029E8, u32@0x0 */
ts4_word ts4_call_seq_fn_88402FD8_8840ED90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    t1 = ts4_call_seq_fn_884027D8_88402FD8((ts4_word)a1);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = ts4_call_seq_fn_884025C0_88402FB0((ts4_word)a2);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
    t5 = ts4_loop_call_seq_fn_884027D8_884029E8((ts4_word)a2);
    t7 = fn_8840E420((ts4_word)a0, (ts4_word)t2, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 0)), (ts4_word)a3);
    return t7;
}

/* Swing_DLL.xex 0x88413F98: if_call_seq u16@0x4, lbl_8803B244, u32@0x0, u32@0x5c, u32@0x58, u32@lbl_88CACF08 */
ts4_word ts4_if_call_seq_u16_off4_88413F98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p7;
    unsigned short t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803B244;
    p7 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
        t5 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t6 = fn_8841A590((ts4_word)t5, (ts4_word)t3, (ts4_word)t2, (ts4_word)56);
        p7 = (ts4_word)t6;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p7;
}

/* Swing_DLL.xex 0x88425FA0: if_call_seq u32@0x10, u32@0x18, lbl_8803E868, u16@0x6, u32@0x0, u32@0xc */
ts4_word ts4_if_call_seq_u32_off10_88425FA0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a3;
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803E868;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)-1;
    if ((int)a3 == 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t3 = ts4_call_seq_fn_8841A510_8841A7C8((ts4_word)t2, (ts4_word)a2, (ts4_word)26);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
        fn_88421450((ts4_word)t3, (ts4_word)a1, (ts4_word)a2);
        return a0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    return a0;
}

/* Swing_DLL.xex 0x88426110: addr lbl_88B3C5B8 */
ts4_word ts4_addr_lbl_88B3C5B8_88426110(ts4_word a0)
{
    return (((a0 + (a0 << 1)) << 2) + (ts4_word)lbl_88B3C5B8);
}

/* Swing_DLL.xex 0x88428AC8: if_call_seq u32@0x4, ts4_get_u32_off4_88426130, u32@0x0, u32@0x0, fn_8841ED98, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off4_88428AC8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t2 = ts4_get_u32_off4_88426130((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    t4 = fn_8841ED98((ts4_word)t2, (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((*(unsigned short *)((char *)(ts4_word)(t4) + 18)) + t3);
    }
    return a0;
}

/* Swing_DLL.xex 0x88428B48: call_seq u32@0x4, ts4_get_u32_off4_88426130, u32@0x0, u32@0x4, u32@0x0 */
ts4_word ts4_call_seq_u32_off4_88428B48(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;

    t2 = ts4_get_u32_off4_88426130((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
    return a0;
}

/* Swing_DLL.xex 0x884292B8: if_set fn_88425490, u32@0x20, lbl_8803EBA4, u32@0x0, u32@0x10, vcall */
ts4_word ts4_if_set_fn_88425490_884292B8(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    fn_88425490();
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803EBA4;
    if ((int)a1 == -1) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8803EBA4) + 16))))((ts4_word)a0);
        t4 = ts4_tailcall_NetDll_socket_884F0240((ts4_word)2, (ts4_word)1, (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)t4;
    }
    return a0;
}

