/* Swing_DLL.xex 0x88404090: returns {1} when every 16-bit index of list (array +4, count +8) lies in [0, o->count), else {0}
 * (1-byte result returned through the hidden pointer). agO: plain and LTCG. */
struct Flag1 {
    unsigned char v;
    Flag1(unsigned char x) : v(x) {}
};
struct Obj { char pad[0x10]; int count; };
struct IndexList { int f0; short *items; int count; };
extern "C" Flag1 fn_88404090(Obj *o, IndexList *list)
{
    for (int i = 0; i < list->count; i++) {
        short k = list->items[i];
        if (k < 0 || k >= o->count)
            return Flag1(0);
    }
    return Flag1(1);
}
