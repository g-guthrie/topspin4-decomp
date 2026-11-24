/* Swing_DLL.xex 0x88462418: calls virtual slot 7 with arg on the object of every 8-byte entry of the array at +0xc
 * (count at +0x10, re-read each pass), then virtual slot 0 of self with 1. agO: lookalike of 884EB4B0, plain and LTCG. */
struct Item { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual void f6(); virtual void apply(int arg); };
struct Entry { int key; Item *obj; };
struct Obj { virtual void finish(int flag); int f4; int f8; Entry *entries; int count; };
extern "C" void fn_88462418(Obj *o, int arg)
{
    int i;
    for (i = 0; i < o->count; i++)
        o->entries[i].obj->apply(arg);
    o->finish(1);
}
