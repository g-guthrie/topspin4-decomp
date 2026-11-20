/*
 * GA6: gameplay slot-table accessors.
 */
typedef unsigned int ts4_word;

/* Pointer to the n-th 8-byte slot (n in 0..7); out-of-range n returns base unchanged. */
#define GA6_SLOT_PTR(NAME, ADDR) \
    /* Swing_DLL.xex ADDR */ \
    char *NAME(char *base, ts4_word n) \
    { \
        switch (n) { \
        case 0: return base; \
        case 1: return base + 8; \
        case 2: return base + 16; \
        case 3: return base + 24; \
        case 4: return base + 32; \
        case 5: return base + 40; \
        case 6: return base + 48; \
        case 7: return base + 56; \
        default: return base; \
        } \
    }

GA6_SLOT_PTR(ga6_slot_ptr_886E62B8, 0x886E62B8)
GA6_SLOT_PTR(ga6_slot_ptr_886E6388, 0x886E6388)
