/* 0x883EF360: when def flag 0x1000 is set, runs fn_883CF9B8(item, v or 0 if def flag 0x2000) on each item of the list at +0x18, then fn_883CC388(def); returns the first error */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct Link { struct Link *next; } Link;
typedef struct Item Item;
typedef struct Def { char pad[0x60]; unsigned int flags; } Def;
typedef struct T { int f0; Def *def; char pad[0x10]; Link head; } T;
int fn_883CF9B8(Item *it, int v);
int fn_883CC388(Def *d);
int ts4_apply_to_children_then_def_883EF360(T *t, int v)
{
    int val = (t->def->flags & 0x2000) ? 0 : v;
    Link *n;
    int r;
    if (t->def->flags & 0x1000) {
        for (n = t->head.next; n != &t->head; n = n->next) {
            r = fn_883CF9B8(n ? (Item *)((char *)n - 4) : 0, val);
            if (r)
                return r;
        }
        r = fn_883CC388(t->def);
        if (r)
            return r;
    }
    return 0;
}
