/*
 * 0x88890E30: slot 2 of vtable 0x880DCE70 (pres). Frees `n` heap blocks held in a pointer array and clears
 * each slot. The free is the engine heap's inlined release: find the sub-heap that owns the block
 * (8860D360) and release it there, else release it on the heap's fallback allocator (+0x24).
 * LTCG route; reading the heap global into a local and again as the find argument gives the target's
 * `clrrwi r3` copy (rule CL1).
 */
typedef struct Ts4WorldHeap {
    char pad_00[0x24];
    void *fallback;                              /* +0x24 V 88890E30 */
} Ts4WorldHeap;

extern Ts4WorldHeap *lbl_88D45B38;
extern void *ts4_find_range_owner_8860D360(void *heap, void *p);
extern void ts4_node_visit_8860DBC8(void *owner, void *p);

static void world_heap_free(void *p)
{
    Ts4WorldHeap *h = lbl_88D45B38;
    if (p) {
        void *r = ts4_find_range_owner_8860D360(lbl_88D45B38, p);
        if (r)
            ts4_node_visit_8860DBC8(r, p);
        else
            ts4_node_visit_8860DBC8(h->fallback, p);
    }
}

void ts4_pres_free_block_array_88890E30(void *self, void **blocks, int n)
{
    int i;
    (void)self;
    for (i = 0; i < n; i++) {
        world_heap_free(blocks[i]);
        blocks[i] = 0;
    }
}
