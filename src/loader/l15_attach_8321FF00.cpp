/* Loader_DLL.xex 0x8321FF00-0x8321FF70, executable version 0.0.0.3. */
/* Initialise an object, attach a reference-counted handle and run its start-up step; on failure run its cleanup slot. */
extern "C" long ts4l_interlocked_830AAAC0(void *);
extern "C" int fn_8321F7A0(void *);
struct Ts4lObjA {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual int Init();
    virtual void Cleanup();
    char pad[0x38 - 4];
    void *ref;
};
extern "C" int ts4l_attach_8321FF00(Ts4lObjA *o, void *ref)
{
    int hr = o->Init();
    if (hr >= 0) {
        ts4l_interlocked_830AAAC0(ref);
        o->ref = ref;
        hr = fn_8321F7A0(o);
        if (hr >= 0)
            return hr;
    }
    o->Cleanup();
    return hr;
}
