/* 0x8848BD88: Allocates a 128-byte object from the TLS allocator (kind 0x22), stores its size 0x80 at +4, and constructs it via fn_8848BC48 with the maker context at +8 and the two arguments adjusted by their signed byte offsets at +0x10; returns that result. */
/* Matched on /Oc (agAH). Allocator fetched into a local before the alloc call (keeps li r5 before li r4); adjusted pointers computed first. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void *fn_8841A510(void *allocator, unsigned int size, int kind);
typedef struct Adjustable { char pad[0x10]; signed char adjust; } Adjustable;
typedef struct Sized128 { int unk0; unsigned short size; } Sized128;
typedef struct Maker { char pad[0x8]; void *ctx; } Maker;
void *fn_8848BC48(Sized128 *obj, void *ctx, void *a, void *b);

void *fn_8848BD88(Maker *m, Adjustable *a, Adjustable *b)
{
    char *pa = (char *)a + a->adjust;
    char *pb = (char *)b + b->adjust;
    void *alloc = KeTlsGetValue(lbl_88CACF08);
    Sized128 *obj = (Sized128 *)fn_8841A510(alloc, 0x80, 0x22);
    obj->size = 0x80;
    return fn_8848BC48(obj, m->ctx, pa, pb);
}
