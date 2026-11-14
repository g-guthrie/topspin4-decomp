/* Loader_DLL.xex 0x83222020-0x8322345C, executable version 0.0.0.3. */
#ifdef _MSC_VER
extern "C" void *memset(void *, int, unsigned);
#pragma intrinsic(memset)
#else
#include <string.h>
#endif
struct Ts4lParams { int a, b, c, d, e, f, g; };
struct Ts4lTarget {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual int Submit(Ts4lParams *);
};

extern "C" int ts4l_submit_params_83222020(Ts4lTarget *t, int a, int b)
{
    Ts4lParams p;
    memset(&p, 0, sizeof(p));
    p.a = a;
    p.b = b;
    return t->Submit(&p);
}

extern "C" int ts4l_submit_params_83223408(Ts4lTarget *t, int a, int b)
{
    Ts4lParams p;
    memset(&p, 0, sizeof(p));
    p.a = a;
    p.b = b;
    return t->Submit(&p);
}
