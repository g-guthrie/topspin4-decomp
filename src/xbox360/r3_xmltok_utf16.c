/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "r3_xmltok.h"

/* Expat unicode_byte_type(hi, lo): byte-type class of a UTF-16 code unit (placeholder callee). */


typedef struct ts4_xml_position {
    unsigned int line_number;   /* +0x00 */
    unsigned int column_number; /* +0x04 */
} ts4_xml_position;

/* Expat unicode_byte_type: byte-type class of a UTF-16 code unit. Swing_DLL.xex 0x888927A0 */
int ts4_xmltok_unicode_byte_type_888927A0(char hi, char lo)
{
    switch ((unsigned char)hi) {
    case 0xD8: case 0xD9: case 0xDA: case 0xDB:
        return TS4_BT_LEAD4;
    case 0xDC: case 0xDD: case 0xDE: case 0xDF:
        return TS4_BT_TRAIL;
    case 0xFF:
        switch ((unsigned char)lo) {
        case 0xFF: case 0xFE:
            return TS4_BT_NONXML;
        }
        break;
    }
    return TS4_BT_NONASCII;
}

#define TS4_BIG2_BYTE_TYPE(enc, p) \
    ((p)[0] == 0 ? ((const struct ts4_xml_normal_encoding *)(enc))->type[(unsigned char)(p)[1]] \
                 : ts4_xmltok_unicode_byte_type_888927A0((p)[0], (p)[1]))
#define TS4_BIG2_BYTE_TYPE_CALL(enc, p) \
    ((p)[0] == 0 ? ((const struct ts4_xml_normal_encoding *)(enc))->type[(unsigned char)(p)[1]] \
                 : ts4_xmltok_unicode_byte_type_888927A0((p)[0], (p)[1]))
#define TS4_LITTLE2_BYTE_TYPE(enc, p) \
    ((p)[1] == 0 ? ((const struct ts4_xml_normal_encoding *)(enc))->type[(unsigned char)(p)[0]] \
                 : ts4_xmltok_unicode_byte_type_888927A0((p)[1], (p)[0]))
#define TS4_LITTLE2_BYTE_TYPE_CALL(enc, p) \
    ((p)[1] == 0 ? ((const struct ts4_xml_normal_encoding *)(enc))->type[(unsigned char)(p)[0]] \
                 : ts4_xmltok_unicode_byte_type_888927A0((p)[1], (p)[0]))

/* Update line/column position over a UTF-16 range (Expat PREFIX(updatePosition)), parameterised
 * by function name and the byte-type macro of the byte order. */
#define TS4_DEFINE_UPDATE_POSITION(name, BYTE_TYPE, BYTE_TYPE_CALL) \
void name(const struct ts4_xml_encoding *enc, const char *ptr, const char *end, ts4_xml_position *pos) \
{ \
    while (ptr != end) { \
        switch (BYTE_TYPE(enc, ptr)) { \
        case TS4_BT_LEAD2: \
            ptr += 2; \
            break; \
        case TS4_BT_LEAD3: \
            ptr += 3; \
            break; \
        case TS4_BT_LEAD4: \
            ptr += 4; \
            break; \
        case TS4_BT_LF: \
            pos->column_number = (unsigned int)-1; \
            pos->line_number++; \
            ptr += 2; \
            break; \
        case TS4_BT_CR: \
            pos->line_number++; \
            ptr += 2; \
            if (ptr != end && BYTE_TYPE_CALL(enc, ptr) == TS4_BT_LF) \
                ptr += 2; \
            pos->column_number = (unsigned int)-1; \
            break; \
        default: \
            ptr += 2; \
            break; \
        } \
        pos->column_number++; \
    } \
}

/* Swing_DLL.xex 0x88895150 (big-endian UTF-16) */
TS4_DEFINE_UPDATE_POSITION(ts4_xmltok_big2_update_position_88895150, TS4_BIG2_BYTE_TYPE, TS4_BIG2_BYTE_TYPE_CALL)
/* Swing_DLL.xex 0x88897270 (little-endian UTF-16) */
TS4_DEFINE_UPDATE_POSITION(ts4_xmltok_little2_update_position_88897270, TS4_LITTLE2_BYTE_TYPE, TS4_LITTLE2_BYTE_TYPE_CALL)

/* Convert UTF-16 to UTF-8 until the input or output range is exhausted (Expat PREFIX(toUtf8)),
 * parameterised by the byte order's GET_LO / GET_HI. */
#define TS4_DEFINE_TO_UTF8(name, GET_LO, GET_HI) \
void name(const struct ts4_xml_encoding *enc, const char **from_p, const char *from_lim, char **to_p, \
          const char *to_lim) \
{ \
    const char *from; \
    (void)enc; \
    for (from = *from_p; from != from_lim; from += 2) { \
        int plane; \
        unsigned char lo2; \
        unsigned char lo = GET_LO(from); \
        unsigned char hi = GET_HI(from); \
        switch (hi) { \
        case 0: \
            if (lo < 0x80) { \
                if (*to_p == to_lim) { \
                    *from_p = from; \
                    return; \
                } \
                *(*to_p)++ = lo; \
                break; \
            } \
            /* fall through */ \
        case 0x1: case 0x2: case 0x3: case 0x4: case 0x5: case 0x6: case 0x7: \
            if (to_lim - *to_p < 2) { \
                *from_p = from; \
                return; \
            } \
            *(*to_p)++ = ((lo >> 6) | (hi << 2) | 0xc0); \
            *(*to_p)++ = ((lo & 0x3f) | 0x80); \
            break; \
        default: \
            if (to_lim - *to_p < 3) { \
                *from_p = from; \
                return; \
            } \
            *(*to_p)++ = ((hi >> 4) | 0xe0); \
            *(*to_p)++ = (((hi & 0xf) << 2) | (lo >> 6) | 0x80); \
            *(*to_p)++ = ((lo & 0x3f) | 0x80); \
            break; \
        case 0xD8: case 0xD9: case 0xDA: case 0xDB: \
            if (to_lim - *to_p < 4) { \
                *from_p = from; \
                return; \
            } \
            plane = (((hi & 0x3) << 2) | ((lo >> 6) & 0x3)) + 1; \
            *(*to_p)++ = (char)((plane >> 2) | 0xf0); \
            *(*to_p)++ = (((lo >> 2) & 0xF) | ((plane & 0x3) << 4) | 0x80); \
            from += 2; \
            lo2 = GET_LO(from); \
            *(*to_p)++ = (((lo & 0x3) << 4) | ((GET_HI(from) & 0x3) << 2) | (lo2 >> 6) | 0x80); \
            *(*to_p)++ = ((lo2 & 0x3f) | 0x80); \
            break; \
        } \
    } \
    *from_p = from; \
}

#define TS4_LITTLE2_GET_LO(p) ((unsigned char)(p)[0])
#define TS4_LITTLE2_GET_HI(p) ((unsigned char)(p)[1])
#define TS4_BIG2_GET_LO(p) ((unsigned char)(p)[1])
#define TS4_BIG2_GET_HI(p) ((unsigned char)(p)[0])

/* Swing_DLL.xex 0x888925C0 (little-endian UTF-16 source) */
TS4_DEFINE_TO_UTF8(ts4_xmltok_little2_to_utf8_888925C0, TS4_LITTLE2_GET_LO, TS4_LITTLE2_GET_HI)
/* Swing_DLL.xex 0x88892348 (big-endian UTF-16 source) */
TS4_DEFINE_TO_UTF8(ts4_xmltok_big2_to_utf8_88892348, TS4_BIG2_GET_LO, TS4_BIG2_GET_HI)

/* Latin-1 ENCODING table used by Expat's checkCharRefNumber (normal_encoding layout). */
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

/* Parameterised by byte order: CHAR_MATCHES(p, c) and BYTE_TO_ASCII(p). */
#define TS4_BIG2_CHAR_MATCHES(p, c) ((p)[0] == 0 && (p)[1] == (c))
#define TS4_BIG2_BYTE_TO_ASCII(p) ((p)[0] == 0 ? (p)[1] : -1)
#define TS4_LITTLE2_CHAR_MATCHES(p, c) ((p)[1] == 0 && (p)[0] == (c))
#define TS4_LITTLE2_BYTE_TO_ASCII(p) ((p)[1] == 0 ? (p)[0] : -1)

/* Numeric character reference value for UTF-16 input (Expat PREFIX(charRefNumber)). */
#define TS4_DEFINE_CHAR_REF_NUMBER(name, CHAR_MATCHES, BYTE_TO_ASCII) \
int name(const struct ts4_xml_encoding *enc, const char *ptr) \
{ \
    int result = 0; \
    (void)enc; \
    ptr += 2 * 2; \
    if (CHAR_MATCHES(ptr, 'x')) { \
        for (ptr += 2; !CHAR_MATCHES(ptr, ';'); ptr += 2) { \
            int c = BYTE_TO_ASCII(ptr); \
            switch (c) { \
            case '0': case '1': case '2': case '3': case '4': \
            case '5': case '6': case '7': case '8': case '9': \
                result <<= 4; \
                result |= (c - '0'); \
                break; \
            case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': \
                result <<= 4; \
                result += 10 + (c - 'A'); \
                break; \
            case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': \
                result <<= 4; \
                result += 10 + (c - 'a'); \
                break; \
            } \
            if (result >= 0x110000) \
                return -1; \
        } \
    } else { \
        for (; !CHAR_MATCHES(ptr, ';'); ptr += 2) { \
            int c = BYTE_TO_ASCII(ptr); \
            result *= 10; \
            result += (c - '0'); \
            if (result >= 0x110000) \
                return -1; \
        } \
    } \
    return ts4_check_char_ref_number(result); \
}

/* Swing_DLL.xex 0x88891BD8 */
TS4_DEFINE_CHAR_REF_NUMBER(ts4_xmltok_big2_char_ref_number_88891BD8, TS4_BIG2_CHAR_MATCHES, TS4_BIG2_BYTE_TO_ASCII)
/* Swing_DLL.xex 0x88892048 */
TS4_DEFINE_CHAR_REF_NUMBER(ts4_xmltok_little2_char_ref_number_88892048, TS4_LITTLE2_CHAR_MATCHES, TS4_LITTLE2_BYTE_TO_ASCII)

/* Predefined entity name (lt, gt, amp, quot, apos) to its character, or 0
 * (Expat PREFIX(predefinedEntityName)). */
#define TS4_DEFINE_PREDEFINED_ENTITY_NAME(name, CHAR_MATCHES, BYTE_TO_ASCII) \
int name(const struct ts4_xml_encoding *enc, const char *ptr, const char *end) \
{ \
    (void)enc; \
    switch ((end - ptr) / 2) { \
    case 2: \
        if (CHAR_MATCHES(ptr + 2, 't')) { \
            switch (BYTE_TO_ASCII(ptr)) { \
            case 'l': \
                return '<'; \
            case 'g': \
                return '>'; \
            } \
        } \
        break; \
    case 3: \
        if (CHAR_MATCHES(ptr, 'a')) { \
            ptr += 2; \
            if (CHAR_MATCHES(ptr, 'm')) { \
                ptr += 2; \
                if (CHAR_MATCHES(ptr, 'p')) \
                    return '&'; \
            } \
        } \
        break; \
    case 4: \
        switch (BYTE_TO_ASCII(ptr)) { \
        case 'q': \
            ptr += 2; \
            if (CHAR_MATCHES(ptr, 'u')) { \
                ptr += 2; \
                if (CHAR_MATCHES(ptr, 'o')) { \
                    ptr += 2; \
                    if (CHAR_MATCHES(ptr, 't')) \
                        return '"'; \
                } \
            } \
            break; \
        case 'a': \
            ptr += 2; \
            if (CHAR_MATCHES(ptr, 'p')) { \
                ptr += 2; \
                if (CHAR_MATCHES(ptr, 'o')) { \
                    ptr += 2; \
                    if (CHAR_MATCHES(ptr, 's')) \
                        return '\''; \
                } \
            } \
            break; \
        } \
    } \
    return 0; \
}

/* Swing_DLL.xex 0x88891A48 */
TS4_DEFINE_PREDEFINED_ENTITY_NAME(ts4_xmltok_big2_predefined_entity_name_88891A48, TS4_BIG2_CHAR_MATCHES, TS4_BIG2_BYTE_TO_ASCII)
/* Swing_DLL.xex 0x88891EA8 */
TS4_DEFINE_PREDEFINED_ENTITY_NAME(ts4_xmltok_little2_predefined_entity_name_88891EA8, TS4_LITTLE2_CHAR_MATCHES, TS4_LITTLE2_BYTE_TO_ASCII)
