#ifndef _MSC_VER
#pragma GCC diagnostic ignored "-Wreturn-type"
#endif
/* Derived from Lua 5.0.2 lstrlib.c (MIT); see THIRD_PARTY_NOTICES.md */
/* Pattern-matching captures of the LuaPlus wide string library (16-bit characters). */
#include "lua3.h"
#ifdef _MSC_VER
extern int memcmp(const void *a, const void *b, unsigned int n);
#pragma intrinsic(memcmp)
#else
#include <string.h>
#endif

#define LUA_MAXCAPTURES 32
#define CAP_UNFINISHED (-1)
#define CAP_POSITION (-2)

typedef struct WMatchState {
    const u16 *src_init; /* init of source string */
    const u16 *src_end;  /* end (`\0') of source string */
    lua_State *L;
    int level; /* total number of captures (finished or unfinished) */
    struct {
        const u16 *init;
        int len;
    } capture[LUA_MAXCAPTURES];
} WMatchState;

extern void lib3_luaL_where_8882E2D0(lua_State *L, int level);
extern void fn_8880FA80(lua_State *L, int total, int last);    /* luaV_concat */
extern void ts4_call_seq_fn_8881C130_8881C200(lua_State *L); /* luaC_collectgarbage */
#ifdef _MSC_VER
#define LUA3_UNREACHABLE() __assume(0)
#else
#define LUA3_UNREACHABLE() __builtin_unreachable()
#endif
extern void ts4_lua_pushnumber_888240B8(lua_State *L, double n);
extern void fn_88834B28(lua_State *L, const u16 *s, u32 l); /* lua_pushlwstring */
const u16 *lua3_wmatch_8882FEF8(WMatchState *ms, const u16 *s, const u16 *p);
extern char lbl_880E1B28[]; /* "unfinished capture" */
extern char lbl_880E1B14[]; /* "too many captures" */
extern char lbl_880E1AA4[]; /* "invalid pattern capture" */
extern char lbl_880E1A8C[]; /* "invalid capture index" */

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

/* push_onecapture */
LUA2_NOINLINE void lua3_wpush_onecapture_8882F7D8(WMatchState *ms, int i)
{
    int l = ms->capture[i].len;
    if (l == CAP_UNFINISHED) lib3_luaL_error_8882E5F0(ms->L, lbl_880E1B28);
    if (l == CAP_POSITION)
        ts4_lua_pushnumber_888240B8(ms->L, (double)(ms->capture[i].init - ms->src_init + 1));
    else
        fn_88834B28(ms->L, ms->capture[i].init, l);
}

/* start_capture */
const u16 *lua3_wstart_capture_8882F870(WMatchState *ms, const u16 *s, const u16 *p, int what)
{
    const u16 *res;
    int level = ms->level;
    if (level >= LUA_MAXCAPTURES) lib3_luaL_error_8882E5F0(ms->L, lbl_880E1B14);
    ms->capture[level].init = s;
    ms->capture[level].len = what;
    ms->level = level + 1;
    if ((res = lua3_wmatch_8882FEF8(ms, s, p)) == 0) /* match failed? */
        ms->level--;                         /* undo capture */
    return res;
}

/* capture_to_close */
int lua3_wcapture_to_close_8882FA70(WMatchState *ms)
{
    int level = ms->level;
    for (level--; level >= 0; level--)
        if (ms->capture[level].len == CAP_UNFINISHED) return level;
    lib3_luaL_error_8882E5F0(ms->L, lbl_880E1AA4);
}

/* check_capture */
int lua3_wcheck_capture_8882FAD0(WMatchState *ms, int l)
{
    l -= '1';
    if (l < 0 || l >= ms->level || ms->capture[l].len == CAP_UNFINISHED)
        lib3_luaL_error_8882E5F0(ms->L, lbl_880E1A8C);
    return l;
}

extern int fn_88569800(int c, int mask); /* iswctype */
extern int lib3_lua_checkstack_88822028(lua_State *L, int size);
extern const u16 lbl_880E1B7C[]; /* L"-+ #0" (FLAGS) */
extern char lbl_880E1B88[];      /* "invalid format (width or precision too long)" */
extern char lbl_880E1BB8[];      /* "invalid format (too long)" */
extern char lbl_880E1B00[];      /* "unbalanced pattern" */
extern char lbl_880E1AE0[];      /* "malformed pattern (missing `]')" */
extern char lbl_880E1ABC[];      /* "malformed pattern (ends with `%')" */
extern char lbl_880E1C84[];      /* "stack overflow (%s)" */

/* Same-TU copy of the bounded wide copy: scanformat keeps a value in a volatile register across it. */
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

#define L_ESC '%'
#define MAX_FORMAT 20
#define wisdigit(c) fn_88569800((c), 4)

/* wcschr(FLAGS, c) != NULL */
LUA2_FORCEINLINE int isflag(u16 c)
{
    const u16 *p = lbl_880E1B7C;
    u32 ch = '-';
    do {
        if (ch == c) return 1;
        ch = *++p;
    } while (ch != 0);
    return 0;
}

/* scanformat */
const u16 *lua3_wscanformat_8882F698(lua_State *L, const u16 *strfrmt, u16 *form, int *hasprecision)
{
    const u16 *p = strfrmt;
    for (;;) { /* skip flags */
        u32 c = *p;
        if (!isflag((u16)c)) break;
        p++;
    }
    if (wisdigit(*p)) p++;  /* skip width */
    if (wisdigit(*p)) p++;  /* (2 digits at most) */
    if (*p == '.') {
        u32 c;
        p++;
        c = *p;
        *hasprecision = 1;
        if (wisdigit(c)) p++;  /* skip precision */
        if (wisdigit(*p)) p++; /* (2 digits at most) */
    }
    if (wisdigit(*p)) lib3_luaL_error_8882E5F0(L, lbl_880E1B88);
    if (p - strfrmt + 2 > MAX_FORMAT) lib3_luaL_error_8882E5F0(L, lbl_880E1BB8);
    form[0] = '%';
    lib3_lua_wstrncpy_8882EDF0(form + 1, strfrmt, p - strfrmt + 1);
    form[p - strfrmt + 2] = 0;
    return p;
}

/* matchbalance: %bxy */
const u16 *lua3_wmatchbalance_8882F8F0(WMatchState *ms, const u16 *s, const u16 *p)
{
    if (*p == 0 || *(p + 1) == 0) lib3_luaL_error_8882E5F0(ms->L, lbl_880E1B00);
    if (*s != *p) return 0;
    else {
        int b = *p;
        int e = *(p + 1);
        int cont = 1;
        while (++s < ms->src_end) {
            if (*s == e) {
                if (--cont == 0) return s + 1;
            } else if (*s == b)
                cont++;
        }
    }
    return 0; /* string ends out of balance */
}

/* luaI_classend */
const u16 *lua3_wclassend_8882F9B0(WMatchState *ms, const u16 *p)
{
    switch (*p++) {
    case L_ESC: {
        if (*p == '\0') lib3_luaL_error_8882E5F0(ms->L, lbl_880E1ABC);
        return p + 1;
    }
    case '[': {
        if (*p == '^') p++;
        do { /* look for a `]' */
            if (*p == '\0') lib3_luaL_error_8882E5F0(ms->L, lbl_880E1AE0);
            if (*(p++) == L_ESC && *p != '\0') p++; /* skip escapes (e.g. `%]') */
        } while (*p != ']');
        return p + 1;
    }
    default: {
        return p;
    }
    }
}

LUA2_FORCEINLINE void luaL_checkstack_(lua_State *L, int space, const char *mes)
{
    if (!lib3_lua_checkstack_88822028(L, space)) lib3_luaL_error_8882E5F0(L, lbl_880E1C84, mes);
}

/* push_captures */
int lua3_wpush_captures_8882FB28(WMatchState *ms, const u16 *s, const u16 *e)
{
    int i;
    luaL_checkstack_(ms->L, ms->level, lbl_880E1B14);
    if (ms->level == 0 && s) { /* no explicit captures? */
        fn_88834B28(ms->L, s, e - s); /* return whole match */
        return 1;
    } else { /* return all captures */
        for (i = 0; i < ms->level; i++) lua3_wpush_onecapture_8882F7D8(ms, i);
        return ms->level; /* number of strings pushed */
    }
}

/* match_capture, with check_capture expanded; the length check counts characters, memcmp bytes */
const u16 *lua3_wmatch_capture_8882FBD8(WMatchState *ms, const u16 *s, int l)
{
    u32 len;
    l -= '1';
    if (l < 0 || l >= ms->level || ms->capture[l].len == CAP_UNFINISHED)
        lib3_luaL_error_8882E5F0(ms->L, lbl_880E1A8C);
    len = ms->capture[l].len;
    if ((u32)(ms->src_end - s) >= len && memcmp(ms->capture[l].init, s, len) == 0)
        return s + len;
    else
        return 0;
}

extern int ts4_match_flag_char_8882EED0(int c, int cl); /* match_class */
extern int lib3_wmatchbracketclass_8882F1E8(int c, const u16 *p, const u16 *ec);
extern const u16 *lib3_wmin_expand_8882F488(WMatchState *ms, const u16 *s, const u16 *p, const u16 *ep);
extern const u16 *lib3_wmax_expand_8882F548(WMatchState *ms, const u16 *s, const u16 *p, const u16 *ep);
extern const u16 *ts4_if_call_seq_fn_8882FA70_8882FCA8(WMatchState *ms, const u16 *s, const u16 *p); /* end_capture */

#define CAP_UNFINISHED (-1)
#define CAP_POSITION (-2)

/* luaI_singlematch */
LUA2_FORCEINLINE int wsinglematch(int c, const u16 *p, const u16 *ep)
{
    switch (*p) {
    case '.': return 1; /* matches any char */
    case '%': return ts4_match_flag_char_8882EED0(c, *(p + 1));
    case '[': return lib3_wmatchbracketclass_8882F1E8(c, p, ep - 1);
    default: return (*p == (u16)c);
    }
}

/* match */
const u16 *lua3_wmatch_8882FEF8(WMatchState *ms, const u16 *s, const u16 *p)
{
init: /* using goto's to optimize tail recursion */
    switch (*p) {
    case '(': /* start capture */
        if (*(p + 1) == ')') /* position capture? */
            return lua3_wstart_capture_8882F870(ms, s, p + 2, CAP_POSITION);
        else
            return lua3_wstart_capture_8882F870(ms, s, p + 1, CAP_UNFINISHED);
    case ')': /* end capture */
        return ts4_if_call_seq_fn_8882FA70_8882FCA8(ms, s, p + 1);
    case '%':
        if (fn_88569800(*(p + 1), 4)) { /* capture? */
            s = lua3_wmatch_capture_8882FBD8(ms, s, *(p + 1));
            if (s == 0) return 0;
            p += 2;
            goto init; /* else return match(ms, s, p+2) */
        }
        if (*(p + 1) == 'b') { /* balanced string? */
            s = lua3_wmatchbalance_8882F8F0(ms, s, p + 2);
            if (s == 0) return 0;
            p += 4;
            goto init; /* else return match(ms, s, p+4); */
        }
        goto dflt;
    case '\0': /* end of pattern */
        return s; /* match succeeded */
    case '$':
        if (*(p + 1) == '\0') /* is the `$' the last char in pattern? */
            return (s == ms->src_end) ? s : 0; /* check end of string */
        else
            goto dflt;
    default:
    dflt: { /* it is a pattern item */
        const u16 *ep = lua3_wclassend_8882F9B0(ms, p); /* points to what is next */
        int m = s < ms->src_end && wsinglematch(*s, p, ep);
        switch (*ep) {
        case '?': { /* optional */
            const u16 *res;
            if (m && ((res = lua3_wmatch_8882FEF8(ms, s + 1, ep + 1)) != 0)) return res;
            p = ep + 1;
            goto init; /* else return match(ms, s, ep+1); */
        }
        case '*': /* 0 or more repetitions */
            return lib3_wmax_expand_8882F548(ms, s, p, ep);
        case '+': /* 1 or more repetitions */
            return (m ? lib3_wmax_expand_8882F548(ms, s + 1, p, ep) : 0);
        case '-': /* 0 or more repetitions (minimum) */
            return lib3_wmin_expand_8882F488(ms, s, p, ep);
        default:
            if (!m) return 0;
            s++;
            p = ep;
            goto init; /* else return match(ms, s+1, ep); */
        }
    }
    }
}
