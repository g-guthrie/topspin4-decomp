/* Derived from Lua 5.0.2 lstrlib.c (MIT); see THIRD_PARTY_NOTICES.md */
/* lmemfind for 16-bit strings (LuaPlus wide string library); wmemchr and wmemcmp are inlined. */
#include "lua3.h"

/* wchar.h inline wmemchr */
LUA2_FORCEINLINE const u16 *wmemchr_(const u16 *s, u16 c, u32 n)
{
    for (; 0 < n; ++s, --n)
        if (*s == c) return s;
    return 0;
}

/* wchar.h inline wmemcmp */
LUA2_FORCEINLINE int wmemcmp_(const u16 *s1, const u16 *s2, u32 n)
{
    for (; 0 < n; ++s1, ++s2, --n)
        if (*s1 != *s2) return (*s1 < *s2 ? -1 : +1);
    return 0;
}

/* lmemfind */
const u16 *lua3_wlmemfind_8882F128(const u16 *s1, u32 l1, const u16 *s2, u32 l2)
{
    if (l2 == 0) return s1; /* empty strings are everywhere */
    else if (l2 > l1)
        return 0; /* avoids a negative `l1' */
    else {
        const u16 *init; /* to search for a `*s2' inside `s1' */
        l2--;            /* 1st char will be checked by `memchr' */
        l1 = l1 - l2;    /* `s2' cannot be found after that */
        while (l1 > 0 && (init = wmemchr_(s1, *s2, l1)) != 0) {
            init++; /* 1st char is already checked */
            if (wmemcmp_(init, s2 + 1, l2) == 0)
                return init - 1;
            else { /* correct `l1' and `s1' to try again */
                l1 -= init - s1;
                s1 = init;
            }
        }
        return 0; /* not found */
    }
}
