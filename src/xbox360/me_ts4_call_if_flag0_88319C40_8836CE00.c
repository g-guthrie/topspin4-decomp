/* 0x8836CE00: forwards (a, (signed char)c) to fn_88319C40 when bit 0 of +0x188 is set; -1 otherwise */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
/* The extsw r4 says fn_88319C40 takes a 64-bit second argument here. */
typedef struct { char pad[0x188]; unsigned int flags; } O;
int fn_88319C40(O *o, long long a, int c);
int ts4_call_if_flag0_88319C40_8836CE00(O *o, int a, int c)
{
    if (o->flags & 1) return fn_88319C40(o, a, (signed char)c);
    return -1;
}
