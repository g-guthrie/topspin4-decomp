/* Loader_DLL.xex 0x831D5098-0x832308D8, executable version 0.0.0.3.
   Small accessors, thunks and call sequences (generated, byte-verified). a0 = this/first argument; fields by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char lbl_8302AA08[];
extern char lbl_8302AA48[];
extern char lbl_8302AA88[];
extern char lbl_8302AAA8[];
extern char lbl_8302B268[];
extern char lbl_8302B458[];
extern char lbl_8302B850[];
extern char lbl_8302B8A0[];
extern char lbl_8302B908[];
ts4_word KeWaitForSingleObject();
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_830A6F40();
ts4_word fn_830AABF0();
ts4_word fn_830AAC30();
ts4_word fn_830AF408();
ts4_word fn_830AF558();
ts4_word fn_830AF6E8();
ts4_word fn_830AF778();
ts4_word fn_830B3678();
ts4_word fn_830B3700();
ts4_word fn_830BBD00();
ts4_word fn_831BB278();
ts4_word fn_8321EB08();
ts4_word fn_8321F4A0();
ts4_word fn_83220488();
ts4_word fn_832229D0();
ts4_word fn_83225F90();
ts4_word fn_83226FC0();
ts4_word fn_83227008();
ts4_word fn_832272F0();
ts4_word fn_83227348();
ts4_word fn_8322CD78();
ts4_word fn_8322E7C8();
ts4_word fn_8322EA10();
ts4_word fn_83230840();
ts4_word fn_832333B8();
ts4_word fn_83236198();
ts4_word fn_8340D118();
ts4_word fn_8340D710();
ts4_word fn_8340D830();

/* Loader_DLL.xex 0x831D5098: tailcall fn_831BB278 */
ts4_word ts4_tailcall_fn_831BB278_831D5098(ts4_word a0)
{
    return fn_831BB278((ts4_word)a0);
}

/* Loader_DLL.xex 0x8320C048: set u32@0x60 */
void ts4_set_u32_off60_8320C048(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x8320C058: set u32@0x60 */
void ts4_set_u32_off60_8320C058(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8320C068: get u32@0x60 */
ts4_word ts4_get_u32_off60_8320C068(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 96));
}

/* Loader_DLL.xex 0x8321D5E8: get u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off0_8321D5E8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321D608: get u32@0x0, u32@0x48 */
ts4_word ts4_get_u32_off0_8321D608(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 72))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321DCD0: get u32@0x0, u32@0x58 */
ts4_word ts4_get_u32_off0_8321DCD0(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 88))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321DCE0: get u32@0x0, u32@0x5c */
ts4_word ts4_get_u32_off0_8321DCE0(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 92))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321DD88: get u32@0x0, u32@0x78 */
ts4_word ts4_get_u32_off0_8321DD88(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 120))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321EAD0: call_seq fn_83226FC0 */
ts4_word ts4_call_seq_fn_83226FC0_8321EAD0(ts4_word a0)
{
    fn_83226FC0((ts4_word)a0);
    return a0;
}

/* Loader_DLL.xex 0x8321EB00: tailcall fn_83227008 */
ts4_word ts4_tailcall_fn_83227008_8321EB00(ts4_word a0)
{
    return fn_83227008((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321EC20: get u32@0x0, u32@0x30 */
ts4_word ts4_get_u32_off0_8321EC20(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a0);
}

/* Loader_DLL.xex 0x8321EDF8: fn  */
void ts4_fn_8321EDF8(void)
{
    return;
}

/* Loader_DLL.xex 0x8321EE00: fn  */
ts4_word ts4_fn_8321EE00(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x8321EE60: fn  */
void ts4_fn_8321EE60(void)
{
    return;
}

/* Loader_DLL.xex 0x8321EE68: fn  */
void ts4_fn_8321EE68(void)
{
    return;
}

/* Loader_DLL.xex 0x8321F178: get u32@0x40 */
ts4_word ts4_get_u32_off40_8321F178(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a1)) + 64))))((ts4_word)a0, (ts4_word)a2);
}

/* Loader_DLL.xex 0x8321F190: get u32@0x1d4 */
ts4_word ts4_get_u32_off1d4_8321F190(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a2)) + 468))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a3);
}

/* Loader_DLL.xex 0x8321F1A8: call_seq fn_830A6F40 */
ts4_word ts4_call_seq_fn_830A6F40_8321F1A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    fn_830A6F40((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return 0;
}

/* Loader_DLL.xex 0x8321F308: call_seq fn_830B3678, u32@0x0 */
ts4_word ts4_call_seq_fn_830B3678_8321F308(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;

    t1 = fn_830B3678((ts4_word)a0, (ts4_word)a1, (ts4_word)a3, (ts4_word)a4);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t1;
    return 0;
}

/* Loader_DLL.xex 0x8321F348: call_seq fn_830B3700 */
ts4_word ts4_call_seq_fn_830B3700_8321F348(void)
{
    fn_830B3700();
    return 0;
}

/* Loader_DLL.xex 0x8321F370: call_seq fn_830BBD00 */
ts4_word ts4_call_seq_fn_830BBD00_8321F370(void)
{
    fn_830BBD00();
    return 0;
}

/* Loader_DLL.xex 0x8321F398: call_seq fn_830AF408, u32@0x0 */
ts4_word ts4_call_seq_fn_830AF408_8321F398(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;

    t1 = fn_830AF408((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4);
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t1;
    return 0;
}

/* Loader_DLL.xex 0x8321F3D0: call_seq fn_830AF558 */
ts4_word ts4_call_seq_fn_830AF558_8321F3D0(ts4_word a0)
{
    fn_830AF558((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x8321F3F8: call_seq fn_830AF6E8, u32@0x0 */
ts4_word ts4_call_seq_fn_830AF6E8_8321F3F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;

    t1 = fn_830AF6E8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4);
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t1;
    return 0;
}

/* Loader_DLL.xex 0x8321F430: call_seq fn_830AF778 */
ts4_word ts4_call_seq_fn_830AF778_8321F430(ts4_word a0)
{
    fn_830AF778((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x8321F458: get u32@0x0, u32@0x5c */
ts4_word ts4_get_u32_off0_8321F458(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 92))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321F468: call_seq fn_83226FC0, fn_8321EB08 */
ts4_word ts4_call_seq_fn_83226FC0_8321F468(ts4_word a0)
{
    fn_83226FC0((ts4_word)a0);
    fn_8321EB08((ts4_word)a0);
    return a0;
}

/* Loader_DLL.xex 0x8321F9F8: call_seq fn_8321F4A0, fn_83227008 */
ts4_word ts4_call_seq_fn_8321F4A0_8321F9F8(ts4_word a0)
{
    ts4_word t2;

    fn_8321F4A0((ts4_word)a0);
    t2 = fn_83227008((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x83220028: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83220028(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32773));
}

/* Loader_DLL.xex 0x83220038: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83220038(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32773));
}

/* Loader_DLL.xex 0x83220048: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83220048(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32773));
}

/* Loader_DLL.xex 0x83220058: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83220058(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32773));
}

/* Loader_DLL.xex 0x83220068: addr lbl_8302AA08, u32@0x0, fn_832272F0 */
ts4_word ts4_addr_lbl_8302AA08_83220068(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8302AA08;
    return fn_832272F0((ts4_word)a0);
}

/* Loader_DLL.xex 0x832200C8: set u32@0x38 */
void ts4_set_u32_off38_832200C8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x832200D0: set u32@0x3c */
void ts4_set_u32_off3c_832200D0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x832200D8: set u32@0x40 */
void ts4_set_u32_off40_832200D8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x832200E0: set u32@0x44 */
void ts4_set_u32_off44_832200E0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x832200E8: set  */
void ts4_set_832200E8(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 72) = f1;
    return;
}

/* Loader_DLL.xex 0x832200F0: get u32@0x38 */
ts4_word ts4_get_u32_off38_832200F0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 56));
}

/* Loader_DLL.xex 0x832200F8: get u32@0x3c */
ts4_word ts4_get_u32_off3c_832200F8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 60));
}

/* Loader_DLL.xex 0x83220100: get u32@0x40 */
ts4_word ts4_get_u32_off40_83220100(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 64));
}

/* Loader_DLL.xex 0x83220108: get u32@0x44 */
ts4_word ts4_get_u32_off44_83220108(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 68));
}

/* Loader_DLL.xex 0x83220110: get  */
float ts4_get_83220110(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 72));
}

/* Loader_DLL.xex 0x832201E8: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_832201E8(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32772));
}

/* Loader_DLL.xex 0x832201F8: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_832201F8(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32772));
}

/* Loader_DLL.xex 0x83220208: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83220208(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32772));
}

/* Loader_DLL.xex 0x83220218: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83220218(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32772));
}

/* Loader_DLL.xex 0x83220228: addr lbl_8302AA48, u32@0x0, fn_832272F0 */
ts4_word ts4_addr_lbl_8302AA48_83220228(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8302AA48;
    return fn_832272F0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83220290: set u32@0x38 */
void ts4_set_u32_off38_83220290(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83220298: set u32@0x3c */
void ts4_set_u32_off3c_83220298(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x832202A0: set u32@0x40 */
void ts4_set_u32_off40_832202A0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x832202A8: set u32@0x44 */
void ts4_set_u32_off44_832202A8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x832202B0: set u32@0x48 */
void ts4_set_u32_off48_832202B0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x832202B8: set u32@0x4c */
void ts4_set_u32_off4c_832202B8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x832202C0: set  */
void ts4_set_832202C0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 80) = f1;
    return;
}

/* Loader_DLL.xex 0x832202C8: get u32@0x38 */
ts4_word ts4_get_u32_off38_832202C8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 56));
}

/* Loader_DLL.xex 0x832202D0: get u32@0x3c */
ts4_word ts4_get_u32_off3c_832202D0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 60));
}

/* Loader_DLL.xex 0x832202D8: get u32@0x40 */
ts4_word ts4_get_u32_off40_832202D8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 64));
}

/* Loader_DLL.xex 0x832202E0: get u32@0x44 */
ts4_word ts4_get_u32_off44_832202E0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 68));
}

/* Loader_DLL.xex 0x832202E8: get u32@0x48 */
ts4_word ts4_get_u32_off48_832202E8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 72));
}

/* Loader_DLL.xex 0x832202F0: get u32@0x4c */
ts4_word ts4_get_u32_off4c_832202F0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 76));
}

/* Loader_DLL.xex 0x832202F8: get  */
float ts4_get_832202F8(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 80));
}

/* Loader_DLL.xex 0x832203D8: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_832203D8(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32808));
}

/* Loader_DLL.xex 0x832203E8: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_832203E8(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32808));
}

/* Loader_DLL.xex 0x832203F8: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_832203F8(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32808));
}

/* Loader_DLL.xex 0x83220408: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83220408(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32808));
}

/* Loader_DLL.xex 0x83220480: fn  */
ts4_word ts4_fn_83220480(void)
{
    return 1;
}

/* Loader_DLL.xex 0x83220550: get u32@0x0, u32@0x30 */
ts4_word ts4_get_u32_off0_83220550(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a0);
}

/* Loader_DLL.xex 0x83220568: if_set u32@0x30, u32@0x34 */
ts4_word ts4_if_set_u32_off30_83220568(ts4_word a0, int a1, ts4_word a2, ts4_word a3)
{
    if ((int)a1 != 1) {
        return 0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)a3;
    return 0;
}

/* Loader_DLL.xex 0x83220648: get u32@0x38, u32@0x0 */
ts4_word ts4_get_u32_off38_83220648(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56));
    return 0;
}

/* Loader_DLL.xex 0x83220B58: fn  */
void ts4_fn_83220B58(void)
{
    return;
}

/* Loader_DLL.xex 0x83220B60: addr lbl_8302AA88, u32@0x0 */
void ts4_addr_lbl_8302AA88_83220B60(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8302AA88;
    return;
}

/* Loader_DLL.xex 0x83220B70: fn  */
void ts4_fn_83220B70(void)
{
    return;
}

/* Loader_DLL.xex 0x83220B78: fn  */
void ts4_fn_83220B78(void)
{
    return;
}

/* Loader_DLL.xex 0x83220B80: fn  */
void ts4_fn_83220B80(void)
{
    return;
}

/* Loader_DLL.xex 0x83220B88: fn  */
void ts4_fn_83220B88(void)
{
    return;
}

/* Loader_DLL.xex 0x83220B90: fn  */
void ts4_fn_83220B90(void)
{
    return;
}

/* Loader_DLL.xex 0x83220B98: fn  */
void ts4_fn_83220B98(void)
{
    return;
}

/* Loader_DLL.xex 0x83220C20: call_seq lbl_8302AAA8, u32@0x0, fn_83220488, fn_83227008 */
ts4_word ts4_call_seq_lbl_8302AAA8_83220C20(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8302AAA8;
    fn_83220488((ts4_word)a0);
    t2 = fn_83227008((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x83221058: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83221058(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32810));
}

/* Loader_DLL.xex 0x83221068: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83221068(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32810));
}

/* Loader_DLL.xex 0x83221078: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83221078(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32810));
}

/* Loader_DLL.xex 0x83221088: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83221088(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32810));
}

/* Loader_DLL.xex 0x83221110: fn  */
ts4_word ts4_fn_83221110(void)
{
    return 2;
}

/* Loader_DLL.xex 0x832211F8: fn  */
ts4_word ts4_fn_832211F8(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x83221258: fn  */
void ts4_fn_83221258(void)
{
    return;
}

/* Loader_DLL.xex 0x83221260: fn  */
void ts4_fn_83221260(void)
{
    return;
}

/* Loader_DLL.xex 0x83221570: get u32@0x40 */
ts4_word ts4_get_u32_off40_83221570(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a1)) + 64))))((ts4_word)a0, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83221588: get u32@0x1d4 */
ts4_word ts4_get_u32_off1d4_83221588(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a2)) + 468))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a3);
}

/* Loader_DLL.xex 0x832215E8: if_get u32@0x110, u32@0x11c */
ts4_word ts4_if_get_u32_off110_832215E8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 272);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word))(t1))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 284)));
}

/* Loader_DLL.xex 0x83221E78: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83221E78(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32797));
}

/* Loader_DLL.xex 0x83221E88: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83221E88(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32797));
}

/* Loader_DLL.xex 0x83221E98: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83221E98(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32797));
}

/* Loader_DLL.xex 0x83221EA8: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83221EA8(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32797));
}

/* Loader_DLL.xex 0x83221EB8: call_seq fn_83226FC0, fn_83227348 */
ts4_word ts4_call_seq_fn_83226FC0_83221EB8(ts4_word a0)
{
    fn_83226FC0((ts4_word)a0);
    fn_83227348((ts4_word)(a0 + 56));
    return a0;
}

/* Loader_DLL.xex 0x83221EF0: call_seq fn_832272F0, fn_83227008 */
ts4_word ts4_call_seq_fn_832272F0_83221EF0(ts4_word a0)
{
    ts4_word t2;

    fn_832272F0((ts4_word)(a0 + 56));
    t2 = fn_83227008((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x83221F80: fn  */
ts4_word ts4_fn_83221F80(void)
{
    return 8;
}

/* Loader_DLL.xex 0x83222BB0: tailcall fn_832229D0 */
ts4_word ts4_tailcall_fn_832229D0_83222BB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return fn_832229D0((ts4_word)a4);
}

/* Loader_DLL.xex 0x83222CA0: get u32@0x78 */
ts4_word ts4_get_u32_off78_83222CA0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 120));
}

/* Loader_DLL.xex 0x83222EC8: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83222EC8(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32791));
}

/* Loader_DLL.xex 0x83222ED8: if_fn  */
ts4_word ts4_if_fn_83222ED8(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        if ((ts4_word)a0 > 11 && (ts4_word)a0 <= 14) {
            return ((3222077440) | 10416);
        }
        return ((2147483648) | 16389);
    }
    return 0;
}

/* Loader_DLL.xex 0x83222F10: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83222F10(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32791));
}

/* Loader_DLL.xex 0x83222F20: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83222F20(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32791));
}

/* Loader_DLL.xex 0x83222F30: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83222F30(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32791));
}

/* Loader_DLL.xex 0x83222F88: fn  */
ts4_word ts4_fn_83222F88(void)
{
    return 6;
}

/* Loader_DLL.xex 0x832243C8: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_832243C8(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32817));
}

/* Loader_DLL.xex 0x832243D8: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_832243D8(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32817));
}

/* Loader_DLL.xex 0x832243E8: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_832243E8(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32817));
}

/* Loader_DLL.xex 0x832243F8: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_832243F8(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32817));
}

/* Loader_DLL.xex 0x83224468: get u32@0x0, u32@0x2c */
ts4_word ts4_get_u32_off0_83224468(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 44))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83224A78: get u32@0x0, u32@0x78 */
ts4_word ts4_get_u32_off0_83224A78(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 120))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83224A88: set  */
ts4_word ts4_set_83224A88(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 340) = f1;
    return 0;
}

/* Loader_DLL.xex 0x83224ED0: get u32@0x144, u32@0x144 */
ts4_word ts4_get_u32_off144_83224ED0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 324) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 324)) + 1);
    return 0;
}

/* Loader_DLL.xex 0x83224F98: get u32@0x140, u32@0x140 */
ts4_word ts4_get_u32_off140_83224F98(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 320) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 320)) + 1);
    return 0;
}

/* Loader_DLL.xex 0x83224FB0: if_get u32@0x148, u32@0x148, u32@0x144, u32@0x144, u32@0x140, u32@0x140 */
ts4_word ts4_if_get_u32_off148_83224FB0(ts4_word a0, int a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 328) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 328)) + 1);
    if ((int)a1 != 0) {
        return 0;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 324) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 324)) + 1);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 320) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 320)) + 1);
    return 0;
}

/* Loader_DLL.xex 0x83225168: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83225168(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32819));
}

/* Loader_DLL.xex 0x83225178: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83225178(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32819));
}

/* Loader_DLL.xex 0x83225188: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83225188(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32819));
}

/* Loader_DLL.xex 0x83225198: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83225198(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32819));
}

/* Loader_DLL.xex 0x832251A8: call_seq fn_83230840, lbl_8302B268, u32@0x0 */
ts4_word ts4_call_seq_fn_83230840_832251A8(ts4_word a0)
{
    fn_83230840((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8302B268;
    return a0;
}

/* Loader_DLL.xex 0x832251E8: addr lbl_8302B268, u32@0x0, fn_832333B8 */
ts4_word ts4_addr_lbl_8302B268_832251E8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8302B268;
    return fn_832333B8((ts4_word)a0);
}

/* Loader_DLL.xex 0x83225260: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83225260(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32780));
}

/* Loader_DLL.xex 0x83225270: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83225270(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32780));
}

/* Loader_DLL.xex 0x83225280: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83225280(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32780));
}

/* Loader_DLL.xex 0x83225290: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83225290(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32780));
}

/* Loader_DLL.xex 0x832252A0: call_seq fn_83226FC0 */
ts4_word ts4_call_seq_fn_83226FC0_832252A0(ts4_word a0)
{
    fn_83226FC0((ts4_word)a0);
    return a0;
}

/* Loader_DLL.xex 0x832252D0: tailcall fn_83227008 */
ts4_word ts4_tailcall_fn_83227008_832252D0(ts4_word a0)
{
    return fn_83227008((ts4_word)a0);
}

/* Loader_DLL.xex 0x832252D8: set u64@0x30, u32@0x2c, u32@0x38, u32@0x3c */
void ts4_set_u64_off30_832252D8(ts4_word a0)
{
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 48) = (ts4_u64)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x832252F8: fn  */
ts4_word ts4_fn_832252F8(void)
{
    return 8;
}

/* Loader_DLL.xex 0x83225368: get u32@0x0, u32@0x64, vcall */
ts4_word ts4_get_u32_off0_83225368(ts4_word a0)
{
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 100))))((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x832253B8: set u64@0x30, u32@0x2c */
ts4_word ts4_set_u64_off30_832253B8(ts4_word a0)
{
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 48) = (ts4_u64)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    return 0;
}

/* Loader_DLL.xex 0x83225440: fn  */
ts4_word ts4_fn_83225440(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x83225450: fn  */
ts4_word ts4_fn_83225450(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x83225460: fn  */
ts4_word ts4_fn_83225460(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x83225470: fn  */
ts4_word ts4_fn_83225470(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83225478: fn  */
ts4_word ts4_fn_83225478(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83225480: fn  */
ts4_word ts4_fn_83225480(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83225488: fn  */
ts4_word ts4_fn_83225488(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83225490: get u32@0x2c */
ts4_word ts4_get_u32_off2c_83225490(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 44));
}

/* Loader_DLL.xex 0x832254F0: fn  */
ts4_word ts4_fn_832254F0(void)
{
    return 0;
}

/* Loader_DLL.xex 0x832254F8: fn  */
ts4_word ts4_fn_832254F8(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x832255C8: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_832255C8(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32781));
}

/* Loader_DLL.xex 0x832255D8: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_832255D8(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32781));
}

/* Loader_DLL.xex 0x832255E8: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_832255E8(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32781));
}

/* Loader_DLL.xex 0x832255F8: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_832255F8(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32781));
}

/* Loader_DLL.xex 0x83225608: set u32@0x2c, u32@0x30, u32@0x34, u32@0x38 */
void ts4_set_u32_off2c_83225608(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83225620: fn  */
ts4_word ts4_fn_83225620(void)
{
    return 4;
}

/* Loader_DLL.xex 0x832256A0: if_get u32@0x0, u32@0x30, vcall, u32@0x2c, u32@0x30 */
ts4_word ts4_if_get_u32_off0_832256A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    int t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0);
    if ((int)t3 >= 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)a2;
    }
    return t3;
}

/* Loader_DLL.xex 0x83225760: if_set u32@0x34, u32@0x30, u32@0x34 */
ts4_word ts4_if_set_u32_off34_83225760(ts4_word a0, int a1)
{
    if ((int)a1 != 1 && (int)a1 == 3) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48));
        return 0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    return 0;
}

/* Loader_DLL.xex 0x832258B8: fn  */
ts4_word ts4_fn_832258B8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x832258D8: get u32@0x2c */
ts4_word ts4_get_u32_off2c_832258D8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 44));
}

/* Loader_DLL.xex 0x832258E0: get u32@0x34, u32@0x2c */
ts4_word ts4_get_u32_off34_832258E0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    return (t1 + (*(ts4_word *)((char *)(ts4_word)(a0) + 44)));
}

/* Loader_DLL.xex 0x832258F0: get u32@0x30 */
ts4_word ts4_get_u32_off30_832258F0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 48));
}

/* Loader_DLL.xex 0x832258F8: get u32@0x34 */
ts4_word ts4_get_u32_off34_832258F8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 52));
}

/* Loader_DLL.xex 0x83225A70: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83225A70(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32778));
}

/* Loader_DLL.xex 0x83225A80: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83225A80(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32778));
}

/* Loader_DLL.xex 0x83225A90: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83225A90(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32778));
}

/* Loader_DLL.xex 0x83225AA0: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83225AA0(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32778));
}

/* Loader_DLL.xex 0x83225B00: fn  */
ts4_word ts4_fn_83225B00(void)
{
    return 2;
}

/* Loader_DLL.xex 0x83226DE8: fn  */
ts4_word ts4_fn_83226DE8(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x83226DF8: fn  */
ts4_word ts4_fn_83226DF8(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x83226E08: fn  */
ts4_word ts4_fn_83226E08(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x83226E18: fn  */
ts4_word ts4_fn_83226E18(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83226E20: fn  */
ts4_word ts4_fn_83226E20(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83226E38: fn  */
ts4_word ts4_fn_83226E38(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83226E40: get u32@0x30 */
ts4_word ts4_get_u32_off30_83226E40(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 48));
}

/* Loader_DLL.xex 0x83226ED0: call_seq lbl_8302B458, u32@0x0, fn_83225F90, fn_83227008 */
ts4_word ts4_call_seq_lbl_8302B458_83226ED0(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8302B458;
    fn_83225F90();
    t2 = fn_83227008((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x83226F80: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83226F80(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32769));
}

/* Loader_DLL.xex 0x83226F90: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83226F90(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32769));
}

/* Loader_DLL.xex 0x83226FA0: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83226FA0(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32769));
}

/* Loader_DLL.xex 0x83226FB0: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83226FB0(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32769));
}

/* Loader_DLL.xex 0x832270B8: call_seq RtlEnterCriticalSection */
ts4_word ts4_call_seq_RtlEnterCriticalSection_832270B8(ts4_word a0)
{
    RtlEnterCriticalSection((ts4_word)(a0 + 16));
    return 0;
}

/* Loader_DLL.xex 0x83227118: call_seq RtlLeaveCriticalSection */
ts4_word ts4_call_seq_RtlLeaveCriticalSection_83227118(ts4_word a0)
{
    RtlLeaveCriticalSection((ts4_word)(a0 + 16));
    return 0;
}

/* Loader_DLL.xex 0x832271E8: if_call_seq fn_8340D118 */
ts4_word ts4_if_call_seq_fn_8340D118_832271E8(void)
{
    ts4_word p2;
    int t1;

    t1 = fn_8340D118();
    p2 = (ts4_word)t1;
    if ((int)t1 > 0) {
        p2 = (ts4_word)((t1 & 0xffff) | 2147942400);
    }
    return p2;
}

/* Loader_DLL.xex 0x83227218: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83227218(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32807));
}

/* Loader_DLL.xex 0x83227228: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83227228(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32807));
}

/* Loader_DLL.xex 0x83227238: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83227238(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32807));
}

/* Loader_DLL.xex 0x83227248: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83227248(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32807));
}

/* Loader_DLL.xex 0x83227258: set u32@0x30, u32@0x34, u32@0x2c */
void ts4_set_u32_off30_83227258(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83227270: fn  */
ts4_word ts4_fn_83227270(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x83227280: fn  */
ts4_word ts4_fn_83227280(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x83227290: fn  */
ts4_word ts4_fn_83227290(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x832272A0: fn  */
ts4_word ts4_fn_832272A0(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x832272B0: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_832272B0(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32771));
}

/* Loader_DLL.xex 0x832272C0: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_832272C0(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32771));
}

/* Loader_DLL.xex 0x832272D0: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_832272D0(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32771));
}

/* Loader_DLL.xex 0x832272E0: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_832272E0(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32771));
}

/* Loader_DLL.xex 0x83227300: set u32@0x2c, u32@0x30, u32@0x34 */
void ts4_set_u32_off2c_83227300(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83227318: set u32@0x2c */
void ts4_set_u32_off2c_83227318(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83227320: set u32@0x30 */
void ts4_set_u32_off30_83227320(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83227328: set u32@0x34 */
void ts4_set_u32_off34_83227328(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83227330: get u32@0x2c */
ts4_word ts4_get_u32_off2c_83227330(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 44));
}

/* Loader_DLL.xex 0x83227338: get u32@0x30 */
ts4_word ts4_get_u32_off30_83227338(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 48));
}

/* Loader_DLL.xex 0x83227340: get u32@0x34 */
ts4_word ts4_get_u32_off34_83227340(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 52));
}

/* Loader_DLL.xex 0x83227400: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83227400(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32793));
}

/* Loader_DLL.xex 0x83227410: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83227410(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32793));
}

/* Loader_DLL.xex 0x83227420: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83227420(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32793));
}

/* Loader_DLL.xex 0x83227430: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83227430(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32793));
}

/* Loader_DLL.xex 0x832274A0: fn  */
ts4_word ts4_fn_832274A0(void)
{
    return 2;
}

/* Loader_DLL.xex 0x83227548: set u32@0x1f4, u32@0x1f8 */
ts4_word ts4_set_u32_off1f4_83227548(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 500) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 504) = (ts4_word)a2;
    return 0;
}

/* Loader_DLL.xex 0x83227588: set u32@0x200 */
void ts4_set_u32_off200_83227588(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 512) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x832289B0: fn  */
ts4_word ts4_fn_832289B0(void)
{
    return 29;
}

/* Loader_DLL.xex 0x8322BFD0: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8322BFD0(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32824));
}

/* Loader_DLL.xex 0x8322BFE0: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8322BFE0(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32824));
}

/* Loader_DLL.xex 0x8322BFF0: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8322BFF0(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32824));
}

/* Loader_DLL.xex 0x8322C000: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8322C000(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32824));
}

/* Loader_DLL.xex 0x8322C010: addr lbl_8302B850, u32@0x0, fn_83236198 */
ts4_word ts4_addr_lbl_8302B850_8322C010(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8302B850;
    return fn_83236198((ts4_word)a0);
}

/* Loader_DLL.xex 0x8322C0D0: set u32@0x11c */
void ts4_set_u32_off11c_8322C0D0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 284) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x8322C0D8: get u32@0x11c */
ts4_word ts4_get_u32_off11c_8322C0D8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 284));
}

/* Loader_DLL.xex 0x8322C0E0: get u32@0x0, u32@0x30 */
ts4_word ts4_get_u32_off0_8322C0E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)40, (ts4_word)(a0 + 124));
}

/* Loader_DLL.xex 0x8322C0F8: fn  */
ts4_word ts4_fn_8322C0F8(ts4_word a0)
{
    return (a0 + 124);
}

/* Loader_DLL.xex 0x8322C100: get u32@0x0, u32@0x30 */
ts4_word ts4_get_u32_off0_8322C100(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)40, (ts4_word)(a0 + 204));
}

/* Loader_DLL.xex 0x8322C118: fn  */
ts4_word ts4_fn_8322C118(ts4_word a0)
{
    return (a0 + 204);
}

/* Loader_DLL.xex 0x8322C1F8: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8322C1F8(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32786));
}

/* Loader_DLL.xex 0x8322C208: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8322C208(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32786));
}

/* Loader_DLL.xex 0x8322C218: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8322C218(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32786));
}

/* Loader_DLL.xex 0x8322C228: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8322C228(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32786));
}

/* Loader_DLL.xex 0x8322C238: fn  */
ts4_word ts4_fn_8322C238(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8322C248: set u32@0x2c, u32@0x34, u32@0x30, u32@0x70, u32@0x74, u32@0x78 */
void ts4_set_u32_off2c_8322C248(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8322C2B8: fn  */
ts4_word ts4_fn_8322C2B8(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8322C2C8: fn  */
ts4_word ts4_fn_8322C2C8(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8322C2D8: fn  */
ts4_word ts4_fn_8322C2D8(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8322C2E8: fn  */
ts4_word ts4_fn_8322C2E8(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8322C2F8: fn  */
ts4_word ts4_fn_8322C2F8(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8322C308: fn  */
ts4_word ts4_fn_8322C308(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8322C318: fn  */
ts4_word ts4_fn_8322C318(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8322C328: fn  */
ts4_word ts4_fn_8322C328(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8322C338: fn  */
ts4_word ts4_fn_8322C338(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8322C348: fn  */
ts4_word ts4_fn_8322C348(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8322C358: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8322C358(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32787));
}

/* Loader_DLL.xex 0x8322C368: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8322C368(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32787));
}

/* Loader_DLL.xex 0x8322C378: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8322C378(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32787));
}

/* Loader_DLL.xex 0x8322C388: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8322C388(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32787));
}

/* Loader_DLL.xex 0x8322C3E0: fn  */
ts4_word ts4_fn_8322C3E0(void)
{
    return 1;
}

/* Loader_DLL.xex 0x8322C488: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8322C488(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((613154816) | 32768));
}

/* Loader_DLL.xex 0x8322C498: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8322C498(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((613154816) | 32768));
}

/* Loader_DLL.xex 0x8322C918: if_get u16@0xee, u16@0x0 */
ts4_word ts4_if_get_u16_offee_8322C918(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        *(unsigned short *)((char *)(ts4_word)(a1) + 0) = (unsigned short)(*(unsigned short *)((char *)(ts4_word)(a0) + 238));
        return 0;
    }
    return 2;
}

/* Loader_DLL.xex 0x8322C9F8: if_get u32@0xdc, u32@0x0, u32@0xe0 */
ts4_word ts4_if_get_u32_offdc_8322C9F8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 220));
        return (*(ts4_word *)((char *)(ts4_word)(a0) + 224));
    }
    return 0;
}

/* Loader_DLL.xex 0x8322CD48: if_set u32@0x228, u32@0x250, u32@0x228 */
ts4_word ts4_if_set_u32_off228_8322CD48(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 592) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 552) = (ts4_word)1;
        return 0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 552) = (ts4_word)0;
    return 0;
}

/* Loader_DLL.xex 0x8322D7E0: if_get u32@0xcc, u32@0x0 */
ts4_word ts4_if_get_u32_offcc_8322D7E0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 204));
        return 0;
    }
    return 2;
}

/* Loader_DLL.xex 0x8322D808: if_get u32@0xd0, u32@0x0 */
ts4_word ts4_if_get_u32_offd0_8322D808(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 208));
        return 0;
    }
    return 2;
}

/* Loader_DLL.xex 0x8322D970: if_get u32@0x224 */
ts4_word ts4_if_get_u32_off224_8322D970(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        return ((((*(ts4_word *)((char *)(ts4_word)(a0) + 548)) == 0) ^ 1) + 13);
    }
    return 2;
}

/* Loader_DLL.xex 0x8322E2F8: call_seq fn_8322CD78 */
ts4_word ts4_call_seq_fn_8322CD78_8322E2F8(ts4_word a0)
{
    ts4_word loc50[6];
    ts4_word t1;

    t1 = fn_8322CD78((ts4_word)a0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)1);
    return t1;
}

/* Loader_DLL.xex 0x8322E778: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8322E778(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32823));
}

/* Loader_DLL.xex 0x8322E788: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8322E788(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32823));
}

/* Loader_DLL.xex 0x8322E798: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8322E798(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32823));
}

/* Loader_DLL.xex 0x8322E7A8: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8322E7A8(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32823));
}

/* Loader_DLL.xex 0x8322E7B8: addr lbl_8302B8A0, u32@0x0, fn_83236198 */
ts4_word ts4_addr_lbl_8302B8A0_8322E7B8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8302B8A0;
    return fn_83236198((ts4_word)a0);
}

/* Loader_DLL.xex 0x8322E848: tailcall fn_8322E7C8 */
ts4_word ts4_tailcall_fn_8322E7C8_8322E848(ts4_word a0)
{
    return fn_8322E7C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8322E850: set u32@0x1bc */
void ts4_set_u32_off1bc_8322E850(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 444) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x8322E858: get u32@0x1bc */
ts4_word ts4_get_u32_off1bc_8322E858(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 444));
}

/* Loader_DLL.xex 0x8322E860: set u32@0x1c0 */
void ts4_set_u32_off1c0_8322E860(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 448) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x8322E868: get u32@0x1c0 */
ts4_word ts4_get_u32_off1c0_8322E868(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 448));
}

/* Loader_DLL.xex 0x8322E870: get u32@0x0, u32@0x30 */
ts4_word ts4_get_u32_off0_8322E870(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)40, (ts4_word)(a0 + 124));
}

/* Loader_DLL.xex 0x8322E888: fn  */
ts4_word ts4_fn_8322E888(ts4_word a0)
{
    return (a0 + 124);
}

/* Loader_DLL.xex 0x8322E890: get u32@0x0, u32@0x30 */
ts4_word ts4_get_u32_off0_8322E890(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)40, (ts4_word)(a0 + 364));
}

/* Loader_DLL.xex 0x8322E8A8: fn  */
ts4_word ts4_fn_8322E8A8(ts4_word a0)
{
    return (a0 + 364);
}

/* Loader_DLL.xex 0x8322E8B0: get u32@0x0, u32@0x30 */
ts4_word ts4_get_u32_off0_8322E8B0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)40, (ts4_word)(a0 + 284));
}

/* Loader_DLL.xex 0x8322E8C8: fn  */
ts4_word ts4_fn_8322E8C8(ts4_word a0)
{
    return (a0 + 284);
}

/* Loader_DLL.xex 0x8322E8D0: get u32@0x0, u32@0x30 */
ts4_word ts4_get_u32_off0_8322E8D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)40, (ts4_word)(a0 + 204));
}

/* Loader_DLL.xex 0x8322E8E8: fn  */
ts4_word ts4_fn_8322E8E8(ts4_word a0)
{
    return (a0 + 204);
}

/* Loader_DLL.xex 0x8322E9A0: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8322E9A0(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32782));
}

/* Loader_DLL.xex 0x8322E9B0: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8322E9B0(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32782));
}

/* Loader_DLL.xex 0x8322E9C0: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8322E9C0(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32782));
}

/* Loader_DLL.xex 0x8322E9D0: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8322E9D0(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32782));
}

/* Loader_DLL.xex 0x8322E9E0: set u32@0x38, u32@0x3c, u32@0x40, u32@0x2c, u32@0x30, u32@0x34 */
void ts4_set_u32_off38_8322E9E0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8322EA08: fn  */
ts4_word ts4_fn_8322EA08(void)
{
    return 5;
}

/* Loader_DLL.xex 0x8322EAB0: get u32@0x40, u32@0x30, u32@0x34 */
ts4_word ts4_get_u32_off40_8322EAB0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((int)t1 * 60)) + t2))) + 52))))((ts4_word)(((int)t1 * 60) + t2), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x8322EAD0: get u32@0x40, u32@0x30, u32@0x38 */
ts4_word ts4_get_u32_off40_8322EAD0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((int)t1 * 60)) + t2))) + 56))))((ts4_word)(((int)t1 * 60) + t2), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x8322EAF0: get u32@0x40, u32@0x30, u32@0x3c */
ts4_word ts4_get_u32_off40_8322EAF0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((int)t1 * 60)) + t2))) + 60))))((ts4_word)(((int)t1 * 60) + t2), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x8322EB10: get u32@0x40, u32@0x30, u32@0x40 */
ts4_word ts4_get_u32_off40_8322EB10(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((int)t1 * 60)) + t2))) + 64))))((ts4_word)(((int)t1 * 60) + t2), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x8322EB50: get u32@0x40, u32@0x30, u32@0x48 */
ts4_word ts4_get_u32_off40_8322EB50(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((int)t1 * 60)) + t2))) + 72))))((ts4_word)(((int)t1 * 60) + t2), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x8322EC10: get u32@0x44 */
ts4_word ts4_get_u32_off44_8322EC10(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 68));
}

/* Loader_DLL.xex 0x8322EC18: get u32@0x44, u32@0x34 */
ts4_word ts4_get_u32_off44_8322EC18(ts4_word a0)
{
    ts4_word t1;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68);
    return ((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 52)) - t1);
}

/* Loader_DLL.xex 0x8322EC28: get u32@0x38, u32@0x40 */
ts4_word ts4_get_u32_off38_8322EC28(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56));
    return 0;
}

/* Loader_DLL.xex 0x8322EC40: get u32@0x3c, u32@0x40 */
ts4_word ts4_get_u32_off3c_8322EC40(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60));
    return 0;
}

/* Loader_DLL.xex 0x8322EC58: set u32@0x40 */
ts4_word ts4_set_u32_off40_8322EC58(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)a1;
    return 0;
}

/* Loader_DLL.xex 0x8322EE70: set u32@0x38, u32@0x3c, u32@0x40, u32@0x44 */
void ts4_set_u32_off38_8322EE70(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8322EEE8: call_seq lbl_8302B908, u32@0x0, fn_8322EA10, fn_83227008 */
ts4_word ts4_call_seq_lbl_8302B908_8322EEE8(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8302B908;
    fn_8322EA10((ts4_word)a0);
    t2 = fn_83227008((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x8322F2D0: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8322F2D0(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32818));
}

/* Loader_DLL.xex 0x8322F2E0: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8322F2E0(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32818));
}

/* Loader_DLL.xex 0x8322F2F0: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8322F2F0(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32818));
}

/* Loader_DLL.xex 0x8322F300: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8322F300(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32818));
}

/* Loader_DLL.xex 0x8322F418: fn  */
ts4_word ts4_fn_8322F418(void)
{
    return 4;
}

/* Loader_DLL.xex 0x8322F520: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_8322F520(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a0;
    return;
}

/* Loader_DLL.xex 0x8322F530: get u32@0x0, u32@0x38 */
ts4_word ts4_get_u32_off0_8322F530(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a0);
}

/* Loader_DLL.xex 0x8322F660: get u32@0x0, u32@0x4, u32@0x4c */
ts4_word ts4_get_u32_off0_8322F660(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 76))))((ts4_word)a0, (ts4_word)t2, (ts4_word)(a1 + 8), (ts4_word)a1);
}

/* Loader_DLL.xex 0x8322F680: get u32@0x0, u32@0x4c */
ts4_word ts4_get_u32_off0_8322F680(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 76))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Loader_DLL.xex 0x8322F9A0: fn  */
ts4_word ts4_fn_8322F9A0(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x83230678: get u32@0x0, u32@0x84 */
ts4_word ts4_get_u32_off0_83230678(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 132))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83230688: get u32@0x0, u32@0x88 */
ts4_word ts4_get_u32_off0_83230688(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 136))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83230698: get u32@0x0, u32@0x8c, vcall */
ts4_word ts4_get_u32_off0_83230698(ts4_word a0)
{
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 140))))((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x832306C8: get u32@0x0, u32@0x90, vcall */
ts4_word ts4_get_u32_off0_832306C8(ts4_word a0)
{
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 144))))((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x832306F8: get u32@0x0, u32@0x94, vcall */
ts4_word ts4_get_u32_off0_832306F8(ts4_word a0)
{
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 148))))((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x83230728: get u32@0x0, u32@0x98, vcall */
ts4_word ts4_get_u32_off0_83230728(ts4_word a0)
{
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 152))))((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x83230758: call_seq fn_830AABF0 */
ts4_word ts4_call_seq_fn_830AABF0_83230758(ts4_word a0)
{
    fn_830AABF0((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x83230780: call_seq fn_830AAC30 */
ts4_word ts4_call_seq_fn_830AAC30_83230780(ts4_word a0)
{
    fn_830AAC30((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x83230880: tailcall KeWaitForSingleObject */
ts4_word ts4_tailcall_KeWaitForSingleObject_83230880(ts4_word a0)
{
    return KeWaitForSingleObject((ts4_word)(a0 + 84), (ts4_word)3, (ts4_word)1, (ts4_word)0, (ts4_word)0);
}

/* Loader_DLL.xex 0x83230898: tailcall KeWaitForSingleObject */
ts4_word ts4_tailcall_KeWaitForSingleObject_83230898(ts4_word a0)
{
    return KeWaitForSingleObject((ts4_word)(a0 + 100), (ts4_word)3, (ts4_word)1, (ts4_word)0, (ts4_word)0);
}
