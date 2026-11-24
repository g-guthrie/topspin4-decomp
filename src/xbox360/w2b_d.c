#include "w2b_types.h"

/* Self-relative array header: offset of the first element from this header, element count. */
struct W2bRel { int rel; int count; };

/* ---- 0x88660F08 / 0x886614F8: find the element whose key matches ---- */
struct W2bKeyed { w2b_u32 pad; w2b_u32 key; };
struct W2bFindOut { char pad[8]; void *found; };

#define W2B_FIND(NAME, ADDR, HDR_OFF, KEY_OFF) \
struct NAME##Src { char pad[HDR_OFF]; struct W2bRel hdr; }; \
struct NAME##Elem { char pad[KEY_OFF]; w2b_u32 key; }; \
/* Swing_DLL.xex ADDR */ \
void ts4_##NAME(struct W2bFindOut *out, struct W2bKeyed *k, struct NAME##Src *src) \
{ \
    struct W2bRel *h = &src->hdr; \
    w2b_u32 key = k->key; \
    void *r = 0; \
    int i; \
    for (i = 0; i < h->count; i++) { \
        struct NAME##Elem *e = (struct NAME##Elem *)((char *)h + (i * 0x70 + h->rel)); \
        if (e->key == key) { \
            r = e; \
            break; \
        } \
    } \
    out->found = r; \
}
W2B_FIND(find_keyed_elem_88660F08, 0x88660F08, 0x114, 0x54)
W2B_FIND(find_keyed_elem_886614F8, 0x886614F8, 0xfc, 0x60)
