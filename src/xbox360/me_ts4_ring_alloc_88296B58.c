/* 0x88296B58: allocates the 64-slot ring (+0x5EA8, tags 0x80000000 and guard 0x0BADD00D), its context (+0x5EB0), the head word (+0x5EC8) and two 0xFC-byte tables (+0x5EC0/+0x5EC4), freeing what was allocated on failure */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); returns 1 on success; the tested allocations use if (!(x = alloc())) where the target tests before the store. */
typedef struct Slot { unsigned int tag; unsigned int guard; char pad[0x78]; } Slot;
typedef struct T { char pad[0x5EA8]; Slot *ring; int p5eac; void *ctx; char p5eb4[0x5EC0 - 0x5EB4]; unsigned int *a; void *b; unsigned int *head; } T;
void *fn_88888668(unsigned int size, unsigned int tag);
void ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(void *p, unsigned int tag);
int ts4_ring_alloc_88296B58(T *t)
{
    int i;
    if (!(t->ring = (Slot *)fn_88888668(0x2000, 0xb5800000))) return 0;
    t->ctx = fn_88888668(0x4ec, 0x64800000);
    if (!t->ctx) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(t->ring, 0xb1800000);
        t->ring = 0;
        return 0;
    }
    for (i = 0; i < 63; ++i) {
        t->ring[i].tag = 0x80000000;
        t->ring[i].guard = 0x0badd00d;
    }
    t->ring[63].tag = 0x80000000;
    if (!(t->head = (unsigned int *)fn_88888668(4, 0xb5800000))) return 0;
    *t->head = 0x80000000;
    if (!(t->a = (unsigned int *)fn_88888668(0xfc, 0xb5800000))) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(t->head, 0xb1800000);
        t->head = 0;
        return 0;
    }
    t->b = fn_88888668(0xfc, 0x64800000);
    if (!t->b) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(t->head, 0xb1800000);
        t->head = 0;
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(t->a, 0xb1800000);
        t->a = 0;
        return 0;
    }
    return 1;
}
