/* Swing_DLL.xex 0x881E7948-0x881FB6A0, executable version 0.0.0.3. */
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

extern char fn_88AFF268[];
extern char lbl_880C1320[];
extern char lbl_88D41FC0[];
extern char lbl_88D4D8E4[];
extern char lbl_88D4D8E8[];
ts4_word fn_88198CE0();
ts4_word fn_881EEB38();
ts4_word fn_881FB3F0();
ts4_word fn_881FB4A0();
ts4_word fn_881FBA58();
ts4_word fn_88563470();
ts4_word ts4_assign_text_from_c_string();

/* Swing_DLL.xex 0x881E7948: if_get u32@0x4, fn_881FBA58, u32@0x4, u32@0x0, interlocked_inc, u32@0x0 */
ts4_word ts4_if_get_u32_off4_881E7948(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word m_;
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word loc58[2];
    ts4_word t2;
    ts4_word t3;

    m_ = (*(ts4_word *)((char *)(ts4_word)(a1) + 4)) + 828;
    t2 = fn_881FBA58((ts4_word)(m_), (ts4_word)a2, (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t2 == 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
        if ((ts4_word)t3 != 0) {
            _InterlockedIncrement((volatile long *)(ts4_word)((t3 + 4)));
        }
    }
    return a0;
}

/* Swing_DLL.xex 0x881E8F80: if_get u32@0x4, fn_881FBA58, u32@0x0, u32@0x4, u32@0x0, interlocked_inc */
ts4_word ts4_if_get_u32_off4_881E8F80(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word m_;
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word loc58[2];
    ts4_word t2;
    ts4_word t3;

    m_ = (*(ts4_word *)((char *)(ts4_word)(a1) + 4)) + 5160;
    t2 = fn_881FBA58((ts4_word)(m_), (ts4_word)a2, (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
        if ((ts4_word)t3 != 0) {
            _InterlockedIncrement((volatile long *)(ts4_word)((t3 + 4)));
        }
    } else {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    }
    return a0;
}

/* Swing_DLL.xex 0x881E9010: if_get u32@0x4, fn_881FBA58, u32@0x0, u32@0x4, u32@0x0, interlocked_inc */
ts4_word ts4_if_get_u32_off4_881E9010(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word m_;
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word loc58[2];
    ts4_word t2;
    ts4_word t3;

    m_ = (*(ts4_word *)((char *)(ts4_word)(a1) + 4)) + 5104;
    t2 = fn_881FBA58((ts4_word)(m_), (ts4_word)a2, (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
        if ((ts4_word)t3 != 0) {
            _InterlockedIncrement((volatile long *)(ts4_word)((t3 + 4)));
        }
    } else {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    }
    return a0;
}

/* Swing_DLL.xex 0x881EAFB8: if_call_seq u32@lbl_88D41FC0, fn_88198CE0, u32@0x4, fn_881EEB38, lbl_88D4D8E4, u32@lbl_88D4D8E8 */
ts4_word ts4_if_call_seq_u32_lbl_88D41FC0_881EAFB8(ts4_word a0, ts4_word a1)
{
    ts4_word m_;
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word loc58[2];
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D41FC0));
    m_ = (*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 492;
    t4 = fn_881EEB38((ts4_word)(m_), (ts4_word)a1, (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t4 == 0) {
        t7 = *(ts4_word *)lbl_88D4D8E8;
        if ((ts4_word)(t7 & 0x1) == 0) {
            *(volatile ts4_word *)lbl_88D4D8E8 = (ts4_word)(t7 | 1);
            ts4_assign_text_from_c_string((ts4_word)(ts4_word)lbl_88D4D8E4, (ts4_word)(ts4_word)lbl_880C1320);
            fn_88563470((ts4_word)(ts4_word)fn_88AFF268);
        }
        fn_88198CE0((ts4_word)t2);
        return (ts4_word)lbl_88D4D8E4;
    }
    fn_88198CE0((ts4_word)t2);
    return (t4 + 4);
}

/* Swing_DLL.xex 0x881FB3F0: if_get u32@0x8, fn_881FBA58, u32@0x10, u32@0x10, u32@0x0, fn_881FB3F0 */
ts4_word ts4_if_get_u32_off8_881FB3F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word m_;
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word loc58[2];
    ts4_word t2;
    ts4_word t6;
    int t4;

    m_ = (*(ts4_word *)((char *)(ts4_word)(a1) + 8)) + 56;
    t2 = fn_881FBA58((ts4_word)(m_), (ts4_word)a2, (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t2 != 0) {
        t6 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t6;
        if ((ts4_word)t6 != 0) {
            _InterlockedIncrement((volatile long *)(ts4_word)((t6 + 4)));
            return a0;
        }
        return a0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    if ((int)t4 != 0) {
        fn_881FB3F0((ts4_word)a0, (ts4_word)t4, (ts4_word)a2);
        return a0;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x881FB4A0: if_get u32@0x8, fn_881FBA58, u32@0x10, u32@0x10, u32@0x0, fn_881FB4A0 */
ts4_word ts4_if_get_u32_off8_881FB4A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word m_;
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word loc58[2];
    ts4_word t2;
    ts4_word t6;
    int t4;

    m_ = (*(ts4_word *)((char *)(ts4_word)(a1) + 8)) + 224;
    t2 = fn_881FBA58((ts4_word)(m_), (ts4_word)a2, (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t2 != 0) {
        t6 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t6;
        if ((ts4_word)t6 != 0) {
            _InterlockedIncrement((volatile long *)(ts4_word)((t6 + 4)));
            return a0;
        }
        return a0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    if ((int)t4 != 0) {
        fn_881FB4A0((ts4_word)a0, (ts4_word)t4, (ts4_word)a2);
        return a0;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return a0;
}
