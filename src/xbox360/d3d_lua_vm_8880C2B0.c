/* Swing_DLL.xex 0x8880C660-0x8880CBC8, executable version 0.0.0.3. */
/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "d3d_lua.h"

typedef Ts4LuaValue TValue;

typedef struct TString {
    char header[0x14];
    u32 len;
} TString;

#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#else
#include <string.h>
#endif

extern int ex3_l_strcmp_8880C2B0(const TString *ls, const TString *rs);
extern int fn_8880C360(void *L, const TValue *p1, const TValue *p2, int event);
extern int fn_8881EBA8(void *L, const TValue *p1, const TValue *p2);
extern int fn_88818190(const char *, double *);
extern int fn_88818768(const char *, double *);
extern void fn_88818C88(void *L, Ts4LuaObject *o);
extern int fn_885635D0(char *, const char *, ...);
extern char lbl_880E18A4[];
extern Ts4LuaObject *fn_888131A0(void *L, const char *str, u32 len);

/* luaV_lessequal */
int ts4_lua_v_lessequal_8880C660(void *L, const TValue *l, const TValue *r)
{
    int res;
    if (l->tt != r->tt)
        return fn_8881EBA8(L, l, r);
    else if (l->tt == 3)
        return l->u.n <= r->u.n;
    else if (l->tt == 4)
        return ex3_l_strcmp_8880C2B0((const TString *)l->u.p, (const TString *)r->u.p) <= 0;
    else if ((res = fn_8880C360(L, l, r, 0xc)) != -1)
        return res;
    else if ((res = fn_8880C360(L, r, l, 0xb)) != -1)
        return !res;
    return fn_8881EBA8(L, l, r);
}

/* luaV_lessthan */
int ts4_lua_v_lessthan_8880C738(void *L, const TValue *l, const TValue *r)
{
    int res;
    if (l->tt != r->tt)
        return fn_8881EBA8(L, l, r);
    else if (l->tt == 3)
        return l->u.n < r->u.n;
    else if (l->tt == 4)
        return ex3_l_strcmp_8880C2B0((const TString *)l->u.p, (const TString *)r->u.p) < 0;
    else if ((res = fn_8880C360(L, l, r, 0xb)) != -1)
        return res;
    return fn_8881EBA8(L, l, r);
}

/* luaV_tonumber: numbers pass through; strings (and the extra tag 9) are converted into n. */
TValue *ts4_lua_v_tonumber_8880CAF0(void *L, TValue *obj, TValue *n)
{
    double num;
    if (obj->tt == 3) return obj;
    if (obj->tt == 4 && fn_88818190((char *)obj->u.gc + 0x18, &num)) {
        if (n->tt >= 4) {
            if (--n->u.gc->refs == 0) fn_88818C88(L, n->u.gc);
        }
        n->u.n = num;
        n->tt = 3;
        return n;
    }
    if (obj->tt == 9 && fn_88818768((char *)obj->u.gc + 0x18, &num)) {
        if (n->tt >= 4) {
            if (--n->u.gc->refs == 0) fn_88818C88(L, n->u.gc);
        }
        n->u.n = num;
        n->tt = 3;
        return n;
    }
    return 0;
}

/* luaV_tostring: format a number in place as a string value. */
int ts4_lua_v_tostring_8880C9F8(void *L, TValue *obj)
{
    if (obj->tt != 3) return 0;
    else {
        char s[32];
        double n = obj->u.n;
        TValue old;
        fn_885635D0(s, lbl_880E18A4, n);
        old = *obj;
        obj->u.gc = fn_888131A0(L, s, strlen(s));
        obj->tt = 4;
        obj->u.gc->refs++;
        if (old.tt >= 4) {
            if (--old.u.gc->refs == 0) fn_88818C88(L, old.u.gc);
        }
        return 1;
    }
}
