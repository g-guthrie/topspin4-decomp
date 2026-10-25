/*
 * Exact code identity for the functions listed for this unit in
 * config/54540859/remaining_20261025_units.json: full extents, effective
 * relocations and .pdata independently checked. Original ABI and semantics
 * remain provisional. Other declarations/helpers carry no separate credit.
 * AI-assisted, disassembly-derived reconstruction; see docs/exact-matches-20261025.md.
 *
 * Script-side pad-list consumer. The called cleanup function has additional effects outside this unit. Exact code does not establish safety for a missing device.
 */
#include "s2b_pad_binding.h"

ts4_u32 fn_88782AA8(struct TS4ScriptContext *context)
{
    ts4_s32 pad = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u8 *table = (ts4_u8 *)lbl_88D45B30;
    ts4_s32 i;
    for (i = 0; i < 4; i++) {
        if (pad == -1 || pad == i) {
            ts4_pad_device_pair *end = *(ts4_pad_device_pair **)(table + 0x20);
            ts4_pad_device_pair *it = *(ts4_pad_device_pair **)(table + 0x1C);
            void *device = 0;
            for (; end != it; it++) {
                if ((ts4_u32)i == (ts4_u32)it->pad) { /* unsigned key compare [I: cmplw i,key] */
                    device = it->device;
                    break;
                }
            }
            fn_88887A00(device);
        }
    }
    return 0;
}
