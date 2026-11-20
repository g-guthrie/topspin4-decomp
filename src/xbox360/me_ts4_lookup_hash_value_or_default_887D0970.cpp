/* Swing_DLL.xex 0x887D0970: returns (through the hidden pointer) the value stored under hash 0x3D952275 in the table at +0xc8
 * (fn_881BBC00 entry, word +4), defaulting to lbl_88D45B1C->+0x27c. agO: LTCG only (plain 2 off). */
struct Val4 {
    unsigned v;
    Val4(unsigned x) : v(x) {}
};
struct Entry { unsigned key; unsigned value; };
struct Ts4Globals { char pad[0x27c]; unsigned def; };
struct Obj { char pad[0xc8]; char table[4]; };
extern "C" Ts4Globals *lbl_88D45B1C;
extern "C" Entry *fn_881BBC00(void *table, const unsigned *key);
extern "C" Val4 fn_887D0970(Obj *o)
{
    Val4 r(lbl_88D45B1C->def);
    unsigned k = 0x3D952275u;
    Entry *e = fn_881BBC00(o->table, &k);
    if (e)
        r.v = e->value;
    return r;
}
