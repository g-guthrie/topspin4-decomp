/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX5: Expat xmltok_impl.c scanPi for the two 16-bit encodings (after "<?"). */
#include "ex5_xmltok16.h"

/* Expat checkPiTarget for 3-unit targets: "xml" in lower case flags an XML declaration (12); any upper-case
 * letter in it is reserved and returns 0. Local copies of the out-of-line originals (0x88891DA0 big-endian,
 * 0x88892210 little-endian) so the compiler sees their register usage, as for unicode_byte_type. */
#define EX5_BIG2_TO_ASCII(p) ((p)[0] == 0 ? (p)[1] : -1)
#define EX5_LITTLE2_TO_ASCII(p) ((p)[1] == 0 ? (p)[0] : -1)

#ifdef _MSC_VER
#define EX5_NOINLINE __declspec(noinline)
#else
#define EX5_NOINLINE __attribute__((unused))
#endif

#define EX5_DEFINE_CHECK_PI_TARGET(name, TO_ASCII)                                                         \
EX5_NOINLINE static int name(const char *ptr, int *tok_ptr)                                                \
{                                                                                                          \
    int upper = 0;                                                                                         \
    switch (TO_ASCII(ptr)) {                                                                               \
    case 'x':                                                                                              \
        break;                                                                                             \
    case 'X':                                                                                              \
        upper = 1;                                                                                         \
        break;                                                                                             \
    default:                                                                                               \
        return 1;                                                                                          \
    }                                                                                                      \
    ptr += 2;                                                                                              \
    switch (TO_ASCII(ptr)) {                                                                               \
    case 'm':                                                                                              \
        break;                                                                                             \
    case 'M':                                                                                              \
        upper = 1;                                                                                         \
        break;                                                                                             \
    default:                                                                                               \
        return 1;                                                                                          \
    }                                                                                                      \
    ptr += 2;                                                                                              \
    switch (TO_ASCII(ptr)) {                                                                               \
    case 'l':                                                                                              \
        break;                                                                                             \
    case 'L':                                                                                              \
        upper = 1;                                                                                         \
        break;                                                                                             \
    default:                                                                                               \
        return 1;                                                                                          \
    }                                                                                                      \
    if (upper)                                                                                             \
        return 0;                                                                                          \
    *tok_ptr = 12;                                                                                         \
    return 1;                                                                                              \
}

EX5_DEFINE_CHECK_PI_TARGET(ts4_xmltok_big2_check_pi_target_88891DA0, EX5_BIG2_TO_ASCII)
EX5_DEFINE_CHECK_PI_TARGET(ts4_xmltok_little2_check_pi_target_88892210, EX5_LITTLE2_TO_ASCII)

/* Expat checkPiTarget: 3-unit targets are checked for "xml" in any case */
#define EX5_CHECK_PI_TARGET(check, target, ptr, tokp) \
    (*(tokp) = 11 /* XML_TOK_PI */, ((ptr) - (target) == 6) ? check(target, tokp) : 1)

#define EX5_DEFINE_SCAN_PI(name, check, HI, LO)                                                            \
int name(const SwbEnc *enc, const char *ptr, const char *end, const char **next)                          \
{                                                                                                          \
    int tok;                                                                                               \
    const char *target = ptr;                                                                              \
    if (ptr == end)                                                                                        \
        return SWB_TOK_PARTIAL;                                                                            \
    switch (EX5_UNIT_TYPE(enc, HI(ptr), LO(ptr))) {                                                        \
        EX5_CHECK_NMSTRT_CASES(HI, LO)                                                                     \
    default:                                                                                               \
        *next = ptr;                                                                                       \
        return SWB_TOK_INVALID;                                                                            \
    }                                                                                                      \
    while (ptr != end) {                                                                                   \
        switch (EX5_UNIT_TYPE(enc, HI(ptr), LO(ptr))) {                                                    \
            EX5_CHECK_NAME_CASES(HI, LO)                                                                   \
        case SWB_BT_S:                                                                                     \
        case SWB_BT_CR:                                                                                    \
        case SWB_BT_LF:                                                                                    \
            if (!EX5_CHECK_PI_TARGET(check, target, ptr, &tok)) {                                          \
                *next = ptr;                                                                               \
                return SWB_TOK_INVALID;                                                                    \
            }                                                                                              \
            ptr += 2;                                                                                      \
            while (ptr != end) {                                                                           \
                switch (EX5_UNIT_TYPE(enc, HI(ptr), LO(ptr))) {                                            \
                case SWB_BT_LEAD2:                                                                         \
                    if (end - ptr < 2)                                                                     \
                        return SWB_TOK_PARTIAL_CHAR;                                                       \
                    ptr += 2;                                                                              \
                    break;                                                                                 \
                case SWB_BT_LEAD3:                                                                         \
                    if (end - ptr < 3)                                                                     \
                        return SWB_TOK_PARTIAL_CHAR;                                                       \
                    ptr += 3;                                                                              \
                    break;                                                                                 \
                case SWB_BT_LEAD4:                                                                         \
                    if (end - ptr < 4)                                                                     \
                        return SWB_TOK_PARTIAL_CHAR;                                                       \
                    ptr += 4;                                                                              \
                    break;                                                                                 \
                case SWB_BT_NONXML:                                                                        \
                case SWB_BT_MALFORM:                                                                       \
                case SWB_BT_TRAIL:                                                                         \
                    *next = ptr;                                                                           \
                    return SWB_TOK_INVALID;                                                                \
                case SWB_BT_QUEST:                                                                         \
                    ptr += 2;                                                                              \
                    if (ptr == end)                                                                        \
                        return SWB_TOK_PARTIAL;                                                            \
                    if (HI(ptr) == 0 && LO(ptr) == '>') {                                                  \
                        *next = ptr + 2;                                                                   \
                        return tok;                                                                        \
                    }                                                                                      \
                    break;                                                                                 \
                default:                                                                                   \
                    ptr += 2;                                                                              \
                    break;                                                                                 \
                }                                                                                          \
            }                                                                                              \
            return SWB_TOK_PARTIAL;                                                                        \
        case SWB_BT_QUEST:                                                                                 \
            if (!EX5_CHECK_PI_TARGET(check, target, ptr, &tok)) {                                          \
                *next = ptr;                                                                               \
                return SWB_TOK_INVALID;                                                                    \
            }                                                                                              \
            ptr += 2;                                                                                      \
            if (ptr == end)                                                                                \
                return SWB_TOK_PARTIAL;                                                                    \
            if (HI(ptr) == 0 && LO(ptr) == '>') {                                                          \
                *next = ptr + 2;                                                                           \
                return tok;                                                                                \
            }                                                                                              \
            /* fall through */                                                                             \
        default:                                                                                           \
            *next = ptr;                                                                                   \
            return SWB_TOK_INVALID;                                                                        \
        }                                                                                                  \
    }                                                                                                      \
    return SWB_TOK_PARTIAL;                                                                                \
}

/* Swing_DLL.xex 0x88896BE8 (big-endian UTF-16) */
EX5_DEFINE_SCAN_PI(ex5_xml_scan_pi_big2_88896BE8, ts4_xmltok_big2_check_pi_target_88891DA0, EX5_HI_BIG2, EX5_LO_BIG2)
/* Swing_DLL.xex 0x88898CD8 (little-endian UTF-16) */
EX5_DEFINE_SCAN_PI(ex5_xml_scan_pi_little2_88898CD8, ts4_xmltok_little2_check_pi_target_88892210, EX5_HI_LITTLE2, EX5_LO_LITTLE2)
