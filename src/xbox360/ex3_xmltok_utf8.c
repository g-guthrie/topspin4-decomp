/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX3: Expat xmltok.c 8-bit/UTF-8 helpers (invalid-sequence checks, encoding names, scanners). */
#include "r3_xmltok.h"

extern const unsigned char lbl_880CF0C0[];  /* "CDATA[" */
extern const char *const lbl_88C6AD94[6];   /* encodingNames: ISO-8859-1, US-ASCII, UTF-8, UTF-16, UTF-16BE, UTF-16LE */

int ts4_if_addr_lbl_880CF7F8_88891878(int c); /* Expat checkCharRefNumber over the latin1 table */

struct ex3_unknown_encoding {
    struct ts4_xml_normal_encoding normal;           /* +0x000 */
    int (*convert)(void *user_data, const char *p);  /* +0x170 */
    void *user_data;                                 /* +0x174 */
};

/* Scan the digits of a hexadecimal character reference (Expat normal_scanHexCharRef): returns
 * XML_TOK_CHAR_REF (10), XML_TOK_INVALID (0) or XML_TOK_PARTIAL (-1). Swing_DLL.xex 0x88893E38 */
int ts4_xmltok_normal_scan_hex_char_ref_88893E38(const struct ts4_xml_normal_encoding *enc, const char *ptr,
                                                 const char *end, const char **next_tok_ptr)
{
    if (ptr != end) {
        switch (enc->type[(unsigned char)*ptr]) {
        case TS4_BT_DIGIT:
        case TS4_BT_HEX:
            break;
        default:
            *next_tok_ptr = ptr;
            return 0;
        }
        for (ptr += 1; ptr != end; ptr += 1) {
            switch (enc->type[(unsigned char)*ptr]) {
            case TS4_BT_DIGIT:
            case TS4_BT_HEX:
                break;
            case TS4_BT_SEMI:
                *next_tok_ptr = ptr + 1;
                return 10;
            default:
                *next_tok_ptr = ptr;
                return 0;
            }
        }
    }
    return -1;
}

/* Match the six characters "CDATA[" in 8-bit input (Expat normal_scanLt, CDATA section opener);
 * returns XML_TOK_CDATA_SECT_OPEN (8) or XML_TOK_INVALID (0). Swing_DLL.xex 0x88894538 */
int ts4_xmltok_normal_match_cdata_open_88894538(const char *ptr, const char **next_tok_ptr)
{
    int i;
    for (i = 0; i < 6; i++, ptr += 1) {
        if ((unsigned char)*ptr != lbl_880CF0C0[i]) {
            *next_tok_ptr = ptr;
            return 0;
        }
    }
    *next_tok_ptr = ptr;
    return 8;
}

/* Classify a processing-instruction target (Expat normal_checkPiTarget); "xml" in lower case flags an
 * XML declaration (12), other cases with an upper-case letter return 0. Swing_DLL.xex 0x88894580 */
int ts4_xmltok_normal_check_pi_target_88894580(const char *ptr, int *tok_ptr)
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

#define EX3_UTF8_INVALID2(p) (((p)[0]) < 0xC2 || ((p)[1] & 0x80) == 0 || ((p)[1] & 0xC0) == 0xC0)

#define EX3_UTF8_INVALID3(p)                                                                                   \
    (((p)[2] & 0x80) == 0 ||                                                                                   \
     ((p)[0] == 0xEF && (p)[1] == 0xBF ? (p)[2] > 0xBD : ((p)[2] & 0xC0) == 0xC0) ||                          \
     ((p)[0] == 0xE0 ? ((p)[1] < 0xA0 || ((p)[1] & 0xC0) == 0xC0)                                              \
                     : ((p)[1] & 0x80) == 0 || ((p)[0] == 0xED ? (p)[1] > 0x9F : ((p)[1] & 0xC0) == 0xC0)))

#define EX3_UTF8_INVALID4(p)                                                                                   \
    (((p)[3] & 0x80) == 0 || ((p)[3] & 0xC0) == 0xC0 || ((p)[2] & 0x80) == 0 || ((p)[2] & 0xC0) == 0xC0 ||     \
     ((p)[0] == 0xF0 ? ((p)[1] < 0x90 || ((p)[1] & 0xC0) == 0xC0)                                              \
                     : ((p)[1] & 0x80) == 0 || ((p)[0] == 0xF4 ? (p)[1] > 0x8F : ((p)[1] & 0xC0) == 0xC0)))

/* Reject malformed 4-byte UTF-8 sequences (Expat utf8_isInvalid4). Swing_DLL.xex 0x88894800 */
int ts4_xmltok_utf8_is_invalid4_88894800(const struct ts4_xml_encoding *enc, const char *p)
{
    (void)enc;
    return EX3_UTF8_INVALID4((const unsigned char *)p);
}

/* Reject malformed 3-byte UTF-8 sequences (Expat utf8_isInvalid3). Swing_DLL.xex 0x888948A8 */
int ts4_xmltok_utf8_is_invalid3_888948A8(const struct ts4_xml_encoding *enc, const char *p)
{
    (void)enc;
    return EX3_UTF8_INVALID3((const unsigned char *)p);
}

/* Reject malformed 2-byte UTF-8 sequences (Expat utf8_isInvalid2). Swing_DLL.xex 0x88894968 */
int ts4_xmltok_utf8_is_invalid2_88894968(const struct ts4_xml_encoding *enc, const char *p)
{
    (void)enc;
    return EX3_UTF8_INVALID2((const unsigned char *)p);
}

/* Case-insensitive ASCII string equality (Expat streqci), inlined into its callers. */
static int ex3_streqci(const char *s1, const char *s2)
{
    for (;;) {
        char c1 = *s1++;
        char c2 = *s2++;
        if ('a' <= c1 && c1 <= 'z')
            c1 += 'A' - 'a';
        if ('a' <= c2 && c2 <= 'z')
            c2 += 'A' - 'a';
        if (c1 != c2)
            return 0;
        if (!c1)
            break;
    }
    return 1;
}

/* Look up an encoding name in the built-in table; 6 for a NULL name, -1 for an unknown one
 * (Expat getEncodingIndex). Swing_DLL.xex 0x88894BA8 */
int ts4_xmltok_get_encoding_index_88894BA8(const char *name)
{
    int i;
    if (name == 0)
        return 6;
    for (i = 0; i < (int)(sizeof(lbl_88C6AD94) / sizeof(lbl_88C6AD94[0])); i++)
        if (ex3_streqci(name, lbl_88C6AD94[i]))
            return i;
    return -1;
}

/* Test whether an application-converted character is invalid XML (Expat unknown_isInvalid).
 * Swing_DLL.xex 0x88894E10; also referenced by family LG1 as fn_88894E10. */
int fn_88894E10(const struct ts4_xml_encoding *enc, const char *p)
{
    int c = ((const struct ex3_unknown_encoding *)enc)->convert(((const struct ex3_unknown_encoding *)enc)->user_data, p);
    return (c & ~0xFFFF) || ts4_if_addr_lbl_880CF7F8_88891878(c) < 0;
}
