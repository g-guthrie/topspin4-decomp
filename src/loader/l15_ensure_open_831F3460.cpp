/* Loader_DLL.xex 0x831F3460-0x831F34B8, executable version 0.0.0.3. */
/* Lazily open a source interface once and remember whether it succeeded. */
struct Ts4lSrc {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual int Open();
};
struct Ts4lHolder84 { char pad[0x84]; Ts4lSrc *src; char pad2[0x94 - 0x88]; int opened; };
extern "C" int ts4l_ensure_open_831F3460(Ts4lHolder84 *o)
{
    int hr = 0;
    if (o->opened == 0) {
        hr = o->src->Open();
        o->opened = hr >= 0;
    }
    return hr;
}

