/* 0x8840B630: computes the 16-byte-aligned base, skew and padded size of chunk i of n (last chunk uses its own length) */
/* Matched on /Oc (agAH).  */
typedef struct Span { unsigned int base; unsigned int size; unsigned char skew; } Span;
typedef struct Lay { char pad[0x40]; unsigned int origin; char pad44[0x14]; unsigned int stride; unsigned int last; unsigned int offset; } Lay;
void fn_8840B630(Lay *l, int i, int n, Span *s)
{
    unsigned int addr = i * l->stride + l->offset + l->origin;
    unsigned int len;
    s->skew = (unsigned char)(addr & 0xF);
    s->base = addr & ~0xF;
    len = (i == n - 1) ? l->last : l->stride;
    s->size = (s->skew + len + 15) & ~15;
}
