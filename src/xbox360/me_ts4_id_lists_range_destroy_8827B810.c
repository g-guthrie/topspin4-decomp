/* Swing_DLL.xex 0x8827B810: destroy a range of 28-byte records {id; vector<unsigned int> a; vector<unsigned int> b}: zero id, clear both vectors (memmove erase), free b then a.
 * /Oc. The clear inline reads v->last before v->first (load order of the second clear). */
typedef struct Vec { unsigned int *first; unsigned int *last; unsigned int *end; } Vec;
typedef struct IdLists { unsigned int id; Vec a; Vec b; } IdLists;
void ts4_destroy_owned_object(void *obj);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);

static __inline unsigned int *u32_copy(const unsigned int *first, const unsigned int *last, unsigned int *dest)
{
    unsigned int bytes;
    if (last == first) return dest;
    bytes = (const char *)last - (const char *)first;
    return (unsigned int *)((char *)fn_88562DC0(dest, first, bytes) + bytes);
}

static __inline void u32_vec_clear(Vec *v)
{
    unsigned int *last = v->last;
    unsigned int *first = v->first;
    v->last = u32_copy(last, v->last, first);
}

static __inline void u32_vec_tidy(Vec *v)
{
    if (v->first) ts4_destroy_owned_object(v->first);
}

static __inline void id_lists_destroy(IdLists *p)
{
    p->id = 0;
    u32_vec_clear(&p->a);
    u32_vec_clear(&p->b);
    u32_vec_tidy(&p->b);
    u32_vec_tidy(&p->a);
}

void fn_8827B810(IdLists *first, IdLists *last)
{
    for (; first != last; ++first)
        id_lists_destroy(first);
}
