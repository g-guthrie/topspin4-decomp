/* 0x883ED800: runs fn_883ED368 (fade-out) on every item of the intrusive list at +0x30, stopping at the first error.
   LTCG only (agT): node kept in r4 across the call; context is the matched callee. */
typedef struct Fade Fade;
typedef struct Link { struct Link *next; } Link;
typedef struct Group { char pad[0x30]; Link head; } Group;
int fn_883ED368(Fade *o);
int ts4_fade_group_begin_out_883ED800(Group *g)
{
    Link *n;
    int r;
    for (n = g->head.next; n != &g->head; n = n->next) {
        r = fn_883ED368(n ? (Fade *)((char *)n - 4) : 0);
        if (r)
            return r;
    }
    return 0;
}
