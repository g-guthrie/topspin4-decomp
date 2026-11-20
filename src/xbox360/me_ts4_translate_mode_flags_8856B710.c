/* 0x8856B710: Translates a packed flag word: low 2 bits pick 0x300/0x200/0x100, bits 3-7 map to bits 0-4, and 0x80000 is always set. */
/* Matched on /O1 (agAH). Nested if on the 2-bit mode. */
unsigned int fn_8856B710(unsigned int f)
{
    unsigned int r = 0;
    unsigned int m = f & 3;
    if (m != 0) {
        if (m == 1) r = 0x300;
        else if (m == 2) r = 0x200;
        else if (m == 3) r = 0x100;
    }
    if (f & 0x8) r |= 0x1;
    if (f & 0x20) r |= 0x2;
    if (f & 0x40) r |= 0x4;
    if (f & 0x10) r |= 0x8;
    if (f & 0x80) r |= 0x10;
    return r | 0x80000;
}
