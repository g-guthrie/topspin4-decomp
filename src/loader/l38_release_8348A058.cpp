/* Loader_DLL.xex 0x8348A058-0x8348A0A8, 0x8348A140-0x8348A190, executable version 0.0.0.3. */
typedef unsigned long u32;
struct Ts4lRef {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void Destroy(u32 flags);
    u32 refs;
};
extern "C" u32 ts4l_release_8348A140(Ts4lRef *o)
{
    u32 n = --o->refs;
    if (n == 0) o->Destroy(1);
    return n;
}
extern "C" u32 ts4l_release_8348A058(Ts4lRef *o)
{
    u32 n = --o->refs;
    if (n == 0) o->Destroy(1);
    return n;
}
