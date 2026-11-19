/* 0x8841E750: refcounted wrapper init: vtable lbl_8803DE28, refs 1, allocates a 0x1C block (tag 0x1A) from the thread heap in TLS slot lbl_88CACF08, sets its size field and stores the object built by ts4_if_call_seq_u32_off10_88425FA0 */
/* Matched on /Oc (agAH). The heap is held in a block-scoped local; passing KeTlsGetValue inline swaps the li order of the size and tag. */
extern void *lbl_8803DE28;
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int idx);
typedef struct Blk { int a; short size; } Blk;
Blk *fn_8841A510(void *heap, unsigned int size, unsigned int tag);
void *ts4_if_call_seq_u32_off10_88425FA0(Blk *b, void *a, void *c, int kind);
typedef struct RefW { void *vtable; short unk4; short refs; void *impl; } RefW;
RefW *fn_8841E750(RefW *o, void *a, void *c)
{
    Blk *b;
    o->refs = 1;
    o->vtable = &lbl_8803DE28;
    {
        void *heap = KeTlsGetValue(lbl_88CACF08);
        b = fn_8841A510(heap, 0x1c, 0x1a);
    }
    b->size = 0x1c;
    o->impl = ts4_if_call_seq_u32_off10_88425FA0(b, a, c, 2);
    return o;
}
