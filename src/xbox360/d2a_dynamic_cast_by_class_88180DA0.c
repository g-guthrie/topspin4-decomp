/* Swing_DLL.xex 0x88180DA0-0x8820B298, executable version 0.0.0.3. */
typedef struct ClassInfo { void *a; void *b; struct ClassInfo *parent; } ClassInfo;
typedef struct Obj { struct ObjVtbl *vt; } Obj;
struct ObjVtbl { ClassInfo *(*get_class)(Obj *); };
extern ClassInfo lbl_88C4763C;
extern ClassInfo lbl_88C694F4;
extern ClassInfo lbl_88C69528;
extern ClassInfo lbl_88C69578;
extern ClassInfo lbl_88C69614;
extern ClassInfo lbl_88C697D0;
extern ClassInfo lbl_88C698BC;
extern ClassInfo lbl_88C699F4;
extern ClassInfo lbl_88C69C18;

/* Returns self if its class (or a parent class) is lbl_88C4763C, else NULL. */
Obj *ts4_dynamic_cast_by_class_88180DA0(Obj *self)
{
    ClassInfo *c;
    if (self) {
        c = self->vt->get_class(self);
        do {
            if (c == &lbl_88C4763C) {
                return self;
            }
            c = c->parent;
        } while (c);
    }
    return 0;
}

/* Returns self if its class (or a parent class) is lbl_88C69578, else NULL. */
Obj *ts4_dynamic_cast_by_class_88180E18(Obj *self)
{
    ClassInfo *c;
    if (self) {
        c = self->vt->get_class(self);
        do {
            if (c == &lbl_88C69578) {
                return self;
            }
            c = c->parent;
        } while (c);
    }
    return 0;
}

/* Returns self if its class (or a parent class) is lbl_88C69C18, else NULL. */
Obj *ts4_dynamic_cast_by_class_88180E90(Obj *self)
{
    ClassInfo *c;
    if (self) {
        c = self->vt->get_class(self);
        do {
            if (c == &lbl_88C69C18) {
                return self;
            }
            c = c->parent;
        } while (c);
    }
    return 0;
}

/* Returns self if its class (or a parent class) is lbl_88C697D0, else NULL. */
Obj *ts4_dynamic_cast_by_class_881CB2F0(Obj *self)
{
    ClassInfo *c;
    if (self) {
        c = self->vt->get_class(self);
        do {
            if (c == &lbl_88C697D0) {
                return self;
            }
            c = c->parent;
        } while (c);
    }
    return 0;
}

/* Returns self if its class (or a parent class) is lbl_88C699F4, else NULL. */
Obj *ts4_dynamic_cast_by_class_881DA460(Obj *self)
{
    ClassInfo *c;
    if (self) {
        c = self->vt->get_class(self);
        do {
            if (c == &lbl_88C699F4) {
                return self;
            }
            c = c->parent;
        } while (c);
    }
    return 0;
}

/* Returns self if its class (or a parent class) is lbl_88C694F4, else NULL. */
Obj *ts4_dynamic_cast_by_class_881F1A50(Obj *self)
{
    ClassInfo *c;
    if (self) {
        c = self->vt->get_class(self);
        do {
            if (c == &lbl_88C694F4) {
                return self;
            }
            c = c->parent;
        } while (c);
    }
    return 0;
}

/* Returns self if its class (or a parent class) is lbl_88C69528, else NULL. */
Obj *ts4_dynamic_cast_by_class_881F1AC8(Obj *self)
{
    ClassInfo *c;
    if (self) {
        c = self->vt->get_class(self);
        do {
            if (c == &lbl_88C69528) {
                return self;
            }
            c = c->parent;
        } while (c);
    }
    return 0;
}

/* Returns self if its class (or a parent class) is lbl_88C698BC, else NULL. */
Obj *ts4_dynamic_cast_by_class_88204820(Obj *self)
{
    ClassInfo *c;
    if (self) {
        c = self->vt->get_class(self);
        do {
            if (c == &lbl_88C698BC) {
                return self;
            }
            c = c->parent;
        } while (c);
    }
    return 0;
}

/* Returns self if its class (or a parent class) is lbl_88C69614, else NULL. */
Obj *ts4_dynamic_cast_by_class_8820B298(Obj *self)
{
    ClassInfo *c;
    if (self) {
        c = self->vt->get_class(self);
        do {
            if (c == &lbl_88C69614) {
                return self;
            }
            c = c->parent;
        } while (c);
    }
    return 0;
}
