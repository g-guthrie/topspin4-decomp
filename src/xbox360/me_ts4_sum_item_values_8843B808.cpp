/* Swing_DLL.xex 0x8843B808: sum of the virtual slot-9 value over the item array at +0x44 (count +0x48, re-read each pass). */
/* Matched by agO (lookalike of 884EB4B0) with fn_check on the plain and LTCG routes, b142. */
struct Item { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual void f6(); virtual void f7(); virtual void f8(); virtual int value(); };
struct Obj { char pad[0x44]; Item **items; int count; };
extern "C" int fn_8843B808(Obj *o)
{
    int i;
    int sum = 0;
    for (i = 0; i < o->count; i++)
        sum += o->items[i]->value();
    return sum;
}
