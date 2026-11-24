/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* 0x888915C0: Expat unknown_toUtf16 (xmltok.c): convert bytes of an unknown single/multi-byte encoding to UTF-16
 * through the encoding's utf16 table, calling the user converter for multi-byte sequences. Plain route, no flags.
 * src/xbox360/lg1_xmltok_init_unknown.c installs it (as ts4_xmltok_unknown_to_utf16_888915C0). */
#include "r3_xmltok.h"

struct ts4_xml_unknown_encoding_w {
    struct ts4_xml_normal_encoding normal;          /* +0x000 */
    int (*convert)(void *user_data, const char *p); /* +0x170 */
    void *user_data;                                /* +0x174 */
    unsigned short utf16[256];                      /* +0x178 */
    char utf8[256][4];                              /* +0x378 */
};

void ts4_xmltok_unknown_to_utf16_888915C0(const struct ts4_xml_encoding *enc, const char **from_p, const char *from_lim, unsigned short **to_p,
                 const unsigned short *to_lim)
{
    const struct ts4_xml_unknown_encoding_w *uenc = (const struct ts4_xml_unknown_encoding_w *)enc;
    while (*from_p != from_lim && *to_p != to_lim) {
        unsigned short c = uenc->utf16[(unsigned char)**from_p];
        if (c == 0) {
            c = (unsigned short)uenc->convert(uenc->user_data, *from_p);
            *from_p += (((const struct ts4_xml_normal_encoding *)enc)->type[(unsigned char)**from_p] - (5 - 2));
        } else
            (*from_p)++;
        *(*to_p)++ = c;
    }
}
