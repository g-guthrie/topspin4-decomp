/* 0x885DA0D0: when the status is STATUS_PENDING (0x103), waits on the event at +4 and on success takes the final status from +0x1C; always clears the busy flag at +0x20 */
/* Matched on /Oc /Os (agAH).  */
long KeWaitForSingleObject(void *obj, int reason, int mode, int alertable, void *timeout);
typedef struct Req { int pad; char ev[0x18]; long status; int busy; } Req;
long fn_885DA0D0(Req *r, long st)
{
    if (st == 0x103) {
        st = KeWaitForSingleObject(r->ev, 3, 0, 0, 0);
        if (st >= 0)
            st = r->status;
    }
    r->busy = 0;
    return st;
}
