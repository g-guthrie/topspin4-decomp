/* 0x88423600: free-list init: slots = buf, head = 0x80000000, last = bytes/16 - 1, then every one of the bytes/16 64-bit slots set to -1 */
/* Near miss (agAH): 1 off: stdx operand order only (target r10,r11,r9 = offset first). Pointer, void*, unsigned and offset-accumulator spellings tried. */
typedef struct FreeList { long long *slots; unsigned int head; int last; } FreeList;
void fn_88423600(FreeList *f, long long *buf, unsigned int bytes)
{
    int n = bytes >> 4;
    int i;
    f->slots = buf;
    f->head = 0x80000000;
    f->last = n - 1;
    for (i = 0; i < n; i++)
        f->slots[i] = -1;
}
