/* 0x88424050: rounds 3*n up to a power of two (minimum 4) and forwards it to fn_88423E28 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
int fn_88423E28(void *o, int cap);
int ts4_grow_capacity_pow2_88424050(void *o, int n)
{
    int need = n * 3;
    int cap = 4;
    while (cap < need) cap *= 2;
    return fn_88423E28(o, cap);
}
