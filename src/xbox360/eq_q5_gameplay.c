/* Q5 equivalent tier: small gameplay helpers (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * These pass tools/fn_equiv.py; they are not byte matches (see the per-function notes). */
typedef unsigned int u32;

extern void RtlEnterCriticalSection(void *section);
extern void RtlLeaveCriticalSection(void *section);

/* Lock holder: the critical section pointer is its first word. */
typedef struct Q5Lock { void *cs; } Q5Lock;
/* 12-byte u32 list (begin/end/capacity). */
typedef struct Q5U32List { u32 *begin; u32 *end; u32 *cap; } Q5U32List;
typedef struct Q5LockedList {
    char p00[0xc];
    Q5U32List list; /* +0x0c */
    char p18[0xc];
    Q5Lock *lock;   /* +0x24 */
} Q5LockedList;
/* push_back(list, &value) */
extern void ts4_if_call_seq_fn_8864DFF0_88278450(Q5U32List *list, const u32 *value);

/* 0x8864BBB0: append value to the list at +0xc while holding the lock at +0x24; returns 0.
 * Near miss (2 off): the target spills `value` after loading the lock and copying self. */
/* byte-gap: 2 off; target spills value after loading the lock and copying self */
int ts4_locked_list_push_8864BBB0(Q5LockedList *self, u32 value)
{
    Q5Lock *lock = self->lock;
    RtlEnterCriticalSection(lock->cs);
    ts4_if_call_seq_fn_8864DFF0_88278450(&self->list, &value);
    RtlLeaveCriticalSection(lock->cs);
    return 0;
}
