/* 0x8841E5D0: reads a magnitude and a sign flag from the source at +8 through fn_8841DDB0 and stores the signed value; returns the reader */
/* Matched on /Oc (agAH). 64-bit callee return truncated to int; the sign flag is a plain char. */
typedef struct Rd { int a; int b; void *src; } Rd;
unsigned long long fn_8841DDB0(void *src, char *neg);
Rd *fn_8841E5D0(Rd *r, int *out)
{
    char neg;
    int v = (int)fn_8841DDB0(r->src, &neg);
    *out = neg ? -v : v;
    return r;
}
