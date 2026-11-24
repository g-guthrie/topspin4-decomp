/* Swing_DLL.xex 0x881591F8: Ts4FloatGrid constructor: stores width and height, default-constructs the float
 * vector at +8 and resizes it to width * height (ts4_fvec_resize_88158B28). Same layout as Cx21Mat in
 * cx21_core_a.c (its copy constructor is 0x88159180).
 * Matches only as a real C++ constructor (member initialiser list, body reads the members): the C spelling
 * with the same stores loads w before h for the multiply; the constructor loads h (+4) first. */

typedef unsigned int u32;

struct Ts4FloatVec {
    float *first;
    float *last;
    float *cap;
    Ts4FloatVec() : first(0), last(0), cap(0) {}
};

extern "C" void ts4_fvec_resize_88158B28(Ts4FloatVec *v, u32 n);

struct Ts4FloatGrid {
    u32 w;            /* +0x00 */
    u32 h;            /* +0x04 */
    Ts4FloatVec cells; /* +0x08, w * h floats */
    Ts4FloatGrid(u32 width, u32 height);
};

Ts4FloatGrid::Ts4FloatGrid(u32 width, u32 height) : w(width), h(height)
{
    ts4_fvec_resize_88158B28(&cells, w * h);
}
