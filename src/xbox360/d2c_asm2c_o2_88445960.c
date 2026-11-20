/* Swing_DLL.xex 0x88445960-0x885BFD68, executable version 0.0.0.3. */
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
#ifdef __clang__
#pragma clang diagnostic ignored "-Wdeprecated-non-prototype"
#endif

extern char __imp_KeDebugMonitorData[];
extern char lbl_88001978[];
extern char lbl_88001A20[];
extern char lbl_88001A68[];
extern char lbl_88001A6C[];
extern char lbl_88001B0C[];
extern char lbl_88002388[];
extern char lbl_88028BE0[];
extern char lbl_88029278[];
extern char lbl_8802F8CC[];
extern char lbl_8803A308[];
extern char lbl_8803A3B0[];
extern char lbl_88080CE4[];
extern char lbl_88080CF4[];
extern char lbl_88080D04[];
extern char lbl_88081E20[];
extern char lbl_88081E44[];
extern char lbl_88081FD4[];
extern char lbl_880825C4[];
extern char lbl_880828B4[];
extern char lbl_880828F0[];
extern char lbl_88082964[];
extern char lbl_88083354[];
extern char lbl_880836F4[];
extern char lbl_8808379C[];
extern char lbl_8808384C[];
extern char lbl_88084264[];
extern char lbl_88084948[];
extern char lbl_88084A14[];
extern char lbl_880869E8[];
extern char lbl_88086ED0[];
extern char lbl_88086FCC[];
extern char lbl_88087004[];
extern char lbl_88087070[];
extern char lbl_88087078[];
extern char lbl_880870F4[];
extern char lbl_88087154[];
extern char lbl_88087384[];
extern char lbl_88087DDC[];
extern char lbl_880882AC[];
extern char lbl_880885D0[];
extern char lbl_88088BD0[];
extern char lbl_880895D4[];
extern char lbl_88089714[];
extern char lbl_880898DC[];
extern char lbl_8808C1BC[];
extern char lbl_8808C1C8[];
extern char lbl_8808C6C0[];
extern char lbl_8808C72C[];
extern char lbl_8808C750[];
extern char lbl_8808C798[];
extern char lbl_8808C7B8[];
extern char lbl_8808C880[];
extern char lbl_8808C890[];
extern char lbl_8808CAD4[];
extern char lbl_8808CAE8[];
extern char lbl_8808D394[];
extern char lbl_8808E0C8[];
extern char lbl_88091790[];
extern char lbl_88C30DA8[];
extern char lbl_88CACF08[];
extern char lbl_88CACFCC[];
extern char lbl_88CAD02C[];
extern char lbl_88CAD340[];
extern char lbl_88CAD568[];
extern char lbl_88D2ECB8[];
extern char lbl_88D2F124[];
extern char lbl_88D3CB4C[];
extern char lbl_88D3CB50[];
ts4_word KeSetEvent();
ts4_word KeTlsGetValue();
ts4_word NtWaitForSingleObjectEx();
ts4_word NtWriteFile();
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word RtlNtStatusToDosError();
ts4_word fn_8841A328();
ts4_word fn_8841A510();
ts4_word fn_8841A590();
ts4_word fn_8841C678();
ts4_word fn_8841CAA8();
ts4_word fn_8841CBF8();
ts4_word ts4_if_get_u32_off8_8841D058();
ts4_word fn_8841D3B0();
ts4_word ts4_if_set_u32_off8_8841D598();
ts4_word fn_8841D638();
ts4_word fn_88420E48();
ts4_word fn_88420F08();
ts4_word fn_884210E8();
ts4_word fn_884214A8();
ts4_word fn_88423788();
ts4_word fn_88423CE0();
ts4_word fn_88441A10();
ts4_word fn_88445410();
ts4_word fn_88445790();
ts4_word fn_884522B0();
ts4_word ts4_call_seq_fn_88466AB0_88467768();
ts4_word fn_884684A8();
ts4_word fn_8846C178();
ts4_word fn_88471DC8();
ts4_word fn_88472530();
ts4_word ts4_if_call_seq_u32_off4_88472748();
ts4_word fn_88472858();
ts4_word ts4_if_call_seq_u32_off8_88473208();
ts4_word fn_884748C0();
ts4_word fn_88477010();
ts4_word fn_88479EA8();
ts4_word fn_8848D3B0();
ts4_word fn_8848E9A0();
ts4_word fn_88492800();
ts4_word fn_884944C0();
ts4_word fn_884997B0();
ts4_word fn_88499868();
ts4_word fn_8849F8B0();
ts4_word fn_884A3F58();
ts4_word ts4_if_call_seq_u32_off8_884A3F88();
ts4_word fn_884A4088();
ts4_word ts4_call_seq_lbl_88D25C34_884B7900();
ts4_word fn_884C52E0();
ts4_word fn_884D7C98();
ts4_word fn_884D8538();
ts4_word fn_884DAF90();
ts4_word fn_884E30B8();
ts4_word fn_884E6480();
ts4_word fn_884E66F0();
ts4_word fn_884F27D8();
ts4_word fn_884FAAE0();
ts4_word ts4_get_u32_off0_885068E8();
ts4_word fn_88506A98();
ts4_word fn_88508CF8();
ts4_word ts4_if_call_seq_u32_off4_88524080();
ts4_word fn_88526E08();
ts4_word fn_88527018();
ts4_word fn_8852E0C0();
ts4_word fn_88531FF8();
ts4_word fn_88534058();
ts4_word fn_88538098();
ts4_word fn_88541FB0();
ts4_word fn_8854D9B0();
ts4_word fn_88553880();
ts4_word fn_885542E8();
ts4_word fn_88555608();
ts4_word fn_88555668();
ts4_word fn_88555748();
ts4_word fn_88557200();
ts4_word ts4_addr_lbl_88C31510_8856F558();
ts4_word fn_88576B30();
ts4_word fn_88576C20();
ts4_word fn_885771E0();
ts4_word fn_885772B0();
ts4_word ts4_if_get_u32_lbl_88C32048_8857A1E0();
ts4_word ts4_if_call_seq_NtSetEvent_8857C1F8();
ts4_word fn_88582610();
ts4_word ts4_forward_if_small_kind_8858CE08();
ts4_word fn_8858E2E8();
ts4_word fn_8858FD68();
ts4_word fn_88590818();
ts4_word fn_88592800();
ts4_word ts4_member_vcall_88598D70();
ts4_word ts4_if_call_seq_fn_88599808_88599C78();
ts4_word fn_8859D5A8();
ts4_word fn_885AC6C8();
ts4_word ts4_pool_free_885B72F0();
ts4_word fn_885E7AD8();
ts4_word fn_885ED378();
ts4_word fn_885F4AB8();
ts4_word fn_885F4D10();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
#ifndef _MSC_VER
#define memset ts4_host_memset
#endif
ts4_word memset();
ts4_word ts4_addr_fn_8852DA00_8852DB68();
ts4_word ts4_addr_lbl_8808BFAC_884C5458();
ts4_word ts4_call_seq_fn_88420B68_88420BF0();
ts4_word ts4_call_seq_fn_8849FE80_8848E320();
ts4_word ts4_fn_8847B630();
ts4_word ts4_forward_shifted_args_885933B0();
ts4_word ts4_get_u32_off0_8841EAC8();
ts4_word ts4_get_u32_off0_885EAD60();
ts4_word ts4_get_u32_off0_885ED260();
ts4_word ts4_get_u32_off10_884943A0();
ts4_word ts4_get_u32_off4_8841EAD0();
ts4_word ts4_if_call_seq_u32_off0_88487020();
ts4_word ts4_if_call_seq_u32_off18_885F4D78();
ts4_word ts4_if_call_seq_u32_off38_885EAA60();
ts4_word ts4_set_u32_off34_885555D8();
ts4_word ts4_set_u32_off8_8847FA60();
ts4_word ts4_tailcall_fn_88564B08_88421360();
ts4_word ts4_tailcall_fn_88582F30_8857A128();












/* Swing_DLL.xex 0x884649C0: call_seq fn_884522B0, fn_884522B0, fn_884522B0, fn_884522B0, fn_884522B0, fn_884522B0 */
ts4_word ts4_call_seq_fn_884522B0_884649C0(ts4_word a0)
{
    ts4_word t16;

    fn_884522B0((ts4_word)a0, (ts4_word)2, (ts4_word)1);
    fn_884522B0((ts4_word)a0, (ts4_word)4, (ts4_word)1);
    fn_884522B0((ts4_word)a0, (ts4_word)5, (ts4_word)1);
    fn_884522B0((ts4_word)a0, (ts4_word)6, (ts4_word)1);
    fn_884522B0((ts4_word)a0, (ts4_word)3, (ts4_word)1);
    fn_884522B0((ts4_word)a0, (ts4_word)7, (ts4_word)1);
    fn_884522B0((ts4_word)a0, (ts4_word)12, (ts4_word)1);
    fn_884522B0((ts4_word)a0, (ts4_word)13, (ts4_word)1);
    fn_884522B0((ts4_word)a0, (ts4_word)19, (ts4_word)1);
    fn_884522B0((ts4_word)a0, (ts4_word)22, (ts4_word)8);
    fn_884522B0((ts4_word)a0, (ts4_word)10, (ts4_word)8);
    fn_884522B0((ts4_word)a0, (ts4_word)15, (ts4_word)8);
    fn_884522B0((ts4_word)a0, (ts4_word)11, (ts4_word)9);
    fn_884522B0((ts4_word)a0, (ts4_word)1, (ts4_word)25);
    fn_884522B0((ts4_word)a0, (ts4_word)27, (ts4_word)24);
    t16 = fn_884522B0((ts4_word)a0, (ts4_word)14, (ts4_word)24);
    return t16;
}














/* Swing_DLL.xex 0x88479A58: if_get u16@0x1c, u32@0x4c, u8@0x0, ts4_get_u32_off0_885068E8, u8@0x24, u32@0x48 */
ts4_word ts4_if_get_u16_off1c_88479A58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p10;
    ts4_word loc50[4];
    ts4_word loc60[8];
    unsigned short t1;
    ts4_word t2;
    unsigned char t3;
    ts4_word t11;
    ts4_word t12;
    ts4_word t25;
    ts4_word t29;
    unsigned short t30;
    ts4_word t33;
    ts4_word t31;
    ts4_word t32;
    ts4_word t4;
    unsigned char t5;
    ts4_word t6;
    ts4_word t9;

    (void)a3;
    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 28);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 76);
    t3 = *(unsigned char *)((char *)(ts4_word)((t1 + t2)) + 0);
    if ((ts4_word)t3 == 0) {
        t11 = *(ts4_word *)((char *)(ts4_word)(a1) + 48);
        t12 = *(ts4_word *)((char *)(ts4_word)(a1) + 52);
        *(float *)((char *)(ts4_word)((t1 + t2)) + 4) = (*(float *)((char *)(ts4_word)(t11) + 16));
        *(float *)((char *)(ts4_word)((t1 + t2)) + 8) = (*(float *)((char *)(ts4_word)(t11) + 20));
        *(float *)((char *)(ts4_word)((t1 + t2)) + 12) = (*(float *)((char *)(ts4_word)(t11) + 24));
        *(float *)((char *)(ts4_word)((t1 + t2)) + 16) = (*(float *)((char *)(ts4_word)(t12) + 16));
        *(float *)((char *)(ts4_word)((t1 + t2)) + 20) = (*(float *)((char *)(ts4_word)(t12) + 20));
        *(float *)((char *)(ts4_word)((t1 + t2)) + 24) = (*(float *)((char *)(ts4_word)(t12) + 24));
        *(float *)((char *)(ts4_word)((t1 + t2)) + 28) = (*(float *)((char *)(ts4_word)(t11) + 32));
        *(float *)((char *)(ts4_word)((t1 + t2)) + 32) = (*(float *)((char *)(ts4_word)(t11) + 36));
        *(float *)((char *)(ts4_word)((t1 + t2)) + 36) = (*(float *)((char *)(ts4_word)(t11) + 40));
        *(float *)((char *)(ts4_word)((t1 + t2)) + 40) = (*(float *)((char *)(ts4_word)(t12) + 32));
        *(float *)((char *)(ts4_word)((t1 + t2)) + 44) = (*(float *)((char *)(ts4_word)(t12) + 36));
        *(float *)((char *)(ts4_word)((t1 + t2)) + 48) = (*(float *)((char *)(ts4_word)(t12) + 40));
        t25 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t25) + 0))) + 44))))((ts4_word)t25, (ts4_word)(ts4_word)&loc60[0]);
        t29 = loc60[4];
        t30 = *(unsigned short *)((char *)(ts4_word)(t29) + 0);
        if ((ts4_word)t30 == 22) {
            t33 = fn_88508CF8((ts4_word)t29, (ts4_word)a1, (ts4_word)1, (ts4_word)a2);
            return t33;
        }
        t31 = loc60[5];
        t32 = fn_88506A98((ts4_word)t29, (ts4_word)t31, (ts4_word)a1, (ts4_word)a2);
        return t32;
    }
    t4 = ts4_get_u32_off0_885068E8((ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)8, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t3);
    t5 = *(unsigned char *)((char *)(ts4_word)(a0) + 36);
    p10 = (ts4_word)t4;
    if ((ts4_word)t5 != 0) {
        t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 72);
        t9 = fn_88471DC8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 20))) + 8)), (ts4_word)t6);
        p10 = (ts4_word)t9;
    }
    return p10;
}































/* Swing_DLL.xex 0x884B7B90: if_call_seq u32@0x10, u32@lbl_88CACF08, KeTlsGetValue, u32@0x50, fn_8841A328, u32@0x54 */
ts4_word ts4_if_call_seq_u32_off10_884B7B90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p8;
    ts4_word p10;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t12;
    ts4_word t13;
    ts4_word t14;
    int t15;
    ts4_word t16;
    ts4_word t19;
    ts4_word t20;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t1 == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 80);
        if ((ts4_word)t4 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 84) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 84)) + -1);
            *(ts4_word *)((char *)(ts4_word)(t3) + 80) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 0));
            p8 = (ts4_word)t4;
        } else {
            t5 = fn_8841A328((ts4_word)t3, (ts4_word)3);
            p8 = (ts4_word)t5;
        }
        if ((ts4_word)p8 != 0) {
            *(ts4_word *)((char *)(ts4_word)(p8) + 0) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(p8) + 4) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(p8) + 8) = (ts4_word)(2147483648);
            *(ts4_word *)((char *)(ts4_word)(p8) + 12) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(p8) + 16) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(p8) + 20) = (ts4_word)(2147483648);
            p10 = (ts4_word)p8;
        } else {
            p10 = (ts4_word)0;
        }
        t12 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t13 = fn_8841A510((ts4_word)t12, (ts4_word)96, (ts4_word)8);
        *(unsigned short *)((char *)(ts4_word)(t13) + 4) = (unsigned short)96;
        t14 = fn_884E30B8((ts4_word)t13, (ts4_word)p10);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t14;
        t15 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        t16 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        if ((int)t15 == (int)(t16 & 0x3fffffff)) {
            fn_8841C678((ts4_word)a1, (ts4_word)4);
        }
        t19 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        t20 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        *(ts4_word *)((char *)(ts4_word)((t19 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a1) + 0))) = (ts4_word)t20;
        *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 4)) + 1);
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}



/* Swing_DLL.xex 0x884BA268: if_call_seq u32@0xc, u32@lbl_88CACF08, KeTlsGetValue, u32@0x50, fn_8841A328, u32@0x54 */
ts4_word ts4_if_call_seq_u32_offc_884BA268(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p8;
    ts4_word p10;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t12;
    ts4_word t13;
    ts4_word t14;
    int t15;
    ts4_word t16;
    ts4_word t19;
    ts4_word t20;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 80);
        if ((ts4_word)t4 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 84) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 84)) + -1);
            *(ts4_word *)((char *)(ts4_word)(t3) + 80) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 0));
            p8 = (ts4_word)t4;
        } else {
            t5 = fn_8841A328((ts4_word)t3, (ts4_word)3);
            p8 = (ts4_word)t5;
        }
        if ((ts4_word)p8 != 0) {
            *(ts4_word *)((char *)(ts4_word)(p8) + 0) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(p8) + 4) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(p8) + 8) = (ts4_word)(2147483648);
            *(ts4_word *)((char *)(ts4_word)(p8) + 12) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(p8) + 16) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(p8) + 20) = (ts4_word)(2147483648);
            p10 = (ts4_word)p8;
        } else {
            p10 = (ts4_word)0;
        }
        t12 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t13 = fn_8841A510((ts4_word)t12, (ts4_word)96, (ts4_word)8);
        *(unsigned short *)((char *)(ts4_word)(t13) + 4) = (unsigned short)96;
        t14 = fn_884E30B8((ts4_word)t13, (ts4_word)p10);
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t14;
        t15 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        t16 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        if ((int)t15 == (int)(t16 & 0x3fffffff)) {
            fn_8841C678((ts4_word)a1, (ts4_word)4);
        }
        t19 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        t20 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        *(ts4_word *)((char *)(ts4_word)((t19 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a1) + 0))) = (ts4_word)t20;
        *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 4)) + 1);
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}


































































/* Swing_DLL.xex 0x885A7A00: if_call_seq u32@0x2c, ts4_pool_free_885B72F0, u32@0x2c, u32@0x30, ts4_pool_free_885B72F0, u32@0x30 */
ts4_word ts4_if_call_seq_u32_off2c_885A7A00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t1 != 0) {
        ts4_pool_free_885B72F0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((ts4_word)t4 != 0) {
        ts4_pool_free_885B72F0((ts4_word)t4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    }
    memset((ts4_word)(a0 + 36), (ts4_word)0, (ts4_word)36);
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    t8 = memset((ts4_word)(a0 + 72), (ts4_word)0, (ts4_word)24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    return t8;
}

/* Swing_DLL.xex 0x885A9120: if_call_seq memset, u32@0xd0, u32@0xb8, u32@0xbc, u32@0xc0, u32@0xc4 */
ts4_word ts4_if_call_seq_memset_885A9120(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;
    ts4_word t8;
    ts4_word t11;
    ts4_word t14;
    ts4_word t17;
    ts4_word t20;
    ts4_word t23;
    ts4_word t27;

    memset((ts4_word)(a0 + 36), (ts4_word)0, (ts4_word)40);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 208);
    *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 196) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 200) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 204) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 220) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 224) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 228) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 232) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 236) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 240) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 244) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 248) = (ts4_word)0;
    if ((ts4_word)t2 != 0) {
        ts4_pool_free_885B72F0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)0;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 212);
    if ((ts4_word)t5 != 0) {
        ts4_pool_free_885B72F0((ts4_word)t5);
        *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)0;
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 216);
    if ((ts4_word)t8 != 0) {
        ts4_pool_free_885B72F0((ts4_word)t8);
        *(ts4_word *)((char *)(ts4_word)(a0) + 216) = (ts4_word)0;
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    if ((ts4_word)t11 != 0) {
        ts4_pool_free_885B72F0((ts4_word)t11);
        *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    }
    t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    if ((ts4_word)t14 != 0) {
        ts4_pool_free_885B72F0((ts4_word)t14);
        *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    }
    t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    if ((ts4_word)t17 != 0) {
        ts4_pool_free_885B72F0((ts4_word)t17);
        *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    }
    t20 = *(ts4_word *)((char *)(ts4_word)(a0) + 152);
    if ((ts4_word)t20 != 0) {
        ts4_pool_free_885B72F0((ts4_word)t20);
        *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)0;
    }
    t23 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
    if ((ts4_word)t23 != 0) {
        ts4_pool_free_885B72F0((ts4_word)t23);
        *(ts4_word *)((char *)(ts4_word)(a0) + 176) = (ts4_word)0;
    }
    memset((ts4_word)(a0 + 76), (ts4_word)0, (ts4_word)36);
    t27 = memset((ts4_word)(a0 + 112), (ts4_word)0, (ts4_word)72);
    return t27;
}







