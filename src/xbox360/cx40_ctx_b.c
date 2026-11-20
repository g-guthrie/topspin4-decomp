/* CW40 LTCG context: slot-table validity leaf (id check, optional flag byte), keeps r4 untouched for its callers. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Cx40Ent { u32 id; u32 b; char *obj; u32 c, d; } Cx40Ent;
typedef struct Cx40Tab { char pad[0x30]; Cx40Ent *b, *e; } Cx40Tab;
#ifdef _MSC_VER
__declspec(noinline)
#endif
u32 fn_887E9D78(Cx40Tab *t, u32 id, u8 flag)
{
    u32 idx = id & 0x3fff;
    if (idx < (u32)(t->e - t->b)) {
        Cx40Ent *e = &t->b[idx];
        if (e->id == id) {
            if (flag == 1) return e->obj[0x10] == 0;
            return 1;
        }
    }
    return 0;
}
