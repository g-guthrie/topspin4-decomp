/* Swing_DLL.xex 0x8825B918: Swing_DLL.xex 0x8825B918: Unless busy: for every id in the vector at +0x12C that is in use in the global slot pool (not negative, not on the free list), releases the 0x44-byte slot (88753388) and returns the id to the free list (8825E900); then empties the vector and resets the list at +0x150.
 * /Oc. Signed count and index (int i, n) give the base-first lwzx operand order; free-list end cached, end != it. */
typedef struct Slot44 { char data[0x44]; } Slot44;
typedef struct IntVec { int *first; int *last; int *end; } IntVec;
typedef struct SlotPool {
    char pad[4];
    char free_list[0x14 - 4];   /* 0x04 */
    unsigned *free_first;       /* 0x14 */
    unsigned *free_last;        /* 0x18 */
    char pad1c[0x24 - 0x1c];
    Slot44 *slots;              /* 0x24 */
} SlotPool;
typedef struct Game { char pad[0x10]; SlotPool *pool; } Game;
typedef struct Owner {
    char pad[0x110];
    int busy;                   /* 0x110 */
    char pad114[0x12c - 0x114];
    IntVec ids;                 /* 0x12c */
    char pad138[0x150 - 0x138];
    char list150[4];            /* 0x150 */
} Owner;
extern Game *lbl_88D45AD4;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_release_three_88753388(Slot44 *s);
void ts4_ptrvec_add_vcall44_8825E900(void *free_list, int id);
void ts4_if_call_seq_u32_off0_886F9C80(void *list);
static __forceinline int *copy_ints(int *first, int *last, int *dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (int *)fn_88562DC0(dest, first, n);
        return (int *)((char *)dest + n);
    }
}
static __inline unsigned char pool_in_use(SlotPool *p, int id)
{
    unsigned *it, *end;
    if (id < 0)
        return 0;
    end = p->free_last;
    for (it = p->free_first; end != it; it++)
        if ((unsigned)id == *it)
            return 0;
    return 1;
}
static __inline int intvec_size(const IntVec *v) { return v->last - v->first; }
void fn_8825B918(Owner *o)
{
    if (o->busy == 0) {
        IntVec *v = &o->ids;
        SlotPool *pool = lbl_88D45AD4->pool;
        int i, n = intvec_size(v);
        for (i = 0; i != n; i++) {
            int id = v->first[i];
            if (pool_in_use(pool, id) == 1) {
                ts4_release_three_88753388(&pool->slots[id]);
                ts4_ptrvec_add_vcall44_8825E900(pool->free_list, id);
            }
        }
        v->last = copy_ints(v->last, v->last, v->first);
        ts4_if_call_seq_u32_off0_886F9C80(o->list150);
    }
}
