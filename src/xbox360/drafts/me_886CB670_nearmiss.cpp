/* 0x886CB670 near miss (65 off, size 0xE4-0xF4 vs 0x108). Finds a move entry (0x8C records in a self-relative
 * table) by id and style hash: style = mode ? 0xDDDB885D : 0x3583143C; mode 1 falls back to the default style.
 * Game keeps the style in a stack slot written in both arms (stw -0x10) and read back through a pointer, sets the
 * result r3=0 up front, and recomputes begin() for the second scan. C, C++ (hash class, ?: or if/else) tried. */
struct Ts4Hash { unsigned v; Ts4Hash() {} Ts4Hash(unsigned x) : v(x) {} bool operator==(const Ts4Hash &o) const { return v == o.v; } };
struct Ts4MoveEntry { char p[0x1c]; Ts4Hash style; char p2[0x84 - 0x20]; Ts4Hash id; char p3[4]; };
struct Ts4MoveTable { int self_off; int count;
    Ts4MoveEntry *begin() { Ts4MoveEntry *r = 0; if (self_off != -1) r = (Ts4MoveEntry *)((char *)this + self_off); return r; }
    Ts4MoveEntry *end() { Ts4MoveEntry *r = 0; if (self_off != -1) r = (Ts4MoveEntry *)((char *)this + (count * (int)sizeof(Ts4MoveEntry) + self_off)); return r; } };
struct Ts4MoveCfg { char p[0x560]; unsigned mode; };
struct Ts4MoveSet { char p[0x20]; Ts4MoveCfg *cfg; char p2[0x30 - 0x24]; Ts4MoveTable *table; };
static const Ts4Hash kDefaultStyle(0x3583143Cu);
Ts4MoveEntry *ts4_move_set_find(Ts4MoveSet *self, const Ts4Hash &id)
{
    Ts4MoveEntry *r = 0;
    unsigned mode = self->cfg->mode;
    const Ts4Hash dflt(0x3583143Cu);
    Ts4Hash style;
    if (mode == 0) style = dflt; else style = Ts4Hash(0xDDDB885Du);
    Ts4MoveTable *t = self->table;
    Ts4MoveEntry *end = t->end();
    for (Ts4MoveEntry *e = t->begin(); e != end; e++)
        if (e->id == id && e->style == style) return e;
    if (mode == 1)
        for (Ts4MoveEntry *e = t->begin(); e != end; e++)
            if (e->id == id && e->style == dflt) return e;
    return r;
}
