/* Loader_DLL.xex 0x832274F8-0x8322C488, executable version 0.0.0.3. */
struct Ts4lSubCheck {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual int Check();
};
struct Ts4lHolderA { char pad[0x88]; Ts4lSubCheck sub; char pad2[0xd4 - 0x8c]; char tail; };
struct Ts4lHolderB { char pad[0x7c]; Ts4lSubCheck sub; char pad2[0xd0 - 0x80]; char tail; };

extern "C" unsigned ts4l_get_tail_interface_832274F8(Ts4lHolderA *o, char **out)
{
    *out = &o->tail;
    return o->sub.Check() == 0 ? 0x8000000a : 0;
}

extern "C" unsigned ts4l_get_tail_interface_8322C438(Ts4lHolderB *o, char **out)
{
    *out = &o->tail;
    return o->sub.Check() == 0 ? 0x8000000a : 0;
}
