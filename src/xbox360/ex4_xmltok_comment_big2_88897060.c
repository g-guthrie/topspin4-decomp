/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX4: expat-style comment scanner (big-endian UTF-16), twin of swb2_88899140.c. */
#include "swb2_expat.h"

#define EX4_BIG2_MATCHES(p, c) ((p)[0] == 0 && (p)[1] == (c))

/* Expat PREFIX(scanComment) for big-endian UTF-16. Swing_DLL.xex 0x88897060 */
int ex4_xml_scan_comment_big2_88897060(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next)
{
    if (ptr != end) {
        if (!EX4_BIG2_MATCHES(ptr, '-')) {
            *next = ptr;
            return SWB_TOK_INVALID;
        }
        ptr += 2;
        while (ptr != end) {
            switch (SWB_BIG2_TYPE(enc, ptr)) {
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
            case SWB_BT_MINUS:
                if ((ptr += 2) == end)
                    return SWB_TOK_PARTIAL;
                if (EX4_BIG2_MATCHES(ptr, '-')) {
                    if ((ptr += 2) == end)
                        return SWB_TOK_PARTIAL;
                    if (!EX4_BIG2_MATCHES(ptr, '>')) {
                        *next = ptr;
                        return SWB_TOK_INVALID;
                    }
                    *next = ptr + 2;
                    return 13;
                }
                break;
            default:
                ptr += 2;
                break;
            }
        }
    }
    return SWB_TOK_PARTIAL;
}
