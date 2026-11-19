/* 0x8841A710: Pops the top frame: restores the 16-byte state at +0x20 from the header just below top (+0x28), then releases header..end (+0x2c) through fn_8841A590 with kind 0x17. */
/* Matched on /Oc (agAH). Restoring the state as one 16-byte struct copy gives the dead mr r9,r3 and the ld/std pairs; field-by-field u64 copies are 11 off. */
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct FrameHeader { unsigned long long saved0; unsigned long long saved1; } FrameHeader;
typedef struct FrameAllocator {
    char pad0[0x20];
    union {
        FrameHeader state;
        struct { char pad[8]; char *top; char *end; } s;
    } u;
} FrameAllocator;
void fn_8841A710(FrameAllocator *a)
{
    char *top = a->u.s.top;
    char *end = a->u.s.end;
    FrameHeader *h = (FrameHeader *)(top - sizeof(FrameHeader));
    a->u.state = *h;
    fn_8841A590(a, h, (unsigned int)(end - top) + sizeof(FrameHeader), 0x17);
}
