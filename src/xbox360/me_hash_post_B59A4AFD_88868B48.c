/* 88868B48: looks up hash 0xB59A4AFD in the global hash table with key {engine+0x27C, value, 1} and a null handle; result unused. */
typedef unsigned int u32;
typedef struct Ts4Handle12 { u32 a, b, c; } Ts4Handle12;
typedef struct Ts4HashTable Ts4HashTable;
typedef struct Ts4Engine { char pad[0x27c]; u32 f27c; } Ts4Engine;
typedef struct Ts4HashKey3 { u32 a, b, c; } Ts4HashKey3;
extern Ts4HashTable *lbl_88D458F0;
extern Ts4Engine *lbl_88D45B1C;
extern void *ts4_hash_find_arg_88180F08(Ts4HashTable *table, u32 hash, Ts4HashKey3 *key, Ts4Handle12 h);
void ts4_hash_post_B59A4AFD_88868B48(u32 v)
{
    Ts4HashKey3 k;
    Ts4Handle12 n;
    k.b = v;
    k.c = 1;
    n.a = 0;
    n.b = 0xFFFFF;
    n.c = 0;
    k.a = lbl_88D45B1C->f27c;
    ts4_hash_find_arg_88180F08(lbl_88D458F0, 0xB59A4AFDu, &k, n);
}
