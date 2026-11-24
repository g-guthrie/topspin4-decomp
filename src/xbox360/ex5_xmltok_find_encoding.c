/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX5: Expat xmltok.c findEncoding (map an encoding name from an XML declaration to a built-in encoding).
 * The two copies differ only in the table of built-in encodings they index (Expat encodings / encodingsNS). */
#include "r3_xmltok.h"

#ifdef _MSC_VER
extern int ts4_xmltok_streqci_88891978(const char *s1, const char *s2);
#else
int ts4_xmltok_streqci_88891978(const char *s1, const char *s2);
#endif
int ts4_xmltok_get_encoding_index_88894BA8(const char *name);

extern const struct ts4_xml_encoding *lbl_88C6ADC8[]; /* built-in encoding table used by the first copy */
extern const struct ts4_xml_encoding *lbl_88C6ADAC[]; /* built-in encoding table used by the second copy */
extern const char lbl_880D0534[];                     /* "UTF-16" */

#define EX5_ENCODING_MAX 128

#define EX5_DEFINE_FIND_ENCODING(name, table)                                                              \
const struct ts4_xml_encoding *name(const struct ts4_xml_encoding *enc, const char *ptr, const char *end) \
{                                                                                                          \
    char buf[EX5_ENCODING_MAX];                                                                            \
    char *p = buf;                                                                                         \
    int i;                                                                                                 \
    enc->utf8_convert(enc, &ptr, end, &p, buf + EX5_ENCODING_MAX - 1);                                     \
    if (ptr != end)                                                                                        \
        return 0;                                                                                          \
    *p = 0;                                                                                                \
    if (ts4_xmltok_streqci_88891978(buf, lbl_880D0534) && enc->min_bytes_per_char == 2)                    \
        return enc;                                                                                        \
    i = ts4_xmltok_get_encoding_index_88894BA8(buf);                                                       \
    if (i == -1)                                                                                           \
        return 0;                                                                                          \
    return table[i];                                                                                       \
}

/* Swing_DLL.xex 0x888999E0 */
EX5_DEFINE_FIND_ENCODING(ex5_xmltok_find_encoding_888999E0, lbl_88C6ADC8)
/* Swing_DLL.xex 0x88899B28 */
EX5_DEFINE_FIND_ENCODING(ex5_xmltok_find_encoding_88899B28, lbl_88C6ADAC)
