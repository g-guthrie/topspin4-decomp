/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l15_ensure_closed_831F34B8.cpp.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* Release the source interface if it was opened and reset the open/closing flags. */
struct Ts4lSrc {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int Close();
};
struct Ts4lHolder84 { char pad[0x84]; Ts4lSrc *src; char pad2[0x94 - 0x88]; int opened; int closing; };



/* Swing_DLL.xex 0x885CE568 */
extern "C" int ts4_ensure_closed_885CE568(Ts4lHolder84 *o, int keep)
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

