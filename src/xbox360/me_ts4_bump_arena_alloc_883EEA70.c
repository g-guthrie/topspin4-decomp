/* 0x883EEA70: Bump allocation from {?, size (+4), base (+8), cur (+0xc)}: returns cur and advances it by n rounded up to 4 when cur < base + size and the advanced cur stays within it; 0 for n == 0 or no room. */
/* Matched on /Oc /Os (agAH). Built /Os: on /Oc the cur store is scheduled before the mr r3 (2 off). Single result variable; the end and the rounded size are computed before cur is read. */
typedef struct BumpArena { int unk0; unsigned int size; char *base; char *cur; } BumpArena;
void *fn_883EEA70(BumpArena *a, int n)
{
    void *r = 0;
    if (n != 0) {
        char *end = a->base + a->size;
        unsigned int aligned = (n + 3) & ~3;
        char *p = a->cur;
        if (p < end && p + aligned <= end) {
            r = p;
            a->cur = p + aligned;
        }
    }
    return r;
}
