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

extern char fn_885BDBD8[];
extern char fn_885BDCC0[];
extern char fn_885BDD70[];
extern char lbl_88001A20[];
extern char lbl_88001A68[];
extern char lbl_88002434[];
extern char lbl_88002438[];
extern char lbl_88002444[];
extern char lbl_8803A308[];
extern char lbl_880869E8[];
extern char lbl_88087A1C[];
extern char lbl_88087CD4[];
extern char lbl_880B4540[];
extern char lbl_880B4560[];
extern char lbl_880B45A8[];
extern char lbl_880B6868[];
extern char lbl_880B68C4[];
extern char lbl_880B68E0[];
extern char lbl_880B68FC[];
extern char lbl_880B6910[];
extern char lbl_880B691C[];
extern char lbl_880B692C[];
extern char lbl_880B6938[];
extern char lbl_880B7394[];
extern char lbl_880B7D08[];
extern char lbl_880B7D0C[];
extern char lbl_880B7D10[];
extern char lbl_880B7D14[];
extern char lbl_880B7D18[];
extern char lbl_880B9814[];
extern char lbl_880B981C[];
extern char lbl_880BA500[];
extern char lbl_880BD388[];
extern char lbl_880BD3F8[];
extern char lbl_880BD468[];
extern char lbl_880BD4E0[];
extern char lbl_880BD558[];
extern char lbl_880BD5D0[];
extern char lbl_880BD648[];
extern char lbl_880BD6B8[];
extern char lbl_880BD798[];
extern char lbl_880BD810[];
extern char lbl_880BD888[];
extern char lbl_880BD900[];
extern char lbl_880BD9E0[];
extern char lbl_880BDA50[];
extern char lbl_880BDAC0[];
extern char lbl_880BDB38[];
extern char lbl_880BDBB0[];
extern char lbl_880C074C[];
extern char lbl_880C123C[];
extern char lbl_880DD7B0[];
extern char lbl_880FBB04[];
extern char lbl_88CACF08[];
extern char lbl_88D2F130[];
extern char lbl_88D3CB48[];
extern char lbl_88D3CD34[];
ts4_word KeSetEvent();
ts4_word KeTlsGetValue();
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word XAudioUnregisterRenderDriverClient();
ts4_word fn_882A8E28();
ts4_word fn_8841A510();
ts4_word fn_8841A590();
ts4_word fn_88421450();
ts4_word fn_88421460();
ts4_word fn_884235C0();
ts4_word fn_884237F0();
ts4_word fn_8846C2A8();
ts4_word fn_88470AD0();
ts4_word fn_88472530();
ts4_word fn_88472748();
ts4_word fn_88472858();
ts4_word fn_88475AE8();
ts4_word fn_88475B08();
ts4_word fn_8849EE78();
ts4_word fn_885651F8();
ts4_word fn_8857A1E0();
ts4_word fn_8857B508();
ts4_word fn_8857BFA8();
ts4_word fn_88593C30();
ts4_word fn_88593CE8();
ts4_word ts4_if_call_seq_u32_offc_885968A8();
ts4_word fn_8859F3B0();
ts4_word fn_885A5068();
ts4_word fn_885A51A8();
ts4_word fn_885A6158();
ts4_word ts4_forward_this_plus_16_885A6190();
ts4_word fn_885A6878();
ts4_word fn_885A6C48();
ts4_word fn_885A6E08();
ts4_word fn_885A7718();
ts4_word fn_885A7A00();
ts4_word fn_885A9120();
ts4_word fn_885A9A50();
ts4_word fn_885B6B10();
ts4_word fn_885B6B78();
ts4_word fn_885B6BE8();
ts4_word fn_885B6C50();
ts4_word fn_885B6CC8();
ts4_word fn_885B6DC0();
ts4_word fn_885B6F90();
ts4_word fn_885B7008();
ts4_word fn_885B7080();
ts4_word fn_885B70F0();
ts4_word fn_885B7158();
ts4_word fn_885B71C0();
ts4_word fn_885B72F0();
ts4_word fn_885B73E8();
ts4_word fn_885B80C0();
ts4_word fn_885B89A0();
ts4_word fn_885B8A58();
ts4_word fn_885B8DF8();
ts4_word fn_885B8EB8();
ts4_word fn_885B93D0();
ts4_word fn_885C1AD8();
ts4_word fn_885C2038();
ts4_word fn_885C24A0();
ts4_word fn_885C3348();
ts4_word fn_885C3770();
ts4_word fn_885CE510();
ts4_word fn_885CE568();
ts4_word fn_885D4EF0();
ts4_word fn_885DC838();
ts4_word fn_885DD1F8();
ts4_word fn_885E3BA8();
ts4_word fn_885E3F20();
ts4_word fn_885E40C8();
ts4_word fn_885E76C0();
ts4_word fn_885E7AD8();
ts4_word fn_885E7BA8();
ts4_word fn_885E8F50();
ts4_word fn_885EA1A8();
ts4_word fn_885EAAD0();
ts4_word fn_885EAC80();
ts4_word fn_885EB698();
ts4_word fn_885EBBC8();
ts4_word ts4_if_call_seq_fn_885EBBC8_885EC4B0();
ts4_word fn_885EC7D8();
ts4_word fn_885EC938();
ts4_word ts4_if_call_seq_u32_lbl_88CACF08_885ED540();
ts4_word fn_885ED798();
ts4_word ts4_if_call_seq_lbl_880869E8_885F4188();
ts4_word ts4_call_runtime_2890();
ts4_word ts4_forward_885A9E30();
ts4_word ts4_forward_885DBBA8();
ts4_word ts4_runtime_type_code_none();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x885A5138: call_seq RtlEnterCriticalSection, u32@0x20, KeSetEvent, RtlLeaveCriticalSection */
ts4_word ts4_call_seq_RtlEnterCriticalSection_885A5138(ts4_word a0)
{
    ts4_word t4;

    RtlEnterCriticalSection((ts4_word)(a0 + 36));
    KeSetEvent((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)), (ts4_word)1, (ts4_word)0);
    t4 = RtlLeaveCriticalSection((ts4_word)(a0 + 36));
    return t4;
}

/* Swing_DLL.xex 0x885A5190: addr lbl_88D2F130, fn_88593C30 */
ts4_word ts4_addr_lbl_88D2F130_885A5190(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_88593C30((ts4_word)(ts4_word)lbl_88D2F130, (ts4_word)a1, (ts4_word)((546766848) | 6), (ts4_word)8);
}

/* Swing_DLL.xex 0x885A5B48: get u32@0x14, u32@0x10, fn_885A5068 */
ts4_word ts4_get_u32_off14_885A5B48(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
    return fn_885A5068((ts4_word)(a0 + -8), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16)), (ts4_word)t1);
}

/* Swing_DLL.xex 0x885A6150: tailcall fn_885A6878 */
ts4_word ts4_tailcall_fn_885A6878_885A6150(ts4_word a0)
{
    return fn_885A6878((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x885A6180: tailcall fn_885A6158 */
ts4_word ts4_tailcall_fn_885A6158_885A6180(ts4_word a0)
{
    return fn_885A6158((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x885A6188: tailcall fn_885A51A8 */
ts4_word ts4_tailcall_fn_885A51A8_885A6188(ts4_word a0)
{
    return fn_885A51A8((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x885A6198: tailcall ts4_forward_this_plus_16_885A6190 */
ts4_word ts4_tailcall_fn_885A6190_885A6198(ts4_word a0)
{
    return ts4_forward_this_plus_16_885A6190((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x885A69A0: get  */
void ts4_get_885A69A0(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 68));
    return;
}

/* Swing_DLL.xex 0x885A6E38: tailcall fn_885A6C48 */
ts4_word ts4_tailcall_fn_885A6C48_885A6E38(ts4_word a0)
{
    return fn_885A6C48((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x885A79F8: tailcall fn_885A7718 */
ts4_word ts4_tailcall_fn_885A7718_885A79F8(ts4_word a0)
{
    return fn_885A7718((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x885A7A90: call_seq fn_885A7A00, ts4_if_call_seq_u32_offc_885968A8 */
ts4_word ts4_call_seq_fn_885A7A00_885A7A90(ts4_word a0)
{
    ts4_word t2;

    fn_885A7A00((ts4_word)a0);
    t2 = ts4_if_call_seq_u32_offc_885968A8((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x885A9118: tailcall fn_885A6E08 */
ts4_word ts4_tailcall_fn_885A6E08_885A9118(ts4_word a0)
{
    return fn_885A6E08((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x885A9260: call_seq fn_885A9120, ts4_if_call_seq_u32_offc_885968A8 */
ts4_word ts4_call_seq_fn_885A9120_885A9260(ts4_word a0)
{
    ts4_word t2;

    fn_885A9120((ts4_word)a0);
    t2 = ts4_if_call_seq_u32_offc_885968A8((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x885A99E0: set u32@0x34 */
void ts4_set_u32_off34_885A99E0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x885A9E28: tailcall fn_885A9A50 */
ts4_word ts4_tailcall_fn_885A9A50_885A9E28(ts4_word a0)
{
    return fn_885A9A50((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x885A9E98: tailcall ts4_forward_885A9E30 */
ts4_word ts4_tailcall_ts4_forward_885A9E30_885A9E98(ts4_word a0)
{
    return ts4_forward_885A9E30((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x885A9EF0: fn  */
ts4_word ts4_fn_885A9EF0(void)
{
    return ((2291531776) | 1);
}

/* Swing_DLL.xex 0x885B6D30: tailcall fn_885B6B78 */
ts4_word ts4_tailcall_fn_885B6B78_885B6D30(ts4_word a0)
{
    return fn_885B6B78((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885B6D38: tailcall fn_885B6CC8 */
ts4_word ts4_tailcall_fn_885B6CC8_885B6D38(ts4_word a0)
{
    return fn_885B6CC8((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885B6D40: tailcall fn_885B6C50 */
ts4_word ts4_tailcall_fn_885B6C50_885B6D40(ts4_word a0)
{
    return fn_885B6C50((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885B6D48: tailcall fn_885B6B10 */
ts4_word ts4_tailcall_fn_885B6B10_885B6D48(ts4_word a0)
{
    return fn_885B6B10((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885B6D50: tailcall fn_885B6DC0 */
ts4_word ts4_tailcall_fn_885B6DC0_885B6D50(ts4_word a0)
{
    return fn_885B6DC0((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885B6D58: tailcall fn_885B6BE8 */
ts4_word ts4_tailcall_fn_885B6BE8_885B6D58(ts4_word a0)
{
    return fn_885B6BE8((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885B72A8: tailcall fn_885B80C0 */
ts4_word ts4_tailcall_fn_885B80C0_885B72A8(ts4_word a0)
{
    return fn_885B80C0((ts4_word)a0, (ts4_word)16, (ts4_word)0);
}

/* Swing_DLL.xex 0x885B72B8: tailcall fn_885B7080 */
ts4_word ts4_tailcall_fn_885B7080_885B72B8(ts4_word a0)
{
    return fn_885B7080((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885B72C0: tailcall fn_885B6F90 */
ts4_word ts4_tailcall_fn_885B6F90_885B72C0(ts4_word a0)
{
    return fn_885B6F90((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885B72C8: tailcall fn_885B7008 */
ts4_word ts4_tailcall_fn_885B7008_885B72C8(ts4_word a0)
{
    return fn_885B7008((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885B72D0: tailcall fn_885B71C0 */
ts4_word ts4_tailcall_fn_885B71C0_885B72D0(ts4_word a0)
{
    return fn_885B71C0((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885B72D8: tailcall fn_885B7158 */
ts4_word ts4_tailcall_fn_885B7158_885B72D8(ts4_word a0)
{
    return fn_885B7158((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885B72E0: tailcall fn_885B70F0 */
ts4_word ts4_tailcall_fn_885B70F0_885B72E0(ts4_word a0)
{
    return fn_885B70F0((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885B72E8: tailcall fn_885B73E8 */
ts4_word ts4_tailcall_fn_885B73E8_885B72E8(ts4_word a0)
{
    return fn_885B73E8((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885B8460: get u32@0x0, fn_882A8E28 */
ts4_word ts4_get_u32_off0_885B8460(ts4_word a0)
{
    return fn_882A8E28((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x885B8A18: get u32@0x18, fn_885CE510 */
ts4_word ts4_get_u32_off18_885B8A18(ts4_word a0)
{
    return fn_885CE510((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
}

/* Swing_DLL.xex 0x885B8A20: get u32@0x18, fn_885CE568 */
ts4_word ts4_get_u32_off18_885B8A20(ts4_word a0)
{
    return fn_885CE568((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)0);
}

/* Swing_DLL.xex 0x885B8A40: tailcall ts4_runtime_type_code_none */
ts4_word ts4_tailcall_ts4_runtime_type_code_none_885B8A40(ts4_word a0)
{
    return ts4_runtime_type_code_none((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885B8A48: tailcall fn_885B89A0 */
ts4_word ts4_tailcall_fn_885B89A0_885B8A48(ts4_word a0)
{
    return fn_885B89A0((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885B8A50: tailcall fn_885B8A58 */
ts4_word ts4_tailcall_fn_885B8A58_885B8A50(ts4_word a0)
{
    return fn_885B8A58((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885B8CE0: get u32@0x14, u32@0x3c */
ts4_word ts4_get_u32_off14_885B8CE0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)1;
    return t1;
}

/* Swing_DLL.xex 0x885B8DF0: tailcall fn_885B8DF8 */
ts4_word ts4_tailcall_fn_885B8DF8_885B8DF0(ts4_word a0)
{
    return fn_885B8DF8((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885B8E58: if_call_seq u32@0x10, u32@0x18, u32@0x14, fn_8859F3B0, u32@0x28, u32@0x3c */
ts4_word ts4_if_call_seq_u32_off10_885B8E58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;

    (void)a1;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)a2 == 1) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
        fn_8859F3B0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)t2, (ts4_word)t1);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    KeSetEvent((ts4_word)t6, (ts4_word)1, (ts4_word)0);
    return 0;
}

/* Swing_DLL.xex 0x885B8FB0: if_call_seq u32@0x30, KeSetEvent, u32@0x20, XAudioUnregisterRenderDriverClient, u32@0x20, u32@0x30 */
ts4_word ts4_if_call_seq_u32_off30_885B8FB0(ts4_word a0)
{
    ts4_word p5;
    ts4_word t3;
    ts4_word t4;

    KeSetEvent((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)1, (ts4_word)0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    p5 = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        t4 = XAudioUnregisterRenderDriverClient((ts4_word)t3);
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
        p5 = (ts4_word)t4;
    }
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + 4) = (ts4_word)0;
    return p5;
}

/* Swing_DLL.xex 0x885B9088: get u32@0x0, fn_885B8EB8 */
ts4_word ts4_get_u32_off0_885B9088(ts4_word a0)
{
    return fn_885B8EB8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x885B9100: tailcall fn_885B93D0 */
ts4_word ts4_tailcall_fn_885B93D0_885B9100(ts4_word a0)
{
    return fn_885B93D0((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885B9108: get u32@0x20 */
ts4_word ts4_get_u32_off20_885B9108(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 32));
}

/* Swing_DLL.xex 0x885B9110: get u32@0x10 */
ts4_word ts4_get_u32_off10_885B9110(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x885B9128: fn  */
ts4_word ts4_fn_885B9128(void)
{
    return 256;
}

/* Swing_DLL.xex 0x885BDBC8: addr ts4_runtime_type_code_none */
ts4_word ts4_addr_ts4_runtime_type_code_none_885BDBC8(void)
{
    return (ts4_word)ts4_runtime_type_code_none;
}

/* Swing_DLL.xex 0x885BDE60: if_addr fn_885BDCC0, fn_885BDD70, fn_885BDBD8 */
ts4_word ts4_if_addr_fn_885BDCC0_885BDE60(ts4_word a0)
{
    if ((ts4_word)a0 == 1) {
        return (ts4_word)fn_885BDCC0;
    }
    if ((ts4_word)a0 == 2) {
        return (ts4_word)fn_885BDD70;
    }
    return (ts4_word)fn_885BDBD8;
}

/* Swing_DLL.xex 0x885BDF98: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x14 */
void ts4_set_u32_off0_885BDF98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 16) = (*(float *)lbl_88001A20);
    return;
}

/* Swing_DLL.xex 0x885BE178: if_call_seq u32@0xc, fn_885B72F0, u32@0xc, u32@0x14, fn_885B72F0, u32@0x14 */
ts4_word ts4_if_call_seq_u32_offc_885BE178(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        fn_885B72F0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t4 != 0) {
        fn_885B72F0((ts4_word)t4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    p9 = (ts4_word)t7;
    if ((ts4_word)t7 != 0) {
        t8 = fn_885B72F0((ts4_word)t7);
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
        p9 = (ts4_word)t8;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return p9;
}

/* Swing_DLL.xex 0x885BEF10: if_call_seq u32@0x3c, fn_885C24A0, fn_885C1AD8, fn_885C2038, fn_885D4EF0 */
ts4_word ts4_if_call_seq_u32_off3c_885BEF10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p7;
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    if ((int)t1 > 2) {
        fn_885C24A0();
    }
    fn_885C1AD8((ts4_word)a0);
    t5 = fn_885C2038((ts4_word)a0);
    p7 = (ts4_word)t5;
    if ((int)t5 >= 0) {
        t6 = fn_885D4EF0((ts4_word)a0);
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Swing_DLL.xex 0x885BFD40: get  */
ts4_word ts4_get_885BFD40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a1;
    (void)a2;
    return ((short)(*(unsigned short *)((char *)(ts4_word)((a3 << 1)) + a0)));
}

/* Swing_DLL.xex 0x885BFD50: get  */
ts4_word ts4_get_885BFD50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a1;
    (void)a2;
    return ((int)(*(ts4_word *)((char *)(ts4_word)((a3 + (a3 << 1))) + a0)) >> 8);
}

/* Swing_DLL.xex 0x885C35C8: tailcall fn_885C3348 */
ts4_word ts4_tailcall_fn_885C3348_885C35C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    return fn_885C3348((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)0);
}

/* Swing_DLL.xex 0x885C3A10: if_call_seq fn_885C3770, u16@0x10 */
ts4_word ts4_if_call_seq_fn_885C3770_885C3A10(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;

    t1 = fn_885C3770((ts4_word)(a0 + 224), (ts4_word)1, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 >= 0) {
        t2 = loc50[0];
        *(unsigned short *)((char *)(ts4_word)(a0) + 16) = (unsigned short)t2;
    }
    return t1;
}

/* Swing_DLL.xex 0x885CE120: if_call_seq u32@0x2c, fn_885B72F0, u32@0x2c, u32@0x38, fn_885B72F0, u32@0x38 */
ts4_word ts4_if_call_seq_u32_off2c_885CE120(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t1 != 0) {
        fn_885B72F0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((ts4_word)t4 != 0) {
        fn_885B72F0((ts4_word)t4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    }
    t7 = fn_88593CE8((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x885CE5C8: get u32@0x98, u32@0x98 */
void ts4_get_u32_off98_885CE5C8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 152)) + 1);
    return;
}

/* Swing_DLL.xex 0x885CE658: set u32@0x74 */
void ts4_set_u32_off74_885CE658(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)1;
    return;
}

/* Swing_DLL.xex 0x885CF1E8: set u32@0x108 */
void ts4_set_u32_off108_885CF1E8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 264) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x885D9B48: set u32@0x60 */
void ts4_set_u32_off60_885D9B48(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)1;
    return;
}

/* Swing_DLL.xex 0x885D9B58: set u32@0x60 */
void ts4_set_u32_off60_885D9B58(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x885D9B68: get u32@0x60 */
ts4_word ts4_get_u32_off60_885D9B68(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 96));
}

/* Swing_DLL.xex 0x885DBA20: call_seq ts4_forward_885DBBA8, u32@0x0, u32@0x100 */
ts4_word ts4_call_seq_ts4_forward_885DBBA8_885DBA20(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_forward_885DBBA8((ts4_word)1, (ts4_word)260);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(t1) + 256) = (ts4_word)1;
    return 0;
}

/* Swing_DLL.xex 0x885DBBB0: call_seq u32@0x0, fn_885651F8, u32@0x0 */
ts4_word ts4_call_seq_u32_off0_885DBBB0(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_885651F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return t2;
}

/* Swing_DLL.xex 0x885DCAF8: if_call_seq lbl_880B4540, lbl_880B6868, lbl_880B6910, fn_885DC838, u32@0x4, lbl_880B68FC */
ts4_word ts4_if_call_seq_lbl_880B4540_885DCAF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p2;
    ts4_word p5;
    ts4_word p8;
    ts4_word p11;
    ts4_word p13;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;
    ts4_word t10;
    ts4_word t12;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p13 = (ts4_word)a0;
    if ((ts4_word)a1 != 0) {
        p2 = (ts4_word)a0;
        if ((ts4_word)a0 == 0) {
            t1 = fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880B6910, (ts4_word)(ts4_word)lbl_880B6868, (ts4_word)163);
            p2 = (ts4_word)t1;
        }
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        p5 = (ts4_word)p2;
        if ((ts4_word)t3 == 0) {
            t4 = fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880B68FC, (ts4_word)(ts4_word)lbl_880B6868, (ts4_word)164);
            p5 = (ts4_word)t4;
        }
        t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        p8 = (ts4_word)p5;
        if ((ts4_word)t6 != 0) {
            t7 = fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880B68E0, (ts4_word)(ts4_word)lbl_880B6868, (ts4_word)167);
            p8 = (ts4_word)t7;
        }
        t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        p11 = (ts4_word)p8;
        if ((ts4_word)t9 != 0) {
            t10 = fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880B68C4, (ts4_word)(ts4_word)lbl_880B6868, (ts4_word)168);
            p11 = (ts4_word)t10;
        }
        *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)a0;
        t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)t12;
        *(ts4_word *)((char *)(ts4_word)(t12) + 8) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
        p13 = (ts4_word)p11;
    }
    return p13;
}

/* Swing_DLL.xex 0x885DCD38: if_call_seq u32@0x44, lbl_880B45A8, lbl_880B4560, lbl_880B4540, fn_885DC838, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off44_885DCD38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)a1 >= (ts4_word)t1) {
        fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880B4560, (ts4_word)(ts4_word)lbl_880B45A8, (ts4_word)309);
    }
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + (a1 << 2)));
}

/* Swing_DLL.xex 0x885E0050: get  */
ts4_word ts4_get_885E0050(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)lbl_880B9814);
    return 1;
}

/* Swing_DLL.xex 0x885E0158: get  */
ts4_word ts4_get_885E0158(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)lbl_880B981C);
    return 1;
}

/* Swing_DLL.xex 0x885E0878: get  */
ts4_word ts4_get_885E0878(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)lbl_880B7D18);
    return 1;
}

/* Swing_DLL.xex 0x885E0890: get  */
ts4_word ts4_get_885E0890(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)lbl_880B7D14);
    return 1;
}

/* Swing_DLL.xex 0x885E08A8: get  */
ts4_word ts4_get_885E08A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)lbl_880B7D10);
    return 1;
}

/* Swing_DLL.xex 0x885E08C0: get  */
ts4_word ts4_get_885E08C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)lbl_88001A68);
    return 1;
}

/* Swing_DLL.xex 0x885E08D8: get  */
ts4_word ts4_get_885E08D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)lbl_88002438);
    return 1;
}

/* Swing_DLL.xex 0x885E08F0: get  */
ts4_word ts4_get_885E08F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)lbl_88001A20);
    return 1;
}

/* Swing_DLL.xex 0x885E0908: get  */
ts4_word ts4_get_885E0908(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)lbl_880B7D0C);
    return 1;
}

/* Swing_DLL.xex 0x885E0920: get  */
ts4_word ts4_get_885E0920(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)lbl_88002444);
    return 1;
}

/* Swing_DLL.xex 0x885E0938: get  */
ts4_word ts4_get_885E0938(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)lbl_88002434);
    return 1;
}

/* Swing_DLL.xex 0x885E0950: get  */
ts4_word ts4_get_885E0950(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)lbl_880B7D08);
    return 1;
}

/* Swing_DLL.xex 0x885E1930: get u8@0x860 */
ts4_word ts4_get_u8_off860_885E1930(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 2144));
}

/* Swing_DLL.xex 0x885E1938: call_seq u32@0xc, u32@0x4, u32@0x0, fn_885DD1F8, u32@0x8 */
ts4_word ts4_call_seq_u32_offc_885E1938(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)2;
    t1 = fn_885DD1F8((ts4_word)a1, (ts4_word)8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t1;
    return a0;
}

/* Swing_DLL.xex 0x885E1990: call_seq u32@0x814, u32@0x4, fn_885E3BA8, u32@0x0 */
ts4_word ts4_call_seq_u32_off814_885E1990(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 2068);
    t3 = fn_885E3BA8((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4)));
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)a1;
    return t3;
}

/* Swing_DLL.xex 0x885E37E0: call_seq u32@0x0, fn_885E40C8, u32@0x4, fn_885E3F20 */
ts4_word ts4_call_seq_u32_off0_885E37E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    t2 = fn_885E40C8((ts4_word)a2, (ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    fn_885E3F20((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)t2);
    return t2;
}

/* Swing_DLL.xex 0x885E3930: addr lbl_880DD7B0 */
ts4_word ts4_addr_lbl_880DD7B0_885E3930(void)
{
    return (ts4_word)lbl_880DD7B0;
}

/* Swing_DLL.xex 0x885E3940: addr lbl_880BA500 */
ts4_word ts4_addr_lbl_880BA500_885E3940(void)
{
    return (ts4_word)lbl_880BA500;
}

/* Swing_DLL.xex 0x885E3B10: if_get u32@0x4, u32@0x4, u32@0x8, u32@0x8, u32@0x4 */
void ts4_if_get_u32_off4_885E3B10(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)a0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)a0;
    return;
}

/* Swing_DLL.xex 0x885E3B30: if_get u32@0x8, u32@0x8, u32@0x4, u32@0x4, u32@0x8 */
void ts4_if_get_u32_off8_885E3B30(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)a0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)a0;
    return;
}

/* Swing_DLL.xex 0x885E4348: set u8@0x4 */
void ts4_set_u8_off4_885E4348(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)a1;
    return;
}

/* Swing_DLL.xex 0x885E4350: call_seq u32@0x28, u32@0x4, fn_885E3BA8, u32@0x0, u32@0x18, u32@0x18 */
ts4_word ts4_call_seq_u32_off28_885E4350(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    t3 = fn_885E3BA8((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4)));
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24)) + 1);
    return t3;
}

/* Swing_DLL.xex 0x885E5D90: addr lbl_880BD388 */
ts4_word ts4_addr_lbl_880BD388_885E5D90(void)
{
    return (ts4_word)lbl_880BD388;
}

/* Swing_DLL.xex 0x885E5E10: addr lbl_880FBB04 */
ts4_word ts4_addr_lbl_880FBB04_885E5E10(void)
{
    return (ts4_word)lbl_880FBB04;
}

/* Swing_DLL.xex 0x885E5E20: addr lbl_880BD3F8 */
ts4_word ts4_addr_lbl_880BD3F8_885E5E20(void)
{
    return (ts4_word)lbl_880BD3F8;
}

/* Swing_DLL.xex 0x885E5E30: addr lbl_880BD468 */
ts4_word ts4_addr_lbl_880BD468_885E5E30(void)
{
    return (ts4_word)lbl_880BD468;
}

/* Swing_DLL.xex 0x885E5EB8: addr lbl_880BD4E0 */
ts4_word ts4_addr_lbl_880BD4E0_885E5EB8(void)
{
    return (ts4_word)lbl_880BD4E0;
}

/* Swing_DLL.xex 0x885E5F98: addr lbl_880BD558 */
ts4_word ts4_addr_lbl_880BD558_885E5F98(void)
{
    return (ts4_word)lbl_880BD558;
}

/* Swing_DLL.xex 0x885E5FA8: addr lbl_880BD5D0 */
ts4_word ts4_addr_lbl_880BD5D0_885E5FA8(void)
{
    return (ts4_word)lbl_880BD5D0;
}

/* Swing_DLL.xex 0x885E6028: addr lbl_880BD648 */
ts4_word ts4_addr_lbl_880BD648_885E6028(void)
{
    return (ts4_word)lbl_880BD648;
}

/* Swing_DLL.xex 0x885E6038: addr lbl_880BD6B8 */
ts4_word ts4_addr_lbl_880BD6B8_885E6038(void)
{
    return (ts4_word)lbl_880BD6B8;
}

/* Swing_DLL.xex 0x885E6048: fn  */
ts4_word ts4_fn_885E6048(void)
{
    return 1;
}

/* Swing_DLL.xex 0x885E60A0: addr lbl_880BD798 */
ts4_word ts4_addr_lbl_880BD798_885E60A0(void)
{
    return (ts4_word)lbl_880BD798;
}

/* Swing_DLL.xex 0x885E60B0: addr lbl_880BD810 */
ts4_word ts4_addr_lbl_880BD810_885E60B0(void)
{
    return (ts4_word)lbl_880BD810;
}

/* Swing_DLL.xex 0x885E60C0: addr lbl_880BD888 */
ts4_word ts4_addr_lbl_880BD888_885E60C0(void)
{
    return (ts4_word)lbl_880BD888;
}

/* Swing_DLL.xex 0x885E60D0: addr lbl_880BD900 */
ts4_word ts4_addr_lbl_880BD900_885E60D0(void)
{
    return (ts4_word)lbl_880BD900;
}

/* Swing_DLL.xex 0x885E60E0: addr lbl_880B7394 */
ts4_word ts4_addr_lbl_880B7394_885E60E0(void)
{
    return (ts4_word)lbl_880B7394;
}

/* Swing_DLL.xex 0x885E6280: addr lbl_880BD9E0 */
ts4_word ts4_addr_lbl_880BD9E0_885E6280(void)
{
    return (ts4_word)lbl_880BD9E0;
}

/* Swing_DLL.xex 0x885E6308: addr lbl_880BDA50 */
ts4_word ts4_addr_lbl_880BDA50_885E6308(void)
{
    return (ts4_word)lbl_880BDA50;
}

/* Swing_DLL.xex 0x885E6390: addr lbl_880BDAC0 */
ts4_word ts4_addr_lbl_880BDAC0_885E6390(void)
{
    return (ts4_word)lbl_880BDAC0;
}

/* Swing_DLL.xex 0x885E6418: addr lbl_880BDB38 */
ts4_word ts4_addr_lbl_880BDB38_885E6418(void)
{
    return (ts4_word)lbl_880BDB38;
}

/* Swing_DLL.xex 0x885E64A0: addr lbl_880BDBB0 */
ts4_word ts4_addr_lbl_880BDBB0_885E64A0(void)
{
    return (ts4_word)lbl_880BDBB0;
}

/* Swing_DLL.xex 0x885E7620: get u32@0x8, u32@0x0 */
ts4_word ts4_get_u32_off8_885E7620(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return (*(ts4_word *)((char *)(ts4_word)((((t1 + a1) + 1) << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0))));
}

/* Swing_DLL.xex 0x885E7640: get u32@0x8, u32@0x0 */
ts4_word ts4_get_u32_off8_885E7640(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return (*(ts4_word *)((char *)(ts4_word)(((((t1 + 1) << 1) + a1) << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0))));
}

/* Swing_DLL.xex 0x885E7B40: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u32@0x0, fn_88421460, u32@0x4 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_885E7B40(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)192, (ts4_word)23);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
    fn_88421460((ts4_word)t3, (ts4_word)255, (ts4_word)64);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)15;
    return a0;
}

/* Swing_DLL.xex 0x885E85A8: set  */
void ts4_set_885E85A8(ts4_word a0, ts4_word a1, ts4_word a2, float f1, float f2)
{
    (void)a0;
    (void)a1;
    *(float *)((char *)(ts4_word)(a2) + 76) = f1;
    *(float *)((char *)(ts4_word)(a2) + 92) = f2;
    return;
}

/* Swing_DLL.xex 0x885E9160: tailcall fn_885E8F50 */
ts4_word ts4_tailcall_fn_885E8F50_885E9160(ts4_word a0, ts4_word a1)
{
    return fn_885E8F50((ts4_word)(a1 + 48), (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x885E9368: set u32@0x0 */
void ts4_set_u32_off0_885E9368(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x885E93B8: call_seq ts4_call_runtime_2890, u32@0x0 */
ts4_word ts4_call_seq_ts4_call_runtime_2890_885E93B8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = ts4_call_runtime_2890((ts4_word)0, (ts4_word)0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    return (t1 == 0);
}

/* Swing_DLL.xex 0x885E9408: if_call_seq u32@0x0, fn_8857B508 */
ts4_word ts4_if_call_seq_u32_off0_885E9408(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == 0) {
        return 2;
    }
    fn_8857B508((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
    t3 = loc50[0];
    return ((t3 + -259) == 0);
}

/* Swing_DLL.xex 0x885E9490: get u32@0x0 */
ts4_word ts4_get_u32_off0_885E9490(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Swing_DLL.xex 0x885E9618: set u32@0x0 */
void ts4_set_u32_off0_885E9618(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)-47;
    return;
}

/* Swing_DLL.xex 0x885E9628: if_get u32@0x0, u32@0x0, u16@0x4 */
void ts4_if_get_u32_off0_885E9628(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)t1 != -47) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)-15;
    *(unsigned short *)((char *)(ts4_word)(a0) + 4) = (unsigned short)0;
    return;
}

/* Swing_DLL.xex 0x885E9A20: if_call_seq u32@lbl_88D3CB48, fn_88472858, u32@lbl_88D3CB48 */
ts4_word ts4_if_call_seq_u32_lbl_88D3CB48_885E9A20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D3CB48;
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_88472858((ts4_word)t1, (ts4_word)1);
        *(ts4_word *)lbl_88D3CB48 = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x885E9C40: set u64@0x20, RtlLeaveCriticalSection */
ts4_word ts4_set_u64_off20_885E9C40(ts4_word a0)
{
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 32) = (ts4_u64)-1;
    return RtlLeaveCriticalSection((ts4_word)a0);
}

/* Swing_DLL.xex 0x885E9D00: call_seq fn_88472530, u32@0x38 */
ts4_word ts4_call_seq_fn_88472530_885E9D00(ts4_word a0)
{
    fn_88472530((ts4_word)a0);
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 56));
}

/* Swing_DLL.xex 0x885E9D88: call_seq fn_88472530, u32@0x38, fn_8849EE78, u32@0x38, fn_8849EE78, u64@0x20 */
ts4_word ts4_call_seq_fn_88472530_885E9D88(ts4_word a0, ts4_word a1)
{
    ts4_word t6;

    fn_88472530((ts4_word)a0);
    fn_8849EE78((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56)) + 20), (ts4_word)a1);
    fn_8849EE78((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56)) + 40), (ts4_word)a1);
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 32) = (ts4_u64)-1;
    t6 = RtlLeaveCriticalSection((ts4_word)a0);
    return t6;
}

/* Swing_DLL.xex 0x885EAA60: if_call_seq u32@0x38, fn_885EAC80, u32@0x54, fn_885EAAD0, fn_88472748 */
ts4_word ts4_if_call_seq_u32_off38_885EAA60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((ts4_word)t1 != 0) {
        fn_885EAC80((ts4_word)t1, (ts4_word)1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    if ((ts4_word)t4 != 0) {
        fn_885EAAD0((ts4_word)t4, (ts4_word)1);
    }
    t7 = fn_88472748((ts4_word)(a0 + 40));
    return t7;
}

/* Swing_DLL.xex 0x885EAAB8: tailcall fn_885EA1A8 */
ts4_word ts4_tailcall_fn_885EA1A8_885EAAB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_885EA1A8((ts4_word)a0, (ts4_word)a1, (ts4_word)0, (ts4_word)a2, (ts4_word)0, (ts4_word)a3);
}

/* Swing_DLL.xex 0x885EAD20: call_seq fn_8857BFA8, u32@0x0 */
ts4_word ts4_call_seq_fn_8857BFA8_885EAD20(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = fn_8857BFA8((ts4_word)0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    return a0;
}

/* Swing_DLL.xex 0x885EAD60: get u32@0x0, fn_8857A1E0 */
ts4_word ts4_get_u32_off0_885EAD60(ts4_word a0)
{
    return fn_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x885EB4D0: if_call_seq lbl_880C074C, u32@0x4, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880C074C_885EB4D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880C074C;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x885EB618: call_seq fn_884235C0, u32@0x28 */
ts4_word ts4_call_seq_fn_884235C0_885EB618(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_884235C0((ts4_word)(a0 + 28));
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)a1;
    return t1;
}

/* Swing_DLL.xex 0x885EB658: tailcall fn_884235C0 */
ts4_word ts4_tailcall_fn_884235C0_885EB658(ts4_word a0)
{
    return fn_884235C0((ts4_word)(a0 + 28));
}

/* Swing_DLL.xex 0x885EB660: call_seq fn_884235C0, u32@0x14 */
ts4_word ts4_call_seq_fn_884235C0_885EB660(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_884235C0((ts4_word)(a0 + 28));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x885EBAB0: if_call_seq u32@0x10, u32@0xc, fn_885EB698, u8@0x1, u8@0x0, u16@0x2 */
ts4_word ts4_if_call_seq_u32_off10_885EBAB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    p6 = (ts4_word)a0;
    if ((int)(t1 & 0x3fffffff) > (int)(t2 + 70)) {
        t3 = fn_885EB698((ts4_word)(a0 + 8), (ts4_word)0);
        *(unsigned char *)((char *)(ts4_word)(t3) + 1) = (unsigned char)0;
        *(unsigned char *)((char *)(ts4_word)(t3) + 0) = (unsigned char)112;
        *(unsigned short *)((char *)(ts4_word)(t3) + 2) = (unsigned short)0;
        *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)0;
        p6 = (ts4_word)t3;
    }
    return p6;
}

/* Swing_DLL.xex 0x885EC4A8: tailcall ts4_if_call_seq_fn_885EBBC8_885EC4B0 */
ts4_word ts4_tailcall_fn_885EC4B0_885EC4A8(ts4_word a0)
{
    return ts4_if_call_seq_fn_885EBBC8_885EC4B0((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x885EC650: get u32@0x8, u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_off8_885EC650(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x885EC668: get u32@0x8, u32@0x0, u32@0xc, vcall */
ts4_word ts4_get_u32_off8_885EC668(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x885EC6A8: get u32@0x8 */
ts4_word ts4_get_u32_off8_885EC6A8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Swing_DLL.xex 0x885EC8D0: if_call_seq fn_885EC7D8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_885EC7D8_885EC8D0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_885EC7D8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)26);
    }
    return a0;
}

/* Swing_DLL.xex 0x885EC9A8: if_call_seq fn_885E7BA8, lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4 */
ts4_word ts4_if_call_seq_fn_885E7BA8_885EC9A8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_885E7BA8((ts4_word)(a0 + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x885ECA20: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_885EC938 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_885ECA20(void)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)32, (ts4_word)21);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)32;
    t4 = fn_885EC938((ts4_word)t3);
    return t4;
}

/* Swing_DLL.xex 0x885ECA60: get u32@0x0, fn_885E76C0 */
ts4_word ts4_get_u32_off0_885ECA60(ts4_word a0, ts4_word a1)
{
    return fn_885E76C0((ts4_word)(a0 + 8), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)a1);
}

/* Swing_DLL.xex 0x885ECA70: if_get fn_885E7AD8, u32@0x4, vcall */
ts4_word ts4_if_get_fn_885E7AD8_885ECA70(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;

    t1 = fn_885E7AD8((ts4_word)(a0 + 8), (ts4_word)a2, (ts4_word)0);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
        if ((ts4_word)t2 != 0) {
            ((ts4_word (*)(ts4_word))(t2))((ts4_word)a1);
        }
        p5 = (ts4_word)t1;
    } else {
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Swing_DLL.xex 0x885ECBE8: if_call_seq fn_885E7BA8, lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4 */
ts4_word ts4_if_call_seq_fn_885E7BA8_885ECBE8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_885E7BA8((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x885ECDC0: if_get u8@0xc, u8@0xd, u8@0xc, u8@0xd */
void ts4_if_get_u8_offc_885ECDC0(ts4_word a0)
{
    unsigned char t1;
    unsigned char t2;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 20) {
        return;
    }
    t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 13);
    if ((ts4_word)t2 != 2) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)29;
    *(unsigned char *)((char *)(ts4_word)(a0) + 13) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x885ED1E8: set u32@0x8, u32@0x0, u32@0x4 */
void ts4_set_u32_off8_885ED1E8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x885ED258: fn  */
ts4_word ts4_fn_885ED258(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (a1 + 20);
}

/* Swing_DLL.xex 0x885ED260: get u32@0x0 */
ts4_word ts4_get_u32_off0_885ED260(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Swing_DLL.xex 0x885ED268: get u32@0x8 */
ts4_word ts4_get_u32_off8_885ED268(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(ts4_word *)((char *)(ts4_word)(a1) + 8));
}

/* Swing_DLL.xex 0x885ED2B0: get u32@0x10 */
ts4_word ts4_get_u32_off10_885ED2B0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(ts4_word *)((char *)(ts4_word)(a1) + 16));
}

/* Swing_DLL.xex 0x885ED2B8: get u32@0x0 */
ts4_word ts4_get_u32_off0_885ED2B8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(ts4_word *)((char *)(ts4_word)(a1) + 0));
}

/* Swing_DLL.xex 0x885ED2C0: if_call_seq ts4_if_call_seq_u32_lbl_88CACF08_885ED540, fn_88421450, u32@0x4, u32@0x8, u32@0x4, u32@0xc */
ts4_word ts4_if_call_seq_fn_885ED540_885ED2C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;

    t1 = ts4_if_call_seq_u32_lbl_88CACF08_885ED540((ts4_word)a3);
    fn_88421450((ts4_word)(t1 + 20), (ts4_word)a2, (ts4_word)a3);
    if ((ts4_word)a1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)t1;
            *(ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
            *(ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)a1;
            *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)t1;
            return t1;
        }
        *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)a1;
        return t1;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t5 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 8) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
        return t1;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x885ED638: get u32@0x8, u32@0x0, u32@0xc, vcall */
ts4_word ts4_get_u32_off8_885ED638(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x885ED6B8: if_get u32@0x8, u32@0x0, u32@0x1c, vcall, u32@0xc, u32@0x10 */
ts4_word ts4_if_get_u32_off8_885ED6B8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 28))))((ts4_word)t1);
    if ((int)t4 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12));
    }
    return t4;
}

/* Swing_DLL.xex 0x885ED708: if_get u32@0x8, u32@0x0, u32@0x20, vcall, u32@0x10, u32@0xc */
ts4_word ts4_if_get_u32_off8_885ED708(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 32))))((ts4_word)t1);
    if ((int)t4 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16));
    }
    return t4;
}

/* Swing_DLL.xex 0x885ED818: if_call_seq fn_885ED798, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_885ED798_885ED818(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_885ED798((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)26);
    }
    return a0;
}

/* Swing_DLL.xex 0x885ED910: get u32@0x8 */
ts4_word ts4_get_u32_off8_885ED910(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Swing_DLL.xex 0x885ED940: set u8@0x0 */
void ts4_set_u8_off0_885ED940(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x885ED950: set u8@0x0 */
void ts4_set_u8_off0_885ED950(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x885ED988: get u32@lbl_88D3CD34, u32@0x0, u32@0xc */
ts4_word ts4_get_u32_lbl_88D3CD34_885ED988(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D3CD34;
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1);
}

/* Swing_DLL.xex 0x885ED9A0: get u32@lbl_88D3CD34, u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_lbl_88D3CD34_885ED9A0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D3CD34;
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1);
}

/* Swing_DLL.xex 0x885F2280: if_call_seq fn_884237F0, u32@0x0 */
ts4_word ts4_if_call_seq_fn_884237F0_885F2280(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;

    t1 = fn_884237F0((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 == 0) {
        t2 = loc50[0];
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t2;
        return t1;
    }
    return 1;
}

/* Swing_DLL.xex 0x885F2D18: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, lbl_880C123C, u16@0x4, u32@0x0 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_885F2D18(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)8, (ts4_word)21);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)8;
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880C123C;
    *(unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    return t3;
}

/* Swing_DLL.xex 0x885F3BC0: addr lbl_880869E8, lbl_8803A308, u32@0x108, u32@0x100 */
void ts4_addr_lbl_880869E8_885F3BC0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 264) = (ts4_word)(ts4_word)lbl_880869E8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 256) = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x885F4180: tailcall ts4_if_call_seq_lbl_880869E8_885F4188 */
ts4_word ts4_tailcall_fn_885F4188_885F4180(ts4_word a0)
{
    return ts4_if_call_seq_lbl_880869E8_885F4188((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x885F45F0: set u16@0x20, u32@0x24, u32@0x0, u32@0x10 */
void ts4_set_u16_off20_885F45F0(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 32) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x885F4948: if_call_seq u32@0x18, fn_88475AE8, u32@0x1c, fn_88475AE8 */
ts4_word ts4_if_call_seq_u32_off18_885F4948(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)t1 != 0) {
        fn_88475AE8((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = fn_88475AE8((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x885F4A30: if_call_seq u32@0x1c, u32@0x8, fn_88470AD0, u32@0x1c, fn_88475B08, u32@0x1c */
ts4_word ts4_if_call_seq_u32_off1c_885F4A30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p12;
    ts4_word t1;
    ts4_word t2;
    ts4_word t9;
    ts4_word t11;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        if ((int)t2 != 0) {
            fn_88470AD0((ts4_word)t2, (ts4_word)a0, (ts4_word)t1);
        }
        fn_88475B08((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a1;
    fn_88475AE8((ts4_word)a1);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p12 = (ts4_word)t9;
    if ((int)t9 != 0) {
        t11 = fn_8846C2A8((ts4_word)t9, (ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
        p12 = (ts4_word)t11;
    }
    return p12;
}

/* Swing_DLL.xex 0x885F4B48: if_call_seq u32@0x18, lbl_88087A1C, u32@0x0, fn_88475B08, u32@0x18, u32@0x1c */
ts4_word ts4_if_call_seq_u32_off18_885F4B48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087A1C;
    if ((ts4_word)t1 != 0) {
        fn_88475B08((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = fn_88475B08((ts4_word)t4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
        p6 = (ts4_word)t5;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p6;
}

/* Swing_DLL.xex 0x885F4D78: if_call_seq u32@0x18, lbl_88087CD4, u32@0x0, fn_88475B08, u32@0x18, lbl_8803A308 */
ts4_word ts4_if_call_seq_u32_off18_885F4D78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087CD4;
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_88475B08((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p3;
}

/* Swing_DLL.xex 0x885F5220: fn  */
ts4_word ts4_fn_885F5220(void)
{
    return 1;
}

/* Swing_DLL.xex 0x885F52E8: fn  */
ts4_word ts4_fn_885F52E8(void)
{
    return 1;
}

/* Swing_DLL.xex 0x885F5310: set u32@0x28 */
ts4_word ts4_set_u32_off28_885F5310(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F5340: get u16@0x16 */
ts4_word ts4_get_u16_off16_885F5340(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 22));
}

/* Swing_DLL.xex 0x885F5348: get u16@0x14 */
ts4_word ts4_get_u16_off14_885F5348(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x885F5350: set u32@0x14 */
ts4_word ts4_set_u32_off14_885F5350(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F5370: get u16@0x14 */
ts4_word ts4_get_u16_off14_885F5370(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x885F5388: get u16@0x16 */
ts4_word ts4_get_u16_off16_885F5388(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 22));
}

/* Swing_DLL.xex 0x885F5390: get u16@0x14 */
ts4_word ts4_get_u16_off14_885F5390(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x885F5398: get u16@0x16 */
ts4_word ts4_get_u16_off16_885F5398(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 22));
}

/* Swing_DLL.xex 0x885F53A0: get u16@0x14 */
ts4_word ts4_get_u16_off14_885F53A0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x885F53A8: get u16@0x16 */
ts4_word ts4_get_u16_off16_885F53A8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 22));
}

/* Swing_DLL.xex 0x885F53B0: get u16@0x14 */
ts4_word ts4_get_u16_off14_885F53B0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x885F53B8: get u16@0x16 */
ts4_word ts4_get_u16_off16_885F53B8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 22));
}

/* Swing_DLL.xex 0x885F53C0: get u16@0x14 */
ts4_word ts4_get_u16_off14_885F53C0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x885F5400: get u16@0x22 */
ts4_word ts4_get_u16_off22_885F5400(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 34));
}

/* Swing_DLL.xex 0x885F5408: get u16@0x20 */
ts4_word ts4_get_u16_off20_885F5408(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 32));
}

/* Swing_DLL.xex 0x885F5410: get u32@0x1c */
ts4_word ts4_get_u32_off1c_885F5410(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 28));
}

/* Swing_DLL.xex 0x885F5418: get u32@0x18 */
ts4_word ts4_get_u32_off18_885F5418(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

/* Swing_DLL.xex 0x885F5420: get u16@0x16 */
ts4_word ts4_get_u16_off16_885F5420(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 22));
}

/* Swing_DLL.xex 0x885F5428: get u16@0x14 */
ts4_word ts4_get_u16_off14_885F5428(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x885F5430: get u16@0x18 */
ts4_word ts4_get_u16_off18_885F5430(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 24));
}

/* Swing_DLL.xex 0x885F5438: get u32@0x14 */
ts4_word ts4_get_u32_off14_885F5438(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x885F5440: get u16@0x1a */
ts4_word ts4_get_u16_off1a_885F5440(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 26));
}

/* Swing_DLL.xex 0x885F55B8: fn  */
ts4_word ts4_fn_885F55B8(void)
{
    return 14;
}
