#include "script_context.h"

#if defined(_MSC_VER)
#define TS4_FORCEINLINE __forceinline
#else
#define TS4_FORCEINLINE inline __attribute__((always_inline))
#endif

struct TS4NetDbStatRecord {
    ts4_script_u8 reserved[0x40];
    ts4_script_u8 first_block[0x20];
    ts4_script_u8 second_block[0x10];
    ts4_script_u8 third_block[0x10];
    ts4_script_u32 first_value;
    ts4_script_u32 second_value;
    ts4_script_u32 third_value;
    ts4_script_u8 trailing[0x0C];
};

struct TS4RelativeStatArray {
    int data_offset;
    int count;
};

struct TS4NetDbStats {
    ts4_script_u8 reserved[0x1C];
    struct TS4RelativeStatArray records;
};

struct TS4LocalNetDbStatSource {
    ts4_script_u8 reserved0[0x0C];
    ts4_script_u32 second_value;
    ts4_script_u8 reserved1[0x10];
    ts4_script_u32 first_value;
    ts4_script_u8 reserved2[0xBC];
    ts4_script_u8 first_block[0x20];
    ts4_script_u8 reserved3[0x20];
    ts4_script_u8 second_block[0x10];
    ts4_script_u8 third_block[0x10];
    ts4_script_u8 reserved4[0x10];
    ts4_script_u32 third_value;
};

struct TS4LocalPlayerStats {
    ts4_script_u8 reserved[0xEC];
    struct TS4LocalNetDbStatSource netdb_source;
};

struct TS4NetDbOnlineContext {
    ts4_script_u8 reserved0[0x2C];
    struct TS4LocalPlayerStats *local_player;
    ts4_script_u8 reserved1[0x158];
    struct TS4NetDbStats *netdb_stats;
};

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern struct TS4NetDbOnlineContext *g_ts4_online_context;

void ts4_initialize_netdb_stat_record(struct TS4NetDbStatRecord *record);
void ts4_copy_bytes(
    void *destination,
    const void *source,
    ts4_script_u32 size
);

static TS4_FORCEINLINE double ts4_get_netdb_argument_number(
    struct TS4ScriptValue *value
)
{
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        return value->value.number;
    }
    if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        return value->value.integer;
    }
    return g_ts4_script_constants[11];
}

/*
 * Swing_DLL.xex 0x8877F970, registered as
 * TSU_CopyLocalStatToNetDB.
 */
ts4_script_u32 ts4_script_copy_local_stat_to_netdb(
    struct TS4ScriptContext *context
)
{
    struct TS4ScriptValue *argument;
    int index;

    if (context->arguments->count > 0) {
        argument = context->arguments->first_value;
    } else {
        argument = g_ts4_default_script_value;
    }
    index = (int)ts4_get_netdb_argument_number(argument);

    if (g_ts4_online_context != 0) {
        struct TS4NetDbStats *stats = g_ts4_online_context->netdb_stats;
        struct TS4LocalNetDbStatSource *local =
            &g_ts4_online_context->local_player->netdb_source;
        struct TS4RelativeStatArray *records = &stats->records;

        if (index < records->count) {
            struct TS4NetDbStatRecord *record =
                (struct TS4NetDbStatRecord *)(
                    (ts4_script_u8 *)records + records->data_offset +
                    index * sizeof(*record)
                );
            ts4_initialize_netdb_stat_record(record);
            record->first_value = local->first_value;
            record->third_value = local->third_value;
            record->second_value = local->second_value;
            ts4_copy_bytes(record->first_block, local->first_block, 0x20);
            ts4_copy_bytes(record->second_block, local->second_block, 0x10);
            ts4_copy_bytes(record->third_block, local->third_block, 0x10);
        }
    }
    return 0;
}
