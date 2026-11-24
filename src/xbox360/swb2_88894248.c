/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWB2 (jump-table switch): expat cdataSectionTok (normal encoding). One function per file (fn_check label names repeat). */
#include "swb2_expat.h"

int ts4_xml_cdata_section_tok_88894248(const SwbEnc *enc, const char *ptr, const char *end, const char **next)
{
    if (ptr == end)
        return -4;
    switch (SWB_BYTE_TYPE(enc, ptr)) {
    case SWB_BT_RSQB:
        ptr += 1;
        if (ptr == end)
            return SWB_TOK_PARTIAL;
        if (*ptr != ']')
            break;
        ptr += 1;
        if (ptr == end)
            return SWB_TOK_PARTIAL;
        if (*ptr != '>') {
            ptr -= 1;
            break;
        }
        *next = ptr + 1;
        return 40;
    case SWB_BT_CR:
        ptr += 1;
        if (ptr == end)
            return SWB_TOK_PARTIAL;
        if (SWB_BYTE_TYPE(enc, ptr) == SWB_BT_LF)
            ptr += 1;
        *next = ptr;
        return 7;
    case SWB_BT_LF:
        *next = ptr + 1;
        return 7;
    SWB_INVALID_CASES()
    default:
        ptr += 1;
        break;
    }
    while (ptr != end) {
        switch (SWB_BYTE_TYPE(enc, ptr)) {
        case SWB_BT_LEAD2:
            if (end - ptr < 2 || enc->isInvalid2(enc, ptr)) { *next = ptr; return 6; }
            ptr += 2;
            break;
        case SWB_BT_LEAD3:
            if (end - ptr < 3 || enc->isInvalid3(enc, ptr)) { *next = ptr; return 6; }
            ptr += 3;
            break;
        case SWB_BT_LEAD4:
            if (end - ptr < 4 || enc->isInvalid4(enc, ptr)) { *next = ptr; return 6; }
            ptr += 4;
            break;
        case SWB_BT_NONXML:
        case SWB_BT_MALFORM:
        case SWB_BT_TRAIL:
        case SWB_BT_CR:
        case SWB_BT_LF:
        case SWB_BT_RSQB:
            *next = ptr;
            return 6;
        default:
            ptr += 1;
            break;
        }
    }
    *next = ptr;
    return 6;
}
