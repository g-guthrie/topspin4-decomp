/* 0x88162C60: returns whether the byte vectors a and b (begin/end) have the same size and contents. */
/* Matched on /Oc (agAF). size == size && memcmp(...) == 0 with #pragma intrinsic(memcmp) gives the inline compare loop. */
#pragma intrinsic(memcmp)
int memcmp(const void *a, const void *b, unsigned int n);
typedef struct V { unsigned char *begin; unsigned char *end; } V;
unsigned char fn_88162C60(V *a, V *b)
{
    unsigned int n = a->end - a->begin;
    return n == (unsigned int)(b->end - b->begin) && memcmp(a->begin, b->begin, n) == 0;
}
