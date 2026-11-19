/* 0x883FE220: when open (+0x28): releases each list item resource (+0x1C) not marked kept (+0x18) and clears it, then the own resource at +0x2C */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); clears open; returns the first release error. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Item { int f0; Link link; char pad[0x18 - 0xc]; unsigned kept; void *res; } Item;
typedef struct T { char pad[0x28]; unsigned open; void *res; char pad2[0x40 - 0x30]; Link head; } T;
int ts4_if_get_fn_8832BFC0_88317EC0(void *res);
int ts4_if_call_seq_fn_8832F930_88317A28(void *res);
int ts4_release_items_883FE220(T *t)
{
    if (t->open) {
        Link *n;
        int r;
        for (n = t->head.next; n != &t->head; n = n->next) {
            Item *it = n ? (Item *)((char *)n - 4) : 0;
            if (it->res && !it->kept) {
                r = ts4_if_get_fn_8832BFC0_88317EC0(it->res);
                if (r)
                    return r;
            }
            it->res = 0;
        }
        if (t->res) {
            r = ts4_if_call_seq_fn_8832F930_88317A28(t->res);
            if (r)
                return r;
            t->res = 0;
        }
        t->open = 0;
    }
    return 0;
}
