/* 0x8818A210: Compares two 16-byte keys with a size word: both empty means compare the first pointer; otherwise sizes must match and the 16 bytes must be equal. */
/* Near miss (agAH): /Oc, 3 off: the target turns the memcmp result into a branchy li 1/beqlr/li 0, where ours uses cntlzw/extrwi. */
#pragma intrinsic(memcmp)
int memcmp(const void *a, const void *b, unsigned int n);
typedef struct Key { union { void *ptr; unsigned char bytes[16]; } u; unsigned int size; } Key;
unsigned char fn_8818A210(const Key *a, const Key *b)
{
    if (a->size == 0) {
        if (b->size != 0)
            return 0;
        return a->u.ptr == b->u.ptr;
    }
    if (b->size == 0 || a->size != b->size)
        return 0;
    return memcmp(a->u.bytes, b->u.bytes, 16) == 0;
}
