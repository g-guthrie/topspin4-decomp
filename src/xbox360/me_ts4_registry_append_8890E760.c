/* Swing_DLL.xex 0x8890E760: Appends {value, *key} to the registry's entry vector: inline resize(size + 1) (default key 0, _Insert_n fn_88180B38), then fills the last entry.
 * /Oc. Sibling of 8890E698. The last entry goes through one 'Entry *e = last - 1' local, or end is reloaded after the key load. */
typedef struct Entry { void *value; unsigned int key; } Entry;
typedef struct EntryVec { Entry *first; Entry *last; Entry *end; } EntryVec;
typedef struct Registry {
    unsigned char pad[4];
    EntryVec entries;   /* 0x4 */
} Registry;
void fn_88180B38(EntryVec *v, Entry *where, unsigned int count, const Entry *val);

static __inline Entry *copy_entries(Entry *f, Entry *l, Entry *d)
{
    int n;
    for (n = l - f; 0 < n; --n, ++f, ++d) {
        d->value = f->value;
        d->key = f->key;
    }
    return d;
}

static __inline void entries_resize(EntryVec *v, unsigned int n)
{
    Entry val;
    val.key = 0;
    if (n < (unsigned int)(v->last - v->first))
        v->last = copy_entries(v->last, v->last, v->first + n);
    else
        fn_88180B38(v, v->last, n - (v->last - v->first), &val);
}

void fn_8890E760(Registry *r, void *value, const unsigned int *key)
{
    entries_resize(&r->entries, (r->entries.last - r->entries.first) + 1);
    {
        Entry *e = r->entries.last - 1;
        e->value = value;
        e->key = *key;
    }
}
