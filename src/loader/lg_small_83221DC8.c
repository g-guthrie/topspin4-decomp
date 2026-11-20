/* Loader_DLL.xex 0x83221DC8-0x83354358, executable version 0.0.0.3.
   Small accessors, thunks and call sequences (generated, byte-verified). a0 = this/first argument; fields by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char fn_83258730[];
extern char fn_83258C28[];
extern char fn_83267388[];
extern char fn_832AAC00[];
extern char fn_83315048[];
extern char fn_833151D8[];
extern char lbl_8302AFB8[];
extern char lbl_8302B968[];
extern char lbl_8302BD80[];
extern char lbl_8302CFA4[];
extern char lbl_83037A24[];
extern char lbl_8352A3B4[];
extern char lbl_8352A3B8[];
extern char lbl_8353AF58[];
ts4_word KeResetEvent();
ts4_word KeSetEvent();
ts4_word KeWaitForSingleObject();
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word XeCryptAesEcb();
ts4_word XeCryptRandom();
ts4_word XeCryptRc4Ecb();
ts4_word fn_830AFD98();
ts4_word fn_830AFEA0();
ts4_word fn_830B0108();
ts4_word fn_830BBB18();
ts4_word fn_830BBB98();
ts4_word fn_830BBC00();
ts4_word fn_8321F9F8();
ts4_word fn_832200E8();
ts4_word fn_83221648();
ts4_word fn_83226FC0();
ts4_word fn_8322F310();
ts4_word fn_8323D488();
ts4_word fn_8324E680();
ts4_word fn_83250130();
ts4_word fn_83250938();
ts4_word fn_83251030();
ts4_word fn_83251860();
ts4_word fn_83251D20();
ts4_word fn_832597A0();
ts4_word fn_83261930();
ts4_word fn_832623A8();
ts4_word fn_832674B0();
ts4_word fn_8326F898();
ts4_word fn_83272FA0();
ts4_word fn_832753A8();
ts4_word fn_832755A0();
ts4_word fn_83278488();
ts4_word fn_83279A08();
ts4_word fn_83279B30();
ts4_word fn_83279BF0();
ts4_word fn_8327F478();
ts4_word fn_832806D8();
ts4_word fn_832810B0();
ts4_word fn_8328B4F0();
ts4_word fn_8328B5B0();
ts4_word fn_832A2B08();
ts4_word fn_832A3580();
ts4_word fn_832A3678();
ts4_word fn_832A6E48();
ts4_word fn_832AAC88();
ts4_word fn_832DC698();
ts4_word fn_832E8490();
ts4_word fn_8331D100();
ts4_word fn_8331D210();
ts4_word fn_8331D2F0();
ts4_word fn_8331F6E8();
ts4_word fn_8331F860();
ts4_word fn_8331FA10();
ts4_word fn_833201C8();
ts4_word fn_8333E548();
ts4_word fn_8333E630();
ts4_word fn_833541A0();
ts4_word fn_83371D30();
ts4_word fn_83395960();
ts4_word fn_833959D8();
ts4_word fn_833A1F10();
ts4_word fn_833E0AB0();
ts4_word fn_833E1758();
ts4_word fn_833E3A30();
ts4_word fn_833E3AD0();
ts4_word fn_833E73F8();
ts4_word fn_833E74C0();
ts4_word fn_8340C4F8();
ts4_word fn_8340CE50();
ts4_word fn_8340D710();
ts4_word fn_8340D830();
ts4_word fn_83413AA0();
ts4_word fn_83496E70();
ts4_word fn_834B8568();
ts4_word fn_834D2E00();
ts4_word fn_834D38C0();

/* Loader_DLL.xex 0x83221DC8: call_seq lbl_8302AFB8, u32@0x0, fn_83221648, fn_8321F9F8 */
ts4_word ts4_call_seq_lbl_8302AFB8_83221DC8(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8302AFB8;
    fn_83221648();
    t2 = fn_8321F9F8((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x83227008: set u32@0xc */
void ts4_set_u32_offc_83227008(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83227560: call_seq fn_832200E8 */
ts4_word ts4_call_seq_fn_832200E8_83227560(ts4_word a0)
{
    fn_832200E8((ts4_word)(a0 + 136));
    return 0;
}

/* Loader_DLL.xex 0x83230840: call_seq fn_83226FC0, lbl_8302B968, u32@0x0, fn_8322F310 */
ts4_word ts4_call_seq_fn_83226FC0_83230840(ts4_word a0)
{
    ts4_word t2;

    fn_83226FC0((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8302B968;
    t2 = fn_8322F310((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x832308B0: tailcall KeWaitForSingleObject */
ts4_word ts4_tailcall_KeWaitForSingleObject_832308B0(ts4_word a0)
{
    return KeWaitForSingleObject((ts4_word)(a0 + 116), (ts4_word)3, (ts4_word)1, (ts4_word)0, (ts4_word)0);
}

/* Loader_DLL.xex 0x832308C8: tailcall KeWaitForSingleObject */
ts4_word ts4_tailcall_KeWaitForSingleObject_832308C8(ts4_word a0)
{
    return KeWaitForSingleObject((ts4_word)(a0 + 132), (ts4_word)3, (ts4_word)1, (ts4_word)0, (ts4_word)0);
}

/* Loader_DLL.xex 0x832308E0: tailcall KeWaitForSingleObject */
ts4_word ts4_tailcall_KeWaitForSingleObject_832308E0(ts4_word a0)
{
    return KeWaitForSingleObject((ts4_word)(a0 + 148), (ts4_word)3, (ts4_word)1, (ts4_word)0, (ts4_word)0);
}

/* Loader_DLL.xex 0x832308F8: tailcall KeWaitForSingleObject */
ts4_word ts4_tailcall_KeWaitForSingleObject_832308F8(ts4_word a0)
{
    return KeWaitForSingleObject((ts4_word)(a0 + 164), (ts4_word)3, (ts4_word)1, (ts4_word)0, (ts4_word)0);
}

/* Loader_DLL.xex 0x83230910: tailcall KeWaitForSingleObject */
ts4_word ts4_tailcall_KeWaitForSingleObject_83230910(ts4_word a0)
{
    return KeWaitForSingleObject((ts4_word)(a0 + 180), (ts4_word)3, (ts4_word)1, (ts4_word)0, (ts4_word)0);
}

/* Loader_DLL.xex 0x83230928: tailcall KeWaitForSingleObject */
ts4_word ts4_tailcall_KeWaitForSingleObject_83230928(ts4_word a0)
{
    return KeWaitForSingleObject((ts4_word)(a0 + 196), (ts4_word)3, (ts4_word)1, (ts4_word)0, (ts4_word)0);
}

/* Loader_DLL.xex 0x83230940: tailcall KeSetEvent */
ts4_word ts4_tailcall_KeSetEvent_83230940(ts4_word a0)
{
    return KeSetEvent((ts4_word)(a0 + 84), (ts4_word)1, (ts4_word)0);
}

/* Loader_DLL.xex 0x83230950: tailcall KeSetEvent */
ts4_word ts4_tailcall_KeSetEvent_83230950(ts4_word a0)
{
    return KeSetEvent((ts4_word)(a0 + 100), (ts4_word)1, (ts4_word)0);
}

/* Loader_DLL.xex 0x83230960: tailcall KeSetEvent */
ts4_word ts4_tailcall_KeSetEvent_83230960(ts4_word a0)
{
    return KeSetEvent((ts4_word)(a0 + 116), (ts4_word)1, (ts4_word)0);
}

/* Loader_DLL.xex 0x83230970: tailcall KeSetEvent */
ts4_word ts4_tailcall_KeSetEvent_83230970(ts4_word a0)
{
    return KeSetEvent((ts4_word)(a0 + 132), (ts4_word)1, (ts4_word)0);
}

/* Loader_DLL.xex 0x83230980: tailcall KeSetEvent */
ts4_word ts4_tailcall_KeSetEvent_83230980(ts4_word a0)
{
    return KeSetEvent((ts4_word)(a0 + 148), (ts4_word)1, (ts4_word)0);
}

/* Loader_DLL.xex 0x83230990: tailcall KeSetEvent */
ts4_word ts4_tailcall_KeSetEvent_83230990(ts4_word a0)
{
    return KeSetEvent((ts4_word)(a0 + 164), (ts4_word)1, (ts4_word)0);
}

/* Loader_DLL.xex 0x832309A0: tailcall KeSetEvent */
ts4_word ts4_tailcall_KeSetEvent_832309A0(ts4_word a0)
{
    return KeSetEvent((ts4_word)(a0 + 180), (ts4_word)1, (ts4_word)0);
}

/* Loader_DLL.xex 0x832309B0: tailcall KeSetEvent */
ts4_word ts4_tailcall_KeSetEvent_832309B0(ts4_word a0)
{
    return KeSetEvent((ts4_word)(a0 + 196), (ts4_word)1, (ts4_word)0);
}

/* Loader_DLL.xex 0x832309C0: tailcall KeResetEvent */
ts4_word ts4_tailcall_KeResetEvent_832309C0(ts4_word a0)
{
    return KeResetEvent((ts4_word)(a0 + 148));
}

/* Loader_DLL.xex 0x832309C8: tailcall KeResetEvent */
ts4_word ts4_tailcall_KeResetEvent_832309C8(ts4_word a0)
{
    return KeResetEvent((ts4_word)(a0 + 164));
}

/* Loader_DLL.xex 0x832309D0: tailcall KeResetEvent */
ts4_word ts4_tailcall_KeResetEvent_832309D0(ts4_word a0)
{
    return KeResetEvent((ts4_word)(a0 + 180));
}

/* Loader_DLL.xex 0x832309D8: tailcall KeResetEvent */
ts4_word ts4_tailcall_KeResetEvent_832309D8(ts4_word a0)
{
    return KeResetEvent((ts4_word)(a0 + 196));
}

/* Loader_DLL.xex 0x832309E0: get u32@0xd4 */
ts4_word ts4_get_u32_offd4_832309E0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 212));
}

/* Loader_DLL.xex 0x832309E8: get u32@0xd8 */
ts4_word ts4_get_u32_offd8_832309E8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 216));
}

/* Loader_DLL.xex 0x832309F0: get u32@0xdc */
ts4_word ts4_get_u32_offdc_832309F0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 220));
}

/* Loader_DLL.xex 0x832309F8: get u32@0xe0 */
ts4_word ts4_get_u32_offe0_832309F8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 224));
}

/* Loader_DLL.xex 0x83230A00: get u32@0xe4 */
ts4_word ts4_get_u32_offe4_83230A00(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 228));
}

/* Loader_DLL.xex 0x83230A08: if_get u32@0xd4, u32@0xd4, u32@0x40, u32@0x40, u32@0x50 */
ts4_word ts4_if_get_u32_offd4_83230A08(ts4_word a0, int a1)
{
    int t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 212);
    *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)a1;
    if ((int)t1 == (int)a1) {
        return a0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    if ((ts4_word)t3 == 0) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word))(t3))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 80)));
}

/* Loader_DLL.xex 0x83230A38: if_get u32@0xd8, u32@0xd8, u32@0x40, u32@0x40, u32@0x50 */
ts4_word ts4_if_get_u32_offd8_83230A38(ts4_word a0, int a1)
{
    int t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 216);
    *(ts4_word *)((char *)(ts4_word)(a0) + 216) = (ts4_word)a1;
    if ((int)t1 == (int)a1) {
        return a0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    if ((ts4_word)t3 == 0) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word))(t3))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 80)));
}

/* Loader_DLL.xex 0x83231348: get u32@0x34 */
ts4_word ts4_get_u32_off34_83231348(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 52));
}

/* Loader_DLL.xex 0x83233468: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83233468(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32770));
}

/* Loader_DLL.xex 0x83233478: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83233478(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32770));
}

/* Loader_DLL.xex 0x83233488: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83233488(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32770));
}

/* Loader_DLL.xex 0x83233498: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83233498(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32770));
}

/* Loader_DLL.xex 0x832334A8: set u32@0x2c, u32@0x30, u32@0x34, u64@0x38, u64@0x40, u32@0x5c */
void ts4_set_u32_off2c_832334A8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 56) = (ts4_u64)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 64) = (ts4_u64)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)1;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 72) = (ts4_u64)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 80) = (ts4_u64)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x832335A8: get u32@0x30 */
ts4_word ts4_get_u32_off30_832335A8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 48));
}

/* Loader_DLL.xex 0x832335B0: get u32@0x34 */
ts4_word ts4_get_u32_off34_832335B0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 52));
}

/* Loader_DLL.xex 0x832335B8: fn  */
ts4_word ts4_fn_832335B8(ts4_word a0)
{
    return (a0 + 72);
}

/* Loader_DLL.xex 0x832335C0: get u32@0x5c */
ts4_word ts4_get_u32_off5c_832335C0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 92));
}

/* Loader_DLL.xex 0x832335C8: get u32@0x5c, u32@0x5c */
ts4_word ts4_get_u32_off5c_832335C8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)a1;
    return t1;
}

/* Loader_DLL.xex 0x832335D8: set u64@0x38 */
void ts4_set_u64_off38_832335D8(ts4_word a0, ts4_u64 a1)
{
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 56) = (ts4_u64)a1;
    return;
}

/* Loader_DLL.xex 0x832335E8: set u64@0x40 */
void ts4_set_u64_off40_832335E8(ts4_word a0, ts4_u64 a1)
{
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 64) = (ts4_u64)a1;
    return;
}

/* Loader_DLL.xex 0x83233B90: set u8@0x5f4, u32@0x5f8 */
ts4_word ts4_set_u8_off5f4_83233B90(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1524) = (unsigned char)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1528) = (ts4_word)a2;
    return 0;
}

/* Loader_DLL.xex 0x83233C68: set u8@0x5f4, u32@0x5f8 */
ts4_word ts4_set_u8_off5f4_83233C68(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 1524) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1528) = (ts4_word)0;
    return 0;
}

/* Loader_DLL.xex 0x83233DD0: if_call_seq fn_8340D830 */
ts4_word ts4_if_call_seq_fn_8340D830_83233DD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 != 0) {
        fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32768));
    }
    return 0;
}

/* Loader_DLL.xex 0x83233F10: get u32@lbl_8302BD80 */
ts4_word ts4_get_u32_lbl_8302BD80_83233F10(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)lbl_8302BD80)))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83234298: set u8@0x200 */
ts4_word ts4_set_u8_off200_83234298(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 512) = (unsigned char)0;
    return 0;
}

/* Loader_DLL.xex 0x83234700: fn  */
ts4_word ts4_fn_83234700(void)
{
    return ((2152726528) | 5);
}

/* Loader_DLL.xex 0x83234710: set u32@0x0, u32@0x0, u64@0x0, u32@0x4, u32@0xc */
ts4_word ts4_set_u32_off0_83234710(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)0;
    *(ts4_u64 *)((char *)(ts4_word)(a5) + 0) = (ts4_u64)0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 12))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
}

/* Loader_DLL.xex 0x83234D40: get u8@0x10, u8@0x0 */
ts4_word ts4_get_u8_off10_83234D40(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 16));
    return 0;
}

/* Loader_DLL.xex 0x83234F08: get u32@0x4, u32@0x18 */
ts4_word ts4_get_u32_off4_83234F08(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 24))))((ts4_word)t1);
}

/* Loader_DLL.xex 0x83235B90: fn  */
ts4_word ts4_fn_83235B90(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83235C00: get u32@0x14, u32@0x14, u32@0x44, u32@0x4, u32@0x44 */
ts4_word ts4_get_u32_off14_83235C00(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
    *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 68));
    *(ts4_word *)((char *)(ts4_word)(t1) + 68) = (ts4_word)a1;
    return 0;
}

/* Loader_DLL.xex 0x83235C20: fn  */
ts4_word ts4_fn_83235C20(void)
{
    return ((2152726528) | 2);
}

/* Loader_DLL.xex 0x83235C30: fn  */
ts4_word ts4_fn_83235C30(void)
{
    return ((2152726528) | 2);
}

/* Loader_DLL.xex 0x83236158: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83236158(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32822));
}

/* Loader_DLL.xex 0x83236168: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83236168(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32822));
}

/* Loader_DLL.xex 0x83236178: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83236178(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32822));
}

/* Loader_DLL.xex 0x83236188: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83236188(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32822));
}

/* Loader_DLL.xex 0x832361A0: tailcall fn_833E3A30 */
ts4_word ts4_tailcall_fn_833E3A30_832361A0(ts4_word a0)
{
    return fn_833E3A30((ts4_word)(a0 + 44), (ts4_word)0, (ts4_word)80);
}

/* Loader_DLL.xex 0x832361B0: tailcall fn_833E3A30 */
ts4_word ts4_tailcall_fn_833E3A30_832361B0(ts4_word a0)
{
    return fn_833E3A30((ts4_word)(a0 + 44), (ts4_word)0, (ts4_word)80);
}

/* Loader_DLL.xex 0x832361C0: get u32@0x0, u32@0x30 */
ts4_word ts4_get_u32_off0_832361C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)40, (ts4_word)(a0 + 44));
}

/* Loader_DLL.xex 0x832361D8: fn  */
ts4_word ts4_fn_832361D8(ts4_word a0)
{
    return (a0 + 44);
}

/* Loader_DLL.xex 0x83236240: call_seq fn_83226FC0, fn_833E3A30 */
ts4_word ts4_call_seq_fn_83226FC0_83236240(ts4_word a0)
{
    fn_83226FC0((ts4_word)a0);
    fn_833E3A30((ts4_word)(a0 + 44), (ts4_word)0, (ts4_word)80);
    return a0;
}

/* Loader_DLL.xex 0x83236280: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83236280(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((613154816) | 32768));
}

/* Loader_DLL.xex 0x83236290: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83236290(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((613154816) | 32768));
}

/* Loader_DLL.xex 0x832362A0: get u8@0x0, u8@0x1, u8@0x1, u8@0x0 */
void ts4_get_u8_off0_832362A0(ts4_word a0)
{
    unsigned char t1;
    unsigned char t2;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 0);
    t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 1);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1) = (unsigned char)t1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)t2;
    return;
}

/* Loader_DLL.xex 0x832362B8: get u8@0x0, u8@0x3, u8@0x2, u8@0x1, u8@0x3, u8@0x0 */
void ts4_get_u8_off0_832362B8(ts4_word a0)
{
    unsigned char t1;
    unsigned char t2;
    unsigned char t3;
    unsigned char t4;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 0);
    t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 3);
    t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 2);
    t4 = *(unsigned char *)((char *)(ts4_word)(a0) + 1);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 3) = (unsigned char)t1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)t2;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1) = (unsigned char)t3;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 2) = (unsigned char)t4;
    return;
}

/* Loader_DLL.xex 0x8323A660: fn  */
ts4_word ts4_fn_8323A660(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return (((int)a1 * (int)a2) + a0);
}

/* Loader_DLL.xex 0x8323A670: set  */
void ts4_set_8323A670(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc14[1];

    (void)a2;
    loc14[0] = (ts4_word)a0;
    *(unsigned short *)((char *)(ts4_word)((a3 << 1)) + a1) = (unsigned short)(*(unsigned short *)((char *)loc14 + 2));
    return;
}

/* Loader_DLL.xex 0x8323A688: set u32@0x3c */
void ts4_set_u32_off3c_8323A688(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x8323A698: set u32@0x0 */
void ts4_set_u32_off0_8323A698(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x8323A6A0: set u32@0x4 */
void ts4_set_u32_off4_8323A6A0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x8323A6A8: get u32@0xc */
ts4_word ts4_get_u32_offc_8323A6A8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Loader_DLL.xex 0x8323A6B0: set u32@0xc */
void ts4_set_u32_offc_8323A6B0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x8323A6B8: get u32@0x10 */
ts4_word ts4_get_u32_off10_8323A6B8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Loader_DLL.xex 0x8323A6C0: set u32@0x10 */
void ts4_set_u32_off10_8323A6C0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x8323A6C8: set u32@0x34 */
void ts4_set_u32_off34_8323A6C8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x8323A6D0: get u32@0x28, u32@0x28 */
void ts4_get_u32_off28_8323A6D0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(t1 - (t1 & 0x7));
    return;
}

/* Loader_DLL.xex 0x8323AF80: if_get u32@0x0, u16@0x6e, fn_83258C28, u32@0xd4, fn_83258730, u32@0xd4 */
ts4_word ts4_if_get_u32_off0_8323AF80(ts4_word a0)
{
    unsigned short t2;

    t2 = *(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 110);
    if ((ts4_word)t2 <= 16) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)(ts4_word)fn_83258730;
        return 0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)(ts4_word)fn_83258C28;
    return 0;
}

/* Loader_DLL.xex 0x8323AFB8: if_get u32@0x0, u32@0x0, u32@0x0 */
void ts4_if_get_u32_off0_8323AFB8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 > (ts4_word)(((a1 + 7)) >> 3)) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
        return;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(((a1 + 7)) >> 3);
    return;
}

/* Loader_DLL.xex 0x8323DD30: if_get u32@0x0, u32@0x3c, u32@0x200, u32@0x38, u32@0x38 */
ts4_word ts4_if_get_u32_off0_8323DD30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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

/* Loader_DLL.xex 0x83241090: tailcall fn_8323D488 */
ts4_word ts4_tailcall_fn_8323D488_83241090(ts4_word a0)
{
    return fn_8323D488((ts4_word)a0);
}

/* Loader_DLL.xex 0x832437B0: fn  */
ts4_word ts4_fn_832437B0(void)
{
    return 1;
}

/* Loader_DLL.xex 0x832446F0: get u8@0x0, u8@0x1, u8@0x1, u8@0x0 */
void ts4_get_u8_off0_832446F0(ts4_word a0)
{
    unsigned char t1;
    unsigned char t2;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 0);
    t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 1);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1) = (unsigned char)t1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)t2;
    return;
}

/* Loader_DLL.xex 0x83244708: get u8@0x0, u8@0x3, u8@0x2, u8@0x1, u8@0x3, u8@0x0 */
void ts4_get_u8_off0_83244708(ts4_word a0)
{
    unsigned char t1;
    unsigned char t2;
    unsigned char t3;
    unsigned char t4;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 0);
    t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 3);
    t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 2);
    t4 = *(unsigned char *)((char *)(ts4_word)(a0) + 1);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 3) = (unsigned char)t1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)t2;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1) = (unsigned char)t3;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 2) = (unsigned char)t4;
    return;
}

/* Loader_DLL.xex 0x8324EAB0: tailcall fn_8324E680 */
ts4_word ts4_tailcall_fn_8324E680_8324EAB0(ts4_word a0)
{
    return fn_8324E680((ts4_word)a0);
}

/* Loader_DLL.xex 0x83250470: tailcall fn_83250130 */
ts4_word ts4_tailcall_fn_83250130_83250470(ts4_word a0)
{
    return fn_83250130((ts4_word)a0);
}

/* Loader_DLL.xex 0x832509F8: tailcall fn_83250938 */
ts4_word ts4_tailcall_fn_83250938_832509F8(ts4_word a0)
{
    return fn_83250938((ts4_word)a0);
}

/* Loader_DLL.xex 0x83250F30: if_set u32@0x0, u32@0x0, u32@0x20, u32@0x2c, u32@0x0, u32@0x20 */
ts4_word ts4_if_set_u32_off0_83250F30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 32);
    if ((ts4_word)t1 == 0) {
        return ((5242880) | 1);
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 44));
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 32));
    *(ts4_word *)((char *)(ts4_word)(a1) + 32) = (ts4_word)0;
    return ((5242880) | 1);
}

/* Loader_DLL.xex 0x83251AF0: tailcall fn_83251860 */
ts4_word ts4_tailcall_fn_83251860_83251AF0(ts4_word a0)
{
    return fn_83251860((ts4_word)a0);
}

/* Loader_DLL.xex 0x83251D08: if_get u32@0x20, u32@0x20, fn_83251030 */
ts4_word ts4_if_get_u32_off20_83251D08(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 32);
    if ((ts4_word)t1 > 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 32) = (ts4_word)0;
    }
    return fn_83251030((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x83251DE0: tailcall fn_83251D20 */
ts4_word ts4_tailcall_fn_83251D20_83251DE0(ts4_word a0)
{
    return fn_83251D20((ts4_word)a0);
}

/* Loader_DLL.xex 0x83252260: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83252260(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((613154816) | 32768));
}

/* Loader_DLL.xex 0x83252270: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83252270(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((613154816) | 32768));
}

/* Loader_DLL.xex 0x83252280: fn  */
ts4_word ts4_fn_83252280(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83252288: fn  */
void ts4_fn_83252288(void)
{
    return;
}

/* Loader_DLL.xex 0x83252290: fn  */
void ts4_fn_83252290(void)
{
    return;
}

/* Loader_DLL.xex 0x83252298: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83252298(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((613154816) | 32768));
}

/* Loader_DLL.xex 0x832522A8: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_832522A8(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((613154816) | 32768));
}

/* Loader_DLL.xex 0x83252438: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_83252438(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83252740: set u32@0x58, u32@0x64 */
ts4_word ts4_set_u32_off58_83252740(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)a2;
    return 0;
}

/* Loader_DLL.xex 0x83253F70: if_get u32@0x1bc, u32@0x1c0, u32@0x1c0, u32@0x1c8, u32@0x1c8 */
ts4_word ts4_if_get_u32_off1bc_83253F70(ts4_word a0, ts4_word a1)
{
    int t1;
    int t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 444);
    if ((int)t1 != 0) {
        return ((int)a1 >> (*(ts4_word *)((char *)(ts4_word)(a0) + 456)));
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 448);
    if ((int)t3 != 0) {
        return (a1 << (*(ts4_word *)((char *)(ts4_word)(a0) + 456)));
    }
    return a1;
}

/* Loader_DLL.xex 0x83254818: get  */
ts4_word ts4_get_83254818(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a1;
    (void)a2;
    return ((short)(*(unsigned short *)((char *)(ts4_word)((a3 << 1)) + a0)));
}

/* Loader_DLL.xex 0x83254828: get  */
ts4_word ts4_get_83254828(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a1;
    (void)a2;
    return ((int)(*(ts4_word *)((char *)(ts4_word)((a3 + (a3 << 1))) + a0)) >> 8);
}

/* Loader_DLL.xex 0x83254840: get u8@0x2, u16@0x0 */
ts4_word ts4_get_u8_off2_83254840(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    unsigned char t1;

    (void)a1;
    (void)a2;
    t1 = *(unsigned char *)((char *)(ts4_word)(((a3 + (a3 << 1)) + a0)) + 2);
    return ((int)((((signed char)t1) << 16) | (*(unsigned short *)((char *)(ts4_word)(((a3 + (a3 << 1)) + a0)) + 0))) >> 4);
}

/* Loader_DLL.xex 0x832548C0: set  */
void ts4_set_832548C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a2;
    *(unsigned short *)((char *)(ts4_word)((a3 << 1)) + a1) = (unsigned short)a0;
    return;
}

/* Loader_DLL.xex 0x83254A28: fn  */
void ts4_fn_83254A28(void)
{
    return;
}

/* Loader_DLL.xex 0x832563F8: if_fn  */
ts4_word ts4_if_fn_832563F8(int a0, ts4_word a1)
{
    if ((int)a0 >= 0) {
        return ((((int)(1 << a1) >> 1) + a0) & ~((1 << a1) + -1));
    }
    return (((((int)(1 << a1) >> 1) + a0) + -1) & ~((1 << a1) + -1));
}

/* Loader_DLL.xex 0x83256818: fn  */
void ts4_fn_83256818(void)
{
    return;
}

/* Loader_DLL.xex 0x83256820: fn  */
void ts4_fn_83256820(void)
{
    return;
}

/* Loader_DLL.xex 0x83256828: fn  */
void ts4_fn_83256828(void)
{
    return;
}

/* Loader_DLL.xex 0x83256830: fn  */
ts4_word ts4_fn_83256830(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83256890: fn  */
ts4_word ts4_fn_83256890(void)
{
    return 0;
}

/* Loader_DLL.xex 0x832590E8: get u32@0x28 */
ts4_word ts4_get_u32_off28_832590E8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 40));
}

/* Loader_DLL.xex 0x832590F0: get u32@0x20 */
ts4_word ts4_get_u32_off20_832590F0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 32));
}

/* Loader_DLL.xex 0x832590F8: set u32@0xc */
void ts4_set_u32_offc_832590F8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83259100: fn  */
void ts4_fn_83259100(void)
{
    return;
}

/* Loader_DLL.xex 0x83259A20: tailcall fn_832597A0 */
ts4_word ts4_tailcall_fn_832597A0_83259A20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    return fn_832597A0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)0);
}

/* Loader_DLL.xex 0x83259A28: tailcall fn_832597A0 */
ts4_word ts4_tailcall_fn_832597A0_83259A28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    return fn_832597A0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)((a7 ^ 2876637184) ^ 14558));
}

/* Loader_DLL.xex 0x83261340: fn  */
ts4_word ts4_fn_83261340(void)
{
    return 0;
}

/* Loader_DLL.xex 0x832616A8: fn  */
ts4_word ts4_fn_832616A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return (((int)a1 * (int)a2) + a0);
}

/* Loader_DLL.xex 0x832619C0: addr lbl_8302CFA4, fn_83261930 */
ts4_word ts4_addr_lbl_8302CFA4_832619C0(ts4_word a0)
{
    return fn_83261930((ts4_word)(ts4_word)lbl_8302CFA4, (ts4_word)a0);
}

/* Loader_DLL.xex 0x83262478: call_seq fn_832623A8 */
ts4_word ts4_call_seq_fn_832623A8_83262478(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_832623A8((ts4_word)a0, (ts4_word)a1);
    return (t1 - a1);
}

/* Loader_DLL.xex 0x83263670: get u32@0x11c, u32@0x78, u32@0x0, u32@0x58, u32@0x0 */
void ts4_get_u32_off11c_83263670(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 284);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(((int)(*(ts4_word *)((char *)(ts4_word)(t1) + 88)) * (int)t2) + t3);
    return;
}

/* Loader_DLL.xex 0x83267488: if_get u32@0x0, u32@0x24c, fn_83267388, u32@0x204, u32@0x1e4 */
void ts4_if_get_u32_off0_83267488(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 588);
    if ((int)t2 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 516) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 484) = (ts4_word)(ts4_word)fn_83267388;
    return;
}

/* Loader_DLL.xex 0x83267658: call_seq fn_832674B0 */
ts4_word ts4_call_seq_fn_832674B0_83267658(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = fn_832674B0((ts4_word)a1, (ts4_word)a2, (ts4_word)a0, (ts4_word)0);
    return ((t1 << 4) + t1);
}

/* Loader_DLL.xex 0x83268510: if_addr lbl_83037A24 */
ts4_word ts4_if_addr_lbl_83037A24_83268510(ts4_word a0)
{
    if ((ts4_word)a0 >= 9) {
        return 0;
    }
    return (*(ts4_word *)((char *)(ts4_word)((a0 << 2)) + (ts4_word)lbl_83037A24));
}

/* Loader_DLL.xex 0x83269480: fn  */
ts4_word ts4_fn_83269480(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83269598: fn  */
ts4_word ts4_fn_83269598(void)
{
    return 0;
}

/* Loader_DLL.xex 0x832695E0: set u32@0x0 */
ts4_word ts4_set_u32_off0_832695E0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
    return 0;
}

/* Loader_DLL.xex 0x8326DC60: fn  */
ts4_word ts4_fn_8326DC60(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return (((int)a1 * (int)a2) + a0);
}

/* Loader_DLL.xex 0x8326DC70: fn  */
ts4_word ts4_fn_8326DC70(ts4_word a0, ts4_word a1)
{
    return ((a1 << 1) + a0);
}

/* Loader_DLL.xex 0x8326DC80: fn  */
ts4_word ts4_fn_8326DC80(ts4_word a0, ts4_word a1)
{
    return ((a1 + (a1 << 1)) + a0);
}

/* Loader_DLL.xex 0x8326DC90: set u8@0x0, u8@0x1, u8@0x2 */
void ts4_set_u8_off0_8326DC90(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc14[1];
    unsigned char t1;
    unsigned char t2;

    loc14[0] = (ts4_word)a0;
    t1 = *(unsigned char *)((char *)loc14 + 2);
    t2 = *(unsigned char *)((char *)loc14 + 3);
    *(unsigned char *)((char *)(ts4_word)(((a2 + (a2 << 1)) + a1)) + 0) = (unsigned char)(*(unsigned char *)((char *)loc14 + 1));
    *(unsigned char *)((char *)(ts4_word)(((a2 + (a2 << 1)) + a1)) + 1) = (unsigned char)t1;
    *(unsigned char *)((char *)(ts4_word)(((a2 + (a2 << 1)) + a1)) + 2) = (unsigned char)t2;
    return;
}

/* Loader_DLL.xex 0x8326E280: set u32@0xbc */
void ts4_set_u32_offbc_8326E280(ts4_word a0, ts4_word a1)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 188) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8326F928: tailcall fn_8326F898 */
ts4_word ts4_tailcall_fn_8326F898_8326F928(ts4_word a0)
{
    return fn_8326F898((ts4_word)a0);
}

/* Loader_DLL.xex 0x83273148: get u32@0x4, u32@0x14, fn_83272FA0 */
ts4_word ts4_get_u32_off4_83273148(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return fn_83272FA0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)(-(int)t1), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83273160: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10 */
void ts4_set_u32_off0_83273160(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83274CA8: fn  */
ts4_word ts4_fn_83274CA8(void)
{
    return (2147745792);
}

/* Loader_DLL.xex 0x83274FB8: get u32@0x14 */
ts4_word ts4_get_u32_off14_83274FB8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 20)) != 0);
}

/* Loader_DLL.xex 0x832750E8: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_832750E8(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x83275398: fn  */
ts4_word ts4_fn_83275398(void)
{
    return 0;
}

/* Loader_DLL.xex 0x832753A0: fn  */
ts4_word ts4_fn_832753A0(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83275710: call_seq fn_832753A8, u64@0x0 */
ts4_word ts4_call_seq_fn_832753A8_83275710(ts4_word a0)
{
    fn_832753A8((ts4_word)a0);
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 0) = (ts4_u64)0;
    return 0;
}

/* Loader_DLL.xex 0x832758C0: if_set u32@lbl_8352A3B4 */
ts4_word ts4_if_set_u32_lbl_8352A3B4_832758C0(int a0)
{
    if ((int)a0 >= -1 && (int)a0 < 1) {
        *(ts4_word *)lbl_8352A3B4 = (ts4_word)a0;
        return 0;
    }
    return -3;
}

/* Loader_DLL.xex 0x83275920: if_get u32@0x9c */
ts4_word ts4_if_get_u32_off9c_83275920(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return a0;
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 156));
}

/* Loader_DLL.xex 0x83275938: if_get u32@0xa0 */
ts4_word ts4_if_get_u32_offa0_83275938(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return a0;
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 160));
}

/* Loader_DLL.xex 0x83275A78: if_get u32@0x2e0, u32@0x10, u32@0x2e0, u32@0x10, u32@0xe80 */
ts4_word ts4_if_get_u32_off2e0_83275A78(ts4_word a0)
{
    ts4_word t3;
    int t4;

    if ((ts4_word)a0 == 0) {
        return a0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 736);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 16);
    if ((int)t4 != 0) {
        return -4;
    }
    return (*(ts4_word *)((char *)(ts4_word)(t3) + 3712));
}

/* Loader_DLL.xex 0x83277DF0: if_get u32@0x2e0, u32@0x10, u32@0x2e0, u32@0x10, u32@0x56f0 */
ts4_word ts4_if_get_u32_off2e0_83277DF0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    int t4;

    if ((ts4_word)a0 == 0) {
        return -3;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 736);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 16);
    if ((int)t4 != 0) {
        return -4;
    }
    *(ts4_word *)((char *)(ts4_word)(t3) + 22256) = (ts4_word)a1;
    return 0;
}

/* Loader_DLL.xex 0x83278F70: tailcall fn_832810B0 */
ts4_word ts4_tailcall_fn_832810B0_83278F70(ts4_word a0)
{
    return fn_832810B0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83278F78: if_get u32@0x2e0, u32@0x10, u32@0x2e0, u32@0x10, u32@0x4, u32@0xdac */
ts4_word ts4_if_get_u32_off2e0_83278F78(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    int t4;

    if ((ts4_word)a0 == 0) {
        return -3;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 736);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 16);
    if ((int)t4 != 0) {
        return -4;
    }
    *(ts4_word *)((char *)(ts4_word)(t3) + 3500) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    return 0;
}

/* Loader_DLL.xex 0x83278FB0: fn  */
ts4_word ts4_fn_83278FB0(void)
{
    return -4;
}

/* Loader_DLL.xex 0x83279018: fn  */
ts4_word ts4_fn_83279018(void)
{
    return -1;
}

/* Loader_DLL.xex 0x83279D28: call_seq fn_83279A08, u8@0x280, u8@0x280 */
ts4_word ts4_call_seq_fn_83279A08_83279D28(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = fn_83279A08((ts4_word)(a0 + 220), (ts4_word)a1, (ts4_word)a2);
    *(unsigned char *)((char *)(ts4_word)(a0) + 640) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(a0) + 640)) | 64);
    return t1;
}

/* Loader_DLL.xex 0x83279D68: call_seq fn_83279B30, u8@0x280, u8@0x280 */
ts4_word ts4_call_seq_fn_83279B30_83279D68(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = fn_83279B30((ts4_word)(a0 + 436), (ts4_word)a1, (ts4_word)a2);
    *(unsigned char *)((char *)(ts4_word)(a0) + 640) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(a0) + 640)) | 32);
    return t1;
}

/* Loader_DLL.xex 0x83279DA8: call_seq fn_83279BF0, u8@0x280, u8@0x280 */
ts4_word ts4_call_seq_fn_83279BF0_83279DA8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = fn_83279BF0((ts4_word)(a0 + 520), (ts4_word)a1, (ts4_word)a2);
    *(unsigned char *)((char *)(ts4_word)(a0) + 640) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(a0) + 640)) | 16);
    return t1;
}

/* Loader_DLL.xex 0x8327C060: if_tailcall fn_83278488 */
ts4_word ts4_if_tailcall_fn_83278488_8327C060(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return -3;
    }
    return fn_83278488((ts4_word)a0);
}

/* Loader_DLL.xex 0x8327F370: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_8327F370(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8327F3D0: fn  */
ts4_word ts4_fn_8327F3D0(void)
{
    return 1;
}

/* Loader_DLL.xex 0x8327F3D8: fn  */
void ts4_fn_8327F3D8(void)
{
    return;
}

/* Loader_DLL.xex 0x8327F5A8: call_seq XeCryptAesEcb */
ts4_word ts4_call_seq_XeCryptAesEcb_8327F5A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    (void)a0;
    (void)a4;
    XeCryptAesEcb((ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a5);
    return 0;
}

/* Loader_DLL.xex 0x8327F768: if_tailcall fn_8327F478 */
ts4_word ts4_if_tailcall_fn_8327F478_8327F768(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    if ((ts4_word)a2 == 0) {
        return ((2147942400) | 87);
    }
    return fn_8327F478((ts4_word)a0);
}

/* Loader_DLL.xex 0x8327F9A0: tailcall fn_833E0AB0 */
ts4_word ts4_tailcall_fn_833E0AB0_8327F9A0(ts4_word a0)
{
    return fn_833E0AB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x8327F9A8: tailcall fn_833E1758 */
ts4_word ts4_tailcall_fn_833E1758_8327F9A8(ts4_word a0)
{
    return fn_833E1758((ts4_word)a0);
}

/* Loader_DLL.xex 0x8327FA18: call_seq XeCryptRandom */
ts4_word ts4_call_seq_XeCryptRandom_8327FA18(void)
{
    XeCryptRandom();
    return 0;
}

/* Loader_DLL.xex 0x8327FA40: fn  */
void ts4_fn_8327FA40(void)
{
    return;
}

/* Loader_DLL.xex 0x8327FA48: call_seq XeCryptRandom */
ts4_word ts4_call_seq_XeCryptRandom_8327FA48(void)
{
    XeCryptRandom();
    return 1;
}

/* Loader_DLL.xex 0x8327FA90: fn  */
void ts4_fn_8327FA90(void)
{
    return;
}

/* Loader_DLL.xex 0x83280998: set u32@0xb4, u32@0xbc */
void ts4_set_u32_offb4_83280998(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 180) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)a2;
    return;
}

/* Loader_DLL.xex 0x83280A38: if_call_seq u32@0x24, fn_8328B5B0, u32@0x24 */
ts4_word ts4_if_call_seq_u32_off24_83280A38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 36);
    p3 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8328B5B0((ts4_word)a0, (ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a1) + 36) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x83281018: if_tailcall fn_8328B5B0 */
ts4_word ts4_if_tailcall_fn_8328B5B0_83281018(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return a0;
    }
    return fn_8328B5B0((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x83286380: fn  */
void ts4_fn_83286380(void)
{
    return;
}

/* Loader_DLL.xex 0x83286388: set u32@lbl_8352A3B8 */
void ts4_set_u32_lbl_8352A3B8_83286388(ts4_word a0)
{
    *(ts4_word *)lbl_8352A3B8 = (ts4_word)a0;
    return;
}

/* Loader_DLL.xex 0x83286398: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83286398(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((613154816) | 32769));
}

/* Loader_DLL.xex 0x832863A8: tailcall fn_833E73F8 */
ts4_word ts4_tailcall_fn_833E73F8_832863A8(ts4_word a0)
{
    return fn_833E73F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x832863B0: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_832863B0(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((613154816) | 32769));
}

/* Loader_DLL.xex 0x832863C0: tailcall fn_833E74C0 */
ts4_word ts4_tailcall_fn_833E74C0_832863C0(ts4_word a0)
{
    return fn_833E74C0((ts4_word)a0);
}

/* Loader_DLL.xex 0x832879C8: if_get u32@0x8, u32@0x0 */
ts4_word ts4_if_get_u32_off8_832879C8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)a1 >= (ts4_word)t1) {
        return 0;
    }
    return (*(ts4_word *)((char *)(ts4_word)((a1 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0))));
}

/* Loader_DLL.xex 0x83287A38: get u32@0x8 */
ts4_word ts4_get_u32_off8_83287A38(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x83287A40: get u32@0x4 */
ts4_word ts4_get_u32_off4_83287A40(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 3) << 2);
}

/* Loader_DLL.xex 0x83287AA8: get u32@0x20 */
ts4_word ts4_get_u32_off20_83287AA8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 32));
}

/* Loader_DLL.xex 0x832881E8: get u32@0x20 */
ts4_word ts4_get_u32_off20_832881E8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 32));
}

/* Loader_DLL.xex 0x832888F0: get u32@0x20 */
ts4_word ts4_get_u32_off20_832888F0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 32));
}

/* Loader_DLL.xex 0x83288FD0: get u32@0x20 */
ts4_word ts4_get_u32_off20_83288FD0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 32));
}

/* Loader_DLL.xex 0x832896B8: get u32@0x20 */
ts4_word ts4_get_u32_off20_832896B8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 32));
}

/* Loader_DLL.xex 0x83289DA0: get u32@0x20 */
ts4_word ts4_get_u32_off20_83289DA0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 32));
}

/* Loader_DLL.xex 0x8328B370: call_seq u32@0x0, RtlEnterCriticalSection, u32@0x0, RtlLeaveCriticalSection */
ts4_word ts4_call_seq_u32_off0_8328B370(ts4_word a0)
{
    RtlEnterCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    RtlLeaveCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    return 1;
}

/* Loader_DLL.xex 0x8328B3B0: call_seq u32@0x0, RtlEnterCriticalSection, u32@0x0, RtlLeaveCriticalSection */
ts4_word ts4_call_seq_u32_off0_8328B3B0(ts4_word a0)
{
    RtlEnterCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    RtlLeaveCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    return 1;
}

/* Loader_DLL.xex 0x8328B3F0: fn  */
void ts4_fn_8328B3F0(void)
{
    return;
}

/* Loader_DLL.xex 0x8328B3F8: get u32@0x0, u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_get_u32_off0_8328B3F8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)((591724544) | 26505);
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)((878051328) | 30874);
    *(ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)((1164378112) | 35243);
    return;
}

/* Loader_DLL.xex 0x8328B598: if_get u32@0x3c, fn_8328B4F0, fn_832755A0 */
ts4_word ts4_if_get_u32_off3c_8328B598(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    if ((ts4_word)t1 != 0) {
        return fn_832755A0((ts4_word)(a0 + 52));
    }
    return fn_8328B4F0((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x8328B5D8: fn  */
ts4_word ts4_fn_8328B5D8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x8328B898: get u8@0x0, u8@0x5, u8@0x4, u8@0x3, u8@0x1, u8@0x2 */
void ts4_get_u8_off0_8328B898(ts4_word a0)
{
    unsigned char t1;
    unsigned char t2;
    unsigned char t3;
    unsigned char t4;
    unsigned char t5;
    unsigned char t6;

    t1 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0);
    t2 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 5);
    t3 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 4);
    t4 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 3);
    t5 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1);
    t6 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 2);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)t1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)t2;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1) = (unsigned char)t3;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)t5;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 2) = (unsigned char)t4;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 3) = (unsigned char)t6;
    return;
}

/* Loader_DLL.xex 0x832936C8: if_get u32@0xe8c, u32@0x120, u32@0xd5c */
ts4_word ts4_if_get_u32_offe8c_832936C8(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 3724);
    if ((int)t1 == 0) {
        return 5;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 288) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 3420) = (ts4_word)1;
    return 0;
}

/* Loader_DLL.xex 0x8329A320: if_get u32@0x8, fn_832806D8 */
ts4_word ts4_if_get_u32_off8_8329A320(ts4_word a0, ts4_word a1)
{
    ts4_word p2;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p2 = (ts4_word)a1;
    if ((int)(t1 & 0x7) != 0) {
        p2 = (ts4_word)(t1 & 0x7);
    }
    return fn_832806D8((ts4_word)a0, (ts4_word)p2);
}

/* Loader_DLL.xex 0x8329F850: set  */
void ts4_set_8329F850(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + ((0) | 45796)) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8329F868: set  */
void ts4_set_8329F868(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + ((0) | 45796)) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x8329F880: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_8329F880(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8329FAE8: set u32@lbl_8353AF58 */
void ts4_set_u32_lbl_8353AF58_8329FAE8(void)
{
    *(volatile ts4_word *)lbl_8353AF58 = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8329FC38: if_get u32@0x45d8, u32@0x45d8, u32@0x45d8 */
void ts4_if_get_u32_off45d8_8329FC38(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 17880);
    if ((ts4_word)t1 >= 64) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(((t1 + 4406) << 2)) + a0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 17880) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 17880)) + 1);
    return;
}

/* Loader_DLL.xex 0x8329FD90: get u32@0x47e0, u32@0x47ec */
ts4_word ts4_get_u32_off47e0_8329FD90(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 18400);
    return (t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 18412)));
}

/* Loader_DLL.xex 0x8329FE08: set u32@0x27c, u32@0x28 */
void ts4_set_u32_off27c_8329FE08(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 636) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x8329FE18: if_get u32@0xd78, u32@0xea0, u32@0x27c, u32@0x28, u32@0xeb4, u32@0x27c */
void ts4_if_get_u32_offd78_8329FE18(ts4_word a0, ts4_word a1)
{
    int t1;
    ts4_word t3;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 3448);
    if ((int)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 3764);
        *(ts4_word *)((char *)(ts4_word)(t3) + 636) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(a1) + 40) = (ts4_word)t3;
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 3744);
    *(ts4_word *)((char *)(ts4_word)(t2) + 636) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 40) = (ts4_word)t2;
    return;
}

/* Loader_DLL.xex 0x8329FF10: fn  */
ts4_word ts4_fn_8329FF10(void)
{
    return ((159973376) | 26624);
}

/* Loader_DLL.xex 0x8329FF20: get u32@0x314 */
ts4_word ts4_get_u32_off314_8329FF20(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 788));
}

/* Loader_DLL.xex 0x8329FF28: get u32@0x310 */
ts4_word ts4_get_u32_off310_8329FF28(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 784));
}

/* Loader_DLL.xex 0x8329FFF0: get fn_8340CE50 */
ts4_word ts4_get_fn_8340CE50_8329FFF0(ts4_word a0, ts4_word a1)
{
    return fn_8340CE50((ts4_word)(*(ts4_word *)((char *)(ts4_word)(((a1 + 230) << 2)) + a0)), (ts4_word)-1);
}

/* Loader_DLL.xex 0x832A0958: fn  */
void ts4_fn_832A0958(void)
{
    return;
}

/* Loader_DLL.xex 0x832A0DB8: call_seq u32@0x4988, RtlEnterCriticalSection, u32@0x4984, u32@0x4988, u32@0x4990, RtlLeaveCriticalSection */
ts4_word ts4_call_seq_u32_off4988_832A0DB8(ts4_word a0)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    RtlEnterCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 18824)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 18820);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 18824);
    *(ts4_word *)((char *)(ts4_word)(a0) + 18832) = (ts4_word)t3;
    t5 = RtlLeaveCriticalSection((ts4_word)t4);
    return t5;
}

/* Loader_DLL.xex 0x832A0E58: fn  */
ts4_word ts4_fn_832A0E58(void)
{
    return 1;
}

/* Loader_DLL.xex 0x832A1190: fn  */
ts4_word ts4_fn_832A1190(void)
{
    return 0;
}

/* Loader_DLL.xex 0x832A1378: if_tailcall fn_83496E70 */
ts4_word ts4_if_tailcall_fn_83496E70_832A1378(ts4_word a0, ts4_word a1)
{
    if ((int)(a0 + 15984) != 0) {
        return fn_83496E70((ts4_word)a0, (ts4_word)(a0 + 15984), (ts4_word)a1);
    }
    return -9;
}

/* Loader_DLL.xex 0x832A19A8: if_tailcall fn_834D2E00 */
ts4_word ts4_if_tailcall_fn_834D2E00_832A19A8(ts4_word a0, ts4_word a1)
{
    if ((int)(a0 + 15984) != 0) {
        return fn_834D2E00((ts4_word)a0, (ts4_word)(a0 + 15984), (ts4_word)a1);
    }
    return -9;
}

/* Loader_DLL.xex 0x832A19C8: if_tailcall fn_834B8568 */
ts4_word ts4_if_tailcall_fn_834B8568_832A19C8(ts4_word a0, ts4_word a1)
{
    if ((int)(a0 + 15984) != 0) {
        return fn_834B8568((ts4_word)a0, (ts4_word)(a0 + 15984), (ts4_word)a1);
    }
    return -9;
}

/* Loader_DLL.xex 0x832A27B0: if_tailcall fn_834D38C0 */
ts4_word ts4_if_tailcall_fn_834D38C0_832A27B0(ts4_word a0, ts4_word a1)
{
    if ((int)(a0 + 15984) != 0) {
        return fn_834D38C0((ts4_word)a0, (ts4_word)(a0 + 15984), (ts4_word)a1);
    }
    return -9;
}

/* Loader_DLL.xex 0x832A27D0: if_tailcall fn_834D38C0 */
ts4_word ts4_if_tailcall_fn_834D38C0_832A27D0(ts4_word a0, ts4_word a1)
{
    if ((int)(a0 + 18192) != 0) {
        return fn_834D38C0((ts4_word)a0, (ts4_word)(a0 + 18192), (ts4_word)a1);
    }
    return -9;
}

/* Loader_DLL.xex 0x832A2AD0: set u32@0x4, u32@0x34, u32@0x30, u32@0x30, u32@0x34, u32@0x34 */
void ts4_set_u32_off4_832A2AD0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)2;
    *(ts4_word *)((char *)(ts4_word)((((*(ts4_word *)((char *)(ts4_word)(a0) + 52)) + 14) << 2)) + a0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 48) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 48)) + 1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 52)) + 1);
    return;
}

/* Loader_DLL.xex 0x832A3748: call_seq u32@0x6070, fn_832A3580, fn_832A3678 */
ts4_word ts4_call_seq_u32_off6070_832A3748(ts4_word a0)
{
    ts4_word t3;

    fn_832A3580((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24688)));
    t3 = fn_832A3678((ts4_word)a0);
    return t3;
}

/* Loader_DLL.xex 0x832A3EC8: if_get u32@0x47f8, u32@0x310, u32@0x47f8 */
void ts4_if_get_u32_off47f8_832A3EC8(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 18424);
    if ((int)t1 != 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((((*(ts4_word *)((char *)(ts4_word)(a0) + 784)) + 4342) << 2)) + a0))) + ((0) | 45808)) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 18424) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x832A4388: tailcall fn_833E3AD0 */
ts4_word ts4_tailcall_fn_833E3AD0_832A4388(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833E3AD0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x832A8640: fn  */
ts4_word ts4_fn_832A8640(void)
{
    return 3;
}

/* Loader_DLL.xex 0x832AAE90: call_seq fn_832A6E48, fn_832AAC88 */
ts4_word ts4_call_seq_fn_832A6E48_832AAE90(ts4_word a0)
{
    fn_832A6E48((ts4_word)a0);
    fn_832AAC88((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x832AB838: call_seq fn_832AAC00, fn_832A2B08 */
ts4_word ts4_call_seq_fn_832AAC00_832AB838(ts4_word a0, ts4_word a1)
{
    (void)a0;
    fn_832A2B08((ts4_word)a1, (ts4_word)14, (ts4_word)(ts4_word)fn_832AAC00);
    return 0;
}

/* Loader_DLL.xex 0x832C4940: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_832C4940(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x832C5708: fn  */
ts4_word ts4_fn_832C5708(void)
{
    return -1;
}

/* Loader_DLL.xex 0x832C8D20: loop_set u32@0x4, u32@0x8, u32@0xc, u32@0x0 */
void ts4_loop_set_u32_off4_832C8D20(ts4_word a0)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p3;

    c1 = (ts4_word)8;
    lv2 = (ts4_word)(a0 + -4);
    do {
        *(ts4_word *)((char *)(ts4_word)(lv2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(lv2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(lv2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)((lv2 + 16)) + 0) = (ts4_word)0;
        p3 = (ts4_word)(lv2 + 16);
        lv2 = p3;
    } while (--c1 != 0);
    return;
}

/* Loader_DLL.xex 0x832C8D48: loop_set u32@0xc, u32@0x0 */
void ts4_loop_set_u32_offc_832C8D48(ts4_word a0)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p3;

    c1 = (ts4_word)8;
    lv2 = (ts4_word)(a0 + -12);
    do {
        *(ts4_word *)((char *)(ts4_word)(lv2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)((lv2 + 16)) + 0) = (ts4_word)0;
        p3 = (ts4_word)(lv2 + 16);
        lv2 = p3;
    } while (--c1 != 0);
    return;
}

/* Loader_DLL.xex 0x832C8D68: loop_set u32@0x4, u32@0x8, u32@0xc, u32@0x0 */
void ts4_loop_set_u32_off4_832C8D68(ts4_word a0)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p3;

    c1 = (ts4_word)4;
    lv2 = (ts4_word)(a0 + -4);
    do {
        *(ts4_word *)((char *)(ts4_word)(lv2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(lv2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(lv2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)((lv2 + 16)) + 0) = (ts4_word)0;
        p3 = (ts4_word)(lv2 + 16);
        lv2 = p3;
    } while (--c1 != 0);
    return;
}

/* Loader_DLL.xex 0x832C8D90: set u32@0x0, u32@0x4, u32@0x10, u32@0x14, u32@0x20, u32@0x24 */
void ts4_set_u32_off0_832C8D90(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x832D9150: get u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_off4_832D9150(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((ts4_word (*)(ts4_word))(t1))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x832DA598: if_set u32@0x571c, u32@0x5714, u32@0x5714, u32@0x571c */
void ts4_if_set_u32_off571c_832DA598(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)(a1 & 0xff) == 3) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 22292) = (ts4_word)1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 22300) = (ts4_word)1;
        return;
    }
    if ((ts4_word)(a1 & 0xff) == 1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 22292) = (ts4_word)(a1 & 0xff);
        return;
    }
    if ((ts4_word)(a1 & 0xff) != 2) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 22300) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x832DB960: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_832DB960(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x832DC848: tailcall fn_832DC698 */
ts4_word ts4_tailcall_fn_832DC698_832DC848(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_832DC698((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x832DC850: set u32@0x5c, u32@0xfc */
void ts4_set_u32_off5c_832DC850(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 252) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x832DC948: if_get u32@0x124, u32@0x0 */
ts4_word ts4_if_get_u32_off124_832DC948(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    if ((ts4_word)a2 != 0 && (ts4_word)a0 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 292));
        return 0;
    }
    return 1;
}

/* Loader_DLL.xex 0x832E85E0: tailcall fn_832E8490 */
ts4_word ts4_tailcall_fn_832E8490_832E85E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_832E8490((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)0, (ts4_word)0, (ts4_word)1);
}

/* Loader_DLL.xex 0x832E85F0: tailcall fn_832E8490 */
ts4_word ts4_tailcall_fn_832E8490_832E85F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return fn_832E8490((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)0, (ts4_word)1);
}

/* Loader_DLL.xex 0x832E8600: tailcall fn_832E8490 */
ts4_word ts4_tailcall_fn_832E8490_832E8600(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return fn_832E8490((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)0, (ts4_word)a5, (ts4_word)0);
}

/* Loader_DLL.xex 0x832E8610: tailcall fn_832E8490 */
ts4_word ts4_tailcall_fn_832E8490_832E8610(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return fn_832E8490((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)0, (ts4_word)0);
}

/* Loader_DLL.xex 0x832F7150: fn  */
ts4_word ts4_fn_832F7150(ts4_word a0, ts4_word a1)
{
    return ((int)a0 * (int)a1);
}

/* Loader_DLL.xex 0x832F9DA8: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_832F9DA8(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x832FFD48: fn  */
ts4_word ts4_fn_832FFD48(void)
{
    return 1;
}

/* Loader_DLL.xex 0x832FFD50: set u32@0x3d08, u32@0x3d0c, u32@0x3cf0, u32@0x1cc, u32@0xda4 */
ts4_word ts4_set_u32_off3d08_832FFD50(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 15624) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 15628) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 15600) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 460) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 3492) = (ts4_word)1;
    return 0;
}

/* Loader_DLL.xex 0x83303BA0: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_83303BA0(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x83306308: fn  */
void ts4_fn_83306308(void)
{
    return;
}

/* Loader_DLL.xex 0x83313E78: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_83313E78(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x83313E80: fn  */
ts4_word ts4_fn_83313E80(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83315028: get u32@0xf8, u32@0x11c, u32@0x1dc, u32@0xfc4, u32@0xfcc */
void ts4_get_u32_offf8_83315028(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 248);
    *(ts4_word *)((char *)(ts4_word)(a0) + 284) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 476) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4036) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4044) = (ts4_word)t1;
    return;
}

/* Loader_DLL.xex 0x83316A00: if_get u32@0xfac, fn_83315048, fn_833151D8, u32@0x3e38, u32@0x3e3c */
void ts4_if_get_u32_offfac_83316A00(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4012);
    if ((int)t1 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 15928) = (ts4_word)(ts4_word)fn_83315048;
    *(ts4_word *)((char *)(ts4_word)(a0) + 15932) = (ts4_word)(ts4_word)fn_833151D8;
    return;
}

/* Loader_DLL.xex 0x83319FF0: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_83319FF0(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8331A060: if_tailcall fn_83371D30 */
ts4_word ts4_if_tailcall_fn_83371D30_8331A060(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a1 != 0 && (ts4_word)a2 != 0) {
        return fn_83371D30((ts4_word)a1, (ts4_word)a2, (ts4_word)a0);
    }
    return 1;
}

/* Loader_DLL.xex 0x8331A910: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_8331A910(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8331A918: fn  */
ts4_word ts4_fn_8331A918(void)
{
    return 0;
}

/* Loader_DLL.xex 0x8331D2E8: tailcall fn_8331D210 */
ts4_word ts4_tailcall_fn_8331D210_8331D2E8(ts4_word a0)
{
    return fn_8331D210((ts4_word)a0);
}

/* Loader_DLL.xex 0x8331D398: fn  */
ts4_word ts4_fn_8331D398(void)
{
    return 0;
}

/* Loader_DLL.xex 0x8331D3A0: call_seq fn_8331D2F0 */
ts4_word ts4_call_seq_fn_8331D2F0_8331D3A0(ts4_word a0)
{
    fn_8331D2F0((ts4_word)a0, (ts4_word)0);
    return 0;
}

/* Loader_DLL.xex 0x8331D3C8: fn  */
ts4_word ts4_fn_8331D3C8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x8331D3D0: fn  */
ts4_word ts4_fn_8331D3D0(void)
{
    return 0;
}

/* Loader_DLL.xex 0x8331D3D8: fn  */
ts4_word ts4_fn_8331D3D8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x8331D3E0: fn  */
ts4_word ts4_fn_8331D3E0(void)
{
    return 0;
}

/* Loader_DLL.xex 0x8331D430: fn  */
void ts4_fn_8331D430(void)
{
    return;
}

/* Loader_DLL.xex 0x8331FB38: if_get u32@0x3d10, u32@0xf8c, u32@0xf8c, fn_8331F6E8, fn_8331FA10, fn_8331F860 */
ts4_word ts4_if_get_u32_off3d10_8331FB38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    int t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 15632);
    if ((int)t1 != 0) {
        return fn_8331F860((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)a7);
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 3980);
    if ((int)t3 != 0) {
        return fn_8331FA10((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a7, (ts4_word)a6, (ts4_word)a7);
    }
    return fn_8331F6E8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a7, (ts4_word)a6, (ts4_word)a7);
}

/* Loader_DLL.xex 0x833214C8: call_seq fn_8331D100, fn_833201C8 */
ts4_word ts4_call_seq_fn_8331D100_833214C8(ts4_word a0)
{
    fn_8331D100((ts4_word)a0, (ts4_word)0);
    fn_833201C8((ts4_word)a0, (ts4_word)1);
    return 0;
}

/* Loader_DLL.xex 0x83321DD0: if_get u32@0x14, u32@0x8 */
ts4_word ts4_if_get_u32_off14_83321DD0(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((int)t1 != 0) {
        return 0;
    }
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) & 0x7);
}

/* Loader_DLL.xex 0x83321DF0: get u8@0xd */
ts4_word ts4_get_u8_offd_83321DF0(ts4_word a0, ts4_word a1)
{
    return (*(unsigned char *)((char *)(ts4_word)((a0 + a1)) + 13));
}

/* Loader_DLL.xex 0x83321E00: set u8@0xd */
void ts4_set_u8_offd_83321E00(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(unsigned char *)((char *)(ts4_word)((a0 + a1)) + 13) = (unsigned char)a2;
    return;
}

/* Loader_DLL.xex 0x83321E10: set u8@0xd */
void ts4_set_u8_offd_83321E10(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(unsigned char *)((char *)(ts4_word)((a0 + a1)) + 13) = (unsigned char)a2;
    return;
}

/* Loader_DLL.xex 0x8332AA68: tailcall fn_83413AA0 */
ts4_word ts4_tailcall_fn_83413AA0_8332AA68(ts4_word a0)
{
    return fn_83413AA0((ts4_word)0, (ts4_word)a0);
}

/* Loader_DLL.xex 0x8332B0C8: tailcall XeCryptRc4Ecb */
ts4_word ts4_tailcall_XeCryptRc4Ecb_8332B0C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return XeCryptRc4Ecb((ts4_word)a0, (ts4_word)a2, (ts4_word)a1);
}

/* Loader_DLL.xex 0x8332B630: set u32@0x0 */
void ts4_set_u32_off0_8332B630(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8332C4A0: if_get u32@0xc, u8@-0x1 */
ts4_word ts4_if_get_u32_offc_8332C4A0(ts4_word a0, int a1, int a2)
{
    if ((int)a1 > 1) {
        if ((int)a2 > 1) {
            return ((*(unsigned char *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) + a1)) + -1)) & 0x3);
        }
        return 2;
    }
    if ((int)a2 > 1) {
        return 1;
    }
    return 2;
}

/* Loader_DLL.xex 0x8332DD28: set u32@0x8, u32@0x3c */
void ts4_set_u32_off8_8332DD28(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x8332DD40: set u32@0x0 */
void ts4_set_u32_off0_8332DD40(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83331498: if_get u32@0x0 */
ts4_word ts4_if_get_u32_off0_83331498(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    int t1;

    (void)a3;
    t1 = *(ts4_word *)((char *)(ts4_word)(a4) + 0);
    if ((int)t1 == 0) {
        return (*(ts4_word *)((char *)(ts4_word)((a1 << 2)) + a0));
    }
    return (*(ts4_word *)((char *)(ts4_word)(((a2 + 2) << 2)) + a0));
}

/* Loader_DLL.xex 0x8333E5D0: tailcall fn_8333E548 */
ts4_word ts4_tailcall_fn_8333E548_8333E5D0(ts4_word a0, ts4_word a1)
{
    return fn_8333E548((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
}

/* Loader_DLL.xex 0x8333E6B8: tailcall fn_8333E630 */
ts4_word ts4_tailcall_fn_8333E630_8333E6B8(ts4_word a0, ts4_word a1)
{
    return fn_8333E630((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
}

/* Loader_DLL.xex 0x83350168: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_83350168(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x83350170: fn  */
ts4_word ts4_fn_83350170(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83350178: fn  */
ts4_word ts4_fn_83350178(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83350180: tailcall fn_833A1F10 */
ts4_word ts4_tailcall_fn_833A1F10_83350180(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_833A1F10((ts4_word)a1);
}

/* Loader_DLL.xex 0x83350188: tailcall fn_83395960 */
ts4_word ts4_tailcall_fn_83395960_83350188(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    (void)a0;
    (void)a3;
    (void)a4;
    return fn_83395960((ts4_word)a1, (ts4_word)a2, (ts4_word)a5, (ts4_word)a6);
}

/* Loader_DLL.xex 0x833501A0: tailcall fn_833959D8 */
ts4_word ts4_tailcall_fn_833959D8_833501A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    (void)a0;
    (void)a1;
    return fn_833959D8((ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)a7);
}

/* Loader_DLL.xex 0x83353308: fn  */
ts4_word ts4_fn_83353308(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x83353320: set  */
void ts4_set_83353320(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    return;
}

/* Loader_DLL.xex 0x83353328: set  */
void ts4_set_83353328(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 4) = f1;
    return;
}

/* Loader_DLL.xex 0x83353330: set  */
void ts4_set_83353330(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 8) = f1;
    return;
}

/* Loader_DLL.xex 0x83353338: set  */
void ts4_set_83353338(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 12) = f1;
    return;
}

/* Loader_DLL.xex 0x83353340: fn  */
ts4_word ts4_fn_83353340(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x83353C00: get u32@0x47fc */
ts4_word ts4_get_u32_off47fc_83353C00(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 18428));
}

/* Loader_DLL.xex 0x83353CF8: fn  */
ts4_word ts4_fn_83353CF8(ts4_word a0)
{
    return (a0 + 18392);
}

/* Loader_DLL.xex 0x83353D88: get u32@0xdac */
ts4_word ts4_get_u32_offdac_83353D88(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 3500)) == 0);
}

/* Loader_DLL.xex 0x83353E90: fn  */
void ts4_fn_83353E90(void)
{
    return;
}

/* Loader_DLL.xex 0x83353E98: tailcall fn_830BBB18 */
ts4_word ts4_tailcall_fn_830BBB18_83353E98(ts4_word a0)
{
    return fn_830BBB18((ts4_word)a0);
}

/* Loader_DLL.xex 0x83353EA0: call_seq fn_830BBB98 */
ts4_word ts4_call_seq_fn_830BBB98_83353EA0(ts4_word a0)
{
    fn_830BBB98((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x83353EC8: tailcall fn_830BBC00 */
ts4_word ts4_tailcall_fn_830BBC00_83353EC8(ts4_word a0)
{
    return fn_830BBC00((ts4_word)a0);
}

/* Loader_DLL.xex 0x83353ED0: call_seq fn_830AFD98 */
ts4_word ts4_call_seq_fn_830AFD98_83353ED0(void)
{
    fn_830AFD98();
    return 0;
}

/* Loader_DLL.xex 0x83353EF8: call_seq fn_830AFEA0 */
ts4_word ts4_call_seq_fn_830AFEA0_83353EF8(void)
{
    fn_830AFEA0();
    return 0;
}

/* Loader_DLL.xex 0x83353F20: call_seq fn_830B0108 */
ts4_word ts4_call_seq_fn_830B0108_83353F20(void)
{
    fn_830B0108();
    return 0;
}

/* Loader_DLL.xex 0x83354318: call_seq fn_833541A0, u32@0x8 */
ts4_word ts4_call_seq_fn_833541A0_83354318(void)
{
    ts4_word t1;

    t1 = fn_833541A0();
    return (*(ts4_word *)((char *)(ts4_word)(t1) + 8));
}
