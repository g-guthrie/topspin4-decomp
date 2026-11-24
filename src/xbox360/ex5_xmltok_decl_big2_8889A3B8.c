/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX5: Expat xmltok_impl.c scanDecl for big-endian UTF-16, twin of swb2_8889A6D8.c. One function per file
 * (fn_check resolves $LN labels by name and they repeat per function). */
#include "swb2_expat.h"

/* Big-endian scanComment (Swing_DLL.xex 0x88897060, family EX4; still a placeholder name in the b10 split). */
int ex4_xml_scan_comment_big2_88897060(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);

/* Scan after "<!": comment, "<![" (conditional section / CDATA open) or a declaration name.
 * Swing_DLL.xex 0x8889A3B8 */
int ex5_xml_scan_decl_big2_8889A3B8(const SwbEnc *enc, const unsigned char *ptr, const unsigned char *end, const unsigned char **next)
{
    if (ptr == end)
        return SWB_TOK_PARTIAL;
    switch (SWB_BIG2_TYPE(enc, ptr)) {
    case SWB_BT_MINUS:
        return ex4_xml_scan_comment_big2_88897060(enc, ptr + 2, end, next);
    case SWB_BT_LSQB:
        *next = ptr + 2;
        return 33;
    case SWB_BT_NMSTRT:
    case SWB_BT_HEX:
        ptr += 2;
        break;
    default:
        *next = ptr;
        return SWB_TOK_INVALID;
    }
    while (ptr != end) {
        switch (SWB_BIG2_TYPE(enc, ptr)) {
        case 30:
            if (ptr + 2 == end)
                return SWB_TOK_PARTIAL;
            switch (SWB_BIG2_TYPE(enc, ptr + 2)) {
            case SWB_BT_S: case SWB_BT_CR: case SWB_BT_LF: case 30:
                *next = ptr;
                return SWB_TOK_INVALID;
            }
            /* fall through */
        case SWB_BT_S: case SWB_BT_CR: case SWB_BT_LF:
            *next = ptr;
            return 16;
        case SWB_BT_NMSTRT: case SWB_BT_HEX:
            ptr += 2;
            break;
        default:
            *next = ptr;
            return SWB_TOK_INVALID;
        }
    }
    return SWB_TOK_PARTIAL;
}
