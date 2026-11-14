/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX3: small Expat xmltok.c / xmltok_impl.c helpers. */
#include "r3_xmltok.h"

struct ts4_xml_position {
    unsigned int line_number;   /* +0x00 */
    unsigned int column_number; /* +0x04 */
};

/* Copy bytes until either range is exhausted (Expat ascii_toUtf8). Swing_DLL.xex 0x88892800 */
void ts4_xmltok_ascii_to_utf8_88892800(const struct ts4_xml_encoding *enc, const char **from_p, const char *from_lim,
                                       char **to_p, const char *to_lim)
{
    (void)enc;
    while (*from_p != from_lim && *to_p != to_lim)
        *(*to_p)++ = *(*from_p)++;
}

/* Widen bytes to UTF-16 units (Expat latin1_toUtf16). Swing_DLL.xex 0x88892850 */
void ts4_xmltok_latin1_to_utf16_88892850(const struct ts4_xml_encoding *enc, const char **from_p,
                                         const char *from_lim, unsigned short **to_p, const unsigned short *to_lim)
{
    (void)enc;
    while (*from_p != from_lim && *to_p != to_lim)
        *(*to_p)++ = (unsigned char)*(*from_p)++;
}

/* Copy UTF-8 without splitting a trailing partial character (Expat utf8_toUtf8). Swing_DLL.xex 0x88892A50 */
void ts4_xmltok_utf8_to_utf8_88892A50(const struct ts4_xml_encoding *enc, const char **from_p, const char *from_lim,
                                      char **to_p, const char *to_lim)
{
    char *to;
    const char *from;
    (void)enc;
    if (from_lim - *from_p > to_lim - *to_p) {
        from_lim = *from_p + (to_lim - *to_p);
        for (; from_lim > *from_p; from_lim--)
            if (((unsigned char)from_lim[-1] & 0xC0) != 0x80)
                break;
    }
    for (to = *to_p, from = *from_p; from != from_lim; from++, to++)
        *to = *from;
    *from_p = from;
    *to_p = to;
}

/* Advance line/column counters over a range of 8-bit text (Expat normal_updatePosition). Swing_DLL.xex 0x88892AD0 */
void ts4_xmltok_normal_update_position_88892AD0(const struct ts4_xml_normal_encoding *enc, const char *ptr,
                                                const char *end, struct ts4_xml_position *pos)
{
    while (ptr != end) {
        switch (enc->type[(unsigned char)*ptr]) {
        case TS4_BT_LEAD2:
            ptr += 2;
            break;
        case TS4_BT_LEAD3:
            ptr += 3;
            break;
        case TS4_BT_LEAD4:
            ptr += 4;
            break;
        case TS4_BT_LF:
            pos->column_number = (unsigned int)-1;
            pos->line_number++;
            ptr += 1;
            break;
        case TS4_BT_CR:
            pos->line_number++;
            ptr += 1;
            if (ptr != end && enc->type[(unsigned char)*ptr] == TS4_BT_LF)
                ptr += 1;
            pos->column_number = (unsigned int)-1;
            break;
        default:
            ptr += 1;
            break;
        }
        pos->column_number++;
    }
}

/* Skip CR, LF and space characters (Expat normal_skipS). Swing_DLL.xex 0x88892B90 */
const char *ts4_xmltok_normal_skip_s_88892B90(const struct ts4_xml_normal_encoding *enc, const char *ptr)
{
    for (;;) {
        switch (enc->type[(unsigned char)*ptr]) {
        case TS4_BT_LF:
        case TS4_BT_CR:
        case TS4_BT_S:
            ptr += 1;
            break;
        default:
            return ptr;
        }
    }
}

/* Compare a name range with a NUL-terminated ASCII string (Expat normal_nameMatchesAscii). Swing_DLL.xex 0x88892CB0 */
int ts4_xmltok_normal_name_matches_ascii_88892CB0(const struct ts4_xml_encoding *enc, const char *ptr1,
                                                  const char *end1, const char *ptr2)
{
    (void)enc;
    for (; *ptr2; ptr1 += 1, ptr2++) {
        if (ptr1 == end1)
            return 0;
        if (*ptr1 != *ptr2)
            return 0;
    }
    return ptr1 == end1;
}
