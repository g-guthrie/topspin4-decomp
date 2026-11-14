/* Small functions produced by the asm2c translator (FAM4 fork) and verified
   byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360, MSVC 16.00.10224.00).
   FAM5: near misses of the translator fixed by a per-function search over
   source-level variants (commutative operand order, int-widened byte/half
   locals, address of a parameter instead of a stack copy, a named pointer
   for a repeated base+offset, ||/&& conditions kept in a bool temporary,
   ...).  In .cpp files a function whose first argument is `this` is a member
   of a one-function struct ts4_obj_<ADDR>: MSVC orders the operands of
   commutative instructions differently for `this` than for a plain argument.
   The original address is in the comment above each definition. Parameters
   are untyped words (a0 = this/first argument); field accesses are by byte
   offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;

extern char g_ts4_script_constants[];
extern char lbl_88D41FC4[];
ts4_word fn_8817ED58();
ts4_word fn_8817F4E8();
ts4_word ts4_if_call_seq_u32_off0_8819B0C8();
ts4_word fn_881AA7A0();
ts4_word fn_881EC8C8();
ts4_word fn_88608590();
ts4_word ts4_call_seq_u32_off0_8819AD80();

/* Swing_DLL.xex 0x8817E578: if_call_seq u32@0x8, u32@0x4, u32@0x0, fn_8817ED58, u32@0x8, u32@0x4 */
void ts4_if_call_seq_u32_off8_8817E578(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word q80;
    ts4_word t5;
    ts4_word t6;

    q80 = a0 + 36;
    if ((ts4_word)(a2 & 0xff) != 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)((q80)) + 8);
        t6 = *(ts4_word *)((char *)(ts4_word)((q80)) + 4);
        if ((ts4_word)t6 != (ts4_word)t5) {
            if ((ts4_word)t6 != 0) {
                *(ts4_word *)((char *)(ts4_word)(t6) + 0) = (ts4_word)a1;
            }
            *(ts4_word *)((char *)(ts4_word)((q80)) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)((q80)) + 4)) + 4);
            return;
        }
        fn_8817F4E8((ts4_word)(q80), (ts4_word)t6, (ts4_word)(ts4_word)&a1, (ts4_word)1);
        return;
    }
    fn_8817ED58((ts4_word)(q80), (ts4_word)(*(ts4_word *)((char *)(ts4_word)((q80)) + 0)), (ts4_word)(ts4_word)&a1);
    return;
}

/* Swing_DLL.xex 0x8820F068: if_get ts4_if_call_seq_u32_off0_8819B0C8, u32@0x50, fn_88608590, u32@0x54, fn_881AA7A0, u32@0x50 */
void ts4_if_get_fn_8819B0C8_8820F068(ts4_word a0)
{
    ts4_word q80;
    ts4_word p14;
    ts4_word loc50[6];
    ts4_word t3;
    int t6;
    ts4_word t9;
    ts4_word t10;
    ts4_word t15;
    ts4_word t17;
    float t18;
    ts4_word t19;

    q80 = a0 + 80;
    ts4_if_call_seq_u32_off0_8819B0C8((ts4_word)(q80));
    t3 = fn_88608590((ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 80)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)t3;
    fn_881AA7A0((ts4_word)(ts4_word)&loc50[0]);
    t6 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 80))) + -12);
    if ((int)t6 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)t6;
        *(float *)((char *)(ts4_word)(a0) + 96) = (*(float *)g_ts4_script_constants);
    } else {
        t9 = *(unsigned short *)((char *)(ts4_word)(a0) + 32);
        t10 = *(ts4_word *)lbl_88D41FC4;
        if ((ts4_word)((t9 >> 1) & 0x3ff) != 1023) {
            p14 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 4))) + 5092))) + (((t9 >> 1) & 0x3ff) << 2)));
        } else {
            p14 = (ts4_word)0;
        }
        t15 = fn_881EC8C8((ts4_word)t10, (ts4_word)(q80), (ts4_word)(ts4_word)&loc50[0], (ts4_word)p14);
        if ((ts4_word)(t15 & 0xff) != 0) {
            t17 = loc50[1];
            if ((ts4_word)t17 != 0) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)t17;
            }
            t18 = *(float *)((char *)loc50 + 8);
            t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
            *(float *)((char *)(ts4_word)(a0) + 96) = t18;
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t19) + 92))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
        }
    }
    ts4_call_seq_u32_off0_8819AD80((ts4_word)(ts4_word)&loc50[0]);
    return;
}
