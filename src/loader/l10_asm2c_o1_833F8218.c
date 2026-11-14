/* Loader_DLL.xex 0x833F8218-0x834265F0, executable version 0.0.0.3.
   Machine-translated functions (tools/asm2c) verified with /O1. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
typedef __int64 ts4l_s64;
#else
typedef unsigned long long ts4l_u64;
typedef long long ts4l_s64;
#endif
typedef unsigned long ts4l_word;

extern char __imp_ExThreadObjectType[];
ts4l_word ObDereferenceObject();
ts4l_word ObReferenceObjectByHandle();
ts4l_word fn_833E74C0();
ts4l_word ts4_tailcall_fn_8340F088_834141B8();

/* Loader_DLL.xex 0x833F8218: if_call_seq u32@0xc, u32@0x8, fn_833E74C0, u32@0x0, u32@0x8, u32@0x4 */
ts4l_word ts4l_if_call_seq_u32_offc_833F8218(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word p6;
    ts4l_word p8;
    ts4l_word t1;
    ts4l_word t3;

    t1 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    p8 = (ts4l_word)a0;
    if ((int)(t1 & 131) != 0) {
        p6 = (ts4l_word)a0;
        if ((int)(t1 & 0x8) != 0) {
            t3 = fn_833E74C0((ts4l_word)(*(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 8)), (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a3, (ts4l_word)a4, (ts4l_word)a5, (ts4l_word)a6, (ts4l_word)(t1 & 131));
            *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
            *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 8) = (ts4l_word)0;
            *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)0;
            *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)(((*(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 12)) & 0xfffffff7) & 0xfffffbff);
            p6 = (ts4l_word)t3;
        }
        p8 = (ts4l_word)p6;
    }
    return p8;
}

/* Loader_DLL.xex 0x8340CAE0: if_call_seq u32@__imp_ExThreadObjectType, ObReferenceObjectByHandle, ts4_tailcall_fn_8340F088_834141B8, u32@0x4, u32@0x140, u32@0x0 */
ts4l_word ts4l_wait_thread_status_8340CAE0(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p7;
    ts4l_word p9;
    ts4l_word loc50[4];
    int t2;
    ts4l_word t4;
    ts4l_word t5;

    t2 = ObReferenceObjectByHandle((ts4l_word)a0, (ts4l_word)(*(volatile ts4l_word *)__imp_ExThreadObjectType), (ts4l_word)(ts4l_word)&loc50[0]);
    if ((int)t2 >= 0) {
        t4 = loc50[0];
        t5 = *(volatile ts4l_word *)((char *)(ts4l_word)(t4) + 4);
        if ((int)(t5 & 0xff) != 0) {
            p7 = (ts4l_word)(*(volatile ts4l_word *)((char *)(ts4l_word)(t4) + 320));
        } else {
            p7 = (ts4l_word)259;
        }
        *(volatile ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)p7;
        ObDereferenceObject((ts4l_word)t4);
        p9 = (ts4l_word)1;
    } else {
        ts4_tailcall_fn_8340F088_834141B8((ts4l_word)t2);
        p9 = (ts4l_word)0;
    }
    return p9;
}

/* Loader_DLL.xex 0x834265F0: get u16@0x3, u16@0x3, u16@0x5, u16@0x5, u16@0x8, u16@0x8 */
void ts4l_byteswap_u16_fields_834265F0(ts4l_word a0, ts4l_word a1)
{
    unsigned short t1;
    unsigned short t2;
    unsigned short t3;
    unsigned short t4;
    unsigned short t5;
    unsigned short t6;

    t1 = *(unsigned short *)((char *)(ts4l_word)(a1) + 3);
    *(unsigned short *)((char *)(ts4l_word)(a0) + 3) = (unsigned short)(((t1 & 0xff) << 8) | ((t1) >> 8));
    t2 = *(unsigned short *)((char *)(ts4l_word)(a1) + 5);
    *(unsigned short *)((char *)(ts4l_word)(a0) + 5) = (unsigned short)(((t2 & 0xff) << 8) | ((t2) >> 8));
    t3 = *(unsigned short *)((char *)(ts4l_word)(a1) + 8);
    *(unsigned short *)((char *)(ts4l_word)(a0) + 8) = (unsigned short)(((t3 & 0xff) << 8) | ((t3) >> 8));
    t4 = *(unsigned short *)((char *)(ts4l_word)(a1) + 10);
    *(unsigned short *)((char *)(ts4l_word)(a0) + 10) = (unsigned short)(((t4 & 0xff) << 8) | ((t4) >> 8));
    t5 = *(unsigned short *)((char *)(ts4l_word)(a1) + 12);
    *(unsigned short *)((char *)(ts4l_word)(a0) + 12) = (unsigned short)(((t5 & 0xff) << 8) | ((t5) >> 8));
    t6 = *(unsigned short *)((char *)(ts4l_word)(a1) + 14);
    *(unsigned short *)((char *)(ts4l_word)(a0) + 14) = (unsigned short)(((t6 & 0xff) << 8) | ((t6) >> 8));
    return;
}
