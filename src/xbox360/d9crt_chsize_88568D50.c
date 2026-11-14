/* Swing_DLL.xex 0x88568D50-0x88568EE4, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _chsize_nolock. */
typedef unsigned int u32;
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern u32 *ts4_if_call_seq_fn_8856CD88_88567F10(void);
extern long long fn_88574700(int fh, long long pos, int whence);
extern int fn_88574A70(int fh);
extern int fn_8856C300(int fh, int mode);
extern int fn_885687F8(int fh, const void *buf, u32 count);
extern void *ts4_get_u32_lbl_88D4E11C_88581A90(void);
extern void *fn_885805C0(void *heap, u32 flags, u32 size);
extern int fn_88580EB8(void *heap, u32 flags, void *block);
extern int fn_8857BE98(int handle);
extern u32 ts4_tailcall_fn_88582660_8857B840(void);

int ts4_crt_chsize_nolock_88568D50(int fh, long long size)
{
    long long place;
    long long filend;
    long long extend;
    int cnt;
    int oldmode;
    long long retval = 0;
    char *bl;
    u32 *e;

    place = fn_88574700(fh, 0, 1);
    if (place == -1 || (filend = fn_88574700(fh, 0, 2)) == -1)
        return *ts4_if_call_seq_fn_8856CD88_88567ED8();
    extend = size - filend;
    if (extend > 0) {
        bl = (char *)fn_885805C0(ts4_get_u32_lbl_88D4E11C_88581A90(), 8, 0x1000);
        if (bl == 0) {
            e = ts4_if_call_seq_fn_8856CD88_88567ED8();
            *e = 12;
            return *ts4_if_call_seq_fn_8856CD88_88567ED8();
        }
        oldmode = fn_8856C300(fh, 0x8000);
        do {
            cnt = (extend >= 0x1000) ? 0x1000 : (int)extend;
            cnt = fn_885687F8(fh, bl, cnt);
            if (cnt == -1) {
                if (*ts4_if_call_seq_fn_8856CD88_88567F10() == 5)
                    *ts4_if_call_seq_fn_8856CD88_88567ED8() = 13;
                retval = -1;
                break;
            }
            extend -= cnt;
        } while (extend > 0);
        fn_8856C300(fh, oldmode);
        fn_88580EB8(ts4_get_u32_lbl_88D4E11C_88581A90(), 0, bl);
    } else if (extend < 0) {
        if (fn_88574700(fh, size, 0) == -1)
            return *ts4_if_call_seq_fn_8856CD88_88567ED8();
        retval = fn_8857BE98(fn_88574A70(fh)) ? 0 : -1;
        if (retval == -1) {
            u32 *d;
            *ts4_if_call_seq_fn_8856CD88_88567ED8() = 13;
            d = ts4_if_call_seq_fn_8856CD88_88567F10();
            *d = ts4_tailcall_fn_88582660_8857B840();
        }
    }
    if (retval == -1)
        return *ts4_if_call_seq_fn_8856CD88_88567ED8();
    if (fn_88574700(fh, place, 0) == -1)
        return *ts4_if_call_seq_fn_8856CD88_88567ED8();
    return 0;
}
