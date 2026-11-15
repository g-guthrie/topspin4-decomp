/* W11H: manager destructor, LTCG route (integer-only, needed LTCG). Swing_DLL.xex 0x886D77B8 */
typedef unsigned int ts4_word;
void ts4_destroy_owned_object(void *object);
void ts4_registry_dispatch_888860A0(void *buffer);
extern void ts4_loop_call_seq_u32_off0_881B68A8(void *a, ts4_word b);
extern void ga6_destroy_owner_chain_886D36D8(void *a);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *a);
extern char lbl_880F37A8[];
extern void *lbl_88D45AF4;
extern void *lbl_88D45AF8;
void ts4_destroy_manager_886D77B8(char *self)
{
    ts4_word zero = 0;
    void *buffer = *(void **)(self + 0x14C);
    *(void **)self = lbl_880F37A8;
    lbl_88D45AF4 = 0;
    lbl_88D45AF8 = 0;
    if ((long)buffer != 0) {
        ts4_registry_dispatch_888860A0(buffer);
        *(void **)(self + 0x14C) = 0;
        *(ts4_word *)(self + 0x150) = zero;
    }
    ts4_loop_call_seq_u32_off0_881B68A8(*(void **)(self + 0x158), *(ts4_word *)(self + 0x15C));
    if (*(void **)(self + 0x158))
        ts4_destroy_owned_object(*(void **)(self + 0x158));
    ga6_destroy_owner_chain_886D36D8(self + 0x68);
    if (*(void **)(self + 0x5C))
        ts4_destroy_owned_object(*(void **)(self + 0x5C));
    if (*(void **)(self + 0x50))
        ts4_destroy_owned_object(*(void **)(self + 0x50));
    ts4_if_call_seq_lbl_880F7EE4_88617D28(self);
}
