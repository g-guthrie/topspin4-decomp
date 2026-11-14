/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWB2 (jump-table switch): expat entityValueTok for big-endian UTF-16. One function per file (fn_check label names repeat). */
#include "swb2_expat.h"

int ex5_xml_scan_ref_big2_8889BDB8(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);
int ex5_xml_scan_percent_big2_888961E0(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);

int ts4_xml_entity_value_tok_big2_8889D400(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next)
{
    const unsigned char *start;

    if (ptr == end)
        return -4;
    start = ptr;
    while (ptr != end) {
        int t;
        unsigned int raw = ptr[0];

        t = raw == 0 ? enc->type[ptr[1]] : swb_big2_uni_inline(raw, ptr);
        switch (t) {
        case SWB_BT_LEAD2:
            ptr += 2;
            break;
        case SWB_BT_LEAD3:
            ptr += 3;
            break;
        case SWB_BT_LEAD4:
            ptr += 4;
            break;
        case SWB_BT_AMP:
            if (ptr == start)
                return ex5_xml_scan_ref_big2_8889BDB8(enc, ptr + 2, end, next);
            *next = ptr;
            return 6;
        case 30:
            if (ptr == start) {
                int tok = ex5_xml_scan_percent_big2_888961E0(enc, ptr + 2, end, next);
                return (tok == 22) ? 0 : tok;
            }
            *next = ptr;
            return 6;
        case SWB_BT_LF:
            if (ptr == start) {
                *next = ptr + 2;
                return 7;
            }
            *next = ptr;
            return 6;
        case SWB_BT_CR:
            if (ptr == start) {
                ptr += 2;
                if (ptr == end)
                    return -3;
                if (SWB_BIG2_TYPE(enc, ptr) == SWB_BT_LF)
                    ptr += 2;
                *next = ptr;
                return 7;
            }
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
