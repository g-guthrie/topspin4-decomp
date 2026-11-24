/* Twin of 0x8841EAE0 (ts4_count_list_nodes_8841EAE0 in src/xbox360/d1_band2_misc_helpers_88413920.c). */
typedef unsigned int ts4_u32;
typedef struct Ts4ListNode16 {
    ts4_u32 pad[4];
    struct Ts4ListNode16 *next;
} Ts4ListNode16;

int ts4_count_list_nodes_885ED208(ts4_u32 a0, const Ts4ListNode16 *node)
{
    const Ts4ListNode16 *p;
    int count;
    (void)a0;
    count = -1;
    if (node != 0) {
        p = node;
        do {
            p = p->next;
            count++;
        } while (p != 0);
    }
    return count;
}
