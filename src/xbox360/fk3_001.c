/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;
extern long _InterlockedIncrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedIncrement)
#endif

extern char lbl_880E8C9C[];
extern char lbl_880E8CA0[];
extern char lbl_88CA1E00[];
extern char lbl_88D41FC4[];
extern char lbl_88D45A60[];
extern char lbl_88D45A74[];
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word ts4_if_atomic_interlocked_dec_881876D0();
ts4_word fn_881B19A0();
ts4_word ts4_call_seq_u32_off0_881B1A98();
ts4_word ts4_call_seq_fn_88837880_881E2F68();
ts4_word ts4_if_atomic_interlocked_dec_885B5E88();
ts4_word fn_88608590();
ts4_word ts4_if_get_u32_off110_88713880();
ts4_word fn_88837880();
ts4_word ts4_call_seq_u32_off10_88837820();

/* Swing_DLL.xex 0x881E3028: call_seq u32@0x0, fn_88837880, lbl_880E8C9C, ts4_call_seq_fn_88837880_881E2F68, lbl_880E8CA0, ts4_call_seq_fn_88837880_881E2F68 */
ts4_word ts4_call_seq_u32_off0_881E3028(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc70[8];
    ts4_word loc50[4];
    ts4_word loc60[4];
    float t5;
    float t6;
    float t7;
    float t8;
    float t9;
    float t10;
    ts4_word t11;

    fn_88837880((ts4_word)(ts4_word)&loc70[0], (ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    ts4_call_seq_fn_88837880_881E2F68((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)lbl_880E8C9C, (ts4_word)(ts4_word)&loc50[0]);
    ts4_call_seq_fn_88837880_881E2F68((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)lbl_880E8CA0, (ts4_word)(ts4_word)&loc60[0]);
    t5 = *(float *)((char *)loc50 + 0);
    t6 = *(float *)((char *)loc50 + 4);
    t7 = *(float *)((char *)loc50 + 8);
    t8 = *(float *)((char *)loc60 + 0);
    t9 = *(float *)((char *)loc60 + 4);
    t10 = *(float *)((char *)loc60 + 8);
    *(float *)((char *)(ts4_word)(a2) + 0) = t5;
    *(float *)((char *)(ts4_word)(a2) + 8) = t6;
    *(float *)((char *)(ts4_word)(a2) + 16) = t7;
    *(float *)((char *)(ts4_word)(a2) + 4) = (t8 + t5);
    *(float *)((char *)(ts4_word)(a2) + 12) = (t9 + t6);
    *(float *)((char *)(ts4_word)(a2) + 20) = (t10 + t7);
    t11 = fn_881B19A0((ts4_word)(ts4_word)&loc70[0]);
    return t11;
}

/* Swing_DLL.xex 0x881E30D0: call_seq ts4_call_seq_u32_off10_88837820, lbl_880E8C9C, ts4_call_seq_fn_88837880_881E2F68, lbl_880E8CA0, ts4_call_seq_fn_88837880_881E2F68, fn_881B19A0 */
ts4_word ts4_call_seq_ts4_call_seq_u32_off10_88837820_881E30D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc70[8];
    ts4_word loc50[4];
    ts4_word loc60[4];
    float t4;
    float t5;
    float t6;
    float t7;
    float t8;
    float t9;
    ts4_word t10;

    ts4_call_seq_u32_off10_88837820((ts4_word)(ts4_word)&loc70[0], (ts4_word)a0, (ts4_word)a1);
    ts4_call_seq_fn_88837880_881E2F68((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)lbl_880E8C9C, (ts4_word)(ts4_word)&loc50[0]);
    ts4_call_seq_fn_88837880_881E2F68((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)lbl_880E8CA0, (ts4_word)(ts4_word)&loc60[0]);
    t4 = *(float *)((char *)loc50 + 0);
    t5 = *(float *)((char *)loc50 + 4);
    t6 = *(float *)((char *)loc50 + 8);
    t7 = *(float *)((char *)loc60 + 0);
    t8 = *(float *)((char *)loc60 + 4);
    t9 = *(float *)((char *)loc60 + 8);
    *(float *)((char *)(ts4_word)(a2) + 0) = t4;
    *(float *)((char *)(ts4_word)(a2) + 8) = t5;
    *(float *)((char *)(ts4_word)(a2) + 16) = t6;
    *(float *)((char *)(ts4_word)(a2) + 4) = (t7 + t4);
    *(float *)((char *)(ts4_word)(a2) + 12) = (t8 + t5);
    *(float *)((char *)(ts4_word)(a2) + 20) = (t9 + t6);
    t10 = fn_881B19A0((ts4_word)(ts4_word)&loc70[0]);
    return t10;
}

/* Swing_DLL.xex 0x881ED038: if_get u32@lbl_88D41FC4, u32@0x4, u32@0x15b4, u32@0x15b8, u32@0x15b8, interlocked_inc */
ts4_word ts4_if_get_u32_lbl_88D41FC4_881ED038(void)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t19;
    ts4_word t22;
    ts4_word t5;
    ts4_word t10;
    ts4_word t13;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D41FC4)) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 5556);
    if ((ts4_word)t3 != 0) {
        _InterlockedIncrement((volatile long *)(ts4_word)((t3 + 4)));
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t3);
        t19 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D41FC4)) + 4))) + 5556);
        if ((ts4_word)t19 != 0) {
            _InterlockedIncrement((volatile long *)(ts4_word)((t19 + 4)));
        }
        t22 = *(ts4_word *)((char *)(ts4_word)(t19) + 92);
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t19);
        return t22;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(t2) + 5560);
    if ((ts4_word)t5 != 0) {
        _InterlockedIncrement((volatile long *)(ts4_word)((t5 + 4)));
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t5);
        t10 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D41FC4)) + 4))) + 5560);
        if ((ts4_word)t10 != 0) {
            _InterlockedIncrement((volatile long *)(ts4_word)((t10 + 4)));
        }
        t13 = *(ts4_word *)((char *)(ts4_word)(t10) + 60);
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t10);
        return t13;
    }
    return 0;
}

/* Swing_DLL.xex 0x885B61F8: get RtlEnterCriticalSection, u32@0x20, ts4_if_atomic_interlocked_dec_885B5E88, interlocked_inc, u32@0x20, RtlLeaveCriticalSection */
ts4_word ts4_get_RtlEnterCriticalSection_885B61F8(ts4_word a0, ts4_word a1)
{
    ts4_word t5;

    RtlEnterCriticalSection((ts4_word)(a0 + 36));
    ts4_if_atomic_interlocked_dec_885B5E88((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)));
    _InterlockedIncrement((volatile long *)(ts4_word)((a1 + 16)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    t5 = RtlLeaveCriticalSection((ts4_word)(a0 + 36));
    return t5;
}

/* Swing_DLL.xex 0x887194D0: loop_call_seq u32@lbl_88D45A74, fn_88608590, u32@0x0, u32@0x4, u32@0x10c, u32@0x11c */
ts4_word ts4_loop_call_seq_u32_lbl_88D45A74_887194D0(ts4_word a0)
{
    ts4_word lv5;
    ts4_word p12;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    int t10;
    ts4_word t11;

    t1 = *(ts4_word *)lbl_88D45A74;
    t2 = fn_88608590((ts4_word)0, (ts4_word)a0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    if ((ts4_word)t3 < (ts4_word)t4) {
        lv5 = (ts4_word)t3;
        do {
            t8 = *(ts4_word *)((char *)(ts4_word)(lv5) + 268);
            if ((ts4_word)t8 == (ts4_word)t2) {
                t10 = *(ts4_word *)((char *)(ts4_word)(lv5) + 284);
                if ((int)t10 == 1) {
                    *(ts4_word *)((char *)(ts4_word)(lv5) + 284) = (ts4_word)3;
                    t11 = ts4_if_get_u32_off110_88713880((ts4_word)lv5);
                    return t11;
                }
                return t2;
            }
            p12 = (ts4_word)(lv5 + 308);
            lv5 = p12;
        } while ((ts4_word)p12 < (ts4_word)t4);
        return t2;
    }
    return t2;
}

/* Swing_DLL.xex 0x887A76F0: if_get u32@lbl_88D45A60, u32@0x1b0, u32@0x6c, u32@0x50, interlocked_inc, u32@0x60 */
ts4_word ts4_if_get_u32_lbl_88D45A60_887A76F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p10;
    ts4_word loc50[2];
    ts4_word t4;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t4 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 432))) + 108))) + 80);
    if ((ts4_word)t4 != 0) {
        _InterlockedIncrement((volatile long *)(ts4_word)((t4 + 4)));
        t7 = fn_88608590((ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 96)));
        ts4_call_seq_u32_off0_881B1A98((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)t7);
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t4);
        p10 = (ts4_word)1;
    } else {
        p10 = (ts4_word)0;
    }
    return p10;
}

/* Swing_DLL.xex 0x889D33D0: loop_addr lbl_88CA1E00, u32@0x20, u32@0x24, u8@0x28, u32@0x2c, u32@0x30 */
void ts4_loop_addr_lbl_88CA1E00_889D33D0(void)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p3;

    c1 = (ts4_word)16;
    lv2 = (ts4_word)(ts4_word)lbl_88CA1E00;
    do {
        *(ts4_word *)((char *)(ts4_word)(lv2) + 32) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(lv2) + 36) = (ts4_word)8363;
        *(unsigned char *)((char *)(ts4_word)(lv2) + 40) = (unsigned char)255;
        *(ts4_word *)((char *)(ts4_word)(lv2) + 44) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(lv2) + 48) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)((lv2 + 52)) + 0) = (ts4_word)0;
        p3 = (ts4_word)(lv2 + 52);
        lv2 = p3;
    } while (--c1 != 0);
    return;
}
