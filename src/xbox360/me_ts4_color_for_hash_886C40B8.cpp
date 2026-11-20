/* 0x886C40B8 ts4_color_for_hash: looks a hash up in a 4-entry {hash, ARGB colour} table and returns the colour, or
 * 0xFFFFFFFF for an unknown hash. In the original this is a function-local static table with a lazy-init guard
 * (bit 0 of lbl_88D4AAF8). Here the guard and table (lbl_88D4AAD8) are file-scope externs with the guard written out by
 * hand, which gives byte-identical code and the target's data symbol names. (A real `static` local compiles the same
 * code, but MSVC names it ?$S1@... / ?table@..., which fn_check rejects.) Validated: fn_check MATCH, size 0xc4, /Oc. */
struct Ts4Color {
    unsigned argb;
    Ts4Color() {}
    Ts4Color(unsigned v) : argb(v) {}
};
struct Ts4ColorByHash { unsigned hash; Ts4Color color; };
extern "C" unsigned lbl_88D4AAF8;
extern "C" Ts4ColorByHash lbl_88D4AAD8[4];
Ts4Color ts4_color_for_hash(const unsigned &hash)
{
    Ts4Color out(0xFFFFFFFFu);
    Ts4ColorByHash *table = lbl_88D4AAD8;
    unsigned g = lbl_88D4AAF8;
    if (!(g & 1)) {
        lbl_88D4AAF8 = g | 1;
        table[0].hash = 0x2ECCBB5Du; table[0].color = Ts4Color(0xFF00FF00u);
        table[1].hash = 0x4ECDD008u; table[1].color = Ts4Color(0xFFFF0000u);
        table[2].hash = 0x9A963DB5u; table[2].color = Ts4Color(0xFF0000FFu);
        table[3].hash = 0x3B9AD22Eu; table[3].color = Ts4Color(0xFFFFFF00u);
    }
    for (unsigned i = 0; i < 4; i++)
        if (table[i].hash == hash) { out = table[i].color; break; }
    return out;
}
