/* Loader_DLL.xex 0x83288808-0x8328A47F, executable version 0.0.0.3.
 * Locked handle-pool helper: find a handle and clear its mark bit. */

#ifdef _MSC_VER
#define TS4L_INLINE static __forceinline
#else
#define TS4L_INLINE static inline
#endif

extern void RtlEnterCriticalSection(void *);
extern void RtlLeaveCriticalSection(void *);
typedef struct { int *data; unsigned cap; unsigned size; } Vec;
typedef struct { void *lock; Vec a; Vec b; int x1c; unsigned x20; } Obj;
TS4L_INLINE int vget(Vec *v, int i)
{
    if ((unsigned)i >= v->size)
        return 0;
    return v->data[i];
}
extern void ts4_tailcall_DbgBreakPoint_834138F0(void);
TS4L_INLINE void vset(Vec *v, int i, int x)
{
    if ((unsigned)i >= v->size)
        ts4_tailcall_DbgBreakPoint_834138F0();
    if ((unsigned)i < v->size)
        v->data[i] = x;
}

void ts4l_pool_unmark_83288808(Obj *o, unsigned h)
{
    unsigned i = 0, n;
    int found = 0;
    RtlEnterCriticalSection(o->lock);
    n = o->a.size;
    for (; i < n; i++) {
        if ((unsigned)vget(&o->a, i) == h) {
            found = 1;
            break;
        }
    }
    if (found) {
        signed char nv = (signed char)(vget(&o->b, i) & ~1);
        vset(&o->b, i, nv);
        if (i < (unsigned)o->x1c)
            o->x1c = i;
    }
    RtlLeaveCriticalSection(o->lock);
}

void ts4l_pool_unmark_83288EE8(Obj *o, unsigned h)
{
    unsigned i = 0, n;
    int found = 0;
    RtlEnterCriticalSection(o->lock);
    n = o->a.size;
    for (; i < n; i++) {
        if ((unsigned)vget(&o->a, i) == h) {
            found = 1;
            break;
        }
    }
    if (found) {
        signed char nv = (signed char)(vget(&o->b, i) & ~1);
        vset(&o->b, i, nv);
        if (i < (unsigned)o->x1c)
            o->x1c = i;
    }
    RtlLeaveCriticalSection(o->lock);
}

void ts4l_pool_unmark_832895D0(Obj *o, unsigned h)
{
    unsigned i = 0, n;
    int found = 0;
    RtlEnterCriticalSection(o->lock);
    n = o->a.size;
    for (; i < n; i++) {
        if ((unsigned)vget(&o->a, i) == h) {
            found = 1;
            break;
        }
    }
    if (found) {
        signed char nv = (signed char)(vget(&o->b, i) & ~1);
        vset(&o->b, i, nv);
        if (i < (unsigned)o->x1c)
            o->x1c = i;
    }
    RtlLeaveCriticalSection(o->lock);
}

void ts4l_pool_unmark_83289CB8(Obj *o, unsigned h)
{
    unsigned i = 0, n;
    int found = 0;
    RtlEnterCriticalSection(o->lock);
    n = o->a.size;
    for (; i < n; i++) {
        if ((unsigned)vget(&o->a, i) == h) {
            found = 1;
            break;
        }
    }
    if (found) {
        signed char nv = (signed char)(vget(&o->b, i) & ~1);
        vset(&o->b, i, nv);
        if (i < (unsigned)o->x1c)
            o->x1c = i;
    }
    RtlLeaveCriticalSection(o->lock);
}

void ts4l_pool_unmark_8328A398(Obj *o, unsigned h)
{
    unsigned i = 0, n;
    int found = 0;
    RtlEnterCriticalSection(o->lock);
    n = o->a.size;
    for (; i < n; i++) {
        if ((unsigned)vget(&o->a, i) == h) {
            found = 1;
            break;
        }
    }
    if (found) {
        signed char nv = (signed char)(vget(&o->b, i) & ~1);
        vset(&o->b, i, nv);
        if (i < (unsigned)o->x1c)
            o->x1c = i;
    }
    RtlLeaveCriticalSection(o->lock);
}
