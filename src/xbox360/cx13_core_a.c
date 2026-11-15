/* CX13 part a: Pam core (0x88610000-0x88618000): item/entry owner tables, node dispatch, handle chains, pools. Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
typedef unsigned int cx13_uptr;
#define CX13_INL static __forceinline
#else
typedef unsigned long cx13_uptr;
#define CX13_INL static inline
#endif

extern void *fn_88562DC0(void *dst, const void *src, u32 n);
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

/* ---- owner of a vector of items, each holding 12-byte entries and 8-byte records ---- */
typedef struct DEnt { u32 id; u32 id2; u8 b8; u8 b9; u8 pad[2]; } DEnt;
typedef struct DRec { u32 id; u8 b4; u8 b5; u8 pad[2]; } DRec;
typedef struct DItem {
    u32 pad0; u32 key; DEnt *ebegin; DEnt *eend; u32 pad10; DRec *rbegin; DRec *rend; u8 pad1c[4];
    u8 f20, f21, f22, f23;
} DItem;
typedef struct DOwner { u8 pad[0x28]; DItem **begin; DItem **end; } DOwner;

/* 0x88612820: for every item with this key, look for a record with this id; store the record flag and the not-found flag */
void ts4_owner_update_item_flags_88612820(DOwner *self, u32 key, u32 id)
{
    DItem **end = self->end;
    DItem **it = self->begin;
    for (; end != it; it++) {
        DItem *item = *it;
        if (key == item->key) {
            u8 ok = 1;
            u8 found = 0;
            DRec *re = item->rend;
            DRec *r = item->rbegin;
            for (; re != r; r++) {
                if (r->id == id) {
                    if (found == 0) found = r->b5;
                    ok = 0;
                }
            }
            item->f21 = found;
            (*it)->f22 = ok;
        }
    }
}

/* 0x88612598: find the first live item entry matching both ids and derive a 0..3 state from the item and entry flags */
u32 ts4_owner_query_entry_state_88612598(DOwner *self, u32 k1, u32 k2)
{
    DItem **end = self->end;
    DItem **it = self->begin;
    u32 result = 0;
    u8 done = 0;
    for (; end != it; it++) {
        DItem *item;
        DEnt *e, *ee;
        if (done != 0) break;
        item = *it;
        if (item->f23 != 0) {
            ee = item->eend;
            e = item->ebegin;
            for (; ee != e; e++) {
                if (done != 0) break;
                if (e->id2 == k2 && e->id == k1) {
                    if (item->f21 != 0) { if (e->b9 == 0) result = 0; else result = (e->b8 == 0) + 1; } else { if (e->b9 != 0) result = (e->b8 == 0) + 1; else result = 3; }
                    done = 1;
                }
            }
        }
    }
    return result;
}

/* 0x88612670: same search, deriving a 0..2 state from the item's second flag and the entry flag */
u32 ts4_owner_query_entry_state2_88612670(DOwner *self, u32 k1, u32 k2)
{
    DItem **end = self->end;
    DItem **it = self->begin;
    u32 result = 0;
    u8 done = 0;
    for (; end != it; it++) {
        DItem *item;
        DEnt *e, *ee;
        if (done != 0) break;
        item = *it;
        if (item->f23 != 0) {
            ee = item->eend;
            e = item->ebegin;
            for (; ee != e; e++) {
                if (done != 0) break;
                if (e->id2 == k2 && e->id == k1) {
                    if (item->f22 != 0) result = 0; else result = ((e->b8 == 0) ^ 1) + 1;
                    done = 1;
                }
            }
        }
    }
    return result;
}

/* 0x886128B0: for the item with this key look up a record id, mark the item and copy the record flag to its entries; with both ids zero other active items get f23 cleared */
void ts4_owner_apply_entry_flags_886128B0(DOwner *self, u32 k1, u32 a2, u32 a3)
{
    u8 zero = 0;
    u8 both0;
    DItem **end;
    DItem **it;
    if (a2 == 0 && a3 == 0) both0 = 1; else both0 = 0;
    end = self->end;
    it = self->begin;
    for (; end != it; it++) {
        DItem *item = *it;
        if (k1 == item->key) {
            u8 found = 0;
            u8 val = 1;
            DRec *re = item->rend;
            DRec *r = item->rbegin;
            for (; re != r; r++) {
                if (r->id == a3) { val = r->b4; found = 1; break; }
            }
            item->f23 = found;
            if (found != 0) {
                DEnt *ee = (*it)->eend;
                DEnt *e = (*it)->ebegin;
                for (; ee != e; e++) e->b8 = val;
            }
        } else if (both0 != 0) {
            if (item->f20 != 0) item->f23 = zero;
        }
    }
}

typedef struct DVec { DItem **begin; DItem **end; } DVec;
typedef struct DOwner2 { u8 pad[0x28]; DVec vec; } DOwner2;

/* 0x88612998: remove every active item from the vector after clearing its flags and its entries' f9 flags */
void ts4_owner_remove_flagged_items_88612998(DOwner2 *self)
{
    DVec *vec = &self->vec;
    DItem **it = vec->begin;
    DItem **next;
    if (self->vec.end != it) {
        next = it + 1;
        do {
            DItem *item = *it;
            if (item->f20 != 0) {
                DEnt *ee, *e;
                item->f20 = 0;
                (*it)->f21 = 0;
                (*it)->f22 = 0;
                (*it)->f23 = 0;
                ee = (*it)->eend;
                e = (*it)->ebegin;
                for (; ee != e; e++) e->b9 = 0;
                if (next != vec->end) fn_88562DC0(it, next, (u32)((char *)vec->end - (char *)next));
                vec->end--;
            } else {
                next++;
                it++;
            }
        } while (self->vec.end != it);
    }
}

/* ---- service slot table ---- */
typedef struct LockVt { void *s0; void (*enter)(void *); void (*leave)(void *); } LockVt;
typedef struct Lock { const LockVt *vt; } Lock;
typedef struct Entry { u32 pad0[14]; void (*cb)(void *); u8 flag; u8 pad3d[0x6c - 0x3d]; } Entry;
typedef struct EntSvc { u8 pad0[0x24]; Entry entries[16]; Lock lock; } EntSvc;
extern EntSvc *ts4_find_service(u32 id);

/* 0x88611D80: under the service lock find this object in the 16-entry table, then run and clear its callback flag */
void ts4_service_slot_release_88611D80(void *self)
{
    EntSvc *svc = ts4_find_service(0x11A98C5A);
    Lock *lock = &svc->lock;
    Entry *e = 0;
    u32 i;
    lock->vt->enter(lock);
    for (i = 0; i < 16; i++) {
        if (self == &svc->entries[i]) {
            e = &svc->entries[i];
            break;
        }
    }
    lock->vt->leave(lock);
    if (e->cb != 0) e->cb(self);
    e->flag = 0;
}

/* ---- node dispatch ---- */
extern u8 *fn_88883CD0(u32 key);
extern u32 ts4_if_call_seq_fn_88883CD0_8860D208(void);
extern u32 fn_8860DC50(void *n, u32 a, u32 mode);
extern u32 ts4_node_dispatch_8860DCF8(void *n, u32 a, u32 b, u32 c);
typedef struct FNode FNode;
struct FNode { u8 pad0[0x20]; u8 f20; u8 pad21[3]; FNode *f24; u8 pad28[0x40 - 0x28]; FNode *next; };

/* 0x88613350: offer an event to the current node (mode 2, or 0 when the global flag is set), then down its sibling chain until accepted */
void ts4_node_dispatch_default_88613350(FNode *self, u32 a)
{
    u32 mode = 2;
    u8 *p = fn_88883CD0(0);
    FNode *n;
    if (p != 0) {
        if (*p != 0) mode = 0;
    }
    if (self->f20 == 0 && ts4_if_call_seq_fn_88883CD0_8860D208() != 0 && ts4_if_call_seq_fn_88883CD0_8860D208() != (u32)-1)
        n = (FNode *)(cx13_uptr)ts4_if_call_seq_fn_88883CD0_8860D208();
    else
        n = self->f24;
    if (fn_8860DC50(n, a, mode) == 0 && n != 0) {
        n = n->next;
        if ((int)(cx13_uptr)n != 0) {
            while (n != 0) {
                u32 r = fn_8860DC50(n, a, mode);
                n = n->next;
                if (r == 0) continue;
                break;
            }
        }
    }
}

/* 0x88613268: as above with an explicit start node (0 = default, -1 = the owner's) and extra arguments */
void ts4_node_dispatch_with_target_88613268(FNode *self, u32 a, u32 b, u32 c, u32 mode)
{
    u8 *p = fn_88883CD0(0);
    if (p != 0) {
        if (*p != 0) mode = 0;
    }
    if (self->f20 == 0 && c != (u32)-1) {
        if (c == 0) {
            if (ts4_if_call_seq_fn_88883CD0_8860D208() != 0 && ts4_if_call_seq_fn_88883CD0_8860D208() != (u32)-1)
                c = ts4_if_call_seq_fn_88883CD0_8860D208();
            else
                c = (u32)(cx13_uptr)self->f24;
        }
    } else {
        c = (u32)(cx13_uptr)self->f24;
    }
    {
        FNode *n = (FNode *)(cx13_uptr)c;
        if (ts4_node_dispatch_8860DCF8(n, a, b, mode) == 0 && n != 0) {
            n = n->next;
            if ((int)(cx13_uptr)n != 0) {
                while (n != 0) {
                    u32 r = ts4_node_dispatch_8860DCF8(n, a, b, mode);
                    n = n->next;
                    if (r == 0) continue;
                    break;
                }
            }
        }
    }
}

/* ---- memory buffer writer ---- */
typedef struct JBuf { u8 pad[0x14]; int pos; int size; u8 *data; u32 high; } JBuf;

/* 0x88614508: copy up to n bytes into the buffer at the current position, clipped to its size; returns the byte count */
int ts4_membuf_write_88614508(JBuf *self, const void *src, int n)
{
    int result = 0;
    int pos = self->pos;
    if (pos >= 0) {
        int size = self->size;
        int end = pos + n;
        int cnt;
        if (end >= size) end = size;
        cnt = end - pos;
        result = cnt;
        if (cnt != 0) {
            u8 *dst = 0;
            if (pos < size) dst = self->data + pos;
            memcpy(dst, src, cnt);
            pos = cnt + self->pos;
            self->pos = pos;
            if (self->high < (u32)pos) self->high = pos;
        }
    }
    return result;
}

/* ---- directory size total ---- */
extern void ts4_normalize_dir_path_88606978(void *buf, const char *path);
extern u32 fn_88608590(u32 a, void *buf);
typedef struct KItemVt { void *s[5]; u32 (*size)(void *); } KItemVt;
typedef struct KSub { const KItemVt *vt; } KSub;
typedef struct KItem { u8 pad[0x204]; u32 hash; KSub *sub; } KItem;
typedef struct KOwner { u8 pad[0x24]; KItem **begin; KItem **end; u8 pad2[0x2dd0 - 0x2c]; Lock lock; } KOwner;

/* 0x886140B8: under the owner's lock sum (size + 0x4c) over the items whose hash matches the hash of the normalised path */
u32 ts4_dir_total_size_886140B8(KOwner *self, const char *path)
{
    char buf[0x200];
    Lock *lock = &self->lock;
    u32 hash;
    u32 total;
    KItem **it;
    KItem **end;
    lock->vt->enter(lock);
    ts4_normalize_dir_path_88606978(buf, path);
    hash = fn_88608590(0, buf);
    end = self->end;
    it = self->begin;
    total = 0;
    for (; it != end; it++) {
        KItem *item = *it;
        if (hash == item->hash)
            total += item->sub->vt->size(item->sub) + 0x4c;
    }
    lock->vt->leave(lock);
    return total;
}

/* ---- 12-byte handle chains ---- */
typedef struct Ts4HandleRef { void **obj; u32 id; u32 extra; } Ts4HandleRef;
extern Ts4HandleRef *ts4_handle_forward0_88610AC8(Ts4HandleRef *out, Ts4HandleRef *src);
extern Ts4HandleRef *ts4_handle_forward0_88610948(Ts4HandleRef *out, Ts4HandleRef *src);
extern Ts4HandleRef *ts4_handle_forward0_886107F8(Ts4HandleRef *out, Ts4HandleRef *src);
CX13_INL u8 handle_is_null(const Ts4HandleRef *h)
{
    return h->obj == 0 || h->id == 0xFFFFF;
}

/* 0x88615748: walk n steps along the handle chain starting at src; copy the handle reached to out when the chain was long enough */
int ts4_handle_chain_get_nth_88615748(void *unused, Ts4HandleRef *src, int n, Ts4HandleRef *out)
{
    int i = 0;
    Ts4HandleRef cur;
    Ts4HandleRef tmp;
    (void)unused;
    ts4_handle_forward0_88610AC8(&cur, src);
    while (!handle_is_null(&cur)) {
        if (n == i) { *out = cur; break; }
        cur = *ts4_handle_forward0_88610948(&tmp, &cur);
        i++;
    }
    return n;
}

typedef struct IHandle12 { u32 a, b, c; } IHandle12;
typedef struct IObjVt { void *s[36]; void (*f90)(void *self, u32 a, IHandle12 h, Ts4HandleRef *out); } IObjVt;
typedef struct IObj { const IObjVt *vt; } IObj;
typedef void (*IFwdFn)(void *, Ts4HandleRef *, u32, Ts4HandleRef *);

/* 0x88615858: for every handle on the chain from src call slot 36 of self with it, then advance via slot 4 of the handle's object */
void ts4_handle_chain_walk_88615858(IObj *self, u32 a, Ts4HandleRef *src)
{
    Ts4HandleRef cur;
    ts4_handle_forward0_886107F8(&cur, src);
    while (!handle_is_null(&cur)) {
        Ts4HandleRef n1, n2;
        n1.obj = 0; n1.extra = 0; n1.id = 0xFFFFF;
        self->vt->f90(self, a, *(IHandle12 *)&cur, &n1);
        { volatile Ts4HandleRef *v2 = &n2; v2->obj = 0; v2->extra = 0; v2->id = 0xFFFFF; }
        { volatile Ts4HandleRef *vc = &cur; void **o = vc->obj; u32 id = vc->id; ((IFwdFn)(*(void ***)o)[4])(o, &cur, id, &n2); }
        cur = n2;
    }
}

/* ---- 0x20-byte block pool ---- */
extern void ts4_tsu_cleanup_end(void *p);
typedef struct MVec { char **begin; char **end; } MVec;
CX13_INL char **mcopy(char **first, char **last, char **dest)
{
    if (first == last) {
        return dest;
    } else {
        u32 n = (u32)((char *)last - (char *)first);
        dest = (char **)fn_88562DC0(dest, first, n);
        return (char **)((char *)dest + n);
    }
}
typedef struct MArea { u8 data[0x1000]; u32 top; int count; } MArea;
typedef struct MPool { u8 pad0[4]; MVec vec; u32 pad0c; MArea area; u8 pad1018[8]; u8 flag; } MPool;

/* 0x88616160: give every recorded block back (pool blocks shrink the pool, others are freed), then empty the vector */
void ts4_pool_release_all_88616160(MPool *self)
{
    char **end = self->vec.end;
    char **it = self->vec.begin;
    if (end != it) {
        MArea *area = &self->area;
        do {
            u8 *p = (u8 *)*it;
            if (p >= area->data && p < area->data + 0x1000) {
                if (p + 0x20 == (u8 *)(cx13_uptr)area->top) area->top -= 0x20;
                if (--area->count == 0) area->top = (u32)(cx13_uptr)area;
            } else {
                if (p != 0) ts4_tsu_cleanup_end(p);
            }
            it++;
        } while (it != end);
    }
    { MVec *v = &self->vec; v->end = mcopy(v->end, v->end, v->begin); }
    self->flag = 0;
}

/* ---- object lookup from a handle ---- */
typedef struct NH12 { u32 a, b, c; } NH12;
typedef struct NObj NObj;
typedef struct NObjVt { void *s0; NObj *(*get)(NObj *); void *s2[2]; void (*f10)(NObj *, NH12); } NObjVt;
struct NObj { const NObjVt *vt; };
extern void fn_881506A0(u32 *out, NH12 *h);
extern NObj *fn_8816D220(void *reg, u32 key);
extern void *lbl_88D45B20;
extern void fn_882802A0(void *self, NObj *o);

/* 0x88617C68: resolve the handle through the registry, ask the found object for its target, hand it the handle and register it with self */
NObj *ts4_create_object_from_handle_88617C68(void *self, NH12 h)
{
    u32 tmp;
    NObj *o;
    fn_881506A0(&tmp, &h);
    o = fn_8816D220(lbl_88D45B20, tmp);
    if (o != 0) {
        o = o->vt->get(o);
        if (o != 0) {
            o->vt->f10(o, h);
            fn_882802A0(self, o);
        }
    }
    return o;
}
