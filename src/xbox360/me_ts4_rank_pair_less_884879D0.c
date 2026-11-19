/* Swing_DLL.xex 0x884879D0: sort predicate on (first rank, second rank) of two link pairs, each rank read through self-relative byte offsets
 * declare the four resolved links in use order (a, c, b, d) and read three ranks into locals before the compares */
typedef unsigned char u8;
typedef struct Ranked { u8 pad[0xC0]; int rank; } Ranked;
typedef struct Link { u8 pad[5]; signed char selfOff; u8 pad6[0x10 - 6]; signed char rankOff; u8 pad11[0x18 - 0x11]; u8 hasRank; } Link;
typedef struct RankPair { Link *first; Link *second; } RankPair;

static __inline Link *link_self(Link *l)
{
    return (Link *)((char *)l + l->selfOff);
}

static __inline Ranked *link_ranked(Link *l)
{
    return l->hasRank == 1 ? (Ranked *)((char *)l + l->rankOff) : 0;
}

int fn_884879D0(RankPair *x, RankPair *y)
{
    Link *a = link_self(x->first);
    Link *c = link_self(x->second);
    Link *b = link_self(y->first);
    Link *d = link_self(y->second);
    int ra = link_ranked(a)->rank;
    int rc = link_ranked(c)->rank;
    int rb = link_ranked(b)->rank;
    Ranked *pd = link_ranked(d);
    if (ra < rb)
        return 1;
    if (ra == rb)
        return rc < pd->rank;
    return 0;
}
