typedef unsigned int W8bU32;
extern void *fn_88562DC0(void *dst, void *src, W8bU32 n);
typedef struct W8bVec { char *first; char *last; } W8bVec;
static __inline char *w8b_copy(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        W8bU32 n = (W8bU32)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}
struct W8bEnt30 { unsigned char pad00[0x6c]; W8bU32 *p6c; unsigned char pad70[0x2c]; };
struct W8bEntSet { unsigned char pad00[0x38]; W8bVec v; unsigned char pad40[0x6c - 0x40]; W8bU32 *ptrs[1]; };

void ts4_clear_pointer_slots_8867C350(struct W8bEntSet *o)
{
    int i;
    W8bVec *v;
    for (i = 0; i < 4; i++) {
        int k;
        for (k = 0; k < 5; k++) {
            W8bU32 *p = *(W8bU32 **)((char *)o + 0x6c + (i * 5 + k) * 0x30);
            if (p != 0)
                *p = 0;
        }
    }
    v = &o->v;
    v->last = w8b_copy(v->last, v->last, v->first);
}
