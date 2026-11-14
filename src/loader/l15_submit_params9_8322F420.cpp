/* Loader_DLL.xex 0x8322F420-0x8322F520, executable version 0.0.0.3. */
#ifdef _MSC_VER
extern "C" void *memset(void *, int, unsigned);
#pragma intrinsic(memset)
#else
#include <string.h>
#endif
struct Ts4lParams9 { int a, b, c, d, e, f, g, h, i; };
struct Ts4lTarget9 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8();
    virtual int Submit(Ts4lParams9 *);
};

extern "C" int ts4l_submit_default_8322F420(Ts4lTarget9 *t)
{
    Ts4lParams9 p;
    memset(&p, 0, sizeof(p));
    return t->Submit(&p);
}

extern "C" int ts4l_submit_one_8322F470(Ts4lTarget9 *t, int a)
{
    Ts4lParams9 p;
    memset(&p, 0, sizeof(p));
    p.a = a;
    return t->Submit(&p);
}

extern "C" int ts4l_submit_two_8322F4C8(Ts4lTarget9 *t, int a, int b)
{
    Ts4lParams9 p;
    memset(&p, 0, sizeof(p));
    p.a = a;
    p.b = b;
    return t->Submit(&p);
}
