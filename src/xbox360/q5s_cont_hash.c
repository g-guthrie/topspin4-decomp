/* q5s_cont: chained hash table iterator (LTCG route, no /Oc: the divwu by bucket_count keeps a twllei trap).
 * Types: Ts4HashTable / Ts4HashNode / Ts4HashIter in include/ts4/containers.h. */
#include "include/ts4/ts4.h"

/* ++iterator: next node in the chain, else the first non-empty later bucket (NULL at the end). */
void ts4_hash_iter_next_8818FF70(Ts4HashIter *it)
{
    Ts4HashNode *n = it->node;
    Ts4HashTable *t = it->table;
    Ts4HashNode *r;
    unsigned int i;
    if (n->next != 0) {
        it->node = n->next;
        return;
    }
    r = 0;
    i = n->hash % t->bucket_count + 1;
    do {
        if (i >= t->bucket_count)
            break;
        if (t->buckets[i] != 0)
            r = t->buckets[i];
        i++;
    } while (r == 0);
    it->node = r;
}
