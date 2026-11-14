/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX5: Expat xmltok_impl.c scanRef for the two 16-bit encodings (after "&"). */
#include "ex5_xmltok16.h"

/* scanCharRef (family EX5, ex5_xmltok_char_ref_16.c); the placeholder names are used for the callees. */
int ex5_xml_scan_char_ref_big2_8889A2A8(const SwbEnc *enc, const char *ptr, const char *end, const char **next);
int ex5_xml_scan_char_ref_little2_8889A5C8(const SwbEnc *enc, const char *ptr, const char *end, const char **next);

#define EX5_DEFINE_SCAN_REF(name, char_ref, HI, LO)                                                        \
int name(const SwbEnc *enc, const char *ptr, const char *end, const char **next)                          \
{                                                                                                          \
    if (ptr == end)                                                                                        \
        return SWB_TOK_PARTIAL;                                                                            \
    switch (EX5_UNIT_TYPE(enc, HI(ptr), LO(ptr))) {                                                        \
        EX5_CHECK_NMSTRT_CASES(HI, LO)                                                                     \
    case SWB_BT_NUM:                                                                                       \
        return char_ref(enc, ptr + 2, end, next);                                                          \
    default:                                                                                               \
        *next = ptr;                                                                                       \
        return SWB_TOK_INVALID;                                                                            \
    }                                                                                                      \
    while (ptr != end) {                                                                                   \
        switch (EX5_UNIT_TYPE(enc, HI(ptr), LO(ptr))) {                                                    \
            EX5_CHECK_NAME_CASES(HI, LO)                                                                   \
        case SWB_BT_SEMI:                                                                                  \
            *next = ptr + 2;                                                                               \
            return 9; /* XML_TOK_ENTITY_REF */                                                             \
        default:                                                                                           \
            *next = ptr;                                                                                   \
            return SWB_TOK_INVALID;                                                                        \
        }                                                                                                  \
    }                                                                                                      \
    return SWB_TOK_PARTIAL;                                                                                \
}

/* Swing_DLL.xex 0x8889BDB8 (big-endian UTF-16) */
EX5_DEFINE_SCAN_REF(ex5_xml_scan_ref_big2_8889BDB8, ex5_xml_scan_char_ref_big2_8889A2A8, EX5_HI_BIG2, EX5_LO_BIG2)
/* Swing_DLL.xex 0x8889C890 (little-endian UTF-16) */
EX5_DEFINE_SCAN_REF(ex5_xml_scan_ref_little2_8889C890, ex5_xml_scan_char_ref_little2_8889A5C8, EX5_HI_LITTLE2, EX5_LO_LITTLE2)
