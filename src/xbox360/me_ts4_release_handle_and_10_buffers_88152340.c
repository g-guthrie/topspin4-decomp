/* 0x88152340: dispatch the registry handle at +0x558, then release and clear the buffer handle of each of the ten 16-byte slots at +0x564 */
/* Matched on /Oc (agAL). Plain route; same source shape as 881522C8. */
typedef struct Ts4Registry { char p[0x24]; void *fallback; } Ts4Registry;
extern Ts4Registry *lbl_88D45B38;
void *ts4_find_range_owner_8860D360(Ts4Registry *registry, void *key);
void ts4_node_visit_8860DBC8(void *entry, void *key);
void ts4_registry_dispatch_888860A0(void *p);
typedef struct BufSlot { int buf; unsigned int a, b, c; } BufSlot;
typedef struct Holder { char pad[0x558]; int handle; char pad55c[0x564 - 0x55c]; BufSlot slots[10]; } Holder;

static __inline void release(void *key)
{
    Ts4Registry *registry = lbl_88D45B38;
    void *entry = ts4_find_range_owner_8860D360(registry, key);
    if (entry != 0)
        ts4_node_visit_8860DBC8(entry, key);
    else
        ts4_node_visit_8860DBC8(registry->fallback, key);
}

void ts4_release_handle_and_10_buffers_88152340(Holder *h)
{
    int i;
    if (h->handle) ts4_registry_dispatch_888860A0((void *)h->handle);
    for (i = 0; i < 10; i++) {
        BufSlot *s = &h->slots[i];
        if (s->buf) {
            release((void *)s->buf);
            s->buf = 0;
        }
    }
}
