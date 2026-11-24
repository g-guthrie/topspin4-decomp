/* 0x883D93D0: adds an item to the child list at +0x28 (creating the 0x64-byte list on first use via 883D92C8, taken to return this), rejecting a duplicate name (0x25); links it at the tail and stores its index (count-1); 0x2C on allocation failure */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_880393C4[];
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Kids { int p0; Link head; } Kids;
typedef struct Item { int vt; Link link; char pad[0x14 - 0xc]; const char *name; int index; } Item;
typedef struct T { char pad[0x28]; Kids *kids; } T;
void *ts4_tailcall_fn_88315C60_88316068(void *heap, unsigned int size, const char *file, int line, int flags);
Kids *fn_883D92C8(void *p);
int ts4_stricmp_ascii_88329868(const char *a, const char *b);

#define ITEM(n) ((n) ? (Item *)((char *)(n) - 4) : 0)

int fn_883D93D0(T *t, Item *it)
{
    Link *n, *h, *l;
    int count;
    if (!t->kids) {
        void *p = ts4_tailcall_fn_88315C60_88316068(lbl_88B3302C->heap, 0x64, lbl_880393C4, 0xee, 0);
        t->kids = p ? fn_883D92C8(p) : 0;
        if (!t->kids)
            return 0x2c;
    } else if (it->name) {
        for (n = t->kids->head.next; n != (t->kids ? &t->kids->head : 0); n = n->next)
            if (ITEM(n)->name && !ts4_stricmp_ascii_88329868(ITEM(n)->name, it->name))
                return 0x25;
    }
    h = t->kids ? &t->kids->head : 0;
    l = &it->link;
    {
        Link *pv = h->prev;
        l->next = h;
        l->prev = pv;
    }
    h->prev = l;
    l->prev->next = l;
    count = 0;
    h = &t->kids->head;
    for (n = h->next; n != h; n = n->next)
        count++;
    it->index = count - 1;
    return 0;
}
