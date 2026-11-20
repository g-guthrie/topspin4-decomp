/* 0x8857A878: returns 0x3e4 (ERROR_IO_INCOMPLETE) while status is 0x3e5 (pending), else the result at +0x18 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
/* ts4_tailcall_fn_88582660_8857B840 is declared (void) in cx32_game_b.c; here it is passed 0x3e4 in r3. */
typedef struct { unsigned int status; int pad[5]; int result; } O;
int ts4_tailcall_fn_88582660_8857B840(int err);
int ts4_overlapped_status_8857A878(O *o)
{
    int r = 0x3e4;
    if (!o) return ts4_tailcall_fn_88582660_8857B840(r);
    if (o->status != 0x3e5) r = o->result;
    return r;
}
