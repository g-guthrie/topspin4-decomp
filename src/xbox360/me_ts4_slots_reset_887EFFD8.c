/* Swing_DLL.xex 0x887EFFD8: Swing_DLL.xex 0x887EFFD8: Empties the byte vectors at +0x90/+0x9C, resets every 0x1C-byte slot of the self-relative table at +0x68 (id = -1, owner = 0), deletes and clears the cached object at +0x6C.
 * /Oc. Hoisted unsigned count with i != n; slot address via an inline (table + offset + i*0x1C). */
typedef struct Obj Obj;
typedef struct ObjVtbl { void (*destroy)(Obj *self, int flags); } ObjVtbl;
struct Obj { const ObjVtbl *vt; };
typedef struct ByteVec { char *first; char *last; char *end; } ByteVec;
typedef struct Slot { int a; int owner; char pad8[0x14 - 8]; int id; char pad18[4]; } Slot;   /* 0x1c */
typedef struct SlotTable { int offset; unsigned count; } SlotTable;   /* slots at (char *)table + offset */
typedef struct Owner {
    char pad[0x68];
    SlotTable *table;       /* 0x68 */
    Obj *cache;             /* 0x6c */
    char pad70[0x90 - 0x70];
    ByteVec a;              /* 0x90 */
    ByteVec b;              /* 0x9c */
} Owner;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
static __forceinline char *copy_bytes(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}
static __inline void vec_clear(ByteVec *v) { v->last = copy_bytes(v->last, v->last, v->first); }
static __inline Slot *table_slot(SlotTable *t, unsigned i) { return (Slot *)((char *)t + t->offset + i * sizeof(Slot)); }
void fn_887EFFD8(Owner *o)
{
    unsigned i, n;
    vec_clear(&o->a);
    vec_clear(&o->b);
    n = o->table->count;
    for (i = 0; i != n; i++) {
        Slot *s = table_slot(o->table, i);
        s->id = -1;
        s->owner = 0;
    }
    if (o->cache)
        o->cache->vt->destroy(o->cache, 1);
    o->cache = 0;
}
