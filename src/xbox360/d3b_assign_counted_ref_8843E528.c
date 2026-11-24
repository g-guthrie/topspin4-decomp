/* Swing_DLL.xex 0x8843E528-0x884D4134, executable version 0.0.0.3. */
typedef struct Ref { void **vtbl; unsigned short size; short refs; } Ref;

/* Replaces a counted-reference member: takes a reference on the new value, drops the old one (destroying it
   through its first virtual slot at zero), then stores the new pointer. */
#define REF_ASSIGN(NAME, OFF) \
typedef struct NAME##_obj { char pad[OFF]; Ref *ref; } NAME##_obj; \
void NAME(NAME##_obj *self, Ref *r) \
{ \
    Ref *old; \
    if (r != 0 && r->size != 0) r->refs = r->refs + 1; \
    old = self->ref; \
    if (old != 0 && old->size != 0) { \
        short n = old->refs - 1; \
        old->refs = n; \
        if (n == 0) ((void (*)(Ref *, int))old->vtbl[0])(old, 1); \
    } \
    self->ref = r; \
}

REF_ASSIGN(ts4_assign_counted_ref_8843E528, 0x5c)
REF_ASSIGN(ts4_assign_counted_ref_8846A7F8, 0x50)
REF_ASSIGN(ts4_assign_counted_ref_8847B168, 0x118)
REF_ASSIGN(ts4_assign_counted_ref_8847D678, 0xb0)
REF_ASSIGN(ts4_assign_counted_ref_8847FE40, 0x18)
REF_ASSIGN(ts4_assign_counted_ref_88481D68, 0xac)
REF_ASSIGN(ts4_assign_counted_ref_884C53A8, 0x18)
REF_ASSIGN(ts4_assign_counted_ref_884D4098, 0x1c)
