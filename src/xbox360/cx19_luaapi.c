/* Derived from Lua 5.0.2 lapi.c (MIT); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "lua3.h"

/* Release the value held by o and set it to nil. */
void cx19_setnil_88837460(lua_State *L, TValue *o)
{
    setnilvalue(L, o);
}
