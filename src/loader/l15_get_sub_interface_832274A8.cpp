/* Loader_DLL.xex 0x832274A8-0x8322C434, executable version 0.0.0.3.
 * Interface accessors: hand out the embedded sub-interface and report whether its
 * virtual check (slot 13) returned zero as an HRESULT-style failure code. */
struct Ts4lSub {
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
    virtual void v11();
    virtual void v12();
    virtual int Check();
};


struct Ts4lHolder832274A8 { char pad[136]; Ts4lSub sub; };

extern "C" unsigned ts4l_get_sub_interface_832274A8(Ts4lHolder832274A8 *o, Ts4lSub **out)
{
    *out = &o->sub;
    return o->sub.Check() == 0 ? 0x8000000a : 0;
}

struct Ts4lHolder8322C268 { char pad[56]; Ts4lSub sub; };

extern "C" unsigned ts4l_get_sub_interface_8322C268(Ts4lHolder8322C268 *o, Ts4lSub **out)
{
    *out = &o->sub;
    return o->sub.Check() == 0 ? 0x8000000a : 0;
}

struct Ts4lHolder8322C3E8 { char pad[124]; Ts4lSub sub; };

extern "C" unsigned ts4l_get_sub_interface_8322C3E8(Ts4lHolder8322C3E8 *o, Ts4lSub **out)
{
    *out = &o->sub;
    return o->sub.Check() == 0 ? 0x8000000a : 0;
}
