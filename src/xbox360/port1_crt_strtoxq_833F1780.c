/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l8_crt_strtoxq_833F1780.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* Library routine: CRT strtoxq (64-bit body of _strtoi64 / _strtoui64). */

typedef unsigned int ts4_u32;
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif

typedef struct ts4_locinfo {
    char pad0[0xac];
    int mb_cur_max;
    char pad1[0x18];
    const unsigned short *pctype;
} ts4_locinfo;

typedef struct ts4_locale {
    ts4_locinfo *locinfo;
    void *mbcinfo;
} ts4_locale;

extern ts4_locale lbl_88C31878;
int *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
void fn_8856D2C0(void);
int ts4_if_get_u32_lbl_88C31878_88567FD8(int c, int mask, ts4_locale *loc);

/* Swing_DLL.xex 0x88570320 */
ts4_u64 ts4_strtoxq_88570320(const char *nptr, const char **endptr, int ibase, int flags)
{
    const char *p;
    char c;
    ts4_u64 number;
    ts4_u32 digval;
    ts4_u64 maxval;

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
    p = nptr;
    number = 0;
    c = *p++;
    while ((lbl_88C31878.locinfo->mb_cur_max > 1)
               ? ts4_if_get_u32_lbl_88C31878_88567FD8((unsigned char)c, 8, &lbl_88C31878)
               : (lbl_88C31878.locinfo->pctype[(unsigned char)c] & 8))
        c = *p++;
    if (c == '-') {
        flags |= 2;
        c = *p++;
    } else if (c == '+') {
        c = *p++;
    }
    if (ibase == 0) {
        if (c != '0')
            ibase = 10;
        else if (*p == 'x' || *p == 'X')
            ibase = 16;
        else
            ibase = 8;
    }
    if (ibase == 16) {
        if (c == '0' && (*p == 'x' || *p == 'X')) {
            ++p;
            c = *p++;
        }
    }
    maxval = 0xffffffffffffffffull / (ts4_u64)ibase;
    for (;;) {
        int ct = lbl_88C31878.locinfo->pctype[(unsigned char)c];
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
        if (digval >= (ts4_u32)ibase)
            break;
        flags |= 8;
        if (number < maxval || (number == maxval && (ts4_u64)digval <= 0xffffffffffffffffull % (ts4_u64)ibase)) {
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
               (!(flags & 1) && (((flags & 2) && number > 0x8000000000000000ull) ||
                                 (!(flags & 2) && number > 0x7fffffffffffffffull)))) {
        *ts4_if_call_seq_fn_8856CD88_88567ED8() = 34;
        if (flags & 1)
            number = 0xffffffffffffffffull;
        else if (flags & 2)
            number = 0x8000000000000000ull;
        else
            number = 0x7fffffffffffffffull;
    }
    if (endptr != 0)
        *endptr = p;
    if (flags & 2)
        number = (ts4_u64)(-(long long)number);
    return number;
}

