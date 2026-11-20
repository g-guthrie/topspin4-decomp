/* Swing_DLL.xex 0x8856BC88-0x8856BD58, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: xtoa and _itoa. */
typedef unsigned int u32;

#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_crt_xtoa_8856BC88(u32 val, char *buf, u32 radix, int is_neg)
{
    char *p = buf;
    char *firstdig;
    char temp;
    u32 digval;
    if (is_neg) {
        *p++ = '-';
        val = (u32)(-(int)val);
    }
    firstdig = p;
    do {
        digval = val % radix;
        val /= radix;
        if (digval > 9)
            *p++ = (char)(digval - 10 + 'a');
        else
            *p++ = (char)(digval + '0');
    } while (val > 0);
    *p-- = 0;
    do {
        temp = *p;
        *p = *firstdig;
        *firstdig = temp;
        --p;
        ++firstdig;
    } while (firstdig < p);
}

char *ts4_crt_itoa_8856BD18(int val, char *buf, int radix)
{
    if (radix == 10 && val < 0)
        ts4_crt_xtoa_8856BC88((u32)val, buf, radix, 1);
    else
        ts4_crt_xtoa_8856BC88((u32)val, buf, radix, 0);
    return buf;
}
