/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* Altered to match Swing_DLL.xex: the wide-character copy of lstrlib.c (lua_WChar strings). */
#ifdef _MSC_VER
#define LIB3_FORCEINLINE static __forceinline
#else
#define LIB3_FORCEINLINE static inline
#endif

typedef unsigned short lib3_wchar;

/* MatchState with wide source pointers. */
typedef struct Lib3WMatchState {
    const lib3_wchar *src_init;
    const lib3_wchar *src_end;
    void *L;
    int level;
    struct {
        const lib3_wchar *init;
        int len;
    } capture[32];
} Lib3WMatchState;

extern const lib3_wchar *lua3_wmatch_8882FEF8(Lib3WMatchState *ms, const lib3_wchar *s, const lib3_wchar *p);
extern int ts4_match_flag_char_8882EED0(int c, int cl);
extern int lib3_wmatchbracketclass_8882F1E8(int c, const lib3_wchar *p, const lib3_wchar *ec);

/* luaI_singlematch (wide) */
LIB3_FORCEINLINE int lib3_wsinglematch(int c, const lib3_wchar *p, const lib3_wchar *ep)
{
    switch (*p) {
    case '.': return 1;
    case '%': return ts4_match_flag_char_8882EED0(c, *(p + 1));
    case '[': return lib3_wmatchbracketclass_8882F1E8(c, p, ep - 1);
    default: return (*p == (lib3_wchar)c);
    }
}

/* min_expand (wide) */
const lib3_wchar *lib3_wmin_expand_8882F488(Lib3WMatchState *ms, const lib3_wchar *s, const lib3_wchar *p, const lib3_wchar *ep)
{
    for (;;) {
        const lib3_wchar *res = lua3_wmatch_8882FEF8(ms, s, ep + 1);
        if (res != 0)
            return res;
        else if (s < ms->src_end && lib3_wsinglematch(*s, p, ep))
            s++;
        else return 0;
    }
}

/* max_expand (wide) */
const lib3_wchar *lib3_wmax_expand_8882F548(Lib3WMatchState *ms, const lib3_wchar *s, const lib3_wchar *p, const lib3_wchar *ep)
{
    int i = 0;
    while ((s + i) < ms->src_end && lib3_wsinglematch(*(s + i), p, ep))
        i++;
    while (i >= 0) {
        const lib3_wchar *res = lua3_wmatch_8882FEF8(ms, (s + i), ep + 1);
        if (res) return res;
        i--;
    }
    return 0;
}

extern void lib3_luaL_openlib_8882E0D8(void *L, const char *libname, const void *l);
extern char lbl_880E1C10[];
extern char lbl_880C9C98[];
extern void ts4_lua_pushlstring_88823FC0(void *L, const char *s, unsigned int len);
extern void lib3_lua_getglobal_top_88823BA8(void *L);
extern void fn_88834978(void *L, int n);

/* luaopen_wstring */
int lib3_luaopen_wstring_8882F628(void *L)
{
    lib3_luaL_openlib_8882E0D8(L, lbl_880E1C10, lbl_880C9C98);
    ts4_lua_pushlstring_88823FC0(L, lbl_880E1C10, 7);
    lib3_lua_getglobal_top_88823BA8(L);
    fn_88834978(L, 9);
    return 0;
}
