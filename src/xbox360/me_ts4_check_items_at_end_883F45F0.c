/* 0x883F45F0: sets *out to 1 when the object is flagged (bit 0x80000 at +0x60) or some item with mode bit 4 sits at its end (dir > 0 at 1, or dir < 0 at 0), every dependency passes fn_883FDBB8, or every item passes fn_883F4368 (2 when one returns 2); 0x25 when out is null. */
/* Matched on /O1 (agAB). The 0.0/1.0 constants are block locals read after the call, 1.0 first; the r == 0 test is the else arm. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Mode { char pad[0x10]; float dir; char p14[0x28 - 0x14]; unsigned int flags; } Mode;
typedef struct Item { int p0; Link link; char pc[0x14 - 0xc]; Mode *mode; } Item;
typedef struct Obj { char pad[0x60]; unsigned int flags; } Obj;
typedef struct T { int p0; Obj *obj; char p8[0xc - 8]; Link deps; char p14[4]; Link items; } T;
extern float lbl_88001A20;
extern float lbl_88001A68;
void fn_883CEC88(Item *it, float *a, float *b, float *c);
unsigned char fn_883FDBB8(Item *it);
int fn_883F4368(T *t, Item *it);
static unsigned char list_empty(Link *h) { return h->next == h && h->prev == h; }
int fn_883F45F0(T *t, int *out)
{
    Link *l;
    unsigned char found, all;
    int r;
    if (!out)
        return 0x25;
    *out = 0;
    found = (unsigned char)((t->obj->flags >> 19) & 1);
    if (!found) {
        for (l = t->items.next; l != &t->items; l = l->next) {
            Item *it = l ? (Item *)((char *)l - 4) : 0;
            Mode *m = it->mode;
            if (m->flags & 4) {
                float a, b, c;
                fn_883CEC88(it, &c, &b, &a);
                {
                    float one = lbl_88001A68;
                    float z = lbl_88001A20;
                    if ((m->dir > z && a == one) || (m->dir < z && a == z)) {
                        found = 1;
                        break;
                    }
                }
            }
        }
    }
    if (found) {
        all = 1;
        for (l = t->deps.next; l != &t->deps; l = l->next) {
            if (!fn_883FDBB8(l ? (Item *)((char *)l - 4) : 0)) {
                all = 0;
                break;
            }
        }
        if (all) {
            *out = 1;
        } else if (!list_empty(&t->items)) {
            all = 1;
            for (l = t->items.next; l != &t->items; l = l->next) {
                r = fn_883F4368(t, l ? (Item *)((char *)l - 4) : 0);
                if (r) {
                    if (r == 2) {
                        *out = 2;
                        return 0;
                    }
                } else
                    all = 0;
            }
            if (all)
                *out = 1;
        }
    }
    return 0;
}
