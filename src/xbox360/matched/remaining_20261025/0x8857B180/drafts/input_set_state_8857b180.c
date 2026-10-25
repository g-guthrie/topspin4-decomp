/*
 * Exact code identity for the functions listed for this unit in
 * config/54540859/remaining_20261025_units.json: full extents, effective
 * relocations and .pdata independently checked. Original ABI and semantics
 * remain provisional. Other declarations/helpers carry no separate credit.
 * AI-assisted, disassembly-derived reconstruction; see docs/exact-matches-20261025.md.
 *
 * Vibration forwarding wrapper. Device classification, kernel-version field roles and the original signature remain inferred.
 */
#include "s2a_common.h"

#define TS4_KERNEL_BUILD_LIMIT 0x15EBu

extern const ts4_u16 *__imp_XboxKrnlVersion; /* symbols.txt @553f783: __imp_XboxKrnlVersion = .rdata:0x88000874 (import pointer) */

typedef struct ts4_vibration_pair { ts4_u16 first; ts4_u16 second; } ts4_vibration_pair; /* the two u16 at +0/+2 [I] */

ts4_u32 fn_8857B180(ts4_u32 user, const ts4_u8 *vibration)
{
    ts4_vibration_pair local;
    const ts4_u16 *version = __imp_XboxKrnlVersion;
    local = *(const ts4_vibration_pair *)vibration;
    if (version[0] == 2 && version[1] == 0 && version[2] < TS4_KERNEL_BUILD_LIMIT) {
        ts4_u8 capabilities[0x14]; /* XINPUT_CAPABILITIES is 20 bytes; frame evidence below */
        if (XamInputGetCapabilities(user, 1, capabilities) == 0 && capabilities[1] == 2 &&
            (*(ts4_u16 *)(capabilities + 2) & 1) != 0 && (*(ts4_u16 *)(capabilities + 2) & 2) != 0) {
            local.first = *(const ts4_u16 *)(vibration + 2);
            local.second = *(const ts4_u16 *)vibration;
        }
    }
    return XamInputSetState(user, 0, (ts4_u8 *)&local, 0, 0, 0);
}
