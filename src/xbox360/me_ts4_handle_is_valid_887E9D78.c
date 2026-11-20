/* 0x887E9D78: true when the 14-bit index of the handle is in range and its slot holds the same handle; mode 1 also requires the object's +0x10 byte clear */
/* Matched on /Oc (agAH). Inline vsize/vat helpers on the embedded vector give the clrrwi copy of begin; 'return 0 == busy'. */
typedef struct Obj { char p[0x10]; unsigned char busy; } Obj;
typedef struct Slot { unsigned int handle; int pad; Obj *obj; int pad2[2]; } Slot;
typedef struct Vec { Slot *begin; Slot *end; } Vec;
typedef struct T { char p[0x30]; Vec slots; } T;
static __inline unsigned int vsize(Vec *v) { return v->end - v->begin; }
static __inline Slot *vat(Vec *v, unsigned int i) { return &v->begin[i]; }
unsigned char fn_887E9D78(T *t, unsigned int h, unsigned char mode)
{
    unsigned int i = h & 0x3FFF;
    if (i < vsize(&t->slots)) {
        Slot *s = vat(&t->slots, i);
        if (s->handle == h) {
            if (mode == 1)
                return 0 == s->obj->busy;
            return 1;
        }
    }
    return 0;
}
