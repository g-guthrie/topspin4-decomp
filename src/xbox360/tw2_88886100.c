/* Twin of 0x888860A0 (ts4_registry_dispatch_888860A0 in src/xbox360/d2e_registry_dispatch_888860A0.c). */
typedef struct Ts4Registry {
    unsigned char reserved[0x24];
    void *fallback;
} Ts4Registry;

extern Ts4Registry *lbl_88D45B38;
extern void *ts4_find_range_owner_8860D360(Ts4Registry *registry, void *key);
extern void ts4_node_visit_8860DBC8(void *entry, void *key);

void ts4_tsu_cleanup_end(void *key)
{
    Ts4Registry *registry = lbl_88D45B38;
    void *entry;
    if (key == 0) {
        return;
    }
    entry = ts4_find_range_owner_8860D360(registry, key);
    if (entry != 0) {
        ts4_node_visit_8860DBC8(entry, key);
    } else {
        ts4_node_visit_8860DBC8(registry->fallback, key);
    }
}
