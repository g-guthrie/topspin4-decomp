/* 0x883F0480: runs fn_883FE2C0(item, flag) over the list at +0xC; when flag is 0, looks up def->f_ac->f18 (88317D80) and, if found, calls 88317F50(obj, 0, 1) */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct Link { struct Link *next; } Link;
typedef struct Item Item;
typedef struct Rec { char pad[0x18]; void *h; } Rec;
typedef struct Def { char pad[0xac]; Rec *rec; } Def;
typedef struct T { int f0; Def *def; char pad[4]; Link head; } T;
int fn_883FE2C0(Item *it, unsigned char flag);
int ts4_lookup_then_forward_88317D80(void *h, void **out);
int ts4_if_call_seq_fn_8832BFC0_88317F50(void *o, int a, int b);
int ts4_update_children_then_release_883F0480(T *t, unsigned char flag)
{
    Link *n;
    int r;
    void *o;
    for (n = t->head.next; n != &t->head; n = n->next) {
        r = fn_883FE2C0(n ? (Item *)((char *)n - 4) : 0, flag);
        if (r)
            return r;
    }
    if (!flag) {
        r = ts4_lookup_then_forward_88317D80(t->def->rec ? t->def->rec->h : 0, &o);
        if (!r && o)
            ts4_if_call_seq_fn_8832BFC0_88317F50(o, 0, 1);
    }
    return 0;
}
