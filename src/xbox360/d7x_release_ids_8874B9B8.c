/* Swing_DLL.xex 0x8874B9B8-0x8874BA64, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Obj Obj;
typedef struct ObjVtbl { void *s[23]; void *(*find)(Obj *, int); } ObjVtbl;
struct Obj { ObjVtbl *vt; u32 pad[16]; int id2; int id0; int id1; };
typedef struct Entry { char pad[0x20]; char body[0x90]; } Entry;
typedef struct Pool { char pad[0x20]; Entry *entries; } Pool;
typedef struct Mgr { char pad[0x24]; char *res; char pad2[0x78]; Pool *pool; } Mgr;
extern Mgr *lbl_88D45AD4;
extern void fn_88719D50(void *r);
extern void fn_88222B50(void *r, int id);
extern void fn_8825FC78(void *e);
extern void fn_88223890(void *p, int id);
extern void *fn_886F1900(Obj *o);

void *ts4_release_ids_8874B9B8(Obj *o)
{
    if (o->id0 != -1) {
        void *r = o->vt->find(o, o->id0);
        if (r) {
            fn_88719D50(r);
            fn_88222B50(lbl_88D45AD4->res + 0x34, o->id0);
        }
        o->id0 = -1;
    }
    if (o->id1 != -1) {
        void *e = lbl_88D45AD4->pool->entries[o->id1].body;
        if (e) {
            fn_8825FC78(e);
            fn_88223890(lbl_88D45AD4->pool, o->id1);
        }
        o->id1 = -1;
    }
    o->id2 = -1;
    return fn_886F1900(o);
}
