/* NEAR MISS (~7 instructions): the game recomputes end - begin (bytes) for the copy; this source keeps
 * the size difference live in a saved register (one more save, frame 0xa0). Tried copy helper/forms. */
/* 0x886CF940: reserve() for a vector of 16-bit ids: when the capacity is below n, allocates n ids from
 * the vector's allocator, moves the current ids over, frees the old block and updates the three
 * pointers (begin, end, capacity). */
typedef struct Alloc { unsigned short *capacity; } Alloc;
typedef struct VecU16 { unsigned short *begin; unsigned short *end; Alloc alloc; } VecU16;
unsigned short *ts4_if_call_seq_u32_lbl_88D45B38_8815C920(Alloc *a, unsigned int n);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_destroy_owned_object(void *p);
static __inline unsigned short *allocate(Alloc *a, unsigned int n) { return n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_8815C920(a, n) : 0; }
static __inline void copy(unsigned short *d, unsigned short *b, unsigned short *e) { if (e != b) fn_88562DC0(d, b, (char *)e - (char *)b); }
void f(VecU16 *v, unsigned int n)
{
    if ((unsigned int)(v->alloc.capacity - v->begin) < n) {
        unsigned short *old = v->begin;
        unsigned short *oend = v->end;
        int size = oend - old;
        unsigned short *nb;
        if (old != 0) {
            nb = allocate(&v->alloc, n);
            if (oend != old) fn_88562DC0(nb, old, (unsigned int)oend - (unsigned int)old);
            ts4_destroy_owned_object(v->begin);
        } else {
            nb = allocate(&v->alloc, n);
        }
        v->begin = nb;
        v->end = nb + size;
        v->alloc.capacity = nb + n;
    }
}
