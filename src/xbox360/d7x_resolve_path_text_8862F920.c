/* Swing_DLL.xex 0x8862F920-0x8862F9C8, executable version 0.0.0.3. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;

extern char lbl_880F75A4[];
extern char lbl_880F75AC[];
extern char lbl_88D45B1C[];
ts4_word fn_8816CAA0(ts4_word, ts4_word);
ts4_word ts4_format_text(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word);

ts4_word ts4_resolve_path_text_8862F920(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p11;
    struct { char unused[48]; char text[1032]; } loc80;
    ts4_word t2;
    ts4_word t5;
    ts4_word t10;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 568);
    p6 = (ts4_word)0;
    if ((ts4_word)t2 != 0) {
        t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 40))))((ts4_word)t2, (ts4_word)a0, (ts4_word)a1);
        p6 = (ts4_word)t5;
    }
    p11 = (ts4_word)p6;
    if ((ts4_word)(p6 & 0xff) == 0) {
        fn_8816CAA0((ts4_word)a1, (ts4_word)(ts4_word)lbl_880F75A4);
        ts4_format_text((ts4_word)(ts4_word)loc80.text, (ts4_word)1024, (ts4_word)(ts4_word)lbl_880F75AC, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)a0);
        t10 = fn_8816CAA0((ts4_word)a1, (ts4_word)(ts4_word)loc80.text);
        p11 = (ts4_word)t10;
    }
    return p11;
}
