/* Swing_DLL.xex 0x88880240: push_back on the vector<72-byte> at +0x14 */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b133. */
typedef unsigned char u8;
typedef unsigned int u32;
extern void ts4_vector_grow_append_881A6A78(void *v, void *where, const void *item);
extern void fn_881A7188(void *dst, const void *src);

#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
typedef struct Elem72 { u8 bytes[72]; } Elem72;
typedef struct Vec72 { u32 pad; Elem72 *end; Elem72 *capacity; } Vec72;
typedef struct Owner { char pad[0x14]; Vec72 vec; } Owner;

/* push_back on a vector<72-byte> (copy-constructed in place, generic insert when full). */
INL void vec72_push_back(Vec72 *v, const Elem72 *item)
{
    if (v->end != v->capacity) {
        if (v->end) {
            fn_881A7188(v->end, item);
        }
        v->end++;
    } else {
        ts4_vector_grow_append_881A6A78(v, v->end, item);
    }
}

/* Appends item to the vector<72-byte> at +0x14. */
void fn_88880240(Owner *o, const Elem72 *item)
{
    vec72_push_back(&o->vec, item);
}
