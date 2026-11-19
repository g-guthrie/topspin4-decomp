/* 0x882CE298: twin of 882B1548 (another texture unit): copies image b's surface data from a when compatible (flags equal except 0x1C0, a not busy, same w/h/depth/lock, same 0x400-byte palette when paletted); a level-less b goes to 882CDB30; E_FAIL otherwise. Declaring b before a fixes the xor operand order */
/* Matched on /O1 plain and LTCG (agX, v.py chk). */
void *memcpy(void *, const void *, unsigned long);
int memcmp(const void *, const void *, unsigned long);
typedef struct Img {
    int p0;
    unsigned int flags;
    int p8;
    int levels;
    int lock;
    int p14;
    int busy;
    int paletted;
    char *bits;
    char pad24[0x38 - 0x24];
    unsigned char *pal;
    char pad3c[0x60 - 0x3c];
    unsigned int pitch;
    unsigned int slice;
    unsigned int w;
    unsigned int h;
    unsigned int d;
    unsigned int rowbytes;
} Img;
typedef struct Pair { Img *a; Img *b; } Pair;
int fn_882CDB30(Pair *p);

int fn_882CE298(Pair *p)
{
    Img *b = p->b, *a = p->a;
    unsigned int z, y;
    if ((a->flags ^ b->flags) & ~0x1c0)
        return 0x80004005;
    if (a->busy)
        return 0x80004005;
    if (b->w != a->w || b->h != a->h || b->d != a->d || b->lock != a->lock)
        return 0x80004005;
    if (!b->levels)
        return fn_882CDB30(p);
    if (b->paletted && b->pal != a->pal) {
        if (memcmp(b->pal, a->pal, 0x400))
            return 0x80004005;
    }
    b->lock = 0;
    p->a->lock = 0;
    for (z = 0; z < p->b->d; z++) {
        char *dst = p->b->bits + p->b->slice * z;
        char *src = p->a->bits + p->a->slice * z;
        for (y = 0; y < p->b->h; y++) {
            memcpy(dst, src, p->b->rowbytes);
            dst += p->b->pitch;
            src += p->a->pitch;
        }
    }
    return 0;
}
