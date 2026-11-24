/* Swing_DLL.xex 0x881B8360: pooled delete (destructor then kind-5 free list), no flags */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b133. */
typedef unsigned int u32;
extern u32 lbl_88CACF08;
void *KeTlsGetValue(u32 index);
void fn_8841A3F8(void *pool, int kind, void *object);
void fn_881B83E8(void *self);
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
typedef struct FreeList { void *head; int count; } FreeList;
INL int list_full(FreeList *l, int limit) { return l->count >= limit; }
INL void list_push(FreeList *l, void *o) { l->count++; *(void **)o = l->head; l->head = o; }
typedef struct Pool5 { char pad0[0x34]; int limit; char pad1[0x60 - 0x34 - 4]; FreeList list; } Pool5;

/* Unconditional pooled delete: runs the destructor, then returns a non-null object to the kind-5 per-thread
   free list (or the overflow path when the list is full). */
void *fn_881B8360(void *self)
{
    fn_881B83E8(self);
    if (self != 0) {
        Pool5 *p = (Pool5 *)KeTlsGetValue(lbl_88CACF08);
        if (list_full(&p->list, p->limit)) { fn_8841A3F8(p, 5, self); }
        else { list_push(&p->list, self); }
    }
    return self;
}
