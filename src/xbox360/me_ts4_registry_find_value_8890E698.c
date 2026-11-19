/* Swing_DLL.xex 0x8890E698: Looks up the value of key *key in a vector of {value, key} pairs (inline Dinkumware std::find_if, 4x unrolled with a count switch); 0 if absent.
 * /Oc. The not-found return must be the fall-through: 'if (it != end) return it->value; return 0;' (the == form hoists li r3,0 to a beqlr). */
typedef struct Entry { void *value; unsigned int key; } Entry;
typedef struct Registry {
    unsigned char pad[4];
    Entry *begin;   /* 0x4 */
    Entry *end;     /* 0x8 */
} Registry;

static __inline Entry *find_key(Entry *first, Entry *last, unsigned int key)
{
    int trip = (last - first) >> 2;
    for (; trip > 0; --trip) {
        if (first->key == key) return first;
        ++first;
        if (first->key == key) return first;
        ++first;
        if (first->key == key) return first;
        ++first;
        if (first->key == key) return first;
        ++first;
    }
    switch (last - first) {
    case 3:
        if (first->key == key) return first;
        ++first;
    case 2:
        if (first->key == key) return first;
        ++first;
    case 1:
        if (first->key == key) return first;
        ++first;
    case 0:
    default:
        return last;
    }
}

void *fn_8890E698(Registry *r, const unsigned int *key)
{
    Entry *it = find_key(r->begin, r->end, *key);
    if (it != r->end) return it->value;
    return 0;
}
