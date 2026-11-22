/* Q5h3: tag the first node of a given type under the host's lock (Top Spin 4, Xbox 360, Swing_DLL.xex). */
#include "ga3_types.h"
typedef unsigned int u32;

/* Lock object with lock / unlock in virtual slots 1 and 2. */
typedef struct Q5h3Lockable Q5h3Lockable;
typedef struct Q5h3LockableVt {
    void *s00;
    void (*lock)(Q5h3Lockable *self);   /* +0x04 */
    void (*unlock)(Q5h3Lockable *self); /* +0x08 */
} Q5h3LockableVt;
struct Q5h3Lockable { Q5h3LockableVt *vt; };
typedef struct Q5h3Node { char p00[0x14]; u32 type; /* +0x14 */ } Q5h3Node;
typedef struct Q5h3NodeSet {
    char p00[0x40];
    Q5h3Node **begin;   /* +0x40 */
    Q5h3Node **end;     /* +0x44 */
    char p48[0x14];
    Q5h3Lockable lock;  /* +0x5c */
} Q5h3NodeSet;
typedef struct Q5h3SetHost { char p00[0x34]; Q5h3NodeSet *set; /* +0x34 */ } Q5h3SetHost;
typedef struct Q5h3SetUser { void *vt; Q5h3SetHost *host; /* +0x04 */ } Q5h3SetUser;
extern u32 fn_8887B148(Q5h3Node *node, struct Ga3Id tag);

#ifdef _MSC_VER
#define Q5h3_INLINE static __forceinline
#else
#define Q5h3_INLINE static inline
#endif
/* First non-null node in the set whose type matches, or 0. */
Q5h3_INLINE Q5h3Node *q5h3_find_node(Q5h3NodeSet *s, u32 type)
{
    Q5h3Node **it;
    for (it = s->begin; it != s->end; ++it)
        if (*it && (*it)->type == type) return *it;
    return 0;
}

/* 0x888C9DD8: under the set's lock, apply tag 0x26296DD2 (fn_8887B148) to the first node of type 0xC0BA51F5. */
void ts4_tag_node_c0ba51f5_26296dd2_888C9DD8(Q5h3SetUser *self)
{
    Q5h3Lockable *lock = &self->host->set->lock;
    struct Ga3Id tag;
    Q5h3Node *n;
    lock->vt->lock(lock);
    n = q5h3_find_node(self->host->set, 0xC0BA51F5u);
    tag.value = 0x26296DD2u;
    fn_8887B148(n, tag);
    lock->vt->unlock(lock);
}

/* 0x888C9E98: same as above with tag 0x2B05E119. */
void ts4_tag_node_c0ba51f5_2b05e119_888C9E98(Q5h3SetUser *self)
{
    Q5h3Lockable *lock = &self->host->set->lock;
    struct Ga3Id tag;
    Q5h3Node *n;
    lock->vt->lock(lock);
    n = q5h3_find_node(self->host->set, 0xC0BA51F5u);
    tag.value = 0x2B05E119u;
    fn_8887B148(n, tag);
    lock->vt->unlock(lock);
}
