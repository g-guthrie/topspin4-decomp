/* 0x88480FB8: From n at +0x1c, writes out->count = 6n and out->bytes = (2n + 6n) * 8 + align4(n); the second argument is unused. */
/* Matched on /Oc (agAH). 6n read into a local first and reused in the byte sum; writing n*6 twice is 11 off. */
typedef struct SizeReq { unsigned int bytes; unsigned int count; } SizeReq;
typedef struct Mesh { char pad[0x1c]; unsigned int n; } Mesh;
void fn_88480FB8(Mesh *m, void *unused, SizeReq *out)
{
    unsigned int n = m->n;
    unsigned int c = n * 6;
    out->count = c;
    out->bytes = (n * 2 + c) * 8 + ((n + 3) & ~3);
}
