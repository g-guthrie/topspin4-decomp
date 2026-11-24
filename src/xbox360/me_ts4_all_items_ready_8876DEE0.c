/* 0x8876DEE0: 1 unless some non-null item of the group pointer vector (+8) has its ready byte (+0x6A) clear */
/* Matched on /Oc (agAL). Plain route. The element is read through an inline slot accessor at each use (*vslot(v, i)), which gives the target clrrwi copies of first and of the element. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Item { u8 pad[0x6a]; u8 ready; } Item;
typedef struct PtrVec { Item **first; Item **last; } PtrVec;
typedef struct Group { u8 pad[8]; PtrVec items; } Group;

static u32 vsize(PtrVec *v) { return v->last - v->first; }
static Item **vslot(PtrVec *v, u32 i) { return &v->first[i]; }

u8 ts4_all_items_ready_8876DEE0(Group *g)
{
    u32 i = 0;
    u32 n = vsize(&g->items);
    for (; i < n; i++) {
        if (*vslot(&g->items, i) && !(*vslot(&g->items, i))->ready)
            return 0;
    }
    return 1;
}
