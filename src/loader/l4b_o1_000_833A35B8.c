/* Loader_DLL.xex 0x833A35B8-0x83488BF0, executable version 0.0.0.3.
   Small accessor / call-sequence functions generated from the original
   control flow; parameters are untyped words and fields are byte offsets. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
typedef __int64 ts4l_s64;
#else
typedef unsigned long long ts4l_u64;
typedef long long ts4l_s64;
#endif
typedef unsigned long ts4l_word;
extern long _InterlockedExchange(volatile long *value, long v);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedExchange)
#endif

extern char __imp_ExThreadObjectType[];
extern char __imp_KeDebugMonitorData[];
extern char __imp_XboxKrnlVersion[];
extern char fn_834141C0[];
extern char lbl_8306F7CC[];
extern char lbl_8306F7D0[];
extern char lbl_8306FAB0[];
extern char lbl_83071C74[];
extern char lbl_83072E84[];
extern char lbl_83073884[];
extern char lbl_8307392C[];
extern char lbl_8307393C[];
extern char lbl_8307394C[];
extern char lbl_8307395C[];
extern char lbl_8307396C[];
extern char lbl_8307397C[];
extern char lbl_8307398C[];
extern char lbl_8307399C[];
extern char lbl_830739AC[];
extern char lbl_830739BC[];
extern char lbl_830739CC[];
extern char lbl_830739DC[];
extern char lbl_830739EC[];
extern char lbl_830739FC[];
extern char lbl_83073A0C[];
extern char lbl_83073A1C[];
extern char lbl_83073A2C[];
extern char lbl_83073A3C[];
extern char lbl_83073A4C[];
extern char lbl_83073A5C[];
extern char lbl_83073A6C[];
extern char lbl_83073A7C[];
extern char lbl_83073A8C[];
extern char lbl_83073A9C[];
extern char lbl_83073AAC[];
extern char lbl_83073ABC[];
extern char lbl_83073ACC[];
extern char lbl_83073ADC[];
extern char lbl_83073AEC[];
extern char lbl_83073AFC[];
extern char lbl_83073B0C[];
extern char lbl_83073B1C[];
extern char lbl_83073B2C[];
extern char lbl_83073BAC[];
extern char lbl_83073BC8[];
extern char lbl_830755CC[];
extern char lbl_83075808[];
extern char lbl_8307588C[];
extern char lbl_830758C4[];
extern char lbl_83075C00[];
extern char lbl_83075C38[];
extern char lbl_8307A448[];
extern char lbl_8307AECC[];
extern char lbl_8307AEE8[];
extern char lbl_8307B128[];
extern char lbl_8307EC00[];
extern char lbl_8307EC30[];
extern char lbl_8307EC40[];
extern char lbl_8307EC50[];
extern char lbl_8307EC60[];
extern char lbl_8307EC70[];
extern char lbl_8307EC80[];
extern char lbl_8307EC90[];
extern char lbl_8307ECA0[];
extern char lbl_8307ECB0[];
extern char lbl_8307ECC0[];
extern char lbl_8307ECD0[];
extern char lbl_8307ECE0[];
extern char lbl_8307ECF0[];
extern char lbl_8307ED00[];
extern char lbl_8307ED10[];
extern char lbl_8307ED20[];
extern char lbl_8307ED30[];
extern char lbl_8307ED40[];
extern char lbl_8307ED50[];
extern char lbl_8307ED60[];
extern char lbl_8307ED70[];
extern char lbl_8307ED80[];
extern char lbl_8307ED90[];
extern char lbl_8307EDA0[];
extern char lbl_8307EDB0[];
extern char lbl_8307EDC0[];
extern char lbl_8307EDD0[];
extern char lbl_8307EDE0[];
extern char lbl_8307EDF0[];
extern char lbl_8307EE00[];
extern char lbl_8307EE10[];
extern char lbl_8352C3C8[];
extern char lbl_8352C3CC[];
extern char lbl_8352C3D0[];
extern char lbl_8352C6A0[];
extern char lbl_8352CA04[];
extern char lbl_8352CA10[];
extern char lbl_8352D1CC[];
extern char lbl_8352D1E8[];
extern char lbl_8352D220[];
extern char lbl_8352D368[];
extern char lbl_83543A34[];
extern char lbl_835446D8[];
extern char lbl_835446F4[];
extern char lbl_83544724[];
extern char lbl_83544728[];
extern char lbl_8354472C[];
extern char lbl_8354BAB0[];
ts4l_word HalReturnToFirmware();
ts4l_word KeSetDisableBoostThread();
ts4l_word MmAllocatePhysicalMemoryEx();
ts4l_word NtFreeVirtualMemory();
ts4l_word NtSignalAndWaitForSingleObjectEx();
ts4l_word NtWaitForSingleObjectEx();
ts4l_word NtWriteFile();
ts4l_word ObDereferenceObject();
ts4l_word ObReferenceObjectByHandle();
ts4l_word RtlCompareMemory();
ts4l_word RtlEnterCriticalSection();
ts4l_word RtlLeaveCriticalSection();
ts4l_word RtlUnicodeToMultiByteN();
ts4l_word XMsgStartIORequest();
ts4l_word XamInputGetCapabilities();
ts4l_word XamInputSetState();
ts4l_word XamReadTileToTexture();
ts4l_word XamUserCreateStatsEnumerator();
ts4l_word XexLoadImage();
ts4l_word fn_830AD4F0();
ts4l_word fn_830AF1B8();
ts4l_word fn_833A2558();
ts4l_word fn_833E0798();
ts4l_word fn_833E1758();
ts4l_word fn_833E27A8();
ts4l_word fn_833E27F8();
ts4l_word fn_833E3A30();
ts4l_word fn_833E3AD0();
ts4l_word fn_833E74C0();
ts4l_word fn_833E8350();
ts4l_word fn_833E8E50();
ts4l_word fn_833E8E98();
ts4l_word fn_833E9D50();
ts4l_word fn_833E9F90();
ts4l_word fn_833F5188();
ts4l_word fn_833F7960();
ts4l_word fn_833F8280();
ts4l_word fn_833F9160();
ts4l_word fn_833F91C8();
ts4l_word fn_833F9D68();
ts4l_word fn_833FAED8();
ts4l_word fn_833FB560();
ts4l_word fn_833FDA98();
ts4l_word fn_833FE300();
ts4l_word fn_83400FE8();
ts4l_word fn_83401118();
ts4l_word fn_834015C0();
ts4l_word fn_83401B40();
ts4l_word fn_83401FE0();
ts4l_word fn_83402088();
ts4l_word fn_83402330();
ts4l_word fn_834024E0();
ts4l_word fn_83408018();
ts4l_word fn_8340CE50();
ts4l_word fn_8340D0A0();
ts4l_word fn_8340D680();
ts4l_word fn_8340D710();
ts4l_word fn_8340D830();
ts4l_word fn_8340F068();
ts4l_word fn_8340F088();
ts4l_word fn_83413DB0();
ts4l_word fn_83414000();
ts4l_word fn_834141B8();
ts4l_word fn_834144F0();
ts4l_word fn_83415BF0();
ts4l_word fn_83423158();
ts4l_word fn_83423F10();
ts4l_word fn_83430450();
ts4l_word fn_8343C240();
ts4l_word fn_8343D800();
ts4l_word fn_8343FD80();
ts4l_word fn_8343FDB8();
ts4l_word fn_8343FDD0();
ts4l_word fn_834480F0();
ts4l_word fn_8344A150();
ts4l_word fn_8344B7D0();
ts4l_word fn_8344B890();
ts4l_word fn_8344C5B0();
ts4l_word fn_8344EF30();
ts4l_word fn_83451030();
ts4l_word fn_834547F0();
ts4l_word fn_83455050();
ts4l_word fn_834552D0();
ts4l_word fn_83465B20();
ts4l_word fn_8346B788();
ts4l_word fn_834773C8();
ts4l_word fn_83477720();
ts4l_word fn_83485658();
ts4l_word fn_83487878();
ts4l_word fn_83487AC0();
ts4l_word fn_83487B40();

/* Loader_DLL.xex 0x833A35B8: if_call_seq u32@0x0, u32@0x47f4, u32@0x47f4, fn_830AF1B8, u32@0xdc0, fn_8340D0A0 */
ts4l_word ts4l_if_call_seq_u32_off0_833A35B8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p11;
    ts4l_word t1;
    ts4l_word t3;
    ts4l_word t6;
    ts4l_word t10;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    p11 = (ts4l_word)a0;
    if ((ts4l_word)t1 != 0) {
        t3 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 18420);
        if ((ts4l_word)t3 != 0) {
            fn_830AF1B8((ts4l_word)t3);
        }
        t6 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 3520);
        if ((ts4l_word)t6 != 0) {
            fn_8340D0A0((ts4l_word)t6);
        }
        fn_833A2558((ts4l_word)t1);
        t10 = fn_833E1758((ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
        p11 = (ts4l_word)t10;
    }
    return p11;
}

/* Loader_DLL.xex 0x833DFA00: if_call_seq XMsgStartIORequest, fn_8340D680 */
ts4l_word ts4l_if_call_seq_XMsgStartIORequest_833DFA00(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3)
{
    ts4l_word p2;
    ts4l_word p4;
    ts4l_word p5;
    ts4l_word p6;
    ts4l_word p7;
    ts4l_word loc50[4];
    int t1;
    ts4l_word t3;

    loc50[2] = (ts4l_word)a1;
    loc50[1] = (ts4l_word)a0;
    loc50[3] = (ts4l_word)a2;
    loc50[0] = (ts4l_word)2;
    t1 = XMsgStartIORequest((ts4l_word)250, (ts4l_word)((458752) | 61), (ts4l_word)a3, (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)16);
    if ((int)t1 >= 0) {
        p4 = (ts4l_word)t1;
        if ((ts4l_word)a3 == 0) {
            t3 = fn_8340D680((ts4l_word)0);
            p4 = (ts4l_word)t3;
        }
        if ((int)p4 >= 0) {
            p6 = (ts4l_word)0;
        } else {
            p5 = (ts4l_word)(p4 & 0xffff);
            if ((int)(p4 & 0x1fff0000) != (int)(458752)) {
                p5 = (ts4l_word)1627;
            }
            p6 = (ts4l_word)p5;
        }
        p7 = (ts4l_word)p6;
    } else {
        p2 = (ts4l_word)(t1 & 0xffff);
        if ((int)(t1 & 0x1fff0000) != (int)(458752)) {
            p2 = (ts4l_word)1627;
        }
        p7 = (ts4l_word)p2;
    }
    return p7;
}

/* Loader_DLL.xex 0x833DFD38: if_call_seq XMsgStartIORequest, fn_8340D680 */
ts4l_word ts4l_if_call_seq_XMsgStartIORequest_833DFD38(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3)
{
    ts4l_word p2;
    ts4l_word p4;
    ts4l_word p5;
    ts4l_word p6;
    ts4l_word p7;
    ts4l_word loc50[4];
    int t1;
    ts4l_word t3;

    loc50[1] = (ts4l_word)a1;
    loc50[0] = (ts4l_word)a0;
    loc50[2] = (ts4l_word)a2;
    t1 = XMsgStartIORequest((ts4l_word)250, (ts4l_word)((458752) | 14), (ts4l_word)a3, (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)12);
    if ((int)t1 >= 0) {
        p4 = (ts4l_word)t1;
        if ((ts4l_word)a3 == 0) {
            t3 = fn_8340D680((ts4l_word)0);
            p4 = (ts4l_word)t3;
        }
        if ((int)p4 >= 0) {
            p6 = (ts4l_word)0;
        } else {
            p5 = (ts4l_word)(p4 & 0xffff);
            if ((int)(p4 & 0x1fff0000) != (int)(458752)) {
                p5 = (ts4l_word)1627;
            }
            p6 = (ts4l_word)p5;
        }
        p7 = (ts4l_word)p6;
    } else {
        p2 = (ts4l_word)(t1 & 0xffff);
        if ((int)(t1 & 0x1fff0000) != (int)(458752)) {
            p2 = (ts4l_word)1627;
        }
        p7 = (ts4l_word)p2;
    }
    return p7;
}

/* Loader_DLL.xex 0x833DFFB0: if_call_seq XMsgStartIORequest, fn_8340D680 */
ts4l_word ts4l_if_call_seq_XMsgStartIORequest_833DFFB0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    ts4l_word p2;
    ts4l_word p4;
    ts4l_word p5;
    ts4l_word p6;
    ts4l_word p7;
    ts4l_word loc50[4];
    int t1;
    ts4l_word t3;

    loc50[1] = (ts4l_word)a1;
    loc50[0] = (ts4l_word)a0;
    loc50[2] = (ts4l_word)a2;
    loc50[3] = (ts4l_word)a3;
    t1 = XMsgStartIORequest((ts4l_word)250, (ts4l_word)((458752) | 8), (ts4l_word)a4, (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)16);
    if ((int)t1 >= 0) {
        p4 = (ts4l_word)t1;
        if ((ts4l_word)a4 == 0) {
            t3 = fn_8340D680((ts4l_word)0);
            p4 = (ts4l_word)t3;
        }
        if ((int)p4 >= 0) {
            p6 = (ts4l_word)0;
        } else {
            p5 = (ts4l_word)(p4 & 0xffff);
            if ((int)(p4 & 0x1fff0000) != (int)(458752)) {
                p5 = (ts4l_word)1627;
            }
            p6 = (ts4l_word)p5;
        }
        p7 = (ts4l_word)p6;
    } else {
        p2 = (ts4l_word)(t1 & 0xffff);
        if ((int)(t1 & 0x1fff0000) != (int)(458752)) {
            p2 = (ts4l_word)1627;
        }
        p7 = (ts4l_word)p2;
    }
    return p7;
}

/* Loader_DLL.xex 0x833E0188: if_call_seq XMsgStartIORequest, fn_8340D680 */
ts4l_word ts4l_if_call_seq_XMsgStartIORequest_833E0188(ts4l_word a0, ts4l_word a1, ts4l_word a2, float f1)
{
    ts4l_word p2;
    ts4l_word p4;
    ts4l_word p5;
    ts4l_word p6;
    ts4l_word p7;
    ts4l_word loc50[4];
    int t1;
    ts4l_word t3;

    (void)a1;
    loc50[0] = (ts4l_word)a0;
    *(float *)((char *)loc50 + 4) = f1;
    t1 = XMsgStartIORequest((ts4l_word)250, (ts4l_word)((458752) | 12), (ts4l_word)a2, (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)8);
    if ((int)t1 >= 0) {
        p4 = (ts4l_word)t1;
        if ((ts4l_word)a2 == 0) {
            t3 = fn_8340D680((ts4l_word)0);
            p4 = (ts4l_word)t3;
        }
        if ((int)p4 >= 0) {
            p6 = (ts4l_word)0;
        } else {
            p5 = (ts4l_word)(p4 & 0xffff);
            if ((int)(p4 & 0x1fff0000) != (int)(458752)) {
                p5 = (ts4l_word)1627;
            }
            p6 = (ts4l_word)p5;
        }
        p7 = (ts4l_word)p6;
    } else {
        p2 = (ts4l_word)(t1 & 0xffff);
        if ((int)(t1 & 0x1fff0000) != (int)(458752)) {
            p2 = (ts4l_word)1627;
        }
        p7 = (ts4l_word)p2;
    }
    return p7;
}

/* Loader_DLL.xex 0x833E0468: if_call_seq lbl_8306F7CC, u32@0x0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_lbl_8306F7CC_833E0468(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8306F7CC;
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x833E0808: if_call_seq u8@0x8, u32@0x4, fn_833E74C0, u32@0x4, u8@0x8 */
ts4l_word ts4l_if_call_seq_u8_off8_833E0808(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p4;
    unsigned char t1;
    ts4l_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4l_word)(a0) + 8);
    p4 = (ts4l_word)a0;
    if ((ts4l_word)t1 != 0) {
        t3 = fn_833E74C0((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 4)));
        p4 = (ts4l_word)t3;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)0;
    *(unsigned char *)((char *)(ts4l_word)(a0) + 8) = (unsigned char)0;
    return p4;
}

/* Loader_DLL.xex 0x833E0850: if_call_seq u8@0x8, u8@0x8, u32@0x4, fn_833E74C0, u8@0x8, u32@0x4 */
ts4l_word ts4l_if_call_seq_u8_off8_833E0850(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    unsigned char t2;
    unsigned char t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4l_word)a0 != (ts4l_word)a1) {
        t2 = *(unsigned char *)((char *)(ts4l_word)(a0) + 8);
        if ((ts4l_word)t2 != 0) {
            fn_833E74C0((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 4)));
        }
        *(unsigned char *)((char *)(ts4l_word)(a0) + 8) = (unsigned char)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)0;
        t6 = *(unsigned char *)((char *)(ts4l_word)(a1) + 8);
        if ((ts4l_word)t6 != 0) {
            fn_833E0798((ts4l_word)a0, (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 4)));
        } else {
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 4));
        }
    }
    return a0;
}

/* Loader_DLL.xex 0x833E08D8: if_call_seq u8@0x8, lbl_8306F7D0, u32@0x0, u32@0x4, fn_833E74C0, u32@0x4 */
ts4l_word ts4l_if_call_seq_u8_off8_833E08D8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word p4;
    unsigned char t1;
    ts4l_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(unsigned char *)((char *)(ts4l_word)(a0) + 8);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8306F7D0;
    p4 = (ts4l_word)a0;
    if ((ts4l_word)t1 != 0) {
        t3 = fn_833E74C0((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 4)));
        p4 = (ts4l_word)t3;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)0;
    *(unsigned char *)((char *)(ts4l_word)(a0) + 8) = (unsigned char)0;
    return p4;
}

/* Loader_DLL.xex 0x833E1760: if_get u32@lbl_83543A34, vcall, fn_833E8E98, fn_833E27F8, fn_833E27A8 */
ts4l_word ts4l_if_get_u32_lbl_83543A34_833E1760(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)lbl_83543A34;
    if ((ts4l_word)t1 != 0) {
        ((ts4l_word (*)(ts4l_word))(t1))((ts4l_word)a0);
    }
    fn_833E8E98((ts4l_word)25);
    t5 = fn_833E27F8((ts4l_word)0, (ts4l_word)1);
    t6 = fn_833E27A8((ts4l_word)t5);
    return t6;
}

/* Loader_DLL.xex 0x833E8188: if_call_seq lbl_8306FAB0, u32@0x0, fn_833F91C8, fn_833E1758 */
ts4l_word ts4l_if_call_seq_lbl_8306FAB0_833E8188(ts4l_word a0, ts4l_word a1)
{

    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8306FAB0;
    fn_833F91C8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x833E8738: loop_get u32@0x0, u32@0x0, vcall */
ts4l_word ts4l_loop_get_u32_off0_833E8738(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word lv1;
    ts4l_word lv2;
    ts4l_word p6;
    ts4l_word p7;
    ts4l_word p8;
    ts4l_word t4;
    ts4l_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    lv1 = (ts4l_word)0;
    lv2 = (ts4l_word)a0;
    while ((ts4l_word)lv2 < (ts4l_word)a1 && (int)lv1 == 0) {
        t4 = *(ts4l_word *)((char *)(ts4l_word)(lv2) + 0);
        p6 = (ts4l_word)lv1;
        if ((ts4l_word)t4 != 0) {
            t5 = ((ts4l_word (*)(ts4l_word))(t4))((ts4l_word)lv1);
            p6 = (ts4l_word)t5;
        }
        p7 = (ts4l_word)p6;
        p8 = (ts4l_word)(lv2 + 4);
        lv1 = p7;
        lv2 = p8;
    }
    return lv1;
}

/* Loader_DLL.xex 0x833E8EC8: if_call_seq fn_833E8E50, fn_83414000, fn_833E8E50, fn_83414000 */
ts4l_word ts4l_if_call_seq_fn_833E8E50_833E8EC8(void)
{
    ts4l_word p6;
    ts4l_word t1;
    ts4l_word t4;
    ts4l_word t5;

    t1 = fn_833E8E50((ts4l_word)252);
    if ((ts4l_word)t1 != 0) {
        fn_83414000((ts4l_word)t1);
    }
    t4 = fn_833E8E50((ts4l_word)255);
    p6 = (ts4l_word)t4;
    if ((ts4l_word)t4 != 0) {
        t5 = fn_83414000((ts4l_word)t4);
        p6 = (ts4l_word)t5;
    }
    return p6;
}

/* Loader_DLL.xex 0x833E90F8: if_call_seq u32@0xc, u32@0x8, fn_833F9D68, u32@0x0, u32@0x0, u32@0x0 */
ts4l_word ts4l_if_call_seq_u32_offc_833E90F8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p5;
    ts4l_word p7;
    ts4l_word p8;
    ts4l_word t1;
    ts4l_word t3;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 12);
    if ((int)(t1 & 0x40) == 0 || (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 8)) != 0) {
        t3 = fn_833F9D68();
        if ((ts4l_word)(t3 & 0xffff) == 65535) {
            p5 = (ts4l_word)-1;
        } else {
            p5 = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a2) + 0)) + 1);
        }
        p7 = (ts4l_word)p5;
        p8 = (ts4l_word)t3;
    } else {
        p7 = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a2) + 0)) + 1);
        p8 = (ts4l_word)a0;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a2) + 0) = (ts4l_word)p7;
    return p8;
}

/* Loader_DLL.xex 0x833EA070: if_call_seq fn_833E8350, fn_833E8350, lbl_8352C3C8, u32@0x0 */
ts4l_word ts4l_if_call_seq_fn_833E8350_833EA070(ts4l_word a0)
{
    ts4l_word p3;
    ts4l_word p4;
    ts4l_word t1;
    ts4l_word t2;

    t1 = fn_833E8350();
    if ((ts4l_word)t1 == 0) {
        p4 = (ts4l_word)12;
    } else {
        t2 = fn_833E8350((ts4l_word)t1);
        if ((ts4l_word)t2 == 0) {
            p3 = (ts4l_word)(ts4l_word)lbl_8352C3C8;
        } else {
            p3 = (ts4l_word)(t2 + 8);
        }
        *(ts4l_word *)((char *)(ts4l_word)(p3) + 0) = (ts4l_word)a0;
        p4 = (ts4l_word)0;
    }
    return p4;
}

/* Loader_DLL.xex 0x833EA0D0: if_call_seq fn_833E8350, lbl_8352C3C8, u32@0x0, u32@0x0, fn_833E9D50 */
ts4l_word ts4l_if_call_seq_fn_833E8350_833EA0D0(ts4l_word a0)
{
    ts4l_word p2;
    ts4l_word p5;
    ts4l_word t1;

    if ((ts4l_word)a0 == 0) {
        fn_833E9D50();
        p5 = (ts4l_word)22;
    } else {
        t1 = fn_833E8350();
        if ((ts4l_word)t1 == 0) {
            p2 = (ts4l_word)(ts4l_word)lbl_8352C3C8;
        } else {
            p2 = (ts4l_word)(t1 + 8);
        }
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(p2) + 0));
        p5 = (ts4l_word)0;
    }
    return p5;
}

/* Loader_DLL.xex 0x833EA138: if_call_seq fn_833E8350, fn_833E8350, lbl_8352C3CC, u32@0x0 */
ts4l_word ts4l_if_call_seq_fn_833E8350_833EA138(ts4l_word a0)
{
    ts4l_word p3;
    ts4l_word p4;
    ts4l_word t1;
    ts4l_word t2;

    t1 = fn_833E8350();
    if ((ts4l_word)t1 == 0) {
        p4 = (ts4l_word)12;
    } else {
        t2 = fn_833E8350((ts4l_word)t1);
        if ((ts4l_word)t2 == 0) {
            p3 = (ts4l_word)(ts4l_word)lbl_8352C3CC;
        } else {
            p3 = (ts4l_word)(t2 + 12);
        }
        *(ts4l_word *)((char *)(ts4l_word)(p3) + 0) = (ts4l_word)a0;
        p4 = (ts4l_word)0;
    }
    return p4;
}

/* Loader_DLL.xex 0x833EA198: if_call_seq fn_833E8350, lbl_8352C3CC, u32@0x0, u32@0x0, fn_833E9D50 */
ts4l_word ts4l_if_call_seq_fn_833E8350_833EA198(ts4l_word a0)
{
    ts4l_word p2;
    ts4l_word p5;
    ts4l_word t1;

    if ((ts4l_word)a0 == 0) {
        fn_833E9D50();
        p5 = (ts4l_word)22;
    } else {
        t1 = fn_833E8350();
        if ((ts4l_word)t1 == 0) {
            p2 = (ts4l_word)(ts4l_word)lbl_8352C3CC;
        } else {
            p2 = (ts4l_word)(t1 + 12);
        }
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(p2) + 0));
        p5 = (ts4l_word)0;
    }
    return p5;
}

/* Loader_DLL.xex 0x833EB380: if_call_seq fn_833F7960 */
ts4l_word ts4l_if_call_seq_fn_833F7960_833EB380(ts4l_word a0)
{
    ts4l_word p2;
    int t1;

    t1 = fn_833F7960((ts4l_word)(a0 & 0xff));
    if ((int)t1 != 0) {
        p2 = (ts4l_word)a0;
    } else {
        p2 = (ts4l_word)((a0 & 0xffffffdf) + -7);
    }
    return p2;
}

/* Loader_DLL.xex 0x833EC738: if_call_seq fn_833F7960 */
ts4l_word ts4l_if_call_seq_fn_833F7960_833EC738(ts4l_word a0)
{
    ts4l_word p2;
    int t1;

    t1 = fn_833F7960((ts4l_word)(a0 & 0xff));
    if ((int)t1 != 0) {
        p2 = (ts4l_word)a0;
    } else {
        p2 = (ts4l_word)((a0 & 0xffffffdf) + -7);
    }
    return p2;
}

/* Loader_DLL.xex 0x833F0600: if_call_seq lbl_8352C3D0, RtlEnterCriticalSection, fn_833F9160, u32@0xc, u32@0xc */
ts4l_word ts4l_if_call_seq_lbl_8352C3D0_833F0600(ts4l_word a0)
{
    ts4l_word p4;
    ts4l_word t2;
    ts4l_word t1;

    if ((ts4l_word)a0 >= (ts4l_word)(ts4l_word)lbl_8352C3D0 && (ts4l_word)a0 <= (ts4l_word)((ts4l_word)lbl_8352C3D0 + 608)) {
        t2 = fn_833F9160((ts4l_word)(((int)(a0 - (ts4l_word)lbl_8352C3D0) >> 5) + 16));
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 12)) | 32768);
        p4 = (ts4l_word)t2;
    } else {
        t1 = RtlEnterCriticalSection((ts4l_word)(a0 + 32));
        p4 = (ts4l_word)t1;
    }
    return p4;
}

/* Loader_DLL.xex 0x833F0670: if_call_seq RtlEnterCriticalSection, fn_833F9160, u32@0xc, u32@0xc */
ts4l_word ts4l_if_call_seq_RtlEnterCriticalSection_833F0670(int a0, ts4l_word a1)
{
    ts4l_word p4;
    ts4l_word t2;
    ts4l_word t1;

    if ((int)a0 < 20) {
        t2 = fn_833F9160((ts4l_word)(a0 + 16));
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 12) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a1) + 12)) | 32768);
        p4 = (ts4l_word)t2;
    } else {
        t1 = RtlEnterCriticalSection((ts4l_word)(a1 + 32));
        p4 = (ts4l_word)t1;
    }
    return p4;
}

/* Loader_DLL.xex 0x833F0F38: if_call_seq fn_833E9F90, u32@0x0, fn_833E9F90, u32@0x0 */
ts4l_word ts4l_if_call_seq_fn_833E9F90_833F0F38(int a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p3;
    ts4l_word p4;
    ts4l_word t2;
    ts4l_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)a0 != 1) {
        p3 = (ts4l_word)a0;
        if ((int)a0 > 1 && (int)a0 <= 3) {
            t2 = fn_833E9F90();
            *(ts4l_word *)((char *)(ts4l_word)(t2) + 0) = (ts4l_word)34;
            p3 = (ts4l_word)t2;
        }
        p4 = (ts4l_word)p3;
    } else {
        t1 = fn_833E9F90();
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 0) = (ts4l_word)33;
        p4 = (ts4l_word)t1;
    }
    return p4;
}

/* Loader_DLL.xex 0x833F0F80: loop_addr lbl_8352C6A0, u32@0x0, u32@0x0 */
ts4l_word ts4l_loop_addr_lbl_8352C6A0_833F0F80(ts4l_word a0)
{
    ts4l_word lv1;
    ts4l_word lv2;
    ts4l_word p6;
    ts4l_word p7;
    ts4l_word t4;

    lv1 = (ts4l_word)(ts4l_word)lbl_8352C6A0;
    lv2 = (ts4l_word)0;
    do {
        t4 = *(ts4l_word *)((char *)(ts4l_word)(lv1) + 0);
        if ((ts4l_word)t4 == (ts4l_word)a0) {
            return (*(ts4l_word *)((char *)(ts4l_word)((lv2 << 3)) + ((ts4l_word)lbl_8352C6A0 + 4)));
        }
        p6 = (ts4l_word)(lv1 + 8);
        p7 = (ts4l_word)(lv2 + 1);
        lv1 = p6;
        lv2 = p7;
    } while ((int)p6 < (int)((ts4l_word)lbl_8352C6A0 + 232));
    return 0;
}

/* Loader_DLL.xex 0x833F0FC8: if_fn  */
ts4l_word ts4l_if_fn_833F0FC8(ts4l_word a0)
{
    if ((int)(a0 & 0x20) != 0) {
        return 5;
    }
    if ((int)(a0 & 0x8) != 0) {
        return 1;
    }
    if ((int)(a0 & 0x4) != 0) {
        return 2;
    }
    if ((int)(a0 & 0x1) != 0) {
        return 3;
    }
    return (((a0 << 1) | (a0 >> 31)) & 0x4);
}

/* Loader_DLL.xex 0x833F2A18: loop_call_seq u32@0x0, u32@0x0, fn_833FB560, fn_833F5188 */
ts4l_word ts4l_loop_call_seq_u32_off0_833F2A18(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t2;
    int t3;

    do {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0)) + 1);
        t2 = fn_833FB560((ts4l_word)a1);
        if ((ts4l_word)(t2 & 0xffff) == 65535) {
            break;
        }
        t3 = fn_833F5188((ts4l_word)t2, (ts4l_word)8);
    } while ((int)t3 != 0);
    return t2;
}

/* Loader_DLL.xex 0x833F3BC0: loop_call_seq u32@0x0, u32@0x0, fn_833FB560, fn_833F5188 */
ts4l_word ts4l_loop_call_seq_u32_off0_833F3BC0(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t2;
    int t3;

    do {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0)) + 1);
        t2 = fn_833FB560((ts4l_word)a1);
        if ((ts4l_word)(t2 & 0xffff) == 65535) {
            break;
        }
        t3 = fn_833F5188((ts4l_word)t2, (ts4l_word)8);
    } while ((int)t3 != 0);
    return t2;
}

/* Loader_DLL.xex 0x833F5468: if_call_seq u32@0xc, u32@0x8, fn_833F9D68, u32@0x0, u32@0x0, u32@0x0 */
ts4l_word ts4l_if_call_seq_u32_offc_833F5468(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p5;
    ts4l_word p7;
    ts4l_word p8;
    ts4l_word t1;
    ts4l_word t3;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 12);
    if ((int)(t1 & 0x40) == 0 || (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 8)) != 0) {
        t3 = fn_833F9D68();
        if ((ts4l_word)(t3 & 0xffff) == 65535) {
            p5 = (ts4l_word)-1;
        } else {
            p5 = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a2) + 0)) + 1);
        }
        p7 = (ts4l_word)p5;
        p8 = (ts4l_word)t3;
    } else {
        p7 = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a2) + 0)) + 1);
        p8 = (ts4l_word)a0;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a2) + 0) = (ts4l_word)p7;
    return p8;
}

/* Loader_DLL.xex 0x833F6200: if_call_seq u32@0xc, u32@0x8, fn_833F9D68, u32@0x0, u32@0x0, u32@0x0 */
ts4l_word ts4l_if_call_seq_u32_offc_833F6200(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p5;
    ts4l_word p7;
    ts4l_word p8;
    ts4l_word t1;
    ts4l_word t3;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 12);
    if ((int)(t1 & 0x40) == 0 || (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 8)) != 0) {
        t3 = fn_833F9D68();
        if ((ts4l_word)(t3 & 0xffff) == 65535) {
            p5 = (ts4l_word)-1;
        } else {
            p5 = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a2) + 0)) + 1);
        }
        p7 = (ts4l_word)p5;
        p8 = (ts4l_word)t3;
    } else {
        p7 = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a2) + 0)) + 1);
        p8 = (ts4l_word)a0;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a2) + 0) = (ts4l_word)p7;
    return p8;
}

/* Loader_DLL.xex 0x833F7620: if_call_seq u32@0xc, fn_833F8280, u32@0x18, u32@0x0, u32@0x8, u32@0xc */
ts4l_word ts4l_if_call_seq_u32_offc_833F7620(int a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p5;
    ts4l_word p6;
    ts4l_word t1;
    ts4l_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4l_word)a0;
    if ((int)a0 != 0) {
        t1 = *(volatile ts4l_word *)((char *)(ts4l_word)(a1) + 12);
        p5 = (ts4l_word)a0;
        if ((int)(t1 & 0x1000) != 0) {
            t2 = fn_833F8280((ts4l_word)a1);
            *(volatile ts4l_word *)((char *)(ts4l_word)(a1) + 24) = (ts4l_word)0;
            *(volatile ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)0;
            *(volatile ts4l_word *)((char *)(ts4l_word)(a1) + 8) = (ts4l_word)0;
            *(volatile ts4l_word *)((char *)(ts4l_word)(a1) + 12) = (ts4l_word)(((*(volatile ts4l_word *)((char *)(ts4l_word)(a1) + 12)) & 0xfffffeff) & 0xffffefff);
            p5 = (ts4l_word)t2;
        }
        p6 = (ts4l_word)p5;
    }
    return p6;
}

/* Loader_DLL.xex 0x833F7C08: if_call_seq lbl_8352CA04, u32@lbl_8352CA04, u32@0xac, u32@0xc8, fn_833FAED8 */
ts4l_word ts4l_if_call_seq_lbl_8352CA04_833F7C08(int a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word p6;
    ts4l_word p7;
    ts4l_word t1;
    int t2;
    ts4l_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4l_word *)lbl_8352CA04;
    t2 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 172);
    if ((int)t2 > 1) {
        t5 = fn_833FAED8((ts4l_word)a0, (ts4l_word)259, (ts4l_word)(ts4l_word)lbl_8352CA04);
        p6 = (ts4l_word)t5;
    } else {
        p6 = (ts4l_word)((*(unsigned short *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 200))) + (a0 << 1))) & 259);
    }
    p7 = (ts4l_word)p6;
    if ((int)p6 != 0 || (int)a0 == 95) {
        p7 = (ts4l_word)1;
    }
    return p7;
}

/* Loader_DLL.xex 0x833F7CB0: if_call_seq lbl_8352CA04, u32@lbl_8352CA04, u32@0xac, u32@0xc8, fn_833FAED8 */
ts4l_word ts4l_if_call_seq_lbl_8352CA04_833F7CB0(int a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word p6;
    ts4l_word p7;
    ts4l_word t1;
    int t2;
    ts4l_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4l_word *)lbl_8352CA04;
    t2 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 172);
    if ((int)t2 > 1) {
        t5 = fn_833FAED8((ts4l_word)a0, (ts4l_word)263, (ts4l_word)(ts4l_word)lbl_8352CA04);
        p6 = (ts4l_word)t5;
    } else {
        p6 = (ts4l_word)((*(unsigned short *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 200))) + (a0 << 1))) & 263);
    }
    p7 = (ts4l_word)p6;
    if ((int)p6 != 0 || (int)a0 == 95) {
        p7 = (ts4l_word)1;
    }
    return p7;
}

/* Loader_DLL.xex 0x833F8E58: loop_call_seq lbl_8352CA10, u32@0x0, u32@0x4, fn_833E74C0, u32@0x0 */
ts4l_word ts4l_loop_call_seq_lbl_8352CA10_833F8E58(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word lv1;
    ts4l_word p5;
    ts4l_word p6;
    ts4l_word t2;
    ts4l_word t4;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    lv1 = (ts4l_word)(ts4l_word)lbl_8352CA10;
    do {
        t2 = *(ts4l_word *)((char *)(ts4l_word)(lv1) + 0);
        p5 = (ts4l_word)t2;
        if ((ts4l_word)t2 != 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(lv1) + 4)) != 1) {
            t4 = fn_833E74C0((ts4l_word)t2);
            *(ts4l_word *)((char *)(ts4l_word)(lv1) + 0) = (ts4l_word)0;
            p5 = (ts4l_word)t4;
        }
        p6 = (ts4l_word)(lv1 + 8);
        lv1 = p6;
    } while ((int)p6 < (int)((ts4l_word)lbl_8352CA10 + 288));
    return p5;
}

/* Loader_DLL.xex 0x833FA2B8: if_call_seq fn_833F5188 */
ts4l_word ts4l_if_call_seq_fn_833F5188_833FA2B8(ts4l_word a0)
{
    ts4l_word p2;
    int t1;

    t1 = fn_833F5188((ts4l_word)a0, (ts4l_word)263);
    p2 = (ts4l_word)t1;
    if ((int)t1 != 0 || (ts4l_word)(a0 & 0xffff) == 95) {
        p2 = (ts4l_word)1;
    }
    return p2;
}

/* Loader_DLL.xex 0x833FA300: if_call_seq fn_833F5188 */
ts4l_word ts4l_if_call_seq_fn_833F5188_833FA300(ts4l_word a0)
{
    ts4l_word p2;
    int t1;

    t1 = fn_833F5188((ts4l_word)a0, (ts4l_word)263);
    p2 = (ts4l_word)t1;
    if ((int)t1 != 0 || (ts4l_word)(a0 & 0xffff) == 95) {
        p2 = (ts4l_word)1;
    }
    return p2;
}

/* Loader_DLL.xex 0x833FA348: if_call_seq fn_833F5188 */
ts4l_word ts4l_if_call_seq_fn_833F5188_833FA348(ts4l_word a0)
{
    ts4l_word p2;
    int t1;

    t1 = fn_833F5188((ts4l_word)a0, (ts4l_word)259);
    p2 = (ts4l_word)t1;
    if ((int)t1 != 0 || (ts4l_word)(a0 & 0xffff) == 95) {
        p2 = (ts4l_word)1;
    }
    return p2;
}

/* Loader_DLL.xex 0x833FA390: if_call_seq fn_833F5188 */
ts4l_word ts4l_if_call_seq_fn_833F5188_833FA390(ts4l_word a0)
{
    ts4l_word p2;
    int t1;

    t1 = fn_833F5188((ts4l_word)a0, (ts4l_word)259);
    p2 = (ts4l_word)t1;
    if ((int)t1 != 0 || (ts4l_word)(a0 & 0xffff) == 95) {
        p2 = (ts4l_word)1;
    }
    return p2;
}

/* Loader_DLL.xex 0x833FA3D8: if_get u8@0x0, u8@0x0, u16@0x0, u16@0x0 */
ts4l_word ts4l_if_get_u8_off0_833FA3D8(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    unsigned char t2;

    if ((ts4l_word)a1 != 0 && (ts4l_word)a2 != 0) {
        t2 = *(unsigned char *)((char *)(ts4l_word)(a1) + 0);
        if ((ts4l_word)t2 == 0) {
            if ((ts4l_word)a0 != 0) {
                *(unsigned short *)((char *)(ts4l_word)(a0) + 0) = (unsigned short)0;
            }
            return 0;
        }
        if ((ts4l_word)a0 != 0) {
            *(unsigned short *)((char *)(ts4l_word)(a0) + 0) = (unsigned short)(t2 & 0xff);
        }
        return 1;
    }
    return 0;
}

/* Loader_DLL.xex 0x833FA420: if_get u8@0x0, u8@0x0, u16@0x0, u16@0x0 */
ts4l_word ts4l_if_get_u8_off0_833FA420(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    unsigned char t2;

    if ((ts4l_word)a1 != 0 && (ts4l_word)a2 != 0) {
        t2 = *(unsigned char *)((char *)(ts4l_word)(a1) + 0);
        if ((ts4l_word)t2 == 0) {
            if ((ts4l_word)a0 != 0) {
                *(unsigned short *)((char *)(ts4l_word)(a0) + 0) = (unsigned short)0;
            }
            return 0;
        }
        if ((ts4l_word)a0 != 0) {
            *(unsigned short *)((char *)(ts4l_word)(a0) + 0) = (unsigned short)(t2 & 0xff);
        }
        return 1;
    }
    return 0;
}

/* Loader_DLL.xex 0x833FEC48: if_call_seq fn_833FE300, fn_833FDA98 */
ts4l_word ts4l_if_call_seq_fn_833FE300_833FEC48(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    ts4l_word p3;
    ts4l_word loc50[6];
    ts4l_word t1;
    int t2;

    t1 = fn_833FE300((ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a3, (ts4l_word)0, (ts4l_word)0, (ts4l_word)0, (ts4l_word)a4);
    t2 = fn_833FDA98((ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)a0);
    p3 = (ts4l_word)t1;
    if ((int)t2 == 1) {
        p3 = (ts4l_word)(t1 | 2);
    }
    return p3;
}

/* Loader_DLL.xex 0x83400AD8: if_addr lbl_835446F4, u32@lbl_83544724, lbl_83071C74, u32@lbl_83544724, u32@0x0, u32@0x4 */
ts4l_word ts4l_if_addr_lbl_835446F4_83400AD8(int a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    ts4l_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    t1 = *(ts4l_word *)lbl_83544724;
    if ((int)(t1 & 0x1) == 0) {
        *(ts4l_word *)lbl_83544724 = (ts4l_word)(t1 | 1);
        *(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_835446F4) + 0) = (ts4l_word)(ts4l_word)lbl_83071C74;
        *(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_835446F4) + 4) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_835446F4) + 12) = (ts4l_word)(ts4l_word)lbl_83071C74;
        *(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_835446F4) + 8) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_835446F4) + 24) = (ts4l_word)(ts4l_word)lbl_83071C74;
        *(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_835446F4) + 36) = (ts4l_word)(ts4l_word)lbl_83071C74;
        *(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_835446F4) + 16) = (ts4l_word)1;
        *(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_835446F4) + 20) = (ts4l_word)4;
        *(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_835446F4) + 28) = (ts4l_word)2;
        *(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_835446F4) + 32) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_835446F4) + 40) = (ts4l_word)3;
        *(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_835446F4) + 44) = (ts4l_word)0;
    }
    if ((int)a0 >= 0 && (int)a0 < 4) {
        return (((int)a0 * 12) + (ts4l_word)lbl_835446F4);
    }
    return ((ts4l_word)lbl_835446F4 + 36);
}

/* Loader_DLL.xex 0x83400C00: if_get u32@0x8, u32@0x0, u32@0x4, vcall, u32@0x4, u32@0x0 */
ts4l_word ts4l_if_get_u32_off8_83400C00(ts4l_word a0)
{
    ts4l_word p9;
    ts4l_word t1;
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t8;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 8);
    t4 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 4))))((ts4l_word)t1);
    p9 = (ts4l_word)t4;
    if ((int)((signed char)t4) == 0) {
        t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
        t8 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t5) + 0))) + 4))))((ts4l_word)t5);
        p9 = (ts4l_word)t8;
    }
    return p9;
}

/* Loader_DLL.xex 0x83401360: if_get u32@0x0, u8@0x4, u32@0x0, u8@0x5, u32@0x0, u8@0x4 */
void ts4l_if_get_u32_off0_83401360(ts4l_word a0, ts4l_word a1, int a2)
{
    int t2;
    ts4l_word t3;
    ts4l_word t4;
    ts4l_word t5;

    if ((int)a2 >= 0 && (int)a2 <= 9) {
        t2 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 0);
        if ((int)t2 != -1 && (int)a2 <= (int)t2) {
            t3 = *(ts4l_word *)((char *)(ts4l_word)(((a2 + 1) << 2)) + a1);
            t4 = *(ts4l_word *)((char *)(ts4l_word)(t3) + 0);
            t5 = *(ts4l_word *)((char *)(ts4l_word)(t3) + 4);
            *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)t4;
            *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)t5;
            return;
        }
        *(volatile unsigned char *)((char *)(ts4l_word)(a0) + 4) = (unsigned char)2;
        *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
        *(volatile unsigned char *)((char *)(ts4l_word)(a0) + 5) = (unsigned char)0;
        return;
    }
    *(volatile unsigned char *)((char *)(ts4l_word)(a0) + 4) = (unsigned char)3;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    *(volatile unsigned char *)((char *)(ts4l_word)(a0) + 5) = (unsigned char)0;
    return;
}

/* Loader_DLL.xex 0x83401A70: call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x4, fn_834015C0 */
ts4l_word ts4l_call_seq_u32_off0_83401A70(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 0));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 4));
    fn_834015C0((ts4l_word)a0, (ts4l_word)a2);
    return a0;
}

/* Loader_DLL.xex 0x83401AB8: if_call_seq u32@0x4, u32@0x0, u32@0x0, u32@0x0, u32@0x0, fn_83401118 */
ts4l_word ts4l_if_call_seq_u32_off4_83401AB8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5)
{
    ts4l_word t1;
    ts4l_word t3;
    ts4l_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 4);
    if ((int)(t1 & 0xff000000) <= (int)(16777216)) {
        t3 = *(volatile ts4l_word *)((char *)(ts4l_word)(a1) + 0);
        if ((ts4l_word)t3 == 0) {
            fn_834015C0((ts4l_word)a0, (ts4l_word)((signed char)(*(volatile unsigned char *)((char *)(ts4l_word)(a1) + 4))));
        } else {
            t5 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 0);
            if ((ts4l_word)t5 == 0) {
                *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(*(volatile ts4l_word *)((char *)(ts4l_word)(a1) + 0));
                *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(*(volatile ts4l_word *)((char *)(ts4l_word)(a1) + 4));
            } else {
                fn_83401118((ts4l_word)a0, (ts4l_word)t3);
            }
        }
    }
    return a0;
}

/* Loader_DLL.xex 0x83401F98: call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x4, fn_83401B40 */
ts4l_word ts4l_call_seq_u32_off0_83401F98(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 0));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 4));
    fn_83401B40((ts4l_word)a0, (ts4l_word)a2);
    return a0;
}

/* Loader_DLL.xex 0x83402450: call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x4, fn_83401FE0 */
ts4l_word ts4l_call_seq_u32_off0_83402450(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 0));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 4));
    fn_83401FE0((ts4l_word)a0, (ts4l_word)a2);
    return a0;
}

/* Loader_DLL.xex 0x83402498: call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x4, fn_83402088 */
ts4l_word ts4l_call_seq_u32_off0_83402498(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 0));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 4));
    fn_83402088((ts4l_word)a0, (ts4l_word)a2);
    return a0;
}

/* Loader_DLL.xex 0x83402E30: call_seq fn_834024E0, fn_83402330, u32@0x0, u32@0x0, u32@0x4, u32@0x4 */
ts4l_word ts4l_call_seq_fn_834024E0_83402E30(ts4l_word a0)
{
    ts4l_word loc50[2];
    ts4l_word loc58[2];
    ts4l_word t1;
    ts4l_word t2;

    t1 = fn_834024E0((ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)0);
    t2 = fn_83402330((ts4l_word)(ts4l_word)&loc58[0], (ts4l_word)96, (ts4l_word)t1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t2) + 0));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t2) + 4));
    fn_83401FE0((ts4l_word)a0, (ts4l_word)39);
    return a0;
}

/* Loader_DLL.xex 0x83403230: if_call_seq u32@lbl_835446D8, u8@0x0, fn_834024E0, u32@lbl_835446D8, fn_834024E0, fn_83402330 */
ts4l_word ts4l_if_call_seq_u32_lbl_835446D8_83403230(ts4l_word a0)
{
    ts4l_word loc50[4];
    ts4l_word t1;
    unsigned char t2;
    ts4l_word t4;

    t1 = *(ts4l_word *)lbl_835446D8;
    t2 = *(unsigned char *)((char *)(ts4l_word)(t1) + 0);
    if ((int)((signed char)t2) == 0) {
        fn_83400FE8((ts4l_word)a0, (ts4l_word)1);
    } else {
        if ((int)((signed char)t2) == 63) {
            *(ts4l_word *)lbl_835446D8 = (ts4l_word)(t1 + 1);
            t4 = fn_834024E0((ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)0);
            fn_83402330((ts4l_word)a0, (ts4l_word)45, (ts4l_word)t4);
        } else {
            fn_834024E0((ts4l_word)a0, (ts4l_word)0);
        }
    }
    return a0;
}

/* Loader_DLL.xex 0x83408978: if_call_seq fn_83408018, fn_833FDA98 */
ts4l_word ts4l_if_call_seq_fn_83408018_83408978(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    ts4l_word p3;
    ts4l_word loc50[6];
    ts4l_word t1;
    int t2;

    t1 = fn_83408018((ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a3, (ts4l_word)0, (ts4l_word)0, (ts4l_word)0, (ts4l_word)a4);
    t2 = fn_833FDA98((ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)a0);
    p3 = (ts4l_word)t1;
    if ((int)t2 == 1) {
        p3 = (ts4l_word)(t1 | 2);
    }
    return p3;
}

/* Loader_DLL.xex 0x8340A130: if_addr lbl_83544728, interlocked_xchg, fn_833E9F90, u32@0x0, fn_833E9D50 */
ts4l_word ts4l_if_addr_lbl_83544728_8340A130(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word p4;
    ts4l_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    if ((int)a0 != 16384 && (ts4l_word)a0 != 32768) {
        t2 = fn_833E9F90();
        *(ts4l_word *)((char *)(ts4l_word)(t2) + 0) = (ts4l_word)22;
        fn_833E9D50((ts4l_word)t2);
        p4 = (ts4l_word)22;
    } else {
        _InterlockedExchange((volatile long *)(ts4l_word)((ts4l_word)lbl_83544728), (long)a0);
        p4 = (ts4l_word)0;
    }
    return p4;
}

/* Loader_DLL.xex 0x8340A360: if_get u32@lbl_8352D220, u32@0x4, vcall, fn_8340F088 */
ts4l_word ts4l_if_get_u32_lbl_8352D220_8340A360(ts4l_word a0)
{
    ts4l_word p5;
    int t3;

    t3 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)lbl_8352D220)) + 4))))((ts4l_word)a0);
    if ((int)t3 >= 0) {
        p5 = (ts4l_word)1;
    } else {
        fn_8340F088((ts4l_word)t3);
        p5 = (ts4l_word)0;
    }
    return p5;
}

/* Loader_DLL.xex 0x8340A788: if_get u32@0x8, fn_834141C0, u32@0xc, u32@lbl_8352D220, u32@0x10, vcall */
ts4l_word ts4l_if_get_u32_off8_8340A788(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    ts4l_word p7;
    ts4l_word loc50[4];
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t5;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a3) + 8);
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a3) + 12);
    loc50[1] = (ts4l_word)t1;
    loc50[0] = (ts4l_word)t2;
    t5 = ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)lbl_8352D220)) + 16))))((ts4l_word)a0, (ts4l_word)0, (ts4l_word)((ts4l_word)fn_834141C0 | 1), (ts4l_word)a4, (ts4l_word)a3, (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)(ts4l_word)&loc50[0]);
    if ((ts4l_word)(t5 & 0xc0000000) == (ts4l_word)(3221225472)) {
        fn_834141B8((ts4l_word)t5);
        p7 = (ts4l_word)0;
    } else {
        p7 = (ts4l_word)1;
    }
    return p7;
}

/* Loader_DLL.xex 0x8340AFC8: if_call_seq XexLoadImage, fn_834141B8 */
ts4l_word ts4l_if_call_seq_XexLoadImage_8340AFC8(ts4l_word a0)
{
    ts4l_word p4;
    ts4l_word loc50[2];
    int t1;
    ts4l_word t2;

    t1 = XexLoadImage((ts4l_word)a0, (ts4l_word)9, (ts4l_word)0, (ts4l_word)(ts4l_word)&loc50[0]);
    if ((int)t1 < 0) {
        fn_834141B8((ts4l_word)t1);
        p4 = (ts4l_word)0;
    } else {
        t2 = loc50[0];
        p4 = (ts4l_word)t2;
    }
    return p4;
}

/* Loader_DLL.xex 0x8340B010: if_call_seq XexLoadImage, fn_834141B8 */
ts4l_word ts4l_if_call_seq_XexLoadImage_8340B010(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p4;
    ts4l_word loc50[2];
    int t1;
    ts4l_word t2;

    t1 = XexLoadImage((ts4l_word)a0, (ts4l_word)9, (ts4l_word)a1, (ts4l_word)(ts4l_word)&loc50[0]);
    if ((int)t1 < 0) {
        fn_834141B8((ts4l_word)t1);
        p4 = (ts4l_word)0;
    } else {
        t2 = loc50[0];
        p4 = (ts4l_word)t2;
    }
    return p4;
}

/* Loader_DLL.xex 0x8340B0F0: if_call_seq u32@0x0, u32@__imp_XboxKrnlVersion, u16@0x0, u16@0x2, u16@0x4, XamInputGetCapabilities */
ts4l_word ts4l_if_call_seq_u32_off0_8340B0F0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word loc50[4];
    ts4l_word loc60[6];
    ts4l_word t1;
    ts4l_word t2;
    unsigned short t3;
    ts4l_word t6;
    unsigned short t8;
    unsigned short t9;
    unsigned short t10;
    ts4l_word t16;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 0);
    t2 = *(ts4l_word *)__imp_XboxKrnlVersion;
    loc50[0] = (ts4l_word)t1;
    t3 = *(unsigned short *)((char *)(ts4l_word)(t2) + 0);
    if (((ts4l_word)t3 == 2 && (ts4l_word)(*(unsigned short *)((char *)(ts4l_word)(t2) + 2)) == 0) && (ts4l_word)(*(unsigned short *)((char *)(ts4l_word)(t2) + 4)) < 5611) {
        t6 = XamInputGetCapabilities((ts4l_word)a0, (ts4l_word)1, (ts4l_word)(ts4l_word)&loc60[0]);
        if ((ts4l_word)t6 == 0 && (ts4l_word)(*(unsigned char *)((char *)loc60 + 1)) == 2) {
            t8 = *(unsigned short *)((char *)loc60 + 2);
            if ((int)(t8 & 0x1) != 0) {
                if ((int)(t8 & 0x2) != 0) {
                    t9 = *(unsigned short *)((char *)(ts4l_word)(a1) + 2);
                    t10 = *(unsigned short *)((char *)(ts4l_word)(a1) + 0);
                    *(unsigned short *)((char *)loc50 + 0) = (unsigned short)t9;
                    *(unsigned short *)((char *)loc50 + 2) = (unsigned short)t10;
                }
            }
        }
    }
    t16 = XamInputSetState((ts4l_word)a0, (ts4l_word)0, (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)0, (ts4l_word)0, (ts4l_word)0);
    return t16;
}

/* Loader_DLL.xex 0x8340B6F8: if_call_seq fn_834144F0, XamUserCreateStatsEnumerator */
ts4l_word ts4l_if_call_seq_fn_834144F0_8340B6F8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word p3;
    ts4l_word t1;
    ts4l_word t2;

    t1 = fn_834144F0((ts4l_word)a0);
    p3 = (ts4l_word)t1;
    if ((ts4l_word)t1 == 0) {
        t2 = XamUserCreateStatsEnumerator((ts4l_word)a0, (ts4l_word)0, (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a3, (ts4l_word)a4, (ts4l_word)a5, (ts4l_word)a6);
        p3 = (ts4l_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x8340B758: if_call_seq fn_834144F0, XamUserCreateStatsEnumerator */
ts4l_word ts4l_if_call_seq_fn_834144F0_8340B758(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word p3;
    ts4l_word t1;
    ts4l_word t2;

    t1 = fn_834144F0((ts4l_word)a0);
    p3 = (ts4l_word)t1;
    if ((ts4l_word)t1 == 0) {
        t2 = XamUserCreateStatsEnumerator((ts4l_word)a0, (ts4l_word)3, (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a3, (ts4l_word)a4, (ts4l_word)a5, (ts4l_word)a6);
        p3 = (ts4l_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x8340B7B8: if_call_seq fn_834144F0, XamReadTileToTexture */
ts4l_word ts4l_if_call_seq_fn_834144F0_8340B7B8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p3;
    ts4l_word t1;
    ts4l_word t2;

    t1 = fn_834144F0((ts4l_word)a1);
    p3 = (ts4l_word)t1;
    if ((ts4l_word)t1 == 0) {
        t2 = XamReadTileToTexture((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a3, (ts4l_word)a4, (ts4l_word)a5, (ts4l_word)a6, (ts4l_word)a7);
        p3 = (ts4l_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x8340C978: if_call_seq u32@__imp_ExThreadObjectType, ObReferenceObjectByHandle, fn_834141B8, KeSetDisableBoostThread, ObDereferenceObject */
ts4l_word ts4l_if_call_seq_u32__imp_ExThreadObjectType_8340C978(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p8;
    ts4l_word loc50[4];
    int t2;
    ts4l_word t4;
    ts4l_word t6;

    t2 = ObReferenceObjectByHandle((ts4l_word)a0, (ts4l_word)(*(ts4l_word *)__imp_ExThreadObjectType), (ts4l_word)(ts4l_word)&loc50[0]);
    if ((int)t2 >= 0) {
        t4 = loc50[0];
        KeSetDisableBoostThread((ts4l_word)t4, (ts4l_word)(a1 != 0));
        t6 = loc50[0];
        ObDereferenceObject((ts4l_word)t6);
        p8 = (ts4l_word)1;
    } else {
        fn_834141B8((ts4l_word)t2);
        p8 = (ts4l_word)0;
    }
    return p8;
}

/* Loader_DLL.xex 0x8340C9E0: if_call_seq u32@__imp_ExThreadObjectType, ObReferenceObjectByHandle, fn_834141B8, u8@0xbb, u32@0x0, ObDereferenceObject */
ts4l_word ts4l_if_call_seq_u32__imp_ExThreadObjectType_8340C9E0(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p7;
    ts4l_word loc50[4];
    int t2;
    ts4l_word t4;

    t2 = ObReferenceObjectByHandle((ts4l_word)a0, (ts4l_word)(*(ts4l_word *)__imp_ExThreadObjectType), (ts4l_word)(ts4l_word)&loc50[0]);
    if ((int)t2 >= 0) {
        t4 = loc50[0];
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)((*(unsigned char *)((char *)(ts4l_word)(t4) + 187)) != 0);
        ObDereferenceObject((ts4l_word)t4);
        p7 = (ts4l_word)1;
    } else {
        fn_834141B8((ts4l_word)t2);
        p7 = (ts4l_word)0;
    }
    return p7;
}

/* Loader_DLL.xex 0x8340D018: if_call_seq u32@lbl_8354472C, MmAllocatePhysicalMemoryEx, fn_8340F068 */
ts4l_word ts4l_if_call_seq_u32_lbl_8354472C_8340D018(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    ts4l_word p2;
    int t1;
    ts4l_word t3;

    t1 = *(volatile ts4l_word *)lbl_8354472C;
    p2 = (ts4l_word)a4;
    if ((int)t1 != 0) {
        p2 = (ts4l_word)(a4 & 0xdfffffff);
    }
    t3 = MmAllocatePhysicalMemoryEx((ts4l_word)0, (ts4l_word)a0, (ts4l_word)p2, (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a3);
    if ((int)t3 == 0) {
        fn_8340F068((ts4l_word)8);
    }
    return t3;
}

/* Loader_DLL.xex 0x8340D120: if_call_seq u32@0x0, u32@0x4, u32@0x0, u32@0x0, fn_8340F088, u32@0x10 */
ts4l_word ts4l_if_call_seq_u32_off0_8340D120(ts4l_word a0, ts4l_word a1, ts4l_word a2, int a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p5;
    ts4l_word p8;
    ts4l_word p10;
    ts4l_word p14;
    ts4l_word p15;
    ts4l_word p17;
    ts4l_word p18;
    ts4l_word t1;
    ts4l_word t7;
    ts4l_word t9;
    int t12;
    int t3;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 0);
    if ((ts4l_word)t1 == 259) {
        if ((int)a3 != 0) {
            t7 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 16);
            p8 = (ts4l_word)a0;
            if ((ts4l_word)t7 != 0) {
                p8 = (ts4l_word)t7;
            }
            t9 = fn_8340CE50((ts4l_word)p8, (ts4l_word)-1);
            p10 = (ts4l_word)t9;
        } else {
            p10 = (ts4l_word)258;
        }
        if ((ts4l_word)p10 == 258) {
            fn_8340F068((ts4l_word)996);
            p17 = (ts4l_word)0;
        } else {
            if ((ts4l_word)p10 == 0) {
                *(ts4l_word *)((char *)(ts4l_word)(a2) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 4));
                t12 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 0);
                if ((int)t12 >= 0) {
                    p14 = (ts4l_word)1;
                } else {
                    fn_8340F088((ts4l_word)t12);
                    p14 = (ts4l_word)0;
                }
                p15 = (ts4l_word)p14;
            } else {
                p15 = (ts4l_word)0;
            }
            p17 = (ts4l_word)p15;
        }
        p18 = (ts4l_word)p17;
    } else {
        *(ts4l_word *)((char *)(ts4l_word)(a2) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 4));
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 0);
        if ((int)t3 >= 0) {
            p5 = (ts4l_word)1;
        } else {
            fn_8340F088((ts4l_word)t3);
            p5 = (ts4l_word)0;
        }
        p18 = (ts4l_word)p5;
    }
    return p18;
}

/* Loader_DLL.xex 0x8340D4D0: loop_call_seq fn_83415BF0, NtSignalAndWaitForSingleObjectEx, fn_834141B8 */
ts4l_word ts4l_loop_call_seq_fn_83415BF0_8340D4D0(ts4l_word a0, ts4l_word a1, ts4l_word a2, int a3)
{
    ts4l_word loc50[4];
    ts4l_word t1;
    int t2;

    t1 = fn_83415BF0((ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)a2);
    do {
        t2 = NtSignalAndWaitForSingleObjectEx((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)1, (ts4l_word)(a3 & 0xff), (ts4l_word)t1);
        if ((int)t2 < 0) {
            fn_834141B8((ts4l_word)t2);
            return -1;
        }
        if ((int)a3 == 0) {
            return t2;
        }
    } while ((int)t2 == 257);
    return t2;
}

/* Loader_DLL.xex 0x8340FAB8: if_call_seq u32@0x14, u32@0x20, NtFreeVirtualMemory */
ts4l_word ts4l_if_call_seq_u32_off14_8340FAB8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p4;
    ts4l_word loc50[1];
    ts4l_word loc54[1];
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 20);
    if ((int)(t1 & 0x1) == 0) {
        t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 32);
        loc50[0] = (ts4l_word)0;
        loc54[0] = (ts4l_word)t2;
        t3 = NtFreeVirtualMemory((ts4l_word)(ts4l_word)&loc54[0], (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)((0) | 32768), (ts4l_word)a1);
        p4 = (ts4l_word)t3;
    } else {
        p4 = (ts4l_word)0;
    }
    return p4;
}

/* Loader_DLL.xex 0x83410090: if_call_seq u8@0x5, u16@0x0, u8@0x6, u16@0x0, u32@-0x8, lbl_8354BAB0 */
ts4l_word ts4l_if_call_seq_u8_off5_83410090(ts4l_word a0)
{
    ts4l_word p7;
    unsigned char t1;
    unsigned short t4;
    unsigned short t2;
    ts4l_word t8;

    t1 = *(unsigned char *)((char *)(ts4l_word)(a0) + 5);
    if ((int)(t1 & 0x8) != 0) {
        t4 = *(unsigned short *)((char *)(ts4l_word)(a0) + 0);
        p7 = (ts4l_word)(((*(ts4l_word *)((char *)(ts4l_word)(a0) + -8)) - t4) + -48);
    } else {
        t2 = *(unsigned short *)((char *)(ts4l_word)(a0) + 0);
        p7 = (ts4l_word)(((t2 << 4) | (t2 >> 28)) - (*(unsigned char *)((char *)(ts4l_word)(a0) + 6)));
    }
    t8 = RtlCompareMemory((ts4l_word)((p7 + a0) + 16), (ts4l_word)(ts4l_word)lbl_8354BAB0, (ts4l_word)16);
    return ((t8 + -16) == 0);
}

/* Loader_DLL.xex 0x83413818: loop_call_seq fn_83415BF0, NtWaitForSingleObjectEx, fn_8340F088 */
ts4l_word ts4l_loop_call_seq_fn_83415BF0_83413818(ts4l_word a0, ts4l_word a1, int a2)
{
    ts4l_word loc50[2];
    ts4l_word t1;
    int t2;

    t1 = fn_83415BF0((ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)a1);
    do {
        t2 = NtWaitForSingleObjectEx((ts4l_word)a0, (ts4l_word)1, (ts4l_word)(a2 & 0xff), (ts4l_word)t1);
        if ((int)t2 < 0) {
            fn_8340F088((ts4l_word)t2);
            return -1;
        }
        if ((int)a2 == 0) {
            return t2;
        }
    } while ((int)t2 == 257);
    return t2;
}

/* Loader_DLL.xex 0x83413B90: loop_get u32@0x0, u32@0x0, vcall */
ts4l_word ts4l_loop_get_u32_off0_83413B90(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word lv1;
    ts4l_word lv2;
    ts4l_word p6;
    ts4l_word p7;
    ts4l_word p8;
    ts4l_word t4;
    ts4l_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    lv1 = (ts4l_word)0;
    lv2 = (ts4l_word)a0;
    while ((ts4l_word)lv2 < (ts4l_word)a1 && (int)lv1 == 0) {
        t4 = *(ts4l_word *)((char *)(ts4l_word)(lv2) + 0);
        p6 = (ts4l_word)lv1;
        if ((ts4l_word)t4 != 0) {
            t5 = ((ts4l_word (*)(ts4l_word))(t4))((ts4l_word)lv1);
            p6 = (ts4l_word)t5;
        }
        p7 = (ts4l_word)p6;
        p8 = (ts4l_word)(lv2 + 4);
        lv1 = p7;
        lv2 = p8;
    }
    return lv1;
}

/* Loader_DLL.xex 0x83413EB0: if_get fn_83413DB0, u32@__imp_KeDebugMonitorData, u32@0x0, u32@__imp_KeDebugMonitorData, u32@0x0, u32@0x18 */
ts4l_word ts4l_if_get_fn_83413DB0_83413EB0(void)
{
    ts4l_word p10;
    int t1;
    ts4l_word t5;
    ts4l_word t9;

    t1 = fn_83413DB0();
    p10 = (ts4l_word)t1;
    if ((int)t1 == 0) {
        t5 = *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)__imp_KeDebugMonitorData)) + 0);
        if ((ts4l_word)t5 != 0) {
            ((ts4l_word (*)(ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(t5) + 24))))((ts4l_word)2, (ts4l_word)0);
        }
        t9 = HalReturnToFirmware((ts4l_word)1);
        p10 = (ts4l_word)t9;
    }
    return p10;
}

/* Loader_DLL.xex 0x83413F90: if_call_seq lbl_8352D1CC, RtlEnterCriticalSection, u32@0x0, u32@0x4, u32@0x0, u32@0x4 */
ts4l_word ts4l_if_call_seq_lbl_8352D1CC_83413F90(ts4l_word a0, int a1)
{
    ts4l_word t4;
    ts4l_word t2;
    ts4l_word t3;
    ts4l_word t7;

    RtlEnterCriticalSection((ts4l_word)(ts4l_word)lbl_8352D1CC);
    if ((int)a1 != 0) {
        t4 = *(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_8352D1E8) + 4);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8352D1E8;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)t4;
        *(ts4l_word *)((char *)(ts4l_word)(t4) + 0) = (ts4l_word)a0;
        *(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_8352D1E8) + 4) = (ts4l_word)a0;
    } else {
        t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
        *(ts4l_word *)((char *)(ts4l_word)(t3) + 0) = (ts4l_word)t2;
        *(ts4l_word *)((char *)(ts4l_word)(t2) + 4) = (ts4l_word)t3;
    }
    t7 = RtlLeaveCriticalSection((ts4l_word)(ts4l_word)lbl_8352D1CC);
    return t7;
}

/* Loader_DLL.xex 0x83414228: if_call_seq fn_834141C0, u32@0x8, u32@0xc, NtWriteFile, fn_834141B8 */
ts4l_word ts4l_if_call_seq_fn_834141C0_83414228(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    ts4l_word p5;
    ts4l_word loc50[4];
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t3;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a3) + 8);
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a3) + 12);
    loc50[1] = (ts4l_word)t1;
    loc50[0] = (ts4l_word)t2;
    t3 = NtWriteFile((ts4l_word)a0, (ts4l_word)0, (ts4l_word)((ts4l_word)fn_834141C0 | 1), (ts4l_word)a4, (ts4l_word)a3, (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)(ts4l_word)&loc50[0]);
    if ((ts4l_word)(t3 & 0xc0000000) == (ts4l_word)(3221225472)) {
        fn_834141B8((ts4l_word)t3);
        p5 = (ts4l_word)0;
    } else {
        p5 = (ts4l_word)1;
    }
    return p5;
}

/* Loader_DLL.xex 0x834159B8: if_get u32@lbl_8352D220, u32@0x18, vcall */
ts4l_word ts4l_if_get_u32_lbl_8352D220_834159B8(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word p5;
    ts4l_word loc60[2];
    int t3;
    ts4l_word t4;

    t3 = ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)lbl_8352D220)) + 24))))((ts4l_word)a0, (ts4l_word)0, (ts4l_word)0, (ts4l_word)0, (ts4l_word)(ts4l_word)&loc60[0], (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)0, (ts4l_word)0);
    p5 = (ts4l_word)t3;
    if ((int)t3 >= 0) {
        t4 = loc60[0];
        p5 = (ts4l_word)t4;
    }
    return p5;
}

/* Loader_DLL.xex 0x83415AB0: if_call_seq u16@0x24, u32@0x28, u16@0x2, u32@0x4, RtlUnicodeToMultiByteN, u16@0x0 */
ts4l_word ts4l_if_call_seq_u16_off24_83415AB0(ts4l_word a0, ts4l_word a1)
{
    ts4l_word loc50[4];
    unsigned short t1;
    ts4l_word t2;
    unsigned short t3;
    int t5;
    ts4l_word t6;

    t1 = *(unsigned short *)((char *)(ts4l_word)(a0) + 36);
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 40);
    loc50[0] = (ts4l_word)0;
    t3 = *(unsigned short *)((char *)(ts4l_word)(a1) + 2);
    t5 = RtlUnicodeToMultiByteN((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 4)), (ts4l_word)t3, (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)t2, (ts4l_word)t1);
    if ((int)t5 >= 0) {
        t6 = loc50[0];
        *(unsigned short *)((char *)(ts4l_word)(a1) + 0) = (unsigned short)t6;
    }
    return t5;
}

/* Loader_DLL.xex 0x83416230: if_call_seq fn_833E3A30, u32@0x0, u32@0x0, u32@0x0, u32@0x0, u32@0x1c */
ts4l_word ts4l_if_call_seq_fn_833E3A30_83416230(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    ts4l_word t1;
    ts4l_word t5;

    (void)a2;
    t1 = fn_833E3A30((ts4l_word)a4, (ts4l_word)0, (ts4l_word)32);
    *(ts4l_word *)((char *)(ts4l_word)(a4) + 0) = (ts4l_word)1;
    if ((int)(a1 & 0x4) != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a4) + 0) = (ts4l_word)((2097152) | 1);
    }
    if ((int)(a1 & 0x200) != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a4) + 0) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a4) + 0)) | 4194304);
    }
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a4) + 28);
    *(ts4l_word *)((char *)(ts4l_word)(a4) + 4) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a4) + 20) = (ts4l_word)(4294901760);
    *(ts4l_word *)((char *)(ts4l_word)(a4) + 24) = (ts4l_word)(a3 | 3);
    *(ts4l_word *)((char *)(ts4l_word)(a4) + 28) = (ts4l_word)((((a0 & 0x3fffffc) | (t5 & 0x8000000)) | 268435456) | 2);
    return t1;
}

/* Loader_DLL.xex 0x834162C8: if_call_seq fn_833E3A30, u32@0x1c, u32@0x4, u32@0x0, u32@0x0, u32@0x0 */
ts4l_word ts4l_if_call_seq_fn_833E3A30_834162C8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5)
{
    ts4l_word t1;
    ts4l_word t5;

    (void)a3;
    t1 = fn_833E3A30((ts4l_word)a5, (ts4l_word)0, (ts4l_word)32);
    *(ts4l_word *)((char *)(ts4l_word)(a5) + 28) = (ts4l_word)a0;
    *(ts4l_word *)((char *)(ts4l_word)(a5) + 4) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a5) + 0) = (ts4l_word)2;
    if ((int)(a1 & 0x4) != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a5) + 0) = (ts4l_word)((2097152) | 2);
    }
    if ((int)(a1 & 0x200) != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a5) + 0) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a5) + 0)) | 4194304);
    }
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a5) + 0);
    *(ts4l_word *)((char *)(ts4l_word)(a5) + 24) = (ts4l_word)a4;
    *(ts4l_word *)((char *)(ts4l_word)(a5) + 20) = (ts4l_word)(4294901760);
    *(ts4l_word *)((char *)(ts4l_word)(a5) + 0) = (ts4l_word)((a2 << 29) | t5);
    return t1;
}

/* Loader_DLL.xex 0x83416358: if_call_seq fn_833E3A30, u32@0x1c, u32@0x4, u32@0x0, u32@0x0, u32@0x0 */
ts4l_word ts4l_if_call_seq_fn_833E3A30_83416358(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3)
{
    ts4l_word t1;

    t1 = fn_833E3A30((ts4l_word)a3, (ts4l_word)0, (ts4l_word)32);
    *(ts4l_word *)((char *)(ts4l_word)(a3) + 28) = (ts4l_word)(a0 << 4);
    *(ts4l_word *)((char *)(ts4l_word)(a3) + 4) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a3) + 0) = (ts4l_word)8;
    if ((int)(a1 & 0x4) != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a3) + 0) = (ts4l_word)((2097152) | 8);
    }
    if ((int)(a1 & 0x200) != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a3) + 0) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a3) + 0)) | 4194304);
    }
    *(ts4l_word *)((char *)(ts4l_word)(a3) + 24) = (ts4l_word)a2;
    *(ts4l_word *)((char *)(ts4l_word)(a3) + 20) = (ts4l_word)(4294901760);
    return t1;
}

/* Loader_DLL.xex 0x83417598: if_call_seq u32@0x20, u32@0x20, fn_830AD4F0, u32@0x30, u32@0x30 */
ts4l_word ts4l_if_call_seq_u32_off20_83417598(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t3;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 32);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)((t1 & 0xfff) | (((t1 & 0xfffff000) + a1) & 0xfffff000));
    t2 = fn_830AD4F0((ts4l_word)a0);
    if ((ts4l_word)t2 > 1) {
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 48);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)((t3 & 0xfff) | (((t3 & 0xfffff000) + a2) & 0xfffff000));
    }
    return t2;
}

/* Loader_DLL.xex 0x83423568: call_seq u32@0x18, u32@0x18, u32@0x14, fn_83423158, u32@0x4, u32@0x18 */
ts4l_word ts4l_call_seq_u32_off18_83423568(ts4l_word a0)
{
    ts4l_word loc50[4];
    ts4l_word t1;
    ts4l_word t2;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 24);
    t2 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 24);
    fn_83423158((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 20)), (ts4l_word)t2, (ts4l_word)4096, (ts4l_word)(ts4l_word)&loc50[0]);
    *(ts4l_word *)((char *)(ts4l_word)(t1) + 4) = (ts4l_word)4096;
    *(ts4l_word *)((char *)(ts4l_word)(t1) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 24));
    return 1;
}

/* Loader_DLL.xex 0x834235F8: if_call_seq u32@0x554, u32@0x4, lbl_83072E84, fn_8343FD80, u32@0x0, fn_833E3AD0 */
ts4l_word ts4l_if_call_seq_u32_off554_834235F8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t6;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 1364);
    t2 = *(volatile ts4l_word *)((char *)(ts4l_word)(t1) + 4);
    if ((ts4l_word)a2 > (ts4l_word)t2) {
        fn_8343FD80((ts4l_word)a0, (ts4l_word)(ts4l_word)lbl_83072E84);
    }
    t6 = fn_833E3AD0((ts4l_word)a1, (ts4l_word)(*(volatile ts4l_word *)((char *)(ts4l_word)(t1) + 0)), (ts4l_word)a2);
    *(volatile ts4l_word *)((char *)(ts4l_word)(t1) + 0) = (ts4l_word)((*(volatile ts4l_word *)((char *)(ts4l_word)(t1) + 0)) + a2);
    *(volatile ts4l_word *)((char *)(ts4l_word)(t1) + 4) = (ts4l_word)((*(volatile ts4l_word *)((char *)(ts4l_word)(t1) + 4)) - a2);
    return t6;
}

/* Loader_DLL.xex 0x83423FA0: if_call_seq fn_83423F10, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_83423F10_83423FA0(ts4l_word a0, ts4l_word a1)
{

    fn_83423F10((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x834306C8: call_seq u32@0x38, lbl_83073884, u32@0x0, fn_8340D830, u32@0x58, fn_8340D830 */
ts4l_word ts4l_call_seq_u32_off38_834306C8(ts4l_word a0)
{
    ts4l_word t1;
    ts4l_word t6;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 56);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073884;
    fn_8340D830((ts4l_word)t1, (ts4l_word)(612433920));
    fn_8340D830((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 88)), (ts4l_word)(612433920));
    t6 = fn_8340D830((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 92)), (ts4l_word)(612433920));
    return t6;
}

/* Loader_DLL.xex 0x83430720: if_call_seq u32@0x8, u32@0x8, u32@0x54, u32@0x54, u32@0x10, u32@0x68 */
ts4l_word ts4l_if_call_seq_u32_off8_83430720(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word p9;
    ts4l_word p12;
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t3;
    ts4l_word t6;
    int t7;
    int t10;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 8);
    t2 = *(volatile ts4l_word *)((char *)(ts4l_word)(a1) + 8);
    if ((ts4l_word)t1 != (ts4l_word)t2 && (ts4l_word)t1 != 4) {
        *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 84) = (ts4l_word)t2;
    }
    t3 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 84);
    if ((ts4l_word)t3 != 0 || (int)(*(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 16)) != 0) {
        t6 = fn_8340D710((ts4l_word)((*(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 104)) << 4), (ts4l_word)(612433920));
        *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 88) = (ts4l_word)t6;
        if ((ts4l_word)t6 == 0) {
            p9 = (ts4l_word)((2147942400) | 14);
        } else {
            t7 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 16);
            if ((int)t7 != 0 && (int)(*(volatile ts4l_word *)((char *)(ts4l_word)(a1) + 16)) != 0) {
                *(volatile ts4l_word *)((char *)(ts4l_word)(a1) + 20) = (ts4l_word)1;
                *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)1;
            }
            p9 = (ts4l_word)0;
        }
        p12 = (ts4l_word)p9;
    } else {
        t10 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 16);
        if ((int)t10 != 0 && (int)(*(volatile ts4l_word *)((char *)(ts4l_word)(a1) + 16)) != 0) {
            *(volatile ts4l_word *)((char *)(ts4l_word)(a1) + 20) = (ts4l_word)1;
            *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)1;
        }
        p12 = (ts4l_word)0;
    }
    return p12;
}

/* Loader_DLL.xex 0x8343CC88: call_seq fn_83430450, lbl_8307392C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343CC88(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307392C;
    return a0;
}

/* Loader_DLL.xex 0x8343CCD8: call_seq fn_83430450, lbl_8307393C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343CCD8(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307393C;
    return a0;
}

/* Loader_DLL.xex 0x8343CD28: call_seq fn_83430450, lbl_8307394C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343CD28(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307394C;
    return a0;
}

/* Loader_DLL.xex 0x8343CD78: call_seq fn_83430450, lbl_8307395C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343CD78(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307395C;
    return a0;
}

/* Loader_DLL.xex 0x8343CDC8: call_seq fn_83430450, lbl_8307396C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343CDC8(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307396C;
    return a0;
}

/* Loader_DLL.xex 0x8343CE18: call_seq fn_83430450, lbl_8307397C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343CE18(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307397C;
    return a0;
}

/* Loader_DLL.xex 0x8343CE68: call_seq fn_83430450, lbl_8307398C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343CE68(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)8, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307398C;
    return a0;
}

/* Loader_DLL.xex 0x8343CEB8: call_seq fn_83430450, lbl_8307399C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343CEB8(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307399C;
    return a0;
}

/* Loader_DLL.xex 0x8343CF08: call_seq fn_83430450, lbl_830739AC, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343CF08(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_830739AC;
    return a0;
}

/* Loader_DLL.xex 0x8343CF58: call_seq fn_83430450, lbl_830739BC, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343CF58(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_830739BC;
    return a0;
}

/* Loader_DLL.xex 0x8343CFA8: call_seq fn_83430450, lbl_830739CC, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343CFA8(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_830739CC;
    return a0;
}

/* Loader_DLL.xex 0x8343CFF8: call_seq fn_83430450, lbl_830739DC, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343CFF8(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_830739DC;
    return a0;
}

/* Loader_DLL.xex 0x8343D048: call_seq fn_83430450, lbl_830739EC, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D048(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_830739EC;
    return a0;
}

/* Loader_DLL.xex 0x8343D098: call_seq fn_83430450, lbl_830739FC, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D098(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)64, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_830739FC;
    return a0;
}

/* Loader_DLL.xex 0x8343D0E8: call_seq fn_83430450, lbl_83073A0C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D0E8(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)8, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073A0C;
    return a0;
}

/* Loader_DLL.xex 0x8343D138: call_seq fn_83430450, lbl_83073A1C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D138(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073A1C;
    return a0;
}

/* Loader_DLL.xex 0x8343D188: call_seq fn_83430450, lbl_83073A2C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D188(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073A2C;
    return a0;
}

/* Loader_DLL.xex 0x8343D1D8: call_seq fn_83430450, lbl_83073A3C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D1D8(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)2);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073A3C;
    return a0;
}

/* Loader_DLL.xex 0x8343D228: call_seq fn_83430450, lbl_83073A4C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D228(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)2);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073A4C;
    return a0;
}

/* Loader_DLL.xex 0x8343D278: call_seq fn_83430450, lbl_83073A5C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D278(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)2);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073A5C;
    return a0;
}

/* Loader_DLL.xex 0x8343D2C8: call_seq fn_83430450, lbl_83073A6C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D2C8(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)3);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073A6C;
    return a0;
}

/* Loader_DLL.xex 0x8343D318: call_seq fn_83430450, lbl_83073A7C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D318(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)2);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073A7C;
    return a0;
}

/* Loader_DLL.xex 0x8343D368: call_seq fn_83430450, lbl_83073A8C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D368(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)2);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073A8C;
    return a0;
}

/* Loader_DLL.xex 0x8343D3B8: call_seq fn_83430450, lbl_83073A9C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D3B8(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)64, (ts4l_word)3);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073A9C;
    return a0;
}

/* Loader_DLL.xex 0x8343D408: call_seq fn_83430450, lbl_83073AAC, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D408(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073AAC;
    return a0;
}

/* Loader_DLL.xex 0x8343D458: call_seq fn_83430450, lbl_83073ABC, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D458(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073ABC;
    return a0;
}

/* Loader_DLL.xex 0x8343D4A8: call_seq fn_83430450, lbl_83073ACC, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D4A8(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073ACC;
    return a0;
}

/* Loader_DLL.xex 0x8343D4F8: call_seq fn_83430450, lbl_83073ADC, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D4F8(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)64, (ts4l_word)4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073ADC;
    return a0;
}

/* Loader_DLL.xex 0x8343D548: call_seq fn_83430450, lbl_83073AEC, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D548(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073AEC;
    return a0;
}

/* Loader_DLL.xex 0x8343D598: call_seq fn_83430450, lbl_83073AFC, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D598(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)64, (ts4l_word)4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073AFC;
    return a0;
}

/* Loader_DLL.xex 0x8343D5E8: call_seq fn_83430450, lbl_83073B0C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D5E8(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)128, (ts4l_word)4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073B0C;
    return a0;
}

/* Loader_DLL.xex 0x8343D638: call_seq fn_83430450, lbl_83073B1C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D638(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073B1C;
    return a0;
}

/* Loader_DLL.xex 0x8343D688: call_seq fn_83430450, lbl_83073B2C, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83430450_8343D688(ts4l_word a0, ts4l_word a1)
{
    fn_83430450((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)48, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073B2C;
    return a0;
}

/* Loader_DLL.xex 0x8343D858: if_call_seq fn_8343C240, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_8343C240_8343D858(ts4l_word a0, ts4l_word a1)
{

    fn_8343C240();
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343E418: if_call_seq fn_8343C240, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_8343C240_8343E418(ts4l_word a0, ts4l_word a1)
{

    fn_8343C240();
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343E468: if_call_seq fn_8343C240, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_8343C240_8343E468(ts4l_word a0, ts4l_word a1)
{

    fn_8343C240();
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343E4B8: if_call_seq fn_8343C240, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_8343C240_8343E4B8(ts4l_word a0, ts4l_word a1)
{

    fn_8343C240();
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343EF90: if_call_seq fn_8343D800, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_8343D800_8343EF90(ts4l_word a0, ts4l_word a1)
{

    fn_8343D800((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343EFE0: if_call_seq fn_8343D800, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_8343D800_8343EFE0(ts4l_word a0, ts4l_word a1)
{

    fn_8343D800((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343F030: if_call_seq fn_8343D800, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_8343D800_8343F030(ts4l_word a0, ts4l_word a1)
{

    fn_8343D800((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343F080: if_call_seq fn_8343D800, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_8343D800_8343F080(ts4l_word a0, ts4l_word a1)
{

    fn_8343D800((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343F0D0: if_call_seq fn_8343D800, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_8343D800_8343F0D0(ts4l_word a0, ts4l_word a1)
{

    fn_8343D800((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343F370: if_get u32@0x4, u32@0x4, u32@0x0, u32@0x14, vcall */
ts4l_word ts4l_if_get_u32_off4_8343F370(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(t1 + -1);
    if ((ts4l_word)t1 == 1) {
        ((ts4l_word (*)(ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 20))))((ts4l_word)a0, (ts4l_word)1);
    }
    return (t1 + -1);
}

/* Loader_DLL.xex 0x8343F408: if_call_seq fn_8340D710, u32@0xc, u32@0x8 */
ts4l_word ts4l_if_call_seq_fn_8340D710_8343F408(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p2;
    ts4l_word t1;

    t1 = fn_8340D710((ts4l_word)a1, (ts4l_word)(612433920));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)t1;
    if ((ts4l_word)t1 == 0) {
        p2 = (ts4l_word)((2147942400) | 14);
    } else {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 8) = (ts4l_word)a1;
        p2 = (ts4l_word)0;
    }
    return p2;
}

/* Loader_DLL.xex 0x8343F5D0: if_call_seq u32@0xc, lbl_83073BC8, u32@0x0, u8@-0x1, u32@0xc, u32@0xc */
ts4l_word ts4l_if_call_seq_u32_offc_8343F5D0(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;
    ts4l_word t5;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073BC8;
    if ((ts4l_word)t1 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)(t1 - (*(unsigned char *)((char *)(ts4l_word)(t1) + -1)));
    }
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073BAC;
    fn_8340D830((ts4l_word)t5, (ts4l_word)(612433920));
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343F890: if_call_seq u32@0xc, lbl_83073BAC, u32@0x0, fn_8340D830, fn_8340D830 */
ts4l_word ts4l_if_call_seq_u32_offc_8343F890(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073BAC;
    fn_8340D830((ts4l_word)t1, (ts4l_word)(612433920));
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x8343FA40: if_call_seq u32@0xc, lbl_83073BAC, u32@0x0, fn_8340D830, fn_8340D830 */
ts4l_word ts4l_if_call_seq_u32_offc_8343FA40(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83073BAC;
    fn_8340D830((ts4l_word)t1, (ts4l_word)(612433920));
    if ((int)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)(612433920));
    }
    return a0;
}

/* Loader_DLL.xex 0x834400D0: if_call_seq fn_8344C5B0, fn_833E3A30 */
ts4l_word ts4l_if_call_seq_fn_8344C5B0_834400D0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p4;
    ts4l_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p4 = (ts4l_word)a0;
    if ((ts4l_word)a0 != 0) {
        t1 = fn_8344C5B0((ts4l_word)2);
        if ((int)t1 != 0) {
            fn_833E3A30((ts4l_word)t1, (ts4l_word)0, (ts4l_word)64);
        }
        p4 = (ts4l_word)t1;
    }
    return p4;
}

/* Loader_DLL.xex 0x83445288: if_call_seq u32@0x558, lbl_830755CC, fn_8343FD80, u32@0x558, u32@0x558, fn_83451030 */
ts4l_word ts4l_if_call_seq_u32_off558_83445288(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;
    ts4l_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 1368);
    if ((int)(t1 & 0x4) == 0) {
        fn_8343FD80((ts4l_word)a0, (ts4l_word)(ts4l_word)lbl_830755CC);
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1368) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 1368)) | 8);
    t5 = fn_83451030((ts4l_word)a0);
    return t5;
}

/* Loader_DLL.xex 0x83445CB8: if_call_seq lbl_83075808, fn_8343FDB8, u32@0x55c, u32@0x5a8, u32@0x55c */
ts4l_word ts4l_if_call_seq_lbl_83075808_83445CB8(ts4l_word a0, int a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p2;
    ts4l_word t1;
    ts4l_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p2 = (ts4l_word)a0;
    if ((int)a1 != 8) {
        t1 = fn_8343FDB8((ts4l_word)a0, (ts4l_word)(ts4l_word)lbl_83075808);
        p2 = (ts4l_word)t1;
    }
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 1372);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1448) = (ts4l_word)a1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1372) = (ts4l_word)(t3 | 16);
    return p2;
}

/* Loader_DLL.xex 0x83445FF8: if_call_seq u32@0x550, u32@0x554, u32@0x54c, u32@0x620, u32@0x550, lbl_830758C4 */
ts4l_word ts4l_if_call_seq_u32_off550_83445FF8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p4;
    ts4l_word t1;
    ts4l_word t3;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 1360);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1364) = (ts4l_word)a1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1356) = (ts4l_word)a2;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1568) = (ts4l_word)a3;
    p4 = (ts4l_word)a0;
    if ((ts4l_word)t1 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 1360) = (ts4l_word)0;
        fn_8343FDB8((ts4l_word)a0, (ts4l_word)(ts4l_word)lbl_830758C4);
        t3 = fn_8343FDB8((ts4l_word)a0, (ts4l_word)(ts4l_word)lbl_8307588C);
        p4 = (ts4l_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x83446828: if_call_seq u32@0x55c, fn_83455050, fn_834480F0 */
ts4l_word ts4l_if_call_seq_u32_off55c_83446828(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;
    ts4l_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 1372);
    if ((int)(t1 & 0x40) == 0) {
        fn_83455050((ts4l_word)a0);
    }
    t4 = fn_834480F0((ts4l_word)a0, (ts4l_word)a1);
    return t4;
}

/* Loader_DLL.xex 0x834474E8: if_get u32@0x8, u32@0x10, u32@0x0, u16@0x14, u32@0x0 */
ts4l_word ts4l_if_get_u32_off8_834474E8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3)
{
    ts4l_word t1;

    if ((ts4l_word)a0 != 0 && (ts4l_word)a1 != 0) {
        t1 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 8);
        if ((int)(t1 & 0x8) != 0 && (ts4l_word)a2 != 0) {
            *(ts4l_word *)((char *)(ts4l_word)(a2) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 16));
            *(ts4l_word *)((char *)(ts4l_word)(a3) + 0) = (ts4l_word)(*(unsigned short *)((char *)(ts4l_word)(a1) + 20));
            return 8;
        }
        return 0;
    }
    return 0;
}

/* Loader_DLL.xex 0x83447680: if_get u32@0x560, u16@0x61e, u32@0x560, u32@0x55c, u32@0x55c, u8@0x616 */
void ts4l_if_get_u32_off560_83447680(ts4l_word a0, ts4l_word a1, int a2)
{
    ts4l_word p3;
    ts4l_word t1;
    ts4l_word t2;
    unsigned char t4;
    unsigned char t7;

    t1 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 1376);
    *(volatile unsigned short *)((char *)(ts4l_word)(a0) + 1566) = (unsigned short)(a1 & 0xff);
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 1376) = (ts4l_word)(t1 | 32768);
    t2 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 1372);
    if ((int)a2 == 1) {
        p3 = (ts4l_word)(t2 | 128);
    } else {
        p3 = (ts4l_word)(t2 & 0xffffff7f);
    }
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 1372) = (ts4l_word)p3;
    t4 = *(volatile unsigned char *)((char *)(ts4l_word)(a0) + 1558);
    if ((ts4l_word)t4 == 2) {
        *(volatile unsigned char *)((char *)(ts4l_word)(a0) + 1563) = (unsigned char)4;
    }
    if ((ts4l_word)t4 != 0) {
        return;
    }
    t7 = *(volatile unsigned char *)((char *)(ts4l_word)(a0) + 1559);
    if ((ts4l_word)t7 < 8) {
        return;
    }
    *(volatile unsigned char *)((char *)(ts4l_word)(a0) + 1563) = (unsigned char)2;
    return;
}

/* Loader_DLL.xex 0x83449D98: if_call_seq u32@0x54c, u32@0x554, u32@0x550, u32@0x54c, lbl_83075C38, fn_8343FDB8 */
ts4l_word ts4l_if_call_seq_u32_off54c_83449D98(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p4;
    ts4l_word t1;
    ts4l_word t3;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 1356);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1364) = (ts4l_word)a1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1360) = (ts4l_word)a2;
    p4 = (ts4l_word)a0;
    if ((ts4l_word)t1 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 1356) = (ts4l_word)0;
        fn_8343FDB8((ts4l_word)a0, (ts4l_word)(ts4l_word)lbl_83075C38);
        t3 = fn_8343FDB8((ts4l_word)a0, (ts4l_word)(ts4l_word)lbl_83075C00);
        p4 = (ts4l_word)t3;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1568) = (ts4l_word)0;
    return p4;
}

/* Loader_DLL.xex 0x8344C330: if_call_seq fn_8344B7D0, fn_8344A150 */
ts4l_word ts4l_if_call_seq_fn_8344B7D0_8344C330(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p3;
    int t1;
    ts4l_word t2;

    t1 = fn_8344B7D0((ts4l_word)a0, (ts4l_word)a1);
    p3 = (ts4l_word)t1;
    if ((int)t1 >= 0) {
        t2 = fn_8344A150((ts4l_word)a0);
        p3 = (ts4l_word)(((int)t2 >> 31) & t2);
    }
    return p3;
}

/* Loader_DLL.xex 0x8344C378: if_call_seq fn_8344B890, fn_8344A150 */
ts4l_word ts4l_if_call_seq_fn_8344B890_8344C378(ts4l_word a0)
{
    ts4l_word p3;
    int t1;
    ts4l_word t2;

    t1 = fn_8344B890();
    p3 = (ts4l_word)t1;
    if ((int)t1 >= 0) {
        t2 = fn_8344A150((ts4l_word)a0);
        p3 = (ts4l_word)(((int)t2 >> 31) & t2);
    }
    return p3;
}

/* Loader_DLL.xex 0x8344C4C0: if_call_seq u32@lbl_8352D368, fn_8344B7D0, fn_8344B7D0, fn_8344A150 */
ts4l_word ts4l_if_call_seq_u32_lbl_8352D368_8344C4C0(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p5;
    ts4l_word p6;
    int t1;
    int t3;
    ts4l_word t4;
    ts4l_word t2;

    t1 = *(ts4l_word *)lbl_8352D368;
    if ((int)t1 != 0) {
        t3 = fn_8344B7D0((ts4l_word)a0, (ts4l_word)a1);
        p5 = (ts4l_word)t3;
        if ((int)t3 >= 0) {
            t4 = fn_8344A150((ts4l_word)a0);
            p5 = (ts4l_word)(((int)t4 >> 31) & t4);
        }
        p6 = (ts4l_word)p5;
    } else {
        t2 = fn_8344B7D0((ts4l_word)a0, (ts4l_word)a1);
        p6 = (ts4l_word)t2;
    }
    return p6;
}

/* Loader_DLL.xex 0x8344C520: if_call_seq u32@lbl_8352D368, fn_8344B890, fn_8344B890, fn_8344A150 */
ts4l_word ts4l_if_call_seq_u32_lbl_8352D368_8344C520(ts4l_word a0)
{
    ts4l_word p5;
    ts4l_word p6;
    int t1;
    int t3;
    ts4l_word t4;
    ts4l_word t2;

    t1 = *(ts4l_word *)lbl_8352D368;
    if ((int)t1 != 0) {
        t3 = fn_8344B890();
        p5 = (ts4l_word)t3;
        if ((int)t3 >= 0) {
            t4 = fn_8344A150((ts4l_word)a0);
            p5 = (ts4l_word)(((int)t4 >> 31) & t4);
        }
        p6 = (ts4l_word)p5;
    } else {
        t2 = fn_8344B890();
        p6 = (ts4l_word)t2;
    }
    return p6;
}

/* Loader_DLL.xex 0x8344C640: if_call_seq fn_8340D710, lbl_8307A448, fn_8343FD80 */
ts4l_word ts4l_if_call_seq_fn_8340D710_8344C640(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p4;
    ts4l_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4l_word)a0 != 0 && (ts4l_word)a1 != 0) {
        t1 = fn_8340D710((ts4l_word)a1, (ts4l_word)(612433920));
        if ((int)t1 == 0) {
            fn_8343FD80((ts4l_word)a0, (ts4l_word)(ts4l_word)lbl_8307A448);
        }
        p4 = (ts4l_word)t1;
    } else {
        p4 = (ts4l_word)0;
    }
    return p4;
}

/* Loader_DLL.xex 0x83455848: if_call_seq u32@0x558, lbl_8307AEE8, fn_8343FD80, u32@0x558, u32@0x558, lbl_8307AECC */
ts4l_word ts4l_if_call_seq_u32_off558_83455848(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word p7;
    ts4l_word p17;
    ts4l_word p18;
    ts4l_word p19;
    ts4l_word t1;
    ts4l_word t12;
    ts4l_word t16;
    ts4l_word t11;
    ts4l_word t2;
    ts4l_word t6;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 1368);
    if ((int)(t1 & 0x1) != 0) {
        if ((int)(t1 & 0x4) == 0) {
            t12 = fn_8343FD80((ts4l_word)a0, (ts4l_word)(ts4l_word)lbl_8307AEE8);
            p17 = (ts4l_word)t12;
            if ((ts4l_word)a1 != 0) {
                *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 1368) = (ts4l_word)((*(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 1368)) | 24);
                if ((ts4l_word)a2 != 0) {
                    fn_8343FDB8((ts4l_word)a0, (ts4l_word)(ts4l_word)lbl_8307AECC);
                }
                t16 = fn_834552D0((ts4l_word)a0, (ts4l_word)a2);
                p17 = (ts4l_word)t16;
            }
            p18 = (ts4l_word)p17;
        } else {
            *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 1368) = (ts4l_word)((*(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 1368)) | 24);
            if ((ts4l_word)a2 != 0) {
                fn_8343FDB8((ts4l_word)a0, (ts4l_word)(ts4l_word)lbl_8307AECC);
            }
            t11 = fn_834552D0((ts4l_word)a0, (ts4l_word)a2);
            p18 = (ts4l_word)t11;
        }
        p19 = (ts4l_word)p18;
    } else {
        t2 = fn_8343FD80((ts4l_word)a0, (ts4l_word)(ts4l_word)lbl_8307AEE8);
        p7 = (ts4l_word)t2;
        if ((ts4l_word)a1 != 0) {
            *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 1368) = (ts4l_word)((*(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 1368)) | 24);
            if ((ts4l_word)a2 != 0) {
                fn_8343FDB8((ts4l_word)a0, (ts4l_word)(ts4l_word)lbl_8307AECC);
            }
            t6 = fn_834552D0((ts4l_word)a0, (ts4l_word)a2);
            p7 = (ts4l_word)t6;
        }
        p19 = (ts4l_word)p7;
    }
    return p19;
}

/* Loader_DLL.xex 0x83455E10: if_call_seq fn_834547F0, u8@0x60c, u32@0x558, u32@0x558, fn_834552D0, lbl_8307B128 */
ts4l_word ts4l_if_call_seq_fn_834547F0_83455E10(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word p10;
    ts4l_word p11;
    unsigned char t2;
    ts4l_word t6;
    ts4l_word t7;
    ts4l_word t9;
    ts4l_word t3;
    ts4l_word t5;

    fn_834547F0((ts4l_word)a0, (ts4l_word)(a0 + 1548));
    t2 = *(unsigned char *)((char *)(ts4l_word)(a0) + 1548);
    if ((int)(t2 & 0x20) == 0) {
        t6 = fn_8343FDD0((ts4l_word)a0, (ts4l_word)(ts4l_word)lbl_8307B128);
        p10 = (ts4l_word)t6;
        if ((ts4l_word)a1 != 0) {
            t7 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 1368);
            if ((int)(t7 & 0x4) != 0) {
                *(ts4l_word *)((char *)(ts4l_word)(a0) + 1368) = (ts4l_word)(t7 | 8);
            }
            t9 = fn_834552D0((ts4l_word)a0, (ts4l_word)a2);
            p10 = (ts4l_word)t9;
        }
        p11 = (ts4l_word)p10;
    } else {
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 1368);
        if ((int)(t3 & 0x4) != 0) {
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 1368) = (ts4l_word)(t3 | 8);
        }
        t5 = fn_834552D0((ts4l_word)a0, (ts4l_word)a2);
        p11 = (ts4l_word)t5;
    }
    return p11;
}

/* Loader_DLL.xex 0x83460AA8: loop_call_seq fn_8344EF30 */
ts4l_word ts4l_loop_call_seq_fn_8344EF30_83460AA8(ts4l_word a0, ts4l_word a1, int a2, int a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word lv1;
    ts4l_word p3;
    ts4l_word p4;
    ts4l_word t2;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p4 = (ts4l_word)a0;
    lv1 = (ts4l_word)a2;
    while ((int)lv1 < (int)a3) {
        t2 = fn_8344EF30((ts4l_word)a0, (ts4l_word)(a2 + -1), (ts4l_word)a0, (ts4l_word)lv1, (ts4l_word)1, (ts4l_word)a1);
        p3 = (ts4l_word)(lv1 + 1);
        lv1 = p3;
        p4 = (ts4l_word)t2;
    }
    return p4;
}

/* Loader_DLL.xex 0x83466520: get fn_83465B20, u32@0x24, u32@0x28, u32@0x28, vcall, u32@0x24 */
ts4l_word ts4l_get_fn_83465B20_83466520(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t2;
    ts4l_word t3;
    ts4l_word t6;
    ts4l_word t7;
    ts4l_word t10;

    fn_83465B20((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)0);
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 36);
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 40);
    ((ts4l_word (*)(ts4l_word, ts4l_word))(t2))((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 40)), (ts4l_word)t3);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 36);
    t7 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 36);
    ((ts4l_word (*)(ts4l_word, ts4l_word))(t6))((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 40)), (ts4l_word)t7);
    t10 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 36);
    ((ts4l_word (*)(ts4l_word, ts4l_word))(t10))((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 40)), (ts4l_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x834690F0: if_get u32@0x20, u32@0x28, vcall, u32@0x14, u32@0x18, u32@0x0 */
ts4l_word ts4l_if_get_u32_off20_834690F0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    ts4l_word t1;
    ts4l_word t3;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a4) + 32);
    t3 = ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word))(t1))((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a4) + 40)), (ts4l_word)1, (ts4l_word)28);
    if ((ts4l_word)t3 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(t3) + 20) = (ts4l_word)a2;
        *(ts4l_word *)((char *)(ts4l_word)(t3) + 24) = (ts4l_word)a3;
        *(ts4l_word *)((char *)(ts4l_word)(t3) + 0) = (ts4l_word)0;
        *(unsigned char *)((char *)(ts4l_word)(t3) + 16) = (unsigned char)a0;
        *(unsigned char *)((char *)(ts4l_word)(t3) + 17) = (unsigned char)a1;
    }
    return t3;
}

/* Loader_DLL.xex 0x8346B9D8: if_call_seq fn_8346B788, fn_833E9F90, u32@0x0, fn_833E9D50 */
ts4l_word ts4l_if_call_seq_fn_8346B788_8346B9D8(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p4;
    ts4l_word loc50[2];
    ts4l_word t2;
    ts4l_word t1;

    if ((ts4l_word)a0 == 0) {
        t2 = fn_833E9F90();
        *(ts4l_word *)((char *)(ts4l_word)(t2) + 0) = (ts4l_word)22;
        fn_833E9D50((ts4l_word)t2);
        p4 = (ts4l_word)22;
    } else {
        t1 = fn_8346B788((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)2, (ts4l_word)((2147418112) | 65535), (ts4l_word)(ts4l_word)&loc50[0]);
        p4 = (ts4l_word)t1;
    }
    return p4;
}

/* Loader_DLL.xex 0x8346D170: call_seq fn_833E3A30, u8@0x0, u16@0x2, u8@0x1, u16@0x6, u8@0x2 */
ts4l_word ts4l_call_seq_fn_833E3A30_8346D170(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;

    t1 = fn_833E3A30((ts4l_word)a1, (ts4l_word)0, (ts4l_word)16);
    *(unsigned short *)((char *)(ts4l_word)(a1) + 2) = (unsigned short)(*(unsigned char *)((char *)(ts4l_word)(a0) + 0));
    *(unsigned short *)((char *)(ts4l_word)(a1) + 6) = (unsigned short)(*(unsigned char *)((char *)(ts4l_word)(a0) + 1));
    *(unsigned short *)((char *)(ts4l_word)(a1) + 4) = (unsigned short)(*(unsigned char *)((char *)(ts4l_word)(a0) + 2));
    *(unsigned short *)((char *)(ts4l_word)(a1) + 8) = (unsigned short)(*(unsigned char *)((char *)(ts4l_word)(a0) + 3));
    return t1;
}

/* Loader_DLL.xex 0x83472D18: if_get u32@0x4, u32@0x0, u32@0x0, vcall, u32@0x0, u32@0x0 */
ts4l_word ts4l_if_get_u32_off4_83472D18(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p10;
    ts4l_word t1;
    ts4l_word t6;
    ts4l_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
    if ((ts4l_word)t1 != 0) {
        ((ts4l_word (*)(ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 0))))((ts4l_word)t1, (ts4l_word)1);
    }
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    p10 = (ts4l_word)t6;
    if ((ts4l_word)t6 != 0) {
        t9 = ((ts4l_word (*)(ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 0))))((ts4l_word)t6, (ts4l_word)1);
        p10 = (ts4l_word)t9;
    }
    return p10;
}

/* Loader_DLL.xex 0x83476CB0: call_seq u32@0x38, lbl_8307EC00, u32@0x0, fn_833E1758, u32@0x58, fn_833E1758 */
ts4l_word ts4l_call_seq_u32_off38_83476CB0(ts4l_word a0)
{
    ts4l_word t1;
    ts4l_word t6;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 56);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307EC00;
    fn_833E1758((ts4l_word)t1);
    fn_833E1758((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 88)));
    t6 = fn_833E1758((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 92)));
    return t6;
}

/* Loader_DLL.xex 0x834835B8: if_call_seq fn_834773C8, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_834773C8_834835B8(ts4l_word a0, ts4l_word a1)
{

    fn_834773C8();
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83484000: call_seq fn_83477720, lbl_8307EC30, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484000(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307EC30;
    return a0;
}

/* Loader_DLL.xex 0x834840A0: call_seq fn_83477720, lbl_8307EC40, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_834840A0(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307EC40;
    return a0;
}

/* Loader_DLL.xex 0x83484140: call_seq fn_83477720, lbl_8307EC50, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484140(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307EC50;
    return a0;
}

/* Loader_DLL.xex 0x834841E0: call_seq fn_83477720, lbl_8307EC60, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_834841E0(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307EC60;
    return a0;
}

/* Loader_DLL.xex 0x83484280: call_seq fn_83477720, lbl_8307EC70, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484280(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307EC70;
    return a0;
}

/* Loader_DLL.xex 0x83484320: call_seq fn_83477720, lbl_8307EC80, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484320(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307EC80;
    return a0;
}

/* Loader_DLL.xex 0x834843C0: call_seq fn_83477720, lbl_8307EC90, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_834843C0(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)8, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307EC90;
    return a0;
}

/* Loader_DLL.xex 0x83484460: call_seq fn_83477720, lbl_8307ECA0, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484460(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307ECA0;
    return a0;
}

/* Loader_DLL.xex 0x83484500: call_seq fn_83477720, lbl_8307ECB0, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484500(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307ECB0;
    return a0;
}

/* Loader_DLL.xex 0x834845A0: call_seq fn_83477720, lbl_8307ECC0, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_834845A0(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307ECC0;
    return a0;
}

/* Loader_DLL.xex 0x83484640: call_seq fn_83477720, lbl_8307ECD0, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484640(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307ECD0;
    return a0;
}

/* Loader_DLL.xex 0x834846E0: call_seq fn_83477720, lbl_8307ECE0, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_834846E0(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307ECE0;
    return a0;
}

/* Loader_DLL.xex 0x83484780: call_seq fn_83477720, lbl_8307ECF0, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484780(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307ECF0;
    return a0;
}

/* Loader_DLL.xex 0x83484820: call_seq fn_83477720, lbl_8307ED00, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484820(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)64, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307ED00;
    return a0;
}

/* Loader_DLL.xex 0x834848C0: call_seq fn_83477720, lbl_8307ED10, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_834848C0(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)8, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307ED10;
    return a0;
}

/* Loader_DLL.xex 0x83484960: call_seq fn_83477720, lbl_8307ED20, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484960(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307ED20;
    return a0;
}

/* Loader_DLL.xex 0x83484A00: call_seq fn_83477720, lbl_8307ED30, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484A00(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307ED30;
    return a0;
}

/* Loader_DLL.xex 0x83484AA0: call_seq fn_83477720, lbl_8307ED40, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484AA0(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)2);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307ED40;
    return a0;
}

/* Loader_DLL.xex 0x83484B40: call_seq fn_83477720, lbl_8307ED50, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484B40(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)2);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307ED50;
    return a0;
}

/* Loader_DLL.xex 0x83484BE0: call_seq fn_83477720, lbl_8307ED60, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484BE0(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)2);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307ED60;
    return a0;
}

/* Loader_DLL.xex 0x83484C80: call_seq fn_83477720, lbl_8307ED70, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484C80(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)3);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307ED70;
    return a0;
}

/* Loader_DLL.xex 0x83484D20: call_seq fn_83477720, lbl_8307ED80, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484D20(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)2);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307ED80;
    return a0;
}

/* Loader_DLL.xex 0x83484DC0: call_seq fn_83477720, lbl_8307ED90, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484DC0(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)2);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307ED90;
    return a0;
}

/* Loader_DLL.xex 0x83484E60: call_seq fn_83477720, lbl_8307EDA0, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484E60(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)64, (ts4l_word)3);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307EDA0;
    return a0;
}

/* Loader_DLL.xex 0x83484F00: call_seq fn_83477720, lbl_8307EDB0, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484F00(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307EDB0;
    return a0;
}

/* Loader_DLL.xex 0x83484FA0: call_seq fn_83477720, lbl_8307EDC0, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83484FA0(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)16, (ts4l_word)4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307EDC0;
    return a0;
}

/* Loader_DLL.xex 0x83485040: call_seq fn_83477720, lbl_8307EDD0, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83485040(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307EDD0;
    return a0;
}

/* Loader_DLL.xex 0x834850E0: call_seq fn_83477720, lbl_8307EDE0, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_834850E0(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)64, (ts4l_word)4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307EDE0;
    return a0;
}

/* Loader_DLL.xex 0x83485180: call_seq fn_83477720, lbl_8307EDF0, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83485180(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)32, (ts4l_word)4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307EDF0;
    return a0;
}

/* Loader_DLL.xex 0x83485220: call_seq fn_83477720, lbl_8307EE00, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_83485220(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)64, (ts4l_word)4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307EE00;
    return a0;
}

/* Loader_DLL.xex 0x834852C0: call_seq fn_83477720, lbl_8307EE10, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83477720_834852C0(ts4l_word a0, ts4l_word a1)
{
    fn_83477720((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)128, (ts4l_word)4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8307EE10;
    return a0;
}

/* Loader_DLL.xex 0x834853A8: if_call_seq fn_834773C8, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_834773C8_834853A8(ts4l_word a0, ts4l_word a1)
{

    fn_834773C8();
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83485440: if_call_seq fn_834773C8, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_834773C8_83485440(ts4l_word a0, ts4l_word a1)
{

    fn_834773C8();
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x834854D8: if_call_seq fn_834773C8, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_834773C8_834854D8(ts4l_word a0, ts4l_word a1)
{

    fn_834773C8();
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83485570: if_call_seq fn_834773C8, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_834773C8_83485570(ts4l_word a0, ts4l_word a1)
{

    fn_834773C8();
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83485608: if_call_seq fn_834773C8, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_834773C8_83485608(ts4l_word a0, ts4l_word a1)
{

    fn_834773C8();
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83486318: if_call_seq fn_83485658, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83485658_83486318(ts4l_word a0, ts4l_word a1)
{

    fn_83485658((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83486368: if_call_seq fn_83485658, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83485658_83486368(ts4l_word a0, ts4l_word a1)
{

    fn_83485658((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x834863B8: if_call_seq fn_83485658, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83485658_834863B8(ts4l_word a0, ts4l_word a1)
{

    fn_83485658((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83486408: if_call_seq fn_83485658, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83485658_83486408(ts4l_word a0, ts4l_word a1)
{

    fn_83485658((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83486458: if_call_seq fn_83485658, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_83485658_83486458(ts4l_word a0, ts4l_word a1)
{

    fn_83485658((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83488598: if_call_seq fn_83487878, fn_83487AC0 */
ts4l_word ts4l_if_call_seq_fn_83487878_83488598(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p3;
    int t1;
    ts4l_word t2;

    t1 = fn_83487878((ts4l_word)a0, (ts4l_word)(a1 + 8));
    p3 = (ts4l_word)t1;
    if ((int)t1 >= 0) {
        t2 = fn_83487AC0((ts4l_word)a0, (ts4l_word)a1);
        p3 = (ts4l_word)(((int)t2 >> 31) & t2);
    }
    return p3;
}

/* Loader_DLL.xex 0x834885F0: if_call_seq fn_83487878, fn_83487B40 */
ts4l_word ts4l_if_call_seq_fn_83487878_834885F0(ts4l_word a0)
{
    ts4l_word p3;
    int t1;
    ts4l_word t2;

    t1 = fn_83487878();
    p3 = (ts4l_word)t1;
    if ((int)t1 >= 0) {
        t2 = fn_83487B40((ts4l_word)a0);
        p3 = (ts4l_word)(((int)t2 >> 31) & t2);
    }
    return p3;
}
