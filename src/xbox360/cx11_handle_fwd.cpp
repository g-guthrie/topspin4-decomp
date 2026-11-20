/* CW11: C++ part (validated-handle forwarding stubs 0x8860A818-0x8860AC78, a tail-forwarding owner stub, and lock-guarded
   free-list helpers). C++ so that `return voidcall()` gives a tail call and inline member functions keep dead sub-object addresses. A handle is {object pointer, id}; it is invalid when the pointer is null or the id is 0xFFFFF. When valid
   the stub forwards to the object's vtable slot with the handle as the second argument. Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;

struct Cx11Target { const void *vt; };
struct Cx11Handle { Cx11Target *ptr; u32 id; };

typedef void (*Cx11Fn0)(Cx11Target *, Cx11Handle *);
typedef u32 (*Cx11Fn0R)(Cx11Target *, Cx11Handle *);
typedef void (*Cx11Fn1)(Cx11Target *, Cx11Handle *, u32);
typedef void (*Cx11Fn2)(Cx11Target *, Cx11Handle *, u32, u32);
typedef u32 (*Cx11Fn1Z1)(Cx11Target *, Cx11Handle *, u32, u32);
typedef u32 (*Cx11Fn1Z2)(Cx11Target *, Cx11Handle *, u32, u32, u32);

#define CX11_BAD(h, p) ((u8)((long)(p) == 0 || (h)->id == 0xFFFFF))
#define CX11_VT(NAME, SLOT, FN) struct NAME##_vt { void *s[(SLOT) / 4]; FN f; };
#define CX11_SLOT(NAME, p) (((const NAME##_vt *)(p)->vt)->f)

/* no extra arguments, no result */
#define CX11_FWD0(NAME, SLOT) \
    CX11_VT(NAME, SLOT, Cx11Fn0) \
    extern "C" void NAME(Cx11Handle *h) \
    { \
        Cx11Target *p = h->ptr; \
        u8 bad = CX11_BAD(h, p); \
        if (bad == 0) return CX11_SLOT(NAME, p)(p, h); \
    }

/* no extra arguments, result 0 when the handle is invalid */
#define CX11_FWD0R0(NAME, SLOT) \
    CX11_VT(NAME, SLOT, Cx11Fn0R) \
    extern "C" u32 NAME(Cx11Handle *h) \
    { \
        Cx11Target *p = h->ptr; \
        u32 r = 0; \
        u8 bad = CX11_BAD(h, p); \
        if (bad == 0) r = CX11_SLOT(NAME, p)(p, h); \
        return r; \
    }

/* one extra argument */
#define CX11_FWD1(NAME, SLOT) \
    CX11_VT(NAME, SLOT, Cx11Fn1) \
    extern "C" void NAME(Cx11Handle *h, u32 a) \
    { \
        Cx11Target *p = h->ptr; \
        u8 bad = CX11_BAD(h, p); \
        if (bad == 0) return CX11_SLOT(NAME, p)(p, h, a); \
    }

/* two extra arguments */
#define CX11_FWD2(NAME, SLOT) \
    CX11_VT(NAME, SLOT, Cx11Fn2) \
    extern "C" void NAME(Cx11Handle *h, u32 a, u32 b) \
    { \
        Cx11Target *p = h->ptr; \
        u8 bad = CX11_BAD(h, p); \
        if (bad == 0) return CX11_SLOT(NAME, p)(p, h, a, b); \
    }

/* one extra argument followed by one (Z1) or two (Z2) zero arguments; result 1 when the handle is invalid */
#define CX11_FWD1Z1(NAME, SLOT) \
    CX11_VT(NAME, SLOT, Cx11Fn1Z1) \
    extern "C" u32 NAME(Cx11Handle *h, u32 a) \
    { \
        Cx11Target *p = h->ptr; \
        u32 r = 1; \
        u8 bad = CX11_BAD(h, p); \
        if (bad == 0) r = CX11_SLOT(NAME, p)(p, h, a, 0); \
        return r; \
    }
#define CX11_FWD1Z2(NAME, SLOT) \
    CX11_VT(NAME, SLOT, Cx11Fn1Z2) \
    extern "C" u32 NAME(Cx11Handle *h, u32 a) \
    { \
        Cx11Target *p = h->ptr; \
        u32 r = 1; \
        u8 bad = CX11_BAD(h, p); \
        if (bad == 0) r = CX11_SLOT(NAME, p)(p, h, a, 0, 0); \
        return r; \
    }

CX11_FWD0(ts4_handle_fwd_slot70_8860A938, 0x70)
CX11_FWD0(ts4_handle_fwd_slot68_8860A9E0, 0x68)
CX11_FWD0(ts4_handle_fwd_slot5c_8860AB08, 0x5c)
CX11_FWD0R0(ts4_handle_fwd_slot44_8860AB58, 0x44)
CX11_FWD0R0(ts4_handle_fwd_slot1c_8860ABB0, 0x1c)
CX11_FWD0R0(ts4_handle_fwd_slot08_8860AC28, 0x08)
CX11_FWD1(ts4_handle_fwd_slot6c_8860A988, 0x6c)
CX11_FWD1(ts4_handle_fwd_slot64_8860AAB0, 0x64)
CX11_FWD2(ts4_handle_fwd_slot84_8860A818, 0x84)
CX11_FWD1Z1(ts4_handle_fwd_slot7c_8860A8D8, 0x7c)
CX11_FWD1Z2(ts4_handle_fwd_slot80_8860A870, 0x80)

/* two handles, both validated; forwards (first, second) to the first one's object */
typedef void (*Cx11Fn1H)(Cx11Target *, Cx11Handle *, Cx11Handle *);
CX11_VT(ts4_handle_fwd2_slot60_8860AA30, 0x60, Cx11Fn1H)
extern "C" void ts4_handle_fwd2_slot60_8860AA30(Cx11Handle *h, Cx11Handle *h2)
{
    Cx11Target *p = h->ptr;
    u8 bad = CX11_BAD(h, p);
    if (bad == 0) {
        Cx11Target *q = h2->ptr;
        u8 bad2 = CX11_BAD(h2, q);
        if (bad2 == 0) return CX11_SLOT(ts4_handle_fwd2_slot60_8860AA30, p)(p, h, h2);
    }
}

/* 0x8860BD38: forward to the child object at 0x50 (vtable slot 17) with fields of the owner; no child, no call */
struct Cx11Child { const void *vt; };
typedef void (*Cx11FnChild)(Cx11Child *, u32, u32, u32, u32);
struct Cx11ChildVt { void *s[0x44 / 4]; Cx11FnChild f; };
struct Cx11Ctx10 { u8 pad[0x10]; u32 f10; };
struct Cx11Owner { u8 pad[0x28]; Cx11Ctx10 *f28; u8 pad2[0x44 - 0x2c]; u32 f44; u8 pad3[4]; u32 f4c; Cx11Child *f50; };
extern "C" void ts4_owner_forward_child_8860BD38(Cx11Owner *o, u32 a)
{
    Cx11Child *c = o->f50;
    if ((long)c == 0) return;
    return ((const Cx11ChildVt *)c->vt)->f(c, o->f4c, o->f44, a, o->f28->f10);
}

/* Lock sub-object at 0x44 (critical section at +4). Calls go through inline member functions, which keeps the dead
   sub-object address computation. */
extern "C" void RtlEnterCriticalSection(void *cs);
extern "C" void RtlLeaveCriticalSection(void *cs);
struct Cx11Lock {
    u32 w0; u8 cs[0x1c];
    void enter() { RtlEnterCriticalSection(cs); }
    void leave() { RtlLeaveCriticalSection(cs); }
};
struct Cx11FreeNode { Cx11FreeNode *next; };
struct Cx11FreePool { u8 pad[0x44]; Cx11Lock lock; u8 pad2[0x18c - 0x44 - sizeof(Cx11Lock)]; int count; Cx11FreeNode *head; };
/* 0x8860D9D8: push a node on the pool's free list under its lock */
extern "C" void ts4_free_list_push_8860D9D8(Cx11FreePool *o, Cx11FreeNode *n)
{
    Cx11Lock *l = &o->lock;
    l->enter();
    n->next = o->head;
    o->head = n;
    o->count--;
    l->leave();
}
struct Cx11LockedObj { u8 pad[0x40]; u32 f40; Cx11Lock lock; };
/* 0x8860DDA8: clear the field at 0x40 under the lock at 0x44 */
extern "C" void ts4_clear_f40_locked_8860DDA8(Cx11LockedObj *o)
{
    Cx11Lock *l = &o->lock;
    l->enter();
    o->f40 = 0;
    l->leave();
}

/* 0x8860DA90: pop a node from the free list under the lock when the request fits (stride divisible by align, size within limit);
   tracks the in-use count and its peak */
struct Cx11PopPool { u8 pad[0x44]; Cx11Lock lock; u8 pad2[0x180 - 0x44 - sizeof(Cx11Lock)]; u32 peak; u32 limit; u32 stride; u32 used; Cx11FreeNode *head; };
extern "C" Cx11FreeNode *ts4_free_list_pop_8860DA90(Cx11PopPool *o, u32 size, u32 align)
{
    Cx11Lock *l = &o->lock;
    Cx11FreeNode *r;
    l->enter();
    r = 0;
    if (o->stride % align == 0 && size <= o->limit && o->head != 0) {
        Cx11FreeNode *n = o->head;
        u32 used;
        r = n;
        o->head = n->next;
        used = o->used + 1;
        o->used = used;
        if (used > o->peak) o->peak = used;
    }
    l->leave();
    return r;
}
