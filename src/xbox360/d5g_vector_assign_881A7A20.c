/* Swing_DLL.xex 0x881A7A20-0x881A7BE0, executable version 0.0.0.3. */
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

ts4_word fn_881A9BE8();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881884E0();

/* Swing_DLL.xex 0x881A7A20: loop_call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x8, u32@0x0, u32@0x0 */
ts4_word ts4_vector_assign_881A7A20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv16;
    ts4_word lv17;
    ts4_word p20;
    ts4_word p21;
    ts4_word p32;
    ts4_word lv33;
    ts4_word p36;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t30;
    ts4_word t10;
    ts4_word t12;
    ts4_word t13;
    ts4_word t14;
    ts4_word n1;
    ts4_word m1;
    ts4_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != (ts4_word)a0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t7 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        n1 = (ts4_word)((int)(t7 - t5) / (int)48);
        m1 = (ts4_word)((int)(t8 - t6) / (int)48);
        if ((ts4_word)((int)(t7 - t5) / (int)48) > m1) {
            if (n1 != 0) {
                t30 = ts4_if_call_seq_u32_lbl_88D45B38_881884E0((ts4_word)(a0 + 8), n1, (ts4_word)t6);
                p32 = (ts4_word)t30;
            } else {
                p32 = (ts4_word)0;
            }
            lv33 = (ts4_word)t5;
            while ((ts4_word)lv33 != (ts4_word)t7) {
                if ((int)((p32 - t5) + lv33) != 0) {
                    memcpy((ts4_word)((p32 - t5) + lv33), (ts4_word)lv33, (ts4_word)48);
                }
                p36 = (ts4_word)(lv33 + 48);
                lv33 = p36;
            }
            ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p32;
            *(ts4_word *)((char *)(ts4_word)((a0 + 8)) + 0) = (ts4_word)(((n1 + (n1 << 1)) << 4) + p32);
        } else {
            t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
            if ((ts4_word)((int)(t10 - t6) / (int)48) >= n1) {
                fn_881A9BE8((ts4_word)t5, (ts4_word)t7, (ts4_word)t6);
            } else {
                fn_881A9BE8((ts4_word)t5, (ts4_word)(((((int)(t10 - t6) / (int)48) + (((int)(t10 - t6) / (int)48) << 1)) << 4) + t5), (ts4_word)t6);
                t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
                t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
                t14 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
                t15 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
                lv16 = (ts4_word)t12;
                lv17 = (ts4_word)(((((int)(t12 - t13) / (int)48) + (((int)(t12 - t13) / (int)48) << 1)) << 4) + t14);
                while ((ts4_word)lv17 != (ts4_word)t15) {
                    if ((ts4_word)lv16 != 0) {
                        memcpy((ts4_word)lv16, (ts4_word)lv17, (ts4_word)48);
                    }
                    p20 = (ts4_word)(lv16 + 48);
                    p21 = (ts4_word)(lv17 + 48);
                    lv16 = p20;
                    lv17 = p21;
                }
            }
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(((n1 + (n1 << 1)) << 4) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    }
    return a0;
}
