/*
 * Exact code identity for the functions listed for this unit in
 * config/54540859/remaining_20261025_units.json: full extents, effective
 * relocations and .pdata independently checked. Original ABI and semantics
 * remain provisional. Other declarations/helpers carry no separate credit.
 * AI-assisted, disassembly-derived reconstruction; see docs/exact-matches-20261025.md.
 *
 * Reads a raw signed 16-bit axis value as float, without normalization. The id-dependent offsets and the default global agree with the target; their roles remain inferred.
 */
#ifdef __cplusplus
extern "C" { /* C++ profile candidate: C linkage for the shared C declarations (unmangled names, C calling convention) */
#endif
#include "x1_input_mapper.h"
#ifdef __cplusplus
}
#endif

float fn_8890D5F0(const ts4_u8 *map, ts4_s32 id)
{
    float fallback = g_ts4_event_value;
    ts4_u8 dpad;
    if (id <= 5) {
        return (float)*(const ts4_s16 *)(map + ((ts4_u32)id + 0x21u) * 4u);
    }
    dpad = *(const ts4_u16 *)(map + 0x84) != 0 || *(const ts4_u16 *)(map + 0x88) != 0;
    if (id == 6) {
        return (float)*(const ts4_s16 *)(map + ((ts4_u32)(dpad ? 0 : 2) + 0x21u) * 4u);
    }
    if (id == 7) {
        return (float)*(const ts4_s16 *)(map + ((ts4_u32)(dpad ? 1 : 3) + 0x21u) * 4u);
    }
    return fallback;
}
