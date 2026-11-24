/* nearmiss: 14 off; concrete blocker: register allocation and branch sense in the free path. The game tests
 * n == 0 (bne), keeps n in r28, and loads b.p before the duplicate clears of a; here n <= 0 (ble), n in r29 and
 * the clears of a come first. Tried: (int)p != 0 vs plain p tests, __forceinline/__inline zeroed-alloc helper,
 * if/else order, n == 0 test, unsigned n; perm_auto 429 candidates found nothing better.
 * 0x886CF018: resize of a two-array pair: n <= 0 frees both arrays; otherwise a gets a fresh n*4-byte block and b a
 * zero-filled one, both with count n. */
#ifdef _MSC_VER
#define Q5S_PTR_INT(p) ((int)(p))
#else
#define __forceinline __inline
#define Q5S_PTR_INT(p) ((int)(long)(p))
#endif
typedef unsigned int u32;
extern void *lbl_88D45B38;
extern void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);
extern void ts4_registry_dispatch_888860A0(void *p);
typedef struct Arr { void *p; int n; } Arr;
typedef struct Obj { int pad; Arr a; Arr b; } Obj;
static __inline void arr_free(Arr *a) { if (Q5S_PTR_INT(a->p) != 0) { ts4_registry_dispatch_888860A0(a->p); a->p = 0; a->n = 0; } a->p = 0; a->n = 0; }
static __forceinline u32 *new_zeroed(int n)
{
    u32 *p = (u32 *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, n * 4, 4, 0, 2);
    if (p != 0) {
        int i; u32 *q = p;
        for (i = n - 1; i >= 0; i--) *q++ = 0;
        return p;
    }
    return 0;
}
void ts4_pair_arrays_resize_886CF018(Obj *o, int n)
{
    if (n <= 0) {
        arr_free(&o->a); arr_free(&o->b);
    } else {
        o->a.p = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, n * 4, 4, 0, 2);
        o->a.n = n;
        o->b.p = new_zeroed(n);
        o->b.n = n;
    }
}
