/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset.
   FAM4 variants: void returns, repeated member reads (MSVC turns the
   re-read of a tested pointer into `clrrwi rX,rY,0`), the inlined
   reference-counted string release of fam4_refstr.h. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;

extern char lbl_88D459D4[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B38[];
ts4_word ts4_if_tail_fn_8858B180_88581C90();
ts4_word fn_8860D360();
ts4_word fn_8860DBC8();
ts4_word fn_88614938();
ts4_word ts4_if_set_u32_off314_887993C8();
ts4_word fn_887ADEB8();
ts4_word fn_88865708();
ts4_word ts4_loop_call_seq_u32_off30_8886B150();
ts4_word fn_8886BB78();
ts4_word fn_888E4EF8();
ts4_word ts4_find_service();
ts4_word ts4_if_get_u32_off0_888F5A98();

/* Swing_DLL.xex 0x887AE088: if_call_seq u32@lbl_88D45B1C, u32@0x2cc, u8@0x9, u32@0x234, u32@0x4, u32@0x38 */
void ts4_if_call_seq_u32_lbl_88D45B1C_887AE088(ts4_word a0)
{
    ts4_word t1;
    int t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t10;
    ts4_word t12;
    ts4_word t14;
    ts4_word t17;
    ts4_word t20;

    t1 = *(ts4_word *)lbl_88D45B1C;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 716);
    if ((int)t2 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t2) + 9)) != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 564);
        t5 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
        t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 56);
        fn_887ADEB8((ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((((*(ts4_word *)((char *)(ts4_word)(t6) + 0)) + ((int)t5 * 176)) + t6)) + 12)), (ts4_word)1);
        t10 = *(ts4_word *)((char *)(ts4_word)(t4) + 56);
        t12 = *(ts4_word *)((char *)(ts4_word)((((*(ts4_word *)((char *)(ts4_word)(t10) + 0)) + ((int)t5 * 176)) + t10)) + 12);
        ts4_if_set_u32_off314_887993C8((ts4_word)a0, (ts4_word)t12);
        t14 = ts4_find_service((ts4_word)((279773184) | 64090));
        ts4_if_get_u32_off0_888F5A98((ts4_word)t14, (ts4_word)t12, (ts4_word)1);
        fn_888E4EF8((ts4_word)t14);
        t17 = *(ts4_word *)lbl_88D459D4;
        if ((ts4_word)t17 != 0) {
            ts4_loop_call_seq_u32_off30_8886B150((ts4_word)t17, (ts4_word)((55902208) | 14141), (ts4_word)1);
            fn_88865708((ts4_word)t17);
            t20 = fn_88614938((ts4_word)t4, (ts4_word)t12);
            if ((ts4_word)t20 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t20) + 26)) != 0) {
                fn_8886BB78((ts4_word)t17, (ts4_word)(t12 + 1));
                ts4_loop_call_seq_u32_off30_8886B150((ts4_word)t17, (ts4_word)((55902208) | 14141), (ts4_word)0);
            }
        }
    }
    return;
}

/* Swing_DLL.xex 0x88884DE0: if_call_seq u32@lbl_88D45B38, fn_8860D360, ts4_if_tail_fn_8858B180_88581C90, fn_8860DBC8 */
void ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    if ((ts4_word)a0 != 0) {
        t2 = fn_8860D360((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)a0);
        if ((ts4_word)t2 != 0) {
            fn_8860DBC8((ts4_word)t2, (ts4_word)a0);
        } else {
            ts4_if_tail_fn_8858B180_88581C90((ts4_word)a0, (ts4_word)a1);
        }
    }
    return;
}
