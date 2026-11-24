/* 0x883E7828: reads two words (+0, +4) through fn_883194F0(stream, dst, 4, 1, 0) and byte-swaps the second when version < 0x300000; keeps fn_ name (callee of 0x883EC308) */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct Hdr { unsigned int magic; unsigned int value; } Hdr;
int fn_883194F0(void *stream, void *dst, unsigned int size, unsigned int count, int a);
int fn_883E7828(Hdr *h, void *stream, unsigned int version)
{
    int r = fn_883194F0(stream, &h->magic, 4, 1, 0);
    if (r)
        return r;
    r = fn_883194F0(stream, &h->value, 4, 1, 0);
    if (r)
        return r;
    if (version < 0x300000) {
        unsigned int w = h->value;
        h->value = ((w & 0xff) << 24) | ((w & 0xff00) << 8) | ((w >> 8) & 0xff00) | ((unsigned char *)&h->value)[0];
    }
    return 0;
}
