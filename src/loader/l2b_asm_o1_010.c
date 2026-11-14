/* Loader_DLL.xex 0x8318B048-0x8318B248, executable version 0.0.0.3. */
/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Loader_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

ts4_word fn_83188F68();
ts4_word fn_8318AA00();
ts4_word fn_8318B098();

/* Loader_DLL.xex 0x8318B048: if_call_seq fn_8318AA00, fn_83188F68 */
ts4_word ts4l_if_call_seq_fn_8318AA00_8318B048(ts4_word a0, ts4_word a1)
{

    fn_8318AA00((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83188F68((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8318B1E8: if_call_seq fn_8318B098, fn_8318AA00, fn_83188F68 */
ts4_word ts4l_if_call_seq_fn_8318B098_8318B1E8(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p2;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;
    ts4_word t1;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)a1 == 0) {
        p5 = (ts4_word)a0;
        if ((ts4_word)a2 != 0) {
            fn_8318AA00((ts4_word)a2);
            t4 = fn_83188F68((ts4_word)a2);
            p5 = (ts4_word)t4;
        }
        p6 = (ts4_word)p5;
    } else {
        p2 = (ts4_word)a0;
        if ((ts4_word)a2 != 0) {
            t1 = fn_8318B098((ts4_word)a2, (ts4_word)3);
            p2 = (ts4_word)t1;
        }
        p6 = (ts4_word)p2;
    }
    return p6;
}
