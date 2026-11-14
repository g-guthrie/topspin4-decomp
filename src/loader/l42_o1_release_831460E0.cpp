/* Loader_DLL.xex 0x831460E0-0x83151108, executable version 0.0.0.3. */
/* Owner teardown: release a COM-style member through its vtable (slot 1) and free the buffers. */
typedef unsigned long long u64;
struct Ts4lIf {
    virtual void s0();
    virtual void s1();
};
struct Own1 { void *a; Ts4lIf *h; };
struct Own2 { void *a; char pad[0x24]; Ts4lIf *h; char pad2[8]; void *c; };
struct B1C { int a[7]; };
extern "C" {
extern void fn_83120540(void *p);

void ts4l_release_members_831460E0(Own1 *o)
{
    if (o->h)
        ((Ts4lIf *)(u64)o->h)->s1();
    if (o->a)
        fn_83120540(o->a);
}

void ts4l_release_members_83151108(Own2 *o)
{
    fn_83120540(o->a);
    if (o->h)
        ((Ts4lIf *)(u64)o->h)->s1();
    fn_83120540(o->c);
}

int ts4l_query_83150E78(void *self, char *src, Ts4lIf **out, B1C *dst)
{
    int r;
    (void)self;
    if (src == 0) {
        r = (int)0x80070057u;
    } else {
        *out = *(Ts4lIf **)(src + 0x28);
        (*(Ts4lIf **)(src + 0x28))->s0();
        if (dst != 0)
            *dst = *(B1C *)(src + 0xc);
        r = 0;
    }
    return r;
}
}
