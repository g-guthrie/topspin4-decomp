/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "r3_xmltok.h"

/* Expat unknown_encoding: a normal encoding plus application conversion callback and tables. */
struct ts4_xml_unknown_encoding {
    struct ts4_xml_normal_encoding normal;     /* +0x000 */
    int (*convert)(void *user_data, const char *p); /* +0x170 */
    void *user_data;                           /* +0x174 */
    unsigned short utf16[256];                 /* +0x178 */
    char utf8[256][4];                         /* +0x378 */
};

/* Encode a code point as UTF-8 into buf, returning the byte count (0 when not encodable)
 * (Expat XmlUtf8Encode). */
static int ts4_xml_utf8_encode(int c, char *buf)
{
    if (c < 0)
        return 0;
    if (c < 0x80) {
        buf[0] = (char)(c | 0x00);
        return 1;
    }
    if (c < 0x800) {
        buf[0] = (char)((c >> 6) | 0xc0);
        buf[1] = (char)((c & 0x3f) | 0x80);
        return 2;
    }
    if (c < 0x10000) {
        buf[0] = (char)((c >> 12) | 0xe0);
        buf[1] = (char)(((c >> 6) & 0x3f) | 0x80);
        buf[2] = (char)((c & 0x3f) | 0x80);
        return 3;
    }
    if (c < 0x110000) {
        buf[0] = (char)((c >> 18) | 0xf0);
        buf[1] = (char)(((c >> 12) & 0x3f) | 0x80);
        buf[2] = (char)(((c >> 6) & 0x3f) | 0x80);
        buf[3] = (char)((c & 0x3f) | 0x80);
        return 4;
    }
    return 0;
}

/* Convert application-defined single/multi-byte input to UTF-8 until output is exhausted
 * (Expat unknown_toUtf8). Swing_DLL.xex 0x88894C50 */
void ts4_xmltok_unknown_to_utf8_88894C50(const struct ts4_xml_encoding *enc, const char **from_p, const char *from_lim,
                                         char **to_p, const char *to_lim)
{
    char buf[4];
    for (;;) {
        const char *utf8;
        int n;
        if (*from_p == from_lim)
            break;
        utf8 = ((const struct ts4_xml_unknown_encoding *)enc)->utf8[(unsigned char)**from_p];
        n = *utf8++;
        if (n == 0) {
            int c = ((const struct ts4_xml_unknown_encoding *)enc)->convert(
                ((const struct ts4_xml_unknown_encoding *)enc)->user_data, *from_p);
            n = ts4_xml_utf8_encode(c, buf);
            if (n > to_lim - *to_p)
                break;
            utf8 = buf;
            *from_p += ((const struct ts4_xml_normal_encoding *)enc)->type[(unsigned char)**from_p] - (TS4_BT_LEAD2 - 2);
        } else {
            if (n > to_lim - *to_p)
                break;
            (*from_p)++;
        }
        do {
            *(*to_p)++ = *utf8++;
        } while (--n != 0);
    }
}
