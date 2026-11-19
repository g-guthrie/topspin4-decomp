/* Swing_DLL.xex 0x88159870: pooled string destructor: returns the buffer to the size-class free list (lbl_88D49310) under the pool lock, or to the heap above 128 bytes.
 * /Oc. Base of the 8815DB40-8815DEA0 range destroyers; lock lbl_88D49350 declared volatile. */
typedef struct PoolNode { struct PoolNode *next; } PoolNode;
typedef struct PoolStr { char *first; char *last; char *end; } PoolStr;
extern PoolNode *lbl_88D49310[16];
extern volatile int lbl_88D49350;
void fn_8815E358(void);
void ts4_tsu_cleanup_end(void *p);

static __inline void pool_free(void *p, unsigned int n)
{
    if (n > 128) {
        ts4_tsu_cleanup_end(p);
    } else {
        PoolNode **list = &lbl_88D49310[(n - 1) >> 3];
        fn_8815E358();
        ((PoolNode *)p)->next = *list;
        *list = (PoolNode *)p;
        lbl_88D49350 = 0;
    }
}

static __inline void pool_dealloc(char *p, unsigned int n)
{
    if (p) pool_free(p, n);
}

static __inline void pool_str_destroy(PoolStr *s)
{
    pool_dealloc(s->first, s->end - s->first);
}

void fn_88159870(PoolStr *s)
{
    pool_str_destroy(s);
}
