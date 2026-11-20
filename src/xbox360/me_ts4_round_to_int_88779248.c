/* 0x88779248: renderer: round to nearest int as (int)floor(x + 0.5f). */
/* Matched on /Oc (LTCG) (agAL). The 0.5f is a literal: on LTCG without pp1_pool_primer.c it lands at __pool@_0 = lbl_8814B910. */
double floor(double x);

int ts4_round_to_int_88779248(float x)
{
    return (int)(float)floor(x + 0.5f);
}
