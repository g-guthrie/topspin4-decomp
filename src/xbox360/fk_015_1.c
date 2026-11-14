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
ts4_word ts4_counted_ref_release_88475B08();
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
ts4_word ts4_atomic_interlocked_inc_885A6158();
ts4_word ts4_forward_this_plus_16_885A6190();
ts4_word fn_885A6878();
ts4_word fn_885A6C48();
ts4_word ts4_atomic_interlocked_inc_885A6E08();
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
ts4_word ts4_pool_free_885B72F0();
ts4_word fn_885B73E8();
ts4_word fn_885B80C0();
ts4_word fn_885B89A0();
ts4_word fn_885B8A58();
ts4_word fn_885B8DF8();
ts4_word fn_885B8EB8();
ts4_word ts4_if_call_seq_u32_off30_885B8FB0();
ts4_word fn_885B93D0();
ts4_word fn_885C1AD8();
ts4_word fn_885C2038();
ts4_word fn_885C24A0();
ts4_word fn_885C3348();
ts4_word fn_885C3770();
ts4_word ts4_ensure_open_885CE510();
ts4_word ts4_ensure_closed_885CE568();
ts4_word fn_885D4EF0();
ts4_word fn_885DC838();
ts4_word ts4_if_call_seq_lbl_880B4540_885DCAF8();
ts4_word fn_885DD1F8();
ts4_word ts4_if_get_u32_off4_885E3B10();
ts4_word ts4_if_get_u32_off8_885E3B30();
ts4_word fn_885E3BA8();
ts4_word fn_885E3F20();
ts4_word fn_885E40C8();
ts4_word fn_885E76C0();
ts4_word fn_885E7AD8();
ts4_word fn_885E7BA8();
ts4_word fn_885E8F50();
ts4_word fn_885EA1A8();
ts4_word ts4_pooled_deleting_dtor_885EAAD0();
ts4_word ts4_pooled_deleting_dtor_885EAC80();
ts4_word fn_885EB698();
ts4_word fn_885EBBC8();
ts4_word ts4_ref_holder_dtor_nullable_885EC7D8();
ts4_word fn_885EC938();
ts4_word ts4_ref_holder_dtor_885ED798();
ts4_word ts4_call_runtime_2890();
ts4_word ts4_forward_885A9E30();
ts4_word ts4_forward_885DBBA8();
ts4_word ts4_runtime_type_code_none();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x885B9328: call_seq ts4_if_call_seq_u32_off30_885B8FB0 */
ts4_word ts4_call_seq_fn_885B8FB0_885B9328(ts4_word a0)
{
    ts4_if_call_seq_u32_off30_885B8FB0((ts4_word)(a0 + -4));
    return 0;
}

/* Swing_DLL.xex 0x885DCBE0: if_call_seq lbl_880B4540, lbl_880B6868, lbl_880B692C, fn_885DC838, lbl_880B691C, fn_885DC838 */
ts4_word ts4_if_call_seq_lbl_880B4540_885DCBE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t5;
    ts4_word t9;
    ts4_word t10;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    if ((ts4_word)a0 == 0) {
        fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880B692C, (ts4_word)(ts4_word)lbl_880B6868, (ts4_word)3105);
    }
    if ((ts4_word)a1 == 0) {
        fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880B691C, (ts4_word)(ts4_word)lbl_880B6868, (ts4_word)3106);
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)a1 == (ts4_word)t5) {
        fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880B6938, (ts4_word)(ts4_word)lbl_880B6868, (ts4_word)3107);
    }
    t9 = ts4_if_call_seq_lbl_880B4540_885DCAF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)a1);
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t10 == 0) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 8) = (ts4_word)a1;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20)) + 1);
    return t9;
}

/* Swing_DLL.xex 0x885E6CF0: call_seq u32@0x74, ts4_if_get_u32_off4_885E3B10, u32@0x3b4 */
ts4_word ts4_call_seq_u32_off74_885E6CF0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    t2 = ts4_if_get_u32_off4_885E3B10((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 116)));
    *(ts4_word *)((char *)(ts4_word)(a1) + 948) = (ts4_word)a0;
    return t2;
}

/* Swing_DLL.xex 0x885E6D38: call_seq u32@0x70, ts4_if_get_u32_off8_885E3B30, u32@0x3b4 */
ts4_word ts4_call_seq_u32_off70_885E6D38(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    t2 = ts4_if_get_u32_off8_885E3B30((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 112)));
    *(ts4_word *)((char *)(ts4_word)(a1) + 948) = (ts4_word)a0;
    return t2;
}

/* Swing_DLL.xex 0x885EC4B0: if_call_seq fn_885EBBC8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_885EBBC8_885EC4B0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_885EBBC8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x885ED540: if_call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u32@0x0, u32@0x4, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88CACF08_885ED540(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)(a0 + 20), (ts4_word)23);
    if ((ts4_word)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t3) + 16) = (ts4_word)0;
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x885F4188: if_call_seq lbl_880869E8, lbl_8803A308, u32@0x8, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue */
ts4_word ts4_if_call_seq_lbl_880869E8_885F4188(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_880869E8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

