/* Swing_DLL.xex 0x88540500-0x8863A178, executable version 0.0.0.3. */
typedef struct Ts4Item70 { float v; char pad[0x6c]; } Ts4Item70;
typedef struct Ts4Items { char pad[0x30]; Ts4Item70 *data; int count; } Ts4Items;
typedef struct Ts4Sub { char pad[8]; Ts4Items *items; } Ts4Sub;
typedef struct Ts4Holder { char pad[0xc]; Ts4Sub *sub; } Ts4Holder;
void ts4_items_add_88540500(Ts4Holder *h, float f)
{
    Ts4Items *it = h->sub->items;
    int i;
    for (i = 0; i < it->count; ++i) {
        it->data[i].v += f;
    }
}
typedef struct Ts4Pair { unsigned a; unsigned b; } Ts4Pair;
int ts4_find_slot_88618390(Ts4Pair *tab, unsigned n, const unsigned *key, unsigned val)
{
    int r = 0;
    unsigned i;
    for (i = 0; i < n; ++i) {
        Ts4Pair *p = &tab[i];
        if (p->a == 0) {
            r = i + 1;
            p->a = *key;
            p->b = val;
            break;
        }
    }
    return r;
}
typedef struct Ts4V2 { char pad[0x45c]; float x, y; char pad2[0x39]; unsigned char dirty; } Ts4V2;
