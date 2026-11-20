/* 0x886C8750: looks a key up in the bank's 16-byte entry table and reports the entry's index.
 * Returns 1 when found, 0 otherwise (the index is left untouched). */
typedef struct Entry { unsigned int key; char p[0xc]; } Entry;
typedef struct EntryTable { volatile int offset; int count; } EntryTable;
typedef struct Bank { char p[8]; EntryTable entries; } Bank;
typedef struct Owner { char p[0xc]; Bank *bank; } Owner;
Entry *fn_8826C388(EntryTable *t, const unsigned int *key);
unsigned char ts4_entry_index_by_key_886C8750(Owner *o, const unsigned int *key, int *index)
{
    unsigned char found = 0;
    Entry *e = fn_8826C388(&o->bank->entries, key);
    if (e != 0) {
        EntryTable *t = &o->bank->entries;
        *index = e - (Entry *)((char *)t + t->offset);
        found = 1;
    }
    return found;
}
