/* Q5: tag the first node of a given type under the host's lock (Top Spin 4, Xbox 360, Swing_DLL.xex). */
#include "ga3_types.h"
typedef unsigned int u32;

/* Lock object with lock / unlock in virtual slots 1 and 2. */
typedef struct Q5Lockable Q5Lockable;
typedef struct Q5LockableVt {
    void *s00;
    void (*lock)(Q5Lockable *self);   /* +0x04 */
    void (*unlock)(Q5Lockable *self); /* +0x08 */
} Q5LockableVt;
struct Q5Lockable { Q5LockableVt *vt; };
typedef struct Q5Node { char p00[0x14]; u32 type; /* +0x14 */ } Q5Node;
typedef struct Q5NodeSet {
    char p00[0x40];
    Q5Node **begin;   /* +0x40 */
    Q5Node **end;     /* +0x44 */
    char p48[0x14];
    Q5Lockable lock;  /* +0x5c */
} Q5NodeSet;
typedef struct Q5SetHost { char p00[0x34]; Q5NodeSet *set; /* +0x34 */ } Q5SetHost;
typedef struct Q5SetUser { void *vt; Q5SetHost *host; /* +0x04 */ } Q5SetUser;
extern u32 fn_8887B148(Q5Node *node, struct Ga3Id tag);

#ifdef _MSC_VER
#define Q5_INLINE static __forceinline
#else
#define Q5_INLINE static inline
#endif
/* First non-null node in the set whose type matches, or 0. */
Q5_INLINE Q5Node *q5_find_node(Q5NodeSet *s, u32 type)
{
    Q5Node **it;
    for (it = s->begin; it != s->end; ++it)
        if (*it && (*it)->type == type) return *it;
    return 0;
}

/* 0x888C9D18: under the set's lock, apply tag 0x01505C7E (fn_8887B148) to the first node of type 0xC0BA51F5. */
void ts4_tag_node_c0ba51f5_01505c7e_888C9D18(Q5SetUser *self)
{
    Q5Lockable *lock = &self->host->set->lock;
    struct Ga3Id tag;
    Q5Node *n;
    lock->vt->lock(lock);
    n = q5_find_node(self->host->set, 0xC0BA51F5u);
    tag.value = 0x01505C7Eu;
    fn_8887B148(n, tag);
    lock->vt->unlock(lock);
}
