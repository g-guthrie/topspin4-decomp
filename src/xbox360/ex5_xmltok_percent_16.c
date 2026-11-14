/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX5: Expat xmltok_impl.c scanPercent for the two 16-bit encodings ("%" or "%name;" in a DTD). */
#include "ex5_xmltok16.h"

#define EX5_DEFINE_SCAN_PERCENT(name, HI, LO)                                                              \
int name(const SwbEnc *enc, const char *ptr, const char *end, const char **next)                          \
{                                                                                                          \
    if (ptr == end)                                                                                        \
        return SWB_TOK_PARTIAL;                                                                            \
    switch (EX5_UNIT_TYPE(enc, HI(ptr), LO(ptr))) {                                                        \
        EX5_CHECK_NMSTRT_CASES(HI, LO)                                                                     \
    case SWB_BT_CR:                                                                                        \
    case SWB_BT_LF:                                                                                        \
    case SWB_BT_S:                                                                                         \
    case 30: /* BT_PERCNT */                                                                               \
        *next = ptr;                                                                                       \
        return 22; /* XML_TOK_PERCENT */                                                                   \
    default:                                                                                               \
        *next = ptr;                                                                                       \
        return SWB_TOK_INVALID;                                                                            \
    }                                                                                                      \
    while (ptr != end) {                                                                                   \
        switch (EX5_UNIT_TYPE(enc, HI(ptr), LO(ptr))) {                                                    \
            EX5_CHECK_NAME_CASES(HI, LO)                                                                   \
        case SWB_BT_SEMI:                                                                                  \
            *next = ptr + 2;                                                                               \
            return 28; /* XML_TOK_PARAM_ENTITY_REF */                                                      \
        default:                                                                                           \
            *next = ptr;                                                                                   \
            return SWB_TOK_INVALID;                                                                        \
        }                                                                                                  \
    }                                                                                                      \
    return SWB_TOK_PARTIAL;                                                                                \
}

/* Swing_DLL.xex 0x888961E0 (big-endian UTF-16) */
EX5_DEFINE_SCAN_PERCENT(ex5_xml_scan_percent_big2_888961E0, EX5_HI_BIG2, EX5_LO_BIG2)
/* Swing_DLL.xex 0x888982F0 (little-endian UTF-16) */
EX5_DEFINE_SCAN_PERCENT(ex5_xml_scan_percent_little2_888982F0, EX5_HI_LITTLE2, EX5_LO_LITTLE2)
