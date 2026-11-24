/* 0x8841A8B0: Frees a block allocated with a 16-byte header {magic, size, kind, offset} just before p: stamps magic 0xDEADBEEF, then releases (p - offset, size + 16, kind) through fn_8841A590. Null p is ignored. */
/* Matched on /Oc (agAH). Header as a struct indexed with (BlockHeader *)p - 1. */
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct BlockHeader { unsigned int magic; unsigned int size; int kind; unsigned int offset; } BlockHeader;
void fn_8841A8B0(void *allocator, void *p)
{
    if (p != 0) {
        BlockHeader *h = (BlockHeader *)p - 1;
        h->magic = 0xDEADBEEF;
        fn_8841A590(allocator, (char *)p - h->offset, h->size + sizeof(BlockHeader), h->kind);
    }
}
