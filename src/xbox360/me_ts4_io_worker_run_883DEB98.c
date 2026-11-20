/* 0x883DEB98: I/O worker body (joined by ts4_worker_shutdown_883DECF0): under the queue lock, takes each job from the head of the queue, runs it unlocked (read via fn_883DDA00, write via fn_883DE760, or flush via fn_883DE180/fn_883DC3C0) and completes it, until the quit flag is raised (then sets it to 2) or a completion fails */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); keeps the busy counter at 0x88CAC99C raised while running; returns the completion error. */
typedef struct Job { struct Job *next; char p4[8]; void *file; unsigned char write; char p11[3]; void *buf; void *p18; void *p1c; unsigned int flags; int p24; int p28; } Job;
extern Job lbl_88B3B4B8;
extern void *lbl_88CAC994;
extern int lbl_88CAC998;
extern int lbl_88CAC99C;
void ts4_if_call_seq_RtlEnterCriticalSection_8831AD58(void *cs);
void ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98(void *cs);
void fn_883DE180(void *file, int a, int b, int c);
void fn_883DC3C0(void *file, int b, int c, int d);
int fn_883DE760(void *file, unsigned int flags, void *buf, void *a, void *b);
int fn_883DDA00(void *file, unsigned int flags, int a, void *buf, void *b);
void fn_883DCA00(Job *j, int r);
int fn_883DCC58(Job *j, int r);
int ts4_io_worker_run_883DEB98(void)
{
    int r = 0;
    void *cs;
    Job *j;
    ++lbl_88CAC99C;
    cs = lbl_88CAC994;
    ts4_if_call_seq_RtlEnterCriticalSection_8831AD58(cs);
    for (j = lbl_88B3B4B8.next; j != &lbl_88B3B4B8; j = lbl_88B3B4B8.next) {
        if (lbl_88CAC998 >= 1) {
            lbl_88CAC998 = 2;
            r = 0;
            break;
        }
        ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98(cs);
        if (j->write) {
            if (!j->buf && !j->p18 && !j->p1c) {
                fn_883DE180(j->file, 0, j->p24, j->p28);
                fn_883DC3C0(j->file, j->p24, j->p28, 1);
            } else {
                r = fn_883DE760(j->file, j->flags, j->buf, j->p18, j->p1c);
            }
        } else {
            r = fn_883DDA00(j->file, j->flags | 0x10000, 0, j->buf, j->p18);
        }
        fn_883DCA00(j, r);
        ts4_if_call_seq_RtlEnterCriticalSection_8831AD58(cs);
        r = fn_883DCC58(j, r);
        if (r) break;
    }
    ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98(cs);
    --lbl_88CAC99C;
    return r;
}
