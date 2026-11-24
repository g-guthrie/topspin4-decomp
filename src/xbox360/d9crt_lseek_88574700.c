/* Swing_DLL.xex 0x88574700-0x885747C8, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _lseeki64_nolock. */
typedef unsigned int u32;
typedef struct IoInfo {
    int osfhnd;
    char osfile;
    char pad[0x48 - 5];
} IoInfo;
extern IoInfo *lbl_88D4E000[];
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern int fn_88574A70(int fh);
extern u32 fn_8857BA40(int handle, u32 lo, int *hi, int method);
extern u32 ts4_tailcall_fn_88582660_8857B840(void);
extern void fn_88567F48(u32 oserr);

long long ts4_crt_lseeki64_nolock_88574700(int fh, long long pos, int mthd)
{
    int h;
    u32 lo;
    u32 *e;
    long long lpos = pos;
    h = fn_88574A70(fh);
    if (h == -1) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 9;
        return -1;
    }
    lo = fn_8857BA40(h, *((u32 *)&lpos + 1), (int *)&lpos, mthd);
    *((u32 *)&lpos + 1) = lo;
    if (lo == (u32)-1) {
        u32 err = ts4_tailcall_fn_88582660_8857B840();
        if (err != 0) {
            fn_88567F48(err);
            return -1;
        }
    }
    (lbl_88D4E000[fh >> 5] + (fh & 31))->osfile &= ~2;
    return lpos;
}
