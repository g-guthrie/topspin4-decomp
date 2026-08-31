#include "script_context.h"

typedef int ts4_script_s32;

#if defined(_MSC_VER)
typedef ts4_script_u32 ts4_memcpy_size;
#else
#include <stddef.h>
typedef size_t ts4_memcpy_size;
#endif

struct TS4SessionStats {
    ts4_script_u8 reserved[0x84];
    ts4_script_u32 stat_a;
    ts4_script_u32 stat_b;
    ts4_script_u8 tail[0x14];
};

struct TS4SearchResults {
    ts4_script_s32 data_offset;
    ts4_script_s32 length;
    ts4_script_s32 capacity;
    ts4_script_s32 source_count;
};

struct TS4StatsOnlineManager {
    ts4_script_u8 reserved[0x31C];
    struct TS4SearchResults results;
};

struct TS4StatsOnlineContext {
    ts4_script_u8 reserved[0x3C];
    struct TS4StatsOnlineManager *manager;
};

extern struct TS4StatsOnlineContext *g_ts4_session_context;

void ts4_session_stats_init(struct TS4SessionStats *stats);
#if defined(_MSC_VER)
#pragma function(memcpy)
#endif
void *memcpy(
    void *destination,
    const void *source,
    ts4_memcpy_size size
);

/*
 * Swing_DLL.xex 0x8877F758, registered as
 * TSU_ReplaceSearchResultsWithSessionStats.
 */
ts4_script_u32 ts4_script_tsu_replace_search_results_with_session_stats(void)
{
    struct TS4SessionStats combined;
    struct TS4StatsOnlineManager *manager;
    struct TS4SearchResults *results;
    ts4_script_s32 remaining;

    ts4_session_stats_init(&combined);
    manager = g_ts4_session_context->manager;
    results = &manager->results;

    remaining = results->source_count;
    if (remaining > 0) {
        ts4_script_u32 byte_offset = 0;
        while (remaining > 0) {
            struct TS4SessionStats *entry = (struct TS4SessionStats *)(
                (ts4_script_u8 *)results + results->data_offset + byte_offset
            );
            combined.stat_b += entry->stat_b;
            combined.stat_a += entry->stat_a;
            byte_offset += sizeof(*entry);
            --remaining;
        }
    }

    results->length = 0;
    if (results->capacity > 0) {
        struct TS4SessionStats *first = (struct TS4SessionStats *)(
            (ts4_script_u8 *)results + results->data_offset
        );
        memcpy(first, &combined, sizeof(combined));
        ++results->length;
    }

    return 0;
}
