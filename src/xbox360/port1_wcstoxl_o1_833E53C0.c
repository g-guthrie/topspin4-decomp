/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l18_wcstoxl_o1_833E53C0.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* MSVC CRT wide-character strtol/strtoul core (xtoxl). */
#define FL_UNSIGNED 1
#define FL_NEG      2
#define FL_OVERFLOW 4
#define FL_READDIGIT 8

extern int fn_88569800(unsigned short c, int type);
extern int fn_88578BE0(unsigned short c);
extern int *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(void);

/* Swing_DLL.xex 0x88575668 */
unsigned long ts4_wcstoxl_88575668(const unsigned short *nptr, const unsigned short **endptr, int ibase, int flags)
{
    const unsigned short *p;
    unsigned short c;
    unsigned long number;
    unsigned int digval;
    unsigned long maxval;

    if (endptr != 0)
        *endptr = nptr;
    if (nptr == 0) {
        *ts4_if_call_seq_fn_8856CD88_88567ED8() = 22;
        fn_8856D2C0();
        return 0;
    }
    if (ibase != 0 && (ibase < 2 || ibase > 36)) {
        *ts4_if_call_seq_fn_8856CD88_88567ED8() = 22;
        fn_8856D2C0();
        return 0;
    }
    c = *nptr;
    number = 0;
    p = nptr + 1;
    while (fn_88569800(c, 8) != 0)
        c = *p++;
    if (c == '-') {
        flags |= FL_NEG;
        c = *p++;
    } else if (c == '+') {
        c = *p++;
    }
    if (ibase == 0) {
        if (fn_88578BE0(c) != 0)
            ibase = 10;
        else if (*p == 'x' || *p == 'X')
            ibase = 16;
        else
            ibase = 8;
    }
    if (ibase == 16) {
        if (fn_88578BE0(c) == 0 && (*p == 'x' || *p == 'X')) {
            ++p;
            c = *p++;
        }
    }
    maxval = 0xFFFFFFFFUL / (unsigned long)ibase;
    for (;;) {
        digval = fn_88578BE0(c);
        if (digval == (unsigned int)-1) {
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                unsigned int t = c;
                if (t >= 'a' && t <= 'z')
                    t -= 0x20;
                digval = t - 'A' + 10;
            } else {
                break;
            }
        }
        if (digval >= (unsigned int)ibase)
            break;
        flags |= FL_READDIGIT;
        if (number < maxval || (number == maxval && digval <= 0xFFFFFFFFUL % (unsigned long)ibase)) {
            number = number * ibase + digval;
        } else {
            flags |= FL_OVERFLOW;
            if (endptr == 0)
                break;
        }
        c = *p++;
    }
    --p;
    if (!(flags & FL_READDIGIT)) {
        if (endptr != 0)
            p = nptr;
        number = 0;
    } else if ((flags & FL_OVERFLOW) ||
               (!(flags & FL_UNSIGNED) &&
                (((flags & FL_NEG) && number > 0x80000000UL) ||
                 (!(flags & FL_NEG) && number > 0x7FFFFFFFUL)))) {
        *ts4_if_call_seq_fn_8856CD88_88567ED8() = 34;
        if (flags & FL_UNSIGNED)
            number = 0xFFFFFFFFUL;
        else if (flags & FL_NEG)
            number = 0x80000000UL;
        else
            number = 0x7FFFFFFFUL;
    }
    if (endptr != 0)
        *endptr = p;
    if (flags & FL_NEG)
        number = (unsigned long)(-(long)number);
    return number;
}

