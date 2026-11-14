/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* Altered to match Swing_DLL.xex: wide-character matchbracketclass (one jump-table function per file). */

typedef unsigned short lib3_wchar;

extern int fn_88569800(int c, int mask);
extern lib3_wchar ts4_if_fn_885677C0(int c);

#ifdef _MSC_VER
#define LIB3_FORCEINLINE static __forceinline
#else
#define LIB3_FORCEINLINE static inline
#endif

/* match_class (wide): classes through the C runtime wide ctype test. */
LIB3_FORCEINLINE int lib3_wmatch_class(int c, int cl)
{
    int res;
    switch (ts4_if_fn_885677C0(cl)) {
    case 'a': res = fn_88569800(c, 0x103); break;
    case 'c': res = fn_88569800(c, 0x20); break;
    case 'd': res = fn_88569800(c, 0x4); break;
    case 'l': res = fn_88569800(c, 0x2); break;
    case 'p': res = fn_88569800(c, 0x10); break;
    case 's': res = fn_88569800(c, 0x8); break;
    case 'u': res = fn_88569800(c, 0x1); break;
    case 'w': res = fn_88569800(c, 0x107); break;
    case 'x': res = fn_88569800(c, 0x80); break;
    case 'z': res = ((lib3_wchar)c == 0); break;
    default: return ((lib3_wchar)cl == (lib3_wchar)c);
    }
    if (fn_88569800(cl, 0x2)) return res;
    return !res;
}

/* matchbracketclass (wide) */
int lib3_wmatchbracketclass_8882F1E8(int c, const lib3_wchar *p, const lib3_wchar *ec)
{
    int sig = 1;
    if (*(p + 1) == '^') {
        sig = 0;
        p++;
    }
    while (++p < ec) {
        if (*p == '%') {
            p++;
            if (lib3_wmatch_class(c, *p)) return sig;
        }
        else if ((*(p + 1) == '-') && (p + 2 < ec)) {
            p += 2;
            if (*(p - 2) <= (lib3_wchar)c && (lib3_wchar)c <= *p) return sig;
        }
        else if (*p == (lib3_wchar)c) return sig;
    }
    return !sig;
}
