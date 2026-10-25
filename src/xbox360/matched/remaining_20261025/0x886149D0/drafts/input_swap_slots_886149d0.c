/*
 * Exact code identity for the functions listed for this unit in
 * config/54540859/remaining_20261025_units.json: full extents, effective
 * relocations and .pdata independently checked. Original ABI and semantics
 * remain provisional. Other declarations/helpers carry no separate credit.
 * AI-assisted, disassembly-derived reconstruction; see docs/exact-matches-20261025.md.
 *
 * Swaps player-slot bindings in records and the manager table. The original code does not null-check both records; caller preconditions remain inferred.
 */
#include "s2a_common.h"

void fn_886149D0(ts4_u8 *manager, ts4_u32 first, ts4_u32 second)
{
    ts4_u8 *first_record, *second_record;
    ts4_u32 *table;
    ts4_u32 first_pad, second_pad;
    if (first == second) {
        return;
    }
    first_record = fn_88614938(manager, first);
    second_record = fn_88614938(manager, second);
    if (second_record[0x19] != 0) {
        return;
    }
    *(ts4_u32 *)(second_record + 0xC) = first;
    *(ts4_u32 *)(first_record + 0xC) = second;
    table = *(ts4_u32 **)(manager + 0x30);
    first_pad = table[first];
    second_pad = table[second];
    table[first] = second_pad;
    (*(ts4_u32 **)(manager + 0x30))[second] = first_pad;
}
