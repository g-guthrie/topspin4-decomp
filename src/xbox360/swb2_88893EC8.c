/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWB2 (jump-table switch): expat scanEndTag (normal encoding). One function per file (fn_check label names repeat). */
#include "swb2_expat.h"

int ts4_xml_scan_end_tag_88893EC8(const SwbEnc *enc, const char *ptr, const char *end, const char **next)
{
    if (ptr == end)
        return SWB_TOK_PARTIAL;
    switch (SWB_BYTE_TYPE(enc, ptr)) {
    case SWB_BT_NONASCII:
        *next = ptr;
        return SWB_TOK_INVALID;
    case SWB_BT_NMSTRT:
    case SWB_BT_HEX:
        ptr += 1;
        break;
    case SWB_BT_LEAD2:
        if (end - ptr < 2) return SWB_TOK_PARTIAL_CHAR;
        if (!enc->isNmstrt2(enc, ptr)) { *next = ptr; return SWB_TOK_INVALID; }
        ptr += 2;
        break;
    case SWB_BT_LEAD3:
        if (end - ptr < 3) return SWB_TOK_PARTIAL_CHAR;
        if (!enc->isNmstrt3(enc, ptr)) { *next = ptr; return SWB_TOK_INVALID; }
        ptr += 3;
        break;
    case SWB_BT_LEAD4:
        if (end - ptr < 4) return SWB_TOK_PARTIAL_CHAR;
        if (!enc->isNmstrt4(enc, ptr)) { *next = ptr; return SWB_TOK_INVALID; }
        ptr += 4;
        break;
    default:
        *next = ptr;
        return SWB_TOK_INVALID;
    }
    while (ptr != end) {
        switch (SWB_BYTE_TYPE(enc, ptr)) {
        case SWB_BT_NONASCII:
            *next = ptr;
            return SWB_TOK_INVALID;
        case SWB_BT_NMSTRT:
        case SWB_BT_HEX:
        case SWB_BT_DIGIT:
        case SWB_BT_NAME:
        case SWB_BT_MINUS:
            ptr += 1;
            break;
        case SWB_BT_LEAD2:
            if (end - ptr < 2) return SWB_TOK_PARTIAL_CHAR;
            if (!enc->isName2(enc, ptr)) { *next = ptr; return SWB_TOK_INVALID; }
            ptr += 2;
            break;
        case SWB_BT_LEAD3:
            if (end - ptr < 3) return SWB_TOK_PARTIAL_CHAR;
            if (!enc->isName3(enc, ptr)) { *next = ptr; return SWB_TOK_INVALID; }
            ptr += 3;
            break;
        case SWB_BT_LEAD4:
            if (end - ptr < 4) return SWB_TOK_PARTIAL_CHAR;
            if (!enc->isName4(enc, ptr)) { *next = ptr; return SWB_TOK_INVALID; }
            ptr += 4;
            break;
        case SWB_BT_S:
        case SWB_BT_CR:
        case SWB_BT_LF:
            for (ptr += 1; ptr != end; ptr += 1) {
                switch (SWB_BYTE_TYPE(enc, ptr)) {
                case SWB_BT_S: case SWB_BT_CR: case SWB_BT_LF:
                    break;
                case SWB_BT_GT:
                    *next = ptr + 1;
                    return 5;
                default:
                    *next = ptr;
                    return SWB_TOK_INVALID;
                }
            }
            return SWB_TOK_PARTIAL;
        case SWB_BT_COLON:
            ptr += 1;
            break;
        case SWB_BT_GT:
            *next = ptr + 1;
            return 5;
        default:
            *next = ptr;
            return SWB_TOK_INVALID;
        }
    }
    return SWB_TOK_PARTIAL;
}
