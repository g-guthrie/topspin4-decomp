/* 0x88606A88: maps flag bits 1 and 2 to a mode: 2 when both are set, 1 when only bit 2 is set, else 0, always or-ed with 0x8000. */
/* Matched on /Oc (agAB). Signed int argument (cmpwi) and r = 0 with an if/else-if chain. */
int fn_88606A88(int x)
{
    int r = 0;
    if ((x & 1) && (x & 2))
        r = 2;
    else if (!(x & 1) && (x & 2))
        r = 1;
    return r | 0x8000;
}
