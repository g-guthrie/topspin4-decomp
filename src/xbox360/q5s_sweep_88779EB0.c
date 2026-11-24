/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x88779EB0: append an entry to the owner's pending list (+0x308) while holding the global lock.
 * Source: drafts/me_88779EB0_nearmiss.c (Q5S sweep, 2026-11-24); see work/specs/Q5S/sweep_88779EB0.json for route and flags. */
typedef unsigned int u32;
typedef struct Ts4Lock Ts4Lock;
typedef struct Ts4LockVt { void *s0; void (*lock)(Ts4Lock *l); void (*unlock)(Ts4Lock *l); } Ts4LockVt;
struct Ts4Lock { Ts4LockVt *vt; };
typedef struct Ts4LockHost { char pad[0x204]; Ts4Lock lock; } Ts4LockHost;
extern Ts4LockHost *lbl_88D45A60;
typedef struct Ts4PendVec { u32 *first; u32 *last; u32 *end; } Ts4PendVec;
typedef struct Ts4PendOwner { char pad[0x308]; Ts4PendVec pending; } Ts4PendOwner;
extern void ts4_vector_grow_append_scalar4_88174A38(Ts4PendVec *vec, u32 *pos, u32 *val);
void ts4_pend_owner_push_88779EB0(Ts4PendOwner *o, u32 v)
{
    Ts4Lock *l = &lbl_88D45A60->lock;
    Ts4PendVec *p;
    u32 k = v;
    l->vt->lock(l);
    p = &o->pending;
    if (p->last != p->end) {
        if (p->last) *p->last = k;
        p->last++;
    } else {
        ts4_vector_grow_append_scalar4_88174A38(p, p->last, &v);
    }
    l->vt->unlock(l);
}
