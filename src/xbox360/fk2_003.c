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

extern char __imp_KeDebugMonitorData[];
extern char lbl_88001978[];
extern char lbl_88001A20[];
extern char lbl_88001A68[];
extern char lbl_88001A6C[];
extern char lbl_88001B0C[];
extern char lbl_88002388[];
extern char lbl_880038D8[];
extern char lbl_88028BE0[];
extern char lbl_88029278[];
extern char lbl_8802BB9C[];
extern char lbl_8802F8CC[];
extern char lbl_8803A308[];
extern char lbl_8803A3B0[];
extern char lbl_8803E868[];
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
extern char lbl_8808E4F0[];
extern char lbl_88091790[];
extern char lbl_880DD80C[];
extern char lbl_88B3302C[];
extern char lbl_88C21EE0[];
extern char lbl_88C30DA8[];
extern char lbl_88CACF08[];
extern char lbl_88CACFCC[];
extern char lbl_88CAD02C[];
extern char lbl_88CAD340[];
extern char lbl_88CAD568[];
extern char lbl_88D275C0[];
extern char lbl_88D2ECB8[];
extern char lbl_88D2F124[];
extern char lbl_88D3CB4C[];
extern char lbl_88D3CB50[];
extern char lbl_88D45B38[];
extern char ts4_noop_881B3360[];
ts4_word KeSetEvent();
ts4_word KeTlsGetValue();
ts4_word MmSetAddressProtect();
ts4_word NtWaitForSingleObjectEx();
ts4_word NtWriteFile();
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word RtlNtStatusToDosError();
ts4_word ts4_loop_call_seq_lbl_880F3428_882343C0();
ts4_word fn_88315F10();
ts4_word fn_8831A088();
ts4_word ts4_call_seq_lbl_8802924C_8832BF80();
ts4_word ts4_loop_call_seq_u32_off0_88376998();
ts4_word fn_8841A328();
ts4_word fn_8841A510();
ts4_word fn_8841A590();
ts4_word ts4_if_get_u32_0xc_8841A820();
ts4_word fn_8841C678();
ts4_word fn_8841CAA8();
ts4_word fn_8841CBF8();
ts4_word ts4_if_get_u32_off8_8841D058();
ts4_word fn_8841D3B0();
ts4_word ts4_if_set_u32_off8_8841D598();
ts4_word fn_8841D638();
ts4_word ts4_get_u32_off0_8841EAC8();
ts4_word ts4_get_u32_off4_8841EAD0();
ts4_word ts4_call_seq_fn_88420B68_88420BF0();
ts4_word fn_88420E48();
ts4_word fn_88420F08();
ts4_word fn_884210E8();
ts4_word ts4_tailcall_fn_88564B08_88421360();
ts4_word fn_884214A8();
ts4_word fn_88423788();
ts4_word fn_88423CE0();
ts4_word fn_88441A10();
ts4_word fn_88445410();
ts4_word fn_88445790();
ts4_word ts4_addr_lbl_8803A308_88449008();
ts4_word fn_88450A70();
ts4_word fn_88466A58();
ts4_word fn_88466A78();
ts4_word fn_88467690();
ts4_word fn_884676D8();
ts4_word fn_88467720();
ts4_word ts4_call_seq_fn_88466AB0_88467768();
ts4_word fn_884684A8();
ts4_word fn_8846C178();
ts4_word fn_88472530();
ts4_word ts4_if_call_seq_u32_off4_88472748();
ts4_word fn_88472858();
ts4_word ts4_if_call_seq_u32_off8_88473208();
ts4_word fn_884748C0();
ts4_word fn_88477010();
ts4_word fn_88479EA8();
ts4_word ts4_fn_8847B630();
ts4_word ts4_set_u32_off8_8847FA60();
ts4_word ts4_if_call_seq_u32_off0_88487020();
ts4_word fn_88489C28();
ts4_word fn_8848D3B0();
ts4_word ts4_call_seq_fn_8849FE80_8848E320();
ts4_word fn_8848E9A0();
ts4_word fn_88492800();
ts4_word ts4_get_u32_off10_884943A0();
ts4_word fn_884944C0();
ts4_word fn_884997B0();
ts4_word fn_88499868();
ts4_word fn_8849F8B0();
ts4_word fn_884A3F58();
ts4_word ts4_if_call_seq_u32_off8_884A3F88();
ts4_word fn_884A4088();
ts4_word fn_884AE750();
ts4_word ts4_call_seq_lbl_88D25C34_884B7900();
ts4_word fn_884C52E0();
ts4_word ts4_addr_lbl_8808BFAC_884C5458();
ts4_word fn_884D7C98();
ts4_word fn_884D8538();
ts4_word fn_884DAF90();
ts4_word fn_884E6480();
ts4_word fn_884E66F0();
ts4_word fn_884F27D8();
ts4_word fn_884F38B0();
ts4_word fn_884F3A70();
ts4_word fn_884FAAE0();
ts4_word fn_884FD878();
ts4_word fn_88523EE8();
ts4_word fn_88523F28();
ts4_word fn_88523F70();
ts4_word ts4_call_seq_fn_88531FF8_88524038();
ts4_word ts4_if_call_seq_u32_off4_88524080();
ts4_word fn_88526E08();
ts4_word fn_88527018();
ts4_word fn_8852C9F0();
ts4_word fn_8852CB30();
ts4_word ts4_addr_fn_8852DA00_8852DB68();
ts4_word fn_8852DD38();
ts4_word fn_8852E0C0();
ts4_word fn_88531FF8();
ts4_word fn_88534058();
ts4_word fn_88538098();
ts4_word fn_88541FB0();
ts4_word fn_8854D9B0();
ts4_word fn_88553880();
ts4_word fn_885542E8();
ts4_word ts4_set_u32_off34_885555D8();
ts4_word fn_88555608();
ts4_word fn_88555668();
ts4_word fn_88555748();
ts4_word fn_88557200();
ts4_word fn_885651F8();
#ifndef _MSC_VER
#define memset ts4_host_memset
#endif
ts4_word memset();
ts4_word fn_8856CF60();
ts4_word fn_8856D0A8();
ts4_word ts4_addr_lbl_88C31510_8856F558();
ts4_word fn_88576B30();
ts4_word fn_88576C20();
ts4_word fn_885771E0();
ts4_word fn_885772B0();
ts4_word ts4_tailcall_fn_88582F30_8857A128();
ts4_word ts4_if_get_u32_lbl_88C32048_8857A1E0();
ts4_word fn_8857C1F8();
ts4_word fn_88582610();
ts4_word ts4_forward_if_small_kind_8858CE08();
ts4_word fn_8858E2E8();
ts4_word fn_8858FD68();
ts4_word fn_88590818();
ts4_word fn_88592800();
ts4_word ts4_forward_shifted_args_885933B0();
ts4_word ts4_member_vcall_88598D70();
ts4_word ts4_if_call_seq_fn_88599808_88599C78();
ts4_word fn_8859D5A8();
ts4_word fn_885AC6C8();
ts4_word ts4_forward_with_const_248C8000_885BE200();
ts4_word fn_885D90A8();
ts4_word ts4_free_buffers_885D90C8();
ts4_word ts4_zero_five_words_885D94F8();
ts4_word ts4_if_call_seq_u32_off8_885D9518();
ts4_word fn_885E7AD8();
ts4_word ts4_set_u8_off3d_885E9CC8();
ts4_word ts4_if_call_seq_u32_off38_885EAA60();
ts4_word ts4_get_u32_off0_885EAD60();
ts4_word ts4_get_u32_off0_885ED260();
ts4_word fn_885ED378();
ts4_word fn_885F4AB8();
ts4_word fn_885F4D10();
ts4_word ts4_if_call_seq_u32_off18_885F4D78();
ts4_word ts4_if_call_seq_fn_881F04B8_886131F0();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();

/* Swing_DLL.xex 0x882594A0: if_call_seq u32@0x0, u32@0x4, ts4_loop_call_seq_lbl_880F3428_882343C0, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off0_882594A0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = ts4_loop_call_seq_lbl_880F3428_882343C0((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = ts4_if_call_seq_fn_881F04B8_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88376E50: if_get u32@0x5c, vcall, u32@0x108, lbl_8802BB9C, fn_8831A088, u32@lbl_88B3302C */
ts4_word ts4_if_get_u32_off5c_88376E50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t11;
    ts4_word t17;
    ts4_word t20;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))(t1))((ts4_word)(a0 + 28));
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 264);
    if ((ts4_word)t4 != 0) {
        fn_8831A088((ts4_word)t4);
        t6 = *(ts4_word *)lbl_88B3302C;
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 264);
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t6) + 4)), (ts4_word)t7, (ts4_word)(ts4_word)lbl_8802BB9C, (ts4_word)44);
        *(ts4_word *)((char *)(ts4_word)(a0) + 264) = (ts4_word)0;
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    if ((ts4_word)t11 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 68)) == 8) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t11, (ts4_word)(ts4_word)lbl_8802BB9C, (ts4_word)50);
        *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    }
    t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 260);
    if ((ts4_word)t17 != 0) {
        ts4_loop_call_seq_u32_off0_88376998((ts4_word)t17);
        *(ts4_word *)((char *)(ts4_word)(a0) + 260) = (ts4_word)0;
    }
    t20 = ts4_call_seq_lbl_8802924C_8832BF80((ts4_word)a0);
    return t20;
}

/* Swing_DLL.xex 0x8841D508: addr lbl_880DD80C, ts4_if_get_u32_off8_8841D058, u32@0x8, u32@0x0, u32@0x14, vcall */
ts4_word ts4_addr_lbl_880DD80C_8841D508(ts4_word a0)
{
    ts4_word t2;

    ts4_if_get_u32_off8_8841D058((ts4_word)a0, (ts4_word)(ts4_word)lbl_880DD80C);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 20))))((ts4_word)t2);
    return a0;
}

/* Swing_DLL.xex 0x88426030: if_call_seq u32@0x18, lbl_8803E868, u32@0x0, u32@0x8, u32@lbl_88CACF08, KeTlsGetValue */
ts4_word ts4_if_call_seq_u32_off18_88426030(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803E868;
    p6 = (ts4_word)a0;
    if ((int)t1 == 0 || (int)t1 == 1) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        t4 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t5 = ts4_if_get_u32_0xc_8841A820((ts4_word)t4, (ts4_word)t2);
        p6 = (ts4_word)t5;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p6;
}

/* Swing_DLL.xex 0x88438C48: if_call_seq u32@0x68, u32@lbl_88CACF08, KeTlsGetValue, u32@0x60, fn_8841A590, ts4_addr_lbl_8803A308_88449008 */
ts4_word ts4_if_call_seq_u32_off68_88438C48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t9;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 96)), (ts4_word)(t1 << 2), (ts4_word)23);
    }
    ts4_addr_lbl_8803A308_88449008((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t9 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t9, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88439158: get  */
void ts4_get_88439158(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(((a1 + 13) << 2)) + a0) = (ts4_word)((1 << a2) | (*(ts4_word *)((char *)(ts4_word)(((a1 + 13) << 2)) + a0)));
    *(ts4_word *)((char *)(ts4_word)(((a2 + 13) << 2)) + a0) = (ts4_word)((1 << a1) | (*(ts4_word *)((char *)(ts4_word)(((a2 + 13) << 2)) + a0)));
    return;
}

/* Swing_DLL.xex 0x88439190: get  */
void ts4_get_88439190(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(((a1 + 13) << 2)) + a0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(((a1 + 13) << 2)) + a0)) & ~(1 << a2));
    *(ts4_word *)((char *)(ts4_word)(((a2 + 13) << 2)) + a0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(((a2 + 13) << 2)) + a0)) & ~(1 << a1));
    return;
}

/* Swing_DLL.xex 0x88440750: get u32@0x0, u32@0x0, u32@0xc */
ts4_word ts4_get_u32_off0_88440750(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
    return (((*(ts4_word *)((char *)(ts4_word)((((*(ts4_word *)((char *)(ts4_word)(t1) + 12)) + 68) << 2)) + t2)) >> 9) & 0x1);
}

/* Swing_DLL.xex 0x88444858: if_get  */
ts4_word ts4_if_get_88444858(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 < 256) {
        return ((1 << (a1 & 0x1f)) & (*(ts4_word *)((char *)(ts4_word)(((((a1) >> 5) + 16) << 2)) + a0)));
    }
    return 1;
}

/* Swing_DLL.xex 0x884449D0: call_seq u32@0x10, fn_88526E08 */
ts4_word ts4_call_seq_u32_off10_884449D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[18];
    ts4_word t2;

    (void)a3;
    t2 = fn_88526E08((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a4, (ts4_word)a4);
    return t2;
}

/* Swing_DLL.xex 0x88445960: call_seq u32@0x10, fn_88445790, fn_88445410, u8@0x0 */
ts4_word ts4_call_seq_u32_off10_88445960(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[8];
    ts4_word loc70[10];
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88445790((ts4_word)a2, (ts4_word)(a1 + 32), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16)), (ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc50[0]);
    t3 = fn_88445410((ts4_word)(a1 + 32), (ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)((t3 + 1) != 0);
    return a0;
}

/* Swing_DLL.xex 0x884460F8: set u8@0x3, u32@0x0, u32@0x0 */
void ts4_set_u8_off3_884460F8(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 3) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((a1 & 0xff) | (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    return;
}

/* Swing_DLL.xex 0x88446118: get u8@0x3, u32@0x0 */
void ts4_get_u8_off3_88446118(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((*(unsigned char *)((char *)(ts4_word)(a0) + 3)) | (a1 << 8));
    return;
}

/* Swing_DLL.xex 0x884464C0: if_call_seq lbl_88080D04, lbl_88080CF4, u32@0x0, u32@0x8, u32@0x14, u32@lbl_88CACF08 */
ts4_word ts4_if_call_seq_lbl_88080D04_884464C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88080D04;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_88080CF4;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    p6 = (ts4_word)a0;
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(volatile ts4_word *)lbl_88CACF08));
        t5 = fn_8841A590((ts4_word)t3, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)(t1 << 2), (ts4_word)23);
        p6 = (ts4_word)t5;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_88080CE4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p6;
}

/* Swing_DLL.xex 0x88446E78: call_seq fn_88441A10, lbl_88081E44, lbl_88081E20, u32@0x0, u32@0x10, u32@0xc0 */
ts4_word ts4_call_seq_fn_88441A10_88446E78(ts4_word a0, ts4_word a1, ts4_word a2)
{
    fn_88441A10((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88081E44;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(ts4_word)lbl_88081E20;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 196) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 200) = (ts4_word)(2147483648);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 204) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)(2147483648);
    return a0;
}

/* Swing_DLL.xex 0x8844BEB0: fn  */
ts4_word ts4_fn_8844BEB0(ts4_word a0, ts4_word a1)
{
    return (((a0 & 0xffff) >> ((a1 + (a1 << 2)) & 0xffff)) & 0x1f);
}

/* Swing_DLL.xex 0x8844DE78: if_call_seq lbl_88081FD4, u32@0x0, u32@0x38, u32@lbl_88CACF08, KeTlsGetValue, u32@0x30 */
ts4_word ts4_if_call_seq_lbl_88081FD4_8844DE78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88081FD4;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56);
    p6 = (ts4_word)a0;
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(volatile ts4_word *)lbl_88CACF08));
        t5 = fn_8841A590((ts4_word)t3, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)(t1 << 2), (ts4_word)23);
        p6 = (ts4_word)t5;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p6;
}

/* Swing_DLL.xex 0x8844EAC8: set u8@lbl_88C21EE0 */
void ts4_set_u8_lbl_88C21EE0_8844EAC8(ts4_word a0)
{
    *(volatile unsigned char *)lbl_88C21EE0 = (unsigned char)a0;
    return;
}

/* Swing_DLL.xex 0x88451158: tailcall fn_88450A70 */
ts4_word ts4_tailcall_fn_88450A70_88451158(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    (void)a0;
    return fn_88450A70((ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Swing_DLL.xex 0x88454330: if_get u8@0x84, u32@0x4, fn_8852E0C0 */
ts4_word ts4_if_get_u8_off84_88454330(ts4_word a0, ts4_word a1)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 132);
    if ((ts4_word)t1 != 0) {
        return a0;
    }
    return fn_8852E0C0((ts4_word)(a0 + 48), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)), (ts4_word)a1);
}

/* Swing_DLL.xex 0x88454350: if_get u8@0x84, fn_8852C9F0, fn_88466A58 */
ts4_word ts4_if_get_u8_off84_88454350(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 132);
    if ((ts4_word)t1 != 0) {
        return fn_88466A58((ts4_word)a0);
    }
    return fn_8852C9F0((ts4_word)(a0 + 48));
}

/* Swing_DLL.xex 0x88454368: if_get u8@0x84, fn_8852CB30, fn_88466A78 */
ts4_word ts4_if_get_u8_off84_88454368(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 132);
    if ((ts4_word)t1 != 0) {
        return fn_88466A78((ts4_word)a0);
    }
    return fn_8852CB30((ts4_word)(a0 + 48));
}

/* Swing_DLL.xex 0x88454380: if_get u8@0x84, fn_88467690 */
ts4_word ts4_if_get_u8_off84_88454380(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 132);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    return fn_88467690((ts4_word)a0);
}

/* Swing_DLL.xex 0x88454398: if_get u8@0x84, fn_884676D8 */
ts4_word ts4_if_get_u8_off84_88454398(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 132);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    return fn_884676D8((ts4_word)a0);
}

/* Swing_DLL.xex 0x884543B0: if_get u8@0x84, fn_88467720 */
ts4_word ts4_if_get_u8_off84_884543B0(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 132);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    return fn_88467720((ts4_word)a0);
}

/* Swing_DLL.xex 0x884544F8: call_seq ts4_call_seq_fn_88466AB0_88467768, lbl_880825C4, u32@0x0, u32@0x0, u32@0x80, u8@0x84 */
ts4_word ts4_call_seq_fn_88467768_884544F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[16];
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    float t9;

    ts4_call_seq_fn_88466AB0_88467768((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880825C4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a3) + 0));
    *(unsigned char *)((char *)(ts4_word)(a0) + 132) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 133) = (unsigned char)0;
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t4 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    t5 = *(ts4_word *)((char *)(ts4_word)(a2) + 8);
    fn_8841CAA8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8)), (ts4_word)t5);
    fn_88534058((ts4_word)(a0 + 12), (ts4_word)t3, (ts4_word)t4, (ts4_word)(ts4_word)&loc50[0]);
    t9 = *(float *)lbl_88001A6C;
    *(float *)((char *)(ts4_word)(a0) + 44) = t9;
    *(float *)((char *)(ts4_word)(a0) + 24) = t9;
    return a0;
}

/* Swing_DLL.xex 0x88456C98: if_call_seq u32@0x18, u32@lbl_88CACF08, KeTlsGetValue, u32@0x10, fn_8841A590, lbl_8803A308 */
ts4_word ts4_if_call_seq_u32_off18_88456C98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)(t1 << 2), (ts4_word)23);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t8 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t8, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)31);
    }
    return a0;
}

/* Swing_DLL.xex 0x88458EE0: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u32@0x8, lbl_880828B4, u16@0xc */
ts4_word ts4_call_seq_u32_lbl_88CACF08_88458EE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    (void)a2;
    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)40, (ts4_word)31);
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)a3;
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 12) = (unsigned short)((0) | 65535);
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)40;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880828B4;
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 14) = (unsigned short)((0) | 65535);
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 16) = (unsigned short)((0) | 65535);
    fn_88538098((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0)) + 32), (ts4_word)(t3 + 20));
    return t3;
}

/* Swing_DLL.xex 0x88458FD8: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u32@0x8, lbl_880828B4, u16@0xc */
ts4_word ts4_call_seq_u32_lbl_88CACF08_88458FD8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    (void)a1;
    (void)a2;
    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)40, (ts4_word)31);
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)a3;
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 12) = (unsigned short)((0) | 65535);
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)40;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880828B4;
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 14) = (unsigned short)((0) | 65535);
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 16) = (unsigned short)((0) | 65535);
    fn_88538098((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + 32), (ts4_word)(t3 + 20));
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880828F0;
    return t3;
}

/* Swing_DLL.xex 0x8845A5A8: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u32@0x8, lbl_88082964, u16@0xc */
ts4_word ts4_call_seq_u32_lbl_88CACF08_8845A5A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    (void)a1;
    (void)a2;
    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)20, (ts4_word)31);
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)a3;
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 12) = (unsigned short)((0) | 65535);
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)20;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88082964;
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 14) = (unsigned short)((0) | 65535);
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 16) = (unsigned short)((0) | 65535);
    return t3;
}

/* Swing_DLL.xex 0x8845FE70: if_get u32@0x1c, u32@0x14, u32@0x10, u32@0xc, u32@0x0, u32@0x28 */
ts4_word ts4_if_get_u32_off1c_8845FE70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    int t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t19;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((int)t1 == 29) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 40))))((ts4_word)t2, (ts4_word)t4, (ts4_word)t3);
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((int)t9 == 29) {
        t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
        t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 40))))((ts4_word)t10, (ts4_word)t12, (ts4_word)t11);
    }
    t19 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)1);
    return t19;
}

/* Swing_DLL.xex 0x8845FF08: get u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off0_8845FF08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a4) + 0))) + 4))))((ts4_word)a4);
}

/* Swing_DLL.xex 0x8845FF20: get u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off0_8845FF20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a2;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 0))) + 4))))((ts4_word)a3, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88463390: if_call_seq u32@0x14, u32@lbl_88CACF08, KeTlsGetValue, u32@0xc, fn_8841A590, lbl_8803A308 */
ts4_word ts4_if_call_seq_u32_off14_88463390(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)(t1 << 3), (ts4_word)23);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t8 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t8, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)31);
    }
    return a0;
}

/* Swing_DLL.xex 0x88466798: get u32@0x0, u32@0x0, u32@0x1c */
ts4_word ts4_get_u32_off0_88466798(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    (void)a0;
    (void)a2;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 28))))((ts4_word)t1, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88466800: get u32@0x0, u32@0x0, u32@0x24 */
ts4_word ts4_get_u32_off0_88466800(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 36))))((ts4_word)t1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88466818: get u32@0x0, u32@0x0, u32@0x28 */
ts4_word ts4_get_u32_off0_88466818(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;

    (void)a0;
    (void)a3;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4);
}

/* Swing_DLL.xex 0x88466830: get u32@0x0, u32@0x0, u32@0x2c */
ts4_word ts4_get_u32_off0_88466830(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 44))))((ts4_word)t1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88466848: get u32@0x0, u32@0x0, u32@0x30 */
ts4_word ts4_get_u32_off0_88466848(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 48))))((ts4_word)t1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88466860: get u32@0x0, u32@0x0, u32@0x34 */
ts4_word ts4_get_u32_off0_88466860(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 52))))((ts4_word)t1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884691E8: if_call_seq u32@0x34, u32@lbl_88CACF08, KeTlsGetValue, u32@0x2c, fn_8841A590, u32@0x28 */
ts4_word ts4_if_call_seq_u32_off34_884691E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p12;
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t9;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    p6 = (ts4_word)a0;
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t5 = fn_8841A590((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 44)), (ts4_word)(t1 << 2), (ts4_word)23);
        p6 = (ts4_word)t5;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    p12 = (ts4_word)p6;
    if ((int)(t7 & 0x80000000) == 0) {
        t9 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t11 = fn_8841A590((ts4_word)t9, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)), (ts4_word)(t7 << 4), (ts4_word)23);
        p12 = (ts4_word)t11;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p12;
}

/* Swing_DLL.xex 0x88469960: call_seq fn_884748C0, lbl_88084948 */
ts4_word ts4_call_seq_fn_884748C0_88469960(void)
{
    ts4_word loc50[130];

    fn_884748C0((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    return (ts4_word)lbl_88084948;
}

/* Swing_DLL.xex 0x8846A0F8: if_call_seq u32@0x3c, u32@lbl_88CACF08, KeTlsGetValue, u32@0x34, fn_8841A590, u32@0x30 */
ts4_word ts4_if_call_seq_u32_off3c_8846A0F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p12;
    ts4_word p18;
    ts4_word p24;
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t9;
    ts4_word t11;
    ts4_word t13;
    ts4_word t15;
    ts4_word t17;
    ts4_word t19;
    ts4_word t21;
    ts4_word t23;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    p6 = (ts4_word)a0;
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t5 = fn_8841A590((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)), (ts4_word)(t1 << 2), (ts4_word)23);
        p6 = (ts4_word)t5;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    p12 = (ts4_word)p6;
    if ((int)(t7 & 0x80000000) == 0) {
        t9 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t11 = fn_8841A590((ts4_word)t9, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40)), (ts4_word)(t7 << 2), (ts4_word)23);
        p12 = (ts4_word)t11;
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    p18 = (ts4_word)p12;
    if ((int)(t13 & 0x80000000) == 0) {
        t15 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t17 = fn_8841A590((ts4_word)t15, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)), (ts4_word)(t13 << 2), (ts4_word)23);
        p18 = (ts4_word)t17;
    }
    t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    p24 = (ts4_word)p18;
    if ((int)(t19 & 0x80000000) == 0) {
        t21 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t23 = fn_8841A590((ts4_word)t21, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)(t19 << 4), (ts4_word)23);
        p24 = (ts4_word)t23;
    }
    return p24;
}

/* Swing_DLL.xex 0x8846A538: if_get u8@0x9, u16@0xa, u16@0xc, u16@0xa, u16@0xc */
void ts4_if_get_u8_off9_8846A538(ts4_word a0, ts4_word a1, ts4_word a2, int a3)
{
    ts4_word p2;
    ts4_word p3;
    unsigned char t1;
    unsigned short t4;
    unsigned short t5;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 9);
    if ((ts4_word)(a3 & 0x3) < (ts4_word)(t1 & 0x3)) {
        p2 = (ts4_word)((~(a1 | a1)) << 14);
    } else {
        p2 = (ts4_word)(a1 << 14);
    }
    if ((int)a3 < (int)t1) {
        p3 = (ts4_word)((~(a2 | a2)) << 14);
    } else {
        p3 = (ts4_word)(a2 << 14);
    }
    t4 = *(unsigned short *)((char *)(ts4_word)(a0) + 10);
    t5 = *(unsigned short *)((char *)(ts4_word)(a0) + 12);
    *(unsigned short *)((char *)(ts4_word)(a0) + 10) = (unsigned short)((t4 & 0x3fff) | p2);
    *(unsigned short *)((char *)(ts4_word)(a0) + 12) = (unsigned short)((t5 & 0x3fff) | p3);
    return;
}

/* Swing_DLL.xex 0x8846AA10: get u32@0x7c, u32@0x80, fn_88489C28 */
ts4_word ts4_get_u32_off7c_8846AA10(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 124);
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    return fn_88489C28((ts4_word)t1);
}

/* Swing_DLL.xex 0x88472458: if_call_seq lbl_8803A308, u32@0x8, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4 */
ts4_word ts4_if_call_seq_lbl_8803A308_88472458(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_8803A308;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)4);
    }
    return a0;
}

/* Swing_DLL.xex 0x88472A00: if_set u16@0xa, u8@0x9, u16@0xc, u8@0x9, u16@0xa, u16@0xc */
void ts4_if_set_u16_offa_88472A00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, int a5)
{
    ts4_word p1;
    ts4_word p2;
    unsigned short t3;
    unsigned short t4;

    if ((ts4_word)(a1 & 0xff) != 0) {
        *(unsigned char *)((char *)(ts4_word)(a0) + 9) = (unsigned char)(a2 & 0xf);
        if ((ts4_word)(a5 & 0x3) < (ts4_word)(a2 & 0x3)) {
            p1 = (ts4_word)((~(a3 | a3)) << 14);
        } else {
            p1 = (ts4_word)(a3 << 14);
        }
        if ((int)a5 < (int)(a2 & 0xf)) {
            p2 = (ts4_word)((~(a4 | a4)) << 14);
        } else {
            p2 = (ts4_word)(a4 << 14);
        }
        t3 = *(unsigned short *)((char *)(ts4_word)(a0) + 10);
        t4 = *(unsigned short *)((char *)(ts4_word)(a0) + 12);
        *(unsigned short *)((char *)(ts4_word)(a0) + 10) = (unsigned short)((t3 & 0x3fff) | p1);
        *(unsigned short *)((char *)(ts4_word)(a0) + 12) = (unsigned short)((t4 & 0x3fff) | p2);
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 10) = (unsigned short)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 9) = (unsigned char)255;
    *(unsigned short *)((char *)(ts4_word)(a0) + 12) = (unsigned short)0;
    return;
}

/* Swing_DLL.xex 0x88472B60: get u8@0xd9 */
ts4_word ts4_get_u8_offd9_88472B60(ts4_word a0)
{
    return (((((*(unsigned char *)((char *)(ts4_word)(a0) + 217)) + -255) == 0) ^ 1) + 1);
}

/* Swing_DLL.xex 0x884734B8: if_get u8@0xd8, u32@0x1e8 */
ts4_word ts4_if_get_u8_offd8_884734B8(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 216);
    if ((ts4_word)t1 != 6 && (ts4_word)t1 != 7) {
        return 0;
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 488));
}

/* Swing_DLL.xex 0x884734E0: if_get u8@0xd8, u32@0x1e8 */
ts4_word ts4_if_get_u8_offd8_884734E0(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 216);
    if ((ts4_word)t1 != 6 && (ts4_word)t1 != 7) {
        return 0;
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 488));
}

/* Swing_DLL.xex 0x88473F78: if_call_seq u32@0x8, u32@0x10, u32@0x6c, fn_884944C0 */
ts4_word ts4_if_call_seq_u32_off8_88473F78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p5;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p5 = (ts4_word)a0;
    if ((ts4_word)t1 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)) != 0) {
        loc50[0] = (ts4_word)a0;
        t4 = fn_884944C0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 108)), (ts4_word)(ts4_word)&loc50[0], (ts4_word)1);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x88475A78: if_addr lbl_88086ED0, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88086ED0_88475A78(ts4_word a0, int a1)
{
    float t1;
    float t2;

    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88086ED0;
    if ((int)a1 == 0) {
        return;
    }
    t1 = *(float *)((char *)(ts4_word)(a0) + 36);
    t2 = *(float *)lbl_88001A20;
    if (!(t1 == t2)) {
        return;
    }
    *(float *)((char *)(ts4_word)(a0) + 36) = (*(float *)lbl_8803A3B0);
    return;
}

/* Swing_DLL.xex 0x88476C30: addr lbl_8808384C, u32@0x8, u16@0x6, u32@0x0, u32@0x10, u8@0x1c */
void ts4_addr_lbl_8808384C_88476C30(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808384C;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)a1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 29) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88477588: if_call_seq lbl_88083354, u32@0x0, fn_88477010, u32@0x94, u32@lbl_88CACF08, KeTlsGetValue */
ts4_word ts4_if_call_seq_lbl_88083354_88477588(ts4_word a0)
{
    ts4_word t2;
    ts4_word t4;
    ts4_word t8;
    ts4_word t10;
    ts4_word t14;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88083354;
    fn_88477010();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 148);
    if ((int)(t2 & 0x80000000) == 0) {
        t4 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 140)), (ts4_word)(t2 << 2), (ts4_word)23);
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
    if ((int)(t8 & 0x80000000) == 0) {
        t10 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t10, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 128)), (ts4_word)(t8 << 2), (ts4_word)23);
    }
    t14 = fn_884684A8((ts4_word)a0);
    return t14;
}

/* Swing_DLL.xex 0x88478CE8: call_seq lbl_88086FCC, u16@0x6, u32@0x0, u32@0x14, ts4_set_u32_off8_8847FA60, ts4_set_u32_off8_8847FA60 */
ts4_word ts4_call_seq_lbl_88086FCC_88478CE8(ts4_word a0)
{
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88086FCC;
    ts4_set_u32_off8_8847FA60((ts4_word)(a0 + 12), (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 20)));
    ts4_set_u32_off8_8847FA60((ts4_word)(a0 + 12), (ts4_word)a0);
    return a0;
}

/* Swing_DLL.xex 0x88478D50: if_call_seq lbl_88086FCC, u32@0x0, u32@0x20, u32@lbl_88CACF08, KeTlsGetValue, u32@0x18 */
ts4_word ts4_if_call_seq_lbl_88086FCC_88478D50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88086FCC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    p6 = (ts4_word)a0;
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(volatile ts4_word *)lbl_88CACF08));
        t5 = fn_8841A590((ts4_word)t3, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)(t1 << 5), (ts4_word)23);
        p6 = (ts4_word)t5;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p6;
}

/* Swing_DLL.xex 0x884796F8: call_seq lbl_88087004, u16@0x6, u32@0x0, u32@0x14, ts4_set_u32_off8_8847FA60, ts4_set_u32_off8_8847FA60 */
ts4_word ts4_call_seq_lbl_88087004_884796F8(ts4_word a0)
{
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087004;
    ts4_set_u32_off8_8847FA60((ts4_word)(a0 + 12), (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 20)));
    ts4_set_u32_off8_8847FA60((ts4_word)(a0 + 12), (ts4_word)a0);
    return a0;
}

/* Swing_DLL.xex 0x8847A440: call_seq fn_88479EA8, lbl_880836F4, u32@0x0, u32@0x150, u32@0x154, u32@0x158 */
ts4_word ts4_call_seq_fn_88479EA8_8847A440(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a1;
    (void)a2;
    fn_88479EA8();
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880836F4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 336) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 340) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 344) = (ts4_word)(2147483648);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)a3;
    return a0;
}

/* Swing_DLL.xex 0x8847A978: set u16@0x6, lbl_8808379C, u8@0x8, u32@0x0, u32@0x18, u8@0x8 */
void ts4_set_u16_off6_8847A978(ts4_word a0, ts4_word a1, ts4_word a2)
{
    float t1;
    float t2;

    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808379C;
    t1 = *(float *)lbl_88087070;
    t2 = *(float *)lbl_8802F8CC;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    *(volatile float *)((char *)(ts4_word)(a0) + 12) = t1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)4;
    *(volatile float *)((char *)(ts4_word)(a0) + 16) = t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a2;
    return;
}

/* Swing_DLL.xex 0x8847B788: call_seq lbl_88087078, u16@0x6, u32@0x0, u32@0x14, ts4_set_u32_off8_8847FA60, ts4_if_call_seq_u32_off0_88487020 */
ts4_word ts4_call_seq_lbl_88087078_8847B788(ts4_word a0, ts4_word a1)
{
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087078;
    ts4_set_u32_off8_8847FA60((ts4_word)(a0 + 12), (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 20)));
    ts4_if_call_seq_u32_off0_88487020((ts4_word)(a0 + 24), (ts4_word)a1);
    ts4_set_u32_off8_8847FA60((ts4_word)(a0 + 12), (ts4_word)a0);
    return a0;
}

/* Swing_DLL.xex 0x8847E988: call_seq lbl_880870F4, u16@0x6, u32@0x0, u32@0x18, ts4_set_u32_off8_8847FA60, ts4_set_u32_off8_8847FA60 */
ts4_word ts4_call_seq_lbl_880870F4_8847E988(ts4_word a0)
{
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880870F4;
    ts4_set_u32_off8_8847FA60((ts4_word)(a0 + 16), (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 24)));
    ts4_set_u32_off8_8847FA60((ts4_word)(a0 + 16), (ts4_word)a0);
    return a0;
}

/* Swing_DLL.xex 0x8847EF68: addr lbl_88084264, u16@0x6, u32@0x0, u32@0x8, u32@0xc, u32@0x10 */
void ts4_addr_lbl_88084264_8847EF68(ts4_word a0)
{
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88084264;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(2147483648);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(2147483648);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(2147483648);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(2147483648);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 64) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88480E98: if_get  */
ts4_word ts4_if_get_88480E98(float f1)
{
    float t1;

    t1 = *(float *)lbl_88001A20;
    if (f1 < t1) {
        return 8;
    }
    return 0;
}

/* Swing_DLL.xex 0x88481180: get  */
void ts4_get_88481180(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    float t1;
    float t3;
    float t8;

    t1 = *(float *)((char *)(ts4_word)(a0) + 8);
    *(float *)((char *)(ts4_word)(a3) + 0) = (t1 * (*(float *)((char *)(ts4_word)(a1) + 4)));
    t3 = *(float *)((char *)(ts4_word)(a0) + 12);
    *(float *)((char *)(ts4_word)(a3) + 4) = (t3 * (*(float *)((char *)(ts4_word)(a1) + 4)));
    *(float *)((char *)(ts4_word)(a3) + 8) = (*(float *)((char *)(ts4_word)(a0) + 4));
    *(float *)((char *)(ts4_word)(a3) + 12) = (*(float *)((char *)(ts4_word)(a0) + 16));
    *(float *)((char *)(ts4_word)(a3) + 16) = (*(float *)((char *)(ts4_word)(a0) + 20));
    t8 = *(float *)((char *)(ts4_word)(a1) + 8);
    *(float *)((char *)(ts4_word)(a2) + 28) = (t8 * (*(float *)((char *)(ts4_word)(a0) + 0)));
    return;
}

/* Swing_DLL.xex 0x88481278: call_seq lbl_88087154, u16@0x6, u32@0x0, u32@0x14, ts4_set_u32_off8_8847FA60, ts4_set_u32_off8_8847FA60 */
ts4_word ts4_call_seq_lbl_88087154_88481278(ts4_word a0)
{
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087154;
    ts4_set_u32_off8_8847FA60((ts4_word)(a0 + 12), (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 20)));
    ts4_set_u32_off8_8847FA60((ts4_word)(a0 + 12), (ts4_word)a0);
    return a0;
}

/* Swing_DLL.xex 0x88482FC8: call_seq fn_88479EA8, lbl_88084A14, u32@0x0, u32@0x150, u32@0x154, u32@0x158 */
ts4_word ts4_call_seq_fn_88479EA8_88482FC8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a1;
    (void)a2;
    fn_88479EA8();
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88084A14;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 336) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 340) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 344) = (ts4_word)(2147483648);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)a3;
    return a0;
}

/* Swing_DLL.xex 0x884834F0: get  */
void ts4_get_884834F0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 32) = ((*(float *)((char *)(ts4_word)(a0) + 20)) + f1);
    return;
}

/* Swing_DLL.xex 0x88483500: if_get  */
ts4_word ts4_if_get_88483500(ts4_word a0)
{
    ts4_word p3;
    float t1;
    float t2;

    t1 = *(float *)((char *)(ts4_word)(a0) + 20);
    t2 = *(float *)((char *)(ts4_word)(a0) + 32);
    p3 = (ts4_word)1;
    if (!(t1 == t2)) {
        p3 = (ts4_word)0;
    }
    return (p3 & 0xff);
}

/* Swing_DLL.xex 0x88483520: if_get  */
ts4_word ts4_if_get_88483520(ts4_word a0)
{
    ts4_word p3;
    float t1;
    float t2;

    t1 = *(float *)((char *)(ts4_word)(a0) + 24);
    t2 = *(float *)((char *)(ts4_word)(a0) + 20);
    p3 = (ts4_word)1;
    if (!(t1 == t2)) {
        p3 = (ts4_word)0;
    }
    return (p3 & 0xff);
}

/* Swing_DLL.xex 0x88483598: if_get u32@0x28, u32@0x0, u32@0x10, vcall, u32@0x28, u32@0x0 */
ts4_word ts4_if_get_u32_off28_88483598(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t1 == 0 || (ts4_word)t1 == 1) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16))))((ts4_word)a0);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t6 == 0 || (ts4_word)t6 == 2) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0);
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t11 == 0 || (ts4_word)t11 == 3) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 24))))((ts4_word)a0);
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 40));
}

/* Swing_DLL.xex 0x884876F0: if_tail ts4_set_u8_off3d_885E9CC8, ts4_set_u8_off3d_885E9CC8 */
ts4_word ts4_if_tail_fn_885E9CC8_884876F0(ts4_word a0, int a1)
{
    if ((int)a1 == 0) {
        return ts4_set_u8_off3d_885E9CC8((ts4_word)(a0 + 384), (ts4_word)0);
    }
    return ts4_set_u8_off3d_885E9CC8((ts4_word)(a0 + 384), (ts4_word)2);
}

/* Swing_DLL.xex 0x88487AD8: call_seq fn_88472530, u32@0xfc, u32@0xfc, u64@0x160, RtlLeaveCriticalSection */
ts4_word ts4_call_seq_fn_88472530_88487AD8(ts4_word a0)
{
    ts4_word t2;

    fn_88472530((ts4_word)(a0 + 320));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 252);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 252) = (ts4_word)(t2 + 1);
    *(volatile ts4_u64 *)((char *)(ts4_word)(a0) + 352) = (ts4_u64)-1;
    RtlLeaveCriticalSection((ts4_word)(a0 + 320));
    return t2;
}

/* Swing_DLL.xex 0x88488740: if_call_seq lbl_88087384, u32@0x0, ts4_if_call_seq_u32_off4_88472748, ts4_if_call_seq_u32_off4_88472748, ts4_get_u32_off0_885EAD60, ts4_get_u32_off0_885EAD60 */
ts4_word ts4_if_call_seq_lbl_88087384_88488740(ts4_word a0)
{
    ts4_word t10;
    ts4_word t12;
    ts4_word t17;
    ts4_word t19;
    ts4_word t23;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087384;
    ts4_if_call_seq_u32_off4_88472748((ts4_word)(a0 + 936));
    ts4_if_call_seq_u32_off4_88472748((ts4_word)(a0 + 872));
    ts4_get_u32_off0_885EAD60((ts4_word)(a0 + 768));
    ts4_get_u32_off0_885EAD60((ts4_word)(a0 + 640));
    ts4_get_u32_off0_885EAD60((ts4_word)(a0 + 512));
    ts4_if_call_seq_u32_off38_885EAA60((ts4_word)(a0 + 384));
    ts4_if_call_seq_u32_off4_88472748((ts4_word)(a0 + 360));
    ts4_get_u32_off0_885EAD60((ts4_word)(a0 + 256));
    ts4_if_call_seq_u32_off4_88472748((ts4_word)(a0 + 232));
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 184);
    if ((int)(t10 & 0x80000000) == 0) {
        t12 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t12, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 176)), (ts4_word)(t10 << 3), (ts4_word)23);
    }
    ts4_if_call_seq_u32_off4_88472748((ts4_word)(a0 + 160));
    t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    if ((int)(t17 & 0x80000000) == 0) {
        t19 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t19, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 108)), (ts4_word)(t17 << 3), (ts4_word)23);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)(ts4_word)lbl_880869E8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)(ts4_word)lbl_880869E8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)(ts4_word)lbl_880869E8;
    t23 = fn_88541FB0((ts4_word)a0);
    return t23;
}

/* Swing_DLL.xex 0x88489438: if_get u32@0x4, u32@0x4, u32@0xb8, u32@0xb8, u16@0x20, u16@0x20 */
void ts4_if_get_u32_off4_88489438(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    unsigned short t5;
    unsigned short t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 184);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 184);
    t5 = *(unsigned short *)((char *)(ts4_word)(t3) + 32);
    t6 = *(unsigned short *)((char *)(ts4_word)(t4) + 32);
    if ((ts4_word)t5 >= (ts4_word)t6) {
        if ((ts4_word)t5 != (ts4_word)t6 || (ts4_word)(*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 8))) + 184))) + 32)) >= (ts4_word)(*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 8))) + 184))) + 32))) {
            *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
            return;
        }
        *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x8848B958: get u32@0x20, u32@0x3c */
ts4_word ts4_get_u32_off20_8848B958(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    unsigned char t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    t3 = *(unsigned char *)((char *)(ts4_word)(t1) + (a1 & 0xffff));
    return ((((t3 << 5) | (t3 >> 27)) + t2) + 48);
}

/* Swing_DLL.xex 0x8848E3E0: if_call_seq u32@0x118, fn_8848D3B0, fn_8849F8B0 */
ts4_word ts4_if_call_seq_u32_off118_8848E3E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 280);
    if ((int)t1 != 0) {
        fn_8848D3B0();
    }
    t4 = fn_8849F8B0((ts4_word)a1);
    return t4;
}

/* Swing_DLL.xex 0x8848E680: if_get u16@0x22, u32@0x40, u16@0x22 */
void ts4_if_get_u16_off22_8848E680(ts4_word a0, ts4_word a1)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a1) + 34);
    if ((ts4_word)t1 == 65535) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)((t1 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 64))) = (ts4_word)0;
    *(unsigned short *)((char *)(ts4_word)(a1) + 34) = (unsigned short)-1;
    return;
}

/* Swing_DLL.xex 0x8848F838: if_get u32@0xb8, u32@0x8, fn_88492800, u16@0x20, u32@0x4c, u8@0xb8 */
ts4_word ts4_if_get_u32_offb8_8848F838(ts4_word a0, ts4_word a1)
{
    ts4_word p10;
    ts4_word t1;
    ts4_word t2;
    unsigned short t3;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 184);
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)0;
    t2 = fn_88492800((ts4_word)t1, (ts4_word)a1);
    t3 = *(unsigned short *)((char *)(ts4_word)(t1) + 32);
    p10 = (ts4_word)t2;
    if (((ts4_word)t3 != 65535 && (int)(*(ts4_word *)((char *)(ts4_word)(t1) + 76)) == 0) && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 184)) != 0) {
        fn_8848E9A0((ts4_word)a0, (ts4_word)t1);
        t9 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
        p10 = (ts4_word)t9;
    }
    return p10;
}

/* Swing_DLL.xex 0x884927E0: get u32@0x28, u8@0x12, u8@0x12 */
void ts4_get_u32_off28_884927E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 40);
    *(unsigned char *)((char *)(ts4_word)(t1) + 18) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(t1) + 18)) | a2);
    return;
}

/* Swing_DLL.xex 0x88493778: if_call_seq u32@0x2c, ts4_if_call_seq_u32_off8_88473208, u32@0x10, fn_8846C178 */
ts4_word ts4_if_call_seq_u32_off2c_88493778(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t1 >= 1 && (ts4_word)t1 != 1) {
        if ((ts4_word)t1 < 3) {
            t4 = fn_8846C178((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)a1);
            return t4;
        }
        return a1;
    }
    t2 = ts4_if_call_seq_u32_off8_88473208((ts4_word)a1, (ts4_word)7, (ts4_word)1, (ts4_word)0);
    return t2;
}

/* Swing_DLL.xex 0x88493EB0: if_get u16@0x20, u16@0x20, u16@0x20 */
ts4_word ts4_if_get_u16_off20_88493EB0(ts4_word a0, ts4_word a1)
{
    unsigned short t1;
    unsigned short t3;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t1 != 65535) {
        return a0;
    }
    t3 = *(unsigned short *)((char *)(ts4_word)(a1) + 32);
    if ((ts4_word)t3 == 65535) {
        return a0;
    }
    return a1;
}

/* Swing_DLL.xex 0x88498B20: call_seq ts4_fn_8847B630, u32@0x4, u32@0x0, u32@0x8, u32@0xc, u8@0x10 */
ts4_word ts4_call_seq_fn_8847B630_88498B20(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = ts4_fn_8847B630((ts4_word)a1);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 17) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 18) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 19) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 20) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 21) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 25) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 22) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 23) = (unsigned char)0;
    return t1;
}

/* Swing_DLL.xex 0x88499928: call_seq fn_88420E48, fn_88420E48, fn_884997B0, fn_88499868, u8@0x18, u8@0x19 */
ts4_word ts4_call_seq_fn_88420E48_88499928(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[4];
    ts4_word loc60[4];
    ts4_word t3;

    fn_88420E48((ts4_word)(ts4_word)&loc50[0], (ts4_word)(a1 + 224), (ts4_word)a3);
    fn_88420E48((ts4_word)(ts4_word)&loc60[0], (ts4_word)(a2 + 224), (ts4_word)a3);
    t3 = fn_884997B0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    fn_88499868((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    *(unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 25) = (unsigned char)1;
    return t3;
}

/* Swing_DLL.xex 0x884A0720: call_seq ts4_call_seq_fn_8849FE80_8848E320, u32@0x28, u8@0x12, u8@0x12 */
ts4_word ts4_call_seq_fn_8848E320_884A0720(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    t1 = ts4_call_seq_fn_8849FE80_8848E320();
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 40);
    *(unsigned char *)((char *)(ts4_word)(t2) + 18) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(t2) + 18)) | a2);
    return t1;
}

/* Swing_DLL.xex 0x884A1700: if_call_seq fn_885F4D10, lbl_88087DDC, u32@0x0, u32@0x54, u32@0x58, u32@0x5c */
ts4_word ts4_if_call_seq_fn_885F4D10_884A1700(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p2;
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p2 = (ts4_word)a0;
    if ((ts4_word)a0 != 0) {
        t1 = fn_885F4D10((ts4_word)a0, (ts4_word)0, (ts4_word)0);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087DDC;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)(2147483648);
        p2 = (ts4_word)t1;
    }
    return p2;
}

/* Swing_DLL.xex 0x884A1760: call_seq fn_885F4D10, lbl_88087DDC */
ts4_word ts4_call_seq_fn_885F4D10_884A1760(void)
{
    ts4_word loc50[26];

    fn_885F4D10((ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)0);
    return (ts4_word)lbl_88087DDC;
}

/* Swing_DLL.xex 0x884A1798: if_call_seq u32@0x5c, u32@lbl_88CACF08, KeTlsGetValue, u32@0x54, fn_8841A590, ts4_if_call_seq_u32_off18_885F4D78 */
ts4_word ts4_if_call_seq_u32_off5c_884A1798(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t9;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 84)), (ts4_word)(t1 << 2), (ts4_word)23);
    }
    ts4_if_call_seq_u32_off18_885F4D78((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t9 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t9, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)41);
    }
    return a0;
}

/* Swing_DLL.xex 0x884A22C0: if_get u32@0x8, u32@0x0, u32@0x8, vcall, u32@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_off8_884A22C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p8;
    int t1;
    ts4_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    p8 = (ts4_word)a0;
    if ((int)t1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
        t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0, (ts4_word)a1);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x884A2FE8: if_call_seq lbl_880885D0, u32@0x0, u32@0x34, u32@lbl_88CACF08, KeTlsGetValue, u32@0x2c */
ts4_word ts4_if_call_seq_lbl_880885D0_884A2FE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p6;
    ts4_word p12;
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t9;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880885D0;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52);
    p6 = (ts4_word)a0;
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(volatile ts4_word *)lbl_88CACF08));
        t5 = fn_8841A590((ts4_word)t3, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 44)), (ts4_word)(t1 << 2), (ts4_word)23);
        p6 = (ts4_word)t5;
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
    p12 = (ts4_word)p6;
    if ((int)(t7 & 0x80000000) == 0) {
        t9 = KeTlsGetValue((ts4_word)(*(volatile ts4_word *)lbl_88CACF08));
        t11 = fn_8841A590((ts4_word)t9, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)(t7 << 2), (ts4_word)23);
        p12 = (ts4_word)t11;
    }
    return p12;
}

/* Swing_DLL.xex 0x884A5138: if_get u32@0xc, u32@0x0, u32@0x10, vcall, u32@0x18, u32@0x14 */
ts4_word ts4_if_get_u32_offc_884A5138(ts4_word a0, ts4_word a1)
{
    ts4_word p9;
    ts4_word p10;
    ts4_word t1;
    int t4;
    ts4_word t5;
    ts4_word t7;
    ts4_word t8;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1);
    p10 = (ts4_word)t4;
    if ((int)t4 != 11) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
        t7 = fn_8854D9B0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 20)) + 16), (ts4_word)(t5 + 16));
        p9 = (ts4_word)t7;
        if ((ts4_word)t7 != 0) {
            t8 = ts4_get_u32_off10_884943A0((ts4_word)t7);
            p9 = (ts4_word)t8;
        }
        p10 = (ts4_word)p9;
    }
    return p10;
}

/* Swing_DLL.xex 0x884A5900: if_call_seq u32@0xcc, u32@lbl_88CACF08, KeTlsGetValue, u32@0x48, fn_8841A328, u32@0x4c */
ts4_word ts4_if_call_seq_u32_offcc_884A5900(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p8;
    ts4_word p10;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 204);
    if ((ts4_word)t1 == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 72);
        if ((ts4_word)t4 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 76) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 76)) + -1);
            *(ts4_word *)((char *)(ts4_word)(t3) + 72) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 0));
            p8 = (ts4_word)t4;
        } else {
            t5 = fn_8841A328((ts4_word)t3, (ts4_word)2);
            p8 = (ts4_word)t5;
        }
        if ((ts4_word)p8 != 0) {
            *(ts4_word *)((char *)(ts4_word)(p8) + 0) = (ts4_word)0;
            *(unsigned short *)((char *)(ts4_word)(p8) + 4) = (unsigned short)0;
            *(unsigned short *)((char *)(ts4_word)(p8) + 6) = (unsigned short)((0) | 32768);
            *(ts4_word *)((char *)(ts4_word)(p8) + 8) = (ts4_word)0;
            *(unsigned short *)((char *)(ts4_word)(p8) + 12) = (unsigned short)0;
            *(unsigned short *)((char *)(ts4_word)(p8) + 14) = (unsigned short)((0) | 32768);
            p10 = (ts4_word)p8;
        } else {
            p10 = (ts4_word)0;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 204) = (ts4_word)p10;
    }
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 204)) + 8);
}

/* Swing_DLL.xex 0x884A8DF0: call_seq fn_885F4AB8, lbl_880882AC, u32@0x0, u8@0x5c, u8@0x5d */
ts4_word ts4_call_seq_fn_885F4AB8_884A8DF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    float t2;
    float t3;
    float t4;

    fn_885F4AB8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    t2 = *(float *)lbl_88001A68;
    t3 = *(float *)lbl_88028BE0;
    t4 = *(float *)lbl_88029278;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880882AC;
    *(volatile float *)((char *)(ts4_word)(a0) + 80) = t2;
    *(volatile float *)((char *)(ts4_word)(a0) + 84) = t3;
    *(volatile float *)((char *)(ts4_word)(a0) + 88) = t4;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 92) = (unsigned char)1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 93) = (unsigned char)1;
    return a0;
}

/* Swing_DLL.xex 0x884ADD48: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, lbl_88088BD0, u16@0x4, u32@0x0 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_884ADD48(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)20, (ts4_word)21);
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)20;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88088BD0;
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 16) = (ts4_word)(2147483648);
    return t3;
}

/* Swing_DLL.xex 0x884AE5C0: if_call_seq u32@0x10, u32@lbl_88CACF08, KeTlsGetValue, u32@0x8, fn_8841A590, lbl_8803A308 */
ts4_word ts4_if_call_seq_u32_off10_884AE5C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)(t1 << 2), (ts4_word)23);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t8 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t8, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x884AE8A8: if_get u32@0x8, fn_884AE750 */
ts4_word ts4_if_get_u32_off8_884AE8A8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)a1 != (ts4_word)t1) {
        return a0;
    }
    return fn_884AE750((ts4_word)(a0 + -32), (ts4_word)a1);
}

/* Swing_DLL.xex 0x884B7988: if_call_seq u8@0x0, fn_884A3F58, ts4_if_call_seq_u32_off8_884A3F88, ts4_call_seq_lbl_88D25C34_884B7900, u8@0x0, fn_884A4088 */
ts4_word ts4_if_call_seq_u8_off0_884B7988(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word loc60[6];
    ts4_word loc50[4];
    ts4_word t3;
    unsigned char t4;

    if ((ts4_word)a1 != 0 && (ts4_word)a2 != 0) {
        fn_884A3F58((ts4_word)(ts4_word)&loc60[0]);
        ts4_if_call_seq_u32_off8_884A3F88((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1, (ts4_word)a5);
        t3 = ts4_call_seq_lbl_88D25C34_884B7900((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0], (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
        t4 = *(unsigned char *)((char *)(ts4_word)(t3) + 0);
        fn_884A4088((ts4_word)(ts4_word)&loc60[0]);
        *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)t4;
        return a0;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x884B7C98: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, lbl_880895D4, u16@0x4, u32@0x0 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_884B7C98(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)20, (ts4_word)21);
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)20;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880895D4;
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 16) = (ts4_word)(2147483648);
    return t3;
}

/* Swing_DLL.xex 0x884B9630: if_call_seq u32@0x10, u32@lbl_88CACF08, KeTlsGetValue, u32@0x8, fn_8841A590, lbl_8803A308 */
ts4_word ts4_if_call_seq_u32_off10_884B9630(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)(t1 << 3), (ts4_word)23);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t8 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t8, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x884BA370: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, lbl_88089714, u16@0x4, u32@0x0 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_884BA370(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)20, (ts4_word)21);
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)20;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88089714;
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 16) = (ts4_word)(2147483648);
    return t3;
}

/* Swing_DLL.xex 0x884BEE70: if_call_seq lbl_880898DC, u32@0x0, u32@0x18, u32@lbl_88CACF08, KeTlsGetValue, u32@0x10 */
ts4_word ts4_if_call_seq_lbl_880898DC_884BEE70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880898DC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24);
    p6 = (ts4_word)a0;
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(volatile ts4_word *)lbl_88CACF08));
        t5 = fn_8841A590((ts4_word)t3, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)(t1 << 5), (ts4_word)23);
        p6 = (ts4_word)t5;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p6;
}

/* Swing_DLL.xex 0x884BF5A8: if_call_seq u32@0x30, u32@lbl_88CACF08, KeTlsGetValue, u32@0x28, fn_8841A590, u32@0x24 */
ts4_word ts4_if_call_seq_u32_off30_884BF5A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p12;
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t9;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    p6 = (ts4_word)a0;
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t5 = fn_8841A590((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40)), (ts4_word)(t1 << 2), (ts4_word)23);
        p6 = (ts4_word)t5;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    p12 = (ts4_word)p6;
    if ((int)(t7 & 0x80000000) == 0) {
        t9 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t11 = fn_8841A590((ts4_word)t9, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)), (ts4_word)(t7 << 2), (ts4_word)23);
        p12 = (ts4_word)t11;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p12;
}

/* Swing_DLL.xex 0x884BFF70: if_call_seq u32@0x8, u32@0x4, u32@0x10, fn_8841C678, u32@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off8_884BFF70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p5;
    ts4_word t1;
    int t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p5 = (ts4_word)a0;
    if ((int)t2 == (int)(t1 & 0x3fffffff)) {
        t4 = fn_8841C678((ts4_word)a1, (ts4_word)4);
        p5 = (ts4_word)t4;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(ts4_word *)((char *)(ts4_word)((t6 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a1) + 0))) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 4)) + 1);
    return p5;
}

/* Swing_DLL.xex 0x884C0C88: get  */
float ts4_get_884C0C88(ts4_word a0, float f1)
{
    float t1;
    float t2;
    float t3;

    t1 = *(float *)((char *)(ts4_word)(a0) + 20);
    t2 = *(float *)((char *)(ts4_word)(a0) + 12);
    t3 = *(float *)((char *)(ts4_word)(a0) + 8);
    return (((((t1 * t2) * t3) * f1) * f1) * (*(float *)lbl_88001978));
}

/* Swing_DLL.xex 0x884C5258: if_call_seq u32@lbl_88CAD568, u32@lbl_88D3CB4C, u32@lbl_88D3CB50, u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510 */
ts4_word ts4_if_call_seq_u32_lbl_88CAD568_884C5258(void)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    t1 = *(ts4_word *)lbl_88CAD568;
    if (((ts4_word)t1 != 0 && (ts4_word)(*(ts4_word *)lbl_88D3CB4C) != 0) && (ts4_word)(*(ts4_word *)lbl_88D3CB50) != 0) {
        t5 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t6 = fn_8841A510((ts4_word)t5, (ts4_word)8, (ts4_word)21);
        *(unsigned short *)((char *)(ts4_word)(t6) + 4) = (unsigned short)8;
        t7 = fn_884C52E0((ts4_word)t6);
        return t7;
    }
    return 0;
}

/* Swing_DLL.xex 0x884C9958: if_get u32@0x1c, u32@0x20, u32@0x24, u32@0x0, u32@0x38 */
ts4_word ts4_if_get_u32_off1c_884C9958(ts4_word a0)
{
    ts4_word t1;
    int t2;
    int t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 32);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 36);
    if ((int)t2 >= 0 && (int)t3 >= 0) {
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0, (ts4_word)t2, (ts4_word)t3);
    }
    return 0;
}

/* Swing_DLL.xex 0x884C9AF0: if_get u32@0x78, u32@0x1c, u32@0x20, u32@0x24, u32@0x1c, u32@0x20 */
ts4_word ts4_if_get_u32_off78_884C9AF0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t5;
    int t6;
    int t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    if ((ts4_word)t1 != 0) {
        return fn_88423788((ts4_word)(t1 + 40), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 52)), (ts4_word)0);
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 32);
    t7 = *(ts4_word *)((char *)(ts4_word)(t5) + 36);
    if ((int)t6 >= 0 && (int)t7 >= 0) {
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0, (ts4_word)t6, (ts4_word)t7);
    }
    return 0;
}

/* Swing_DLL.xex 0x884CCE18: if_addr lbl_88CACFCC, ts4_get_u32_off0_8841EAC8, ts4_get_u32_off0_8841EAC8, fn_884210E8, lbl_88CAD02C, ts4_get_u32_off0_8841EAC8 */
ts4_word ts4_if_addr_lbl_88CACFCC_884CCE18(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    int t3;
    ts4_word t4;
    ts4_word t5;
    int t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;

    t1 = ts4_get_u32_off0_8841EAC8((ts4_word)(ts4_word)lbl_88CACFCC);
    t2 = ts4_get_u32_off0_8841EAC8((ts4_word)a1);
    t3 = fn_884210E8((ts4_word)t2, (ts4_word)t1);
    if ((int)t3 != 0) {
        t4 = ts4_get_u32_off0_8841EAC8((ts4_word)(ts4_word)lbl_88CAD02C);
        t5 = ts4_get_u32_off0_8841EAC8((ts4_word)a1);
        t6 = fn_884210E8((ts4_word)t5, (ts4_word)t4);
        if ((int)t6 != 0) {
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
            t8 = ts4_get_u32_off0_8841EAC8((ts4_word)a1);
            t10 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t7) + 16))))((ts4_word)a0, (ts4_word)t8);
            if ((ts4_word)t10 == 0) {
                ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 28))))((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
            }
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x884D37D0: call_seq lbl_8808C6C0, u32@0x8, u16@0x6, u32@0x0, u32@0xc, fn_88423CE0 */
ts4_word ts4_call_seq_lbl_8808C6C0_884D37D0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808C6C0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    fn_88423CE0((ts4_word)(a0 + 16));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(2147483648);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(2147483648);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)(2147483648);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)(2147483648);
    return a0;
}

/* Swing_DLL.xex 0x884D3E08: if_get ts4_addr_lbl_8808BFAC_884C5458, u32@0x14, fn_884210E8, fn_8841CBF8, ts4_addr_lbl_8808BFAC_884C5458, u32@0x14 */
ts4_word ts4_if_get_fn_884C5458_884D3E08(ts4_word a0)
{
    ts4_word p17;
    ts4_word loc60[130];
    ts4_word loc50[4];
    ts4_word t1;
    int t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;
    ts4_word t12;
    ts4_word t16;

    t1 = ts4_addr_lbl_8808BFAC_884C5458();
    t3 = fn_884210E8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)t1);
    p17 = (ts4_word)t3;
    if ((int)t3 != 0) {
        t4 = fn_8841CBF8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0], (ts4_word)512);
        t5 = ts4_addr_lbl_8808BFAC_884C5458((ts4_word)t4);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
        t7 = ts4_if_get_u32_off8_8841D058((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_8808C7B8);
        t8 = ts4_if_get_u32_off8_8841D058((ts4_word)t7, (ts4_word)t6);
        t9 = ts4_if_get_u32_off8_8841D058((ts4_word)t8, (ts4_word)(ts4_word)lbl_8808C798);
        t10 = ts4_if_get_u32_off8_8841D058((ts4_word)t9, (ts4_word)t5);
        ts4_if_get_u32_off8_8841D058((ts4_word)t10, (ts4_word)(ts4_word)lbl_8808C750);
        t12 = *(ts4_word *)lbl_88CAD340;
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t12) + 0))) + 12))))((ts4_word)t12, (ts4_word)1, (ts4_word)((2062483456) | 27654), (ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_8808C72C, (ts4_word)118);
        t16 = fn_8841D638((ts4_word)(ts4_word)&loc50[0]);
        p17 = (ts4_word)t16;
    }
    return p17;
}

/* Swing_DLL.xex 0x884D60D0: if_call_seq lbl_8808C890, fn_884DAF90, lbl_8808C1C8, fn_884214A8, u32@0x0, ts4_tailcall_fn_88564B08_88421360 */
ts4_word ts4_if_call_seq_lbl_8808C890_884D60D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    int t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t6;
    ts4_word t4;
    ts4_word t2;

    t1 = fn_884DAF90((ts4_word)a0, (ts4_word)(ts4_word)lbl_8808C890, (ts4_word)0);
    if ((ts4_word)t1 != 0) {
        t3 = ts4_tailcall_fn_88564B08_88421360((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t3;
        if ((int)t3 != 1) {
            if ((int)t3 > 1 && (int)t3 <= 5) {
                t5 = fn_884DAF90((ts4_word)a0, (ts4_word)(ts4_word)lbl_8808C880, (ts4_word)0);
                if ((ts4_word)t5 == 0) {
                    t7 = fn_884214A8((ts4_word)(ts4_word)lbl_8808C1BC);
                    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t7;
                    return 0;
                }
                t6 = fn_884214A8((ts4_word)t5);
                *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t6;
                return 0;
            }
            return 1;
        }
        t4 = fn_884214A8((ts4_word)(ts4_word)lbl_8808C1C8);
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t4;
        return 0;
    }
    t2 = fn_884214A8((ts4_word)(ts4_word)lbl_8808C1C8);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t2;
    return 0;
}

/* Swing_DLL.xex 0x884D7550: loop_call_seq ts4_get_u32_off0_885ED260, u32@0x0, fn_885ED378 */
ts4_word ts4_loop_call_seq_fn_885ED260_884D7550(ts4_word a0)
{
    ts4_word lv2;
    ts4_word p5;
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;

    t1 = ts4_get_u32_off0_885ED260((ts4_word)(a0 + 4));
    p6 = (ts4_word)t1;
    lv2 = (ts4_word)t1;
    while ((ts4_word)lv2 != 0) {
        t4 = fn_885ED378((ts4_word)(a0 + 4), (ts4_word)lv2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
        p5 = (ts4_word)t4;
        lv2 = p5;
        p6 = (ts4_word)lv2;
    }
    return p6;
}

/* Swing_DLL.xex 0x884D7D40: loop_call_seq fn_88423788, ts4_get_u32_off0_8841EAC8, fn_885E7AD8, ts4_get_u32_off4_8841EAD0, fn_884D7C98, ts4_get_u32_off0_8841EAC8 */
ts4_word ts4_loop_call_seq_fn_88423788_884D7D40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word lv4;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;

    t1 = fn_88423788((ts4_word)(a0 + 156), (ts4_word)a1, (ts4_word)-1);
    if ((int)t1 == -1) {
        t2 = ts4_get_u32_off0_8841EAC8((ts4_word)a2);
        t3 = fn_885E7AD8((ts4_word)(a0 + 168), (ts4_word)t2, (ts4_word)-1);
        if ((int)t3 == -1) {
            lv4 = (ts4_word)a2;
            do {
                t5 = ts4_get_u32_off4_8841EAD0((ts4_word)lv4);
                if ((ts4_word)t5 == 0) {
                    t6 = fn_884D7C98((ts4_word)a0, (ts4_word)a3);
                    return t6;
                }
                t7 = ts4_get_u32_off0_8841EAC8((ts4_word)t5);
                t8 = fn_885E7AD8((ts4_word)(a0 + 168), (ts4_word)t7, (ts4_word)-1);
                p9 = (ts4_word)t5;
                lv4 = p9;
            } while ((int)t8 == -1);
            return t8;
        }
        return t3;
    }
    return t1;
}

/* Swing_DLL.xex 0x884D9098: call_seq ts4_if_set_u32_off8_8841D598, u32@0x8, lbl_8808CAE8, fn_8841D3B0, fn_884D8538, lbl_8808CAD4 */
ts4_word ts4_call_seq_fn_8841D598_884D9098(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[6];
    ts4_word t4;

    ts4_if_set_u32_off8_8841D598((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    fn_8841D3B0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_8808CAE8, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a3);
    t4 = fn_884D8538((ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    fn_8841D3B0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_8808CAD4);
    fn_8841D638((ts4_word)(ts4_word)&loc50[0]);
    return t4;
}

/* Swing_DLL.xex 0x884E16F8: call_seq u32@0x18, fn_88472530, u32@0xc, u32@0x18, u64@0x20, RtlLeaveCriticalSection */
ts4_word ts4_call_seq_u32_off18_884E16F8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    fn_88472530((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 24)));
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24);
    t5 = *(volatile ts4_word *)((char *)(ts4_word)(((a1 + (a1 << 2)) << 2)) + t3);
    *(volatile ts4_u64 *)((char *)(ts4_word)(t4) + 32) = (ts4_u64)-1;
    RtlLeaveCriticalSection((ts4_word)t4);
    return t5;
}

/* Swing_DLL.xex 0x884E65A8: call_seq fn_88420F08, fn_88420F08, fn_884E6480 */
ts4_word ts4_call_seq_fn_88420F08_884E65A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word loc60[4];
    ts4_word loc50[4];
    ts4_word t3;

    fn_88420F08((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1, (ts4_word)a2);
    fn_88420F08((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a3);
    t3 = fn_884E6480((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a4, (ts4_word)a5);
    return t3;
}

/* Swing_DLL.xex 0x884E6600: call_seq ts4_call_seq_fn_88420B68_88420BF0, fn_88420F08, fn_88420F08, fn_884E6480 */
ts4_word ts4_call_seq_fn_88420BF0_884E6600(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word loc70[12];
    ts4_word loc60[4];
    ts4_word loc50[4];
    ts4_word t4;

    (void)a1;
    ts4_call_seq_fn_88420B68_88420BF0((ts4_word)(ts4_word)&loc70[0]);
    fn_88420F08((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc70[0], (ts4_word)a2);
    fn_88420F08((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc70[0], (ts4_word)a3);
    t4 = fn_884E6480((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a4, (ts4_word)a5);
    return t4;
}

/* Swing_DLL.xex 0x884E6798: call_seq ts4_call_seq_fn_88420B68_88420BF0, fn_884E66F0 */
ts4_word ts4_call_seq_fn_88420BF0_884E6798(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word loc50[12];
    ts4_word t2;

    (void)a1;
    ts4_call_seq_fn_88420B68_88420BF0((ts4_word)(ts4_word)&loc50[0]);
    t2 = fn_884E66F0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
    return t2;
}

/* Swing_DLL.xex 0x884E7418: if_call_seq u32@0x14, lbl_8808D394, u32@0x0, fn_88472858, u32@0x10, u32@lbl_88CACF08 */
ts4_word ts4_if_call_seq_u32_off14_884E7418(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p3;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t6;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808D394;
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_88472858((ts4_word)t1, (ts4_word)1);
        p3 = (ts4_word)t2;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p9 = (ts4_word)p3;
    if ((int)(t4 & 0x80000000) == 0) {
        t6 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t8 = fn_8841A590((ts4_word)t6, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)(t4 << 2), (ts4_word)23);
        p9 = (ts4_word)t8;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p9;
}

/* Swing_DLL.xex 0x884F1F38: if_call_seq u32@0x0, u32@0x0, fn_88582610, u32@0x0, u32@0x18 */
ts4_word ts4_if_call_seq_u32_off0_884F1F38(int a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p1;
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)a0;
    p1 = (ts4_word)a0;
    if ((int)a0 > 0) {
        p1 = (ts4_word)((a0 & 0xffff) | 2147942400);
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)p1;
    t2 = fn_88582610((ts4_word)p1);
    if ((ts4_word)a3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a3) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0));
    }
    return t2;
}

/* Swing_DLL.xex 0x884F2FC8: call_seq fn_884F27D8 */
ts4_word ts4_call_seq_fn_884F27D8_884F2FC8(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)0;
    t1 = fn_884F27D8((ts4_word)a0, (ts4_word)0, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Swing_DLL.xex 0x884F3D88: if_get u32@0x24, fn_884F38B0, fn_884F3A70 */
ts4_word ts4_if_get_u32_off24_884F3D88(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((int)t1 == 1) {
        return fn_884F3A70((ts4_word)a0);
    }
    return fn_884F38B0((ts4_word)a0);
}

/* Swing_DLL.xex 0x884FB300: if_get u32@0x8, u32@0x114, fn_884FAAE0 */
ts4_word ts4_if_get_u32_off8_884FB300(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p3;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(((a1 + 9) << 2)) + a0);
    p3 = (ts4_word)t1;
    if ((ts4_word)a2 != (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(((a1 + 9) << 2)) + a0) = (ts4_word)a2;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 276) = (ts4_word)1;
        p3 = (ts4_word)1;
    }
    return fn_884FAAE0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)p3);
}

/* Swing_DLL.xex 0x884FD910: if_get u32@lbl_88D275C0, fn_884FD878 */
ts4_word ts4_if_get_u32_lbl_88D275C0_884FD910(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)lbl_88D275C0;
    if ((int)t1 != 0) {
        return a0;
    }
    return fn_884FD878((ts4_word)a0);
}

/* Swing_DLL.xex 0x88504760: get u32@0x0, u8@0x3, u32@0x0 */
void ts4_get_u32_off0_88504760(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    float t2;
    float t4;
    float t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
    t2 = *(float *)((char *)(ts4_word)(a1) + 8);
    *(float *)((char *)(ts4_word)(a2) + 28) = (t2 * (*(float *)((char *)(ts4_word)(a0) + 0)));
    *(unsigned char *)((char *)(ts4_word)(t1) + 3) = (unsigned char)14;
    t4 = *(float *)((char *)(ts4_word)(a0) + 8);
    *(float *)((char *)(ts4_word)(t1) + 32) = (t4 * (*(float *)((char *)(ts4_word)(a1) + 4)));
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(t1 + 64);
    t6 = *(float *)((char *)(ts4_word)(a0) + 12);
    *(float *)((char *)(ts4_word)(t1) + 36) = (t6 * (*(float *)((char *)(ts4_word)(a1) + 4)));
    *(float *)((char *)(ts4_word)(t1) + 40) = (*(float *)((char *)(ts4_word)(a0) + 4));
    *(float *)((char *)(ts4_word)(t1) + 44) = (*(float *)((char *)(ts4_word)(a0) + 16));
    *(float *)((char *)(ts4_word)(t1) + 48) = (*(float *)((char *)(ts4_word)(a0) + 20));
    return;
}

/* Swing_DLL.xex 0x88506170: get u32@0x0, u32@0x54, u32@0x50, u32@0x48, u8@0x3, u16@0x6 */
ts4_word ts4_get_u32_off0_88506170(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    *(volatile unsigned char *)((char *)(ts4_word)(t1) + 3) = (unsigned char)1;
    *(volatile unsigned short *)((char *)(ts4_word)(t1) + 6) = (unsigned short)t2;
    *(volatile unsigned short *)((char *)(ts4_word)(t1) + 4) = (unsigned short)t3;
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)t4;
    *(volatile unsigned char *)((char *)(ts4_word)(t1) + 1) = (unsigned char)a2;
    *(volatile ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(t1 + 16);
    return t4;
}

/* Swing_DLL.xex 0x885068A8: get u32@0x0, u32@0x54, u32@0x50, u32@0x48, u8@0x3, u16@0x6 */
ts4_word ts4_get_u32_off0_885068A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    *(volatile unsigned char *)((char *)(ts4_word)(t1) + 3) = (unsigned char)1;
    *(volatile unsigned short *)((char *)(ts4_word)(t1) + 6) = (unsigned short)t2;
    *(volatile unsigned short *)((char *)(ts4_word)(t1) + 4) = (unsigned short)t3;
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)a2;
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)t4;
    *(volatile unsigned char *)((char *)(ts4_word)(t1) + 1) = (unsigned char)a3;
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(t1 + 16);
    return t4;
}

/* Swing_DLL.xex 0x885068E8: get u32@0x0, u32@0x54, u32@0x50, u32@0x48, u8@0x3, u16@0x6 */
ts4_word ts4_get_u32_off0_885068E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    *(volatile unsigned char *)((char *)(ts4_word)(t1) + 3) = (unsigned char)1;
    *(volatile unsigned short *)((char *)(ts4_word)(t1) + 6) = (unsigned short)t2;
    *(volatile unsigned short *)((char *)(ts4_word)(t1) + 4) = (unsigned short)t3;
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)a2;
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)t4;
    *(volatile unsigned char *)((char *)(ts4_word)(t1) + 1) = (unsigned char)a3;
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(t1 + 16);
    return t4;
}

/* Swing_DLL.xex 0x88509C80: get u32@0x0, u8@0x3, u32@0x0 */
void ts4_get_u32_off0_88509C80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    float t2;
    float t4;
    float t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
    t2 = *(float *)((char *)(ts4_word)(a1) + 8);
    *(float *)((char *)(ts4_word)(a2) + 12) = (t2 * (*(float *)((char *)(ts4_word)(a0) + 0)));
    *(unsigned char *)((char *)(ts4_word)(t1) + 3) = (unsigned char)9;
    t4 = *(float *)((char *)(ts4_word)(a0) + 8);
    *(float *)((char *)(ts4_word)(t1) + 48) = (t4 * (*(float *)((char *)(ts4_word)(a1) + 4)));
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(t1 + 80);
    t6 = *(float *)((char *)(ts4_word)(a0) + 12);
    *(float *)((char *)(ts4_word)(t1) + 52) = (t6 * (*(float *)((char *)(ts4_word)(a1) + 4)));
    *(float *)((char *)(ts4_word)(t1) + 56) = (*(float *)((char *)(ts4_word)(a0) + 4));
    *(float *)((char *)(ts4_word)(t1) + 60) = (*(float *)((char *)(ts4_word)(a0) + 16));
    *(float *)((char *)(ts4_word)(t1) + 64) = (*(float *)((char *)(ts4_word)(a0) + 20));
    return;
}

/* Swing_DLL.xex 0x88516B60: get u8@0x3, u8@0x0, u8@0x0, u8@0x3, u8@0x1, u8@0x2 */
void ts4_get_u8_off3_88516B60(ts4_word a0)
{
    unsigned char t1;
    unsigned char t2;
    unsigned char t3;

    t1 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 3);
    t2 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)t1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 3) = (unsigned char)t2;
    t3 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1) = (unsigned char)(*(volatile unsigned char *)((char *)(ts4_word)(a0) + 2));
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 2) = (unsigned char)t3;
    return;
}

/* Swing_DLL.xex 0x88516B88: get u8@0x1, u8@0x0, u8@0x0, u8@0x1, u8@0x2, u8@0x3 */
void ts4_get_u8_off1_88516B88(ts4_word a0)
{
    unsigned char t1;
    unsigned char t2;
    unsigned char t3;
    unsigned char t5;

    t1 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1);
    t2 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)t1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1) = (unsigned char)t2;
    t3 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 2);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 2) = (unsigned char)(*(volatile unsigned char *)((char *)(ts4_word)(a0) + 3));
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 3) = (unsigned char)t3;
    t5 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 4);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)(*(volatile unsigned char *)((char *)(ts4_word)(a0) + 5));
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)t5;
    return;
}

/* Swing_DLL.xex 0x88516BC0: get u8@0x3, u8@0x0, u8@0x0, u8@0x3, u8@0x1, u8@0x2 */
void ts4_get_u8_off3_88516BC0(ts4_word a0)
{
    unsigned char t1;
    unsigned char t2;
    unsigned char t3;
    unsigned char t5;
    unsigned char t7;
    unsigned char t9;
    unsigned char t11;

    t1 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 3);
    t2 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)t1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 3) = (unsigned char)t2;
    t3 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1) = (unsigned char)(*(volatile unsigned char *)((char *)(ts4_word)(a0) + 2));
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 2) = (unsigned char)t3;
    t5 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 4);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)(*(volatile unsigned char *)((char *)(ts4_word)(a0) + 7));
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 7) = (unsigned char)t5;
    t7 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 5);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)(*(volatile unsigned char *)((char *)(ts4_word)(a0) + 6));
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 6) = (unsigned char)t7;
    t9 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 8);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)(*(volatile unsigned char *)((char *)(ts4_word)(a0) + 11));
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 11) = (unsigned char)t9;
    t11 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 9);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 9) = (unsigned char)(*(volatile unsigned char *)((char *)(ts4_word)(a0) + 10));
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 10) = (unsigned char)t11;
    return;
}

/* Swing_DLL.xex 0x88516DB8: get  */
void ts4_get_88516DB8(ts4_word a0, ts4_word a1)
{
    float t1;
    float t2;
    float t3;
    float t4;
    float t5;
    float t6;
    float t7;

    t1 = *(float *)((char *)(ts4_word)(a1) + 0);
    t2 = *(float *)((char *)(ts4_word)(a0) + 0);
    t3 = *(float *)((char *)(ts4_word)(a0) + 4);
    *(float *)((char *)(ts4_word)(a0) + 0) = (t2 - t1);
    t4 = *(float *)((char *)(ts4_word)(a1) + 4);
    t5 = *(float *)((char *)(ts4_word)(a0) + 8);
    *(float *)((char *)(ts4_word)(a0) + 4) = (t3 - t4);
    t6 = *(float *)((char *)(ts4_word)(a1) + 8);
    t7 = *(float *)((char *)(ts4_word)(a0) + 12);
    *(float *)((char *)(ts4_word)(a0) + 8) = (t5 - t6);
    *(float *)((char *)(ts4_word)(a0) + 12) = (t7 - (*(float *)((char *)(ts4_word)(a1) + 12)));
    return;
}

/* Swing_DLL.xex 0x88520B88: if_call_seq u32@0x28, u32@lbl_88CACF08, KeTlsGetValue, u32@0x20, fn_8841A590, u32@0x1c */
ts4_word ts4_if_call_seq_u32_off28_88520B88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p12;
    ts4_word p18;
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t9;
    ts4_word t11;
    ts4_word t13;
    ts4_word t15;
    ts4_word t17;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    p6 = (ts4_word)a0;
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t5 = fn_8841A590((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)), (ts4_word)(t1 << 2), (ts4_word)23);
        p6 = (ts4_word)t5;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p12 = (ts4_word)p6;
    if ((int)(t7 & 0x80000000) == 0) {
        t9 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t11 = fn_8841A590((ts4_word)t9, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)(t7 << 2), (ts4_word)23);
        p12 = (ts4_word)t11;
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p18 = (ts4_word)p12;
    if ((int)(t13 & 0x80000000) == 0) {
        t15 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t17 = fn_8841A590((ts4_word)t15, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)(t13 << 2), (ts4_word)23);
        p18 = (ts4_word)t17;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p18;
}

/* Swing_DLL.xex 0x88520EF0: tailcall fn_8852C9F0 */
ts4_word ts4_tailcall_fn_8852C9F0_88520EF0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    return fn_8852C9F0((ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88520F90: if_get u32@0x0, u32@0xc, u32@0x34 */
ts4_word ts4_if_get_u32_off0_88520F90(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
    if ((int)t2 != 11) {
        return 0;
    }
    return (*(ts4_word *)((char *)(ts4_word)(t1) + 52));
}

/* Swing_DLL.xex 0x88521680: tailcall fn_8852DD38 */
ts4_word ts4_tailcall_fn_8852DD38_88521680(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    (void)a0;
    (void)a2;
    (void)a3;
    return fn_8852DD38((ts4_word)a1, (ts4_word)a4);
}

/* Swing_DLL.xex 0x885216F0: tailcall fn_8852C9F0 */
ts4_word ts4_tailcall_fn_8852C9F0_885216F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    return fn_8852C9F0((ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88521A98: if_get u8@0xb, u32@0x0, lbl_8808E0C8, u32@0x10, vcall, fn_8852E0C0 */
ts4_word ts4_if_get_u8_offb_88521A98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p9;
    unsigned char t1;
    ts4_word t8;

    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 11);
    p9 = (ts4_word)a0;
    if ((ts4_word)(t1 & 0x20) == 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 0))) + 16))))((ts4_word)a3, (ts4_word)(ts4_word)lbl_8808E0C8);
        fn_8852E0C0((ts4_word)(a1 + 16), (ts4_word)a2, (ts4_word)a3);
        t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 0))) + 20))))((ts4_word)a3);
        p9 = (ts4_word)t8;
    }
    return p9;
}

/* Swing_DLL.xex 0x88521B08: if_get u8@0xb, fn_8852C9F0 */
ts4_word ts4_if_get_u8_offb_88521B08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 11);
    if ((ts4_word)(t1 & 0x20) != 0) {
        return a0;
    }
    return fn_8852C9F0((ts4_word)(a1 + 16), (ts4_word)a2, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)(t1 & 0x20), (ts4_word)t1);
}

/* Swing_DLL.xex 0x88521B30: if_get u8@0xb, fn_8852CB30 */
ts4_word ts4_if_get_u8_offb_88521B30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    unsigned char t1;

    (void)a3;
    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 11);
    if ((ts4_word)(t1 & 0x20) != 0) {
        return a0;
    }
    return fn_8852CB30((ts4_word)(a1 + 16), (ts4_word)a1, (ts4_word)a2, (ts4_word)a4, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(t1 & 0x20));
}

/* Swing_DLL.xex 0x88521B50: call_seq ts4_if_call_seq_u32_off4_88524080, u8@0xb, u8@0xb */
ts4_word ts4_call_seq_fn_88524080_88521B50(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = ts4_if_call_seq_u32_off4_88524080((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    *(unsigned char *)((char *)(ts4_word)(a2) + 11) = (unsigned char)((((*(unsigned char *)((char *)(ts4_word)(a2) + 11)) & 0xff) & 0xffffff9f) | 32);
    return t1;
}

/* Swing_DLL.xex 0x88521B90: if_get u8@0xb, fn_8852DD38, ts4_call_seq_fn_88531FF8_88524038 */
ts4_word ts4_if_get_u8_offb_88521B90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 11);
    if ((ts4_word)(t1 & 0x20) != 0) {
        return ts4_call_seq_fn_88531FF8_88524038((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)(t1 & 0x20), (ts4_word)t1);
    }
    return fn_8852DD38((ts4_word)(a1 + 16), (ts4_word)a4, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)(t1 & 0x20), (ts4_word)t1);
}

/* Swing_DLL.xex 0x88521BC0: if_get u8@0xb, fn_88523EE8 */
ts4_word ts4_if_get_u8_offb_88521BC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 11);
    if ((ts4_word)(t1 & 0x20) == 0) {
        return a0;
    }
    return fn_88523EE8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(t1 & 0x20));
}

/* Swing_DLL.xex 0x88521BD8: if_get u8@0xb, fn_88523F28 */
ts4_word ts4_if_get_u8_offb_88521BD8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 11);
    if ((ts4_word)(t1 & 0x20) == 0) {
        return a0;
    }
    return fn_88523F28((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(t1 & 0x20));
}

/* Swing_DLL.xex 0x88521BF0: if_get u8@0xb, fn_88523F70 */
ts4_word ts4_if_get_u8_offb_88521BF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 11);
    if ((ts4_word)(t1 & 0x20) == 0) {
        return a0;
    }
    return fn_88523F70((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(t1 & 0x20));
}

/* Swing_DLL.xex 0x88521C08: if_get u8@0xb, u32@0x0, u32@0x0, u32@0x14, vcall, ts4_addr_fn_8852DA00_8852DB68 */
ts4_word ts4_if_get_u8_offb_88521C08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p7;
    ts4_word loc50[7];
    unsigned char t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;

    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 11);
    p7 = (ts4_word)a0;
    if ((ts4_word)(t1 & 0x20) == 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
        t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 20))))((ts4_word)t2);
        loc50[3] = (ts4_word)t5;
        loc50[0] = (ts4_word)a2;
        loc50[1] = (ts4_word)a3;
        loc50[4] = (ts4_word)a4;
        loc50[5] = (ts4_word)a5;
        loc50[6] = (ts4_word)a6;
        t6 = ts4_addr_fn_8852DA00_8852DB68((ts4_word)(a1 + 16), (ts4_word)(ts4_word)&loc50[0]);
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Swing_DLL.xex 0x88522F98: call_seq fn_88531FF8, u8@0x2, u8@0x2 */
ts4_word ts4_call_seq_fn_88531FF8_88522F98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    t1 = fn_88531FF8((ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
    *(unsigned char *)((char *)(ts4_word)(a1) + 2) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 2));
    return t1;
}

/* Swing_DLL.xex 0x88523218: if_call_seq ts4_if_call_seq_u32_off4_88524080, u8@0xb, u8@0xb, u32@0x0, u32@0x0, u32@0xc */
ts4_word ts4_if_call_seq_fn_88524080_88523218(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    unsigned char t2;
    int t5;
    int t10;

    t1 = ts4_if_call_seq_u32_off4_88524080((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    t2 = *(unsigned char *)((char *)(ts4_word)(a2) + 11);
    *(unsigned char *)((char *)(ts4_word)(a2) + 11) = (unsigned char)(t2 & 0xfffffff0);
    t5 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))) + 12);
    if ((int)t5 == 3) {
        *(unsigned char *)((char *)(ts4_word)(a2) + 11) = (unsigned char)(((t2 & 0xfffffff0) & 0xff) | 5);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0))) + 12);
    if ((int)t10 == 3) {
        *(unsigned char *)((char *)(ts4_word)(a2) + 11) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(a2) + 11)) | 10);
    }
    return t1;
}

/* Swing_DLL.xex 0x885248A0: tailcall fn_8852C9F0 */
ts4_word ts4_tailcall_fn_8852C9F0_885248A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    return fn_8852C9F0((ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88528510: call_seq fn_88553880, u8@0x0 */
ts4_word ts4_call_seq_fn_88553880_88528510(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc60[22];
    ts4_word loc50[4];
    ts4_word t1;

    t1 = fn_88553880((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0], (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    return ((*(unsigned char *)((char *)(ts4_word)(t1) + 0)) != 0);
}

/* Swing_DLL.xex 0x88528558: call_seq fn_885542E8 */
ts4_word ts4_call_seq_fn_885542E8_88528558(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[10];
    ts4_word t1;

    t1 = fn_885542E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return t1;
}

/* Swing_DLL.xex 0x88528588: call_seq ts4_set_u32_off34_885555D8, fn_88555668, fn_88555608 */
ts4_word ts4_call_seq_fn_885555D8_88528588(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[52];
    ts4_word t3;

    ts4_set_u32_off34_885555D8((ts4_word)(ts4_word)&loc50[0]);
    fn_88555668((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    t3 = fn_88555608((ts4_word)(ts4_word)&loc50[0]);
    return t3;
}

/* Swing_DLL.xex 0x885285D0: call_seq u32@0x20, fn_88555748 */
ts4_word ts4_call_seq_u32_off20_885285D0(ts4_word a0, ts4_word a1)
{
    ts4_word loc60[6];
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;

    loc60[0] = (ts4_word)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    t2 = fn_88555748((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)t1);
    return t2;
}

/* Swing_DLL.xex 0x88528610: call_seq fn_88526E08 */
ts4_word ts4_call_seq_fn_88526E08_88528610(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[18];
    ts4_word t1;

    (void)a3;
    t1 = fn_88526E08((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4, (ts4_word)a4);
    return t1;
}

/* Swing_DLL.xex 0x88528648: call_seq fn_88527018 */
ts4_word ts4_call_seq_fn_88527018_88528648(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[18];
    ts4_word t1;

    t1 = fn_88527018((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return t1;
}

/* Swing_DLL.xex 0x88528678: call_seq fn_88557200 */
ts4_word ts4_call_seq_fn_88557200_88528678(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[22];
    ts4_word t1;

    t1 = fn_88557200((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return t1;
}

/* Swing_DLL.xex 0x8852E350: get u32@0x0, u32@0x14, vcall, u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off0_8852E350(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t3;

    (void)a2;
    t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 20))))((ts4_word)a1, (ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t3;
    *(volatile ts4_word *)((char *)(ts4_word)(a3) + 4) = (ts4_word)a0;
    return t3;
}

/* Swing_DLL.xex 0x8853A030: addr lbl_8808E4F0 */
ts4_word ts4_addr_lbl_8808E4F0_8853A030(ts4_word a0)
{
    return ((((a0 << 31) | (a0 >> 1)) & 0x70) + (ts4_word)lbl_8808E4F0);
}

/* Swing_DLL.xex 0x88545B60: if_call_seq u32@0x8, u32@0x4, fn_8841C678, u32@0x4, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off8_88545B60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p4;
    ts4_word t1;
    int t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;

    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    p4 = (ts4_word)a0;
    if ((int)t2 == (int)(t1 & 0x3fffffff)) {
        t3 = fn_8841C678((ts4_word)a2, (ts4_word)8);
        p4 = (ts4_word)t3;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    t6 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)(t5 + 1);
    *(ts4_word *)((char *)(ts4_word)((t5 << 3)) + t6) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12));
    *(ts4_word *)((char *)(ts4_word)(((t5 << 3) + t6)) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    return p4;
}

/* Swing_DLL.xex 0x88545BC8: if_call_seq u32@0x8, u32@0x4, fn_8841C678, u32@0x4, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off8_88545BC8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p4;
    ts4_word t1;
    int t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;

    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    p4 = (ts4_word)a0;
    if ((int)t2 == (int)(t1 & 0x3fffffff)) {
        t3 = fn_8841C678((ts4_word)a2, (ts4_word)8);
        p4 = (ts4_word)t3;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    t6 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)(t5 + 1);
    *(ts4_word *)((char *)(ts4_word)((t5 << 3)) + t6) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12));
    *(ts4_word *)((char *)(ts4_word)(((t5 << 3) + t6)) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    return p4;
}

/* Swing_DLL.xex 0x8854D7C8: get u32@0x10, u16@0x4, u16@0x6, u32@0x4c, u32@0x14, u32@0x4c */
void ts4_get_u32_off10_8854D7C8(ts4_word a0)
{
    ts4_word t1;
    unsigned short t2;
    unsigned short t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(unsigned short *)((char *)(ts4_word)(a0) + 4);
    t3 = *(unsigned short *)((char *)(ts4_word)(a0) + 6);
    *(ts4_word *)((char *)(ts4_word)(((t2 << 3) | (t2 >> 29))) + (*(ts4_word *)((char *)(ts4_word)(t1) + 76))) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 76))) + ((t3 << 3) | (t3 >> 29))) = (ts4_word)a0;
    return;
}

/* Swing_DLL.xex 0x88554448: get  */
float ts4_get_88554448(ts4_word a0, ts4_word a1, float f1)
{
    float t1;

    t1 = *(float *)((char *)(ts4_word)(((a1 << 3) + a0)) + 4);
    *(float *)((char *)(ts4_word)(((a1 << 3) + a0)) + 4) = f1;
    return t1;
}

/* Swing_DLL.xex 0x8855A250: if_get  */
float ts4_if_get_8855A250(float f1, float f2)
{
    float t1;

    t1 = *(float *)lbl_88001A20;
    if (f1 < t1) {
        return ((*(float *)lbl_88002388) - f2);
    }
    if (f2 > t1) {
        return f2;
    }
    return ((*(float *)lbl_88001B0C) - f2);
}

/* Swing_DLL.xex 0x8855AA30: if_get u8@0x0 */
void ts4_if_get_u8_off0_8855AA30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p3;
    float t1;
    float t2;

    t1 = *(float *)((char *)(ts4_word)(a1) + 4);
    t2 = *(float *)((char *)(ts4_word)(a2) + 4);
    p3 = (ts4_word)1;
    if (!(t1 < t2)) {
        p3 = (ts4_word)0;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)p3;
    return;
}

/* Swing_DLL.xex 0x8855AA50: if_get u8@0x0 */
void ts4_if_get_u8_off0_8855AA50(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p3;
    float t1;
    float t2;

    t1 = *(float *)((char *)(ts4_word)(a1) + 16);
    t2 = *(float *)((char *)(ts4_word)(a2) + 16);
    p3 = (ts4_word)1;
    if (!(t1 < t2)) {
        p3 = (ts4_word)0;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)p3;
    return;
}

/* Swing_DLL.xex 0x88567730: if_fn  */
ts4_word ts4_if_fn_88567730(int a0)
{
    if ((int)a0 < 65) {
        return a0;
    }
    if ((int)a0 > 90) {
        return a0;
    }
    return (a0 + 32);
}

/* Swing_DLL.xex 0x885677C0: if_fn  */
ts4_word ts4_if_fn_885677C0(ts4_word a0)
{
    ts4_word p1;

    if ((ts4_word)(a0 & 0xffff) == 65535) {
        return a0;
    }
    p1 = (ts4_word)(a0 & 0xffff);
    if ((ts4_word)(a0 & 0xffff) >= 65 && (ts4_word)(a0 & 0xffff) <= 90) {
        p1 = (ts4_word)((a0 & 0xffff) + 32);
    }
    return (p1 & 0xffff);
}

/* Swing_DLL.xex 0x885677E8: if_fn  */
ts4_word ts4_if_fn_885677E8(ts4_word a0)
{
    ts4_word p1;

    if ((ts4_word)(a0 & 0xffff) == 65535) {
        return a0;
    }
    p1 = (ts4_word)(a0 & 0xffff);
    if ((ts4_word)(a0 & 0xffff) >= 97 && (ts4_word)(a0 & 0xffff) <= 122) {
        p1 = (ts4_word)((a0 & 0xffff) + -32);
    }
    return (p1 & 0xffff);
}

/* Swing_DLL.xex 0x88567E00: if_addr lbl_88C30DA8, RtlLeaveCriticalSection, u32@0xc, u32@0xc, ts4_addr_lbl_88C31510_8856F558 */
ts4_word ts4_if_addr_lbl_88C30DA8_88567E00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    if ((ts4_word)a0 >= (ts4_word)(ts4_word)lbl_88C30DA8 && (ts4_word)a0 <= (ts4_word)((ts4_word)lbl_88C30DA8 + 608)) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t1 & 0xffff7fff);
        return ts4_addr_lbl_88C31510_8856F558((ts4_word)(((int)(a0 - (ts4_word)lbl_88C30DA8) >> 5) + 16), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(t1 & 0xffff7fff));
    }
    return RtlLeaveCriticalSection((ts4_word)(a0 + 32));
}

/* Swing_DLL.xex 0x8856D290: if_tailcall fn_8856D0A8 */
ts4_word ts4_if_tailcall_fn_8856D0A8_8856D290(ts4_word a0)
{
    if ((ts4_word)a0 == (ts4_word)((3765239808) | 29539)) {
        return fn_8856D0A8((ts4_word)((3765239808) | 29539));
    }
    return 0;
}

/* Swing_DLL.xex 0x88576848: if_get  */
ts4_word ts4_if_get_88576848(ts4_word a0)
{
    double t1;
    double t2;

    t1 = *(double *)((char *)(ts4_word)(a0) + 0);
    t2 = *(double *)lbl_880038D8;
    if (!(t1 < t2)) {
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x885773E0: if_tail fn_88576B30, fn_88576C20, fn_885772B0, fn_885771E0 */
ts4_word ts4_if_tail_fn_88576B30_885773E0(ts4_word a0, ts4_word a1, ts4_word a2, int a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    if ((int)a3 != 101 && (int)a3 != 69) {
        if ((int)a3 == 102) {
            return fn_885771E0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4, (ts4_word)a6, (ts4_word)a6);
        }
        if ((int)a3 != 97 && (int)a3 != 65) {
            return fn_885772B0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
        }
        return fn_88576C20((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
    }
    return fn_88576B30((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
}

/* Swing_DLL.xex 0x88577430: if_tail fn_88576B30, fn_88576C20, fn_885772B0, fn_885771E0 */
ts4_word ts4_if_tail_fn_88576B30_88577430(ts4_word a0, ts4_word a1, ts4_word a2, int a3, ts4_word a4, ts4_word a5)
{
    if ((int)a3 != 101 && (int)a3 != 69) {
        if ((int)a3 == 102) {
            return fn_885771E0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4, (ts4_word)0, (ts4_word)a5);
        }
        if ((int)a3 != 97 && (int)a3 != 65) {
            return fn_885772B0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4, (ts4_word)a5, (ts4_word)0);
        }
        return fn_88576C20((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4, (ts4_word)a5, (ts4_word)0);
    }
    return fn_88576B30((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4, (ts4_word)a5, (ts4_word)0);
}

/* Swing_DLL.xex 0x885776B8: if_tailcall fn_8856CF60 */
ts4_word ts4_if_tailcall_fn_8856CF60_885776B8(int a0)
{
    if ((int)a0 != 0) {
        return a0;
    }
    return fn_8856CF60((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857B148: if_tailcall MmSetAddressProtect */
ts4_word ts4_if_tailcall_MmSetAddressProtect_8857B148(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return a0;
    }
    return MmSetAddressProtect((ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8857CA80: if_call_seq u32@0x0, NtWriteFile, u32@0x0, NtWaitForSingleObjectEx */
ts4_word ts4_if_call_seq_u32_off0_8857CA80(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    int t2;

    loc50[1] = (ts4_word)(a2 << 12);
    loc50[0] = (ts4_word)0;
    t2 = NtWriteFile((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)4096, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t2 == 259) {
        NtWaitForSingleObjectEx((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)1, (ts4_word)0, (ts4_word)0);
    }
    return 0;
}

/* Swing_DLL.xex 0x8857CD70: call_seq lbl_88D2ECB8, RtlEnterCriticalSection, u32@0xd0, u32@0xd0, RtlLeaveCriticalSection, u32@0x34 */
ts4_word ts4_call_seq_lbl_88D2ECB8_8857CD70(ts4_word a0)
{
    ts4_word t5;

    RtlEnterCriticalSection((ts4_word)((ts4_word)lbl_88D2ECB8 + 16));
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2ECB8) + 208) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2ECB8) + 208)) | a0);
    RtlLeaveCriticalSection((ts4_word)((ts4_word)lbl_88D2ECB8 + 16));
    t5 = fn_8857C1F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2ECB8) + 52)));
    return t5;
}

/* Swing_DLL.xex 0x88582420: if_get u32@__imp_KeDebugMonitorData, u32@0x0, u32@0x18 */
ts4_word ts4_if_get_u32__imp_KeDebugMonitorData_88582420(void)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeDebugMonitorData)) + 0);
    if ((ts4_word)t2 != 0) {
        return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 24))))((ts4_word)68, (ts4_word)0);
    }
    return 0;
}

/* Swing_DLL.xex 0x885846C0: if_get u32@0x0, u32@0x4, RtlNtStatusToDosError, vcall */
ts4_word ts4_if_get_u32_off0_885846C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p4;
    ts4_word p5;
    ts4_word t1;
    ts4_word t3;
    ts4_word t2;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)(t1 & 0xc0000000) == (ts4_word)(3221225472)) {
        t3 = RtlNtStatusToDosError((ts4_word)t1);
        p4 = (ts4_word)t3;
        p5 = (ts4_word)0;
    } else {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        p4 = (ts4_word)0;
        p5 = (ts4_word)t2;
    }
    t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(a0))((ts4_word)p4, (ts4_word)p5, (ts4_word)a1);
    return t6;
}

/* Swing_DLL.xex 0x8858E5C8: call_seq u32@0x868, fn_88590818, fn_88590818, fn_88590818 */
ts4_word ts4_call_seq_u32_off868_8858E5C8(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    fn_88590818((ts4_word)a0, (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 2152)) + 32) << 3), (ts4_word)(a0 + 10472), (ts4_word)(a0 + 9520), (ts4_word)(a0 + 13272), (ts4_word)a1);
    fn_88590818((ts4_word)a0, (ts4_word)249, (ts4_word)(a0 + 15374), (ts4_word)(a0 + 10221), (ts4_word)(a0 + 16370), (ts4_word)a1);
    t4 = fn_88590818((ts4_word)a0, (ts4_word)8, (ts4_word)(a0 + 17118), (ts4_word)(a0 + 17166), (ts4_word)(a0 + 17150), (ts4_word)1);
    return t4;
}

/* Swing_DLL.xex 0x8858E698: call_seq fn_8858E2E8, u32@0x868, fn_8858E2E8, fn_8858E2E8 */
ts4_word ts4_call_seq_fn_8858E2E8_8858E698(ts4_word a0)
{
    ts4_word t4;

    fn_8858E2E8((ts4_word)a0, (ts4_word)(a0 + 9520), (ts4_word)(a0 + 14672), (ts4_word)256);
    fn_8858E2E8((ts4_word)a0, (ts4_word)(a0 + 9776), (ts4_word)(a0 + 14928), (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 2152)) << 3));
    t4 = fn_8858E2E8((ts4_word)a0, (ts4_word)(a0 + 10221), (ts4_word)(a0 + 16868), (ts4_word)249);
    return t4;
}

/* Swing_DLL.xex 0x8858F028: if_get u32@0x860, ts4_forward_if_small_kind_8858CE08, u32@0x854, u32@0x858, u32@0x4340, u32@0x860 */
ts4_word ts4_if_get_u32_off860_8858F028(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word p10;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 2144);
    p10 = (ts4_word)a0;
    if ((ts4_word)t1 > 0) {
        t2 = ts4_forward_if_small_kind_8858CE08((ts4_word)a0);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 2132);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 2136);
        p9 = (ts4_word)t2;
        if ((int)(t4 - t3) > 0) {
            t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 17216);
            t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 2144);
            t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))(t5))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 17200)), (ts4_word)t3, (ts4_word)(t4 - t3), (ts4_word)t6);
            p9 = (ts4_word)t8;
        }
        p10 = (ts4_word)p9;
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 2132);
    *(ts4_word *)((char *)(ts4_word)(a0) + 2144) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)32;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 2136) = (ts4_word)t11;
    return p10;
}

/* Swing_DLL.xex 0x8858FEC8: call_seq memset, memset, fn_8858FD68 */
ts4_word ts4_call_seq_fn_8856ABA0_8858FEC8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t3;

    memset((ts4_word)(a0 + 10472), (ts4_word)0, (ts4_word)2800);
    memset((ts4_word)(a0 + 15374), (ts4_word)0, (ts4_word)996);
    t3 = fn_8858FD68((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    return t3;
}

/* Swing_DLL.xex 0x88592F38: get u32@0x8, u32@0x8, u32@0x4, u32@0x8, u32@0x4 */
ts4_word ts4_get_u32_off8_88592F38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)((((a1 + (a1 << 1)) << 5) + t1)) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)((((a1 + (a1 << 1)) << 5) + t1)) + 4);
    *(ts4_word *)((char *)(ts4_word)((((a1 + (a1 << 1)) << 5) + t1)) + 8) = (ts4_word)((t2 & 0xfc000000) | (a2 & 0x3ffffff));
    *(ts4_word *)((char *)(ts4_word)((((a1 + (a1 << 1)) << 5) + t1)) + 4) = (ts4_word)((((a3 << 24) | (a3 >> 8)) & 0x7000000) | (t3 & 0xf8ffffff));
    return 0;
}

/* Swing_DLL.xex 0x88592F70: if_call_seq fn_88592800, u32@0x4, lbl_88D2F124, ts4_forward_shifted_args_885933B0 */
ts4_word ts4_if_call_seq_fn_88592800_88592F70(ts4_word a0)
{
    ts4_word t2;

    fn_88592800();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)(t2 & 0x2) == 0) {
        ts4_forward_shifted_args_885933B0((ts4_word)(ts4_word)lbl_88D2F124, (ts4_word)a0, (ts4_word)((2810314752) | 7));
    }
    return 0;
}

/* Swing_DLL.xex 0x88593CE8: if_call_seq u32@0x20, lbl_88091790, u32@0x0, RtlEnterCriticalSection, RtlLeaveCriticalSection */
ts4_word ts4_if_call_seq_u32_off20_88593CE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p4;
    int t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88091790;
    p4 = (ts4_word)a0;
    if ((int)t1 != 0) {
        RtlEnterCriticalSection((ts4_word)(a0 + 4), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t1);
        t3 = RtlLeaveCriticalSection((ts4_word)(a0 + 4));
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x8859C120: if_call_seq u32@0x25c, u32@0x288, fn_8859D5A8, ts4_if_call_seq_fn_88599808_88599C78, u32@0x260, u32@0x288 */
ts4_word ts4_if_call_seq_u32_off25c_8859C120(ts4_word a0)
{
    ts4_word p7;
    ts4_word p13;
    ts4_word p14;
    int t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t10;
    ts4_word t12;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 604);
    if ((int)t1 != 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 648);
        if ((ts4_word)t5 != 0) {
            p7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 0));
        } else {
            p7 = (ts4_word)0;
        }
        t8 = *(ts4_word *)((char *)(ts4_word)(p7) + 20);
        if ((ts4_word)t8 != 255) {
            *(volatile ts4_word *)((char *)(ts4_word)(p7) + 20) = (ts4_word)(t8 + -1);
        }
        t10 = *(ts4_word *)((char *)(ts4_word)(p7) + 0);
        t12 = ts4_member_vcall_88598D70((ts4_word)(a0 + 140), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(p7) + 24)), (ts4_word)t10);
        p13 = (ts4_word)t12;
        p14 = (ts4_word)0;
    } else {
        t3 = fn_8859D5A8((ts4_word)(a0 + 624));
        t4 = ts4_if_call_seq_fn_88599808_88599C78((ts4_word)(a0 + 664), (ts4_word)t3);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 608) = (ts4_word)0;
        p13 = (ts4_word)t4;
        p14 = (ts4_word)0;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 452) = (ts4_word)p14;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 456) = (ts4_word)p14;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 464) = (ts4_word)p14;
    return p13;
}

/* Swing_DLL.xex 0x8859F280: if_call_seq u16@0x0, u32@0x0, u16@0x10, u32@0x0, u16@0x0, u16@0x10 */
ts4_word ts4_if_call_seq_u16_off0_8859F280(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word p5;
    ts4_word p9;
    ts4_word p11;
    unsigned short t1;
    ts4_word t2;
    unsigned short t6;
    ts4_word t13;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    if ((ts4_word)t1 == 357) {
        p5 = (ts4_word)32;
    } else {
        if ((ts4_word)t1 == 1) {
            p4 = (ts4_word)18;
        } else {
            p4 = (ts4_word)((*(unsigned short *)((char *)(ts4_word)(a0) + 16)) + 18);
        }
        p5 = (ts4_word)p4;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)p5;
    t6 = *(unsigned short *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t6 == 357) {
        p11 = (ts4_word)32;
    } else {
        if ((ts4_word)t6 == 1) {
            p9 = (ts4_word)16;
        } else {
            p9 = (ts4_word)((*(unsigned short *)((char *)(ts4_word)(a0) + 16)) + 18);
        }
        p11 = (ts4_word)p9;
    }
    memcpy((ts4_word)a1, (ts4_word)a0, (ts4_word)p11);
    t13 = memset((ts4_word)(p11 + a1), (ts4_word)0, (ts4_word)(t2 - p11));
    return t13;
}

/* Swing_DLL.xex 0x885AC5B8: if_get u32@0x0, u32@0x3c, u32@0xd4, u32@0x25c, u32@0x8, u32@0x25c */
ts4_word ts4_if_get_u32_off0_885AC5B8(ts4_word a0)
{
    ts4_word t1;
    int t2;
    int t8;
    int t6;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 60);
    if ((int)t2 <= 2) {
        t8 = *(ts4_word *)((char *)(ts4_word)(t1) + 212);
        if ((int)t8 != 0) {
            return (((*(ts4_word *)((char *)(ts4_word)(t1) + 8)) + 11) & 0xff);
        }
        return 0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 604);
    t7 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
    if ((int)t6 != 0) {
        return ((t7 + 17) & 0xff);
    }
    return ((t7 + 6) & 0xff);
}

/* Swing_DLL.xex 0x885AC910: if_call_seq fn_885AC6C8, memset, u32@0x14, u32@0xc, u32@0x20, u32@0x24 */
ts4_word ts4_if_call_seq_fn_885AC6C8_885AC910(ts4_word a0)
{
    int t1;

    t1 = fn_885AC6C8();
    if ((int)t1 >= 0) {
        memset((ts4_word)a0, (ts4_word)0, (ts4_word)720);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)2;
        *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 216) = (ts4_word)1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 164) = (ts4_word)2;
        *(ts4_word *)((char *)(ts4_word)(a0) + 692) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 696) = (ts4_word)1;
    }
    return t1;
}

/* Swing_DLL.xex 0x885AF4F0: if_get u32@0x0, u32@0x3c, u32@0x200, u32@0x38, u32@0x38 */
ts4_word ts4_if_get_u32_off0_885AF4F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    int t2;
    ts4_word t3;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 60);
    if ((int)t2 <= 2) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
        return a0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 512);
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)4;
    if ((ts4_word)t3 == 0) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(t3))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)4);
}

/* Swing_DLL.xex 0x885B5880: if_call_seq RtlEnterCriticalSection, u32@0xc, u32@0x18, KeSetEvent, u32@0xc, ts4_tailcall_fn_88582F30_8857A128 */
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_885B5880(ts4_word a0)
{
    ts4_word t2;
    ts4_word t7;
    ts4_word t11;

    RtlEnterCriticalSection((ts4_word)(a0 + 36));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t2 != 0) {
        KeSetEvent((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)1, (ts4_word)0);
        ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)-1);
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        if ((ts4_word)t7 != 0 && (int)t7 != -1) {
            ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)t7);
            *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
        }
    }
    t11 = RtlLeaveCriticalSection((ts4_word)(a0 + 36));
    return t11;
}

/* Swing_DLL.xex 0x885B7DA8: if_get u32@0x0, u32@0x14, u32@0x2c, u32@0x30, u32@0x34 */
ts4_word ts4_if_get_u32_off0_885B7DA8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a2;
    if ((ts4_word)a1 >= 1) {
        if ((ts4_word)a1 != 1) {
            return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 52))))((ts4_word)a0);
        }
        return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 48))))((ts4_word)a0);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 44))))((ts4_word)a0);
}

/* Swing_DLL.xex 0x885BF698: if_get u32@0x1bc, u32@0x1c0, u32@0x1c0, u32@0xfc, u32@0x100, u32@0x10c */
void ts4_if_get_u32_off1bc_885BF698(ts4_word a0, ts4_word a1)
{
    ts4_word p15;
    int t1;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    int t14;
    int t3;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 444);
    if ((int)t1 != 0) {
        t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 456);
        t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 252);
        t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 256);
        t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 268);
        *(ts4_word *)((char *)(ts4_word)(a0) + 464) = (ts4_word)((int)t12 >> t11);
        *(ts4_word *)((char *)(ts4_word)(a0) + 468) = (ts4_word)((int)t13 >> t11);
        p15 = (ts4_word)((short)a1);
        if ((int)t14 < (int)((short)a1)) {
            p15 = (ts4_word)t14;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 472) = (ts4_word)p15;
        return;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 448);
    if ((int)t3 != 0) {
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 456);
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 252);
        t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 256);
        t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 268);
        *(ts4_word *)((char *)(ts4_word)(a0) + 464) = (ts4_word)(t8 << t7);
        *(ts4_word *)((char *)(ts4_word)(a0) + 468) = (ts4_word)(t9 << t7);
        *(ts4_word *)((char *)(ts4_word)(a0) + 472) = (ts4_word)t10;
        return;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 252);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 256);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 268);
    *(ts4_word *)((char *)(ts4_word)(a0) + 464) = (ts4_word)t4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 468) = (ts4_word)t5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 472) = (ts4_word)t6;
    return;
}

/* Swing_DLL.xex 0x885BFD68: get u8@0x2, u16@0x0 */
ts4_word ts4_get_u8_off2_885BFD68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    unsigned char t1;

    (void)a1;
    (void)a2;
    t1 = *(unsigned char *)((char *)(ts4_word)(((a3 + (a3 << 1)) + a0)) + 2);
    return ((int)((((signed char)t1) << 16) | (*(unsigned short *)((char *)(ts4_word)(((a3 + (a3 << 1)) + a0)) + 0))) >> 4);
}

/* Swing_DLL.xex 0x885BFDE8: set  */
void ts4_set_885BFDE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a2;
    *(unsigned short *)((char *)(ts4_word)((a3 << 1)) + a1) = (unsigned short)a0;
    return;
}

/* Swing_DLL.xex 0x885C0F08: if_call_seq ts4_free_buffers_885D90C8, ts4_if_call_seq_u32_off8_885D9518, ts4_if_call_seq_u32_off8_885D9518, ts4_if_call_seq_u32_off8_885D9518, ts4_if_call_seq_u32_off8_885D9518, u32@0x94 */
ts4_word ts4_if_call_seq_fn_885D90C8_885C0F08(ts4_word a0)
{
    ts4_word t6;
    ts4_word t9;
    ts4_word t17;

    ts4_free_buffers_885D90C8((ts4_word)a0);
    ts4_if_call_seq_u32_off8_885D9518((ts4_word)(a0 + 24));
    ts4_if_call_seq_u32_off8_885D9518((ts4_word)(a0 + 44));
    ts4_if_call_seq_u32_off8_885D9518((ts4_word)(a0 + 64));
    ts4_if_call_seq_u32_off8_885D9518((ts4_word)(a0 + 84));
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 148);
    if ((ts4_word)t6 != 0) {
        ts4_forward_with_const_248C8000_885BE200((ts4_word)t6);
        *(ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)0;
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 160);
    if ((ts4_word)t9 != 0) {
        ts4_forward_with_const_248C8000_885BE200((ts4_word)t9);
        *(ts4_word *)((char *)(ts4_word)(a0) + 160) = (ts4_word)0;
    }
    memset((ts4_word)a0, (ts4_word)0, (ts4_word)168);
    fn_885D90A8((ts4_word)a0);
    ts4_zero_five_words_885D94F8((ts4_word)(a0 + 24));
    ts4_zero_five_words_885D94F8((ts4_word)(a0 + 44));
    ts4_zero_five_words_885D94F8((ts4_word)(a0 + 64));
    t17 = ts4_zero_five_words_885D94F8((ts4_word)(a0 + 84));
    return t17;
}

/* Swing_DLL.xex 0x885C2CF0: if_get u32@0x8, u32@0x24, u32@0x28, u32@0x2c, u32@0x30, u32@0x20 */
void ts4_if_get_u32_off8_885C2CF0(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 704);
    if ((int)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)(ts4_word)ts4_noop_881B3360;
    return;
}

/* Swing_DLL.xex 0x885C3098: if_get u32@0x4c, u32@0x8, u32@0x2c0, u32@0x8, u32@0x2c0, u32@0x1c */
ts4_word ts4_if_get_u32_off4c_885C3098(ts4_word a0)
{
    int t1;
    int t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((int)t1 != 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 704);
        if ((int)t5 == 0 || (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 28))) >= (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 20)))) {
            return 1;
        }
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x885C32B8: if_set u32@0x8, u32@0x0, u32@0x4, u32@0xc, u32@0x10, u32@0x14 */
void ts4_if_set_u32_off8_885C32B8(ts4_word a0, ts4_word a1)
{
    int t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)15;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 212));
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 704);
    if ((int)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)(ts4_word)ts4_noop_881B3360;
    return;
}
