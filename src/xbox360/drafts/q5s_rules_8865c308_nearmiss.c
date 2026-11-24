/* nearmiss: 32 off (LTCG); register numbering and scheduling only. 90 statement orders tried, all inert. No concrete blocker found: open. */
struct Flow { char p[0x7c]; int last; };
struct B44 { char p[0x64]; int loser; };
struct M { char p[0x30]; struct Flow *flow; char p2[0x10]; struct B44 *b44; };
struct S { void *vt; struct M *m; };
struct Info { unsigned reason; };
int f(struct S *self, struct Info *info)
{
    struct M *m; unsigned r; unsigned char miss, other, let; int last;
    m = self->m;
    r = info->reason;
    other = 0x79EE9B03u == r;
    miss = 0xC222A5E0u == r;
    let = 0xC9238771u == r;
    last = m->flow->last;
    if (0x3C1D5115u == r)
        last = 1 - last;
    if (0x22703895u == info->reason)
        return 1 - m->b44->loser;
    if (let)
        return -1;
    if (miss || other)
        return 1 - last;
    return last;
}
