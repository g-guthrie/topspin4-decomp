/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family D6S: xmltok_impl.c scanAtts body for the two 16-bit encodings (XML_NS build). The including file defines
 * D6S_FN, D6S_REF (scanRef name), D6S_CREF (scanCharRef name), D6S_HREF (scanHexCharRef name), D6S_TYPE(p), D6S_HI(p),
 * D6S_LO(p), D6S_MATCHES(p, c) and D6S_TYPE_INL(p) and D6S_TYPE_INL1(p) (the same classification with the UTF-16
 * classifier expanded in place, used at the sites where the original compiler inlined it). The three callees are same-file copies of functions matched elsewhere: with the
 * callee chain visible the compiler keeps the address-taken `ptr` of the attribute-value loop in a register and
 * only synchronises its stack image around the scanRef call. Labels are `LN_*` so jump-table entries get
 * `$LN`-style names. */
#ifndef D6S_XMLTOK_ATTS16_H
#define D6S_XMLTOK_ATTS16_H

#include "ex5_xmltok16.h"

#ifdef _MSC_VER
#define D6S_NOINLINE __declspec(noinline)
#define D6S_LOOP_LABEL(n) n:
#else
#define D6S_NOINLINE __attribute__((unused))
#define D6S_LOOP_LABEL(n)
#endif

#define D6S_PLAIN_TYPE(p) (D6S_HI(p) == 0 ? (enc)->type[D6S_LO(p)] : ts4_xmltok_unicode_byte_type_888927A0(D6S_HI(p), D6S_LO(p)))

D6S_NOINLINE static int D6S_HREF(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next)
{
    if (ptr != end) {
        switch (D6S_PLAIN_TYPE(ptr)) {
        case SWB_BT_DIGIT:
        case SWB_BT_HEX:
            break;
        default:
            *next = ptr;
            return SWB_TOK_INVALID;
        }
        for (ptr += 2; ptr != end; ptr += 2) {
            switch (D6S_PLAIN_TYPE(ptr)) {
            case SWB_BT_DIGIT:
            case SWB_BT_HEX:
                break;
            case SWB_BT_SEMI:
                *next = ptr + 2;
                return 10;
            default:
                *next = ptr;
                return SWB_TOK_INVALID;
            }
        }
    }
    return SWB_TOK_PARTIAL;
}

D6S_NOINLINE static int D6S_CREF(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next)
{
    if (ptr != end) {
        if (D6S_MATCHES(ptr, 'x'))
            return D6S_HREF(enc, ptr + 2, end, next);
        switch (D6S_PLAIN_TYPE(ptr)) {
        case SWB_BT_DIGIT:
            break;
        default:
            *next = ptr;
            return SWB_TOK_INVALID;
        }
        for (ptr += 2; ptr != end; ptr += 2) {
            switch (D6S_PLAIN_TYPE(ptr)) {
            case SWB_BT_DIGIT:
                break;
            case SWB_BT_SEMI:
                *next = ptr + 2;
                return 10;
            default:
                *next = ptr;
                return SWB_TOK_INVALID;
            }
        }
    }
    return SWB_TOK_PARTIAL;
}

D6S_NOINLINE static int D6S_REF(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next)
{
    if (ptr == end)
        return SWB_TOK_PARTIAL;
    switch (D6S_PLAIN_TYPE(ptr)) {
        EX5_CHECK_NMSTRT_CASES(D6S_HI, D6S_LO)
    case SWB_BT_NUM:
        return D6S_CREF(enc, ptr + 2, end, next);
    default:
        *next = ptr;
        return SWB_TOK_INVALID;
    }
    while (ptr != end) {
        switch (D6S_PLAIN_TYPE(ptr)) {
            EX5_CHECK_NAME_CASES(D6S_HI, D6S_LO)
        case SWB_BT_SEMI:
            *next = ptr + 2;
            return 9;
        default:
            *next = ptr;
            return SWB_TOK_INVALID;
        }
    }
    return SWB_TOK_PARTIAL;
}

#define D6S_LEAD_PARTIAL(n)                                                                    \
    if (end - ptr < n)                                                                         \
        return SWB_TOK_PARTIAL_CHAR;                                                           \
    *next = ptr;                                                                               \
    return SWB_TOK_INVALID;

int D6S_FN(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next)
{
    unsigned char hi;
    unsigned short hi2;
    char hi5;
    int had_colon = 0;
    int open;
    int t;

    while (ptr != end) {
        switch (D6S_TYPE_INL1(ptr)) {
        case SWB_BT_NONASCII:
            if (!EX5_UCS2_NAMING(lbl_880CE9C0, lbl_880CEFC0, D6S_HI(ptr), D6S_LO(ptr))) {
                *next = ptr;
                return SWB_TOK_INVALID;
            }
        case SWB_BT_NMSTRT:
        case SWB_BT_HEX:
        case SWB_BT_DIGIT:
        case SWB_BT_NAME:
        case SWB_BT_MINUS:
            ptr += 2;
            break;
        case SWB_BT_LEAD2:
            D6S_LEAD_PARTIAL(2)
        case SWB_BT_LEAD3:
            D6S_LEAD_PARTIAL(3)
        case SWB_BT_LEAD4:
            D6S_LEAD_PARTIAL(4)
        case SWB_BT_COLON:
            if (had_colon) {
                *next = ptr;
                return SWB_TOK_INVALID;
            }
            had_colon = 1;
            ptr += 2;
            if (ptr == end)
                return SWB_TOK_PARTIAL;
            switch (D6S_TYPE(ptr)) {
                EX5_CHECK_NMSTRT_CASES(D6S_HI, D6S_LO)
            default:
                *next = ptr;
                return SWB_TOK_INVALID;
            }
            break;
        case SWB_BT_S:
        case SWB_BT_CR:
        case SWB_BT_LF:
            D6S_LOOP_LABEL(LN_ws)
            for (;;) {
                ptr += 2;
                if (ptr == end)
                    return SWB_TOK_PARTIAL;
                t = D6S_TYPE_INL(ptr);
                if (t == SWB_BT_EQUALS)
                    break;
                switch (t) {
                case SWB_BT_S:
                case SWB_BT_LF:
                case SWB_BT_CR:
                    break;
                default:
                    *next = ptr;
                    return SWB_TOK_INVALID;
                }
            }
        case SWB_BT_EQUALS:
            had_colon = 0;
            for (;;) {
                ptr += 2;
                if (ptr == end)
                    return SWB_TOK_PARTIAL;
                open = D6S_TYPE_INL(ptr);
                if (open == SWB_BT_QUOT || open == SWB_BT_APOS)
                    break;
                switch (open) {
                case SWB_BT_S:
                case SWB_BT_LF:
                case SWB_BT_CR:
                    break;
                default:
                    *next = ptr;
                    return SWB_TOK_INVALID;
                }
            }
            ptr += 2;
            for (;;) {
                if (ptr == end)
                    return SWB_TOK_PARTIAL;
                t = D6S_TYPE_INL(ptr);
                if (t == open)
                    break;
                switch (t) {
                case SWB_BT_LEAD2:
                    if (end - ptr < 2)
                        return SWB_TOK_PARTIAL_CHAR;
                    ptr += 2;
                    break;
                case SWB_BT_LEAD3:
                    if (end - ptr < 3)
                        return SWB_TOK_PARTIAL_CHAR;
                    ptr += 3;
                    break;
                case SWB_BT_LEAD4:
                    if (end - ptr < 4)
                        return SWB_TOK_PARTIAL_CHAR;
                    ptr += 4;
                    break;
                case SWB_BT_NONXML:
                case SWB_BT_MALFORM:
                case SWB_BT_TRAIL:
                    *next = ptr;
                    return SWB_TOK_INVALID;
                case SWB_BT_AMP: {
                    int tok = D6S_REF(enc, ptr + 2, end, &ptr);
                    if (tok <= 0) {
                        if (tok == SWB_TOK_INVALID)
                            *next = ptr;
                        return tok;
                    }
                    break;
                }
                case SWB_BT_LT:
                    *next = ptr;
                    return SWB_TOK_INVALID;
                default:
                    ptr += 2;
                    break;
                }
            }
            ptr += 2;
            if (ptr == end)
                return SWB_TOK_PARTIAL;
            switch (D6S_TYPE(ptr)) {
            case SWB_BT_S:
            case SWB_BT_CR:
            case SWB_BT_LF:
                break;
            case SWB_BT_SOL:
                goto LN_sol;
            case SWB_BT_GT:
                goto LN_gt;
            default:
                *next = ptr;
                return SWB_TOK_INVALID;
            }
            D6S_LOOP_LABEL(LN_close)
            for (;;) {
                ptr += 2;
                if (ptr == end)
                    return SWB_TOK_PARTIAL;
                switch (D6S_TYPE(ptr)) {
                    EX5_CHECK_NMSTRT_CASES(D6S_HI, D6S_LO)
                case SWB_BT_S:
                case SWB_BT_CR:
                case SWB_BT_LF:
                    continue;
                case SWB_BT_SOL:
                LN_sol:
                    ptr += 2;
                    if (ptr == end)
                        return SWB_TOK_PARTIAL;
                    if (!D6S_MATCHES(ptr, '>')) {
                        *next = ptr;
                        return SWB_TOK_INVALID;
                    }
                    *next = ptr + 2;
                    return 3;
                case SWB_BT_GT:
                LN_gt:
                    *next = ptr + 2;
                    return 1;
                default:
                    *next = ptr;
                    return SWB_TOK_INVALID;
                }
                break;
            }
            break;
        default:
            *next = ptr;
            return SWB_TOK_INVALID;
        }
    }
    return SWB_TOK_PARTIAL;
}

#endif
