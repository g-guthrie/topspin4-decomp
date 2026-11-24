/* 0x883DECF0: when initialised, raises the quit flag, sleeps 1 ms while the worker is still busy, joins ts4_io_worker_run_883DEB98 through fn_88332760, closes the two handles and frees the buffer */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); returns the join result (0 when not initialised). */
typedef struct Mgr { int p0; void *heap; } Mgr;
extern Mgr *lbl_88B3302C;
extern char lbl_88039468[];
extern void *lbl_88CAC98C;
extern void *lbl_88CAC990;
extern void *lbl_88CAC994;
extern int lbl_88CAC998;
extern int lbl_88CAC99C;
extern unsigned char lbl_88CAC9A4;
void ts4_call_seq_fn_8857AFE8_8831A8F0(int ms);
int fn_88332760(void (*fn)(void));
void ts4_if_call_seq_lbl_88028EA4_8831ACF0(void *h, int a);
void fn_88315F10(void *heap, void *buf, const char *file, int line);
void ts4_io_worker_run_883DEB98(void);
int ts4_worker_shutdown_883DECF0(void)
{
    int r = 0;
    if (lbl_88CAC9A4) {
        lbl_88CAC998 = 1;
        while (lbl_88CAC99C)
            ts4_call_seq_fn_8857AFE8_8831A8F0(1);
        r = fn_88332760(ts4_io_worker_run_883DEB98);
        if (lbl_88CAC994) {
            ts4_if_call_seq_lbl_88028EA4_8831ACF0(lbl_88CAC994, 0);
            lbl_88CAC994 = 0;
        }
        if (lbl_88CAC990) {
            ts4_if_call_seq_lbl_88028EA4_8831ACF0(lbl_88CAC990, 0);
            lbl_88CAC990 = 0;
        }
        if (lbl_88CAC98C) {
            fn_88315F10(lbl_88B3302C->heap, lbl_88CAC98C, lbl_88039468, 0x774);
            lbl_88CAC98C = 0;
        }
        lbl_88CAC9A4 = 0;
    }
    return r;
}
