/* 0x8841E630: long overload of 8841E5D0 (same code) */
/* Matched on /Oc (agAH).  */
typedef struct Rd { int a; int b; void *src; } Rd;
unsigned long long fn_8841DDB0(void *src, char *neg);
Rd *fn_8841E630(Rd *r, long *out)
{
    char neg;
    int v = (int)fn_8841DDB0(r->src, &neg);
    *out = neg ? -v : v;
    return r;
}
