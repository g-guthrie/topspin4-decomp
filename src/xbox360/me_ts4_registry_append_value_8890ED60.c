/* Swing_DLL.xex 0x8890ED60: Appends {12-byte value (by value), *key} to the 16-byte entry vector: inline resize(size() + 1) with the default {0, 0xFFFFF, 0, 0} (_Insert_n fn_88178D10), then fills the last entry.
 * /Oc. Needs an inline size() helper used for both size computations (the open-coded form is 52 off); sibling of 8890E760. */
typedef struct Value12 { unsigned int a; unsigned int link; unsigned int c; } Value12;
typedef struct Entry16 { Value12 v; unsigned int key; } Entry16;
typedef struct EntryVec { Entry16 *first; Entry16 *last; Entry16 *end; } EntryVec;
typedef struct Registry {
    unsigned char pad[4];
    EntryVec entries;   /* 0x4 */
} Registry;
void fn_88178D10(EntryVec *v, Entry16 *where, unsigned int count, const Entry16 *val);

static __inline Entry16 *copy_entries(Entry16 *f, Entry16 *l, Entry16 *d)
{
    int n;
    for (n = l - f; 0 < n; --n, ++f, ++d) {
        d->v = f->v;
        d->key = f->key;
    }
    return d;
}

static __inline unsigned int entries_size(const EntryVec *v) { return v->last - v->first; }
static __inline void entries_resize(EntryVec *v, unsigned int n)
{
    Entry16 val;
    val.v.a = 0;
    val.v.link = 0xFFFFF;
    val.v.c = 0;
    val.key = 0;
    if (n < entries_size(v))
        v->last = copy_entries(v->last, v->last, v->first + n);
    else
        fn_88178D10(v, v->last, n - entries_size(v), &val);
}

void fn_8890ED60(Registry *r, const unsigned int *key, Value12 value)
{
    entries_resize(&r->entries, entries_size(&r->entries) + 1);
    {
        Entry16 *e = r->entries.last - 1;
        e->v = value;
        e->key = *key;
    }
}
