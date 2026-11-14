/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX5: Expat xmltok_impl.c scanPoundName for the two 16-bit encodings ("#NAME" tokens). */
#include "ex5_xmltok16.h"

#define EX5_DEFINE_SCAN_POUND_NAME(name, HI, LO)                                                           \
int name(const SwbEnc *enc, const char *ptr, const char *end, const char **next)                          \
{                                                                                                          \
    if (ptr == end)                                                                                        \
        return SWB_TOK_PARTIAL;                                                                            \
    switch (EX5_UNIT_TYPE(enc, HI(ptr), LO(ptr))) {                                                        \
        EX5_CHECK_NMSTRT_CASES(HI, LO)                                                                     \
    default:                                                                                               \
        *next = ptr;                                                                                       \
        return SWB_TOK_INVALID;                                                                            \
    }                                                                                                      \
    while (ptr != end) {                                                                                   \
        switch (EX5_UNIT_TYPE(enc, HI(ptr), LO(ptr))) {                                                    \
            EX5_CHECK_NAME_CASES(HI, LO)                                                                   \
        case SWB_BT_CR:                                                                                    \
        case SWB_BT_LF:                                                                                    \
        case SWB_BT_S:                                                                                     \
        case 30: /* BT_PERCNT */                                                                           \
        case 32: /* BT_RPAR */                                                                             \
        case SWB_BT_GT:                                                                                    \
        case 36: /* BT_VERBAR */                                                                           \
            *next = ptr;                                                                                   \
            return 20; /* XML_TOK_POUND_NAME */                                                            \
        default:                                                                                           \
            *next = ptr;                                                                                   \
            return SWB_TOK_INVALID;                                                                        \
        }                                                                                                  \
    }                                                                                                      \
    return -20;                                                                                            \
}

/* Swing_DLL.xex 0x88895F30 (big-endian UTF-16) */
EX5_DEFINE_SCAN_POUND_NAME(ex5_xml_scan_pound_name_big2_88895F30, EX5_HI_BIG2, EX5_LO_BIG2)
/* Swing_DLL.xex 0x88898050 (little-endian UTF-16) */
EX5_DEFINE_SCAN_POUND_NAME(ex5_xml_scan_pound_name_little2_88898050, EX5_HI_LITTLE2, EX5_LO_LITTLE2)
