/*
 * 0x886559C8: removes the first item with a given id from a locked pointer vector. Locks the object's
 * lock (+0x24, vtable slots +4 lock / +8 unlock), scans items [begin,end) at +0x44, and on a hit
 * shifts the tail down with memmove (fn_88562DC0) and drops end by one. Returns 1 when removed,
 * 0 otherwise; unlocks on both paths.
 *
 * Codegen: the loop caches end in a register, while the erase helper re-reads end through an
 * address-taken pointer (`&v->end`): the target reloads 0x48(r) for the memmove length and again for
 * the decrement.
 */
typedef unsigned int u32;

extern void *fn_88562DC0(void *dst, const void *src, u32 n); /* memmove */

struct Q5sLock;
typedef struct Q5sLockVt {
    void *f0;
    void (*lock)(struct Q5sLock *l);   /* +0x04 */
    void (*unlock)(struct Q5sLock *l); /* +0x08 */
} Q5sLockVt;

typedef struct Q5sLock {
    Q5sLockVt *vt;
} Q5sLock;

typedef struct Q5sItem {
    u32 id; /* +0x00 */
} Q5sItem;

typedef struct Q5sItemVec {
    Q5sItem **begin;
    Q5sItem **end;
} Q5sItemVec;

typedef struct Q5sItemOwner {
    char pad00[0x24];
    Q5sLock lock;     /* +0x24 */
    char pad28[0x44 - 0x28];
    Q5sItemVec items; /* +0x44 */
} Q5sItemOwner;

static __inline void q5s_item_vec_erase(Q5sItemVec *v, Q5sItem **p)
{
    Q5sItem **next = p + 1;
    Q5sItem ***pe = &v->end;
    if (next != *pe)
        fn_88562DC0(p, next, (u32)((char *)*pe - (char *)next));
    v->end--;
}

int ts4_remove_item_by_id_886559C8(Q5sItemOwner *o, u32 id)
{
    Q5sLock *l = &o->lock;
    Q5sItemVec *v;
    Q5sItem **p, **end;
    l->vt->lock(l);
    v = &o->items;
    end = v->end;
    for (p = v->begin; p != end; p++) {
        if ((*p)->id == id) {
            q5s_item_vec_erase(v, p);
            l->vt->unlock(l);
            return 1;
        }
    }
    l->vt->unlock(l);
    return 0;
}
