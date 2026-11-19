/* 0x883EF2A0: for every group in the list at +0xC and every source in its list at +0x34: runs ts4_stop_current_883E2C90 on the source when its flags (+0x24) have 2 or 0x10 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); else on each node of the source list at +0x78; returns the first error; model 0x883F6338. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct S { char pad[0x24]; unsigned flags; char pad2[0x78 - 0x28]; Link head; } S;
typedef struct G { char pad[0x34]; Link head; } G;
typedef struct T { char pad[0xc]; Link head; } T;
int ts4_stop_current_883E2C90(S *s);
int ts4_visit_all_sources_883EF2A0(T *t)
{
    Link *a, *b, *c;
    int r;
    for (a = t->head.next; a != &t->head; a = a->next) {
        G *g = a ? (G *)((char *)a - 4) : 0;
        for (b = g->head.next; b != &g->head; b = b->next) {
            S *s = b ? (S *)((char *)b - 4) : 0;
            if (!(s->flags & 2) && !(s->flags & 0x10)) {
                for (c = s->head.next; c != &s->head; c = c->next) {
                    r = ts4_stop_current_883E2C90(c ? (S *)((char *)c - 4) : 0);
                    if (r)
                        return r;
                }
            } else {
                r = ts4_stop_current_883E2C90(s);
                if (r)
                    return r;
            }
        }
    }
    return 0;
}
