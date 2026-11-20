/* 0x8841A850: aligned allocation through fn_8841A510: over-allocates align+size+16, aligns up, and writes a 16-byte header {0x02345656, align+size, tag, offset back to the raw block} just before the returned pointer */
/* Matched on /Oc (agAH).  */
typedef struct AlignHdr { unsigned int magic; unsigned int size; unsigned int tag; unsigned int offset; } AlignHdr;
char *fn_8841A510(void *heap, unsigned int size, unsigned int tag);
void *fn_8841A850(void *heap, unsigned int align, unsigned int size, unsigned int tag)
{
    unsigned int total = align + size;
    char *raw = fn_8841A510(heap, total + 0x10, tag);
    char *p = (char *)((unsigned int)(raw + align + 0xf) & ~(align - 1));
    AlignHdr *h = (AlignHdr *)p - 1;
    h->magic = 0x02345656;
    h->size = total;
    h->tag = tag;
    h->offset = p - raw;
    return p;
}
