/* 0x882DDD58: counts the ~handle node list, clamps *count, and fills up to n 0x30-byte records via 882DD920. */
/* Matched on /O1 LTCG with fk2_o1_000.c as context (agT draft; agAC fixed the 0x8876086C relocation). */
typedef unsigned long ts4_word;
typedef struct Node { char pad[0x24]; struct Node *next; } Node;
ts4_word ts4_if_set_u32_off0_882DD920(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7);
int ts4_get_list_records_882DDD58(void *self, ts4_word handle, char *out, unsigned int *count)
{
    Node *node, *p;
    unsigned int n, k;
    int r;
    if (!out && !count) return (int)0x8876086C;
    node = (Node *)~handle;
    n = 0; k = 1;
    for (p = node; p; p = p->next) n++;
    if (count) {
        k = *count;
        if (k == 0) k = 1;
        if (k > n) k = n;
        *count = n;
    }
    if (!out) return 0;
    for (; node; node = node->next, out += 0x30, k--) {
        if (!k) break;
        r = (int)ts4_if_set_u32_off0_882DD920((ts4_word)node, (ts4_word)out, 0, 0, 0, 0, 0, 0);
        if (r < 0) return r;
    }
    return 0;
}
