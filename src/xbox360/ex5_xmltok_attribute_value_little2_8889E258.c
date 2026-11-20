/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX5: Expat xmltok_impl.c attributeValueTok for little-endian UTF-16, twin of swb2_8889D650.c.
 * One function per file (fn_check resolves $LN labels by name and they repeat per function). */
#include "swb2_expat.h"

/* scanRef little-endian (family EX5): placeholder name. */
int ex5_xml_scan_ref_little2_8889C890(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);

/* Swing_DLL.xex 0x8889E258 */
int ex5_xml_attribute_value_tok_little2_8889E258(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next)
{
    const unsigned char *start;

    if (ptr == end)
        return -4;
    start = ptr;
    while (ptr != end) {
        int t;
        unsigned int raw = ptr[1];

        t = raw == 0 ? enc->type[ptr[0]] : swb_little2_uni_inline(raw, ptr);
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
                return ex5_xml_scan_ref_little2_8889C890(enc, ptr + 2, end, next);
            *next = ptr;
            return 6;
        case SWB_BT_LT:
            *next = ptr;
            return 0;
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
                if (SWB_LITTLE2_TYPE(enc, ptr) == SWB_BT_LF)
                    ptr += 2;
                *next = ptr;
                return 7;
            }
            *next = ptr;
            return 6;
        case SWB_BT_S:
            if (ptr == start) {
                *next = ptr + 2;
                return 39;
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
