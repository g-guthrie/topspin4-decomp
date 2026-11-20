/* 0x88617608: add an item to the owned u32 vector unless the contains vcall (slot 14) already finds its key; returns 1 when added */
/* Matched on /Oc (agAL). Plain route; a result local set in the added branch keeps the 0 in r29. */
typedef unsigned int u32;
typedef struct Item { u32 kind; u32 key; } Item;
typedef struct Reg Reg;
typedef struct RegVt { void *s[14]; unsigned char (*contains)(Reg *r, u32 *key); } RegVt;
typedef struct VecU32 { u32 *begin; u32 *end; u32 *capacity; } VecU32;
struct Reg { const RegVt *vt; u32 pad[0x1c]; VecU32 vec; };
extern void ts4_vector_push_back_u32_8817E508(Reg *self, u32 value);

unsigned char ts4_add_if_absent_88617608(Reg *r, Item *it)
{
    unsigned char result = 0;
    if (!r->vt->contains(r, &it->key)) {
        ts4_vector_push_back_u32_8817E508(r, (u32)it);
        result = 1;
    }
    return result;
}
