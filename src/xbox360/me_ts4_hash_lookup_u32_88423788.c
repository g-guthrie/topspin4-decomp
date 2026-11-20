/* 0x88423788: open-addressing u32 hash lookup: probes from ((key >> 4) * 0x9E3779B1) & mask over slots until an empty (-1) slot; on a hit returns the value stored at slots[mask + 1 + i], else def. */
/* Matched on /Oc (agAF). Plain while loop with the slot re-read for both tests. */
typedef struct H { unsigned int *slots; int p4; unsigned int mask; } H;
unsigned int fn_88423788(H *h, unsigned int key, unsigned int def)
{
    unsigned int i = (key >> 4) * 0x9E3779B1 & h->mask;
    while (h->slots[i] != 0xFFFFFFFF) {
        if (h->slots[i] == key)
            return h->slots[h->mask + i + 1];
        i = (i + 1) & h->mask;
    }
    return def;
}
