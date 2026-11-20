/* 0x88288628: Refines the low-nibble format code. Kind 3 maps mode bits 9-10 (3/2/0) to 0x12/0x11/0x14, or to 0x13 if caps has 0x400. Kind 4 with flag 0x40000000 and surface bits (0x600)==0x400 maps to 0x10. Otherwise the code is unchanged. */
/* Matched on /O1 (agAH). Else-if chain on a result local. */
typedef struct Surf { char p0[0x30]; unsigned int bits; } Surf;
typedef struct Desc { unsigned int flags; char p4[0x14]; Surf *surf; char p1c[4]; unsigned int caps; char p24[0xc]; unsigned int mode; } Desc;
unsigned int fn_88288628(const Desc *d)
{
    unsigned int fmt = d->flags & 0xF;
    if (fmt == 3) {
        unsigned int m = (d->mode >> 9) & 3;
        if (m == 3)
            fmt = 0x12;
        else if (m == 2)
            fmt = 0x11;
        else if (m == 0)
            fmt = 0x14;
        else if (d->caps & 0x400)
            fmt = 0x13;
    } else if (fmt == 4 && (d->flags & 0x40000000) && (d->surf->bits & 0x600) == 0x400)
        fmt = 0x10;
    return fmt;
}
