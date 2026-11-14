/* Small functions produced by the asm2c translator (FAM4/FAM5 fork) and verified
   byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360, MSVC 16.00.10224.00).
   FAM6: FAM5 near misses fixed by a per-function hill climb over source-level
   variants. Besides FAM5's mutations (operand order, retyped locals, volatile
   reloads, statement swaps, if/else inversion, members for `this`), it uses:
   a ||/&& condition kept in an unsigned char/int temporary; compound
   assignment; resized/reordered stack arrays; a load hoisted out of both
   branches or above a store; strlen() instead of an inline byte scan (the
   intrinsic returns through `clrrwi`); a one-word struct argument read from
   memory (also `clrrwi`). Callers and callees sit in different files.
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

extern "C" {
extern char __imp_VdGlobalDevice[];
extern char __imp_VdGlobalXamDevice[];
ts4_word KeGetCurrentProcessType();
ts4_word fn_881B9148(ts4_word);
ts4_word fn_88292698(ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word fn_883A3218(ts4_word);
ts4_word fn_883A3950(ts4_word, ts4_word);
ts4_word ts4_if_atomic_interlocked_dec_88288530(ts4_word);
ts4_word ts4_if_call_seq_u32_off880_883632B8(ts4_word, ts4_word);

}
/* Swing_DLL.xex 0x883637B0: loop_call_seq u32@0x20, u32@0x110, fn_883A3950, u8@0x87d, ts4_if_call_seq_u32_off880_883632B8, u32@0x20 */
struct ts4_obj_883637B0 { ts4_word ts4_loop_call_seq_u32_off20_883637B0(); };
ts4_word ts4_obj_883637B0::ts4_loop_call_seq_u32_off20_883637B0()
{
    ts4_word a0 = (ts4_word)this;
    unsigned char t3;
    ts4_word t6;
    unsigned char t8;

    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 272) = (ts4_word)0;
    fn_883A3950((ts4_word)a0, (ts4_word)0);
    t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 2173);
    if ((ts4_word)t3 == 0) {
        do {
            ts4_if_call_seq_u32_off880_883632B8((ts4_word)a0, (ts4_word)0);
            t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 1264);
            *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)(32 + (char *)(ts4_word)(a0)))) + 272) += t6;
            t8 = *(unsigned char *)((char *)(ts4_word)(a0) + 2173);
        } while ((ts4_word)t8 == 0);
    }
    fn_883A3218((ts4_word)a0);
    return 0;
}

/* Swing_DLL.xex 0x88424D08: if_get u32@0x8, u32@0x10, u32@0x14, u32@0x0, u32@0xc, vcall */
struct ts4_obj_88424D08 { ts4_word ts4_if_get_u32_off8_88424D08(ts4_word a1); };
ts4_word ts4_obj_88424D08::ts4_if_get_u32_off8_88424D08(ts4_word a1)
{
    ts4_word a0 = (ts4_word)this;
    ts4_word loc50[4];
    ts4_word p7;

    if ((ts4_word)(*(ts4_word *)(8 + (char *)(ts4_word)(a1))) != 0) {
        p7 = (ts4_word)(((ts4_word (*)(ts4_word, void *))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((void *)((*(ts4_word *)((char *)(ts4_word)(a1) + 8))))) + 0))) + 12))))((ts4_word)(ts4_word)&loc50[0], ((void *)((*(ts4_word *)((char *)(ts4_word)(a1) + 8))))));
    } else {
        p7 = (ts4_word)(ts4_word)&loc50[0];
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)(((*(ts4_word *)(20 + (char *)(ts4_word)(a1))) - (*(volatile ts4_word *)((char *)(ts4_word)(a1) + 16))) != 0);
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(p7) + 0));
    return a0;
}

/* Swing_DLL.xex 0x8861D090: if_get u32@0x1c, u32@0x24, u32@0x20, u32@0x0, u32@0x68, vcall */
struct ts4_obj_8861D090 { void ts4_if_get_u32_off1c_8861D090(ts4_word a1, ts4_word a2, int a3, ts4_word a4, int a5, ts4_word a6); };
void ts4_obj_8861D090::ts4_if_get_u32_off1c_8861D090(ts4_word a1, ts4_word a2, int a3, ts4_word a4, int a5, ts4_word a6)
{
    ts4_word a0 = (ts4_word)this;
    ts4_word t210;
    unsigned char b80;
    short p6;
    ts4_word loc50[4];
    int t1;
    ts4_word t2;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    loc50[0] = (ts4_word)t1;
    loc50[1] = (ts4_word)t3;
    loc50[2] = (ts4_word)t2;
    b80 = !((ts4_word)t1 != 0) || ((ts4_word)t3 == (ts4_word)((983040) | 65535));
    p6 = (ts4_word)b80;
    if (0 == (ts4_word)(p6 & 0xff)) {
        t210 = (*(volatile ts4_word *)((char *)(ts4_word)((((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 0))))) + 104));
        ((ts4_word (*)(ts4_word, ts4_word))((t210)))((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    fn_881B9148((ts4_word)(a0 + 16));
    return;
}

/* Swing_DLL.xex 0x88719EB0: if_call_seq u32@0x10, KeGetCurrentProcessType, u32@__imp_VdGlobalDevice, u32@__imp_VdGlobalXamDevice, u32@0x8, u32@0x0 */
struct ts4_obj_88719EB0 { void ts4_if_call_seq_u32_off10_88719EB0(); };
void ts4_obj_88719EB0::ts4_if_call_seq_u32_off10_88719EB0()
{
    ts4_word a0 = (ts4_word)this;
    ts4_word t111;
    ts4_word p5;
    int t1;
    int t2;
    ts4_word t6;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;

    t1 = *(ts4_word *)(16 + (char *)(ts4_word)(a0));
    if ((int)t1 != 0) {
        t2 = KeGetCurrentProcessType();
        if ((int)t2 == 2) {
            t111 = (*(ts4_word *)__imp_VdGlobalXamDevice);
            p5 = (ts4_word)t111;
        } else {
            p5 = (ts4_word)(*(ts4_word *)__imp_VdGlobalDevice);
        }
        t7 = *(volatile ts4_word *)((char *)(ts4_word)(p5) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
        if ((ts4_word)t6 != 0) {
            fn_88292698((ts4_word)t7, (ts4_word)t6, (ts4_word)5, (ts4_word)0);
        }
        t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        if ((ts4_word)t10 != 0) {
            t11 = ts4_if_atomic_interlocked_dec_88288530((ts4_word)t10);
            if ((ts4_word)t11 == 0) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
            }
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    }
    return;
}

/* Swing_DLL.xex 0x889C6258: if_get u32@0x0, u32@0x8, u32@0x0, u32@0x8, u8@0x0 */
struct ts4_obj_889C6258 { void ts4_if_get_u32_off0_889C6258(int a1); };
void ts4_obj_889C6258::ts4_if_get_u32_off0_889C6258(int a1)
{
    ts4_word a0 = (ts4_word)this;
    ts4_word t2;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(ts4_word *)(0 + (char *)(ts4_word)(t1));
    if ((int)t2 >= (int)t3) {
        return;
    }
    t4 = *(unsigned char *)((char *)(ts4_word)(t1) + t2);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t2 + 1);
    *(volatile unsigned char *)(0 + (char *)(ts4_word)(a1)) = (unsigned char)t4;
    return;
}

/* Swing_DLL.xex 0x889C62C8: if_get u32@0x0, u32@0x8, u32@0x0, u8@0x1, u8@0x2, u8@0x3 */
struct ts4_obj_889C62C8 { void ts4_if_get_u32_off0_889C62C8(ts4_word a1); };
void ts4_obj_889C62C8::ts4_if_get_u32_off0_889C62C8(ts4_word a1)
{
    ts4_word a0 = (ts4_word)this;
    ts4_word t1;
    int t2;
    int t3;
    unsigned char t4;
    unsigned char t6;
    unsigned char t5;
    unsigned char t7;

    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    if ((int)t2 >= (int)t3) {
        return;
    }
    t4 = *(unsigned char *)((char *)(ts4_word)(t1) + t2);
    t5 = *(unsigned char *)((char *)(ts4_word)((t1 + t2)) + 1);
    t6 = *(unsigned char *)((char *)(ts4_word)((t1 + t2)) + 2);
    t7 = *(unsigned char *)((char *)(ts4_word)((t2 + t1)) + 3);
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)t4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t2 + 4);
    *(unsigned char *)((char *)(ts4_word)(a1) + 1) = (unsigned char)t5;
    *(unsigned char *)((char *)(ts4_word)(a1) + 2) = (unsigned char)t6;
    *(unsigned char *)(3 + (char *)(ts4_word)(a1)) = (unsigned char)t7;
    return;
}
