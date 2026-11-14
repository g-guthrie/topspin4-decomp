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

extern char __imp_XexExecutableModuleHandle[];
extern char fn_884F4430[];
extern char fn_884F44D0[];
extern char ts4_if_get_u32_off0_885846C0[];
extern char ts4_mask_if_ne_88598D98[];
extern char lbl_88001A20[];
extern char lbl_880023FC[];
extern char lbl_88004430[];
extern char lbl_880260D8[];
extern char lbl_880391A0[];
extern char lbl_880391E0[];
extern char lbl_88039444[];
extern char lbl_88039C34[];
extern char lbl_88039D5C[];
extern char lbl_88039EC0[];
extern char lbl_88039FA4[];
extern char lbl_8803A004[];
extern char lbl_8803A090[];
extern char lbl_8803A098[];
extern char lbl_8803A150[];
extern char lbl_8803A180[];
extern char lbl_8803A1A4[];
extern char lbl_8803A1C8[];
extern char lbl_8803A218[];
extern char lbl_8803A21C[];
extern char lbl_8803A260[];
extern char lbl_8808D66C[];
extern char lbl_8808D674[];
extern char lbl_8808D7C4[];
extern char lbl_8808F790[];
extern char lbl_8808F798[];
extern char lbl_88091314[];
extern char lbl_880917A8[];
extern char lbl_88091A8C[];
extern char lbl_88091AB8[];
extern char lbl_88091BA4[];
extern char lbl_88091C50[];
extern char lbl_88091CE8[];
extern char lbl_88091D58[];
extern char lbl_88091DA8[];
extern char lbl_88B3302C[];
extern char lbl_88C2D5AC[];
extern char lbl_88C2D5CC[];
extern char lbl_88C30BE0[];
extern char lbl_88C30DA8[];
extern char lbl_88C31194[];
extern char lbl_88C31510[];
extern char lbl_88C317A0[];
extern char lbl_88C31878[];
extern char lbl_88C31A60[];
extern char lbl_88C31A98[];
extern char lbl_88C31FF4[];
extern char lbl_88C32010[];
extern char lbl_88C32048[];
extern char lbl_88C320BC[];
extern char lbl_88C320D8[];
extern char lbl_88C320E8[];
extern char lbl_88C320F8[];
extern char lbl_88C326B8[];
extern char lbl_88C6E210[];
extern char lbl_88CAC988[];
extern char lbl_88CAC9A8[];
extern char lbl_88CACF08[];
extern char lbl_88D27040[];
extern char lbl_88D2E534[];
extern char lbl_88D2E588[];
extern char lbl_88D2E878[];
extern char lbl_88D2EE58[];
extern char lbl_88D2EE70[];
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
ts4_word NetDll_WSAStartup();
ts4_word NetDll_XNetStartup();
ts4_word NtClearEvent();
ts4_word NtClose();
ts4_word NtDuplicateObject();
ts4_word NtFreeVirtualMemory();
ts4_word NtQueryFullAttributesFile();
ts4_word NtReleaseSemaphore();
ts4_word NtYieldExecution();
ts4_word RtlEnterCriticalSection();
ts4_word RtlInitAnsiString();
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
ts4_word ts4_call_seq_u32_off38_882B4520();
ts4_word fn_882BF5C8();
ts4_word fn_882C28B0();
ts4_word fn_882C2B78();
ts4_word ts4_if_call_seq_fn_882C28B0_882C3680();
ts4_word ts4_call_seq_u32_off38_882D1E30();
ts4_word fn_882DB100();
ts4_word png2_png_write_chunk_start_882EFE60();
ts4_word ts4_call_seq_u32_off600_882EFEE8();
ts4_word fn_88315C60();
ts4_word fn_88315F10();
ts4_word fn_8832EDB0();
ts4_word fn_8832F538();
ts4_word ts4_call_seq_ts4_memset_8832F8F0();
ts4_word ts4_if_get_fn_883CB130_883CB4A0();
ts4_word fn_883CC388();
ts4_word fn_883CF6A8();
ts4_word ts4_addr_lbl_8803913C_883CF860();
ts4_word ts4_addr_lbl_8803943C_883DB758();
ts4_word ts4_if_get_u32_lbl_88B3302C_883DBC98();
ts4_word fn_883DBDC0();
ts4_word ts4_get_bits_0_1c_7_883E0778();
ts4_word fn_883E13B8();
ts4_word fn_883E1DD0();
ts4_word fn_883E1E78();
ts4_word fn_883E2FB0();
ts4_word fn_883E3700();
ts4_word ts4_if_call_seq_u32_off8_883E4E70();
ts4_word fn_883ED740();
ts4_word ts4_loop_call_seq_u32_off8_883FADF0();
ts4_word fn_883FB3E8();
ts4_word fn_883FDC10();
ts4_word fn_883FE660();
ts4_word ts4_addr_lbl_8803A248_883FEE90();
ts4_word ts4_finalize_owned_and_clear_883FF908();
ts4_word fn_88400C60();
ts4_word ts4_if_call_seq_fn_88400670_88400D28();
ts4_word ts4_if_get_u32_0xc_8841A820();
ts4_word fn_88472530();
ts4_word fn_884C5660();
ts4_word ts4_call_seq_u32_off10_884F3428();
ts4_word fn_884F3458();
ts4_word fn_884F3DA0();
ts4_word fn_884F4328();
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
ts4_word ts4_if_call_seq_u32_off18_885018B0();
ts4_word fn_88564400();
ts4_word fn_885651F8();
ts4_word ts4_tailcall_fn_885655E8_88565748();
ts4_word fn_88566B48();
ts4_word ts4_tailcall_fn_88566C60_88566F38();
ts4_word ts4_if_call_seq_fn_8856CD88_88567ED8();
#ifndef _MSC_VER
#define memset ts4_host_memset
#endif
ts4_word memset();
ts4_word fn_8856CD88();
ts4_word fn_8856D2C0();
ts4_word fn_8856D820();
ts4_word ts4_addr_lbl_88C31510_8856F558();
ts4_word fn_8856F7D8();
ts4_word fn_88574618();
ts4_word fn_88576488();
ts4_word fn_885775E8();
ts4_word fn_88579FF8();
ts4_word fn_8857A068();
ts4_word ts4_tailcall_fn_88582F30_8857A128();
ts4_word fn_8857D080();
ts4_word fn_88582680();
ts4_word ts4_if_call_seq_RtlInitUnicodeString_88582BD0();
ts4_word ts4_if_get_u32_lbl_88C32048_885844E8();
ts4_word fn_88584728();
ts4_word fn_885854A0();
ts4_word fn_885887B8();
ts4_word fn_88589748();
ts4_word fn_885897C8();
ts4_word fn_88589A50();
ts4_word fn_8858AF70();
ts4_word ts4_call_seq_fn_8858E5C8_8858CE30();
ts4_word ts4_loop_call_seq_u32_off1c_8858CE80();
ts4_word fn_8858DA50();
ts4_word fn_8858EA98();
ts4_word ts4_if_call_seq_u32_off20_88593CE8();
ts4_word fn_88594740();
ts4_word fn_88594848();
ts4_word fn_88594AA8();
ts4_word fn_88596020();
ts4_word ts4_if_call_seq_u32_offc_88596808();
ts4_word fn_88598798();
ts4_word ts4_list_find_88598DB0();
ts4_word fn_885997A8();
ts4_word fn_88599808();
ts4_word ts4_pool1_clear_88599CF8();
ts4_word fn_8859A0F0();
ts4_word fn_8859AC98();
ts4_word fn_8859D5A8();
ts4_word fn_8859D728();
ts4_word fn_885A0048();
ts4_word fn_885A02F8();
ts4_word ts4_loop_call_seq_u32_off4_885A50D0();
ts4_word fn_885A5568();
ts4_word fn_885A5CE8();
ts4_word fn_885AA560();
ts4_word fn_885AB808();
ts4_word ts4_if_get_fn_885ABDB0_885ABE30();
ts4_word fn_885B5460();
ts4_word fn_885B5698();
ts4_word fn_885B66F0();
ts4_word ts4_pool_free_885B72F0();
ts4_word ts4_if_get_u32_off0_885CF1F0();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88884DE0();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_call_runtime_2610();
ts4_word ts4_forward_8858ED68();
ts4_word ts4_forward_record_status();
ts4_word ts4_forward_runtime_b3360();
ts4_word ts4_memset();
ts4_word ts4_record_status();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x882C0B38: if_call_seq lbl_880023FC, u32@0x0, fn_882BF5C8, u32@0x80, ts4_tsu_cleanup_end, ts4_call_seq_u32_off38_882B4520 */
ts4_word ts4_if_call_seq_lbl_880023FC_882C0B38(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880023FC;
    fn_882BF5C8();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    if ((ts4_word)t2 != 0) {
        ts4_tsu_cleanup_end((ts4_word)t2);
    }
    t5 = ts4_call_seq_u32_off38_882B4520((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x882C3878: if_call_seq u32@lbl_88C6E210, fn_882C28B0, fn_882C2B78, ts4_if_call_seq_fn_882C28B0_882C3680 */
ts4_word ts4_if_call_seq_u32_lbl_88C6E210_882C3878(ts4_word a0)
{
    ts4_word p4;
    ts4_word p6;
    int t1;
    ts4_word t5;
    int t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88C6E210;
    if ((int)t1 != 0) {
        t5 = ts4_if_call_seq_fn_882C28B0_882C3680((ts4_word)a0);
        p6 = (ts4_word)t5;
    } else {
        t2 = fn_882C28B0();
        p4 = (ts4_word)t2;
        if ((int)t2 >= 0) {
            t3 = fn_882C2B78((ts4_word)a0);
            p4 = (ts4_word)(((int)t3 >> 31) & t3);
        }
        p6 = (ts4_word)p4;
    }
    return p6;
}

/* Swing_DLL.xex 0x882DC5E8: if_call_seq lbl_88004430, u32@0x0, fn_882DB100, u32@0x80, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0, ts4_call_seq_u32_off38_882D1E30 */
ts4_word ts4_if_call_seq_lbl_88004430_882DC5E8(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88004430;
    fn_882DB100();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    if ((ts4_word)t2 != 0) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)t2, (ts4_word)(612433920));
    }
    t5 = ts4_call_seq_u32_off38_882D1E30((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x882DC690: if_call_seq ts4_call_seq_u32_off38_882D1E30, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0 */
ts4_word ts4_if_call_seq_fn_882D1E30_882DC690(ts4_word a0, ts4_word a1)
{

    ts4_call_seq_u32_off38_882D1E30((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)a0, (ts4_word)(612433920));
    }
    return a0;
}

/* Swing_DLL.xex 0x882F0808: call_seq lbl_880260D8, png2_png_write_chunk_start_882EFE60, ts4_call_seq_u32_off600_882EFEE8, u32@0x558, u32@0x558 */
ts4_word ts4_call_seq_lbl_880260D8_882F0808(ts4_word a0)
{
    ts4_word t2;

    png2_png_write_chunk_start_882EFE60((ts4_word)a0, (ts4_word)(ts4_word)lbl_880260D8, (ts4_word)0);
    t2 = ts4_call_seq_u32_off600_882EFEE8((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 1368) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1368)) | 16);
    return t2;
}

/* Swing_DLL.xex 0x883DBD18: if_get u32@lbl_88CAC988, u32@0x0, u32@0x48, vcall, lbl_88039444, u32@0xac */
ts4_word ts4_if_get_u32_lbl_88CAC988_883DBD18(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p13;
    ts4_word loc50[1];
    ts4_word t1;
    int t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;
    int t11;
    ts4_word t12;

    (void)a0;
    t1 = *(ts4_word *)lbl_88CAC988;
    t4 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 72))))((ts4_word)t1, (ts4_word)-3, (ts4_word)16, (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0]);
    p13 = (ts4_word)t4;
    if ((int)t4 == 0) {
        t5 = loc50[0];
        t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 172);
        t7 = *(ts4_word *)((char *)(ts4_word)(t5) + 312);
        *(ts4_word *)((char *)(ts4_word)(t6) + 32) = (ts4_word)a2;
        t8 = ts4_if_get_u32_lbl_88B3302C_883DBC98((ts4_word)a2, (ts4_word)0, (ts4_word)(ts4_word)lbl_88039444, (ts4_word)119);
        fn_883E13B8((ts4_word)t8, (ts4_word)0);
        t10 = loc50[0];
        *(ts4_word *)((char *)(ts4_word)(t8) + 32) = (ts4_word)t10;
        t11 = fn_883E3700((ts4_word)t8, (ts4_word)a2);
        if ((int)t11 == 0) {
            *(ts4_word *)((char *)(ts4_word)(t7) + 16) = (ts4_word)t8;
            t12 = loc50[0];
            *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t12;
        }
        p13 = (ts4_word)t11;
    }
    return p13;
}

/* Swing_DLL.xex 0x883E5050: addr lbl_880391A0, u32@0x0, ts4_if_call_seq_u32_off8_883E4E70 */
ts4_word ts4_addr_lbl_880391A0_883E5050(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880391A0;
    return ts4_if_call_seq_u32_off8_883E4E70((ts4_word)a0);
}

/* Swing_DLL.xex 0x883E63D8: if_get u32@lbl_88CAC9A8, u32@0x0, u32@0x18 */
ts4_word ts4_if_get_u32_lbl_88CAC9A8_883E63D8(void)
{
    ts4_word t1;

    t1 = *(volatile ts4_word *)lbl_88CAC9A8;
    if ((ts4_word)t1 != 0) {
        return ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 0))) + 24))))((ts4_word)t1);
    }
    return 0;
}

/* Swing_DLL.xex 0x883EDC40: if_get u32@0x2c, u32@0x2c, fn_883ED740, u8@0x20, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_off2c_883EDC40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;
    ts4_word p15;
    ts4_word p16;
    ts4_word p17;
    ts4_word p18;
    ts4_word p19;
    ts4_word p20;
    ts4_word loc50[1];
    ts4_word t1;
    int t3;
    ts4_word t5;
    unsigned char t6;
    int t9;
    ts4_word t10;
    int t11;
    ts4_word t14;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)(t1 & 0x1) != (ts4_word)(a1 & 0xff)) {
        if ((ts4_word)(a1 & 0xff) != 0) {
            p2 = (ts4_word)(t1 | 1);
        } else {
            p2 = (ts4_word)(t1 & 0xfffffffe);
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)p2;
        t3 = fn_883ED740((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
        p19 = (ts4_word)t3;
        if ((int)t3 == 0) {
            t5 = loc50[0];
            if ((ts4_word)t5 != 0) {
                t6 = *(unsigned char *)((char *)(ts4_word)(t5) + 32);
                if ((int)(t6 & 0x1) != 0) {
                    t9 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 8))))((ts4_word)t5, (ts4_word)(ts4_word)&loc50[0]);
                    p16 = (ts4_word)t9;
                    if ((int)t9 == 0) {
                        t10 = loc50[0];
                        t11 = ts4_if_get_fn_883CB130_883CB4A0((ts4_word)t10, (ts4_word)a1);
                        if ((int)t11 == 36) {
                            t14 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12))))((ts4_word)a0);
                            p15 = (ts4_word)t14;
                        } else {
                            p15 = (ts4_word)0;
                        }
                        p16 = (ts4_word)p15;
                    }
                    p17 = (ts4_word)p16;
                } else {
                    p17 = (ts4_word)0;
                }
                p18 = (ts4_word)p17;
            } else {
                p18 = (ts4_word)0;
            }
            p19 = (ts4_word)p18;
        }
        p20 = (ts4_word)p19;
    } else {
        p20 = (ts4_word)0;
    }
    return p20;
}

/* Swing_DLL.xex 0x883EEA50: addr lbl_880391E0, u32@0x4, u32@0x0, u32@0x8, u32@0xc */
void ts4_addr_lbl_880391E0_883EEA50(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880391E0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x883EEC60: if_call_seq u32@0x8, lbl_88039C34, u32@lbl_88B3302C, u32@0x4, fn_88315F10, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off8_883EEC60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p5 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t4 = fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_88039C34, (ts4_word)58);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x883EF028: get u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off0_883EF028(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0, (ts4_word)a1, (ts4_word)1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Swing_DLL.xex 0x883EF118: if_call_seq u32@0x4, u32@0xac, u32@0x20, lbl_88039D5C, u32@lbl_88B3302C, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off4_883EF118(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 172);
    if ((ts4_word)t2 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 32));
    } else {
        p4 = (ts4_word)0;
    }
    if ((ts4_word)p4 == 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_88039D5C, (ts4_word)57);
    }
    return 0;
}

/* Swing_DLL.xex 0x883F2910: if_get u32@0x18, u32@0x18, u8@0x0 */
ts4_word ts4_if_get_u32_off18_883F2910(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p3;
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    if ((ts4_word)t1 != 0) {
        p3 = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(t1) + 24)) >> 1) & 0x1);
    } else {
        p3 = (ts4_word)0;
    }
    *(unsigned char *)((char *)(ts4_word)(a2) + 0) = (unsigned char)p3;
    return 0;
}

/* Swing_DLL.xex 0x883F2938: if_get u32@0x18, u32@0x1c, u32@0x4, u32@0x3c, u32@0x0 */
ts4_word ts4_if_get_u32_off18_883F2938(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p5;
    int t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 24))) + 28);
    p5 = (ts4_word)t2;
    if ((int)t2 < 0) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 60));
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)p5;
    return 0;
}

/* Swing_DLL.xex 0x883F2A30: get u32@0x18, u32@0x28, u32@0x0 */
ts4_word ts4_get_u32_off18_883F2A30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 24))) + 40));
    return 0;
}

/* Swing_DLL.xex 0x883F2A48: call_seq u32@0x18, fn_883FDC10, u8@0x0 */
ts4_word ts4_call_seq_u32_off18_883F2A48(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    (void)a0;
    t2 = fn_883FDC10((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24)), (ts4_word)32);
    *(unsigned char *)((char *)(ts4_word)(a2) + 0) = (unsigned char)(t2 != 0);
    return 0;
}

/* Swing_DLL.xex 0x883F2DC0: if_get u32@lbl_88B3302C, u32@0x4, fn_88315C60, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_lbl_88B3302C_883F2DC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p7;
    ts4_word t6;
    ts4_word t3;

    (void)a1;
    if ((ts4_word)a0 != 0) {
        t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)88, (ts4_word)7, (ts4_word)a2, (ts4_word)a3);
        p7 = (ts4_word)t6;
    } else {
        t3 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)88, (ts4_word)a2, (ts4_word)a3, (ts4_word)0, (ts4_word)0);
        p7 = (ts4_word)t3;
    }
    if ((ts4_word)p7 != 0) {
        fn_883FE660((ts4_word)p7);
    }
    return p7;
}

/* Swing_DLL.xex 0x883F2E40: if_get u32@lbl_88B3302C, u32@0x4, fn_88315C60, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_lbl_88B3302C_883F2E40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p7;
    ts4_word t6;
    ts4_word t3;

    (void)a1;
    if ((ts4_word)a0 != 0) {
        t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)40, (ts4_word)8, (ts4_word)a2, (ts4_word)a3);
        p7 = (ts4_word)t6;
    } else {
        t3 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)40, (ts4_word)a2, (ts4_word)a3, (ts4_word)0, (ts4_word)0);
        p7 = (ts4_word)t3;
    }
    if ((ts4_word)p7 != 0) {
        ts4_addr_lbl_8803A248_883FEE90((ts4_word)p7);
    }
    return p7;
}

/* Swing_DLL.xex 0x883F2EC0: if_get u32@lbl_88B3302C, u32@0x4, fn_88315C60, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_lbl_88B3302C_883F2EC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p7;
    ts4_word t6;
    ts4_word t3;

    (void)a1;
    if ((ts4_word)a0 != 0) {
        t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)64, (ts4_word)10, (ts4_word)a2, (ts4_word)a3);
        p7 = (ts4_word)t6;
    } else {
        t3 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)64, (ts4_word)a2, (ts4_word)a3, (ts4_word)0, (ts4_word)0);
        p7 = (ts4_word)t3;
    }
    if ((ts4_word)p7 != 0) {
        fn_883CF6A8((ts4_word)p7);
    }
    return p7;
}

/* Swing_DLL.xex 0x883F2F40: if_get u32@lbl_88B3302C, u32@0x4, fn_88315C60, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_lbl_88B3302C_883F2F40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p7;
    ts4_word t6;
    ts4_word t3;

    (void)a1;
    if ((ts4_word)a0 != 0) {
        t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)60, (ts4_word)6, (ts4_word)a2, (ts4_word)a3);
        p7 = (ts4_word)t6;
    } else {
        t3 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)60, (ts4_word)a2, (ts4_word)a3, (ts4_word)0, (ts4_word)0);
        p7 = (ts4_word)t3;
    }
    if ((ts4_word)p7 != 0) {
        fn_883E2FB0((ts4_word)p7);
    }
    return p7;
}

/* Swing_DLL.xex 0x883F2FC0: if_get u32@lbl_88B3302C, u32@0x4, fn_88315C60, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_lbl_88B3302C_883F2FC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p7;
    ts4_word t6;
    ts4_word t3;

    (void)a1;
    if ((ts4_word)a0 != 0) {
        t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)48, (ts4_word)11, (ts4_word)a2, (ts4_word)a3);
        p7 = (ts4_word)t6;
    } else {
        t3 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)48, (ts4_word)a2, (ts4_word)a3, (ts4_word)0, (ts4_word)0);
        p7 = (ts4_word)t3;
    }
    if ((ts4_word)p7 != 0) {
        ts4_addr_lbl_8803913C_883CF860((ts4_word)p7);
    }
    return p7;
}

/* Swing_DLL.xex 0x883F61E0: addr lbl_88039EC0, u32@0x4, u32@0x0, u32@0x10, u32@0xc */
void ts4_addr_lbl_88039EC0_883F61E0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88039EC0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x883F6288: if_call_seq u32@0x4, u32@0xac, u32@0x20, lbl_88039FA4, u32@lbl_88B3302C, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off4_883F6288(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 172);
    if ((ts4_word)t2 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 32));
    } else {
        p4 = (ts4_word)0;
    }
    if ((ts4_word)p4 == 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_88039FA4, (ts4_word)54);
    }
    return 0;
}

/* Swing_DLL.xex 0x883F63D8: if_get u32@0x4, u32@0x60, fn_883CC388 */
ts4_word ts4_if_get_u32_off4_883F63D8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 96);
    if ((int)(t2 & 0x1000) != 0) {
        return fn_883CC388((ts4_word)t1);
    }
    return 0;
}

/* Swing_DLL.xex 0x883F71D8: if_get u32@0x10, u32@0x14 */
ts4_word ts4_if_get_u32_off10_883F71D8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 20))) + 28));
    return 0;
}

/* Swing_DLL.xex 0x883F7200: if_call_seq u32@0x10, u32@0x24, u16@0x8c, u32@0x84, u32@0x14, u32@0x24 */
ts4_word ts4_if_call_seq_u32_off10_883F7200(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    float t3;
    ts4_word t4;
    int t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 36);
    t3 = *(float *)lbl_88001A20;
    *(unsigned short *)((char *)(ts4_word)(t1) + 140) = (unsigned short)0;
    *(float *)((char *)(ts4_word)(t1) + 76) = t3;
    *(ts4_word *)((char *)(ts4_word)(t1) + 132) = (ts4_word)0;
    t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 20);
    *(ts4_word *)((char *)(ts4_word)(t1) + 36) = (ts4_word)((t2 & -394) | 1024);
    t7 = ts4_get_bits_0_1c_7_883E0778((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 12))) + 12)));
    if ((int)t7 == 3) {
        *(unsigned short *)((char *)(ts4_word)(t1) + 64) = (unsigned short)-1;
    }
    return 0;
}

/* Swing_DLL.xex 0x883F7788: if_get u32@0x4, u32@0x60, u32@0x0 */
ts4_word ts4_if_get_u32_off4_883F7788(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 96)) >> 19) & 0x1);
    return 0;
}

/* Swing_DLL.xex 0x883F7868: get u32@0xc, u8@0x0 */
ts4_word ts4_get_u32_offc_883F7868(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    *(unsigned char *)((char *)(ts4_word)(a2) + 0) = (unsigned char)((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) & 0x1);
    return 0;
}

/* Swing_DLL.xex 0x883F7880: get u32@0x4, u32@0x3c, u32@0x0 */
ts4_word ts4_get_u32_off4_883F7880(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 60));
    return 0;
}

/* Swing_DLL.xex 0x883F78B0: if_get u32@0x4, u32@0xac, u32@0x18, u32@0x0 */
ts4_word ts4_if_get_u32_off4_883F78B0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t2;

    (void)a1;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 172);
    if ((ts4_word)t2 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 24));
    } else {
        p4 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)p4;
    return 0;
}

/* Swing_DLL.xex 0x883F78F8: if_call_seq u32@0x10, fn_883E1E78, u32@0x10, fn_883E1DD0 */
ts4_word ts4_if_call_seq_u32_off10_883F78F8(ts4_word a0)
{
    ts4_word p5;
    int t2;
    ts4_word t4;

    t2 = fn_883E1E78((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
    p5 = (ts4_word)t2;
    if ((int)t2 == 0) {
        t4 = fn_883E1DD0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x883F9238: if_call_seq u32@0x38, lbl_8803A004, u32@lbl_88B3302C, u32@0x4, fn_88315C60, ts4_addr_lbl_8803943C_883DB758 */
ts4_word ts4_if_call_seq_u32_off38_883F9238(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p8;
    ts4_word p9;
    ts4_word p10;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((ts4_word)t1 != 0) {
        p10 = (ts4_word)32;
    } else {
        if ((ts4_word)a1 > 50000) {
            p9 = (ts4_word)37;
        } else {
            t4 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)24, (ts4_word)(ts4_word)lbl_8803A004, (ts4_word)573, (ts4_word)0, (ts4_word)0);
            if ((ts4_word)t4 != 0) {
                t5 = ts4_addr_lbl_8803943C_883DB758((ts4_word)t4);
                p6 = (ts4_word)t5;
            } else {
                p6 = (ts4_word)0;
            }
            *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)p6;
            if ((ts4_word)p6 == 0) {
                p8 = (ts4_word)44;
            } else {
                t7 = fn_883DBDC0((ts4_word)p6, (ts4_word)a1);
                p8 = (ts4_word)t7;
            }
            p9 = (ts4_word)p8;
        }
        p10 = (ts4_word)p9;
    }
    return p10;
}

/* Swing_DLL.xex 0x883F9EB0: if_set u32@0x0, ts4_call_seq_ts4_memset_8832F8F0, u32@0x0, u32@0x40, vcall, u32@0x0 */
ts4_word ts4_if_set_u32_off0_883F9EB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p12;
    ts4_word p13;
    ts4_word loc50[52];
    int t4;
    int t7;
    ts4_word t10;

    if ((ts4_word)a3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
    }
    ts4_call_seq_ts4_memset_8832F8F0((ts4_word)(ts4_word)&loc50[0]);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 64))))((ts4_word)a0, (ts4_word)0);
    p13 = (ts4_word)t4;
    if ((int)t4 == 0) {
        t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 64))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
        p12 = (ts4_word)t7;
        if ((int)t7 == 0) {
            if ((ts4_word)a4 != 0) {
                memcpy((ts4_word)a4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)192);
            }
            if ((ts4_word)a3 != 0) {
                t10 = fn_8832F538((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2);
                *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t10;
            }
            p12 = (ts4_word)0;
        }
        p13 = (ts4_word)p12;
    }
    return p13;
}

/* Swing_DLL.xex 0x883FAC00: addr lbl_8803A090, u32@0xc, u32@0x4, u32@0x8, u32@0x0, u32@0x14 */
void ts4_addr_lbl_8803A090_883FAC00(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(a0 + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(a0 + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A090;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x883FAE48: if_call_seq ts4_loop_call_seq_u32_off8_883FADF0, u32@0x8, u32@0xc, u32@0x10 */
ts4_word ts4_if_call_seq_fn_883FADF0_883FAE48(ts4_word a0)
{
    int t1;

    t1 = ts4_loop_call_seq_u32_off8_883FADF0();
    if ((int)t1 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(a0 + 8);
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(a0 + 8);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    }
    return t1;
}

/* Swing_DLL.xex 0x883FAE90: loop_call_seq u32@0x8, fn_8832EDB0, u32@0x0 */
ts4_word ts4_loop_call_seq_u32_off8_883FAE90(ts4_word a0, ts4_word a1)
{
    ts4_word lv2;
    ts4_word p5;

    lv2 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
    while ((ts4_word)lv2 != (ts4_word)(a0 + 8)) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)2, (ts4_word)20);
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 0));
        lv2 = p5;
    }
    return 0;
}

/* Swing_DLL.xex 0x883FB1E8: if_get u32@0x8, u32@0x4, vcall, u32@0x20, u32@0x4, vcall */
ts4_word ts4_if_get_u32_off8_883FB1E8(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    int t3;
    ts4_word t6;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 4))))((ts4_word)(a0 + 8));
    p7 = (ts4_word)t3;
    if ((int)t3 == 0) {
        t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 4))))((ts4_word)(a0 + 32), (ts4_word)a1);
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Swing_DLL.xex 0x883FB250: if_set u32@0x8, u32@0x0 */
ts4_word ts4_if_set_u32_off8_883FB250(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    if ((ts4_word)a2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)a1;
    }
    return 0;
}

/* Swing_DLL.xex 0x883FB268: if_get u32@0x8, u32@0x8 */
ts4_word ts4_if_get_u32_off8_883FB268(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)a1 == (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    }
    return 0;
}

/* Swing_DLL.xex 0x883FB4B8: if_call_seq fn_883FB3E8, lbl_8803A098, u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
ts4_word ts4_if_call_seq_fn_883FB3E8_883FB4B8(ts4_word a0)
{
    ts4_word p5;
    int t1;

    t1 = fn_883FB3E8();
    p5 = (ts4_word)t1;
    if ((int)t1 == 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803A098, (ts4_word)702);
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Swing_DLL.xex 0x883FB928: if_call_seq u32@0x4, ts4_if_call_seq_fn_88400670_88400D28, u32@0x14, u32@0x1c */
ts4_word ts4_if_call_seq_u32_off4_883FB928(ts4_word a0)
{
    int t2;

    t2 = ts4_if_call_seq_fn_88400670_88400D28((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    if ((int)t2 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    }
    return t2;
}

/* Swing_DLL.xex 0x883FD0F0: if_get u32@0x14, u32@0x0, u32@0xc, vcall, u32@0x18, u8@0x0 */
ts4_word ts4_if_get_u32_off14_883FD0F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t12;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;
    ts4_word t4;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 >= 1) {
        if ((ts4_word)t1 != 1) {
            if ((ts4_word)t1 < 3) {
                t12 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 12))))((ts4_word)a1);
                *(unsigned char *)((char *)(ts4_word)(a2) + 0) = (unsigned char)(t12 == 0);
            }
        } else {
            t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
            t9 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t6) + 8))))((ts4_word)a1, (ts4_word)t7);
            *(unsigned char *)((char *)(ts4_word)(a2) + 0) = (unsigned char)t9;
        }
    } else {
        t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 12))))((ts4_word)a1);
        *(unsigned char *)((char *)(ts4_word)(a2) + 0) = (unsigned char)(((*(ts4_word *)((char *)(ts4_word)(a0) + 24)) - t4) == 0);
    }
    return 0;
}

/* Swing_DLL.xex 0x883FD2D0: addr lbl_8803A180, u32@0x1c, u32@0xc, u32@0x0, u8@0x24 */
void ts4_addr_lbl_8803A180_883FD2D0(ts4_word a0)
{
    float t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    t1 = *(float *)lbl_88001A20;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)1;
    *(float *)((char *)(ts4_word)(a0) + 20) = t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A180;
    *(float *)((char *)(ts4_word)(a0) + 24) = t1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 36) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x883FD3C8: addr lbl_8803A1A4, u32@0x18, u32@0xc, u32@0x0, u32@0x1c */
void ts4_addr_lbl_8803A1A4_883FD3C8(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A1A4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x883FD438: if_call_seq lbl_8803A150, u32@lbl_88B3302C, u32@0x4, fn_88315C60, lbl_8803A1A4, u32@0x18 */
ts4_word ts4_if_call_seq_lbl_8803A150_883FD438(ts4_word a0)
{
    ts4_word p4;
    ts4_word t3;

    t3 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)32, (ts4_word)(ts4_word)lbl_8803A150, (ts4_word)193, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t3 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)1;
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_8803A1A4;
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 28) = (ts4_word)0;
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(p4) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20));
    *(volatile ts4_word *)((char *)(ts4_word)(p4) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
    *(volatile ts4_word *)((char *)(ts4_word)(p4) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
    return p4;
}

/* Swing_DLL.xex 0x883FD4D0: addr lbl_8803A1C8, u32@0xc, u32@0x0, u8@0x11 */
void ts4_addr_lbl_8803A1C8_883FD4D0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A1C8;
    *(unsigned char *)((char *)(ts4_word)(a0) + 17) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x883FD4F8: if_call_seq lbl_8803A150, u32@lbl_88B3302C, u32@0x4, fn_88315C60, lbl_8803A1C8, u32@0xc */
ts4_word ts4_if_call_seq_lbl_8803A150_883FD4F8(ts4_word a0)
{
    ts4_word p4;
    ts4_word t3;

    t3 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)20, (ts4_word)(ts4_word)lbl_8803A150, (ts4_word)235, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)1;
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_8803A1C8;
        *(unsigned char *)((char *)(ts4_word)(t3) + 17) = (unsigned char)1;
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    *(unsigned char *)((char *)(ts4_word)(p4) + 17) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 17));
    return p4;
}

/* Swing_DLL.xex 0x883FE8C8: addr lbl_8803A218, u32@0x10, u32@0x0 */
void ts4_addr_lbl_8803A218_883FE8C8(ts4_word a0)
{
    float t1;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)1;
    t1 = *(float *)lbl_88001A20;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A218;
    *(volatile float *)((char *)(ts4_word)(a0) + 8) = t1;
    *(volatile float *)((char *)(ts4_word)(a0) + 12) = t1;
    return;
}

/* Swing_DLL.xex 0x883FE8F0: if_call_seq u8@0x4, u8@0x4, u8@0x4, fn_8832EDB0, u8@0x4 */
ts4_word ts4_if_call_seq_u8_off4_883FE8F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    unsigned char t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 4);
        if ((ts4_word)t2 == 0) {
            fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)(16777216), (ts4_word)20);
            *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)1;
        }
    } else {
        *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)0;
    }
    return 0;
}

/* Swing_DLL.xex 0x883FEAB0: if_addr lbl_8803A21C, u32@0x1c, u32@lbl_88B3302C, u32@0x4, fn_88315F10, u32@0x0 */
ts4_word ts4_if_addr_lbl_8803A21C_883FEAB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t10;
    ts4_word t11;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        if ((ts4_word)a1 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 8))))((ts4_word)a1, (ts4_word)t1, (ts4_word)(ts4_word)lbl_8803A21C, (ts4_word)192);
        } else {
            fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_8803A21C, (ts4_word)192);
        }
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    *(unsigned short *)((char *)(ts4_word)(a0) + 52) = (unsigned short)0;
    if ((ts4_word)t10 != 0) {
        t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
        if ((int)(t11 & 0x2) == 0) {
            fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t10, (ts4_word)(ts4_word)lbl_8803A21C, (ts4_word)198);
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x883FF020: if_call_seq u32@0x8, lbl_8803A260, u32@lbl_88B3302C, u32@0x4, fn_88315F10, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off8_883FF020(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_8803A260, (ts4_word)84);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    }
    return 0;
}

/* Swing_DLL.xex 0x883FF778: get u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_off4_883FF778(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((t1 & (*(ts4_word *)((char *)(ts4_word)(a1) + 0))) != 0);
}

/* Swing_DLL.xex 0x883FFBE0: if_call_seq u32@0x10, ts4_finalize_owned_and_clear_883FF908, u32@0x14, u32@0x14, u32@0x10, u32@0x14 */
ts4_word ts4_if_call_seq_u32_off10_883FFBE0(ts4_word a0)
{
    ts4_word p7;
    int t2;
    ts4_word t4;
    ts4_word t5;

    t2 = ts4_finalize_owned_and_clear_883FF908((ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) << 2) + a0));
    p7 = (ts4_word)t2;
    if ((int)t2 == 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
        if ((ts4_word)t4 > 1) {
            t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(t4 + -1);
            *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)((t5 + 1) & 0x3);
        }
        p7 = (ts4_word)0;
    }
    return p7;
}

/* Swing_DLL.xex 0x88400CD0: if_call_seq fn_88400C60, lbl_8803A260, u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
ts4_word ts4_if_call_seq_fn_88400C60_88400CD0(ts4_word a0)
{
    ts4_word p5;
    int t1;

    t1 = fn_88400C60((ts4_word)a0);
    p5 = (ts4_word)t1;
    if ((int)t1 == 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803A260, (ts4_word)1140);
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Swing_DLL.xex 0x88424F78: call_seq ts4_tailcall_fn_885655E8_88565748, u32@0x8 */
ts4_word ts4_call_seq_fn_88565748_88424F78(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = ts4_tailcall_fn_885655E8_88565748((ts4_word)a1, (ts4_word)a2);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x88451E90: if_call_seq u32@0x1e30, u32@lbl_88CACF08, KeTlsGetValue, ts4_if_get_u32_0xc_8841A820, u32@lbl_88CACF08, u32@0x1e34 */
ts4_word ts4_if_call_seq_u32_off1e30_88451E90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p17;
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t13;
    ts4_word t14;
    ts4_word t15;
    ts4_word t16;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 7728);
    p17 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        ts4_if_get_u32_0xc_8841A820((ts4_word)t3, (ts4_word)t1);
        t5 = *(ts4_word *)lbl_88CACF08;
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 7732);
        t7 = KeTlsGetValue((ts4_word)t5);
        ts4_if_get_u32_0xc_8841A820((ts4_word)t7, (ts4_word)t6);
        t9 = *(ts4_word *)lbl_88CACF08;
        t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 7736);
        t11 = KeTlsGetValue((ts4_word)t9);
        ts4_if_get_u32_0xc_8841A820((ts4_word)t11, (ts4_word)t10);
        t13 = *(ts4_word *)lbl_88CACF08;
        t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 7740);
        t15 = KeTlsGetValue((ts4_word)t13);
        t16 = ts4_if_get_u32_0xc_8841A820((ts4_word)t15, (ts4_word)t14);
        *(ts4_word *)((char *)(ts4_word)(a0) + 7728) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 7732) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 7736) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 7740) = (ts4_word)0;
        p17 = (ts4_word)t16;
    }
    return p17;
}

/* Swing_DLL.xex 0x88472748: if_call_seq u32@0x4, lbl_88D3CB10, fn_88472530, u32@0x4, u32@0x8, u32@0x30 */
ts4_word ts4_if_call_seq_u32_off4_88472748(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p9 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        fn_88472530((ts4_word)(ts4_word)lbl_88D3CB10);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        *(ts4_word *)((char *)(ts4_word)(t3) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        if ((ts4_word)t5 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t5) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
        }
        *(ts4_u64 *)((char *)(ts4_word)((ts4_word)lbl_88D3CB10) + 32) = (ts4_u64)-1;
        t8 = RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_88D3CB10);
        p9 = (ts4_word)t8;
    }
    return p9;
}

/* Swing_DLL.xex 0x884CE940: if_call_seq u32@0x14, u32@0x10, u32@0xc, fn_884C5660, u32@0x14 */
ts4_word ts4_if_call_seq_u32_off14_884CE940(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    int t1;
    ts4_word t2;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    p6 = (ts4_word)a0;
    if ((int)t1 == 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        t4 = fn_884C5660((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)1;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Swing_DLL.xex 0x884EFDD0: if_addr XamGetSystemVersion, lbl_8808D66C, XexGetModuleHandle, XexGetProcedureAddress, NetDll_XNetStartup, vcall */
ts4_word ts4_if_addr_XamGetSystemVersion_884EFDD0(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word p10;
    ts4_word p14;
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t4;
    ts4_word t2;
    ts4_word t13;
    ts4_word t12;

    loc50[0] = (ts4_word)0;
    t1 = XamGetSystemVersion();
    if ((ts4_word)t1 >= (ts4_word)((537526272) | 12800)) {
        t3 = XexGetModuleHandle((ts4_word)(ts4_word)lbl_8808D66C, (ts4_word)(ts4_word)&loc54[0]);
        if ((int)t3 >= 0) {
            t5 = loc54[0];
            t6 = XexGetProcedureAddress((ts4_word)t5, (ts4_word)80, (ts4_word)(ts4_word)&loc50[0]);
            t7 = loc50[0];
            loc50[0] = (ts4_word)((((t6) >> 31) + -1) & t7);
            p8 = (ts4_word)((((t6) >> 31) + -1) & t7);
        } else {
            t4 = loc50[0];
            p8 = (ts4_word)t4;
        }
        p10 = (ts4_word)p8;
    } else {
        t2 = loc50[0];
        p10 = (ts4_word)t2;
    }
    if ((ts4_word)p10 != 0) {
        t13 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(p10))((ts4_word)a0, (ts4_word)a1, (ts4_word)((541982720) | 61696));
        p14 = (ts4_word)t13;
    } else {
        t12 = NetDll_XNetStartup((ts4_word)a0, (ts4_word)a1);
        p14 = (ts4_word)t12;
    }
    return p14;
}

/* Swing_DLL.xex 0x884F0178: if_addr XamGetSystemVersion, lbl_8808D66C, XexGetModuleHandle, XexGetProcedureAddress, NetDll_WSAStartup, vcall */
ts4_word ts4_if_addr_XamGetSystemVersion_884F0178(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p8;
    ts4_word p10;
    ts4_word p14;
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t4;
    ts4_word t2;
    ts4_word t13;
    ts4_word t12;

    loc50[0] = (ts4_word)0;
    t1 = XamGetSystemVersion();
    if ((ts4_word)t1 >= (ts4_word)((537526272) | 12800)) {
        t3 = XexGetModuleHandle((ts4_word)(ts4_word)lbl_8808D66C, (ts4_word)(ts4_word)&loc54[0]);
        if ((int)t3 >= 0) {
            t5 = loc54[0];
            t6 = XexGetProcedureAddress((ts4_word)t5, (ts4_word)36, (ts4_word)(ts4_word)&loc50[0]);
            t7 = loc50[0];
            loc50[0] = (ts4_word)((((t6) >> 31) + -1) & t7);
            p8 = (ts4_word)((((t6) >> 31) + -1) & t7);
        } else {
            t4 = loc50[0];
            p8 = (ts4_word)t4;
        }
        p10 = (ts4_word)p8;
    } else {
        t2 = loc50[0];
        p10 = (ts4_word)t2;
    }
    if ((ts4_word)p10 != 0) {
        t13 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))(p10))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)((541982720) | 61696));
        p14 = (ts4_word)t13;
    } else {
        t12 = NetDll_WSAStartup((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p14 = (ts4_word)t12;
    }
    return p14;
}

/* Swing_DLL.xex 0x884F1D68: if_call_seq fn_88582680, XamUserReadProfileSettings */
ts4_word ts4_if_call_seq_fn_88582680_884F1D68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = fn_88582680((ts4_word)a0);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        t2 = XamUserReadProfileSettings((ts4_word)a0, (ts4_word)a1, (ts4_word)0, (ts4_word)0, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x884F1FC8: if_call_seq fn_884F3458, ts4_call_seq_u32_off10_884F3428 */
ts4_word ts4_if_call_seq_fn_884F3458_884F1FC8(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)2;
    t1 = fn_884F3458((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    p3 = (ts4_word)t1;
    if ((int)t1 >= 0) {
        t2 = ts4_call_seq_u32_off10_884F3428((ts4_word)a0, (ts4_word)(a1 + 2));
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x884F2440: if_get u16@0x18, u32@0x40, u32@0x0 */
ts4_word ts4_if_get_u16_off18_884F2440(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)(a1 & 0xffff) > (ts4_word)t1) {
        return ((2147483648) | 16389);
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((a1 & 0xffff) << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 64))));
    return 0;
}

/* Swing_DLL.xex 0x884F3398: if_get u32@0x8, u32@0xc, u32@0xc */
ts4_word ts4_if_get_u32_off8_884F3398(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)(t1 - t2) < (ts4_word)a1) {
        return ((2147942400) | 122);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t2 + a1);
    return 0;
}

/* Swing_DLL.xex 0x884F3530: if_get u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_884F3530(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    if ((ts4_word)a1 >= 64) {
        return ((2147942400) | 87);
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(((a1 << 4) + a0)) + 0);
    if ((int)(t1 & 0x80000000) != 0) {
        if ((int)(t1 & 0x40000000) == 0) {
            *(ts4_word *)((char *)(ts4_word)(((a1 << 4) + a0)) + 0) = (ts4_word)(t1 | 1073741824);
            *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((a1 << 4) + a0);
            return 0;
        }
        return ((2147483648) | 16389);
    }
    return ((2147483648) | 16389);
}

/* Swing_DLL.xex 0x884F3580: if_get  */
ts4_word ts4_if_get_884F3580(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    if ((ts4_word)a1 >= 64) {
        return ((2147942400) | 87);
    }
    if ((ts4_word)a1 == 63) {
        return 0;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)((a1 << 4)) + a0);
    if ((int)(t1 & 0x80000000) != 0) {
        if ((int)(t1 & 0x40000000) != 0) {
            *(ts4_word *)((char *)(ts4_word)((a1 << 4)) + a0) = (ts4_word)(t1 & 0xbfffffff);
            return 0;
        }
        return ((2147483648) | 16389);
    }
    return ((2147483648) | 16389);
}

/* Swing_DLL.xex 0x884F37E0: if_set u32@0x4, u32@0x24, lbl_88C2D5AC, lbl_88C2D5CC, u32@0x0 */
void ts4_if_set_u32_off4_884F37E0(ts4_word a0, ts4_word a1)
{
    ts4_word p2;
    int t1;

    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)10;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((int)t1 == 1) {
        p2 = (ts4_word)(ts4_word)lbl_88C2D5CC;
    } else {
        p2 = (ts4_word)(ts4_word)lbl_88C2D5AC;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)p2;
    return;
}

/* Swing_DLL.xex 0x884F42B8: if_call_seq u32@0x18, u32@0x24, u32@0x4c, fn_884F5F00, ts4_get_u32_offc_884F4748, fn_884F3DA0 */
ts4_word ts4_if_call_seq_u32_off18_884F42B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((int)t1 == 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)) == 1) {
        fn_884F5F00((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 76)));
    }
    t6 = ts4_get_u32_offc_884F4748((ts4_word)a0);
    if ((int)t6 < 0) {
        fn_884F3DA0((ts4_word)a0);
    }
    return t6;
}

/* Swing_DLL.xex 0x884F4408: if_tail fn_884F4328, fn_884F4328 */
ts4_word ts4_if_tail_fn_884F4328_884F4408(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((int)(a2 & 0xff) == 0) {
        return fn_884F4328((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
    }
    return fn_884F4328((ts4_word)a0, (ts4_word)a1, (ts4_word)(a2 & 0xff));
}

/* Swing_DLL.xex 0x884F4560: if_call_seq u32@0x0, lbl_8808D66C, XexGetModuleHandle, XexGetProcedureAddress */
ts4_word ts4_if_call_seq_u32_off0_884F4560(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
    t1 = XexGetModuleHandle((ts4_word)(ts4_word)lbl_8808D66C, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 >= 0) {
        t2 = loc50[0];
        t3 = XexGetProcedureAddress((ts4_word)t2, (ts4_word)a0, (ts4_word)a1);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x884F4698: if_get ts4_memset, fn_884F7A50, u32@0x0, lbl_88D27040, fn_884F4430, fn_884F44D0 */
ts4_word ts4_if_get_ts4_memset_884F4698(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[6];
    ts4_word t2;
    ts4_word t4;

    ts4_memset((ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)12);
    loc50[0] = (ts4_word)a0;
    loc50[1] = (ts4_word)a1;
    loc50[2] = (ts4_word)a2;
    t2 = fn_884F7A50((ts4_word)(ts4_word)&loc50[0], (ts4_word)a3);
    if ((int)t2 < 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
        if ((ts4_word)t4 != 0) {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 4))))((ts4_word)t4);
            *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
        }
    } else {
        *(ts4_word *)lbl_88D27040 = (ts4_word)(ts4_word)fn_884F4430;
        *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D27040) + 4) = (ts4_word)(ts4_word)fn_884F44D0;
    }
    return t2;
}

/* Swing_DLL.xex 0x884F4770: get u32@0xc, u32@0x8, u32@0x18 */
ts4_word ts4_get_u32_offc_884F4770(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(((t1 + 4) << 2)) + t2) = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x884F4C70: if_get u32@0x4, fn_884F5120 */
ts4_word ts4_if_get_u32_off4_884F4C70(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;

    if ((ts4_word)a1 == 2) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    } else {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((a1 + 2) << 2)) + a0));
    }
    return fn_884F5120((ts4_word)p4, (ts4_word)a2, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884F6370: if_call_seq RtlEnterCriticalSection, fn_884F85E8, RtlLeaveCriticalSection */
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_884F6370(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p5;
    ts4_word t2;
    ts4_word t3;

    RtlEnterCriticalSection((ts4_word)(a0 + 240));
    t2 = *(ts4_word *)((char *)(ts4_word)(((a1 + 20) << 2)) + a0);
    if ((ts4_word)t2 == 0) {
        p5 = (ts4_word)((2147942400) | 87);
    } else {
        t3 = fn_884F85E8((ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
        p5 = (ts4_word)t3;
    }
    RtlLeaveCriticalSection((ts4_word)(a0 + 240));
    return p5;
}

/* Swing_DLL.xex 0x884F63E0: if_call_seq RtlEnterCriticalSection, fn_884F8700, RtlLeaveCriticalSection */
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_884F63E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p5;
    ts4_word t2;
    ts4_word t3;

    RtlEnterCriticalSection((ts4_word)(a0 + 240));
    t2 = *(ts4_word *)((char *)(ts4_word)(((a1 + 20) << 2)) + a0);
    if ((ts4_word)t2 == 0) {
        p5 = (ts4_word)((2147942400) | 87);
    } else {
        t3 = fn_884F8700((ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
        p5 = (ts4_word)t3;
    }
    RtlLeaveCriticalSection((ts4_word)(a0 + 240));
    return p5;
}

/* Swing_DLL.xex 0x884F6518: call_seq RtlEnterCriticalSection, fn_884F84A8, RtlLeaveCriticalSection */
ts4_word ts4_call_seq_RtlEnterCriticalSection_884F6518(ts4_word a0, ts4_word a1)
{
    RtlEnterCriticalSection((ts4_word)(a0 + 240));
    fn_884F84A8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(((a1 + 20) << 2)) + a0)));
    RtlLeaveCriticalSection((ts4_word)(a0 + 240));
    return 0;
}

/* Swing_DLL.xex 0x884F65F0: if_call_seq RtlEnterCriticalSection, u32@lbl_8808D674, fn_884F8A90, RtlLeaveCriticalSection */
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_884F65F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p6;
    ts4_word t2;
    ts4_word t4;

    RtlEnterCriticalSection((ts4_word)(a0 + 240));
    t2 = *(ts4_word *)((char *)(ts4_word)(((a1 + 20) << 2)) + a0);
    if ((ts4_word)t2 == 0) {
        p6 = (ts4_word)((2147942400) | 87);
    } else {
        t4 = fn_884F8A90((ts4_word)t2, (ts4_word)(*(ts4_word *)lbl_8808D674), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
        p6 = (ts4_word)t4;
    }
    RtlLeaveCriticalSection((ts4_word)(a0 + 240));
    return p6;
}

/* Swing_DLL.xex 0x884F7168: if_call_seq RtlEnterCriticalSection, fn_884F6858, fn_884FAFC0, RtlLeaveCriticalSection */
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_884F7168(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p5;
    ts4_word t2;
    ts4_word t3;

    RtlEnterCriticalSection((ts4_word)(a0 + 240));
    t2 = fn_884F6858((ts4_word)a0, (ts4_word)a1);
    if ((ts4_word)t2 == 0) {
        p5 = (ts4_word)((2147942400) | 87);
    } else {
        t3 = fn_884FAFC0((ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
        p5 = (ts4_word)t3;
    }
    RtlLeaveCriticalSection((ts4_word)(a0 + 240));
    return p5;
}

/* Swing_DLL.xex 0x884F71D8: if_call_seq RtlEnterCriticalSection, fn_884F6858, fn_884FB038, RtlLeaveCriticalSection */
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_884F71D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p5;
    ts4_word t2;
    ts4_word t3;

    RtlEnterCriticalSection((ts4_word)(a0 + 240));
    t2 = fn_884F6858((ts4_word)a0, (ts4_word)a1);
    if ((ts4_word)t2 == 0) {
        p5 = (ts4_word)((2147942400) | 87);
    } else {
        t3 = fn_884FB038((ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
        p5 = (ts4_word)t3;
    }
    RtlLeaveCriticalSection((ts4_word)(a0 + 240));
    return p5;
}

/* Swing_DLL.xex 0x884F7350: if_call_seq RtlEnterCriticalSection, fn_884F6858, fn_884FB178, RtlLeaveCriticalSection */
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_884F7350(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t2;
    ts4_word t3;

    RtlEnterCriticalSection((ts4_word)(a0 + 240));
    t2 = fn_884F6858((ts4_word)a0, (ts4_word)a1);
    if ((ts4_word)t2 == 0) {
        p5 = (ts4_word)((2147942400) | 87);
    } else {
        t3 = fn_884FB178((ts4_word)t2);
        p5 = (ts4_word)t3;
    }
    RtlLeaveCriticalSection((ts4_word)(a0 + 240));
    return p5;
}

/* Swing_DLL.xex 0x884F7540: if_call_seq RtlEnterCriticalSection, fn_884F6858, fn_884FA5E0, RtlLeaveCriticalSection */
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_884F7540(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p5;
    ts4_word t2;
    ts4_word t3;

    RtlEnterCriticalSection((ts4_word)(a0 + 240));
    t2 = fn_884F6858((ts4_word)a0, (ts4_word)a1);
    if ((ts4_word)t2 == 0) {
        p5 = (ts4_word)((2147942400) | 87);
    } else {
        t3 = fn_884FA5E0((ts4_word)t2, (ts4_word)a2);
        p5 = (ts4_word)t3;
    }
    RtlLeaveCriticalSection((ts4_word)(a0 + 240));
    return p5;
}

/* Swing_DLL.xex 0x884F75A8: if_call_seq RtlEnterCriticalSection, fn_884F6858, ts4_if_get_u32_off48_884FA700, RtlLeaveCriticalSection */
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_884F75A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p5;
    ts4_word t2;
    ts4_word t3;

    RtlEnterCriticalSection((ts4_word)(a0 + 240));
    t2 = fn_884F6858((ts4_word)a0, (ts4_word)a1);
    if ((ts4_word)t2 == 0) {
        p5 = (ts4_word)((2147942400) | 87);
    } else {
        t3 = ts4_if_get_u32_off48_884FA700((ts4_word)t2, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
        p5 = (ts4_word)t3;
    }
    RtlLeaveCriticalSection((ts4_word)(a0 + 240));
    return p5;
}

/* Swing_DLL.xex 0x884F7788: if_call_seq RtlEnterCriticalSection, fn_884F6858, ts4_if_get_u32_off8_884FB300, RtlLeaveCriticalSection */
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_884F7788(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p5;
    ts4_word t2;
    ts4_word t3;

    RtlEnterCriticalSection((ts4_word)(a0 + 240));
    t2 = fn_884F6858((ts4_word)a0, (ts4_word)a1);
    if ((ts4_word)t2 == 0) {
        p5 = (ts4_word)((2147942400) | 87);
    } else {
        t3 = ts4_if_get_u32_off8_884FB300((ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
        p5 = (ts4_word)t3;
    }
    RtlLeaveCriticalSection((ts4_word)(a0 + 240));
    return p5;
}

/* Swing_DLL.xex 0x884F77F8: if_call_seq RtlEnterCriticalSection, fn_884F6858, fn_884FB288, RtlLeaveCriticalSection */
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_884F77F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p5;
    ts4_word t2;
    ts4_word t3;

    RtlEnterCriticalSection((ts4_word)(a0 + 240));
    t2 = fn_884F6858((ts4_word)a0, (ts4_word)a1);
    if ((ts4_word)t2 == 0) {
        p5 = (ts4_word)((2147942400) | 87);
    } else {
        t3 = fn_884FB288((ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
        p5 = (ts4_word)t3;
    }
    RtlLeaveCriticalSection((ts4_word)(a0 + 240));
    return p5;
}

/* Swing_DLL.xex 0x884F7DD0: if_call_seq u32@0x0, XamUserGetDeviceContext */
ts4_word ts4_if_call_seq_u32_off0_884F7DD0(ts4_word a0)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t3;

    t2 = XamUserGetDeviceContext((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)1, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t2 < 0) {
        p4 = (ts4_word)0;
    } else {
        t3 = loc50[0];
        p4 = (ts4_word)(t3 & 0xf0000000);
    }
    return p4;
}

/* Swing_DLL.xex 0x884F9E48: get u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_884F9E48(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
}

/* Swing_DLL.xex 0x884FA380: if_call_seq lbl_8808D7C4, u32@0x0, ts4_if_call_seq_u32_offc_88596808, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0 */
ts4_word ts4_if_call_seq_lbl_8808D7C4_884FA380(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808D7C4;
    ts4_if_call_seq_u32_offc_88596808();
    if ((int)(a1 & 0x1) != 0) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)a0, (ts4_word)((1619656704) | 8194));
    }
    return a0;
}

/* Swing_DLL.xex 0x88501990: if_call_seq u32@0x18, u32@0x0, lbl_8808D66C, u32@0x4, fn_8857A068, u32@0x18 */
ts4_word ts4_if_call_seq_u32_off18_88501990(ts4_word a0)
{
    ts4_word p19;
    ts4_word p20;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t6;
    ts4_word t8;
    ts4_word t10;
    ts4_word t12;
    ts4_word t13;
    ts4_word t18;

    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    t1 = fn_8857A068((ts4_word)(ts4_word)lbl_8808D66C);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t1;
    p20 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_88579FF8((ts4_word)t1, (ts4_word)2815);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t2;
        t4 = fn_88579FF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)2816);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t4;
        t6 = fn_88579FF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)2827);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t6;
        t8 = fn_88579FF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)2832);
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t8;
        t10 = fn_88579FF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)773);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t10;
        t12 = fn_88579FF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)779);
        t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t12;
        p19 = (ts4_word)t12;
        if ((((((ts4_word)t13 == 0 || (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)) == 0) || (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)) == 0) || (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)) == 0) || (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)) == 0) || (ts4_word)t12 == 0) {
            t18 = ts4_if_call_seq_u32_off18_885018B0((ts4_word)a0);
            p19 = (ts4_word)t18;
        }
        p20 = (ts4_word)p19;
    }
    return p20;
}

/* Swing_DLL.xex 0x88562ED0: get u32@lbl_88C30BE0, u32@lbl_88C30BE0 */
ts4_word ts4_get_u32_lbl_88C30BE0_88562ED0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88C30BE0;
    *(ts4_word *)lbl_88C30BE0 = (ts4_word)((t1 & ~a1) | (a0 & a1));
    return t1;
}

/* Swing_DLL.xex 0x885647A8: loop_get u16@0x0 */
ts4_word ts4_loop_get_u16_off0_885647A8(ts4_word a0)
{
    ts4_word lv1;
    ts4_word p3;
    unsigned short t2;

    lv1 = (ts4_word)a0;
    do {
        t2 = *(unsigned short *)((char *)(ts4_word)(lv1) + 0);
        p3 = (ts4_word)(lv1 + 2);
        lv1 = p3;
    } while ((ts4_word)t2 != 0);
    return (((int)(lv1 - a0) >> 1) + -1);
}

/* Swing_DLL.xex 0x88565B10: if_call_seq u32@0xc, ts4_if_call_seq_fn_8856CD88_88567ED8, u32@0x0, fn_8856D2C0 */
ts4_word ts4_if_call_seq_u32_offc_88565B10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 == 0) {
        t2 = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)22;
        fn_8856D2C0((ts4_word)t2);
        p4 = (ts4_word)0;
    } else {
        p4 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) & 0x10);
    }
    return p4;
}

/* Swing_DLL.xex 0x88565B58: if_call_seq u32@0xc, ts4_if_call_seq_fn_8856CD88_88567ED8, u32@0x0, fn_8856D2C0 */
ts4_word ts4_if_call_seq_u32_offc_88565B58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 == 0) {
        t2 = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)22;
        fn_8856D2C0((ts4_word)t2);
        p4 = (ts4_word)0;
    } else {
        p4 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) & 0x20);
    }
    return p4;
}

/* Swing_DLL.xex 0x88567810: addr lbl_88C317A0, u32@0xc8 */
ts4_word ts4_addr_lbl_88C317A0_88567810(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C317A0) + 200)))) & 259);
}

/* Swing_DLL.xex 0x88567830: addr lbl_88C317A0, u32@0xc8 */
ts4_word ts4_addr_lbl_88C317A0_88567830(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C317A0) + 200)))) & 0x4);
}

/* Swing_DLL.xex 0x88567850: addr lbl_88C317A0, u32@0xc8 */
ts4_word ts4_addr_lbl_88C317A0_88567850(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C317A0) + 200)))) & 0x80);
}

/* Swing_DLL.xex 0x88567870: addr lbl_88C317A0, u32@0xc8 */
ts4_word ts4_addr_lbl_88C317A0_88567870(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C317A0) + 200)))) & 0x8);
}

/* Swing_DLL.xex 0x88567890: addr lbl_88C317A0, u32@0xc8 */
ts4_word ts4_addr_lbl_88C317A0_88567890(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C317A0) + 200)))) & 263);
}

/* Swing_DLL.xex 0x885678B0: addr lbl_88C317A0, u32@0xc8 */
ts4_word ts4_addr_lbl_88C317A0_885678B0(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C317A0) + 200)))) & 343);
}

/* Swing_DLL.xex 0x88567D00: if_call_seq ts4_tailcall_fn_88566C60_88566F38, u8@lbl_88D2E534, fn_88574618, u32@lbl_88D4E104, fn_885651F8 */
ts4_word ts4_if_call_seq_fn_88566F38_88567D00(void)
{
    ts4_word t1;
    unsigned char t2;
    ts4_word t6;

    t1 = ts4_tailcall_fn_88566C60_88566F38();
    t2 = *(unsigned char *)lbl_88D2E534;
    if ((ts4_word)t2 != 0) {
        fn_88574618((ts4_word)t1);
    }
    t6 = fn_885651F8((ts4_word)(*(ts4_word *)lbl_88D4E104));
    return t6;
}

/* Swing_DLL.xex 0x88567D40: if_call_seq lbl_88C30DA8, RtlEnterCriticalSection, fn_8856F7D8, u32@0xc, u32@0xc */
ts4_word ts4_if_call_seq_lbl_88C30DA8_88567D40(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t1;

    if ((ts4_word)a0 >= (ts4_word)(ts4_word)lbl_88C30DA8 && (ts4_word)a0 <= (ts4_word)((ts4_word)lbl_88C30DA8 + 608)) {
        t2 = fn_8856F7D8((ts4_word)(((int)(a0 - (ts4_word)lbl_88C30DA8) >> 5) + 16));
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) | 32768);
        p4 = (ts4_word)t2;
    } else {
        t1 = RtlEnterCriticalSection((ts4_word)(a0 + 32));
        p4 = (ts4_word)t1;
    }
    return p4;
}

/* Swing_DLL.xex 0x88567DB0: if_call_seq RtlEnterCriticalSection, fn_8856F7D8, u32@0xc, u32@0xc */
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_88567DB0(int a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t1;

    if ((int)a0 < 20) {
        t2 = fn_8856F7D8((ts4_word)(a0 + 16));
        *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 12)) | 32768);
        p4 = (ts4_word)t2;
    } else {
        t1 = RtlEnterCriticalSection((ts4_word)(a1 + 32));
        p4 = (ts4_word)t1;
    }
    return p4;
}

/* Swing_DLL.xex 0x88567E40: if_tail RtlLeaveCriticalSection, u32@0xc, u32@0xc, ts4_addr_lbl_88C31510_8856F558 */
ts4_word ts4_if_tail_RtlLeaveCriticalSection_88567E40(int a0, ts4_word a1)
{
    if ((int)a0 < 20) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 12)) & 0xffff7fff);
        return ts4_addr_lbl_88C31510_8856F558((ts4_word)(a0 + 16), (ts4_word)a1);
    }
    return RtlLeaveCriticalSection((ts4_word)(a1 + 32), (ts4_word)a1);
}

/* Swing_DLL.xex 0x88567F10: if_call_seq fn_8856CD88, lbl_88C31194 */
ts4_word ts4_if_call_seq_fn_8856CD88_88567F10(void)
{
    ts4_word p2;
    ts4_word t1;

    t1 = fn_8856CD88();
    if ((ts4_word)t1 == 0) {
        p2 = (ts4_word)(ts4_word)lbl_88C31194;
    } else {
        p2 = (ts4_word)(t1 + 12);
    }
    return p2;
}

/* Swing_DLL.xex 0x88567FD8: if_get u32@lbl_88C31878, u32@0xc8 */
ts4_word ts4_if_get_u32_lbl_88C31878_88567FD8(int a0, ts4_word a1)
{
    if ((int)a0 >= -1 && (int)a0 <= 255) {
        return ((*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88C31878)) + 200))) + (a0 << 1))) & a1);
    }
    return 0;
}

/* Swing_DLL.xex 0x88568010: addr lbl_88C317A0, u32@0xc8 */
ts4_word ts4_addr_lbl_88C317A0_88568010(ts4_word a0, ts4_word a1)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C317A0) + 200)))) & a1);
}

/* Swing_DLL.xex 0x8856A0C8: loop_get u16@0x0 */
void ts4_loop_get_u16_off0_8856A0C8(ts4_word a0, ts4_word a1)
{
    ts4_word lv1;
    ts4_word p3;
    unsigned short t2;

    lv1 = (ts4_word)a1;
    do {
        t2 = *(unsigned short *)((char *)(ts4_word)(lv1) + 0);
        *(unsigned short *)((char *)(ts4_word)((a0 - a1)) + lv1) = (unsigned short)t2;
        p3 = (ts4_word)(lv1 + 2);
        lv1 = p3;
    } while ((ts4_word)t2 != 0);
    return;
}

/* Swing_DLL.xex 0x8856C270: get u32@lbl_88C31A98, u32@lbl_88D2E588 */
ts4_word ts4_get_u32_lbl_88C31A98_8856C270(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88C31A98;
    return (((t1 | 1) - (*(ts4_word *)lbl_88D2E588)) == 0);
}

/* Swing_DLL.xex 0x8856C3E0: if_call_seq u32@0x10, ts4_if_call_seq_fn_8856CD88_88567ED8, u32@0x0, fn_8856D2C0 */
ts4_word ts4_if_call_seq_u32_off10_8856C3E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 == 0) {
        t2 = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)22;
        fn_8856D2C0((ts4_word)t2);
        p4 = (ts4_word)-1;
    } else {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16));
    }
    return p4;
}

/* Swing_DLL.xex 0x8856C420: if_call_seq lbl_8808F790, u32@0x0, fn_885775E8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_8808F790_8856C420(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808F790;
    fn_885775E8((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8856CD68: addr lbl_8808F798, u32@0x8, u32@0x5c, u32@0x14 */
void ts4_addr_lbl_8808F798_8856CD68(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)(ts4_word)lbl_8808F798;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)1;
    return;
}

/* Swing_DLL.xex 0x8856CE60: if_call_seq fn_8856CD88, fn_88564400 */
ts4_word ts4_if_call_seq_fn_8856CD88_8856CE60(void)
{
    ts4_word t1;

    t1 = fn_8856CD88();
    if ((int)t1 == 0) {
        fn_88564400((ts4_word)16);
    }
    return t1;
}

/* Swing_DLL.xex 0x8856D868: if_call_seq fn_8856D820, ts4_if_call_seq_RtlInitUnicodeString_88582BD0 */
ts4_word ts4_if_call_seq_fn_8856D820_8856D868(ts4_word a0)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = fn_8856D820((ts4_word)a0);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_if_call_seq_RtlInitUnicodeString_88582BD0((ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x8856D898: if_call_seq fn_8856D820, ts4_if_call_seq_RtlInitUnicodeString_88582BD0, fn_8856D820, ts4_if_call_seq_RtlInitUnicodeString_88582BD0 */
ts4_word ts4_if_call_seq_fn_8856D820_8856D898(void)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    t1 = fn_8856D820((ts4_word)252);
    if ((ts4_word)t1 != 0) {
        ts4_if_call_seq_RtlInitUnicodeString_88582BD0((ts4_word)t1);
    }
    t4 = fn_8856D820((ts4_word)255);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_if_call_seq_RtlInitUnicodeString_88582BD0((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x8856EFD8: if_call_seq ts4_if_call_seq_fn_8856CD88_88567ED8, u32@0x0, ts4_if_call_seq_fn_8856CD88_88567ED8, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88567ED8_8856EFD8(int a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word p4;
    ts4_word t2;
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)a0 != 1) {
        p3 = (ts4_word)a0;
        if ((int)a0 > 1 && (int)a0 <= 3) {
            t2 = ts4_if_call_seq_fn_8856CD88_88567ED8();
            *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)34;
            p3 = (ts4_word)t2;
        }
        p4 = (ts4_word)p3;
    } else {
        t1 = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)33;
        p4 = (ts4_word)t1;
    }
    return p4;
}

/* Swing_DLL.xex 0x8856F020: if_fn  */
ts4_word ts4_if_fn_8856F020(ts4_word a0)
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

/* Swing_DLL.xex 0x8856F4E8: loop_call_seq lbl_88C31510, u32@0x0, u32@0x4, fn_885651F8, u32@0x0 */
ts4_word ts4_loop_call_seq_lbl_88C31510_8856F4E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p5;
    ts4_word p6;
    ts4_word t2;
    ts4_word t4;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    lv1 = (ts4_word)(ts4_word)lbl_88C31510;
    do {
        t2 = *(ts4_word *)((char *)(ts4_word)(lv1) + 0);
        p5 = (ts4_word)t2;
        if ((ts4_word)t2 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(lv1) + 4)) != 1) {
            t4 = fn_885651F8((ts4_word)t2);
            *(ts4_word *)((char *)(ts4_word)(lv1) + 0) = (ts4_word)0;
            p5 = (ts4_word)t4;
        }
        p6 = (ts4_word)(lv1 + 8);
        lv1 = p6;
    } while ((int)p6 < (int)((ts4_word)lbl_88C31510 + 288));
    return p5;
}

/* Swing_DLL.xex 0x88570CF8: if_call_seq u32@0xc, fn_88566B48, u32@0x18, u32@0x0, u32@0x8, u32@0xc */
ts4_word ts4_if_call_seq_u32_offc_88570CF8(int a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    if ((int)a0 != 0) {
        t1 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 12);
        p5 = (ts4_word)a0;
        if ((int)(t1 & 0x1000) != 0) {
            t2 = fn_88566B48((ts4_word)a1);
            *(volatile ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)0;
            *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
            *(volatile ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)0;
            *(volatile ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)(((*(volatile ts4_word *)((char *)(ts4_word)(a1) + 12)) & 0xfffffeff) & 0xffffefff);
            p5 = (ts4_word)t2;
        }
        p6 = (ts4_word)p5;
    }
    return p6;
}

/* Swing_DLL.xex 0x885758F0: if_call_seq u32@0xc, u32@0x8, fn_88576488, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_u32_offc_885758F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word p7;
    ts4_word p8;
    ts4_word t1;
    ts4_word t3;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    if ((int)(t1 & 0x40) == 0 || (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8)) != 0) {
        t3 = fn_88576488();
        if ((ts4_word)(t3 & 0xffff) == 65535) {
            p5 = (ts4_word)-1;
        } else {
            p5 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0)) + 1);
        }
        p7 = (ts4_word)p5;
        p8 = (ts4_word)t3;
    } else {
        p7 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0)) + 1);
        p8 = (ts4_word)a0;
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)p7;
    return p8;
}

/* Swing_DLL.xex 0x885766E0: addr lbl_88C31A60, u32@0x4, u32@0xc, u32@0x8 */
void ts4_addr_lbl_88C31A60_885766E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C31A60) + 4) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C31A60) + 12) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C31A60) + 8) = (ts4_word)a2;
    return;
}

/* Swing_DLL.xex 0x88578B98: if_get u8@0x0, u8@0x0, u16@0x0, u16@0x0 */
ts4_word ts4_if_get_u8_off0_88578B98(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned char t2;

    if ((ts4_word)a1 != 0 && (ts4_word)a2 != 0) {
        t2 = *(unsigned char *)((char *)(ts4_word)(a1) + 0);
        if ((ts4_word)t2 == 0) {
            if ((ts4_word)a0 != 0) {
                *(unsigned short *)((char *)(ts4_word)(a0) + 0) = (unsigned short)0;
            }
            return 0;
        }
        if ((ts4_word)a0 != 0) {
            *(unsigned short *)((char *)(ts4_word)(a0) + 0) = (unsigned short)(t2 & 0xff);
        }
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x88579FC0: if_call_seq XexUnloadImage, ts4_forward_record_status */
ts4_word ts4_if_call_seq_XexUnloadImage_88579FC0(void)
{
    ts4_word p3;
    int t1;

    t1 = XexUnloadImage();
    if ((int)t1 < 0) {
        ts4_forward_record_status((ts4_word)t1);
        p3 = (ts4_word)0;
    } else {
        p3 = (ts4_word)1;
    }
    return p3;
}

/* Swing_DLL.xex 0x8857A0B0: if_call_seq XexGetModuleSection, ts4_forward_record_status */
ts4_word ts4_if_call_seq_XexGetModuleSection_8857A0B0(void)
{
    ts4_word p3;
    int t1;

    t1 = XexGetModuleSection();
    if ((int)t1 < 0) {
        ts4_forward_record_status((ts4_word)t1);
        p3 = (ts4_word)0;
    } else {
        p3 = (ts4_word)1;
    }
    return p3;
}

/* Swing_DLL.xex 0x8857A1E0: if_get u32@lbl_88C32048, u32@0x4, vcall, ts4_record_status */
ts4_word ts4_if_get_u32_lbl_88C32048_8857A1E0(ts4_word a0)
{
    ts4_word p5;
    int t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88C32048)) + 4))))((ts4_word)a0);
    if ((int)t3 >= 0) {
        p5 = (ts4_word)1;
    } else {
        ts4_record_status((ts4_word)t3);
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Swing_DLL.xex 0x8857A5D8: if_call_seq fn_88582680, XamUserCreateStatsEnumerator */
ts4_word ts4_if_call_seq_fn_88582680_8857A5D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = fn_88582680((ts4_word)a0);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        t2 = XamUserCreateStatsEnumerator((ts4_word)a0, (ts4_word)0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x8857A748: if_call_seq u32@0x4, ts4_forward_runtime_b3360, u32@0x8, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0 */
ts4_word ts4_if_call_seq_u32_off4_8857A748(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word p6;
    int t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p3 = (ts4_word)a0;
    if ((int)t1 == 1) {
        t2 = ts4_forward_runtime_b3360();
        p3 = (ts4_word)t2;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p6 = (ts4_word)p3;
    if ((int)(t4 & 0x40000000) != 0) {
        t5 = ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)a0, (ts4_word)(612564992));
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x8857B0D0: if_call_seq u32@lbl_88D2E878, MmAllocatePhysicalMemoryEx, ts4_call_runtime_2610 */
ts4_word ts4_if_call_seq_u32_lbl_88D2E878_8857B0D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p2;
    int t1;
    ts4_word t3;

    t1 = *(volatile ts4_word *)lbl_88D2E878;
    p2 = (ts4_word)a4;
    if ((int)t1 != 0) {
        p2 = (ts4_word)(a4 & 0xdfffffff);
    }
    t3 = MmAllocatePhysicalMemoryEx((ts4_word)0, (ts4_word)a0, (ts4_word)p2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    if ((int)t3 == 0) {
        ts4_call_runtime_2610((ts4_word)8);
    }
    return t3;
}

/* Swing_DLL.xex 0x8857C040: if_call_seq NtReleaseSemaphore, ts4_forward_record_status */
ts4_word ts4_if_call_seq_NtReleaseSemaphore_8857C040(void)
{
    ts4_word p3;
    int t1;

    t1 = NtReleaseSemaphore();
    if ((int)t1 >= 0) {
        p3 = (ts4_word)1;
    } else {
        ts4_forward_record_status((ts4_word)t1);
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Swing_DLL.xex 0x8857C238: if_get u32@0x8, ts4_if_get_u32_off0_885846C0, u32@0xc, u32@lbl_88C32048, u32@0x10, vcall */
ts4_word ts4_if_get_u32_off8_8857C238(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p7;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a3) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a3) + 12);
    loc50[1] = (ts4_word)t1;
    loc50[0] = (ts4_word)t2;
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88C32048)) + 16))))((ts4_word)a0, (ts4_word)0, (ts4_word)((ts4_word)ts4_if_get_u32_off0_885846C0 | 1), (ts4_word)a4, (ts4_word)a3, (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)(t5 & 0xc0000000) == (ts4_word)(3221225472)) {
        ts4_forward_record_status((ts4_word)t5);
        p7 = (ts4_word)0;
    } else {
        p7 = (ts4_word)1;
    }
    return p7;
}

/* Swing_DLL.xex 0x8857C2C8: if_call_seq u32@0x0, u32@0x4, u32@0x0, u32@0x0, ts4_record_status, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off0_8857C2C8(ts4_word a0, ts4_word a1, ts4_word a2, int a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word p8;
    ts4_word p10;
    ts4_word p14;
    ts4_word p15;
    ts4_word p17;
    ts4_word p18;
    ts4_word t1;
    ts4_word t7;
    ts4_word t9;
    int t12;
    int t3;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 == 259) {
        if ((int)a3 != 0) {
            t7 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
            p8 = (ts4_word)a0;
            if ((ts4_word)t7 != 0) {
                p8 = (ts4_word)t7;
            }
            t9 = ts4_tailcall_fn_88582F30_8857A128((ts4_word)p8, (ts4_word)-1);
            p10 = (ts4_word)t9;
        } else {
            p10 = (ts4_word)258;
        }
        if ((ts4_word)p10 == 258) {
            ts4_call_runtime_2610((ts4_word)996);
            p17 = (ts4_word)0;
        } else {
            if ((ts4_word)p10 == 0) {
                *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
                t12 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
                if ((int)t12 >= 0) {
                    p14 = (ts4_word)1;
                } else {
                    ts4_record_status((ts4_word)t12);
                    p14 = (ts4_word)0;
                }
                p15 = (ts4_word)p14;
            } else {
                p15 = (ts4_word)0;
            }
            p17 = (ts4_word)p15;
        }
        p18 = (ts4_word)p17;
    } else {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        if ((int)t3 >= 0) {
            p5 = (ts4_word)1;
        } else {
            ts4_record_status((ts4_word)t3);
            p5 = (ts4_word)0;
        }
        p18 = (ts4_word)p5;
    }
    return p18;
}

/* Swing_DLL.xex 0x8857C370: if_call_seq RtlInitAnsiString, NtQueryFullAttributesFile, ts4_record_status */
ts4_word ts4_if_call_seq_RtlInitAnsiString_8857C370(ts4_word a0)
{
    ts4_word p5;
    ts4_word loc50[1];
    ts4_word loc58[3];
    ts4_word loc70[13];
    int t2;
    ts4_word t4;

    RtlInitAnsiString((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    loc58[0] = (ts4_word)-3;
    loc58[2] = (ts4_word)64;
    loc58[1] = (ts4_word)(ts4_word)&loc50[0];
    t2 = NtQueryFullAttributesFile((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc70[0]);
    if ((int)t2 >= 0) {
        t4 = loc70[12];
        p5 = (ts4_word)t4;
    } else {
        ts4_record_status((ts4_word)t2);
        p5 = (ts4_word)-1;
    }
    return p5;
}

/* Swing_DLL.xex 0x8857C468: if_call_seq ts4_if_get_u32_lbl_88C32048_885844E8, fn_88584728, ts4_record_status */
ts4_word ts4_if_call_seq_fn_885844E8_8857C468(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word loc50[84];
    int t1;

    t1 = ts4_if_get_u32_lbl_88C32048_885844E8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)328);
    if ((int)t1 < 0) {
        ts4_record_status((ts4_word)t1);
        p4 = (ts4_word)0;
    } else {
        fn_88584728((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
        p4 = (ts4_word)1;
    }
    return p4;
}

/* Swing_DLL.xex 0x8857D138: loop_call_seq lbl_88091314, fn_8857D080, u32@__imp_XexExecutableModuleHandle, u32@0x0, u16@0x2c, u32@__imp_XexExecutableModuleHandle */
ts4_word ts4_loop_call_seq_lbl_88091314_8857D138(ts4_word a0)
{
    ts4_word lv8;
    ts4_word p12;
    ts4_word p14;
    ts4_word p16;
    ts4_word loc50[128];
    int t1;
    ts4_word t6;
    unsigned short t7;
    unsigned short t11;
    ts4_word t15;

    t1 = fn_8857D080((ts4_word)(ts4_word)lbl_88091314, (ts4_word)12, (ts4_word)a0);
    if ((int)t1 != 0) {
        p16 = (ts4_word)1;
    } else {
        t6 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_XexExecutableModuleHandle)) + 0);
        t7 = *(unsigned short *)((char *)(ts4_word)(t6) + 44);
        p14 = (ts4_word)t7;
        if ((ts4_word)t7 != 0) {
            lv8 = (ts4_word)0;
            do {
                *(unsigned char *)((char *)(ts4_word)(lv8) + (ts4_word)&loc50[0]) = (unsigned char)(*(unsigned short *)((char *)(ts4_word)((lv8 << 1)) + (*(ts4_word *)((char *)(ts4_word)(t6) + 48))));
                t11 = *(unsigned short *)((char *)(ts4_word)(t6) + 44);
                p12 = (ts4_word)((lv8 + 1) & 0xffff);
                lv8 = p12;
            } while ((ts4_word)p12 < (ts4_word)t11);
            p14 = (ts4_word)t11;
        }
        t15 = fn_8857D080((ts4_word)(ts4_word)&loc50[0], (ts4_word)p14, (ts4_word)a0);
        p16 = (ts4_word)(t15 != 0);
    }
    return p16;
}

/* Swing_DLL.xex 0x8857EC08: if_call_seq u32@0x14, u32@0x20, NtFreeVirtualMemory */
ts4_word ts4_if_call_seq_u32_off14_8857EC08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((int)(t1 & 0x1) == 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        loc50[0] = (ts4_word)0;
        loc54[0] = (ts4_word)t2;
        t3 = NtFreeVirtualMemory((ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)((0) | 32768), (ts4_word)a1);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x88581FD0: if_call_seq NtDuplicateObject, ts4_record_status */
ts4_word ts4_if_call_seq_NtDuplicateObject_88581FD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p3;
    int t1;

    (void)a0;
    (void)a2;
    (void)a4;
    (void)a5;
    t1 = NtDuplicateObject((ts4_word)a1, (ts4_word)a3, (ts4_word)a6);
    if ((int)t1 >= 0) {
        p3 = (ts4_word)1;
    } else {
        ts4_record_status((ts4_word)t1);
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Swing_DLL.xex 0x885826F8: if_call_seq NtClearEvent, ts4_record_status */
ts4_word ts4_if_call_seq_NtClearEvent_885826F8(void)
{
    ts4_word p3;
    int t1;

    t1 = NtClearEvent();
    if ((int)t1 >= 0) {
        p3 = (ts4_word)1;
    } else {
        ts4_record_status();
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Swing_DLL.xex 0x88582900: call_seq NtYieldExecution */
ts4_word ts4_call_seq_NtYieldExecution_88582900(void)
{
    ts4_word t1;

    t1 = NtYieldExecution();
    return ((((1073741824) | 36) - t1) != 0);
}

/* Swing_DLL.xex 0x88582D30: if_call_seq lbl_88C31FF4, RtlEnterCriticalSection, u32@0x0, u32@0x4, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_lbl_88C31FF4_88582D30(ts4_word a0, int a1)
{
    ts4_word t4;
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;

    RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_88C31FF4);
    if ((int)a1 != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C32010) + 4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88C32010;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t4;
        *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)a0;
        *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C32010) + 4) = (ts4_word)a0;
    } else {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)t2;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)t3;
    }
    t7 = RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_88C31FF4);
    return t7;
}

/* Swing_DLL.xex 0x885850F0: if_call_seq u32@0x18, KeEnterCriticalRegion, RtlEnterCriticalSection, u8@0xcb, u32@0x2c, u8@0xcb */
ts4_word ts4_if_call_seq_u32_off18_885850F0(ts4_word a0)
{
    ts4_word p8;
    ts4_word p11;
    ts4_word t1;
    unsigned char t4;
    ts4_word t5;
    ts4_word t9;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    KeEnterCriticalRegion();
    RtlEnterCriticalSection((ts4_word)t1);
    t4 = *(unsigned char *)((char *)(ts4_word)(t1) + 203);
    if ((ts4_word)t4 == 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(t1) + 44);
        *(unsigned char *)((char *)(ts4_word)(t1) + 203) = (unsigned char)1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 136) = (ts4_word)((3221225472) | 622);
        NtClose((ts4_word)t5);
        *(ts4_word *)((char *)(ts4_word)(t1) + 44) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 52) = (ts4_word)0;
        p8 = (ts4_word)0;
    } else {
        p8 = (ts4_word)((3221225472) | 622);
    }
    t9 = RtlLeaveCriticalSection((ts4_word)t1);
    p11 = (ts4_word)t9;
    if ((int)p8 >= 0) {
        t10 = IoDeleteDevice((ts4_word)a0);
        p11 = (ts4_word)t10;
    }
    KeLeaveCriticalRegion((ts4_word)p11);
    return p8;
}

/* Swing_DLL.xex 0x885851E0: if_call_seq ExAllocatePoolTypeWithTag, memset, u32@0x10, u8@0x35, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_ExAllocatePoolTypeWithTag_885851E0(ts4_word a0)
{
    ts4_word t1;

    t1 = ExAllocatePoolTypeWithTag((ts4_word)120, (ts4_word)((1665531904) | 29779), (ts4_word)((a0 == 0) + 1));
    if ((int)t1 != 0) {
        memset((ts4_word)t1, (ts4_word)0, (ts4_word)120);
        *(ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)1;
        if ((ts4_word)a0 != 0) {
            *(unsigned char *)((char *)(ts4_word)(t1) + 53) = (unsigned char)1;
        }
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 36) = (ts4_word)-1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 40) = (ts4_word)-1;
    }
    return t1;
}

/* Swing_DLL.xex 0x88587360: if_call_seq u32@0x50, u32@0x18, u32@0xc, ExFreePool, RtlEnterCriticalSection, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off50_88587360(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;
    ts4_word t13;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 80))) + 24);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 12);
    if ((ts4_word)t3 != 0) {
        ExFreePool((ts4_word)t3);
    }
    RtlEnterCriticalSection((ts4_word)a0);
    t7 = *(ts4_word *)((char *)(ts4_word)(t2) + 8);
    if ((ts4_word)t7 != 0) {
        fn_885854A0((ts4_word)t7);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(t2) + 80);
    t11 = *(ts4_word *)((char *)(ts4_word)(t2) + 84);
    *(ts4_word *)((char *)(ts4_word)(t11) + 0) = (ts4_word)t10;
    *(ts4_word *)((char *)(ts4_word)(t10) + 4) = (ts4_word)t11;
    RtlLeaveCriticalSection((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)0;
    t13 = IoCompleteRequest((ts4_word)a1, (ts4_word)1);
    return t13;
}

/* Swing_DLL.xex 0x88589DD0: if_call_seq u32@0x50, u32@0x18, u32@0x8, RtlEnterCriticalSection, IoRemoveShareAccess, u32@0x88 */
ts4_word ts4_if_call_seq_u32_off50_88589DD0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    int t6;
    unsigned char t8;
    int t11;
    unsigned char t12;
    ts4_word t17;
    ts4_word t18;
    ts4_word t26;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 80))) + 24);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 8);
    RtlEnterCriticalSection();
    IoRemoveShareAccess((ts4_word)t2, (ts4_word)(t3 + 56));
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
    if ((int)t6 == 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 16)) == 1) {
        t8 = *(unsigned char *)((char *)(ts4_word)(t3) + 53);
        if ((int)(t8 & 0x8) != 0) {
            t11 = fn_88589748((ts4_word)a0, (ts4_word)t3, (ts4_word)1);
            if ((int)t11 >= 0) {
                t12 = *(unsigned char *)((char *)(ts4_word)(t3) + 53);
                if ((int)(t12 & 0x2) == 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 20)) != 0) {
                    fn_885887B8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 32)), (ts4_word)0, (ts4_word)0);
                }
                t17 = *(ts4_word *)((char *)(ts4_word)(t3) + 72);
                t18 = *(ts4_word *)((char *)(ts4_word)(t3) + 76);
                *(ts4_word *)((char *)(ts4_word)(t18) + 0) = (ts4_word)t17;
                *(ts4_word *)((char *)(ts4_word)(t17) + 4) = (ts4_word)t18;
                fn_885854A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 8)));
                *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)0;
            }
        } else {
            if ((int)(t8 & 0x10) != 0) {
                fn_88589748((ts4_word)a0, (ts4_word)t3, (ts4_word)0);
            }
        }
    }
    *(unsigned char *)((char *)(ts4_word)(t2) + 2) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(t2) + 2)) | 16);
    RtlLeaveCriticalSection((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)0;
    t26 = IoCompleteRequest((ts4_word)a1, (ts4_word)1);
    return t26;
}

/* Swing_DLL.xex 0x8858AD00: if_call_seq u32@0x0, u32@0x4, u32@0x18, u32@0x4, u32@0x18, fn_885897C8 */
ts4_word ts4_if_call_seq_u32_off0_8858AD00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p10;
    ts4_word p11;
    ts4_word p12;
    ts4_word p13;
    ts4_word p14;
    int t1;
    ts4_word t4;
    ts4_word t5;
    int t6;
    int t8;
    unsigned char t9;
    unsigned char t7;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    if ((int)t1 != 0) {
        p14 = (ts4_word)((3221225472) | 127);
    } else {
        t4 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
        if ((ts4_word)t4 != (ts4_word)t5) {
            t6 = fn_885897C8((ts4_word)a0, (ts4_word)a1);
            p12 = (ts4_word)t6;
            if ((int)t6 >= 0) {
                if ((ts4_word)t4 > (ts4_word)t5) {
                    t8 = fn_88589A50((ts4_word)a0, (ts4_word)a1, (ts4_word)t4, (ts4_word)1);
                    p10 = (ts4_word)t8;
                    if ((int)t8 >= 0) {
                        t9 = *(unsigned char *)((char *)(ts4_word)(a1) + 53);
                        *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)t4;
                        *(unsigned char *)((char *)(ts4_word)(a1) + 53) = (unsigned char)(t9 | 16);
                        p10 = (ts4_word)0;
                    }
                    p11 = (ts4_word)p10;
                } else {
                    t7 = *(unsigned char *)((char *)(ts4_word)(a1) + 53);
                    *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)t4;
                    *(unsigned char *)((char *)(ts4_word)(a1) + 53) = (unsigned char)(t7 | 16);
                    p11 = (ts4_word)0;
                }
                p12 = (ts4_word)p11;
            }
            p13 = (ts4_word)p12;
        } else {
            p13 = (ts4_word)0;
        }
        p14 = (ts4_word)p13;
    }
    return p14;
}

/* Swing_DLL.xex 0x8858B060: if_call_seq lbl_88D2EE58, u32@0x8, u32@0x4, u32@0x4, fn_8858AF70, KeEnterCriticalRegion */
ts4_word ts4_if_call_seq_lbl_88D2EE58_8858B060(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word p16;
    int t1;
    int t7;
    ts4_word t14;
    ts4_word t15;
    int t3;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2EE58) + 8);
    if ((int)t1 != 0) {
        KeEnterCriticalRegion();
        t7 = *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2EE58) + 0);
        if ((int)t7 != 0) {
            *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2EE58) + 0) = (ts4_word)0;
            ExRegisterTitleTerminateNotification((ts4_word)(ts4_word)lbl_88C320F8, (ts4_word)0);
        }
        RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_88C320BC);
        *(ts4_word *)lbl_88D2EE70 = (ts4_word)2;
        KeSetEvent((ts4_word)(ts4_word)lbl_88C320D8, (ts4_word)1, (ts4_word)0);
        KeWaitForSingleObject((ts4_word)(ts4_word)lbl_88C320E8, (ts4_word)3, (ts4_word)1, (ts4_word)0, (ts4_word)0);
        KeResetEvent((ts4_word)(ts4_word)lbl_88C320E8);
        t14 = RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_88C320BC);
        t15 = KeLeaveCriticalRegion((ts4_word)t14);
        p16 = (ts4_word)t15;
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2EE58) + 4);
        p5 = (ts4_word)a0;
        if ((int)t3 != 0) {
            t4 = fn_8858AF70();
            p5 = (ts4_word)t4;
        }
        p16 = (ts4_word)p5;
    }
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2EE58) + 4) = (ts4_word)0;
    return p16;
}

/* Swing_DLL.xex 0x8858C250: if_call_seq u32@0x984, u32@0x988, u32@0x86c, fn_8858DA50, u8@0x19, ts4_call_seq_fn_8858E5C8_8858CE30 */
ts4_word ts4_if_call_seq_u32_off984_8858C250(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p4;
    unsigned char t2;
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 2436) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 2440) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 2156) = (ts4_word)a4;
    fn_8858DA50((ts4_word)a0);
    t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 25);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
        p4 = (ts4_word)2;
    } else {
        t3 = ts4_call_seq_fn_8858E5C8_8858CE30((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t3;
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x8858C2C0: call_seq ts4_loop_call_seq_u32_off1c_8858CE80, u8@0x19 */
ts4_word ts4_call_seq_fn_8858CE80_8858C2C0(ts4_word a0)
{
    ts4_loop_call_seq_u32_off1c_8858CE80((ts4_word)a0);
    return ((*(unsigned char *)((char *)(ts4_word)(a0) + 25)) == 0);
}

/* Swing_DLL.xex 0x8858C6E0: if_call_seq u32@0x2b0c, u32@0x2b04, u32@0x2b08, MmQueryAddressProtect, u8@0x2fe4, ts4_forward_8858ED68 */
ts4_word ts4_if_call_seq_u32_off2b0c_8858C6E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t3;

    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 11020) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 11012) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 11016) = (ts4_word)((a2 + a3) + 4);
    t1 = MmQueryAddressProtect((ts4_word)a4);
    *(unsigned char *)((char *)(ts4_word)(a0) + 12260) = (unsigned char)((t1 & 0x600) != 0);
    ts4_forward_8858ED68((ts4_word)a0);
    t3 = fn_8858EA98((ts4_word)a0, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 11972) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 11972)) + 1);
    if ((int)t3 < 0) {
        *(ts4_word *)((char *)(ts4_word)(a6) + 0) = (ts4_word)0;
        p8 = (ts4_word)1;
    } else {
        *(ts4_word *)((char *)(ts4_word)(a6) + 0) = (ts4_word)t3;
        *(ts4_word *)((char *)(ts4_word)(a0) + 11024) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 11024)) + t3);
        p8 = (ts4_word)0;
    }
    return p8;
}

/* Swing_DLL.xex 0x8858C9E8: call_seq u8@0x2eb5, memset, u8@0x2eb5, memset, memset, memset */
ts4_word ts4_call_seq_u8_off2eb5_8858C9E8(ts4_word a0)
{
    ts4_word t6;

    memset((ts4_word)(a0 + 2584), (ts4_word)0, (ts4_word)(((*(unsigned char *)((char *)(ts4_word)(a0) + 11957)) + 32) << 3));
    memset((ts4_word)(a0 + 11028), (ts4_word)0, (ts4_word)(((*(unsigned char *)((char *)(ts4_word)(a0) + 11957)) + 32) << 3));
    memset((ts4_word)(a0 + 3256), (ts4_word)0, (ts4_word)249);
    t6 = memset((ts4_word)(a0 + 11700), (ts4_word)0, (ts4_word)249);
    return t6;
}

/* Swing_DLL.xex 0x885933C0: if_get u32@0x2c, u32@0x4, vcall, u32@0x50, u32@0x4, vcall */
ts4_word ts4_if_get_u32_off2c_885933C0(ts4_word a0)
{
    ts4_word p10;
    ts4_word p11;
    int t3;
    int t6;
    ts4_word t9;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 4))))((ts4_word)(a0 + 44));
    p11 = (ts4_word)t3;
    if ((int)t3 >= 0) {
        t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 80))) + 4))))((ts4_word)(a0 + 80));
        p10 = (ts4_word)t6;
        if ((int)t6 >= 0) {
            t9 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 116))) + 4))))((ts4_word)(a0 + 116));
            p10 = (ts4_word)t9;
        }
        p11 = (ts4_word)p10;
    }
    return p11;
}

/* Swing_DLL.xex 0x88593438: if_call_seq u32@0x0, fn_882A9128, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_88593438(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word loc50[4];
    int t2;
    ts4_word t3;

    t2 = fn_882A9128((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t2 >= 0) {
        t3 = loc50[0];
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t3;
        p4 = (ts4_word)1;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x88593DF0: if_call_seq ts4_if_call_seq_u32_off20_88593CE8, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_88593CE8_88593DF0(ts4_word a0, ts4_word a1)
{

    ts4_if_call_seq_u32_off20_88593CE8((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88593EE8: if_call_seq lbl_880917A8, u32@0x0, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_lbl_880917A8_88593EE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880917A8;
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0();
    }
    return a0;
}

/* Swing_DLL.xex 0x88593FD0: if_get u32@0xb0, u32@0xb8, u32@0xb8, u32@0x0, u32@0x34, vcall */
ts4_word ts4_if_get_u32_offb0_88593FD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p16;
    ts4_word t1;
    ts4_word t3;
    ts4_word t8;
    ts4_word t9;
    ts4_word t15;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
    p16 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 184);
        if ((ts4_word)t3 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 52))))((ts4_word)t1, (ts4_word)t3);
            *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)0;
        }
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 180);
        if ((ts4_word)t8 != 0) {
            t9 = *(ts4_word *)((char *)(ts4_word)((a0 + 176)) + 0);
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 52))))((ts4_word)t9, (ts4_word)t8);
            *(ts4_word *)((char *)(ts4_word)(a0) + 180) = (ts4_word)0;
        }
        fn_88598798((ts4_word)(a0 + 592));
        t15 = ts4_if_get_u32_off0_885CF1F0((ts4_word)(a0 + 176));
        p16 = (ts4_word)t15;
    }
    return p16;
}

/* Swing_DLL.xex 0x88594210: get u32@0x2c, u32@0x8, vcall, u32@0xb0, u32@0x0, u32@0x4c */
ts4_word ts4_get_u32_off2c_88594210(ts4_word a0, ts4_word a1)
{
    ts4_word t4;
    ts4_word t17;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 8))))((ts4_word)(a0 + 44));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 76))))((ts4_word)t4, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a1) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20));
    *(ts4_word *)((char *)(ts4_word)(a1) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 400));
    *(ts4_word *)((char *)(ts4_word)(a1) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
    *(ts4_word *)((char *)(ts4_word)(a1) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36));
    *(ts4_word *)((char *)(ts4_word)(a1) + 52) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40));
    *(ts4_word *)((char *)(ts4_word)(a1) + 56) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
    *(ts4_word *)((char *)(ts4_word)(a1) + 60) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32));
    t17 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 20))))((ts4_word)(a0 + 44));
    return t17;
}

/* Swing_DLL.xex 0x885942A8: get u32@0x2c, u32@0x8, vcall, u32@0x2c, u32@0x14, vcall */
ts4_word ts4_get_u32_off2c_885942A8(ts4_word a0)
{
    ts4_word t6;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 8))))((ts4_word)(a0 + 44));
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 20))))((ts4_word)(a0 + 44));
    return t6;
}

/* Swing_DLL.xex 0x88594308: if_get u32@0x50, u32@0x8, vcall, u32@0xa8, u32@0x2c, u32@0x14 */
ts4_word ts4_if_get_u32_off50_88594308(ts4_word a0, ts4_word a1)
{
    int t4;
    ts4_word t8;
    ts4_word t19;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 80))) + 8))))((ts4_word)(a0 + 80));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 168);
    if ((int)t4 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 20))))((ts4_word)(a0 + 44));
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 60))))((ts4_word)t8, (ts4_word)a1);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 8))))((ts4_word)(a0 + 44));
        *(ts4_word *)((char *)(ts4_word)(a0) + 172) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 168) = (ts4_word)((a1 + -1) != 0);
    }
    t19 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 80)) + 0))) + 20))))((ts4_word)(a0 + 80));
    return t19;
}

/* Swing_DLL.xex 0x88594700: get u32@0x10, u32@0x18, u32@0x18c, u32@0x1c, u32@0x14, u32@0x20 */
void ts4_get_u32_off10_88594700(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16));
    *(ts4_word *)((char *)(ts4_word)(a1) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 396));
    *(ts4_word *)((char *)(ts4_word)(a1) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20));
    *(ts4_word *)((char *)(ts4_word)(a1) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
    *(ts4_word *)((char *)(ts4_word)(a1) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
    *(ts4_word *)((char *)(ts4_word)(a1) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32));
    *(ts4_word *)((char *)(ts4_word)(a1) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36));
    return;
}

/* Swing_DLL.xex 0x88594940: if_call_seq fn_88594848, u32@0x0, u32@0x18, u32@0x4, u32@0x8, u32@0x18 */
ts4_word ts4_if_call_seq_fn_88594848_88594940(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_88594848((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)0;
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Swing_DLL.xex 0x88594EF8: if_call_seq fn_88594740, u32@0x0, u32@0x4, u32@0xd0, u32@0x8, u32@0xd0 */
ts4_word ts4_if_call_seq_fn_88594740_88594EF8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_88594740((ts4_word)a0);
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

/* Swing_DLL.xex 0x88594F78: if_call_seq fn_88594848, u32@0x0, u32@0x4, u32@0x1c, u32@0x8, u32@0x1c */
ts4_word ts4_if_call_seq_fn_88594848_88594F78(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_88594848((ts4_word)a0);
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

/* Swing_DLL.xex 0x88595100: if_get u32@0x2c, u32@0x8, vcall, fn_88594AA8, u32@0x98, u32@0x0 */
ts4_word ts4_if_get_u32_off2c_88595100(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    int t4;
    ts4_word t10;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 8))))((ts4_word)(a0 + 44));
    t4 = fn_88594AA8((ts4_word)a0);
    loc50[0] = (ts4_word)t4;
    if ((int)t4 >= 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 152));
    }
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 44)) + 0))) + 20))))((ts4_word)(a0 + 44));
    fn_885AA560((ts4_word)(ts4_word)&loc50[0]);
    t10 = loc50[0];
    return t10;
}

/* Swing_DLL.xex 0x88596578: if_call_seq fn_88596020, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_88596020_88596578(ts4_word a0, ts4_word a1)
{

    fn_88596020();
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88598378: if_get u32@0x4, u32@0x4, vcall, u32@0x0, u32@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_off4_88598378(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 4))))((ts4_word)(a0 + 4));
    if ((int)t3 >= 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1);
    }
    return t3;
}

/* Swing_DLL.xex 0x88598560: if_call_seq fn_88594740, u32@0x0, u32@0xcc, u32@0x4, u32@0x8, u32@0xcc */
ts4_word ts4_if_call_seq_fn_88594740_88598560(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_88594740((ts4_word)a0);
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

/* Swing_DLL.xex 0x88598EF0: get u32@0x34, u32@0x2c, u32@0x8, vcall, u32@0x3c, u32@0x0 */
ts4_word ts4_get_u32_off34_88598EF0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t8;
    ts4_word t11;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60));
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 64));
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 212));
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t11 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 44))) + 20))))((ts4_word)(t8 + 44));
    return t11;
}

/* Swing_DLL.xex 0x88599110: get u32@0x34, u32@0x2c, u32@0x8, vcall, u32@0x90, u32@0x0 */
ts4_word ts4_get_u32_off34_88599110(ts4_word a0)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 32))))((ts4_word)t5, (ts4_word)0);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 44))) + 20))))((ts4_word)(t9 + 44));
    return t8;
}

/* Swing_DLL.xex 0x88599188: get u32@0x34, u32@0x2c, u32@0x8, vcall, u32@0x90, u32@0x0 */
ts4_word ts4_get_u32_off34_88599188(ts4_word a0)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 40))))((ts4_word)t5);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 44))) + 20))))((ts4_word)(t9 + 44));
    return t8;
}

/* Swing_DLL.xex 0x88599200: get u32@0x34, u32@0x2c, u32@0x8, vcall, u32@0x90, u32@0x0 */
ts4_word ts4_get_u32_off34_88599200(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 36))))((ts4_word)t5, (ts4_word)a1);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 44))) + 20))))((ts4_word)(t9 + 44));
    return t8;
}

/* Swing_DLL.xex 0x88599350: get u32@0x34, u32@0x2c, u32@0x8, vcall, u32@0x90, u32@0x0 */
ts4_word ts4_get_u32_off34_88599350(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t9;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 12))))((ts4_word)t5, (ts4_word)1, (ts4_word)a1, (ts4_word)4);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t12 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 44))) + 20))))((ts4_word)(t9 + 44));
    return t12;
}

/* Swing_DLL.xex 0x88599460: if_get u32@0x30, fn_882A8E28, u32@0x38, u32@0x0, u32@0x10, vcall */
ts4_word ts4_if_get_u32_off30_88599460(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p10;
    ts4_word p11;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t9;

    t2 = fn_882A8E28((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)a1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    p11 = (ts4_word)t2;
    if ((ts4_word)t3 != 0) {
        t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 16))))((ts4_word)t3, (ts4_word)a1);
        p10 = (ts4_word)t6;
        if ((int)(a2 & 0x40) != 0) {
            t9 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3);
            p10 = (ts4_word)t9;
        }
        p11 = (ts4_word)p10;
    }
    return p11;
}

/* Swing_DLL.xex 0x88599660: if_call_seq ts4_mask_if_ne_88598D98, ts4_list_find_88598DB0 */
ts4_word ts4_if_call_seq_fn_88598D98_88599660(ts4_word a0, ts4_word a1)
{
    ts4_word p2;
    ts4_word loc50[4];
    ts4_word t1;

    loc50[0] = (ts4_word)a1;
    t1 = ts4_list_find_88598DB0((ts4_word)(a0 + 228), (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)ts4_mask_if_ne_88598D98, (ts4_word)0);
    p2 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        p2 = (ts4_word)((2147483648) | 16389);
    }
    return p2;
}

/* Swing_DLL.xex 0x88599730: if_get u32@0x4, u32@0x5c, vcall, u32@0x8, u32@0x34, u32@0x2c */
ts4_word ts4_if_get_u32_off4_88599730(ts4_word a0)
{
    int t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t11;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 92))))((ts4_word)(a0 + 4));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t4 != 2) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
        *(ts4_word *)((char *)(ts4_word)(t5) + 40) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 40)) - t6);
    }
    t11 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 120))))((ts4_word)a0, (ts4_word)1);
    return t11;
}

/* Swing_DLL.xex 0x88599C78: if_call_seq fn_88599808, u32@0x0, u32@0x4, u32@0x1c, u32@0x8, u32@0x1c */
ts4_word ts4_if_call_seq_fn_88599808_88599C78(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_88599808((ts4_word)a0);
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

/* Swing_DLL.xex 0x8859A158: if_call_seq fn_8859A0F0, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_8859A0F0_8859A158(ts4_word a0, ts4_word a1)
{

    fn_8859A0F0();
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8859B2D0: if_get u32@0x4, u32@0x8, u32@0x40, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_off4_8859B2D0(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)(t1 & 0x20000) != 0) {
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((int)a1 * 96)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 8))));
    } else {
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((((int)a1 * 96) + (*(ts4_word *)((char *)(ts4_word)(a0) + 8)))) + 64))) + 0));
    }
    return ((p8 >> 12) & 0xff);
}

/* Swing_DLL.xex 0x8859B648: if_call_seq u32@0x4, lbl_88C326B8, RtlEnterCriticalSection, u32@0x8, lbl_88D2F1B0, u16@0x50 */
ts4_word ts4_if_call_seq_u32_off4_8859B648(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    unsigned short t4;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)(t1 & 0x4) != 0) {
        RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_88C326B8);
        t4 = *(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 80);
        *(ts4_word *)((char *)(ts4_word)(((t4 << 2) | (t4 >> 30))) + (ts4_word)lbl_88D2F1B0) = (ts4_word)0;
        RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_88C326B8);
    }
    fn_8859AC98((ts4_word)a0);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)(t8 & 0x2) == 0) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)a0, (ts4_word)(2811691008));
    }
    return 0;
}

/* Swing_DLL.xex 0x8859BBA0: get u32@0x34, u32@0x2c, u32@0x8, vcall, u32@0x90, u32@0x0 */
ts4_word ts4_get_u32_off34_8859BBA0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 52))))((ts4_word)t5, (ts4_word)512);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 44))) + 20))))((ts4_word)(t9 + 44));
    return t8;
}

/* Swing_DLL.xex 0x8859BF80: if_tailcall ts4_pool_free_885B72F0 */
ts4_word ts4_if_tailcall_fn_885B72F0_8859BF80(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return a0;
    }
    return ts4_pool_free_885B72F0((ts4_word)a1, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8859CBC0: call_seq lbl_88091AB8, lbl_88091A8C, u32@0x4, u32@0x8c, u32@0x0, ts4_pool1_clear_88599CF8 */
ts4_word ts4_call_seq_lbl_88091AB8_8859CBC0(ts4_word a0)
{
    ts4_word t6;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_88091AB8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)(ts4_word)lbl_88091A8C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    ts4_pool1_clear_88599CF8((ts4_word)(a0 + 664));
    ts4_pool1_clear_88599CF8((ts4_word)(a0 + 624));
    ts4_loop_call_seq_u32_off4_885A50D0((ts4_word)(a0 + 616));
    ts4_pool1_clear_88599CF8((ts4_word)(a0 + 548));
    ts4_pool1_clear_88599CF8((ts4_word)(a0 + 508));
    t6 = fn_8859A0F0((ts4_word)a0);
    return t6;
}

/* Swing_DLL.xex 0x8859D658: if_get u32@0x6c, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4_if_get_u32_off6c_8859D658(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t8;
    ts4_word t9;
    ts4_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 108);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)a1 == (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 112);
    if ((ts4_word)a1 == (ts4_word)t8) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    } else {
        t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        *(ts4_word *)((char *)(ts4_word)(t9) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)(t15 + -1);
    return t2;
}

/* Swing_DLL.xex 0x8859DE70: if_call_seq fn_8859D728, u32@0x0, u32@0x6c, u32@0x4, u32@0x8, u32@0x6c */
ts4_word ts4_if_call_seq_fn_8859D728_8859DE70(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_8859D728((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 108));
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)0;
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 108);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
        *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Swing_DLL.xex 0x8859EA08: call_seq lbl_88091C50, lbl_88091BA4, u32@0x4, u32@0x8c, u32@0x0, ts4_pool1_clear_88599CF8 */
ts4_word ts4_call_seq_lbl_88091C50_8859EA08(ts4_word a0)
{
    ts4_word t4;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_88091C50;
    *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)(ts4_word)lbl_88091BA4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    ts4_pool1_clear_88599CF8((ts4_word)(a0 + 540));
    ts4_pool1_clear_88599CF8((ts4_word)(a0 + 500));
    ts4_loop_call_seq_u32_off4_885A50D0((ts4_word)(a0 + 492));
    t4 = fn_8859A0F0((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x8859FEC8: if_get u32@0x8c, u32@0x30, u32@0xb0, u32@0x0, u32@0x34, vcall */
ts4_word ts4_if_get_u32_off8c_8859FEC8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p22;
    ts4_word t1;
    ts4_word t3;
    ts4_word t8;
    ts4_word t10;
    ts4_word t15;
    ts4_word t16;
    ts4_word t18;
    ts4_word t21;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 140);
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + 176);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 52))))((ts4_word)t3, (ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)0;
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    if ((ts4_word)t8 != 0) {
        t10 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + 176);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 52))))((ts4_word)t10, (ts4_word)t8);
        *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)0;
    }
    t15 = ts4_if_get_fn_885ABDB0_885ABE30((ts4_word)a0);
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
    p22 = (ts4_word)t15;
    if ((ts4_word)t16 != 0) {
        t18 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + 176);
        t21 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t18) + 0))) + 28))))((ts4_word)t18, (ts4_word)t16);
        p22 = (ts4_word)t21;
    }
    return p22;
}

/* Swing_DLL.xex 0x8859FF78: call_seq fn_885AB808, lbl_88091D58, lbl_88091CE8, u32@0x8c, u32@0x0, u32@0x4 */
ts4_word ts4_call_seq_fn_885AB808_8859FF78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    fn_885AB808((ts4_word)(a0 + 4), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88091D58;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_88091CE8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x885A0098: if_call_seq fn_885A0048, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_885A0048_885A0098(ts4_word a0, ts4_word a1)
{

    fn_885A0048((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885A0238: call_seq fn_885AB808, u32@0x8c, lbl_88091D58, u32@0x90, lbl_88091DA8, u32@0x0 */
ts4_word ts4_call_seq_fn_885AB808_885A0238(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    fn_885AB808((ts4_word)(a0 + 4), (ts4_word)a1, (ts4_word)a4, (ts4_word)a5);
    *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88091D58;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_88091DA8;
    return a0;
}

/* Swing_DLL.xex 0x885A0348: if_call_seq fn_885A02F8, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_885A02F8_885A0348(ts4_word a0, ts4_word a1)
{

    fn_885A02F8((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885A4E40: if_get u32@0x1c, u32@0x4, vcall, u32@0x54, u32@0x4, vcall */
ts4_word ts4_if_get_u32_off1c_885A4E40(ts4_word a0)
{
    ts4_word p7;
    int t3;
    ts4_word t6;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 4))))((ts4_word)(a0 + 28));
    p7 = (ts4_word)t3;
    if ((int)t3 >= 0) {
        t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 84))) + 4))))((ts4_word)(a0 + 84));
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Swing_DLL.xex 0x885A4F10: if_get u32@0x1c, u32@0x8, vcall, u32@0x0, u32@0x17c, u32@0x0 */
ts4_word ts4_if_get_u32_off1c_885A4F10(ts4_word a0, ts4_word a1)
{
    int t4;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 8))))((ts4_word)(a0 + 28));
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 380);
    if ((int)t4 == 2) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)1;
    }
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 28)) + 0))) + 20))))((ts4_word)(a0 + 28));
    return 0;
}

/* Swing_DLL.xex 0x885A4F78: get u32@0x1c, u32@0x8, vcall, u32@0x44, fn_885B5698, u32@0x1c */
ts4_word ts4_get_u32_off1c_885A4F78(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t5;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 8))))((ts4_word)(a0 + 28));
    t5 = fn_885B5698((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 68)), (ts4_word)a1, (ts4_word)a2);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 20))))((ts4_word)(a0 + 28));
    return t5;
}

/* Swing_DLL.xex 0x885A4FE0: get u32@0x1c, u32@0x8, vcall, u32@0x44, fn_885B5460, u32@0x1c */
ts4_word ts4_get_u32_off1c_885A4FE0(ts4_word a0, ts4_word a1)
{
    ts4_word t8;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 8))))((ts4_word)(a0 + 28));
    fn_885B5460((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 68)), (ts4_word)a1);
    t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 20))))((ts4_word)(a0 + 28));
    return t8;
}

/* Swing_DLL.xex 0x885A5068: if_get u32@0x0, u32@0x28, vcall, u32@0x0, u32@0x28, vcall */
ts4_word ts4_if_get_u32_off0_885A5068(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t3;
    ts4_word t8;
    ts4_word t10;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p5 = (ts4_word)0;
    if ((ts4_word)a1 != 0) {
        t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 40))))((ts4_word)a1);
        p5 = (ts4_word)t3;
    }
    t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0))) + 40))))((ts4_word)a2);
    t10 = fn_885B66F0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 72)), (ts4_word)p5, (ts4_word)t8);
    return t10;
}

/* Swing_DLL.xex 0x885A53C0: get u32@0x48, u32@0x40, u32@0x8 */
ts4_word ts4_get_u32_off48_885A53C0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 64))) + 8))))((ts4_word)(t1 + 64));
}

/* Swing_DLL.xex 0x885A53D8: get u32@0x48, u32@0x40, u32@0x14 */
ts4_word ts4_get_u32_off48_885A53D8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 64))) + 20))))((ts4_word)(t1 + 64));
}

/* Swing_DLL.xex 0x885A5488: if_get u32@0x18, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4_if_get_u32_off18_885A5488(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t8;
    ts4_word t9;
    ts4_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)a1 == (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)a1 == (ts4_word)t8) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    } else {
        t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        *(ts4_word *)((char *)(ts4_word)(t9) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t15 + -1);
    return t2;
}

/* Swing_DLL.xex 0x885A54F8: if_get u32@0xcc, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4_if_get_u32_offcc_885A54F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t8;
    ts4_word t9;
    ts4_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 204);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)a1 == (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 204) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 208);
    if ((ts4_word)a1 == (ts4_word)t8) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    } else {
        t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        *(ts4_word *)((char *)(ts4_word)(t9) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 212);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)(t15 + -1);
    return t2;
}

/* Swing_DLL.xex 0x885A5BF0: loop_get u32@0x54, u32@0x8, vcall, u32@0x14c, fn_885997A8, u32@0x0 */
ts4_word ts4_loop_get_u32_off54_885A5BF0(ts4_word a0)
{
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;
    ts4_word t10;
    ts4_word t15;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 84))) + 8))))((ts4_word)(a0 + 84));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
    if ((ts4_word)t4 != 0) {
        do {
            t5 = fn_885997A8((ts4_word)(a0 + 120));
            t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 4))))((ts4_word)t5, (ts4_word)0);
            ts4_pool_free_885B72F0((ts4_word)t8);
            t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
        } while ((ts4_word)t10 != 0);
    }
    t15 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 84)) + 0))) + 20))))((ts4_word)(a0 + 84));
    return t15;
}

/* Swing_DLL.xex 0x885A5C70: loop_get u32@0x174, fn_8859D5A8, u32@0x4, u32@0x0, vcall, ts4_pool_free_885B72F0 */
ts4_word ts4_loop_get_u32_off174_885A5C70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 372);
    p9 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        do {
            t2 = fn_8859D5A8((ts4_word)(a0 + 340));
            t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 4))) + 0))))((ts4_word)(t2 + 4), (ts4_word)0);
            t6 = ts4_pool_free_885B72F0((ts4_word)t5);
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 372);
        } while ((ts4_word)t7 != 0);
        p9 = (ts4_word)t6;
    }
    return p9;
}

/* Swing_DLL.xex 0x885A5FD0: if_call_seq fn_885A5568, u32@0x0, u32@0x4, u32@0xd0, u32@0x8, u32@0xd0 */
ts4_word ts4_if_call_seq_fn_885A5568_885A5FD0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_885A5568((ts4_word)a0);
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

/* Swing_DLL.xex 0x885A6258: if_get u32@0x1c, u32@0x8, vcall, u32@0x17c, fn_885A5CE8, u32@0x0 */
ts4_word ts4_if_get_u32_off1c_885A6258(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p6;
    int t4;
    ts4_word t5;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 8))))((ts4_word)(a0 + 28));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 380);
    p6 = (ts4_word)0;
    if ((int)t4 == 2) {
        t5 = fn_885A5CE8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p6 = (ts4_word)t5;
    }
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 28)) + 0))) + 20))))((ts4_word)(a0 + 28));
    return p6;
}
