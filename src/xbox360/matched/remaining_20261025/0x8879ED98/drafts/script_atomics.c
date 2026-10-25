/*
 * Exact code identity for the functions listed for this unit in
 * config/54540859/remaining_20261025_units.json: full extents, effective
 * relocations and .pdata independently checked. Original ABI and semantics
 * remain provisional. Other declarations/helpers carry no separate credit.
 * AI-assisted, disassembly-derived reconstruction; see docs/exact-matches-20261025.md.
 *
 * The decrement uses the compiler interlocked intrinsic. Exact instruction identity does not verify behavior under contention or interrupts.
 */
#include "script_argument_helpers.h"

long _InterlockedDecrement(long volatile *);

/* Header 0x10 bytes before the text: allocator object at +0, count at +0xC. */
typedef struct ts4_atomics_text_header {
    void *allocator;
    ts4_u32 reserved[2];
    long volatile refs;
} ts4_atomics_text_header;

typedef void (*ts4_atomics_free_fn)(void *allocator, ts4_atomics_text_header *header);

void fn_8818EB10(char **out, const void *payload);

/* Registered as LaunchExe. 0x8879ED98-0x8879EE28. */
ts4_u32 fn_8879ED98(struct TS4ScriptContext *context)
{
    char *text;
    ts4_atomics_text_header *header;
    fn_8818EB10(&text, ts4_script_argument(context, 0)->payload);
    header = (ts4_atomics_text_header *)(text - 0x10);
    if (_InterlockedDecrement(&header->refs) == 0) {
        ts4_atomics_free_fn *dispatch = *(ts4_atomics_free_fn **)header->allocator;
        dispatch[0x8 / sizeof(ts4_atomics_free_fn)](header->allocator, header);
    }
    return 0;
}
