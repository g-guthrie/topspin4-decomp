/* FAM2: inlined global hash-table lookups with the null handle.  Each is
 * ts4_hash_find_881AB900 inlined for a constant HASH on the table held by lbl_88D458F0:
 * find the bucket node via fn_881518D0, resolve it with fn_8892E7A0 and
 * return the record's +0x14 payload, or 0 when absent. */
#ifndef _MSC_VER
#define __forceinline inline
#endif
typedef unsigned int u32;
typedef struct Ts4Handle12 { u32 a, b, c; } Ts4Handle12;
typedef struct Ts4HashTable { u32 pad[7]; void *buckets; } Ts4HashTable;
typedef struct Ts4HashRecord { u32 pad[5]; void *payload; } Ts4HashRecord;

extern Ts4HashTable *lbl_88D458F0;
extern void *fn_881518D0(void *buckets, u32 *hash);
extern Ts4HashRecord *fn_8892E7A0(Ts4HashTable *table, void *node, u32 a,
                                  u32 b, u32 c, Ts4Handle12 h);
extern void *ts4_hash_find_881AB900(Ts4HashTable *table, u32 hash, Ts4Handle12 h);

static __forceinline void *hash_find(Ts4HashTable *table, u32 hash, Ts4Handle12 h)
{
    void *result = 0;
    void *node = fn_881518D0(table->buckets, &hash);
    if (node) {
        Ts4HashRecord *rec = fn_8892E7A0(table, node, 1, 0, 0, h);
        if (rec)
            result = rec->payload;
    }
    return result;
}

#define TS4_HASH_FIND_NULL(A, HASH) \
void *ts4_hash_find_null_##A(void); \
void *ts4_hash_find_null_##A(void) \
{ \
    Ts4Handle12 h; \
    h.a = 0; \
    h.b = 0xFFFFF; \
    h.c = 0; \
    return hash_find(lbl_88D458F0, HASH, h); \
}

TS4_HASH_FIND_NULL(88848D60, 0x0F55F779)
TS4_HASH_FIND_NULL(88848DF0, 0x2565E2C5)
TS4_HASH_FIND_NULL(8884A0C0, 0x78722220)
TS4_HASH_FIND_NULL(8884B090, 0x8120B8B2)
TS4_HASH_FIND_NULL(8884B1A8, 0x40766126)
TS4_HASH_FIND_NULL(8884B238, 0xB0DEF59F)
TS4_HASH_FIND_NULL(8884B3C8, 0xD75A321C)
TS4_HASH_FIND_NULL(8884B458, 0xF991252B)
TS4_HASH_FIND_NULL(8884B4E8, 0x8F69DCEC)
TS4_HASH_FIND_NULL(8884B578, 0x31F4E86E)
TS4_HASH_FIND_NULL(8884B608, 0x1D25E468)
TS4_HASH_FIND_NULL(888689F8, 0x59CA7C3B)
TS4_HASH_FIND_NULL(88868BB8, 0x243E0FE3)
TS4_HASH_FIND_NULL(888E1D40, 0x042947AB)
TS4_HASH_FIND_NULL(888E3968, 0xEDAACCDA)
TS4_HASH_FIND_NULL(888E39F8, 0xE969ADBC)

/* The out-of-line lookup the constants above inline. */
void *ts4_hash_find_881AB900(Ts4HashTable *table, u32 hash, Ts4Handle12 h)
{
    void *result = 0;
    void *node = fn_881518D0(table->buckets, &hash);
    if (node) {
        Ts4HashRecord *rec = fn_8892E7A0(table, node, 1, 0, 0, h);
        if (rec)
            result = rec->payload;
    }
    return result;
}

/* Lookup with caller-supplied resolve arguments. */
void *ts4_hash_find_arg_88180F08(Ts4HashTable *table, u32 hash, u32 b, Ts4Handle12 h)
{
    void *result = 0;
    void *node = fn_881518D0(table->buckets, &hash);
    if (node) {
        Ts4HashRecord *rec = fn_8892E7A0(table, node, 1, b, 1, h);
        if (rec)
            result = rec->payload;
    }
    return result;
}

typedef struct Ts4HashNode { u32 pad[3]; int pinned; } Ts4HashNode;

void *ts4_hash_find_args_88170EC0(Ts4HashTable *table, u32 hash, u32 a, u32 b,
                                  u32 c, Ts4Handle12 h)
{
    void *result = 0;
    Ts4HashNode *node = fn_881518D0(table->buckets, &hash);
    if (node) {
        Ts4HashRecord *rec = fn_8892E7A0(table, node, node->pinned == 0 ? a : 1, b, c, h);
        if (rec)
            result = rec->payload;
    }
    return result;
}

typedef struct Ts4HashPair { u32 pad[2]; void *f8, *f0c; } Ts4HashPair;

void ts4_hash_find_pair_88848CA0(Ts4HashPair *self)
{
    Ts4Handle12 h;
    h.a = 0;
    h.b = 0xFFFFF;
    h.c = 0;
    self->f8 = ts4_hash_find_881AB900(lbl_88D458F0, 0xAF3F8C5F, h);
    h.a = 0;
    h.b = 0xFFFFF;
    h.c = 0;
    self->f0c = hash_find(lbl_88D458F0, 0x2E1C39A1, h);
}

/* Resolve to a handle: the null handle unless the record is found, in which
 * case its first two words come back swapped (id, object) plus the third. */
Ts4Handle12 *ts4_hash_find_handle_881814E0(Ts4Handle12 *out, Ts4HashTable *table, u32 hash,
                                           u32 b, u32 c, void *node, Ts4Handle12 h)
{
    void *n;
    out->a = 0;
    out->c = 0;
    out->b = 0xFFFFF;
    if (node)
        n = node;
    else
        n = fn_881518D0(table->buckets, &hash);
    if (n) {
        Ts4Handle12 *rec = (Ts4Handle12 *)fn_8892E7A0(table, n, 1, b, c, h);
        if (rec) {
            Ts4Handle12 t = *rec;
            out->b = t.a;
            out->a = t.b;
            out->c = t.c;
        }
    }
    return out;
}
