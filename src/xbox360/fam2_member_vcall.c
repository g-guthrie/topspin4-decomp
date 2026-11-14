/* FAM2: forwarders that invoke one virtual slot on an optional member
 * interface (pointer at FIELD), doing nothing when the member is null.
 * Built at /O1 like the surrounding 0x8859xxxx code. */
typedef unsigned int u32;
typedef void (*Ts4VoidMethod)(void *self);

#define TS4_VSLOT(OBJ, SLOT) ((*(void ***)(OBJ))[(SLOT) / 4])

#define TS4_MEMBER_VCALL(A, FIELD, SLOT) \
void ts4_member_vcall_##A(char *self) \
{ \
    if (*(void **)(self + FIELD)) \
        ((Ts4VoidMethod)TS4_VSLOT(*(void **)(self + FIELD), SLOT))(*(void **)(self + FIELD)); \
}

TS4_MEMBER_VCALL(88598D20, 0x38, 0x4)
TS4_MEMBER_VCALL(88598D48, 0x38, 0xc)
TS4_MEMBER_VCALL(88598D70, 0x38, 0x14)
TS4_MEMBER_VCALL(885A4E98, 0x44, 0x0)
TS4_MEMBER_VCALL(885A4EC0, 0x44, 0x4)
TS4_MEMBER_VCALL(885A4EE8, 0x44, 0xc)
