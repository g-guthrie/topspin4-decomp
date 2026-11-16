/* 0x8864A3B0 (hand match): removes an entry from the owner's list at offset 0x1c and, when it was
 * present and is not null, destroys its owned sub-objects (fields 0x1c and 0x10) and then runs the
 * standard cleanup. Sibling 0x8864AE08 does the same for the list at offset 0x28. */
typedef struct Entry Entry;
typedef struct Vec { Entry **first; Entry **last; } Vec;
typedef struct VVec { Entry **first; Entry **volatile last; } VVec;
typedef struct Obj { char p[0x1c]; Vec entries; } Obj;
struct Entry { char a[0x10]; void *field_10; char b[0x8]; void *field_1c; };
void *fn_88562DC0(void *dst, void *src, unsigned int n);
void ts4_destroy_owned_object(void *p);
void ts4_tsu_cleanup_end(Entry *e);
static __forceinline Entry **copy(Entry **first, Entry **last, Entry **dest)
{
    if (last == first) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (Entry **)fn_88562DC0(dest, first, n);
        return (Entry **)((char *)dest + n);
    }
}
static __forceinline void erase2(Vec *v, Entry **a, Entry **b) { if (a != b) { copy(b, v->last, a); v->last -= b - a; } }
static __forceinline void erase(Vec *v, Entry **p) { copy(p + 1, ((VVec *)v)->last, p); --v->last; }
static __forceinline Entry **find(Entry **first, Entry **last, Entry *e)
{
    int trip;
    for (trip = (last - first) >> 2; trip > 0; --trip) {
        if (*first == e) return first;
        ++first;
        if (*first == e) return first;
        ++first;
        if (*first == e) return first;
        ++first;
        if (*first == e) return first;
        ++first;
    }
    switch (last - first) {
    case 3:
        if (*first == e) return first;
        ++first;
    case 2:
        if (*first == e) return first;
        ++first;
    case 1:
        if (*first == e) return first;
        ++first;
    case 0:
    default:
        return last;
    }
}
void ts4_remove_and_destroy_entry_8864A3B0(Obj *o, Entry *e)
{
    Entry **p = find(o->entries.first, o->entries.last, e);
    if (o->entries.last != p) {
        erase(&o->entries, p);
        if (e != 0) {
            if (e->field_1c != 0) ts4_destroy_owned_object(e->field_1c);
            if (e->field_10 != 0) ts4_destroy_owned_object(e->field_10);
            ts4_tsu_cleanup_end(e);
        }
    }
}
