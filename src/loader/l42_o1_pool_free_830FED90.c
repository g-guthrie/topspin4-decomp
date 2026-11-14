/* Loader_DLL.xex 0x830FED90-0x83101678, executable version 0.0.0.3. */
/* Fixed-block pool helpers: blocks inside the pool go back on its list, others fall through to the heap. */
typedef unsigned int u32;

extern void fn_83120540(void *p);
typedef struct PoolA { char *base; int cnt; int off; } PoolA;
void ts4l_pool_a_free_830FED90(PoolA *o, char *p)
{
    if (p >= o->base && p < o->base + 0x1000) {
        if (--o->cnt == 0)
            o->off = 0;
        return;
    }
    fn_83120540(p);
}
typedef struct PoolB { char *base; u32 size; u32 count; void **freelist; } PoolB;
void ts4l_pool_b_free_831016A0(PoolB *o, void **p)
{
    if ((char *)p >= o->base && (char *)p < o->base + o->count * o->size) {
        *p = o->freelist;
        o->freelist = p;
        return;
    }
    fn_83120540(p);
}

extern void *ts4_tailcall_fn_8340D710_83120518(u32 n);
void *ts4l_pool_b_alloc_83101678(PoolB *o)
{
    void **r = o->freelist;
    void *res;
    if (r != 0) {
        o->freelist = (void **)*r;
        res = r;
    } else {
        res = ts4_tailcall_fn_8340D710_83120518(o->count);
    }
    return res;
}
