typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

#if defined(_MSC_VER)
typedef u32 ts4_memcpy_size;
#else
#include <stddef.h>
typedef size_t ts4_memcpy_size;
#endif

typedef struct SearchResult {
    u8 prefix[0x84];
    s32 first_stat;
    s32 second_stat;
    u8 middle[8];
    s32 round;
    u8 suffix[8];
} SearchResult;

typedef struct RelativeResultArray {
    s32 data_offset;
    s32 unknown;
    s32 capacity;
    s32 count;
} RelativeResultArray;

typedef struct SessionState {
    u8 reserved[0x31c];
    RelativeResultArray results;
} SessionState;

typedef struct SessionContext {
    u8 reserved[0x3c];
    SessionState *session;
} SessionContext;

extern SessionContext *g_ts4_session_context;
extern void ts4_init_search_result(SearchResult *result);
extern void *memcpy(
    void *destination,
    const void *source,
    ts4_memcpy_size size
);

/* Swing_DLL.xex 0x8877F818, registered as TSU_ReplaceSearchResultsWithPerRoundStats. */
u32 tsu_replace_search_results_with_per_round_stats(void)
{
    SearchResult per_round[4];
    SessionState *session;
    RelativeResultArray *results;
    SearchResult *aggregate;
    s32 index;
    s32 offset;
    s32 result_count;
    u32 remaining;

    index = 3;
    do {
        SearchResult *result = &per_round[3 - index];
        *(s32 *)((u8 *)result + 0x04) = 0;
        *(s32 *)((u8 *)result + 0x50) = 0;
        *(s32 *)((u8 *)result + 0x54) = 0;
        *(s32 *)((u8 *)result + 0x5c) = 0;
        *(s32 *)((u8 *)result + 0x6c) = 0;
        *(s32 *)((u8 *)result + 0x70) = 0;
        *(s32 *)((u8 *)result + 0x74) = 0;
        *(s32 *)((u8 *)result + 0x7c) = 0;
        *(s32 *)((u8 *)result + 0x80) = 0;
        *(s32 *)((u8 *)result + 0x90) = 0;
        ts4_init_search_result(result);
        --index;
    } while (index >= 0);

    per_round[0].round = 0;
    per_round[1].round = 1;
    per_round[2].round = 2;
    per_round[3].round = 3;

    session = g_ts4_session_context->session;
    results = &session->results;
    result_count = results->count;
    if (result_count > 0) {
        offset = 0;
        remaining = result_count;
        do {
            SearchResult *result = (SearchResult *)
                ((u8 *)results + results->data_offset + offset);
            s32 round = result->round;
            if ((round >= 0) && (round < 4)) {
                SearchResult *round_result = &per_round[round];
                round_result->second_stat += result->second_stat;
                round_result->first_stat += result->first_stat;
            }
            offset += sizeof(SearchResult);
            --remaining;
        } while (remaining != 0);
    }

    results->unknown = 0;
    aggregate = per_round;
    remaining = 4;
    do {
        if (results->unknown < results->capacity) {
            memcpy(
                (u8 *)results + results->data_offset +
                    results->unknown * sizeof(SearchResult),
                aggregate,
                sizeof(SearchResult)
            );
            ++results->unknown;
        }
        ++aggregate;
        --remaining;
    } while (remaining != 0);
    return 0;
}
