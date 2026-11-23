/* nearmiss: MATCH only as C++ member ??MHKey@@QBA_NABU0@@Z (plain, /Oc); every extern "C" free-function form is 39 off (this vs first-param register numbering). Blocker: caller fk5_001.c (C) references fn_881509F8, so integration needs a callers rename or a linker alias. */
#include "include/ts4/ts4.h"
struct HKey {
    unsigned int w[8];
    unsigned long long hash() const
    {
        unsigned long long h = w[0];
        h = (h << 4) ^ w[1];
        h = (h << 5) ^ w[3];
        h = (h << 5) ^ w[4];
        h = (h << 6) ^ w[5];
        h = (h << 6) ^ w[6];
        h = (h << 10) ^ w[7];
        return h;
    }
    bool operator<(const HKey &o) const;
};
bool HKey::operator<(const HKey &o) const { return hash() < o.hash(); }
extern "C" bool ts4_hkey_less_881509F8(const HKey *a, const HKey *b) { return a->hash() < b->hash(); }
