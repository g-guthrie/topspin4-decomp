/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family D5N: xmltok_impl.c prologTok for the 8-bit "normal" encoding (Swing_DLL.xex 0x8889A8E8-0x8889B15C).
 * One function per file (fn_check resolves $LN labels by name and they repeat per function). */
#include "swb2_expat.h"

#define PT_NONE (-4)
#define PT_PROLOG_S 15
#define PT_DECL_CLOSE 17
#define PT_NAME 18
#define PT_NMTOKEN 19
#define PT_OR 21
#define PT_OPEN_PAREN 23
#define PT_CLOSE_PAREN 24
#define PT_OPEN_BRACKET 25
#define PT_CLOSE_BRACKET 26
#define PT_INSTANCE_START 29
#define PT_NAME_QUESTION 30
#define PT_NAME_ASTERISK 31
#define PT_NAME_PLUS 32
#define PT_COND_SECT_CLOSE 34
#define PT_CLOSE_PAREN_QUESTION 35
#define PT_CLOSE_PAREN_ASTERISK 36
#define PT_CLOSE_PAREN_PLUS 37
#define PT_COMMA 38
#define PT_PREFIXED_NAME 41

#define PT_BT_PERCNT 30
#define PT_BT_LPAR 31
#define PT_BT_RPAR 32
#define PT_BT_AST 33
#define PT_BT_PLUS 34
#define PT_BT_COMMA 35
#define PT_BT_VERBAR 36

int ts4_scan_literal_88893690(int bt, const SwbEnc *enc, const char *ptr, const char *end, const char **next);
int ts4_scan_name_end_88899870(const SwbEnc *enc, const char *ptr, const char *end, const char **next);
int ex5_xml_scan_pi_normal_888993E8(const SwbEnc *enc, const char *ptr, const char *end, const char **next);
int ts4_xml_scan_percent_88893B50(const SwbEnc *enc, const char *ptr, const char *end, const char **next);
int ts4_xmltok_normal_scan_pound_name_88893860(const SwbEnc *enc, const char *ptr, const char *end, const char **next);

#define PT_NAME_CASES                                                                          \
    case SWB_BT_NONASCII:                                                                      \
        *next = ptr;                                                                           \
        return SWB_TOK_INVALID;                                                                \
    case SWB_BT_NMSTRT:                                                                        \
    case SWB_BT_HEX:                                                                           \
    case SWB_BT_DIGIT:                                                                         \
    case SWB_BT_NAME:                                                                          \
    case SWB_BT_MINUS:                                                                         \
        ptr += 1;                                                                              \
        break;                                                                                 \
    case SWB_BT_LEAD2:                                                                         \
        if (end - ptr < 2) return SWB_TOK_PARTIAL_CHAR;                                        \
        if (!enc->isName2(enc, ptr)) { *next = ptr; return SWB_TOK_INVALID; }                  \
        ptr += 2;                                                                              \
        break;                                                                                 \
    case SWB_BT_LEAD3:                                                                         \
        if (end - ptr < 3) return SWB_TOK_PARTIAL_CHAR;                                        \
        if (!enc->isName3(enc, ptr)) { *next = ptr; return SWB_TOK_INVALID; }                  \
        ptr += 3;                                                                              \
        break;                                                                                 \
    case SWB_BT_LEAD4:                                                                         \
        if (end - ptr < 4) return SWB_TOK_PARTIAL_CHAR;                                        \
        if (!enc->isName4(enc, ptr)) { *next = ptr; return SWB_TOK_INVALID; }                  \
        ptr += 4;                                                                              \
        break;

int ts4_xml_prolog_tok_normal_8889A8E8(const SwbEnc *enc, const char *ptr, const char *end, const char **next)
{
    int tok;

    if (ptr == end)
        return PT_NONE;
    switch (SWB_BYTE_TYPE(enc, ptr)) {
    case SWB_BT_QUOT:
        return ts4_scan_literal_88893690(SWB_BT_QUOT, enc, ptr + 1, end, next);
    case SWB_BT_APOS:
        return ts4_scan_literal_88893690(SWB_BT_APOS, enc, ptr + 1, end, next);
    case SWB_BT_LT:
        ptr += 1;
        if (ptr == end)
            return SWB_TOK_PARTIAL;
        switch (SWB_BYTE_TYPE(enc, ptr)) {
        case SWB_BT_EXCL:
            return ts4_scan_name_end_88899870(enc, ptr + 1, end, next);
        case SWB_BT_QUEST:
            return ex5_xml_scan_pi_normal_888993E8(enc, ptr + 1, end, next);
        case SWB_BT_NMSTRT:
        case SWB_BT_HEX:
        case SWB_BT_NONASCII:
        case SWB_BT_LEAD2:
        case SWB_BT_LEAD3:
        case SWB_BT_LEAD4:
            *next = ptr - 1;
            return PT_INSTANCE_START;
        }
        *next = ptr;
        return SWB_TOK_INVALID;
    case SWB_BT_CR:
        if (ptr + 1 == end) {
            *next = end;
            return -PT_PROLOG_S;
        }
    case SWB_BT_S:
    case SWB_BT_LF:
        ptr += 1;
        while (ptr != end) {
            switch (SWB_BYTE_TYPE(enc, ptr)) {
            case SWB_BT_LF:
                break;
            case SWB_BT_S:
                break;
            case SWB_BT_CR:
                if (ptr + 1 != end)
                    break;
            default:
                *next = ptr;
                return PT_PROLOG_S;
            }
            ptr += 1;
        }
        *next = ptr;
        return PT_PROLOG_S;
    case PT_BT_PERCNT:
        return ts4_xml_scan_percent_88893B50(enc, ptr + 1, end, next);
    case PT_BT_COMMA:
        *next = ptr + 1;
        return PT_COMMA;
    case SWB_BT_LSQB:
        *next = ptr + 1;
        return PT_OPEN_BRACKET;
    case SWB_BT_RSQB:
        ptr += 1;
        if (ptr == end)
            return -PT_CLOSE_BRACKET;
        if (*ptr == ']') {
            if (ptr + 1 == end)
                return SWB_TOK_PARTIAL;
            if (ptr[1] == '>') {
                *next = ptr + 2;
                return PT_COND_SECT_CLOSE;
            }
        }
        *next = ptr;
        return PT_CLOSE_BRACKET;
    case PT_BT_LPAR:
        *next = ptr + 1;
        return PT_OPEN_PAREN;
    case PT_BT_RPAR:
        ptr += 1;
        if (ptr == end)
            return -PT_CLOSE_PAREN;
        switch (SWB_BYTE_TYPE(enc, ptr)) {
        case PT_BT_AST:
            *next = ptr + 1;
            return PT_CLOSE_PAREN_ASTERISK;
        case SWB_BT_QUEST:
            *next = ptr + 1;
            return PT_CLOSE_PAREN_QUESTION;
        case PT_BT_PLUS:
            *next = ptr + 1;
            return PT_CLOSE_PAREN_PLUS;
        case SWB_BT_CR:
        case SWB_BT_LF:
        case SWB_BT_S:
        case SWB_BT_GT:
        case PT_BT_COMMA:
        case PT_BT_VERBAR:
        case PT_BT_RPAR:
            *next = ptr;
            return PT_CLOSE_PAREN;
        }
        *next = ptr;
        return SWB_TOK_INVALID;
    case PT_BT_VERBAR:
        *next = ptr + 1;
        return PT_OR;
    case SWB_BT_GT:
        *next = ptr + 1;
        return PT_DECL_CLOSE;
    case SWB_BT_NUM:
        return ts4_xmltok_normal_scan_pound_name_88893860(enc, ptr + 1, end, next);
    case SWB_BT_LEAD2:
        if (end - ptr < 2)
            return SWB_TOK_PARTIAL_CHAR;
        if (enc->isNmstrt2(enc, ptr)) {
            ptr += 2;
            tok = PT_NAME;
            break;
        }
        if (!enc->isName2(enc, ptr)) {
            *next = ptr;
            return SWB_TOK_INVALID;
        }
        ptr += 2;
        tok = PT_NMTOKEN;
        break;
    case SWB_BT_LEAD3:
        if (end - ptr < 3)
            return SWB_TOK_PARTIAL_CHAR;
        if (enc->isNmstrt3(enc, ptr)) {
            ptr += 3;
            tok = PT_NAME;
            break;
        }
        if (!enc->isName3(enc, ptr)) {
            *next = ptr;
            return SWB_TOK_INVALID;
        }
        ptr += 3;
        tok = PT_NMTOKEN;
        break;
    case SWB_BT_LEAD4:
        if (end - ptr < 4)
            return SWB_TOK_PARTIAL_CHAR;
        if (enc->isNmstrt4(enc, ptr)) {
            ptr += 4;
            tok = PT_NAME;
            break;
        }
        if (!enc->isName4(enc, ptr)) {
            *next = ptr;
            return SWB_TOK_INVALID;
        }
        ptr += 4;
        tok = PT_NMTOKEN;
        break;
    case SWB_BT_NMSTRT:
    case SWB_BT_HEX:
        tok = PT_NAME;
        ptr += 1;
        break;
    case SWB_BT_DIGIT:
    case SWB_BT_NAME:
    case SWB_BT_MINUS:
    case SWB_BT_COLON:
        tok = PT_NMTOKEN;
        ptr += 1;
        break;
    default:
        *next = ptr;
        return SWB_TOK_INVALID;
    }
    while (ptr != end) {
        switch (SWB_BYTE_TYPE(enc, ptr)) {
        PT_NAME_CASES
        case SWB_BT_GT:
        case PT_BT_RPAR:
        case PT_BT_COMMA:
        case PT_BT_VERBAR:
        case SWB_BT_LSQB:
        case PT_BT_PERCNT:
        case SWB_BT_S:
        case SWB_BT_CR:
        case SWB_BT_LF:
            *next = ptr;
            return tok;
        case SWB_BT_COLON:
            ptr += 1;
            switch (tok) {
            case PT_NAME:
                if (ptr == end)
                    return SWB_TOK_PARTIAL;
                tok = PT_PREFIXED_NAME;
                switch (SWB_BYTE_TYPE(enc, ptr)) {
                PT_NAME_CASES
                default:
                    tok = PT_NMTOKEN;
                    break;
                }
                break;
            case PT_PREFIXED_NAME:
                tok = PT_NMTOKEN;
                break;
            }
            break;
        case PT_BT_PLUS:
            if (tok == PT_NMTOKEN) {
                *next = ptr;
                return SWB_TOK_INVALID;
            }
            *next = ptr + 1;
            return PT_NAME_PLUS;
        case PT_BT_AST:
            if (tok == PT_NMTOKEN) {
                *next = ptr;
                return SWB_TOK_INVALID;
            }
            *next = ptr + 1;
            return PT_NAME_ASTERISK;
        case SWB_BT_QUEST:
            if (tok == PT_NMTOKEN) {
                *next = ptr;
                return SWB_TOK_INVALID;
            }
            *next = ptr + 1;
            return PT_NAME_QUESTION;
        default:
            *next = ptr;
            return SWB_TOK_INVALID;
        }
    }
    return -tok;
}
