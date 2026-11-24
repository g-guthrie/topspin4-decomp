/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* Altered to match Swing_DLL.xex. lstrlib.c matchbracketclass (one jump-table function per file). */

const unsigned short *ts4_get_u32_lbl_88C311F4_88567FC8(void);
int ts4_if_fn_88567730(int c);

#ifdef _MSC_VER
#define LIB3_FORCEINLINE static __forceinline
#else
#define LIB3_FORCEINLINE static inline
#endif

/* match_class: character class letters through the C runtime ctype table. */
LIB3_FORCEINLINE int lib3_match_class(int c, int cl)
{
    int res;
    switch (ts4_if_fn_88567730(cl)) {
    case 'a': res = ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x103; break;
    case 'c': res = ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x20; break;
    case 'd': res = ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x4; break;
    case 'l': res = ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x2; break;
    case 'p': res = ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x10; break;
    case 's': res = ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x8; break;
    case 'u': res = ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x1; break;
    case 'w': res = ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x107; break;
    case 'x': res = ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x80; break;
    case 'z': res = (c == 0); break;
    default: return (cl == c);
    }
    if (ts4_get_u32_lbl_88C311F4_88567FC8()[cl] & 0x2) return res;
    return !res;
}

/* matchbracketclass: test c against a [set] spanning p..ec. */
int lib3_matchbracketclass_88825118(int c, const char *p, const char *ec)
{
    int sig = 1;
    if (*(p + 1) == '^') {
        sig = 0;
        p++;
    }
    while (++p < ec) {
        if (*p == '%') {
            p++;
            if (lib3_match_class(c, *p)) return sig;
        }
        else if ((*(p + 1) == '-') && (p + 2 < ec)) {
            p += 2;
            if ((unsigned char)*(p - 2) <= c && c <= (unsigned char)*p) return sig;
        }
        else if ((unsigned char)*p == c) return sig;
    }
    return !sig;
}
