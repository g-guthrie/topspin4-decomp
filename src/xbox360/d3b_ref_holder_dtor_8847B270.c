/* Swing_DLL.xex 0x8847B270-0x88481F5C, executable version 0.0.0.3. */
typedef struct Ref { void **vtbl; unsigned short size; short refs; } Ref;
extern char lbl_88083C8C[], lbl_8803A308[];
extern char lbl_8808406C[];
extern char lbl_880842B8[];
extern char lbl_8808466C[];

/* Destructor body: installs the class vtable, drops the counted reference held at a fixed offset (destroying it
   through its first virtual slot when the count reaches zero), then installs the base vtable. */
#define REF_HOLDER_DTOR(NAME, OFF, LABEL) \
typedef struct NAME##_obj { void *vtbl; char pad[(OFF) - 4]; Ref *ref; } NAME##_obj; \
void NAME(NAME##_obj *self) \
{ \
    Ref *r; \
    self->vtbl = LABEL; \
    r = self->ref; \
    if (r != 0 && r->size != 0) { \
        short n = r->refs - 1; \
        r->refs = n; \
        if (n == 0) ((void (*)(Ref *, int))r->vtbl[0])(r, 1); \
    } \
    self->vtbl = lbl_8803A308; \
}

REF_HOLDER_DTOR(ts4_ref_holder_dtor_8847B270, 0x118, lbl_88083C8C)
REF_HOLDER_DTOR(ts4_ref_holder_dtor_8847D7F0, 0xb0, lbl_8808406C)
REF_HOLDER_DTOR(ts4_ref_holder_dtor_88480128, 0x18, lbl_880842B8)
REF_HOLDER_DTOR(ts4_ref_holder_dtor_88481ED8, 0xac, lbl_8808466C)
