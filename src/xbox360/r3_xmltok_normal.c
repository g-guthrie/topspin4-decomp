/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "r3_xmltok.h"

/* Latin-1 ENCODING table used by Expat's checkCharRefNumber (normal_encoding layout with type[256]). */
extern const struct ts4_xml_normal_encoding lbl_880CF7F8;

/* Expat checkCharRefNumber: reject surrogates, non-XML Latin-1 controls and U+FFFE/U+FFFF. */
static int ts4_check_char_ref_number(int result)
{
    switch (result >> 8) {
    case 0xD8: case 0xD9: case 0xDA: case 0xDB: case 0xDC: case 0xDD: case 0xDE: case 0xDF:
        return -1;
    case 0:
        if (lbl_880CF7F8.type[result] == TS4_BT_NONXML)
            return -1;
        break;
    case 0xFF:
        if (result == 0xFFFE || result == 0xFFFF)
            return -1;
        break;
    }
    return result;
}

/* Numeric character reference value ("&#...;" or "&#x...;") for 1-byte-per-char encodings
 * (Expat normal_charRefNumber). Swing_DLL.xex 0x88892F88 */
int ts4_xmltok_normal_char_ref_number_88892F88(const struct ts4_xml_encoding *enc, const char *ptr)
{
    int result = 0;
    (void)enc;
    ptr += 2;
    if (*ptr == 'x') {
        for (ptr += 1; !(*ptr == ';'); ptr += 1) {
            int c = *ptr;
            switch (c) {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                result <<= 4;
                result |= (c - '0');
                break;
            case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
                result <<= 4;
                result += 10 + (c - 'A');
                break;
            case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
                result <<= 4;
                result += 10 + (c - 'a');
                break;
            }
            if (result >= 0x110000)
                return -1;
        }
    } else {
        for (; !(*ptr == ';'); ptr += 1) {
            int c = *ptr;
            result *= 10;
            result += (c - '0');
            if (result >= 0x110000)
                return -1;
        }
    }
    return ts4_check_char_ref_number(result);
}

#define TS4_XML_TOK_PARTIAL (-1)
#define TS4_XML_TOK_PARTIAL_CHAR (-2)
#define TS4_XML_TOK_INVALID 0
#define TS4_XML_TOK_IGNORE_SECT 42

/* Scan a conditional section being ignored: track nested "<![" / "]]>" (Expat normal_ignoreSectionTok).
 * Swing_DLL.xex 0x888934B0 */
int ts4_xmltok_normal_ignore_section_tok_888934B0(const struct ts4_xml_encoding *enc, const char *ptr,
                                                  const char *end, const char **next_tok_ptr)
{
    int level = 0;
    while (ptr != end) {
        switch (((const struct ts4_xml_normal_encoding *)enc)->type[(unsigned char)*ptr]) {
        case TS4_BT_LEAD2:
            if (end - ptr < 2)
                return TS4_XML_TOK_PARTIAL_CHAR;
            if (((const struct ts4_xml_normal_encoding *)enc)->is_invalid2(enc, ptr)) {
                *next_tok_ptr = ptr;
                return TS4_XML_TOK_INVALID;
            }
            ptr += 2;
            break;
        case TS4_BT_LEAD3:
            if (end - ptr < 3)
                return TS4_XML_TOK_PARTIAL_CHAR;
            if (((const struct ts4_xml_normal_encoding *)enc)->is_invalid3(enc, ptr)) {
                *next_tok_ptr = ptr;
                return TS4_XML_TOK_INVALID;
            }
            ptr += 3;
            break;
        case TS4_BT_LEAD4:
            if (end - ptr < 4)
                return TS4_XML_TOK_PARTIAL_CHAR;
            if (((const struct ts4_xml_normal_encoding *)enc)->is_invalid4(enc, ptr)) {
                *next_tok_ptr = ptr;
                return TS4_XML_TOK_INVALID;
            }
            ptr += 4;
            break;
        case TS4_BT_NONXML:
        case TS4_BT_MALFORM:
        case TS4_BT_TRAIL:
            *next_tok_ptr = ptr;
            return TS4_XML_TOK_INVALID;
        case TS4_BT_LT:
            if ((ptr += 1) == end)
                return TS4_XML_TOK_PARTIAL;
            if (*ptr == '!') {
                if ((ptr += 1) == end)
                    return TS4_XML_TOK_PARTIAL;
                if (*ptr == '[') {
                    ++level;
                    ptr += 1;
                }
            }
            break;
        case TS4_BT_RSQB:
            if ((ptr += 1) == end)
                return TS4_XML_TOK_PARTIAL;
            if (*ptr == ']') {
                if ((ptr += 1) == end)
                    return TS4_XML_TOK_PARTIAL;
                if (*ptr == '>') {
                    ptr += 1;
                    if (level == 0) {
                        *next_tok_ptr = ptr;
                        return TS4_XML_TOK_IGNORE_SECT;
                    }
                    --level;
                }
            }
            break;
        default:
            ptr += 1;
            break;
        }
    }
    return TS4_XML_TOK_PARTIAL;
}

/* Expat INIT_ENCODING: the initial auto-detecting encoding plus a pointer to the live encoding slot. */
struct ts4_xml_init_encoding {
    struct ts4_xml_encoding init_enc;       /* +0x00 */
    const struct ts4_xml_encoding **enc_ptr; /* +0x4C */
};

/* Encoding table indices (Expat). */
#define TS4_ISO_8859_1_ENC 0
#define TS4_UTF_8_ENC 2
#define TS4_UTF_16_ENC 3
#define TS4_UTF_16BE_ENC 4
#define TS4_UTF_16LE_ENC 5

#define TS4_XML_CONTENT_STATE 1
#define TS4_XML_TOK_NONE (-4)
#define TS4_XML_TOK_BOM 14

#define TS4_INIT_ENC_INDEX(enc) ((int)(signed char)(enc)->init_enc.is_utf16)
#define TS4_XML_TOK(enc, state, ptr, end, next) ((enc)->scanners[state]((enc), (ptr), (end), (next)))

