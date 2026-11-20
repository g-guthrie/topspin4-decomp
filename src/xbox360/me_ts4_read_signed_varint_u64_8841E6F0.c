/* 0x8841E6F0: unsigned 64-bit overload of 8841E5D0 (same code as the signed 64-bit one) */
/* Matched on /Oc (agAH).  */
typedef struct Rd { int a; int b; void *src; } Rd;
unsigned long long fn_8841DDB0(void *src, char *neg);
Rd *fn_8841E6F0(Rd *r, unsigned long long *out)
{
    char neg;
    unsigned long long v = (unsigned long long)fn_8841DDB0(r->src, &neg);
    *out = neg ? -v : v;
    return r;
}
