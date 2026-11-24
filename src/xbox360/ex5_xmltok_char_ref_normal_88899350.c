/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX5: Expat xmltok_impl.c scanCharRef for the 8-bit "normal" encoding (after "&#"). */
#include "swb2_expat.h"

int ts4_xmltok_normal_scan_hex_char_ref_88893E38(const SwbEnc *enc, const char *ptr, const char *end, const char **next);

/* Swing_DLL.xex 0x88899350 */
int ex5_xml_scan_char_ref_normal_88899350(const SwbEnc *enc, const char *ptr, const char *end, const char **next)
{
    if (ptr != end) {
        if (*ptr == 'x')
            return ts4_xmltok_normal_scan_hex_char_ref_88893E38(enc, ptr + 1, end, next);
        switch (SWB_BYTE_TYPE(enc, ptr)) {
        case SWB_BT_DIGIT:
            break;
        default:
            *next = ptr;
            return SWB_TOK_INVALID;
        }
        for (ptr += 1; ptr != end; ptr += 1) {
            switch (SWB_BYTE_TYPE(enc, ptr)) {
            case SWB_BT_DIGIT:
                break;
            case SWB_BT_SEMI:
                *next = ptr + 1;
                return 10; /* XML_TOK_CHAR_REF */
            default:
                *next = ptr;
                return SWB_TOK_INVALID;
            }
        }
    }
    return SWB_TOK_PARTIAL;
}
