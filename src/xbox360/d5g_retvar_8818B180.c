/* Swing_DLL.xex 0x8818B180-0x8818B380, executable version 0.0.0.3. */
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

extern char lbl_880DD020[];
ts4_word fn_88199068();

/* Swing_DLL.xex 0x8818B180: if_call_seq fn_88199068, u32@0x4, u32@0x8, lbl_880DD020, u8@0xc, u32@0x10 */
ts4_word ts4_if_call_seq_fn_88199068_8818B180(void)
{
    ts4_word r_ = 0;
    ts4_word loc50[4];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)40, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)0;
        *(unsigned char *)((char *)(ts4_word)(t1) + 12) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)1024;
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880DD020;
        *(ts4_word *)((char *)(ts4_word)(t1) + 20) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 24) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 28) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 32) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 36) = (ts4_word)1;
        r_ = t1;
    }
    return r_;
}
