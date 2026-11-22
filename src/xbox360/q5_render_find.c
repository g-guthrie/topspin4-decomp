/* Q5: renderer lookups (Top Spin 4, Xbox 360, Swing_DLL.xex). */
#include "ga3_types.h"
typedef unsigned int u32;

/* One-word record key. Copying it into a struct local keeps the target's load order (key field, then *key). */
typedef struct Q5RecKey { u32 id; } Q5RecKey;
/* 0x14-byte keyed record in a self-relative array. */
typedef struct Q5KeyedRec20 { u32 w00, w04, w08; Q5RecKey key; /* +0x0c */ u32 w10; } Q5KeyedRec20;
typedef struct Q5RecBlock { char p00[0x60]; struct Ga3RelArr recs; /* +0x60 */ } Q5RecBlock;
typedef struct Q5RecOwner { char p00[0x14]; Q5RecBlock *block; /* +0x14 */ } Q5RecOwner;

#ifdef _MSC_VER
#define Q5_INLINE static __forceinline
#else
#define Q5_INLINE static inline
#endif
Q5_INLINE Q5KeyedRec20 *q5_recs_begin(struct Ga3RelArr *a)
{
    Q5KeyedRec20 *r = 0;
    if (a->offset != -1) r = (Q5KeyedRec20 *)((char *)a + a->offset);
    return r;
}
Q5_INLINE Q5KeyedRec20 *q5_recs_end(struct Ga3RelArr *a)
{
    Q5KeyedRec20 *r = 0;
    if (a->offset != -1) r = (Q5KeyedRec20 *)((char *)a + (a->count * 20 + a->offset));
    return r;
}

/* 0x886EFC48: the record of the owner's block (+0x14, list at +0x60) whose key equals *key, or 0. */
Q5KeyedRec20 *ts4_find_rec_by_key_886EFC48(Q5RecOwner *owner, const Q5RecKey *key)
{
    Q5KeyedRec20 *e;
    if (!owner->block) return 0;
    e = q5_recs_begin(&owner->block->recs);
    for (; e != q5_recs_end(&owner->block->recs); ++e) {
        Q5RecKey k;
        k = e->key;
        if (key->id == k.id) return e;
    }
    return 0;
}
