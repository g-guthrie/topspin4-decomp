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

extern char fn_8845C208[];
extern char fn_8845D078[];
extern char fn_8845D370[];
extern char lbl_8803A308[];
extern char lbl_8807FF50[];
extern char lbl_88082070[];
extern char lbl_88082A64[];
extern char lbl_88082AA0[];
extern char lbl_88082B04[];
extern char lbl_88082B40[];
extern char lbl_88082B8C[];
extern char lbl_88082DC0[];
extern char lbl_88082E58[];
extern char lbl_88083214[];
extern char lbl_8808340C[];
extern char lbl_8808356C[];
extern char lbl_8808379C[];
extern char lbl_880837B4[];
extern char lbl_8808384C[];
extern char lbl_8808386C[];
extern char lbl_880838A4[];
extern char lbl_88083C6C[];
extern char lbl_88083C8C[];
extern char lbl_88083CFC[];
extern char lbl_88083E24[];
extern char lbl_88083EEC[];
extern char lbl_88083F24[];
extern char lbl_8808406C[];
extern char lbl_8808411C[];
extern char lbl_88084264[];
extern char lbl_88084334[];
extern char lbl_880843CC[];
extern char lbl_8808466C[];
extern char lbl_880846E8[];
extern char lbl_88084948[];
extern char lbl_880849B0[];
extern char lbl_88084AC4[];
extern char lbl_88084BDC[];
extern char lbl_88084BFC[];
extern char lbl_88084C94[];
extern char lbl_88084CAC[];
extern char lbl_88084D14[];
extern char lbl_88084E84[];
extern char lbl_88084EBC[];
extern char lbl_88084F6C[];
extern char lbl_880850AC[];
extern char lbl_880869CC[];
extern char lbl_880869E8[];
extern char lbl_880869F8[];
extern char lbl_88CACF08[];
ts4_word KeTlsGetValue();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_8841A510();
ts4_word fn_8841A590();
ts4_word fn_88420E48();
ts4_word fn_88425B90();
ts4_word fn_88462090();
ts4_word fn_88462C70();
ts4_word fn_88463610();
ts4_word fn_884636B0();
ts4_word ts4_if_call_seq_lbl_8807FF50_884653E0();
ts4_word fn_884684A8();
ts4_word fn_88468D78();
ts4_word fn_884691E8();
ts4_word ts4_pooled_deleting_dtor_8846A1B8();
ts4_word fn_8846B868();
ts4_word fn_8846B998();
ts4_word fn_8846BB60();
ts4_word fn_8846BC08();
ts4_word fn_8846BD20();
ts4_word fn_8846D6D0();
ts4_word fn_88471C08();
ts4_word ts4_if_call_seq_lbl_880869E8_884724C0();
ts4_word fn_88472530();
ts4_word ts4_addr_lbl_88084948_88472AD8();
ts4_word fn_88472BF0();
ts4_word fn_88473508();
ts4_word fn_88474120();
ts4_word fn_884748C0();
ts4_word fn_88475158();
ts4_word fn_884761E0();
ts4_word fn_88476860();
ts4_word fn_88476B90();
ts4_word fn_88476CB0();
ts4_word fn_88477588();
ts4_word fn_88477610();
ts4_word fn_884781E8();
ts4_word fn_88478648();
ts4_word fn_88478D50();
ts4_word ts4_ref_holder_dtor_88479760();
ts4_word fn_8847A4A0();
ts4_word fn_8847AF38();
ts4_word fn_8847B270();
ts4_word fn_8847D7F0();
ts4_word fn_8847EF68();
ts4_word fn_8847EFC8();
ts4_word fn_88480128();
ts4_word fn_88481ED8();
ts4_word fn_88483028();
ts4_word ts4_addr_lbl_8803A308_884834E0();
ts4_word fn_884834F0();
ts4_word fn_88483500();
ts4_word fn_88483520();
ts4_word ts4_set_u32_offfc_884876C0();
ts4_word fn_88487AD8();
ts4_word fn_88487B38();
ts4_word fn_88488090();
ts4_word fn_88489498();
ts4_word fn_885068E8();
ts4_word fn_88531FF8();
ts4_word fn_88537FC8();
ts4_word fn_885E85B8();
ts4_word fn_885E8F50();
ts4_word fn_885E9000();
ts4_word fn_885E90D8();
ts4_word ts4_tailcall_fn_885E8F50_885E9160();
ts4_word fn_885E9AB8();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x8845C5B0: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u32@0x8, lbl_88082A64, u16@0x4 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_8845C5B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    (void)a1;
    (void)a2;
    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)32, (ts4_word)31);
    *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)a3;
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)32;
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88082A64;
    *(unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    *(unsigned short *)((char *)(ts4_word)(t3) + 12) = (unsigned short)-1;
    fn_88537FC8((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + 32), (ts4_word)(t3 + 16));
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88082AA0;
    return t3;
}

/* Swing_DLL.xex 0x8845D480: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u32@0x8, lbl_88082B04, u16@0x4 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_8845D480(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    (void)a1;
    (void)a2;
    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)16, (ts4_word)31);
    *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)a3;
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)16;
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88082B04;
    *(unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    *(unsigned short *)((char *)(ts4_word)(t3) + 12) = (unsigned short)-1;
    return t3;
}

/* Swing_DLL.xex 0x8845D550: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u32@0x8, lbl_88082B40, u16@0x4 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_8845D550(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    (void)a1;
    (void)a2;
    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)16, (ts4_word)31);
    *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)a3;
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)16;
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88082B40;
    *(unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    *(unsigned short *)((char *)(ts4_word)(t3) + 12) = (unsigned short)-1;
    return t3;
}

/* Swing_DLL.xex 0x8845E618: if_get u16@0xc, u32@0x8, u32@0x0, u32@0x14, vcall, u16@0xc */
ts4_word ts4_if_get_u16_offc_8845E618(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    unsigned short t1;
    ts4_word t2;
    ts4_word t10;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 65535) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 20))))((ts4_word)t2, (ts4_word)t1, (ts4_word)a1);
        *(unsigned short *)((char *)(ts4_word)(a0) + 12) = (unsigned short)-1;
    }
    t10 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)1);
    return t10;
}

/* Swing_DLL.xex 0x8845E688: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u32@0x8, lbl_88082B8C, u16@0x4 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_8845E688(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    (void)a1;
    (void)a2;
    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)16, (ts4_word)31);
    *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)a3;
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)16;
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88082B8C;
    *(unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    *(unsigned short *)((char *)(ts4_word)(t3) + 12) = (unsigned short)-1;
    return t3;
}

/* Swing_DLL.xex 0x88460290: get u32@0xc, u32@0x0, u32@0x1c, vcall, u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_offc_88460290(ts4_word a0)
{
    ts4_word t1;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 28))))((ts4_word)t1);
    t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)1);
    return t7;
}

/* Swing_DLL.xex 0x88460390: get u32@0xc, u32@0x0, u32@0x28 */
ts4_word ts4_get_u32_offc_88460390(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884603A8: get u32@0xc, u32@0x0, u32@0x2c */
ts4_word ts4_get_u32_offc_884603A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 44))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884603C0: get u32@0xc, u32@0x0, u32@0x30 */
ts4_word ts4_get_u32_offc_884603C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 48))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884603D8: get u32@0xc, u32@0x0, u32@0x34 */
ts4_word ts4_get_u32_offc_884603D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 52))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884612B0: if_call_seq lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_lbl_8803A308_884612B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)31);
    }
    return a0;
}

/* Swing_DLL.xex 0x88462280: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_88462090 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_88462280(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)56, (ts4_word)31);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)56;
    t4 = fn_88462090((ts4_word)t3, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    return t4;
}

/* Swing_DLL.xex 0x884622D8: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_88462090, lbl_88082070 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_884622D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)56, (ts4_word)31);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)56;
    fn_88462090((ts4_word)t3, (ts4_word)a1, (ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88082070;
    return t3;
}

/* Swing_DLL.xex 0x88462E58: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_88462C70 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_88462E58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)56, (ts4_word)31);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)56;
    t4 = fn_88462C70((ts4_word)t3, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    return t4;
}

/* Swing_DLL.xex 0x88462EB0: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_88462C70, lbl_88082DC0 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_88462EB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)56, (ts4_word)31);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)56;
    fn_88462C70((ts4_word)t3, (ts4_word)a1, (ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88082DC0;
    return t3;
}

/* Swing_DLL.xex 0x88463410: if_get u32@0xc, u32@0x0, u32@0x1c, vcall, u32@0x10, u32@0x0 */
ts4_word ts4_if_get_u32_offc_88463410(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 28))))((ts4_word)t1);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t5 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 28))))((ts4_word)t5, (ts4_word)a1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    }
    t12 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)1);
    return t12;
}

/* Swing_DLL.xex 0x88463780: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_884636B0 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_88463780(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)20, (ts4_word)31);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)20;
    t4 = fn_884636B0((ts4_word)t3, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    return t4;
}

/* Swing_DLL.xex 0x884644D0: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_884636B0, lbl_88082E58 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_884644D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)20, (ts4_word)31);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)20;
    fn_884636B0((ts4_word)t3, (ts4_word)a1, (ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88082E58;
    return t3;
}

/* Swing_DLL.xex 0x88464780: tailcall fn_88463610 */
ts4_word ts4_tailcall_fn_88463610_88464780(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88463610((ts4_word)a0, (ts4_word)a2, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88464D38: get u32@0x1c */
ts4_word ts4_get_u32_off1c_88464D38(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 28));
}

/* Swing_DLL.xex 0x88464D58: fn  */
ts4_word ts4_fn_88464D58(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88464D60: if_get u32@0x14 */
ts4_word ts4_if_get_u32_off14_88464D60(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((int)(a1 + 1) < (int)t1) {
        return (a1 + 1);
    }
    return -1;
}

/* Swing_DLL.xex 0x884653D8: tailcall ts4_if_call_seq_lbl_8807FF50_884653E0 */
ts4_word ts4_tailcall_fn_884653E0_884653D8(ts4_word a0)
{
    return ts4_if_call_seq_lbl_8807FF50_884653E0((ts4_word)(a0 + -20));
}

/* Swing_DLL.xex 0x884666C0: get u32@0x8, u32@0x0, u32@0x4, vcall, u32@0x8, u8@0x4 */
ts4_word ts4_get_u32_off8_884666C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t4 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 4))))((ts4_word)t1, (ts4_word)a2, (ts4_word)a1);
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 4));
    return t4;
}

/* Swing_DLL.xex 0x88466778: addr lbl_88083214, u16@0x6, u32@0x0, u32@0x8 */
void ts4_addr_lbl_88083214_88466778(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88083214;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88466928: get u32@0x0, u32@0x8, u32@0x4, u32@0x0, u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off0_88466928(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 24))))((ts4_word)t1, (ts4_word)t4, (ts4_word)t3, (ts4_word)t2);
    return (a2 + 16);
}

/* Swing_DLL.xex 0x88467640: get u32@0x8, fn_88531FF8, u32@0x0, u32@0x0, vcall */
ts4_word ts4_get_u32_off8_88467640(ts4_word a0, ts4_word a1)
{
    ts4_word t5;

    fn_88531FF8((ts4_word)(a0 + 48), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a1);
    t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)1);
    return t5;
}

/* Swing_DLL.xex 0x884682A0: set u8@0x4 */
void ts4_set_u8_off4_884682A0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88468338: set u16@0x2, u16@0x6, u16@0xa, u16@0xe, u16@0x12, u16@0x16 */
void ts4_set_u16_off2_88468338(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 2) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 10) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 14) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 18) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 22) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 26) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 30) = (unsigned short)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 33) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 34) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88468570: if_call_seq fn_884684A8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884684A8_88468570(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884684A8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x884686A0: if_call_seq fn_884781E8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884781E8_884686A0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884781E8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)49);
    }
    return a0;
}

/* Swing_DLL.xex 0x88468730: if_addr lbl_8808340C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8808340C_88468730(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808340C;
    return;
}

/* Swing_DLL.xex 0x88468750: addr lbl_8808340C */
ts4_word ts4_addr_lbl_8808340C_88468750(void)
{
    return (ts4_word)lbl_8808340C;
}

/* Swing_DLL.xex 0x884687E0: if_addr lbl_8808356C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8808356C_884687E0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808356C;
    return;
}

/* Swing_DLL.xex 0x88468800: addr lbl_8808356C */
ts4_word ts4_addr_lbl_8808356C_88468800(void)
{
    return (ts4_word)lbl_8808356C;
}

/* Swing_DLL.xex 0x88468810: if_call_seq lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_lbl_8803A308_88468810(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)46);
    }
    return a0;
}

/* Swing_DLL.xex 0x88468930: if_call_seq fn_88477588, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88477588_88468930(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88477588();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)49);
    }
    return a0;
}

/* Swing_DLL.xex 0x88468A00: if_call_seq fn_8847A4A0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8847A4A0_88468A00(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8847A4A0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)49);
    }
    return a0;
}

/* Swing_DLL.xex 0x88468A80: if_addr lbl_8808379C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8808379C_88468A80(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808379C;
    return;
}

/* Swing_DLL.xex 0x88468AA0: addr lbl_8808379C */
ts4_word ts4_addr_lbl_8808379C_88468AA0(void)
{
    return (ts4_word)lbl_8808379C;
}

/* Swing_DLL.xex 0x88468AC8: if_addr lbl_880837B4, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_880837B4_88468AC8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880837B4;
    return;
}

/* Swing_DLL.xex 0x88468AE8: addr lbl_880837B4 */
ts4_word ts4_addr_lbl_880837B4_88468AE8(void)
{
    return (ts4_word)lbl_880837B4;
}

/* Swing_DLL.xex 0x88468B10: if_addr lbl_8808386C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8808386C_88468B10(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808386C;
    return;
}

/* Swing_DLL.xex 0x88468B30: addr lbl_8808386C */
ts4_word ts4_addr_lbl_8808386C_88468B30(void)
{
    return (ts4_word)lbl_8808386C;
}

/* Swing_DLL.xex 0x88468B40: if_call_seq fn_88476CB0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88476CB0_88468B40(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88476CB0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)44);
    }
    return a0;
}

/* Swing_DLL.xex 0x88468BA8: if_call_seq fn_8847AF38, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8847AF38_88468BA8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8847AF38();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)44);
    }
    return a0;
}

/* Swing_DLL.xex 0x88468C10: if_addr lbl_880838A4, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_880838A4_88468C10(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880838A4;
    return;
}

/* Swing_DLL.xex 0x88468C48: addr lbl_880838A4 */
ts4_word ts4_addr_lbl_880838A4_88468C48(void)
{
    return (ts4_word)lbl_880838A4;
}

/* Swing_DLL.xex 0x88468C58: if_call_seq lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_lbl_8803A308_88468C58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)41);
    }
    return a0;
}

/* Swing_DLL.xex 0x88468CD0: if_addr lbl_8808384C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8808384C_88468CD0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808384C;
    return;
}

/* Swing_DLL.xex 0x88468CF0: addr lbl_8808384C */
ts4_word ts4_addr_lbl_8808384C_88468CF0(void)
{
    return (ts4_word)lbl_8808384C;
}

/* Swing_DLL.xex 0x88468D70: tailcall fn_88468D78 */
ts4_word ts4_tailcall_fn_88468D78_88468D70(ts4_word a0)
{
    return fn_88468D78((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x88468E60: if_addr lbl_88083C6C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88083C6C_88468E60(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88083C6C;
    return;
}

/* Swing_DLL.xex 0x88468E80: addr lbl_88083C6C */
ts4_word ts4_addr_lbl_88083C6C_88468E80(void)
{
    return (ts4_word)lbl_88083C6C;
}

/* Swing_DLL.xex 0x88468EA8: if_addr lbl_88083CFC, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88083CFC_88468EA8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88083CFC;
    return;
}

/* Swing_DLL.xex 0x88468EC8: addr lbl_88083CFC */
ts4_word ts4_addr_lbl_88083CFC_88468EC8(void)
{
    return (ts4_word)lbl_88083CFC;
}

/* Swing_DLL.xex 0x88468ED8: if_call_seq fn_8847B270, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8847B270_88468ED8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8847B270((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)46);
    }
    return a0;
}

/* Swing_DLL.xex 0x88468FC8: if_addr lbl_88083E24, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88083E24_88468FC8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88083E24;
    return;
}

/* Swing_DLL.xex 0x88468FE8: addr lbl_88083E24 */
ts4_word ts4_addr_lbl_88083E24_88468FE8(void)
{
    return (ts4_word)lbl_88083E24;
}

/* Swing_DLL.xex 0x88469020: if_addr lbl_88083EEC, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88083EEC_88469020(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88083EEC;
    return;
}

/* Swing_DLL.xex 0x88469040: addr lbl_88083EEC */
ts4_word ts4_addr_lbl_88083EEC_88469040(void)
{
    return (ts4_word)lbl_88083EEC;
}

/* Swing_DLL.xex 0x88469080: if_addr lbl_88083C8C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88083C8C_88469080(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88083C8C;
    return;
}

/* Swing_DLL.xex 0x884690A0: addr lbl_88083C8C */
ts4_word ts4_addr_lbl_88083C8C_884690A0(void)
{
    return (ts4_word)lbl_88083C8C;
}

/* Swing_DLL.xex 0x884690B0: if_addr lbl_88083F24, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88083F24_884690B0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88083F24;
    return;
}

/* Swing_DLL.xex 0x884690D0: addr lbl_88083F24 */
ts4_word ts4_addr_lbl_88083F24_884690D0(void)
{
    return (ts4_word)lbl_88083F24;
}

/* Swing_DLL.xex 0x88469108: if_addr lbl_8808406C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8808406C_88469108(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808406C;
    return;
}

/* Swing_DLL.xex 0x88469128: addr lbl_8808406C */
ts4_word ts4_addr_lbl_8808406C_88469128(void)
{
    return (ts4_word)lbl_8808406C;
}

/* Swing_DLL.xex 0x88469138: if_call_seq fn_8847D7F0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8847D7F0_88469138(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8847D7F0((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)44);
    }
    return a0;
}

/* Swing_DLL.xex 0x884691B8: if_addr lbl_8808411C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8808411C_884691B8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808411C;
    return;
}

/* Swing_DLL.xex 0x884691D8: addr lbl_8808411C */
ts4_word ts4_addr_lbl_8808411C_884691D8(void)
{
    return (ts4_word)lbl_8808411C;
}

/* Swing_DLL.xex 0x88469260: if_call_seq fn_884691E8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884691E8_88469260(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884691E8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)44);
    }
    return a0;
}

/* Swing_DLL.xex 0x88469340: if_addr lbl_88084264, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88084264_88469340(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88084264;
    return;
}

/* Swing_DLL.xex 0x88469360: addr lbl_88084264 */
ts4_word ts4_addr_lbl_88084264_88469360(void)
{
    return (ts4_word)lbl_88084264;
}

/* Swing_DLL.xex 0x88469370: if_call_seq fn_8847EFC8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8847EFC8_88469370(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8847EFC8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)47);
    }
    return a0;
}

/* Swing_DLL.xex 0x88469460: if_call_seq fn_88480128, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88480128_88469460(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88480128((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)44);
    }
    return a0;
}

/* Swing_DLL.xex 0x884694F0: if_addr lbl_88084334, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88084334_884694F0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88084334;
    return;
}

/* Swing_DLL.xex 0x88469510: addr lbl_88084334 */
ts4_word ts4_addr_lbl_88084334_88469510(void)
{
    return (ts4_word)lbl_88084334;
}

/* Swing_DLL.xex 0x88469538: if_addr lbl_880843CC, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_880843CC_88469538(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880843CC;
    return;
}

/* Swing_DLL.xex 0x88469558: addr lbl_880843CC */
ts4_word ts4_addr_lbl_880843CC_88469558(void)
{
    return (ts4_word)lbl_880843CC;
}

/* Swing_DLL.xex 0x884695F8: if_addr lbl_8808466C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8808466C_884695F8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808466C;
    return;
}

/* Swing_DLL.xex 0x88469618: addr lbl_8808466C */
ts4_word ts4_addr_lbl_8808466C_88469618(void)
{
    return (ts4_word)lbl_8808466C;
}

/* Swing_DLL.xex 0x88469628: if_call_seq fn_88481ED8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88481ED8_88469628(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88481ED8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)44);
    }
    return a0;
}

/* Swing_DLL.xex 0x884696B8: if_addr lbl_880846E8, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_880846E8_884696B8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880846E8;
    return;
}

/* Swing_DLL.xex 0x884696D8: addr lbl_880846E8 */
ts4_word ts4_addr_lbl_880846E8_884696D8(void)
{
    return (ts4_word)lbl_880846E8;
}

/* Swing_DLL.xex 0x884697C0: if_call_seq fn_88476860, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88476860_884697C0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88476860();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)44);
    }
    return a0;
}

/* Swing_DLL.xex 0x88469918: if_call_seq fn_884748C0, lbl_88084948, u32@0x0 */
ts4_word ts4_if_call_seq_fn_884748C0_88469918(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p3 = (ts4_word)a0;
    if ((ts4_word)a0 != 0) {
        t1 = fn_884748C0((ts4_word)a0, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88084948;
        p3 = (ts4_word)t1;
    }
    return p3;
}

/* Swing_DLL.xex 0x88469990: if_call_seq ts4_addr_lbl_88084948_88472AD8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88472AD8_88469990(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_addr_lbl_88084948_88472AD8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)45);
    }
    return a0;
}

/* Swing_DLL.xex 0x88469A20: if_addr lbl_880849B0, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_880849B0_88469A20(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880849B0;
    return;
}

/* Swing_DLL.xex 0x88469A40: addr lbl_880849B0 */
ts4_word ts4_addr_lbl_880849B0_88469A40(void)
{
    return (ts4_word)lbl_880849B0;
}

/* Swing_DLL.xex 0x88469B20: if_call_seq fn_88483028, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88483028_88469B20(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88483028((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)49);
    }
    return a0;
}

/* Swing_DLL.xex 0x88469BA0: if_addr lbl_88084AC4, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88084AC4_88469BA0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88084AC4;
    return;
}

/* Swing_DLL.xex 0x88469BC0: addr lbl_88084AC4 */
ts4_word ts4_addr_lbl_88084AC4_88469BC0(void)
{
    return (ts4_word)lbl_88084AC4;
}

/* Swing_DLL.xex 0x88469BD0: if_call_seq ts4_addr_lbl_8803A308_884834E0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884834E0_88469BD0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_addr_lbl_8803A308_884834E0((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x88469C58: if_addr lbl_88084BDC, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88084BDC_88469C58(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88084BDC;
    return;
}

/* Swing_DLL.xex 0x88469C78: addr lbl_88084BDC */
ts4_word ts4_addr_lbl_88084BDC_88469C78(void)
{
    return (ts4_word)lbl_88084BDC;
}

/* Swing_DLL.xex 0x88469C88: if_call_seq lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_lbl_8803A308_88469C88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)43);
    }
    return a0;
}

/* Swing_DLL.xex 0x88469D00: if_addr lbl_88084BFC, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88084BFC_88469D00(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88084BFC;
    return;
}

/* Swing_DLL.xex 0x88469D20: addr lbl_88084BFC */
ts4_word ts4_addr_lbl_88084BFC_88469D20(void)
{
    return (ts4_word)lbl_88084BFC;
}

/* Swing_DLL.xex 0x88469D48: if_addr lbl_88084C94, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88084C94_88469D48(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88084C94;
    return;
}

/* Swing_DLL.xex 0x88469D68: addr lbl_88084C94 */
ts4_word ts4_addr_lbl_88084C94_88469D68(void)
{
    return (ts4_word)lbl_88084C94;
}

/* Swing_DLL.xex 0x88469D90: if_addr lbl_88084CAC, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88084CAC_88469D90(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88084CAC;
    return;
}

/* Swing_DLL.xex 0x88469DB0: addr lbl_88084CAC */
ts4_word ts4_addr_lbl_88084CAC_88469DB0(void)
{
    return (ts4_word)lbl_88084CAC;
}

/* Swing_DLL.xex 0x88469DD8: if_addr lbl_88084D14, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88084D14_88469DD8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88084D14;
    return;
}

/* Swing_DLL.xex 0x88469DF8: addr lbl_88084D14 */
ts4_word ts4_addr_lbl_88084D14_88469DF8(void)
{
    return (ts4_word)lbl_88084D14;
}

/* Swing_DLL.xex 0x88469E98: if_addr lbl_88084E84, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88084E84_88469E98(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88084E84;
    return;
}

/* Swing_DLL.xex 0x88469EB8: addr lbl_88084E84 */
ts4_word ts4_addr_lbl_88084E84_88469EB8(void)
{
    return (ts4_word)lbl_88084E84;
}

/* Swing_DLL.xex 0x88469EE0: if_addr lbl_88084EBC, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88084EBC_88469EE0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88084EBC;
    return;
}

/* Swing_DLL.xex 0x88469F00: addr lbl_88084EBC */
ts4_word ts4_addr_lbl_88084EBC_88469F00(void)
{
    return (ts4_word)lbl_88084EBC;
}

/* Swing_DLL.xex 0x88469F28: if_addr lbl_88084F6C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88084F6C_88469F28(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88084F6C;
    return;
}

/* Swing_DLL.xex 0x88469F48: addr lbl_88084F6C */
ts4_word ts4_addr_lbl_88084F6C_88469F48(void)
{
    return (ts4_word)lbl_88084F6C;
}

/* Swing_DLL.xex 0x88469F80: if_addr lbl_880850AC, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_880850AC_88469F80(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880850AC;
    return;
}

/* Swing_DLL.xex 0x88469FA0: addr lbl_880850AC */
ts4_word ts4_addr_lbl_880850AC_88469FA0(void)
{
    return (ts4_word)lbl_880850AC;
}

/* Swing_DLL.xex 0x88469FB0: if_call_seq lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_lbl_8803A308_88469FB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)44);
    }
    return a0;
}

/* Swing_DLL.xex 0x8846A0F0: tailcall ts4_pooled_deleting_dtor_8846A1B8 */
ts4_word ts4_tailcall_fn_8846A1B8_8846A0F0(ts4_word a0)
{
    return ts4_pooled_deleting_dtor_8846A1B8((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x8846A490: get u32@0x0, lbl_880869CC, u32@0x4, vcall, u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off0_8846A490(ts4_word a0, ts4_word a1)
{
    ts4_word t6;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(ts4_word)lbl_880869CC, (ts4_word)2, (ts4_word)a0);
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 24))))((ts4_word)a1);
    return t6;
}

/* Swing_DLL.xex 0x8846A4F0: if_call_seq lbl_880869F8, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880869F8_8846A4F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880869F8;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x8846A598: set u32@0x0 */
void ts4_set_u32_off0_8846A598(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)70;
    return;
}

/* Swing_DLL.xex 0x8846A718: get u32@0x8 */
float ts4_get_u32_off8_8846A718(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 20));
}

/* Swing_DLL.xex 0x8846A728: get u32@0x8 */
float ts4_get_u32_off8_8846A728(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 24));
}

/* Swing_DLL.xex 0x8846A738: get u32@0x8, u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_off8_8846A738(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8846A768: get u32@0x8, fn_884834F0 */
ts4_word ts4_get_u32_off8_8846A768(ts4_word a0)
{
    return fn_884834F0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
}

/* Swing_DLL.xex 0x8846A770: get u32@0x8, fn_88483500 */
ts4_word ts4_get_u32_off8_8846A770(ts4_word a0)
{
    return fn_88483500((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
}

/* Swing_DLL.xex 0x8846A778: get u32@0x8, fn_88483520 */
ts4_word ts4_get_u32_off8_8846A778(ts4_word a0)
{
    return fn_88483520((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
}

/* Swing_DLL.xex 0x8846A780: get u32@0x8, fn_88488090 */
ts4_word ts4_get_u32_off8_8846A780(ts4_word a0)
{
    return fn_88488090((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
}

/* Swing_DLL.xex 0x8846A788: get u32@0x8, fn_88487B38 */
ts4_word ts4_get_u32_off8_8846A788(ts4_word a0)
{
    return fn_88487B38((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
}

/* Swing_DLL.xex 0x8846A790: get u32@0x8, fn_88487AD8 */
ts4_word ts4_get_u32_off8_8846A790(ts4_word a0)
{
    return fn_88487AD8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
}

/* Swing_DLL.xex 0x8846A798: get u32@0x8, ts4_set_u32_offfc_884876C0 */
ts4_word ts4_get_u32_off8_8846A798(ts4_word a0)
{
    return ts4_set_u32_offfc_884876C0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
}

/* Swing_DLL.xex 0x8846A7A0: get u32@0x8, u32@0x0, u32@0x48 */
ts4_word ts4_get_u32_off8_8846A7A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 72))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8846A7B8: get u32@0x8, u32@0x0, u32@0x4c */
ts4_word ts4_get_u32_off8_8846A7B8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8846A7D0: get u32@0x8, u32@0x0, u32@0x50 */
ts4_word ts4_get_u32_off8_8846A7D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 80))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8846A7F0: get u32@0x50 */
ts4_word ts4_get_u32_off50_8846A7F0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 80));
}

/* Swing_DLL.xex 0x8846A898: get u32@0x54, u32@0x0, u32@0x4c, vcall, u32@0x54, u32@0x6c */
ts4_word ts4_get_u32_off54_8846A898(ts4_word a0)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 108);
    t9 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 80))))((ts4_word)t5, (ts4_word)(t6 + 32), (ts4_word)(t6 + 48));
    return t9;
}

/* Swing_DLL.xex 0x8846A9B0: get u32@0x18c */
ts4_word ts4_get_u32_off18c_8846A9B0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 396));
}

/* Swing_DLL.xex 0x8846AA28: get u32@0x7c, fn_88489498 */
ts4_word ts4_get_u32_off7c_8846AA28(ts4_word a0)
{
    return fn_88489498((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 124)));
}

/* Swing_DLL.xex 0x8846AA30: get u32@0xac, u64@0x20, RtlLeaveCriticalSection */
ts4_word ts4_get_u32_offac_8846AA30(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 172);
    *(ts4_u64 *)((char *)(ts4_word)(t1) + 32) = (ts4_u64)-1;
    return RtlLeaveCriticalSection((ts4_word)t1);
}

/* Swing_DLL.xex 0x8846BA48: call_seq fn_8846B868, fn_8846B998, u8@0x0, u8@0x40 */
ts4_word ts4_call_seq_fn_8846B868_8846BA48(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t2;

    fn_8846B868((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    t2 = fn_8846B998((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    *(unsigned char *)((char *)(ts4_word)(a1) + 64) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(t2) + 0));
    return t2;
}

/* Swing_DLL.xex 0x8846BE08: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_8847EF68, fn_8846B868 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_8846BE08(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)68, (ts4_word)47);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)68;
    t4 = fn_8847EF68((ts4_word)t3);
    fn_8846B868((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)t4);
    t6 = fn_8846B998((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)t4);
    *(unsigned char *)((char *)(ts4_word)(t4) + 64) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(t6) + 0));
    fn_8846BD20((ts4_word)a0, (ts4_word)t4);
    fn_8846BB60((ts4_word)a0, (ts4_word)t4);
    fn_8846BC08((ts4_word)a0, (ts4_word)t4);
    return t4;
}

/* Swing_DLL.xex 0x8846C158: get u32@0xac, fn_88472530 */
ts4_word ts4_get_u32_offac_8846C158(ts4_word a0)
{
    return fn_88472530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 172)));
}

/* Swing_DLL.xex 0x88471D50: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_88476B90, u32@0x8 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_88471D50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)44, (ts4_word)44);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)44;
    t4 = fn_88476B90((ts4_word)t3, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)1);
    *(ts4_word *)((char *)(ts4_word)(t4) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a3) + 8));
    fn_88471C08((ts4_word)a0, (ts4_word)t4);
    return t4;
}

/* Swing_DLL.xex 0x88472448: tailcall ts4_if_call_seq_lbl_880869E8_884724C0 */
ts4_word ts4_tailcall_fn_884724C0_88472448(ts4_word a0)
{
    return ts4_if_call_seq_lbl_880869E8_884724C0((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x88472450: fn  */
ts4_word ts4_fn_88472450(ts4_word a0)
{
    return (a0 + 8);
}

/* Swing_DLL.xex 0x884728F8: if_call_seq fn_8846D6D0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8846D6D0_884728F8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8846D6D0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)47);
    }
    return a0;
}

/* Swing_DLL.xex 0x88472960: get fn_88474120, u32@0xd0, u32@0x48, vcall */
ts4_word ts4_get_fn_88474120_88472960(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    fn_88474120((ts4_word)a0);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 208))) + 72))))((ts4_word)(a0 + 208), (ts4_word)a1);
    return t4;
}

/* Swing_DLL.xex 0x884729B0: get fn_88474120, u32@0xd0, u32@0x50, vcall */
ts4_word ts4_get_fn_88474120_884729B0(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    fn_88474120((ts4_word)a0);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 208))) + 80))))((ts4_word)(a0 + 208), (ts4_word)a1);
    return t4;
}

/* Swing_DLL.xex 0x88472AE8: fn  */
ts4_word ts4_fn_88472AE8(ts4_word a0)
{
    return (a0 + 224);
}

/* Swing_DLL.xex 0x88472B80: get u32@0xd0, u32@0xc */
ts4_word ts4_get_u32_offd0_88472B80(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 208))) + 12))))((ts4_word)(a0 + 208), (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88472B98: get u32@0xd0, u32@0x10 */
ts4_word ts4_get_u32_offd0_88472B98(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 208))) + 16))))((ts4_word)(a0 + 208), (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88472BB0: set  */
void ts4_set_88472BB0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 132) = f1;
    return;
}

/* Swing_DLL.xex 0x88472BB8: set  */
void ts4_set_88472BB8(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 136) = f1;
    return;
}

/* Swing_DLL.xex 0x88472BC0: get u32@0xd0, u32@0x1c */
ts4_word ts4_get_u32_offd0_88472BC0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 208))) + 28))))((ts4_word)(a0 + 208), (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88472BD8: get u32@0xd0, u32@0x20 */
ts4_word ts4_get_u32_offd0_88472BD8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 208))) + 32))))((ts4_word)(a0 + 208), (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88473468: get u32@0xd0, u32@0x2c, vcall, u32@0x10, fn_88472BF0 */
ts4_word ts4_get_u32_offd0_88473468(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t5;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 208))) + 44))))((ts4_word)(a0 + 208));
    t5 = fn_88472BF0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)(ts4_word)&loc50[0]);
    return t5;
}

/* Swing_DLL.xex 0x88473638: get u32@0xd0, u32@0x30, vcall, fn_88473508 */
ts4_word ts4_get_u32_offd0_88473638(ts4_word a0)
{
    ts4_word t4;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 208))) + 48))))((ts4_word)(a0 + 208));
    t4 = fn_88473508((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88473680: get u32@0xd0, u32@0x34, vcall, fn_88473508 */
ts4_word ts4_get_u32_offd0_88473680(ts4_word a0)
{
    ts4_word t4;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 208))) + 52))))((ts4_word)(a0 + 208));
    t4 = fn_88473508((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x884736C8: get u32@0xd0, u32@0x38, vcall, fn_88473508 */
ts4_word ts4_get_u32_offd0_884736C8(ts4_word a0)
{
    ts4_word t4;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 208))) + 56))))((ts4_word)(a0 + 208));
    t4 = fn_88473508((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88473710: get u32@0xd0, u32@0x3c, vcall, fn_88473508 */
ts4_word ts4_get_u32_offd0_88473710(ts4_word a0)
{
    ts4_word t4;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 208))) + 60))))((ts4_word)(a0 + 208));
    t4 = fn_88473508((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88474380: get u16@0x9c, u32@0xa4 */
ts4_word ts4_get_u16_off9c_88474380(ts4_word a0)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 156);
    return (t1 + (*(ts4_word *)((char *)(ts4_word)(a0) + 164)));
}

/* Swing_DLL.xex 0x88475280: if_call_seq fn_88475158, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88475158_88475280(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88475158();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)45);
    }
    return a0;
}

/* Swing_DLL.xex 0x88475448: tailcall fn_885E85B8 */
ts4_word ts4_tailcall_fn_885E85B8_88475448(ts4_word a0, ts4_word a1)
{
    return fn_885E85B8((ts4_word)a1, (ts4_word)(a0 + 16));
}

/* Swing_DLL.xex 0x88475458: tailcall fn_885E90D8 */
ts4_word ts4_tailcall_fn_885E90D8_88475458(ts4_word a0, ts4_word a1)
{
    return fn_885E90D8((ts4_word)a1, (ts4_word)(a0 + 16));
}

/* Swing_DLL.xex 0x88475468: tailcall ts4_tailcall_fn_885E8F50_885E9160 */
ts4_word ts4_tailcall_fn_885E9160_88475468(ts4_word a0, ts4_word a1)
{
    return ts4_tailcall_fn_885E8F50_885E9160((ts4_word)a1, (ts4_word)(a0 + 16));
}

/* Swing_DLL.xex 0x88475478: tailcall fn_885E8F50 */
ts4_word ts4_tailcall_fn_885E8F50_88475478(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_885E8F50((ts4_word)a1, (ts4_word)a2, (ts4_word)(a0 + 16));
}

/* Swing_DLL.xex 0x88475490: tailcall fn_885E9000 */
ts4_word ts4_tailcall_fn_885E9000_88475490(ts4_word a0, ts4_word a1)
{
    return fn_885E9000((ts4_word)a1, (ts4_word)(a0 + 16));
}

/* Swing_DLL.xex 0x884754A0: set u8@0xbe */
void ts4_set_u8_offbe_884754A0(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 190) = (unsigned char)a1;
    return;
}

/* Swing_DLL.xex 0x884754E0: set  */
void ts4_set_884754E0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 204) = f1;
    return;
}

/* Swing_DLL.xex 0x884754E8: tailcall fn_885E9AB8 */
ts4_word ts4_tailcall_fn_885E9AB8_884754E8(ts4_word a0)
{
    return fn_885E9AB8((ts4_word)(a0 + 80));
}

/* Swing_DLL.xex 0x88475AB8: fn  */
ts4_word ts4_fn_88475AB8(void)
{
    return 1;
}

/* Swing_DLL.xex 0x884760E0: tailcall fn_88478648 */
ts4_word ts4_tailcall_fn_88478648_884760E0(ts4_word a0, ts4_word a1)
{
    return fn_88478648((ts4_word)(a0 + 16), (ts4_word)298, (ts4_word)a1);
}

/* Swing_DLL.xex 0x884760F0: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_884760F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)12;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)128;
    return;
}

/* Swing_DLL.xex 0x88476108: set  */
void ts4_set_88476108(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 248) = f1;
    return;
}

/* Swing_DLL.xex 0x884761A0: tailcall fn_88425B90 */
ts4_word ts4_tailcall_fn_88425B90_884761A0(ts4_word a0, ts4_word a1)
{
    return fn_88425B90((ts4_word)(a0 + 176), (ts4_word)a1, (ts4_word)(a0 + 32));
}

/* Swing_DLL.xex 0x884761D8: get u32@0xe0 */
ts4_word ts4_get_u32_offe0_884761D8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 224));
}

/* Swing_DLL.xex 0x88476270: tailcall fn_884761E0 */
ts4_word ts4_tailcall_fn_884761E0_88476270(ts4_word a0, ts4_word a1)
{
    return fn_884761E0((ts4_word)a0, (ts4_word)0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88476280: get u32@0xe8 */
ts4_word ts4_get_u32_offe8_88476280(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 232));
}

/* Swing_DLL.xex 0x88476288: tailcall fn_884761E0 */
ts4_word ts4_tailcall_fn_884761E0_88476288(ts4_word a0, ts4_word a1)
{
    return fn_884761E0((ts4_word)a0, (ts4_word)2, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88476298: get u32@0xe4 */
ts4_word ts4_get_u32_offe4_88476298(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 228));
}

/* Swing_DLL.xex 0x884762A0: tailcall fn_884761E0 */
ts4_word ts4_tailcall_fn_884761E0_884762A0(ts4_word a0, ts4_word a1)
{
    return fn_884761E0((ts4_word)a0, (ts4_word)1, (ts4_word)a1);
}

/* Swing_DLL.xex 0x884762B0: get u8@0xa2, u8@0x0 */
void ts4_get_u8_offa2_884762B0(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 162));
    return;
}

/* Swing_DLL.xex 0x884762C0: fn  */
ts4_word ts4_fn_884762C0(void)
{
    return 7;
}

/* Swing_DLL.xex 0x88476C68: if_get u32@0x28, u8@0x1c, u8@0x13 */
void ts4_if_get_u32_off28_88476C68(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)(a1 & 0xff);
    if ((ts4_word)t1 == 0) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(t1) + 19) = (unsigned char)(a1 & 0xff);
    return;
}

/* Swing_DLL.xex 0x88476D90: if_get u32@0x14, u8@0xd8, u32@0x18, u32@0xb8 */
ts4_word ts4_if_get_u32_off14_88476D90(ts4_word a0)
{
    ts4_word p4;
    ts4_word t1;
    unsigned char t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 216);
    p4 = (ts4_word)t1;
    if ((ts4_word)t2 == 7) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
    }
    return (*(ts4_word *)((char *)(ts4_word)(p4) + 184));
}

/* Swing_DLL.xex 0x884779C0: fn  */
ts4_word ts4_fn_884779C0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88478A40: call_seq fn_88420E48, fn_88420E48 */
ts4_word ts4_call_seq_fn_88420E48_88478A40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;

    fn_88420E48((ts4_word)(a0 + 32), (ts4_word)a1, (ts4_word)a3);
    t2 = fn_88420E48((ts4_word)(a0 + 48), (ts4_word)a2, (ts4_word)a3);
    return t2;
}

/* Swing_DLL.xex 0x88478AA0: tailcall fn_88478648 */
ts4_word ts4_tailcall_fn_88478648_88478AA0(ts4_word a0, ts4_word a1)
{
    return fn_88478648((ts4_word)(a0 + 16), (ts4_word)50, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88478AE0: set u8@0x0 */
void ts4_set_u8_off0_88478AE0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88478AF0: fn  */
ts4_word ts4_fn_88478AF0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88478B48: fn  */
ts4_word ts4_fn_88478B48(void)
{
    return 101;
}

/* Swing_DLL.xex 0x88479040: if_call_seq fn_88478D50, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88478D50_88479040(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88478D50((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)44);
    }
    return a0;
}

/* Swing_DLL.xex 0x88479558: tailcall fn_885068E8 */
ts4_word ts4_tailcall_fn_885068E8_88479558(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    return fn_885068E8((ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)8);
}

/* Swing_DLL.xex 0x88479570: get u32@0x18, u32@0x0, u32@0x2c, vcall, u32@0x10, u32@0x14 */
ts4_word ts4_get_u32_off18_88479570(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 44))))((ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)(a0 + 12);
    *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)12;
    return t4;
}

/* Swing_DLL.xex 0x884795C8: get u16@0x1e, u32@0x4, u16@0x1c, u32@0x0 */
void ts4_get_u16_off1e_884795C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 30));
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((*(unsigned short *)((char *)(ts4_word)(a0) + 28)) + 52);
    return;
}

/* Swing_DLL.xex 0x884795E0: get u32@0x18, u32@0x0, u32@0xc, vcall */
ts4_word ts4_get_u32_off18_884795E0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x88479620: fn  */
ts4_word ts4_fn_88479620(void)
{
    return 12;
}

/* Swing_DLL.xex 0x88479B88: if_call_seq ts4_ref_holder_dtor_88479760, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88479760_88479B88(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_ref_holder_dtor_88479760((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)44);
    }
    return a0;
}

/* Swing_DLL.xex 0x88479BF8: tailcall fn_88477610 */
ts4_word ts4_tailcall_fn_88477610_88479BF8(ts4_word a0)
{
    return fn_88477610((ts4_word)a0);
}

/* Swing_DLL.xex 0x88479F30: fn  */
ts4_word ts4_fn_88479F30(void)
{
    return 2;
}
