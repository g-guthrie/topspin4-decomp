/* 0x8847B650: Initialises a descriptor {quad[4] = 0, data = &src->data (+0xc), stride 12}, then copies the 16-byte quad at src+0x18 into it. */
/* Matched on /Oc (agAH). Init through an inline helper, then a 16-byte struct assignment (gives the dead addi r8 of the copy source). */
typedef struct Quad { int v[4]; } Quad;
typedef struct Desc { Quad q; void *data; unsigned int stride; } Desc;
typedef struct Src { char pad[0xc]; char data[0xc]; Quad q; } Src;
static __forceinline void Desc_Init(Desc *d, void *data, unsigned int stride)
{
    d->q.v[0] = 0; d->q.v[1] = 0; d->q.v[2] = 0; d->q.v[3] = 0;
    d->data = data;
    d->stride = stride;
}
void fn_8847B650(Src *s, Desc *d)
{
    Desc_Init(d, s->data, 0xc);
    d->q = s->q;
}
