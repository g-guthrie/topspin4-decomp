/* Swing_DLL.xex 0x8861E9C0-0x8861EB08, executable version 0.0.0.3. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;

extern void fn_88617958(void);
extern char lbl_880F759C[];
extern char lbl_880F75E0[];
extern char lbl_88C47594[];
extern char lbl_88D45B38[];
ts4_word fn_8857B598(ts4_word, ts4_word);
ts4_word fn_8857B6D8(ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word fn_88618998(ts4_word, ts4_word);
ts4_word fn_88883CD0(ts4_word);
ts4_word ts4_loop_call_seq_fn_88563230_88884B20(ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word ts4_format_text(ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word ts4_if_call_seq_fn_88883CD0_8860D250(ts4_word);
ts4_word ts4_resume_thread(ts4_word);
ts4_word ts4_tailcall_fn_88582F30_8857A128(ts4_word, ts4_word);

ts4_word ts4_spawn_formatted_task_8861E9C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p18;
    struct { char unused[0x20]; char text[0x80]; } line;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    int t11;
    ts4_word t13;
    int t15;
    ts4_word t16;
    ts4_word t25;
    ts4_word t31;

    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    t1 = fn_8857B6D8((ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t1;
    t2 = fn_8857B6D8((ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t2;
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)1;
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 40);
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 44);
    if ((ts4_word)t3 != 0) {
        t6 = fn_88618998((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)t3);
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t6;
    }
    if ((ts4_word)t4 != 0) {
        t9 = fn_88618998((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)t4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t9;
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((int)t11 == 0) {
        t13 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)(*(ts4_word *)lbl_88D45B38));
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t13;
    }
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((int)t15 == 0) {
        t16 = fn_88883CD0((ts4_word)0);
        if ((ts4_word)t16 != 0) {
            p18 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t16) + 16));
        } else {
            p18 = (ts4_word)0;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)p18;
    }
    ts4_format_text((ts4_word)(ts4_word)lbl_88C47594, (ts4_word)16, (ts4_word)(ts4_word)lbl_880F759C, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    ts4_format_text((ts4_word)(ts4_word)line.text, (ts4_word)128, (ts4_word)(ts4_word)lbl_880F75E0, (ts4_word)(ts4_word)lbl_88C47594);
    t25 = ts4_loop_call_seq_fn_88563230_88884B20((ts4_word)fn_88617958, (ts4_word)a0, (ts4_word)(ts4_word)line.text, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t25;
    fn_8857B598((ts4_word)t25, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20)));
    ts4_resume_thread((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t31 = ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)-1);
    return t31;
}
