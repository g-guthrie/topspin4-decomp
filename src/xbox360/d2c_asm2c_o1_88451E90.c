/* Swing_DLL.xex 0x88451E90-0x885B8C80, executable version 0.0.0.3. */
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

extern char __imp_ExThreadObjectType[];
extern char __imp_XexExecutableModuleHandle[];
extern char fn_884F4430[];
extern char fn_884F44D0[];
extern char ts4_if_get_u32_off0_885846C0[];
extern char fn_88598D98[];
extern char lbl_8808D66C[];
extern char lbl_8808D674[];
extern char lbl_8808D7C4[];
extern char lbl_8808F790[];
extern char lbl_88091314[];
extern char lbl_880917A8[];
extern char lbl_88091964[];
extern char lbl_88091A8C[];
extern char lbl_88091AB8[];
extern char lbl_88091BA4[];
extern char lbl_88091C50[];
extern char lbl_88091CE8[];
extern char lbl_88091D58[];
extern char lbl_88091DA8[];
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
extern char lbl_88095F04[];
extern char lbl_88095F78[];
extern char lbl_88095FB0[];
extern char lbl_88C2D5AC[];
extern char lbl_88C2D5CC[];
extern char lbl_88C2D800[];
extern char lbl_88C30DA8[];
extern char lbl_88C31194[];
extern char lbl_88C31510[];
extern char lbl_88C31878[];
extern char lbl_88C31FF4[];
extern char lbl_88C32010[];
extern char lbl_88C32048[];
extern char lbl_88C320BC[];
extern char lbl_88C320D8[];
extern char lbl_88C320E8[];
extern char lbl_88C320F8[];
extern char lbl_88C326B8[];
extern char lbl_88C32B28[];
extern char lbl_88C32F58[];
extern char lbl_88C33388[];
extern char lbl_88C337B8[];
extern char lbl_88CACF08[];
extern char lbl_88D27040[];
extern char lbl_88D2E534[];
extern char lbl_88D2E5AC[];
extern char lbl_88D2E878[];
extern char lbl_88D2EE58[];
extern char lbl_88D2EE70[];
extern char lbl_88D2F130[];
extern char lbl_88D2F1B0[];
extern char lbl_88D3CB10[];
extern char lbl_88D4E104[];
ts4_word ExAllocatePoolTypeWithTag();
ts4_word ExFreePool();
ts4_word ExRegisterTitleTerminateNotification();
ts4_word IoCompleteRequest();
ts4_word IoDeleteDevice();
ts4_word IoRemoveShareAccess();
ts4_word KeEnterCriticalRegion();
ts4_word KeLeaveCriticalRegion();
ts4_word KeResetEvent();
ts4_word KeSetEvent();
ts4_word KeTlsGetValue();
ts4_word KeWaitForSingleObject();
ts4_word MmAllocatePhysicalMemoryEx();
ts4_word MmQueryAddressProtect();
ts4_word NetDll_XNetStartup();
ts4_word NtCancelTimer();
ts4_word NtClearEvent();
ts4_word NtClose();
ts4_word NtDuplicateObject();
ts4_word NtFlushBuffersFile();
ts4_word NtFreeVirtualMemory();
ts4_word NtReleaseMutant();
ts4_word NtReleaseSemaphore();
ts4_word NtSetEvent();
ts4_word NtSuspendThread();
ts4_word NtYieldExecution();
ts4_word ObDereferenceObject();
ts4_word ObReferenceObjectByHandle();
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word XamGetSystemVersion();
ts4_word XamUserCreateStatsEnumerator();
ts4_word XamUserGetDeviceContext();
ts4_word XamUserReadProfileSettings();
ts4_word XexGetModuleHandle();
ts4_word XexGetModuleSection();
ts4_word XexGetProcedureAddress();
ts4_word XexUnloadImage();
ts4_word fn_882A8E28();
ts4_word fn_882A9128();
ts4_word ts4_if_get_u32_0xc_8841A820();
ts4_word fn_88472530();
ts4_word fn_884C5660();
ts4_word fn_884F3458();
ts4_word fn_884F3DA0();
ts4_word ts4_get_u32_offc_884F4748();
ts4_word fn_884F5120();
ts4_word fn_884F5F00();
ts4_word fn_884F6858();
ts4_word fn_884F7A50();
ts4_word fn_884F84A8();
ts4_word fn_884F85E8();
ts4_word fn_884F8700();
ts4_word fn_884F8A90();
ts4_word fn_884FA5E0();
ts4_word ts4_if_get_u32_off48_884FA700();
ts4_word fn_884FAFC0();
ts4_word fn_884FB038();
ts4_word fn_884FB178();
ts4_word fn_884FB288();
ts4_word ts4_if_get_u32_off8_884FB300();
ts4_word fn_88562DC0();
ts4_word fn_88562E80();
ts4_word ts4_get_u32_lbl_88C30BE0_88562ED0();
ts4_word fn_88564400();
ts4_word fn_885651F8();
ts4_word fn_88566B48();
ts4_word ts4_if_call_seq_fn_8856CD88_88567ED8();
ts4_word fn_8856CD88();
ts4_word fn_8856D2C0();
ts4_word fn_8856D820();
ts4_word ts4_if_call_seq_fn_8856D820_8856D868();
ts4_word fn_8856F7D8();
ts4_word fn_88574618();
ts4_word fn_88576488();
ts4_word fn_885775E8();
ts4_word fn_88579FF8();
ts4_word ts4_if_call_seq_XexLoadImage_8857A068();
ts4_word fn_8857C8C8();
ts4_word fn_8857D080();
ts4_word fn_88582680();
ts4_word ts4_if_call_seq_RtlInitUnicodeString_88582BD0();
ts4_word ts4_if_get_u32_lbl_88C32048_885844E8();
ts4_word ts4_call_seq_u32_off38_88584728();
ts4_word fn_885854A0();
ts4_word fn_885887B8();
ts4_word fn_88589330();
ts4_word fn_88589748();
ts4_word fn_885897C8();
ts4_word fn_88589A50();
ts4_word fn_8858AF70();
ts4_word fn_8858CBA0();
ts4_word ts4_loop_call_seq_u32_off1c_8858CE80();
ts4_word fn_8858DA50();
ts4_word fn_8858DAA8();
ts4_word fn_8858E758();
ts4_word fn_8858EA98();
ts4_word fn_88590220();
ts4_word fn_88590818();
ts4_word fn_88593B18();
ts4_word ts4_if_call_seq_u32_off20_88593CE8();
ts4_word fn_88594740();
ts4_word fn_88594848();
ts4_word fn_88594AA8();
ts4_word fn_88596020();
ts4_word fn_88597828();
ts4_word fn_88598798();
ts4_word fn_88598DB0();
ts4_word fn_885997A8();
ts4_word fn_88599808();
ts4_word fn_88599CF8();
ts4_word fn_8859A0F0();
ts4_word fn_8859AC98();
ts4_word fn_8859D5A8();
ts4_word fn_8859D728();
ts4_word ts4_if_call_seq_u16_off0_8859F280();
ts4_word fn_885A0048();
ts4_word fn_885A02F8();
ts4_word ts4_loop_call_seq_u32_off4_885A50D0();
ts4_word fn_885A5568();
ts4_word fn_885A5CE8();
ts4_word fn_885A5EB0();
ts4_word fn_885A6438();
ts4_word fn_885A6ED0();
ts4_word ts4_if_call_seq_u32_off2c_885A7A00();
ts4_word fn_885A7B18();
ts4_word ts4_if_call_seq_memset_885A9120();
ts4_word fn_885AA008();
ts4_word fn_885AA050();
ts4_word fn_885AA098();
ts4_word fn_885AA110();
ts4_word fn_885AA168();
ts4_word fn_885AA560();
ts4_word fn_885AA5F0();
ts4_word fn_885AA668();
ts4_word fn_885AA8A0();
ts4_word fn_885AB808();
ts4_word fn_885ABE30();
ts4_word fn_885B5368();
ts4_word fn_885B5460();
ts4_word fn_885B5698();
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_885B5880();
ts4_word fn_885B5910();
ts4_word fn_885B5E88();
ts4_word fn_885B5EE8();
ts4_word fn_885B62F8();
ts4_word fn_885B6628();
ts4_word fn_885B66F0();
ts4_word fn_885B72F0();
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
ts4_word fn_885B8660();
ts4_word fn_885B86E0();
ts4_word fn_885B87E0();
ts4_word fn_885CF138();
ts4_word ts4_if_get_u32_off0_885CF1F0();
ts4_word fn_885F5180();
ts4_word fn_88884DE0();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
#ifndef _MSC_VER
#define memset ts4_host_memset
#endif
ts4_word memset();
ts4_word ts4_call_runtime_2610();
ts4_word ts4_call_seq_fn_8858E5C8_8858CE30();
ts4_word ts4_call_seq_u32_off10_884F3428();
ts4_word ts4_forward_8858ED68();
ts4_word ts4_forward_record_status();
ts4_word ts4_forward_runtime_b3360();
ts4_word ts4_if_call_seq_u32_off18_885018B0();
ts4_word ts4_if_call_seq_u32_offc_88596808();
ts4_word ts4_if_call_seq_u32_offc_885BE178();
ts4_word ts4_memset();
ts4_word ts4_record_status();
ts4_word ts4_set_u32_off4_88597EC0();
ts4_word ts4_tailcall_fn_88566C60_88566F38();
ts4_word ts4_tailcall_fn_88582F30_8857A128();
ts4_word ts4_tsu_cleanup_end();





























/* Swing_DLL.xex 0x884F9E58: call_seq lbl_88C2D800, ts4_set_u32_off4_88597EC0, lbl_8808D7C4, u32@0x20, u32@0x0, ts4_memset */
ts4_word ts4_call_seq_lbl_88C2D800_884F9E58(ts4_word a0)
{
    ts4_set_u32_off4_88597EC0((ts4_word)a0, (ts4_word)(ts4_word)lbl_88C2D800);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808D7C4;
    ts4_memset((ts4_word)(a0 + 36), (ts4_word)0, (ts4_word)2064);
    ts4_memset((ts4_word)(a0 + 2100), (ts4_word)0, (ts4_word)16);
    return a0;
}



















/* Swing_DLL.xex 0x88573560: if_call_seq u32@0xc, u32@0x8, fn_885651F8, u32@0x0, u32@0x8, u32@0x4 */
ts4_word ts4_if_call_seq_u32_offc_88573560(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p6;
    ts4_word p8;
    ts4_word t1;
    ts4_word t3;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    p8 = (ts4_word)a0;
    if ((int)(t1 & 131) != 0) {
        p6 = (ts4_word)a0;
        if ((int)(t1 & 0x8) != 0) {
            t3 = fn_885651F8((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(t1 & 131));
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 12)) & 0xfffffff7) & 0xfffffbff);
            p6 = (ts4_word)t3;
        }
        p8 = (ts4_word)p6;
    }
    return p8;
}





/* Swing_DLL.xex 0x8857A0E8: if_call_seq XexGetModuleHandle, ts4_record_status */
ts4_word ts4_if_call_seq_XexGetModuleHandle_8857A0E8(ts4_word a0)
{
    ts4_word p4;
    ts4_word loc50[2];
    int t1;
    ts4_word t2;

    t1 = XexGetModuleHandle((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 < 0) {
        ts4_record_status((ts4_word)t1);
        p4 = (ts4_word)0;
    } else {
        t2 = loc50[0];
        p4 = (ts4_word)t2;
    }
    return p4;
}





/* Swing_DLL.xex 0x8857B4C8: if_call_seq NtSuspendThread, ts4_forward_record_status */
ts4_word ts4_if_call_seq_NtSuspendThread_8857B4C8(ts4_word a0)
{
    ts4_word p4;
    ts4_word loc50[2];
    int t1;
    ts4_word t2;

    t1 = NtSuspendThread((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 < 0) {
        ts4_forward_record_status((ts4_word)t1);
        p4 = (ts4_word)-1;
    } else {
        t2 = loc50[0];
        p4 = (ts4_word)t2;
    }
    return p4;
}

/* Swing_DLL.xex 0x8857B508: if_call_seq u32@__imp_ExThreadObjectType, ObReferenceObjectByHandle, ts4_forward_record_status, u32@0x4, u32@0x140, u32@0x0 */
ts4_word ts4_if_call_seq_u32__imp_ExThreadObjectType_8857B508(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word p9;
    ts4_word loc50[4];
    int t2;
    ts4_word t4;
    ts4_word t5;

    t2 = ObReferenceObjectByHandle((ts4_word)a0, (ts4_word)(*(volatile ts4_word *)__imp_ExThreadObjectType), (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t2 >= 0) {
        t4 = loc50[0];
        t5 = *(volatile ts4_word *)((char *)(ts4_word)(t4) + 4);
        if ((int)(t5 & 0xff) != 0) {
            p7 = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t4) + 320));
        } else {
            p7 = (ts4_word)259;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)p7;
        ObDereferenceObject((ts4_word)t4);
        p9 = (ts4_word)1;
    } else {
        ts4_forward_record_status((ts4_word)t2);
        p9 = (ts4_word)0;
    }
    return p9;
}

/* Swing_DLL.xex 0x8857BE58: if_call_seq NtFlushBuffersFile, ts4_record_status */
ts4_word ts4_if_call_seq_NtFlushBuffersFile_8857BE58(ts4_word a0)
{
    ts4_word p3;
    ts4_word loc50[2];
    int t1;

    t1 = NtFlushBuffersFile((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 >= 0) {
        p3 = (ts4_word)1;
    } else {
        ts4_record_status((ts4_word)t1);
        p3 = (ts4_word)0;
    }
    return p3;
}


/* Swing_DLL.xex 0x8857C1B8: if_call_seq NtReleaseMutant, ts4_record_status */
ts4_word ts4_if_call_seq_NtReleaseMutant_8857C1B8(ts4_word a0)
{
    ts4_word p3;
    int t1;

    t1 = NtReleaseMutant((ts4_word)a0, (ts4_word)0);
    if ((int)t1 >= 0) {
        p3 = (ts4_word)1;
    } else {
        ts4_record_status((ts4_word)t1);
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Swing_DLL.xex 0x8857C1F8: if_call_seq NtSetEvent, ts4_record_status */
ts4_word ts4_if_call_seq_NtSetEvent_8857C1F8(ts4_word a0)
{
    ts4_word p3;
    int t1;

    t1 = NtSetEvent((ts4_word)a0, (ts4_word)0);
    if ((int)t1 >= 0) {
        p3 = (ts4_word)1;
    } else {
        ts4_record_status((ts4_word)t1);
        p3 = (ts4_word)0;
    }
    return p3;
}








/* Swing_DLL.xex 0x88582730: if_call_seq NtCancelTimer, ts4_record_status */
ts4_word ts4_if_call_seq_NtCancelTimer_88582730(ts4_word a0)
{
    ts4_word p3;
    int t1;

    t1 = NtCancelTimer((ts4_word)a0, (ts4_word)0);
    if ((int)t1 < 0) {
        ts4_record_status((ts4_word)t1);
        p3 = (ts4_word)0;
    } else {
        p3 = (ts4_word)1;
    }
    return p3;
}






/* Swing_DLL.xex 0x885896D8: if_call_seq fn_88589330, u32@0x0, u32@0x0, u32@0x54, u32@0x54 */
ts4_word ts4_if_call_seq_fn_88589330_885896D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    int t1;
    ts4_word t3;

    t1 = fn_88589330((ts4_word)a0, (ts4_word)(a0 + 56), (ts4_word)a1, (ts4_word)0, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
    if ((int)t1 >= 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((a1 & 0xfff) + (*(ts4_word *)((char *)(ts4_word)(a4) + 0)));
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
        if ((ts4_word)a1 == (ts4_word)t3) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)(t3 + 4096);
        }
    }
    return t1;
}








/* Swing_DLL.xex 0x8858CCD8: if_call_seq u32@0x20, u32@0x1c, u8@0x972, fn_88590220, fn_8858CBA0, u32@0x1c */
ts4_word ts4_if_call_seq_u32_off20_8858CCD8(ts4_word a0)
{
    ts4_word loc54[1];
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    ts4_word t12;
    ts4_word t15;
    ts4_word t16;
    ts4_word t19;
    ts4_word t20;
    ts4_word t23;
    ts4_word t24;
    ts4_word t25;
    ts4_word t26;
    ts4_word t29;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(unsigned char *)((char *)(ts4_word)(a0) + 2418) = (unsigned char)0;
    fn_88590220((ts4_word)a0, (ts4_word)0, (ts4_word)t2, (ts4_word)t1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc54[0]);
    t4 = loc54[0];
    t5 = loc50[0];
    fn_8858CBA0((ts4_word)a0, (ts4_word)t5, (ts4_word)t4);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t8 = loc50[0];
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t8 == (ts4_word)t7) {
        memset((ts4_word)t9, (ts4_word)0, (ts4_word)8192);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    } else {
        fn_88562DC0((ts4_word)t9, (ts4_word)(((t8) >> 3) + t9), (ts4_word)((((t7) >> 3) - ((t8) >> 3)) + 1));
        t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        t12 = loc50[0];
        memset((ts4_word)(((((t11 - t12)) >> 3) + (*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 1), (ts4_word)0, (ts4_word)(8191 - (((t11 - t12)) >> 3)));
        t15 = loc50[0];
        t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
        fn_88562DC0((ts4_word)t16, (ts4_word)(t16 + t15), (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28)) - t15));
        t19 = loc54[0];
        t20 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
        fn_88562DC0((ts4_word)t20, (ts4_word)((t19 << 2) + t20), (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) - t19) << 2));
        t23 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        t24 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        t25 = loc50[0];
        t26 = loc54[0];
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(t23 - t25);
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t24 - t26);
    }
    t29 = fn_8858E758((ts4_word)a0);
    return t29;
}

/* Swing_DLL.xex 0x8858E700: loop_call_seq fn_88590818, fn_8858DAA8 */
ts4_word ts4_loop_call_seq_fn_88590818_8858E700(ts4_word a0)
{
    ts4_word lv2;
    ts4_word p5;
    ts4_word t4;

    fn_88590818((ts4_word)a0, (ts4_word)8, (ts4_word)(a0 + 17118), (ts4_word)(a0 + 17166), (ts4_word)(a0 + 17150), (ts4_word)1);
    lv2 = (ts4_word)0;
    do {
        t4 = fn_8858DAA8((ts4_word)a0, (ts4_word)3, (ts4_word)(*(unsigned char *)((char *)(ts4_word)((a0 + 17166)) + lv2)));
        p5 = (ts4_word)(lv2 + 1);
        lv2 = p5;
    } while ((int)p5 < 8);
    return t4;
}















/* Swing_DLL.xex 0x885965C8: if_call_seq u16@0x0, lbl_88091964, fn_885F5180, u32@0x18 */
ts4_word ts4_if_call_seq_u16_off0_885965C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word p5;
    unsigned short t1;
    int t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile unsigned short *)((char *)(ts4_word)(a0) + 0);
    p5 = (ts4_word)t1;
    if ((ts4_word)t1 == 65534) {
        t2 = fn_885F5180((ts4_word)(a0 + 28), (ts4_word)((ts4_word)lbl_88091964 + 4), (ts4_word)12);
        if ((int)t2 == 0) {
            p4 = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 24)) & 0xffff);
        } else {
            p4 = (ts4_word)0;
        }
        p5 = (ts4_word)p4;
    }
    return p5;
}







































/* Swing_DLL.xex 0x885A73C8: call_seq lbl_88C32B28, ts4_set_u32_off4_88597EC0, lbl_88091F68, u32@0x20, u32@0x0, u32@0x24 */
ts4_word ts4_call_seq_lbl_88C32B28_885A73C8(ts4_word a0)
{
    ts4_set_u32_off4_88597EC0((ts4_word)a0, (ts4_word)(ts4_word)lbl_88C32B28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88091F68;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    fn_88593B18((ts4_word)(ts4_word)lbl_88D2F130);
    return a0;
}



/* Swing_DLL.xex 0x885A7960: call_seq lbl_88C32F58, ts4_set_u32_off4_88597EC0, lbl_88091FB8, lbl_88091FA4, u32@0x60, u32@0x0 */
ts4_word ts4_call_seq_lbl_88C32F58_885A7960(ts4_word a0)
{
    ts4_set_u32_off4_88597EC0((ts4_word)a0, (ts4_word)(ts4_word)lbl_88C32F58);
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88091FB8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_88091FA4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    fn_88593B18((ts4_word)(ts4_word)lbl_88D2F130);
    memset((ts4_word)(a0 + 36), (ts4_word)0, (ts4_word)36);
    memset((ts4_word)(a0 + 72), (ts4_word)0, (ts4_word)24);
    return a0;
}














































/* Swing_DLL.xex 0x885B7520: call_seq ts4_set_u32_off4_885B7EE0, u32@0x94, lbl_88095F04, lbl_88095ECC, u32@0x0, u32@0x4 */
ts4_word ts4_call_seq_fn_885B7EE0_885B7520(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_set_u32_off4_885B7EE0((ts4_word)(a0 + 4), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88095F04;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_88095ECC;
    memset((ts4_word)(a0 + 28), (ts4_word)0, (ts4_word)60);
    memset((ts4_word)(a0 + 88), (ts4_word)0, (ts4_word)60);
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)(a0 + 28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)(a0 + 88);
    return a0;
}










