/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWB2 (jump-table switch): expat cdataSectionTok (little-endian UTF-16). One function per file (fn_check label names repeat). */
#include "swb2_expat.h"

int ts4_xml_cdata_section_tok_16_888989A0(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next)
{
    if (ptr == end)
        return -4;
    {
        unsigned int n = (unsigned int)(end - ptr);
        if (n & 1) {
            n &= ~1u;
            if (n == 0)
                return SWB_TOK_PARTIAL;
            end = ptr + n;
        }
    }
    switch (SWB_LITTLE2_TYPE(enc, ptr)) {
    case SWB_BT_RSQB:
        ptr += 2;
        if (ptr == end)
            return SWB_TOK_PARTIAL;
        if (!SWB_LITTLE2_MATCHES(ptr, ']'))
            break;
        ptr += 2;
        if (ptr == end)
            return SWB_TOK_PARTIAL;
        if (!SWB_LITTLE2_MATCHES(ptr, '>')) {
            ptr -= 2;
            break;
        }
        *next = ptr + 2;
        return 40;
    case SWB_BT_CR:
        ptr += 2;
        if (ptr == end)
            return SWB_TOK_PARTIAL;
        if (SWB_LITTLE2_TYPE(enc, ptr) == SWB_BT_LF)
            ptr += 2;
        *next = ptr;
        return 7;
    case SWB_BT_LF:
        *next = ptr + 2;
        return 7;
    case SWB_BT_LEAD2:
        if (end - ptr < 2) return SWB_TOK_PARTIAL_CHAR;
        ptr += 2;
        break;
    case SWB_BT_LEAD3:
        if (end - ptr < 3) return SWB_TOK_PARTIAL_CHAR;
        ptr += 3;
        break;
    case SWB_BT_LEAD4:
        if (end - ptr < 4) return SWB_TOK_PARTIAL_CHAR;
        ptr += 4;
        break;
    case SWB_BT_NONXML:
    case SWB_BT_MALFORM:
    case SWB_BT_TRAIL:
        *next = ptr;
        return SWB_TOK_INVALID;
    default:
        ptr += 2;
        break;
    }
    while (ptr != end) {
        int t;
        unsigned int raw = ptr[1];

        if (raw == 0) {
            t = enc->type[ptr[0]];
        } else {
            switch ((int)(raw & 0xff)) {
            case 0xd8: case 0xd9: case 0xda: case 0xdb:
                t = SWB_BT_LEAD4;
                break;
            case 0xdc: case 0xdd: case 0xde: case 0xdf:
                t = SWB_BT_TRAIL;
                break;
            case 0xff:
                { int lo = ptr[0]; if (lo >= 0xfe && lo <= 0xff) { t = SWB_BT_NONXML; break; } }
                /* fallthrough */
            default:
                t = SWB_BT_NONASCII;
                break;
            }
        }
        switch (t) {
        case SWB_BT_LEAD2:
            if (end - ptr < 2) { *next = ptr; return 6; }
            ptr += 2;
            break;
        case SWB_BT_LEAD3:
            if (end - ptr < 3) { *next = ptr; return 6; }
            ptr += 3;
            break;
        case SWB_BT_LEAD4:
            if (end - ptr < 4) { *next = ptr; return 6; }
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
            ptr += 2;
            break;
        }
    }
    *next = ptr;
    return 6;
}
