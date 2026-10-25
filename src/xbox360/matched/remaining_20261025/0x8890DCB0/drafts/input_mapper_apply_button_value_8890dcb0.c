/*
 * Exact code identity for the functions listed for this unit in
 * config/54540859/remaining_20261025_units.json: full extents, effective
 * relocations and .pdata independently checked. Original ABI and semantics
 * remain provisional. Other declarations/helpers carry no separate credit.
 * AI-assisted, disassembly-derived reconstruction; see docs/exact-matches-20261025.md.
 *
 * Short tail-branch wrapper into 0x8890DB90. Runtime reachability and the destination behavior are not established by this unit.
 */
#include "x1_input_mapper.h"

void fn_8890DCB0(ts4_u8 *entry, ts4_u8 *binding)
{
    ts4_s32 channel = *(ts4_s32 *)(binding + 0x24);
    const ts4_u8 *map = *(const ts4_u8 **)(entry + 0x18);
    fn_8890DB90(entry, binding, map[((ts4_u32)channel + 0xCu) * 4u]);
}
