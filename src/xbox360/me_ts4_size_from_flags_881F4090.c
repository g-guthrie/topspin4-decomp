/* 0x881F4090: byte size implied by a flag word: 0xC for bit 1, 0x24 for bit 2, bit 0 adds both plus 0x24, 0x30 for bit 3 and 0xC for bit 4 */
/* Matched on /Oc (agAH). Bit 0 kept in an unsigned char local tested in each condition; early return when it is clear. */
int fn_881F4090(unsigned int flags)
{
    int size = 0;
    unsigned char all = (unsigned char)(flags & 1);
    if ((flags & 2) || all)
        size = 0xc;
    if ((flags & 4) || all)
        size += 0x24;
    if (!all)
        return size;
    size += 0x24;
    if (flags & 8)
        size += 0x30;
    if (flags & 0x10)
        size += 0xc;
    return size;
}
