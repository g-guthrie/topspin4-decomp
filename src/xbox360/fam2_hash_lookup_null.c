/* Family FAM2: global hash-table lookups with the null handle (Swing_DLL.xex 0x8884A070..0x888E3908).
   Each looks HASH up in the table held by lbl_88D458F0 via ts4_hash_find_881AB900, passing the null handle
   {0, 0xFFFFF, 0} by value; variants return the entry, the address of the entry's +0xc field, or
   release the entry (fn_889254C8 with 1) when its +0xc word is set. */
typedef unsigned int u32;
typedef struct Ts4Handle12 { u32 a, b, c; } Ts4Handle12;
typedef struct Ts4HashEntry { u32 f0, f4, f8, f0c; } Ts4HashEntry;
extern void *lbl_88D458F0;
extern Ts4HashEntry *ts4_hash_find_881AB900(void *table, u32 hash, Ts4Handle12 h);
extern void fn_889254C8(Ts4HashEntry *entry, u32 flag);

static __inline Ts4HashEntry *hash_lookup_null(u32 hash)
{
    Ts4Handle12 h;
    h.a = 0;
    h.b = 0xFFFFF;
    h.c = 0;
    return ts4_hash_find_881AB900(lbl_88D458F0, hash, h);
}

#define TS4_HASH_LOOKUP_NULL(A, HASH) \
Ts4HashEntry *ts4_hash_lookup_null_##A(void); \
Ts4HashEntry *ts4_hash_lookup_null_##A(void) \
{ \
    return hash_lookup_null(HASH); \
}

#define TS4_HASH_LOOKUP_NULL_FIELD(A, HASH) \
u32 *ts4_hash_lookup_null_field_##A(void); \
u32 *ts4_hash_lookup_null_field_##A(void) \
{ \
    return &hash_lookup_null(HASH)->f0c; \
}

#define TS4_HASH_LOOKUP_NULL_RELEASE(A, HASH) \
void ts4_hash_lookup_null_release_##A(void); \
void ts4_hash_lookup_null_release_##A(void) \
{ \
    Ts4HashEntry *e = hash_lookup_null(HASH); \
    if (e->f0c) \
        fn_889254C8(e, 1); \
}

/* Release as above, then clear the owner's word at OFF. */
#define TS4_HASH_LOOKUP_NULL_RELEASE_CLEAR(A, HASH, OFF) \
void ts4_hash_lookup_null_release_clear_##A(char *self); \
void ts4_hash_lookup_null_release_clear_##A(char *self) \
{ \
    Ts4HashEntry *e = hash_lookup_null(HASH); \
    if (e->f0c) \
        fn_889254C8(e, 1); \
    *(u32 *)(self + OFF) = 0; \
}

/* As above, only when the owner's (signed) word at OFF is non-zero. */
#define TS4_HASH_LOOKUP_NULL_RELEASE_IF(A, HASH, OFF) \
void ts4_hash_lookup_null_release_if_##A(char *self); \
void ts4_hash_lookup_null_release_if_##A(char *self) \
{ \
    if (*(int *)(self + OFF) != 0) { \
        Ts4HashEntry *e = hash_lookup_null(HASH); \
        if (e->f0c) \
            fn_889254C8(e, 1); \
        *(int *)(self + OFF) = 0; \
    } \
}

/* Swing_DLL.xex addresses */
TS4_HASH_LOOKUP_NULL(8884A070, 0xBD725A0E)
TS4_HASH_LOOKUP_NULL(8884A150, 0xE395D6A4)
TS4_HASH_LOOKUP_NULL(8884CB00, 0x0B6E4489)
TS4_HASH_LOOKUP_NULL(8884E330, 0x52FF4F73)
TS4_HASH_LOOKUP_NULL(88868788, 0x0B6E4489)
TS4_HASH_LOOKUP_NULL(888689A8, 0x5621DE55)
TS4_HASH_LOOKUP_NULL(88868AF8, 0x251E3B37)
TS4_HASH_LOOKUP_NULL(88868C48, 0x8928F4FD)
TS4_HASH_LOOKUP_NULL_FIELD(8884A1A0, 0xE395D6A4)
TS4_HASH_LOOKUP_NULL_RELEASE(888E38A8, 0x9B6E0EFE)
TS4_HASH_LOOKUP_NULL_RELEASE(888E3908, 0xAD0C7318)
TS4_HASH_LOOKUP_NULL_RELEASE_CLEAR(8884CB50, 0x49872A9E, 0x28)
TS4_HASH_LOOKUP_NULL_RELEASE_IF(8884BA30, 0x6DD09F08, 0x48)
