/* Swing_DLL.xex 0x884613F8: calls virtual slot 10 with (a, b, c) on the object of every 8-byte entry of the array at +0xc
 * (count at +0x10, re-read each pass). agO: lookalike of 88461310, plain and LTCG. */
struct Item { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void apply(float a, float b, int c); };
struct Entry { int key; Item *obj; };
struct Obj { char pad[0xc]; Entry *entries; int count; };
extern "C" void fn_884613F8(Obj *o, float a, float b, int c)
{
    int i;
    for (i = 0; i < o->count; i++)
        o->entries[i].obj->apply(a, b, c);
}
