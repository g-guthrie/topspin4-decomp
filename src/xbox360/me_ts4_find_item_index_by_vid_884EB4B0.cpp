/* Swing_DLL.xex 0x884EB4B0: index of the item whose virtual id() equals id, or -1 */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b139. */
struct Item { virtual void f0(); virtual int id(); };
struct Obj { char pad[0x38]; Item **items; int count; };
/* Returns the index of the first item whose id() equals id, or -1. */
extern "C" int fn_884EB4B0(Obj *o, int id)
{
    int i;
    int n = o->count;
    for (i = 0; i < n; i++) {
        if (o->items[i]->id() == id)
            return i;
    }
    return -1;
}
