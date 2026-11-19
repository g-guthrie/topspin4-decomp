/* Swing_DLL.xex 0x88487FB8: put the lower-ranked link first in every pair, then sort the pairs with fn_884891E0 / fn_884879D0
 * end pointer local for the ctr loop; first rank in a local before the compare; swap through an inline taking both slot pointers */
typedef unsigned char u8;
typedef struct Ranked { u8 pad[0xC0]; int rank; } Ranked;
typedef struct Link { u8 pad[5]; signed char selfOff; u8 pad6[0x10 - 6]; signed char rankOff; u8 pad11[0x18 - 0x11]; u8 hasRank; } Link;
typedef struct RankPair { Link *first; Link *second; } RankPair;
typedef struct RankPairList { RankPair *pairs; int count; } RankPairList;

int fn_884879D0(RankPair *x, RankPair *y);
void fn_884891E0(RankPair *items, int lo, int hi, int (*less)(RankPair *, RankPair *));

static __inline Link *link_self(Link *l)
{
    return (Link *)((char *)l + l->selfOff);
}

static __inline Ranked *link_ranked(Link *l)
{
    return l->hasRank == 1 ? (Ranked *)((char *)l + l->rankOff) : 0;
}

static __inline void swap_links(Link **a, Link **b)
{
    Link *t = *a;
    *a = *b;
    *b = t;
}

/* Order each pair so the lower rank comes first, then sort the pairs. */
void fn_88487FB8(RankPairList *list)
{
    RankPair *p = list->pairs;
    RankPair *end = p + list->count;
    for (; p < end; p++) {
        Link *a = link_self(p->first);
        Link *b = link_self(p->second);
        int ra = link_ranked(a)->rank;
        if (ra > link_ranked(b)->rank)
            swap_links(&p->first, &p->second);
    }
    if (list->count > 1)
        fn_884891E0(list->pairs, 0, list->count - 1, fn_884879D0);
}
