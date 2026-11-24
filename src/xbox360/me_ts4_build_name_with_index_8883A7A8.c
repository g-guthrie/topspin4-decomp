/* Swing_DLL.xex 0x8883A7A8: interns literal lbl_880E14A8 followed by the decimal index: itoa into a 16-byte buffer, bounded copy of the literal into a 124-byte buffer, strncat the number, then 88608590(0, buf) into *out.
 * /Oc. Set the literal and buffer pointers after the itoa call; `124 - (int)strlen(buf)` gives the clrrwi. */
unsigned int strlen(const char *s);
char *ts4_crt_itoa_8856BD18(int val, char *buf, int radix);
char *ts4_crt_strncat_88564EF0(char *dst, const char *src, unsigned int count);
int ts4_crc32_cstr_seed_88608590(int, const char *);
extern char lbl_880E14A8[];

int *fn_8883A7A8(int *out, int index)
{
    char num[16];
    char buf[124];
    const char *s;
    char *d;
    ts4_crt_itoa_8856BD18(index, num, 10);
    s = lbl_880E14A8;
    d = buf;
    while (d != buf + 124) {
        char c = *s;
        if (!c)
            break;
        *d = c;
        d++;
        s++;
    }
    *d = 0;
    ts4_crt_strncat_88564EF0(buf, num, 124 - (int)strlen(buf));
    *out = ts4_crc32_cstr_seed_88608590(0, buf);
    return out;
}
