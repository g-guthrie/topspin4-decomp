/* Swing_DLL.xex 0x88461390: calls virtual slot 9 with arg on the object of every 8-byte entry of the array at +0xc
 * (count at +0x10, re-read each pass). agO: lookalike of 8843B808, plain and LTCG. */
struct Item { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual void f6(); virtual void f7(); virtual void f8(); virtual void apply(int arg); };
struct Entry { int key; Item *obj; };
struct Obj { char pad[0xc]; Entry *entries; int count; };
extern "C" void fn_88461390(Obj *o, int arg)
{
    int i;
    for (i = 0; i < o->count; i++)
        o->entries[i].obj->apply(arg);
}
