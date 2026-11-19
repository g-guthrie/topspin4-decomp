/* Swing_DLL.xex 0x884F7E18: returns the first of the inline item pointers at +0x10 (count at +0x2c) whose virtual slot 6
 * returns key, or 0. agO: needs /Os; plain and LTCG. */
struct Item { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual unsigned key(); };
struct Obj { char pad[0x10]; Item *items[7]; unsigned count; };
extern "C" Item *fn_884F7E18(Obj *o, unsigned key)
{
    unsigned i;
    for (i = 0; i < o->count; i++) {
        if (key == o->items[i]->key())
            return o->items[i];
    }
    return 0;
}
