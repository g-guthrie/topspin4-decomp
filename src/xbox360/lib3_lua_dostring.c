/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* Altered to match Swing_DLL.xex. lua_dostring (lauxlib.c) with luaL_loadbuffer folded in. */
#include "d3d_lua.h"
#ifdef _MSC_VER
extern unsigned int strlen(const char *s);
#pragma intrinsic(strlen)
#else
#include <string.h>
#endif
typedef Ts4LuaState lua_State;
/* String source handed to the loader: pointer and length. */
typedef struct Lib3LoadS { const char *s; unsigned int size; } Lib3LoadS;
extern int lib3_lua_load_buffer_88824CF8(lua_State *L, Lib3LoadS *ls, const char *chunkname);
extern int lib3_aux_do_8882E368(lua_State *L, int status);
/* lua_dostring: load str as a chunk named after itself, then run it through aux_do. */
int lib3_lua_dostring_8882ED00(lua_State *L, const char *str)
{
    Lib3LoadS ls;
    unsigned int size = strlen(str);
    ls.s = str;
    ls.size = size;
    return lib3_aux_do_8882E368(L, lib3_lua_load_buffer_88824CF8(L, &ls, str));
}
