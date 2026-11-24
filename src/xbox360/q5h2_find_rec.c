/* Q5h2: renderer keyed lookup (Top Spin 4, Xbox 360, Swing_DLL.xex), plain route, no flags.
 * Clone of ts4_find_rec_by_key_886EFC48 for the sister 0x886EFD38: the list is at block +0x08 (not +0x60), the
 * records are 0xC bytes (count * 12) with the key at +0x00. */
#include "ga3_types.h"
typedef unsigned int u32;

/* One-word record key. Copying it into a struct local keeps the target's load order (key field, then *key). */
typedef struct Q5h2RecKey { u32 id; } Q5h2RecKey;
/* 0x0C-byte keyed record in a self-relative array; the key is the first word. */
typedef struct Q5h2KeyedRec12 { Q5h2RecKey key; /* +0x00 */ u32 w04, w08; } Q5h2KeyedRec12;
typedef struct Q5h2RecBlock { char p00[0x08]; struct Ga3RelArr recs; /* +0x08 */ } Q5h2RecBlock;
typedef struct Q5h2RecOwner { char p00[0x14]; Q5h2RecBlock *block; /* +0x14 */ } Q5h2RecOwner;

#ifdef _MSC_VER
#define Q5H2_INLINE static __forceinline
#else
#define Q5H2_INLINE static inline
#endif
Q5H2_INLINE Q5h2KeyedRec12 *q5h2_recs_begin(struct Ga3RelArr *a)
{
    Q5h2KeyedRec12 *r = 0;
    if (a->offset != -1) r = (Q5h2KeyedRec12 *)((char *)a + a->offset);
    return r;
}
Q5H2_INLINE Q5h2KeyedRec12 *q5h2_recs_end(struct Ga3RelArr *a)
{
    Q5h2KeyedRec12 *r = 0;
    if (a->offset != -1) r = (Q5h2KeyedRec12 *)((char *)a + (a->count * 12 + a->offset));
    return r;
}

/* 0x886EFD38: the record of the owner's block (+0x14, list at +0x08) whose key equals *key, or 0. */
Q5h2KeyedRec12 *ts4_find_rec_by_key_886EFD38(Q5h2RecOwner *owner, const Q5h2RecKey *key)
{
    Q5h2KeyedRec12 *e;
    if (!owner->block) return 0;
    e = q5h2_recs_begin(&owner->block->recs);
    for (; e != q5h2_recs_end(&owner->block->recs); ++e) {
        Q5h2RecKey k;
        k = e->key;
        if (key->id == k.id) return e;
    }
    return 0;
}
