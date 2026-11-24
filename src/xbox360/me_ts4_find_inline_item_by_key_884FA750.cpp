/* Swing_DLL.xex 0x884FA750: returns the first of the inline item pointers at +0xc (count at +0x14) whose virtual slot 6
 * returns key, or 0. agO: needs /Os; plain and LTCG. */
struct Item { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual unsigned key(); };
struct Obj { char pad[0xc]; Item *items[2]; unsigned count; };
extern "C" Item *fn_884FA750(Obj *o, unsigned key)
{
    unsigned i;
    for (i = 0; i < o->count; i++) {
        if (key == o->items[i]->key())
            return o->items[i];
    }
    return 0;
}
