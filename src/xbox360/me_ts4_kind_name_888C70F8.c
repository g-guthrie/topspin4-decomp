
typedef unsigned int u32; typedef unsigned char u8;
typedef struct Globals { char pad[0x2b8]; u32 kind_hash; } Globals;
extern Globals *lbl_88D45B1C;
extern const char lbl_880D7690[];
extern const char *lbl_880D091C[];
extern u32 ts4_map_id_to_slot_88883F38(void);
extern u8 ts4_registry_has_kind_88611E38(u32 kind);
extern u32 ts4_hash_to_kind_8860C128(u32 h);
const char *fn_888C70F8(void)
{
    const char *def = lbl_880D7690;
    u32 k = ts4_map_id_to_slot_88883F38();
    if (!ts4_registry_has_kind_88611E38(k))
        k = ts4_hash_to_kind_8860C128(lbl_88D45B1C->kind_hash);
    if (k < 6) def = lbl_880D091C[k];
    return def;
}
