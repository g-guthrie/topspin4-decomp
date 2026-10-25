/*
 * Exact code identity for the functions listed for this unit in
 * config/54540859/remaining_20261025_units.json: full extents, effective
 * relocations and .pdata independently checked. Original ABI and semantics
 * remain provisional. Other declarations/helpers carry no separate credit.
 * AI-assisted, disassembly-derived reconstruction; see docs/exact-matches-20261025.md.
 *
 * Per-pad map reset. Release thresholds become zero and press thresholds become one. The void signature is provisional even though the generated return register agrees with retail.
 */
#include "guest_std.h"

#include "pad_map.h"

void fn_886096C0(ts4_u8 *map)
{
    ts4_u32 i;
    for (i = 0; i < 12; i++) {
        if (map[0x78 + i] != 0) {
            map[0x78 + i] = map[0x30 + 4 * i] == 0;
        }
    }
    fn_8856ABA0(map + 0x30, 0, 0x30);
    memset((ts4_u32 *)(map + 0x6C), 0, 12);
    memset((ts4_u32 *)(map + 0xA8), 0, 12);
    for (i = 0; i < 6; i++) {
        *(ts4_u16 *)(map + 0x9C + 2 * i) = 1;
    }
    for (i = 0; i < 12; i++) {
        map[0x60 + i] = 1;
    }
}
