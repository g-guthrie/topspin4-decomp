/* Q5: keyed hash-table lookup wrappers (Top Spin 4, Xbox 360, Swing_DLL.xex), plain route, no flags. */
#include "ga3_types.h"
typedef unsigned int u32;
/* 12-byte lookup key passed by address. */
typedef struct Q5HashKey3 { u32 kind; u32 value; u32 count; } Q5HashKey3;
/* 12-byte xdata handle passed by value (TS4TripleArg idiom); {0, 0xFFFFF, 0} is the null handle. */
typedef struct Q5Handle12 { u32 node; u32 offset; u32 extra; } Q5Handle12;
typedef struct Q5HashTable Q5HashTable;
extern Q5HashTable *lbl_88D458F0;
extern void *ts4_hash_find_arg_88180F08(Q5HashTable *table, struct Ga3Id hash, Q5HashKey3 *key, Q5Handle12 handle);

/* 0x888E3848: look up key {0, v, 1} under hash 0xC7F47320 in the global table, with a null handle */
void *ts4_hash_find_c7f47320_888E3848(u32 v)
{
    Q5HashKey3 key;
    Q5Handle12 none;
    struct Ga3Id hash;
    key.value = v;
    key.kind = 0;
    key.count = 1;
    none.node = 0;
    none.offset = 0xFFFFF;
    none.extra = 0;
    hash.value = 0xC7F47320u;
    return ts4_hash_find_arg_88180F08(lbl_88D458F0, hash, &key, none);
}
