/* 0x885A9BD8: returns total/per plus n times the count from fn_885BDF00 */
/* Matched on /Os (agAH). /Os without /Oc: keeps the twllei trap and the /Os register choice. */
typedef struct Pg { char pad[0x24]; unsigned short a; unsigned short b; unsigned short per; char pad2a[0xa]; unsigned int total; } Pg;
unsigned short fn_885BDF00(unsigned short b, unsigned short a);
unsigned int fn_885A9BD8(Pg *p, unsigned int n)
{
    unsigned int c = fn_885BDF00(p->b, p->a);
    return p->total / p->per + c * n;
}
