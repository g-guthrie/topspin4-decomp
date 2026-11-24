/* 0x883DFE20: adds an item to the set at +0x48 (creating the 0x54-byte set via 883DFC50 and initialising it inline), rejecting null (0x25) or a duplicate name (0x5A); tail-links it, sets owner and index, then calls item slot 14 with the owner mode byte at +0x1D; 0x2C on allocation failure. Float 1.0f/0.0f literals; owner store through a pointer local fixes its order */
/* Matched on /O1 plain only (agX, v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_8803955C[];
extern const float lbl_88001A68;
extern const float lbl_88001A20;
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct T T;
typedef struct Item Item;
typedef struct ItemVt { void *f[14]; int (*attach)(Item *it, unsigned char v); } ItemVt;
struct Item { ItemVt *vt; Link link; char pad[0x14 - 0xc]; const char *name; int index; char pad2[0x4c - 0x1c]; T *owner; };
typedef struct Set {
    int p0; Link head; char pad[0x14 - 0xc];
    int a14, a18;
    unsigned char b1c, b1d;
    float f20, f24, f28;
    int a2c;
    unsigned short h30;
    int a34;
    Link list;
    int a40, a44, a48, a4c, a50;
} Set;
struct T { char pad[0x1d]; unsigned char mode; char pad2[0x48 - 0x1e]; Set *set; };
void *fn_88315C60(void *heap, unsigned int size, const char *file, int line, int a, int b);
Set *fn_883DFC50(void *p);
Item *ts4_find_named_in_set_883DEE80(T *t, const char *name);

int fn_883DFE20(T *t, Item *it)
{
    Link *n, *h, *l;
    int count;
    if (!it)
        return 0x25;
    if (t->set) {
        if (ts4_find_named_in_set_883DEE80(t, it->name))
            return 0x5a;
    } else {
        void *p = fn_88315C60(lbl_88B3302C->heap, 0x54, lbl_8803955C, 0x201, 0, 0);
        Set *s;
        t->set = p ? fn_883DFC50(p) : 0;
        if (!t->set)
            return 0x2c;
        s = t->set;
        s->a14 = 0;
        s->a18 = 0;
        s->b1c = 0;
        s->b1d = 0;
        s->f20 = 1.0f;
        s->f24 = 1.0f;
        s->f28 = 0.0f;
        s->a2c = 0;
        s->h30 = 0;
        s->a34 = 0;
        s->a44 = 0;
        s->a48 = 0;
        s->a4c = 0;
        s->a50 = 0;
        { Link *l = &s->list; l->next = l; l->prev = l; }
        s->a40 = 0;
    }
    h = t->set ? &t->set->head : 0;
    l = &it->link;
    {
        Link *pv = h->prev;
        l->next = h;
        l->prev = pv;
    }
    h->prev = l;
    l->prev->next = l;
    { T **o = &it->owner; *o = t; }
    count = 0;
    for (n = it->link.next; n != l; n = n->next)
        count++;
    it->index = count - 1;
    return it->vt->attach(it, t->mode);
}
