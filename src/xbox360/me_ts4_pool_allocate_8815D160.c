/* Swing_DLL.xex 0x8815D160: SGI-style node pool allocate(n): pops the size-class free list (lbl_88D49310) under the pool lock, else refills it with 20 nodes carved from a chunk (fn_8815E1D8).
 * /Oc. _S_refill inlined; one result variable for both paths; lock lbl_88D49350 volatile. */
typedef struct PoolNode { struct PoolNode *next; } PoolNode;
extern PoolNode *lbl_88D49310[16];
extern volatile int lbl_88D49350;
void fn_8815E358(void);
char *fn_8815E1D8(unsigned int size, int *nobjs);

static __inline void *pool_refill(unsigned int n)
{
    int nobjs = 20;
    char *chunk = fn_8815E1D8(n, &nobjs);
    PoolNode **list;
    PoolNode *cur, *next;
    int i;
    if (nobjs == 1) return chunk;
    list = &lbl_88D49310[(n - 1) >> 3];
    *list = next = (PoolNode *)(chunk + n);
    for (i = 1; ; i++) {
        cur = next;
        next = (PoolNode *)((char *)next + n);
        if (nobjs - 1 == i) {
            cur->next = 0;
            break;
        } else {
            cur->next = next;
        }
    }
    return chunk;
}

void *fn_8815D160(unsigned int n)
{
    PoolNode **list = &lbl_88D49310[(n - 1) >> 3];
    PoolNode *r;
    fn_8815E358();
    r = *list;
    if (r != 0) {
        *list = r->next;
    } else {
        r = (PoolNode *)pool_refill((n + 7) & ~7);
    }
    lbl_88D49350 = 0;
    return r;
}
