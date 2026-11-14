/* Swing_DLL.xex 0x881902D0-0x8827BA6C, executable version 0.0.0.3. */
typedef unsigned int u32;

typedef struct Ts4BucketNode8 {
    char pad0[0x8];
    struct Ts4BucketNode8 *next;
} Ts4BucketNode8;

typedef struct Ts4BucketTable8 {
    char pad0[0x14];
    Ts4BucketNode8 **buckets;
    u32 bucket_count_field;
    u32 bucket_count;
    char pad20[0x34 - 0x20];
    u32 busy;
} Ts4BucketTable8;

typedef struct Ts4BucketNode14 {
    char pad0[0x14];
    struct Ts4BucketNode14 *next;
} Ts4BucketNode14;

typedef struct Ts4BucketTable14 {
    char pad0[0x14];
    Ts4BucketNode14 **buckets;
    u32 bucket_count_field;
    u32 bucket_count;
    char pad20[0x34 - 0x20];
    u32 busy;
} Ts4BucketTable14;

typedef struct Ts4BucketNode38 {
    char pad0[0x38];
    struct Ts4BucketNode38 *next;
} Ts4BucketNode38;

typedef struct Ts4BucketTable38 {
    char pad0[0x14];
    Ts4BucketNode38 **buckets;
    u32 bucket_count_field;
    u32 bucket_count;
    char pad20[0x34 - 0x20];
    u32 busy;
} Ts4BucketTable38;

extern void *fn_881F0388(void *table, int flag);
extern void fn_881992A8(void *context, void *memory);
extern void fn_881C5AA8(void *table, void *value, int flag);
extern void fn_881906E8(Ts4BucketTable14 *table, Ts4BucketNode14 *node);
extern void fn_881C5B50(Ts4BucketTable8 *table, Ts4BucketNode8 *node);
extern void fn_881EFF80(Ts4BucketTable8 *table, Ts4BucketNode8 *node);
extern void ts4_if_call_seq_u32_off0_881EF9A0(Ts4BucketTable38 *table, Ts4BucketNode38 *node);
extern void ts4_if_call_seq_u32_off0_881F0208(Ts4BucketTable8 *table, Ts4BucketNode8 *node);
extern void fn_8827BF00(Ts4BucketTable8 *table, Ts4BucketNode8 *node);

void ts4_clear_bucket_table_881902D0(Ts4BucketTable14 *table)
{
    table->busy = table->busy + 1;
    if (table->buckets != 0) {
        u32 index;

        for (index = 0; index < table->bucket_count; index++) {
            Ts4BucketNode14 *current = table->buckets[index];

            while (current != 0) {
                Ts4BucketNode14 *node = current;

                current = current->next;
                fn_881906E8(table, node);
            }
        }
    }
    if (table->buckets != 0) {
        fn_881992A8(0, table->buckets);
    }
    table->buckets = 0;
    table->bucket_count_field = 0;
    if (table->busy == 0) {
        fn_881C5AA8(table, fn_881F0388(table, 0), 0);
    }
    table->busy = table->busy - 1;
}

void ts4_clear_bucket_table_881C5878(Ts4BucketTable8 *table)
{
    table->busy = table->busy + 1;
    if (table->buckets != 0) {
        u32 index;

        for (index = 0; index < table->bucket_count; index++) {
            Ts4BucketNode8 *current = table->buckets[index];

            while (current != 0) {
                Ts4BucketNode8 *node = current;

                current = current->next;
                fn_881C5B50(table, node);
            }
        }
    }
    if (table->buckets != 0) {
        fn_881992A8(0, table->buckets);
    }
    table->buckets = 0;
    table->bucket_count_field = 0;
    if (table->busy == 0) {
        fn_881C5AA8(table, fn_881F0388(table, 0), 0);
    }
    table->busy = table->busy - 1;
}

void ts4_clear_bucket_table_881EF198(Ts4BucketTable8 *table)
{
    table->busy = table->busy + 1;
    if (table->buckets != 0) {
        u32 index;

        for (index = 0; index < table->bucket_count; index++) {
            Ts4BucketNode8 *current = table->buckets[index];

            while (current != 0) {
                Ts4BucketNode8 *node = current;

                current = current->next;
                fn_881EFF80(table, node);
            }
        }
    }
    if (table->buckets != 0) {
        fn_881992A8(0, table->buckets);
    }
    table->buckets = 0;
    table->bucket_count_field = 0;
    if (table->busy == 0) {
        fn_881C5AA8(table, fn_881F0388(table, 0), 0);
    }
    table->busy = table->busy - 1;
}

void ts4_clear_bucket_table_881EF750(Ts4BucketTable38 *table)
{
    table->busy = table->busy + 1;
    if (table->buckets != 0) {
        u32 index;

        for (index = 0; index < table->bucket_count; index++) {
            Ts4BucketNode38 *current = table->buckets[index];

            while (current != 0) {
                Ts4BucketNode38 *node = current;

                current = current->next;
                ts4_if_call_seq_u32_off0_881EF9A0(table, node);
            }
        }
    }
    if (table->buckets != 0) {
        fn_881992A8(0, table->buckets);
    }
    table->buckets = 0;
    table->bucket_count_field = 0;
    if (table->busy == 0) {
        fn_881C5AA8(table, fn_881F0388(table, 0), 0);
    }
    table->busy = table->busy - 1;
}

void ts4_clear_bucket_table_881EFA60(Ts4BucketTable8 *table)
{
    table->busy = table->busy + 1;
    if (table->buckets != 0) {
        u32 index;

        for (index = 0; index < table->bucket_count; index++) {
            Ts4BucketNode8 *current = table->buckets[index];

            while (current != 0) {
                Ts4BucketNode8 *node = current;

                current = current->next;
                ts4_if_call_seq_u32_off0_881F0208(table, node);
            }
        }
    }
    if (table->buckets != 0) {
        fn_881992A8(0, table->buckets);
    }
    table->buckets = 0;
    table->bucket_count_field = 0;
    if (table->busy == 0) {
        fn_881C5AA8(table, fn_881F0388(table, 0), 0);
    }
    table->busy = table->busy - 1;
}

void ts4_clear_bucket_table_8827B998(Ts4BucketTable8 *table)
{
    table->busy = table->busy + 1;
    if (table->buckets != 0) {
        u32 index;

        for (index = 0; index < table->bucket_count; index++) {
            Ts4BucketNode8 *current = table->buckets[index];

            while (current != 0) {
                Ts4BucketNode8 *node = current;

                current = current->next;
                fn_8827BF00(table, node);
            }
        }
    }
    if (table->buckets != 0) {
        fn_881992A8(0, table->buckets);
    }
    table->buckets = 0;
    table->bucket_count_field = 0;
    if (table->busy == 0) {
        fn_881C5AA8(table, fn_881F0388(table, 0), 0);
    }
    table->busy = table->busy - 1;
}
