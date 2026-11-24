/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX3: small Expat xmltok helpers (UTF-16 CDATA/PI checks, name comparison, toAscii, streqci). */
#include "r3_xmltok.h"

extern const unsigned char lbl_880CFF30[]; /* "CDATA[" (big-endian UTF-16 low bytes) */
extern const unsigned char lbl_880CFC48[]; /* "CDATA[" (little-endian UTF-16 low bytes) */

/* Match the six characters "CDATA[" after "<![" in big-endian UTF-16 input (Expat scanCdataSection part of
 * big2_scanLt); returns XML_TOK_CDATA_SECT_OPEN (8) or XML_TOK_INVALID (0). Swing_DLL.xex 0x88891D50 */
int ts4_xmltok_big2_match_cdata_open_88891D50(const char *ptr, const char **next_tok_ptr)
{
    int i;
    for (i = 0; i < 6; i++, ptr += 2) {
        if (!(ptr[0] == 0 && (unsigned char)ptr[1] == lbl_880CFF30[i])) {
            *next_tok_ptr = ptr;
            return 0;
        }
    }
    *next_tok_ptr = ptr;
    return 8;
}

/* Same as above for little-endian UTF-16 input. Swing_DLL.xex 0x888921C0 */
int ts4_xmltok_little2_match_cdata_open_888921C0(const char *ptr, const char **next_tok_ptr)
{
    int i;
    for (i = 0; i < 6; i++, ptr += 2) {
        if (!(ptr[1] == 0 && (unsigned char)ptr[0] == lbl_880CFC48[i])) {
            *next_tok_ptr = ptr;
            return 0;
        }
    }
    *next_tok_ptr = ptr;
    return 8;
}

#define EX3_BIG2_TO_ASCII(p) ((p)[0] == 0 ? (p)[1] : -1)
#define EX3_LITTLE2_TO_ASCII(p) ((p)[1] == 0 ? (p)[0] : -1)

/* Classify a processing-instruction target: "xml" in lower case flags an XML declaration (12); any
 * upper-case letter in it is reserved and returns 0 (Expat checkPiTarget, big-endian UTF-16).
 * Swing_DLL.xex 0x88891DA0 */
int ts4_xmltok_big2_check_pi_target_88891DA0(const char *ptr, int *tok_ptr)
{
    int upper = 0;
    switch (EX3_BIG2_TO_ASCII(ptr)) {
    case 'x':
        break;
    case 'X':
        upper = 1;
        break;
    default:
        return 1;
    }
    ptr += 2;
    switch (EX3_BIG2_TO_ASCII(ptr)) {
    case 'm':
        break;
    case 'M':
        upper = 1;
        break;
    default:
        return 1;
    }
    ptr += 2;
    switch (EX3_BIG2_TO_ASCII(ptr)) {
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

/* Same check for little-endian UTF-16 input. Swing_DLL.xex 0x88892210 */
int ts4_xmltok_little2_check_pi_target_88892210(const char *ptr, int *tok_ptr)
{
    int upper = 0;
    switch (EX3_LITTLE2_TO_ASCII(ptr)) {
    case 'x':
        break;
    case 'X':
        upper = 1;
        break;
    default:
        return 1;
    }
    ptr += 2;
    switch (EX3_LITTLE2_TO_ASCII(ptr)) {
    case 'm':
        break;
    case 'M':
        upper = 1;
        break;
    default:
        return 1;
    }
    ptr += 2;
    switch (EX3_LITTLE2_TO_ASCII(ptr)) {
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

/* Compare a little-endian UTF-16 name range with a NUL-terminated ASCII string (Expat little2_nameMatchesAscii).
 * Swing_DLL.xex 0x88891E48 */
int ts4_xmltok_little2_name_matches_ascii_88891E48(const struct ts4_xml_encoding *enc, const char *ptr1,
                                                const char *end1, const char *ptr2)
{
    (void)enc;
    for (; *ptr2; ptr1 += 2, ptr2++) {
        if (ptr1 == end1)
            return 0;
        if (!(ptr1[1] == 0 && ptr1[0] == *ptr2))
            return 0;
    }
    return ptr1 == end1;
}

/* Same for big-endian UTF-16 (Expat big2_nameMatchesAscii). Swing_DLL.xex 0x888919E8 */
int ts4_xmltok_big2_name_matches_ascii_888919E8(const struct ts4_xml_encoding *enc, const char *ptr1,
                                                   const char *end1, const char *ptr2)
{
    (void)enc;
    for (; *ptr2; ptr1 += 2, ptr2++) {
        if (ptr1 == end1)
            return 0;
        if (!(ptr1[0] == 0 && ptr1[1] == *ptr2))
            return 0;
    }
    return ptr1 == end1;
}

/* Test for an XML whitespace character (space, tab, LF, CR). Swing_DLL.xex 0x888918D0 */
int ts4_xmltok_is_space_888918D0(int c)
{
    switch (c) {
    case 0x20:
    case 0xD:
    case 0xA:
    case 0x9:
        return 1;
    }
    return 0;
}

/* Convert the first character at ptr to ASCII through the encoding's UTF-8 converter, or -1 when it
 * produces no byte (Expat toAscii). Swing_DLL.xex 0x88891908 */
int ts4_xmltok_to_ascii_88891908(const struct ts4_xml_encoding *enc, const char *ptr, const char *end)
{
    char buf[1];
    char *p = buf;
    enc->utf8_convert(enc, &ptr, end, &p, p + 1);
    if (p == buf)
        return -1;
    return buf[0];
}

/* Case-insensitive ASCII string equality (Expat streqci). Swing_DLL.xex 0x88891978 */
int ts4_xmltok_streqci_88891978(const char *s1, const char *s2)
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
