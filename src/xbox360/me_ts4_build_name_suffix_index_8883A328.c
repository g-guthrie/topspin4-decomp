/* Swing_DLL.xex 0x8883A328: interns literal lbl_880E1064 + optional suffix + separator lbl_880DFE48 + decimal index (itoa), all bounded to a 124-byte buffer, via 88608590(0, buf) into *out.
 * /Oc. Each strncat room is `124 - (int)strlen(buf)` (clrrwi). */
unsigned int strlen(const char *s);
char *ts4_crt_itoa_8856BD18(int val, char *buf, int radix);
char *ts4_crt_strncat_88564EF0(char *dst, const char *src, unsigned int count);
int ts4_crc32_cstr_seed_88608590(int, const char *);
extern char lbl_880E1064[];
extern char lbl_880DFE48[];

int *fn_8883A328(int *out, const char *suffix, int index)
{
    char num[16];
    char buf[124];
    const char *s;
    char *d;
    ts4_crt_itoa_8856BD18(index, num, 10);
    s = lbl_880E1064;
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
    if (suffix)
        ts4_crt_strncat_88564EF0(buf, suffix, 124 - (int)strlen(buf));
    ts4_crt_strncat_88564EF0(buf, lbl_880DFE48, 124 - (int)strlen(buf));
    ts4_crt_strncat_88564EF0(buf, num, 124 - (int)strlen(buf));
    *out = ts4_crc32_cstr_seed_88608590(0, buf);
    return out;
}
