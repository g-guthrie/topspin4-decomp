/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family D6S: xmltok_impl.c scanLt body for the two 16-bit encodings (XML_NS build, scanCdataSection inlined).
 * The including file defines D6S_FN, D6S_TYPE(p), D6S_HI(p), D6S_LO(p), D6S_MATCHES(p, c), D6S_CDATA, D6S_GAP and
 * the callees D6S_ATTS, D6S_COMMENT, D6S_PI, D6S_END_TAG. */
#ifndef D6S_XMLTOK_LT16_H
#define D6S_XMLTOK_LT16_H

#include "swb2_expat.h"

#ifdef _MSC_VER
#define D6S_UNUSED_DATA
#else
#define D6S_UNUSED_DATA __attribute__((unused))
#endif
/* The name-class tables and the "CDATA[" character table are statics of the original translation unit (one base
 * register addresses all of them); the contents are placeholders that only fix the object layout. */
static const unsigned char d6s_layout_pad[16] D6S_UNUSED_DATA = {1};
static const unsigned int lbl_880CE9C0[320] = {1};  /* namingBitmap */
static const unsigned char lbl_880CEEC0[256] = {1}; /* nmstrtPages */
static const unsigned char lbl_880CEFC0[256] = {1}; /* namePages */
static const unsigned char d6s_layout_gap[D6S_GAP] D6S_UNUSED_DATA = {1};
static const unsigned char D6S_CDATA[8] = {'C', 'D', 'A', 'T', 'A', '['};

#define D6S_NAMING(pages, p) \
    ((lbl_880CE9C0)[((pages)[D6S_HI(p)] << 3) + (D6S_LO(p) >> 5)] & (1u << (D6S_LO(p) & 0x1F)))

#define D6S_LEAD_PARTIAL(n)                                                                    \
    if (end - ptr < n)                                                                         \
        return SWB_TOK_PARTIAL_CHAR;                                                           \
    *next = ptr;                                                                               \
    return SWB_TOK_INVALID;

int D6S_ATTS(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);
int D6S_COMMENT(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);
int D6S_PI(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);
int D6S_END_TAG(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);

int D6S_FN(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next)
{
    unsigned char hi;
    int had_colon;

    if (ptr == end)
        return SWB_TOK_PARTIAL;
    switch (D6S_TYPE(ptr)) {
    case SWB_BT_NONASCII:
        if (!D6S_NAMING(lbl_880CEEC0, ptr)) {
            *next = ptr;
            return SWB_TOK_INVALID;
        }
    case SWB_BT_NMSTRT:
    case SWB_BT_HEX:
        ptr += 2;
        break;
    case SWB_BT_LEAD2:
        D6S_LEAD_PARTIAL(2)
    case SWB_BT_LEAD3:
        D6S_LEAD_PARTIAL(3)
    case SWB_BT_LEAD4:
        D6S_LEAD_PARTIAL(4)
    case SWB_BT_EXCL:
        ptr += 2;
        if (ptr == end)
            return SWB_TOK_PARTIAL;
        switch (D6S_TYPE(ptr)) {
        case SWB_BT_MINUS:
            return D6S_COMMENT(enc, ptr + 2, end, next);
        case SWB_BT_LSQB:
            goto LN_cdata;
        }
        *next = ptr;
        return SWB_TOK_INVALID;
    case SWB_BT_QUEST:
        return D6S_PI(enc, ptr + 2, end, next);
    case SWB_BT_SOL:
        return D6S_END_TAG(enc, ptr + 2, end, next);
    default:
        *next = ptr;
        return SWB_TOK_INVALID;
    }
    had_colon = 0;
    while (ptr != end) {
        switch (D6S_TYPE(ptr)) {
        case SWB_BT_NONASCII:
            if (!D6S_NAMING(lbl_880CEFC0, ptr)) {
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
            case SWB_BT_NONASCII:
                if (!D6S_NAMING(lbl_880CEEC0, ptr)) {
                    *next = ptr;
                    return SWB_TOK_INVALID;
                }
            case SWB_BT_NMSTRT:
            case SWB_BT_HEX:
                ptr += 2;
                break;
            case SWB_BT_LEAD2:
                D6S_LEAD_PARTIAL(2)
            case SWB_BT_LEAD3:
                D6S_LEAD_PARTIAL(3)
            case SWB_BT_LEAD4:
                D6S_LEAD_PARTIAL(4)
            default:
                *next = ptr;
                return SWB_TOK_INVALID;
            }
            break;
        case SWB_BT_S:
        case SWB_BT_CR:
        case SWB_BT_LF:
            ptr += 2;
            while (ptr != end) {
                switch (D6S_TYPE(ptr)) {
                case SWB_BT_NONASCII:
                    if (!D6S_NAMING(lbl_880CEEC0, ptr)) {
                        *next = ptr;
                        return SWB_TOK_INVALID;
                    }
                case SWB_BT_NMSTRT:
                case SWB_BT_HEX:
                    ptr += 2;
                    break;
                case SWB_BT_LEAD2:
                    D6S_LEAD_PARTIAL(2)
                case SWB_BT_LEAD3:
                    D6S_LEAD_PARTIAL(3)
                case SWB_BT_LEAD4:
                    D6S_LEAD_PARTIAL(4)
                case SWB_BT_GT:
                    goto LN_gt;
                case SWB_BT_SOL:
                    goto LN_sol;
                case SWB_BT_S:
                case SWB_BT_CR:
                case SWB_BT_LF:
                    ptr += 2;
                    continue;
                default:
                    *next = ptr;
                    return SWB_TOK_INVALID;
                }
                return D6S_ATTS(enc, ptr, end, next);
            }
            return SWB_TOK_PARTIAL;
        case SWB_BT_GT:
        LN_gt:
            *next = ptr + 2;
            return 2;
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
            return 4;
        default:
            *next = ptr;
            return SWB_TOK_INVALID;
        }
    }
    return SWB_TOK_PARTIAL;
LN_cdata: {
        int i;
        int tok;
        ptr += 2;
        if (end - ptr < 12)
            return SWB_TOK_PARTIAL;
        for (i = 0; i < 6; i++, ptr += 2) {
            if (!D6S_MATCHES(ptr, D6S_CDATA[i])) {
                tok = 0;
                goto LN_cdata_out;
            }
        }
        tok = 8;
    LN_cdata_out:
        *next = ptr;
        return tok;
    }
}

#endif
