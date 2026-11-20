/* 0x881C7E10: storage size of a variant of the given type: kinds with bit 0x20 take 0x10 (0x14 with the array flag 0x40), bit 0x10 takes 0x14, others use the per-kind size table lbl_88C69D60 (times count plus 0x10 for arrays, plus 0xC otherwise) */
/* Matched on /Oc (agAL). Plain route. r = 0x10; if (array) r = 0x14; return r; gives the li/beqlr/li tail that the 0x10 kind branches into; an int array flag gives cmpwi; the table entry read into a local before the array test. */
typedef unsigned int u32;
extern int lbl_88C69D60[];

int ts4_variant_storage_size_881C7E10(u32 type, int count)
{
    u32 base = type & ~0x40u;
    int array = type & 0x40;
    if (base & 0x20) {
        int r = 0x10;
        if (array) r = 0x14;
        return r;
    }
    if (base & 0x10) return 0x14;
    {
        int size = lbl_88C69D60[base];
        if (array) return size * count + 0x10;
        return size + 0xc;
    }
}
