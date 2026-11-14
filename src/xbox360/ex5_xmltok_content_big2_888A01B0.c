/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX5: Expat xmltok_impl.c contentTok for big-endian UTF-16, twin of swb2_888A05B8.c.
 * One function per file (fn_check resolves $LN labels by name and they repeat per function). */
#include "swb2_expat.h"

#define EX5_BIG2_MATCHES(p, c) ((p)[0] == 0 && (p)[1] == (c))

/* scanLt and scanRef for big-endian UTF-16 (family EX5): placeholder names. */
int fn_8889F2B8(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);
int ex5_xml_scan_ref_big2_8889BDB8(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);

/* Swing_DLL.xex 0x888A01B0 */
int ex5_xml_content_tok_big2_888A01B0(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next)
{
    if (ptr == end)
        return -4;
    {
        unsigned int n = (unsigned int)(end - ptr);
        if (n & 1) {
            n &= ~1u;
            if (n == 0)
                return SWB_TOK_PARTIAL;
            end = ptr + n;
        }
    }
    switch (SWB_BIG2_TYPE(enc, ptr)) {
    case SWB_BT_LT:
        return fn_8889F2B8(enc, ptr + 2, end, next);
    case SWB_BT_AMP:
        return ex5_xml_scan_ref_big2_8889BDB8(enc, ptr + 2, end, next);
    case SWB_BT_CR:
        ptr += 2;
        if (ptr == end)
            return -3;
        if (SWB_BIG2_TYPE(enc, ptr) == SWB_BT_LF)
            ptr += 2;
        *next = ptr;
        return 7;
    case SWB_BT_LF:
        *next = ptr + 2;
        return 7;
    case SWB_BT_RSQB:
        ptr += 2;
        if (ptr == end)
            return -5;
        if (!EX5_BIG2_MATCHES(ptr, ']'))
            break;
        ptr += 2;
        if (ptr == end)
            return -5;
        if (!EX5_BIG2_MATCHES(ptr, '>')) {
            ptr -= 2;
            break;
        }
        *next = ptr;
        return SWB_TOK_INVALID;
    case SWB_BT_LEAD2:
        if (end - ptr < 2) return SWB_TOK_PARTIAL_CHAR;
        ptr += 2;
        break;
    case SWB_BT_LEAD3:
        if (end - ptr < 3) return SWB_TOK_PARTIAL_CHAR;
        ptr += 3;
        break;
    case SWB_BT_LEAD4:
        if (end - ptr < 4) return SWB_TOK_PARTIAL_CHAR;
        ptr += 4;
        break;
    case SWB_BT_NONXML:
    case SWB_BT_MALFORM:
    case SWB_BT_TRAIL:
        *next = ptr;
        return SWB_TOK_INVALID;
    default:
        ptr += 2;
        break;
    }
    while (ptr != end) {
        int t;
        unsigned int raw = ptr[0];

        if (raw == 0) {
            t = enc->type[ptr[1]];
        } else {
            switch ((int)(raw & 0xff)) {
            case 0xd8: case 0xd9: case 0xda: case 0xdb:
                t = SWB_BT_LEAD4;
                break;
            case 0xdc: case 0xdd: case 0xde: case 0xdf:
                t = SWB_BT_TRAIL;
                break;
            case 0xff:
                { int lo = ptr[1]; if (lo >= 0xfe && lo <= 0xff) { t = SWB_BT_NONXML; break; } }
                /* fallthrough */
            default:
                t = SWB_BT_NONASCII;
                break;
            }
        }
        switch (t) {
        case SWB_BT_LEAD2:
            if (end - ptr < 2) { *next = ptr; return 6; }
            ptr += 2;
            break;
        case SWB_BT_LEAD3:
            if (end - ptr < 3) { *next = ptr; return 6; }
            ptr += 3;
            break;
        case SWB_BT_LEAD4:
            if (end - ptr < 4) { *next = ptr; return 6; }
            ptr += 4;
            break;
        case SWB_BT_RSQB:
            if (ptr + 2 != end) {
                if (!EX5_BIG2_MATCHES(ptr + 2, ']')) {
                    ptr += 2;
                    break;
                }
                if (ptr + 4 != end) {
                    if (!EX5_BIG2_MATCHES(ptr + 4, '>')) {
                        ptr += 2;
                        break;
                    }
                    *next = ptr + 4;
                    return SWB_TOK_INVALID;
                }
            }
            /* fallthrough */
        case SWB_BT_AMP:
        case SWB_BT_LT:
        case SWB_BT_NONXML:
        case SWB_BT_MALFORM:
        case SWB_BT_TRAIL:
        case SWB_BT_CR:
        case SWB_BT_LF:
            *next = ptr;
            return 6;
        default:
            ptr += 2;
            break;
        }
    }
    *next = ptr;
    return 6;
}
