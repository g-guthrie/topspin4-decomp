#ifndef _MSC_VER
#pragma GCC diagnostic ignored "-Wunused-function"
#endif
/* Swing_DLL.xex 0x8882E8F8-0x88832E4C, executable version 0.0.0.3. */
/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "d6q_lua.h"
#ifndef _MSC_VER
int ts4_luaL_error_8882E5F0();
#endif

extern int fn_88822028(lua_State *L, int a);
extern const char lbl_880E1C84[];
extern int fn_8880C538(void *x, void *a, void *b);

/* Raise a formatted error unless the check on an argument passes. */
static void lib3_luaL_checkstack_8882E8F8(lua_State *L, int a, int b)
{
    if (!fn_88822028(L, a))
        ts4_luaL_error_8882E5F0(L, lbl_880E1C84, b);
}

/* Boxed values with the same tag compare equal when the comparison helper agrees. */
typedef struct Ts6Box {
    char pad0[8];
    int tt;
    char pad1[0xc];
    void **tab;
} Ts6Box;

int ts4_box_equal_88832DF8(Ts6Box *a, Ts6Box *b)
{
    if (a->tt == b->tt) {
        if (fn_8880C538(*a->tab, &a->tt, &b->tt) != 0)
            return 1;
    }
    return 0;
}
