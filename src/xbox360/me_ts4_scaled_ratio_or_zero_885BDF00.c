/* 0x885BDF00: returns (u16)(2a/b - 12) when a >= 7b, else 0. */
/* Matched on /Oc (agAB). Taken path written first; b*8-b keeps the shift/subtract form. */
unsigned short fn_885BDF00(unsigned short a, unsigned short b)
{
    if ((int)a >= b * 8 - b)
        return (unsigned short)(a * 2 / b - 12);
    return 0;
}
