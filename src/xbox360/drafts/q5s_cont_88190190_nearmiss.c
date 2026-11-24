/* nearmiss: 15 off (LTCG, no /Oc); blocker: MSVC schedules bucket_count before node->hash, keeps idx live in r9
 * and moves the head-store arm out of line after the tail call. perm_auto (84 candidates; a later hu_s5 run tried 389, best 15) cannot pass --include,
 * so it scores against a different baseline (27): retry once perm_auto supports --include.
 * Check: python3 tools/fn_check_ltcg.py <this> ts4_hash_unlink_88190190=0x88190190
 *   --include ts4_if_call_seq_fn_88190770_881906E8 --context 'flags(/Ob1):src/xbox360/fk2_000.c'
 *   --context src/xbox360/pp1_pool_primer.c */
#include "../include/ts4/ts4.h"

void ts4_if_call_seq_fn_88190770_881906E8(Ts4HashTable *t, Ts4HashNode *node);

void ts4_hash_unlink_88190190(Ts4HashTable *t, Ts4HashNode *node)
{
    unsigned int idx = node->hash % t->bucket_count;
    if (node != t->buckets[idx]) {
        Ts4HashNode *prev = t->buckets[idx];
        Ts4HashNode *cur;
        while ((cur = prev->next) != node)
            prev = cur;
        prev->next = node->next;
    } else {
        t->buckets[idx] = node->next;
    }
    ts4_if_call_seq_fn_88190770_881906E8(t, node);
}
