/* 0x883ED7A8: runs fn_883ED2B0 (fade-in) on every item of the intrusive list at +0x30, stopping at the first error.
   LTCG only (agT): node and end kept in r5/r4 across the call; context is the matched callee. */
typedef struct Fade Fade;
typedef struct Link { struct Link *next; } Link;
typedef struct Group { char pad[0x30]; Link head; } Group;
int fn_883ED2B0(Fade *o);
int ts4_fade_group_begin_in_883ED7A8(Group *g)
{
    Link *n;
    int r;
    for (n = g->head.next; n != &g->head; n = n->next) {
        r = fn_883ED2B0(n ? (Fade *)((char *)n - 4) : 0);
        if (r)
            return r;
    }
    return 0;
}
