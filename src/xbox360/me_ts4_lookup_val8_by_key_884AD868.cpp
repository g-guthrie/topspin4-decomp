/* Swing_DLL.xex 0x884AD868: 8-byte value paired with key (16-byte entries at +0x74), default zero */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b139. */
struct Val8 {
    unsigned __int64 v;
    Val8() : v(0) {}
};
struct Entry { unsigned int key; int pad; Val8 value; };
struct Obj { char pad[0x74]; Entry *items; int count; };

/* Returns the 8-byte value paired with key, or a default (zero) value when absent. */
extern "C" Val8 fn_884AD868(Obj *o, unsigned int key)
{
    for (int i = 0; i < o->count; i++) {
        if (o->items[i].key == key)
            return o->items[i].value;
    }
    return Val8();
}
