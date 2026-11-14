/* Family FAM2: pooled deleting destructors (Swing_DLL.xex); same shape as d3b_pooled_deleting_dtor_88403ED8.c. */
typedef unsigned int u32;
extern u32 lbl_88CACF08;
void *KeTlsGetValue(u32 index);
void fn_8841A3F8(void *pool, int kind, void *object);
void ts4_if_call_seq_u32_off3c_8846A0F8(void *self);
void fn_884DA900(void *self);
void fn_884E1FE8(void *self);
void ts4_get_u32_off0_885EAD60(void *self);
void fn_885EAB70(void *self);
void fn_885EEFB8(void *self);
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
#define POOLED_DTOR(A, BASE, LIM, HEAD, KIND) \
typedef struct pool_##A { char pad0[LIM]; int limit; char pad1[(HEAD) - (LIM) - 4]; FreeList list; } pool_##A; \
void *ts4_pooled_deleting_dtor_##A(void *self, u32 flags); \
void *ts4_pooled_deleting_dtor_##A(void *self, u32 flags) \
{ \
    BASE(self); \
    if ((flags & 1) != 0 && self != 0) { \
        pool_##A *p = (pool_##A *)KeTlsGetValue(lbl_88CACF08); \
        if (list_full(&p->list, p->limit)) { fn_8841A3F8(p, KIND, self); } \
        else { list_push(&p->list, self); } \
    } \
    return self; \
}

POOLED_DTOR(8846A1B8, ts4_if_call_seq_u32_off3c_8846A0F8, 0x34, 0x60, 0x5)
POOLED_DTOR(884DA998, fn_884DA900, 0x34, 0x58, 0x4)
POOLED_DTOR(884E2060, fn_884E1FE8, 0x34, 0x50, 0x3)
POOLED_DTOR(885EAAD0, ts4_get_u32_off0_885EAD60, 0x34, 0x40, 0x1)
POOLED_DTOR(885EAC80, fn_885EAB70, 0x34, 0x68, 0x6)
POOLED_DTOR(885EC408, fn_885EEFB8, 0x34, 0x68, 0x6)
