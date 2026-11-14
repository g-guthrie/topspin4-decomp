/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX4: Expat xmltok_impl.c ignoreSectionTok for the two 16-bit encodings. */
#include "r3_xmltok.h"

#define EX4_XML_TOK_PARTIAL (-1)
#define EX4_XML_TOK_PARTIAL_CHAR (-2)
#define EX4_XML_TOK_INVALID 0
#define EX4_XML_TOK_IGNORE_SECT 42

/* Expat unicode_byte_type(hi, lo), inlined into the scanners. */
static int ex4_unicode_byte_type(char hi, char lo)
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

#define EX4_BIG2_BYTE_TYPE(enc, p)                                                           \
    ((p)[0] == 0 ? ((const struct ts4_xml_normal_encoding *)(enc))->type[(unsigned char)(p)[1]] \
                 : ex4_unicode_byte_type((p)[0], (p)[1]))
#define EX4_LITTLE2_BYTE_TYPE(enc, p)                                                        \
    ((p)[1] == 0 ? ((const struct ts4_xml_normal_encoding *)(enc))->type[(unsigned char)(p)[0]] \
                 : ex4_unicode_byte_type((p)[1], (p)[0]))
#define EX4_BIG2_CHAR_MATCHES(p, c) ((p)[0] == 0 && (p)[1] == (c))
#define EX4_LITTLE2_CHAR_MATCHES(p, c) ((p)[1] == 0 && (p)[0] == (c))

/* Scan a conditional section being ignored: track nested "<![" and "]]>" (Expat PREFIX(ignoreSectionTok)). */
#define EX4_DEFINE_IGNORE_SECTION_TOK(name, BYTE_TYPE, CHAR_MATCHES)                                         \
int name(const struct ts4_xml_encoding *enc, const char *ptr, const char *end, const char **next_tok_ptr)  \
{                                                                                                            \
    int level = 0;                                                                                           \
    if (2 > 1) {                                                                                             \
        unsigned n = (unsigned)(end - ptr);                                                                  \
        if (n & (2 - 1)) {                                                                                   \
            n &= ~(2U - 1);                                                                                  \
            end = ptr + n;                                                                                   \
        }                                                                                                    \
    }                                                                                                        \
    while (ptr != end) {                                                                                     \
        switch (BYTE_TYPE(enc, ptr)) {                                                                       \
        case TS4_BT_LEAD2:                                                                                   \
            if (end - ptr < 2)                                                                               \
                return EX4_XML_TOK_PARTIAL_CHAR;                                                             \
            ptr += 2;                                                                                        \
            break;                                                                                           \
        case TS4_BT_LEAD3:                                                                                   \
            if (end - ptr < 3)                                                                               \
                return EX4_XML_TOK_PARTIAL_CHAR;                                                             \
            ptr += 3;                                                                                        \
            break;                                                                                           \
        case TS4_BT_LEAD4:                                                                                   \
            if (end - ptr < 4)                                                                               \
                return EX4_XML_TOK_PARTIAL_CHAR;                                                             \
            ptr += 4;                                                                                        \
            break;                                                                                           \
        case TS4_BT_NONXML:                                                                                  \
        case TS4_BT_MALFORM:                                                                                 \
        case TS4_BT_TRAIL:                                                                                   \
            *next_tok_ptr = ptr;                                                                             \
            return EX4_XML_TOK_INVALID;                                                                      \
        case TS4_BT_LT:                                                                                      \
            if ((ptr += 2) == end)                                                                           \
                return EX4_XML_TOK_PARTIAL;                                                                  \
            if (CHAR_MATCHES(ptr, '!')) {                                                                    \
                if ((ptr += 2) == end)                                                                       \
                    return EX4_XML_TOK_PARTIAL;                                                              \
                if (CHAR_MATCHES(ptr, '[')) {                                                                \
                    ++level;                                                                                 \
                    ptr += 2;                                                                                \
                }                                                                                            \
            }                                                                                                \
            break;                                                                                           \
        case TS4_BT_RSQB:                                                                                    \
            if ((ptr += 2) == end)                                                                           \
                return EX4_XML_TOK_PARTIAL;                                                                  \
            if (CHAR_MATCHES(ptr, ']')) {                                                                    \
                if ((ptr += 2) == end)                                                                       \
                    return EX4_XML_TOK_PARTIAL;                                                              \
                if (CHAR_MATCHES(ptr, '>')) {                                                                \
                    ptr += 2;                                                                                \
                    if (level == 0) {                                                                        \
                        *next_tok_ptr = ptr;                                                                 \
                        return EX4_XML_TOK_IGNORE_SECT;                                                      \
                    }                                                                                        \
                    --level;                                                                                 \
                }                                                                                            \
            }                                                                                                \
            break;                                                                                           \
        default:                                                                                             \
            ptr += 2;                                                                                        \
            break;                                                                                           \
        }                                                                                                    \
    }                                                                                                        \
    return EX4_XML_TOK_PARTIAL;                                                                              \
}

/* Swing_DLL.xex 0x88895B30 (big-endian UTF-16) */
EX4_DEFINE_IGNORE_SECTION_TOK(ex4_xmltok_big2_ignore_section_tok_88895B30, EX4_BIG2_BYTE_TYPE, EX4_BIG2_CHAR_MATCHES)
/* Swing_DLL.xex 0x88897C50 (little-endian UTF-16) */
EX4_DEFINE_IGNORE_SECTION_TOK(ex4_xmltok_little2_ignore_section_tok_88897C50, EX4_LITTLE2_BYTE_TYPE, EX4_LITTLE2_CHAR_MATCHES)
