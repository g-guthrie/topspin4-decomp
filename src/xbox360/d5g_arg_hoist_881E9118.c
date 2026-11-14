/* Swing_DLL.xex 0x881E9118-0x881E9318, executable version 0.0.0.3. */
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

extern char lbl_88D41FC0[];
extern char lbl_88D45A1F[];
ts4_word ts4_if_atomic_interlocked_dec_881876D0();
ts4_word fn_88198CE0();
ts4_word fn_88199068();
ts4_word fn_881C38D0();
ts4_word fn_881EE128();
ts4_word fn_881FBA58();
ts4_word fn_8820B418();

/* Swing_DLL.xex 0x881E9118: if_get u32@0x4, fn_881FBA58, fn_88199068, fn_8820B418, interlocked_inc, u32@0x4 */
ts4_word ts4_if_get_u32_off4_881E9118(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word m_;
    ts4_word p6;
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word loc58[2];
    ts4_word loc60[4];
    ts4_word t2;
    ts4_word t24;
    ts4_word t3;
    ts4_word t4;
    ts4_word t14;
    ts4_word t15;
    ts4_word t16;
    ts4_word t17;
    ts4_word t18;

    m_ = (*(ts4_word *)((char *)(ts4_word)(a1) + 4)) + 5160;
    t2 = fn_881FBA58((ts4_word)(m_), (ts4_word)a2, (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t2 != 0) {
        t24 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t24;
        if ((ts4_word)t24 != 0) {
            _InterlockedIncrement((volatile long *)(ts4_word)((t24 + 4)));
            return a0;
        }
        return a0;
    }
    loc60[0] = (ts4_word)1000;
    loc60[1] = (ts4_word)0;
    t3 = fn_88199068((ts4_word)0, (ts4_word)68, (ts4_word)(ts4_word)&loc60[0]);
    if ((ts4_word)t3 != 0) {
        t4 = fn_8820B418((ts4_word)t3);
        p6 = (ts4_word)t4;
    } else {
        p6 = (ts4_word)0;
    }
    loc50[0] = (ts4_word)p6;
    if ((ts4_word)p6 != 0) {
        _InterlockedIncrement((volatile long *)(ts4_word)((p6 + 4)));
    }
    fn_881C38D0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 4)) + 5560), (ts4_word)(ts4_word)&loc50[0]);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 0))) + 32))))((ts4_word)p6, (ts4_word)a2);
    t14 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D41FC0));
    t15 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(unsigned char *)lbl_88D45A1F = (unsigned char)1;
    t16 = fn_881EE128((ts4_word)(t15 + 5160), (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(t16) + 0) = (ts4_word)p6;
    t17 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(unsigned char *)lbl_88D45A1F = (unsigned char)0;
    t18 = *(ts4_word *)((char *)(ts4_word)(t17) + 5560);
    if ((ts4_word)t18 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t18);
        *(ts4_word *)((char *)(ts4_word)(t17) + 5560) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p6;
    _InterlockedIncrement((volatile long *)(ts4_word)((p6 + 4)));
    fn_88198CE0((ts4_word)t14);
    ts4_if_atomic_interlocked_dec_881876D0((ts4_word)p6);
    return a0;
}
