/* Loader_DLL.xex 0x8319D730-0x831ECB38, executable version 0.0.0.3.
   Small accessor / call-sequence functions; parameters are untyped words
   (a0 = this/first argument), field accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#else
typedef unsigned long long ts4l_u64;
#endif
typedef unsigned long ts4l_word;

extern char fn_831C0FF0[];
extern char lbl_830009F8[];
extern char lbl_83019808[];
extern char lbl_83019EA0[];
extern char lbl_8301B378[];
extern char lbl_8301C4D8[];
extern char lbl_8301EEA0[];
extern char lbl_83021028[];
extern char lbl_83021F10[];
extern char lbl_83022CB0[];
extern char lbl_83022D30[];
extern char lbl_83022D88[];
extern char lbl_83023038[];
extern char lbl_830231A8[];
extern char lbl_83023240[];
extern char lbl_83025C98[];
extern char lbl_83025CB4[];
ts4l_word KeSetEvent();
ts4l_word RtlEnterCriticalSection();
ts4l_word RtlLeaveCriticalSection();
ts4l_word XAudioUnregisterRenderDriverClient();
ts4l_word fn_8317E5A0();
ts4l_word fn_831BAF50();
ts4l_word fn_831BB268();
ts4l_word fn_831BB278();
ts4l_word fn_831BB2E0();
ts4l_word fn_831BF558();
ts4l_word fn_831BFC20();
ts4l_word fn_831C0088();
ts4l_word fn_831C1AB8();
ts4l_word fn_831C1C28();
ts4l_word fn_831CCA18();
ts4l_word fn_831CCB90();
ts4l_word fn_831CE240();
ts4l_word fn_831D52D0();
ts4l_word fn_831FAAA8();
ts4l_word fn_831FEEB0();
ts4l_word fn_831FEED0();
ts4l_word fn_831FF318();
ts4l_word fn_831FF338();
ts4l_word fn_83201218();
ts4l_word fn_832014C0();
ts4l_word fn_832014F8();
ts4l_word fn_83201500();
ts4l_word fn_83201560();
ts4l_word fn_833E3A30();
ts4l_word fn_833E3AD0();
ts4l_word fn_8340A360();
ts4l_word fn_8340CE50();
ts4l_word fn_8340D710();
ts4l_word fn_8340D830();

/* Loader_DLL.xex 0x8319D730: if_call_seq u32@0x0, fn_8340A360, u32@0x0 */
ts4l_word ts4l_if_call_seq_u32_off0_8319D730(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p3;
    ts4l_word t1;
    ts4l_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    p3 = (ts4l_word)t1;
    if ((ts4l_word)t1 != 0 && (int)t1 != -1) {
        t2 = fn_8340A360((ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
        p3 = (ts4l_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x8319DBA0: if_call_seq RtlEnterCriticalSection, u32@0xc, u32@0x18, KeSetEvent, u32@0xc, fn_8340CE50 */
ts4l_word ts4l_if_call_seq_RtlEnterCriticalSection_8319DBA0(ts4l_word a0)
{
    ts4l_word t2;
    ts4l_word t7;
    ts4l_word t11;

    RtlEnterCriticalSection((ts4l_word)(a0 + 36));
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    if ((ts4l_word)t2 != 0) {
        KeSetEvent((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 24)), (ts4l_word)1, (ts4l_word)0);
        fn_8340CE50((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 12)), (ts4l_word)-1);
        t7 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
        if ((ts4l_word)t7 != 0 && (int)t7 != -1) {
            fn_8340A360((ts4l_word)t7);
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)0;
        }
    }
    t11 = RtlLeaveCriticalSection((ts4l_word)(a0 + 36));
    return t11;
}

/* Loader_DLL.xex 0x831A2348: if_call_seq u32@0x10, u32@0x18, u32@0x14, fn_8317E5A0, u32@0x28, u32@0x3c */
ts4l_word ts4l_if_call_seq_u32_off10_831A2348(ts4l_word a0, ts4l_word a1, int a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t6;

    (void)a1;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)a2 == 1) {
        t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 16);
        t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 24);
        fn_8317E5A0((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 20)), (ts4l_word)t2, (ts4l_word)t1);
    }
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 40);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)0;
    KeSetEvent((ts4l_word)t6, (ts4l_word)1, (ts4l_word)0);
    return 0;
}

/* Loader_DLL.xex 0x831A24A0: if_call_seq u32@0x30, KeSetEvent, u32@0x20, XAudioUnregisterRenderDriverClient, u32@0x20, u32@0x30 */
ts4l_word ts4l_if_call_seq_u32_off30_831A24A0(ts4l_word a0)
{
    ts4l_word p5;
    ts4l_word t3;
    ts4l_word t4;

    KeSetEvent((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 48)), (ts4l_word)1, (ts4l_word)0);
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 32);
    p5 = (ts4l_word)t3;
    if ((ts4l_word)t3 != 0) {
        t4 = XAudioUnregisterRenderDriverClient((ts4l_word)t3);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)0;
        p5 = (ts4l_word)t4;
    }
    *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 48))) + 4) = (ts4l_word)0;
    return p5;
}

/* Loader_DLL.xex 0x831A2C50: if_call_seq u16@0x0, u32@0x0, u16@0x10, u32@0x0, u16@0x0, u16@0x0 */
ts4l_word ts4l_if_call_seq_u16_off0_831A2C50(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p4;
    ts4l_word p5;
    ts4l_word p10;
    ts4l_word p12;
    ts4l_word p15;
    unsigned short t1;
    ts4l_word t2;
    unsigned short t7;
    ts4l_word t14;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned short *)((char *)(ts4l_word)(a0) + 0);
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a2) + 0);
    if ((ts4l_word)t1 == 357) {
        p5 = (ts4l_word)32;
    } else {
        if ((ts4l_word)t1 == 1) {
            p4 = (ts4l_word)18;
        } else {
            p4 = (ts4l_word)((*(unsigned short *)((char *)(ts4l_word)(a0) + 16)) + 18);
        }
        p5 = (ts4l_word)p4;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a2) + 0) = (ts4l_word)p5;
    p15 = (ts4l_word)a0;
    if ((ts4l_word)p5 <= (ts4l_word)t2) {
        t7 = *(unsigned short *)((char *)(ts4l_word)(a0) + 0);
        if ((ts4l_word)t7 == 357) {
            p12 = (ts4l_word)32;
        } else {
            if ((ts4l_word)t7 == 1) {
                p10 = (ts4l_word)16;
            } else {
                p10 = (ts4l_word)((*(unsigned short *)((char *)(ts4l_word)(a0) + 16)) + 18);
            }
            p12 = (ts4l_word)p10;
        }
        fn_833E3AD0((ts4l_word)a1, (ts4l_word)a0, (ts4l_word)p12);
        t14 = fn_833E3A30((ts4l_word)(p12 + a1), (ts4l_word)0, (ts4l_word)(t2 - p12));
        p15 = (ts4l_word)t14;
    }
    return p15;
}

/* Loader_DLL.xex 0x831A3268: if_call_seq u32@0xc, fn_8340D830, u32@0xc */
ts4l_word ts4l_if_call_seq_u32_offc_831A3268(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p3;
    ts4l_word t1;
    ts4l_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    p3 = (ts4l_word)t1;
    if ((ts4l_word)t1 != 0) {
        t2 = fn_8340D830((ts4l_word)t1, (ts4l_word)(546766848));
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)0;
        p3 = (ts4l_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x831A3308: if_call_seq u32@0xc, u32@0x18, fn_8340D830, u32@0xc, u32@0x8, u32@0x10 */
ts4l_word ts4l_if_call_seq_u32_offc_831A3308(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p3;
    ts4l_word t1;
    ts4l_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 24) = (ts4l_word)0;
    p3 = (ts4l_word)t1;
    if ((ts4l_word)t1 != 0) {
        t2 = fn_8340D830((ts4l_word)t1, (ts4l_word)(546766848));
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)0;
        p3 = (ts4l_word)t2;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 8) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 16) = (ts4l_word)7;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)1;
    return p3;
}

/* Loader_DLL.xex 0x831A3410: if_call_seq u32@0xc, fn_8340D830, u32@0xc */
ts4l_word ts4l_if_call_seq_u32_offc_831A3410(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p3;
    ts4l_word t1;
    ts4l_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    p3 = (ts4l_word)t1;
    if ((ts4l_word)t1 != 0) {
        t2 = fn_8340D830((ts4l_word)t1, (ts4l_word)(546766848));
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)0;
        p3 = (ts4l_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x831A5698: set u32@0x4, u32@0x24, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4l_set_u32_off4_831A5698(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)a1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 36) = (ts4l_word)a2;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 8) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 16) = (ts4l_word)7;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 24) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 28) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 40) = (ts4l_word)a2;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)a3;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)a4;
    return;
}

/* Loader_DLL.xex 0x831AF788: addr lbl_83025C98, u16@0x14, lbl_83025CB4, u32@lbl_83025C98, u16@0x16, u32@lbl_83025CB4 */
void ts4l_addr_lbl_83025C98_831AF788(ts4l_word a0)
{
    *(unsigned short *)((char *)(ts4l_word)(a0) + 20) = (unsigned short)7;
    *(unsigned short *)((char *)(ts4l_word)(a0) + 22) = (unsigned short)(*(ts4l_word *)lbl_83025C98);
    *(unsigned short *)((char *)(ts4l_word)(a0) + 24) = (unsigned short)(*(ts4l_word *)lbl_83025CB4);
    *(unsigned short *)((char *)(ts4l_word)(a0) + 26) = (unsigned short)(*(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_83025C98) + 4));
    *(unsigned short *)((char *)(ts4l_word)(a0) + 28) = (unsigned short)(*(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_83025CB4) + 4));
    *(unsigned short *)((char *)(ts4l_word)(a0) + 30) = (unsigned short)(*(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_83025C98) + 8));
    *(unsigned short *)((char *)(ts4l_word)(a0) + 32) = (unsigned short)(*(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_83025CB4) + 8));
    *(unsigned short *)((char *)(ts4l_word)(a0) + 34) = (unsigned short)(*(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_83025C98) + 12));
    *(unsigned short *)((char *)(ts4l_word)(a0) + 36) = (unsigned short)(*(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_83025CB4) + 12));
    *(unsigned short *)((char *)(ts4l_word)(a0) + 38) = (unsigned short)(*(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_83025C98) + 16));
    *(unsigned short *)((char *)(ts4l_word)(a0) + 40) = (unsigned short)(*(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_83025CB4) + 16));
    *(unsigned short *)((char *)(ts4l_word)(a0) + 42) = (unsigned short)(*(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_83025C98) + 20));
    *(unsigned short *)((char *)(ts4l_word)(a0) + 44) = (unsigned short)(*(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_83025CB4) + 20));
    *(unsigned short *)((char *)(ts4l_word)(a0) + 46) = (unsigned short)(*(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_83025C98) + 24));
    *(unsigned short *)((char *)(ts4l_word)(a0) + 48) = (unsigned short)(*(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_83025CB4) + 24));
    return;
}

/* Loader_DLL.xex 0x831B0E48: if_fn  */
ts4l_word ts4l_if_fn_831B0E48(ts4l_word a0, ts4l_word a1)
{
    if ((ts4l_word)a1 == 1) {
        return ((196608) | 22960);
    }
    if ((ts4l_word)a1 == 2) {
        return ((327680) | 45284);
    }
    if ((ts4l_word)a0 == 1) {
        return ((196608) | 24012);
    }
    return ((327680) | 51508);
}

/* Loader_DLL.xex 0x831B14B0: call_seq fn_833E3A30, u32@0x1000 */
ts4l_word ts4l_call_seq_fn_833E3A30_831B14B0(ts4l_word a0)
{
    ts4l_word t1;
    float t2;

    t1 = fn_833E3A30((ts4l_word)a0, (ts4l_word)0, (ts4l_word)4096);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4096) = (ts4l_word)0;
    t2 = *(float *)lbl_830009F8;
    *(float *)((char *)(ts4l_word)(a0) + 4116) = t2;
    *(float *)((char *)(ts4l_word)(a0) + 4120) = t2;
    return t1;
}

/* Loader_DLL.xex 0x831B1590: call_seq fn_833E3A30, u32@0x4000 */
ts4l_word ts4l_call_seq_fn_833E3A30_831B1590(ts4l_word a0)
{
    ts4l_word t1;
    float t2;

    t1 = fn_833E3A30((ts4l_word)a0, (ts4l_word)0, (ts4l_word)16384);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 16384) = (ts4l_word)0;
    t2 = *(float *)lbl_830009F8;
    *(float *)((char *)(ts4l_word)(a0) + 16404) = t2;
    *(float *)((char *)(ts4l_word)(a0) + 16408) = t2;
    return t1;
}

/* Loader_DLL.xex 0x831B1EB8: call_seq fn_833E3A30, u32@0x400 */
ts4l_word ts4l_call_seq_fn_833E3A30_831B1EB8(ts4l_word a0)
{
    ts4l_word t1;

    t1 = fn_833E3A30((ts4l_word)a0, (ts4l_word)0, (ts4l_word)1024);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1024) = (ts4l_word)0;
    *(float *)((char *)(ts4l_word)(a0) + 1048) = (*(float *)lbl_830009F8);
    return t1;
}

/* Loader_DLL.xex 0x831B1FA8: call_seq fn_833E3A30, u32@0x800 */
ts4l_word ts4l_call_seq_fn_833E3A30_831B1FA8(ts4l_word a0)
{
    ts4l_word t1;
    float t2;

    t1 = fn_833E3A30((ts4l_word)a0, (ts4l_word)0, (ts4l_word)2048);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 2048) = (ts4l_word)0;
    t2 = *(float *)lbl_830009F8;
    *(float *)((char *)(ts4l_word)(a0) + 2072) = t2;
    *(float *)((char *)(ts4l_word)(a0) + 2076) = t2;
    return t1;
}

/* Loader_DLL.xex 0x831B42D0: call_seq fn_833E3A30 */
ts4l_word ts4l_call_seq_fn_833E3A30_831B42D0(ts4l_word a0)
{
    fn_833E3A30((ts4l_word)a0, (ts4l_word)0, (ts4l_word)(65536));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + (65536)) = (ts4l_word)0;
    return a0;
}

/* Loader_DLL.xex 0x831B4318: call_seq fn_833E3A30 */
ts4l_word ts4l_call_seq_fn_833E3A30_831B4318(ts4l_word a0)
{
    fn_833E3A30((ts4l_word)a0, (ts4l_word)0, (ts4l_word)(131072));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + (131072)) = (ts4l_word)0;
    return a0;
}

/* Loader_DLL.xex 0x831BB1B8: if_call_seq u32@0xc, fn_831BAF50, u32@0xc, u32@0x14, fn_831BAF50, u32@0x14 */
ts4l_word ts4l_if_call_seq_u32_offc_831BB1B8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p9;
    ts4l_word t1;
    ts4l_word t4;
    ts4l_word t7;
    ts4l_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    if ((ts4l_word)t1 != 0) {
        fn_831BAF50((ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)0;
    }
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 20);
    if ((ts4l_word)t4 != 0) {
        fn_831BAF50((ts4l_word)t4);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)0;
    }
    t7 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 24);
    p9 = (ts4l_word)t7;
    if ((ts4l_word)t7 != 0) {
        t8 = fn_831BAF50((ts4l_word)t7);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 24) = (ts4l_word)0;
        p9 = (ts4l_word)t8;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    return p9;
}

/* Loader_DLL.xex 0x831BB288: if_call_seq fn_8340D710, fn_833E3A30 */
ts4l_word ts4l_if_call_seq_fn_8340D710_831BB288(ts4l_word a0)
{
    ts4l_word p3;
    ts4l_word t1;

    t1 = fn_8340D710((ts4l_word)a0, (ts4l_word)((613154816) | 32768));
    p3 = (ts4l_word)t1;
    if ((ts4l_word)t1 != 0) {
        fn_833E3A30((ts4l_word)t1, (ts4l_word)0, (ts4l_word)a0);
        p3 = (ts4l_word)t1;
    }
    return p3;
}

/* Loader_DLL.xex 0x831BB3B8: if_call_seq fn_831BB2E0, fn_833E3A30 */
ts4l_word ts4l_if_call_seq_fn_831BB2E0_831BB3B8(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p3;
    ts4l_word t1;

    t1 = fn_831BB2E0((ts4l_word)a0, (ts4l_word)a1);
    p3 = (ts4l_word)t1;
    if ((ts4l_word)t1 != 0) {
        fn_833E3A30((ts4l_word)t1, (ts4l_word)0, (ts4l_word)a0);
        p3 = (ts4l_word)t1;
    }
    return p3;
}

/* Loader_DLL.xex 0x831BC100: if_call_seq u32@0x3c, fn_831C0088, fn_831BF558, fn_831BFC20, fn_831FAAA8 */
ts4l_word ts4l_if_call_seq_u32_off3c_831BC100(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p7;
    int t1;
    int t5;
    ts4l_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 60);
    if ((int)t1 > 2) {
        fn_831C0088();
    }
    fn_831BF558((ts4l_word)a0);
    t5 = fn_831BFC20((ts4l_word)a0);
    p7 = (ts4l_word)t5;
    if ((int)t5 >= 0) {
        t6 = fn_831FAAA8((ts4l_word)a0);
        p7 = (ts4l_word)t6;
    }
    return p7;
}

/* Loader_DLL.xex 0x831BCBD8: if_get u32@0x1bc, u32@0x1c0, u32@0x1c0, u32@0xfc, u32@0x100, u32@0x10c */
void ts4l_if_get_u32_off1bc_831BCBD8(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p15;
    int t1;
    ts4l_word t11;
    ts4l_word t12;
    ts4l_word t13;
    int t14;
    int t3;
    ts4l_word t7;
    ts4l_word t8;
    ts4l_word t9;
    ts4l_word t10;
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t6;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 444);
    if ((int)t1 != 0) {
        t11 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 456);
        t12 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 252);
        t13 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 256);
        t14 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 268);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 464) = (ts4l_word)((int)t12 >> t11);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 468) = (ts4l_word)((int)t13 >> t11);
        p15 = (ts4l_word)((short)a1);
        if ((int)t14 < (int)((short)a1)) {
            p15 = (ts4l_word)t14;
        }
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 472) = (ts4l_word)p15;
        return;
    }
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 448);
    if ((int)t3 != 0) {
        t7 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 456);
        t8 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 252);
        t9 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 256);
        t10 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 268);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 464) = (ts4l_word)(t8 << t7);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 468) = (ts4l_word)(t9 << t7);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 472) = (ts4l_word)t10;
        return;
    }
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 252);
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 256);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 268);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 464) = (ts4l_word)t4;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 468) = (ts4l_word)t5;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 472) = (ts4l_word)t6;
    return;
}

/* Loader_DLL.xex 0x831BE470: call_seq fn_833E3A30, fn_831FEEB0, fn_831FF318, fn_831FF318, fn_831FF318, fn_831FF318 */
ts4l_word ts4l_call_seq_fn_833E3A30_831BE470(ts4l_word a0)
{
    ts4l_word t6;

    fn_833E3A30((ts4l_word)a0, (ts4l_word)0, (ts4l_word)168);
    fn_831FEEB0((ts4l_word)a0);
    fn_831FF318((ts4l_word)(a0 + 24));
    fn_831FF318((ts4l_word)(a0 + 44));
    fn_831FF318((ts4l_word)(a0 + 64));
    t6 = fn_831FF318((ts4l_word)(a0 + 84));
    return t6;
}

/* Loader_DLL.xex 0x831BE4D0: if_call_seq fn_831FEED0, fn_831FF338, fn_831FF338, fn_831FF338, fn_831FF338, u32@0x94 */
ts4l_word ts4l_if_call_seq_fn_831FEED0_831BE4D0(ts4l_word a0)
{
    ts4l_word t6;
    ts4l_word t9;
    ts4l_word t17;

    fn_831FEED0((ts4l_word)a0);
    fn_831FF338((ts4l_word)(a0 + 24));
    fn_831FF338((ts4l_word)(a0 + 44));
    fn_831FF338((ts4l_word)(a0 + 64));
    fn_831FF338((ts4l_word)(a0 + 84));
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 148);
    if ((ts4l_word)t6 != 0) {
        fn_831BB278((ts4l_word)t6);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 148) = (ts4l_word)0;
    }
    t9 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 160);
    if ((ts4l_word)t9 != 0) {
        fn_831BB278((ts4l_word)t9);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 160) = (ts4l_word)0;
    }
    fn_833E3A30((ts4l_word)a0, (ts4l_word)0, (ts4l_word)168);
    fn_831FEEB0((ts4l_word)a0);
    fn_831FF318((ts4l_word)(a0 + 24));
    fn_831FF318((ts4l_word)(a0 + 44));
    fn_831FF318((ts4l_word)(a0 + 64));
    t17 = fn_831FF318((ts4l_word)(a0 + 84));
    return t17;
}

/* Loader_DLL.xex 0x831C0FF8: if_get u32@0x8, u32@0x24, u32@0x28, u32@0x2c, u32@0x30, u32@0x20 */
void ts4l_if_get_u32_off8_831C0FF8(ts4l_word a0)
{
    ts4l_word t1;
    int t2;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 8);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 36) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 40) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)0;
    t2 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 704);
    if ((int)t2 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 68) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 76) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 28) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 24) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 80) = (ts4l_word)0;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 84) = (ts4l_word)(ts4l_word)fn_831C0FF0;
    return;
}

/* Loader_DLL.xex 0x831C13E0: if_get u32@0x4c, u32@0x8, u32@0x2c0, u32@0x8, u32@0x2c0, u32@0x1c */
ts4l_word ts4l_if_get_u32_off4c_831C13E0(ts4l_word a0)
{
    int t1;
    int t5;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 76);
    if ((int)t1 != 0) {
        t5 = *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 8))) + 704);
        if ((int)t5 == 0 || (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 32)) + (*(ts4l_word *)((char *)(ts4l_word)(a0) + 28))) >= (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 24)) + (*(ts4l_word *)((char *)(ts4l_word)(a0) + 20)))) {
            return 1;
        }
        return 0;
    }
    return 0;
}

/* Loader_DLL.xex 0x831C1600: if_set u32@0x8, u32@0x0, u32@0x4, u32@0xc, u32@0x10, u32@0x14 */
void ts4l_if_set_u32_off8_831C1600(ts4l_word a0, ts4l_word a1)
{
    int t3;

    *(ts4l_word *)((char *)(ts4l_word)(a0) + 8) = (ts4l_word)a1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 16) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 24) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 76) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 28) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)15;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a1) + 0))) + 212));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 36) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 40) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)0;
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 704);
    if ((int)t3 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 68) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 76) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 28) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 24) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 80) = (ts4l_word)0;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 84) = (ts4l_word)(ts4l_word)fn_831C0FF0;
    return;
}

/* Loader_DLL.xex 0x831C1D58: if_call_seq fn_831C1AB8, u16@0x10 */
ts4l_word ts4l_if_call_seq_fn_831C1AB8_831C1D58(ts4l_word a0)
{
    ts4l_word loc50[4];
    int t1;
    ts4l_word t2;

    t1 = fn_831C1AB8((ts4l_word)(a0 + 224), (ts4l_word)1, (ts4l_word)(ts4l_word)&loc50[0]);
    if ((int)t1 >= 0) {
        t2 = loc50[0];
        *(unsigned short *)((char *)(ts4l_word)(a0) + 16) = (unsigned short)t2;
    }
    return t1;
}

/* Loader_DLL.xex 0x831C6760: if_call_seq u16@0xae, fn_832014C0, u32@0xa4, u16@0xa8, fn_83201218 */
ts4l_word ts4l_if_call_seq_u16_offae_831C6760(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    int t3;

    fn_832014C0((ts4l_word)a2, (ts4l_word)a4, (ts4l_word)(*(unsigned short *)((char *)(ts4l_word)(a0) + 174)));
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 164);
    if ((int)t3 == 1) {
        fn_83201218((ts4l_word)a0, (ts4l_word)a2, (ts4l_word)(a1 + 1616), (ts4l_word)a3, (ts4l_word)(a1 + 1456), (ts4l_word)a4, (ts4l_word)(*(unsigned short *)((char *)(ts4l_word)(a0) + 168)));
    }
    return 1;
}

/* Loader_DLL.xex 0x831C7540: call_seq fn_833E3A30, u32@0x8, u32@0x4, u32@0x0, u64@0x10, u64@0x18 */
ts4l_word ts4l_call_seq_fn_833E3A30_831C7540(ts4l_word a0)
{
    ts4l_word t1;

    t1 = fn_833E3A30((ts4l_word)a0, (ts4l_word)0, (ts4l_word)120);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 8) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 16) = (ts4l_u64)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 24) = (ts4l_u64)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 104) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)(4288675840);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 36) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 40) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 64) = (ts4l_word)500;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 68) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 72) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 76) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 80) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 84) = (ts4l_word)200;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 88) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 92) = (ts4l_word)2;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 96) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 100) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 108) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 112) = (ts4l_word)0;
    return t1;
}

/* Loader_DLL.xex 0x831CBA30: if_call_seq fn_831CCB90, fn_831CCA18, fn_831C1C28, fn_831C1AB8, u32@0x0, fn_831C1C28 */
ts4l_word ts4l_if_call_seq_fn_831CCB90_831CBA30(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word loc50[4];
    int t1;
    int t2;
    ts4l_word t4;
    int t11;
    int t8;
    int t9;
    ts4l_word t10;
    int t5;
    int t6;
    ts4l_word t7;

    t1 = fn_831CCB90((ts4l_word)a2, (ts4l_word)(a1 + 3));
    if ((int)t1 >= 0) {
        t2 = fn_831CCA18((ts4l_word)a2, (ts4l_word)3, (ts4l_word)(ts4l_word)&loc50[0]);
        if ((int)t2 >= 0) {
            t4 = loc50[0];
            if ((ts4l_word)(t4 & 0x80000000) == 0) {
                t11 = fn_831C1C28((ts4l_word)a2, (ts4l_word)1);
                if ((int)t11 >= 0) {
                    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
                    return t11;
                }
                return t11;
            }
            if ((int)(t4 & 0x40000000) == 0) {
                t8 = fn_831C1C28((ts4l_word)a2, (ts4l_word)2);
                if ((int)t8 >= 0) {
                    t9 = fn_831C1AB8((ts4l_word)a2, (ts4l_word)2, (ts4l_word)(ts4l_word)&loc50[0]);
                    if ((int)t9 >= 0) {
                        t10 = loc50[0];
                        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(t10 + 1);
                        return t9;
                    }
                    return t9;
                }
                return t8;
            }
            if ((int)(t4 & 0x20000000) == 0) {
                t5 = fn_831C1C28((ts4l_word)a2, (ts4l_word)3);
                if ((int)t5 >= 0) {
                    t6 = fn_831C1AB8((ts4l_word)a2, (ts4l_word)a1, (ts4l_word)(ts4l_word)&loc50[0]);
                    if ((int)t6 >= 0) {
                        t7 = loc50[0];
                        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(t7 + 4);
                        return t6;
                    }
                    return t6;
                }
                return t5;
            }
            return ((2147745792) | 2);
        }
        return t2;
    }
    return t1;
}

/* Loader_DLL.xex 0x831CE2D8: call_seq u32@0x0, u16@0x10, u16@0x10, u32@0x0, u16@0x16, u32@0x0 */
ts4l_word ts4l_call_seq_u32_off0_831CE2D8(ts4l_word a0)
{
    ts4l_word t1;
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t6;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    *(unsigned short *)((char *)(ts4l_word)(t1) + 16) = (unsigned short)(((*(unsigned short *)((char *)(ts4l_word)(t1) + 16)) & 0xffff) & 0xfffff8ff);
    *(unsigned short *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 22) = (unsigned short)160;
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 40) = (ts4l_word)(t5 + -36);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 28) = (ts4l_word)(t4 + 28);
    t6 = fn_833E3A30((ts4l_word)(t4 + 28), (ts4l_word)0, (ts4l_word)(t5 + -36));
    *(unsigned short *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 6) = (unsigned short)160;
    return t6;
}

/* Loader_DLL.xex 0x831CE350: if_call_seq u32@0x0, u16@0x10, u16@0x10, u32@0x0, u16@0x16, u32@0xc */
ts4l_word ts4l_if_call_seq_u32_off0_831CE350(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;
    ts4l_word t4;
    ts4l_word t5;

    if ((ts4l_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    *(volatile unsigned short *)((char *)(ts4l_word)(t1) + 16) = (unsigned short)(((*(unsigned short *)((char *)(ts4l_word)(t1) + 16)) & 0xffff) & 0xfffff8ff);
    *(volatile unsigned short *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 22) = (unsigned short)160;
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 28) = (ts4l_word)(t5 + 28);
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 40) = (ts4l_word)(t4 + -36);
    fn_833E3A30((ts4l_word)(t5 + 28), (ts4l_word)0, (ts4l_word)(t4 + -36));
    *(volatile unsigned short *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 6) = (unsigned short)160;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 72) = (ts4l_word)a1;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 76) = (ts4l_word)2;
    return 0;
}

/* Loader_DLL.xex 0x831CF518: if_call_seq fn_8340D710, fn_833E3A30, fn_83201560, u32@0x50, fn_83201500, lbl_83019808 */
ts4l_word ts4l_if_call_seq_fn_8340D710_831CF518(void)
{
    ts4l_word t1;
    ts4l_word t3;

    t1 = fn_8340D710((ts4l_word)216, (ts4l_word)((613154816) | 32768));
    if ((ts4l_word)t1 != 0) {
        fn_833E3A30((ts4l_word)t1, (ts4l_word)0, (ts4l_word)216);
        t3 = fn_83201560((ts4l_word)0, (ts4l_word)0);
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 80) = (ts4l_word)t3;
        if ((ts4l_word)t3 == 0) {
            fn_831CE240((ts4l_word)t1);
            return 0;
        }
        fn_83201500((ts4l_word)t3);
        fn_832014F8((ts4l_word)(ts4l_word)lbl_83019808);
        return t1;
    }
    return 0;
}

/* Loader_DLL.xex 0x831CF788: if_fn  */
ts4l_word ts4l_if_fn_831CF788(int a0, int a1, ts4l_word a2, int a3)
{
    if ((int)a0 != 0) {
        if ((int)a1 <= 2) {
            return ((a2 + 11) & 0xff);
        }
        if ((int)a3 != 0) {
            return ((a2 + 17) & 0xff);
        }
        return ((a2 + 6) & 0xff);
    }
    return 0;
}

/* Loader_DLL.xex 0x831D5470: get u32@0x0, u32@0x14, u32@0x4, u32@0x18, u32@0x8, u32@0x1c */
void ts4l_get_u32_off0_831D5470(ts4l_word a0)
{
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t3;
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t6;
    ts4l_word t7;
    ts4l_word t8;
    ts4l_word t9;
    ts4l_word t10;

    t1 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    t2 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 20);
    t3 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 4);
    t4 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 24);
    t5 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 8);
    t6 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 28);
    t7 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    t8 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 32);
    t9 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 16);
    t10 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 36);
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)t2;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)t1;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)t4;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 24) = (ts4l_word)t3;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 8) = (ts4l_word)t6;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 28) = (ts4l_word)t5;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)t8;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)t7;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 16) = (ts4l_word)t10;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 36) = (ts4l_word)t9;
    return;
}

/* Loader_DLL.xex 0x831D54D8: get u32@0x0, u32@0x0, u32@0x0, u32@0x0, u32@0x4, u32@0x4 */
void ts4l_get_u32_off0_831D54D8(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t3;
    ts4l_word t5;
    ts4l_word t7;
    ts4l_word t9;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 0);
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)t1;
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)t2;
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 4));
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 4) = (ts4l_word)t3;
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 8);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 8) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 8));
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 8) = (ts4l_word)t5;
    t7 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 12));
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 12) = (ts4l_word)t7;
    t9 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 16);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 16) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 16));
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 16) = (ts4l_word)t9;
    return;
}

/* Loader_DLL.xex 0x831D5618: if_call_seq fn_831BB268, u32@0xc, u32@0x10, u32@0x4, fn_831D52D0 */
ts4l_word ts4l_if_call_seq_fn_831BB268_831D5618(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p3;
    ts4l_word p4;
    ts4l_word t1;
    ts4l_word t2;

    t1 = fn_831BB268((ts4l_word)40);
    p4 = (ts4l_word)t1;
    if ((ts4l_word)t1 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 12) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 16) = (ts4l_word)32;
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 4) = (ts4l_word)0;
        p3 = (ts4l_word)t1;
        if ((ts4l_word)a0 != 0) {
            t2 = fn_831D52D0((ts4l_word)t1, (ts4l_word)a0, (ts4l_word)a1);
            p3 = (ts4l_word)t2;
        }
        p4 = (ts4l_word)p3;
    }
    return p4;
}

/* Loader_DLL.xex 0x831E1428: if_set u32@0x0, u32@0x30d0, u32@0x30d0, u32@0x0, u32@0x0, u32@0x0 */
void ts4l_if_set_u32_off0_831E1428(ts4l_word a0, ts4l_word a1, int a2)
{
    ts4l_word p3;
    int t2;

    *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)a2;
    if ((int)a2 >= 259) {
        return;
    }
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12496);
    if ((int)a2 >= (int)t2) {
        p3 = (ts4l_word)(a2 + 1);
        if ((int)((int)((int)a2 * 125) / (int)100) > (int)(a2 + 1)) {
            p3 = (ts4l_word)((int)((int)a2 * 125) / (int)100);
        }
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)p3;
        if ((int)p3 <= 259) {
            return;
        }
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)259;
        return;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)(a2 + 1);
    return;
}

/* Loader_DLL.xex 0x831ECB38: if_get u32@0x0, u16@0x22, u32@0x11c, u32@0x11c, u32@0x120, u32@0x120 */
void ts4l_if_get_u32_off0_831ECB38(ts4l_word a0)
{
    ts4l_word t1;
    unsigned short t2;
    int t4;
    int t17;
    int t7;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    t2 = *(unsigned short *)((char *)(ts4l_word)(t1) + 34);
    if ((ts4l_word)t2 == 1) {
        return;
    }
    t4 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 284);
    if ((int)t4 == 0) {
        t17 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 288);
        if ((int)t17 == 1) {
            *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 660) = (ts4l_word)(ts4l_word)lbl_83019EA0;
            *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 664) = (ts4l_word)(ts4l_word)lbl_83022CB0;
            *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 668) = (ts4l_word)60;
            return;
        }
        if ((int)t17 == 2) {
            *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 660) = (ts4l_word)(ts4l_word)lbl_8301C4D8;
            *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 664) = (ts4l_word)(ts4l_word)lbl_83022D88;
            *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 668) = (ts4l_word)340;
            return;
        }
        if ((int)t17 != 3) {
            return;
        }
        *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 660) = (ts4l_word)(ts4l_word)lbl_83021028;
        *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 664) = (ts4l_word)(ts4l_word)lbl_830231A8;
        *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 668) = (ts4l_word)70;
        return;
    }
    if ((int)t4 != 1) {
        return;
    }
    t7 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 288);
    if ((int)t7 == 1) {
        *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 660) = (ts4l_word)(ts4l_word)lbl_8301B378;
        *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 664) = (ts4l_word)(ts4l_word)lbl_83022D30;
        *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 668) = (ts4l_word)40;
        return;
    }
    if ((int)t7 == 2) {
        *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 660) = (ts4l_word)(ts4l_word)lbl_8301EEA0;
        *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 664) = (ts4l_word)(ts4l_word)lbl_83023038;
        *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 668) = (ts4l_word)180;
        return;
    }
    if ((int)t7 != 3) {
        return;
    }
    *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 660) = (ts4l_word)(ts4l_word)lbl_83021F10;
    *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 664) = (ts4l_word)(ts4l_word)lbl_83023240;
    *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 668) = (ts4l_word)40;
    return;
}
