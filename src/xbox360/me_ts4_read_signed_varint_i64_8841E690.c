/* 0x8841E690: 64-bit overload of 8841E5D0: stores the signed magnitude with std */
/* Matched on /Oc (agAH).  */
typedef struct Rd { int a; int b; void *src; } Rd;
unsigned long long fn_8841DDB0(void *src, char *neg);
Rd *fn_8841E690(Rd *r, long long *out)
{
    char neg;
    long long v = (long long)fn_8841DDB0(r->src, &neg);
    *out = neg ? -v : v;
    return r;
}
