/* 0x88639D48: 1 when two C strings are equal (signed char compare), 0 otherwise */
/* Matched on /Oc (agAL). Plain route. The target walks one cursor over a and reads b at the same offset (lbzx with b - a), so the source keeps a cursor p and reads b[p - a]; incrementing both pointers gives a b induction. */
unsigned char ts4_str_equal_88639D48(const char *a, const char *b)
{
    const char *p = a;
    char ca = *p;
    char cb = *b;
    while (ca != 0 && cb != 0 && ca == cb) {
        p++;
        ca = *p;
        cb = b[p - a];
    }
    return ca == 0 && cb == 0;
}
