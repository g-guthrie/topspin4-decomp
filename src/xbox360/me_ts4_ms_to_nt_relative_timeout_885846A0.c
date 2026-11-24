/* 0x885846A0: converts a millisecond wait to a negative 100ns NT timeout; -1 (infinite) returns NULL */
/* Matched on /Os plain and LTCG (work/army/ME/v.py chk). */
long long *ts4_ms_to_nt_relative_timeout_885846A0(long long *out, int ms)
{
    if (ms == -1) return 0;
    *out = (long long)(unsigned int)ms * -10000;
    return out;
}
