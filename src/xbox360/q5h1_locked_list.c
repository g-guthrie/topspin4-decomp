/* Q5h1 clone: append under a critical section (Top Spin 4, Xbox 360, Swing_DLL.xex), equivalent tier.
 * Clone of ts4_locked_list_push_8864BBB0 (eq_q5_gameplay.c). Sister 0x8864BAE8 has the same body with the
 * lock at +0x48 (template +0x24) and the list at +0x38 (template +0x0C). The struct padding changes; the
 * code does not. */
typedef unsigned int u32;

extern void RtlEnterCriticalSection(void *section);
extern void RtlLeaveCriticalSection(void *section);

/* Lock holder: the critical section pointer is its first word. */
typedef struct Q5h1Lock { void *cs; } Q5h1Lock;
/* 12-byte u32 list (begin/end/capacity). */
typedef struct Q5h1U32List { u32 *begin; u32 *end; u32 *cap; } Q5h1U32List;
typedef struct Q5h1LockedList {
    char p00[0x38];
    Q5h1U32List list; /* +0x38 */
    char p44[0x4];
    Q5h1Lock *lock;   /* +0x48 */
} Q5h1LockedList;
/* push_back(list, &value): same prototype as the template's callee, with this file's list type */
extern void ts4_if_call_seq_fn_8864DFF0_88278450(Q5h1U32List *list, const u32 *value);

/* Swing_DLL.xex 0x8864BAE8: append value to the list at +0x38 while holding the lock at +0x48; returns 0. */
/* byte-gap: 2 off; target spills value after loading the lock and copying self (as 0x8864BBB0) */
int ts4_locked_list_push_8864BAE8(Q5h1LockedList *self, u32 value)
{
    Q5h1Lock *lock = self->lock;
    RtlEnterCriticalSection(lock->cs);
    ts4_if_call_seq_fn_8864DFF0_88278450(&self->list, &value);
    RtlLeaveCriticalSection(lock->cs);
    return 0;
}
