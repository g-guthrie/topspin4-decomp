/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family LG1: Expat xmltok_impl.c PREFIX(getAtts) for the UTF-16 encodings (big2 / little2). */
#include "r3_xmltok.h"

#ifdef _MSC_VER
#define LG1_INLINE __inline
#else
#define LG1_INLINE inline
#endif

/* Expat ATTRIBUTE (0x10 bytes). */
struct lg1_xml_attribute {
    const char *name;      /* +0x0 */
    const char *value_ptr; /* +0x4 */
    const char *value_end; /* +0x8 */
    char normalized;       /* +0xC */
};

#ifdef _MSC_VER
#define LG1_NOINLINE __declspec(noinline)
#else
#define LG1_NOINLINE
#endif

/* Expat unicode_byte_type: byte-type class of a UTF-16 code unit. A same-TU static copy of the function
 * matched in r3_xmltok_utf16.c (Swing_DLL.xex 0x888927A0): the callers below only match when the compiler
 * sees its body, because it then keeps caller registers live across the call. Not listed in the spec. */
static LG1_NOINLINE int ts4_xmltok_unicode_byte_type_888927A0(char hi, char lo)
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

/* Expat unicode_byte_type, inlined copy (the original inlines it at some call sites only). */
static LG1_INLINE int lg1_unicode_byte_type(char hi, char lo)
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

#define LG1_NORMAL_TYPE(enc, c) (((const struct ts4_xml_normal_encoding *)(enc))->type[(unsigned char)(c)])
#define LG1_BIG2_BYTE_TYPE(enc, p) ((p)[0] == 0 ? LG1_NORMAL_TYPE(enc, (p)[1]) : lg1_unicode_byte_type((p)[0], (p)[1]))
#define LG1_BIG2_BYTE_TYPE_CALL(enc, p) \
    ((p)[0] == 0 ? LG1_NORMAL_TYPE(enc, (p)[1]) : ts4_xmltok_unicode_byte_type_888927A0((p)[0], (p)[1]))
#define LG1_BIG2_BYTE_TO_ASCII(enc, p) ((p)[0] == 0 ? (p)[1] : -1)
#define LG1_LITTLE2_BYTE_TYPE(enc, p) ((p)[1] == 0 ? LG1_NORMAL_TYPE(enc, (p)[0]) : lg1_unicode_byte_type((p)[1], (p)[0]))
#define LG1_LITTLE2_BYTE_TYPE_CALL(enc, p) \
    ((p)[1] == 0 ? LG1_NORMAL_TYPE(enc, (p)[0]) : ts4_xmltok_unicode_byte_type_888927A0((p)[1], (p)[0]))
#define LG1_LITTLE2_BYTE_TO_ASCII(enc, p) ((p)[1] == 0 ? (p)[0] : -1)

/* Collect attribute name/value pointers of a start tag that was already tokenized (Expat PREFIX(getAtts));
 * returns the attribute count, filling at most atts_max entries. */
#define LG1_DEFINE_GET_ATTS(fname, BYTE_TYPE, BYTE_TYPE_CALL, BYTE_TO_ASCII) \
int fname(const struct ts4_xml_encoding *enc, const char *ptr, int atts_max, struct lg1_xml_attribute *atts) \
{ \
    enum { other, in_name, in_value } state = in_name; \
    int n_atts = 0; \
    int open = 0; \
    for (ptr += 2;; ptr += 2) { \
        switch (BYTE_TYPE(enc, ptr)) { \
        case TS4_BT_LEAD2: \
            if (state == other) { \
                if (n_atts < atts_max) { \
                    atts[n_atts].name = ptr; \
                    atts[n_atts].normalized = 1; \
                } \
                state = in_name; \
            } \
            ptr += 2 - 2; \
            break; \
        case TS4_BT_LEAD3: \
            if (state == other) { \
                if (n_atts < atts_max) { \
                    atts[n_atts].name = ptr; \
                    atts[n_atts].normalized = 1; \
                } \
                state = in_name; \
            } \
            ptr += 3 - 2; \
            break; \
        case TS4_BT_LEAD4: \
            if (state == other) { \
                if (n_atts < atts_max) { \
                    atts[n_atts].name = ptr; \
                    atts[n_atts].normalized = 1; \
                } \
                state = in_name; \
            } \
            ptr += 4 - 2; \
            break; \
        case TS4_BT_NONASCII: \
        case TS4_BT_NMSTRT: \
        case TS4_BT_HEX: \
            if (state == other) { \
                if (n_atts < atts_max) { \
                    atts[n_atts].name = ptr; \
                    atts[n_atts].normalized = 1; \
                } \
                state = in_name; \
            } \
            break; \
        case TS4_BT_QUOT: \
            if (state != in_value) { \
                if (n_atts < atts_max) \
                    atts[n_atts].value_ptr = ptr + 2; \
                state = in_value; \
                open = TS4_BT_QUOT; \
            } else if (open == TS4_BT_QUOT) { \
                state = other; \
                if (n_atts < atts_max) \
                    atts[n_atts].value_end = ptr; \
                n_atts++; \
            } \
            break; \
        case TS4_BT_APOS: \
            if (state != in_value) { \
                if (n_atts < atts_max) \
                    atts[n_atts].value_ptr = ptr + 2; \
                state = in_value; \
                open = TS4_BT_APOS; \
            } else if (open == TS4_BT_APOS) { \
                state = other; \
                if (n_atts < atts_max) \
                    atts[n_atts].value_end = ptr; \
                n_atts++; \
            } \
            break; \
        case TS4_BT_AMP: \
            if (n_atts < atts_max) \
                atts[n_atts].normalized = 0; \
            break; \
        case TS4_BT_S: \
            if (state == in_name) \
                state = other; \
            else if (state == in_value && n_atts < atts_max && atts[n_atts].normalized && \
                     (ptr == atts[n_atts].value_ptr || BYTE_TO_ASCII(enc, ptr) != 0x20 || \
                      BYTE_TO_ASCII(enc, ptr + 2) == 0x20 || BYTE_TYPE_CALL(enc, ptr + 2) == open)) \
                atts[n_atts].normalized = 0; \
            break; \
        case TS4_BT_CR: \
        case TS4_BT_LF: \
            if (state == in_name) \
                state = other; \
            else if (state == in_value && n_atts < atts_max) \
                atts[n_atts].normalized = 0; \
            break; \
        case TS4_BT_GT: \
        case TS4_BT_SOL: \
            if (state != in_value) \
                return n_atts; \
            break; \
        default: \
            break; \
        } \
    } \
}

/* Swing_DLL.xex 0x88895638 (big-endian UTF-16) */
LG1_DEFINE_GET_ATTS(ts4_xmltok_big2_get_atts_88895638, LG1_BIG2_BYTE_TYPE, LG1_BIG2_BYTE_TYPE_CALL, LG1_BIG2_BYTE_TO_ASCII)
/* Swing_DLL.xex 0x88897758 (little-endian UTF-16) */
LG1_DEFINE_GET_ATTS(ts4_xmltok_little2_get_atts_88897758, LG1_LITTLE2_BYTE_TYPE, LG1_LITTLE2_BYTE_TYPE_CALL,
                    LG1_LITTLE2_BYTE_TO_ASCII)
