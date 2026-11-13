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
extern char ts4_call_seq_u32_lbl_88CACF08_8845C5B0[];
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
ts4_word fn_884684A8();
ts4_word fn_88468D78();
ts4_word fn_884691E8();
ts4_word fn_8846A1B8();
ts4_word fn_8846B868();
ts4_word fn_8846B998();
ts4_word fn_8846BB60();
ts4_word fn_8846BC08();
ts4_word fn_8846BD20();
ts4_word fn_8846D6D0();
ts4_word fn_88471C08();
ts4_word fn_88472530();
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
ts4_word fn_88479760();
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

/* Swing_DLL.xex 0x8845CE48: addr ts4_call_seq_u32_lbl_88CACF08_8845C5B0, fn_8845D078, fn_8845D370, u32@0x0, fn_8845C208, u32@0x4 */
void ts4_addr_fn_8845C5B0_8845CE48(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_call_seq_u32_lbl_88CACF08_8845C5B0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)fn_8845D078;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)fn_8845D370;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(ts4_word)fn_8845C208;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 17) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x884653E0: if_call_seq lbl_8807FF50, lbl_8803A308, u32@0x14, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue */
ts4_word ts4_if_call_seq_lbl_8807FF50_884653E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(ts4_word)lbl_8807FF50;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x884724C0: if_call_seq lbl_880869E8, lbl_8803A308, u32@0x8, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue */
ts4_word ts4_if_call_seq_lbl_880869E8_884724C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_880869E8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)4);
    }
    return a0;
}

/* Swing_DLL.xex 0x88472AD8: addr lbl_88084948, u32@0x0, fn_88475158 */
ts4_word ts4_addr_lbl_88084948_88472AD8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88084948;
    return fn_88475158((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_88084948);
}

