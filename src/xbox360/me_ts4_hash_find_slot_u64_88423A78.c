/* 0x88423A78: open-addressing u64 key lookup: probes from ((key >> 4) * 0x9E3779B1) & mask until an empty (-1) slot; returns the slot index of key, else mask + 1. */
/* Matched on /Oc (agAF). The probe index is a 64-bit variable (mulld, sign-extended int mask, clrrwi copy per probe) narrowed to u32 at each use. */
typedef struct H { unsigned __int64 *slots; int p4; int mask; } H;
unsigned int fn_88423A78(H *h, unsigned __int64 key)
{
    unsigned __int64 i = (key >> 4) * 0x9E3779B1 & h->mask;
    while (h->slots[(unsigned int)i] != (unsigned __int64)-1) {
        if (h->slots[(unsigned int)i] == key)
            return (unsigned int)i;
        i = (i + 1) & h->mask;
    }
    return h->mask + 1;
}
