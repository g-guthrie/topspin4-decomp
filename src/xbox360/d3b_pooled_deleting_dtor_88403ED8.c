/* Swing_DLL.xex 0x88403ED8-0x884A1D44, executable version 0.0.0.3. */
typedef unsigned int u32;
extern u32 lbl_88CACF08;
void *KeTlsGetValue(u32 index);
void fn_8841A3F8(void *pool, int kind, void *object);
void fn_88403BC8(void *self);
void fn_884418D0(void *self);
void fn_88489B98(void *self);
void fn_884A8B00(void *self);
void ts4_addr_lbl_880869E8_885F3BC0(void *self);
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
typedef struct FreeList { void *head; int count; } FreeList;
INL int list_full(FreeList *l, int limit) { return l->count >= limit; }
INL void list_push(FreeList *l, void *o) { l->count++; *(void **)o = l->head; l->head = o; }

/* Deleting-destructor: runs the base destructor, then (when bit 0 of the flags is set and the object exists) returns
   the object to the per-thread free list for its kind, or to the overflow path when that list is full. */
#define POOLED_DTOR(NAME, BASE, LIM, HEAD, KIND) \
typedef struct NAME##_pool { char pad0[LIM]; int limit; char pad1[(HEAD) - (LIM) - 4]; FreeList list; } NAME##_pool; \
void *NAME(void *self, u32 flags) \
{ \
    BASE(self); \
    if ((flags & 1) != 0 && self != 0) { \
        NAME##_pool *p = (NAME##_pool *)KeTlsGetValue(lbl_88CACF08); \
        if (list_full(&p->list, p->limit)) { fn_8841A3F8(p, KIND, self); } \
        else { list_push(&p->list, self); } \
    } \
    return self; \
}

POOLED_DTOR(ts4_pooled_deleting_dtor_88403ED8, fn_88403BC8, 0x34, 0x58, 4)
POOLED_DTOR(ts4_pooled_deleting_dtor_88437A70, fn_884418D0, 0x34, 0x60, 5)
POOLED_DTOR(ts4_pooled_deleting_dtor_88472608, ts4_addr_lbl_880869E8_885F3BC0, 0x34, 0x90, 11)
POOLED_DTOR(ts4_pooled_deleting_dtor_884726A8, fn_88489B98, 0x34, 0x68, 6)
POOLED_DTOR(ts4_pooled_deleting_dtor_884A1CA8, fn_884A8B00, 0x34, 0x50, 3)
