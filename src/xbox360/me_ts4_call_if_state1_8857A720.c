/* 0x8857A720: returns E_FAIL unless state (+4) is 1, then forwards to fn_885830C0 */
/* Matched on /Os plain and LTCG (work/army/ME/v.py chk). */
typedef struct { int x0; int state; } O;
int fn_885830C0(O *o);
int ts4_call_if_state1_8857A720(O *o)
{
    int r = 0x80004005;
    if (o->state == 1) r = fn_885830C0(o);
    return r;
}
