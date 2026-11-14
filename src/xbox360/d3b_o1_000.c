/* Swing_DLL.xex 0x884F7918-0x8857B248, executable version 0.0.0.3. */
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

extern char __imp_XboxKrnlVersion[];
extern char fn_884F62E8[];
extern char fn_884F6450[];
extern char fn_884F6478[];
extern char ts4_locked_get_field_884F6560[];
extern char ts4_get_nested_field_884F65B8[];
extern char fn_884F6FA8[];
extern char fn_884F7248[];
extern char fn_884F73B0[];
extern char fn_884F7470[];
extern char ts4_locked_lookup_884F74E8[];
extern char fn_884F7628[];
extern char fn_88593EC0[];
extern char ts4_call_seq_RtlEnterCriticalSection_884F6518[];
extern char ts4_get_u32_offec_884F65E8[];
extern char ts4_if_call_seq_RtlEnterCriticalSection_884F6370[];
extern char ts4_if_call_seq_RtlEnterCriticalSection_884F63E0[];
extern char ts4_if_call_seq_RtlEnterCriticalSection_884F65F0[];
extern char ts4_if_call_seq_RtlEnterCriticalSection_884F7168[];
extern char ts4_if_call_seq_RtlEnterCriticalSection_884F71D8[];
extern char ts4_if_call_seq_RtlEnterCriticalSection_884F7350[];
extern char ts4_if_call_seq_RtlEnterCriticalSection_884F7540[];
extern char ts4_if_call_seq_RtlEnterCriticalSection_884F75A8[];
extern char ts4_if_call_seq_RtlEnterCriticalSection_884F7788[];
extern char ts4_if_call_seq_RtlEnterCriticalSection_884F77F8[];
ts4_word XamInputGetCapabilities();
ts4_word XamInputSetState();

/* Swing_DLL.xex 0x884F7918: if_get u32@0x0, fn_88593EC0, fn_884F6FA8, fn_884F62E8, u32@0x0, u32@0x4 */
void ts4_if_get_u32_off0_884F7918(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_88593EC0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)fn_884F6FA8;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)fn_884F62E8;
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(ts4_word)ts4_if_call_seq_RtlEnterCriticalSection_884F6370;
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(ts4_word)ts4_if_call_seq_RtlEnterCriticalSection_884F63E0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(ts4_word)ts4_if_call_seq_RtlEnterCriticalSection_884F7168;
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(ts4_word)ts4_if_call_seq_RtlEnterCriticalSection_884F71D8;
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(ts4_word)fn_884F6450;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)fn_884F6478;
        *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(ts4_word)ts4_call_seq_RtlEnterCriticalSection_884F6518;
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(ts4_word)fn_884F7248;
        *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(ts4_word)ts4_if_call_seq_RtlEnterCriticalSection_884F7350;
        *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(ts4_word)fn_884F73B0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(ts4_word)ts4_locked_get_field_884F6560;
        *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(ts4_word)ts4_get_nested_field_884F65B8;
        *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)(ts4_word)ts4_locked_lookup_884F74E8;
        *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)(ts4_word)ts4_if_call_seq_RtlEnterCriticalSection_884F7540;
        *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)(ts4_word)ts4_if_call_seq_RtlEnterCriticalSection_884F75A8;
        *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)(ts4_word)ts4_get_u32_offec_884F65E8;
        *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)(ts4_word)ts4_if_call_seq_RtlEnterCriticalSection_884F65F0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)(ts4_word)ts4_if_call_seq_RtlEnterCriticalSection_884F7788;
        *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)(ts4_word)ts4_if_call_seq_RtlEnterCriticalSection_884F77F8;
        *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)(ts4_word)fn_884F7628;
        *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)(ts4_word)fn_884F7470;
    }
    return;
}

/* Swing_DLL.xex 0x8857B180: if_call_seq u32@0x0, u32@__imp_XboxKrnlVersion, u16@0x0, u16@0x2, u16@0x4, XamInputGetCapabilities */
ts4_word ts4_if_call_seq_u32_off0_8857B180(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word loc50[4];
    ts4_word loc60[6];
    ts4_word t1;
    ts4_word t2;
    unsigned short t3;
    ts4_word t6;
    unsigned short t8;
    unsigned short t9;
    unsigned short t10;
    ts4_word t16;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)__imp_XboxKrnlVersion;
    loc50[0] = (ts4_word)t1;
    t3 = *(unsigned short *)((char *)(ts4_word)(t2) + 0);
    if (((ts4_word)t3 == 2 && (ts4_word)(*(unsigned short *)((char *)(ts4_word)(t2) + 2)) == 0) && (ts4_word)(*(unsigned short *)((char *)(ts4_word)(t2) + 4)) < 5611) {
        t6 = XamInputGetCapabilities((ts4_word)a0, (ts4_word)1, (ts4_word)(ts4_word)&loc60[0]);
        if ((ts4_word)t6 == 0 && (ts4_word)(*(unsigned char *)((char *)loc60 + 1)) == 2) {
            t8 = *(unsigned short *)((char *)loc60 + 2);
            if ((int)(t8 & 0x1) != 0) {
                if ((int)(t8 & 0x2) != 0) {
                    t9 = *(unsigned short *)((char *)(ts4_word)(a1) + 2);
                    t10 = *(unsigned short *)((char *)(ts4_word)(a1) + 0);
                    *(unsigned short *)((char *)loc50 + 0) = (unsigned short)t9;
                    *(unsigned short *)((char *)loc50 + 2) = (unsigned short)t10;
                }
            }
        }
    }
    t16 = XamInputSetState((ts4_word)a0, (ts4_word)0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t16;
}
