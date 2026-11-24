/* 0x88656538 near miss (agAY, 3 off, plain /Oc and .cpp): float from a self-relative array in the source data when ready and not busy, else 0. Only the rel/i*4 add operand order differs (target add r10,r9(i*4),r10(rel)); expression orders, locals and op1 pads do not change it. */
typedef unsigned char u8;
typedef struct RelF { int rel; unsigned count; } RelF;
typedef struct Data { u8 pad[0x3c]; RelF vals; } Data;
struct Src;
typedef struct SrcVt { u8 pad[0x30]; u8 (*ready)(struct Src *); u8 pad34[0x14]; Data *(*data)(struct Src *, int); } SrcVt;
typedef struct Src { SrcVt *vt; } Src;
typedef struct Obj { u8 pad[0x1c]; Src src; u8 pad20[0x58]; void *busy; } Obj;
extern const float lbl_8814B440;
float fn_88656538(Obj *o, unsigned i)
{
    float r = lbl_8814B440;
    Src *s = &o->src;
    if (s->vt->ready(s) && o->busy == 0) {
        RelF *a = &s->vt->data(s, 0)->vals;
        if (i < a->count) return *(float *)((char *)a + (a->rel + i * 4));
    }
    return r;
}
