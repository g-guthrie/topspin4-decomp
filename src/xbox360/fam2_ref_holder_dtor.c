/* Family FAM2: reference-holder destructors without a NULL test (Swing_DLL.xex 0x88427338..0x885ED798).
   Each installs the class vtable, drops one reference of the counted record held at FIELD (when the
   record's size is non-zero; the record deletes itself through its vtable slot 0 when the count reaches
   zero) and finally installs the base vtable.  Same body as d3b_ref_holder_dtor_8841D638.c minus the
   NULL check on the held record. */
typedef unsigned int u32;
typedef struct Ts4CountedRef { void **vtbl; unsigned short size; short refs; } Ts4CountedRef;
extern char lbl_8803A308[], lbl_8807FF50[];
extern char lbl_8808CCCC[], lbl_880C079C[], lbl_8807FF98[], lbl_8808BFC0[], lbl_8808C7DC[];
extern void fn_885E7BA8(void *);
void ts4_ref_holder_dtor_88436F58(void **self);
#define TS4_RHD_88436F58(p) ts4_ref_holder_dtor_88436F58((void **)(p))
extern char lbl_8803EADC[], lbl_8807FF74[], lbl_88080AA4[], lbl_88087004[], lbl_880870F4[], lbl_8808CE18[], lbl_880C0F8C[];

#define TS4_REF_HOLDER_DTOR(A, VT, BASE_VT, FIELD) \
void ts4_ref_holder_dtor_##A(void **self); \
void ts4_ref_holder_dtor_##A(void **self) \
{ \
    Ts4CountedRef *r = *(Ts4CountedRef **)((char *)self + FIELD); \
    self[0] = VT; \
    if (r->size != 0) { \
        short n = r->refs - 1; \
        r->refs = n; \
        if (n == 0) \
            ((void (*)(Ts4CountedRef *, int))r->vtbl[0])(r, 1); \
    } \
    self[0] = BASE_VT; \
}

static __inline void counted_ref_release(Ts4CountedRef *r)
{
    if (r->size != 0) {
        short n = r->refs - 1;
        r->refs = n;
        if (n == 0)
            ((void (*)(Ts4CountedRef *, int))r->vtbl[0])(r, 1);
    }
}

/* As above, tolerating a NULL record. */
#define TS4_REF_HOLDER_DTOR_NULLABLE(A, VT, FIELD) \
void ts4_ref_holder_dtor_nullable_##A(void **self); \
void ts4_ref_holder_dtor_nullable_##A(void **self) \
{ \
    Ts4CountedRef *r = *(Ts4CountedRef **)((char *)self + FIELD); \
    self[0] = VT; \
    if (r != 0) \
        counted_ref_release(r); \
    self[0] = lbl_8803A308; \
}

/* As above, also destroying the member at MEMBER with MEMBER_DTOR. */
#define TS4_REF_HOLDER_DTOR_MEMBER(A, VT, FIELD, MEMBER, MEMBER_DTOR) \
void ts4_ref_holder_dtor_member_##A(void **self); \
void ts4_ref_holder_dtor_member_##A(void **self) \
{ \
    Ts4CountedRef *r = *(Ts4CountedRef **)((char *)self + FIELD); \
    self[0] = VT; \
    counted_ref_release(r); \
    MEMBER_DTOR((char *)self + MEMBER); \
    self[0] = lbl_8803A308; \
}

#define TS4_REF_HOLDER_DTOR_NULLABLE_MEMBER(A, VT, FIELD, MEMBER, MEMBER_DTOR) \
void ts4_ref_holder_dtor_nullable_member_##A(void **self); \
void ts4_ref_holder_dtor_nullable_member_##A(void **self) \
{ \
    Ts4CountedRef *r = *(Ts4CountedRef **)((char *)self + FIELD); \
    self[0] = VT; \
    if (r != 0) \
        counted_ref_release(r); \
    MEMBER_DTOR((char *)self + MEMBER); \
    self[0] = lbl_8803A308; \
}

/* Replace the record held at FIELD by r, taking a reference on r first. */
#define TS4_REF_HOLDER_ASSIGN(A, FIELD) \
void ts4_ref_holder_assign_##A(char *self, Ts4CountedRef *r); \
void ts4_ref_holder_assign_##A(char *self, Ts4CountedRef *r) \
{ \
    if (r->size != 0) \
        r->refs++; \
    counted_ref_release(*(Ts4CountedRef **)(self + FIELD)); \
    *(Ts4CountedRef **)(self + FIELD) = r; \
}

/* Release element i of the counted-record array at DATA and move the last element into its place.
   The _IDX spelling indexes the array for the released element, which flips the operand order of
   the indexed load. */
#define REF_ARRAY_AT_OFF(self, DATA, i, off) (*(Ts4CountedRef **)(*(char **)((self) + DATA) + (off)))
#define TS4_REF_ARRAY_SWAP_REMOVE_IDX(A, DATA, COUNT) \
void ts4_ref_array_swap_remove_##A(char *self, u32 i); \
void ts4_ref_array_swap_remove_##A(char *self, u32 i) \
{ \
    counted_ref_release((*(Ts4CountedRef ***)(self + DATA))[i]); \
    (*(Ts4CountedRef ***)(self + DATA))[i] = (*(Ts4CountedRef ***)(self + DATA))[--*(u32 *)(self + COUNT)]; \
}
#define TS4_REF_ARRAY_SWAP_REMOVE(A, DATA, COUNT, LOAD) \
void ts4_ref_array_swap_remove_##A(char *self, u32 i); \
void ts4_ref_array_swap_remove_##A(char *self, u32 i) \
{ \
    u32 off = i * 4; \
    counted_ref_release(LOAD(self, DATA, i, off)); \
    { \
        u32 n = --*(u32 *)(self + COUNT); \
        char *d = *(char **)(self + DATA); \
        *(Ts4CountedRef **)(off + d) = ((Ts4CountedRef **)d)[n]; \
    } \
}

/* Ref-holder destructor that also deletes the owned object at +0xc (Swing_DLL.xex 0x884DA7B0). */
extern void ts4_pooled_deleting_dtor_884DA998(void *obj, u32 flags);
void ts4_ref_holder_dtor_owner_884DA7B0(void **self);
void ts4_ref_holder_dtor_owner_884DA7B0(void **self)
{
    Ts4CountedRef *r = (Ts4CountedRef *)self[2];
    self[0] = lbl_8808CCCC;
    counted_ref_release(r);
    if (self[3])
        ts4_pooled_deleting_dtor_884DA998(self[3], 1);
    self[0] = lbl_8803A308;
}

/* Drop one reference (Swing_DLL.xex 0x88475B08, 0x884893F8). */
void ts4_counted_ref_release_88475B08(Ts4CountedRef *r);
void ts4_counted_ref_release_88475B08(Ts4CountedRef *r) { counted_ref_release(r); }
void ts4_counted_ref_release_884893F8(Ts4CountedRef *r);
void ts4_counted_ref_release_884893F8(Ts4CountedRef *r) { counted_ref_release(r); }

/* Swing_DLL.xex addresses */
TS4_REF_HOLDER_DTOR(88427338, lbl_8803EADC, lbl_8803A308, 0x8)
TS4_REF_HOLDER_DTOR(88436F58, lbl_8807FF74, lbl_8807FF50, 0x4)
TS4_REF_HOLDER_DTOR(88437EE8, lbl_88080AA4, lbl_8803A308, 0x10)
TS4_REF_HOLDER_DTOR(88479760, lbl_88087004, lbl_8803A308, 0x18)
TS4_REF_HOLDER_DTOR(8847E9F0, lbl_880870F4, lbl_8803A308, 0xc)
TS4_REF_HOLDER_DTOR(884DCDD8, lbl_8808CE18, lbl_8803A308, 0x8)
TS4_REF_HOLDER_DTOR(885ED798, lbl_880C0F8C, lbl_8803A308, 0x8)
TS4_REF_HOLDER_DTOR_NULLABLE(885EC7D8, lbl_880C079C, 0x8)
TS4_REF_HOLDER_DTOR_MEMBER(8843A1C8, lbl_8807FF98, 0x10, 0x14, TS4_RHD_88436F58)
TS4_REF_HOLDER_DTOR_NULLABLE_MEMBER(884C9150, lbl_8808BFC0, 0x18, 0x8, fn_885E7BA8)
TS4_REF_HOLDER_DTOR_NULLABLE_MEMBER(884D4008, lbl_8808C7DC, 0x1c, 0xc, fn_885E7BA8)
TS4_REF_HOLDER_ASSIGN(8841D478, 0x8)
TS4_REF_HOLDER_ASSIGN(88427210, 0x8)
TS4_REF_HOLDER_ASSIGN(885EC6B0, 0x8)
TS4_REF_ARRAY_SWAP_REMOVE(8847EC18, 0x14, 0x18, REF_ARRAY_AT_OFF)
TS4_REF_ARRAY_SWAP_REMOVE_IDX(8847ECA8, 0x20, 0x24)
TS4_REF_ARRAY_SWAP_REMOVE_IDX(884A7310, 0x44, 0x48)
