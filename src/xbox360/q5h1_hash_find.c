/* Q5h1 clone: keyed hash-table lookup wrapper (Top Spin 4, Xbox 360, Swing_DLL.xex), plain route, no flags.
 * Clone of ts4_hash_find_c7f47320_888E3848 (q5_gameplay_hash_find.c). The sister 0x88848B50 differs only in the
 * hash constant: 0x00DEEEF6u instead of 0xC7F47320u. The hash is passed as struct Ga3Id by value, as in the
 * template (a plain u32 argument does not match). */
#include "ga3_types.h"
typedef unsigned int u32;
/* 12-byte lookup key passed by address. */
typedef struct Q5h1HashKey { u32 kind; u32 value; u32 count; } Q5h1HashKey;
/* 12-byte xdata handle passed by value; {0, 0xFFFFF, 0} is the null handle. */
typedef struct Q5h1Handle { u32 node; u32 offset; u32 extra; } Q5h1Handle;
typedef struct Q5h1HashTable Q5h1HashTable;
extern Q5h1HashTable *lbl_88D458F0;
extern void *ts4_hash_find_arg_88180F08(Q5h1HashTable *table, struct Ga3Id hash, Q5h1HashKey *key, Q5h1Handle handle);

/* Swing_DLL.xex 0x88848B50: look up key {0, v, 1} under hash 0x00DEEEF6 in the global table, with a null handle */
void *ts4_hash_find_00deeef6_88848B50(u32 v)
{
    Q5h1HashKey key;
    Q5h1Handle none;
    struct Ga3Id hash;
    key.value = v;
    key.kind = 0;
    key.count = 1;
    none.node = 0;
    none.offset = 0xFFFFF;
    none.extra = 0;
    hash.value = 0x00DEEEF6u;
    return ts4_hash_find_arg_88180F08(lbl_88D458F0, hash, &key, none);
}
