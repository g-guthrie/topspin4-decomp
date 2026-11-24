/* 0x8859B308: For each of count (+0) 0x60-byte entries (+8): when bits 12-19 of the first word differ from value, sets them to value and marks +0x30 dirty. */
/* Near miss (agAH): 2 off on /Oc /Os: add/lwzx operand order (target base, offset); &a[i], a + i, i[a], byte offsets and a local entries pointer do not flip it. */
typedef struct Entry { unsigned int bits; char pad4[0x2c]; int dirty; char pad34[0x60 - 0x34]; } Entry;
typedef struct EntryTable { unsigned int count; int unk4; Entry *entries; } EntryTable;
void fn_8859B308(EntryTable *t, unsigned int value)
{
    unsigned int i;
    for (i = 0; i < t->count; i++) {
        Entry *e = &t->entries[i];
        unsigned int w = e->bits;
        if (((w >> 12) & 0xff) != value) {
            e->dirty = 1;
            e->bits = (w & ~0xff000u) | ((value & 0xff) << 12);
        }
    }
}
