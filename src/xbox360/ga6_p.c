#ifndef _MSC_VER
#pragma GCC diagnostic ignored "-Wunused-function"
#endif
/*
 * GA6: gameplay container teardown (owned object vectors).
 */
typedef unsigned int ts4_word;
#ifdef _MSC_VER
#define GA6_INL static __forceinline
#else
#define GA6_INL static inline
#endif

void ts4_destroy_owned_object(void *object);
void ts4_tsu_cleanup_end(void *object);
void ts4_object_finalize(void *object);
void ts4_registry_dispatch_888860A0(void *buffer);
struct Ga6Pooled;
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ga6_release_pooled_886CF5F8(struct Ga6Pooled *self);
void *fn_88562DC0(void *dest, void *src, ts4_word n);

struct Ga6OwnedSlot {
    ts4_word pad_00;
    void *owned;               /* +0x04 */
    ts4_word pad_08;
};
struct Ga6Object {
    char pad_00[0x14];
    struct Ga6OwnedSlot slots[3]; /* +0x14, +0x20, +0x2C */
};
struct Ga6ObjVec { struct Ga6Object **first; struct Ga6Object **last; };
struct Ga6Container {
    char pad_00[0x88];
    struct Ga6ObjVec items;    /* +0x88 */
};

GA6_INL struct Ga6Object **ga6_copy_ptrs(struct Ga6Object **first, struct Ga6Object **last, struct Ga6Object **dest)
{
    if (first == last) {
        return dest;
    } else {
        ts4_word n = (ts4_word)((char *)last - (char *)first);
        dest = (struct Ga6Object **)fn_88562DC0(dest, first, n);
        return (struct Ga6Object **)((char *)dest + n);
    }
}

/* Destroy every owned object in the container's item vector, then empty the vector. */

struct Ga6WordVec { ts4_word *begin; ts4_word *end; };
struct Ga6Pooled {
    void *buffer;              /* +0x00 */
    ts4_word len;              /* +0x04 */
    char pad_08[0x10];
    struct Ga6WordVec vec_a;   /* +0x18 */
    char pad_20[4];
    struct Ga6WordVec vec_b;   /* +0x24 */
    char pad_2c[4];
    char sub_30[4];
};
GA6_INL ts4_word *ga6_copy_words(ts4_word *first, ts4_word *last, ts4_word *dest)
{
    int n = (int)(last - first);
    for (; n > 0; --n)
        *dest++ = *first++;
    return dest;
}
/* Release the buffer, clear the two word vectors and finalize the sub-object. */
void ga6_release_pooled_886CF5F8(struct Ga6Pooled *self)
{
    struct Ga6WordVec *va;
    struct Ga6WordVec *vb;
    if ((long)self->buffer != 0) {
        ts4_registry_dispatch_888860A0(self->buffer);
        self->buffer = 0;
        self->len = 0;
    }
    va = &self->vec_a;
    va->end = ga6_copy_words(va->end, va->end, va->begin);
    vb = &self->vec_b;
    vb->end = ga6_copy_words(vb->end, vb->end, vb->begin);
    ts4_object_finalize(self->sub_30);
}
