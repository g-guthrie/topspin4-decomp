/* Swing_DLL.xex 0x8847A040: returns {1} when an 8-byte pair of the array at +0x150 (count +0x154) has x as its second word,
 * else {0} (1-byte result returned through the hidden pointer). agO: plain and LTCG. */
struct Flag1 {
    unsigned char v;
    Flag1(unsigned char x) : v(x) {}
};
struct Pair { void *first; void *second; };
struct Obj { char pad[0x150]; Pair *pairs; int count; };
extern "C" Flag1 fn_8847A040(Obj *o, void *x)
{
    for (int i = 0; i < o->count; i++) {
        if (o->pairs[i].second == x)
            return Flag1(1);
    }
    return Flag1(0);
}
