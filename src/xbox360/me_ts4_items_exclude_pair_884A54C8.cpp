/* Swing_DLL.xex 0x884A54C8: returns {0} when any item of the pointer array at +0x2c (count +0x30) has its +0x10 sub-object
 * equal to a or b, else {1} (1-byte result returned through the hidden pointer). agO: plain and LTCG. */
struct Flag1 {
    unsigned char v;
    Flag1(unsigned char x) : v(x) {}
};
struct Obj { char pad[0x2c]; char **items; int count; };
extern "C" Flag1 fn_884A54C8(Obj *o, char *a, char *b)
{
    for (int i = 0; i < o->count; i++) {
        char *s = o->items[i] + 0x10;
        if (s == a || s == b)
            return Flag1(0);
    }
    return Flag1(1);
}
