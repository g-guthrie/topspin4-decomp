/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* Altered to match Swing_DLL.xex (wide strings, split objects). lauxlib.c argument checks. */
#include "d3d_lua.h"
#ifdef _MSC_VER
extern unsigned int strlen(const char *s);
#pragma intrinsic(strlen)
#else
#include <string.h>
#endif

typedef Ts4LuaState lua_State;

TS4_NORETURN extern void lib3_luaL_typerror_8882E950(lua_State *L, int narg, const char *tname);
extern int lib3_lua_checkstack_88822028(lua_State *L, int size);
extern int lib3_lua_type_88822738(lua_State *L, int idx);
extern const char *lib3_lua_pushfstring_88822988(lua_State *L, const char *fmt, ...);
extern void lib3_luaL_addlstring_8882E828(void *B, const char *s, unsigned int l);
extern const char *lbl_880C9684[];
extern char lbl_880E17A4[];
extern char lbl_880E1C64[];
extern char lbl_880E1C84[];


/* luaL_typename / lua_typename */
#define LIB3_TYPENAME(t) ((t) == -1 ? lbl_880E17A4 : lbl_880C9684[t])


/* luaL_addstring */
void lib3_luaL_addstring_8882E9E0(void *B, const char *s)
{
    lib3_luaL_addlstring_8882E828(B, s, strlen(s));
}

/* tag_error */
void lib3_tag_error_8882EA08(lua_State *L, int narg, int tag)
{
    lib3_luaL_typerror_8882E950(L, narg, LIB3_TYPENAME(tag));
}

/* luaL_checklwstring (8882EA30) lives in lib3_lua_auxlib3.c next to its callers. */
