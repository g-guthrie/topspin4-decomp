/* 0x883F17F8: finds the item on the list at +0x18 whose desc name equals name (fn_88329868), wraps it via fn_883D3A60(lbl_88CAC988, item) into *out; 0x24 when that fails, 0x5B when not found */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct Link { struct Link *next; } Link;
typedef struct Desc { char pad[0xc]; const char *name; } Desc;
typedef struct Item { int f0; Link link; char pad[0xc]; Desc *desc; } Item;
typedef struct T { char pad[0x18]; Link head; } T;
extern void *lbl_88CAC988;
int fn_88329868(const char *a, const char *b);
void *fn_883D3A60(void *mgr, Item *it);
int ts4_find_child_by_name_883F17F8(T *t, const char *name, void **out)
{
    Link *n;
    for (n = t->head.next; n != &t->head; n = n->next) {
        Item *it = n ? (Item *)((char *)n - 4) : 0;
        if (it->desc->name && fn_88329868(it->desc->name, name) == 0) {
            void *r = fn_883D3A60(lbl_88CAC988, it);
            *out = r;
            return r ? 0 : 0x24;
        }
    }
    return 0x5b;
}
