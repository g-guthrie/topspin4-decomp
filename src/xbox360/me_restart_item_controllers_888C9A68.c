typedef struct Ctl { char pad[8]; void *owner; char p1[0x1e]; short st; int timer; } Ctl;
typedef struct Item { char pad[0x10]; Ctl *ctl; char p1[0x44]; unsigned int hash; char p2[0xc]; unsigned char active; } Item;
typedef struct Obj { char pad[0xac]; int **refs_first; int **refs_last; char p1[4]; Item **items_first; Item **items_last; char p2[0x1470]; unsigned char ready; unsigned char armed; } Obj;
void ts4_if_call_seq_u32_off8_88473208(void *p, int a, int b, int c);
void fn_8846F580(void *a, void *b, int c, int d);
/* Clears every referenced flag, then restarts each item controller (state 1, timer 10) and arms the object. */
void fn_888C9A68(Obj *o)
{
    int **r, **re;
    Item **it, **ie;
    re = o->refs_last;
    for (r = o->refs_first; r != re; r++)
        **r = 0;
    ie = o->items_last;
    for (it = o->items_first; it != ie; it++) {
        Item *x = *it;
        if (x->ctl) {
            { unsigned int *h = &x->hash; *h = 0x29E6DBEF; }
            ts4_if_call_seq_u32_off8_88473208(x->ctl, 7, 1, 0);
            x->ctl->st = 1;
            x->active = 1;
            x->ctl->timer = 10;
            fn_8846F580(x->ctl->owner, x->ctl, 0, 0);
        }
    }
    o->ready = 1;
    o->armed = 1;
}
