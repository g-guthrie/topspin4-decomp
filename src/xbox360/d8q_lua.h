/* Swing_DLL.xex Lua object layouts shared by the d8q units. */
/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#ifndef D8Q_LUA_H
#define D8Q_LUA_H

#ifdef _MSC_VER
#define TS4_LUA_ERROR_LINKAGE static __declspec(noinline)
#else
#define TS4_LUA_ERROR_LINKAGE static inline
#endif
#include "d7q_lua.h"

/* Auxiliary-library string buffer: write cursor at +0, pending pieces at +4, wide flag at +8, bytes at +0x10. */
typedef struct Ts8Buf {
    char *p;
    int lvl;
    int wide;
    lua_State *L;
    char buffer[0x200];
} Ts8Buf;

extern int lib3_emptybuffer_8882DE88(Ts8Buf *B);
extern void lib3_adjuststack_8882DBA8(Ts8Buf *B);


/* Lua C API entry points used by the library units. */
extern void ts4_lua_pushlstring_88823FC0(lua_State *L, const char *s, u32 len);
extern void ts4_lua_pushnil_88824188(lua_State *L);
extern void ts4_lua_pushnumber_888240B8(lua_State *L, double n);
extern void ts4_lua_pushvalue_88824248(lua_State *L, int idx);
extern void ts4_lua_rawget_88823AE8(lua_State *L, int idx);
extern void ts4_lua_rawset_88823430(lua_State *L, int idx);
extern void ts4_lua_remove_below_top_888245A8(lua_State *L);
extern void lua3_lua_settop_888246A8(lua_State *L, int idx);
extern int ts4_lua_getmetatable_88823768(lua_State *L, int idx);
extern char *fn_88563500(const char *s, int c);

#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#else
#include <string.h>
#endif

#endif
