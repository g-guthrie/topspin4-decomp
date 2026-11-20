/* 0x88657DA8: manager shutdown: frees every queued item (its queue flushed, then deleted; its buffer
 * released through the registry; the item freed), deletes the two owned objects, resets the embedded
 * object, clears the active flag and trims the list. */
typedef struct Ts4Registry { char p[0x24]; void *fallback; } Ts4Registry;
extern Ts4Registry *lbl_88D45B38;
void *ts4_find_range_owner_8860D360(Ts4Registry *registry, void *key);
void ts4_node_visit_8860DBC8(void *entry, void *key);
void ts4_tsu_cleanup_end(void *key);
void ts4_flush_queue_88655BC8(void *q);
void ts4_vec204_move_tail_881B9148(void *p);
typedef struct VObj { struct VObjVt *vt; } VObj;
typedef struct VObjVt { void (*destroy)(VObj *, int); } VObjVt;
typedef struct Embed { struct EmbedVt *vt; } Embed;
typedef struct EmbedVt { char p[0x14]; void (*reset)(Embed *); } EmbedVt;
typedef struct Item { char p[4]; void *buf; void *queue; } Item;
typedef struct Mgr {
    char p[8]; unsigned char active; char p1[0x10 - 9]; char list[0x1c - 0x10]; VObj *b;
    char p2[0x44 - 0x20]; Item **first; Item **last; char p3[4]; VObj *a; Embed embed;
} Mgr;
static __inline void release(void *key)
{
    Ts4Registry *registry = lbl_88D45B38;
    void *entry;
    if (key == 0)
        return;
    entry = ts4_find_range_owner_8860D360(registry, key);
    if (entry != 0)
        ts4_node_visit_8860DBC8(entry, key);
    else
        ts4_node_visit_8860DBC8(registry->fallback, key);
}
static __inline void free_queue(void *q)
{
    if (q) {
        ts4_flush_queue_88655BC8(q);
        ts4_tsu_cleanup_end(q);
    }
}
static __inline void destroy_items(Item **it, Item **end)
{
    for (; it != end; ++it) {
        Item *e = *it;
        if (e) {
            ts4_flush_queue_88655BC8(e->queue);
            free_queue(e->queue);
            release(e->buf);
            ts4_tsu_cleanup_end(e);
        }
    }
}
void ts4_mgr_shutdown_88657DA8(Mgr *o)
{
    destroy_items(o->first, o->last);
    if (o->a)
        o->a->vt->destroy(o->a, 1);
    o->a = 0;
    if (o->b)
        o->b->vt->destroy(o->b, 1);
    o->b = 0;
    o->embed.vt->reset(&o->embed);
    o->active = 0;
    ts4_vec204_move_tail_881B9148(o->list);
}
