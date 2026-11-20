/* SM2: field comparisons through an owner pointer, destroy-owned-field dtors, virtual tail calls. */
extern void ts4_destroy_owned_object(void *object);
extern char lbl_880D75FC[];
extern char lbl_880F37A4[];
extern char lbl_880F4854[];
extern char lbl_880D6B70[];

/* own field A (+A) compared with the field B (+B) of the object at +0xc */
#define OWNER_LE(NAME, A, B) \
    int NAME(char *p) { return *(int *)(p + (A)) <= *(int *)(*(char **)(p + 0xc) + (B)); }
#define OWNER_GE(NAME, A, B) \
    int NAME(char *p) { return *(int *)(p + (A)) >= *(int *)(*(char **)(p + 0xc) + (B)); }
OWNER_LE(ts4_owner_field_le_8865B330, 0x100, 0xb8)
OWNER_LE(ts4_owner_field_le_8865B2F0, 0x108, 0xc8)
OWNER_GE(ts4_owner_field_ge_8865B310, 0x104, 0xc0)
OWNER_GE(ts4_owner_field_ge_8865B4F0, 0x10c, 0x68)
OWNER_GE(ts4_owner_field_ge_8865B638, 0x80, 0x44)
OWNER_GE(ts4_owner_field_ge_8865B608, 0x90, 0x20)
OWNER_GE(ts4_owner_field_ge_8865B350, 0x90, 0xb0)
OWNER_GE(ts4_owner_field_ge_8865B6A0, 0x94, 0xc)
OWNER_GE(ts4_owner_field_ge_8865B550, 0x98, 0x48)
OWNER_GE(ts4_owner_field_ge_8865B370, 0x9c, 0xa4)
OWNER_GE(ts4_owner_field_ge_8865B390, 0xa0, 0x9c)
OWNER_GE(ts4_owner_field_ge_8865B5E8, 0xa4, 0x28)
OWNER_GE(ts4_owner_field_ge_8865B510, 0xb8, 0x5c)
OWNER_GE(ts4_owner_field_ge_8865B460, 0xbc, 0x8c)
OWNER_GE(ts4_owner_field_ge_8865B480, 0xf4, 0x7c)

/* reset vtable then destroy the owned object in FIELD */
#define DTOR_OWNED(NAME, VT, FIELD) \
    void NAME(char *p) { void *q; *(char *volatile *)p = (VT); q = *(void *volatile *)(p + (FIELD)); if (q) ts4_destroy_owned_object(q); }
DTOR_OWNED(ts4_dtor_owned_886CBB80, lbl_880D75FC, 4)
DTOR_OWNED(ts4_dtor_owned_886E2558, lbl_880F37A4, 0xc)
DTOR_OWNED(ts4_dtor_owned_8867C0E0, lbl_880F4854, 8)

/* call virtual slot SLOT on the object in FIELD when present */
#define VCALL_FIELD(NAME, FIELD, SLOT) \
    void NAME(char *p) { void **q = *(void ***)(p + (FIELD)); if (q) ((void (*)(void *))(*(void ***)q)[SLOT])(q); }
VCALL_FIELD(ts4_vcall_field_88636E88, 0, 0)
VCALL_FIELD(ts4_vcall_field_8860CB70, 0x178, 13)
VCALL_FIELD(ts4_vcall_field_8860CB50, 0x178, 27)

#define FIELD_EQ(NAME, F1, F2) \
    int NAME(char *p) { return *(int *)(*(char **)(*(char **)(p + 0x20) + (F1)) + (F2)) == *(int *)(p + 0x28); }
FIELD_EQ(ts4_field_matches_8865EA30, 0x30, 0x7c)
FIELD_EQ(ts4_field_matches_8865EA88, 0x44, 0x54)

int ts4_get_table_int_886EF8F8(char *p, int i)
{
    char *base = *(char **)(p + 0xc) + 0x14;
    return *(int *)(base + *(int *)base + i * 8 + 4);
}
float ts4_get_table_float_886EF8D8(char *p, int i)
{
    char *base = *(char **)(p + 0xc) + 0x20;
    return *(float *)(base + *(int *)base + i * 8 + 4);
}
#define BIND_AND_NOTIFY(NAME, OFF) \
    void NAME(char *p, char *owner) \
    { \
        void **vt = *(void ***)p; \
        char *t; \
        void (*fn)(void *); \
        *(char **)(p + 0x18) = owner; \
        t = *(char **)(owner + 0x74) + (OFF); \
        fn = (void (*)(void *))vt[1]; \
        *(char **)(p + 0x1c) = t; \
        fn(p); \
    }
void ts4_init_shorts_886F0420(char *p)
{
    *(short *)(p + 4) = -1;
    *(short *)(p + 8) = -1;
    *(short *)(p + 0xa) = 6;
    p[6] = 0;
}
