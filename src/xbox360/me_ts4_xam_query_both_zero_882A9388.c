/* 0x882A9388: runs XAM in-process call 2 and returns its error */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); on success stores whether both outputs are zero. */
unsigned ts4_xam_in_process_call_882A92D8(int id, int *a, int *b);
unsigned ts4_xam_query_both_zero_882A9388(int *out)
{
    int a, b;
    unsigned r = ts4_xam_in_process_call_882A92D8(2, &a, &b);
    if (!r)
        *out = a == 0 && b == 0;
    return r;
}
