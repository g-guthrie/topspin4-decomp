/* 0x88329B70: Parses a hexadecimal string (either case; other characters still shift in a zero nibble). Returns 0 for NULL. */
/* Matched on /Oc (agAH). Initialise the accumulator after the NULL check. */
unsigned int fn_88329B70(const char *s)
{
    unsigned int v;
    char c;
    if (s == 0)
        return 0;
    v = 0;
    for (c = *s; c != 0; c = *++s) {
        v <<= 4;
        if (c >= '0' && c <= '9')
            v += c - '0';
        else if (c >= 'A' && c <= 'F')
            v += c - 'A' + 10;
        else if (c >= 'a' && c <= 'f')
            v += c - 'a' + 10;
    }
    return v;
}
