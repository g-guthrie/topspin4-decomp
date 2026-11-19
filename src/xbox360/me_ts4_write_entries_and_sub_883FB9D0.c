/* 0x883FB9D0: writes a 0xA0 header, then each 0x20-byte entry's object (slot 1, signed null test) and the entry table size via fn_8832EDB0, and finally the embedded sub-object at +0x20 (slot 0x18) */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
#ifdef _MSC_VER
#define PTR_INT(p) ((int)(p))
#else
#define PTR_INT(p) ((int)(long)(p))
#endif
typedef struct Obj Obj;
typedef struct ObjVt { void *f0; int (*write)(Obj *o, void *w); } ObjVt;
struct Obj { ObjVt *vt; };
typedef struct Sub Sub;
typedef struct SubVt { char pad[0x18]; int (*write)(Sub *s, void *w); } SubVt;
struct Sub { SubVt *vt; };
typedef struct Entry { int f0; Obj *obj; char pad[0x18]; } Entry;
typedef struct T { char pad[0xc]; int count; Entry *entries; char pad2[0xc]; Sub sub; } T;
void fn_8832EDB0(void *w, int a, unsigned int kind, unsigned int size);
int ts4_write_entries_and_sub_883FB9D0(T *t, void *w)
{
    int i;
    int r;
    fn_8832EDB0(w, 1, 2, 0xa0);
    if (t->entries) {
        for (i = 0; i < t->count; i++) {
            Obj *o = t->entries[i].obj;
            if (PTR_INT(o) != 0) {
                r = o->vt->write(o, w);
                if (r)
                    return r;
            }
        }
        fn_8832EDB0(w, 1, 2, t->count * 32);
    }
    return t->sub.vt->write(&t->sub, w);
}
