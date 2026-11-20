/* 0x883DFF90: merges item it into tree t: when t's set (+0x48) has an item with the same name, optionally (update) applies it's floats +0x20/+0x28 through slots 8 and 10 and recursively merges each of it's children into it; otherwise releases it's tree (883DF0F0), unlinks it, adds it to t (883DFE20) and calls 883DEF28(it, t) */
/* Matched on /O1 plain and LTCG (agX, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Set { int p0; Link head; } Set;
typedef struct Item Item;
typedef struct ItemVt { void *f[8]; int (*set_a)(Item *it, float v); void *f9; int (*set_b)(Item *it, float v, int c); } ItemVt;
struct Item {
    ItemVt *vt; Link link; int fc; char pad[0x14 - 0x10]; const char *name;
    char pad1[0x20 - 0x18]; float a; char pad2[0x28 - 0x24]; float b;
    char pad3[0x48 - 0x2c]; Set *set;
};
int fn_88329868(const char *a, const char *b);
int ts4_release_tree_883DF0F0(Item *t);
int fn_883DFE20(Item *t, Item *it);
int fn_883DEF28(Item *it, Item *t);
#define HEAD(s) ((s) ? &(s)->head : 0)
#define ITEM(n) ((n) ? (Item *)((char *)(n) - 4) : 0)

int fn_883DFF90(Item *t, Item *it, unsigned char update)
{
    Link *n;
    Item *found;
    int r;
    if (t->set) {
        for (n = t->set->head.next; n != HEAD(t->set); n = n->next) {
            if (!fn_88329868(ITEM(n)->name, it->name)) {
                found = ITEM(n);
                if (!found)
                    break;
                if (update) {
                    r = found->vt->set_a(found, it->a);
                    if (r)
                        return r;
                    r = found->vt->set_b(found, it->b, 0);
                    if (r)
                        return r;
                }
                if (it->set) {
                    for (n = it->set->head.next; n != HEAD(it->set); ) {
                        Item *c = ITEM(n);
                        n = n->next;
                        r = fn_883DFF90(found, c, update);
                        if (r)
                            return r;
                    }
                }
                return 0;
            }
        }
    }
    ts4_release_tree_883DF0F0(it);
    it->link.prev->next = it->link.next;
    it->link.next->prev = it->link.prev;
    it->link.prev = &it->link;
    it->link.next = &it->link;
    it->fc = 0;
    r = fn_883DFE20(t, it);
    if (r)
        return r;
    fn_883DEF28(it, t);
    return 0;
}
