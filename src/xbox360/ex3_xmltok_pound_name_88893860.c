/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX3: switch jump-table function. One function per file: fn_check resolves $LN labels by name and they repeat per function. */
#include "r3_xmltok.h"

/* Single-byte encodings have no multi-byte name characters (Expat IS_NAME_CHAR_MINBPC is 0 there). */
#define EX3_IS_NMSTRT_CHAR_MINBPC(enc, p) (0)
#define EX3_IS_NAME_CHAR_MINBPC(enc, p) (0)

/* Scan a "#NAME" token after '#' in a content-model/attlist declaration (Expat normal_scanPoundName):
 * returns XML_TOK_POUND_NAME (20), its negative when input ends, XML_TOK_INVALID (0), or
 * XML_TOK_PARTIAL (-1) / XML_TOK_PARTIAL_CHAR (-2). Swing_DLL.xex 0x88893860 */
int ts4_xmltok_normal_scan_pound_name_88893860(const struct ts4_xml_normal_encoding *enc, const char *ptr,
                                               const char *end, const char **next_tok_ptr)
{
    if (ptr == end)
        return -1;
    switch (enc->type[(unsigned char)*ptr]) {
    case TS4_BT_NONASCII:
        if (!EX3_IS_NMSTRT_CHAR_MINBPC(enc, ptr)) {
            *next_tok_ptr = ptr;
            return 0;
        }
        /* fall through */
    case TS4_BT_NMSTRT:
    case TS4_BT_HEX:
        ptr += 1;
        break;
    case TS4_BT_LEAD2:
        if (end - ptr < 2)
            return -2;
        if (!enc->is_nmstrt2(&enc->enc, ptr)) {
            *next_tok_ptr = ptr;
            return 0;
        }
        ptr += 2;
        break;
    case TS4_BT_LEAD3:
        if (end - ptr < 3)
            return -2;
        if (!enc->is_nmstrt3(&enc->enc, ptr)) {
            *next_tok_ptr = ptr;
            return 0;
        }
        ptr += 3;
        break;
    case TS4_BT_LEAD4:
        if (end - ptr < 4)
            return -2;
        if (!enc->is_nmstrt4(&enc->enc, ptr)) {
            *next_tok_ptr = ptr;
            return 0;
        }
        ptr += 4;
        break;
    default:
        *next_tok_ptr = ptr;
        return 0;
    }
    while (ptr != end) {
        switch (enc->type[(unsigned char)*ptr]) {
        case TS4_BT_NONASCII:
            if (!EX3_IS_NAME_CHAR_MINBPC(enc, ptr)) {
                *next_tok_ptr = ptr;
                return 0;
            }
            /* fall through */
        case TS4_BT_NMSTRT:
        case TS4_BT_HEX:
        case TS4_BT_DIGIT:
        case TS4_BT_NAME:
        case TS4_BT_MINUS:
            ptr += 1;
            break;
        case TS4_BT_LEAD2:
            if (end - ptr < 2)
                return -2;
            if (!enc->is_name2(&enc->enc, ptr)) {
                *next_tok_ptr = ptr;
                return 0;
            }
            ptr += 2;
            break;
        case TS4_BT_LEAD3:
            if (end - ptr < 3)
                return -2;
            if (!enc->is_name3(&enc->enc, ptr)) {
                *next_tok_ptr = ptr;
                return 0;
            }
            ptr += 3;
            break;
        case TS4_BT_LEAD4:
            if (end - ptr < 4)
                return -2;
            if (!enc->is_name4(&enc->enc, ptr)) {
                *next_tok_ptr = ptr;
                return 0;
            }
            ptr += 4;
            break;
        case TS4_BT_CR:
        case TS4_BT_LF:
        case TS4_BT_GT:
        case TS4_BT_S:
        case TS4_BT_PERCNT:
        case TS4_BT_RPAR:
        case TS4_BT_VERBAR:
            *next_tok_ptr = ptr;
            return 20;
        default:
            *next_tok_ptr = ptr;
            return 0;
        }
    }
    return -20;
}
