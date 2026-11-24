/* 0x8841E500: 16-bit overload of 8841E5D0 */
/* Matched on /Oc (agAH). The sign choice is an if/else with two stores; the ternary form merges them. */
typedef struct Rd { int a; int b; void *src; } Rd;
unsigned long long fn_8841DDB0(void *src, char *neg);
Rd *fn_8841E500(Rd *r, short *out)
{
    char neg;
    short v = (short)fn_8841DDB0(r->src, &neg);
    if (neg)
        *out = -v;
    else
        *out = v;
    return r;
}
