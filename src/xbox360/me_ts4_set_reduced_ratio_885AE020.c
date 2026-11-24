/* 0x885AE020: Stores num/den at +0x148/+0x14c, then divides both by their GCD (subtraction GCD, run only while the first value is > 0) when the GCD is non-zero. */
/* Matched on /Oc (agAH). Inline Gcd(a, b) helper; written inline, the declaration order of the two locals picks which mr comes first. */
typedef struct Clock { char pad[0x148]; int num; int den; } Clock;
static __forceinline int Gcd(int a, int b)
{
    while (a > 0) {
        if (a < b) { int t = a; a = b; b = t; }
        a -= b;
    }
    return b;
}
void fn_885AE020(Clock *c, int num, int den)
{
    int g;
    c->num = num;
    c->den = den;
    g = Gcd(num, den);
    if (g != 0) {
        c->num = num / g;
        c->den = den / g;
    }
}
