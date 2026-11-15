/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Swing_DLL.xex 0x8889EC00-0x8889F2B8.
 * Family OS2: xmltok_impl.c scanLt (after "<") for the 8-bit "normal" encoding, XML_NS build, scanCdataSection
 * inlined. One function per file (fn_check resolves $LN labels by name and they repeat per function). */
#include "swb2_expat.h"

int ts4_xml_scan_atts_normal_8889CE50(const SwbEnc *enc, const char *ptr, const char *end, const char **next);
int ts4_xml_scan_comment_888945F8(const SwbEnc *enc, const char *ptr, const char *end, const char **next);
int ex5_xml_scan_pi_normal_888993E8(const SwbEnc *enc, const char *ptr, const char *end, const char **next);
int ts4_xml_scan_end_tag_88893EC8(const SwbEnc *enc, const char *ptr, const char *end, const char **next);

extern const char lbl_880CF0C0[]; /* "CDATA[" */

#ifdef _MSC_VER
#define OS2_FORCEINLINE static __forceinline
#else
#define OS2_FORCEINLINE static inline
#endif
/* Expat scanCdataSection (after "<![") */
OS2_FORCEINLINE int os2_scan_cdata_section(const SwbEnc *enc, const char *ptr, const char *end, const char **next)
{
    int i;
    (void)enc;
    if (end - ptr < 6)
        return SWB_TOK_PARTIAL;
    for (i = 0; i < 6; i++, ptr += 1) {
        if (*ptr != lbl_880CF0C0[i]) {
            *next = ptr;
            return SWB_TOK_INVALID;
        }
    }
    *next = ptr;
    return 8;
}

/* Expat IS_NMSTRT_CHAR_MINBPC / IS_NAME_CHAR_MINBPC: always false for the 8-bit encodings */
#define OS2_NONASCII_OK(enc, p) (0)
#define OS2_NONASCII(chk)                                                                      \
    case SWB_BT_NONASCII:                                                                      \
        if (!chk(enc, ptr)) {                                                                  \
            *next = ptr;                                                                       \
            return SWB_TOK_INVALID;                                                            \
        }

#define OS2_LEAD(n, fn)                                                                        \
    if (end - ptr < n)                                                                         \
        return SWB_TOK_PARTIAL_CHAR;                                                           \
    if (!enc->fn(enc, ptr)) {                                                                  \
        *next = ptr;                                                                           \
        return SWB_TOK_INVALID;                                                                \
    }                                                                                          \
    ptr += n;                                                                                  \
    break;

int os2_xml_scan_lt_normal_8889EC00(const SwbEnc *enc, const char *ptr, const char *end, const char **next)
{
    int had_colon;

    if (ptr == end)
        return SWB_TOK_PARTIAL;
    switch (SWB_BYTE_TYPE(enc, ptr)) {
    OS2_NONASCII(OS2_NONASCII_OK)
    case SWB_BT_NMSTRT:
    case SWB_BT_HEX:
        ptr += 1;
        break;
    case SWB_BT_LEAD2:
        OS2_LEAD(2, isNmstrt2)
    case SWB_BT_LEAD3:
        OS2_LEAD(3, isNmstrt3)
    case SWB_BT_LEAD4:
        OS2_LEAD(4, isNmstrt4)
    case SWB_BT_EXCL:
        ptr += 1;
        if (ptr == end)
            return SWB_TOK_PARTIAL;
        switch (SWB_BYTE_TYPE(enc, ptr)) {
        case SWB_BT_MINUS:
            return ts4_xml_scan_comment_888945F8(enc, ptr + 1, end, next);
        case SWB_BT_LSQB:
            return os2_scan_cdata_section(enc, ptr + 1, end, next);
        }
        *next = ptr;
        return SWB_TOK_INVALID;
    case SWB_BT_QUEST:
        return ex5_xml_scan_pi_normal_888993E8(enc, ptr + 1, end, next);
    case SWB_BT_SOL:
        return ts4_xml_scan_end_tag_88893EC8(enc, ptr + 1, end, next);
    default:
        *next = ptr;
        return SWB_TOK_INVALID;
    }
    had_colon = 0;
    while (ptr != end) {
        switch (SWB_BYTE_TYPE(enc, ptr)) {
        OS2_NONASCII(OS2_NONASCII_OK)
        case SWB_BT_NMSTRT:
        case SWB_BT_HEX:
        case SWB_BT_DIGIT:
        case SWB_BT_NAME:
        case SWB_BT_MINUS:
            ptr += 1;
            break;
        case SWB_BT_LEAD2:
            OS2_LEAD(2, isName2)
        case SWB_BT_LEAD3:
            OS2_LEAD(3, isName3)
        case SWB_BT_LEAD4:
            OS2_LEAD(4, isName4)
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
            OS2_NONASCII(OS2_NONASCII_OK)
            case SWB_BT_NMSTRT:
            case SWB_BT_HEX:
                ptr += 1;
                break;
            case SWB_BT_LEAD2:
                OS2_LEAD(2, isNmstrt2)
            case SWB_BT_LEAD3:
                OS2_LEAD(3, isNmstrt3)
            case SWB_BT_LEAD4:
                OS2_LEAD(4, isNmstrt4)
            default:
                *next = ptr;
                return SWB_TOK_INVALID;
            }
            break;
        case SWB_BT_S:
        case SWB_BT_CR:
        case SWB_BT_LF:
            ptr += 1;
            while (ptr != end) {
                switch (SWB_BYTE_TYPE(enc, ptr)) {
                OS2_NONASCII(OS2_NONASCII_OK)
                case SWB_BT_NMSTRT:
                case SWB_BT_HEX:
                    ptr += 1;
                    break;
                case SWB_BT_LEAD2:
                    OS2_LEAD(2, isNmstrt2)
                case SWB_BT_LEAD3:
                    OS2_LEAD(3, isNmstrt3)
                case SWB_BT_LEAD4:
                    OS2_LEAD(4, isNmstrt4)
                case SWB_BT_GT:
                    goto LN_gt;
                case SWB_BT_SOL:
                    goto LN_sol;
                case SWB_BT_S:
                case SWB_BT_CR:
                case SWB_BT_LF:
                    ptr += 1;
                    continue;
                default:
                    *next = ptr;
                    return SWB_TOK_INVALID;
                }
                return ts4_xml_scan_atts_normal_8889CE50(enc, ptr, end, next);
            }
            return SWB_TOK_PARTIAL;
        case SWB_BT_GT:
        LN_gt:
            *next = ptr + 1;
            return 2;
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
            return 4;
        default:
            *next = ptr;
            return SWB_TOK_INVALID;
        }
    }
    return SWB_TOK_PARTIAL;
}
