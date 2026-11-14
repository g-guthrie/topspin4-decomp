/* Swing_DLL.xex 0x8841D638-0x8841DC24, executable version 0.0.0.3. */
typedef struct Ref { void **vtbl; unsigned short size; short refs; } Ref;
typedef struct Obj { void *vtbl; char pad[4]; Ref *ref; } Obj;
extern char lbl_8803DE18[], lbl_8803DE28[], lbl_8803A308[];

void ts4_ref_holder_dtor_8841D638(Obj *self)
{
    Ref *r = self->ref;
    self->vtbl = lbl_8803DE18;
    if (r != 0 && r->size != 0) {
        short n = r->refs - 1;
        r->refs = n;
        if (n == 0) ((void (*)(Ref *, int))r->vtbl[0])(r, 1);
    }
    self->vtbl = lbl_8803A308;
}

void ts4_ref_holder_dtor_8841DBA0(Obj *self)
{
    Ref *r = self->ref;
    self->vtbl = lbl_8803DE28;
    if (r != 0 && r->size != 0) {
        short n = r->refs - 1;
        r->refs = n;
        if (n == 0) ((void (*)(Ref *, int))r->vtbl[0])(r, 1);
    }
    self->vtbl = lbl_8803A308;
}
