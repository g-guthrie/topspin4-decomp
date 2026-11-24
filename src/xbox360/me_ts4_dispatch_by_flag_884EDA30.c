/* 0x884EDA30: calls fn_884ED5F8(d, o, b) when c is nonzero, else fn_884ED968(d, o) */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
int fn_884ED5F8(void *d, void *o, void *b);
int fn_884ED968(void *d, void *o);
int ts4_dispatch_by_flag_884EDA30(void *o, void *b, char c, void *d)
{
    if (c) return fn_884ED5F8(d, o, b);
    return fn_884ED968(d, o);
}
