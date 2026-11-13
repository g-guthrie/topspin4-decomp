/* Binary-heap sift routines (MSVC STL-style _Adjust_heap/_Make_heap) over pointer arrays
   with a boolean comparison callback. */
#ifdef _MSC_VER
#define TS4_INLINE static __forceinline
#else
#define TS4_INLINE static inline
#endif

typedef unsigned char (*Ts4HeapLess)(void *lhs, void *rhs);

/* Move value up from hole toward top while its parent compares less. */
TS4_INLINE void ts4_heap_push_up_ptr(void **first, int hole, int top, void *value, Ts4HeapLess less)
{
    int parent;

    for (parent = (hole - 1) / 2; hole > top && less(first[parent], value); parent = (hole - 1) / 2) {
        first[hole] = first[parent];
        hole = parent;
    }
    first[hole] = value;
}

/* Sift hole down to the leaves taking the larger child, then push value back up. */
TS4_INLINE void ts4_heap_adjust_ptr_inline(void **first, int hole, int bottom, void *value, Ts4HeapLess less)
{
    int top = hole;
    int child = 2 * hole + 2;

    for (; child < bottom; child = 2 * child + 2) {
        if (less(first[child], first[child - 1])) {
            --child;
        }
        first[hole] = first[child];
        hole = child;
    }
    if (child == bottom) {
        first[hole] = first[child - 1];
        hole = child - 1;
    }
    ts4_heap_push_up_ptr(first, hole, top, value, less);
}

/* Swing_DLL.xex 0x88186EE8 */
void ts4_heap_adjust_ptr_88186EE8(void **first, int hole, int bottom, void *value, Ts4HeapLess less)
{
    int top = hole;
    int child = 2 * hole + 2;
    int parent;

    for (; child < bottom; child = 2 * child + 2) {
        if (less(first[child], first[child - 1])) {
            --child;
        }
        first[hole] = first[child];
        hole = child;
    }
    if (child == bottom) {
        first[hole] = first[child - 1];
        hole = child - 1;
    }
    for (parent = (hole - 1) / 2; hole > top && less(first[parent], value); parent = (hole - 1) / 2) {
        first[hole] = first[parent];
        hole = parent;
    }
    first[hole] = value;
}

/* Build a heap over [first,last) by sifting every internal node down, last parent first.
   Swing_DLL.xex 0x88186FF0 */
void ts4_make_heap_ptr_88186FF0(void **first, void **last, Ts4HeapLess less)
{
    int count = (int)(last - first);
    int hole = (count - 2) / 2;

    for (;;) {
        void *value = first[hole];
        ts4_heap_adjust_ptr_inline(first, hole, count, value, less);
        if (hole == 0) {
            break;
        }
        --hole;
    }
}
