/* Derived from Lua 5.0.2 (MIT); see THIRD_PARTY_NOTICES.md */
/* LUA3 shared declarations on top of lua2.h (LuaPlus build in Swing_DLL.xex). */
#ifndef LUA3_H
#define LUA3_H
#include "lua2.h"

#define LUA3_NORETURN LUA2_NORETURN

#define CI_C 1
#define CI_HASFRAME 2
#define CI_CALLING 4
#define CI_SAVEDPC 8
#define CI_YIELD 16

typedef struct lua_Debug {
    int event;
    const char *name;
    const char *namewhat;
    const char *what;
    const char *source;
    int currentline;
    int nups;
    int linedefined;
    char short_src[60];
    int i_ci; /* active function */
} lua_Debug;

typedef void (*lua_Hook)(lua_State *L, lua_Debug *ar);

extern LUA2_NORETURN void fn_88569D30(void *jb, int v);                  /* longjmp */
extern LUA2_NORETURN void ts4_tailcall_fn_88564208_885643D0(int status); /* exit */

#endif
