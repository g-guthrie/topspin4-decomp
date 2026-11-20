/* CX25 part d: bucketed hash table rehash (three node layouts), plain route, no flags. */
typedef unsigned int u32;
typedef unsigned char u8;
extern void fn_881992A8(u32, void *);
extern u32 fn_881F0388(void *ht, u32 n);
extern void fn_881C5AA8(void *ht, u32 n, u32 flag);
extern void ts4_if_call_seq_u32_off14_881FBD30(void *ht, u32 n);
extern void *ts4_dispatch2_88199068(u32 z, u32 bytes, void *tag);
#ifdef _MSC_VER
extern void *memset(void *, int, unsigned int);
#else
#include <string.h>
#endif
typedef struct Cx25dTag { u32 a; u32 b; } Cx25dTag;

typedef struct Cx25dNodeA { u8 pad[8]; struct Cx25dNodeA *chain; u32 val; } Cx25dNodeA;
typedef struct Cx25dHTA {
    void *freelist; u32 p4; u32 p8; u32 pc; u32 p10;
    Cx25dNodeA **buckets; u32 count; u32 nbuckets;
    float f20; float f24; float f28; u32 highmark; u32 lowmark; u32 depth;
} Cx25dHTA;

/* 0x881EFE08: change the bucket count (0 = pick one from the element count) and relink every node; chain at +8 */
void ts4_hashtable_rehash_881EFE08(Cx25dHTA *ht, u32 n)
{
    Cx25dNodeA **nb;
    u32 i;
    Cx25dTag tag;
    float fn;
    u32 bytes;
    u32 low;
    if (n == 0) n = fn_881F0388(ht, ht->count);
    if (n == ht->nbuckets) return;
    if (ht->buckets == 0) {
        fn_881C5AA8(ht, n, 0);
        return;
    }
    bytes = n * 4;
    if (n > 0x3fffffffu) bytes = 0xffffffffu;
    tag.a = 1000;
    tag.b = 0;
    nb = (Cx25dNodeA **)ts4_dispatch2_88199068(0, bytes, &tag);
    memset(nb, 0, n << 2);
    for (i = 0; i < ht->nbuckets; i++) {
        Cx25dNodeA *node = ht->buckets[i];
        while (node != 0) {
            Cx25dNodeA *nx = node->chain;
            u32 idx = node->val % n;
            node->chain = nb[idx];
            nb[idx] = node;
            node = nx;
        }
    }
    if (ht->buckets != 0) fn_881992A8(0, ht->buckets);
    fn = (float)n;
    low = (u32)(ht->f24 * fn);
    ht->buckets = nb;
    ht->nbuckets = n;
    ht->highmark = (u32)(ht->f28 * fn);
    ht->lowmark = low;
    if (low < 0x11) ht->lowmark = 0;
}

typedef struct Cx25dNodeB { u8 pad[0x38]; struct Cx25dNodeB *chain; u32 val; } Cx25dNodeB;
typedef struct Cx25dHTB {
    void *freelist; u32 p4; u32 p8; u32 pc; u32 p10;
    Cx25dNodeB **buckets; u32 count; u32 nbuckets;
    float f20; float f24; float f28; u32 highmark; u32 lowmark; u32 depth;
} Cx25dHTB;

/* 0x881EF828: change the bucket count (0 = pick one from the element count) and relink every node; chain at +0x38 */
void ts4_hashtable_rehash_881EF828(Cx25dHTB *ht, u32 n)
{
    Cx25dNodeB **nb;
    u32 i;
    Cx25dTag tag;
    float fn;
    u32 bytes;
    u32 low;
    if (n == 0) n = fn_881F0388(ht, ht->count);
    if (n == ht->nbuckets) return;
    if (ht->buckets == 0) {
        fn_881C5AA8(ht, n, 0);
        return;
    }
    bytes = n * 4;
    if (n > 0x3fffffffu) bytes = 0xffffffffu;
    tag.a = 1000;
    tag.b = 0;
    nb = (Cx25dNodeB **)ts4_dispatch2_88199068(0, bytes, &tag);
    memset(nb, 0, n << 2);
    for (i = 0; i < ht->nbuckets; i++) {
        Cx25dNodeB *node = ht->buckets[i];
        while (node != 0) {
            Cx25dNodeB *nx = node->chain;
            u32 idx = node->val % n;
            node->chain = nb[idx];
            nb[idx] = node;
            node = nx;
        }
    }
    if (ht->buckets != 0) fn_881992A8(0, ht->buckets);
    fn = (float)n;
    low = (u32)(ht->f24 * fn);
    ht->buckets = nb;
    ht->nbuckets = n;
    ht->highmark = (u32)(ht->f28 * fn);
    ht->lowmark = low;
    if (low < 0x11) ht->lowmark = 0;
}

typedef struct Cx25dNodeC { u8 pad[0x2c]; struct Cx25dNodeC *chain; u32 val; } Cx25dNodeC;
typedef struct Cx25dHTC {
    void *freelist; u32 p4; u32 p8; u32 pc; u32 p10;
    Cx25dNodeC **buckets; u32 count; u32 nbuckets;
    float f20; float f24; float f28; u32 highmark; u32 lowmark; u32 depth;
} Cx25dHTC;

/* 0x881EFC90: change the bucket count (0 = pick one from the element count) and relink every node; chain at +0x2c */
void ts4_hashtable_rehash_881EFC90(Cx25dHTC *ht, u32 n)
{
    Cx25dNodeC **nb;
    u32 i;
    Cx25dTag tag;
    float fn;
    u32 bytes;
    u32 low;
    if (n == 0) n = fn_881F0388(ht, ht->count);
    if (n == ht->nbuckets) return;
    if (ht->buckets == 0) {
        fn_881C5AA8(ht, n, 0);
        return;
    }
    bytes = n * 4;
    if (n > 0x3fffffffu) bytes = 0xffffffffu;
    tag.a = 1000;
    tag.b = 0;
    nb = (Cx25dNodeC **)ts4_dispatch2_88199068(0, bytes, &tag);
    memset(nb, 0, n << 2);
    for (i = 0; i < ht->nbuckets; i++) {
        Cx25dNodeC *node = ht->buckets[i];
        while (node != 0) {
            Cx25dNodeC *nx = node->chain;
            u32 idx = node->val % n;
            node->chain = nb[idx];
            nb[idx] = node;
            node = nx;
        }
    }
    if (ht->buckets != 0) fn_881992A8(0, ht->buckets);
    fn = (float)n;
    low = (u32)(ht->f24 * fn);
    ht->buckets = nb;
    ht->nbuckets = n;
    ht->highmark = (u32)(ht->f28 * fn);
    ht->lowmark = low;
    if (low < 0x11) ht->lowmark = 0;
}

/* ---- same rehash for the table whose empty case goes through a different initialiser ---- */

/* 0x881F0008: change the bucket count (0 = pick one from the element count) and relink every node; chain at +8 */
void ts4_hashtable_rehash_881F0008(Cx25dHTA *ht, u32 n)
{
    Cx25dNodeA **nb;
    u32 i;
    Cx25dTag tag;
    float fn;
    u32 bytes;
    u32 low;
    if (n == 0) n = fn_881F0388(ht, ht->count);
    if (n == ht->nbuckets) return;
    if (ht->buckets == 0) {
        ts4_if_call_seq_u32_off14_881FBD30(ht, n);
        return;
    }
    bytes = n * 4;
    if (n > 0x3fffffffu) bytes = 0xffffffffu;
    tag.a = 1000;
    tag.b = 0;
    nb = (Cx25dNodeA **)ts4_dispatch2_88199068(0, bytes, &tag);
    memset(nb, 0, n << 2);
    for (i = 0; i < ht->nbuckets; i++) {
        Cx25dNodeA *node = ht->buckets[i];
        while (node != 0) {
            Cx25dNodeA *nx = node->chain;
            u32 idx = node->val % n;
            node->chain = nb[idx];
            nb[idx] = node;
            node = nx;
        }
    }
    if (ht->buckets != 0) fn_881992A8(0, ht->buckets);
    fn = (float)n;
    low = (u32)(ht->f24 * fn);
    ht->buckets = nb;
    ht->nbuckets = n;
    ht->highmark = (u32)(ht->f28 * fn);
    ht->lowmark = low;
    if (low < 0x11) ht->lowmark = 0;
}

