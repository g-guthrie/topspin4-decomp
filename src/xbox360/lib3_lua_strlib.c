/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* Altered to match Swing_DLL.xex. lstrlib.c helpers and byte-order utilities linked next to it. */
#ifdef _MSC_VER
extern int memcmp(const void *a, const void *b, unsigned int n);
#else
#include <string.h>
#endif

extern void *fn_88569CF0(const void *s, int c, unsigned int n);

/* Swap each pair of bytes in place (16-bit byte swap of n units). */
void lib3_swap_byte_pairs_88824DA0(unsigned char *p, unsigned int n)
{
    while (n--) {
        unsigned char t = p[0];
        p[0] = p[1];
        p[1] = t;
        p += 2;
    }
}

/* Reverse the order of n bytes in place. */
void lib3_reverse_bytes_88824DC8(unsigned char *p, unsigned int n)
{
    unsigned int i, j;
    for (i = 0, j = n - 1, n = n / 2; n--; i++, j--) {
        unsigned char t = p[i];
        p[i] = p[j];
        p[j] = t;
    }
}

/* lmemfind: find the block s2[0..l2) inside s1[0..l1). */
const char *lib3_lmemfind_88824E78(const char *s1, unsigned int l1, const char *s2, unsigned int l2)
{
    if (l2 == 0) return s1;
    else if (l2 > l1) return 0;
    else {
        const char *init;
        l2--;
        l1 = l1 - l2;
        while (l1 > 0 && (init = (const char *)fn_88569CF0(s1, *s2, l1)) != 0) {
            init++;
            if (memcmp(init, s2 + 1, l2) == 0)
                return init - 1;
            else {
                l1 -= init - s1;
                s1 = init;
            }
        }
        return 0;
    }
}

/* MatchState (lstrlib.c): source start/end, Lua state, capture level, then 32 captures. */
typedef struct Lib3MatchState {
    const char *src_init;
    const char *src_end;
    void *L;
    int level;
    struct {
        const char *init;
        int len;
    } capture[32];
} Lib3MatchState;

extern const char *lib3_match_88825EF0(Lib3MatchState *ms, const char *s, const char *p);
extern int ts4_match_class_88824F38(int c, int cl);
extern int lib3_matchbracketclass_88825118(int c, const char *p, const char *ec);

#ifdef _MSC_VER
#define LIB3_FORCEINLINE static __forceinline
#else
#define LIB3_FORCEINLINE static inline
#endif

/* luaI_singlematch */
LIB3_FORCEINLINE int lib3_singlematch(int c, const char *p, const char *ep)
{
    switch (*p) {
    case '.': return 1;
    case '%': return ts4_match_class_88824F38(c, *(p + 1));
    case '[': return lib3_matchbracketclass_88825118(c, p, ep - 1);
    default: return ((unsigned char)*p == c);
    }
}

/* min_expand: shortest repetition of a single-char class that lets the rest match. */
const char *lib3_min_expand_888253B8(Lib3MatchState *ms, const char *s, const char *p, const char *ep)
{
    for (;;) {
        const char *res = lib3_match_88825EF0(ms, s, ep + 1);
        if (res != 0)
            return res;
        else if (s < ms->src_end && lib3_singlematch((unsigned char)*s, p, ep))
            s++;
        else return 0;
    }
}

/* max_expand: longest repetition first, backing off one char at a time. */
const char *lib3_max_expand_88825478(Lib3MatchState *ms, const char *s, const char *p, const char *ep)
{
    int i = 0;
    while ((s + i) < ms->src_end && lib3_singlematch((unsigned char)*(s + i), p, ep))
        i++;
    while (i >= 0) {
        const char *res = lib3_match_88825EF0(ms, (s + i), ep + 1);
        if (res) return res;
        i--;
    }
    return 0;
}

extern void lib3_luaL_openlib_8882E0D8(void *L, const char *libname, const void *l);
extern char lbl_880E24B8[];
extern char lbl_880C9A48[];
extern void ts4_lua_pushlstring_88823FC0(void *L, const char *s, unsigned int len);
extern void lib3_lua_getglobal_top_88823BA8(void *L);
extern void fn_88834978(void *L, int n);

/* Register the second half of the "string" library (functions table at 0x880C9A48). */
int lib3_open_string_extra_88825548(void *L)
{
    lib3_luaL_openlib_8882E0D8(L, lbl_880E24B8, lbl_880C9A48);
    return 0;
}

/* luaopen_string: register both "string" function tables around a lookup of the global. */
int lib3_luaopen_string_88825580(void *L)
{
    lib3_luaL_openlib_8882E0D8(L, lbl_880E24B8, lbl_880C9A48 - 0x70);
    ts4_lua_pushlstring_88823FC0(L, lbl_880E24B8, 6);
    lib3_lua_getglobal_top_88823BA8(L);
    fn_88834978(L, 4);
    lib3_luaL_openlib_8882E0D8(L, lbl_880E24B8, lbl_880C9A48);
    return 1;
}

#ifdef _MSC_VER
extern void *memcpy(void *d, const void *s, unsigned int n);
#define LIB3_NORETURN __declspec(noreturn)
#else
#define LIB3_NORETURN _Noreturn
#endif
extern char lbl_880E2494[];
LIB3_NORETURN extern void lib3_luaL_argerror_8882E6B8(void *L, int narg, const char *msg);

/* Raise "bad code `c'" as an error on argument 1. */
void lib3_bad_code_error_888255F0(void *L, int c)
{
    char buff[13];
    memcpy(buff, lbl_880E2494, 13);
    buff[10] = (char)c;
    lib3_luaL_argerror_8882E6B8(L, 1, buff);
}

