/* Swing_DLL.xex 0x8817A8D0-0x8817AA90, executable version 0.0.0.3. */
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

ts4_word fn_88178268();
ts4_word fn_88179D88();
ts4_word fn_8817B310();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88162AE0();

/* Swing_DLL.xex 0x8817A8D0: loop_call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x8, u32@0x0, u32@0x0 */
ts4_word ts4_vector_assign_8817A8D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv16;
    ts4_word lv17;
    ts4_word p20;
    ts4_word p21;
    ts4_word lv27;
    ts4_word p29;
    ts4_word p37;
    ts4_word lv39;
    ts4_word p42;
    ts4_word lv48;
    ts4_word p50;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t36;
    ts4_word t46;
    ts4_word t47;
    ts4_word t10;
    ts4_word t25;
    ts4_word t26;
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
        n1 = (ts4_word)((int)(t7 - t5) / (int)40);
        m1 = (ts4_word)((int)(t8 - t6) / (int)40);
        if ((ts4_word)((int)(t7 - t5) / (int)40) > m1) {
            if (n1 != 0) {
                t36 = ts4_if_call_seq_u32_lbl_88D45B38_88162AE0((ts4_word)(a0 + 8), n1, (ts4_word)t6);
                p37 = (ts4_word)t36;
            } else {
                p37 = (ts4_word)0;
            }
            lv39 = (ts4_word)t5;
            while ((ts4_word)lv39 != (ts4_word)t7) {
                if ((int)((p37 - t5) + lv39) != 0) {
                    fn_88179D88((ts4_word)((p37 - t5) + lv39), (ts4_word)lv39);
                }
                p42 = (ts4_word)(lv39 + 40);
                lv39 = p42;
            }
            t46 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
            t47 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
            lv48 = (ts4_word)t46;
            while ((ts4_word)lv48 != (ts4_word)t47) {
                fn_88178268((ts4_word)lv48);
                p50 = (ts4_word)(lv48 + 40);
                lv48 = p50;
            }
            ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p37;
            *(ts4_word *)((char *)(ts4_word)((a0 + 8)) + 0) = (ts4_word)(((n1 + (n1 << 2)) << 3) + p37);
        } else {
            t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
            if ((ts4_word)((int)(t10 - t6) / (int)40) >= n1) {
                t25 = fn_8817B310((ts4_word)t5, (ts4_word)t7, (ts4_word)t6);
                t26 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
                lv27 = (ts4_word)t25;
                while ((ts4_word)lv27 != (ts4_word)t26) {
                    fn_88178268((ts4_word)lv27);
                    p29 = (ts4_word)(lv27 + 40);
                    lv27 = p29;
                }
            } else {
                fn_8817B310((ts4_word)t5, (ts4_word)(((((int)(t10 - t6) / (int)40) + (((int)(t10 - t6) / (int)40) << 2)) << 3) + t5), (ts4_word)t6);
                t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
                t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
                t14 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
                t15 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
                lv16 = (ts4_word)t12;
                lv17 = (ts4_word)(((((int)(t12 - t13) / (int)40) + (((int)(t12 - t13) / (int)40) << 2)) << 3) + t14);
                while ((ts4_word)lv17 != (ts4_word)t15) {
                    if ((ts4_word)lv16 != 0) {
                        fn_88179D88((ts4_word)lv16, (ts4_word)lv17);
                    }
                    p20 = (ts4_word)(lv16 + 40);
                    p21 = (ts4_word)(lv17 + 40);
                    lv16 = p20;
                    lv17 = p21;
                }
            }
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(((n1 + (n1 << 2)) << 3) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    }
    return a0;
}
