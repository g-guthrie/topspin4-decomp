/* 0x886A06B0: builds the 7-entry key -> accessor table: allocates the accessor array and a zeroed key array from the
 * default heap and fills them with the chain/field accessors and their key hashes. */
typedef unsigned int u32;
typedef void (*Ts4KeyFn)(void);
extern void *lbl_88D45B38;
void *ts4_node_dispatch_with_target_88613268(void *heap, int size, int align, int flags, int tag);
void ts4_get_u32_off1c_88269E10(void);
void ts4_key_matches_chain_or_constant_88269E30(void);
void ts4_compare_chain_field_to_key_88269E68(void);
void ts4_get_u32_off18_88269EC0(void);
void ts4_if_get_u32_off18_88269E88(void);
void ts4_tailcall_fn_88660D10_88269EE0(void);
void ts4_if_get_u32_off1c_88269EE8(void);
typedef struct Ts4KeyTable { void *unk; Ts4KeyFn *fns; int fn_count; u32 *keys; int key_count; } Ts4KeyTable;
static __inline u32 *alloc_zeroed_u32(int n)
{
    u32 *p = (u32 *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, n * 4, 4, 0, 2);
    u32 *r;
    if (p) { int i; for (i = 0; i < n; i++) p[i] = 0; r = p; }
    else r = 0;
    return r;
}
void ts4_key_table_init(Ts4KeyTable *t)
{
    t->fns = (Ts4KeyFn *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 7 * 4, 4, 0, 2);
    t->fn_count = 7;
    t->keys = alloc_zeroed_u32(7);
    t->key_count = 7;
    t->fns[0] = ts4_get_u32_off1c_88269E10;             t->keys[0] = 0xAD4BA1ABu;
    t->fns[1] = ts4_key_matches_chain_or_constant_88269E30; t->keys[1] = 0x96793E47u;
    t->fns[2] = ts4_compare_chain_field_to_key_88269E68; t->keys[2] = 0x860F3051u;
    t->fns[3] = ts4_get_u32_off18_88269EC0;             t->keys[3] = 0xE4DC7934u;
    t->fns[4] = ts4_if_get_u32_off18_88269E88;          t->keys[4] = 0x73FCA7F2u;
    t->fns[5] = ts4_tailcall_fn_88660D10_88269EE0;      t->keys[5] = 0xA906C730u;
    t->fns[6] = ts4_if_get_u32_off1c_88269EE8;          t->keys[6] = 0x80EC0B87u;
}
