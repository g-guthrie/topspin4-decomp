/* 0x88711998: delete[] the counted array of 16-byte entries at +0 (release each +0xC buffer handle in reverse through the registry, then free the block from its count header), then dispatch the handles at +0xC and +0x18 */
/* Matched on /Oc (agAL). Plain route. agAH reverse destroy_n inline; the count header read through an int * one below the array, freed by ts4_registry_dispatch_888860A0. */
typedef struct Ts4Registry { char p[0x24]; void *fallback; } Ts4Registry;
extern Ts4Registry *lbl_88D45B38;
void *ts4_find_range_owner_8860D360(Ts4Registry *registry, void *key);
void ts4_node_visit_8860DBC8(void *entry, void *key);
void ts4_registry_dispatch_888860A0(void *p);
typedef struct Buf16 { unsigned int a, b, c; void *buf; } Buf16;
typedef struct Owner { Buf16 *bufs; unsigned int pad4, pad8; void *extra0; unsigned int pad10, pad14; void *extra1; } Owner;

static __inline void release(void *key)
{
    Ts4Registry *registry;
    void *entry;
    if (key == 0)
        return;
    registry = lbl_88D45B38;
    entry = ts4_find_range_owner_8860D360(registry, key);
    if (entry != 0)
        ts4_node_visit_8860DBC8(entry, key);
    else
        ts4_node_visit_8860DBC8(registry->fallback, key);
}

static __inline void bufs_destroy_n(Buf16 *first, int count)
{
    Buf16 *p = first + count;
    while (--count >= 0) {
        --p;
        release(p->buf);
    }
}

void ts4_release_buffer_array_88711998(Owner *o)
{
    Buf16 *b = o->bufs;
    if (b) {
        int *hdr = (int *)b - 1;
        bufs_destroy_n(b, *hdr);
        ts4_registry_dispatch_888860A0(hdr);
    }
    if (o->extra0) ts4_registry_dispatch_888860A0(o->extra0);
    if (o->extra1) ts4_registry_dispatch_888860A0(o->extra1);
}
