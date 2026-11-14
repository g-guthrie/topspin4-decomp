/* Swing_DLL.xex 0x88633470-0x88633524, executable version 0.0.0.3. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;

extern void ts4_loop_set_fn_8857C8C8_8862F6D8(void);
extern char lbl_880F75B8[];
extern char lbl_88D45B38[];
ts4_word fn_8857B598(ts4_word, ts4_word);
ts4_word fn_88883CD0(ts4_word);
ts4_word ts4_loop_call_seq_fn_88563230_88884B20(ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word ts4_format_text(ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word ts4_if_call_seq_fn_88883CD0_8860D250(ts4_word);
ts4_word ts4_resume_thread(ts4_word);
ts4_word ts4_tailcall_fn_88582F30_8857A128(ts4_word, ts4_word);

ts4_word ts4_start_named_thread_88633470(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    struct { char unused[0x20]; char text[0x80]; } line;
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;
    ts4_word t12;

    t2 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)(*(ts4_word *)lbl_88D45B38));
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)t2;
    t3 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t3 != 0) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 16));
    } else {
        p5 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)p5;
    ts4_format_text((ts4_word)(ts4_word)line.text, (ts4_word)128, (ts4_word)(ts4_word)lbl_880F75B8, (ts4_word)a1);
    t7 = ts4_loop_call_seq_fn_88563230_88884B20((ts4_word)ts4_loop_set_fn_8857C8C8_8862F6D8, (ts4_word)a0, (ts4_word)(ts4_word)line.text, (ts4_word)(131072));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t7;
    fn_8857B598((ts4_word)t7, (ts4_word)a1);
    ts4_resume_thread((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    t12 = ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)-1);
    return t12;
}
