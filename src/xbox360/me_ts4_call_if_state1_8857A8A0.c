/* 0x8857A8A0: returns E_FAIL unless state (+4) is 1, then forwards to fn_88583188 */
/* Matched on /Os plain and LTCG (work/army/ME/v.py chk). */
typedef struct { int x0; int state; } O;
int fn_88583188(O *o);
int ts4_call_if_state1_8857A8A0(O *o)
{
    int r = 0x80004005;
    if (o->state == 1) r = fn_88583188(o);
    return r;
}
