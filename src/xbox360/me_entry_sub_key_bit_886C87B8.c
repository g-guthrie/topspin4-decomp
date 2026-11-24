/* 0x886C87B8: looks a key up in the bank's 16-byte entry table, reports the entry's index, then finds
 * the sub-key among the entry's listed ids and reports its bit (1 << position). Returns 1 when the
 * sub-key is found, else 0. */
typedef struct IdList { int offset; int count; } IdList;
typedef struct Entry { IdList ids; char p[8]; } Entry;
typedef struct EntryTable { volatile int offset; int count; } EntryTable;
typedef struct Bank { char p[8]; EntryTable entries; } Bank;
typedef struct Owner { char p[0xc]; Bank *bank; } Owner;
Entry *fn_8826C388(EntryTable *t, const unsigned int *key);
unsigned char ts4_entry_sub_key_bit_886C87B8(Owner *o, const unsigned int *key, const unsigned int *sub, int *index, unsigned int *bit)
{
    unsigned char found = 0;
    Entry *e = fn_8826C388(&o->bank->entries, key);
    if (e != 0) {
        EntryTable *t = &o->bank->entries;
        int i;
        int off = t->offset;
        *index = e - (Entry *)((char *)t + off);
        for (i = 0; i < e->ids.count; i++) {
            unsigned int *p = (unsigned int *)((char *)&e->ids + (i * 4 + e->ids.offset));
            if (*p == *sub) {
                *bit = 1 << (p - (unsigned int *)((char *)&e->ids + e->ids.offset));
                found = 1;
                break;
            }
        }
    }
    return found;
}
