/* CW9 part b: bucketed hash table (0x881EEBB0..). Built with /Oc. */
typedef unsigned int u32;
#ifdef _MSC_VER
typedef unsigned int cw9_uptr;
#else
typedef unsigned long cw9_uptr;
#endif

extern void fn_881992A8(u32, void *);
extern void ts4_call_seq_u32_off4_881F0400(void *node);
extern u32 fn_881F0388(void *ht, u32 n);
extern void ts4_hashtable_rehash_881EFE08(void *ht, u32 n);
extern void fn_881C5AA8(void *ht, u32 n, u32 flag);
struct Cw9HNode;
extern struct Cw9HNode *fn_8818F1D8(void *ht);

struct Cw9Singleton;
typedef struct Cw9SingletonVt { void *s[4]; char *(*get_block)(struct Cw9Singleton *); } Cw9SingletonVt;
typedef struct Cw9Singleton { const Cw9SingletonVt *vt; } Cw9Singleton;
extern Cw9Singleton *lbl_88D3E418;
extern Cw9Singleton *ts4_if_get_u32_lbl_88D45B38_8819A938(void);

typedef struct Cw9HNode Cw9HNode;
struct Cw9HNode { void *link; char *data; Cw9HNode *chain; u32 val; };
typedef struct Cw9HT {
    void *freelist; u32 p4; u32 p8; u32 pc; u32 p10;
    Cw9HNode **buckets; u32 count; u32 nbuckets;
    float f20; float f24; float f28; u32 highmark; u32 lowmark; u32 depth;
} Cw9HT;

/* 0x881EEBB0: add a freshly allocated node to bucket idx, growing the table if over the high mark */
Cw9HNode *ts4_hashtable_insert_881EEBB0(Cw9HT *ht, u32 key, u32 idx, u32 val)
{
    Cw9HNode *node;
    if (ht->buckets == 0)
        fn_881C5AA8(ht, ht->nbuckets, 1);
    node = fn_8818F1D8(ht);
    if (node != 0) {
        Cw9Singleton *s;
        volatile Cw9HNode *vn = node;
        vn->link = (void *)(cw9_uptr)key;
        s = lbl_88D3E418;
        if (s == 0) s = ts4_if_get_u32_lbl_88D45B38_8819A938();
        vn->data = s->vt->get_block(s) + 0x10;
        vn->val = val;
    }
    ht->count++;
    node->chain = ht->buckets[idx];
    ht->buckets[idx] = node;
    if (ht->count > ht->highmark && ht->depth == 0)
        ts4_hashtable_rehash_881EFE08(ht, fn_881F0388(ht, ht->count));
    return node;
}

/* 0x881EEE60: run per-node teardown on every node of a bucketed table, free the bucket array */
void ts4_hashtable_clear_881EEE60(Cw9HT *ht)
{
    u32 i;
    ht->depth++;
    if (ht->buckets != 0) {
        for (i = 0; i < ht->nbuckets; i++) {
            Cw9HNode *n = ht->buckets[i];
            while (n != 0) {
                Cw9HNode *cur = n;
                n = n->chain;
                ts4_call_seq_u32_off4_881F0400(cur);
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
