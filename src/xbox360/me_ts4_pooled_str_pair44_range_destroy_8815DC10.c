/* Swing_DLL.xex 0x8815DC10: _Destroy(first, last) over 44-byte records holding two pooled strings (+0x1C, +0x10): buffers go back to the size-class free list (lbl_88D49310) or the heap.
 * /Oc. Sibling of 8815DCE0 (volatile pool lock lbl_88D49350, null test in deallocate(p, n)). */
typedef struct PoolNode { struct PoolNode *next; } PoolNode;
typedef struct PoolStr { char *first; char *last; char *end; } PoolStr;
typedef struct Record { unsigned int id; unsigned int kind; unsigned int w[2]; PoolStr b; PoolStr a; unsigned int pad; } Record;
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

void fn_8815DC10(Record *first, Record *last)
{
    for (; first != last; ++first) {
        pool_str_destroy(&first->a);
        pool_str_destroy(&first->b);
    }
}
