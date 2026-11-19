/* 0x886174F0: maps a hash to its index in a 6-entry lazily initialised static table (0 when unknown), stores the
 * index at +0x4C and the hash at +0x20C of the object at +0x44. Guard bit 0 of lbl_88D4BD50, table lbl_88D4BD38. */
struct Ts4Target { char p[0x20c]; unsigned hash; };
struct Ts4HashSel { char p[0x44]; Ts4Target *target; char p48[4]; unsigned index; };
extern "C" unsigned lbl_88D4BD50;
extern "C" unsigned lbl_88D4BD38[6];
extern "C" void fn_886174F0(Ts4HashSel *s, const unsigned &hash)
{
    unsigned *table = lbl_88D4BD38;
    unsigned g = lbl_88D4BD50;
    if (!(g & 1)) {
        lbl_88D4BD50 = g | 1;
        table[0] = 0xD6EA3914u; table[1] = 0x10C6BEC4u; table[2] = 0xB8EC9983u;
        table[3] = 0xB31B556Du; table[4] = 0x78E46251u; table[5] = 0xD60D5133u;
    }
    unsigned index = 0;
    for (unsigned i = 0; i < 6; i++)
        if (hash == table[i]) { index = i; break; }
    s->index = index;
    s->target->hash = hash;
}
