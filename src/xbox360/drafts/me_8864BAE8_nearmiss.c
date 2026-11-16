/* NEAR MISS 0x8864BAE8: 2 off, the parameter spill (stw r4,0x8c(r1)) is scheduled before the lock load;
 * target has it after. Open rule in matching-tips (parameter spill vs load). Sibling 0x8864BBB0 differs only in offsets
 * (lock at 0x24, list at 0xc). */
/* 0x8864BAE8 (hand match): queues a value on the owner's pending list while holding the owner's lock;
 * always reports success (0). Sibling 0x8864BBB0 is the same for another queue/lock pair. */
typedef struct Lock { void *cs; } Lock;
typedef struct List { void *head; void *tail; void *last; } List;
typedef struct Obj { char p[0x38]; List pending; char p2[0x48 - 0x44]; Lock *lock; } Obj;
void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);
unsigned int ts4_if_call_seq_fn_8864DFF0_88278450(List *list, unsigned int *value);
static __forceinline void enter(Lock *l) { RtlEnterCriticalSection(l->cs); }
static __forceinline void leave(Lock *l) { RtlLeaveCriticalSection(l->cs); }
int ts4_queue_pending_value_8864BAE8(Obj *o, unsigned int value)
{
    Lock *lock = o->lock;
    enter(lock);
    ts4_if_call_seq_fn_8864DFF0_88278450(&o->pending, &value);
    leave(lock);
    return 0;
}
