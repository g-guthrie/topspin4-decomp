/* 0x88995CB8: release the buffers of the six 12-byte slots at +0x28 through the range-owner registry (lbl_88D45B38, fallback +0x24) */
/* Matched on /Oc (agAL). Plain route. agAH registry release inline taking the registry as a parameter (clrrwi copy); a plain index loop gives the subic./bne countdown. */
typedef struct Ts4Registry { char p[0x24]; void *fallback; } Ts4Registry;
extern Ts4Registry *lbl_88D45B38;
void *ts4_find_range_owner_8860D360(Ts4Registry *registry, void *key);
void ts4_node_visit_8860DBC8(void *entry, void *key);
typedef struct Slot { void *buf; unsigned int a; unsigned int b; } Slot;
typedef struct Owner { char pad[0x28]; Slot slots[6]; } Owner;

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

void ts4_release_six_slots_88995CB8(Owner *o)
{
    int i;
    for (i = 0; i < 6; i++)
        release(lbl_88D45B38, o->slots[i].buf);
}
