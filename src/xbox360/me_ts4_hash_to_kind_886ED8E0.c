/* 0x886ED8E0: maps four name hashes to kinds 0/1/2 and (kind arg 2 ? 1 : 4), default 1 */
/* Matched on /Oc (agAH). Result local defaulting to 1 with an else-if chain in the target's compare order; the redundant 'r = 1' arm is what gives the separate li r3,1 block. */
int fn_886ED8E0(unsigned int hash, unsigned int kind)
{
    int r = 1;
    if (hash == 0x40F13194u)
        r = 0;
    else if (hash == 0xFD267F35u)
        r = 1;
    else if (hash == 0x4905ED7Bu)
        r = 2;
    else if (hash == 0x538050CEu)
        r = kind == 2 ? 1 : 4;
    return r;
}
