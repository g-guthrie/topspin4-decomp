/* Loader_DLL.xex 0x833E53C0-0x833E563C, executable version 0.0.0.3. */
/* MSVC CRT wide-character strtol/strtoul core (xtoxl). */
#define FL_UNSIGNED 1
#define FL_NEG      2
#define FL_OVERFLOW 4
#define FL_READDIGIT 8

extern int fn_833F5188(unsigned short c, int type);
extern int fn_833F5230(unsigned short c);
extern int *ts4_if_call_seq_fn_833E8350_833E9F90(void);
extern void fn_833E9D50(void);

unsigned long ts4l_wcstoxl_833E53C0(const unsigned short *nptr, const unsigned short **endptr, int ibase, int flags)
{
    const unsigned short *p;
    unsigned short c;
    unsigned long number;
    unsigned int digval;
    unsigned long maxval;

    if (endptr != 0)
        *endptr = nptr;
    if (nptr == 0) {
        *ts4_if_call_seq_fn_833E8350_833E9F90() = 22;
        fn_833E9D50();
        return 0;
    }
    if (ibase != 0 && (ibase < 2 || ibase > 36)) {
        *ts4_if_call_seq_fn_833E8350_833E9F90() = 22;
        fn_833E9D50();
        return 0;
    }
    c = *nptr;
    number = 0;
    p = nptr + 1;
    while (fn_833F5188(c, 8) != 0)
        c = *p++;
    if (c == '-') {
        flags |= FL_NEG;
        c = *p++;
    } else if (c == '+') {
        c = *p++;
    }
    if (ibase == 0) {
        if (fn_833F5230(c) != 0)
            ibase = 10;
        else if (*p == 'x' || *p == 'X')
            ibase = 16;
        else
            ibase = 8;
    }
    if (ibase == 16) {
        if (fn_833F5230(c) == 0 && (*p == 'x' || *p == 'X')) {
            ++p;
            c = *p++;
        }
    }
    maxval = 0xFFFFFFFFUL / (unsigned long)ibase;
    for (;;) {
        digval = fn_833F5230(c);
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
        *ts4_if_call_seq_fn_833E8350_833E9F90() = 34;
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
