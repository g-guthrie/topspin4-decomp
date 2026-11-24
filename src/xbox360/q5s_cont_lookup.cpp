/* q5s_cont: name-hash lookups over relative arrays (LTCG route, /Oc).
 * Context: ts4_index_to_name_hash_887F7BC8 forced (/Ob1, cx39_ctx_hash.c) so the caller knows which
 * registers it keeps; ts4_offset_array_end4_88187738 must NOT be in context (it is an ordinary call). */
#include "include/ts4/ts4.h"
#ifdef _MSC_VER
#define TS4_FINL __forceinline
#else
#define TS4_FINL inline
#endif

extern "C" unsigned int *ts4_index_to_name_hash_887F7BC8(unsigned int *out, unsigned char index);
extern "C" void *ts4_offset_array_end4_88187738(Ts4RelArray *a);

/* 4-byte entry: name index (mapped to a hash) and a 16-bit value. */
struct Ts4HashIdxEntry {
    unsigned char index;
    unsigned char pad;
    unsigned short value;
};
struct Ts4HashIdxTables {
    Ts4RelArray a;  /* +0x00 */
    char pad8[4];
    Ts4RelArray b;  /* +0x0C */
};
struct Ts4HashIdxOwner {
    char pad[0x28];
    Ts4HashIdxTables *tables; /* +0x28 */
};

static inline Ts4HashIdxEntry *ts4_rel_begin4(Ts4RelArray *a)
{
    Ts4HashIdxEntry *r = 0;
    if (a->offset != -1)
        r = (Ts4HashIdxEntry *)((char *)a + a->offset);
    return r;
}

/* Value of the first entry whose name hash equals *key, or -1. */
static TS4_FINL int ts4_hash_idx_find(Ts4RelArray *a, const unsigned int *key)
{
    Ts4HashIdxEntry *it = ts4_rel_begin4(a);
    Ts4HashIdxEntry *end = (Ts4HashIdxEntry *)ts4_offset_array_end4_88187738(a);
    for (; it != end; ++it) {
        unsigned int h;
        if (*ts4_index_to_name_hash_887F7BC8(&h, it->index) == *key)
            return it->value;
    }
    return -1;
}

extern "C" int ts4_hash_idx_find_a_8816CBB0(Ts4HashIdxOwner *self, const unsigned int *key)
{
    return ts4_hash_idx_find(&self->tables->a, key);
}

extern "C" int ts4_hash_idx_find_b_8816C490(Ts4HashIdxOwner *self, const unsigned int *key)
{
    return ts4_hash_idx_find(&self->tables->b, key);
}
