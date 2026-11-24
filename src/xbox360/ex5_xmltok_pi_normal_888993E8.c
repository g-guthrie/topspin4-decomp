/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX5: Expat xmltok_impl.c scanPi for the 8-bit "normal" encoding (after "<?"). One function per file
 * (fn_check resolves $LN labels by name and they repeat per function). */
#include "swb2_expat.h"

/* Expat normal_checkPiTarget, local copy of the out-of-line original at 0x88894580 so the compiler sees its
 * register usage (same trick as unicode_byte_type). */
#ifdef _MSC_VER
__declspec(noinline)
#else
__attribute__((unused))
#endif
static int ts4_xmltok_normal_check_pi_target_88894580(const char *ptr, int *tok_ptr)
{
    int upper = 0;
    switch ((unsigned char)*ptr) {
    case 'x':
        break;
    case 'X':
        upper = 1;
        break;
    default:
        return 1;
    }
    ptr += 1;
    switch ((unsigned char)*ptr) {
    case 'm':
        break;
    case 'M':
        upper = 1;
        break;
    default:
        return 1;
    }
    ptr += 1;
    switch ((unsigned char)*ptr) {
    case 'l':
        break;
    case 'L':
        upper = 1;
        break;
    default:
        return 1;
    }
    if (upper)
        return 0;
    *tok_ptr = 12;
    return 1;
}

#define EX5_CHECK_PI_TARGET(target, ptr, tokp) \
    (*(tokp) = 11 /* XML_TOK_PI */, ((ptr) - (target) == 3) ? ts4_xmltok_normal_check_pi_target_88894580(target, tokp) : 1)

/* Swing_DLL.xex 0x888993E8 */
int ex5_xml_scan_pi_normal_888993E8(const SwbEnc *enc, const char *ptr, const char *end, const char **next)
{
    int tok;
    const char *target = ptr;
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
            if (!EX5_CHECK_PI_TARGET(target, ptr, &tok)) {
                *next = ptr;
                return SWB_TOK_INVALID;
            }
            ptr += 1;
            while (ptr != end) {
                switch (SWB_BYTE_TYPE(enc, ptr)) {
                SWB_INVALID_CASES()
                case SWB_BT_QUEST:
                    ptr += 1;
                    if (ptr == end)
                        return SWB_TOK_PARTIAL;
                    if (*ptr == '>') {
                        *next = ptr + 1;
                        return tok;
                    }
                    break;
                default:
                    ptr += 1;
                    break;
                }
            }
            return SWB_TOK_PARTIAL;
        case SWB_BT_QUEST:
            if (!EX5_CHECK_PI_TARGET(target, ptr, &tok)) {
                *next = ptr;
                return SWB_TOK_INVALID;
            }
            ptr += 1;
            if (ptr == end)
                return SWB_TOK_PARTIAL;
            if (*ptr == '>') {
                *next = ptr + 1;
                return tok;
            }
            /* fall through */
        default:
            *next = ptr;
            return SWB_TOK_INVALID;
        }
    }
    return SWB_TOK_PARTIAL;
}
