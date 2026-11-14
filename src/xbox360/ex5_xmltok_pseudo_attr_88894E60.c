/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX5: Expat xmltok.c parsePseudoAttribute (one name="value" pair of an XML declaration). */
#include "r3_xmltok.h"

int ts4_xmltok_to_ascii_88891908(const struct ts4_xml_encoding *enc, const char *ptr, const char *end);
#define to_ascii ts4_xmltok_to_ascii_88891908

#ifdef _MSC_VER
#define EX5_FORCEINLINE static __forceinline
#else
#define EX5_FORCEINLINE static inline
#endif
/* Inline copy of toAscii, used by one call site of the original. */
EX5_FORCEINLINE int to_ascii_inl(const struct ts4_xml_encoding *enc, const char *ptr, const char *end)
{
    char buf[1];
    char *p = buf;
    enc->utf8_convert(enc, &ptr, end, &p, p + 1);
    if (p == buf)
        return -1;
    return buf[0];
}

/* Expat isSpace */
static int is_space(int c)
{
    switch (c) {
    case 0x20: case 0xD: case 0xA: case 0x9:
        return 1;
    }
    return 0;
}
#define IS_SPACE is_space

/* Parse one pseudo-attribute: leading white space, name, "=", quoted value. Returns 1 with *name_ptr NULL at the
 * end of the declaration; returns 0 with *next_tok_ptr at the offending character. Swing_DLL.xex 0x88894E60 */
int ex5_xmltok_parse_pseudo_attribute_88894E60(const struct ts4_xml_encoding *enc, const char *ptr, const char *end,
                                               const char **name_ptr, const char **name_end_ptr,
                                               const char **val_ptr, const char **next_tok_ptr)
{
    int c;
    char open;
    if (ptr == end) {
        *name_ptr = 0;
        return 1;
    }
    if (!IS_SPACE(to_ascii(enc, ptr, end))) {
        *next_tok_ptr = ptr;
        return 0;
    }
    do {
        ptr += enc->min_bytes_per_char;
    } while (IS_SPACE(to_ascii_inl(enc, ptr, end)));
    if (ptr == end) {
        *name_ptr = 0;
        return 1;
    }
    *name_ptr = ptr;
    for (;;) {
        c = to_ascii(enc, ptr, end);
        if (c == -1) {
            *next_tok_ptr = ptr;
            return 0;
        }
        if (c == '=') {
            *name_end_ptr = ptr;
            break;
        }
        if (IS_SPACE(c)) {
            *name_end_ptr = ptr;
            do {
                ptr += enc->min_bytes_per_char;
            } while (IS_SPACE(c = to_ascii(enc, ptr, end)));
            if (c != '=') {
                *next_tok_ptr = ptr;
                return 0;
            }
            break;
        }
        ptr += enc->min_bytes_per_char;
    }
    if (ptr == *name_ptr) {
        *next_tok_ptr = ptr;
        return 0;
    }
    ptr += enc->min_bytes_per_char;
    c = to_ascii(enc, ptr, end);
    while (IS_SPACE(c)) {
        ptr += enc->min_bytes_per_char;
        c = to_ascii(enc, ptr, end);
    }
    if (c != '"' && c != '\'') {
        *next_tok_ptr = ptr;
        return 0;
    }
    open = (char)c;
    ptr += enc->min_bytes_per_char;
    *val_ptr = ptr;
    for (;; ptr += enc->min_bytes_per_char) {
        c = to_ascii(enc, ptr, end);
        if (c == open)
            break;
        if (!('a' <= c && c <= 'z') && !('A' <= c && c <= 'Z') && !('0' <= c && c <= '9') && c != '.' &&
            c != '-' && c != '_') {
            *next_tok_ptr = ptr;
            return 0;
        }
    }
    *next_tok_ptr = ptr + enc->min_bytes_per_char;
    return 1;
}
