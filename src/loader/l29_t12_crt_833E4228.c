/* Loader_DLL.xex 0x833E4228-0x833E4324, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _wcsicmp with locale-aware folding. */
typedef unsigned long ts4l_u32;
typedef struct Ts4lLoc { char pad[0x14]; unsigned f14; } Ts4lLoc;
extern ts4l_u32 *ts4_if_call_seq_fn_833E8350_833E9F90(void);
extern void fn_833E9D50(ts4l_u32 *e);
extern int ts4_if_fn_833E5E28(int c, void *loc);
extern Ts4lLoc *lbl_8352CA04;

int ts4l_crt_wcsicmp_l_833E4228(const unsigned short *a, const unsigned short *b)
{
    int f, l;
    ts4l_u32 *e;
    if (a == 0) {
        e = ts4_if_call_seq_fn_833E8350_833E9F90();
        *e = 22;
        fn_833E9D50(e);
        return 0x7fffffff;
    }
    if (b == 0) {
        e = ts4_if_call_seq_fn_833E8350_833E9F90();
        *e = 22;
        fn_833E9D50(e);
        return 0x7fffffff;
    }
    if (lbl_8352CA04->f14 == 0) {
        do {
            f = (unsigned short)((*a >= 'A' && *a <= 'Z') ? *a + 32 : *a);
            l = (unsigned short)((*b >= 'A' && *b <= 'Z') ? *b + 32 : *b);
            a++;
            b++;
        } while ((unsigned short)f != 0 && (unsigned short)f == (unsigned short)l);
    } else {
        a--;
        b--;
        do {
            f = ts4_if_fn_833E5E28(*++a, &lbl_8352CA04);
            l = ts4_if_fn_833E5E28(*++b, &lbl_8352CA04);
        } while ((unsigned short)f != 0 && (unsigned short)f == (unsigned short)l);
    }
    return (int)(unsigned short)f - (int)(unsigned short)l;
}
