/* R6: net/session keyed property resets (Swing_DLL.xex 0x889xxxxx). */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Ts4NetGuid {
    u32 word[3];
} Ts4NetGuid;

struct Ts4NetPropStore;
typedef struct Ts4NetPropRef {
    struct Ts4NetPropStore *store;
    u32 index;
    u32 pad[2];
} Ts4NetPropRef;

typedef struct Ts4NetPropStoreVtbl {
    u32 pad[0x28 / 4];
    u8 *(*lookup)(struct Ts4NetPropStore *store, Ts4NetPropRef *ref, u32 index, int create);
} Ts4NetPropStoreVtbl;

typedef struct Ts4NetPropStore {
    Ts4NetPropStoreVtbl *vtbl;
} Ts4NetPropStore;

typedef struct Ts4NetPropOwner {
    u32 pad;
} Ts4NetPropOwner;

typedef struct Ts4NetGuid16 {
    u32 word[4];
} Ts4NetGuid16;

typedef struct Ts4NetOwnerRef {
    u32 pad[2];
} Ts4NetOwnerRef;

extern Ts4NetGuid lbl_88C6B410;
extern char *lbl_88D45AD4;
void fn_8876BCA8(void *block);
void fn_88610778(void *owner, void *guid, u32 *key);
Ts4NetPropRef *fn_88164450(Ts4NetPropRef *out, Ts4NetPropOwner *owner, u32 *key, int flag);

/* Swing_DLL.xex 0x88944F58: register a keyed entry then clear two byte properties by key. */
Ts4NetPropOwner *ts4_net_reset_two_props_88944F58(Ts4NetPropOwner *owner)
{
    Ts4NetGuid guid = lbl_88C6B410;
    u32 key_register = 0x7C78B5F5;
    u32 key_a;
    u32 key_b;
    Ts4NetPropRef ref;
    Ts4NetPropRef *found;

    fn_88610778(owner, &guid, &key_register);
    key_a = 0xD91411DA;
    found = fn_88164450(&ref, owner, &key_a, 0);
    *found->store->vtbl->lookup(found->store, found, found->index, 1) = 0;
    key_b = 0xB01F4F95;
    found = fn_88164450(&ref, owner, &key_b, 0);
    *found->store->vtbl->lookup(found->store, found, found->index, 1) = 0;
    return owner;
}

/* Swing_DLL.xex 0x8890A948: set one byte property by key, clear another, optionally notify. */
void ts4_net_set_prop_byte_8890A948(Ts4NetGuid16 guid, u8 notify, u8 value)
{
    u32 key_register = 0x7C78B5F5;
    u32 key_a;
    u32 key_b;
    Ts4NetOwnerRef owner;
    Ts4NetPropRef ref;
    Ts4NetPropRef *found;

    fn_88610778(&owner, &guid, &key_register);
    key_a = 0xD91411DA;
    found = fn_88164450(&ref, (Ts4NetPropOwner *)&owner, &key_a, 0);
    *found->store->vtbl->lookup(found->store, found, found->index, 1) = value;
    key_b = 0xB01F4F95;
    found = fn_88164450(&ref, (Ts4NetPropOwner *)&owner, &key_b, 0);
    *found->store->vtbl->lookup(found->store, found, found->index, 1) = 0;
    if (notify) {
        fn_8876BCA8(lbl_88D45AD4 + 0x150);
    }
}
