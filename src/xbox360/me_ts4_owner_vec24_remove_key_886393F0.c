/* Swing_DLL.xex 0x886393F0: erase first 24-byte element with matching key from the vector at +0x78 */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b135. */
typedef unsigned int u32;
typedef struct Elem { void *owned; u32 pad[4]; u32 key; } Elem;
typedef struct Vec { Elem *first; Elem *last; } Vec;
typedef struct Owner { char pad[0x78]; Vec vec; } Owner;
extern Elem *fn_8827C3C0(Elem *first, Elem *last, Elem *dest);
extern void ts4_destroy_owned_object(void *obj);

static __forceinline void vec_erase(Vec *v, Elem *where)
{
    if (where + 1 != v->last)
        fn_8827C3C0(where + 1, v->last, where);
    v->last--;
    ts4_destroy_owned_object(v->last->owned);
}

/* Erases the first 24-byte element whose key matches from the vector at +0x78. */
void fn_886393F0(Owner *o, u32 key)
{
    Vec *v = &o->vec;
    Elem *last = o->vec.last;
    Elem *p = o->vec.first;
    for (; p != last; p++) {
        if (p->key == key) {
            vec_erase(v, p);
            return;
        }
    }
}
