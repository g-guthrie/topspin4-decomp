/* Loader_DLL.xex 0x833FBC80-0x833FBF4C, executable version 0.0.0.3. */
/* Library routine: CRT _wcstombs_l_helper (wide to multibyte conversion). */

typedef unsigned int ts4l_size_t;
typedef unsigned short ts4l_wchar;

typedef struct ts4l_locinfo {
    int pad0;
    int codepage;
    char pad1[0xc];
    unsigned int ctype_handle;
    char pad2[0x94];
    int mb_cur_max;
} ts4l_locinfo;

typedef struct ts4l_locale {
    ts4l_locinfo *locinfo;
    void *mbcinfo;
} ts4l_locale;

extern ts4l_locale lbl_8352CA04;

int *fn_833E9F90(void);
void fn_833E9D50(void);
int fn_8340F118(int codepage, int flags, const ts4l_wchar *wide, int cchwide, char *mb,
                int cchmb, const char *defchar, int *used_default);
unsigned int fn_8340D118(void);

ts4l_size_t ts4l_wcstombs_833FBC80(char *s, const ts4l_wchar *pwcs, ts4l_size_t n)
{
    ts4l_size_t count = 0;
    int i;
    int retval;
    int defused = 0;
    char buffer[5];

    if (s && n == 0)
        return 0;
    if (pwcs == 0) {
        *fn_833E9F90() = 22;
        fn_833E9D50();
        return (ts4l_size_t)-1;
    }
    if (s) {
        if (lbl_8352CA04.locinfo->ctype_handle == 0) {
            while (count < n) {
                if (*pwcs > 255) {
                    *fn_833E9F90() = 42;
                    return (ts4l_size_t)-1;
                }
                s[count] = (char)*pwcs;
                if (*pwcs++ == 0)
                    return count;
                count++;
            }
            return count;
        } else {
            if (lbl_8352CA04.locinfo->mb_cur_max == 1) {
                const ts4l_wchar *q;
                ts4l_size_t rem;
                if (n != 0) {
                    q = pwcs;
                    rem = n;
                    while (rem != 0 && *q != 0) {
                        rem--;
                        q++;
                    }
                    if (rem != 0 && *q == 0)
                        n = (ts4l_size_t)(q - pwcs) + 1;
                }
                count = fn_8340F118(lbl_8352CA04.locinfo->codepage, 0, pwcs, (int)n, s, (int)n, 0,
                                    &defused);
                if (count != 0 && !defused) {
                    if (s[count - 1] == 0)
                        count--;
                    return count;
                }
                *fn_833E9F90() = 42;
                return (ts4l_size_t)-1;
            } else {
                if ((count = fn_8340F118(lbl_8352CA04.locinfo->codepage, 0, pwcs, -1, s, (int)n, 0,
                                         &defused)) != 0 &&
                    !defused)
                    return count - 1;
                if (defused || fn_8340D118() != 122) {
                    *fn_833E9F90() = 42;
                    return (ts4l_size_t)-1;
                }
                while (count < n) {
                    retval = fn_8340F118(lbl_8352CA04.locinfo->codepage, 0, pwcs, 1, buffer,
                                         lbl_8352CA04.locinfo->mb_cur_max, 0, &defused);
                    if (retval == 0 || defused) {
                        *fn_833E9F90() = 42;
                        return (ts4l_size_t)-1;
                    }
                    if (retval < 0 || (ts4l_size_t)retval > 5) {
                        *fn_833E9F90() = 42;
                        return (ts4l_size_t)-1;
                    }
                    if (count + retval > n)
                        return count;
                    for (i = 0; i < retval; i++, count++) {
                        if ((s[count] = buffer[i]) == 0)
                            return count;
                    }
                    pwcs++;
                }
                return count;
            }
        }
    } else {
        if (lbl_8352CA04.locinfo->ctype_handle == 0) {
            count = 0;
            while (*pwcs != 0) {
                if (*pwcs > 255) {
                    *fn_833E9F90() = 42;
                    return (ts4l_size_t)-1;
                }
                pwcs++;
                count++;
            }
            return count;
        }
        count = fn_8340F118(lbl_8352CA04.locinfo->codepage, 0, pwcs, -1, 0, 0, 0, &defused);
        if (count == 0 || defused) {
            *fn_833E9F90() = 42;
            return (ts4l_size_t)-1;
        }
        return count - 1;
    }
}
