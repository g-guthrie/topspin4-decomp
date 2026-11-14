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

extern char __imp_ExSemaphoreObjectType[];
extern char ts4_addr_lbl_88000A3C_88AFF440[];
extern char ts4_addr_lbl_88D2E270_88AFF7D0[];
extern char g_ts4_session_context[];
extern char lbl_8803A248[];
extern char lbl_88091F04[];
extern char lbl_88091F18[];
extern char lbl_88091F2C[];
extern char lbl_88091F68[];
extern char lbl_88091FA4[];
extern char lbl_88091FB8[];
extern char lbl_88091FF4[];
extern char lbl_88092008[];
extern char lbl_88092044[];
extern char lbl_88092058[];
extern char lbl_88095E68[];
extern char lbl_88095E78[];
extern char lbl_88095EB0[];
extern char lbl_88095ECC[];
extern char lbl_88095F78[];
extern char lbl_88095FB0[];
extern char lbl_88095FCC[];
extern char lbl_88095FF8[];
extern char lbl_88096024[];
extern char lbl_880AEB58[];
extern char lbl_880AEB88[];
extern char lbl_880AEBBC[];
extern char lbl_880B4540[];
extern char lbl_880B6858[];
extern char lbl_880B6868[];
extern char lbl_880B9778[];
extern char lbl_880B97F0[];
extern char lbl_880B9E30[];
extern char lbl_880B9EC0[];
extern char lbl_880BC988[];
extern char lbl_880BCA48[];
extern char lbl_880BCA6C[];
extern char lbl_880BCAD8[];
extern char lbl_880BCAFC[];
extern char lbl_880BCB08[];
extern char lbl_880BCB28[];
extern char lbl_880BCB4C[];
extern char lbl_880BD1E8[];
extern char lbl_880BD568[];
extern char lbl_880BD650[];
extern char lbl_880BD730[];
extern char lbl_880BD7A8[];
extern char lbl_880BD820[];
extern char lbl_880BD898[];
extern char lbl_880BD910[];
extern char lbl_880C02B8[];
extern char lbl_880C1320[];
extern char lbl_880D4488[];
extern char lbl_880FCB08[];
extern char lbl_8814B440[];
extern char lbl_88B30F80[];
extern char lbl_88C31190[];
extern char lbl_88C32048[];
extern char lbl_88C33388[];
extern char lbl_88C337B8[];
extern char lbl_88C42CC8[];
extern char lbl_88D2E270[];
extern char lbl_88D2E5AC[];
extern char lbl_88D2F130[];
extern char lbl_88D459D0[];
extern char lbl_88D459D8[];
extern char lbl_88D45B38[];
extern char lbl_88D4DABE[];
ts4_word KeSetEvent();
ts4_word ObReferenceObjectByHandle();
ts4_word RtlEnterCriticalSection();
ts4_word RtlFreeAnsiString();
ts4_word RtlInitUnicodeString();
ts4_word RtlInitializeCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word RtlUnicodeStringToAnsiString();
ts4_word fn_88150600();
ts4_word fn_88163B90();
ts4_word fn_8816CF48();
ts4_word fn_8816D090();
ts4_word fn_88213D38();
ts4_word fn_882882A0();
ts4_word fn_882A9128();
ts4_word ts4_if_get_u32_lbl_88CAC9A8_883E63D8();
ts4_word ts4_ring_push_883FFA40();
ts4_word fn_88400670();
ts4_word ts4_if_call_seq_u32_off18_88501990();
ts4_word fn_88562E80();
ts4_word ts4_get_u32_lbl_88C30BE0_88562ED0();
ts4_word fn_88563470();
ts4_word fn_885647D0();
#ifndef _MSC_VER
#define memset ts4_host_memset
#endif
ts4_word memset();
ts4_word fn_8856CD88();
ts4_word ts4_if_call_seq_fn_8856D820_8856D868();
ts4_word ts4_get_u32__imp_KeTimeStampBundle_8857B830();
ts4_word fn_8857C8C8();
ts4_word fn_88581AF0();
ts4_word ts4_call_seq_RtlInitAnsiString_88582148();
ts4_word fn_8858CCD8();
ts4_word ts4_if_get_u32_off860_8858F028();
ts4_word fn_88593B18();
ts4_word ts4_if_get_u32_off50_88594308();
ts4_word ts4_if_call_seq_u32_offc_88596808();
ts4_word fn_88597828();
ts4_word ts4_set_u32_off4_88597EC0();
ts4_word ts4_if_get_u32_off30_88599460();
ts4_word ts4_pool1_clear_88599CF8();
ts4_word ts4_call_seq_lbl_88091AB8_8859CBC0();
ts4_word ts4_call_seq_lbl_88091C50_8859EA08();
ts4_word ts4_if_call_seq_u16_off0_8859F280();
ts4_word fn_885A5568();
ts4_word ts4_loop_get_u32_off54_885A5BF0();
ts4_word fn_885A5EB0();
ts4_word fn_885A6438();
ts4_word fn_885A6ED0();
ts4_word fn_885A7A00();
ts4_word fn_885A7B18();
ts4_word fn_885A9120();
ts4_word fn_885AA008();
ts4_word fn_885AA050();
ts4_word fn_885AA098();
ts4_word fn_885AA110();
ts4_word fn_885AA168();
ts4_word fn_885AA560();
ts4_word fn_885AA5F0();
ts4_word ts4_get_u32_off0_885AA668();
ts4_word fn_885AA8A0();
ts4_word fn_885B5368();
ts4_word fn_885B55F0();
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_885B5880();
ts4_word fn_885B5910();
ts4_word ts4_if_atomic_interlocked_dec_885B5E88();
ts4_word fn_885B5EE8();
ts4_word fn_885B62F8();
ts4_word fn_885B6628();
ts4_word ts4_pool_free_885B72F0();
ts4_word ts4_get_u32_off4_885B7DE0();
ts4_word ts4_get_u32_off4_885B7E18();
ts4_word ts4_set_u32_off4_885B7EE0();
ts4_word ts4_if_get_u32_off4_885B7F98();
ts4_word fn_885B8008();
ts4_word fn_885B80C0();
ts4_word fn_885B8180();
ts4_word fn_885B8290();
ts4_word fn_885B8350();
ts4_word fn_885B8468();
ts4_word fn_885B85F8();
ts4_word fn_885B8660();
ts4_word fn_885B86E0();
ts4_word fn_885B87E0();
ts4_word fn_885B9140();
ts4_word ts4_if_call_seq_u32_offc_885BE178();
ts4_word ts4_if_call_seq_u32_off2c_885CE120();
ts4_word fn_885CF138();
ts4_word fn_885CF5D8();
ts4_word fn_885CF688();
ts4_word fn_885D01A0();
ts4_word fn_885D9C48();
ts4_word ts4_loop_get_u32_off8_885D9D10();
ts4_word fn_885DC838();
ts4_word fn_885DCE58();
ts4_word fn_885DCFD0();
ts4_word fn_885DD1F8();
ts4_word fn_885DD2C0();
ts4_word ts4_call_seq_u32_off814_885E1990();
ts4_word fn_885E2DC0();
ts4_word ts4_if_call_seq_u32_off18_885E38A8();
ts4_word fn_885E3A10();
ts4_word fn_885E3E60();
ts4_word fn_885E41F0();
ts4_word fn_885E4248();
ts4_word ts4_call_seq_u32_off28_885E4350();
ts4_word fn_885E4798();
ts4_word ts4_call_seq_fn_885E4248_885E4A58();
ts4_word fn_885E4AB0();
ts4_word fn_885E4B58();
ts4_word fn_885E4FA8();
ts4_word fn_885E50C0();
ts4_word ts4_call_seq_fn_885E48D8_885E52C8();
ts4_word fn_885E5A08();
ts4_word fn_885E5BC8();
ts4_word fn_885E5CE0();
ts4_word fn_885E5D38();
ts4_word fn_885E5F38();
ts4_word fn_885E5FB8();
ts4_word fn_885E6050();
ts4_word fn_885E61F8();
ts4_word fn_885E6290();
ts4_word fn_885E6318();
ts4_word fn_885E63A0();
ts4_word fn_885E6428();
ts4_word fn_885E6C48();
ts4_word fn_88608590();
ts4_word fn_8860BD70();
ts4_word fn_88613268();
ts4_word fn_886E79A8();
ts4_word fn_886E7A28();
ts4_word fn_886ED298();
ts4_word fn_88771868();
ts4_word fn_88799490();
ts4_word fn_88851F00();
ts4_word fn_88852068();
ts4_word fn_8886F8B0();
ts4_word fn_888860A0();
ts4_word fn_889B4418();
ts4_word fn_889B9A58();
ts4_word fn_889D01F8();
ts4_word ts4_get_fn_889D1918_889D19B8();
ts4_word fn_889D1A88();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_find_service();
ts4_word ts4_forward_882A9120();
ts4_word ts4_memset();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x883FEE90: addr lbl_8803A248, u32@0xc, u32@0x4, u32@0x8, u32@0x0, u32@0x14 */
void ts4_addr_lbl_8803A248_883FEE90(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(a0 + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(a0 + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A248;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 36) = (unsigned short)0;
    return;
}

/* Swing_DLL.xex 0x884005A0: if_get ts4_if_get_u32_lbl_88CAC9A8_883E63D8, u32@0x0, u32@0xc, vcall, ts4_ring_push_883FFA40 */
ts4_word ts4_if_get_fn_883E63D8_884005A0(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;

    t1 = ts4_if_get_u32_lbl_88CAC9A8_883E63D8();
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1, (ts4_word)a1);
    if ((int)t4 == 0) {
        p6 = (ts4_word)37;
    } else {
        ts4_ring_push_883FFA40((ts4_word)(a0 + 20), (ts4_word)t4);
        p6 = (ts4_word)0;
    }
    return p6;
}

/* Swing_DLL.xex 0x88400D28: if_call_seq fn_88400670, u32@0x44 */
ts4_word ts4_if_call_seq_fn_88400670_88400D28(ts4_word a0)
{
    int t1;

    t1 = fn_88400670((ts4_word)a0);
    if ((int)t1 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)1;
    }
    return t1;
}

/* Swing_DLL.xex 0x884F4748: get u32@0xc, u32@0x8, u32@0x18 */
ts4_word ts4_get_u32_offc_884F4748(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(((t1 + 4) << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 8))) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)1;
    return 0;
}

/* Swing_DLL.xex 0x884FA700: if_get u32@0x48, u32@0x50, u32@0x48, u32@0x50, u32@0x0, u32@0x18 */
ts4_word ts4_if_get_u32_off48_884FA700(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p3;
    ts4_word p6;

    if ((int)a1 != 0) {
        p3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 80));
    } else {
        p3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 72));
    }
    if ((int)a1 != 0) {
        p6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 80));
    } else {
        p6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 72));
    }
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 0))) + 24))))((ts4_word)p3, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)0, (ts4_word)a5, (ts4_word)a6, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88563070: if_get u32@lbl_88D2E5AC, vcall, ts4_if_call_seq_fn_8856D820_8856D868, ts4_get_u32_lbl_88C30BE0_88562ED0, fn_88562E80 */
ts4_word ts4_if_get_u32_lbl_88D2E5AC_88563070(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D2E5AC;
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))(t1))((ts4_word)a0);
    }
    ts4_if_call_seq_fn_8856D820_8856D868((ts4_word)25);
    t5 = ts4_get_u32_lbl_88C30BE0_88562ED0((ts4_word)0, (ts4_word)1);
    t6 = fn_88562E80((ts4_word)t5);
    return t6;
}

/* Swing_DLL.xex 0x88567ED8: if_call_seq fn_8856CD88, lbl_88C31190 */
ts4_word ts4_if_call_seq_fn_8856CD88_88567ED8(void)
{
    ts4_word p2;
    ts4_word t1;

    t1 = fn_8856CD88();
    if ((ts4_word)t1 == 0) {
        p2 = (ts4_word)(ts4_word)lbl_88C31190;
    } else {
        p2 = (ts4_word)(t1 + 8);
    }
    return p2;
}

/* Swing_DLL.xex 0x88582BD0: if_call_seq RtlInitUnicodeString, RtlUnicodeStringToAnsiString, lbl_880C1320, ts4_call_seq_RtlInitAnsiString_88582148, RtlFreeAnsiString */
ts4_word ts4_if_call_seq_RtlInitUnicodeString_88582BD0(ts4_word a0)
{
    ts4_word p6;
    ts4_word loc58[2];
    ts4_word loc50[2];
    int t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    RtlInitUnicodeString((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0);
    t2 = RtlUnicodeStringToAnsiString((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)1);
    if ((int)t2 < 0) {
        loc50[1] = (ts4_word)(ts4_word)lbl_880C1320;
    }
    t3 = loc50[1];
    t4 = ts4_call_seq_RtlInitAnsiString_88582148((ts4_word)t3);
    p6 = (ts4_word)t4;
    if ((int)t2 >= 0) {
        t5 = RtlFreeAnsiString((ts4_word)(ts4_word)&loc50[0]);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x885844E8: if_get u32@lbl_88C32048, u32@0x18, vcall */
ts4_word ts4_if_get_u32_lbl_88C32048_885844E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p5;
    ts4_word loc60[2];
    int t3;
    ts4_word t4;

    t3 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88C32048)) + 24))))((ts4_word)a0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)&loc60[0], (ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)0);
    p5 = (ts4_word)t3;
    if ((int)t3 >= 0) {
        t4 = loc60[0];
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x8858CE80: loop_call_seq u32@0x1c, fn_8858CCD8, ts4_if_get_u32_off860_8858F028 */
ts4_word ts4_loop_call_seq_u32_off1c_8858CE80(ts4_word a0)
{
    ts4_word t3;

    while ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)) > 0) {
        fn_8858CCD8((ts4_word)a0);
    }
    t3 = ts4_if_get_u32_off860_8858F028((ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x88594DD8: if_get u32@0x2c, u32@0x8, vcall, fn_8857C8C8, u32@0xac, u32@0x50 */
ts4_word ts4_if_get_u32_off2c_88594DD8(ts4_word a0)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    int t9;
    ts4_word t19;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 8))))((ts4_word)(a0 + 44));
    t4 = fn_8857C8C8((ts4_word)t3);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 172);
    if ((ts4_word)t4 != (ts4_word)t5) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 80))) + 8))))((ts4_word)(a0 + 80));
        t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 164);
        if ((int)t9 != 0) {
            ts4_if_get_u32_off50_88594308((ts4_word)a0, (ts4_word)0);
            *(ts4_word *)((char *)(ts4_word)(a0) + 164) = (ts4_word)0;
        }
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 80)) + 0))) + 20))))((ts4_word)(a0 + 80));
    }
    t19 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 44)) + 0))) + 20))))((ts4_word)(a0 + 44));
    return t19;
}

/* Swing_DLL.xex 0x8859CC38: if_call_seq ts4_call_seq_lbl_88091AB8_8859CBC0, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_8859CBC0_8859CC38(ts4_word a0, ts4_word a1)
{

    ts4_call_seq_lbl_88091AB8_8859CBC0((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8859D230: if_tailcall ts4_if_get_u32_off30_88599460 */
ts4_word ts4_if_tailcall_fn_88599460_8859D230(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((int)(a2 & 0x10000000) == 0) {
        return a0;
    }
    return ts4_if_get_u32_off30_88599460((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8859EA70: if_call_seq ts4_call_seq_lbl_88091C50_8859EA08, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_8859EA08_8859EA70(ts4_word a0, ts4_word a1)
{

    ts4_call_seq_lbl_88091C50_8859EA08((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885A50D0: loop_call_seq u32@0x4, u32@0x4, u32@0x0, fn_882A9128, u32@0x0, ts4_forward_882A9120 */
ts4_word ts4_loop_call_seq_u32_off4_885A50D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word loc50[1];
    int t1;
    int t3;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p6 = (ts4_word)a0;
    if ((int)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        do {
            t3 = fn_882A9128((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)(ts4_word)&loc50[0]);
        } while ((int)t3 >= 0);
        t5 = ts4_forward_882A9120((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x885A61A0: if_get u32@0x48, u32@0x80, u32@0x0, u32@0x3c, vcall, ts4_loop_get_u32_off54_885A5BF0 */
ts4_word ts4_if_get_u32_off48_885A61A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p21;
    ts4_word t1;
    ts4_word t8;
    ts4_word t12;
    ts4_word t16;
    ts4_word t19;
    ts4_word t20;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    if ((ts4_word)t1 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(t1) + 128)) != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 60))))((ts4_word)a0, (ts4_word)1);
    }
    ts4_loop_get_u32_off54_885A5BF0((ts4_word)a0);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t8 != 0) {
        fn_885B55F0((ts4_word)t8);
        ts4_pool_free_885B72F0((ts4_word)t8);
        *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((ts4_word)t12 != 0) {
        fn_885B85F8((ts4_word)t12);
        ts4_pool_free_885B72F0((ts4_word)t12);
        *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    }
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    p21 = (ts4_word)t16;
    if ((ts4_word)t16 != 0) {
        t19 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t16) + 0))) + 4))))((ts4_word)t16, (ts4_word)0);
        t20 = ts4_pool_free_885B72F0((ts4_word)t19);
        *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
        p21 = (ts4_word)t20;
    }
    return p21;
}

/* Swing_DLL.xex 0x885A62D0: if_get u32@0x48, u32@0x40, u32@0x8, vcall, u32@0x1c, u32@0x8 */
ts4_word ts4_if_get_u32_off48_885A62D0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t13;
    int t18;
    ts4_word t21;
    ts4_word t26;
    ts4_word t29;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 64))) + 8))))((ts4_word)(t1 + 64));
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 8))))((ts4_word)(a0 + 28));
    fn_885B86E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 76)), (ts4_word)(a1 + 4));
    fn_885A5EB0((ts4_word)a0, (ts4_word)(a1 + 4));
    t13 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a1 + 4)) + 0))) + 40))))((ts4_word)(a1 + 4));
    fn_885B62F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 72)), (ts4_word)t13);
    t18 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a1 + 4)) + 0))) + 36))))((ts4_word)(a1 + 4));
    if ((int)t18 == 2) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 384) = (ts4_word)0;
    }
    t21 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a1 + 4)) + 0))) + 4))))((ts4_word)(a1 + 4), (ts4_word)0);
    ts4_pool_free_885B72F0((ts4_word)t21);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 28)) + 0))) + 20))))((ts4_word)(a0 + 28));
    t26 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    t29 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t26) + 64))) + 20))))((ts4_word)(t26 + 64));
    return t29;
}

/* Swing_DLL.xex 0x885A6878: if_call_seq fn_885A6438, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_885A6438_885A6878(ts4_word a0, ts4_word a1)
{

    fn_885A6438((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885A6968: get u32@0x48, u32@0x30, memset */
ts4_word ts4_get_u32_off48_885A6968(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    return memset((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)0, (ts4_word)((int)t1 * 12));
}

/* Swing_DLL.xex 0x885A7320: call_seq lbl_88091F2C, lbl_88091F18, lbl_88091F04, u32@0x0, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_lbl_88091F2C_885A7320(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88091F2C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_88091F18;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(ts4_word)lbl_88091F04;
    fn_885A6ED0((ts4_word)a0);
    t2 = ts4_if_call_seq_u32_offc_88596808((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x885A75B8: if_call_seq lbl_88091F68, u32@0x0, ts4_if_call_seq_u32_offc_88596808, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_lbl_88091F68_885A75B8(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88091F68;
    ts4_if_call_seq_u32_offc_88596808();
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885A7610: call_seq u32@0x38, u32@0x2c, memset, u32@0x38, u32@0x30, memset */
ts4_word ts4_call_seq_u32_off38_885A7610(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    memset((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 44)), (ts4_word)0, (ts4_word)(t1 << 2));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    t6 = memset((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)0, (ts4_word)(t4 << 2));
    return t6;
}

/* Swing_DLL.xex 0x885A7AC8: call_seq lbl_88091FB8, lbl_88091FA4, u32@0x0, u32@0x20, fn_885A7A00, ts4_if_call_seq_u32_offc_88596808 */
ts4_word ts4_call_seq_lbl_88091FB8_885A7AC8(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88091FB8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_88091FA4;
    fn_885A7A00((ts4_word)a0);
    t2 = ts4_if_call_seq_u32_offc_88596808((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x885A7C80: if_call_seq fn_88597828, u32@0x0, u16@0x2, fn_885A7B18 */
ts4_word ts4_if_call_seq_fn_88597828_885A7C80(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p5;
    int t1;
    ts4_word t4;

    (void)a1;
    t1 = fn_88597828((ts4_word)a0, (ts4_word)1, (ts4_word)a2, (ts4_word)1);
    p5 = (ts4_word)t1;
    if ((int)t1 >= 0) {
        t4 = fn_885A7B18((ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0))) + 2)));
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x885A7D60: if_call_seq u32@0x104, u32@0x60, u32@0x54, memset, u32@0x60, u32@0x58 */
ts4_word ts4_if_call_seq_u32_off104_885A7D60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p8;
    int t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 260);
    p8 = (ts4_word)a0;
    if ((int)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
        memset((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 84)), (ts4_word)0, (ts4_word)(t2 << 2));
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
        t7 = memset((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 88)), (ts4_word)0, (ts4_word)(t5 << 2));
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x885A9038: call_seq lbl_88C33388, ts4_set_u32_off4_88597EC0, lbl_88092008, lbl_88091FF4, u32@0xb8, u32@0x0 */
ts4_word ts4_call_seq_lbl_88C33388_885A9038(ts4_word a0)
{
    ts4_set_u32_off4_88597EC0((ts4_word)a0, (ts4_word)(ts4_word)lbl_88C33388);
    *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88092008;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_88091FF4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 196) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 200) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 204) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 216) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 220) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 224) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 228) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 232) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 236) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 240) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 244) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 248) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 252) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 256) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 260) = (ts4_word)0;
    fn_88593B18((ts4_word)(ts4_word)lbl_88D2F130);
    memset((ts4_word)(a0 + 76), (ts4_word)0, (ts4_word)36);
    memset((ts4_word)(a0 + 36), (ts4_word)0, (ts4_word)40);
    memset((ts4_word)(a0 + 112), (ts4_word)0, (ts4_word)72);
    return a0;
}

/* Swing_DLL.xex 0x885A9298: call_seq lbl_88092008, lbl_88091FF4, u32@0x0, u32@0x20, fn_885A9120, ts4_if_call_seq_u32_offc_88596808 */
ts4_word ts4_call_seq_lbl_88092008_885A9298(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88092008;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_88091FF4;
    fn_885A9120((ts4_word)a0);
    t2 = ts4_if_call_seq_u32_offc_88596808((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x885A9DA8: call_seq lbl_88C337B8, ts4_set_u32_off4_88597EC0, lbl_88092058, lbl_88092044, u16@0x24, u32@0x0 */
ts4_word ts4_call_seq_lbl_88C337B8_885A9DA8(ts4_word a0)
{
    ts4_set_u32_off4_88597EC0((ts4_word)a0, (ts4_word)(ts4_word)lbl_88C337B8);
    *(unsigned short *)((char *)(ts4_word)(a0) + 36) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88092058;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_88092044;
    *(unsigned short *)((char *)(ts4_word)(a0) + 38) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 40) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    fn_88593B18((ts4_word)(ts4_word)lbl_88D2F130);
    return a0;
}

/* Swing_DLL.xex 0x885A9E38: if_call_seq u32@0x2c, lbl_88092058, lbl_88092044, u32@0x0, u32@0x20, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_u32_off2c_885A9E38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88092058;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_88092044;
    if ((ts4_word)t1 != 0) {
        ts4_pool_free_885B72F0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    }
    t5 = ts4_if_call_seq_u32_offc_88596808((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x885AA820: get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x38, u32@0x0 */
ts4_word ts4_get_u32_off30_885AA820(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t8;
    ts4_word t11;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56));
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60));
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 64));
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t11 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 44))) + 20))))((ts4_word)(t8 + 44));
    return t11;
}

/* Swing_DLL.xex 0x885AA928: get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x84, u32@0x0 */
ts4_word ts4_get_u32_off30_885AA928(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 8))))((ts4_word)t5, (ts4_word)0, (ts4_word)a2, (ts4_word)a1, (ts4_word)12);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 44))) + 20))))((ts4_word)(t9 + 44));
    return t8;
}

/* Swing_DLL.xex 0x885AA9A8: get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x84, u32@0x0 */
ts4_word ts4_get_u32_off30_885AA9A8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t9;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 12))))((ts4_word)t5, (ts4_word)0, (ts4_word)a1, (ts4_word)12);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t12 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 44))) + 20))))((ts4_word)(t9 + 44));
    return t12;
}

/* Swing_DLL.xex 0x885AAA30: get u32@0x30, u32@0x2c, u32@0x8, vcall, fn_885AA8A0, u32@0x8 */
ts4_word ts4_get_u32_off30_885AAA30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t7;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = fn_885AA8A0((ts4_word)a0, (ts4_word)a1);
    t7 = fn_885AA5F0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 8)), (ts4_word)a2, (ts4_word)a3);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 44))) + 20))))((ts4_word)(t8 + 44));
    return t7;
}

/* Swing_DLL.xex 0x885AAAA8: get u32@0x30, u32@0x2c, u32@0x8, vcall, fn_885AA8A0, u32@0x8 */
ts4_word ts4_get_u32_off30_885AAAA8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t11;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = fn_885AA8A0((ts4_word)a0, (ts4_word)a1);
    ts4_get_u32_off0_885AA668((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 8)), (ts4_word)a2);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t11 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 44))) + 20))))((ts4_word)(t8 + 44));
    return t11;
}

/* Swing_DLL.xex 0x885AAB10: get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x30, u32@0x2c */
ts4_word ts4_get_u32_off30_885AAB10(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 72));
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t9 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 44))) + 20))))((ts4_word)(t6 + 44));
    return t9;
}

/* Swing_DLL.xex 0x885AAB80: if_get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x0, u32@0x60 */
ts4_word ts4_if_get_u32_off30_885AAB80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t7;
    ts4_word t11;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 96))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    if ((int)t7 >= 0) {
        memcpy((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 76)), (ts4_word)a2, (ts4_word)(a1 << 2));
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t11) + 44))) + 20))))((ts4_word)(t11 + 44));
    return t7;
}

/* Swing_DLL.xex 0x885AAC10: if_get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x34, u32@0x3c */
ts4_word ts4_if_get_u32_off30_885AAC10(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t5;
    ts4_word t12;
    ts4_word t15;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t5 != 0) {
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 0));
    } else {
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60));
    }
    if ((ts4_word)a1 == (ts4_word)p8) {
        memcpy((ts4_word)a2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 76)), (ts4_word)(a1 << 2));
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t15 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t12) + 44))) + 20))))((ts4_word)(t12 + 44));
    return t15;
}

/* Swing_DLL.xex 0x885AAC90: get u32@0x30, u32@0x2c, u32@0x8, vcall, fn_885AA8A0, u32@0x8 */
ts4_word ts4_get_u32_off30_885AAC90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t11;
    ts4_word t14;

    (void)a2;
    (void)a3;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = fn_885AA8A0((ts4_word)a0, (ts4_word)a1);
    t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 8);
    t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 8);
    t8 = *(ts4_word *)((char *)(ts4_word)(t6) + 4);
    memcpy((ts4_word)a4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t6) + 20)), (ts4_word)(((int)t7 * (int)t8) << 2));
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t14 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t11) + 44))) + 20))))((ts4_word)(t11 + 44));
    return t14;
}

/* Swing_DLL.xex 0x885AB0D0: get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x34, fn_885AA008 */
ts4_word ts4_get_u32_off30_885AB0D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t6 = fn_885AA008((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)), (ts4_word)a1, (ts4_word)a2);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 44))) + 20))))((ts4_word)(t7 + 44));
    return t6;
}

/* Swing_DLL.xex 0x885AB138: get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x34, fn_885AA050 */
ts4_word ts4_get_u32_off30_885AB138(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t6 = fn_885AA050((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)), (ts4_word)a1, (ts4_word)a2);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 44))) + 20))))((ts4_word)(t7 + 44));
    return t6;
}

/* Swing_DLL.xex 0x885AB1A0: get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x34, fn_885AA098 */
ts4_word ts4_get_u32_off30_885AB1A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t7;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    fn_885AA098((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)), (ts4_word)a1, (ts4_word)a2);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t10 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 44))) + 20))))((ts4_word)(t7 + 44));
    return t10;
}

/* Swing_DLL.xex 0x885AB200: get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x34, fn_885AA110 */
ts4_word ts4_get_u32_off30_885AB200(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t6;
    ts4_word t8;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t6 = fn_885AA110((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    loc50[0] = (ts4_word)t6;
    fn_885AA560((ts4_word)(ts4_word)&loc50[0]);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 44))) + 20))))((ts4_word)(t8 + 44));
    t12 = loc50[0];
    return t12;
}

/* Swing_DLL.xex 0x885AB280: get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x34, fn_885AA168 */
ts4_word ts4_get_u32_off30_885AB280(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t6;
    ts4_word t8;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t6 = fn_885AA168((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    loc50[0] = (ts4_word)t6;
    fn_885AA560((ts4_word)(ts4_word)&loc50[0]);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 44))) + 20))))((ts4_word)(t8 + 44));
    t12 = loc50[0];
    return t12;
}

/* Swing_DLL.xex 0x885AB7B0: if_call_seq u32@0x8, ts4_if_call_seq_u32_offc_885BE178, ts4_pool_free_885B72F0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off8_885AB7B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p4 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        ts4_if_call_seq_u32_offc_885BE178((ts4_word)t1);
        t3 = ts4_pool_free_885B72F0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x885ABD50: if_call_seq u32@0x0, ts4_pool1_clear_88599CF8, ts4_pool1_clear_88599CF8, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_u32_off0_885ABD50(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    ts4_pool1_clear_88599CF8((ts4_word)(a0 + 80));
    ts4_pool1_clear_88599CF8((ts4_word)(a0 + 8));
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885B54F8: if_call_seq fn_885B5368, u32@0x0, u32@0x4, u32@0x1c, u32@0x8, u32@0x1c */
ts4_word ts4_if_call_seq_fn_885B5368_885B54F8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_885B5368((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Swing_DLL.xex 0x885B5740: if_get u32@0x23c, u32@0x23c, u32@0x23c, u32@0x23c */
void ts4_if_get_u32_off23c_885B5740(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 572) = (ts4_word)2;
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 572);
    if ((int)t2 != 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 572) = (ts4_word)1;
    return;
}

/* Swing_DLL.xex 0x885B59D0: set fn_8857C8C8, u32@0x10, u32@0x14, KeSetEvent, fn_885B5910, u32@0x0 */
ts4_word ts4_set_fn_8857C8C8_885B59D0(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_8857C8C8();
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t1;
    KeSetEvent((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)1, (ts4_word)0);
    fn_885B5910((ts4_word)a0, (ts4_word)-1);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x885B6060: if_call_seq u32@0x4, lbl_88095E68, u32@0x0, ts4_if_call_seq_RtlEnterCriticalSection_885B5880, u32@0x20, ts4_if_atomic_interlocked_dec_885B5E88 */
ts4_word ts4_if_call_seq_u32_off4_885B6060(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p11;
    int t1;
    ts4_word t10;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88095E68;
    p11 = (ts4_word)a0;
    if ((int)t1 != 0) {
        ts4_if_call_seq_RtlEnterCriticalSection_885B5880((ts4_word)a0);
        ts4_if_atomic_interlocked_dec_885B5E88((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)));
        ts4_if_atomic_interlocked_dec_885B5E88((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
        ts4_if_atomic_interlocked_dec_885B5E88((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
        t10 = ts4_if_atomic_interlocked_dec_885B5E88((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
        p11 = (ts4_word)t10;
    }
    return p11;
}

/* Swing_DLL.xex 0x885B62A8: if_get u32@0x40, u32@0x4, vcall, fn_885B5EE8 */
ts4_word ts4_if_get_u32_off40_885B62A8(ts4_word a0)
{
    ts4_word p5;
    int t3;
    ts4_word t4;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 64))) + 4))))((ts4_word)(a0 + 64));
    p5 = (ts4_word)t3;
    if ((int)t3 >= 0) {
        t4 = fn_885B5EE8((ts4_word)a0);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x885B6468: if_call_seq fn_885A5568, u32@0x0, u32@0xcc, u32@0x4, u32@0x8, u32@0xcc */
ts4_word ts4_if_call_seq_fn_885A5568_885B6468(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_885A5568((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 204));
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)0;
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 204);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 212);
        *(ts4_word *)((char *)(ts4_word)(a0) + 204) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Swing_DLL.xex 0x885B69E0: if_call_seq fn_885B6628, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_885B6628_885B69E0(ts4_word a0, ts4_word a1)
{

    fn_885B6628((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885B6B10: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_885B80C0, u32@0xc */
ts4_word ts4_get_u32_offc_885B6B10(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    t5 = fn_885B80C0((ts4_word)(a0 + 4), (ts4_word)a1, (ts4_word)a2);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 20))))((ts4_word)t6);
    return t5;
}

/* Swing_DLL.xex 0x885B6B78: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_885B8180, u32@0xc */
ts4_word ts4_get_u32_offc_885B6B78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    t5 = fn_885B8180((ts4_word)(a0 + 4), (ts4_word)0, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 20))))((ts4_word)t6);
    return t5;
}

/* Swing_DLL.xex 0x885B6BE8: get u32@0xc, u32@0x0, u32@0x8, vcall, ts4_get_u32_off4_885B7DE0, u32@0xc */
ts4_word ts4_get_u32_offc_885B6BE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    t5 = ts4_get_u32_off4_885B7DE0((ts4_word)(a0 + 4), (ts4_word)0, (ts4_word)a2, (ts4_word)a3);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 20))))((ts4_word)t6);
    return t5;
}

/* Swing_DLL.xex 0x885B6C50: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_885B8350, u32@0xc */
ts4_word ts4_get_u32_offc_885B6C50(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    t5 = fn_885B8350((ts4_word)(a0 + 4), (ts4_word)0, (ts4_word)a2);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 20))))((ts4_word)t6);
    return t5;
}

/* Swing_DLL.xex 0x885B6CC8: get u32@0xc, u32@0x0, u32@0x8, vcall, ts4_get_u32_off4_885B7E18, u32@0xc */
ts4_word ts4_get_u32_offc_885B6CC8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    t5 = ts4_get_u32_off4_885B7E18((ts4_word)(a0 + 4), (ts4_word)0);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 20))))((ts4_word)t6);
    return t5;
}

/* Swing_DLL.xex 0x885B6D60: call_seq ts4_set_u32_off4_885B7EE0, u32@0x1c, lbl_88095EB0, lbl_88095E78, u32@0x0, u32@0x4 */
ts4_word ts4_call_seq_fn_885B7EE0_885B6D60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_set_u32_off4_885B7EE0((ts4_word)(a0 + 4), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88095EB0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_88095E78;
    return a0;
}

/* Swing_DLL.xex 0x885B6DC0: if_call_seq lbl_88095E78, u32@0x0, u32@0x4, ts4_if_get_u32_off4_885B7F98, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_lbl_88095E78_885B6DC0(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_88095E78;
    ts4_if_get_u32_off4_885B7F98((ts4_word)(a0 + 4));
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885B6F90: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_885B8008, u32@0xc */
ts4_word ts4_get_u32_offc_885B6F90(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    t5 = fn_885B8008((ts4_word)(a0 + 4), (ts4_word)a1);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 20))))((ts4_word)t6);
    return t5;
}

/* Swing_DLL.xex 0x885B7008: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_885B8180, u32@0xc */
ts4_word ts4_get_u32_offc_885B7008(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    t5 = fn_885B8180((ts4_word)(a0 + 4), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 20))))((ts4_word)t6);
    return t5;
}

/* Swing_DLL.xex 0x885B7080: get u32@0xc, u32@0x0, u32@0x8, vcall, ts4_get_u32_off4_885B7DE0, u32@0xc */
ts4_word ts4_get_u32_offc_885B7080(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    t5 = ts4_get_u32_off4_885B7DE0((ts4_word)(a0 + 4), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 20))))((ts4_word)t6);
    return t5;
}

/* Swing_DLL.xex 0x885B70F0: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_885B8290, u32@0xc */
ts4_word ts4_get_u32_offc_885B70F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    t5 = fn_885B8290((ts4_word)(a0 + 4), (ts4_word)a1, (ts4_word)a2);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 20))))((ts4_word)t6);
    return t5;
}

/* Swing_DLL.xex 0x885B7158: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_885B8350, u32@0xc */
ts4_word ts4_get_u32_offc_885B7158(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    t5 = fn_885B8350((ts4_word)(a0 + 4), (ts4_word)a1, (ts4_word)a2);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 20))))((ts4_word)t6);
    return t5;
}

/* Swing_DLL.xex 0x885B71C0: get u32@0xc, u32@0x0, u32@0x8, vcall, ts4_get_u32_off4_885B7E18, u32@0xc */
ts4_word ts4_get_u32_offc_885B71C0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    t5 = ts4_get_u32_off4_885B7E18((ts4_word)(a0 + 4), (ts4_word)a1);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 20))))((ts4_word)t6);
    return t5;
}

/* Swing_DLL.xex 0x885B7238: get u32@0xc, u32@0x0, u32@0x8, vcall, u32@0x94, fn_885CF138 */
ts4_word ts4_get_u32_offc_885B7238(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    fn_885CF138((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 148)), (ts4_word)a1);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 20))))((ts4_word)t7);
    return 0;
}

/* Swing_DLL.xex 0x885B73E8: if_call_seq lbl_88095ECC, u32@0x0, u32@0x4, ts4_if_get_u32_off4_885B7F98, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_lbl_88095ECC_885B73E8(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_88095ECC;
    ts4_if_get_u32_off4_885B7F98((ts4_word)(a0 + 4));
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885B7E30: get u32@0x4, u32@0x0, u32@0x10, vcall, u32@0xc, u32@0x0 */
ts4_word ts4_get_u32_off4_885B7E30(ts4_word a0)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 4))))((ts4_word)t5, (ts4_word)1);
    return t8;
}

/* Swing_DLL.xex 0x885B7E88: get u32@0x4, u32@0x10, u32@0x0, u32@0x14, vcall, u32@0xc */
ts4_word ts4_get_u32_off4_885B7E88(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1, (ts4_word)t2);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t9 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 4))))((ts4_word)t6, (ts4_word)0);
    return t9;
}

/* Swing_DLL.xex 0x885B8410: if_call_seq ts4_if_get_u32_off4_885B7F98, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_885B7F98_885B8410(ts4_word a0, ts4_word a1)
{

    ts4_if_get_u32_off4_885B7F98((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885B8578: if_call_seq fn_885B8468, u32@0x0, u32@0x4, u32@0xd0, u32@0x8, u32@0xd0 */
ts4_word ts4_if_call_seq_fn_885B8468_885B8578(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_885B8468((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 208));
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 208);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 204) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 212);
        *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Swing_DLL.xex 0x885B8780: if_get u32@0xc, u32@0x0, u32@0x0, vcall, u32@0x8, ts4_pool_free_885B72F0 */
ts4_word ts4_if_get_u32_offc_885B8780(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1);
    t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    if ((ts4_word)t5 != 5) {
        ts4_pool_free_885B72F0((ts4_word)a1);
    }
    return t4;
}

/* Swing_DLL.xex 0x885B8960: if_call_seq fn_885B8660, fn_885B87E0 */
ts4_word ts4_if_call_seq_fn_885B8660_885B8960(ts4_word a0)
{
    ts4_word p3;
    int t1;
    ts4_word t2;

    t1 = fn_885B8660();
    p3 = (ts4_word)t1;
    if ((int)t1 >= 0) {
        t2 = fn_885B87E0((ts4_word)a0);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x885B89A0: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_885B8290, u32@0xc */
ts4_word ts4_get_u32_offc_885B89A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    t5 = fn_885B8290((ts4_word)(a0 + 4), (ts4_word)0, (ts4_word)a2);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 20))))((ts4_word)t6);
    return t5;
}

/* Swing_DLL.xex 0x885B8A30: get u32@0x0, u32@0x30 */
ts4_word ts4_get_u32_off0_885B8A30(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0);
}

/* Swing_DLL.xex 0x885B8A58: if_call_seq lbl_88095F78, u32@0x0, u32@0x4, ts4_if_get_u32_off4_885B7F98, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_lbl_88095F78_885B8A58(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_88095F78;
    ts4_if_get_u32_off4_885B7F98((ts4_word)(a0 + 4));
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885B8AC0: call_seq ts4_set_u32_off4_885B7EE0, u32@0x1c, lbl_88095FB0, lbl_88095F78, u32@0x0, u32@0x4 */
ts4_word ts4_call_seq_fn_885B7EE0_885B8AC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_set_u32_off4_885B7EE0((ts4_word)(a0 + 4), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88095FB0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_88095F78;
    return a0;
}

/* Swing_DLL.xex 0x885B8C80: get u32@0xc, u32@0x0, u32@0x8, vcall, u32@0x14, ts4_if_call_seq_u16_off0_8859F280 */
ts4_word ts4_get_u32_offc_885B8C80(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    ts4_if_call_seq_u16_off0_8859F280((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)a1, (ts4_word)a2);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 20))))((ts4_word)t7);
    return 0;
}

/* Swing_DLL.xex 0x885B8DA8: if_call_seq lbl_88095FCC, u32@0x0, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_lbl_88095FCC_885B8DA8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88095FCC;
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0();
    }
    return a0;
}

/* Swing_DLL.xex 0x885B8DF8: if_call_seq lbl_88096024, lbl_88095FF8, lbl_88095FCC, u32@0x0, u32@0x4, u32@0x4 */
ts4_word ts4_if_call_seq_lbl_88096024_885B8DF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88096024;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_88095FF8;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_88095FCC;
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0();
    }
    return a0;
}

/* Swing_DLL.xex 0x885B9130: get u32@0x0, u32@0x24 */
ts4_word ts4_get_u32_off0_885B9130(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 36))))((ts4_word)a0);
}

/* Swing_DLL.xex 0x885B93D0: if_call_seq fn_885B9140, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_885B9140_885B93D0(ts4_word a0, ts4_word a1)
{

    fn_885B9140();
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885CE0C8: get u32@0x0, u32@0x8, vcall, u32@0x24, u32@0x24, u32@0x0 */
ts4_word ts4_get_u32_off0_885CE0C8(ts4_word a0)
{
    ts4_word t7;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36)) + 1);
    t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x885CE328: if_get u32@0x0, u32@0x8, vcall, u32@0x28, u32@0x24, u32@0x0 */
ts4_word ts4_if_get_u32_off0_885CE328(ts4_word a0)
{
    ts4_word p10;
    ts4_word t4;
    ts4_word t9;
    ts4_word t7;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)1;
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t4 == 0) {
        ts4_if_call_seq_u32_off2c_885CE120((ts4_word)a0);
        t9 = ts4_pool_free_885B72F0((ts4_word)a0);
        p10 = (ts4_word)t9;
    } else {
        t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0);
        p10 = (ts4_word)t7;
    }
    return p10;
}

/* Swing_DLL.xex 0x885CE470: if_get u32@0x84, u32@0x0, u32@0x28, vcall, u32@0x84, u32@0x0 */
ts4_word ts4_if_get_u32_off84_885CE470(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    int t8;
    int t9;
    ts4_word t12;
    ts4_word t13;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)t1);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 32))))((ts4_word)t5, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t8 >= 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)1;
        t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 148);
        if ((int)t9 != 0) {
            t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
            t13 = loc50[0];
            if ((ts4_word)(t12 + t13) > (ts4_word)t4) {
                *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
            } else {
                if ((ts4_word)((t12 << 1) + t13) <= (ts4_word)t4) {
                    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)2;
                }
            }
        }
    }
    return t8;
}

/* Swing_DLL.xex 0x885CE5E8: call_seq fn_885D9C48, u32@0x7c, u32@0x84, lbl_880AEB58, u32@0x78, u32@0x0 */
ts4_word ts4_call_seq_fn_885D9C48_885CE5E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    fn_885D9C48((ts4_word)a0, (ts4_word)a3);
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880AEB58;
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x885CE648: get u32@0x74 */
ts4_word ts4_get_u32_off74_885CE648(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 116)) == 0);
}

/* Swing_DLL.xex 0x885CE668: if_get u32@0x84, u32@0x8c, u32@0x0, u32@0x94, u32@0x80, u32@0x18 */
ts4_word ts4_if_get_u32_off84_885CE668(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    int t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 140);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 148);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t3) + 24))))((ts4_word)t1, (ts4_word)t5, (ts4_word)(t2 == 0), (ts4_word)(t4 == 0));
    if ((int)t7 == (int)((143130624) | 1638)) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 152)) + 1);
    }
    return t7;
}

/* Swing_DLL.xex 0x885CE6E0: if_call_seq u32@0x84, u32@0x4, u32@0x0, ts4_loop_get_u32_off8_885D9D10, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_u32_off84_885CE6E0(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 132))) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    ts4_loop_get_u32_off8_885D9D10();
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885CE9A0: call_seq fn_885D9C48, lbl_880AEB88, u32@0x78, u32@0x0, u32@0x7c */
ts4_word ts4_call_seq_fn_885D9C48_885CE9A0(ts4_word a0, ts4_word a1)
{
    fn_885D9C48((ts4_word)a0, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880AEB88;
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x885CEA48: if_call_seq u32@0x78, lbl_880AEB88, u32@0x0, ts4_pool_free_885B72F0, u32@0x78, u32@0x7c */
ts4_word ts4_if_call_seq_u32_off78_885CEA48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880AEB88;
    if ((ts4_word)t1 != 0) {
        ts4_pool_free_885B72F0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 124);
    if ((ts4_word)t4 != 0) {
        ts4_pool_free_885B72F0((ts4_word)t4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    t7 = ts4_loop_get_u32_off8_885D9D10((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x885CF1F0: if_get u32@0x0, u32@0x0, u32@0x8, vcall, u32@0x0 */
ts4_word ts4_if_get_u32_off0_885CF1F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p5 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x885D0090: if_call_seq fn_885CF688, u32@0x0, u32@0x4, u32@0x28, u32@0x8, u32@0x28 */
ts4_word ts4_if_call_seq_fn_885CF688_885D0090(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_885CF688((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40));
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Swing_DLL.xex 0x885D0110: call_seq fn_885D9C48, u32@0x80, lbl_880AEBBC, u32@0x78, u32@0x0, u32@0x7c */
ts4_word ts4_call_seq_fn_885D9C48_885D0110(ts4_word a0, ts4_word a1, ts4_word a2)
{
    fn_885D9C48((ts4_word)a0, (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880AEBBC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    fn_885CF5D8((ts4_word)(a0 + 132));
    *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 240) = (ts4_word)(a0 + 208);
    *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 200) = (ts4_u64)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 244) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 248) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 252) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 256) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 260) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 264) = (ts4_word)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 208) = (ts4_u64)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 216) = (ts4_u64)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 224) = (ts4_u64)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 232) = (ts4_u64)0;
    return a0;
}

/* Swing_DLL.xex 0x885D0750: if_call_seq fn_885D01A0, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_885D01A0_885D0750(ts4_word a0, ts4_word a1)
{

    fn_885D01A0();
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885D9AD0: get u32@0x8, u32@0x0, u32@0x1c */
ts4_word ts4_get_u32_off8_885D9AD0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 28))))((ts4_word)t1);
}

/* Swing_DLL.xex 0x885D9DD0: if_call_seq ts4_loop_get_u32_off8_885D9D10, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_885D9D10_885D9DD0(ts4_word a0, ts4_word a1)
{

    ts4_loop_get_u32_off8_885D9D10();
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885DCA80: if_call_seq fn_885DCFD0, lbl_880B6868, lbl_880B6858, lbl_880B4540, fn_885DC838, u32@0x0 */
ts4_word ts4_if_call_seq_fn_885DCFD0_885DCA80(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_885DCFD0();
    if ((int)t1 == 0) {
        fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880B6858, (ts4_word)(ts4_word)lbl_880B6868, (ts4_word)73);
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x885DD498: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x10 */
void ts4_set_u32_off0_885DD498(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0)) | 2147483648);
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)a0;
    return;
}

/* Swing_DLL.xex 0x885DD808: if_addr fn_885DCE58, lbl_88C42CC8, lbl_880B9778, u32@0x20, vcall */
ts4_word ts4_if_addr_fn_885DCE58_885DD808(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a0;
    (void)a1;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a2 != 0) {
        fn_885DCE58((ts4_word)a2, (ts4_word)6, (ts4_word)0, (ts4_word)0);
    }
    if ((ts4_word)a3 != 0 && (ts4_word)a4 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(a3))((ts4_word)a4, (ts4_word)(ts4_word)lbl_880B9778, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C42CC8) + 32)), (ts4_word)8, (ts4_word)0);
    }
    return 0;
}

/* Swing_DLL.xex 0x885DD898: if_addr fn_885DCE58, lbl_88C42CC8, lbl_880B97F0, u32@0x28, vcall */
ts4_word ts4_if_addr_fn_885DCE58_885DD898(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a0;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a2 != 0) {
        fn_885DCE58((ts4_word)a2, (ts4_word)7, (ts4_word)a1, (ts4_word)0);
    }
    if ((ts4_word)a3 != 0 && (ts4_word)a4 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(a3))((ts4_word)a4, (ts4_word)(ts4_word)lbl_880B97F0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C42CC8) + 40)), (ts4_word)10, (ts4_word)a1, (ts4_word)0);
    }
    return 0;
}

/* Swing_DLL.xex 0x885E19C8: call_seq u32@0xac, ts4_if_call_seq_u32_off18_885E38A8, u8@0x818, u32@0x10, u32@0x81c */
ts4_word ts4_call_seq_u32_offac_885E19C8(ts4_word a0)
{
    ts4_word t2;

    t2 = ts4_if_call_seq_u32_off18_885E38A8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 172)), (ts4_word)18, (ts4_word)0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 2072) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 2076) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 16));
    return t2;
}

/* Swing_DLL.xex 0x885E3758: if_get u32@0xa8, u32@0x38, u32@0x50, u32@lbl_880B9EC0, u32@0xe4, u32@0x38 */
ts4_word ts4_if_get_u32_offa8_885E3758(ts4_word a0)
{
    ts4_word p8;
    ts4_word p9;
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 168);
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 228);
        if ((int)(t3 & 0x1) != 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 80));
            *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 56));
            p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 128));
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
            p8 = (ts4_word)(*(ts4_word *)lbl_880B9EC0);
        }
        p9 = (ts4_word)p8;
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
        p9 = (ts4_word)(*(ts4_word *)lbl_880B9EC0);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)p9;
    return fn_885E2DC0((ts4_word)a0);
}

/* Swing_DLL.xex 0x885E37A8: get u32@0x18, u32@0xc, u32@0x18, u32@0x20, u32@0x18, u32@0x4 */
ts4_word ts4_get_u32_off18_885E37A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(((a2 + 14) << 2)) + a1));
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(((a2 + 20) << 2)) + a1);
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 32) = (ts4_word)t4;
    t5 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24);
    return fn_885E3E60((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)t5, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)((a2 + 20) << 2), (ts4_word)t4);
}

/* Swing_DLL.xex 0x885E3900: get u32@0x858 */
void ts4_get_u32_off858_885E3900(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 2136);
    *(ts4_word *)((char *)(ts4_word)(((((a1) >> 5) + 2) << 2)) + t1) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(((((a1) >> 5) + 2) << 2)) + t1)) & ~(1 << (a1 & 0x1f)));
    return;
}

/* Swing_DLL.xex 0x885E3B50: get u32@0x4, u32@0x8, u32@0x8, u32@0x8, u32@0x4, u32@0x4 */
void ts4_get_u32_off4_885E3B50(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    return;
}

/* Swing_DLL.xex 0x885E4748: if_call_seq u32@0x2c, lbl_880BCB28, u32@0x0, fn_885E41F0, u32@-0x4, fn_885DD2C0 */
ts4_word ts4_if_call_seq_u32_off2c_885E4748(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880BCB28;
    p5 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        fn_885E41F0((ts4_word)t1);
        t4 = fn_885DD2C0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + -4)), (ts4_word)(t1 + -4));
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x885E48D8: call_seq fn_885E4248, lbl_880BCAD8, u32@0x0, u32@0x584, u32@0x10, u32@0x30 */
ts4_word ts4_call_seq_fn_885E4248_885E48D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;

    (void)a1;
    (void)a2;
    fn_885E4248();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880BCAD8;
    t2 = *(ts4_word *)((char *)(ts4_word)(a3) + 1412);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a3) + 1412) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 1412)) + 1);
    return a0;
}

/* Swing_DLL.xex 0x885E4938: call_seq fn_885E4248, lbl_880BCA48, u32@0x34, u32@0x0 */
ts4_word ts4_call_seq_fn_885E4248_885E4938(ts4_word a0)
{
    fn_885E4248();
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880BCA48;
    return a0;
}

/* Swing_DLL.xex 0x885E4980: if_get fn_885E4248, u32@0xc, u32@0x20, lbl_880BCA6C, u32@0x30, u32@0x0 */
ts4_word ts4_if_get_fn_885E4248_885E4980(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p10;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    unsigned char t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t13;

    (void)a1;
    (void)a2;
    fn_885E4248();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880BCA6C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    t5 = fn_885E3A10((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 2736)) + 184), (ts4_word)t3, (ts4_word)t2, (ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t5;
    *(unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)1;
    t6 = *(unsigned char *)((char *)(ts4_word)(a3) + 1380);
    if ((ts4_word)t6 == 0) {
        t7 = *(ts4_word *)((char *)(ts4_word)(a3) + 1452);
        t8 = fn_885DD1F8((ts4_word)t7, (ts4_word)964);
        *(ts4_word *)((char *)(ts4_word)(t8) + 0) = (ts4_word)t7;
        p10 = (ts4_word)0;
        if ((int)(t8 + 4) != 0) {
            t9 = fn_885E5F38((ts4_word)(t8 + 4), (ts4_word)a3);
            p10 = (ts4_word)t9;
        }
        t13 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 2736))) + 164);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t13) + 0))) + 40))))((ts4_word)t13, (ts4_word)p10);
        fn_885E5A08((ts4_word)p10, (ts4_word)0, (ts4_word)a0);
        ts4_call_seq_u32_off28_885E4350((ts4_word)a0, (ts4_word)p10);
    }
    return a0;
}

/* Swing_DLL.xex 0x885E5308: call_seq fn_885E4248, u32@0x10, lbl_880BCB28, u32@0x0 */
ts4_word ts4_call_seq_fn_885E4248_885E5308(ts4_word a0, ts4_word a1)
{
    fn_885E4248();
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880BCB28;
    return a0;
}

/* Swing_DLL.xex 0x885E5358: if_call_seq fn_885E4248, lbl_880BCB28, u32@0x0, lbl_880BC988, lbl_880BCAFC, lbl_880B4540 */
ts4_word ts4_if_call_seq_fn_885E4248_885E5358(ts4_word a0, int a1)
{

    fn_885E4248();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880BCB28;
    if ((int)a1 != 0) {
        fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880BCAFC, (ts4_word)(ts4_word)lbl_880BC988, (ts4_word)851);
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)32;
    return a0;
}

/* Swing_DLL.xex 0x885E53E0: if_call_seq fn_885E4248, lbl_880BCB28, u32@0x0, lbl_880BC988, lbl_880BCB08, lbl_880B4540 */
ts4_word ts4_if_call_seq_fn_885E4248_885E53E0(ts4_word a0, int a1)
{

    fn_885E4248();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880BCB28;
    if ((int)a1 < 0 || (int)a1 > 4) {
        fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880BCB08, (ts4_word)(ts4_word)lbl_880BC988, (ts4_word)862);
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(a1 + 33);
    return a0;
}

/* Swing_DLL.xex 0x885E54C8: call_seq fn_885E4248, lbl_880BCB4C, u32@0x30, u32@0x0, u32@0x58c, u32@0x10 */
ts4_word ts4_call_seq_fn_885E4248_885E54C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a1;
    (void)a2;
    fn_885E4248();
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880BCB4C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a3) + 1420));
    *(ts4_word *)((char *)(ts4_word)(a3) + 1420) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 1420)) + 1);
    return a0;
}

/* Swing_DLL.xex 0x885E5530: call_seq fn_885E4248, lbl_880BCB4C, u32@0x30, u32@0x0, u32@0x590, u32@0x10 */
ts4_word ts4_call_seq_fn_885E4248_885E5530(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a1;
    (void)a2;
    fn_885E4248();
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880BCB4C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a3) + 1424));
    *(ts4_word *)((char *)(ts4_word)(a3) + 1424) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 1424)) + 1);
    return a0;
}

/* Swing_DLL.xex 0x885E5598: call_seq fn_885E4248, lbl_880BCB4C, u32@0x30, u32@0x0, u32@0x594, u32@0x10 */
ts4_word ts4_call_seq_fn_885E4248_885E5598(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a1;
    (void)a2;
    fn_885E4248();
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880BCB4C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a3) + 1428));
    *(ts4_word *)((char *)(ts4_word)(a3) + 1428) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 1428)) + 1);
    return a0;
}

/* Swing_DLL.xex 0x885E5850: if_get u32@0x50, lbl_880C02B8 */
ts4_word ts4_if_get_u32_off50_885E5850(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t1;
    unsigned char t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(((a1 + 58) << 2)) + a0);
    if ((ts4_word)t1 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 80));
    } else {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((a1 + 20) << 2)) + a0));
    }
    t5 = *(unsigned char *)((char *)(ts4_word)(((int)p4 * 12)) + ((ts4_word)lbl_880C02B8 + 7));
    if ((ts4_word)t5 != 1) {
        return ((t5 + -2) == 0);
    }
    return 2;
}

/* Swing_DLL.xex 0x885E5B98: get u32@0xe4, u32@0x38, u32@0x50, u32@0x10, u32@0xe4, ts4_call_seq_u32_off814_885E1990 */
ts4_word ts4_get_u32_offe4_885E5B98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 228);
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 228) = (ts4_word)(t1 | 66);
    return ts4_call_seq_u32_off814_885E1990((ts4_word)a1, (ts4_word)a0);
}

/* Swing_DLL.xex 0x885E6138: call_seq fn_885E5BC8, lbl_880BD910, u32@0xac, u32@0x14, u32@0x0, u32@0x10 */
ts4_word ts4_call_seq_fn_885E5BC8_885E6138(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t3;

    t1 = fn_885E5BC8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(t1) + 172) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 20) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880BD910;
    *(ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(t1) + 176) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(t1) + 80) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 84) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 104) = (ts4_word)0;
    t3 = fn_885DD1F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 1452)), (ts4_word)30);
    memset((ts4_word)t3, (ts4_word)0, (ts4_word)30);
    *(unsigned short *)((char *)(ts4_word)(t3) + 14) = (unsigned short)1;
    *(unsigned short *)((char *)(ts4_word)(t3) + 0) = (unsigned short)3;
    *(unsigned short *)((char *)(ts4_word)(t3) + 2) = (unsigned short)3;
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)3;
    *(unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)7;
    *(unsigned short *)((char *)(ts4_word)(t3) + 8) = (unsigned short)7;
    *(unsigned short *)((char *)(ts4_word)(t3) + 10) = (unsigned short)3;
    *(unsigned short *)((char *)(ts4_word)(t3) + 12) = (unsigned short)3;
    *(unsigned short *)((char *)(ts4_word)(t3) + 16) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(t3) + 18) = (unsigned short)1;
    *(unsigned short *)((char *)(ts4_word)(t3) + 22) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(t3) + 24) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(t3) + 26) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(t3) + 28) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(t3) + 20) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)t3;
    return a0;
}

/* Swing_DLL.xex 0x885E64B0: if_call_seq lbl_880B9E30, u32@0x0, u32@-0x4, fn_885DD2C0 */
ts4_word ts4_if_call_seq_lbl_880B9E30_885E64B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880B9E30;
    if ((int)(a1 & 0x1) != 0) {
        fn_885DD2C0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + -4)), (ts4_word)(a0 + -4));
    }
    return a0;
}

/* Swing_DLL.xex 0x885E6500: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E5BC8, lbl_880BD1E8, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6500(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)964);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E5BC8((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1);
        *(ts4_word *)((char *)(ts4_word)(t3) + 16) = (ts4_word)1;
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880BD1E8;
        *(ts4_word *)((char *)(ts4_word)(t3) + 20) = (ts4_word)1;
        p5 = (ts4_word)t3;
    } else {
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Swing_DLL.xex 0x885E6568: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E5D38 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6568(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)964);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E5D38((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E6708: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E6290 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6708(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)964);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E6290((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E6758: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E6318 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6758(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)964);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E6318((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E67A8: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E61F8 */
ts4_word ts4_if_call_seq_u32_off5ac_885E67A8(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)964);
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E61F8((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E67F8: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E63A0 */
ts4_word ts4_if_call_seq_u32_off5ac_885E67F8(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)964);
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E63A0((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E6848: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E6428 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6848(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)964);
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E6428((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E68E8: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E5BC8, lbl_880BD568, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off5ac_885E68E8(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)964);
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E5BC8((ts4_word)(t2 + 4), (ts4_word)128, (ts4_word)a1);
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 16) = (ts4_word)1;
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880BD568;
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 20) = (ts4_word)1;
        p5 = (ts4_word)t3;
    } else {
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Swing_DLL.xex 0x885E6968: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E5FB8 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6968(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)964);
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E5FB8((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E69B8: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E5BC8, lbl_880BD650, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off5ac_885E69B8(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)964);
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E5BC8((ts4_word)(t2 + 4), (ts4_word)126, (ts4_word)a1);
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 16) = (ts4_word)1;
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880BD650;
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 20) = (ts4_word)1;
        p5 = (ts4_word)t3;
    } else {
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Swing_DLL.xex 0x885E6A38: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E6050, lbl_880BD7A8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6A38(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)964);
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E6050((ts4_word)(t2 + 4), (ts4_word)142, (ts4_word)a1);
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880BD7A8;
        p5 = (ts4_word)t3;
    } else {
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Swing_DLL.xex 0x885E6AA8: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E6050, lbl_880BD820, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6AA8(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)964);
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E6050((ts4_word)(t2 + 4), (ts4_word)143, (ts4_word)a1);
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880BD820;
        p5 = (ts4_word)t3;
    } else {
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Swing_DLL.xex 0x885E6B18: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E6050, lbl_880BD898, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6B18(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)964);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E6050((ts4_word)(t2 + 4), (ts4_word)144, (ts4_word)a1);
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880BD898;
        p5 = (ts4_word)t3;
    } else {
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Swing_DLL.xex 0x885E6B88: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E6050, lbl_880BD730, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6B88(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)964);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E6050((ts4_word)(t2 + 4), (ts4_word)145, (ts4_word)a1);
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880BD730;
        p5 = (ts4_word)t3;
    } else {
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Swing_DLL.xex 0x885E6BF8: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E5CE0 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6BF8(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)964);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E5CE0((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E6CA0: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E6C48 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6CA0(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)964);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E6C48((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E6DD8: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E4798 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6DD8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)52);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E4798((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E6E88: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, ts4_call_seq_fn_885E48D8_885E52C8 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6E88(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)56);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = ts4_call_seq_fn_885E48D8_885E52C8((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E6EE0: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E4B58 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6EE0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)56);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E4B58((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E6F38: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E4AB0 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6F38(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)52);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E4AB0((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E70F0: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E50C0 */
ts4_word ts4_if_call_seq_u32_off5ac_885E70F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)56);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E50C0((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E71F8: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, ts4_call_seq_fn_885E4248_885E4A58 */
ts4_word ts4_if_call_seq_u32_off5ac_885E71F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)52);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = ts4_call_seq_fn_885E4248_885E4A58((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E72A8: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, fn_885E4FA8 */
ts4_word ts4_if_call_seq_u32_off5ac_885E72A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)56);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = fn_885E4FA8((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x88606800: if_call_seq lbl_880C1320, fn_885647D0, fn_885647D0 */
ts4_word ts4_if_call_seq_lbl_880C1320_88606800(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word p4;
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p5 = (ts4_word)(ts4_word)lbl_880C1320;
    if ((ts4_word)a0 != 0) {
        t1 = fn_885647D0((ts4_word)a0, (ts4_word)92);
        t2 = fn_885647D0((ts4_word)a0, (ts4_word)47);
        if ((ts4_word)t1 != (ts4_word)t2) {
            if ((ts4_word)t1 > (ts4_word)t2) {
                p3 = (ts4_word)(t1 + 1);
            } else {
                p3 = (ts4_word)(t2 + 1);
            }
            p4 = (ts4_word)p3;
        } else {
            p4 = (ts4_word)a0;
        }
        p5 = (ts4_word)p4;
    }
    return p5;
}

/* Swing_DLL.xex 0x8860CD88: if_call_seq u32@0x180, u32@0x17c, ts4_memset, u32@0x184 */
ts4_word ts4_if_call_seq_u32_off180_8860CD88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 384);
    p5 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t3 = ts4_memset((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 380)), (ts4_word)0, (ts4_word)((int)t1 * 56));
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 388) = (ts4_word)0;
        p5 = (ts4_word)t3;
    }
    return p5;
}

/* Swing_DLL.xex 0x88617AF8: if_call_seq u32@0x28, u32@0xc, u32@0xc, fn_8860BD70, ts4_tsu_cleanup_end, u32@0x28 */
ts4_word ts4_if_call_seq_u32_off28_88617AF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p7;
    int t1;
    int t3;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    p7 = (ts4_word)a0;
    if ((int)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
        if ((int)t3 != 0) {
            fn_8860BD70((ts4_word)t1);
        }
        t6 = ts4_tsu_cleanup_end((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Swing_DLL.xex 0x8865E568: get u32@0x18, u32@0xc, u32@0x4, u32@0x14, u32@0x10 */
void ts4_get_u32_off18_8865E568(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88660080: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_88660080(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)lbl_8814B440);
    return;
}

/* Swing_DLL.xex 0x886603A8: get u32@0x4, u32@0x0, u32@0x7c */
ts4_word ts4_get_u32_off4_886603A8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    return ((*(ts4_word *)((char *)(ts4_word)(t1) + 124)) + (t2 << 3));
}

/* Swing_DLL.xex 0x8867C870: set u32@0x0, u32@0x4, u32@0xc, u32@0x10, u32@0x18, u32@0x1c */
void ts4_set_u32_off0_8867C870(ts4_word a0)
{
    float t1;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    t1 = *(float *)lbl_8814B440;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile float *)((char *)(ts4_word)(a0) + 8) = t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile float *)((char *)(ts4_word)(a0) + 20) = t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile float *)((char *)(ts4_word)(a0) + 32) = t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile float *)((char *)(ts4_word)(a0) + 44) = t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile float *)((char *)(ts4_word)(a0) + 56) = t1;
    *(volatile float *)((char *)(ts4_word)(a0) + 72) = t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)-1;
    *(volatile float *)((char *)(ts4_word)(a0) + 88) = t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile float *)((char *)(ts4_word)(a0) + 104) = t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(volatile float *)((char *)(ts4_word)(a0) + 120) = t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x886C5000: get u32@0x28, u32@0x544, u32@0x28, u32@0x42c, u32@0x410 */
void ts4_get_u32_off28_886C5000(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 1348) = (ts4_word)a1;
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    *(ts4_word *)((char *)(ts4_word)(t2) + 1068) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(t2) + 1040) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x886E80A8: if_call_seq u32@0x20, fn_886E7A28, fn_886E79A8 */
ts4_word ts4_if_call_seq_u32_off20_886E80A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    int t1;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    p4 = (ts4_word)a0;
    if ((int)t1 != 0) {
        fn_886E7A28();
        t3 = fn_886E79A8((ts4_word)(a0 + 176));
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x886EE750: if_call_seq u8@0xc, fn_88581AF0, fn_886ED298 */
ts4_word ts4_if_call_seq_u8_offc_886EE750(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word loc50[8];
    unsigned char t1;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 12);
    p4 = (ts4_word)a0;
    if ((ts4_word)t1 == 1) {
        fn_88581AF0((ts4_word)(ts4_word)&loc50[0]);
        t3 = fn_886ED298((ts4_word)a0);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88707790: if_get u32@0x4, u8@-0x4, u8@-0x5, u8@-0x5, lbl_880D4488, fn_8816CF48 */
ts4_word ts4_if_get_u32_off4_88707790(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    unsigned char t2;
    unsigned char t4;

    (void)a1;
    (void)a2;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + -4);
    if ((ts4_word)t2 == 46) {
        return a0;
    }
    t4 = *(unsigned char *)((char *)(ts4_word)(t1) + -5);
    if ((ts4_word)t4 == 46) {
        return a0;
    }
    return fn_8816CF48((ts4_word)a0, (ts4_word)(ts4_word)lbl_880D4488, (ts4_word)((ts4_word)lbl_880D4488 + 5), (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t2);
}

/* Swing_DLL.xex 0x887077C0: if_get u32@0x4, u8@-0x4, u8@-0x5, u8@-0x5, lbl_880D4488, fn_8816CF48 */
ts4_word ts4_if_get_u32_off4_887077C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    unsigned char t2;
    unsigned char t4;

    (void)a1;
    (void)a2;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + -4);
    if ((ts4_word)t2 == 46) {
        return a0;
    }
    t4 = *(unsigned char *)((char *)(ts4_word)(t1) + -5);
    if ((ts4_word)t4 == 46) {
        return a0;
    }
    return fn_8816CF48((ts4_word)a0, (ts4_word)(ts4_word)lbl_880D4488, (ts4_word)((ts4_word)lbl_880D4488 + 5), (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t2);
}

/* Swing_DLL.xex 0x88714718: get u32@0x0, u32@0x18, fn_882882A0 */
ts4_word ts4_get_u32_off0_88714718(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    return fn_882882A0((ts4_word)t1, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 24)) & 0xfffffffc), (ts4_word)0);
}

/* Swing_DLL.xex 0x88736BB8: call_seq fn_88163B90, u32@0x10c, u32@0x128, u32@0x12c, fn_8816D090, u32@0x0 */
ts4_word ts4_call_seq_fn_88163B90_88736BB8(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    fn_88163B90((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 268) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 296) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 300) = (ts4_word)0;
    fn_8816D090((ts4_word)a0, (ts4_word)a1);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 268) = (ts4_word)t4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 284) = (ts4_word)2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 276) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 272) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 288) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 292) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 304) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 280) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x88772CE0: if_get u32@0x0, u8@0x30, u8@0x30, u32@0x34, u32@0xc, fn_88771868 */
ts4_word ts4_if_get_u32_off0_88772CE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    unsigned char t3;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    t3 = *(unsigned char *)((char *)(ts4_word)(t1) + 48);
    if ((ts4_word)t3 == 1) {
        return fn_88771868((ts4_word)a0, (ts4_word)((4273668096) | 29060), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t3);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 52));
    return a0;
}

/* Swing_DLL.xex 0x88785838: if_call_seq u32@0x210, u32@0x0, u32@0x4, u32@lbl_88D45B38, fn_88613268, u32@0x20c */
ts4_word ts4_if_call_seq_u32_off210_88785838(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p7;
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 528);
    p7 = (ts4_word)a0;
    if ((ts4_word)t1 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)) != (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4))) {
        t5 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)t1, (ts4_word)1, (ts4_word)0, (ts4_word)2);
        *(ts4_word *)((char *)(ts4_word)(a1) + 524) = (ts4_word)t5;
        t6 = fn_88213D38((ts4_word)(a0 + 12), (ts4_word)a1);
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Swing_DLL.xex 0x8879D968: call_seq fn_88150600, u8@0x83, u8@0x84, u8@0x80, u8@0x81, u8@0x82 */
ts4_word ts4_call_seq_fn_88150600_8879D968(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t2;

    fn_88150600((ts4_word)(a0 + 88), (ts4_word)a1);
    *(unsigned char *)((char *)(ts4_word)(a0) + 131) = (unsigned char)a2;
    *(unsigned char *)((char *)(ts4_word)(a0) + 132) = (unsigned char)a3;
    *(unsigned char *)((char *)(ts4_word)(a0) + 128) = (unsigned char)a4;
    *(unsigned char *)((char *)(ts4_word)(a0) + 129) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 130) = (unsigned char)0;
    t2 = fn_88799490((ts4_word)a0, (ts4_word)0);
    return t2;
}

/* Swing_DLL.xex 0x88818348: loop_fn  */
ts4_word ts4_loop_fn_88818348(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word lv2;
    ts4_word p3;
    ts4_word p4;
    ts4_word p5;
    ts4_word p6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p5 = (ts4_word)0;
    p6 = (ts4_word)a0;
    if ((ts4_word)a0 >= 8) {
        lv1 = (ts4_word)0;
        lv2 = (ts4_word)a0;
        do {
            p3 = (ts4_word)(lv1 + 1);
            p4 = (ts4_word)(((lv2 + 1)) >> 1);
            lv1 = p3;
            lv2 = p4;
        } while ((ts4_word)p4 >= 8);
        p5 = (ts4_word)lv1;
        p6 = (ts4_word)lv2;
    }
    return ((p5 << 3) | p6);
}

/* Swing_DLL.xex 0x88854760: if_call_seq u32@0x1c, u8@0x1a, fn_88852068, u32@0x1c, fn_88851F00 */
ts4_word ts4_if_call_seq_u32_off1c_88854760(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    unsigned char t2;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 26);
    if ((ts4_word)t2 == 1) {
        fn_88852068((ts4_word)a0, (ts4_word)(t1 + 12), (ts4_word)a1, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t2);
    }
    t6 = fn_88851F00((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28)) + 28), (ts4_word)a2, (ts4_word)0);
    return t6;
}

/* Swing_DLL.xex 0x888633F8: call_seq u32@lbl_88D459D0, u32@lbl_88D459D8, u32@0x1c, u32@0x1c, fn_8886F8B0, u32@lbl_88D459D0 */
ts4_word ts4_call_seq_u32_lbl_88D459D0_888633F8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)lbl_88D459D0;
    t2 = *(ts4_word *)lbl_88D459D8;
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 28);
    *(ts4_word *)((char *)(ts4_word)(t1) + 28) = (ts4_word)((753074176) | 14659);
    t4 = fn_8886F8B0((ts4_word)t2, (ts4_word)a0, (ts4_word)a1, (ts4_word)1);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D459D0)) + 28) = (ts4_word)t3;
    return t4;
}

/* Swing_DLL.xex 0x88884508: tailcall RtlLeaveCriticalSection */
ts4_word ts4_tailcall_RtlLeaveCriticalSection_88884508(ts4_word a0)
{
    return RtlLeaveCriticalSection((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88884510: tailcall RtlEnterCriticalSection */
ts4_word ts4_tailcall_RtlEnterCriticalSection_88884510(ts4_word a0)
{
    return RtlEnterCriticalSection((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88884518: tailcall RtlInitializeCriticalSection */
ts4_word ts4_tailcall_RtlInitializeCriticalSection_88884518(ts4_word a0)
{
    return RtlInitializeCriticalSection((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88905DF0: call_seq u32@lbl_88D459D0, u32@lbl_88D459D8, u32@0x1c, u32@0x1c, fn_8886F8B0, u32@lbl_88D459D0 */
ts4_word ts4_call_seq_u32_lbl_88D459D0_88905DF0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)lbl_88D459D0;
    t2 = *(ts4_word *)lbl_88D459D8;
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 28);
    *(ts4_word *)((char *)(ts4_word)(t1) + 28) = (ts4_word)((753074176) | 14659);
    t4 = fn_8886F8B0((ts4_word)t2, (ts4_word)a0, (ts4_word)a1, (ts4_word)1);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D459D0)) + 28) = (ts4_word)t3;
    return t4;
}

/* Swing_DLL.xex 0x88931FA0: get u32@g_ts4_session_context, u32@0x3c, u32@0x320, u32@0x328 */
void ts4_get_u32_g_ts4_session_context_88931FA0(void)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 60);
    *(ts4_word *)((char *)(ts4_word)(t2) + 800) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t2) + 808) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88996DF8: if_call_seq u32@0x50, fn_888860A0, u32@0x50, u32@g_ts4_session_context, u32@0x3c, u32@0x320 */
ts4_word ts4_if_call_seq_u32_off50_88996DF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    int t1;
    ts4_word t2;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    p3 = (ts4_word)t1;
    if ((int)t1 != 0) {
        t2 = fn_888860A0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 60);
    *(ts4_word *)((char *)(ts4_word)(t5) + 800) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t5) + 808) = (ts4_word)0;
    return p3;
}

/* Swing_DLL.xex 0x889980D8: get u32@0x8, u32@g_ts4_session_context, u32@0x3c, u32@0x124, u32@0x128, u8@0x121 */
void ts4_get_u32_off8_889980D8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 60);
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 292) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 296) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(t3) + 289) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88998100: get u32@0x8, u32@g_ts4_session_context, u32@0x3c, u32@0x124, u32@0x128, u8@0x121 */
void ts4_get_u32_off8_88998100(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 60);
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 292) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 296) = (ts4_word)1;
    *(volatile unsigned char *)((char *)(ts4_word)(t3) + 289) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x8899D028: call_seq ts4_get_u32__imp_KeTimeStampBundle_8857B830, u32@0x9c, u32@g_ts4_session_context, u32@0x3c, u32@0x858, u32@0x85c */
ts4_word ts4_call_seq_fn_8857B830_8899D028(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = ts4_get_u32__imp_KeTimeStampBundle_8857B830();
    *(ts4_word *)((char *)(ts4_word)(a0) + 156) = (ts4_word)t1;
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 60);
    *(ts4_word *)((char *)(ts4_word)(t3) + 2136) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t3) + 2140) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x8899DDB8: if_call_seq u32@0xc, u32@0xc, u32@0x4, ts4_find_service, u32@0x54, u32@0x28 */
ts4_word ts4_if_call_seq_u32_offc_8899DDB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p9;
    ts4_word t1;
    int t2;
    ts4_word t4;
    int t5;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 12);
    p9 = (ts4_word)a0;
    if ((int)t2 == 0 && (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t1) + 4)) == 0) {
        t4 = ts4_find_service((ts4_word)((4109369344) | 37424));
        t5 = *(volatile ts4_word *)((char *)(ts4_word)(t4) + 84);
        t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40);
        if ((int)t5 == -1) {
            *(volatile ts4_word *)((char *)(ts4_word)(t4) + 84) = (ts4_word)t6;
            *(volatile unsigned char *)((char *)(ts4_word)(t4) + 93) = (unsigned char)1;
        }
        p9 = (ts4_word)t4;
    }
    return p9;
}

/* Swing_DLL.xex 0x889BA250: if_call_seq u32@0xc, fn_889B9A58, u32@0xc, fn_889B4418, u32@0xc */
ts4_word ts4_if_call_seq_u32_offc_889BA250(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p8;
    int t1;
    ts4_word t2;
    int t3;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    p8 = (ts4_word)a0;
    if ((int)t1 != -1) {
        t2 = fn_889B9A58();
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        p6 = (ts4_word)t2;
        if ((int)t3 == 4) {
            t4 = fn_889B4418((ts4_word)1);
            *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
            p6 = (ts4_word)t4;
        }
        p8 = (ts4_word)p6;
    }
    return p8;
}

/* Swing_DLL.xex 0x889C6550: if_call_seq u32@0x4, u32@lbl_88D45B38, fn_88613268, ts4_memset, u32@0x8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off4_889C6550(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p10;
    int t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t9;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p10 = (ts4_word)a0;
    if ((int)a1 > (int)t1) {
        t3 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)a1, (ts4_word)1, (ts4_word)0, (ts4_word)0);
        ts4_memset((ts4_word)t3, (ts4_word)0, (ts4_word)a1);
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        memcpy((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t5);
        t9 = ts4_tsu_cleanup_end((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
        p10 = (ts4_word)t9;
    }
    return p10;
}

/* Swing_DLL.xex 0x889D13C0: call_seq u32@0x8, fn_889D01F8, u32@0x4, lbl_880FCB08, u32@0x8, u32@0x0 */
ts4_word ts4_call_seq_u32_off8_889D13C0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    loc50[0] = (ts4_word)12;
    t1 = fn_889D01F8((ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880FCB08;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    return a0;
}

/* Swing_DLL.xex 0x889D18A0: set u32@0x0, u32@0x10, u32@0x4, u32@0xc, u32@0x14, u32@0x1c */
void ts4_set_u32_off0_889D18A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 28))) + 0));
    return;
}

/* Swing_DLL.xex 0x889D1AD8: if_call_seq u8@lbl_88D4DABE, fn_889D1A88, ts4_get_fn_889D1918_889D19B8 */
ts4_word ts4_if_call_seq_u8_lbl_88D4DABE_889D1AD8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    unsigned char t1;
    ts4_word t2;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)lbl_88D4DABE;
    p4 = (ts4_word)a0;
    if ((ts4_word)t1 == 0) {
        t2 = fn_889D1A88();
        t3 = ts4_get_fn_889D1918_889D19B8((ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x889D1D60: call_seq u32@__imp_ExSemaphoreObjectType, ObReferenceObjectByHandle */
ts4_word ts4_call_seq_u32__imp_ExSemaphoreObjectType_889D1D60(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t3;

    t2 = ObReferenceObjectByHandle((ts4_word)a0, (ts4_word)(*(ts4_word *)__imp_ExSemaphoreObjectType), (ts4_word)(ts4_word)&loc50[0]);
    t3 = loc50[0];
    return ((((t2) >> 31) + -1) & t3);
}

/* Swing_DLL.xex 0x889D32D8: call_seq lbl_88B30F80, RtlInitializeCriticalSection, ts4_addr_lbl_88000A3C_88AFF440, fn_88563470 */
ts4_word ts4_call_seq_lbl_88B30F80_889D32D8(void)
{
    ts4_word t2;

    RtlInitializeCriticalSection((ts4_word)((ts4_word)lbl_88B30F80 + 4));
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_88000A3C_88AFF440);
    return t2;
}

/* Swing_DLL.xex 0x88AFDEC0: call_seq lbl_88D2E270, ts4_if_call_seq_u32_off18_88501990, ts4_addr_lbl_88D2E270_88AFF7D0, fn_88563470 */
ts4_word ts4_call_seq_lbl_88D2E270_88AFDEC0(void)
{
    ts4_word t2;

    ts4_if_call_seq_u32_off18_88501990((ts4_word)(ts4_word)lbl_88D2E270);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_88D2E270_88AFF7D0);
    return t2;
}
