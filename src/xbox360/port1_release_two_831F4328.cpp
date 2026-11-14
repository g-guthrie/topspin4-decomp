/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l15_release_two_831F4328.cpp.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
struct Tgt { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void M(); };
struct Obj { char pad[8]; Tgt *a; char pad2[0xf0]; Tgt *b; };



/* Swing_DLL.xex 0x885CF0D0 */
extern "C" void ts4_release_two_885CF0D0(Obj *o)
{
    if (o->a)
        o->a->M();
    if (o->b)
        o->b->M();
}

