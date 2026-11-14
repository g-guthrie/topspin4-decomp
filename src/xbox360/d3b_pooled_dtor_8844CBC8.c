/* Swing_DLL.xex 0x8844CBC8-0x88455960, executable version 0.0.0.3. */
typedef unsigned int u32;
extern char lbl_88081F80[];
extern char lbl_88081F8C[];
extern u32 lbl_88CACF08;
void *KeTlsGetValue(u32 index);
void fn_8841A3F8(void *pool, int kind, void *object);
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
typedef struct FreeList { void *head; int count; } FreeList;
INL int list_full(FreeList *l, int limit) { return l->count >= limit; }
INL void list_push(FreeList *l, void *o) { l->count++; *(void **)o = l->head; l->head = o; }

/* Deleting-destructor tail for objects that live in per-thread free lists: resets the vtable, and when bit 0 of the
   flags is set, returns the object to the list for its kind (or hands it to the overflow path when the list is full). */
#define POOLED_DTOR(NAME, LABEL, LIM, HEAD, KIND) \
typedef struct NAME##_pool { char pad0[LIM]; int limit; char pad1[(HEAD) - (LIM) - 4]; FreeList list; } NAME##_pool; \
void *NAME(void *self, u32 flags) \
{ \
    *(void **)self = LABEL; \
    if (flags & 1) { \
        NAME##_pool *p = (NAME##_pool *)KeTlsGetValue(lbl_88CACF08); \
        if (list_full(&p->list, p->limit)) { fn_8841A3F8(p, KIND, self); } \
        else { list_push(&p->list, self); } \
    } \
    return self; \
}

POOLED_DTOR(ts4_pooled_dtor_8844CBC8, lbl_88081F80, 0x34, 0x40, 1)
POOLED_DTOR(ts4_pooled_dtor_8844CC58, lbl_88081F80, 0x34, 0x58, 4)
POOLED_DTOR(ts4_pooled_dtor_8844CCE8, lbl_88081F8C, 0x34, 0x48, 2)
POOLED_DTOR(ts4_pooled_dtor_884558D0, lbl_88081F80, 0x34, 0x60, 5)
POOLED_DTOR(ts4_pooled_dtor_88455960, lbl_88081F8C, 0x34, 0x40, 1)
