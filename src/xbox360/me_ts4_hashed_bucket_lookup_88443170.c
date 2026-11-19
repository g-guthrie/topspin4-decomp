/* 0x88443170: bucket = key >> (32 - bits); reads a u8 or u16 slot from the bucket's index table and returns data + slot * stride, 0 when empty or -1 */
/* Matched on /Oc (agAH). An index-table local gives offset-first lbzx/lhzx; the shared return 0 needs the nested if. */
typedef struct Bucket { char p[0x11]; unsigned char narrow; char p2[0xe]; unsigned char *index; unsigned int istride; char *data; unsigned int dstride; char p3[8]; } Bucket;
typedef struct T { char p[0x30]; unsigned int bits; Bucket *buckets; } T;
void *fn_88443170(T *t, unsigned int key)
{
    Bucket *b = &t->buckets[key >> (32 - t->bits)];
    if (b->index) {
        unsigned char *ix = b->index;
        unsigned int off = (key & (0xFFFFFFFFu >> t->bits)) * b->istride;
        int v;
        if (b->narrow == 1)
            v = ix[off];
        else
            v = *(unsigned short *)(ix + off);
        if (v != -1)
            return b->data + b->dstride * v;
    }
    return 0;
}
