/* 0x883FB780: returns the first 0x20-byte entry (skipping +0x14) whose embedded sub-object key (slot 0xC) or whose manager-resolved object key (883E63D8 manager, slot 0xC lookup of fn_88400300(def+0x2C), slot 0x20) equals key; 0 if none */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct Sub Sub;
typedef struct SubVt { char pad[0xc]; void *(*key)(Sub *s); } SubVt;
struct Sub { SubVt *vt; };
typedef struct Obj Obj;
typedef struct ObjVt { char pad[0x20]; void *(*key)(Obj *o); } ObjVt;
struct Obj { ObjVt *vt; };
typedef struct Mgr Mgr;
typedef struct MgrVt { char pad[0xc]; Obj *(*find)(Mgr *m, void *id); } MgrVt;
struct Mgr { MgrVt *vt; };
typedef struct Entry { int f0; char *def; char pad[4]; Sub sub; char pad2[0x10]; } Entry;
typedef struct T { char pad[0xc]; int count; Entry *entries; Entry *skip; } T;
void *fn_88400300(void *p);
Mgr *ts4_if_get_u32_lbl_88CAC9A8_883E63D8(void);
Entry *ts4_find_entry_by_key_883FB780(T *t, void *key)
{
    int i;
    for (i = 0; i < t->count; i++) {
        Entry *e = &t->entries[i];
        void *id;
        Obj *o;
        if (e == t->skip)
            continue;
        if (e->sub.vt->key(&e->sub) == key)
            return e;
        id = fn_88400300(e->def + 0x2c);
        {
            Mgr *m = ts4_if_get_u32_lbl_88CAC9A8_883E63D8();
            o = m->vt->find(m, id);
        }
        if (o && o->vt->key(o) == key)
            return e;
    }
    return 0;
}
