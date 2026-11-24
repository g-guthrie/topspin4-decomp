/* 0x886EBB70: renderer: performance counter divided by its frequency, as double seconds (fn_8857AFF0 counter, fn_8857B010 frequency) */
/* Matched on /Oc (LTCG) (agAL). LTCG route, first try. */
extern int fn_8857AFF0(long long *count);
extern int fn_8857B010(long long *freq);

double ts4_elapsed_seconds_886EBB70(void)
{
    long long count, freq;
    fn_8857AFF0(&count);
    fn_8857B010(&freq);
    return (double)count / (double)freq;
}
