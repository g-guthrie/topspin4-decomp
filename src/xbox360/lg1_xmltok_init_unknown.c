/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family LG1: Expat XmlInitUnknownEncoding. The original addresses latin1_encoding, nmstrtPages and
 * namingBitmap from the namePages symbol (0x880CEFC0) with constant offsets. */
#include "r3_xmltok.h"

#ifdef _MSC_VER
#define LG1_UNUSED
#else
#define LG1_UNUSED __attribute__((unused))
#endif

/* Layout stand-ins for the Expat tables of this translation unit (contents are NOT the real data; only the
 * relative layout matters, because the original addresses every static from one anchor register). */
static const unsigned char lg1_layout_pad[16] LG1_UNUSED = {1};   /* shifts the anchor choice */
static const unsigned int lbl_880CE9C0[320] = {1};                /* namingBitmap */
static const unsigned char lbl_880CEEC0[256] = {1};               /* nmstrtPages */
static const unsigned char lbl_880CEFC0[256] = {1};               /* namePages */
static const unsigned char lg1_encodings_gap[0x738] LG1_UNUSED = {1}; /* utf8/internal/latin1_ns encodings */
static const struct ts4_xml_normal_encoding lbl_880CF7F8 = {0}; /* latin1_encoding */

#define LG1_LATIN1 (&lbl_880CF7F8)
#define LG1_NMSTRT_PAGES lbl_880CEEC0
#define LG1_BITMAP lbl_880CE9C0
#define LG1_UCS2_NAMING(pages, hi, lo) (LG1_BITMAP[((pages)[hi] << 3) + ((lo) >> 5)] & (1u << ((lo) & 0x1F)))

struct lg1_unknown_encoding {
    struct ts4_xml_normal_encoding normal;          /* +0x000 */
    int (*convert)(void *user_data, const char *p); /* +0x170 */
    void *user_data;                                /* +0x174 */
    unsigned short utf16[256];                      /* +0x178 */
    char utf8[256][4];                              /* +0x378 */
};

int fn_88891700(const struct ts4_xml_encoding *enc, const char *p); /* unknown_isName */
int fn_88891678(const struct ts4_xml_encoding *enc, const char *p); /* unknown_isNmstrt */
int fn_88894E10(const struct ts4_xml_encoding *enc, const char *p); /* unknown_isInvalid */
void fn_888915C0(const struct ts4_xml_encoding *enc, const char **from_p, const char *from_lim, unsigned short **to_p,
                 const unsigned short *to_lim); /* unknown_toUtf16 */
void ts4_xmltok_unknown_to_utf8_88894C50(const struct ts4_xml_encoding *enc, const char **from_p, const char *from_lim,
                                         char **to_p, const char *to_lim);

/* Encode a code point as UTF-8 into buf, returning the byte count (0 when not encodable)
 * (Expat XmlUtf8Encode). Swing_DLL.xex 0x88891790 */
int ts4_xmltok_utf8_encode_88891790(int c, char *buf)
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

/* Reject surrogates, U+FFFE/U+FFFF and non-XML latin1 controls (Expat checkCharRefNumber). */
static int lg1_check_char_ref_number(int result)
{
    switch (result >> 8) {
    case 0xD8: case 0xD9: case 0xDA: case 0xDB:
    case 0xDC: case 0xDD: case 0xDE: case 0xDF:
        return -1;
    case 0:
        if (LG1_LATIN1->type[result] == TS4_BT_NONXML)
            return -1;
        break;
    case 0xFF:
        if (result == 0xFFFE || result == 0xFFFF)
            return -1;
        break;
    }
    return result;
}

/* Build an application-defined single-byte encoding from a 256-entry code table on top of latin1
 * (Expat XmlInitUnknownEncoding); returns 0 when the table is inconsistent. Swing_DLL.xex 0x88899C70 */
const struct ts4_xml_encoding *ts4_xmltok_init_unknown_encoding_88899C70(void *mem, int *table,
                                                                        int (*convert)(void *, const char *),
                                                                        void *user_data)
{
    int i;
    struct lg1_unknown_encoding *e = (struct lg1_unknown_encoding *)mem;
    for (i = 0; i < (int)sizeof(struct ts4_xml_normal_encoding); i++)
        ((char *)mem)[i] = ((const char *)LG1_LATIN1)[i];
    for (i = 0; i < 128; i++)
        if (LG1_LATIN1->type[i] != TS4_BT_OTHER && LG1_LATIN1->type[i] != TS4_BT_NONXML && table[i] != i)
            return 0;
    for (i = 0; i < 256; i++) {
        int c = table[i];
        if (c == -1) {
            e->normal.type[i] = TS4_BT_MALFORM;
            e->utf16[i] = 0xFFFF;
            e->utf8[i][0] = 1;
            e->utf8[i][1] = 0;
        } else if (c < 0) {
            if (c < -4)
                return 0;
            e->normal.type[i] = (unsigned char)(TS4_BT_LEAD2 - (c + 2));
            e->utf8[i][0] = 0;
            e->utf16[i] = 0;
        } else if (c < 0x80) {
            if (LG1_LATIN1->type[c] != TS4_BT_OTHER && LG1_LATIN1->type[c] != TS4_BT_NONXML && c != i)
                return 0;
            e->normal.type[i] = LG1_LATIN1->type[c];
            e->utf8[i][0] = 1;
            e->utf8[i][1] = (char)c;
            e->utf16[i] = (unsigned short)(c == 0 ? 0xFFFF : c);
        } else if (lg1_check_char_ref_number(c) < 0) {
            e->normal.type[i] = TS4_BT_NONXML;
            e->utf16[i] = 0xFFFF;
            e->utf8[i][0] = 1;
            e->utf8[i][1] = 0;
        } else {
            if (c > 0xFFFF)
                return 0;
            if (LG1_UCS2_NAMING(LG1_NMSTRT_PAGES, c >> 8, c & 0xFF))
                e->normal.type[i] = TS4_BT_NMSTRT;
            else if (LG1_UCS2_NAMING(lbl_880CEFC0, c >> 8, c & 0xFF))
                e->normal.type[i] = TS4_BT_NAME;
            else
                e->normal.type[i] = TS4_BT_OTHER;
            e->utf8[i][0] = (char)ts4_xmltok_utf8_encode_88891790(c, e->utf8[i] + 1);
            e->utf16[i] = (unsigned short)c;
        }
    }
    e->user_data = user_data;
    e->convert = convert;
    if (convert) {
        e->normal.is_name2 = fn_88891700;
        e->normal.is_name3 = fn_88891700;
        e->normal.is_name4 = fn_88891700;
        e->normal.is_nmstrt2 = fn_88891678;
        e->normal.is_nmstrt3 = fn_88891678;
        e->normal.is_nmstrt4 = fn_88891678;
        e->normal.is_invalid2 = fn_88894E10;
        e->normal.is_invalid3 = fn_88894E10;
        e->normal.is_invalid4 = fn_88894E10;
    }
    e->normal.enc.utf8_convert = ts4_xmltok_unknown_to_utf8_88894C50;
    e->normal.enc.utf16_convert = fn_888915C0;
    return &e->normal.enc;
}
