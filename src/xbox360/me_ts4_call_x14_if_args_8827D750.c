/* 0x8827D750: forwards (b, n) to the handle at +0x14 unless either is zero; -1 otherwise */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char pad[0x14]; void *h; } O;
int fn_88568A40(void *h, void *b, int n);
int ts4_call_x14_if_args_8827D750(O *o, void *b, int n)
{
    int r = -1;
    if (n != 0 && b != 0) r = fn_88568A40(o->h, b, n);
    return r;
}
