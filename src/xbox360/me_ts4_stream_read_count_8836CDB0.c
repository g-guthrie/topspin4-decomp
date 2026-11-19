/* 0x8836CDB0: fread-style wrapper: calls fn_883194F0(stream, dst, size, count, &got) and returns got when the result is 0 or 0x16, else -1. */
/* Matched on /Oc (agAH). The fifth fn_883194F0 argument is an optional out count (other callers pass 0). */
int fn_883194F0(void *stream, void *dst, unsigned int size, unsigned int count, unsigned int *outRead);
int fn_8836CDB0(void *dst, unsigned int size, unsigned int count, void *stream)
{
    unsigned int got;
    int r = fn_883194F0(stream, dst, size, count, &got);
    if (r == 0 || r == 0x16)
        return got;
    return -1;
}
