/* 0x8893B7E8: Reads the type id of src (fn_88939288 with key lbl_88C6B4AC). If the registry has a factory for it, builds the object and clears its pending byte (+0x41d) unless keep_pending is set. Returns the object or 0. */
/* Matched on /Oc (agAH). The entry pointer must be assigned inside the condition; an indexed reg->entries[type] read puts the slwi in another register. */
typedef struct Built { char p0[0x41d]; unsigned char pending; } Built;
typedef Built *(*Factory)(void *src);
typedef struct FactoryEntry { Factory create; int a; int b; int c; } FactoryEntry;
typedef struct Registry { int p0; FactoryEntry *entries; unsigned int count; } Registry;
extern unsigned int lbl_88C6B4AC;
extern void fn_88939288(void *src, unsigned int *type, unsigned int key);
Built *fn_8893B7E8(Registry *reg, void *src, unsigned char keep_pending)
{
    unsigned int type;
    FactoryEntry *e;
    fn_88939288(src, &type, lbl_88C6B4AC);
    if (type < reg->count && (e = &reg->entries[type])->create != 0) {
        Built *b = e->create(src);
        if (!keep_pending)
            b->pending = 0;
        return b;
    }
    return 0;
}
