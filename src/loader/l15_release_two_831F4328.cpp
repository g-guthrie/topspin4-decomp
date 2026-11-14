/* Loader_DLL.xex 0x831F4328-0x831F4390, executable version 0.0.0.3. */
struct Tgt { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void M(); };
struct Obj { char pad[8]; Tgt *a; char pad2[0xf0]; Tgt *b; };
extern "C" void ts4l_release_two_831F4328(Obj *o)
{
    if (o->a)
        o->a->M();
    if (o->b)
        o->b->M();
}
