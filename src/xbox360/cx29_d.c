/* Swing_DLL.xex game core 0x8818C6C0-0x8819C000 (CW29): string-keyed hash table (case folded multiplicative hash). */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

#pragma pack(push, 1)
struct cx_hn { const char *key; u16 id; struct cx_hn *next; u32 hash; };
#pragma pack(pop)
struct cx_ht { u8 pad[0x14]; struct cx_hn **buckets; u32 count; u32 nbuckets; };

int ts4_if_fn_88567730(int c);
int fn_8856A3A0(const char *a, const char *b);

/* 0x8818EEA0: find the node for a key: hash the folded characters, report the bucket, hash and predecessor */
struct cx_hn *ts4_hash_find_8818EEA0(struct cx_ht *self, const char **keyp, u32 *bucket_out, u32 *hash_out, struct cx_hn **prev_out)
{
    const char *p = *keyp;
    u32 h = 0;
    int c = *p;
    u32 idx, nb;
    struct cx_hn *prev, *n;
    struct cx_hn **tab;
    while (c != 0) {
        h = ts4_if_fn_88567730(c) + h * 33;
        p++;
        c = *p;
    }
    nb = self->nbuckets;
    tab = self->buckets;
    idx = h % nb;
    *hash_out = h;
    *bucket_out = idx;
    if (tab == 0)
        return 0;
    *prev_out = 0;
    prev = 0;
    n = tab[idx];
    while (n != 0) {
        if (n->hash == *hash_out && fn_8856A3A0(n->key, *keyp) == 0) {
            *prev_out = prev;
            return n;
        }
        prev = n;
        n = n->next;
    }
    return 0;
}
