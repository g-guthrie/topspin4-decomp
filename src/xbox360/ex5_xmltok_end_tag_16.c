/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX5: Expat xmltok_impl.c scanEndTag for the two 16-bit encodings (after "</"). */
#include "ex5_xmltok16.h"

#define EX5_DEFINE_SCAN_END_TAG(name, HI, LO)                                                              \
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
        case SWB_BT_S:                                                                                     \
        case SWB_BT_CR:                                                                                    \
        case SWB_BT_LF:                                                                                    \
            for (ptr += 2; ptr != end; ptr += 2) {                                                         \
                switch (EX5_UNIT_TYPE(enc, HI(ptr), LO(ptr))) {                                            \
                case SWB_BT_S:                                                                             \
                case SWB_BT_CR:                                                                            \
                case SWB_BT_LF:                                                                            \
                    break;                                                                                 \
                case SWB_BT_GT:                                                                            \
                    *next = ptr + 2;                                                                       \
                    return 5; /* XML_TOK_END_TAG */                                                        \
                default:                                                                                   \
                    *next = ptr;                                                                           \
                    return SWB_TOK_INVALID;                                                                \
                }                                                                                          \
            }                                                                                              \
            return SWB_TOK_PARTIAL;                                                                        \
        case SWB_BT_COLON:                                                                                 \
            ptr += 2;                                                                                      \
            break;                                                                                         \
        case SWB_BT_GT:                                                                                    \
            *next = ptr + 2;                                                                               \
            return 5; /* XML_TOK_END_TAG */                                                                \
        default:                                                                                           \
            *next = ptr;                                                                                   \
            return SWB_TOK_INVALID;                                                                        \
        }                                                                                                  \
    }                                                                                                      \
    return SWB_TOK_PARTIAL;                                                                                \
}

/* Swing_DLL.xex 0x88896578 (big-endian UTF-16) */
EX5_DEFINE_SCAN_END_TAG(ex5_xml_scan_end_tag_big2_88896578, EX5_HI_BIG2, EX5_LO_BIG2)
/* Swing_DLL.xex 0x88898678 (little-endian UTF-16) */
EX5_DEFINE_SCAN_END_TAG(ex5_xml_scan_end_tag_little2_88898678, EX5_HI_LITTLE2, EX5_LO_LITTLE2)
