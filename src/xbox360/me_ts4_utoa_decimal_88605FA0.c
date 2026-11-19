/* 0x88605FA0: write an unsigned int as a decimal string into out (digits built backwards in a 10-byte stack buffer, then copied with the terminator) */
/* Matched on /Oc (agAL). Plain route. A separate n = value local gives the target mr r10,r3; the digit is n - q * 10 from the quotient; the copy loop walks the source and stores to out[s - p] (stbx with out - s). */
void ts4_utoa_decimal_88605FA0(unsigned int value, char *out)
{
    char buf[10];
    char *p = &buf[9];
    char *s;
    char c;
    unsigned int n = value;
    *p = 0;
    do {
        unsigned int q = n / 10;
        *--p = (char)('0' + (n - q * 10));
        n = q;
    } while (n != 0);
    s = p;
    do {
        c = *s;
        out[s - p] = c;
        s++;
    } while (c != 0);
}
