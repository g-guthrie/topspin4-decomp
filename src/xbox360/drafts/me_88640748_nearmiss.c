/* NEAR MISS 0x88640748: 16 off, store/constant scheduling of the field initialisation; source orders tried
 * (natural, target emission order, 45 random permutations) all leave ~16. */
/* 0x88640748 (hand match): creates the global resource manager (0x38 bytes from the main heap) with its
 * default limits and tuning values; the global is null when the allocation fails. */
typedef struct Manager {
    void *head; void *tail; int capacity; int grow; int count; int used; int pending; int buckets;
    float scale_a; float scale_b; float scale_c; int max_entries; int flags; int reserved;
} Manager;
extern void *lbl_88D45B38;
extern Manager *lbl_88D45290;
extern float g_ts4_script_constants[];
void *ts4_node_dispatch_with_target_88613268(void *heap, int size, int align, int flags, int tag);
void ts4_create_resource_manager_88640748(void)
{
    Manager *m = (Manager *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x38, 4, 0, 2);
    if (m != 0) {
        lbl_88D45290 = m;
    m->buckets = 0x11;
    m->head = 0;
    m->tail = 0;
    m->count = 0;
    m->used = 0;
    m->pending = 0;
    m->scale_a = g_ts4_script_constants[168];
    m->reserved = 0;
    m->scale_b = g_ts4_script_constants[167];
    m->max_entries = 0x26;
    m->scale_c = g_ts4_script_constants[509];
    m->flags = 0;
    m->grow = 10;
    m->capacity = 0x10;
    } else {
        lbl_88D45290 = 0;
    }
}
