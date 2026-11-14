/* SM1 /O1 config batch 2: bitfield setters on the 0x18-byte per-slot records starting at +0x540 of the config object;
 * each also sets the slot's bit (counted from the top bit) in the 64-bit dirty mask at +0x18. */
typedef unsigned int u32;
typedef unsigned long long u64;

/* Field at record offset OFF, reached through a record pointer. */
#define SET_SLOT_FIELD_PTR(NAME, OFF, SH, MASK) \
    void NAME(char *p, int idx, u32 v) { \
        char *rec = p + (idx + 0x30) * 0x18; \
        u32 w = *(u32 *)(rec + OFF); \
        *(u32 *)(rec + OFF) = (w & ~(MASK)) | ((v << SH) & (MASK)); \
        *(u64 *)(p + 0x18) |= 0x8000000000000000ULL >> (u32)(idx + 0x20); \
    }

/* Field at record offset 0, reached through a byte offset. */
#define SET_SLOT_FIELD_IDX(NAME, SH, MASK) \
    void NAME(char *p, int idx, u32 v) { \
        int ro = (idx + 0x30) * 0x18; \
        u32 w = *(u32 *)(p + ro); \
        *(u32 *)(p + ro) = (w & ~(MASK)) | ((v << SH) & (MASK)); \
        *(u64 *)(p + 0x18) |= 0x8000000000000000ULL >> (u32)(idx + 0x20); \
    }

/* Swing_DLL.xex 0x8828D750 */
SET_SLOT_FIELD_PTR(ts4_cfg_set_slot_field_c_8828D750, 0xc, 23, 0x01800000u)
/* 0x8828DC78 */
SET_SLOT_FIELD_PTR(ts4_cfg_set_slot_field_14_8828DC78, 0x14, 3, 0x18u)
/* 0x8828DCD0 */
SET_SLOT_FIELD_PTR(ts4_cfg_set_slot_field_10a_8828DCD0, 0x10, 22, 0x7c00000u)
/* 0x8828DD28 */
SET_SLOT_FIELD_PTR(ts4_cfg_set_slot_field_10b_8828DD28, 0x10, 27, 0xf8000000u)
/* 0x8828DB88 */
SET_SLOT_FIELD_IDX(ts4_cfg_set_slot_field_0a_8828DB88, 10, 0x1c00u)
/* 0x8828DBD8 */
SET_SLOT_FIELD_IDX(ts4_cfg_set_slot_field_0b_8828DBD8, 13, 0xe000u)
/* 0x8828DC28 */
SET_SLOT_FIELD_IDX(ts4_cfg_set_slot_field_0c_8828DC28, 16, 0x70000u)
