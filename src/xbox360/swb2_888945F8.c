/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWB2 (jump-table switch): expat-style comment scanner (normal encoding). */
#include "swb2_expat.h"

int ts4_xml_scan_comment_888945F8(const SwbEnc *enc, const char *ptr, const char *end, const char **next)
{
    if (ptr != end) {
        if (*ptr != '-') {
            *next = ptr;
            return SWB_TOK_INVALID;
        }
        ptr += 1;
        while (ptr != end) {
            switch (SWB_BYTE_TYPE(enc, ptr)) {
            SWB_INVALID_CASES()
            case SWB_BT_MINUS:
                if ((ptr += 1) == end)
                    return SWB_TOK_PARTIAL;
                if (*ptr == '-') {
                    if ((ptr += 1) == end)
                        return SWB_TOK_PARTIAL;
                    if (*ptr != '>') {
                        *next = ptr;
                        return SWB_TOK_INVALID;
                    }
                    *next = ptr + 1;
                    return 13;
                }
                break;
            default:
                ptr += 1;
                break;
            }
        }
    }
    return SWB_TOK_PARTIAL;
}
