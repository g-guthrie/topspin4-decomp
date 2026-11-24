/* Loader_DLL.xex 0x83287C20-0x8328A050, executable version 0.0.0.3.
 * Locked scans of a pair of growable arrays (six identical template
 * instantiations of three methods). */

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
extern void fn_834138F0(void);
TS4L_INLINE void vset(Vec *v, int i, int x)
{
    if ((unsigned)i >= v->size)
        fn_834138F0();
    if ((unsigned)i < v->size)
        v->data[i] = x;
}
int ts4l_clear_marked_entries_83287C20(Obj *o, int mode)
{
    int cnt = 0;
    int i, n, e;
    if (o == 0)
        return 0;
    RtlEnterCriticalSection(o->lock);
    if (o->x1c != -1) {
        n = (int)o->a.size;
        for (i = 0; i < n; i++) {
            e = vget(&o->b, i) & 1;
            if (e) {
                cnt++;
                if (mode == 0) {
                    signed char nv = (signed char)(e & ~1);
                    vset(&o->b, i, nv);
                }
            }
        }
    }
    RtlLeaveCriticalSection(o->lock);
    return cnt;
}

int ts4l_clear_marked_entries_83288320(Obj *o, int mode)
{
    int cnt = 0;
    int i, n, e;
    if (o == 0)
        return 0;
    RtlEnterCriticalSection(o->lock);
    if (o->x1c != -1) {
        n = (int)o->a.size;
        for (i = 0; i < n; i++) {
            e = vget(&o->b, i) & 1;
            if (e) {
                cnt++;
                if (mode == 0) {
                    signed char nv = (signed char)(e & ~1);
                    vset(&o->b, i, nv);
                }
            }
        }
    }
    RtlLeaveCriticalSection(o->lock);
    return cnt;
}

int ts4l_clear_marked_entries_83288A28(Obj *o, int mode)
{
    int cnt = 0;
    int i, n, e;
    if (o == 0)
        return 0;
    RtlEnterCriticalSection(o->lock);
    if (o->x1c != -1) {
        n = (int)o->a.size;
        for (i = 0; i < n; i++) {
            e = vget(&o->b, i) & 1;
            if (e) {
                cnt++;
                if (mode == 0) {
                    signed char nv = (signed char)(e & ~1);
                    vset(&o->b, i, nv);
                }
            }
        }
    }
    RtlLeaveCriticalSection(o->lock);
    return cnt;
}

int ts4l_clear_marked_entries_83289108(Obj *o, int mode)
{
    int cnt = 0;
    int i, n, e;
    if (o == 0)
        return 0;
    RtlEnterCriticalSection(o->lock);
    if (o->x1c != -1) {
        n = (int)o->a.size;
        for (i = 0; i < n; i++) {
            e = vget(&o->b, i) & 1;
            if (e) {
                cnt++;
                if (mode == 0) {
                    signed char nv = (signed char)(e & ~1);
                    vset(&o->b, i, nv);
                }
            }
        }
    }
    RtlLeaveCriticalSection(o->lock);
    return cnt;
}

int ts4l_clear_marked_entries_832897F0(Obj *o, int mode)
{
    int cnt = 0;
    int i, n, e;
    if (o == 0)
        return 0;
    RtlEnterCriticalSection(o->lock);
    if (o->x1c != -1) {
        n = (int)o->a.size;
        for (i = 0; i < n; i++) {
            e = vget(&o->b, i) & 1;
            if (e) {
                cnt++;
                if (mode == 0) {
                    signed char nv = (signed char)(e & ~1);
                    vset(&o->b, i, nv);
                }
            }
        }
    }
    RtlLeaveCriticalSection(o->lock);
    return cnt;
}

int ts4l_clear_marked_entries_83289ED8(Obj *o, int mode)
{
    int cnt = 0;
    int i, n, e;
    if (o == 0)
        return 0;
    RtlEnterCriticalSection(o->lock);
    if (o->x1c != -1) {
        n = (int)o->a.size;
        for (i = 0; i < n; i++) {
            e = vget(&o->b, i) & 1;
            if (e) {
                cnt++;
                if (mode == 0) {
                    signed char nv = (signed char)(e & ~1);
                    vset(&o->b, i, nv);
                }
            }
        }
    }
    RtlLeaveCriticalSection(o->lock);
    return cnt;
}

int ts4l_any_entry_marked_83287CF8(Obj *o)
{
    int r;
    int i;
    RtlEnterCriticalSection(o->lock);
    r = 0;
    for (i = 0; i < (int)o->a.size; i++) {
        if (vget(&o->b, i) & 1) {
            r = 1;
            break;
        }
    }
    RtlLeaveCriticalSection(o->lock);
    return r;
}
int ts4l_any_entry_marked_832883F8(Obj *o)
{
    int r;
    int i;
    RtlEnterCriticalSection(o->lock);
    r = 0;
    for (i = 0; i < (int)o->a.size; i++) {
        if (vget(&o->b, i) & 1) {
            r = 1;
            break;
        }
    }
    RtlLeaveCriticalSection(o->lock);
    return r;
}
int ts4l_any_entry_marked_83288B00(Obj *o)
{
    int r;
    int i;
    RtlEnterCriticalSection(o->lock);
    r = 0;
    for (i = 0; i < (int)o->a.size; i++) {
        if (vget(&o->b, i) & 1) {
            r = 1;
            break;
        }
    }
    RtlLeaveCriticalSection(o->lock);
    return r;
}
int ts4l_any_entry_marked_832891E0(Obj *o)
{
    int r;
    int i;
    RtlEnterCriticalSection(o->lock);
    r = 0;
    for (i = 0; i < (int)o->a.size; i++) {
        if (vget(&o->b, i) & 1) {
            r = 1;
            break;
        }
    }
    RtlLeaveCriticalSection(o->lock);
    return r;
}
int ts4l_any_entry_marked_832898C8(Obj *o)
{
    int r;
    int i;
    RtlEnterCriticalSection(o->lock);
    r = 0;
    for (i = 0; i < (int)o->a.size; i++) {
        if (vget(&o->b, i) & 1) {
            r = 1;
            break;
        }
    }
    RtlLeaveCriticalSection(o->lock);
    return r;
}
int ts4l_any_entry_marked_83289FB0(Obj *o)
{
    int r;
    int i;
    RtlEnterCriticalSection(o->lock);
    r = 0;
    for (i = 0; i < (int)o->a.size; i++) {
        if (vget(&o->b, i) & 1) {
            r = 1;
            break;
        }
    }
    RtlLeaveCriticalSection(o->lock);
    return r;
}
int ts4l_find_region_83287D98(Obj *o, unsigned p, unsigned *out1, unsigned *out2)
{
    int r;
    int i;
    unsigned base, end;
    RtlEnterCriticalSection(o->lock);
    r = 0;
    for (i = 0; i < (int)o->a.size; i++) {
        base = (unsigned)vget(&o->a, i);
        end = base + o->x20;
        if (p >= base && p < end) {
            *out1 = base;
            *out2 = end;
            r = 1;
            break;
        }
    }
    RtlLeaveCriticalSection(o->lock);
    return r;
}
int ts4l_find_region_83288498(Obj *o, unsigned p, unsigned *out1, unsigned *out2)
{
    int r;
    int i;
    unsigned base, end;
    RtlEnterCriticalSection(o->lock);
    r = 0;
    for (i = 0; i < (int)o->a.size; i++) {
        base = (unsigned)vget(&o->a, i);
        end = base + o->x20;
        if (p >= base && p < end) {
            *out1 = base;
            *out2 = end;
            r = 1;
            break;
        }
    }
    RtlLeaveCriticalSection(o->lock);
    return r;
}
int ts4l_find_region_83288BA0(Obj *o, unsigned p, unsigned *out1, unsigned *out2)
{
    int r;
    int i;
    unsigned base, end;
    RtlEnterCriticalSection(o->lock);
    r = 0;
    for (i = 0; i < (int)o->a.size; i++) {
        base = (unsigned)vget(&o->a, i);
        end = base + o->x20;
        if (p >= base && p < end) {
            *out1 = base;
            *out2 = end;
            r = 1;
            break;
        }
    }
    RtlLeaveCriticalSection(o->lock);
    return r;
}
int ts4l_find_region_83289280(Obj *o, unsigned p, unsigned *out1, unsigned *out2)
{
    int r;
    int i;
    unsigned base, end;
    RtlEnterCriticalSection(o->lock);
    r = 0;
    for (i = 0; i < (int)o->a.size; i++) {
        base = (unsigned)vget(&o->a, i);
        end = base + o->x20;
        if (p >= base && p < end) {
            *out1 = base;
            *out2 = end;
            r = 1;
            break;
        }
    }
    RtlLeaveCriticalSection(o->lock);
    return r;
}
int ts4l_find_region_83289968(Obj *o, unsigned p, unsigned *out1, unsigned *out2)
{
    int r;
    int i;
    unsigned base, end;
    RtlEnterCriticalSection(o->lock);
    r = 0;
    for (i = 0; i < (int)o->a.size; i++) {
        base = (unsigned)vget(&o->a, i);
        end = base + o->x20;
        if (p >= base && p < end) {
            *out1 = base;
            *out2 = end;
            r = 1;
            break;
        }
    }
    RtlLeaveCriticalSection(o->lock);
    return r;
}
int ts4l_find_region_8328A050(Obj *o, unsigned p, unsigned *out1, unsigned *out2)
{
    int r;
    int i;
    unsigned base, end;
    RtlEnterCriticalSection(o->lock);
    r = 0;
    for (i = 0; i < (int)o->a.size; i++) {
        base = (unsigned)vget(&o->a, i);
        end = base + o->x20;
        if (p >= base && p < end) {
            *out1 = base;
            *out2 = end;
            r = 1;
            break;
        }
    }
    RtlLeaveCriticalSection(o->lock);
    return r;
}
