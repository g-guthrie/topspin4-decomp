/* Swing_DLL.xex 0x8825DE40: Swing_DLL.xex 0x8825DE40: Deletes the counted array at +0x1C40 (0x28-byte elements, count at [-1]): destroys the elements back to front (clear both byte vectors, free +0x1C then +0x10), frees the block and zeroes the pointer and count.
 * /Oc. Hand-written vector delete[]; the array field is an int (cmpwi). */
typedef struct ByteVec { char *first; char *last; char *end; } ByteVec;
typedef struct Elem { char pad[0x10]; ByteVec a; ByteVec b; } Elem;
typedef struct Owner { char pad[0x1c40]; int elems; int count; } Owner;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_destroy_owned_object(void *obj);
void ts4_registry_dispatch_888860A0(void *obj);
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
static __inline void elem_destroy(Elem *e)
{
    vec_clear(&e->a);
    vec_clear(&e->b);
    if (e->b.first) ts4_destroy_owned_object(e->b.first);
    if (e->a.first) ts4_destroy_owned_object(e->a.first);
}
void fn_8825DE40(Owner *o)
{
    if (o->elems) {
        Elem *arr = (Elem *)o->elems;
        int *hdr = (int *)arr - 1;
        int i = *hdr;
        Elem *e = arr + i;
        while (--i >= 0) {
            e--;
            elem_destroy(e);
        }
        ts4_registry_dispatch_888860A0(hdr);
        o->elems = 0;
        o->count = 0;
    }
}
