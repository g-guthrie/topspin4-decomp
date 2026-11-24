/* Swing_DLL.xex 0x8895B200: runs 8895B160 on each non-null item, releases the service handle at +0x6C through vtable slot 0x68 when it is set, then empties the item vector.
 * /Oc. Handle copied by value into two function-scope locals (frame 0x90); the null test is a by-value inline returning unsigned char. */
typedef struct Item Item;
typedef struct ItemVec { Item **first; Item **last; Item **end; } ItemVec;
typedef struct Service Service;
typedef struct Handle { Service *svc; unsigned int id; unsigned int gen; } Handle;
typedef struct ServiceVtbl { void *slots[26]; void (*release)(Service *s, Handle *h); } ServiceVtbl;
struct Service { ServiceVtbl *vt; };
typedef struct Owner { unsigned char p0[0x60]; ItemVec items; Handle handle; } Owner;
void ts4_if_call_seq_u32_off8_8895B160(Item *it);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);

static __forceinline Item **copy_items(Item **first, Item **last, Item **dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (Item **)fn_88562DC0(dest, first, n);
        return (Item **)((char *)dest + n);
    }
}

static __inline unsigned char handle_is_null(Handle h)
{
    if (h.svc == 0 || h.id == 0xFFFFF) return 1;
    return 0;
}

void fn_8895B200(Owner *o)
{
    ItemVec *v = &o->items;
    Handle h;
    Item **it;
    Handle cur;
    for (it = v->first; it != o->items.last; it++)
        if (*it) ts4_if_call_seq_u32_off8_8895B160(*it);
    cur = o->handle;
    if (!handle_is_null(cur)) {
        h = o->handle;
        if (!handle_is_null(h)) h.svc->vt->release(h.svc, &h);
    }
    v->last = copy_items(v->last, v->last, v->first);
}
