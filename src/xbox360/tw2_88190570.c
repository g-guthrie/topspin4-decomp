/* Twin of 0x881EF828 (ts4_hashtable_rehash_881EF828 in src/xbox360/cx25_core_d.c). Node chain at +0x14, val at +0x18. */
typedef unsigned int u32;
typedef unsigned char u8;
extern void fn_881992A8(u32, void *);
extern u32 fn_881F0388(void *ht, u32 n);
extern void fn_881C5AA8(void *ht, u32 n, u32 flag);
extern void *ts4_dispatch2_88199068(u32 z, u32 bytes, void *tag);
#ifdef _MSC_VER
extern void *memset(void *, int, unsigned int);
#else
#include <string.h>
#endif
typedef struct Cx25dTag { u32 a; u32 b; } Cx25dTag;
typedef struct Cx25dNodeR { u8 pad[0x14]; struct Cx25dNodeR *chain; u32 val; } Cx25dNodeR;
typedef struct Cx25dHTR {
    void *freelist; u32 p4; u32 p8; u32 pc; u32 p10;
    Cx25dNodeR **buckets; u32 count; u32 nbuckets;
    float f20; float f24; float f28; u32 highmark; u32 lowmark; u32 depth;
} Cx25dHTR;

void ts4_hashtable_rehash_88190570(Cx25dHTR *ht, u32 n)
{
    Cx25dNodeR **nb;
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
    nb = (Cx25dNodeR **)ts4_dispatch2_88199068(0, bytes, &tag);
    memset(nb, 0, n << 2);
    for (i = 0; i < ht->nbuckets; i++) {
        Cx25dNodeR *node = ht->buckets[i];
        while (node != 0) {
            Cx25dNodeR *nx = node->chain;
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
