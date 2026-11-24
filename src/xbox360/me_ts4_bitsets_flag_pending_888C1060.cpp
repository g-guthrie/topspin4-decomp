/* 0x888C1060: true when bit k is set in the set at +0x44 but not in +0x58, or set in +0x1c but not in +0x30.
 * fn_8817E150 returns a non-POD {word*, mask} bit reference through a hidden pointer, hence C++. */

typedef unsigned int u32;
struct BitRef { u32 *w; u32 m; BitRef(u32 *a, u32 b) : w(a), m(b) {} bool get() const { return (m & *w) != 0; } };
struct Bits { char p[0x14]; };
struct O { char p[0x1c]; Bits b1c; Bits b30; Bits b44; Bits b58; };
extern "C" BitRef fn_8817E150(Bits *b, u32 k);
extern "C" int ts4_bitsets_flag_pending_888C1060(O *o, u32 k) {
    int r;
    if ((fn_8817E150(&o->b44, k).get() && !fn_8817E150(&o->b58, k).get())
        || (fn_8817E150(&o->b1c, k).get() && !fn_8817E150(&o->b30, k).get())) r = 1;
    else r = 0;
    return r;
}
