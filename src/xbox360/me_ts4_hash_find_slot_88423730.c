/* 0x88423730: looks a key up in an open-addressed word table (slots +0, mask +8; -1 = empty) hashed as (key >> 4) * 0x9E3779B1 with linear probing; returns the slot index, or mask + 1 when absent. */
/* Matched on /Oc (agAB). while ((k = slots[i]) != -1) loop with the probe step at the bottom. */
typedef struct H { unsigned int *slots; int p4; unsigned int mask; } H;
unsigned int fn_88423730(H *h, unsigned int key)
{
    unsigned int i = (key >> 4) * 0x9e3779b1 & h->mask;
    unsigned int k;
    while ((k = h->slots[i]) != 0xffffffff) {
        if (k == key)
            return i;
        i = (i + 1) & h->mask;
    }
    return h->mask + 1;
}
