/* Swing_DLL.xex 0x88493ED0: return the block pool that owns p (512-byte blocks), probing only the pool with fewer blocks
 * char flags for the size test and the ownership result; owner = (owned != 0) ^ (aSmaller != 0) ? b : a */
typedef unsigned char u8;
typedef struct BlockPool { u8 pad[0x5C]; u8 **blocks; int count; } BlockPool;

static __inline char pool_owns(BlockPool *pool, u8 *p)
{
    char found = 0;
    int i;
    for (i = 0; i < pool->count; i++) {
        u8 *b = pool->blocks[i];
        if (b <= p && p < b + 0x200) {
            found = 1;
            break;
        }
    }
    return found;
}

/* Pick the pool that owns p, testing only the smaller of the two. */
BlockPool *fn_88493ED0(u8 *p, BlockPool *a, BlockPool *b)
{
    char aSmaller = (char)(a->count <= b->count);
    BlockPool *probe = aSmaller ? a : b;
    char owned = pool_owns(probe, p);
    return ((owned != 0) ^ (aSmaller != 0)) ? b : a;
}
