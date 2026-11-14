/* Swing_DLL.xex 0x884F4748-0x885B93D0, executable version 0.0.0.3. */
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

extern char lbl_88095F40[];
extern char lbl_88095FCC[];
extern char lbl_88095FF8[];
extern char lbl_88096024[];
extern char lbl_88C31190[];
extern char lbl_88C32048[];
ts4_word XexLoadImage();
ts4_word fn_882A9128();
ts4_word fn_8856CD88();
ts4_word fn_8856D820();
ts4_word fn_8857C8C8();
ts4_word ts4_if_call_seq_RtlInitUnicodeString_88582BD0();
ts4_word ts4_if_call_seq_u32_off20_8858CCD8();
ts4_word ts4_if_get_u32_off860_8858F028();
ts4_word ts4_if_get_u32_off50_88594308();
ts4_word ts4_call_seq_lbl_88091AB8_8859CBC0();
ts4_word ts4_call_seq_lbl_88091C50_8859EA08();
ts4_word ts4_loop_get_u32_off54_885A5BF0();
ts4_word ts4_call_seq_lbl_88091F2C_885A7320();
ts4_word ts4_call_seq_lbl_88091FB8_885A7AC8();
ts4_word ts4_call_seq_lbl_88092008_885A9298();
ts4_word ts4_if_call_seq_u32_off2c_885A9E38();
ts4_word fn_885B55F0();
ts4_word ts4_if_call_seq_u32_off4_885B6060();
ts4_word ts4_pool_free_885B72F0();
ts4_word fn_885B85F8();
ts4_word fn_885B9140();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_forward_882A9120();
ts4_word ts4_forward_record_status();





/* Swing_DLL.xex 0x8857A068: if_call_seq XexLoadImage, ts4_forward_record_status */
ts4_word ts4_if_call_seq_XexLoadImage_8857A068(ts4_word a0)
{
    ts4_word p4;
    ts4_word loc50[2];
    int t1;
    ts4_word t2;

    t1 = XexLoadImage((ts4_word)a0, (ts4_word)9, (ts4_word)0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 < 0) {
        ts4_forward_record_status((ts4_word)t1);
        p4 = (ts4_word)0;
    } else {
        t2 = loc50[0];
        p4 = (ts4_word)t2;
    }
    return p4;
}


/* Swing_DLL.xex 0x88584728: call_seq u32@0x38, u32@0x0, u32@0x8, u32@0x4, u32@0xc, u32@0x8 */
ts4_word ts4_call_seq_u32_off38_88584728(ts4_word a0, ts4_word a1)
{
    ts4_word t11;

    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 56));
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8));
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 12));
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 16));
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 20));
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 24));
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28));
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 28) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 40));
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 32) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 44));
    t11 = memcpy((ts4_word)(a1 + 44), (ts4_word)(a0 + 64), (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 60)));
    *(volatile unsigned char *)((char *)(ts4_word)(((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 60)) + a1)) + 44) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a1) + 304) = (unsigned char)0;
    return t11;
}

















