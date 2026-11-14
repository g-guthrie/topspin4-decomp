/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX3: Expat xmltok.c / xmltok_impl.c converters and entity-name helpers. */
#include "r3_xmltok.h"

#define EX3_UTF8_CVAL2 0xc0

/* Convert big-endian UTF-16 to native 16-bit units, never splitting a surrogate pair
 * (Expat big2_toUtf16). Swing_DLL.xex 0x888922C0 */
void ts4_xmltok_big2_to_utf16_888922C0(const struct ts4_xml_encoding *enc, const char **from_p, const char *from_lim,
                                       unsigned short **to_p, const unsigned short *to_lim)
{
    (void)enc;
    if (from_lim - *from_p > ((to_lim - *to_p) << 1) && ((from_lim[-2]) & 0xF8) == 0xD8)
        from_lim -= 2;
    for (; *from_p != from_lim && *to_p != to_lim; *from_p += 2)
        *(*to_p)++ = (unsigned short)(((unsigned char)(*from_p)[0] << 8) | (unsigned char)(*from_p)[1]);
}

/* Same for little-endian UTF-16 (Expat little2_toUtf16). Swing_DLL.xex 0x88892538 */
void ts4_xmltok_little2_to_utf16_88892538(const struct ts4_xml_encoding *enc, const char **from_p,
                                          const char *from_lim, unsigned short **to_p, const unsigned short *to_lim)
{
    (void)enc;
    if (from_lim - *from_p > ((to_lim - *to_p) << 1) && ((from_lim[-1]) & 0xF8) == 0xD8)
        from_lim -= 2;
    for (; *from_p != from_lim && *to_p != to_lim; *from_p += 2)
        *(*to_p)++ = (unsigned short)(((unsigned char)(*from_p)[1] << 8) | (unsigned char)(*from_p)[0]);
}

/* Convert ISO-8859-1 to UTF-8 (Expat latin1_toUtf8). Swing_DLL.xex 0x888928A0 */
void ts4_xmltok_latin1_to_utf8_888928A0(const struct ts4_xml_encoding *enc, const char **from_p, const char *from_lim,
                                        char **to_p, const char *to_lim)
{
    (void)enc;
    for (;;) {
        unsigned char c;
        if (*from_p == from_lim)
            break;
        c = (unsigned char)**from_p;
        if (c & 0x80) {
            if (to_lim - *to_p < 2)
                return;
            *(*to_p)++ = (char)((c >> 6) | EX3_UTF8_CVAL2);
            *(*to_p)++ = (char)((c & 0x3f) | 0x80);
            (*from_p)++;
        } else {
            if (*to_p == to_lim)
                return;
            *(*to_p)++ = *(*from_p)++;
        }
    }
}

/* Convert UTF-8 to UTF-16, emitting surrogate pairs for 4-byte sequences (Expat utf8_toUtf16).
 * Swing_DLL.xex 0x88892950 */
void ts4_xmltok_utf8_to_utf16_88892950(const struct ts4_xml_normal_encoding *enc, const char **from_p,
                                       const char *from_lim, unsigned short **to_p, const unsigned short *to_lim)
{
    unsigned short *to = *to_p;
    const char *from = *from_p;
    while (from != from_lim && to != to_lim) {
        switch (enc->type[(unsigned char)*from]) {
        case TS4_BT_LEAD2:
            *to++ = (unsigned short)(((from[0] & 0x1f) << 6) | (from[1] & 0x3f));
            from += 2;
            break;
        case TS4_BT_LEAD3:
            *to++ = (unsigned short)(((from[0] & 0xf) << 12) | ((from[1] & 0x3f) << 6) | (from[2] & 0x3f));
            from += 3;
            break;
        case TS4_BT_LEAD4: {
            unsigned long n;
            if (to + 1 == to_lim)
                goto after;
            n = ((from[0] & 0x7) << 18) | ((from[1] & 0x3f) << 12) | ((from[2] & 0x3f) << 6) | (from[3] & 0x3f);
            n -= 0x10000;
            to[0] = (unsigned short)((n >> 10) | 0xD800);
            to[1] = (unsigned short)((n & 0x3FF) | 0xDC00);
            to += 2;
            from += 4;
        } break;
        default:
            *to++ = *from++;
            break;
        }
    }
after:
    *from_p = from;
    *to_p = to;
}

/* Recognise lt, gt, amp, quot and apos (Expat normal_predefinedEntityName); returns the replacement
 * character or 0. Swing_DLL.xex 0x88892E98 */
int ts4_xmltok_normal_predefined_entity_name_88892E98(const struct ts4_xml_encoding *enc, const char *ptr,
                                                      const char *end)
{
    (void)enc;
    switch ((int)(end - ptr)) {
    case 2:
        if (ptr[1] == 't') {
            switch (ptr[0]) {
            case 'l':
                return '<';
            case 'g':
                return '>';
            }
        }
        break;
    case 3:
        if (ptr[0] == 'a') {
            ptr += 1;
            if (ptr[0] == 'm') {
                ptr += 1;
                if (ptr[0] == 'p')
                    return '&';
            }
        }
        break;
    case 4:
        switch (ptr[0]) {
        case 'q':
            ptr += 1;
            if (ptr[0] == 'u') {
                ptr += 1;
                if (ptr[0] == 'o') {
                    ptr += 1;
                    if (ptr[0] == 't')
                        return '"';
                }
            }
            break;
        case 'a':
            ptr += 1;
            if (ptr[0] == 'p') {
                ptr += 1;
                if (ptr[0] == 'o') {
                    ptr += 1;
                    if (ptr[0] == 's')
                        return '\'';
                }
            }
            break;
        }
        break;
    }
    return 0;
}
