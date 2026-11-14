/* Family LG1: key registration list (region 0x8869BC48, see docs/gameplay/gp0.md).
 * Passes 30 name hashes, one per callee, to the keyed-item list lbl_88D45B20. All callees but one are the
 * "add keyed item if mode" thunks (src/xbox360/fa_keyed_item_add_if_mode.cpp): when *mode == 1 they append
 * an item with that key and their own vtable unless the key is already present. */

typedef struct lg1_service_key {
    unsigned int hash;
} lg1_service_key;

extern void *lbl_88D45B20; /* keyed-item list (placeholder name) */
void ts4_keyed_item_add_or_remove_889C1788(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_8867E2C0(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_8867EC50(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_886810C0(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_886811F8(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_886812D8(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_88681468(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_886815E8(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_88681768(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_88681DC0(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_88681F40(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_886820C0(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_88682A78(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_88682E60(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_886871C0(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_8868BFB0(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_8868C998(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_8868CE18(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_8868CF98(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_8868D118(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_8868D298(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_88690208(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_88690760(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_88690840(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_886927C0(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_88692F60(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_88693630(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_88693710(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_88693D48(void *list, lg1_service_key *key, unsigned char *mode);
void ts4_keyed_item_list_add_unique_if_mode_88693E28(void *list, lg1_service_key *key, unsigned char *mode);

/* Offer each of the 30 key hashes to its keyed-item thunk. Swing_DLL.xex 0x8869C9E8 */
void ts4_keyed_items_register_all_8869C9E8(unsigned char *mode)
{
    lg1_service_key key;
    key.hash = 0xD18BEF51u;
    ts4_keyed_item_list_add_unique_if_mode_88690840(lbl_88D45B20, &key, mode);
    key.hash = 0xE81F2AE1u;
    ts4_keyed_item_list_add_unique_if_mode_88690760(lbl_88D45B20, &key, mode);
    key.hash = 0xE73B8150u;
    ts4_keyed_item_list_add_unique_if_mode_88690208(lbl_88D45B20, &key, mode);
    key.hash = 0x9BD3657Eu;
    ts4_keyed_item_list_add_unique_if_mode_8867E2C0(lbl_88D45B20, &key, mode);
    key.hash = 0xAF20A359u;
    ts4_keyed_item_list_add_unique_if_mode_88693D48(lbl_88D45B20, &key, mode);
    key.hash = 0x85B71A2Bu;
    ts4_keyed_item_list_add_unique_if_mode_88692F60(lbl_88D45B20, &key, mode);
    key.hash = 0x83B15071u;
    ts4_keyed_item_list_add_unique_if_mode_886927C0(lbl_88D45B20, &key, mode);
    key.hash = 0x36594CC8u;
    ts4_keyed_item_add_or_remove_889C1788(lbl_88D45B20, &key, mode);
    key.hash = 0x6034F29Cu;
    ts4_keyed_item_list_add_unique_if_mode_88693630(lbl_88D45B20, &key, mode);
    key.hash = 0x4AC3C6C8u;
    ts4_keyed_item_list_add_unique_if_mode_88693710(lbl_88D45B20, &key, mode);
    key.hash = 0xB0EF04B3u;
    ts4_keyed_item_list_add_unique_if_mode_88693E28(lbl_88D45B20, &key, mode);
    key.hash = 0x961271DFu;
    ts4_keyed_item_list_add_unique_if_mode_886812D8(lbl_88D45B20, &key, mode);
    key.hash = 0x0E0DB124u;
    ts4_keyed_item_list_add_unique_if_mode_88681768(lbl_88D45B20, &key, mode);
    key.hash = 0x2DF2A93Au;
    ts4_keyed_item_list_add_unique_if_mode_886820C0(lbl_88D45B20, &key, mode);
    key.hash = 0x5989B500u;
    ts4_keyed_item_list_add_unique_if_mode_88681468(lbl_88D45B20, &key, mode);
    key.hash = 0x34B31A80u;
    ts4_keyed_item_list_add_unique_if_mode_88681DC0(lbl_88D45B20, &key, mode);
    key.hash = 0xB9F15B60u;
    ts4_keyed_item_list_add_unique_if_mode_88682A78(lbl_88D45B20, &key, mode);
    key.hash = 0x368ED310u;
    ts4_keyed_item_list_add_unique_if_mode_8868BFB0(lbl_88D45B20, &key, mode);
    key.hash = 0x4B649818u;
    ts4_keyed_item_list_add_unique_if_mode_8868CE18(lbl_88D45B20, &key, mode);
    key.hash = 0x14C197B0u;
    ts4_keyed_item_list_add_unique_if_mode_8868D118(lbl_88D45B20, &key, mode);
    key.hash = 0x46617B17u;
    ts4_keyed_item_list_add_unique_if_mode_8868C998(lbl_88D45B20, &key, mode);
    key.hash = 0x04E0BD27u;
    ts4_keyed_item_list_add_unique_if_mode_8868CF98(lbl_88D45B20, &key, mode);
    key.hash = 0xFE44A736u;
    ts4_keyed_item_list_add_unique_if_mode_8868D298(lbl_88D45B20, &key, mode);
    key.hash = 0x002DAC2Bu;
    ts4_keyed_item_list_add_unique_if_mode_886815E8(lbl_88D45B20, &key, mode);
    key.hash = 0xEDF815A4u;
    ts4_keyed_item_list_add_unique_if_mode_88681F40(lbl_88D45B20, &key, mode);
    key.hash = 0x4D7FB59Du;
    ts4_keyed_item_list_add_unique_if_mode_88682E60(lbl_88D45B20, &key, mode);
    key.hash = 0x23428A2Cu;
    ts4_keyed_item_list_add_unique_if_mode_886871C0(lbl_88D45B20, &key, mode);
    key.hash = 0xAF2346B9u;
    ts4_keyed_item_list_add_unique_if_mode_886811F8(lbl_88D45B20, &key, mode);
    key.hash = 0x9D187419u;
    ts4_keyed_item_list_add_unique_if_mode_886810C0(lbl_88D45B20, &key, mode);
    key.hash = 0xDD92070Au;
    ts4_keyed_item_list_add_unique_if_mode_8867EC50(lbl_88D45B20, &key, mode);
}
