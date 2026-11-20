/* near miss 886F3350 (2 off, /Oc plain: the tag store is scheduled after the a.x reload; target stores the tag first). */
/* Swing_DLL.xex 0x886F3350: stamp a block's tag and copy two by-value 3-int triples into it. */
typedef struct Ts4Int3 { int x, y, z; } Ts4Int3;
typedef struct Ts4TripleBlock { int pad0; unsigned int tag; char pad[0x34]; Ts4Int3 a; Ts4Int3 b; } Ts4TripleBlock;
void ts4_triple_block_set_886F3350(Ts4TripleBlock *blk, Ts4Int3 a, Ts4Int3 b)
{
    blk->tag = 0x29BFB37F;
    blk->a = a;
    blk->b = b;
}
