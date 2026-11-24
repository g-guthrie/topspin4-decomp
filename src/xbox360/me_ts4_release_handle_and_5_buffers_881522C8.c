/* 0x881522C8: dispatch the registry handle at +0x2B0, then release and clear the buffer handle of each of the five 16-byte slots at +0x2BC */
/* Matched on /Oc (agAL). Plain route. Handles tested with cmpwi are int fields; the registry is read inside the release inline after the key test (no clrrwi copy), and the clear sits inside the if. */
typedef struct Ts4Registry { char p[0x24]; void *fallback; } Ts4Registry;
extern Ts4Registry *lbl_88D45B38;
void *ts4_find_range_owner_8860D360(Ts4Registry *registry, void *key);
void ts4_node_visit_8860DBC8(void *entry, void *key);
void ts4_registry_dispatch_888860A0(void *p);
typedef struct BufSlot { int buf; unsigned int a, b, c; } BufSlot;
typedef struct Holder { char pad[0x2b0]; int handle; char pad2b4[0x2bc - 0x2b4]; BufSlot slots[5]; } Holder;

static __inline void release(void *key)
{
    Ts4Registry *registry = lbl_88D45B38;
    void *entry = ts4_find_range_owner_8860D360(registry, key);
    if (entry != 0)
        ts4_node_visit_8860DBC8(entry, key);
    else
        ts4_node_visit_8860DBC8(registry->fallback, key);
}

void ts4_release_handle_and_5_buffers_881522C8(Holder *h)
{
    int i;
    if (h->handle) ts4_registry_dispatch_888860A0((void *)h->handle);
    for (i = 0; i < 5; i++) {
        BufSlot *s = &h->slots[i];
        if (s->buf) {
            release((void *)s->buf);
            s->buf = 0;
        }
    }
}
