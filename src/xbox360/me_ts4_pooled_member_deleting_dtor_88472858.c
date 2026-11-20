/* Swing_DLL.xex 0x88472858: pooled deleting destructor, member at +0x28, free-list kind 5 */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b133. */
typedef unsigned int u32;
extern u32 lbl_88CACF08;
void *KeTlsGetValue(u32 index);
void fn_8841A3F8(void *pool, int kind, void *object);
void ts4_if_call_seq_u32_off4_88472748(void *member);
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
typedef struct FreeList { void *head; int count; } FreeList;
INL int list_full(FreeList *l, int limit) { return l->count >= limit; }
INL void list_push(FreeList *l, void *o) { l->count++; *(void **)o = l->head; l->head = o; }
typedef struct Pool5 { char pad0[0x34]; int limit; char pad1[0x60 - 0x34 - 4]; FreeList list; } Pool5;

/* Deleting destructor: destroys the member at +0x28, then returns the object to the kind-5 per-thread free list
   (or the overflow path when the list is full) when bit 0 of the flags is set. */
void *fn_88472858(void *self, u32 flags)
{
    ts4_if_call_seq_u32_off4_88472748((char *)self + 0x28);
    if ((flags & 1) != 0 && self != 0) {
        Pool5 *p = (Pool5 *)KeTlsGetValue(lbl_88CACF08);
        if (list_full(&p->list, p->limit)) { fn_8841A3F8(p, 5, self); }
        else { list_push(&p->list, self); }
    }
    return self;
}
