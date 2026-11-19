/* 0x883F6338: runs fn_883E2C90 on the source at +0x10 itself when its flags (+0x24) have 2 or 0x10 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); else on every node of its list at +0x78 (link at node+4, end re-read each pass); returns the first error. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct S { char pad[0x24]; unsigned flags; char pad2[0x78 - 0x28]; Link head; } S;
typedef struct T { char pad[0x10]; S *s; } T;
int fn_883E2C90(S *s);
int ts4_visit_source_items_883F6338(T *t)
{
    S *s;
    int r;
    if (t->s) {
        s = t->s;
        if (!(s->flags & 2) && !(s->flags & 0x10)) {
            Link *n;
            for (n = s->head.next; n != &t->s->head; n = n->next) {
                r = fn_883E2C90(n ? (S *)((char *)n - 4) : 0);
                if (r)
                    return r;
            }
        } else {
            r = fn_883E2C90(s);
            if (r)
                return r;
        }
    }
    return 0;
}
