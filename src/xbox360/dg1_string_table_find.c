/* DG1: lookup in a chained string hash table (hash = h * 33 + c). */
typedef unsigned int u32;

/* Chain node; name pointer first, next/hash positions differ per table. */
#define DG1_NODE_TYPE(TYPE, PAD_A, PAD_B) \
    typedef struct TYPE { \
        const char *name; \
        u32 pad_a[PAD_A]; \
        struct TYPE *next; \
        u32 hash; \
        u32 pad_b[PAD_B]; \
    } TYPE;

DG1_NODE_TYPE(Dg1StrNodeA, 4, 0)    /* next 0x14, hash 0x18 */
DG1_NODE_TYPE(Dg1StrNodeB, 13, 0)   /* next 0x38, hash 0x3C */
DG1_NODE_TYPE(Dg1StrNodeC, 10, 0)   /* next 0x2C, hash 0x30 */
DG1_NODE_TYPE(Dg1StrNodeD, 1, 0)    /* next 0x08, hash 0x0C */

typedef struct Dg1StrTable {
    u32 pad00[5];
    void **buckets;   /* 0x14 */
    u32 pad18;
    u32 bucket_count;       /* 0x1C */
} Dg1StrTable;

/* Hashes *key_ptr, stores hash and bucket index, and returns the node whose name matches
   (storing its predecessor in *prev_out), or 0. */
#ifdef _MSC_VER
extern int strcmp(const char *, const char *);
#pragma intrinsic(strcmp)
#else
#include <string.h>
#endif

/* Hashes *key_ptr (h = h * 33 + c), stores hash and bucket index, and returns the chain node whose
   hash and name match (storing its predecessor in *prev_out), or 0. */
#define DG1_STRING_TABLE_FIND(NAME, NODE) \
NODE *NAME(Dg1StrTable *t, const char **key_ptr, u32 *bucket_out, u32 *hash_out, NODE **prev_out) \
{ \
    const char *key = *key_ptr; \
    const char *p = key; \
    u32 h = 0; \
    u32 idx; \
    NODE **bk; \
    NODE *prev; \
    NODE *n; \
    while (*p != 0) { h = h * 33 + *p; p++; } \
    idx = h % t->bucket_count; \
    bk = (NODE **)t->buckets; \
    *hash_out = h; \
    *bucket_out = idx; \
    if (bk == 0) return 0; \
    *prev_out = 0; \
    prev = 0; \
    for (n = bk[idx]; n != 0; n = n->next) { \
        if (n->hash == h) { \
            if (strcmp(n->name, key) == 0) { *prev_out = prev; return n; } \
        } \
        prev = n; \
    } \
    return 0; \
}

DG1_STRING_TABLE_FIND(ts4_string_table_find_881903A8, Dg1StrNodeA)
DG1_STRING_TABLE_FIND(ts4_string_table_find_881EEC90, Dg1StrNodeB)
DG1_STRING_TABLE_FIND(ts4_string_table_find_881EED78, Dg1StrNodeC)
DG1_STRING_TABLE_FIND(ts4_string_table_find_881FBA58, Dg1StrNodeD)
