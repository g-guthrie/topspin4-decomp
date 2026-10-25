/*
 * Exact code identity for the functions listed for this unit in
 * config/54540859/remaining_20261025_units.json: full extents, effective
 * relocations and .pdata independently checked. Original ABI and semantics
 * remain provisional. Other declarations/helpers carry no separate credit.
 * AI-assisted, disassembly-derived reconstruction; see docs/exact-matches-20261025.md.
 *
 * Returns the word at offset 0x10 of the record selected by player slot, or -1. The field meaning and runtime reachability remain unknown.
 */
#include "s2b_pad_binding.h"

ts4_s32 fn_88614990(ts4_u8 *manager, ts4_s32 player)
{
    ts4_u8 *record = fn_88614938(manager, player);
    if (record != 0) {
        return *(ts4_s32 *)(record + 0x10);
    }
    return -1;
}
