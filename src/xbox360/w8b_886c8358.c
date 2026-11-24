typedef unsigned int W8bU32;
extern void *fn_88562DC0(void *dst, void *src, W8bU32 n);
typedef struct W8bBVec { char *first; char *last; } W8bBVec;
static __inline char *w8b_mcopy(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        W8bU32 n = (W8bU32)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}
struct W8bItem;
typedef struct W8bPair { W8bU32 a; struct W8bItem *b; } W8bPair;
typedef struct W8bPVec { W8bPair *begin; W8bPair *end; } W8bPVec;
static W8bPair *w8b_copy8(W8bPair *src, W8bPair *src_end, W8bPair *dest)
{
    int n = (int)((char *)src_end - (char *)src) >> 3;
    for (; n > 0; --n) {
        dest->a = src->a;
        dest->b = src->b;
        ++src;
        ++dest;
    }
    return dest;
}
struct W8bVtD { unsigned char pad00[0x34]; void (*slot34)(void *self, void *item); };
struct W8bObjD { struct W8bVtD *vt; };
struct W8bItem { unsigned char pad00[8]; W8bU32 w08; W8bU32 w0c; unsigned char pad10[0xc]; W8bBVec v1c; } W8bItem;
typedef struct W8bOwner {
    unsigned char pad00[0x5c]; W8bPVec items; unsigned char pad64[0x148 - 0x64]; struct W8bObjD *sink;
} W8bOwner;
extern void ts4_if_call_seq_u32_off2c_88646210(void *item);

void ts4_release_all_items_886C8358(W8bOwner *self)
{
    int pd0 = 0, pd1 = 0, pd2 = 0, pd3 = 0, pd4 = 0, pd5 = 0;
    W8bPVec *v = &self->items;
    int n = (int)((char *)v->end - (char *)v->begin) >> 3;
    int i;
    W8bU32 zero;
    for (i = 0; i < n; i++) {
        struct W8bItem *it = v->begin[i].b;
        W8bBVec *iv = &it->v1c;
        iv->last = w8b_mcopy(iv->last, iv->last, iv->first);
        ts4_if_call_seq_u32_off2c_88646210(it);
        zero = 0;
        it->w0c = zero;
        it->w08 = zero;
        self->sink->vt->slot34(self->sink, it);
    }
    v->end = w8b_copy8(v->end, v->end, v->begin);
    (void)pd0; (void)pd1; (void)pd2; (void)pd3; (void)pd4; (void)pd5;
}
