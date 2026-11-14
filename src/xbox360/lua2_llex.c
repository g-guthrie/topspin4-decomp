/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* llex.c: LuaPlus lexer (16-bit characters from wide streams, refcounted reserved words). */
#include "lua2_lparser.h"
#ifdef _MSC_VER
extern unsigned int strlen(const char *s);
extern int memcmp(const void *a, const void *b, unsigned int n);
#pragma intrinsic(strlen, memcmp)
#else
#include <string.h>
#endif

/* LuaPlus ZIO: a wide stream delivers each character as two bytes, high byte first. */
typedef struct ZIO {
    u32 n;
    const char *p;
    void *reader;
    void *data;
    const char *name;
    int wide;
} ZIO;

#define EOZ (-1)
#define zgetc(z) (((z)->n--) > 0 ? (int)((unsigned char)(*(z)->p++)) : ex3_luaZ_fill_8880C040(z))
#define NUM_RESERVED 22
#define MAXSRC 80
#define LUA_ERRSYNTAX 3

extern int ex3_luaZ_fill_8880C040(ZIO *z);
extern char *fn_8880BFB0(lua_State *L, Mbuffer *buff, u32 n); /* luaZ_openspace */
extern TString *lua2_newlstr_88812EE0(lua_State *L, const char *str, u32 l, u32 h); /* newlstr */
extern void fn_88569D30(void *jb, int v);                                 /* longjmp */
extern LUA2_NORETURN void ts4_tailcall_fn_88564208_885643D0(int status); /* exit */

extern const char *const lbl_880C9858[]; /* token2string */

/* luaO_pushfstring: callers only get the original frame when the variadic body is visible. */
LUA2_LOCAL const char *ts4_forward_varargs_88818C40(lua_State *L, const char *fmt, ...)
{
    const char *msg;
    va_list argp;
    va_start(argp, fmt);
    msg = lua3_luaO_pushvfstring_888188F8(L, fmt, argp);
    va_end(argp);
    return msg;
}
extern char lbl_880E18F8[];              /* "%c" */
extern char lbl_880E2868[];              /* "too many %s (limit=%d)" */
extern char lbl_880E2880[];              /* "%s:%d: %s near `%s'" */
extern char lbl_880E2894[];              /* "lines in a chunk" */
extern char lbl_880E28A8[];              /* "ambiguous syntax (decimal point x string concatenation)" */
extern char lbl_880E28E0[];              /* "malformed number" */
extern char lbl_880E28F4[];              /* "malformed integer" */
extern int ts4_if_fn_88567730(int c);    /* tolower */
extern int lua3_luaO_str2d_88818190(const char *s, double *result); /* luaO_str2d */

/* next: read one character (two bytes from a wide stream) */
#define lsz(LS) ((ZIO *)(LS)->z)
LUA2_NOINLINE int lua2_next_88819008(LexState *LS)
{
    int c = zgetc(lsz(LS));
    if (c == EOZ) return LS->current = EOZ;
    if (lsz(LS)->wide) {
        union {
            unsigned char b[2];
            u16 w;
        } u;
        u.b[0] = (unsigned char)c;
        c = zgetc(lsz(LS));
        if (c == EOZ) return LS->current = EOZ;
        u.b[1] = (unsigned char)c;
        c = u.w;
    }
    return LS->current = c;
}

/* Inline copy for the call sites the original build expanded. */
LUA2_FORCEINLINE void next_inl(LexState *LS)
{
    int c = zgetc(lsz(LS));
    if (c == EOZ) {
        LS->current = EOZ;
        return;
    }
    if (!lsz(LS)->wide)
        LS->current = c;
    else {
        union {
            unsigned char b[2];
            u16 w;
        } u;
        u.b[0] = (unsigned char)c;
        c = zgetc(lsz(LS));
        if (c == EOZ) {
            LS->current = EOZ;
            return;
        }
        u.b[1] = (unsigned char)c;
        LS->current = u.w;
    }
}

LUA2_FORCEINLINE TString *luaS_newlstr_inl(lua_State *L, const char *str, u32 l)
{
    GCheader *o;
    u32 h = (u32)l;
    u32 step = (l >> 5) + 1;
    u32 l1;
    for (l1 = l; l1 >= step; l1 -= step)
        h = h ^ ((h << 5) + (h >> 2) + (unsigned char)str[l1 - 1]);
    for (o = G(L)->strt.hash[h & (G(L)->strt.size - 1)]; o != 0; o = o->next) {
        TString *ts = (TString *)o;
        if (o->tt == LUA2_TSTRING && ts->len == l && memcmp(str, getstr(ts), l) == 0)
            return ts;
    }
    return lua2_newlstr_88812EE0(L, str, l, h);
}

/* luaX_init */
void lua2_luaX_init_88819370(lua_State *L)
{
    int i;
    for (i = 0; i < NUM_RESERVED; i++) {
        TString *ts = luaS_newlstr_inl(L, lbl_880C9858[i], strlen(lbl_880C9858[i]));
        ts->h.marked |= 0x10; /* luaS_fix: reserved words are never collected */
        ts->h.refs = 1;
        ts->reserved = (lu_byte)(i + 1); /* reserved word */
    }
}

/* luaX_token2str */
LUA2_NOINLINE const char *lua2_luaX_token2str_888194C0(LexState *ls, int token)
{
    if (token < TK_AND)
        return ts4_forward_varargs_88818C40(ls->L, lbl_880E18F8, token);
    else
        return lbl_880C9858[token - TK_AND];
}

/* luaX_errorline */
LUA2_NOINLINE LUA2_NORETURN void lua2_luaX_errorline_88819520(LexState *ls, const char *s, const char *token, int line)
{
    lua_State *L = ls->L;
    char buff[MAXSRC];
    ts4_forward_varargs_88818C40(L, lbl_880E2880, buff, line, s, token);
    if (L->errorJmp) {
        L->errorJmp->status = LUA_ERRSYNTAX;
        fn_88569D30(L->errorJmp->b, 1);
    }
    G(L)->panic(L);
    ts4_tailcall_fn_88564208_885643D0(1);
}

/* luaX_lexerror */
LUA2_NOINLINE void lua2_luaX_lexerror_88819598(LexState *ls, const char *s, int token)
{
    if (token == TK_EOS) {
        const char *t = lua2_luaX_token2str_888194C0(ls, token);
        lua2_luaX_errorline_88819520(ls, s, t, ls->linenumber);
    } else
        lua2_luaX_errorline_88819520(ls, s, ls->buff->buffer, ls->linenumber);
}

/* luaX_lexerror for a token other than <eof>, as expanded at its call sites */
#define lexerror_tok(ls, s) lua2_luaX_errorline_88819520(ls, s, (ls)->buff->buffer, (ls)->linenumber)

/* luaX_syntaxerror */
LUA2_NOINLINE void lua2_luaX_syntaxerror_888195F0(LexState *ls, const char *msg)
{
    const char *lasttoken;
    switch (ls->t.token) {
    case TK_NAME:
        lasttoken = getstr(ls->t.seminfo.ts);
        break;
    case TK_STRING:
    case TK_NUMBER:
        lasttoken = ls->buff->buffer;
        break;
    default:
        lasttoken = lua2_luaX_token2str_888194C0(ls, ls->t.token);
        break;
    }
    lua2_luaX_errorline_88819520(ls, msg, lasttoken, ls->linenumber);
}

/* luaX_checklimit, with the comparison left in its callers */
LUA2_NOINLINE void lua2_luaX_errorlimit_88819660(LexState *ls, int limit, const char *msg)
{
    msg = ts4_forward_varargs_88818C40(ls->L, lbl_880E2868, msg, limit);
    lua2_luaX_syntaxerror_888195F0(ls, msg);
}

/* luaX_setinput */
void lua2_luaX_setinput_88819238(lua_State *L, LexState *LS, ZIO *z, TString *source)
{
    LS->L = L;
    LS->lookahead.token = TK_EOS; /* no look-ahead token */
    LS->z = z;
    LS->fs = 0;
    LS->linenumber = 1;
    LS->lastline = 1;
    LS->source = source;
    lua2_next_88819008(LS); /* read first char */
    if (LS->current == '#') {
        do { /* skip first line */
            next_inl(LS);
        } while (LS->current != '\n' && LS->current != EOZ);
    }
}

/* inclinenumber */
LUA2_NOINLINE void lua2_inclinenumber_88819B50(LexState *LS)
{
    lua2_next_88819008(LS); /* skip `\n' */
    ++LS->linenumber;
    if (LS->linenumber > MAX_INT)
        lua2_luaX_syntaxerror_888195F0(LS, ts4_forward_varargs_88818C40(LS->L, lbl_880E2868, lbl_880E2894, MAX_INT));
}

#define EXTRABUFF 32
#define LUA_MINBUFFER 32

LUA2_FORCEINLINE void luaZ_openspace_inl(lua_State *L, Mbuffer *buff, u32 n)
{
    if (n > buff->buffsize) {
        int old = L->inrealloc;
        if (n < LUA_MINBUFFER) n = LUA_MINBUFFER;
        L->inrealloc = 1;
        buff->buffer = (char *)fn_889CE718(L, buff->buffer, buff->buffsize, n);
        L->inrealloc = old;
        buff->buffsize = n;
    }
}

/* LuaPlus reserves room for a wide character and its terminator. */
#define checkbuffer(LS, len) \
    if (((len) + 5) > (LS)->buff->buffsize) fn_8880BFB0((LS)->L, (LS)->buff, (len) + EXTRABUFF)
#define checkbuffer_inl(LS, len) \
    if (((len) + 5) > (LS)->buff->buffsize) luaZ_openspace_inl((LS)->L, (LS)->buff, (len) + EXTRABUFF)
#define save(LS, c, l) ((LS)->buff->buffer[l++] = (char)(c))
#define save_and_next(LS, l) (save(LS, LS->current, l), lua2_next_88819008(LS))

/* readname: an optional first character, then letters, digits and `_' */
LUA2_NOINLINE u32 lua2_readname_888190F0(LexState *LS, char c)
{
    u32 l = 0;
    checkbuffer(LS, l);
    if (c) {
        checkbuffer(LS, l);
        save(LS, c, l);
    }
    do {
        checkbuffer_inl(LS, l);
        save_and_next(LS, l);
    } while ((LS->current >= 'a' && LS->current <= 'z') || (LS->current >= 'A' && LS->current <= 'Z') ||
             (LS->current >= '0' && LS->current <= '9') || LS->current == '_');
    save(LS, '\0', l);
    return l - 1;
}

#define isdigit_(c) ((c) >= '0' && (c) <= '9')
#define isxlower_(c) ((c) >= 'a' && (c) <= 'f')

/* read_numeral: LuaPlus adds 0x hexadecimal integers (at most eight digits) */
LUA2_NOINLINE int lua2_read_numeral_88819698(LexState *LS, int comma, SemInfo *seminfo)
{
    int lead0 = (LS->current == '0');
    int isfloat = 0;
    u32 l = 0;
    checkbuffer(LS, l);
    if (comma) {
        save(LS, '.', l);
        isfloat = 1;
    }
    if (lead0) {
        lua2_next_88819008(LS);
        if (LS->current == 'x') {
            int n = 0;
            int i = 0;
            int c;
            lua2_next_88819008(LS);
            do {
                c = ts4_if_fn_88567730(LS->current);
                if (isdigit_(c))
                    n = n * 16 + (c - '0');
                else if (isxlower_(c))
                    n = n * 16 + (c - 'a' + 10);
                lua2_next_88819008(LS);
                c = ts4_if_fn_88567730(LS->current);
                i++;
            } while (i < 8 && (isdigit_(c) || isxlower_(c)));
            seminfo->r = (double)n;
            return TK_NUMBER;
        }
        checkbuffer_inl(LS, 1);
        save(LS, '0', l);
    }
    while (isdigit_(LS->current)) {
        checkbuffer_inl(LS, l);
        save_and_next(LS, l);
    }
    if (LS->current == '.') {
        isfloat = 1;
        save_and_next(LS, l);
        if (LS->current == '.') {
            save_and_next(LS, l);
            save(LS, '\0', l);
            lexerror_tok(LS, lbl_880E28A8);
        }
    }
    while (isdigit_(LS->current)) {
        checkbuffer_inl(LS, l);
        save_and_next(LS, l);
    }
    if (LS->current == 'e' || LS->current == 'E') {
        isfloat = 1;
        save_and_next(LS, l); /* read `E' */
        if (LS->current == '+' || LS->current == '-') save_and_next(LS, l); /* optional exponent sign */
        while (isdigit_(LS->current)) {
            checkbuffer_inl(LS, l);
            save_and_next(LS, l);
        }
    }
    save(LS, '\0', l);
    if (isfloat) {
        if (!lua3_luaO_str2d_88818190(LS->buff->buffer, &seminfo->r)) lexerror_tok(LS, lbl_880E28E0);
    } else {
        if (!lua3_luaO_str2d_88818190(LS->buff->buffer, &seminfo->r)) lexerror_tok(LS, lbl_880E28F4);
    }
    return TK_NUMBER;
}

extern char lbl_880E2938[]; /* "unfinished string" */
extern char lbl_880E294C[]; /* "escape sequence too large" */
extern TString *lua2_luaS_newlstr_888131A0(lua_State *L, const char *str, u32 l);
extern TString *lua2_luaS_newlwstr_88812FC8(lua_State *L, const unsigned short *str, u32 l);

/* luaX_lexerror(LS, s, TK_EOS), as expanded at its call sites */
#define lexerror_eos(ls, s) lua2_luaX_errorline_88819520(ls, s, lbl_880C9858[TK_EOS - TK_AND], (ls)->linenumber)

/* read_string: LuaPlus adds \x hexadecimal escapes (at most two digits) */
LUA2_NOINLINE void lua2_read_string_8881A028(LexState *LS, int del, SemInfo *seminfo)
{
    u32 l = 0;
    checkbuffer(LS, l);
    save_and_next(LS, l);
    while (LS->current != del) {
        checkbuffer_inl(LS, l);
        switch (LS->current) {
        case EOZ:
            save(LS, '\0', l);
            lexerror_eos(LS, lbl_880E2938);
        case '\n':
            save(LS, '\0', l);
            lexerror_tok(LS, lbl_880E2938);
        case '\\':
            lua2_next_88819008(LS); /* do not save the `\' */
            switch (LS->current) {
            case 'a': save(LS, '\a', l); lua2_next_88819008(LS); break;
            case 'b': save(LS, '\b', l); lua2_next_88819008(LS); break;
            case 'f': save(LS, '\f', l); lua2_next_88819008(LS); break;
            case 'n': save(LS, '\n', l); lua2_next_88819008(LS); break;
            case 'r': save(LS, '\r', l); lua2_next_88819008(LS); break;
            case 't': save(LS, '\t', l); lua2_next_88819008(LS); break;
            case 'v': save(LS, '\v', l); lua2_next_88819008(LS); break;
            case '\n': save(LS, '\n', l); lua2_inclinenumber_88819B50(LS); break;
            case EOZ: break; /* will raise an error next loop */
            case 'x': {
                int c;
                lua2_next_88819008(LS);
                c = ts4_if_fn_88567730(LS->current);
                if (isdigit_(c) || isxlower_(c)) {
                    int n = 0;
                    int i = 0;
                    do {
                        c = ts4_if_fn_88567730(LS->current);
                        if (isdigit_(c))
                            n = n * 16 + (c - '0');
                        else if (isxlower_(c))
                            n = n * 16 + (c - 'a' + 10);
                        lua2_next_88819008(LS);
                        c = ts4_if_fn_88567730(LS->current);
                        i++;
                    } while (i < 2 && (isdigit_(c) || isxlower_(c)));
                    save(LS, n, l);
                } else
                    save(LS, 'x', l);
                break;
            }
            default:
                if (!isdigit_(LS->current))
                    save_and_next(LS, l); /* handles \\, \", \', and \? */
                else { /* \xxx */
                    int c = 0;
                    int i = 0;
                    do {
                        c = 10 * c + (LS->current - '0');
                        lua2_next_88819008(LS);
                    } while (++i < 3 && isdigit_(LS->current));
                    if (c > 255) {
                        save(LS, '\0', l);
                        lexerror_tok(LS, lbl_880E294C);
                    }
                    save(LS, c, l);
                }
            }
            break;
        default:
            save_and_next(LS, l);
        }
    }
    save_and_next(LS, l); /* skip delimiter */
    save(LS, '\0', l);
    seminfo->ts = lua2_luaS_newlstr_888131A0(LS->L, LS->buff->buffer + 1, l - 3);
}

/* Wide strings keep 16-bit characters in the byte buffer; l counts bytes. */
#define wsave(LS, c, l) (*(u16 *)((LS)->buff->buffer + (l)) = (u16)(c), l += 2)
#define wsave_and_next(LS, l) (wsave(LS, LS->current, l), lua2_next_88819008(LS))
#define wcheckbuffer_inl(LS, len) checkbuffer_inl(LS, (len) * 2)

/* read_wstring: LuaPlus L"..." literals; \x takes up to four hexadecimal digits */
LUA2_NOINLINE void lua2_read_wstring_88819BC0(LexState *LS, int del, SemInfo *seminfo)
{
    u32 l = 0;
    checkbuffer(LS, l);
    wsave_and_next(LS, l);
    while (LS->current != del) {
        wcheckbuffer_inl(LS, l);
        switch (LS->current) {
        case EOZ:
            wsave(LS, '\0', l);
            lexerror_eos(LS, lbl_880E2938);
        case '\n':
            wsave(LS, '\0', l);
            lexerror_tok(LS, lbl_880E2938);
        case '\\':
            lua2_next_88819008(LS); /* do not save the `\' */
            switch (LS->current) {
            case 'a': wsave(LS, '\a', l); lua2_next_88819008(LS); break;
            case 'b': wsave(LS, '\b', l); lua2_next_88819008(LS); break;
            case 'f': wsave(LS, '\f', l); lua2_next_88819008(LS); break;
            case 'n': wsave(LS, '\n', l); lua2_next_88819008(LS); break;
            case 'r': wsave(LS, '\r', l); lua2_next_88819008(LS); break;
            case 't': wsave(LS, '\t', l); lua2_next_88819008(LS); break;
            case 'v': wsave(LS, '\v', l); lua2_next_88819008(LS); break;
            case '\n': wsave(LS, '\n', l); lua2_inclinenumber_88819B50(LS); break;
            case EOZ: break; /* will raise an error next loop */
            case 'x': {
                int c;
                lua2_next_88819008(LS);
                c = ts4_if_fn_88567730(LS->current);
                if (isdigit_(c) || isxlower_(c)) {
                    int n = 0;
                    int i = 0;
                    do {
                        c = ts4_if_fn_88567730(LS->current);
                        if (isdigit_(c))
                            n = n * 16 + (c - '0');
                        else if (isxlower_(c))
                            n = n * 16 + (c - 'a' + 10);
                        lua2_next_88819008(LS);
                        c = ts4_if_fn_88567730(LS->current);
                        i++;
                    } while (i < 4 && (isdigit_(c) || isxlower_(c)));
                    wsave(LS, n, l);
                } else
                    save(LS, 'x', l); /* LuaPlus stores a single byte here */
                break;
            }
            default:
                if (!isdigit_(LS->current))
                    wsave_and_next(LS, l); /* handles \\, \", \', and \? */
                else { /* \xxx */
                    int c = 0;
                    int i = 0;
                    do {
                        c = 10 * c + (LS->current - '0');
                        lua2_next_88819008(LS);
                    } while (++i < 3 && isdigit_(LS->current));
                    if (c > 255) {
                        wsave(LS, '\0', l);
                        lexerror_tok(LS, lbl_880E294C);
                    }
                    wsave(LS, c, l);
                }
            }
            break;
        default:
            wsave_and_next(LS, l);
        }
    }
    wsave_and_next(LS, l); /* skip delimiter */
    wsave(LS, '\0', l);
    seminfo->ts = lua2_luaS_newlwstr_88812FC8(LS->L, (const unsigned short *)(LS->buff->buffer + 2), (l - 6) / 2);
}

extern char lbl_880E2908[]; /* "unfinished long string" */
extern char lbl_880E2920[]; /* "unfinished long comment" */

/* read_long_string: [[...]] with nesting; a null seminfo skips a long comment */
LUA2_NOINLINE void lua2_read_long_string_8881A488(LexState *LS, SemInfo *seminfo)
{
    int cont = 0;
    u32 l = 0;
    checkbuffer(LS, l);
    save(LS, '[', l);      /* save first `[' */
    save_and_next(LS, l); /* pass the second `[' */
    if (LS->current == '\n') /* string starts with a newline? */
        lua2_inclinenumber_88819B50(LS); /* skip it */
    for (;;) {
        checkbuffer_inl(LS, l);
        switch (LS->current) {
        case EOZ:
            save(LS, '\0', l);
            lexerror_eos(LS, (seminfo) ? lbl_880E2908 : lbl_880E2920);
            break; /* to avoid warnings */
        case '[':
            save_and_next(LS, l);
            if (LS->current == '[') {
                cont++;
                save_and_next(LS, l);
            }
            continue;
        case ']':
            save_and_next(LS, l);
            if (LS->current == ']') {
                if (cont == 0) goto endloop;
                cont--;
                save_and_next(LS, l);
            }
            continue;
        case '\n':
            save(LS, '\n', l);
            lua2_inclinenumber_88819B50(LS);
            if (!seminfo) l = 0; /* reset buffer to avoid wasting space */
            continue;
        default:
            save_and_next(LS, l);
        }
    }
endloop:
    save_and_next(LS, l); /* skip the second `]' */
    save(LS, '\0', l);
    if (seminfo)
        seminfo->ts = lua2_luaS_newlstr_888131A0(LS->L, LS->buff->buffer + 2, l - 5);
}

extern char lbl_880E2968[]; /* "char(%d)" */
extern char lbl_880E2974[]; /* "invalid wide char" */
extern char lbl_880E2988[]; /* "invalid control char" */

/* luaX_lex: LuaPlus adds L"..." wide strings and the << and >> operators */
int lua2_luaX_lex_8881A6E8(LexState *LS, SemInfo *seminfo)
{
    for (;;) {
        switch (LS->current) {
        case '\n':
            lua2_inclinenumber_88819B50(LS);
            continue;
        case '-':
            lua2_next_88819008(LS);
            if (LS->current != '-') return '-';
            /* else is a comment */
            lua2_next_88819008(LS);
            if (LS->current == '[' && (lua2_next_88819008(LS), LS->current == '['))
                lua2_read_long_string_8881A488(LS, 0); /* long comment */
            else /* short comment */
                while (LS->current != '\n' && LS->current != EOZ)
                    lua2_next_88819008(LS);
            continue;
        case '[':
            lua2_next_88819008(LS);
            if (LS->current != '[') return '[';
            lua2_read_long_string_8881A488(LS, seminfo);
            return TK_STRING;
        case '=':
            lua2_next_88819008(LS);
            if (LS->current != '=') return '=';
            lua2_next_88819008(LS);
            return TK_EQ;
        case '<':
            lua2_next_88819008(LS);
            if (LS->current == '<') {
                lua2_next_88819008(LS);
                return TK_SHL;
            }
            if (LS->current != '=') return '<';
            lua2_next_88819008(LS);
            return TK_LE;
        case '>':
            lua2_next_88819008(LS);
            if (LS->current == '>') {
                lua2_next_88819008(LS);
                return TK_SHR;
            }
            if (LS->current != '=') return '>';
            lua2_next_88819008(LS);
            return TK_GE;
        case '~':
            lua2_next_88819008(LS);
            if (LS->current != '=') return '~';
            lua2_next_88819008(LS);
            return TK_NE;
        case '"':
        case '\'':
            lua2_read_string_8881A028(LS, LS->current, seminfo);
            return TK_STRING;
        case '.':
            lua2_next_88819008(LS);
            if (LS->current == '.') {
                lua2_next_88819008(LS);
                if (LS->current == '.') {
                    lua2_next_88819008(LS);
                    return TK_DOTS; /* ... */
                }
                return TK_CONCAT; /* .. */
            } else if (!isdigit_(LS->current))
                return '.';
            return lua2_read_numeral_88819698(LS, 1, seminfo);
        case EOZ:
            return TK_EOS;
        default: {
            int c = LS->current;
            if ((c >= '\t' && c <= '\r') || c == ' ') {
                lua2_next_88819008(LS);
                continue;
            } else if (isdigit_(c))
                return lua2_read_numeral_88819698(LS, 0, seminfo);
            else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
                /* identifier or reserved word */
                TString *ts;
                char first = 0;
                if (c == 'L') {
                    lua2_next_88819008(LS);
                    if (LS->current == '"') {
                        lua2_read_wstring_88819BC0(LS, '"', seminfo);
                        return TK_WSTRING;
                    }
                    first = 'L';
                }
                ts = lua2_luaS_newlstr_888131A0(LS->L, LS->buff->buffer, lua2_readname_888190F0(LS, first));
                if (ts->reserved) /* reserved word? */
                    return ts->reserved - 1 + TK_AND;
                seminfo->ts = ts;
                return TK_NAME;
            } else {
                if (c >= 0xFF)
                    {
                    const char *t = ts4_forward_varargs_88818C40(LS->L, lbl_880E2968, c);
                    lua2_luaX_errorline_88819520(LS, lbl_880E2974, t, LS->linenumber);
                }
                if ((c >= 0 && c <= 31) || c == 127)
                    {
                    const char *t = ts4_forward_varargs_88818C40(LS->L, lbl_880E2968, c);
                    lua2_luaX_errorline_88819520(LS, lbl_880E2988, t, LS->linenumber);
                }
                lua2_next_88819008(LS);
                return c; /* single-char tokens (+ - / ...) */
            }
        }
        }
    }
}
