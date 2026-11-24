/* Loader_DLL.xex 0x833F1488-0x833F1760, executable version 0.0.0.3. */
/* Library routine: CRT strtoxl (shared body of strtol / strtoul). */

typedef unsigned int ts4l_u32;

typedef struct ts4l_locinfo {
    char pad0[0xac];
    int mb_cur_max;
    char pad1[0x18];
    const unsigned short *pctype;
} ts4l_locinfo;

typedef struct ts4l_locale {
    ts4l_locinfo *locinfo;
    void *mbcinfo;
} ts4l_locale;

extern ts4l_locale lbl_8352CA04;

int *fn_833E9F90(void);
void fn_833E9D50(void);
int fn_833FAED8(int c, int mask, ts4l_locale *loc);

ts4l_u32 ts4l_strtoxl_833F1488(const char *nptr, const char **endptr, int ibase, int flags)
{
    const char *p;
    char c;
    ts4l_u32 number;
    ts4l_u32 digval;
    ts4l_u32 maxval;

    if (endptr != 0)
        *endptr = nptr;
    if (nptr == 0) {
        *fn_833E9F90() = 22;
        fn_833E9D50();
        return 0;
    }
    if (ibase != 0 && (ibase < 2 || ibase > 36)) {
        *fn_833E9F90() = 22;
        fn_833E9D50();
        return 0;
    }
    p = nptr;
    number = 0;
    c = *p++;
    while ((lbl_8352CA04.locinfo->mb_cur_max > 1)
               ? fn_833FAED8((unsigned char)c, 8, &lbl_8352CA04)
               : (lbl_8352CA04.locinfo->pctype[(unsigned char)c] & 8))
        c = *p++;
    if (c == '-') {
        flags |= 2;
        c = *p++;
    } else if (c == '+') {
        c = *p++;
    }
    if (ibase < 0 || ibase == 1 || ibase > 36) {
        if (endptr != 0)
            *endptr = nptr;
        return 0;
    } else if (ibase == 0) {
        if (c != '0')
            ibase = 10;
        else if (*p == 'x' || *p == 'X') {
            ibase = 16;
            goto hex;
        } else
            ibase = 8;
    }
    if (ibase == 16) {
hex:
        if (c == '0' && (*p == 'x' || *p == 'X')) {
            ++p;
            c = *p++;
        }
    }
    maxval = 0xffffffffu / (ts4l_u32)ibase;
    for (;;) {
        int ct = lbl_8352CA04.locinfo->pctype[(unsigned char)c];
        if (ct & 4) {
            digval = c - '0';
        } else if (ct & 0x103) {
            int t = c;
            if (t >= 'a' && t <= 'z')
                t -= 0x20;
            digval = t - 'A' + 10;
        } else {
            break;
        }
        if (digval >= (ts4l_u32)ibase)
            break;
        flags |= 8;
        if (number < maxval || (number == maxval && digval <= 0xffffffffu % (ts4l_u32)ibase)) {
            number = number * ibase + digval;
        } else {
            flags |= 4;
            if (endptr == 0)
                break;
        }
        c = *p++;
    }
    --p;
    if (!(flags & 8)) {
        if (endptr != 0)
            p = nptr;
        number = 0;
    } else if ((flags & 4) ||
               (!(flags & 1) && (((flags & 2) && number > 0x80000000u) ||
                                 (!(flags & 2) && number > 0x7fffffffu)))) {
        *fn_833E9F90() = 34;
        if (flags & 1)
            number = 0xffffffffu;
        else if (flags & 2)
            number = 0x80000000u;
        else
            number = 0x7fffffffu;
    }
    if (endptr != 0)
        *endptr = p;
    if (flags & 2)
        number = (ts4l_u32)(-(int)number);
    return number;
}
