/* Derived from Lua 5.0.2 lvm.c (MIT); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex (wide strings). */
#include "d3d_lua.h"

typedef Ts4LuaValue TValue;

extern void fn_88818C88(void *L, Ts4LuaObject *o);
extern int fn_885635D0(char *, const char *, ...); /* sprintf */
extern char lbl_880E18A4[];                          /* "%.14g" */
extern Ts4LuaObject *lua2_luaS_newlwstr_88812FC8(void *L, const unsigned short *str, u32 len);

/* luaV_tolwstring: format a number in place as a wide string value. */
int cx19_lua_v_tolwstring_88834740(void *L, TValue *obj)
{
    if (obj->tt != 3) return 0;
    else {
        char s[32];
        unsigned short w[32];
        const char *p = s;
        unsigned short *q = w;
        const unsigned short *e;
        double n = obj->u.n;
        TValue old;
        fn_885635D0(s, lbl_880E18A4, n);
        while (*p) *q++ = (unsigned short)(signed char)*p++;
        *q = 0;
        old = *obj;
        e = w;
        while (*e) e++;
        obj->u.gc = lua2_luaS_newlwstr_88812FC8(L, w, (u32)(e - w));
        obj->tt = 9;
        obj->u.gc->refs++;
        if (old.tt >= 4) {
            if (--old.u.gc->refs == 0) fn_88818C88(L, old.u.gc);
        }
        return 1;
    }
}

extern TValue *lib3_lua_negindex_88821F98(Ts4LuaState *L, int idx);

/* luaA_indexAcceptable: NULL when a positive index is past the top. */
TS4_FORCEINLINE TValue *cx19_acceptable(Ts4LuaState *L, int idx)
{
    if (idx > 0) {
        TValue *o = L->base + (idx - 1);
        if (o >= L->top) return 0;
        else return o;
    }
    return lib3_lua_negindex_88821F98(L, idx);
}

/* lua_tolwstring: wide string contents follow the 0x18-byte header. */
const unsigned short *cx19_lua_tolwstring_888348A0(Ts4LuaState *L, int idx)
{
    TValue *o = cx19_acceptable(L, idx);
    if (o == 0) return 0;
    else if (o->tt == 9) return (const unsigned short *)((char *)o->u.p + 0x18);
    else return cx19_lua_v_tolwstring_88834740(L, o) ? (const unsigned short *)((char *)o->u.p + 0x18) : 0;
}
