/* Swing_DLL.xex 0x88959880: Swing_DLL.xex 0x88959880: Finalizes the object at +0x4C, resets the list at +0x64, finalizes and releases (88886100) every non-null item in the vector at +0x84, then empties the vector.
 * /Oc. Loop end re-read through o->items.last each iteration, begin via the v local. */
typedef struct Object { int f[3]; } Object;
typedef struct Item Item;
typedef struct ItemVec { Item **first; Item **last; Item **end; } ItemVec;
typedef struct Owner {
    char pad[0x4c];
    Object obj;         /* 0x4c */
    char pad58[0x64 - 0x58];
    char list64[0x84 - 0x64];
    ItemVec items;      /* 0x84 */
} Owner;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_object_finalize(Object *o);
void ts4_if_call_seq_u32_off4_88161D58(void *list);
void ts4_if_call_seq_ts4_object_finalize_8815E898(Item *p);
void ts4_tsu_cleanup_end(Item *p);
static __inline Item **copy_items(Item **first, Item **last, Item **dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (Item **)fn_88562DC0(dest, first, n);
        return (Item **)((char *)dest + n);
    }
}
void fn_88959880(Owner *o)
{
    ItemVec *v;
    Item **it;
    ts4_object_finalize(&o->obj);
    ts4_if_call_seq_u32_off4_88161D58(o->list64);
    v = &o->items;
    for (it = v->first; it != o->items.last; it++) {
        Item *p = *it;
        if (p) {
            ts4_if_call_seq_ts4_object_finalize_8815E898(p);
            ts4_tsu_cleanup_end(p);
        }
    }
    v->last = copy_items(v->last, v->last, v->first);
}
