/* Derived from Lua 5.0.2 ldblib.c (MIT); see THIRD_PARTY_NOTICES.md */
/* ldblib.c: hook masks and upvalue access (lapi calls inlined by LTCG). */
#include "lua3.h"
#ifdef _MSC_VER
extern unsigned int strlen(const char *s);
extern int strcmp(const char *a, const char *b);
#pragma intrinsic(strlen, strcmp)
#else
#include <string.h>
#endif

#define LUA_MASKCALL 1
#define LUA_MASKRET 2
#define LUA_MASKLINE 4
#define LUA_MASKCOUNT 8

extern char *fn_88563500(const char *s, int c); /* strchr */
extern double ts4_lua_opt_number_default_8882EA98(lua_State *L, int narg); /* luaL_checknumber */
extern LUA3_NORETURN int lib3_luaL_typerror_8882E950(lua_State *L, int narg, const char *tname);
extern LUA3_NORETURN int lib3_luaL_argerror_8882E6B8(lua_State *L, int narg, const char *extramsg);
extern void ts4_lua_pushlstring_88823FC0(lua_State *L, const char *s, u32 len);
extern void ts4_lua_insert_88824438(lua_State *L, int idx);
extern const char *fn_88822BB8(lua_State *L, int n); /* lua_getupvalue(L, 1, n) */
extern const char *fn_88822AC8(lua_State *L, int n); /* lua_setupvalue(L, 1, n) */
extern const char *lbl_880C9684[]; /* luaT_typenames */
extern void ts4_lua_pushlightuserdata_88823C98(lua_State *L, void *p);
extern void ts4_lua_rawget_88823AE8(lua_State *L, int idx);
extern void ts4_lua_rawset_88823430(lua_State *L, int idx);
extern void ts4_lua_pushnil_88824188(lua_State *L);
extern void ts4_lua_pushnumber_888240B8(lua_State *L, double n);
extern void lua3_lua_settop_888246A8(lua_State *L, int idx);
extern void lua2_luaD_call_8881E258(lua_State *L, StkId func, int nresults);
extern const char *lbl_880C9734[]; /* hooknames; the KEY_HOOK byte sits just before it */
#define KEY_HOOK ((void *)((char *)lbl_880C9734 - 1))
extern char lbl_880C9733[]; /* KEY_HOOK, as gethook references it */
extern char lbl_880E2280[]; /* "external hook" */
extern char lbl_880E226C[]; /* "level out of range" */
extern void ts4_lua_pushvalue_88824248(lua_State *L, int idx);
extern void ts4_if_call_seq_fn_88822738_8882E8A0(lua_State *L, int narg); /* luaL_checkany */
extern int lua3_lua_getstack_8881EED0(lua_State *L, int level, lua_Debug *ar);
extern const char *lua3_lua_setlocal_8881FDF0(lua_State *L, const lua_Debug *ar, int n);
extern const char *lua3_lua_getlocal_88820020(lua_State *L, const lua_Debug *ar, int n);
extern const char *lib3_lua_tostring_88822888(lua_State *L, int idx);
extern const double g_ts4_script_constants[]; /* +0x58: 0.0 */
#define luaL_checkint(L, n) ((int)ts4_lua_opt_number_default_8882EA98((L), (n)))
extern char lbl_880E1C98[];        /* "value expected" */

/* luaA_indexAcceptable for idx > 0 */
LUA2_FORCEINLINE StkId index_acceptable(lua_State *L, int idx)
{
    if (idx > 0) {
        StkId o = L->base + (idx - 1);
        if (o >= L->top) return 0;
        return o;
    }
    return L->top + idx;
}

LUA2_FORCEINLINE int lua_type_(lua_State *L, int idx)
{
    StkId o = index_acceptable(L, idx);
    return (o == 0) ? -1 : ttype(o);
}

LUA2_FORCEINLINE int lua_iscfunction_(lua_State *L, int idx)
{
    StkId o = index_acceptable(L, idx);
    return (o == 0) ? 0 : (ttype(o) == LUA2_TFUNCTION && clvalue(o)->c.isC);
}

/* unmakemask */
LUA2_NOINLINE char *lua3_unmakemask_8882A3D0(int mask, char *smask)
{
    int i = 0;
    if (mask & LUA_MASKCALL) smask[i++] = 'c';
    if (mask & LUA_MASKRET) smask[i++] = 'r';
    if (mask & LUA_MASKLINE) smask[i++] = 'l';
    smask[i] = '\0';
    return smask;
}

/* makemask */
int lua3_makemask_8882A430(const char *smask, int count)
{
    int mask = 0;
    if (fn_88563500(smask, 'c')) mask |= LUA_MASKCALL;
    if (fn_88563500(smask, 'r')) mask |= LUA_MASKRET;
    if (fn_88563500(smask, 'l')) mask |= LUA_MASKLINE;
    if (count > 0) mask |= LUA_MASKCOUNT;
    return mask;
}

/* auxupvalue */
int lua3_auxupvalue_8882AA90(lua_State *L, int get)
{
    const char *name;
    int n = (int)ts4_lua_opt_number_default_8882EA98(L, 2);
    if (lua_type_(L, 1) != LUA2_TFUNCTION) lib3_luaL_typerror_8882E950(L, 1, lbl_880C9684[LUA2_TFUNCTION]);
    if (lua_iscfunction_(L, 1)) return 0; /* cannot touch C upvalues from Lua */
    name = get ? fn_88822BB8(L, n) : fn_88822AC8(L, n);
    if (name == 0) return 0;
    ts4_lua_pushlstring_88823FC0(L, name, strlen(name));
    ts4_lua_insert_88824438(L, -(get + 1));
    return get + 1;
}

/* db_setupvalue */
int lua3_db_setupvalue_8882AEF8(lua_State *L)
{
    if (lua_type_(L, 3) == -1) lib3_luaL_argerror_8882E6B8(L, 3, lbl_880E1C98);
    return lua3_auxupvalue_8882AA90(L, 0);
}

LUA2_FORCEINLINE void lua_pushstring_(lua_State *L, const char *s)
{
    if (s == 0) ts4_lua_pushnil_88824188(L);
    else ts4_lua_pushlstring_88823FC0(L, s, strlen(s));
}

/* hookf: call the Lua hook stored in the registry under KEY_HOOK */
void lua3_hookf_8882A768(lua_State *L, lua_Debug *ar)
{
    ts4_lua_pushlightuserdata_88823C98(L, KEY_HOOK);
    ts4_lua_rawget_88823AE8(L, -10000); /* LUA_REGISTRYINDEX */
    if (lua_type_(L, -1) == LUA2_TFUNCTION) {
        lua_pushstring_(L, lbl_880C9734[ar->event]);
        if (ar->currentline >= 0) ts4_lua_pushnumber_888240B8(L, ar->currentline);
        else ts4_lua_pushnil_88824188(L);
        lua2_luaD_call_8881E258(L, L->top - 3, 0); /* lua_call(L, 2, 0) */
    } else
        lua3_lua_settop_888246A8(L, -2); /* lua_pop(L, 1) */
}

/* settabsi */
LUA2_NOINLINE void lua3_settabsi_8882A858(lua_State *L, const char *i, int v)
{
    lua_pushstring_(L, i);
    ts4_lua_pushnumber_888240B8(L, (double)v);
    ts4_lua_rawset_88823430(L, -3);
}

/* settabss */
LUA2_NOINLINE void lua3_settabss_8882A8E8(lua_State *L, const char *i, const char *v)
{
    lua_pushstring_(L, i);
    lua_pushstring_(L, v);
    ts4_lua_rawset_88823430(L, -3);
}

/* gethook */
int lua3_gethook_8882A9A0(lua_State *L)
{
    char buff[5];
    int mask = L->hookmask;
    lua_Hook hook = (lua_Hook)L->hook;
    if (hook != 0 && hook != lua3_hookf_8882A768) /* external hook? */
        ts4_lua_pushlstring_88823FC0(L, lbl_880E2280, sizeof("external hook") - 1);
    else {
        ts4_lua_pushlightuserdata_88823C98(L, lbl_880C9733);
        ts4_lua_rawget_88823AE8(L, -10000);
    }
    lua_pushstring_(L, lua3_unmakemask_8882A3D0(mask, buff));
    ts4_lua_pushnumber_888240B8(L, L->basehookcount);
    return 3;
}

/* getlocal */
int lua3_getlocal_8882AC80(lua_State *L)
{
    lua_Debug ar;
    const char *name;
    if (!lua3_lua_getstack_8881EED0(L, luaL_checkint(L, 1), &ar)) /* level out of range? */
        return lib3_luaL_argerror_8882E6B8(L, 1, lbl_880E226C);
    name = lua3_lua_getlocal_88820020(L, &ar, luaL_checkint(L, 2));
    if (name) {
        ts4_lua_pushlstring_88823FC0(L, name, strlen(name));
        ts4_lua_pushvalue_88824248(L, -2);
        return 2;
    } else {
        ts4_lua_pushnil_88824188(L);
        return 1;
    }
}

/* setlocal */
int lua3_setlocal_8882ABA8(lua_State *L)
{
    lua_Debug ar;
    if (!lua3_lua_getstack_8881EED0(L, luaL_checkint(L, 1), &ar)) /* level out of range? */
        return lib3_luaL_argerror_8882E6B8(L, 1, lbl_880E226C);
    ts4_if_call_seq_fn_88822738_8882E8A0(L, 3);
    lua_pushstring_(L, lua3_lua_setlocal_8881FDF0(L, &ar, luaL_checkint(L, 2)));
    return 1;
}

/* lua_sethook (ldebug.c), inlined here by LTCG */
LUA2_FORCEINLINE void lua_sethook_(lua_State *L, lua_Hook func, int mask, int count)
{
    if (func == 0 || mask == 0) { /* turn off hooks? */
        mask = 0;
        func = 0;
    }
    L->hook = (void (*)(struct lua_State *, void *))func;
    L->basehookcount = count;
    L->hookcount = count;
    L->hookmask = (lu_byte)mask;
    L->hookinit = 0;
}

LUA2_FORCEINLINE const char *luaL_checkstring_(lua_State *L, int narg)
{
    const char *s = lib3_lua_tostring_88822888(L, narg);
    if (!s) lib3_luaL_typerror_8882E950(L, narg, lbl_880C9684[LUA2_TSTRING]);
    return s;
}

LUA2_FORCEINLINE double luaL_optnumber_(lua_State *L, int narg, double def)
{
    if (lua_type_(L, narg) <= LUA2_TNIL) return def;
    return ts4_lua_opt_number_default_8882EA98(L, narg);
}

/* sethook */
int lua3_sethook_8882AD68(lua_State *L)
{
    if (lua_type_(L, 1) <= LUA2_TNIL) {
        lua3_lua_settop_888246A8(L, 1);
        lua_sethook_(L, 0, 0, 0); /* turn off hooks */
    } else {
        const char *smask = luaL_checkstring_(L, 2);
        int count = (int)luaL_optnumber_(L, 3, g_ts4_script_constants[0x58 / 8]);
        if (lua_type_(L, 1) != LUA2_TFUNCTION) lib3_luaL_typerror_8882E950(L, 1, lbl_880C9684[LUA2_TFUNCTION]);
        lua_sethook_(L, lua3_hookf_8882A768, lua3_makemask_8882A430(smask, count), count);
    }
    ts4_lua_pushlightuserdata_88823C98(L, lbl_880C9733);
    ts4_lua_pushvalue_88824248(L, 1);
    ts4_lua_rawset_88823430(L, -10000); /* set new hook */
    return 0;
}

/* ZIO with the LuaPlus unicode flag at +0x14. */
typedef struct Zio {
    u32 n;
    const char *p;
    void *reader;
    void *data;
    const char *name;
    int unicode;
} ZIO;

typedef struct LoadS {
    const char *s;
    u32 size;
} LoadS;

extern char *ts4_addr_lbl_88C30DA8_88567BC8(void);                 /* __iob_func */
extern int fn_88566048(const char *s, void *stream);               /* fputs */
extern char *fn_88566220(char *buf, int n, void *stream);          /* fgets */
extern const char *ts4_if_get_u32_off4_8882DB60(lua_State *L, void *ud, u32 *size); /* getS */
extern int ex3_luaZ_fill_8880C040(ZIO *z);
extern int lua3_luaD_protectedparser_8881EAF8(lua_State *L, ZIO *z, int bin);
extern int lib3_aux_do_8882E368(lua_State *L, int status);
extern char lbl_880E2290[]; /* "lua_debug> " */
extern char lbl_880E229C[]; /* "cont\n" */
#define stdin_ ((void *)ts4_addr_lbl_88C30DA8_88567BC8())
#define stderr_ ((void *)(ts4_addr_lbl_88C30DA8_88567BC8() + 0x40))

/* luaZ_lookahead */
LUA2_FORCEINLINE int lookahead_(ZIO *z)
{
    if (z->n == 0) {
        int c = ex3_luaZ_fill_8880C040(z);
        if (c == -1) return c;
        z->n++;
        z->p--;
    }
    return (unsigned char)*z->p;
}

/* lua_load with luaL_loadbuffer's reader */
LUA2_FORCEINLINE int loadbuffer_(lua_State *L, const char *buff, u32 size, const char *name)
{
    LoadS ls;
    ZIO z;
    int c;
    ls.s = buff;
    ls.size = size;
    z.n = 0;
    z.p = 0;
    z.unicode = 0;
    z.reader = ts4_if_get_u32_off4_8882DB60;
    z.data = &ls;
    z.name = name;
    c = lookahead_(&z);
    return lua3_luaD_protectedparser_8881EAF8(L, &z, c == 0x1b);
}

/* db_debug: read and run lines from stdin until "cont" */
int lua3_db_debug_8882B1D0(lua_State *L)
{
    for (;;) {
        char buffer[250];
        fn_88566048(lbl_880E2290, stderr_);
        if (fn_88566220(buffer, sizeof(buffer), stdin_) == 0 || strcmp(buffer, lbl_880E229C) == 0) return 0;
        lib3_aux_do_8882E368(L, loadbuffer_(L, buffer, strlen(buffer), buffer));
        lua3_lua_settop_888246A8(L, 0);
    }
}

#define LEVELS1 12 /* size of the first part of the stack */
#define LEVELS2 10 /* size of the second part of the stack */

extern char lbl_880C1320[]; /* "" */
extern char lbl_880C13B8[]; /* "\n" */
extern char lbl_880E22A4[]; /* "stack traceback:" */
extern char lbl_880E22B8[]; /* "\n\t..." */
extern char lbl_880E22C0[]; /* "\n\t" */
extern char lbl_880E1C78[]; /* "Snl" */
extern char lbl_880E22C4[]; /* "%s:" */
extern char lbl_880E22C8[]; /* "%d:" */
extern char lbl_880E22CC[]; /* " in function `%s'" */
extern char lbl_880E22E0[]; /* " in main chunk" */
extern char lbl_880E22F0[]; /* " ?" */
extern char lbl_880E22F4[]; /* " in function <%s:%d>" */
extern int lua3_lua_getinfo_8881FF18(lua_State *L, const char *what, lua_Debug *ar);
extern const char *lua3_luaO_pushvfstring_888188F8(lua_State *L, const char *fmt, va_list argp); /* luaO_pushvfstring */
extern void ts4_call_seq_fn_8881C130_8881C200(lua_State *L);               /* luaC_checkGC body */
/* lua_pushfstring: a static copy, because callers that see a variadic body keep a larger frame. */
LUA2_LOCAL const char *lib3_lua_pushfstring_88822988(lua_State *L, const char *fmt, ...)
{
    const char *ret;
    va_list argp;
    if (G(L)->nblocks >= G(L)->GCthreshold) ts4_call_seq_fn_8881C130_8881C200(L);
    va_start(argp, fmt);
    ret = lua3_luaO_pushvfstring_888188F8(L, fmt, argp);
    va_end(argp);
    return ret;
}
extern void ts4_lua_concat_88822DB0(lua_State *L, int n);
#define lua_gettop_(L) ((int)((L)->top - (L)->base))
#define lua_pushliteral_(L, s, lit) ts4_lua_pushlstring_88823FC0((L), (s), sizeof(lit) - 1)

LUA2_FORCEINLINE int lua_isstring_(lua_State *L, int idx)
{
    int t = lua_type_(L, idx);
    return (t == LUA2_TSTRING || t == LUA2_TNUMBER || t == LUA2_TWSTRING);
}

/* errorfb (debug.traceback); wide strings count as messages */
int lua3_errorfb_8882A4A8(lua_State *L)
{
    int level = 1;     /* skip level 0 (it's this function) */
    int firstpart = 1; /* still before eventual `...' */
    lua_Debug ar;
    if (lua_gettop_(L) == 0)
        lua_pushliteral_(L, lbl_880C1320, "");
    else if (!lua_isstring_(L, 1))
        return 1; /* no string message */
    else
        lua_pushliteral_(L, lbl_880C13B8, "\n");
    lua_pushliteral_(L, lbl_880E22A4, "stack traceback:");
    while (lua3_lua_getstack_8881EED0(L, level++, &ar)) {
        if (level > LEVELS1 && firstpart) {
            /* no more than `LEVELS2' more levels? */
            if (!lua3_lua_getstack_8881EED0(L, level + LEVELS2, &ar))
                level--; /* keep going */
            else {
                lua_pushliteral_(L, lbl_880E22B8, "\n\t..."); /* too many levels */
                while (lua3_lua_getstack_8881EED0(L, level + LEVELS2, &ar)) /* find last levels */
                    level++;
            }
            firstpart = 0;
            continue;
        }
        lua_pushliteral_(L, lbl_880E22C0, "\n\t");
        lua3_lua_getinfo_8881FF18(L, lbl_880E1C78, &ar);
        lib3_lua_pushfstring_88822988(L, lbl_880E22C4, ar.short_src);
        if (ar.currentline > 0) lib3_lua_pushfstring_88822988(L, lbl_880E22C8, ar.currentline);
        switch (*ar.namewhat) {
        case 'g': /* global */
        case 'l': /* local */
        case 'f': /* field */
        case 'm': /* method */
            lib3_lua_pushfstring_88822988(L, lbl_880E22CC, ar.name);
            break;
        default: {
            if (*ar.what == 'm') /* main? */
                lib3_lua_pushfstring_88822988(L, lbl_880E22E0);
            else if (*ar.what == 'C' || *ar.what == 't')
                lua_pushliteral_(L, lbl_880E22F0, " ?"); /* C function or tail call */
            else
                lib3_lua_pushfstring_88822988(L, lbl_880E22F4, ar.short_src, ar.linedefined);
        }
        }
        ts4_lua_concat_88822DB0(L, lua_gettop_(L));
    }
    ts4_lua_concat_88822DB0(L, lua_gettop_(L));
    return 1;
}

extern const char *lib3_luaL_checklstring_8882EB20(lua_State *L, int narg, u32 *len);
extern int lib3_lua_isnumber_88822650(lua_State *L, int idx);
extern double ts4_lua_tonumber_88822420(lua_State *L, int idx);
extern void ts4_lua_newtable_888238D8(lua_State *L);
extern char lbl_880E21E4[]; /* "flnSu" */
extern char lbl_880E21EC[]; /* ">%s" */
extern char lbl_880E21F0[]; /* "function or level expected" */
extern char lbl_880E220C[]; /* "invalid option" */
extern char lbl_880E2264[]; /* "func" */
extern char lbl_880E221C[]; /* "source" */
extern char lbl_880E2224[]; /* "short_src" */
extern char lbl_880E2230[]; /* "linedefined" */
extern char lbl_880E223C[]; /* "what" */
extern char lbl_880E2244[]; /* "currentline" */
extern char lbl_880E2250[]; /* "nups" */
extern char lbl_880E1A00[]; /* "name" */
extern char lbl_880E2258[]; /* "namewhat" */

LUA2_FORCEINLINE const char *luaL_optstring_(lua_State *L, int narg, const char *def)
{
    if (lua_type_(L, narg) <= LUA2_TNIL) return def;
    return lib3_luaL_checklstring_8882EB20(L, narg, 0);
}

/* db_getinfo */
int lua3_getinfo_8882AF40(lua_State *L)
{
    lua_Debug ar;
    const char *options = luaL_optstring_(L, 2, lbl_880E21E4);
    if (lib3_lua_isnumber_88822650(L, 1)) {
        if (!lua3_lua_getstack_8881EED0(L, (int)ts4_lua_tonumber_88822420(L, 1), &ar)) {
            ts4_lua_pushnil_88824188(L); /* level out of range */
            return 1;
        }
    } else if (lua_type_(L, 1) == LUA2_TFUNCTION) {
        lib3_lua_pushfstring_88822988(L, lbl_880E21EC, options);
        options = lib3_lua_tostring_88822888(L, -1);
        ts4_lua_pushvalue_88824248(L, 1);
    } else
        return lib3_luaL_argerror_8882E6B8(L, 1, lbl_880E21F0);
    if (!lua3_lua_getinfo_8881FF18(L, options, &ar)) return lib3_luaL_argerror_8882E6B8(L, 2, lbl_880E220C);
    ts4_lua_newtable_888238D8(L);
    for (; *options; options++) {
        switch (*options) {
        case 'S':
            lua3_settabss_8882A8E8(L, lbl_880E221C, ar.source);
            lua3_settabss_8882A8E8(L, lbl_880E2224, ar.short_src);
            lua3_settabsi_8882A858(L, lbl_880E2230, ar.linedefined);
            lua3_settabss_8882A8E8(L, lbl_880E223C, ar.what);
            break;
        case 'l':
            lua3_settabsi_8882A858(L, lbl_880E2244, ar.currentline);
            break;
        case 'u':
            lua3_settabsi_8882A858(L, lbl_880E2250, ar.nups);
            break;
        case 'n':
            lua3_settabss_8882A8E8(L, lbl_880E1A00, ar.name);
            lua3_settabss_8882A8E8(L, lbl_880E2258, ar.namewhat);
            break;
        case 'f':
            lua_pushliteral_(L, lbl_880E2264, "func");
            ts4_lua_pushvalue_88824248(L, -3);
            ts4_lua_rawset_88823430(L, -3);
            break;
        }
    }
    return 1; /* return table */
}
