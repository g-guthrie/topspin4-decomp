/* Derived from Lua 5.0.2 lstrlib.c (MIT); see THIRD_PARTY_NOTICES.md */
/* Wide-string helpers from the LuaPlus wide string library; LTCG specialised them to their constant arguments. */
#include "lua3.h"

extern const u16 lbl_880E1B7C[]; /* L"-+ #0" (FLAGS) */

/* wcschr(FLAGS, c) */
const u16 *lua3_wcschr_flags_8882EE50(u16 c)
{
    const u16 *p = lbl_880E1B7C;
    u32 ch = '-';
    do {
        if (ch == c) return p;
        ch = *++p;
    } while (ch != 0);
    return 0;
}

extern const u16 *fn_888348A0(lua_State *L, int narg); /* lua_towstring */
extern LUA2_NORETURN void lib3_luaL_typerror_8882E950(lua_State *L, int narg, const char *tname);
extern const char *const lbl_880C9684[]; /* luaT_typenames */
extern u32 lib3_lua_strlen_888222F0(lua_State *L, int idx);

/* Same-TU copy of luaL_checklwstring: callers rely on LTCG knowing it does not retain len. */
LUA2_LOCAL const u16 *lib3_luaL_checklwstring_8882EA30(lua_State *L, int narg, u32 *len)
{
    const u16 *s = fn_888348A0(L, narg);
    if (!s) lib3_luaL_typerror_8882E950(L, narg, lbl_880C9684[9]);
    if (len) *len = lib3_lua_strlen_888222F0(L, narg);
    return s;
}
extern void ts4_lua_pushnumber_888240B8(lua_State *L, double n);

/* str_len for wide strings */
int lua3_wstr_len_88831990(lua_State *L)
{
    u32 l;
    lib3_luaL_checklwstring_8882EA30(L, 1, &l);
    ts4_lua_pushnumber_888240B8(L, (double)l);
    return 1;
}

#define LUA3_BUFFERSIZE 0x200

/* luaL_Buffer: write pointer, level count, wide flag, owner state, storage. */
typedef struct WBuffer {
    char *p;
    int lvl;
    int wide;
    lua_State *L;
    char buffer[LUA3_BUFFERSIZE];
} WBuffer;

extern int lib3_emptybuffer_8882DE88(WBuffer *B);
extern void lib3_adjuststack_8882DBA8(WBuffer *B);
extern void lib3_luaL_addlwstring_8882E790(WBuffer *B, const u16 *s, u32 l);
extern void ts4_lua_concat_88822DB0(lua_State *L, int n);
extern double ts4_lua_opt_number_default_8882EA98(lua_State *L, int narg); /* luaL_checknumber */
extern LUA2_NORETURN void lib3_luaL_argerror_8882E6B8(lua_State *L, int narg, const char *msg);
extern u16 ts4_if_fn_885677E8(u16 c); /* towupper */
extern u16 ts4_if_fn_885677C0(u16 c); /* towlower */
extern char lbl_880E1A7C[];           /* "invalid value" */

#define wbuffinit(L, B) ((B)->L = (L), (B)->p = (B)->buffer, (B)->wide = 1, (B)->lvl = 0)
#define wputchar(B, c) \
    do { \
        if ((B)->p + 1 >= (B)->buffer + LUA3_BUFFERSIZE && lib3_emptybuffer_8882DE88(B)) \
            lib3_adjuststack_8882DBA8(B); \
        *(u16 *)(B)->p = (u16)(c); \
        (B)->p += 2; \
    } while (0)
#define wpushresult(B) (lib3_emptybuffer_8882DE88(B), ts4_lua_concat_88822DB0((B)->L, (B)->lvl))

/* str_upper */
int lua3_wstr_upper_888317F0(lua_State *L)
{
    u32 l;
    u32 i;
    WBuffer b;
    const u16 *s = lib3_luaL_checklwstring_8882EA30(L, 1, &l);
    wbuffinit(L, &b);
    for (i = 0; i < l; i++) wputchar(&b, ts4_if_fn_885677E8(s[i]));
    wpushresult(&b);
    return 1;
}

/* str_lower */
int lua3_wstr_lower_888318C0(lua_State *L)
{
    u32 l;
    u32 i;
    WBuffer b;
    const u16 *s = lib3_luaL_checklwstring_8882EA30(L, 1, &l);
    wbuffinit(L, &b);
    for (i = 0; i < l; i++) wputchar(&b, ts4_if_fn_885677C0(s[i]));
    wpushresult(&b);
    return 1;
}

/* str_rep */
int lua3_wstr_rep_88831750(lua_State *L)
{
    u32 l;
    WBuffer b;
    const u16 *s = lib3_luaL_checklwstring_8882EA30(L, 1, &l);
    int n = (int)ts4_lua_opt_number_default_8882EA98(L, 2);
    wbuffinit(L, &b);
    while (n-- > 0) lib3_luaL_addlwstring_8882E790(&b, s, l);
    wpushresult(&b);
    return 1;
}

/* str_char */
int lua3_wstr_char_88831668(lua_State *L)
{
    int n = (int)(L->top - L->base);
    int i;
    WBuffer b;
    wbuffinit(L, &b);
    for (i = 1; i <= n; i++) {
        int c = (int)ts4_lua_opt_number_default_8882EA98(L, i);
        if ((u16)c != c) lib3_luaL_argerror_8882E6B8(L, i, lbl_880E1A7C);
        wputchar(&b, c);
    }
    wpushresult(&b);
    return 1;
}

#if 0 /* near miss: 4 instructions differ in register choice for the pushlwstring arguments */
extern void fn_88834B28(lua_State *L, const u16 *s, u32 l); /* lua_pushlwstring */
extern const double g_ts4_script_constants[];             /* [294] = -1.0 */
extern const u16 lbl_880DFC68[];                           /* L"" */


/* luaL_optint(L, narg, -1) */
LUA2_FORCEINLINE int optint_m1(lua_State *L, int narg)
{
    return (int)(isnoneornil(L, narg) ? g_ts4_script_constants[294] : ts4_lua_opt_number_default_8882EA98(L, narg));
}

/* str_sub */
int lua3_wstr_sub_88832648(lua_State *L)
{
    u32 l;
    const u16 *s = lib3_luaL_checklwstring_8882EA30(L, 1, &l);
    int start = posrelat((int)ts4_lua_opt_number_default_8882EA98(L, 2), l);
    int end = posrelat(optint_m1(L, 3), l);
    if (start < 1) start = 1;
    if (end > (int)l) end = (int)l;
    if (start <= end)
        fn_88834B28(L, s + start - 1, end - start + 1);
    else
        fn_88834B28(L, lbl_880DFC68, 0);
    return 1;
}
#endif

extern void lua3_lua_settop_888246A8(lua_State *L, int idx);
extern void lib3_lua_pushcclosure_88823E00(lua_State *L, int (*fn)(lua_State *L), int n);
extern int fn_888313E0(lua_State *L); /* gfind_aux (wide) */
extern const double g_ts4_script_constants[]; /* [11] = 0.0 */

LUA2_FORCEINLINE const u16 *checkwstring_(lua_State *L, int narg)
{
    const u16 *s = fn_888348A0(L, narg);
    if (!s) lib3_luaL_typerror_8882E950(L, narg, lbl_880C9684[9]);
    return s;
}

/* gfind for wide strings */
int lua3_wgfind_88832248(lua_State *L)
{
    checkwstring_(L, 1);
    checkwstring_(L, 2);
    lua3_lua_settop_888246A8(L, 2);
    ts4_lua_pushnumber_888240B8(L, g_ts4_script_constants[11]);
    lib3_lua_pushcclosure_88823E00(L, fn_888313E0, 3);
    return 1;
}


/* lua_isnoneornil on a positive index */
LUA2_FORCEINLINE int isnoneornil(lua_State *L, int idx)
{
    TValue *o = L->base + (idx - 1);
    if (o >= L->top) o = 0;
    return o == 0 || ttype(o) <= LUA2_TNIL;
}

LUA2_FORCEINLINE int posrelat(int pos, u32 len)
{
    return pos >= 0 ? pos : (int)len + pos + 1;
}

#define LUA3_MAXCAPTURES 32

typedef struct WMatchState {
    const u16 *src_init; /* init of source string */
    const u16 *src_end;  /* end (`\0') of source string */
    lua_State *L;
    int level; /* total number of captures (finished or unfinished) */
    struct {
        const u16 *init;
        int len;
    } capture[LUA3_MAXCAPTURES];
} WMatchState;

extern const u16 lbl_880E1B3C[]; /* L"^$*+?.([%-" (SPECIALS) */
extern char lbl_880E1A6C[];      /* "out of range" */
extern int ts4_lua_toboolean_88822398(lua_State *L, int idx);
extern const u16 *lua3_wlmemfind_8882F128(const u16 *s1, u32 l1, const u16 *s2, u32 l2); /* lmemfind */
extern const u16 *lua3_wmatch_8882FEF8(WMatchState *ms, const u16 *s, const u16 *p); /* match */
extern int lua3_wpush_captures_8882FB28(WMatchState *ms, const u16 *s, const u16 *e);       /* push_captures */
extern void ts4_lua_pushnil_88824188(lua_State *L);

/* luaL_optint(L, narg, 1) */
LUA2_FORCEINLINE int optint_1(lua_State *L, int narg)
{
    return (int)(isnoneornil(L, narg) ? g_ts4_script_constants[15] : ts4_lua_opt_number_default_8882EA98(L, narg));
}

/* wcspbrk against a non-empty set */
LUA2_FORCEINLINE const u16 *wcspbrk_(const u16 *s, const u16 *p)
{
    const u16 *q;
    for (; *s; ++s) {
        q = p;
        for (;;) {
            if (*q++ == *s) return s;
            if (!*q) break;
        }
    }
    return 0;
}

/* wcspbrk(s, SPECIALS) */
const u16 *lua3_wcspbrk_specials_8882EE88(const u16 *s)
{
    return wcspbrk_(s, lbl_880E1B3C);
}

/* str_find for wide strings */
int lua3_wstr_find_888322F0(lua_State *L)
{
    u32 l1, l2;
    const u16 *s = lib3_luaL_checklwstring_8882EA30(L, 1, &l1);
    const u16 *p = lib3_luaL_checklwstring_8882EA30(L, 2, &l2);
    int init = posrelat(optint_1(L, 3), l1) - 1;
    if (!(0 <= init && (u32)init <= l1)) lib3_luaL_argerror_8882E6B8(L, 3, lbl_880E1A6C);
    if (ts4_lua_toboolean_88822398(L, 4) || wcspbrk_(p, lbl_880E1B3C) == 0) {
        /* do a plain search */
        const u16 *s2 = lua3_wlmemfind_8882F128(s + init, l1 - init, p, l2);
        if (s2) {
            ts4_lua_pushnumber_888240B8(L, (double)(int)(s2 - s + 1));
            ts4_lua_pushnumber_888240B8(L, (double)((u32)(s2 - s) + l2));
            return 2;
        }
    } else {
        WMatchState ms;
        int anchor = (*p == '^') ? (p++, 1) : 0;
        const u16 *s1 = s + init;
        ms.L = L;
        ms.src_init = s;
        ms.src_end = s + l1;
        do {
            const u16 *res;
            ms.level = 0;
            if ((res = lua3_wmatch_8882FEF8(&ms, s1, p)) != 0) {
                ts4_lua_pushnumber_888240B8(L, (double)(int)(s1 - s + 1)); /* start */
                ts4_lua_pushnumber_888240B8(L, (double)(int)(res - s));    /* end */
                return lua3_wpush_captures_8882FB28(&ms, 0, 0) + 2;
            }
        } while (s1++ < ms.src_end && !anchor);
    }
    ts4_lua_pushnil_88824188(L); /* not found */
    return 1;
}

extern char lbl_880E1B54[]; /* "string or function expected" */

/* lua_iswstring on a positive index: wide strings and numbers */
LUA2_FORCEINLINE int iswstring_(lua_State *L, int idx)
{
    TValue *o = L->base + (idx - 1);
    if (o >= L->top) o = 0;
    return o != 0 && (ttype(o) == LUA2_TWSTRING || ttype(o) == LUA2_TNUMBER);
}

LUA2_FORCEINLINE int isfunction_(lua_State *L, int idx)
{
    TValue *o = L->base + (idx - 1);
    if (o >= L->top) o = 0;
    return o != 0 && ttype(o) == LUA2_TFUNCTION;
}

/* luaL_optint(L, narg, def) */
LUA2_FORCEINLINE int optint_(lua_State *L, int narg, double def)
{
    return (int)(isnoneornil(L, narg) ? def : ts4_lua_opt_number_default_8882EA98(L, narg));
}

extern int fn_88569800(u16 c, int type); /* iswctype; 4 = _DIGIT */
extern int lua3_wcheck_capture_8882FAD0(WMatchState *ms, u16 l); /* check_capture */
extern void lua3_wpush_onecapture_8882F7D8(WMatchState *ms, int i); /* push_onecapture */
extern void lib3_luaL_addvalue_8882E3E8(WBuffer *B);
extern void ts4_lua_pushvalue_88824248(lua_State *L, int idx);
extern void lua2_luaD_call_8881E258(lua_State *L, StkId func, int nresults);

/* lua_iswstring(L, -1) */
LUA2_FORCEINLINE int iswstring_top(lua_State *L)
{
    TValue *o = L->top - 1;
    return o != 0 && (ttype(o) == LUA2_TWSTRING || ttype(o) == LUA2_TNUMBER);
}

/* add_s for wide strings */
void lua3_wadd_s_8882FD10(WMatchState *ms, WBuffer *b, const u16 *s, const u16 *e)
{
    lua_State *L = ms->L;
    if (iswstring_(L, 3)) {
        const u16 *news = fn_888348A0(L, 3);
        u32 l = lib3_lua_strlen_888222F0(L, 3);
        u32 i;
        for (i = 0; i < l; i++) {
            if (news[i] != '%')
                wputchar(b, news[i]);
            else {
                i++; /* skip ESC */
                if (!fn_88569800(news[i], 4))
                    wputchar(b, news[i]);
                else {
                    int level = lua3_wcheck_capture_8882FAD0(ms, news[i]);
                    lua3_wpush_onecapture_8882F7D8(ms, level);
                    lib3_luaL_addvalue_8882E3E8(b); /* add capture to accumulated result */
                }
            }
        }
    } else { /* is a function */
        int n;
        ts4_lua_pushvalue_88824248(L, 3);
        n = lua3_wpush_captures_8882FB28(ms, s, e);
        lua2_luaD_call_8881E258(L, L->top - (n + 1), 1);
        if (iswstring_top(L))
            lib3_luaL_addvalue_8882E3E8(b); /* add return to accumulated result */
        else
            lua3_lua_settop_888246A8(L, -2); /* function result is not a string */
    }
}

/* str_gsub for wide strings */
int lua3_wstr_gsub_88831FD0(lua_State *L)
{
    u32 srcl;
    const u16 *src = lib3_luaL_checklwstring_8882EA30(L, 1, &srcl);
    const u16 *p = checkwstring_(L, 2);
    int max_s = optint_(L, 4, (double)(srcl + 1));
    int anchor = (*p == '^') ? (p++, 1) : 0;
    int n = 0;
    WMatchState ms;
    WBuffer b;
    if (!((int)(L->top - L->base) >= 3 && (iswstring_(L, 3) || isfunction_(L, 3))))
        lib3_luaL_argerror_8882E6B8(L, 3, lbl_880E1B54);
    wbuffinit(L, &b);
    ms.L = L;
    ms.src_init = src;
    ms.src_end = src + srcl;
    while (n < max_s) {
        const u16 *e;
        ms.level = 0;
        e = lua3_wmatch_8882FEF8(&ms, src, p);
        if (e) {
            n++;
            lua3_wadd_s_8882FD10(&ms, &b, src, e);
        }
        if (e && e > src) /* non empty match? */
            src = e;      /* skip it */
        else if (src < ms.src_end)
            wputchar(&b, *src++);
        else
            break;
        if (anchor) break;
    }
    lib3_luaL_addlwstring_8882E790(&b, src, ms.src_end - src);
    wpushresult(&b);
    b.lvl = 1;
    ts4_lua_pushnumber_888240B8(L, (double)n); /* number of substitutions */
    return 2;
}

extern const u16 lbl_880E1B70[]; /* L"\\000" */

/* luaI_addquoted for wide strings */
void lua3_waddquoted_88831248(lua_State *L, WBuffer *b, int arg)
{
    u32 l;
    const u16 *s = lib3_luaL_checklwstring_8882EA30(L, arg, &l);
    wputchar(b, '"');
    while (l--) {
        switch (*s) {
        case '"':
        case '\\':
        case '\n':
            wputchar(b, '\\');
            wputchar(b, *s);
            break;
        case '\0':
            lib3_luaL_addlwstring_8882E790(b, lbl_880E1B70, 4);
            break;
        default:
            wputchar(b, *s);
            break;
        }
        s++;
    }
    wputchar(b, '"');
}

extern void lib3_luaL_where_8882E2D0(lua_State *L, int level);
extern void fn_8880FA80(lua_State *L, int total, int last);    /* luaV_concat */
extern void ts4_call_seq_fn_8881C130_8881C200(lua_State *L); /* luaC_collectgarbage */
#ifdef _MSC_VER
#define LUA3_UNREACHABLE() __assume(0)
#else
#define LUA3_UNREACHABLE() __builtin_unreachable()
#endif

/* Same-TU copy of luaL_error: the callers' frames depend on its variadic body being visible. */
LUA2_LOCAL LUA3_NORETURN void lib3_luaL_error_8882E5F0(lua_State *L, const char *fmt, ...)
{
    va_list argp;
    va_start(argp, fmt);
    lib3_luaL_where_8882E2D0(L, 1);
    if (G(L)->nblocks >= G(L)->GCthreshold) ts4_call_seq_fn_8881C130_8881C200(L);
    lua3_luaO_pushvfstring_888188F8(L, fmt, argp);
    va_end(argp);
    if (G(L)->nblocks >= G(L)->GCthreshold) ts4_call_seq_fn_8881C130_8881C200(L);
    fn_8880FA80(L, 2, (int)(L->top - L->base) - 1);
    L->top -= 1;
    lua3_luaG_errormsg_8881F900(L);
    LUA3_UNREACHABLE();
}


#define MAX_ITEM 512
#define MAX_FORMAT 20

extern char lbl_880E1B88[]; /* "invalid format (width or precision too long)" */
extern char lbl_880E1BB8[]; /* "invalid format (too long)" */

/* Same-TU copy of the bounded wide copy (see lua3_lwmatch.c). */
LUA2_LOCAL void lib3_lua_wstrncpy_8882EDF0(u16 *dst, const u16 *src, u32 n)
{
    while (n) {
        if ((*dst++ = *src++) == 0) break;
        n--;
    }
    if (n) {
        while (--n) *dst++ = 0;
    }
}

/* Same-TU copy of scanformat: str_format reuses the slot of hasprecision once LTCG knows the pointer is not kept. */
LUA2_LOCAL const u16 *lua3_wscanformat_8882F698(lua_State *L, const u16 *strfrmt, u16 *form, int *hasprecision)
{
    const u16 *p = strfrmt;
    for (;;) { /* skip flags */
        u32 c = *p;
        if (!lua3_wcschr_flags_8882EE50((u16)c)) break;
        p++;
    }
    if (fn_88569800(*p, 4)) p++; /* skip width */
    if (fn_88569800(*p, 4)) p++; /* (2 digits at most) */
    if (*p == '.') {
        u32 c;
        p++;
        c = *p;
        *hasprecision = 1;
        if (fn_88569800((u16)c, 4)) p++; /* skip precision */
        if (fn_88569800(*p, 4)) p++;     /* (2 digits at most) */
    }
    if (fn_88569800(*p, 4)) lib3_luaL_error_8882E5F0(L, lbl_880E1B88);
    if (p - strfrmt + 2 > MAX_FORMAT) lib3_luaL_error_8882E5F0(L, lbl_880E1BB8);
    form[0] = '%';
    lib3_lua_wstrncpy_8882EDF0(form + 1, strfrmt, p - strfrmt + 1);
    form[p - strfrmt + 2] = 0;
    return p;
}
extern void fn_88830700(lua_State *L, WBuffer *b, int arg); /* %Q */
extern int fn_885635D0(char *buf, const char *fmt, ...);    /* sprintf */
extern int fn_885696C0(u16 *buf, u32 n, const u16 *fmt, ...); /* _snwprintf */
extern char lbl_880E1BD4[]; /* "obsolete `format' option (d$)" */
extern char lbl_880E1BF4[]; /* "invalid option in `format'" */

/* narrow copy of a wide format */
LUA2_FORCEINLINE void narrow_(const u16 *s, char *d)
{
    while (*s) *d++ = (char)*s++;
    *d = 0;
}

/* widen a narrow result */
LUA2_FORCEINLINE void widen_(const char *s, u16 *d)
{
    while (*s) *d++ = (u16)*s++;
    *d = 0;
}

LUA2_FORCEINLINE u32 wcslen2_(const u16 *s)
{
    const u16 *e = s;
    while (*e) e++;
    return (u32)(e - s);
}

/* str_format body for wide strings; the caller owns the buffer and pushes the result */
int lua3_wstr_format_888319E0(WBuffer *b, lua_State *L)
{
    int arg = 1;
    const u16 *strfrmt;
    const u16 *strfrmt_end;
    {
        u32 sfl;
        strfrmt = lib3_luaL_checklwstring_8882EA30(L, arg, &sfl);
        strfrmt_end = strfrmt + sfl;
    }
    wbuffinit(L, b);
    while (strfrmt < strfrmt_end) {
        if (*strfrmt != '%')
            wputchar(b, *strfrmt++);
        else if (*++strfrmt == '%')
            wputchar(b, *strfrmt++); /* %% */
        else { /* format item */
            int hasprecision;
            u32 l;
            char form8[MAX_FORMAT];
            u16 form[MAX_FORMAT]; /* to store the format (`%...') */
            u16 buff[MAX_ITEM];   /* to store the formatted item */
            char buff8[MAX_ITEM];
            hasprecision = 0;
            if (fn_88569800(*strfrmt, 4) && *(strfrmt + 1) == '$')
                lib3_luaL_error_8882E5F0(L, lbl_880E1BD4);
            arg++;
            strfrmt = lua3_wscanformat_8882F698(L, strfrmt, form, &hasprecision);
            switch (*strfrmt++) {
            case 'b': { /* binary item: %bb byte, %bw word, %bd int, %bf float, %bF double */
                buff[8] = 0;
                buff[7] = 0;
                buff[6] = 0;
                buff[5] = 0;
                buff[4] = 0;
                buff[3] = 0;
                buff[2] = 0;
                buff[1] = 0;
                switch (*strfrmt++) {
                case 'b':
                    buff[0] = (unsigned char)(int)ts4_lua_opt_number_default_8882EA98(L, arg);
                    lib3_luaL_addlwstring_8882E790(b, buff, 1);
                    break;
                case 'w':
                    buff[0] = (u16)(int)ts4_lua_opt_number_default_8882EA98(L, arg);
                    lib3_luaL_addlwstring_8882E790(b, buff, 2);
                    break;
                case 'd':
                    *(int *)buff = (int)ts4_lua_opt_number_default_8882EA98(L, arg);
                    lib3_luaL_addlwstring_8882E790(b, buff, 4);
                    break;
                case 'f':
                    *(float *)buff = (float)ts4_lua_opt_number_default_8882EA98(L, arg);
                    lib3_luaL_addlwstring_8882E790(b, buff, 4);
                    break;
                case 'F':
                    *(double *)buff = ts4_lua_opt_number_default_8882EA98(L, arg);
                    lib3_luaL_addlwstring_8882E790(b, buff, 8);
                    break;
                }
                buff[0] = 0;
                break;
            }
            case 'c':
            case 'd':
            case 'i':
                narrow_(form, form8);
                fn_885635D0(buff8, form8, (int)ts4_lua_opt_number_default_8882EA98(L, arg));
                widen_(buff8, buff);
                break;
            case 'o':
            case 'u':
            case 'x':
            case 'X':
                narrow_(form, form8);
                fn_885635D0(buff8, form8, (unsigned int)ts4_lua_opt_number_default_8882EA98(L, arg));
                widen_(buff8, buff);
                break;
            case 'e':
            case 'E':
            case 'f':
            case 'g':
            case 'G':
                narrow_(form, form8);
                fn_885635D0(buff8, form8, ts4_lua_opt_number_default_8882EA98(L, arg));
                widen_(buff8, buff);
                break;
            case 'q':
                lua3_waddquoted_88831248(L, b, arg);
                continue; /* skip the `addsize' at the end */
            case 'Q':
                fn_88830700(L, b, arg);
                continue;
            case 's': {
                const u16 *s = lib3_luaL_checklwstring_8882EA30(L, arg, &l);
                if (!hasprecision && l >= 100) {
                    /* no precision and string is too long to be formatted; keep original string */
                    ts4_lua_pushvalue_88824248(L, arg);
                    lib3_luaL_addvalue_8882E3E8(b);
                    continue; /* skip the `addsize' at the end */
                } else {
                    fn_885696C0(buff, MAX_ITEM, form, s);
                    break;
                }
            }
            default: /* also treat cases `pnLlh' */
                lib3_luaL_error_8882E5F0(L, lbl_880E1BF4);
            }
            lib3_luaL_addlwstring_8882E790(b, buff, wcslen2_(buff));
        }
    }
    return 1;
}

extern int ts4_if_fn_88567730(int c);                                  /* tolower */
extern const unsigned short *ts4_get_u32_lbl_88C311F4_88567FC8(void); /* _pctype */
#define c_isdigit(c) (ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x4)
#define w_isdigit(c) fn_88569800((c), 4)
#define w_isxalpha(c) ((c) >= 'a' && (c) <= 'f')

/* Decode C escapes (\a \b \f \n \r \t \v, \xHH or \xHHHH when arg 2 is non-zero, \ddd) in a wide string. */
int lua3_wstr_unescape_88830178(lua_State *L)
{
    u32 l = 0;
    const u16 *s = lib3_luaL_checklwstring_8882EA30(L, 1, &l);
    int unicode = (int)ts4_lua_opt_number_default_8882EA98(L, 2) != 0;
    WBuffer b;
    u32 i;
    wbuffinit(L, &b);
    for (i = 0; i < l; i++) {
        if (s[i] != '\\')
            wputchar(&b, s[i]);
        else {
            i++;
            switch (s[i]) {
            case 'a': wputchar(&b, 7); break;
            case 'b': wputchar(&b, 8); break;
            case 'f': wputchar(&b, 12); break;
            case 'n': wputchar(&b, 10); break;
            case 'r': wputchar(&b, 13); break;
            case 't': wputchar(&b, 9); break;
            case 'v': wputchar(&b, 11); break;
            case 'x': {
                u32 j = i + 1;
                int c = ts4_if_fn_88567730(s[j]);
                if (c_isdigit(c) || w_isxalpha(c)) {
                    int value = 0;
                    u32 n = 0;
                    u32 max = unicode ? 4 : 2;
                    int w;
                    do {
                        w = ts4_if_fn_885677C0(s[j]);
                        if (w_isdigit(w))
                            value = value * 16 + w - '0';
                        else if (w_isxalpha(w))
                            value = value * 16 + w - 'a' + 10;
                        j++;
                        n++;
                        w = ts4_if_fn_885677C0(s[j]);
                    } while (n < max && (w_isdigit(w) || w_isxalpha(w)));
                    wputchar(&b, value);
                    i = j - 1;
                } else {
                    i = j - 1;
                    wputchar(&b, 'x');
                }
                break;
            }
            default:
                if (!w_isdigit(s[i]))
                    wputchar(&b, s[i]);
                else {
                    int value = 0;
                    int n = 0;
                    do {
                        value = value * 10 + s[i] - '0';
                        n++;
                        i++;
                    } while (n < 3 && w_isdigit(s[i]));
                    wputchar(&b, value);
                }
                break;
            }
        }
    }
    wpushresult(&b);
    return 1;
}

#if 0 /* NEAR MISS 0x888313E0 gfind_aux: 21 instructions, L and s swap r27/r28 */

extern int fn_88834740(lua_State *L, TValue *obj); /* luaV_towstring */
extern int ts4_lua_v_tostring_8880C9F8(lua_State *L, TValue *obj);
extern TValue *ts4_lua_v_tonumber_8880CAF0(lua_State *L, TValue *obj, TValue *n);
extern void ts4_lua_replace_88824340(lua_State *L, int idx);


/* lua_towstring on a resolved slot */
LUA2_FORCEINLINE const u16 *towstring_obj(lua_State *L, TValue *o)
{
    if (o == 0) return 0;
    else if (ttype(o) == LUA2_TWSTRING) return (const u16 *)getstr(tsvalue(o));
    else {
        const u16 *s;
        s = (fn_88834740(L, o) ? (const u16 *)getstr(tsvalue(o)) : 0);
        return s;
    }
}

/* lua_strlen on a resolved slot */
LUA2_FORCEINLINE u32 strlen_obj(lua_State *L, TValue *o)
{
    if (o == 0) return 0;
    else if (ttype(o) == LUA2_TSTRING) return tsvalue(o)->len;
    else if (ttype(o) == LUA2_TWSTRING) return tsvalue(o)->len;
    else {
        u32 l;
        l = (ts4_lua_v_tostring_8880C9F8(L, o) ? tsvalue(o)->len : 0);
        return l;
    }
}

/* lua_tonumber on a resolved slot */
LUA2_FORCEINLINE double tonumber_obj(lua_State *L, TValue *o)
{
    TValue n;
    n.tt = 0;
    n.value.p = 0;
    if (o != 0 && (o->tt == LUA2_TNUMBER || (o = ts4_lua_v_tonumber_8880CAF0(L, o, &n)) != 0))
        return nvalue(o);
    return g_ts4_script_constants[11];
}

/* gfind_aux for wide strings */
int lua3_wgfind_aux_888313E0(lua_State *L)
{
    WMatchState ms;
    const u16 *s;
    u32 ls;
    const u16 *p;
    const u16 *src;
    CClosure *cl = &clvalue(L->base - 1)->c;
    TValue *o = (1 <= cl->nupvalues) ? &cl->upvalue[0] : 0;
    s = towstring_obj(L, o);
    cl = &clvalue(L->base - 1)->c;
    o = (1 <= cl->nupvalues) ? &cl->upvalue[0] : 0;
    ls = strlen_obj(L, o);
    cl = &clvalue(L->base - 1)->c;
    o = (2 <= cl->nupvalues) ? &cl->upvalue[1] : 0;
    p = towstring_obj(L, o);
    ms.L = L;
    ms.src_init = s;
    ms.src_end = s + ls;
    cl = &clvalue(L->base - 1)->c;
    o = (3 <= cl->nupvalues) ? &cl->upvalue[2] : 0;
    for (src = s + (u32)tonumber_obj(L, o); src <= ms.src_end; src++) {
        const u16 *e;
        ms.level = 0;
        if ((e = lua3_wmatch_8882FEF8(&ms, src, p)) != 0) {
            int newstart = (int)(e - s);
            if (e == src) newstart++; /* empty match? go at least one position */
            ts4_lua_pushnumber_888240B8(L, (double)newstart);
            ts4_lua_replace_88824340(L, -10004);
            return lua3_wpush_captures_8882FB28(&ms, src, e);
        }
    }
    return 0; /* not found */
}
#endif
