/*
 * Exact code identity for the functions listed for this unit in
 * config/54540859/remaining_20261025_units.json: full extents, effective
 * relocations and .pdata independently checked. Original ABI and semantics
 * remain provisional. Other declarations/helpers carry no separate credit.
 * AI-assisted, disassembly-derived reconstruction; see docs/exact-matches-20261025.md.
 *
 * Device initialization forwards a 12-byte handle through argument registers and copies configuration fields. This handle convention and the original source signature remain inferred.
 */
#include "s1_input_common.h"

#define TS4_INPUT_CONFIG_TYPE 0xB40632A8u

void fn_88888538(ts4_u8 *device, ts4_typed_handle config)
{
    ts4_u8 *record;
    fn_88628D48(device, config);
    record = fn_88923530(config.container, config, TS4_INPUT_CONFIG_TYPE);
    *(ts4_u32 *)(device + 0x34) = *(ts4_u32 *)(record + 0x20);
    device[0x1D] = record[0x1D];
    device[0x1C] = record[0x1E];
}
