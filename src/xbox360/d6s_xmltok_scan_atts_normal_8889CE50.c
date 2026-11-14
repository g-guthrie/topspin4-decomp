/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Swing_DLL.xex 0x8889CE50-0x8889D3FC, executable version 0.0.0.3.
 * Family D6S: xmltok_impl.c scanAtts for the 8-bit "normal" encoding (XML_NS build).
 * One function per file (fn_check resolves $LN labels by name and they repeat per function). */
#include "swb2_expat.h"

/* The callees below are same-file copies of the functions at 0x88893E38, 0x88899350 and 0x8889B160 (they are
 * matched elsewhere). With the callee chain visible, the compiler promotes the address-taken `ptr` of the
 * attribute-value loop to a register and keeps its stack image only around the scanRef call; without them it
 * keeps `ptr` in memory throughout. Case labels are written `LN_*` so jump-table entries use `$LN`-style names. */
#ifdef _MSC_VER
#define D6S_NOINLINE __declspec(noinline)
#define D6S_LOOP_LABEL(n) n:
#else
#define D6S_NOINLINE __attribute__((unused))
#define D6S_LOOP_LABEL(n)
#endif
D6S_NOINLINE static int ts4_xmltok_normal_scan_hex_char_ref_88893E38(const SwbEnc *enc, const char *ptr, const char *end, const char **next)
{
    if (ptr != end) {
        switch (SWB_BYTE_TYPE(enc, ptr)) {
        case SWB_BT_DIGIT:
        case SWB_BT_HEX:
            break;
        default:
            *next = ptr;
            return 0;
        }
        for (ptr += 1; ptr != end; ptr += 1) {
            switch (SWB_BYTE_TYPE(enc, ptr)) {
            case SWB_BT_DIGIT:
            case SWB_BT_HEX:
                break;
            case SWB_BT_SEMI:
                *next = ptr + 1;
                return 10;
            default:
                *next = ptr;
                return 0;
            }
        }
    }
    return SWB_TOK_PARTIAL;
}

D6S_NOINLINE static int ex5_xml_scan_char_ref_normal_88899350(const SwbEnc *enc, const char *ptr, const char *end, const char **next)
{
    if (ptr != end) {
        if (*ptr == 'x')
            return ts4_xmltok_normal_scan_hex_char_ref_88893E38(enc, ptr + 1, end, next);
        switch (SWB_BYTE_TYPE(enc, ptr)) {
        case SWB_BT_DIGIT:
            break;
        default:
            *next = ptr;
            return SWB_TOK_INVALID;
        }
        for (ptr += 1; ptr != end; ptr += 1) {
            switch (SWB_BYTE_TYPE(enc, ptr)) {
            case SWB_BT_DIGIT:
                break;
            case SWB_BT_SEMI:
                *next = ptr + 1;
                return 10; /* XML_TOK_CHAR_REF */
            default:
                *next = ptr;
                return SWB_TOK_INVALID;
            }
        }
    }
    return SWB_TOK_PARTIAL;
}

D6S_NOINLINE static int ts4_xml_scan_ref_8889B160(const SwbEnc *enc, const char *ptr, const char *end, const char **next)
{
    if (ptr == end)
        return SWB_TOK_PARTIAL;
    switch (SWB_BYTE_TYPE(enc, ptr)) {
    case SWB_BT_NONASCII:
        *next = ptr;
        return SWB_TOK_INVALID;
    case SWB_BT_NMSTRT:
    case SWB_BT_HEX:
        ptr += 1;
        break;
    case SWB_BT_LEAD2:
        if (end - ptr < 2) return SWB_TOK_PARTIAL_CHAR;
        if (!enc->isNmstrt2(enc, ptr)) { *next = ptr; return SWB_TOK_INVALID; }
        ptr += 2;
        break;
    case SWB_BT_LEAD3:
        if (end - ptr < 3) return SWB_TOK_PARTIAL_CHAR;
        if (!enc->isNmstrt3(enc, ptr)) { *next = ptr; return SWB_TOK_INVALID; }
        ptr += 3;
        break;
    case SWB_BT_LEAD4:
        if (end - ptr < 4) return SWB_TOK_PARTIAL_CHAR;
        if (!enc->isNmstrt4(enc, ptr)) { *next = ptr; return SWB_TOK_INVALID; }
        ptr += 4;
        break;
    case SWB_BT_NUM:
        return ex5_xml_scan_char_ref_normal_88899350(enc, ptr + 1, end, next);
    default:
        *next = ptr;
        return SWB_TOK_INVALID;
    }
    while (ptr != end) {
        switch (SWB_BYTE_TYPE(enc, ptr)) {
        case SWB_BT_NONASCII:
            *next = ptr;
            return SWB_TOK_INVALID;
        case SWB_BT_NMSTRT:
        case SWB_BT_HEX:
        case SWB_BT_DIGIT:
        case SWB_BT_NAME:
        case SWB_BT_MINUS:
            ptr += 1;
            break;
        case SWB_BT_LEAD2:
            if (end - ptr < 2) return SWB_TOK_PARTIAL_CHAR;
            if (!enc->isName2(enc, ptr)) { *next = ptr; return SWB_TOK_INVALID; }
            ptr += 2;
            break;
        case SWB_BT_LEAD3:
            if (end - ptr < 3) return SWB_TOK_PARTIAL_CHAR;
            if (!enc->isName3(enc, ptr)) { *next = ptr; return SWB_TOK_INVALID; }
            ptr += 3;
            break;
        case SWB_BT_LEAD4:
            if (end - ptr < 4) return SWB_TOK_PARTIAL_CHAR;
            if (!enc->isName4(enc, ptr)) { *next = ptr; return SWB_TOK_INVALID; }
            ptr += 4;
            break;
        case SWB_BT_SEMI:
            *next = ptr + 1;
            return 9;
        default:
            *next = ptr;
            return SWB_TOK_INVALID;
        }
    }
    return SWB_TOK_PARTIAL;
}

#define D6S_NAME_LEAD(bt, n, fn)                                             \
    case bt:                                                                 \
        if (end - ptr < n)                                                   \
            return SWB_TOK_PARTIAL_CHAR;                                     \
        if (!enc->fn(enc, ptr)) {                                            \
            *next = ptr;                                                     \
            return SWB_TOK_INVALID;                                          \
        }                                                                    \
        ptr += n;                                                            \
        break;

int ts4_xml_scan_atts_normal_8889CE50(const SwbEnc *enc, const char *ptr, const char *end, const char **next)
{
    int had_colon = 0;
    int open;
    int t;
    int (*fn4)(const SwbEnc *, const char *);

    while (ptr != end) {
        switch (SWB_BYTE_TYPE(enc, ptr)) {
        D6S_NAME_LEAD(SWB_BT_LEAD2, 2, isName2)
        D6S_NAME_LEAD(SWB_BT_LEAD3, 3, isName3)
        case SWB_BT_LEAD4:
            if (end - ptr < 4)
                return SWB_TOK_PARTIAL_CHAR;
            fn4 = enc->isName4;
            goto LN_lead4_call;
        case SWB_BT_NONASCII:
            *next = ptr;
            return SWB_TOK_INVALID;
        case SWB_BT_NMSTRT:
        case SWB_BT_HEX:
        case SWB_BT_DIGIT:
        case SWB_BT_NAME:
        case SWB_BT_MINUS:
            ptr += 1;
            break;
        case SWB_BT_COLON:
            if (had_colon) {
                *next = ptr;
                return SWB_TOK_INVALID;
            }
            had_colon = 1;
            ptr += 1;
            if (ptr == end)
                return SWB_TOK_PARTIAL;
            switch (SWB_BYTE_TYPE(enc, ptr)) {
            case SWB_BT_NONASCII:
                *next = ptr;
                return SWB_TOK_INVALID;
            case SWB_BT_LEAD2:
                goto LN_nm_lead2;
            case SWB_BT_LEAD3:
                goto LN_nm_lead3;
            case SWB_BT_LEAD4:
                goto LN_nm_lead4;
            case SWB_BT_NMSTRT:
            case SWB_BT_HEX:
                goto LN_nm_one;
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
                ptr += 1;
                if (ptr == end)
                    return SWB_TOK_PARTIAL;
                t = SWB_BYTE_TYPE(enc, ptr);
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
                ptr += 1;
                if (ptr == end)
                    return SWB_TOK_PARTIAL;
                open = SWB_BYTE_TYPE(enc, ptr);
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
            ptr += 1;
            for (;;) {
                if (ptr == end)
                    return SWB_TOK_PARTIAL;
                t = SWB_BYTE_TYPE(enc, ptr);
                if (t == open)
                    break;
                switch (t) {
                SWB_INVALID_CASES()
                case SWB_BT_AMP: {
                    int tok = ts4_xml_scan_ref_8889B160(enc, ptr + 1, end, &ptr);
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
                    ptr += 1;
                    break;
                }
            }
            ptr += 1;
            if (ptr == end)
                return SWB_TOK_PARTIAL;
            switch (SWB_BYTE_TYPE(enc, ptr)) {
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
                ptr += 1;
                if (ptr == end)
                    return SWB_TOK_PARTIAL;
                switch (SWB_BYTE_TYPE(enc, ptr)) {
                case SWB_BT_NONASCII:
                    *next = ptr;
                    return SWB_TOK_INVALID;
                case SWB_BT_NMSTRT:
                case SWB_BT_HEX:
                LN_nm_one:
                    ptr += 1;
                    break;
                case SWB_BT_LEAD2:
                LN_nm_lead2:
                    if (end - ptr < 2)
                        return SWB_TOK_PARTIAL_CHAR;
                    if (!enc->isNmstrt2(enc, ptr)) {
                        *next = ptr;
                        return SWB_TOK_INVALID;
                    }
                    ptr += 2;
                    break;
                case SWB_BT_LEAD3:
                LN_nm_lead3:
                    if (end - ptr < 3)
                        return SWB_TOK_PARTIAL_CHAR;
                    if (!enc->isNmstrt3(enc, ptr)) {
                        *next = ptr;
                        return SWB_TOK_INVALID;
                    }
                    ptr += 3;
                    break;
                case SWB_BT_LEAD4:
                LN_nm_lead4:
                    if (end - ptr < 4)
                        return SWB_TOK_PARTIAL_CHAR;
                    fn4 = enc->isNmstrt4;
                LN_lead4_call:
                    if (!fn4(enc, ptr)) {
                        *next = ptr;
                        return SWB_TOK_INVALID;
                    }
                    ptr += 4;
                    break;
                case SWB_BT_S:
                case SWB_BT_CR:
                case SWB_BT_LF:
                    continue;
                case SWB_BT_SOL:
                LN_sol:
                    ptr += 1;
                    if (ptr == end)
                        return SWB_TOK_PARTIAL;
                    if (*ptr != '>') {
                        *next = ptr;
                        return SWB_TOK_INVALID;
                    }
                    *next = ptr + 1;
                    return 3;
                case SWB_BT_GT:
                LN_gt:
                    *next = ptr + 1;
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
