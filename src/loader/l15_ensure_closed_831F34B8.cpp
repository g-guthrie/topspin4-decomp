/* Loader_DLL.xex 0x831F34B8-0x831F3514, executable version 0.0.0.3. */
/* Release the source interface if it was opened and reset the open/closing flags. */
struct Ts4lSrc {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int Close();
};
struct Ts4lHolder84 { char pad[0x84]; Ts4lSrc *src; char pad2[0x94 - 0x88]; int opened; int closing; };
extern "C" int ts4l_ensure_closed_831F34B8(Ts4lHolder84 *o, int keep)
{
    int hr = 0;
    if (o->opened != 0) {
        hr = o->src->Close();
        if (hr < 0)
            return hr;
    }
    o->opened = 0;
    if (keep == 0)
        o->closing = 0;
    return hr;
}
