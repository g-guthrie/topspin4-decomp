/* Loader_DLL.xex 0x8348A348-0x8348A40C, executable version 0.0.0.3. */
typedef unsigned long u32;
struct Ts4lIface {
    virtual void v0();
    virtual u32 Release();
    virtual void v2();
    virtual void v3();
    virtual u32 GetId();
    virtual void v5();
    virtual void Op(u32 a, u32 id, u32 *out);
};
struct Ts4lSrc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int Query(const void *iid, Ts4lIface **out);
};
struct Ts4lHolder {
    char pad[0x40];
    Ts4lSrc src;
};
struct Ts4lSink {
    char pad[0x2ae8];
    void (*notify)(u32 *a, u32 id);
};
extern "C" const char lbl_830850BC[];
extern "C" int ts4l_query_notify_8348A348(Ts4lHolder *h, Ts4lSink *sink, u32 *a)
{
    Ts4lIface *p = 0;
    u32 tmp;
    int r = h->src.Query(lbl_830850BC, &p);
    if (r == 0) {
        u32 id = p->GetId();
        sink->notify(a, id);
        p->Op(*a, id, &tmp);
        r = p->Release();
    }
    return r;
}
