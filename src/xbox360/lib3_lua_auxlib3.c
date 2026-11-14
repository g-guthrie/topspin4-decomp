/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* Altered to match Swing_DLL.xex. lauxlib.c string argument checks. */
#include "d3d_lua.h"
#ifdef _MSC_VER
extern unsigned int strlen(const char *s);
#pragma intrinsic(strlen)
#else
#include <string.h>
#endif

typedef Ts4LuaState lua_State;

/* Kept out of line but visible: the callers below depend on LTCG knowing it does not retain len. */
#ifdef _MSC_VER
#define LIB3_NOINLINE __declspec(noinline)
#else
#define LIB3_NOINLINE
#endif

TS4_NORETURN extern void lib3_luaL_typerror_8882E950(lua_State *L, int narg, const char *tname);
extern int lib3_lua_type_88822738(lua_State *L, int idx);
extern const char *lib3_lua_tostring_88822888(lua_State *L, int idx);
extern unsigned int lib3_lua_strlen_888222F0(lua_State *L, int idx);
extern const char *lbl_880C9684[];
extern char lbl_880E17A4[];

#define LIB3_TYPENAME(t) ((t) == -1 ? lbl_880E17A4 : lbl_880C9684[t])

/* luaL_checklstring */
LIB3_NOINLINE const char *lib3_luaL_checklstring_8882EB20(lua_State *L, int narg, unsigned int *len)
{
    const char *s = lib3_lua_tostring_88822888(L, narg);
    if (!s) lib3_luaL_typerror_8882E950(L, narg, lbl_880C9684[4]);
    if (len) *len = lib3_lua_strlen_888222F0(L, narg);
    return s;
}

/* luaL_checktype */
void lib3_luaL_checktype_8882EB88(lua_State *L, int narg, int t)
{
    if (lib3_lua_type_88822738(L, narg) != t)
        lib3_luaL_typerror_8882E950(L, narg, LIB3_TYPENAME(t));
}

typedef struct Lib3Buffer { char *p; int lvl; int wide; lua_State *L; char buffer[0x200]; } Lib3Buffer;
extern double ts4_lua_opt_number_default_8882EA98(lua_State *L, int narg);
extern void ts4_lua_pushnumber_888240B8(lua_State *L, double n);
extern void lib3_luaL_addlstring_8882E828(Lib3Buffer *B, const char *s, unsigned int l);
extern int lib3_emptybuffer_8882DE88(Lib3Buffer *B);
extern void ts4_lua_concat_88822DB0(lua_State *L, int n);
int lib3_str_rep_888286C8(lua_State *L)
{
    unsigned int l;
    Lib3Buffer b;
    const char *s = lib3_luaL_checklstring_8882EB20(L, 1, &l);
    int n = (int)ts4_lua_opt_number_default_8882EA98(L, 2);
    b.L = L; b.p = b.buffer; b.wide = 0; b.lvl = 0;
    while (n-- > 0)
        lib3_luaL_addlstring_8882E828(&b, s, l);
    lib3_emptybuffer_8882DE88(&b); ts4_lua_concat_88822DB0(b.L, b.lvl);
    return 1;
}
int lib3_str_len_888288C0(lua_State *L)
{
    unsigned int l;
    lib3_luaL_checklstring_8882EB20(L, 1, &l);
    ts4_lua_pushnumber_888240B8(L, (double)l);
    return 1;
}
extern void lib3_adjuststack_8882DBA8(Lib3Buffer *B);
extern int ts4_ascii_lower_to_upper_88564790(int c);
extern int ts4_if_fn_88567730(int c);
int lib3_str_upper_88828760(lua_State *L)
{
    unsigned int l;
    unsigned int i;
    Lib3Buffer b;
    const char *s = lib3_luaL_checklstring_8882EB20(L, 1, &l);
    b.L = L; b.p = b.buffer; b.wide = 0; b.lvl = 0;
    for (i = 0; i < l; i++) {
        if (b.p >= b.buffer + 0x200 && lib3_emptybuffer_8882DE88(&b)) lib3_adjuststack_8882DBA8(&b);
        *b.p++ = (char)ts4_ascii_lower_to_upper_88564790((unsigned char)s[i]);
    }
    lib3_emptybuffer_8882DE88(&b); ts4_lua_concat_88822DB0(b.L, b.lvl);
    return 1;
}
int lib3_str_lower_88828810(lua_State *L)
{
    unsigned int l;
    unsigned int i;
    Lib3Buffer b;
    const char *s = lib3_luaL_checklstring_8882EB20(L, 1, &l);
    b.L = L; b.p = b.buffer; b.wide = 0; b.lvl = 0;
    for (i = 0; i < l; i++) {
        if (b.p >= b.buffer + 0x200 && lib3_emptybuffer_8882DE88(&b)) lib3_adjuststack_8882DBA8(&b);
        *b.p++ = (char)ts4_if_fn_88567730((unsigned char)s[i]);
    }
    lib3_emptybuffer_8882DE88(&b); ts4_lua_concat_88822DB0(b.L, b.lvl);
    return 1;
}

extern char lbl_880E2444[];

#define LIB3_PUTCHAR(B, c) \
    do { \
        if ((B)->p >= (B)->buffer + 0x200 && lib3_emptybuffer_8882DE88(B)) lib3_adjuststack_8882DBA8(B); \
        *(B)->p++ = (char)(c); \
    } while (0)

/* luaI_addquoted */
void lib3_luaI_addquoted_88828190(lua_State *L, Lib3Buffer *b, int arg)
{
    unsigned int l;
    const char *s = lib3_luaL_checklstring_8882EB20(L, arg, &l);
    LIB3_PUTCHAR(b, '"');
    while (l--) {
        switch (*s) {
        case '"': case '\\': case '\n':
            LIB3_PUTCHAR(b, '\\');
            LIB3_PUTCHAR(b, *s);
            break;
        case '\0': {
            const char *q = lbl_880E2444;
            unsigned int k = 4;
            while (k--) LIB3_PUTCHAR(b, *q++);
            break;
        }
        default:
            LIB3_PUTCHAR(b, *s);
            break;
        }
        s++;
    }
    LIB3_PUTCHAR(b, '"');
}

extern const unsigned short *ts4_get_u32_lbl_88C311F4_88567FC8(void);
#define LIB3_ISDIGIT(c) (ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x4)
#define LIB3_ISHEXLOWER(c) ((c) >= 'a' && (c) <= 'f')

/* Game addition to the string library: expand C-style escapes (\a \b \f \n \r \t \v,
   \xHH (\xHHHH when wide), \ddd). When the second argument is non-zero every plain or
   simply escaped character is written twice, as a 16-bit unit. */
int lib3_str_unescape_88827170(lua_State *L)
{
    unsigned int l = 0;
    unsigned int i;
    int wide;
    Lib3Buffer b;
    const char *s = lib3_luaL_checklstring_8882EB20(L, 1, &l);
    wide = (int)ts4_lua_opt_number_default_8882EA98(L, 2) != 0;
    b.L = L; b.p = b.buffer; b.wide = 0; b.lvl = 0;
    for (i = 0; i < l; i++) {
        int pad = 1;
        if (s[i] != '\\') {
            LIB3_PUTCHAR(&b, s[i]);
        } else {
            switch (s[++i]) {
            case 'a': LIB3_PUTCHAR(&b, '\a'); break;
            case 'b': LIB3_PUTCHAR(&b, '\b'); break;
            case 'f': LIB3_PUTCHAR(&b, '\f'); break;
            case 'n': LIB3_PUTCHAR(&b, '\n'); break;
            case 'r': LIB3_PUTCHAR(&b, '\r'); break;
            case 't': LIB3_PUTCHAR(&b, '\t'); break;
            case 'v': LIB3_PUTCHAR(&b, '\v'); break;
            case 'x': {
                int c;
                i++;
                c = ts4_if_fn_88567730(s[i]);
                if (!LIB3_ISDIGIT(c) && !LIB3_ISHEXLOWER(c)) {
                    i--;
                    LIB3_PUTCHAR(&b, 'x');
                } else {
                    unsigned int max = wide ? 4 : 2;
                    int v = 0;
                    unsigned int k = 0;
                    do {
                        c = ts4_if_fn_88567730(s[i]);
                        if (LIB3_ISDIGIT(c)) v = v * 16 + c - '0';
                        else if (LIB3_ISHEXLOWER(c)) v = v * 16 + c - 'a' + 10;
                        i++;
                        k++;
                        c = ts4_if_fn_88567730(s[i]);
                    } while (k < max && (LIB3_ISDIGIT(c) || LIB3_ISHEXLOWER(c)));
                    LIB3_PUTCHAR(&b, v);
                    LIB3_PUTCHAR(&b, v >> 8);
                    pad = 0;
                }
                break;
            }
            default:
                if (!LIB3_ISDIGIT((int)s[i])) {
                    LIB3_PUTCHAR(&b, s[i]);
                } else {
                    int c = s[i];
                    int v = 0;
                    int k = 0;
                    do {
                        v = v * 10 + c - '0';
                        k++;
                        i++;
                    } while (k < 3 && LIB3_ISDIGIT(c = s[i]));
                    LIB3_PUTCHAR(&b, v);
                }
                break;
            }
        }
        if (wide && pad) LIB3_PUTCHAR(&b, s[i]);
    }
    lib3_emptybuffer_8882DE88(&b); ts4_lua_concat_88822DB0(b.L, b.lvl);
    return 1;
}

extern const unsigned short *fn_888348A0(lua_State *L, int idx);
extern int fn_885635D0(char *buf, const char *fmt, ...);
extern char lbl_880E191C[];
extern char lbl_880E1928[];

/* Wide variant of luaL_checklstring. */
LIB3_NOINLINE const unsigned short *lib3_luaL_checklwstring_8882EA30(lua_State *L, int narg, unsigned int *len)
{
    const unsigned short *s = fn_888348A0(L, narg);
    if (!s) lib3_luaL_typerror_8882E950(L, narg, lbl_880C9684[9]);
    if (len) *len = lib3_lua_strlen_888222F0(L, narg);
    return s;
}

#define LIB3_ISPRINT(c) (ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x157)

/* luaI_addquoted extended for wide strings and C escapes (string.format "%q"). */
void lib3_luaI_addquoted_ex_88827758(lua_State *L, Lib3Buffer *b, int arg)
{
    unsigned int l;
    char wbuf[10];
    char buf[10];
    if (lib3_lua_type_88822738(L, arg) == 9) {
        const unsigned short *s = lib3_luaL_checklwstring_8882EA30(L, arg, &l);
        LIB3_PUTCHAR(b, 'L');
        LIB3_PUTCHAR(b, '"');
        while (l--) {
            switch (*s) {
            case '"': case '\\':
                LIB3_PUTCHAR(b, '\\');
                LIB3_PUTCHAR(b, *s);
                break;
            case '\a': LIB3_PUTCHAR(b, '\\'); LIB3_PUTCHAR(b, 'a'); break;
            case '\b': LIB3_PUTCHAR(b, '\\'); LIB3_PUTCHAR(b, 'b'); break;
            case '\f': LIB3_PUTCHAR(b, '\\'); LIB3_PUTCHAR(b, 'f'); break;
            case '\n': LIB3_PUTCHAR(b, '\\'); LIB3_PUTCHAR(b, 'n'); break;
            case '\r': LIB3_PUTCHAR(b, '\\'); LIB3_PUTCHAR(b, 'r'); break;
            case '\t': LIB3_PUTCHAR(b, '\\'); LIB3_PUTCHAR(b, 't'); break;
            case '\v': LIB3_PUTCHAR(b, '\\'); LIB3_PUTCHAR(b, 'v'); break;
            default:
                if (*s < 0x100 && LIB3_ISPRINT((unsigned char)*s)) {
                    LIB3_PUTCHAR(b, *s);
                } else {
                    fn_885635D0(wbuf, lbl_880E1928, *s);
                    lib3_luaL_addlstring_8882E828(b, wbuf, strlen(wbuf));
                }
                break;
            }
            s++;
        }
    } else {
        const char *s = lib3_luaL_checklstring_8882EB20(L, arg, &l);
        LIB3_PUTCHAR(b, '"');
        while (l--) {
            switch (*s) {
            case '"': case '\\':
                LIB3_PUTCHAR(b, '\\');
                LIB3_PUTCHAR(b, *s);
                break;
            case '\a': LIB3_PUTCHAR(b, '\\'); LIB3_PUTCHAR(b, 'a'); break;
            case '\b': LIB3_PUTCHAR(b, '\\'); LIB3_PUTCHAR(b, 'b'); break;
            case '\f': LIB3_PUTCHAR(b, '\\'); LIB3_PUTCHAR(b, 'f'); break;
            case '\n': LIB3_PUTCHAR(b, '\\'); LIB3_PUTCHAR(b, 'n'); break;
            case '\r': LIB3_PUTCHAR(b, '\\'); LIB3_PUTCHAR(b, 'r'); break;
            case '\t': LIB3_PUTCHAR(b, '\\'); LIB3_PUTCHAR(b, 't'); break;
            case '\v': LIB3_PUTCHAR(b, '\\'); LIB3_PUTCHAR(b, 'v'); break;
            default:
                if (LIB3_ISPRINT((unsigned char)*s)) {
                    LIB3_PUTCHAR(b, *s);
                } else {
                    fn_885635D0(buf, lbl_880E191C, (unsigned char)*s);
                    lib3_luaL_addlstring_8882E828(b, buf, strlen(buf));
                }
                break;
            }
            s++;
        }
    }
    LIB3_PUTCHAR(b, '"');
}

/* luaL_optlstring */
const char *lib3_luaL_optlstring_8882EBF0(lua_State *L, int narg, const char *def, unsigned int *len)
{
    if (lib3_lua_type_88822738(L, narg) <= 0) {
        if (len) *len = def ? strlen(def) : 0;
        return def;
    }
    return lib3_luaL_checklstring_8882EB20(L, narg, len);
}
