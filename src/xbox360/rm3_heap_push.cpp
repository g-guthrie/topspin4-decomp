/* Priority-heap sift-up over records ordered by a multi-key comparison
 * (MSVC std::_Push_heap shape), Swing_DLL.xex auto_03_88259514. Field meanings
 * are unknown; names give offsets only. (RM3) */

struct ts4_heap_record {
    long long key0;      /* 0x00 */
    long long key8;      /* 0x08 */
    long long key10;     /* 0x10 */
    unsigned char pad18[0x74 - 0x18];
    int f74;
    int f78;
    /* 0x7c: flag word and 20-bit id; going through this member function (not a
     * plain field read) makes the compiler reload id, as the original does. */
    struct Slot {
        int used;
        unsigned int id;
        bool unset() const { return used == 0 || id == 0xfffff; }
    } slot;
    unsigned char pad84[0x8e - 0x84];
    short f8e;
    short f90;
    unsigned char pad92[2];
    short f94;
    unsigned char pad96[2];
    int f98;
    int f9c;
    unsigned char pada0[3];
    signed char fa3;
    signed char fa4;
    signed char fa5;
    unsigned char fa6b7 : 1;
    unsigned char fa6b6 : 1;
    unsigned char fa6b5 : 1;
    unsigned char fa6b4 : 1;
    unsigned char fa6lo : 4;
};

/* Strict-weak ordering used by the heap: true when a sorts before b. */
static bool record_less(const ts4_heap_record *a, const ts4_heap_record *b)
{
    if (a->f9c != b->f9c) return a->f9c < b->f9c;
    if (a->f74 != b->f74) return a->f74 > b->f74;
    if (a->fa5 != b->fa5) return a->fa5 < b->fa5;
    if (a->fa6b6 != b->fa6b6) return a->fa6b6 > b->fa6b6;
    if (a->f98 != b->f98) return a->f98 < b->f98;
    if (a->fa6lo != b->fa6lo) return a->fa6lo < b->fa6lo;
    if (b->fa6lo > 2) {
        if (a->fa3 == b->fa3) {
            if (a->key0 == b->key0) return a->fa4 < b->fa4;
            return a->key8 > b->key8;
        }
        return a->fa3 < b->fa3;
    }
    if (a->slot.id != b->slot.id) return a->slot.id < b->slot.id;
    bool skip = a->slot.unset();
    if (!skip) {
        if (a->f94 != b->f94) return a->f94 < b->f94;
        if (a->f8e != b->f8e || (unsigned char)a->fa4 != (unsigned char)b->fa4)
            return a->f8e < b->f8e || a->fa4 < b->fa4;
        if (a->f90 != b->f90) return a->f90 < b->f90;
    }
    if (a->fa6b5 != b->fa6b5) return a->fa6b5 < b->fa6b5;
    return a->key10 < b->key10;
}

/* Moves value up from hole toward top while its parent orders before it
 * (Swing_DLL.xex 0x8825AB38). */
extern "C" void ts4_record_heap_push_8825AB38(ts4_heap_record **heap, int hole, int top, ts4_heap_record *value)
{
    int parent = (hole - 1) / 2;
    while (hole > top && record_less(heap[parent], value)) {
        heap[hole] = heap[parent];
        hole = parent;
        parent = (hole - 1) / 2;
    }
    heap[hole] = value;
}
