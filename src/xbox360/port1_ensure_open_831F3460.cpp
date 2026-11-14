/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l15_ensure_open_831F3460.cpp.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* Lazily open a source interface once and remember whether it succeeded. */
struct Ts4lSrc {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual int Open();
};
struct Ts4lHolder84 { char pad[0x84]; Ts4lSrc *src; char pad2[0x94 - 0x88]; int opened; };



/* Swing_DLL.xex 0x885CE510 */
extern "C" int ts4_ensure_open_885CE510(Ts4lHolder84 *o)
{
    int hr = 0;
    if (o->opened == 0) {
        hr = o->src->Open();
        o->opened = hr >= 0;
    }
    return hr;
}

