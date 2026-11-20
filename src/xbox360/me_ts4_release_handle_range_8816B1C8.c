/* 0x8816B1C8: destroy a range of registry buffer handles [first, last) (range-owner release with the +0x24 fallback); returns the allocator argument */
/* Matched on /Oc (agAL). Plain route; agAH registry release inline. */
typedef struct Ts4Registry { char p[0x24]; void *fallback; } Ts4Registry;
extern Ts4Registry *lbl_88D45B38;
void *ts4_find_range_owner_8860D360(Ts4Registry *registry, void *key);
void ts4_node_visit_8860DBC8(void *entry, void *key);

static __inline void release(Ts4Registry *registry, void *key)
{
    void *entry;
    if (key == 0)
        return;
    entry = ts4_find_range_owner_8860D360(registry, key);
    if (entry != 0)
        ts4_node_visit_8860DBC8(entry, key);
    else
        ts4_node_visit_8860DBC8(registry->fallback, key);
}

void *ts4_release_handle_range_8816B1C8(void **first, void **last, void *al)
{
    for (; first != last; ++first)
        release(lbl_88D45B38, *first);
    return al;
}
