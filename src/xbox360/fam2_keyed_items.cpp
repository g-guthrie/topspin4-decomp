/* Family FAM2: keyed-item pointer-vector thunks (Swing_DLL.xex).
   Items are 8-byte objects (vtable, key) allocated with the shared allocator; the vector holds item pointers.
   ADD_UNIQUE: scan [begin,end) for an item whose key equals *key; if none, allocate one and append it
   (fn_881898E8, push_back-like). ADD_OR_REMOVE: the same when *mode_flag == 1, otherwise remove the key with
   ts4_vec_remove_key_881507F0. Same shapes as fa_keyed_item_list_add_unique.cpp / fa_keyed_item_add_if_mode.cpp;
   instances differ only in the item vtable. */
extern "C" {
extern void *lbl_88D45B38; /* shared allocator heap */
void *fn_88613268(void *heap, int size, int align, int flags, int tag);
void fn_881898E8(void *vector, void *element_ptr);
void ts4_vec_remove_key_881507F0(void *vector, unsigned key);
extern int lbl_880EFF20; /* item vtable */
extern int lbl_880EFF14; /* item vtable */
extern int lbl_880EFEFC; /* item vtable */
extern int lbl_880EFEF0; /* item vtable */
extern int lbl_880EFEE4; /* item vtable */
extern int lbl_880EFED8; /* item vtable */
extern int lbl_880EFECC; /* item vtable */
extern int lbl_880EFEC0; /* item vtable */
extern int lbl_880D2EF0; /* item vtable */
extern int lbl_880D2EE4; /* item vtable */
extern int lbl_880D2ED8; /* item vtable */
extern int lbl_880D2564; /* item vtable */
extern int lbl_880D2558; /* item vtable */
extern int lbl_880D254C; /* item vtable */
extern int lbl_880D2540; /* item vtable */
extern int lbl_880D2534; /* item vtable */
extern int lbl_880D2528; /* item vtable */
extern int lbl_880DCA9C; /* item vtable */
extern int lbl_880D7574; /* item vtable */
extern int lbl_880D741C; /* item vtable */
extern int lbl_880D73E4; /* item vtable */
extern int lbl_880D73A0; /* item vtable */
extern int lbl_880D7330; /* item vtable */
extern int lbl_880EFF08; /* item vtable */
extern int lbl_880EFEB4; /* item vtable */
extern int lbl_880D251C; /* item vtable */
extern int lbl_880C141C; /* item vtable */
extern int lbl_880C1410; /* item vtable */
extern int lbl_880D75B8; /* item vtable */
extern int lbl_880D726C; /* item vtable */
extern int lbl_880D6E60; /* item vtable */
}

struct ts4_keyed_item;
struct ts4_item_vector { ts4_keyed_item **begin; ts4_keyed_item **end; };

inline void *operator new(unsigned, void *heap, int size, int align, int flags, int tag)
{ return fn_88613268(heap, size, align, flags, tag); }

#define TS4_KEYED_ITEM_ADD_UNIQUE(A, VTBL) \
struct itemu_##A { void *vtbl; unsigned key; \
    itemu_##A(unsigned k) { key = k; vtbl = &VTBL; } }; \
extern "C" void ts4_keyed_item_add_unique_##A(ts4_item_vector *vec, unsigned *key) \
{ \
    itemu_##A **end = (itemu_##A **)vec->end; \
    itemu_##A **it = (itemu_##A **)vec->begin; \
    unsigned k = *key; \
    for (; it != end; it++) \
        if ((*it)->key == k) return; \
    itemu_##A *tmp = new(lbl_88D45B38, 8, 4, 0, 2) itemu_##A(k); \
    itemu_##A *item = tmp; \
    fn_881898E8(vec, &item); \
}

#define TS4_KEYED_ITEM_ADD_OR_REMOVE(A, VTBL) \
struct item_##A { void *vtbl; unsigned key; \
    item_##A(unsigned k) { key = k; vtbl = &VTBL; } }; \
static __forceinline void push_##A(ts4_item_vector *vec, item_##A *item) \
{ fn_881898E8(vec, &item); } \
extern "C" void ts4_keyed_item_add_or_remove_##A(ts4_item_vector *vec, unsigned *key, unsigned char *mode_flag) \
{ \
    if (*mode_flag == 1) { \
        item_##A **end = (item_##A **)vec->end; \
        item_##A **it = (item_##A **)vec->begin; \
        unsigned k = *key; \
        for (; it != end; it++) \
            if ((*it)->key == k) return; \
        item_##A *tmp = new(lbl_88D45B38, 8, 4, 0, 2) item_##A(k); \
        push_##A(vec, tmp); \
    } else \
        ts4_vec_remove_key_881507F0(vec, *key); \
}

/* Swing_DLL.xex addresses */
TS4_KEYED_ITEM_ADD_UNIQUE(88770018, lbl_880EFF08)
TS4_KEYED_ITEM_ADD_UNIQUE(887712C8, lbl_880EFEB4)
TS4_KEYED_ITEM_ADD_UNIQUE(889A7C88, lbl_880D251C)
TS4_KEYED_ITEM_ADD_UNIQUE(889BCC28, lbl_880C141C)
TS4_KEYED_ITEM_ADD_UNIQUE(889BCCD8, lbl_880C1410)
TS4_KEYED_ITEM_ADD_UNIQUE(889C7208, lbl_880D75B8)
TS4_KEYED_ITEM_ADD_UNIQUE(889C7EF8, lbl_880D726C)
TS4_KEYED_ITEM_ADD_UNIQUE(889C93B8, lbl_880D6E60)
TS4_KEYED_ITEM_ADD_OR_REMOVE(8876FD58, lbl_880EFF20)
TS4_KEYED_ITEM_ADD_OR_REMOVE(8876FE38, lbl_880EFF14)
TS4_KEYED_ITEM_ADD_OR_REMOVE(887700C8, lbl_880EFEFC)
TS4_KEYED_ITEM_ADD_OR_REMOVE(887701A8, lbl_880EFEF0)
TS4_KEYED_ITEM_ADD_OR_REMOVE(88770750, lbl_880EFEE4)
TS4_KEYED_ITEM_ADD_OR_REMOVE(88770AB0, lbl_880EFED8)
TS4_KEYED_ITEM_ADD_OR_REMOVE(88770B90, lbl_880EFECC)
TS4_KEYED_ITEM_ADD_OR_REMOVE(88770D50, lbl_880EFEC0)
TS4_KEYED_ITEM_ADD_OR_REMOVE(889998A8, lbl_880D2EF0)
TS4_KEYED_ITEM_ADD_OR_REMOVE(88999C30, lbl_880D2EE4)
TS4_KEYED_ITEM_ADD_OR_REMOVE(88999FF8, lbl_880D2ED8)
TS4_KEYED_ITEM_ADD_OR_REMOVE(889A2818, lbl_880D2564)
TS4_KEYED_ITEM_ADD_OR_REMOVE(889A3F48, lbl_880D2558)
TS4_KEYED_ITEM_ADD_OR_REMOVE(889A6B00, lbl_880D254C)
TS4_KEYED_ITEM_ADD_OR_REMOVE(889A70A0, lbl_880D2540)
TS4_KEYED_ITEM_ADD_OR_REMOVE(889A7A20, lbl_880D2534)
TS4_KEYED_ITEM_ADD_OR_REMOVE(889A7B00, lbl_880D2528)
TS4_KEYED_ITEM_ADD_OR_REMOVE(889C1788, lbl_880DCA9C)
TS4_KEYED_ITEM_ADD_OR_REMOVE(889C30B8, lbl_880D7574)
TS4_KEYED_ITEM_ADD_OR_REMOVE(889C5468, lbl_880D741C)
TS4_KEYED_ITEM_ADD_OR_REMOVE(889C5818, lbl_880D73E4)
TS4_KEYED_ITEM_ADD_OR_REMOVE(889C5BC0, lbl_880D73A0)
TS4_KEYED_ITEM_ADD_OR_REMOVE(889C5F18, lbl_880D7330)
