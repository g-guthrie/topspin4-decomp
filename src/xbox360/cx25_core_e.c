/* CX25 part e: bucketed hash table clear (per-node teardown through the node helper), plain route, no flags. */
typedef unsigned int u32;

extern void fn_881992A8(u32, void *);
extern void ts4_if_call_seq_u32_off4_881FBE68(void *node);
extern u32 fn_881F0388(void *ht, u32 n);
extern void ts4_hashtable_rehash_881EFE08(void *ht, u32 n);
extern void fn_881C5AA8(void *ht, u32 n, u32 flag);

typedef struct Cx25eNode Cx25eNode;
struct Cx25eNode { void *link; char *data; Cx25eNode *chain; u32 val; };
typedef struct Cx25eHT {
    void *freelist; u32 p4; u32 p8; u32 pc; u32 p10;
    Cx25eNode **buckets; u32 count; u32 nbuckets;
    float f20; float f24; float f28; u32 highmark; u32 lowmark; u32 depth;
} Cx25eHT;

/* 0x881FB940: run the per-node teardown on every node of a bucketed table, release the bucket array */
void ts4_hashtable_clear_881FB940(Cx25eHT *ht)
{
    u32 i;
    ht->depth++;
    if (ht->buckets != 0) {
        for (i = 0; i < ht->nbuckets; i++) {
            Cx25eNode *n = ht->buckets[i];
            while (n != 0) {
                Cx25eNode *cur = n;
                n = n->chain;
                ts4_if_call_seq_u32_off4_881FBE68(cur);
                cur->link = ht->freelist;
                ht->freelist = cur;
                ht->count--;
                if (ht->count < ht->lowmark && ht->depth == 0)
                    ts4_hashtable_rehash_881EFE08(ht, fn_881F0388(ht, ht->count));
            }
        }
    }
    if (ht->buckets != 0) fn_881992A8(0, ht->buckets);
    ht->buckets = 0;
    ht->count = 0;
    if (ht->depth == 0) fn_881C5AA8(ht, fn_881F0388(ht, 0), 0);
    ht->depth--;
}
