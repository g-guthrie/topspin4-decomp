/* Derived from Lua 5.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Lua tag-method helpers (customised, reference-counted objects). */

typedef struct lu1_State lu1_State;
typedef struct lu1_Global { char pad[0x98]; void *tmnames; } lu1_Global;
struct lu1_State { char pad[0x14]; lu1_Global *l_G; };
typedef struct lu1_Obj { char pad[0xc]; unsigned char flags; } lu1_Obj;

void *lua2_luaT_gettm_88811168(void *obj, int event, void *names);
void *lib3_luaO_rawequalObj_88818240(void *a, void *b);

/* call_orderTM-style helper: both operands must share the same tag method. */
void *lu1_call_orderTM_8880C480(lu1_State *L, lu1_Obj *p1, lu1_Obj *p2)
{
    void *tm1 = 0;
    void *tm2;
    if (!(p1->flags & 0x10))
        tm1 = lua2_luaT_gettm_88811168(p1, 4, L->l_G->tmnames);
    if (tm1 == 0)
        return 0;
    if (p1 == p2)
        return tm1;
    if (p2->flags & 0x10)
        return 0;
    tm2 = lua2_luaT_gettm_88811168(p2, 4, L->l_G->tmnames);
    if (tm2 == 0)
        return 0;
    return lib3_luaO_rawequalObj_88818240(tm1, tm2) ? tm1 : 0;
}
