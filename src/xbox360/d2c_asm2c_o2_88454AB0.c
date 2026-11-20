/* Swing_DLL.xex 0x88454AB0-0x88524080, executable version 0.0.0.3. */
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

extern char lbl_88082540[];
extern char lbl_88082644[];
extern char lbl_8808338C[];
extern char lbl_88084A14[];
extern char lbl_88087F04[];
extern char lbl_88CACF08[];
ts4_word KeTlsGetValue();
ts4_word fn_8841A510();
ts4_word fn_8841A590();
ts4_word ts4_call_seq_fn_88467768_884544F8();
ts4_word fn_88462090();
ts4_word ts4_call_seq_fn_88466AB0_88467768();
ts4_word ts4_if_call_seq_lbl_88083354_88477588();
ts4_word ts4_addr_lbl_88084264_8847EF68();
ts4_word fn_88534058();
ts4_word fn_88534240();

/* Swing_DLL.xex 0x88454AB0: if_get u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_88462090, u32@0xc */
ts4_word ts4_if_get_u32_lbl_88CACF08_88454AB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t5;
    ts4_word t8;
    ts4_word t18;
    ts4_word t19;
    ts4_word t14;
    ts4_word t15;
    ts4_word t16;
    ts4_word t10;
    ts4_word t11;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    if ((ts4_word)a3 != 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a2) + 12);
        t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 12))))((ts4_word)t5, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        if ((ts4_word)t8 >= 1) {
            if ((ts4_word)t8 != 1) {
                if ((ts4_word)t8 >= 3) {
                    return 0;
                }
                t18 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
                t19 = fn_8841A510((ts4_word)t18, (ts4_word)128, (ts4_word)31);
                *(unsigned short *)((char *)(ts4_word)(t19) + 4) = (unsigned short)128;
                ts4_call_seq_fn_88466AB0_88467768((ts4_word)t19, (ts4_word)a0, (ts4_word)a1, (ts4_word)a3);
                *(ts4_word *)((char *)(ts4_word)(t19) + 0) = (ts4_word)(ts4_word)lbl_88082540;
                return t19;
            }
            t14 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
            t15 = fn_8841A510((ts4_word)t14, (ts4_word)56, (ts4_word)31);
            *(unsigned short *)((char *)(ts4_word)(t15) + 4) = (unsigned short)56;
            t16 = fn_88462090((ts4_word)t15, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
            return t16;
        }
        t10 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t11 = fn_8841A510((ts4_word)t10, (ts4_word)144, (ts4_word)31);
        *(unsigned short *)((char *)(ts4_word)(t11) + 4) = (unsigned short)144;
        ts4_call_seq_fn_88467768_884544F8((ts4_word)t11, (ts4_word)a1, (ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
        *(ts4_word *)((char *)(ts4_word)(t11) + 0) = (ts4_word)(ts4_word)lbl_88082644;
        return t11;
    }
    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)56, (ts4_word)31);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)56;
    t4 = fn_88462090((ts4_word)t3, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
    return t4;
}





