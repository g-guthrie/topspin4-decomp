/* Loader_DLL.xex 0x8320D620-0x832183B8, executable version 0.0.0.3.
 * Interlocked helpers: compare-and-swap with release barrier, and tagged-object teardown. */

#ifdef _MSC_VER
void __emit(unsigned);
#pragma intrinsic(__emit)
long _InterlockedCompareExchange(long volatile *, long, long);
#pragma intrinsic(_InterlockedCompareExchange)
long _InterlockedExchange(long volatile *, long);
#pragma intrinsic(_InterlockedExchange)
#define TS4L_LWSYNC() __emit(0x7c2004ac) /* PowerPC lwsync */
#else
#define TS4L_LWSYNC() ((void)0)
long _InterlockedCompareExchange(long volatile *, long, long);
long _InterlockedExchange(long volatile *, long);
#endif

extern void fn_8321B730(void *);
extern void fn_8320DA80(void *, void *, unsigned *);
extern void fn_8320D850(void *, void *, unsigned *);

#define TS4L_AT(o, off, T) (*(T *)((char *)(o) + (off)))

int ts4l_compare_swap_release_8320D620(long volatile *p, long nv, long expect)
{
    TS4L_LWSYNC();
    return _InterlockedCompareExchange(p, nv, expect) == expect;
}

int ts4l_compare_swap_release_8320D670(long volatile *p, long nv, long expect)
{
    TS4L_LWSYNC();
    return _InterlockedCompareExchange(p, nv, expect) == expect;
}

int ts4l_release_tagged_a_8320F008(void *o)
{
    unsigned s;
    long old;
    if (o != 0) {
        old = _InterlockedExchange(&TS4L_AT(o, 0x40, volatile long), 0);
        if (old == 0x4c665175) {
            if (TS4L_AT(o, 0x1c, void *) != 0)
                fn_8321B730(TS4L_AT(o, 0x1c, void *));
            if (TS4L_AT(o, 0x24, void *) != 0)
                fn_8321B730(TS4L_AT(o, 0x24, void *));
            s = TS4L_AT(o, 0x3c, unsigned);
            fn_8320DA80(TS4L_AT(o, 0x48, void *), (char *)o + 0x28, &s);
            fn_8320D850(TS4L_AT(o, 0x48, void *), TS4L_AT(o, 0x44, void *), &s);
            TS4L_LWSYNC();
        }
    }
    return 1;
}

int ts4l_release_tagged_a_8320FFB0(void *o)
{
    unsigned s;
    long old;
    if (o != 0) {
        old = _InterlockedExchange(&TS4L_AT(o, 0x40, volatile long), 0);
        if (old == 0x4c665175) {
            if (TS4L_AT(o, 0x1c, void *) != 0)
                fn_8321B730(TS4L_AT(o, 0x1c, void *));
            if (TS4L_AT(o, 0x24, void *) != 0)
                fn_8321B730(TS4L_AT(o, 0x24, void *));
            s = TS4L_AT(o, 0x3c, unsigned);
            fn_8320DA80(TS4L_AT(o, 0x48, void *), (char *)o + 0x28, &s);
            fn_8320D850(TS4L_AT(o, 0x48, void *), TS4L_AT(o, 0x44, void *), &s);
            TS4L_LWSYNC();
        }
    }
    return 1;
}

int ts4l_release_tagged_b_83215E70(void *o)
{
    unsigned s;
    long old;
    if (o != 0) {
        old = _InterlockedExchange(&TS4L_AT(o, 0x40, volatile long), 0);
        if (old == 0x4c464854) {
            if (TS4L_AT(o, 0x14, void *) != 0)
                fn_8321B730(TS4L_AT(o, 0x14, void *));
            if (TS4L_AT(o, 0x20, void *) != 0)
                fn_8321B730(TS4L_AT(o, 0x20, void *));
            s = TS4L_AT(o, 0x3c, unsigned);
            fn_8320DA80(TS4L_AT(o, 0x4c, void *), (char *)o + 0x28, &s);
            fn_8320D850(TS4L_AT(o, 0x4c, void *), TS4L_AT(o, 0x48, void *), &s);
            fn_8320D850(TS4L_AT(o, 0x4c, void *), TS4L_AT(o, 0x44, void *), &s);
            TS4L_LWSYNC();
        }
    }
    return 1;
}

int ts4l_release_tagged_b_832183B8(void *o)
{
    unsigned s;
    long old;
    if (o != 0) {
        old = _InterlockedExchange(&TS4L_AT(o, 0x40, volatile long), 0);
        if (old == 0x4c464854) {
            if (TS4L_AT(o, 0x14, void *) != 0)
                fn_8321B730(TS4L_AT(o, 0x14, void *));
            if (TS4L_AT(o, 0x20, void *) != 0)
                fn_8321B730(TS4L_AT(o, 0x20, void *));
            s = TS4L_AT(o, 0x3c, unsigned);
            fn_8320DA80(TS4L_AT(o, 0x4c, void *), (char *)o + 0x28, &s);
            fn_8320D850(TS4L_AT(o, 0x4c, void *), TS4L_AT(o, 0x48, void *), &s);
            fn_8320D850(TS4L_AT(o, 0x4c, void *), TS4L_AT(o, 0x44, void *), &s);
            TS4L_LWSYNC();
        }
    }
    return 1;
}
