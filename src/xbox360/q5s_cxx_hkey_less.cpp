/* 0x881509F8: HKey::operator<(const HKey &) const: orders two 8-word keys by a 64-bit hash folded from
 * words 0, 1, 3, 4, 5, 6 and 7 (shift 4, 5, 5, 6, 6, 10, xor).
 * It matches only as a C++ member (as an extern "C" function with two pointers the registers are numbered
 * differently, 39 instructions off). symbols.txt therefore holds the decorated name ??MHKey@@QBA_NABU0@@Z;
 * C sources call it as ts4_hkey_less_881509F8, its reviewed "cxx" alias
 * (config/54540859/icf_aliases.json, docs/ltcg-route.md section 12). */
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
