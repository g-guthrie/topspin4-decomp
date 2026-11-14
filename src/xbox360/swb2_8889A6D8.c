/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWB2 (jump-table switch): expat scanDecl for little-endian UTF-16. One function per file (fn_check label names repeat). */
#include "swb2_expat.h"

int ts4_xml_scan_comment_16_88899140(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);

int ts4_xml_scan_decl_16_8889A6D8(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next)
{
    if (ptr == end)
        return SWB_TOK_PARTIAL;
    switch (SWB_LITTLE2_TYPE(enc, ptr)) {
    case SWB_BT_MINUS:
        return ts4_xml_scan_comment_16_88899140(enc, ptr + 2, end, next);
    case SWB_BT_LSQB:
        *next = ptr + 2;
        return 33;
    case SWB_BT_NMSTRT:
    case SWB_BT_HEX:
        ptr += 2;
        break;
    default:
        *next = ptr;
        return SWB_TOK_INVALID;
    }
    while (ptr != end) {
        switch (SWB_LITTLE2_TYPE(enc, ptr)) {
        case 30:
            if (ptr + 2 == end)
                return SWB_TOK_PARTIAL;
            switch (SWB_LITTLE2_TYPE(enc, ptr + 2)) {
            case SWB_BT_S: case SWB_BT_CR: case SWB_BT_LF: case 30:
                *next = ptr;
                return SWB_TOK_INVALID;
            }
            /* fallthrough */
        case SWB_BT_S: case SWB_BT_CR: case SWB_BT_LF:
            *next = ptr;
            return 16;
        case SWB_BT_NMSTRT: case SWB_BT_HEX:
            ptr += 2;
            break;
        default:
            *next = ptr;
            return SWB_TOK_INVALID;
        }
    }
    return SWB_TOK_PARTIAL;
}
