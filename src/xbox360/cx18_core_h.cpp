/* CW18 part h: C++ because the managed object converts to its second base (null-checked +0x40 adjustment) (0x88850000-0x88871F08). Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" {
struct Cx18VtObj;
}
struct Cx18Base0 { u8 pad[0x40]; };
struct Cx18Base1 { u8 pad[0xc]; void *f0c; };
struct Cx18MObj : Cx18Base0, Cx18Base1 { u8 pad50[0x180 - 0x50]; int id180; };
extern "C" {
typedef struct Cx18Mgr { u8 pad0[0x20]; Cx18MObj **begin; Cx18MObj **end; } Cx18Mgr;
extern u8 fn_88867310(int id);
extern void fn_889254C8(void *obj, int flag);

/* 0x88867D00: when the id is valid, find the object with that id and poke its second base if it holds a member */
void ts4_mgr_poke_by_id_88867D00(Cx18Mgr *m, int id)
{
    if (fn_88867310(id)) {
        Cx18MObj **e = m->end;
        Cx18MObj **it;
        Cx18MObj *found = 0;
        for (it = m->begin; it != e; it++) {
            if ((*it)->id180 == id) { found = *it; break; }
        }
        if (found != 0) {
            Cx18Base1 *sub = found;
            if (sub != 0 && sub->f0c != 0) fn_889254C8(sub, 1);
        }
    }
}
}
