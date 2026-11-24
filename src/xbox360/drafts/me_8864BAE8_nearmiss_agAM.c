/* agAM: 2 off (plain and LTCG). The target spills v (stw r4,0x8c) after loading o->lock; ours spills it first. Sibling 8864BBB0 is the same at +0x24/+0xC. The callee prototype is inferred from the call site. */
typedef unsigned char u8; typedef unsigned int u32;
extern void RtlEnterCriticalSection(void *section); extern void RtlLeaveCriticalSection(void *section);
extern void ts4_if_call_seq_fn_8864DFF0_88278450(void *list, const u32 *value);
typedef struct { void *cs; } Lk; typedef struct { char p[0x38]; char list[0x10]; Lk *lock; } O;
int f(O *o, u32 v){ Lk *l=o->lock; RtlEnterCriticalSection(l->cs); ts4_if_call_seq_fn_8864DFF0_88278450(o->list,&v); RtlLeaveCriticalSection(l->cs); return 0; }
