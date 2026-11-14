/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family D5N: xmltok_impl.c prologTok body for the two 16-bit encodings. The including file defines
 * D5N_FN (function name), D5N_TYPE(p), D5N_HI(p), D5N_LO(p), D5N_MATCHES(p, c) and the five callees
 * D5N_SCAN_LIT, D5N_SCAN_DECL, D5N_SCAN_PI, D5N_SCAN_PERCENT, D5N_SCAN_POUND. */
#ifndef D5N_XMLTOK_PROLOG16_H
#define D5N_XMLTOK_PROLOG16_H

#include "ex5_xmltok16.h"

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

int D5N_SCAN_LIT(int open, const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);
int D5N_SCAN_DECL(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);
int D5N_SCAN_PI(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);
int D5N_SCAN_PERCENT(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);
int D5N_SCAN_POUND(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);

#define PT_LEADN(n, isfn)                                                                      \
    if (end - ptr < n)                                                                         \
        return SWB_TOK_PARTIAL_CHAR;                                                           \
    *next = ptr;                                                                               \
    return SWB_TOK_INVALID;

int D5N_FN(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next)
{
    int tok;
    unsigned char hi;

    if (ptr == end)
        return PT_NONE;
    {
        unsigned int n = (unsigned int)(end - ptr);
        if (n & 1) {
            n &= ~1u;
            if (n == 0)
                return SWB_TOK_PARTIAL;
            end = ptr + n;
        }
    }
    switch (D5N_TYPE(ptr)) {
    case SWB_BT_QUOT:
        return D5N_SCAN_LIT(SWB_BT_QUOT, enc, ptr + 2, end, next);
    case SWB_BT_APOS:
        return D5N_SCAN_LIT(SWB_BT_APOS, enc, ptr + 2, end, next);
    case SWB_BT_LT:
        ptr += 2;
        if (ptr == end)
            return SWB_TOK_PARTIAL;
        switch (D5N_TYPE(ptr)) {
        case SWB_BT_EXCL:
            return D5N_SCAN_DECL(enc, ptr + 2, end, next);
        case SWB_BT_QUEST:
            return D5N_SCAN_PI(enc, ptr + 2, end, next);
        case SWB_BT_NMSTRT:
        case SWB_BT_HEX:
        case SWB_BT_NONASCII:
        case SWB_BT_LEAD2:
        case SWB_BT_LEAD3:
        case SWB_BT_LEAD4:
            *next = ptr - 2;
            return PT_INSTANCE_START;
        }
        *next = ptr;
        return SWB_TOK_INVALID;
    case SWB_BT_CR:
        if (ptr + 2 == end) {
            *next = end;
            return -PT_PROLOG_S;
        }
    case SWB_BT_S:
    case SWB_BT_LF:
        for (;;) {
            ptr += 2;
            if (ptr == end)
                break;
            switch (D5N_TYPE(ptr)) {
            case SWB_BT_LF:
                break;
            case SWB_BT_S:
                break;
            case SWB_BT_CR:
                if (D5N_NOT_LAST(ptr, end))
                    break;
            default:
                *next = ptr;
                return PT_PROLOG_S;
            }
        }
        *next = ptr;
        return PT_PROLOG_S;
    case PT_BT_PERCNT:
        return D5N_SCAN_PERCENT(enc, ptr + 2, end, next);
    case PT_BT_COMMA:
        *next = ptr + 2;
        return PT_COMMA;
    case SWB_BT_LSQB:
        *next = ptr + 2;
        return PT_OPEN_BRACKET;
    case SWB_BT_RSQB:
        ptr += 2;
        if (ptr == end)
            return -PT_CLOSE_BRACKET;
        if (D5N_MATCHES(ptr, ']')) {
            if (ptr + 2 == end)
                return SWB_TOK_PARTIAL;
            if (D5N_MATCHES(ptr + 2, '>')) {
                *next = ptr + 4;
                return PT_COND_SECT_CLOSE;
            }
        }
        *next = ptr;
        return PT_CLOSE_BRACKET;
    case PT_BT_LPAR:
        *next = ptr + 2;
        return PT_OPEN_PAREN;
    case PT_BT_RPAR:
        ptr += 2;
        if (ptr == end)
            return -PT_CLOSE_PAREN;
        switch (D5N_TYPE(ptr)) {
        case PT_BT_AST:
            *next = ptr + 2;
            return PT_CLOSE_PAREN_ASTERISK;
        case SWB_BT_QUEST:
            *next = ptr + 2;
            return PT_CLOSE_PAREN_QUESTION;
        case PT_BT_PLUS:
            *next = ptr + 2;
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
        *next = ptr + 2;
        return PT_OR;
    case SWB_BT_GT:
        *next = ptr + 2;
        return PT_DECL_CLOSE;
    case SWB_BT_NUM:
        return D5N_SCAN_POUND(enc, ptr + 2, end, next);
    case SWB_BT_LEAD2:
        PT_LEADN(2, 0)
    case SWB_BT_LEAD3:
        PT_LEADN(3, 0)
    case SWB_BT_LEAD4:
        PT_LEADN(4, 0)
    case SWB_BT_NMSTRT:
    case SWB_BT_HEX:
        tok = PT_NAME;
        ptr += 2;
        break;
    case SWB_BT_DIGIT:
    case SWB_BT_NAME:
    case SWB_BT_MINUS:
    case SWB_BT_COLON:
        tok = PT_NMTOKEN;
        ptr += 2;
        break;
    case SWB_BT_NONASCII:
        if (EX5_UCS2_NAMING(lbl_880CE9C0, lbl_880CEEC0, D5N_HI(ptr), D5N_LO(ptr))) {
            ptr += 2;
            tok = PT_NAME;
            break;
        }
        if (EX5_UCS2_NAMING(lbl_880CE9C0, lbl_880CEFC0, D5N_HI(ptr), D5N_LO(ptr))) {
            ptr += 2;
            tok = PT_NMTOKEN;
            break;
        }
    default:
        *next = ptr;
        return SWB_TOK_INVALID;
    }
    while (ptr != end) {
        switch (D5N_TYPE(ptr)) {
        EX5_CHECK_NAME_CASES(D5N_HI, D5N_LO)
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
            ptr += 2;
            switch (tok) {
            case PT_NAME:
                if (ptr == end)
                    return SWB_TOK_PARTIAL;
                tok = PT_PREFIXED_NAME;
                switch (D5N_TYPE(ptr)) {
                EX5_CHECK_NAME_CASES(D5N_HI, D5N_LO)
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
            *next = ptr + 2;
            return PT_NAME_PLUS;
        case PT_BT_AST:
            if (tok == PT_NMTOKEN) {
                *next = ptr;
                return SWB_TOK_INVALID;
            }
            *next = ptr + 2;
            return PT_NAME_ASTERISK;
        case SWB_BT_QUEST:
            if (tok == PT_NMTOKEN) {
                *next = ptr;
                return SWB_TOK_INVALID;
            }
            *next = ptr + 2;
            return PT_NAME_QUESTION;
        default:
            *next = ptr;
            return SWB_TOK_INVALID;
        }
    }
    return -tok;
}

#endif
