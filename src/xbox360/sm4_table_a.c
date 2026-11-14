/* SM4: pointer-array tables owned by an object: id lookup and per-element dispatch (MSVC 16.00 /O2). */
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif

struct Ts4Rec { unsigned id; };
struct Ts4Tab { char pad[0x30]; struct Ts4Rec **recs; int n; };

/* index of the record whose id equals key, or -1 */
INL int find_idx(struct Ts4Tab *t, unsigned key)
{
    int i;
    for (i = 0; i < t->n; i++) if (t->recs[i]->id == key) return i;
    return -1;
}

#define FIND_INDEX(NAME) \
    int NAME(struct Ts4Tab *t, unsigned key) { return find_idx(t, key); }
FIND_INDEX(ts4_find_record_index_884AAA28)
FIND_INDEX(ts4_find_record_index_884AC760)
FIND_INDEX(ts4_find_record_index_884B0490)

/* this points at owner + 0x20: look the id up in the owner's table and hand the index to the handler */
#define HANDLE_BY_ID(NAME, HANDLER) \
    extern void HANDLER(void *, int); \
    void NAME(char *self, unsigned key) \
    { \
        struct Ts4Tab *t = (struct Ts4Tab *)(self - 0x20); \
        int i = find_idx(t, key); \
        if (i >= 0) HANDLER(t, i); \
    }
HANDLE_BY_ID(ts4_handle_record_by_id_884AB7E0, fn_884AB5B0)
HANDLE_BY_ID(ts4_handle_record_by_id_884AD818, fn_884AD5D0)
HANDLE_BY_ID(ts4_handle_record_by_id_884B0F88, fn_884B0D58)

/* call the per-element handler for every element of the sub-table at +0x1c, passing owner - 8 */
struct Ts4Sub { char pad[0x6c]; void **arr; int cnt; };
struct Ts4Own { char pad[0x1c]; struct Ts4Sub *sub; };
#define FOR_EACH_ELEM(NAME, HANDLER) \
    extern void HANDLER(void *, void *); \
    void NAME(struct Ts4Own *o) \
    { \
        int i; \
        if (o->sub) { \
            for (i = 0; i < o->sub->cnt; i++) HANDLER((char *)o - 8, o->sub->arr[i]); \
        } \
    }
FOR_EACH_ELEM(ts4_for_each_element_884AB540, fn_884AB2F8)
FOR_EACH_ELEM(ts4_for_each_element_884AD560, fn_884ACC68)
FOR_EACH_ELEM(ts4_for_each_element_884ADC60, fn_884ADB38)
FOR_EACH_ELEM(ts4_for_each_element_884B0CE8, fn_884B0A98)
FOR_EACH_ELEM(ts4_for_each_element_884B1FC8, fn_884B1B48)

/* remove the first element equal to key from an array {ptr, count} by moving the last element into its slot */
typedef struct { unsigned *p; int n; } Ts4Arr;
INL int arr_find(Ts4Arr *a, unsigned key) { int i; int n = a->n; for (i = 0; i < n; i++) if (a->p[i] == key) return i; return -1; }
INL void arr_swap_remove(volatile Ts4Arr *a, int i) { int n = a->n - 1; unsigned *p = a->p; a->n = n; p[i] = p[n]; }
#define SWAP_REMOVE(NAME, OFF) \
    struct NAME##_owner { char pad[OFF]; Ts4Arr a; }; \
    void NAME(struct NAME##_owner *o, unsigned key) \
    { \
        Ts4Arr *a = &o->a; \
        int i = arr_find(a, key); \
        if (i >= 0) arr_swap_remove(a, i); \
    }
SWAP_REMOVE(ts4_remove_key_swap_last_884A2988, 0x78)
SWAP_REMOVE(ts4_remove_key_swap_last_884AEF48, 8)
SWAP_REMOVE(ts4_remove_key_swap_last_884B1CF0, 8)
