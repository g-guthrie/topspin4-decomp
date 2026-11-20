/* Swing_DLL.xex 0x88227978: Swing_DLL.xex 0x88227978: Appends a 0x24-byte item (growing via 88228C40 when full): zeroes its id, constructs its short vector (88260B38), resizes it to 8 and fills every slot with -1; returns the new item.
 * /Oc. Dinkumware resize template; the 16-byte allocator block sets the 0xA0 frame. */
typedef struct Alloc { int unused[4]; } Alloc;   /* 16-byte allocator/param block, passed uninitialised */
typedef struct ShortVec { short *first; short *last; short *end; } ShortVec;
typedef struct Item { int id; int pad4; ShortVec slots; char pad14[0x24 - 0x14]; } Item;   /* 0x24 */
typedef struct ItemVec { int pad0; Item *last; int pad8; Item *end; } ItemVec;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_vector_grow_append_88228C40(ItemVec *v, Item *where);
void fn_88260B38(ShortVec *v, const Alloc *al);
void fn_8825BC30(ShortVec *v, short *where, unsigned n, const short *val);
static __inline short *copy_shorts(short *first, short *last, short *dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (short *)fn_88562DC0(dest, first, n);
        return (short *)((char *)dest + n);
    }
}
static __inline unsigned shortvec_size(const ShortVec *v) { return v->last - v->first; }
static __inline void shortvec_resize(ShortVec *v, unsigned n, short val)
{
    unsigned size = shortvec_size(v);
    if (n < size)
        v->last = copy_shorts(v->last, v->last, v->first + n);
    else
        fn_8825BC30(v, v->last, n - size, &val);
}
Item *fn_88227978(ItemVec *v)
{
    Item *e;
    if (v->last == v->end)
        ts4_vector_grow_append_88228C40(v, v->last);
    e = v->last;
    if (e) {
        Alloc al;
        unsigned i, n;
        e->id = 0;
        fn_88260B38(&e->slots, &al);
        shortvec_resize(&e->slots, 8, 0);
        n = shortvec_size(&e->slots);
        for (i = 0; i != n; i++)
            e->slots.first[i] = -1;
    }
    v->last++;
    return v->last - 1;
}
