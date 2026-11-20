/* NEAR MISS (agAD, b169): /O1, ~70 off from register allocation only: the target keeps dev in r30 and gives pend and the image cursor p
 * both r31 (p stays in r31 through the skip loop). Logic, offsets and the packet bitfield store already match. Sibling of 882909B0. */
/* Swing_DLL.xex 0x88290D58: binds a recorded state block to the GPU device: flushes the pending block (fence write
 * or a 8-byte ring packet), clears the low bit of +0x2ABE, and replays the block's register image into regs+0x480:
 * plain copies (memcpy runs), then masked runs ((reg & and) | or). agAD: /O1. */
typedef unsigned __int64 u64;
typedef struct Packet { unsigned int b0 : 1; unsigned int b1 : 1; unsigned int addr : 30; unsigned int tag; } Packet;
typedef struct Pending { unsigned int mask; int pad4; void *fence; } Pending;
typedef struct Image { u64 clear; u64 dirty; unsigned int size; } Image;
typedef struct Block { char pad0[0x14]; unsigned int image; } Block;
typedef struct StateBlock { char pad0[0x368]; Block blk; } StateBlock;
typedef struct Dev {
    u64 mask; int pad8[2]; u64 flags10; int pad18[2]; u64 dirty20; char pad28[0x480 - 0x28]; unsigned char regs[0x2a9c - 0x480];
    void *fence; unsigned int fence_mask; char pad2aa4[0x2abe - 0x2aa4]; unsigned char state; char pad2abf[0x3248 - 0x2abf];
    StateBlock *bound; char pad324c[0x35a8 - 0x324c]; Packet *ring; Packet *ring_end;
} Dev;
void *memcpy(void *d, const void *s, unsigned int n);
Packet *fn_8829BA90(Dev *d);

void fn_88290D58(Dev *d, StateBlock *sb)
{
    Pending *pend;
    Block *b;
    Image *img;
    const unsigned short *p, *end;
    unsigned char *regs;
    if (sb)
        d->flags10 |= 0x80000;
    pend = (Pending *)d->bound;
    if (pend) {
        if (d->fence)
            pend->fence = d->fence;
        else if (d->fence_mask & pend->mask) {
            Packet *pk = d->ring;
            Packet v;
            if (pk >= d->ring_end)
                pk = fn_8829BA90(d);
            v.addr = (unsigned int)pend >> 2;
            v.b1 = 0;
            v.tag = 0xffffffff;
            *pk = v;
            d->ring = pk + 1;
        }
    }
    d->bound = sb;
    d->state &= 0x7f;
    if (!sb)
        return;
    b = &sb->blk;
    if (!b || !b->image)
        return;
    img = (Image *)((char *)b + b->image);
    d->mask &= ~img->clear;
    if (img->dirty)
        d->dirty20 |= 1ull << 56;
    p = (const unsigned short *)((char *)img + 0x14);
    regs = d->regs;
    end = (const unsigned short *)((const char *)p + img->size);
    while (p < end) {
        unsigned short n = p[1];
        p += 2;
        if (!n)
            break;
        p += 2;
    }
copy:
    while (p < end) {
        unsigned short n = p[1], off = p[0];
        p += 2;
        if (!n)
            goto masked;
        memcpy(regs + off, p, n * 4);
        p = (const unsigned short *)((const char *)p + n * 4);
    }
    return;
masked:
    while (p < end) {
        unsigned short n = p[1], off = p[0];
        unsigned int *r;
        p += 2;
        if (!n)
            return;
        r = (unsigned int *)(regs + off) - 1;
        do {
            const unsigned int *w = (const unsigned int *)p;
            *++r = (r[1] & w[0]) | w[1];
            p += 4;
        } while (--n);
    }
}
