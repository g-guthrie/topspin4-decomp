/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWB2 (jump-table switch): expat-style literal scanner (little-endian UTF-16). */
#include "swb2_expat.h"

int ts4_xml_scan_lit_16_88897E48(int open, const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next)
{
    while (ptr != end) {
        int t;
        unsigned int raw = ptr[1];

        t = raw == 0 ? enc->type[ptr[0]] : swb_little2_uni_inline(raw, ptr);
        switch (t) {
        case SWB_BT_LEAD2:
            if (end - ptr < 2) return -2;
            ptr += 2;
            break;
        case SWB_BT_LEAD3:
            if (end - ptr < 3) return -2;
            ptr += 3;
            break;
        case SWB_BT_LEAD4:
            if (end - ptr < 4) return -2;
            ptr += 4;
            break;
        case SWB_BT_NONXML:
        case SWB_BT_MALFORM:
        case SWB_BT_TRAIL:
            *next = ptr;
            return SWB_TOK_INVALID;
        case SWB_BT_QUOT:
        case SWB_BT_APOS:
            ptr += 2;
            if (t != open)
                break;
            if (ptr == end)
                return -27;
            *next = ptr;
            {
                int t2 = (unsigned char)ptr[1] == 0 ? enc->type[(unsigned char)ptr[0]]
                                                    : ts4_xmltok_unicode_byte_type_888927A0(ptr[1], ptr[0]);
                switch (t2) {
                case SWB_BT_CR: case SWB_BT_LF: case SWB_BT_GT:
                case SWB_BT_LSQB: case SWB_BT_S: case 30:
                    return 27;
                default:
                    return SWB_TOK_INVALID;
                }
            }
        default:
            ptr += 2;
            break;
        }
    }
    return SWB_TOK_PARTIAL;
}
