/* Swing_DLL.xex 0x88540460: sort predicate: stage order of the current track stage, ties broken by track address (result through a hidden pointer)
 * order read through an inline taking the owner, so each comparison reloads it */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Stage { u8 pad[0xC0]; u32 order; } Stage;
typedef struct Sortable { u8 pad[0x28]; struct TrackHdr *track; } Sortable;
typedef struct TrackHdr { u32 pad0; Stage *stages[5]; u8 pad18[2]; u8 current; /* +0x1A */ } TrackHdr;

static __inline u32 order_of(Sortable *s)
{
    TrackHdr *t = s->track;
    return t->stages[t->current]->order;
}

u8 *fn_88540460(u8 *ret, Sortable *x, Sortable *y)
{
    if (order_of(x) < order_of(y))
        *ret = 1;
    else if (order_of(x) == order_of(y))
        *ret = x->track < y->track;
    else
        *ret = 0;
    return ret;
}
