/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX5: Expat xmltok_impl.c scanCharRef for the two 16-bit encodings (after "&#"). */
#include "swb2_expat.h"

/* scanHexCharRef (family EX5, ex5_xmltok_hex_char_ref_16.c); the placeholder names are used for the callees. */
int ex5_xml_scan_hex_char_ref_big2_88896488(const SwbEnc *enc, const char *ptr, const char *end, const char **next);
int ex5_xml_scan_hex_char_ref_little2_88898588(const SwbEnc *enc, const char *ptr, const char *end, const char **next);

#define EX5_DEFINE_SCAN_CHAR_REF(name, hex_ref, HI, LO)                                                    \
int name(const SwbEnc *enc, const char *ptr, const char *end, const char **next)                          \
{                                                                                                          \
    if (ptr != end) {                                                                                      \
        if (HI(ptr) == 0 && LO(ptr) == 'x')                                                                \
            return hex_ref(enc, ptr + 2, end, next);                                                       \
        switch (((HI(ptr)) == 0 ? enc->type[(unsigned char)(LO(ptr))]                                      \
                                : ts4_xmltok_unicode_byte_type_888927A0(HI(ptr), LO(ptr)))) {              \
        case SWB_BT_DIGIT:                                                                                 \
            break;                                                                                         \
        default:                                                                                           \
            *next = ptr;                                                                                   \
            return SWB_TOK_INVALID;                                                                        \
        }                                                                                                  \
        for (ptr += 2; ptr != end; ptr += 2) {                                                             \
            switch (((HI(ptr)) == 0 ? enc->type[(unsigned char)(LO(ptr))]                                  \
                                    : ts4_xmltok_unicode_byte_type_888927A0(HI(ptr), LO(ptr)))) {          \
            case SWB_BT_DIGIT:                                                                             \
                break;                                                                                     \
            case SWB_BT_SEMI:                                                                              \
                *next = ptr + 2;                                                                           \
                return 10; /* XML_TOK_CHAR_REF */                                                          \
            default:                                                                                       \
                *next = ptr;                                                                               \
                return SWB_TOK_INVALID;                                                                    \
            }                                                                                              \
        }                                                                                                  \
    }                                                                                                      \
    return SWB_TOK_PARTIAL;                                                                                \
}

#define EX5_HI_BIG2(p) ((p)[0])
#define EX5_LO_BIG2(p) ((p)[1])
#define EX5_HI_LITTLE2(p) ((p)[1])
#define EX5_LO_LITTLE2(p) ((p)[0])

/* Swing_DLL.xex 0x8889A2A8 (big-endian UTF-16) */
EX5_DEFINE_SCAN_CHAR_REF(ex5_xml_scan_char_ref_big2_8889A2A8, ex5_xml_scan_hex_char_ref_big2_88896488, EX5_HI_BIG2, EX5_LO_BIG2)
/* Swing_DLL.xex 0x8889A5C8 (little-endian UTF-16) */
EX5_DEFINE_SCAN_CHAR_REF(ex5_xml_scan_char_ref_little2_8889A5C8, ex5_xml_scan_hex_char_ref_little2_88898588, EX5_HI_LITTLE2, EX5_LO_LITTLE2)
