
typedef struct Elem { char b[0x68]; } Elem;
typedef struct Obj Obj;
typedef struct ObjVt { void *s[10]; unsigned char (*ready)(Obj *); void *s2[2]; void (*hide)(Obj *, int, int); void (*show)(Obj *, int); } ObjVt;
struct Obj { ObjVt *vt; char pad[0x7c]; Elem *first; Elem *last; };
void fn_886ECC38(Obj *o)
{
    unsigned char b = o->vt->ready(o);
    if (b) {
        if ((o->last - o->first) == 0) o->vt->show(o, 0);
    } else {
        if ((o->last - o->first) != 0) o->vt->hide(o, 0, -1);
    }
}
