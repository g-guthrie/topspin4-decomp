/* 0x883CA810: forwards the on/off state to the handle at q+0x18, then on a falling edge of flag 0x2000 (+0x60) stamps +0x50 with the manager clock and on a rising edge calls fn_883C7508, then stores the flag */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); the edge tests are written as two full conditions (flag && !on, !flag && on); the target reuses the masked flag for the second test. */
typedef struct Mgr { int p0, p4; __int64 now; } Mgr;
extern Mgr *lbl_88B3302C;
typedef struct Q { char pad[0x18]; void *h; } Q;
typedef struct T { char pad[0x50]; __int64 stamp; char p58[8]; unsigned int flags; char p64[0xAC - 0x64]; Q *q; } T;
int ts4_call_then_conditionally_forward_result_88317B90(void *h, unsigned char on);
int fn_883C7508(T *t);
int ts4_set_active_flag_883CA810(T *t, unsigned char on)
{
    int r;
    if (t->q ? t->q->h : 0) {
        r = ts4_call_then_conditionally_forward_result_88317B90(t->q ? t->q->h : 0, on);
        if (r) return r;
    }
    if ((t->flags & 0x2000) && !on) {
        t->stamp = lbl_88B3302C->now;
    } else if (!(t->flags & 0x2000) && on) {
        r = fn_883C7508(t);
        if (r) return r;
    }
    t->flags &= ~0x2000;
    if (on) t->flags |= 0x2000;
    return 0;
}
