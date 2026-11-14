/* Swing_DLL.xex 0x8882C498-0x8882CF50, executable version 0.0.0.3. */
/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "d3d_lua.h"

#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#else
#include <string.h>
#endif

typedef Ts4LuaValue TValue;
typedef Ts4LuaState lua_State;
typedef Ts4LuaCall CallS;

extern const char *lbl_880C9684[];
extern char lbl_880E1C98[];
extern TS4_NORETURN int lib3_luaL_typerror_8882E950(lua_State *L, int narg, const char *tname);
extern TS4_NORETURN int lib3_luaL_argerror_8882E6B8(lua_State *L, int narg, const char *extramsg);
extern int lua3_luaD_pcall_8881E748(lua_State *L, CallS *c, int old_top, int ef);
extern void ts4_lua_pushboolean_88823D48(lua_State *L, int b);
extern void ts4_lua_insert_88824438(lua_State *L, int idx);
extern void ts4_lua_replace_88824340(lua_State *L, int idx);
extern void lua3_lua_settop_888246A8(lua_State *L, int idx);
extern void ts4_lua_rawget_88823AE8(lua_State *L, int idx);
extern char lbl_880E17A4[];
extern void ts4_lua_pushlstring_88823FC0(lua_State *L, const char *s, u32 len);
extern void ts4_lua_pushnil_88824188(lua_State *L);
extern void ts4_lua_rawset_88823430(lua_State *L, int idx);

#define lua_type_ ts4_lua_type
#define lua_gettop_ ts4_lua_gettop

TS4_FORCEINLINE int lua_pcall_(lua_State *L, int nargs, int nresults, int errfunc)
{
    CallS c;
    int func;
    func = (errfunc == 0) ? 0 : (int)((char *)(L->base + (errfunc - 1)) - (char *)L->stack);
    c.func = L->top - (nargs + 1);
    c.nresults = nresults;
    return lua3_luaD_pcall_8881E748(L, &c, (int)((char *)c.func - (char *)L->stack), func);
}

/* luaB_xpcall */
int ts4_lua_b_xpcall_8882C498(lua_State *L)
{
    int status;
    if (lua_type_(L, 2) == -1) lib3_luaL_argerror_8882E6B8(L, 2, lbl_880E1C98);
    lua3_lua_settop_888246A8(L, 2);
    ts4_lua_insert_88824438(L, 1);
    status = lua_pcall_(L, 0, -1, 1);
    ts4_lua_pushboolean_88823D48(L, status == 0);
    ts4_lua_replace_88824340(L, 1);
    return lua_gettop_(L);
}

/* luaB_pcall */
int ts4_lua_b_pcall_8882C578(lua_State *L)
{
    int status;
    if (lua_type_(L, 1) == -1) lib3_luaL_argerror_8882E6B8(L, 1, lbl_880E1C98);
    status = lua_pcall_(L, lua_gettop_(L) - 1, -1, 0);
    ts4_lua_pushboolean_88823D48(L, status == 0);
    ts4_lua_insert_88824438(L, 1);
    return lua_gettop_(L);
}

/* luaB_type */
int ts4_lua_b_type_8882C640(lua_State *L)
{
    const char *s;
    int t;
    if (lua_type_(L, 1) == -1) lib3_luaL_argerror_8882E6B8(L, 1, lbl_880E1C98);
    t = lua_type_(L, 1);
    s = (t == -1) ? lbl_880E17A4 : lbl_880C9684[t];
    if (s == 0) ts4_lua_pushnil_88824188(L);
    else ts4_lua_pushlstring_88823FC0(L, s, strlen(s));
    return 1;
}

/* luaB_rawset */
int ts4_lua_b_rawset_8882CE90(lua_State *L)
{
    if (lua_type_(L, 1) != 5) lib3_luaL_typerror_8882E950(L, 1, lbl_880C9684[5]);
    if (lua_type_(L, 2) == -1) lib3_luaL_argerror_8882E6B8(L, 2, lbl_880E1C98);
    if (lua_type_(L, 3) == -1) lib3_luaL_argerror_8882E6B8(L, 3, lbl_880E1C98);
    ts4_lua_rawset_88823430(L, 1);
    return 1;
}

/* luaB_rawget */
int ts4_lua_b_rawget_8882CF50(lua_State *L)
{
    if (lua_type_(L, 1) != 5) lib3_luaL_typerror_8882E950(L, 1, lbl_880C9684[5]);
    if (lua_type_(L, 2) == -1) lib3_luaL_argerror_8882E6B8(L, 2, lbl_880E1C98);
    ts4_lua_rawget_88823AE8(L, 1);
    return 1;
}
